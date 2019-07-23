#include "global.h"
#include "bg.h"
#include "cutscene_mourning.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "alloc.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "script.h"
#include "scanline_effect.h"

struct MourningSceneData
{
	u8 bg0HOff;
	u8 bg0VOff;
	u8 bg1HOff;
	u8 bg1VOff;
	u8 bg2HOff;
	u8 bg2VOff;
	u16 bgTilemapBuffers[4][0x800];
};

static void CB2_MourningMain(void);
static void VblankCallback_MourningScene(void);
static void Task_MourningMain(u8 taskId);


const struct BgTemplate sBgTemplates[4] = {
	{
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

static EWRAM_DATA struct MourningSceneData *sSceneData = NULL;

static void ResetGpuRegisters()
{
	SetGpuReg(REG_OFFSET_WININ, 0);
	SetGpuReg(REG_OFFSET_WINOUT, 0);
	SetGpuReg(REG_OFFSET_WIN0H, 0);
	SetGpuReg(REG_OFFSET_WIN1H, 0);
	SetGpuReg(REG_OFFSET_WIN0V, 0);
	SetGpuReg(REG_OFFSET_WIN1V, 0);
	SetGpuReg(REG_OFFSET_DISPCNT, 0);
	SetGpuReg(REG_OFFSET_BG3CNT, 0);
	SetGpuReg(REG_OFFSET_BG2CNT, 0);
	SetGpuReg(REG_OFFSET_BG1CNT, 0);
	SetGpuReg(REG_OFFSET_BG0CNT, 0);
	SetGpuReg(REG_OFFSET_BG3HOFS, 0);
	SetGpuReg(REG_OFFSET_BG3VOFS, 0);
	SetGpuReg(REG_OFFSET_BG2HOFS, 0);
	SetGpuReg(REG_OFFSET_BG2VOFS, 0);
	SetGpuReg(REG_OFFSET_BG1HOFS, 0);
	SetGpuReg(REG_OFFSET_BG1VOFS, 0);
	SetGpuReg(REG_OFFSET_BG0HOFS, 0);
	SetGpuReg(REG_OFFSET_BG0VOFS, 0);
	SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void CB2_MourningSetup(void)
{
	switch (gMain.state)
	{
	case 0:
		SetVBlankCallback(NULL);
		ResetGpuRegisters();
		ScanlineEffect_Stop();
		DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
		DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
		DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
		sSceneData = AllocZeroed(sizeof(*sSceneData));
	default:
		gMain.state++;
		break;
	case 1:
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetPaletteFade();
		reset_temp_tile_data_buffers();
		InitMapMusic();
        ResetMapMusic();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(0, sSceneData->bgTilemapBuffers[0]);
        SetBgTilemapBuffer(1, sSceneData->bgTilemapBuffers[1]);
        SetBgTilemapBuffer(2, sSceneData->bgTilemapBuffers[2]);
        SetBgTilemapBuffer(3, sSceneData->bgTilemapBuffers[3]);
        gMain.state++;
		break;
	case 2:
		
		break;
	
	
	
	
	case 9:
		SetVBlankCallback(VblankCallback_MourningScene);
        SetMainCallback2(CB2_MourningMain);
		CreateTask(Task_MourningMain, 0);
        
		break;
	}
}

static void CB2_MourningMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    MapMusicMain();
}

static void CB2_MourningCleanup(void)
{
	HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
	ResetGpuRegisters();
    
	ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    UnsetBgTilemapBuffer(0);
    UnsetBgTilemapBuffer(1);
    UnsetBgTilemapBuffer(2);
    UnsetBgTilemapBuffer(3);
    ResetBgsAndClearDma3BusyFlags(0);
    
	DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
    WarpIntoMap();
    gFieldCallback = NULL;
    SetMainCallback2(CB2_LoadMap);
}

static void VblankCallback_MourningScene(void)
{
	CopyBgTilemapBufferToVram(0);
    CopyBgTilemapBufferToVram(3);
	
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_MourningMain(u8 taskId)
{
	
}


static void Task_InitMourningCutscene(u8 taskId)
{
	if (!gPaletteFade.active)
	{
		SetMainCallback2(CB2_MourningSetup);
        DestroyTask(taskId);
	}
}

bool8 DoMourningCutscene()
{
	bool8 doScene = FALSE;
	//TODO Check for Unmourned Pokemon
	
	if (doScene)
	{
		ScriptContext2_Enable();
		CreateTask(Task_InitMourningCutscene, 1);
		FadeScreen(FADE_TO_BLACK_NO_WINDOW, 0);
		return TRUE;
	}
	return FALSE;
}




// TODO: move to the remembered dreams section, if they ever get added
bool8 DoDreamCutscenes()
{
	return FALSE;
}
