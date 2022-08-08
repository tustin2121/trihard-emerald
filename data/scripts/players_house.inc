LittlerootTown_BrendansHouse_2F_EventScript_2926FE:: @ 82926FE
LittlerootTown_MaysHouse_2F_EventScript_2926FE:: @ 82926FE
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

@ -----------------------------------------------------
@ Cutscene: Walk inside for the first time

LittlerootTown_BrendansHouse_1F_EventScript_292704:: @ 8292704
LittlerootTown_MaysHouse_1F_EventScript_292704:: @ 8292704
	flagasdialog
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7A1C, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	applymovement_gendered EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight, Common_Movement_WalkInPlaceLeft
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7A46, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	setflag FLAG_SYS_TV_HOME_OFF @turn off TV
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp1
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceDown
	waitmovement 0
	releaseall
	end
LittlerootTown_PlayersHouse_1F_Text_1F7A1C: @ 81F7A1C
	.string "Dad: See, {PLAYER}?\n"
	.string "Isn't it nice in here?$"
LittlerootTown_PlayersHouse_1F_Text_1F7A46: @ 81F7A46
	.string "Why are you still wearing that ridi--?\n"
	.string "Nevermind…\p"
	.string "The mover's Pokémon are doing the work\n"
	.string "for us, so you don't have to help.\p"
	.string "They put your stuff upstairs already,\n"
	.string "so why don't you head upstairs and\l"
	.string "unpack, relax, maybe change…\p"
	.string "Your clock will need setting. We've\n"
	.string "crossed nearly a dozen timezones.\p"
	.string "Go do that. Please.$"

@ -----------------------------------------------------
@ Cutscene: Trying to leave house

LittlerootTown_BrendansHouse_1F_EventScript_292765:: @ 8292765
LittlerootTown_MaysHouse_1F_EventScript_292765:: @ 8292765
	flagasdialog
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7B24
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292AF0
	waitmovement 0
	releaseall
	end
LittlerootTown_PlayersHouse_1F_Text_1F7B24: @ 81F7B24
	.string "Dad: {PLAYER}. Go to your room, please.\p"
	.string "I don't want you getting in the movers'\n"
	.string "way.$"

@ -----------------------------------------------------
@ Cutscene: Try to leave room

LittlerootTown_PlayersHouse_1F_Text_DadStayInRoom: @ 81F7B67
	.string "Dad: {PLAYER}!\p"
	.string "Stay in your room!$"

@ -----------------------------------------------------
@ Cutscene: Setting the clock

LittlerootTown_BrendansHouse_2F_EventScript_292781:: @ 8292781
	lockall
	setvar VAR_0x8004, 0
	goto LittlerootTown_BrendansHouse_2F_EventScript_292799
	end

LittlerootTown_MaysHouse_2F_EventScript_29278D:: @ 829278D
	lockall
	setvar VAR_0x8004, 1
	goto LittlerootTown_MaysHouse_2F_EventScript_292799
	end

LittlerootTown_BrendansHouse_2F_EventScript_292799:: @ 8292799
LittlerootTown_MaysHouse_2F_EventScript_292799:: @ 8292799
	goto_if_set FLAG_SET_WALL_CLOCK, Common_EventScript_ViewWallClock
	msgbox LittlerootTown_PlayersHouse_2F_Text_ClockStopped, MSGBOX_DEFAULT
	call LittlerootTown_PlayerHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setvar VAR_0x8008, 2
	addobject VAR_0x8008
	playse SE_KAIDAN
	flagasdialog
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_29285B
	waitmovement 0
	message LittlerootTown_PlayersHouse_2F_Text_AfterClock1
	waitmessage
	applymovement_gendered EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight, Common_Movement_WalkInPlaceLeft
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	selectpointer_ongender LittlerootTown_PlayersHouse_2F_Text_AfterClock2_Boy, LittlerootTown_PlayersHouse_2F_Text_AfterClock2_Girl
	message 0
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	message LittlerootTown_PlayersHouse_2F_Text_AfterClock3
	waitmessage
	waitbuttonpress
	closemessage
	
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292857
	waitmovement 0
	playse SE_KAIDAN
	removeobject VAR_0x8008
	releaseall
	end
