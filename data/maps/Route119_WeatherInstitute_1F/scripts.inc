Route119_WeatherInstitute_1F_MapScripts:: @ 826FA86
	map_script MAP_SCRIPT_ON_LOAD, Route119_WeatherInstitute_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route119_WeatherInstitute_1F_FrameTable
	.byte 0

@ -----------------------------------------------------

Route119_WeatherInstitute_1F_OnLoad:
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_26FA98
	end

Route119_WeatherInstitute_1F_EventScript_26FA9J:
	setobjectxyperm 8, 8, 10
	return

@ -----------------------------------------------------

Route119_WeatherInstitute_1F_OnTransition: @ 826FA8C
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_26FA9J
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_le Route119_WeatherInstitute_1F_EventScript_26FA98
	end

Route119_WeatherInstitute_1F_EventScript_26FA98: @ 826FA98
	setobjectxyperm 5, 0, 5
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	setflag FLAG_SCENE_FORCE_AQUA_THEME
	return

@ -----------------------------------------------------

Route119_WeatherInstitute_1F_FrameTable:
	map_script_2 VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_StartHeist
	.2byte 0

#define LID_AQUA_BOY 6
#define LID_SHELLY 8

Route119_WeatherInstitute_1F_StartHeist:
	lockall
	@
	applymovement LID_SHELLY, Route119_WeatherInstitute_1F_Movement_StartHeist1
	delay 16
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceDown
	waitmovement LID_AQUA_BOY
	applymovement LID_AQUA_BOY, Common_Movement_ExclamationMarkAndWait
	waitmovement LID_AQUA_BOY
	waitmovement LID_SHELLY
	setobjectxyperm LID_SHELLY, 40, 0
	moveobjectoffscreen LID_SHELLY
	@
	msgbox Route119_WeatherInstitute_1F_Text_StartHeist2, MSGBOX_CDIALOG
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	releaseall
	end

Route119_WeatherInstitute_1F_Text_StartHeist2:
	.string "{AQUA_BOY}: Oh! {PLAYER}!\n"
	.string "You're just in time!\p"
	.string "We're here to steal some weather\n"
	.string "sensing Pokémon or something.\p"
	.string "I don't know, just follow Shelly up-\n"
	.string "stairs and take out anyone in your way.$"

Route119_WeatherInstitute_1F_Movement_StartHeist1:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

#undef LID_AQUA_BOY
#undef LID_SHELLY

@ -----------------------------------------------------
@ People

Route119_WeatherInstitute_1F_EventScript_26FAA4:: @ 826FAA4
	lock
	faceplayer
	markasdialog
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FABE
	compare VAR_SLEPT_DURING_WI_HEIST, 1
	goto_if_gt Route119_WeatherInstitute_1F_EventScript_26FCE5
	msgbox Route119_WeatherInstitute_1F_Text_26FCE5
	release
	end
Route119_WeatherInstitute_1F_Text_26FCE5:
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a Pokémon Trainer\n"
	.string "like you!$"
Route119_WeatherInstitute_1F_EventScript_26FCE5:: @ 826FABE
	buffernumberstring 0, VAR_SLEPT_DURING_WI_HEIST
	msgbox Route119_WeatherInstitute_1F_Text_26FCEX
	release
	end
Route119_WeatherInstitute_1F_Text_26FCEX: @ 826FCE5
	.string "Hehehe… You're funny. You slept in\n"
	.string "the bed {STR_VAR_1} times.\p"
	.string "That babysitter lady was so mad.$"
Route119_WeatherInstitute_1F_EventScript_26FABE:: @ 826FABE
	msgbox Route119_WeatherInstitute_1F_Text_26FCB7
	release
	end
Route119_WeatherInstitute_1F_Text_26FCB7: @ 826FCB7
	.string "This nice lady says that\n"
	.string "she's babysitting me.\p"
	.string "Everyone else must have gone\n"
	.string "upstairs while I was sleeping.$"


Route119_WeatherInstitute_1F_EventScript_26FAC8:: @ 826FAC8
	lock
	faceplayer
	markasdialog
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_26FB05
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_26FAFF
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_26FAFF
	compare VAR_0x8004, 2
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FDE8, MSGBOX_DEFAULT
	release
	end
