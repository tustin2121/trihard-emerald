DebugScript_EmergencySave::
	lockall
	playse SE_SELECT
	special DoSaveGame
	waitstate
	special DebugSetCallbackSuccess
	releaseall
	end

DebugScript_ShowPCBox::
	lockall
	playse SE_SELECT
	special ShowPokemonStorageSystemPC
	waitstate @ should pause here
	closemessage
	setvar VAR_0x8004, 0 @ Not sure what this does, but the PC sets it to 0 on close
	special DebugSetCallbackSuccess
	releaseall
	end

DebugScript_ShowSoundTest::
	lockall
	playse SE_SELECT
	message DebugScript_Text_SoundTest_Title
	waitstate @ script pauses here until manually reenabled
	closemessage
	releaseall
	end

DebugScript_ShowDebugScreen::
	lockall
	playse SE_SELECT
	waitstate @ script pauses here until manually reenabled
	special DebugSetCallbackSuccess
	releaseall
	end

DebugScript_MessageEnd::
	waitmessage
	closemessage
	end

DebugScript_SetLegendaryWeatherBefore::
	setvar VAR_RAYQUAZA_STATE, 0
	setvar VAR_SKY_PILLAR_STATE, 0
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_SYS_WEATHER_CTRL
	clearflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	clearflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	end

DebugScript_SetLegendaryWeatherDuring::
	setvar VAR_RAYQUAZA_STATE, 2
	setvar VAR_SKY_PILLAR_STATE, 0
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	clearflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	end

DebugScript_SetLegendaryWeatherAfter::
	setvar VAR_RAYQUAZA_STATE, 6
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	end

DebugScript_SetLegendaryWeatherAfterGym::
	setvar VAR_RAYQUAZA_STATE, 6
	setvar VAR_SKY_PILLAR_STATE, 3
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	end


DebugScript_GiveDebugPartyMessage::
	msgbox ScriptText_GiveDebugPartyMessage
	release
	end
ScriptText_GiveDebugPartyMessage:
	.string "Party replaced with Debug Party.$"

DebugScript_GiveDebugPartyAndSetFlags::
	lockall
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_DAD
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_DAD
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_SYS_B_DASH @ Give Fast Movement
	
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ After last intro
	setvar VAR_LITTLEROOT_HOUSES_STATE, 2 @ After rival introduction
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 2 @ After rival introduction
	setvar VAR_0x4050, 4 @ Set mom to after prologue
	setvar VAR_BIRCH_LAB_STATE, 5
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 9, 10
	releaseall
	return

@====================================================================

.align 2
DebugScript_TestScriptTable::
	@ .4byte DreamScript_CantSleep @ 0 - done
	.4byte DebugScript_TestScript2
	@ .4byte DEBUG_DreamScript_0100 @ 1 - done
	.4byte DebugScript_TestScript3
	.4byte DEBUG_DreamScript_0150 @ 2 - done
	.4byte DEBUG_DreamScript_0200 @ 3 - done
	.4byte DEBUG_DreamScript_0300 @ 4 - done
	.4byte DEBUG_DreamScript_0400 @ 5 - done
	.4byte DEBUG_DreamScript_0500 @ 6 - done
	.4byte DEBUG_DreamScript_0600 @ 7 - done
	.4byte DEBUG_DreamScript_0700 @ 8 - 
	.4byte DEBUG_DreamScript_0800 @ 9 - done
	.4byte DEBUG_DreamScript_0802 @ 10 - 
	.4byte DEBUG_DreamScript_0900 @ 11 - done
	.4byte DEBUG_DreamScript_1000 @ 12 - 
	.4byte DEBUG_DreamScript_1001 @ 13 - 
	.4byte 0 @ 14 - 
	.4byte DEBUG_DreamScript_1200 @ 15 - 
	.4byte DEBUG_DreamScript_1300 @ 16 - 
	.4byte DEBUG_DreamScript_1600 @ 17 - 
	.4byte DEBUG_DreamScript_1601 @ 18 - 
	.4byte DEBUG_DreamScript_1602 @ 19 - 
	.4byte 0 @ 20 - 
	.4byte 0 @ 21 - 
	.4byte 0 @ 22 - 
	.4byte 0 @ 23 - 
	.4byte 0 @ 24 - 
	.4byte 0 @ 25 - 
	.4byte 0 @ 26 - 
	.4byte 0 @ 27 - 
	.4byte 0 @ 28 - 
	.4byte 0 @ 29 - 
	.4byte 0 @ 30 - 
	.4byte DEBUG_DreamScript_Alex_FirstCall @ 31
	.4byte DEBUG_DreamScript_Alex_LeagueCall @ 32