LittlerootTown_PlayersHouse_2F_Text_ClockStopped: @ 81F8668
	.string "The clock is stopped…\p"
	.string "Might as well set it…$"
LittlerootTown_BrendansHouse_2F_Movement_29285B: @ 829285B
	delay_8
	walk_down
	step_end
LittlerootTown_PlayersHouse_2F_Text_AfterClock1: @ 81F869A
	.string "Dad: Sigh… The movers are done.\n"
	.string "You can come down now.\p"
	.string "$"
LittlerootTown_PlayersHouse_2F_Text_AfterClock2_Boy:
	.string "So, how do you like your new room?\p"
	.string "What posters? Oh, come now,\n"
	.string "you don't expect me to allow such\l"
	.string "smut on the walls, do you?\p"
	.string "$"
LittlerootTown_PlayersHouse_2F_Text_AfterClock2_Girl:
	.string "So, how do you like your new room?\p"
	.string "What do you mean, “too pink”?\n"
	.string "It's a perfectly reasonable color\l"
	.string "choice for a young lady like yourself.\p"
	.string "$"
LittlerootTown_PlayersHouse_2F_Text_AfterClock3:
	.string "Now, finish unpacking and I'll make\n"
	.string "you something to eat.\p"
	.string "Come down when you're ready.$"
LittlerootTown_BrendansHouse_2F_Movement_292857: @ 8292857
	walk_up
	delay_8
	step_end

LittlerootTown_PlayerHouse_2F_EventScript_SetWallClock:: @ 8292849
	fadescreen 1
	special StartWallClock
	waitstate
	return

@ -----------------------------------------------------
@ Cutscene: Coming back down after setting the clock

LittlerootTown_PlayersHouse_1F_EventScript_AfterClockCutscene::
	flagasdialog
	applymovement_gendered EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft, Common_Movement_WalkInPlaceRight
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone1, MSGBOX_DEFAULT
	closemessage
	@ Dad on phone
	applymovement_gendered EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292AE0, LittlerootTown_MaysHouse_1F_Movement_292AE8
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceDown
	waitmovement 0
	setyesnotext gYN_Elipsis2, gYN_Duh
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone3, MSGBOX_YESNO
	applymovement_gendered VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_292AE6, LittlerootTown_MaysHouse_1F_Movement_292AEE
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PauseLookAway
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone4, MSGBOX_DEFAULT
	waitmovement 0
	@ Given PokeNav
	playfanfare MUS_FANFA4
	message LittlerootTown_PlayersHouse1F_Text_GivenPokenav, MSGTYPE_DESCRIBE
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone5, MSGBOX_DEFAULT
	closemessage
	applymovement_gendered VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2929BD, LittlerootTown_MaysHouse_1F_Movement_2929C1
	waitmovement 0
	message LittlerootTown_PlayersHouse1F_Text_ChangeContact, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	closemessage
	setvar VAR_TEMP_1, 1
	waitmovement 0
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone1: @ 81F7B96
	.string "Dad: Mhm… yeah…\n"
	.string "Yeah, I just got in…$"
LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone2: @ 81F7BBC
	.string "Already?!\p"
	.string "But we've barely settled… … …\p"
	.string "Yes, of course… … … … …\p"
	.string "Very well…\n"
	.string "I'll be there as soon as I can…$"
LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone3:
	.string "Dad: Oh, {PLAYER}, I didn't hear you\n"
	.string "come downstairs.\p"
	.string "That was a call from my new job. They\n"
	.string "want me in as soon as possible.$"
	@ .../Duh
LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone4:
	.string "{PLAYER}, {PLAYER_buddy}, I promise it'll be\n"
	.string "different here. I just have to sort\l"
	.string "things out at work first.\p"
	.string "Here, I got you something. You can call\n"
	.string "me at any time.$"
			
LittlerootTown_PlayersHouse1F_Text_GivenPokenav:
	.string "{PLAYER} received a PokéNav.$"

