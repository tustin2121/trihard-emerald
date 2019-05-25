#include "global.h"
#include "te_command.h"
#include "battle.h"
#include "main.h"
#include "util.h"
#include "constants/songs.h"
#include "data/battle_moves.h"

#define GET_COMMAND() \
struct CommanderCommand cmd = gCommanderCommand; \
memset(&gCommanderCommand, 0, sizeof(gCommanderCommand)); \
if (cmd.cmd <= COMMANDER_NOOP) return FALSE; \
if (cmd.cmd >= COMMANDER_COMMAND_COUNT) return FALSE;


static u16 BattleCheckCommander_HandleInputChooseAction_Table[COMMANDER_COMMAND_COUNT][4] = {
//	B_ACTION_USE_MOVE,	B_ACTION_USE_ITEM,	B_ACTION_SWITCH,B_ACTION_RUN
	{ DPAD_DOWN,		DPAD_LEFT,			A_BUTTON,		DPAD_LEFT }, // COMMANDER_SWITCH
	{ A_BUTTON,			DPAD_LEFT,			DPAD_UP,		DPAD_LEFT }, // COMMANDER_MOVE
	{ A_BUTTON,			DPAD_LEFT,			DPAD_UP,		DPAD_LEFT }, // COMMANDER_MOVE_AT
	{ DPAD_RIGHT,		A_BUTTON,			DPAD_UP,		DPAD_UP }, // COMMANDER_ITEM
	{ DPAD_RIGHT,		A_BUTTON,			DPAD_UP,		DPAD_UP }, // COMMANDER_ITEM_MON
	{ DPAD_RIGHT,		A_BUTTON,			DPAD_UP,		DPAD_UP }, // COMMANDER_ITEM_MOVE
	{ DPAD_DOWN,		DPAD_DOWN,			DPAD_RIGHT,		A_BUTTON }, // COMMANDER_RUN
	{},
};
// Check commander mode when on the main combat menu.
// Returns true if the commander mode has modified the out keys
bool8 BattleCheckCommander_HandleInputChooseAction(u8 selCursor, u16* outKeys)
{
	GET_COMMAND();
	outKeys = BattleCheckCommander_HandleInputChooseAction_Table[cmd.cmd][selCursor];
	return TRUE;
}

// Check commander mode when choosing a move
bool8 BattleCheckCommander_HandleInputChooseMove(u8 selCursor, u16* outKeys)
{
	GET_COMMAND();
	if (cmd.cmd == COMMANDER_MOVE || cmd.cmd == COMMANDER_MOVE_AT) {
		// If the cursor has selected the move, activate it
		if (cmd.move == selCursor) {
			outKeys = A_BUTTON; 
			return TRUE;
		}
		if ((selCursor & 1) && !(cmd.move & 1)) {
			outKeys = DPAD_LEFT;
			return TRUE;
		}
		if (!(selCursor & 1) && (cmd.move & 1)) {
			outKeys = DPAD_RIGHT;
			return TRUE;
		}
		if ((selCursor & 2) && !(cmd.move & 2)) {
			outKeys = DPAD_UP;
			return TRUE;
		}
		if (!(selCursor & 2) && (cmd.move & 2)) {
			outKeys = DPAD_DOWN;
			return TRUE;
		}
	}
	// If we got this far, we want to back out of this screen
	outKeys = B_BUTTON;
	return TRUE;
}

// Check commander mode when choosing a target in a double battle.
bool8 BattleCheckCommander_HandleInputChooseTarget(u8 selCursor, u16* outKeys)
{
	GET_COMMAND();
	if (cmd.cmd == COMMANDER_MOVE) {
		if (gMoveSelectionCursor[gActiveBattler] != cmd.move)
		{	// If this is not the move we want, back out.
			outKeys = B_BUTTON; 
			return TRUE;
		}
		// Cannot determine who to attack, ignore
		return FALSE;
	}
	if (cmd.cmd == COMMANDER_MOVE_AT) {
		struct Pokemon* mon = &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]];
		u8 selectedMove = gMoveSelectionCursor[gActiveBattler];
		u8 targetType = gBattleMoves[GetMonData(mon, MON_DATA_MOVE1 + selectedMove)].target;
		bool8 isValid;
		
		if (selectedMove != cmd.move)
		{	// If this is not the move we want, back out.
			outKeys = B_BUTTON; 
			return TRUE;
		}
		
		if (cmd.pokemon > MAX_BATTLERS_COUNT) return FALSE; //Invalid option
		if (gAbsentBattlerFlags & (1 << GetBattlerAtPosition(cmd.pokemon))) return FALSE; //cannot target absent pokemon
		
		if (cmd.pokemon != GetBattlerPosition(gActiveBattler) || targetType & MOVE_TARGET_USER_OR_SELECTED) {
			// Must do all the effects of moving the cursor, without going through the virtual keys
			PlaySE(SE_SELECT);
			gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;
			gMultiUsePlayerCursor = GetBattlerAtPosition(cmd.pokemon);
			gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039AD8;
			outKeys = 0;
			return TRUE;
		}
		if (cmd.pokemon == GetBattlerPosition(gMultiUsePlayerCursor)) {
			outKeys = A_BUTTON; return TRUE;
		}
		// Cannot select who to attack, ignore
		return FALSE;
	}
	// If we got this far, we want to back out of this screen
	outKeys = B_BUTTON;
	return TRUE;
}

bool8 BattleCheckCommander_HandleInputPartyMenuMain(u8 selCursor, u16* outKeys)
{
	GET_COMMAND();
	switch (cmd.cmd) {
		case COMMANDER_SWITCH:
			// Continue below
			break;
		case COMMANDER_ITEM_MON:
		case COMMANDER_ITEM_MOVE:
			// Continue below
			break;
		default:
			if (gMain.inBattle) {
				// If we're in battle, other options mean we want things outside this menu
				outKeys = B_BUTTON;
				return TRUE;
			} else {
				// If we're not in battle, other options are unsupported
				return FALSE;
			}
			break;
	}
	
	if (selCursor != cmd.pokemon) {
		if (cmd.pokemon == 0 && selCursor > 0) {
			outKeys = DPAD_LEFT;
			return TRUE;
		}
		if (gMain.inBattle && IsDoubleBattle()) {
			if (cmd.pokemon == 1 && selCursor > 1) {
				outKeys = DPAD_LEFT;
				return TRUE;
			}
		}
		if (cmd.pokemon < selCursor) {
			outKeys = DPAD_UP;
			return TRUE;
		} else if (cmd.pokemon > selCursor) {
			outKeys = DPAD_DOWN;
			return TRUE;
		}
	}
	outKeys = A_BUTTON;
	return TRUE;
}