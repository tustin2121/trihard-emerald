// emulatorapi.js

const http = require('http');
const net = require('net');
const { parse:parseUrl } = require('url');
const fs = require('fs');
const { EventEmitter } = require('events');

const CALLBACK_URL = `http://localhost`;
const EMULATOR_URL = `http://localhost:5337`;

class Emulator {
	constructor() {
		this.symbolTable = null;
		this.reverseSymbolTable = null;
		this.varNameTable = null;
		this.flagNameTable = null;
		
		this.connection = null;
	}
	
	destroy() {
		if (this.connection) {
			this.connection.destroy();
		}
	}
	
	connectToBizhawk(callbackPort=52121) {
		this.connection = new BizhawkApiConnection(callbackPort);
		return Promise.resolve();
	}
	
	connectToGdb() {
		return new Promise((resolve, reject)=>{
			this.connection = new GdbSerialConnection();
			this.connection.once('connected', resolve);
		});
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
	
	_resolveSymbol(addr, strict=false) {
		// console.log(`_resolveSymbol(${addr}) => ${this.symbolTable && this.symbolTable[addr]}`);
		if (typeof addr === 'number') addr = addr.toString(16);
		if (/^[0-9A-F]{4,8}$/i.test(addr) && !strict) return addr; //already an address
		if (!this.symbolTable) return addr; //cannot resolve on a table we don't have
		let info = this.symbolTable[addr];
		if (!info) return strict?null:addr; //not in table
		return info;
	}
	
	readSymbols(...symList) {
		symList = symList.map((addr)=>this._resolveSymbol(addr,true)).filter(x=>x);
		return this.connection.readSymbols(symList);
	}
	
	readSymbolPointer(symbol, length) {
		let info = this._resolveSymbol(symbol);
		if (!info) throw new ReferenceError('Symbol not found: '+symbol);
		return this.connection.readSymbolPointer(info, length);
	}
	
	readMemory(addr, len) {
		addr = this._resolveSymbol(addr);
		if (len === undefined && typeof addr !== 'string') len = addr.size;
		if (typeof addr !== 'string') addr = addr.addr;
		return this.connection.readMemory(addr, len);
	}
	
	writeMemory(addr, data) {
		addr = this._resolveSymbol(addr);
		if (typeof addr !== 'string') addr = addr.addr;
		return this.connection.writeMemory(addr, data);
	}
}

class BizhawkApiConnection {
	constructor(port=52121) {
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
	
	destroy() {
		if (this.callbackServer) {
			this.callbackServer.close();
		}
		for (let cblist in this.callbackTable) {
			this._cleanupCallbacks(cblist[0]);
		}
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
	
	_cleanupCallbacks(windowid) {
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
	
	_queryEmulator(path, type) {
		if (type === undefined) {
			if (path.slice(0, 4) === 'Read') type = 'read';
			else type = 'command';
		}
		return new Promise((resolve, reject)=>{
			try {
				// console.log(`_queryEmulator => ${EMULATOR_URL}${path}`);
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
	
	_postToEmulator(path, body) {
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
	
	async readSymbols(symList) {
		let addrList = symList.map(x=>`${x.addr}/${x.size.toString(16)}`).join('/');
		
		let data = await this._queryEmulator(`/ReadByteRange/${addrList}`, 'data');
		let retList = [];
		let doff = 0;
		for (let sym of symList) {
			retList.push({ name:sym.name, size:sym.size, data:data.slice(doff, doff+sym.size) });
			doff += sym.size;
		}
		return retList;
	}
	
	async readSymbolPointer(symInfo, length) {
		return await this._queryEmulator(`/ReadByteRange/*${symInfo.addr}/${length.toString(16)}`, 'data');
	}
	
	readMemory(addr, len) {
		return this._queryEmulator(`/ReadByteRange/${addr}/${len.toString(16)}`, 'data');
	}
	
	writeMemory(addr, data) {
		return this._queryEmulator(`/WriteByteRange/${addr}/${data.toString('hex').toUpperCase()}`, 'command');
	}
}

const START_CHAR = 0x24; //$
const END_CHAR = 0x23; //#
const ESCAPE_CHAR = 0x7D; //}
const STAR_CHAR = 0x2A; //*
const ACK_CHAR = 0x2B; //+
const NACK_CHAR = 0x2D; //-
const INT_CHAR = 0x03; 

class GdbSerialConnection extends EventEmitter {
	constructor() {
		super();
		this._lastMessage = null;
		this.connected = false;
		this.serial = net.createConnection(2345, ()=>{
			console.log('Connected to GDBserver.');
			this.connected = true;
			this._sendCommand('c');
			this.emit('connected');
		});
		this.serial.on('end', ()=>{
			this.connected = false;
			this.serial = null;
		});
		this.serial.on('data', (data)=>{
			console.debug(`<# ${data.toString('hex')}`);
			for (let i = 0; i < data.length; i++) {
				if (data[i] === ACK_CHAR) {
					this.emit('ack');
					continue; //no further processing needed
				}
				if (data[i] === NACK_CHAR) { //retransmit
					this.serial.write(this._lastMessage);
					continue;
				}
				if (data[i] === INT_CHAR) { //dunno what to do with this
					this.emit('interrupt');
					console.error('Remote server sent interrupt! PANIC!!');
					continue;
				}
				if (data[i] === START_CHAR) {
					let end = i+1;
					while (end < data.length) {
						if (data[end] === END_CHAR) break;
						end++;
					}
					//TODO buffer if we don't find an end character
					try {
						let str = this._unwrap(data.slice(i, end+3));
						console.debug(`< ${str}`);
						this.serial.write('+');
						this.emit('message', str);
					} catch (e) {
						console.error(e);
						this.serial.write('-');
					}
					i = end+2;
					continue;
				}
				console.error('Misaligned stream!');
			}
		});
		this.serial.unref();
		this.serial.resume();
		this.serial.setNoDelay(true);
	}
	
	destroy() {
		if (this.serial) {
			this._sendCommand('D', 'ack').then(x=>{
				this.serial.end();
			});
		} 
	}
	
	/**
	 * 
	 * @param {string} cmd - The command to send to the remote GDB server.
	 * @param {string} expect - 'ack' for expecting acknoledgement, 'data' for expecting return data, null, for no expected response.
	 */
	_sendCommand(cmd, expect='ack') {
		if (!this.connected) return Promise.reject(new Error('Not connected!'));
		return new Promise((resolve, reject)=>{
			if (expect) {
				this.once('message', (data)=>{
					if (!data) {
						return reject(new Error('Remote server does not support the given command!'));
					}
					if (data.startsWith('E')) {
						return reject(new Error('Remote server responded with error code: '+data));
					}
					if (expect === 'ack' && data == 'OK') {
						return resolve(true);
					}
					if (expect === 'data') {
						return resolve(Buffer.from(data, "hex"));
					}
					resolve(data);
				});
			} else {
				this.once('ack', ()=>resolve(true));
			}
			this._lastMessage = this._wrap(cmd);
			console.debug(`> ${cmd}`);
			this.serial.write(this._lastMessage, (err)=>{
				if (err) reject(err);
			});
			console.debug(`># ${this._lastMessage.toString('hex')}`);
		});
	}
	
	_wrap(packet) {
		if (typeof packet !== 'string') throw new TypeError('_wrap must be passed a string!');
		let len = packet.length + 4;
		len += (packet.match(/[\$\#\}]/g) || []).length; //add 1 for each character that must be escaped
		
		let buf = Buffer.alloc(len);
		let off = 1;
		let checksum = 0;
		
		buf.writeUInt8(START_CHAR, 0); //$
		for (let i = 0; i < packet.length; i++) {
			let char = packet.charCodeAt(i) & 0xFF;
			if (char == START_CHAR || char == END_CHAR || char == ESCAPE_CHAR) { //$, #, or }
				buf.writeUInt8(ESCAPE_CHAR, off++);
				buf.writeUInt8(char ^ 0x20, off+i);
			} else {
				buf.writeUInt8(char, off+i);
			}
			checksum += char;
		}
		off += packet.length;
		buf.writeUInt8(END_CHAR, off); //#
		checksum %= 256;
		buf.write(checksum.toString(16), off+1, 'ascii');
		// buf.write('\n', off+2, 'ascii');
		return buf;
	}
	
	_unwrap(buf) {
		if (!Buffer.isBuffer(buf)) throw new TypeError('_unwrap must be passed a Buffer!');
		if (buf[0] !== START_CHAR) throw new TypeError('Expected start byte! '+buf.toString('hex'));
		if (buf[buf.length-3] !== END_CHAR) throw new TypeError('Expected end byte! '+buf.toString('hex'));
		
		let checksum = 0;
		for (let i = 1; i < buf.length-3; i++) {
			checksum += buf[i];
		}
		if (checksum % 256 !== Number.parseInt(buf.toString('ascii', buf.length-2), 16))
			throw new TypeError('Checksum does not match!');
		
		let str = '';
		for (let i = 1; i < buf.length-3; i++) {
			let char = buf[i];
			if (char === ESCAPE_CHAR) {
				char = buf[++i] ^ 0x20; //consume escaped character
			}
			str += String.fromCharCode(char);
			if (buf[i+1] === STAR_CHAR && buf[i+2] > 28 && buf[i+2] < 126) {
				i++; //consume star
				let num = buf[++i] - 28; //consume count number
				for (let n = 1; n < num; n++) {
					str += String.fromCharCode(char);
				}
			}
		}
		return str;
	}
	
	async readSymbols(symList) {
		let retList = [];
		for (let sym of symList) {
			let data = await this._sendCommand(`m${sym.addr.toString(16)},${sym.size.toString(16)}`, 'data');
			retList.push({ name:sym.name, size:sym.size, data });
		}
		return retList;
	}
	
	async readSymbolPointer(symInfo, len) {
		let ptr = await this._sendCommand(`m${symInfo.addr.toString(16)},4`, 'hex');
		return await this._sendCommand(`m${ptr},${len.toString(16)}`, 'data');
	}
	
	readMemory(addr, len) {
		return this._sendCommand(`m${addr},${len.toString(16)}`, 'data');
	}
	
	writeMemory(addr, data) {
		return this._sendCommand(`M${addr},${data.length}:${data.toString('hex')}`);
	}
}

/*
// TODO: port this code into the BizhawkApiConnection

class EmulatorApi {
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
}
//*/

module.exports = { Emulator };