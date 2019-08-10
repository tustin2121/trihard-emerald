MtChimney_MapScripts:: @ 822EDC1
	map_script MAP_SCRIPT_ON_LOAD, MtChimney_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

@ -----------------------------------------------------

MtChimney_OnLoad:
	goto_if_unset FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA, Common_EventScript_NopEnd
	goto_if_set FLAG_HIDE_MT_CHIMNEY_TRAINERS, Common_EventScript_NopEnd
	setflag VAR_TEMP_A @ Hide Aqua Girl
	end

@ -----------------------------------------------------

MtChimney_OnResume: @ 822EDD2
	setstepcallback 1
	end

@ -----------------------------------------------------

MtChimney_OnTransition: @ 822EDCC
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

@ -----------------------------------------------------
@ Signs

MtChimney_EventScript_22F141:: @ 822F141
	msgbox MtChimney_Text_22FFFA, MSGBOX_SIGN
	end
MtChimney_Text_22FFFA: @ 822FFFA
	.string "{DOWN_ARROW} Jagged Path\n"
	.string "Lavaridge Town Ahead$"


MtChimney_EventScript_22F0E4:: @ 822F0E4
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_22F137
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_22F12D
	msgbox MtChimney_Text_22FF12, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22F123
	msgbox MtChimney_Text_22FF66, MSGBOX_DEFAULT
	giveitem_std ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end
MtChimney_Text_22FF12: @ 822FF12
	.string "A meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the meteorite?$"
MtChimney_Text_22FF66: @ 822FF66
	.string "{PLAYER} removed the meteorite from\n"
	.string "the mysterious machine.$"
MtChimney_EventScript_22F137:: @ 822F137
	msgbox MtChimney_Text_22FEAA, MSGBOX_DEFAULT
	releaseall
	end
MtChimney_Text_22FEAA: @ 822FEAA
	.string "A meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the meteorite.$"
MtChimney_EventScript_22F12D:: @ 822F12D
	msgbox MtChimney_Text_22FFC0, MSGBOX_DEFAULT
	releaseall
	end
MtChimney_Text_22FFC0: @ 822FFC0
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"
MtChimney_EventScript_22F123:: @ 822F123
	msgbox MtChimney_Text_22FF9C, MSGBOX_DEFAULT
	releaseall
	end
MtChimney_Text_22FF9C: @ 822FF9C
	.string "{PLAYER} left the meteorite where\n"
	.string "it was.$"

@ -----------------------------------------------------
@ People

MtChimney_EventScript_LavaCookieLady:: @ 822EEF3
	lock
	faceplayer
	markasdialog
	showmoneybox 0, 0, 0
	setyesnotext gYN_YeahBang, gYN_Nah
	msgbox MtChimney_Text_22FE04, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_EventScript_22EF69
	checkmoney 0xc8, 0
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22EF76
	msgbox MtChimney_Text_22FE4D, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, 1
	call_if_eq MtChimney_EventScript_22EF5E
	giveitem_std ITEM_LAVA_COOKIE
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22EF51
	hidemoneybox
	release
	end
MtChimney_Text_22FE04: @ 822FE04
	.string "Lava Cookies are Mt. Chimney's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"
MtChimney_Text_22FE4D: @ 822FE4D
	.string "Thank you, dear!$"
MtChimney_EventScript_22EF69:: @ 822EF69
	msgbox MtChimney_Text_22FE9B, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
MtChimney_Text_22FE9B: @ 822FE9B
	.string "Oh, fine then.$"
MtChimney_EventScript_22EF76:: @ 822EF76
	msgbox MtChimney_Text_22FE5E, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
MtChimney_Text_22FE5E: @ 822FE5E
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"
MtChimney_EventScript_22EF5E:: @ 822EF5E
	takemoney 0xc8, 0
	updatemoneybox 0, 0
	return
MtChimney_EventScript_22EF51:: @ 822EF51
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

@ -----------------------------------------------------
@ Trainers

MtChimney_EventScript_22F14A:: @ 822F14A
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_23001D, MtChimney_Text_230076, MtChimney_EventScript_22F176
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtChimney_EventScript_22F195
	msgbox MtChimney_Text_2300A2, MSGBOX_DEFAULT
	release
	end