LittlerootTown_PlayersHouse_1F_Text_DadIntroPhone5:
	.string "Dad: My number's already in there.\n"
	.string "Call me if you want to chat. Any time.\l"
	.string "I promise I'll answer.\p"
	.string "I've, uh, gotta get ready now. Why don't\n"
	.string "you go meet our neighbors?\p"
	.string "Maybe get outside, look around, enjoy\n"
	.string "the beautiful {TIME_OF_DAY}.$"

LittlerootTown_PlayersHouse1F_Text_ChangeContact:
	.string "{PLAYER} surreptitiously changes the\n"
	.string "name on Dad's contact info.$"

LittlerootTown_BrendansHouse_1F_Movement_PauseLookAway:
	delay_16
	face_down
	step_end

@ Brendan's House Movement
LittlerootTown_BrendansHouse_1F_Movement_292AE0: @ 8292AE0
	walk_slow_down
	walk_slow_down
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_down
	face_left
	step_end
LittlerootTown_BrendansHouse_1F_Movement_292AE6: @ 8292AE6
	walk_right
	walk_right
	walk_in_place_down
	step_end
LittlerootTown_BrendansHouse_1F_Movement_2929BD: @ 82929BD
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

@ May's House Movement
LittlerootTown_MaysHouse_1F_Movement_292AE8: @ 8292AE8
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	face_right
	step_end
LittlerootTown_MaysHouse_1F_Movement_292AEE: @ 8292AEE
	walk_left
	walk_left
	walk_in_place_down
	step_end
LittlerootTown_MaysHouse_1F_Movement_2929C1: @ 82929C1
	walk_up
	walk_up
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end


@ -----------------------------------------------------
@ Cutscene: Meeting the Neighbors

LittlerootTown_RivalsHouse_1F_Text_1F8BC5: @ 81F8BC5
	.string "Um, excuse me, who are you?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, our new next-door neighbor!\n"
	.string "Hello!\p"
	.string "With that outfit on, at first I thought\n"
	.string "you were about to… um…\p"
	.string "Anyway, we have a {RIVAL_son} who's\n"
	.string "about the same age as you.\p"
	.string "{RIVAL_They} was excited about making\n"
	.string "a new friend.\p"
	.string "Um… … … Yes… I think\n"
	.string "{RIVAL_they}'s upstairs.$"

@ -----------------------------------------------------
@ Meeting Rival

LittlerootTown_RivalHouse_1F_Text_1F8EC6:
	.string "Oh! Uh…\n"
	.string "W-Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, nice to meet you, {PLAYER}.\n"
	.string "My name is {RIVAL}.\p"
	.string "You're… not at all like I imagined\n"
	.string "when I heard someone had bought the\l"
	.string "house next door.\p"
	.string "Uh, hey, I'd love to chat more but\n"
	.string "I gotta help my dad catch some\l"
	.string "wild Pokémon, so…\p"
	.string "Some other time, okay?$"

@ -----------------------------------------------------
@ Event Object: Dad

LittlerootTown_PlayerHouse_1F_EventScript_Dad::
	flagasdialog
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_PlayerHouse_1F_EventScript_Dad_GoPlay
	@ If dad has sent you outside now (end of intro sequence)
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq LittlerootTown_PlayerHouse_1F_EventScript_Dad_GoOutside
	@ During intro sequence:
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroNotNow, MSGBOX_DEFAULT
	@ applymovement THIS_EVENT, Common_Movement_FaceDown
	release
	end
LittlerootTown_PlayersHouse_1F_Text_DadIntroNotNow: @ 81F7B24
	.string "Dad: Not now, {PLAYER}.\p"
	.string "I'm speaking with the mover. Please,\n"
	.string "go to your room and hang out.$"

LittlerootTown_PlayerHouse_1F_EventScript_Dad_GoOutside:
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroGoOutside, MSGBOX_NPC
	release
	end
LittlerootTown_PlayersHouse_1F_Text_DadIntroGoOutside:
	.string "Dad: Go say hi to the neighbors for us,\n"
	.string "please.$"

LittlerootTown_PlayerHouse_1F_EventScript_Dad_GoPlay:
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroGoPlay, MSGBOX_DEFAULT
	release
	end
