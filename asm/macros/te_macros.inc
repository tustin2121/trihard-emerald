@ Message Box Types

	@ Sets the next messages as a dialogue text box
	.macro flagasdialog
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	.endm
	
	@ Sets the next messages as a dialogue text box
	.macro markasdialog
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	.endm
	
	@ Calls msgbox on a previously selected and loaded string.
	.macro msgbox_selected type=MSGBOX_DEFAULT
	callstd \type
	.endm

@ Select Pointer Functions

	@ Selects a string based on if the player is male or female.
	.macro selectpointer_ongender forMale:req, forFemale:req
	loadword MALE, \forMale 
	loadword FEMALE, \forFemale
	checkplayergender
	selectpointer 0, VAR_RESULT
	.endm
	
	@ Selects a string based on if the player is male or female.
	.macro selectyesnoanswer forYes:req, forNo:req
	loadword YES, \forYes 
	loadword NO, \forNo
	selectpointer 0, VAR_RESULT
	.endm
	
	.macro applymovement_gendered lid:req, forMale:req, forFemale:req
	loadword MALE, \forMale 
	loadword FEMALE, \forFemale
	checkplayergender
	selectpointer 0, VAR_RESULT @it says "string", but this works for pointers just as well
	applymovement \lid, 0
	.endm
	
	@ Calls a given function 
	.macro call_on_gender forMale:req, forFemale:req
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq \forMale
	compare VAR_RESULT, FEMALE
	call_if_eq \forFemale
	.endm

@ Convienence Macros

	@ Only use this in pokecenter tilesets, on the 2nd floor
	.macro pokecenter_sitonbed x:req, y:req
	setmetatileex \x, \y, 0x30C, 4, FALSE  @ set tile to bed, elevation 4
	.endm
	
	.macro trysteal item:req, num:req, flag:req
	@ If already stolen from, exit
	goto_if_set \flag, Common_EventScript_ReleaseEnd
	@ Check space for item
	checkitemspace \item, \num
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_FailTheftNoRoom
	@ Take the item
	giveitem_std \item, \num
	setflag \flag
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	incrementgamestat GAME_STAT_NUM_THINGS_STOLEN, \num
	.endm