MtChimney_Text_23001D: @ 823001D
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"
MtChimney_Text_230076: @ 8230076
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
MtChimney_Text_2300A2: @ 82300A2
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an expert now, can I?$"
MtChimney_EventScript_22F176:: @ 822F176
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox MtChimney_Text_2300E3, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end
MtChimney_Text_2300E3: @ 82300E3
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"
MtChimney_EventScript_22F195:: @ 822F195
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_230153, MtChimney_Text_2301BB
	msgbox MtChimney_Text_2301E7, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_230153: @ 8230153
	.string "If you can mesh your heart with those\n"
	.string "of your Pokémon, why, you should be\l"
	.string "able to achieve great things.$"
MtChimney_Text_2301BB: @ 82301BB
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
MtChimney_Text_2301E7: @ 82301E7
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your Pokémon.$"



MtChimney_EventScript_22F1AC:: @ 822F1AC
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_23022A, MtChimney_Text_23026D
	msgbox MtChimney_Text_230292, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_23022A: @ 823022A
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"
MtChimney_Text_23026D: @ 823026D
	.string "Ooh, that was a scorching-hot match!$"
MtChimney_Text_230292: @ 8230292
	.string "The heat of Mt. Chimney warms\n"
	.string "me up, baby!$"



MtChimney_EventScript_22F1C3:: @ 822F1C3
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_2302BD, MtChimney_Text_230304
	msgbox MtChimney_Text_23033A, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_2302BD: @ 82302BD
	.string "I've finally made it to Mt. Chimney.\n"
	.string "I want to make my Pokémon battle!$"
MtChimney_Text_230304: @ 8230304
	.string "The way you battle…\n"
	.string "It's like a Mt. Chimney eruption!$"
MtChimney_Text_23033A: @ 823033A
	.string "Like I said, I've finally made it to\n"
	.string "Mt. Chimney. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "cookies as souvenirs.$"



MtChimney_EventScript_22F1DA:: @ 822F1DA
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_2303DF, MtChimney_Text_230436
	msgbox MtChimney_Text_230463, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_2303DF: @ 82303DF
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"
MtChimney_Text_230436: @ 8230436
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"
MtChimney_Text_230463: @ 8230463
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"



MtChimney_EventScript_22F208:: @ 822F208
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_2304B3, MtChimney_Text_2304F7, MtChimney_EventScript_22F234
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtChimney_EventScript_22F253
	msgbox MtChimney_Text_230519, MSGBOX_DEFAULT
	release
	end
MtChimney_Text_2304B3: @ 82304B3
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"
MtChimney_Text_2304F7: @ 82304F7
	.string "Oh, you're a real firebrand, too!$"
MtChimney_Text_230519: @ 8230519
	.string "I think I need a dip in Lavaridge\n"
	.string "Hot Spring with the locals!$"
MtChimney_EventScript_22F234:: @ 822F234
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox MtChimney_Text_230557, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end
MtChimney_Text_230557: @ 8230557
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my PokéNav.$"
MtChimney_EventScript_22F253:: @ 822F253
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_23059C, MtChimney_Text_2305E3
	msgbox MtChimney_Text_230614, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_23059C: @ 823059C
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"
MtChimney_Text_2305E3: @ 82305E3
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"
MtChimney_Text_230614: @ 8230614
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"


@ -----------------------------------------------------
@ Team Aqua

MtChimney_EventScript_Aqua1:: @ 822F053
	msgbox MtChimney_Text_22FD1F, MSGBOX_DIALOG
	end
MtChimney_Text_22FD1F: @ 822FD1F
	.string "Darn… Team Magma outnumbers us!\n"
	.string "We can't keep up with them!$"


MtChimney_EventScript_Aqua2:: @ 822F05C
	msgbox MtChimney_Text_22FD5B, MSGBOX_DIALOG
	end
MtChimney_Text_22FD5B: @ 822FD5B
	.string "If they expand the land, there'll be\n"
	.string "less habitats for Water Pokémon!$"


MtChimney_EventScript_Aqua3:: @ 822F065
	msgbox MtChimney_Text_22FDA1, MSGBOX_DIALOG
	end
MtChimney_Text_22FDA1: @ 822FDA1
	.string "We're Team Aqua!\p"
	.string "They're Team Magma!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"


MtChimney_EventScript_AquaGirl:: @ 822F065
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_AquaGirl3
	goto_if_set FLAG_SCENE_1, MtChimney_EventScript_AquaGirl2
	msgbox MtChimney_Text_AquaGirl, MSGBOX_NPC
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	setflag FLAG_SCENE_1
	end
