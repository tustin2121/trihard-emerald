//

let $mainMenu;
let $titleMenu;

// Menu Functions


function initMenuV1() {
	$(`<li>Emergency Save</li>`).appendTo($mainMenu)
		.on('click', function(){
			
		});
	$(`<li>Open PC Storage</li>`).appendTo($mainMenu)
		.on('click', function(){
			
		});
	$(`<li>Skip Battles</li>`).appendTo($mainMenu)
		.addClass('unchecked')
		.on('click', function(){
			
		});
}

$(function(){
	$titleMenu = $('body div');
	$mainMenu = $('<ul>').appendTo('body');
	
	$('<li>Connect</li>').appendTo($titleMenu)
		.on('click', function(){
			
		});
});