Route119_WeatherInstitute_1F_Text_26FDE8: @ 826FDE8
	.string "On the 2nd floor of the Institute,\n"
	.string "we study the weather patterns over\l"
	.string "the Hoenn region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"
Route119_WeatherInstitute_1F_EventScript_26FAFF:: @ 826FAFF
	addvar VAR_0x8004, 1
	return
Route119_WeatherInstitute_1F_EventScript_26FB05:: @ 826FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FD2E, MSGBOX_DEFAULT
	release
	end
Route119_WeatherInstitute_1F_Text_26FD2E: @ 826FD2E
	.string "The professor loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the professor is studying\n"
	.string "if the rain can be put to good use.$"


Route119_WeatherInstitute_1F_EventScript_26FB0F:: @ 826FB0F
	checkplayeroutfit
	selectpointer_clamp Route119_WeatherInstitute_1F_TextArray_26FE94, VAR_RESULT
	msgbox_selected MSGBOX_NPC
	end
.align 2
Route119_WeatherInstitute_1F_TextArray_26FE94:
	.4byte Route119_WeatherInstitute_1F_Text_26FE94
	.4byte Route119_WeatherInstitute_1F_Text_26FE94
	.4byte Route119_WeatherInstitute_1F_Text_26FE94
	.4byte Route119_WeatherInstitute_1F_Text_26FE9R
	.4byte 0
Route119_WeatherInstitute_1F_Text_26FE94: @ 826FE94
	.string "Augh! Team Aqua is back!!$"
Route119_WeatherInstitute_1F_Text_26FE9R: @ 826FE94
	.string "Augh! Team Aqua is back!!\p"
	.string "Oh, what? You're not part of Team\n"
	.string "Aqua anymore?$"


Route119_WeatherInstitute_1F_EventScript_AquaBabySitter::
	lock
	compare VAR_TEMP_2, 1
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_AquaBabySitter2
	msgbox Route119_WeatherInstitute_1F_Text_AquaBabySitter, MSGBOX_NPC
	release
	end
Route119_WeatherInstitute_1F_Text_AquaBabySitter:
	.string "I got stuck with babysitting duty.\p"
	.string "But I guess this kid's alright.$"
Route119_WeatherInstitute_1F_EventScript_AquaBabySitter2:
	msgbox Route119_WeatherInstitute_1F_Text_AquaBabySitter2, MSGBOX_NPC
	end
Route119_WeatherInstitute_1F_Text_AquaBabySitter2:
	.string "Seriously??$"


Route119_WeatherInstitute_1F_EventScript_BlockingWorker::
	msgbox Route119_WeatherInstitute_1F_Text_BlockingWorker, MSGBOX_NPC
	end
Route119_WeatherInstitute_1F_Text_BlockingWorker:
	.string "No. You are not allowed upstairs again.\n"
	.string "Go raid someplace else, jerk.$" @ It's so tempting to put a highly offenseive word in here...


Route119_WeatherInstitute_1F_EventScript_Aqua3::
	msgbox Route119_WeatherInstitute_1F_Text_Aqua3, MSGBOX_DIALOG
	end
Route119_WeatherInstitute_1F_Text_Aqua3:
	.string "Oh, so Doppler Radar is just one part\n"
	.string "of meteorology. They say it so much on\l"
	.string "TV that I thought it was all they used!$"


Route119_WeatherInstitute_1F_EventScript_Man3::
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	goto_if_gt Route119_WeatherInstitute_1F_EventScript_Man3A
	msgbox Route119_WeatherInstitute_1F_Text_Man3, MSGBOX_DIALOG
	end
Route119_WeatherInstitute_1F_Text_Man3:
	.string "As you can see here, Doppler is only\n"
	.string "used to determine a few things, like\l"
	.string "the velocity of the precipitation.$"
Route119_WeatherInstitute_1F_EventScript_Man3A:
	msgbox Route119_WeatherInstitute_1F_Text_Man3A, MSGBOX_NPC
	end
Route119_WeatherInstitute_1F_Text_Man3A:
	.string "Don't tell the other guys, but…\p"
	.string "That Team Aqua chap I was talking to\n"
	.string "seemed very bright.\p"
	.string "If he knew what was good for him, he'd\n"
	.string "drop all this Aqua nonsense and come\l"
	.string "work for us!$"


