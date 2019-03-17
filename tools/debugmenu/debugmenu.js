//

const DEBUG_MENU_LOC = 0x02020004;
const emulator = require('electron').remote.getGlobal('emulator');
const __window_id__ = require('electron').remote.getCurrentWindow().__window_id__;
let $titleMenu, $mainMenu, $subMenus = {};

// Menu Functions
function initMenuV1() {
	{
		let $m = $mainMenu = $('<ul>').appendTo('body');
		$(`<li>Emergency Save</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId:1 });
			});
		$(`<li>Open PC Storage</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId:2 });
			});
		$(`<li>Debug Options</li>`).appendTo($m)
			.on('click', function(){ switchMenu('debugopts'); });
	}{
		let $m = $subMenus['debugopts'] = $('<ul>').appendTo('body');
		$(`<li>Skip Battles</li>`).appendTo($m)
			.addClass('unchecked')
			.attr('name', 'flagBattles')
			.on('click', function(){
				$(this).toggleClass('unchecked');
				$(this).toggleClass('checked');
			});
		$(`<li>Enable Whiteout</li>`).appendTo($m)
			.addClass('unchecked')
			.attr('name', 'flagWhiteout')
			.on('click', function(){
				$(this).toggleClass('unchecked');
				$(this).toggleClass('checked');
			});
		$(`<li>Commit</li>`).appendTo($m)
			.on('click', function(){
				let val = 0;
				val |= ($(`[name=flagBattles]`).hasClass('checked')?1:0) << 0;
				val |= ($(`[name=flagWhiteout]`).hasClass('checked')?1:0) << 0;
				writeInterruptFlags(val);
				switchMenu(); 
			});
	}{
		let $m = $subMenus['forceopts'] = $('<ul>').appendTo('body');
		$(`<li>Text Speed: </li>`).appendTo($m)
			.attr('name', 'textspd')
			.on('click', function(){
				
			});
		$(`<li>Battle Scene</li>`).appendTo($m)
			.attr('name', 'banims')
			.on('click', function(){
				
			});
		$(`<li>Battle Shift Style</li>`).appendTo($m)
			.attr('name', 'bstyle')
			.on('click', function(){
				
			});
		$(`<li>Sound Stereo</li>`).appendTo($m)
			.attr('name', 'sound')
			.on('click', function(){
				
			});
	}
	switchMenu();
}

function switchMenu(id) {
	$('body').children().hide();
	if (id) {
		$subMenus[id].show();
	} else {
		$mainMenu.show();
	}
}

function findConnect() {
	emulator.readMemory(DEBUG_MENU_LOC-4, 0x04).then((data)=>{
		let val = data.readUInt16LE(2);
		switch (val) {
			case 0xAA50: initMenuV1(); break;
			default:
				alert("This ROM does not have a debug menu, or the menu is not supported!");
				break;
		}
	});
}

function readInterrupts() {
	return emulator.readMemory(DEBUG_MENU_LOC, 0x10).then((data)=>{
		data = Buffer.from(data); //No idea why this is needed, but it is...
		return {
			raw: data,
			funcId: data.readUint8(0),
			returnVal: data.readUint8(1),
			args: [ 
				data.readUint8(2), data.readUint8(3), 
				data.readUint8(4), data.readUint8(5), 
				data.readUint8(6), data.readUint8(7), 
				data.readUint8(8), data.readUint8(9), 
				data.readUint8(10), data.readUint8(11), 
				data.readUint8(12), data.readUint8(13), 
			],
			flags: data.readUint16LE(14),
		};
	});
}

function writeInterrupts({ funcId=0, args=[] }) {
	let buf = Buffer.alloc(0x10-2);
	buf.writeUInt8(funcId, 0);
	buf.writeUInt8(0, 1);
	for (let i = 0; i < 12; i++) {
		buf.writeUInt8(args[i] || 0, 2+i);
	}
	emulator.queryEmulator(`/WriteByteRange/${DEBUG_MENU_LOC.toString(16)}/${buf.toString('hex')}`, 'command');
}
function writeInterruptFlags(flags) {
	let buf = Buffer.alloc(0x02);
	buf.writeUInt16LE(flags), 0;
	emulator.queryEmulator(`/WriteByteRange/${(DEBUG_MENU_LOC+14).toString(16)}/${buf.toString('hex')}`, 'command');
}

function checkInterrupt() {
	readInterrupts().then(res=>{
		if (res.returnVal < 0) {
			console.log("Error executing previous item!");
		}
	});
}


$(function(){
	window.addEventListener('beforeunload', ()=>{
		emulator.cleanupCallbacks(__window_id__);
	});
	/*
	emulator.registerOnWrite({ 
		winId:__window_id__,
		addr: DEBUG_MENU_LOC, len: 1,
		name: 'gDebugInterrupt',
		cb: checkInterrupt,
	});
	//*/
	
	$titleMenu = $('body div');
	$('<li>Connect</li>').appendTo($titleMenu)
		.on('click', function(){
			findConnect();
		});
});