LittlerootTown_PlayersHouse_1F_Text_DadIntroGoPlay:
	.string "Dad: I'm busy right now, {PLAYER_buddy}.\n"
	.string "Go play outside.$"

@ -----------------------------------------------------
@ Event Object: Dad's Letter

LittlerootTown_PlayerHouse_1F_OnLoad_Letter::
	goto_if_unset FLAG_DAD_IS_AT_WORK, LittlerootTown_PlayerHouse_1F_OnLoad_LetterHide
	call_if_set FLAG_DAILY_DADS_LETTER_REMOVED, LittlerootTown_PlayerHouse_1F_OnLoad_LetterHide
	end
LittlerootTown_PlayerHouse_1F_OnLoad_LetterHide:
	setflag FLAG_TEMP_1E
	end

LittlerootTown_PlayerHouse_1F_EventScript_Letter::
	lock
	faceplayer
	message LittlerootTown_PlayerHouse_1F_Text_Letter, MSGTYPE_DESCRIBE
	waitmessage
	call_if_unset FLAG_DAD_LETTER_STARTER_ITEM, LittlerootTown_PlayerHouse_1F_EventScript_Letter_CheckStarter
	call_if_unset FLAG_DAD_LETTER_AMULET, LittlerootTown_PlayerHouse_1F_EventScript_Letter_CheckNorman
	goto LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoStandard
	end
LittlerootTown_PlayerHouse_1F_Text_Letter:
	.string "It's a note from dad:\p$"

LittlerootTown_PlayerHouse_1F_EventScript_Letter_CheckStarter:
	@ Check if the starter is alive
	callnative CheckIfStarterAlive
	compare VAR_RESULT, FALSE
	goto_if_eq LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoStarter
	return

LittlerootTown_PlayerHouse_1F_EventScript_Letter_CheckNorman:
	@ Check if got Norman's badge
	goto_if_set FLAG_BADGE05_GET, LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoNorman
	return


LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoStarter:
	bufferspeciesname 0, VAR_0x8000
	message LittlerootTown_PlayerHouse_1F_Text_LetterStarter1, MSGTYPE_SIGN
	waitmessage
	removeobject THIS_EVENT
	msgbox LittlerootTown_PlayerHouse_1F_Text_LetterStarter2, MSGBOX_CDESCRIBE
	giveitem_std ITEM_FOCUS_BAND, 1
	setflag FLAG_DAILY_DADS_LETTER_REMOVED
	setflag FLAG_DAD_LETTER_STARTER_ITEM
	release
	end
LittlerootTown_PlayerHouse_1F_Text_LetterStarter1:
	.string "Hey, champ, I got something special\n"
	.string "for your {STR_VAR_1} to wear.\p"
	.string "I think it'll look good on it, an--”$"
LittlerootTown_PlayerHouse_1F_Text_LetterStarter2:
	.string "{PLAYER} crumpled up the letter\n"
	.string "and threw it out.\p"
	.string "There's an item under it.$"


LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoNorman:
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_SIGN
	msgbox LittlerootTown_PlayerHouse_1F_Text_LetterNorman1
	giveitem_std ITEM_AMULET_COIN, 1
	setflag FLAG_DAILY_DADS_LETTER_REMOVED
	setflag FLAG_DAD_LETTER_AMULET
	release
	end
LittlerootTown_PlayerHouse_1F_Text_LetterNorman1:
	.string "Hey, champ, I heard you've been doing\n"
	.string "well on your journey.\p"
	.string "I found this in a shop in Rustboro.\n"
	.string "I hear it brings good luck if you have\l"
	.string "one of your Pokemon wearing it.\l"
	.string "{CLEAR_TO 0x80}--Dad$"


LittlerootTown_PlayerHouse_1F_EventScript_Letter_DoStandard:
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_SIGN
	msgbox LittlerootTown_PlayerHouse_1F_Text_LetterCommon
	applymovement THIS_EVENT, Common_Movement_FaceDown
	setflag FLAG_DAILY_DADS_LETTER_REMOVED
	release
	end
