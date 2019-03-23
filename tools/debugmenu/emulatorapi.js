// emulatorapi.js

const http = require('http');
const { parse:parseUrl } = require('url');
const fs = require('fs');

const CALLBACK_URL = `http://localhost`;
const EMULATOR_URL = `http://localhost:5337`;

class EmulatorApi {
	constructor(port=52121) {
		this.symbolTable = null;
		this.reverseSymbolTable = null;
		this.varNameTable = null;
		this.flagNameTable = null;
		this.callbackPort = port;
		
		if (!this.callbackPort) {
			this.callbackTable = new Map(); // windowid=>{path=>callback}
			this.callbackServer = http.createServer((req, res)=>{
				let name = '';
				req.on('data', (d)=>name+=d);
				req.on('end', ()=>{
					let handled = false;
					for (let [win, table] of this.callbackTable) {
						if (table[name]) {
							table[name]();
							handled = true;
						}
					}
					if (!handled) {
						console.error('CALLBACK FROM EMULATOR UNHANDLED! path=', path, this.callbackTable);
						res.end();
					} else {
						res.end();
					}
				});
			});
			
			this.callbackServer.listen(this.callbackPort, ()=>console.log('listening'));
		}
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
				let res = SYMBOL_LINE.exec(line);
				if (!res) return; //continue
				let [,addr,size,type,name] = res;
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
	
	loadRomVarNameFile(filename) {
		if (typeof filename !== 'string') return Promise.reject(new ReferenceError("Filename is not valid!"));
		const DEFINE_LINE = /^\#define VAR_([A-Z0-9_]+)\s+0x([0-9A-F]+)/i;
		return new Promise((resolve, reject)=>{
			const table = {};
			const fileStream = fs.createReadStream(filename);
			const rl = require('readline').createInterface({ input: fileStream, crlfDelay:Infinity, terminal:false });
			rl.on('line', (line)=>{
				if (!line.trim()) return; //continue
				if (line.startsWith('//')) return; //continue
				let res = DEFINE_LINE.exec(line);
				if (!res) return; //continue
				let [,name,val] = res;
				val = Number.parseInt(val,16) - 0x4000;
				table[val] = `VAR_${name}`;
			});
			rl.on('close', ()=>{
				this.varNameTable = table;
				resolve(true);
			});
		});
	}
	
	loadRomFlagNameFile(filename) {
		if (typeof filename !== 'string') return Promise.reject(new ReferenceError("Filename is not valid!"));
		const DEFINE_LINE = /^\#define FLAG_([A-Z0-9_]+)\s+0x([0-9A-F]+)/i;
		const HIDDEN_LINE = /^\#define FLAG_([A-Z0-9_]+)\s+\(FLAG_HIDDEN_ITEMS_START \+ 0x([0-9A-F]+)\)/i;
		const SYSTEM_LINE = /^\#define FLAG_([A-Z0-9_]+)\s+\(SYSTEM_FLAGS \+ 0x([0-9A-F]+)\)/i;
		
		return new Promise((resolve, reject)=>{
			const table = {};
			const SYSTEM_FLAGS = 0x860; //TODO make this less annoying to read
			const HIDDEN_FLAG = 0x1F4; //TODO read from file?
			
			const fileStream = fs.createReadStream(filename);
			const rl = require('readline').createInterface({ input: fileStream, crlfDelay:Infinity, terminal:false });
			rl.on('line', (line)=>{
				if (!line.trim()) return; //continue
				if (line.startsWith('//')) return; //continue
				
				let res = DEFINE_LINE.exec(line);
				if (res) {
					let [,name,val] = res;
					val = Number.parseInt(val,16);
					table[val] = `FLAG_${name}`;
					return; //continue
				}
				
				res = HIDDEN_LINE.exec(line);
				if (res) {
					let [,name,val] = res;
					val = Number.parseInt(val,16);
					val += HIDDEN_FLAG;
					table[val] = `FLAG_${name}`;
					return; //continue
				}
				
				res = SYSTEM_LINE.exec(line);
				if (res) {
					let [,name,val] = res;
					val = Number.parseInt(val,16);
					val += SYSTEM_FLAGS;
					table[val] = `FLAG_${name}`;
					return; //continue
				}
			});
			rl.on('close', ()=>{
				this.flagNameTable = table;
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
			if ((res = /^([a-z0-9_]+)\+([0-9a-f]+)$/i.exec(symbol))) {
				// Check if the symbol has an offset already, and add it on
				offset += Number.parseInt(res[2],16);
				symbol = res[1];
			}
			return this.reverseSymbolTable[addr] = `${symbol}+${offset.toString(16)}`;
		}
		// console.log(`Failed to find symbol for `, addr);
		return false;
	}
	
	getVarName(id) { return this.varNameTable[id]; }
	getFlagName(id) {
		if (id > 0x500 && id <= 0x500+0x356) {
			return `TRAINER_FLAG_${(id-0x500).toString(16)}`;
		}
		return this.flagNameTable[id]; 
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
	
	postToEmulator(path, body) {
		return new Promise((resolve, reject)=>{
			try {
				const opts = {
					method: 'POST',
				};
				const req = http.request(`${EMULATOR_URL}${path}`, opts, (res)=>{
					let data = '';
					res.on('data', (c)=>data+=c);
					res.on('end', ()=>{
						if (data == 'ok') resolve(true); // Command response
						else if (res.statusCode === 200) resolve(data);
						else reject(data);
					});
				}).on('error', reject);
				req.write(body);
				req.end();
			} catch (e) {
				reject(e);
			}
		});
	}
	
	async readSymbols(...symList) {
		symList = symList.map((addr)=>this._resolveSymbol(addr,true)).filter(x=>x);
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
	
	async readSymbolPointer(symbol, length) {
		let info = this._resolveSymbol(symbol);
		if (!info) throw new ReferenceError('Symbol not found: '+symbol);
		
		let data = await this.queryEmulator(`/ReadByteRange/*${info.addr}/${length.toString(16)}`, 'data');
		return data;
	}
	
	readMemory(addr, len) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		
		return this.queryEmulator(`/ReadByteRange/${addr}/${len.toString(16)}`, 'data');
	}
	
	registerOnRead({ winId, addr, len, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		return this._registerCallback(winId, `/${name}/OnMemoryRead/${addr}/${len.toString(16)}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	registerOnWrite({ winId, addr, len, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		return this._registerCallback(winId, `/${name}/OnMemoryWrite/${addr}/${len.toString(16)}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	registerOnExecute({ winId, addr, len, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		return this._registerCallback(winId, `/${name}/OnMemoryExecute/${addr}/${len.toString(16)}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	
	registerOnReadIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryReadIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	registerOnWriteIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryWriteIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	registerOnExecuteIfValue({ winId, addr, len, ifAddr, isValue, name, cb }) {
		if (!this.callbackServer) return Promise.reject(new ReferenceError('No callback server instantiated!'));
		if (typeof addr === 'string') {
			addr = this._resolveSymbol(addr);
			if (len === undefined && typeof addr !== 'string') len = addr.size;
			if (typeof addr !== 'string') addr = addr.addr;
		}
		if (typeof addr === 'number') addr = addr.toString(16);
		
		ifAddr = this._resolveSymbol(ifAddr);
		if (typeof ifAddr !== 'string') ifAddr = ifAddr.addr;
		
		return this._registerCallback(winId, `/${name}/OnMemoryExecuteIfValue/${addr}/${len.toString(16)}/${ifAddr}/${isValue}/${CALLBACK_URL}:${this.callbackPort}/${name}`, name, cb);
	}
	
	_resolveSymbol(addr, strict=false) {
		// console.log(`_resolveSymbol(${addr}) => ${this.symbolTable && this.symbolTable[addr]}`);
		if (typeof addr === 'number') addr = addr.toString(16);
		if (/^[0-9A-F]{4,8}$/i.test(addr) && !strict) return addr; //already an address
		if (!this.symbolTable) return addr; //cannot resolve on a table we don't have
		let info = this.symbolTable[addr];
		if (!info) return strict?null:addr; //not in table
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
		if (!this.callbackTable) return;
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
		if (this.callbackServer) {
			this.callbackServer.close();
		}
		for (let cblist in this.callbackTable) {
			this.cleanupCallbacks(cblist[0]);
		}
	}
	
}

module.exports = { EmulatorApi };