//

const DEBUG_MENU_LOC = 0x02020004;
const emulator = require('electron').remote.getGlobal('emulator');
const __window_id__ = require('electron').remote.getCurrentWindow().__window_id__;
let $titleMenu, $mainMenu, $subMenus = {};

const DebugHandle_EmergencySave = 1;
const DebugHandle_ShowPCBox = 2;
const DebugHandle_WarpRequest = 3;
const DebugHandle_ReloadMap = 4;
const DebugHandle_ShowCredits = 5;
const DebugHandle_GetRandomSeeds = 6;
const DebugHandle_SetRandomSeeds = 7;
const DebugHandle_SetWeather = 8;
const DebugHandle_ShowSoundTest = 9;
const DebugHandle_SetFlag = 10;
const DebugHandle_SetVar = 11;

// Menu Functions
function initMenuV1() {
	{
		let $m = $mainMenu = $('<ul>').appendTo('body');
		$(`<li>Emergency Save</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_EmergencySave });
			});
		$(`<li>Open PC Storage</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ShowPCBox });
			});
		$(`<li>Play Credits</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ShowCredits });
			});
		$(`<li>Open Sound Test</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ShowSoundTest });
			});
		$(`<li>Set Weather to...</li>`).appendTo($m)
			.on('click', function(){ switchMenu('weather'); });
		$(`<li>Debug Options...</li>`).appendTo($m)
			.on('click', function(){ switchMenu('debugopts'); });
		$(`<li>Set Flag...</li>`).appendTo($m)
			.on('click', function(){ switchMenu('setflag'); });
		$(`<li>Set Var...</li>`).appendTo($m)
			.on('click', function(){ switchMenu('setvar'); });
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
		let $m = $subMenus['weather'] = $('<ul>').appendTo('body');
		let $opts = [
			$(`<li>No Weather</li>`).attr('value', 0),
			$(`<li>Cloudy</li>`).attr('value', 1),
			$(`<li>Sunny</li>`).attr('value', 2),
			$(`<li>Light Rain</li>`).attr('value', 3),
			$(`<li>Medium Rain</li>`).attr('value', 5),
			$(`<li>Heavy Rain</li>`).attr('value', 13),
			$(`<li>Drought</li>`).attr('value', 12),
			$(`<li>Snow</li>`).attr('value', 4),
			$(`<li>Ash fall</li>`).attr('value', 7),
			$(`<li>Sandstorm</li>`).attr('value', 8),
			$(`<li>Fog 1</li>`).attr('value', 6),
			$(`<li>Fog 2</li>`).attr('value', 9),
			$(`<li>Fog 3</li>`).attr('value', 10),
			$(`<li>Shade</li>`).attr('value', 11),
			$(`<li>Bubbles</li>`).attr('value', 14),
			$(`<li>Power Out</li>`).attr('value', 15),
			$(`<li>Alternating</li>`).attr('value', 16),
			$(`<li>[Route 119]</li>`).attr('value', 20),
			$(`<li>[Route 123]</li>`).attr('value', 20),
		];
		$opts.forEach($x=>$x.appendTo($m)
			.attr('name', 'weatherid')
			.on('click', function(){
			writeInterrupts({ funcId: DebugHandle_SetWeather, args:[
				Number.parseInt($(this).val())
			] });
			switchMenu();
		}));
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
	}{
		let $m = $subMenus['setflag'] = $('<ul>').appendTo('body');
		let $n = $(`<input type='number' value="0" />`);
		$(`<p>Flag ID: </p>`).appendTo($m)
			.append($n);
		$(`<li>Set Flag</li>`).appendTo($m)
			.on('click', function(){
				let id = $n.val();
				writeInterrupts({ 
					funcId: DebugHandle_SetFlag,
					args: [1, 0, (id >> 0) & 0xFF, (id >> 8) & 0xFF],
				});
				switchMenu(); 
			});
		$(`<li>Clear Flag</li>`).appendTo($m)
			.on('click', function(){
				let id = $n.val();
				writeInterrupts({ 
					funcId: DebugHandle_SetFlag,
					args: [0, 0, (id >> 0) & 0xFF, (id >> 8) & 0xFF],
				});
				switchMenu(); 
			});
		$(`<li>Cancel</li>`).appendTo($m)
			.on('click', function(){
				switchMenu(); 
			});
	}{
		let $m = $subMenus['setvar'] = $('<ul>').appendTo('body');
		let $n = $(`<input type='number' value="0" />`);
		let $v = $(`<input type='number' value="0" />`);
		$(`<p>Var ID: </p>`).appendTo($m)
			.append($n)
			.append($v);
		$(`<li>Set Variable</li>`).appendTo($m)
			.on('click', function(){
				let id = $n.val();
				let val = $v.val();
				writeInterrupts({ 
					funcId: DebugHandle_SetVar,
					args: [
						(val >> 0) & 0xFF, (val >> 8) & 0xFF,
						( id >> 0) & 0xFF, ( id >> 8) & 0xFF,
					],
				});
				switchMenu(); 
			});
		$(`<li>Cancel</li>`).appendTo($m)
			.on('click', function(){
				switchMenu(); 
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
	}).catch(x=>console.error(x));
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
	emulator.writeMemory(DEBUG_MENU_LOC, buf);
}
function writeInterruptFlags(flags) {
	let buf = Buffer.alloc(0x02);
	buf.writeUInt16LE(flags), 0;
	emulator.writeMemory(DEBUG_MENU_LOC+14, buf);
}

function checkInterrupt() {
	readInterrupts().then(res=>{
		if (res.returnVal < 0) {
			console.log("Error executing previous item!");
		}
	});
}


$(function(){
	/*window.addEventListener('beforeunload', ()=>{
		emulator.cleanupCallbacks(__window_id__);
	});
	emulator.registerOnWrite({ 
		winId:__window_id__,
		addr: DEBUG_MENU_LOC, len: 1,
		name: 'gDebugInterrupt',
		cb: checkInterrupt,
	});
	//*/
	
	$titleMenu = $('body div');
	$('<li>Connect to Bizhawk</li>').appendTo($titleMenu)
		.on('click', function(){
			emulator.connectToBizhawk(52113).then(()=>findConnect());
		});
	
	$('<li>Connect to mGBA GDB Port</li>').appendTo($titleMenu)
		.on('click', function(){
			emulator.connectToGdb().then(()=>findConnect());
		});
});