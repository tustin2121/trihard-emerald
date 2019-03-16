#include "global.h"
#include "te_debug.h"
#include "script.h"
#include "start_menu.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "event_obj_lock.h"
#include "event_object_movement.h"
#include "random.h"
#include "constants/maps.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;
extern void nullsub_129(void);

// References to scripts defined in data/scripts/te_debug.inc
extern const u8 Script_DebugHandleEmergencySave[];
extern const u8 Script_DebugHandleShowPCBox[];

typedef void (*DebugFunc)(void);

extern bool8 gSoftResetDisabled;

void DebugCheckInterrupts();
static void DebugHandleEmergencySave();
static void DebugHandleShowPCBox();
static void DebugHandleWarpRequest();
static void DebugHandleReloadMap();
static void DebugHandleGetRandomSeeds();
static void DebugHandleSetRandomSeeds();

void DebugSetCallbackSuccess()
{
	gDebugInterrupts.returnVal = 1;
}

void DebugSetCallbackFailure()
{
	gDebugInterrupts.returnVal = -1;
}


static const DebugFunc sDebugCommands[] =
{
	nullsub_129,
	DebugHandleEmergencySave,
	DebugHandleShowPCBox,
	DebugHandleWarpRequest,
	DebugHandleReloadMap,
	DebugHandleGetRandomSeeds,
	DebugHandleSetRandomSeeds,
};

#define DEBUGFN_COUNT ((int)(sizeof(sDebugCommands)/sizeof(DebugFunc)))

void DebugCheckInterrupts()
{
	if (gSoftResetDisabled) return; //don't check when the game has disabled soft-resets
	// if (ScriptContext1_IsScriptSetUp()) return; //don't run it when another script is going
	if (gDebugInterrupts.funcId != 0)
	{
		gDebugInterrupts.returnVal = 0;
		if (gDebugInterrupts.funcId < DEBUGFN_COUNT)
		{
			sDebugCommands[gDebugInterrupts.funcId]();
		}
		gDebugInterrupts.funcId = 0;
	}
}



// parameters: none
// returns: none
void DebugHandleEmergencySave()
{
	ScriptContext1_SetupScript(Script_DebugHandleEmergencySave);
}

// parameters: none
// returns: none
void DebugHandleShowPCBox()
{
	ScriptContext1_SetupScript(Script_DebugHandleShowPCBox);
}

// parameters: 
//	 args[0] = mapGroup
//	 args[1] = mapNum
//	 args[2] = warpId
//	 args[3] = x
//	 args[4] = y
// returns: none
void DebugHandleWarpRequest()
{
	s8 args[5];
	const struct MapHeader* mapHeader;
	
	memcpy(&args, (u8*)gDebugInterrupts.args, 5);
	memset((u8*)gDebugInterrupts.args, 0, 5);
	
	if (args[0] < 0 || args[0] >= MAP_GROUPS_COUNT) goto error;
	
	mapHeader = Overworld_GetMapHeaderByGroupAndId(args[0], args[1]);
	if ((void*)mapHeader < (void*)&Start) goto error; // not in ROM
	
	//TODO check warps
	//TODO check x/y
	
	SetWarpDestination(args[0], args[1], args[2], args[3], args[4]);
	WarpIntoMap();
	
	DebugSetCallbackSuccess();
	return;
error:
	DebugSetCallbackFailure();
	return;
}

// arguments: none
void DebugHandleReloadMap()
{
	struct WarpData data = gSaveBlock1Ptr->location;
	
	SetWarpDestination(data.mapGroup, data.mapNum, -1, data.x, data.y);
	WarpIntoMap();
	DebugSetCallbackSuccess();
}

// arguments: none
// returns: gRngValue copied to +4, gRng2Value copied to +8
void DebugHandleGetRandomSeeds()
{
	u32 *val1 = (u32*)&gDebugInterrupts.args[2]; //choose word-aligned address
	u32 *val2 = (u32*)&gDebugInterrupts.args[6];
	*val1 = gRngValue;
	*val2 = gRng2Value;
	DebugSetCallbackSuccess();
}

// arguments: 
// 	 args[2]+4 = gRngValue to copy
//   args[6]+4 = gRng2Value to copy
// returns: none
void DebugHandleSetRandomSeeds()
{
	u32 *val1 = (u32*)&gDebugInterrupts.args[2]; //choose word-aligned address
	u32 *val2 = (u32*)&gDebugInterrupts.args[6];
	gRngValue = *val1;
	gRng2Value = *val2;
	DebugSetCallbackSuccess();
}