LittlerootTown_PlayerHouse_1F_Text_LetterCommon:
	.string "Hey, {PLAYER_buddy}, I have to\n"
	.string "work late again tonight.\p"
	.string "Don't forget to get a good night's\n"
	.string "rest upstairs. Resting often is good\l"
	.string "for you and your Pokemon.\p"
	.string "There's some soup in the fridge.\n"
	.string "Take some with you when you go.\l"
	.string "{CLEAR_TO 0x80}--Dad$"


@ -----------------------------------------------------
@ Signpost: Fridge

LittlerootTown_PlayerHouse_1F_SignScript_Fridge::
	lock
	goto_if_unset FLAG_DAD_IS_AT_WORK, LittlerootTown_PlayerHouse_1F_SignScript_FridgeNothing
	goto_if_set FLAG_DAILY_HOMEMADE_SOUP, LittlerootTown_PlayerHouse_1F_SignScript_FridgeNothing
	msgbox LittlerootTown_PlayerHouse_1F_Text_Fridge
	giveitem_std ITEM_HOMEMADE_SOUP, 5
	setflag FLAG_DAILY_HOMEMADE_SOUP
	release
	end
LittlerootTown_PlayerHouse_1F_Text_Fridge:
	.string "You open the fridge and look in…\n"
	.string "Oh, that looks good!$"

LittlerootTown_PlayerHouse_1F_SignScript_FridgeNothing:
	msgbox LittlerootTown_PlayerHouse_1F_Text_FridgeNothing
	release
	end
LittlerootTown_PlayerHouse_1F_Text_FridgeNothing:
	.string "You open the fridge and look in…\n"
	.string "You find nothing tasty.$"


@ -----------------------------------------------------
@ Trigger: Sleeping in bed

LittlerootTown_PlayersHouse_2F_TriggerScript_SleepInBed::
	goto_if_set FLAG_TEMP_1F, LittlerootTown_PlayersHouse_2F_TriggerScript_SleepInBed2
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	message LittlerootTown_PlayersHouse_2F_Text_SleepInBed, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	setflag FLAG_TEMP_1F
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call Common_EventScript_PartyHealSave_Setup
	@ TODO: Walk player out of bed?
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	@ Do the mourning cutscene, if needed
	domourning
	call Common_EventScript_PartyHealSave_Save
	@ Check for dream cutscenes
	dodreams
	call Common_EventScript_PartyHealSave_Complete
	release
	end
LittlerootTown_PlayersHouse_2F_Text_SleepInBed:
	.string "{PLAYER} pulls the covers up and\n"
	.string "drifts off to sleep… … …$"
LittlerootTown_PlayersHouse_2F_TriggerScript_SleepInBed2:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	message LittlerootTown_PlayersHouse_2F_Text_SleepInBed2, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	release
	end
LittlerootTown_PlayersHouse_2F_Text_SleepInBed2:
	.string "{PLAYER} lies in bed, contemplating\n"
	.string "the ceiling, not feeling tired…$"






LittlerootTown_BrendansHouse_1F_Movement_292989: @ 8292989
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292991: @ 8292991
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292999: @ 8292999
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299B: @ 829299B
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299D: @ 829299D
	walk_in_place_fastest_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929A6: @ 82929A6
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	delay_16
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929AF: @ 82929AF
	walk_up
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B3: @ 82929B3
	walk_up
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B7: @ 82929B7
	walk_left
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_2929BA: @ 82929BA
	walk_right
	walk_in_place_fastest_left
	step_end


LittlerootTown_BrendansHouse_1F_EventScript_Dad:: @ 82929C5
LittlerootTown_MaysHouse_1F_EventScript_Dad:: @ 82929C5
	lock
	faceplayer
	@ "Don't push yourself too hard"
	compare VAR_LITTLEROOT_HOUSES_STATE, 4
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	@ "Don't push yourself too hard"
	compare VAR_LITTLEROOT_HOUSES_STATE_2, 4
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	@ Get match call
	goto_if_set FLAG_HAS_MATCH_CALL, LittlerootTown_BrendansHouse_1F_EventScript_292A19
	@ 
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_BrendansHouse_1F_EventScript_292A86
	compare VAR_TEMP_1, 1
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A94
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292AB0
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadIntroNotNow, MSGBOX_DEFAULT
	applymovement THIS_EVENT, Common_Movement_FaceDown
	release
	end


