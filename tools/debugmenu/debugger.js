// debugger.js


const emulator = require('electron').remote.getGlobal('emulator');

let updateLoop = null;

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
	switch (mode) {
		case 0: $ctx.find('[name=mode]').text('none'); break;
		case 1: $ctx.find('[name=mode]').text('script'); break;
		case 2: $ctx.find('[name=mode]').text('native'); break;
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
	let x = printAddr(data.readUInt32LE(100)) + '&nbsp;';
	x += printAddr(data.readUInt32LE(104)) + ' ';
	x += printAddr(data.readUInt32LE(108)) + '&nbsp;';
	x += printAddr(data.readUInt32LE(112));
	$ctx.find('[name=data]').html(x);
}

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
		}
	}
}

$(function(){
	for (let i = 0; i < 20; i++) {
		$('.scriptContext .stack').append(`<stackframe idx=${i}>00000000</stackframe>`);
	}
	
	window.addEventListener('beforeunload', ()=>{
		emulator.cleanupCallbacks(__window_id__);
	});
	updateLoop = setInterval(()=>{
		emulator.readSymbols('sScriptContext1Status', 'sScriptContext1', 'sScriptContext2Enabled', 'sScriptContext2').then(fillInContexts);
	}, 200);
});