DebugScript_TestScriptTable_END::
	.4byte 0


DebugScript_DreamSetup:
	lock
	fadescreenspeed 5, 0 @ FADE_TO_BLACK_NO_WINDOW
	setflag FLAG_DISABLE_FADE_INIT
	delay 10
	return
DebugScript_DreamTeardown:
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 0 @ FADE_FROM_BLACK_NO_WINDOW
	release
	return

DEBUG_DreamScript_CantSleep:
	call DebugScript_DreamSetup
	call DreamScript_CantSleep
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0100:
	call DebugScript_DreamSetup
	call DreamScript_0100
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0150:
	call DebugScript_DreamSetup
	call DreamScript_0150
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0200:
	call DebugScript_DreamSetup
	call DreamScript_0200
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0300:
	call DebugScript_DreamSetup
	call DreamScript_0300
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0400:
	call DebugScript_DreamSetup
	call DreamScript_0400
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0500:
	call DebugScript_DreamSetup
	call DreamScript_0500
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0600:
	call DebugScript_DreamSetup
	call DreamScript_0600
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0700:
	call DebugScript_DreamSetup
	call DreamScript_0700
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0800:
	call DebugScript_DreamSetup
	call DreamScript_0800
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0802:
	call DebugScript_DreamSetup
	call DreamScript_0802
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_0900:
	call DebugScript_DreamSetup
	call DreamScript_0900
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1000:
	call DebugScript_DreamSetup
	call DreamScript_1000
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1001:
	call DebugScript_DreamSetup
	call DreamScript_1001
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1200:
	call DebugScript_DreamSetup
	call DreamScript_1200
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1300:
	call DebugScript_DreamSetup
	call DreamScript_1300
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1600:
	call DebugScript_DreamSetup
	call DreamScript_1600
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1601:
	call DebugScript_DreamSetup
	call DreamScript_1601
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_1602:
	call DebugScript_DreamSetup
	call DreamScript_1602
	call DebugScript_DreamTeardown
	end
DEBUG_DreamScript_Alex_FirstCall:
	goto DreamScript_Alex_FirstCall
	end
DEBUG_DreamScript_Alex_LeagueCall:
	goto DreamScript_Alex_LeagueCall
	end


DebugScript_TestScript2::
	lockall
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	addvar_if_set FLAG_ERROR_READING_DREAMS, VAR_0x8001, 1
	addvar_if_set FLAG_ERROR_WRITING_DREAMS, VAR_0x8002, 1
	buffernumberstring 0, VAR_0x8001
	buffernumberstring 1, VAR_0x8002
	buffernumberstring 2, VAR_0x8003
	msgbox ScriptText_TS2
	releaseall
	end
ScriptText_TS2:
	.string "Read Error={STR_VAR_1}\n"
	.string "Write Error={STR_VAR_2}$"

DebugScript_TestScript3::
	lockall
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	addvar_if_set FLAG_SAW_DREAM_0700, VAR_0x8001, 1
	addvar_if_set FLAG_ENABLE_ALEX_MATCH_CALL, VAR_0x8002, 1
	addvar_if_set FLAG_ENABLE_ALEX_FIRST_CALL, VAR_0x8003, 1
	buffernumberstring 0, VAR_0x8001
	buffernumberstring 1, VAR_0x8002
	buffernumberstring 2, VAR_0x8003
	msgbox ScriptText_TS3
	releaseall
	end
ScriptText_TS3:
	.string "Dream 700={STR_VAR_1}  First={STR_VAR_3}\n"
	.string "Match Call={STR_VAR_2}$"


ScriptText_DebugBoxText:
	.string "Oh! There's some Pokemon and badges in\n"
	.string "this box! Yoink!$"

DebugScript_Text_SoundTest_Title::
	.string "Sound Test: {START_BUTTON} Exit$"
DebugScript_Text_SoundTest_SFX::
	.string "SFX: {STR_VAR_1}$"
DebugScript_Text_SoundTest_BGM::
	.string "BGM: {STR_VAR_1}$"
DebugScript_Text_SoundTest_PH::
	.string "PH?: {STR_VAR_1}$"