LittlerootTown_BrendansHouse_1F_EventScript_292A0F:: @ 8292A0F
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7DBE, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A19:: @ 8292A19
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, LittlerootTown_BrendansHouse_1F_EventScript_292A43
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7E0E, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7E89, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A43:: @ 8292A43
	goto_if_set FLAG_BADGE05_GET, LittlerootTown_BrendansHouse_1F_EventScript_292A51
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A86

LittlerootTown_BrendansHouse_1F_EventScript_292A51:: @ 8292A51
	@ goto_if_set FLAG_MOM_SAYS_GOODBYE, LittlerootTown_BrendansHouse_1F_EventScript_292A86
	@ msgbox LittlerootTown_PlayersHouse_1F_Text_1F7D73, MSGBOX_DEFAULT
	@ giveitem_std ITEM_AMULET_COIN
	@ compare VAR_RESULT, 0
	@ goto_if_eq Common_EventScript_ShowBagIsFull
	@ msgbox LittlerootTown_PlayersHouse_1F_Text_1F7DBE, MSGBOX_DEFAULT
	@ setflag FLAG_MOM_SAYS_GOODBYE
	@ release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A86:: @ 8292A86
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7D08, MSGBOX_DEFAULT
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A9E
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A94:: @ 8292A94
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7CC3, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A9E:: @ 8292A9E
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7D5C, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292AB0:: @ 8292AB0
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7CD8, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ABA:: @ 8292ABA
LittlerootTown_MaysHouse_1F_EventScript_292ABA:: @ 8292ABA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7EA8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ACD:: @ 8292ACD
LittlerootTown_MaysHouse_1F_EventScript_292ACD:: @ 8292ACD
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7EB3, MSGBOX_DEFAULT
	waitmoncry
	release
	end







LittlerootTown_BrendansHouse_1F_Movement_292AF0: @ 8292AF0
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292AF2:: @ 8292AF2
LittlerootTown_MaysHouse_1F_EventScript_292AF2:: @ 8292AF2
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C76
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C86
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D08
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D13
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C96
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CA1
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F800E, MSGBOX_DEFAULT
	giveitem_std ITEM_SS_TICKET
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F80FE, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CAC
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CC1
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F815B, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CD6
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CEF
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D48
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D5D
	delay 20
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F81B9, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D72
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D7D
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F824B, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D1E
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D33
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F826F, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D88
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D9D
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F8351, MSGBOX_DEFAULT
	multichoice 22, 8, 108, 1
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F83A1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 4
	releaseall
	end

@ Never called.
LittlerootTown_BrendansHouse_1F_EventScript_292C72:: @ 8292C72
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C76:: @ 8292C76
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C86:: @ 8292C86
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C96:: @ 8292C96
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CA1:: @ 8292CA1
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB5
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CAC:: @ 8292CAC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292989
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CC1:: @ 8292CC1
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292991
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBA
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CD6:: @ 8292CD6
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBC
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CEF:: @ 8292CEF
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DC1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D08:: @ 8292D08
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DC6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D13:: @ 8292D13
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DD1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D1E:: @ 8292D1E
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DD7
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D33:: @ 8292D33
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DDE
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D48:: @ 8292D48
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292999
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D5D:: @ 8292D5D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D72:: @ 8292D72
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299D
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D7D:: @ 8292D7D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929A6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D88:: @ 8292D88
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929AF
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D9D:: @ 8292D9D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929B3
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_292DB2: @ 8292DB2
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB5: @ 8292DB5
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB8: @ 8292DB8
	face_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBA: @ 8292DBA
	face_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBC: @ 8292DBC
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC1: @ 8292DC1
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC6: @ 8292DC6
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DCC: @ 8292DCC
	delay_8
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD1: @ 8292DD1
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD7: @ 8292DD7
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DDE: @ 8292DDE
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end
