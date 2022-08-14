@ Message Box Types

	@ Sets the next messages as a dialogue text box
	.macro flagasdialog
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	.endm
	
	@ Sets the next messages as a dialogue text box
	.macro markasdialog tailOff=0
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	.if \tailOff != 0
	setvar VAR_DIALOG_TAIL_OFFSET, (\tailOff + 32)
	.endif
	.endm
	
	@ Calls msgbox on a previously selected and loaded string.
	.macro msgbox_selected type=MSGBOX_DEFAULT
	callstd \type
	.endm

@ Select Pointer Functions
	
	@ Selects a pointer from the given selection
	.macro selectpointer_from var:req, entry1:req, entry2:req, entry3=0, entry4=0
	loadword 0, \entry1 
	loadword 1, \entry2
	.if \entry3 != 0
		loadword 2, \entry3
	.endif
	.if \entry4 != 0
		loadword 3, \entry4
	.endif
	selectpointer 0, \var
	.endm
	
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
	
	.macro select_if condition:req, forTrue:req, forFalse:req
	loadword TRUE, \forTrue
	loadword FALSE, \forFalse
	selectpointer_conditionally \condition
	.endm
	
	.macro select_if_unset flag:req, forTrue:req, forFalse:req
	checkflag \flag
	select_if 0, \forTrue, \forFalse
	.endm

	.macro select_if_set flag:req, forTrue:req, forFalse:req
	checkflag \flag
	select_if 1, \forTrue, \forFalse
	.endm

	.macro select_if_lt forTrue:req, forFalse:req @ LESS THAN
	select_if 0, \forTrue, \forFalse
	.endm	

	.macro select_if_eq forTrue:req, forFalse:req @ EQUAL
	select_if 1, \forTrue, \forFalse
	.endm

	.macro select_if_gt forTrue:req, forFalse:req @ GREATER THAN
	select_if 2, \forTrue, \forFalse
	.endm

	.macro select_if_le forTrue:req, forFalse:req @ LESS THAN OR EQUAL
	select_if 3, \forTrue, \forFalse
	.endm

	.macro select_if_ge forTrue:req, forFalse:req @ GREATER THAN OR EQUAL
	select_if 4, \forTrue, \forFalse
	.endm

	.macro select_if_ne forTrue:req, forFalse:req @ NOT EQUAL
	select_if 5, \forTrue, \forFalse
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
	.macro trysteal_setcheck ptr:req
	loadword 3, \ptr
	.endm
	
	.macro trysteal item:req, num:req, flag:req
	@ Check if we can steal this item
	checksteal \flag
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseEnd
	@ Check space for item
	checkitemspace \item, \num
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_FailTheftNoRoom
	@ Take the item
	giveitem_std \item, \num
	setflag \flag
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	incrementgamestat GAME_STAT_NUM_THINGS_STOLEN, \num
	.endm
	
	.macro trysteal_money amount:req, flag:req
	@ Check if we can steal this item
	checksteal \flag
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseEnd
	@ Take the item
	setvar VAR_0x8001, \amount
	givemoney VAR_0x8001, 0
	call Common_EventScript_ReportTheftMoney
	setflag \flag
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	incrementgamestat GAME_STAT_NUM_THINGS_STOLEN, \num
	.endm
	
	.macro faceoriginaldir
	applymovement THIS_EVENT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	.endm

	.macro askforboat ask:req, decline:req, nomoney:req, embark:req
	loadword 0, \ask
	loadword 1, \decline
	loadword 2, \nomoney
	loadword 3, \embark
	call Common_EventScript_AskForBoatTransport
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_ReleaseEnd
	.endm

