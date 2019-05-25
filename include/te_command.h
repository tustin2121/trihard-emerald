#ifndef TE_COMMAND_GUARD_H
#define TE_COMMAND_GUARD_H

// #include "global.h"

enum {
	// Do nothing.
	COMMANDER_NOOP,
	// Battle: Switch to the pokemon specified in the pokemon nibble
	COMMANDER_SWITCH,
	// Battle: Use the move at the index specified in the move nibble
	COMMANDER_MOVE,
	// Battle: Use the move at the index specified in the move nibble
	//   targeting the battle position specified in the pokemon nibble
	COMMANDER_MOVE_AT,
	// Battle: Use the item specified in the itemid short.
	COMMANDER_ITEM,
	// Battle: Use the item specified in the itemid short 
	//   on the pokemon specified in the pokemon nibble.
	COMMANDER_ITEM_MON,
	// Battle: Use the item specified in the itemid short 
	//   on the move index specified in the move nibble
	//   on the pokemon specified in the pokemon nibble.
	COMMANDER_ITEM_MOVE,
	// Battle: Flee battle
	COMMANDER_RUN,
	
	COMMANDER_COMMAND_COUNT,
};

// Everything is volatile to prevent it being optimized away. These
// variables will never be referenced within the application. They're 
// meant to be set externally.
struct CommanderCommand
{
	// Command type
	volatile u8 cmd;
	// An index for party members or target pokemon
	volatile u8 pokemon:4;
	// An index for move
	volatile u8 move:4;
	// An item id
	volatile u16 itemid;
}; // size = 0x00
// Defined in main.c for memory location purposes
extern volatile struct CommanderCommand gCommanderCommand;

#define CHECK_COMMANDER(mode, cursor) \
if (gMain.newKeys & START_BUTTON) { \
	if (!BattleCheckCommander_##mode(cursor, &virtualKeys)) { \
		virtualKeys = gMain.newKeys; \
	} \
}


bool8 BattleCheckCommander_HandleInputChooseAction(u8 selCursor, u16* outKeys);
bool8 BattleCheckCommander_HandleInputChooseMove(u8 selCursor, u16* outKeys);
bool8 BattleCheckCommander_HandleInputChooseTarget(u8 selCursor, u16* outKeys);
bool8 BattleCheckCommander_HandleInputPartyMenuMain(u8 selCursor, u16* outKeys);

#endif //TE_COMMAND_GUARD_H