MtChimney_Text_AquaGirl: @ 822FDA1
	.string "{AQUA_GIRL}: {PLAYER}! You're here!\n"
	.string "In just the nick of time!\p"
	.string "There's too many of them!\n"
	.string "We're outnumbered three to one!\p"
	.string "You've done some amazing work against\n"
	.string "these guys before, right?\p"
	.string "You gotta get in there and\n"
	.string "even the odds for us!$"
MtChimney_EventScript_AquaGirl2:
	msgbox MtChimney_Text_AquaGirl2, MSGBOX_NPC
	end
MtChimney_Text_AquaGirl2:
	.string "Quickly! The boss can only hold out\n"
	.string "for so long!$"
MtChimney_EventScript_AquaGirl4:
	msgbox MtChimney_Text_AquaGirl4, MSGBOX_NPC
	end
MtChimney_Text_AquaGirl4:
	.string "{AQUA_GIRL}: See you later, {PLAYER}.$"
MtChimney_EventScript_AquaGirl3:
	goto_if_set FLAG_SCENE_A, MtChimney_EventScript_AquaGirl4
	selectpointer_clamp MtChimney_TextArray_AquaGirl3, VAR_AQUA_GIRL_FRIENDSHIP
	msgbox_selected MSGBOX_NPC
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	setflag FLAG_SCENE_A
	end
.align 2
MtChimney_TextArray_AquaGirl3:
	.4byte MtChimney_Text_AquaGirl3a
	.4byte MtChimney_Text_AquaGirl3a
	.4byte MtChimney_Text_AquaGirl3a
	.4byte MtChimney_Text_AquaGirl3b
	.4byte 0
MtChimney_Text_AquaGirl3a:
	.string "{AQUA_GIRL}: That was some fancy battling,\n"
	.string "{PLAYER}! Nice job!\p"
	.string "I look forward to the next time\n"
	.string "you can help us out.\p"
	.string "You seem to have a knack for it.$"
MtChimney_Text_AquaGirl3b:
	.string "{AQUA_GIRL}: That was amazing, {PLAYER}!\n"
	.string "Welcome to the Team, full time!\p"
	.string "I hope we have some downtime for a bit.\n"
	.string "All this running around Hoenn is tirind.\p"
	.string "I just wanna chill in front of some TV\n"
	.string "for a while or something. Phew!$"
	

@ -----------------------------------------------------
@ Team Magma

MtChimney_EventScript_Magma1:: @ 822F09C
	msgbox MtChimney_Text_22F978, MSGBOX_DIALOG
	end
MtChimney_Text_22F978: @ 822F978
	.string "That annoying Team Aqua…\n"
	.string "They always mess with our plans!$"


MtChimney_EventScript_Magma2:: @ 822F0A5
	msgbox MtChimney_Text_22F9B2, MSGBOX_DIALOG
	end
MtChimney_Text_22F9B2: @ 822F9B2
	.string "Meteorites pack amazing power!$"


MtChimney_EventScript_Magma3:: @ 822F0AE
	msgbox MtChimney_Text_22F9D1, MSGBOX_DIALOG
	end
MtChimney_Text_22F9D1: @ 822F9D1
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"


MtChimney_EventScript_Magma4:: @ 822F0B7
	msgbox MtChimney_Text_22FA2F, MSGBOX_DIALOG
	end
MtChimney_Text_22FA2F: @ 822FA2F
	.string "We're Team Magma!\p"
	.string "They're Team Aqua!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"


MtChimney_EventScript_Magma5:: @ 822F0C0
	msgbox MtChimney_Text_22FA8B, MSGBOX_DIALOG
	end
MtChimney_Text_22FA8B: @ 822FA8B
	.string "Yeah!\n"
	.string "Douse them in fire!$"


MtChimney_EventScript_Magma6:: @ 822F0C9
	msgbox MtChimney_Text_22FAA5, MSGBOX_DIALOG
	end
MtChimney_Text_22FAA5: @ 822FAA5
	.string "We're going to keep making more land!$"


MtChimney_EventScript_Pooch1:: @ 822F0D2
	msgbox MtChimney_Text_22FACB, MSGBOX_DIALOG
	end
MtChimney_Text_22FACB: @ 822FACB
	.string "Bufoh!$"


MtChimney_EventScript_Pooch2:: @ 822F0DB
	msgbox MtChimney_Text_22FDFC, MSGBOX_DIALOG
	end
