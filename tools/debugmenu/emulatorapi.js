// emulatorapi.js

const http = require('http');
const { parse:parseUrl } = require('url');
const fs = require('fs');

const CALLBACK_PORT = 52121;
const CALLBACK_URL = `http://localhost:${CALLBACK_PORT}/`;
const EMULATOR_URL = `http://localhost:5337`;

class EmulatorApi {
	constructor() {
		this.symbolTable = null;
		this.reverseSymbolTable = null;
		this.callbackTable = new Map(); // windowid=>{path=>callback}
		this.callbackServer = http.createServer((req, res)=>{
			let { path } = parseUrl(req.url);
		});
		
		this.callbackServer.listen(CALLBACK_PORT, ()=>console.log('listening'));
	}
	
	loadRomSymbolFile(filename) {
		if (typeof filename !== 'string') return Promise.reject(new ReferenceError("Filename is not valid!"));
		const SYMBOL_LINE = /([0-9A-F]{8}) ([0-9A-F]{8})? ?(\w) ([\w\d_]+)/i;
		return new Promise((resolve, reject)=>{
			const table = {}, reverse = [];
			
			const fileStream = fs.createReadStream(filename);
			const rl = require('readline').createInterface({ input: fileStream, crlfDelay:Infinity, terminal:false });
			rl.on('line', (line)=>{
				// Each line in the input file will be successively available here
				let [,addr,size,type,name] = SYMBOL_LINE.exec(line);
				switch (type) {
					case 'R': type = 'readonly'; break;
					case 'T': type = 'code'; break; // .text section
					case 'D': type = 'script'; break; // data section (still readonly)
				}
				table[name] = { name, addr, size:Number.parseInt(size,16), type };
				reverse[Number.parseInt(addr, 16)] = name;
			});
			rl.on('close', ()=>{
				this.symbolTable = table;
				this.reverseSymbolTable = reverse;
				resolve(true);
			});
		});
	}
	
	lookupSymbol(addr) {
		if (addr === 0) return false; //We know already there's no symbols for 0, shortcut
		// Try fast lookup first
		let symbol = this.reverseSymbolTable[addr];
		if (symbol) return symbol;
		// If fast lookup fails, try reversing until we find a symbol
		let limit = 0x1000;
		let offset = 0;
		while (symbol == null && limit > 0) {
			offset++;
			symbol = this.reverseSymbolTable[addr-offset];
			limit--;
		}
		if (symbol) {
			// If we have a symbol, memoize this symbol for future faster lookup
			let res;
			if ((res = /^([a-z0-9_])\+([0-9a-f]+)$/i.exec(symbol))) {
				// Check if the symbol has an offset already, and add it on
				offset += Number.parseInt(res[2],16);
				symbol = res[1];
			}
			return this.reverseSymbolTable[addr] = `${symbol}+${offset.toString(16)}`;
		}
		// console.log(`Failed to find symbol for `, addr);
		return false;
	}
	
	queryEmulator(path, type) {
		if (type === undefined) {
			if (path.slice(0, 4) === 'Read') type = 'read';
			else type = 'command';
		}
		return new Promise((resolve, reject)=>{
			try {
				// console.log(`queryEmulator => ${EMULATOR_URL}${path}`);
				http.get(`${EMULATOR_URL}${path}`, (res)=>{
					let data = '';
					res.on('data', (c)=>data+=c);
					res.on('end', ()=>{
						if (type === 'data') {
							if (res.statusCode !== 200) reject(data); // Error from emulator
							else resolve(Buffer.from(data, "hex"));
						} else {
							if (data == 'ok') resolve(true); // Command response
							else if (res.statusCode === 200) resolve(data);
							else reject(data);
						}
					});
				}).on('error', reject);
			} catch (e) {
				reject(e);
			}
		});
	}
	
	async readSymbols(...symList) {
		symList = symList.map((addr)=>this._resolveSymbol(addr)).filter(x=>x);
		let addrList = symList.map(x=>`${x.addr}/${x.size.toString(16)}`).join('/');
		
		let data = await this.queryEmulator(`/ReadByteRange/${addrList}`, 'data');
		let retList = [];
		let doff = 0;
		for (let sym of symList) {
			retList.push({ name:sym.name, size:sym.size, data:data.slice(doff, doff+sym.size) });
			doff += sym.size;
		}
		return retList;
	}
	
	readMemory(addr, len) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		return this.queryEmulator(`/ReadByteRange/${addr}/${len.toString(16)}`, 'data');
	}
	
	registerOnRead({ winId, addr, len, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryRead/${addr}/${len.toString(16)}/${CALLBACK_URL}/${name}`, name, cb);
	}
	registerOnWrite({ winId, addr, len, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryWrite/${addr}/${len.toString(16)}/${CALLBACK_URL}/${name}`, name, cb);
	}
	registerOnExecute({ winId, addr, len, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryExecute/${addr}/${len.toString(16)}/${CALLBACK_URL}/${name}`, name, cb);
	}
	
	registerOnReadIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryReadIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}/${name}`, name, cb);
	}
	registerOnWriteIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryWriteIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}/${name}`, name, cb);
	}
	registerOnExecuteIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryExecuteIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}/${name}`, name, cb);
	}
	
	_resolveSymbol(addr) {
		// console.log(`_resolveSymbol(${addr}) => ${this.symbolTable && this.symbolTable[addr]}`);
		if (/^[0-9-A-F]{4,8}$/i.test(addr)) return addr; //already an address
		if (!this.symbolTable) return addr; //cannot resolve on a table we don't have
		let info = this.symbolTable[addr];
		if (!info) return addr; //not in table
		return info;
	}
	
	async _registerCallback(winId, url, cbname, cbfunc) {
		if (typeof winId !== 'string' && typeof winId['__window_id__'] === 'string') {
			winId = winId.__window_id__;
		}
		let table = this.callbackTable.get(winId);
		if (!table) {
			table = {};
			this.callbackTable.set(winId, table);
		}
		if (await this.queryEmulator(url, 'command')) {
			table[cbname] = cbfunc;
			return true;
		}
		return false;
	}
	
	cleanupCallbacks(windowid) {
		if (typeof windowid !== 'string' && typeof windowid['__window_id__'] === 'string') {
			windowid = windowid.__window_id__;
		}
		let cblist = this.callbackTable.get(windowid);
		if (cblist) {
			this.callbackTable.delete(windowid);
			for (let cb in cblist) {
				this.queryEmulator(`/${cb}/RemoveMemoryCallback`);
			}
		}
	}
	destroy() {
		this.callbackServer.close();
		for (let cblist in this.callbackTable) {
			this.cleanupCallbacks(cblist[0]);
		}
	}
	
}

module.exports = { EmulatorApi };