#if TPP_MODE

#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "starter_choose.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/rgb.h"

#define STARTER_MON_COUNT   3

#define VOTE_STEP           8
#define VOTE_THRESHOLD      24
#define START_LINE			((240-VOTE_THRESHOLD*VOTE_STEP)/2)

static const u16 sStarterMon[STARTER_MON_COUNT] =
{
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
};

const u8 gText_Options[] = 
_("{CLEAR_TO 14}Treeko{CLEAR_TO 76}Torchic{CLEAR_TO 136}Mudkip\n"
  "{CLEAR_TO 6}{L_BUTTON}{CLEAR_TO 72}{B_BUTTON}{CLEAR_TO 128}{R_BUTTON}");

const u32 gBirchGrassTilemap[] = INCBIN_U32("graphics/misc/birch_grass_map.bin.lz");
const u16 gBirchBagGrassPal[][16] =
{
    INCBIN_U16("graphics/misc/birch_bag.gbapal"),
    INCBIN_U16("graphics/misc/birch_grass.gbapal"),
};
const u32 gBirchCircleGfx[] = INCBIN_U32("graphics/misc/birch_circle.4bpp.lz");
const u16 gBirchCircle_Pal[] = INCBIN_U16("graphics/misc/birch_circle.gbapal");
const u32 gBirchBagTilemap[] = INCBIN_U32("graphics/misc/birch_bag_map.bin.lz");
const u32 gBirchHelpGfx[] = INCBIN_U32("graphics/misc/birch_help.4bpp.lz");
const u32 gBirchBallarrow_Gfx[] = INCBIN_U32("graphics/misc/birch_ballarrow.4bpp.lz");
const u16 gBirchBallarrow_Pal[] = INCBIN_U16("graphics/misc/birch_ballarrow.gbapal");

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 1,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0200,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBackgroundTemplates[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct OamData gOamData_85B1E18 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_85B1E38[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_85B1E40[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd * const gSpriteAnimTable_85B1E94[] =
{
    gSpriteAnim_85B1E38,
    gSpriteAnim_85B1E40,
};
static const struct SpriteTemplate sSpriteTemplate_PokeBall =
{
    .tileTag = 0x1000,
    .paletteTag = 0x1000,
    .oam = &gOamData_85B1E18,
    .anims = gSpriteAnimTable_85B1E94,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy, //sub_813473C
};

static const struct CompressedSpriteSheet sBirchCircleSpriteSheet[] =
{
    {
        .data = gBirchCircleGfx,
        .size = 0x0800,
        .tag = 0x1001
    },
    {}
};

static const struct SpritePalette sSpritePalettes[] =
{
    {
        .data = gBirchCircle_Pal,
        .tag = 0x1001
    },
    {},
};

///////////////////////////////////////////////////////////

static void VblankCB_StarterChoose(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCallback2_StarterChoose(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

u16 GetStarterPokemon(u16 chosenStarterId)
{
    if (chosenStarterId > STARTER_MON_COUNT)
        chosenStarterId = 0;
    return sStarterMon[chosenStarterId];
}

static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y, u8 slot)
{
    u8 spriteId;

    spriteId = CreatePicSprite2(species, 8, 0, 1, x, y, 0xF-slot, 0xFFFF);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

// static u8 CreatePokemonIconSprite(u16 species, u8 x, u8 y, u8 slot)
// {
//     u16 tileNum;
//     u8 spriteId;
// 	struct SpriteTemplate template =

//     spriteId = CreatePicSprite2(species, 8, 0, 1, x, y, 0xF-slot, 0xFFFF);
//     gSprites[spriteId].oam.priority = 0;
//     return spriteId;
// }

///////////////////////////////////////////////////////////

#define tStarterSelection   data[0]
#define tTimer              data[1]
#define MON_VOTES           4
#define MON_SPRITES         10

static void Task_StarterChoose1(u8 taskId);
static void Task_StarterChoose2(u8 taskId);

void CB2_ChooseStarter(void)
{
    u16 savedIme;
    u8 taskId;
    u8 spriteId;
	u8 i;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
    LZ77UnCompVram(gBirchBagTilemap, (void *)(BG_SCREEN_ADDR(6)));
    LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    InitWindows(sWindowTemplates);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x2A8, 0xD0);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
	
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gBirchBagGrassPal, 0, 0x40);
    LoadCompressedSpriteSheet(&sBirchCircleSpriteSheet[0]);
    LoadSpritePalettes(sSpritePalettes);
	LoadMonIconPalettes();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_StarterChoose);
    SetMainCallback2(MainCallback2_StarterChoose);

    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x1F);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    // ShowBg(3);
	
	FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    CopyWindowToVram(0, 2);
	CopyBgTilemapBufferToVram(0);
	AddTextPrinterParameterized2(0, 1, gText_Options, 0xFF, NULL, 1, 0, 2);
	
    taskId = CreateTask(Task_StarterChoose1, 0);
    gTasks[taskId].tStarterSelection = 1;
    gTasks[taskId].tTimer = 0;

    // Create Pokeball sprite
    // spriteId = CreateSprite(&sSpriteTemplate_PokeBall, 0xC6, 0x80, 2);
    // gSprites[spriteId].data[0] = taskId;
	
	// Create front sprites for the starters
	for (i = 0; i < STARTER_MON_COUNT; i++)
	{
		s16 x = ((240) / (STARTER_MON_COUNT+1)) * (i+1);
		spriteId = CreatePokemonFrontSprite(GetStarterPokemon(i), x, 48, i);
		gSprites[spriteId].data[0] = taskId;
		gSprites[spriteId].data[1] = i;
		
		spriteId = CreateMonIcon(GetStarterPokemon(i), SpriteCallbackDummy, x, 48, 0, 0, FALSE);
		gSprites[spriteId].invisible = TRUE;
		gSprites[spriteId].data[0] = taskId;
		gSprites[spriteId].data[1] = i;
		gTasks[taskId].data[MON_SPRITES+i] = spriteId;
	}
}

static void Task_StarterChoose1(u8 taskId)
{
	u8 i;
	if (gPaletteFade.active)
	{
		RunTextPrinters();
		CopyWindowToVram(0, 2);
		return;
	}
	
	gTasks[taskId].tTimer++;
	if (gTasks[taskId].tTimer < 36*2)
	{
		return;
	}
	
	// Move the sprites to the starting line
	for (i = 0; i < STARTER_MON_COUNT; i++)
	{
		u16 sid = gTasks[taskId].data[MON_SPRITES+i];
		s16 destX = START_LINE;
		s16 destY = 84 + (24 * i);
		s16 deltaX = (gSprites[sid].pos1.x - destX) / 16;
		s16 deltaY = (gSprites[sid].pos1.y - destY) / 16;
		gSprites[sid].invisible = FALSE;
		if (deltaX == 0) {
			deltaX = (gSprites[sid].pos1.x - destX);
			deltaX = (deltaX == 0)? 0 : ((deltaX > 0)? 1 : -1);
		}
		if (deltaY == 0) {
			deltaY = (gSprites[sid].pos1.y - destY);
			deltaY = (deltaY == 0)? 0 : ((deltaY > 0)? 1 : -1);
		}
		gSprites[sid].pos1.x -= deltaX;
		gSprites[sid].pos1.y -= deltaY;
	}
	
	if (gTasks[taskId].tTimer < 36*5)
	{
		return;
	}
	
	for (i = 0; i < STARTER_MON_COUNT; i++)
	{
		u16 sid = gTasks[taskId].data[MON_SPRITES+i];
		gSprites[sid].pos1.x = START_LINE;
		gSprites[sid].pos1.y = 84 + (24 * i);
		gSprites[sid].hFlip = TRUE;
		gTasks[taskId].data[MON_VOTES+i];
	}
	gTasks[taskId].tTimer = 0;
	gTasks[taskId].func = Task_StarterChoose2;
}

static void Task_StarterChoose2(u8 taskId)
{
	u8 i;
	if (gMain.newKeysRaw == L_BUTTON)
	{
		gTasks[taskId].data[MON_VOTES+0]++;
	}
	else if (gMain.newKeysRaw == B_BUTTON)
	{
		gTasks[taskId].data[MON_VOTES+1]++;
	}
	else if (gMain.newKeysRaw == R_BUTTON)
	{
		gTasks[taskId].data[MON_VOTES+2]++;
	}
	else if (gMain.newKeysRaw)
	{
		for (i = 0; i < STARTER_MON_COUNT; i++)
		{
			gTasks[taskId].data[MON_VOTES+i]--;
		}
	}
	
	for (i = 0; i < STARTER_MON_COUNT; i++)
	{
		u16 sid = gTasks[taskId].data[MON_SPRITES+i];
		u16 votes = gTasks[taskId].data[MON_VOTES+i];
		if (votes > 100) //check for rollover
		{
			gTasks[taskId].data[MON_VOTES+i] = votes = 0;
		}
		gSprites[sid].pos1.x = START_LINE + (VOTE_STEP * votes);
		gSprites[sid].pos1.y = 84 + (24 * i);
	}
	
	for (i = 0; i < STARTER_MON_COUNT; i++)
	{
		if (gTasks[taskId].data[MON_VOTES+i] >= VOTE_THRESHOLD)
		{
			gSpecialVar_Result = i;
			ResetAllPicSprites();
        	SetMainCallback2(gMain.savedCallback);
			return;
		}
	}
}




#endif