MtChimney_Text_22FDFC: @ 822FDFC
	.string "Bushaa!$"


MtChimney_TrainerScript_Tabitha:: @ 822F06E
	trainerbattle_single TRAINER_TABITHA_2, MtChimney_Text_22F6AA, MtChimney_Text_22F72C
	msgbox MtChimney_Text_22F76D, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_22F6AA: @ 822F6AA
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the meteorite\l"
	.string "from Meteor Falls to the boss!$"
MtChimney_Text_22F72C: @ 822F72C
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"
MtChimney_Text_22F76D: @ 822F76D
	.string "Boss, hurry!\n"
	.string "Give it the meteorite's energy!\p"
	.string "Hehehe…$"


MtChimney_EventScript_22F085:: @ 822F085
	trainerbattle_single TRAINER_GRUNT_31, MtChimney_Text_22F7A2, MtChimney_Text_22F83A
	msgbox MtChimney_Text_22F859, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_22F7A2: @ 822F7A2
	.string "We of Team Magma are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"
MtChimney_Text_22F83A: @ 822F83A
	.string "Hunh?\n"
	.string "What do you mean I lost?$"
MtChimney_Text_22F859: @ 822F859
	.string "Our boss says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"


MtChimney_EventScript_22F1F1:: @ 822F1F1
	trainerbattle_single TRAINER_GRUNT_24, MtChimney_Text_22F8B6, MtChimney_Text_22F921
	msgbox MtChimney_Text_22F93A, MSGBOX_AUTOCLOSE
	end
MtChimney_Text_22F8B6: @ 822F8B6
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!\p"
	.string "Team Aqua is depriving me of my house!$"
MtChimney_Text_22F921: @ 822F921
	.string "My dream of a big house…$"
MtChimney_Text_22F93A: @ 822F93A
	.string "Why do you Team Aqua grunts always\n"
	.string "ruin everything!? Go back to\l"
	.string "splashing in the waves!$"


MtChimney_EventScript_Archie:: @ 822EDD5
	lock
	faceplayer
	markasdialog
	call_if_unset FLAG_SCENE_0, MtChimney_EventScript_22EDF9
	call_if_set FLAG_SCENE_0, MtChimney_EventScript_22EE02
	closemessage
	faceoriginaldir
	setflag FLAG_SCENE_0
	release
	end
MtChimney_EventScript_22EDF9:: @ 822EDF9
	msgbox MtChimney_Text_22FAD2, MSGBOX_DEFAULT
	return
MtChimney_Text_22FAD2: @ 822FAD2
	.string "Archie: Grr, {PLAYER}!\n"
	.string "About time you show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of Team Magma are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "meteorite's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"
MtChimney_EventScript_22EE02:: @ 822EE02
	msgbox MtChimney_Text_22FBC7, MSGBOX_DEFAULT
	return
MtChimney_Text_22FBC7: @ 822FBC7
	.string "Archie: Grrr…\p"
	.string "I want to stop that Maxie,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"

@ -----------------------------------------------------

#define LID_MAXIE 2

MtChimney_EventScript_Maxie:: @ 822EE0B
	lockall
	playbgm MUS_MGM0, 0
	@
	markasdialog -8
	msgbox MtChimney_Text_Maxie1
	@ Notices player
	applymovement LID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LID_MAXIE, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	@ 
	setyesnotext gYN_PftNo, gYN_FOff
	msgbox MtChimney_Text_Maxie2, MSGBOX_YESNO
	@
	msgbox MtChimney_Text_Maxie3
	@ BATTLE!
	trainerbattle_no_intro TRAINER_MAXIE_2, MtChimney_Text_Maxie4
	@ 
	markasdialog -8
	msgbox MtChimney_Text_Maxie5
	closemessage
	delay 30
	@ Screen fades, and magma vanishes.
	fadescreen 1
	removeobject LID_MAXIE
	removeobject 29
	removeobject 3
	removeobject 22
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen 0
	@ Archie walks up
	setobjectxyperm 1, 10, 12
	addobject 1
	compare VAR_FACING, 4
	call_if_eq MtChimney_EventScript_22EEC7
	compare VAR_FACING, 2
	call_if_eq MtChimney_EventScript_22EED2
	@ 
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	markasdialog 6
	msgbox MtChimney_Text_Maxie6
	playse SE_SELECT
	@ Uniform get!
	playfanfare MUS_ME_BACHI
	message MtChimney_Text_Maxie7, MSGTYPE_DESCRIBE
	waitfanfare
	@
	msgbox MtChimney_Text_Maxie8
	closemessage
	@ Archie leaves again
	compare VAR_FACING, 4
	call_if_eq MtChimney_EventScript_22EEDD
	compare VAR_FACING, 2
	call_if_eq MtChimney_EventScript_22EEE8
	removeobject 1
	@ Player changes clothes
	fadescreen 5 @ FADE_TO_BLACK_NO_WINDOW
	setvar VAR_0x8000, 2
	callnative SetPlayerOutfit
	msgbox MtChimney_Text_Maxie9, MSGBOX_CDESCRIBE
	@ Clean up
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	call Common_EventScript_ClearSceneFlags
	@ reload map
	@ setflag FLAG_HIDE_MAP_NAME_POPUP
	warpcustom MAP_MT_CHIMNEY, 255, VAR_INTERACT_X, VAR_INTERACT_Y
	waitstate
	releaseall
	end
