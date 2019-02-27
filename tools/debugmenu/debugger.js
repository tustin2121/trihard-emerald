// debugger.js


const emulator = require('electron').remote.getGlobal('emulator');

let updateLoop = null;

const FLAG_BYTE_COUNT = 300;
const FLAG_COUNT = FLAG_BYTE_COUNT*8;
const VAR_COUNT = 256;
let m_flags = new Array(FLAG_COUNT);
let m_vars = new Array(VAR_COUNT);

function printSymbolOrAddr(num) {
	let sym = emulator.lookupSymbol(num);
	if (sym) return sym;
	return ('00000000'+num.toString(16)).slice(-8);
}
function printAddr(num) {
	return ('00000000'+num.toString(16)).slice(-8);
}

function fillInContext($ctx, data) {
	let stackDepth = data.readUInt8(0);
	$ctx.find('[name=stackDepth]').text(stackDepth);
	let mode = data.readUInt8(1);
	$ctx.find('.activeMode').removeClass('activeMode');
	switch (mode) {
		case 0: 
			$ctx.find('[name=mode]').text('none'); 
			break;
		case 1: 
			$ctx.find('[name=mode]').text('script');
			$ctx.find('[name=scriptPtr]').addClass('activeMode'); 
			break;
		case 2: 
			$ctx.find('[name=mode]').text('native');
			$ctx.find('[name=nativePtr]').addClass('activeMode'); 
			break;
	}
	
	$ctx.find('[name=comparisonResult]').text(data.readUInt8(2));
	$ctx.find('[name=nativePtr]').val(printSymbolOrAddr(data.readUInt32LE(4)));
	$ctx.find('[name=scriptPtr]').val(printSymbolOrAddr(data.readUInt32LE(8)));
	for (let i = 0; i < 20; i++) {
		let $frame = $ctx.find(`.stack [idx=${i}]`);
		$frame.text(printSymbolOrAddr(data.readUInt32LE(12+(i*4))));
		$frame.toggleClass('active', i < stackDepth);
	}
	$ctx.find('[name=cmdTable]').val(printSymbolOrAddr(data.readUInt32LE(92)));
	
	let dview = '';
	for (let i = 0; i < 4; i++) {
		let d = data.readUInt32LE(100+(i*4));
		let sym = emulator.lookupSymbol(d);
		if (sym) {
			dview += `<a href="#" title="${sym}">${printAddr(d)}</a> `;
		} else {
			dview += `${printAddr(d)} `;
		}
	}
	
	let x = printAddr(data.readUInt32LE(100)) + ' ';
	x += printAddr(data.readUInt32LE(104)) + ' ';
	x += printAddr(data.readUInt32LE(108)) + ' ';
	x += printAddr(data.readUInt32LE(112));
	$ctx.find('[name=data]').html(x);
}

function fillFromMainData(data) {
	$('.mainContext [name=mainCb1]').val(printSymbolOrAddr(data.readUInt32LE(0)));
	$('.mainContext [name=mainCb2]').val(printSymbolOrAddr(data.readUInt32LE(4)));
	$('.mainContext [name=savedCb]').val(printSymbolOrAddr(data.readUInt32LE(8)));
}

function fillFromFlagBlock(data) {
	let flags = data.slice(0, 300);
	let vars = data.slice(300, 300+(256*2));
	
	$('.changeBin .changed').removeClass('changed');
	for (let i = 0; i < FLAG_BYTE_COUNT; i++) {
		let b = flags.readUInt8(i);
		for (let j = 0; j < 8; j++) {
			let idx = (i*8) + j;
			let val = !!(b & 1<<j);
			if (m_flags[idx] !== val) {
				if (m_flags[idx] !== undefined) {
					addFlagChange(idx, m_flags[idx], val);
				}
				m_flags[idx] = val;
			}
		}
	}
	for (let i = 0; i < VAR_COUNT; i++) {
		let val = vars.readUInt16LE(i*2);
		if (m_vars[i] !== val) {
			// The following variables (related to step counts) change so often that 
			// we might as well keep them separate and NOT flash a change color
			if (i == 0x2a || i == 0x2b) {
				$(`#varBin [vid=${i.toString(16)}] .curr`).text(val);
			}
			else if (m_vars[i] !== undefined) {
				addVarChange(i, m_vars[i], val);
			}
			m_vars[i] = val;
		}
	}
}

