#include "global.h"
#include "te_debug.h"
#include "start_menu.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "random.h"
#include "constants/maps.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;
extern void nullsub_129(void);

typedef void (*DebugFunc)(void);

static void DebugHandleEmergencySave();
static void DebugHandleShowPCBox();
static void DebugHandleWarpRequest();
static void DebugHandleReloadMap();
static void DebugHandleGetRandomSeeds();
static void DebugHandleSetRandomSeeds();

#define SET_SUCCESS() gDebugInterrupts.returnVal = 1
#define SET_FAILURE() gDebugInterrupts.returnVal = -1

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
	SaveGame(); //"Would you like to save the game?"
	SET_SUCCESS();
}

// parameters: none
// returns: none
void DebugHandleShowPCBox()
{
	ShowPokemonStorageSystemPC();
	SET_SUCCESS();
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
	
	memcpy(&args, gDebugInterrupts.args, 5);
	memset(gDebugInterrupts.args, 0, 5);
	
	if (args[0] < 0 || args[0] >= MAP_GROUPS_COUNT) goto error;
	
	mapHeader = Overworld_GetMapHeaderByGroupAndId(args[0], args[1]);
	if ((void*)mapHeader < (void*)&Start) goto error; // not in ROM
	
	//TODO check warps
	//TODO check x/y
	
	SetWarpDestination(args[0], args[1], args[2], args[3], args[4]);
	WarpIntoMap();
	
	SET_SUCCESS();
	return;
error:
	SET_FAILURE();
	return;
}

// arguments: none
void DebugHandleReloadMap()
{
	struct WarpData data = gSaveBlock1Ptr->location;
	
	SetWarpDestination(data.mapGroup, data.mapNum, -1, data.x, data.y);
	WarpIntoMap();
	SET_SUCCESS();
}

// arguments: none
// returns: gRngValue copied to +4, gRng2Value copied to +8
void DebugHandleGetRandomSeeds()
{
	u32 *val1 = &gDebugInterrupts.args[2]; //choose word-aligned address
	u32 *val2 = &gDebugInterrupts.args[6];
	*val1 = gRngValue;
	*val2 = gRng2Value;
	SET_SUCCESS();
}

// arguments: 
// 	 args[2]+4 = gRngValue to copy
//   args[6]+4 = gRng2Value to copy
// returns: none
void DebugHandleSetRandomSeeds()
{
	u32 *val1 = &gDebugInterrupts.args[2]; //choose word-aligned address
	u32 *val2 = &gDebugInterrupts.args[6];
	gRngValue = *val1;
	gRng2Value = *val2;
	SET_SUCCESS();
}