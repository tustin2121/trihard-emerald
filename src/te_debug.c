#include "global.h"
#include "te_debug.h"
#include "start_menu.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "constants/maps.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;
extern void nullsub_129(void);

static void DebugHandleEmergencySave();
static void DebugHandleShowPCBox();
static void DebugHandleWarpRequest();
static void DebugHandleReloadMap();

#define SET_SUCCESS() gDebugInterrupts.args[0] = 1
#define SET_FAILURE() gDebugInterrupts.args[0] = -1

static void (*const sDebugCommands[])(void) =
{
	nullsub_129,
	DebugHandleEmergencySave,
	DebugHandleShowPCBox,
	DebugHandleWarpRequest,
	DebugHandleReloadMap,
};

void DebugCheckInterrupts()
{
	if (gDebugInterrupts.funcId != 0)
	{
		sDebugCommands[gDebugInterrupts.funcId]();
		gDebugInterrupts.funcId = 0;
	}
}

// parameters: none
void DebugHandleEmergencySave()
{
	SaveGame(); //"Would you like to save the game?"
	SET_SUCCESS();
}

// parameters: none
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

void DebugHandleReloadMap()
{
	struct WarpData data = gSaveBlock1Ptr->location;
	
	SetWarpDestination(data.mapGroup, data.mapNum, -1, data.x, data.y);
	WarpIntoMap();
	SET_SUCCESS();
}
