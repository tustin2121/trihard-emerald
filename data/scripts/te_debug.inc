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
