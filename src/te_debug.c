#include "global.h"
#include "te_debug.h"
#include "main.h"
#include "script.h"
#include "start_menu.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "event_obj_lock.h"
#include "event_object_movement.h"
#include "random.h"
#include "credits.h"
#include "field_weather.h"
#include "constants/maps.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;
extern void nullsub_129(void);

// References to scripts defined in data/scripts/te_debug.inc
extern const u8 DebugScript_EmergencySave[];
extern const u8 DebugScript_ShowPCBox[];
extern const u8 DebugScript_GiveDebugPartyAndSetFlags[];

typedef void (*DebugFunc)(void);

extern bool8 gSoftResetDisabled;

void DebugCheckInterrupts();
static void DebugHandle_EmergencySave();
static void DebugHandle_ShowPCBox();
static void DebugHandle_WarpRequest();
static void DebugHandle_ReloadMap();
static void DebugHandle_ShowCredits();
static void DebugHandle_GetRandomSeeds();
static void DebugHandle_SetRandomSeeds();
static void DebugHandle_SetWeather();

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
	DebugHandle_EmergencySave,
	DebugHandle_ShowPCBox,
	DebugHandle_WarpRequest,
	DebugHandle_ReloadMap,
	DebugHandle_ShowCredits,
	DebugHandle_GetRandomSeeds,
	DebugHandle_SetRandomSeeds,
	DebugHandle_SetWeather,
};

#define DEBUGFN_COUNT ((int)(sizeof(sDebugCommands)/sizeof(DebugFunc)))

void DebugResetInterrupts()
{
	memset((u8*)&gDebugInterrupts, 0, sizeof(struct DebugInterrupts));
}

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
void DebugHandle_EmergencySave()
{
	ScriptContext1_SetupScript(DebugScript_EmergencySave);
}

// parameters: none
// returns: none
void DebugHandle_ShowPCBox()
{
	ScriptContext1_SetupScript(DebugScript_ShowPCBox);
}

// parameters: none
// returns: none
void DebugHandle_ShowCredits()
{
	SetMainCallback2(CB2_StartCreditsSequence);
	DebugSetCallbackSuccess();
	// Credits will end with the game soft resetting.
}

// parameters: 
//	 args[0] = mapGroup
//	 args[1] = mapNum
//	 args[2] = warpId
//	 args[3] = x
//	 args[4] = y
// returns: none
void DebugHandle_WarpRequest()
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
void DebugHandle_ReloadMap()
{
	struct WarpData data = gSaveBlock1Ptr->location;
	
	SetWarpDestination(data.mapGroup, data.mapNum, -1, data.x, data.y);
	WarpIntoMap();
	DebugSetCallbackSuccess();
}

// arguments: none
// returns: gRngValue copied to +4, gRng2Value copied to +8
void DebugHandle_GetRandomSeeds()
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
void DebugHandle_SetRandomSeeds()
{
	u32 *val1 = (u32*)&gDebugInterrupts.args[2]; //choose word-aligned address
	u32 *val2 = (u32*)&gDebugInterrupts.args[6];
	gRngValue = *val1;
	gRng2Value = *val2;
	DebugSetCallbackSuccess();
}

// arguments: 
// 	 args[0] = weather id to set
// returns: none
void DebugHandle_SetWeather()
{
	SetWeather(gDebugInterrupts.args[0]);
	DebugSetCallbackSuccess();
}