function fillFromSaveBlock(data) {}

function fillInContexts(dataList) {
	// console.log('fillInContexts', dataList);
	for (let data of dataList) {
		switch (data.name) {
			case 'sScriptContext1Status': {
				let status = data.data.readUInt8(0);
				switch (status) {
					case 0: $('#ctx1 .status').attr('status', 'enabled'); break;
					case 1: $('#ctx1 .status').attr('status', 'stopped'); break;
					case 2: $('#ctx1 .status').attr('status', 'standby'); break;
				}
			} break;
			case 'sScriptContext2Enabled': {
				let status = data.data.readUInt8(0);
				$('#ctx2 .status').attr('status', status?'enabled':'disabled');
			} break;
			case 'sScriptContext1':
				fillInContext($('#ctx1'), data.data);
				break;
			case 'sScriptContext2':
				fillInContext($('#ctx2'), data.data);
				break;
			case 'gMain':
				fillFromMainData(data.data);
				break;
			case 'gSaveBlock1Ptr':
				fillFromSaveBlock(data.data);
				break;
		}
	}
}

function addFlagChange(flagid, prev, curr) {
	const flagName = emulator.getFlagName(flagid);
	console.log(`${flagName} (#${flagid.toString(16)}) has been ${curr?'set':'cleared'}!`);
	const $bin = $('#flagBin');
	let $flag = $bin.find(`[fid=${flagid.toString(16)}]`);
	if (!$flag.length) {
		$flag = $(`<label fid="${flagid.toString(16)}">${flagName} (#${flagid.toString(16)}) <input type="checkbox"/></label>`);
		$flag.prependTo($bin.find('bin'));
	}
	$flag.find('input').prop('checked', curr);
	$flag.addClass('changed');
}
function addVarChange(varid, prev, curr) {
	const varName = emulator.getVarName(varid);
	console.log(`${varName} (#${varid.toString(16)}) changed from ${prev} to ${curr}!`);
	const $bin = $('#varBin');
	let $var = $bin.find(`[vid=${varid.toString(16)}]`);
	if (!$var.length) {
		$var = $(`<label vid="${varid.toString(16)}">${varName} (#${varid.toString(16)}) <span class="prev">?</span>--&gt;<span class="curr">?</span></label>`);
		$var.prependTo($bin.find('bin'));
	}
	// $var.find('input').val(curr);
	$var.find('.curr').text(curr);
	$var.find('.prev').text(prev);
	$var.addClass('changed');
}

$(function(){
	for (let i = 0; i < 20; i++) {
		$('.scriptContext .stack').append(`<stackframe idx=${i}>00000000</stackframe>`);
	}
	
	$('#varBin button[name=clearVars]').on('click', ()=>$('#varBin bin').empty());
	$('#flagBin button[name=clearFlags]').on('click', ()=>$('#flagBin bin').empty());
	
	window.addEventListener('beforeunload', ()=>{
		emulator.cleanupCallbacks(__window_id__);
	});
	updateLoop = setInterval(()=>{
		emulator.readSymbols(
			'sScriptContext1Status', 'sScriptContext1', 
			'sScriptContext2Enabled', 'sScriptContext2',
			'gMain',
		).then(fillInContexts);
		
		let ptr = emulator._resolveSymbol('gSaveBlock1Ptr');
		emulator.queryEmulator(`/ReadByteRange/*${ptr.addr}+1270/${(300+(256*2)).toString(16)}`, 'data').then(fillFromFlagBlock);
	}, 200);
});
