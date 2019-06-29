#include "global.h"
#include "te_debug.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "script.h"
#include "start_menu.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "event_data.h"
#include "event_obj_lock.h"
#include "event_object_movement.h"
#include "random.h"
#include "credits.h"
#include "scanline_effect.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "palette.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"
#include "sound.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;
extern void nullsub_129(void);

// References to scripts defined in data/scripts/te_debug.inc
extern const u8 DebugScript_EmergencySave[];
extern const u8 DebugScript_ShowPCBox[];
extern const u8 DebugScript_ShowDebugScreen[];
extern const u8 DebugScript_ShowSoundTest[];
extern const u8 DebugScript_MessageEnd[];
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
static void DebugHandle_ShowSoundTest();
static void DebugHandle_SetFlag();
static void DebugHandle_SetVar();
static void Task_InitMusicSelect(u8 taskId);

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
	DebugHandle_ShowSoundTest,
	DebugHandle_SetFlag,
	DebugHandle_SetVar,
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
    DoWarp();
    ResetInitialPlayerAvatarState();
	
	DebugSetCallbackSuccess();
	return;
error:
	DebugSetCallbackFailure();
	return;
}

// arguments: none
void DebugHandle_ReloadMap()
{
	struct Coords16 pos = gSaveBlock1Ptr->pos;
	struct WarpData data = gSaveBlock1Ptr->location;
	
	SetWarpDestination(data.mapGroup, data.mapNum, -1, pos.x, pos.y);
	DoWarp();
	ResetInitialPlayerAvatarState();
	
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

// arguments: none
// returns: none
void DebugHandle_ShowSoundTest()
{
	CreateTask(Task_InitMusicSelect, 0);
	ScriptContext1_SetupScript(DebugScript_ShowSoundTest);
	DebugSetCallbackSuccess();
}

extern const u8 gYN_Yes[];
extern const u8 gYN_No[];
static const u8 sText_TestStringFlag[] = _("Flag: {STR_VAR_1} -> {STR_VAR_2}{PAUSE 40}");
bool8 ShowFieldAutoScrollMessage(const u8 *str);
// arguments:
//   args[0] = 1=set, 0=clear
//   args[2]+2 = flagid
// returns: none
void DebugHandle_SetFlag()
{
	bool8 set = gDebugInterrupts.args[0];
	u16 id = T2_READ_16(gDebugInterrupts.args + 2);
	if (id > FLAG_DAILY_0x95F) {
		DebugSetCallbackFailure();
		return;
	}
	if (GetFlagPointer(id) == NULL) {
		DebugSetCallbackFailure();
		return;
	}
	
	if (set) {
		FlagSet(id);
	} else {
		FlagClear(id);
	}
	
	ConvertIntToHexStringN(gStringVar1, id, 2, 3);
	StringCopy(gStringVar2, (FlagGet(id))? gYN_Yes : gYN_No);
    StringExpandPlaceholders(gStringVar4, sText_TestStringFlag);
    ShowFieldAutoScrollMessage(gStringVar4);
	ScriptContext1_SetupScript(DebugScript_MessageEnd);
	
	DebugSetCallbackSuccess();
}

static const u8 sText_TestStringVar[] = _("Var: {STR_VAR_1} = {STR_VAR_2} -> {STR_VAR_3}{PAUSE 40}");
// arguments:
//   args[0]+2 = value
//   args[2]+2 = flagid
// returns: none
void DebugHandle_SetVar()
{
	u16 val = T2_READ_16(gDebugInterrupts.args+0);
	u16 id  = T2_READ_16(gDebugInterrupts.args+2);
	u16 oldval;
	if (id > 0xFF) {
		DebugSetCallbackFailure();
		return;
	}
	if (GetVarPointer(id+VARS_START) == NULL) {
		DebugSetCallbackFailure();
		return;
	}
	
	oldval = VarGet(id+VARS_START);
	VarSet(id+VARS_START, val);
	
	ConvertIntToHexStringN(gStringVar1, id, 2, 3);
	ConvertIntToDecimalStringN(gStringVar2, oldval, 2, 3);
	ConvertIntToDecimalStringN(gStringVar3, VarGet(id+VARS_START), 2, 3);
    StringExpandPlaceholders(gStringVar4, sText_TestStringVar);
    ShowFieldAutoScrollMessage(gStringVar4);
	ScriptContext1_SetupScript(DebugScript_MessageEnd);
	
	DebugSetCallbackSuccess();
}

///////////////////////////////////////////////////////////////////////////////
// Sound Test Dialog

extern const u8 DebugScript_Text_SoundTest_SFX[];
extern const u8 DebugScript_Text_SoundTest_BGM[];
extern const u8 DebugScript_Text_SoundTest_PH[];
static const struct WindowTemplate sSoundTestWinTemplate =
{
	.bg = 0,
	.tilemapLeft = 20,
	.tilemapTop = 11,
	.width = 8,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x0176,
};

static void Task_MusicSelect(u8 taskId);

static void RedrawSongSelectWindow(u8 windowId, u16 num)
{
	const u8* txt = DebugScript_Text_SoundTest_SFX;
	num--;
	if (num >= MUS_TETSUJI) txt = DebugScript_Text_SoundTest_BGM;
	if (num >= PH_TRAP_BLEND) txt = DebugScript_Text_SoundTest_PH;
	
	ConvertIntToDecimalStringN(gStringVar1, num, 2, 3);
    StringExpandPlaceholders(gStringVar4, txt);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
}

#define tWindow data[0]
#define tSelected data[1]
#define tMax data[2]
#define tMapMusic data[3]


static void Task_InitMusicSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
	
	tSelected = MUS_TETSUJI + 1;
	tMax = PH_NURSE_SOLO + 1;
	tWindow = AddWindow(&sSoundTestWinTemplate);
	tMapMusic = GetCurrentMapMusic();
	
	StopMapMusic();
    DrawStdWindowFrame(tWindow, FALSE);
	FillWindowPixelBuffer(tWindow, PIXEL_FILL(1));
	RedrawSongSelectWindow(tWindow, tSelected);
    schedule_bg_copy_tilemap_to_vram(0);

    gTasks[taskId].func = Task_MusicSelect;
}

static void Task_MusicSelect(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tSelected, tMax) == TRUE)
    {
        RedrawSongSelectWindow(tWindow, tSelected);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        // PlaySE(SE_SELECT);
		PlayBGM(tSelected-1);
    }
    else if (gMain.newKeys & B_BUTTON)
	{
		PlayBGM(MUS_NONE);
	}
    else if (gMain.newKeys & START_BUTTON)
    {
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(tWindow, 0);
		ClearWindowTilemap(tWindow);
		RemoveWindow(tWindow);
		EnableBothScriptContexts();
		ResetMapMusic();
		PlayNewMapMusic(tMapMusic);
		DestroyTask(taskId);
    }
}

#undef tWindow
#undef tSelected
#undef tMax

///////////////////////////////////////////////////////////////////////////////
// Debug Screen Common Callbacks

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
