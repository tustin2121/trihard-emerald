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
const DebugHandle_SetLegendaryFight = 12;
const DebugHandle_GiveDebugParty = 13;
const DebugHandle_TestScript = 14;
const DebugHandle_SwapGenders = 15;
const DebugHandle_RenamePlayer = 16;
const DebugHandle_UnmarkBoxMon = 17;
const DebugHandle_ClearStats = 18;
const DebugHandle_SetTimeOfDay = 19;

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
		$(`<li>Reload Map</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ReloadMap });
			});
		$m.append('<hr/>');
		$(`<li>Debug Options…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('debugopts'); });
		$(`<li>Set Flag…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('setflag'); });
		$(`<li>Set Var…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('setvar'); });
		$(`<li>Set Weather to…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('weather'); });
		$(`<li>Warp to Map…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('gowarp'); });
		$(`<li>Other Actions…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('submenu1'); });
		$(`<li>Run Test Script…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('runscript'); });
	}{
		let $m = $subMenus['submenu1'] = $('<ul>').appendTo('body');
		$(`<li>&lt; Back</li>`).appendTo($m)
			.on('click', function(){ switchMenu(); });
		$(`<li>Replace Party with Debug Team</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_GiveDebugParty });
				switchMenu();
			});
			$(`<li>Play Credits</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ShowCredits });
				switchMenu();
			});
		$(`<li>Change Player Gender/Form…</li>`).appendTo($m)
			.on('click', function(){
				switchMenu('genders');
			});
		$(`<li>Change Player Name</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_RenamePlayer });
				switchMenu();
			});
		$(`<li>Open Sound Test</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ShowSoundTest });
				switchMenu();
			});
		$(`<li>Set Legendary Fight…</li>`).appendTo($m)
			.on('click', function(){ switchMenu('legendary'); });
		$(`<li>Unset Mourn Flag on All Boxed Mons</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_UnmarkBoxMon });
				switchMenu();
			});
		$(`<li>Reset Game Stats</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_ClearStats });
				switchMenu();
			});
		$(`<li>Set Time of Day…</li>`).appendTo($m)
			.on('click', function(){
				switchMenu('timeofday');
			});
	}{
		let $m = $subMenus['runscript'] = $('<ul>').appendTo('body');
		$(`<li>&lt; Back</li>`).appendTo($m)
			.on('click', function(){ switchMenu(); });
		let $v = $(`<input type='number' value="0" min="0" max="255" />`);
		$(`<p>`).appendTo($m)
			.append(`Script ID: `).append($v);
		$(`<li>Run Script</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_TestScript, args:[$v.val()] });
				switchMenu();
			});
		$m.append('<hr/>');
		$(`<li>Run Test Script 0</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_TestScript, args:[0] });
				switchMenu();
			});
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
		$(`<li>Cancel</li>`).appendTo($m)
			.on('click', function(){
				switchMenu(); 
			});
	}{
		let $m = $subMenus['genders'] = $('<ul>').appendTo('body');
		$(`<li>&lt; Back</li>`).appendTo($m)
			.on('click', function(){ switchMenu(); });
		let $opts = [
			$(`<li>Male / Team Skull</li>`).attr('value', 0),
			$(`<li>Male / Aqua Bandanna</li>`).attr('value', 2),
			$(`<li>Male / Aqua Uniform</li>`).attr('value', 4),
			$(`<li>Male / Final Outfit</li>`).attr('value', 6),
			$(`<li>Female / Team Skull</li>`).attr('value', 1),
			$(`<li>Female / Aqua Bandanna</li>`).attr('value', 3),
			$(`<li>Female / Aqua Uniform</li>`).attr('value', 5),
			$(`<li>Female / Final Outfit</li>`).attr('value', 7),
		];
		$opts.forEach($x=>$x.appendTo($m)
			.attr('name', 'genderid')
			.on('click', function(){
			writeInterrupts({ funcId: DebugHandle_SwapGenders, args:[
				Number.parseInt($(this).val())
			] });
			switchMenu();
		}));
	}{
		let $m = $subMenus['weather'] = $('<ul>').appendTo('body');
		$(`<li>&lt; Back</li>`).appendTo($m)
			.on('click', function(){ switchMenu(); });
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
		let $m = $subMenus['legendary'] = $('<ul>').appendTo('body');
		$(`<li>&lt; Cancel</li>`).appendTo($m)
			.on('click', function(){ switchMenu(); });
		$(`<li>Before</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetLegendaryFight, args:[0] });
				switchMenu();
			});
		$(`<li>During</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetLegendaryFight, args:[1] });
				switchMenu();
			});
		$(`<li>After</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetLegendaryFight, args:[2] });
				switchMenu();
			});
		$(`<li>After Gym</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetLegendaryFight, args:[3] });
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
	}{
		let $m = $subMenus['setflag'] = $('<ul>').appendTo('body');
		let $n = $(`<input type='text' value="0" />`)
			.on('change', function(){
				let n = Number.parseInt($n.val(), 16);
				$n.toggleClass('invalid', Number.isNaN(n));
			});
		$(`<p>Flag ID: 0x</p>`).appendTo($m)
			.append($n);
		$(`<li>Set Flag</li>`).appendTo($m)
			.on('click', function(){
				let id = Number.parseInt($n.val(), 16);
				if (Number.isNaN(id)) return;
				writeInterrupts({ 
					funcId: DebugHandle_SetFlag,
					args: [1, 0, (id >> 0) & 0xFF, (id >> 8) & 0xFF],
				});
				switchMenu(); 
			});
		$(`<li>Clear Flag</li>`).appendTo($m)
			.on('click', function(){
				let id = Number.parseInt($n.val(), 16);
				if (Number.isNaN(id)) return;
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
		$m.append('<hr/>');
		$(`<li>Give Badge 1 (Cut)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x67, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 2 (Flash)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x68, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 3 (Rock Smash)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x69, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 4 (Strength)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x6A, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 5 (Surf)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x6B, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 6 (Fly)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x6C, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 7 (Dive)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x6D, 0x08], });
				switchMenu(); 
			});
		$(`<li>Give Badge 8 (Waterfall)</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ funcId: DebugHandle_SetFlag, args: [1, 0, 0x6E, 0x08], });
				switchMenu(); 
			});
	}{
		let $m = $subMenus['setvar'] = $('<ul>').appendTo('body');
		let $n = $(`<input type='text' value="0" />`)
			.on('change', function(){
				let n = Number.parseInt($n.val(), 16);
				$n.toggleClass('invalid', Number.isNaN(n));
			});
		let $v = $(`<input type='number' value="0" />`);
		$(`<p>`).appendTo($m)
			.append(`Var ID: 0x`).append($n).append('<br/>')
			.append(`Value: `).append($v);
		$(`<li>Set Variable</li>`).appendTo($m)
			.on('click', function(){
				let id = Number.parseInt($n.val(), 16);
				if (Number.isNaN(id)) return;
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
	}{
		let $m = $subMenus['gowarp'] = $('<ul>').appendTo('body');
		let $group = $(`<input type='number' value="0" max="128" min="0" />`);
		let $id    = $(`<input type='number' value="0" max="128" min="0" />`);
		let $warp  = $(`<input type='number' value="0" max="128" min="0" />`);
		$(`<p>`).appendTo($m)
			.append(`Group: `).append($group).append('<br/>')
			.append(`MapId: `).append($id).append('<br/>')
			.append(`Warp: `).append($warp);
		$(`<li>Warp</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ 
					funcId: DebugHandle_WarpRequest,
					args: [
						$group.val(),
						$id.val(),
						$warp.val(),
						0xFF, 0xFF,
					],
				});
				switchMenu(); 
			});
		$(`<li>Cancel</li>`).appendTo($m)
			.on('click', function(){
				switchMenu(); 
			});
		$m.append(`<hr>`);
		$(`<li>Warp to Test Map</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ 
					funcId: DebugHandle_WarpRequest,
					args: [33, 2, 0, 0xFF, 0xFF],
				});
				switchMenu();
			});
		$(`<li>Warp to Slateport</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ 
					funcId: DebugHandle_WarpRequest,
					args: [0, 1, 0, 0xFF, 0xFF],
				});
				switchMenu();
			});
	}{
		let $m = $subMenus['timeofday'] = $('<ul>').appendTo('body');
		let $hour = $(`<input type='number' value="0" max="24" min="0" />`);
		let $min  = $(`<input type='number' value="0" max="60" min="0" />`);
		$(`<p>`).appendTo($m)
			.append(`Hour: `).append($hour).append('<br/>')
			.append(`Minute: `).append($min);
		$(`<li>Warp</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ 
					funcId: DebugHandle_SetTimeOfDay,
					args: [
						$hour.val(),
						$min.val(),
					],
				});
				switchMenu(); 
			});
		$(`<li>Cancel</li>`).appendTo($m)
			.on('click', function(){
				switchMenu(); 
			});
		$m.append(`<hr>`);
		$(`<li>Set to Noon</li>`).appendTo($m)
			.on('click', function(){
				writeInterrupts({ 
					funcId: DebugHandle_SetTimeOfDay,
					args: [12, 0],
				});
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