Route119_WeatherInstitute_1F_FreePokeballBox::
	lock
	goto_if_set FLAG_TEMP_1D, Route119_WeatherInstitute_1F_FreePokeballBoxFlagged
	setyesnotext gYN_Sure, gYN_Nah
	msgbox Route119_WeatherInstitute_1F_FreePokeballBox_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_ReleaseEnd
	giveitem_std ITEM_POKE_BALL, 10
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	incrementgamestat GAME_STAT_NUM_THINGS_STOLEN, 10
	setflag FLAG_TEMP_1D
	release
	end
Route119_WeatherInstitute_1F_FreePokeballBox_Text:
	.string "Looks like a week's supply of\n"
	.string "Poké Balls for the Institute.\p"
	.string "Take a few?$"
Route119_WeatherInstitute_1F_FreePokeballBoxFlagged:
	msgbox Route119_WeatherInstitute_1F_FreePokeballBox_Text2
	release
	end
Route119_WeatherInstitute_1F_FreePokeballBox_Text2:
	.string "Looks like a week's supply of\n"
	.string "Poké Balls for the Institute.$"



@ -----------------------------------------------------

Route119_WeatherInstitute_1F_EventScript_AquaBoy::
	goto_if_set FLAG_SCENE_0, Route119_WeatherInstitute_1F_EventScript_AquaBoyA
	msgbox Route119_WeatherInstitute_1F_Text_AquaBoy, MSGBOX_NPC
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	end
Route119_WeatherInstitute_1F_Text_AquaBoy:
	.string "{AQUA_BOY}: For once, I don't know much\n"
	.string "other information.\p"
	.string "Shelly said she heard they made Pokémon\n"
	.string "here that could control the weather?\p"
	.string "I don't know how that's any more\n"
	.string "powerful than some of the moves other\l"
	.string "Pokémon can do to control local weather.\p"
	.string "It's… her idea and she's an admin, so…\n"
	.string "Just go give her backup upstairs.$"
Route119_WeatherInstitute_1F_EventScript_AquaBoyA:
	msgbox Route119_WeatherInstitute_1F_Text_AquaBoyA, MSGBOX_NPC
	end
Route119_WeatherInstitute_1F_Text_AquaBoyA:
	.string "{AQUA_BOY}: Go give Shelly some backup\n"
	.string "upstairs.\p"
	.string "The sooner you do,\n"
	.string "the sooner we can leave.$"


@ -----------------------------------------------------
@

#define LID_GIRL 7

Route119_WeatherInstitute_1F_EventScript_Bed:: @ 826FB18
	lockall
	compare VAR_TEMP_2, 1
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_BedNope
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_BedDuring
	msgbox Route119_WeatherInstitute_1F_Text_Bed, MSGBOX_DESCRIBE
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end
Route119_WeatherInstitute_1F_Text_Bed: @ 826FEFC
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
Route119_WeatherInstitute_1F_EventScript_BedNope:
	msgbox Route119_WeatherInstitute_1F_Text_BedNope, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_1F_Text_BedNope:
	.string "You just got up.$"


Route119_WeatherInstitute_1F_EventScript_BedDuring:
	applymovement LID_GIRL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_GIRL, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	@ "Oh, sure, just sleep on us!"
	selectpointer_clamp Route119_WeatherInstitute_1F_TextArray_BedDuring, VAR_SLEPT_DURING_WI_HEIST
	msgbox_selected MSGBOX_CDIALOG
	@ Player does just that
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	addvar VAR_SLEPT_DURING_WI_HEIST, 1
	setvar VAR_TEMP_2, 1
	call Common_EventScript_OutOfCenterPartyHeal
	fadedefaultbgm
	end
.align 2
Route119_WeatherInstitute_1F_TextArray_BedDuring:
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring1
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring2
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring3
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring4
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring5
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring6
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring7
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring8
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring9
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring10
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring11
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring12
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring12
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring12
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring13
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring14
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring12
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring13
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring15
	.4byte Route119_WeatherInstitute_1F_Text_BedDuring16
	.4byte 0
Route119_WeatherInstitute_1F_Text_BedDuring1:
	.string "Oh, sure, fine, just tuck into bed and\n"
	.string "sleep on us for eight hours.\p"
	.string "In the middle of a heist, no less!$"