MtChimney_Text_Maxie1: @ 822F26A
	.string "The power contained in the meteorite…\p"
	.string "By amplifying its power with this\n"
	.string "machine, Mt. Chimney's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"
MtChimney_Text_Maxie2: @ 822F32E
	.string "Maxie: Hm?\n"
	.string "Team Aqua! How did you break through?!\p"
	.string "Oh, but you are not a full member,\n"
	.string "are you? You have no uniform.\p"
	.string "Perhaps, then, you can be persuaded\n"
	.string "to our cause?\p"
	.string "Now you listen.\n"
	.string "Long ago, living things used the\l"
	.string "land to live and grow.\p"
	.string "That is why land is all important!\n"
	.string "It is the cradle of all!\p"
	.string "That is why Team Magma is dedicated\n"
	.string "to the expansion of the land mass.\p"
	.string "It is for further advancement of\n"
	.string "humankind and Pokémon!\p"
	.string "And for that, we need the power of\n"
	.string "what sleeps within this mountain…\p"
	.string "Join us, and you will see that we\n"
	.string "know what's best for everyone!$"
MtChimney_Text_Maxie3:
	.string "Tsk, no matter!\n"
	.string "I'll teach you the consequences of\l"
	.string "meddling in our grand design!$"
MtChimney_Text_Maxie4: @ 822F5CF
	.string "What?!\p"
	.string "I, Maxie, was caught off guard?!$"
MtChimney_Text_Maxie5: @ 822F5F7
	.string "Maxie: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of Team Magma.\p"
	.string "Fufufu…\p"
	.string "Even without the meteorite, if we\n"
	.string "obtain that orb… Fufufu…$"
MtChimney_Text_Maxie6: @ 822FC3D
	.string "Archie: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted Team\n"
	.string "Magma's destructive plan!\p"
	.string "I regret not being able to give you\n"
	.string "this uniform before. This time I was\l"
	.string "unexpectedly prepared.\p"
	.string "You certainly earned your keep today.$"
MtChimney_Text_Maxie7:
	.string "Recieved the Team Aqua Striped Shirt!$"
MtChimney_Text_Maxie8:
	.string "Archie: We will remain vigilant and\n"
	.string "keep up our pursuit of Team Magma.\p"
	.string "I suggest you visit our hideout in\n"
	.string "Lilycove, so you can stay in touch.\p"
	.string "{PLAYER}, we shall meet again!$"
MtChimney_Text_Maxie9:
	.string "{PLAYER} put on the blue-striped shirt.$"

MtChimney_EventScript_22EEC7:: @ 822EEC7
	applymovement 1, MtChimney_Movement_22EF83
	waitmovement 0
	return
MtChimney_EventScript_22EED2:: @ 822EED2
	applymovement 1, MtChimney_Movement_22EF94
	waitmovement 0
	return
MtChimney_EventScript_22EEDD:: @ 822EEDD
	applymovement 1, MtChimney_Movement_22EF8B
	waitmovement 0
	return
MtChimney_EventScript_22EEE8:: @ 822EEE8
	applymovement 1, MtChimney_Movement_22EF9C
	waitmovement 0
	return

MtChimney_Movement_22EF83: @ 822EF83
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
MtChimney_Movement_22EF94: @ 822EF94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end
	
MtChimney_Movement_22EF8B: @ 822EF8B
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
MtChimney_Movement_22EF9C: @ 822EF9C
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

#undef LID_MAXIE

