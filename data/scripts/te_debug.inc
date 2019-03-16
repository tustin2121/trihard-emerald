Script_DebugHandleEmergencySave::
	lockall
	playse SE_SELECT
	special DoSaveGame
	waitstate
	special DebugSetCallbackSuccess
	releaseall
	end

Script_DebugHandleShowPCBox::
	lockall
	playse SE_SELECT
	special ShowPokemonStorageSystemPC
	waitstate @ should pause here
	closemessage
	setvar VAR_0x8004, 0 @ Not sure what this does, but the PC sets it to 0 on close
	special DebugSetCallbackSuccess
	releaseall
	end