Route119_WeatherInstitute_1F_Text_BedDuring2:
	.string "No! Nononono! You already did this once!\n"
	.string "You're not doing it again on me!$"
Route119_WeatherInstitute_1F_Text_BedDuring3:
	.string "No! Shame on you for sleeping on the\n"
	.string "job! I will drag your sorry butt out\l"
	.string "of bed, if I have to!$"
Route119_WeatherInstitute_1F_Text_BedDuring4:
	.string "Oh for Helix's Sake, really?!\n"
	.string "Are you narcoleptic?!$"
Route119_WeatherInstitute_1F_Text_BedDuring5:
	.string "Alright, seriously, at this point,\n"
	.string "I don't even know why we're still here.\p"
	.string "It's been at least two days now!\p"
	.string "Just freaking get your sleep,\n"
	.string "apparently we're not going anywhere.$"
Route119_WeatherInstitute_1F_Text_BedDuring6:
	.string "I mean, it's not like the staff have\n"
	.string "kicked us out or anything…$"
Route119_WeatherInstitute_1F_Text_BedDuring7:
	.string "At this rate, this kid is gonna be\n"
	.string "applying for jobs by the time\l"
	.string "we're done here…$"
Route119_WeatherInstitute_1F_Text_BedDuring8:
	.string "Have you still not beaten them?\p"
	.string "If you've come down here to get a\n"
	.string "full night's rest after every fight,\l"
	.string "you should have been done by now…$"
Route119_WeatherInstitute_1F_Text_BedDuring9:
	.string "Now you're just testing my patience…$"
Route119_WeatherInstitute_1F_Text_BedDuring10:
	.string "Now you're just doing this to\n"
	.string "annoy me…$"
Route119_WeatherInstitute_1F_Text_BedDuring11:
	.string "Now you're just seeing if I have\n"
	.string "anything else to say…$"
Route119_WeatherInstitute_1F_Text_BedDuring12:
	.string "Stoppit!$"
Route119_WeatherInstitute_1F_Text_BedDuring13:
	.string "You know what, whatever!$"
Route119_WeatherInstitute_1F_Text_BedDuring14:
	.string "This is going on your permanent record!$"
Route119_WeatherInstitute_1F_Text_BedDuring15:
	.string "Ugh. I quit.$"
Route119_WeatherInstitute_1F_Text_BedDuring16:
	.string "… … … …$"
@ This got out of hand. I was having too much fun.


Route119_WeatherInstitute_1F_EventScript_BedReset::
	setvar VAR_TEMP_2, 0
	end

#undef LID_GIRL

@ -----------------------------------------------------


Route119_WeatherInstitute_1F_EventScript_26FB29:: @ 826FB29
	trainerbattle_single TRAINER_IZZY, Route119_WeatherInstitute_1F_Text_26FB57, Route119_WeatherInstitute_1F_Text_26FBBB
	msgbox Route119_WeatherInstitute_1F_Text_26FBD7, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_1F_Text_26FB57: @ 826FB57
	.string "I can't let you people get past!\p"
	.string "There's some very important research\n"
	.string "at stake!$"
Route119_WeatherInstitute_1F_Text_26FBBB: @ 826FBBB
	.string "Blast it…\n"
	.string "Blasted by a kid…$"
Route119_WeatherInstitute_1F_Text_26FBD7: @ 826FBD7
	.string "Why? Why do you vex us so?$"


Route119_WeatherInstitute_1F_EventScript_26FB40:: @ 826FB40
	trainerbattle_single TRAINER_RODRIGO, Route119_WeatherInstitute_1F_Text_26FC34, Route119_WeatherInstitute_1F_Text_26FC52
	msgbox Route119_WeatherInstitute_1F_Text_26FC60, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_1F_Text_26FC34: @ 826FC34
	.string "Huh?\n"
	.string "What's Team Aqua doing here?!$"
Route119_WeatherInstitute_1F_Text_26FC52: @ 826FC52
	.string "Huh?\n"
	.string "I lost?!$"
Route119_WeatherInstitute_1F_Text_26FC60: @ 826FC60
	.string "What could you guys possibly want\n"
	.string "with us?!\p"
	.string "What do you mean, you don't know?!$"
