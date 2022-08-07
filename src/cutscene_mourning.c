#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "cutscene_mourning.h"
#include "data.h"
#include "dma3.h"
#include "decompress.h"
#include "evolution_scene.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "menu_specialized.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "sound.h"
#include "script.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "constants/songs.h"

enum
{
    STATE_WAIT_FADE_IN,
    STATE_DELAY_1,
    STATE_DELAY_2,
    STATE_SELECT_MON,
    STATE_FADE_IN_MON_PIC,
    STATE_SHOW_MOURN_MESSAGE,
    STATE_WAIT_MOURN_MESSAGE,
    STATE_WAIT_SECONDARY_MOURN_MESSAGE,
    STATE_TALLY_EXP,
    STATE_FADE_OUT_MON,
    STATE_FADE_SCENE,
    STATE_START_GRANT_EXP,
    STATE_WAIT_GRANT_EXP,
    STATE_START_EXIT,
    STATE_EXIT,
};

#define MOURN_MESSAGE_DELAY_FRAMES 180
#define FADE_IN_MON_PIC_FRAMES 120
#define FADE_OUT_MON_PIC_FRAMES 120
#define MOURN_STONE_OFFSET_START (8*2*9)

#define TAG_MON_PIC 3000

#define BG_TEXT 0
#define BG_MON 1
#define BG_HEADSTONE 2

#define WIN_TEXT 0

struct MourningScene
{
    u8 state;
    u8 expTaskId;
    u8 curPartyIndex;
    u16 expGain;
    u16 curExpGain;
    u8 levelUpWindowId;
    bool8 learningFirstMove;
    struct BoxPokemon *boxMon;
    int fadeMonPicCounter;
    u16 mournMessageDelayCounter;
    u16 partyExpGain[PARTY_SIZE];
    u16 statsBeforeLevelUp[NUM_STATS];
    u16 statsAfterLevelUp[NUM_STATS];
    u16 *bgTilemapBuffer0;
    u16 *bgTilemapBuffer1;
    u16 *bgTilemapBuffer2;
};

static void CB2_MourningMain(void);
static void VblankCallback_MourningScene(void);
static void Task_MourningMain(u8 taskId);
static void SelectNextMonToMourn(void);
static void FadeInMonPic(void);
static void ShowMournMessage(void);
static void WaitMournMessage(void);
static void WaitSecondaryMournMessage(void);
static void TallyExpGain(void);
static void StartGrantExperience(void);
static void Task_InitGiveExpToParty(u8 taskId);
static void Task_ChoosePartyMember(u8 taskId);
static void Task_GiveExpToParty(u8 taskId);
static void Task_LevelUp(u8 taskId);
static void Task_LevelUp_WaitMessage(u8 taskId);
static void Task_LevelUp_WaitLevelupWindowPart1(u8 taskId);
static void Task_LevelUp_WaitLevelupWindowPart2(u8 taskId);
static void Task_TeachMove(u8 taskId);
static void Task_WaitSwappedMoveMessage(u8 taskId);
static void Task_WaitReplaceMoveMessage(u8 taskId);
static void Task_GetReplaceMoveInput(u8 taskId);
static void Task_WaitWhichMoveToForgetMessage(u8 taskId);
static void Task_WaitLearnNewMoveFade(u8 taskId);
static void Task_WaitStopLearningMoveMessage(u8 taskId);
static void Task_GetStopLearningMoveInput(u8 taskId);
static void Task_LevelUp_WaitFinalMoveMessage(u8 taskId);
static void Task_TryEvolve(u8 taskId);
static void WaitGrantExperience(void);
static void FadeOutMonPic(void);
static void FreeCutsceneResources(void);
static void ExitMourningScene(void);

/*static*/ EWRAM_DATA struct MourningScene *sMourningScene = NULL;

const struct BgTemplate sBgTemplates[] = {
    {
        .bg = BG_TEXT,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = BG_MON,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = BG_HEADSTONE,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct WindowTemplate sWindows[] =
{
    {
        .bg = BG_TEXT,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sLevelUpWindow =
{
    .bg = BG_TEXT,
    .tilemapLeft = 19,
    .tilemapTop = 1,
    .width = 10,
    .height = 11,
    .paletteNum = 13,
    .baseBlock = 0x71,
};

static const struct WindowTemplate sYesNoWindow =
{
    .bg = BG_TEXT,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 13,
    .baseBlock = 0x71,
};

static const u32 sHeadstone_Gfx[] = INCBIN_U32("graphics/cutscene_mourning/headstone_bg_tiles.4bpp.lz");
static const u16 sHeadstone_Palette[] = INCBIN_U16("graphics/cutscene_mourning/headstone_bg_tiles.gbapal");
static const u32 sHeadstone_Tilemap[] = INCBIN_U32("graphics/cutscene_mourning/headstone_bg_tilemap.bin.lz");
static const u32 sMonBgSprite_Tilemap[] = INCBIN_U32("graphics/cutscene_mourning/mon_sprite_bg_tilemap.bin.lz");

static const u8 sText_TeamRemembersBattles[] = _("Your team remembers their battles\nwith {STR_VAR_1}.");
static const u8 sText_GoodbyeMon[] = _("Goodbye, {STR_VAR_1}.");

static struct BoxPokemon *GetMonToMourn(void)
{
    int i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            struct BoxPokemon *mon = &gPokemonStoragePtr->boxes[i][j];
            if (GetBoxMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE 
             && !GetBoxMonData(mon, MON_DATA_IS_EGG)
             && !GetBoxMonData(mon, MON_DATA_HAS_MOURNED))
            {
                return mon;
            }
        }
    }
    return NULL;
}

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

static void InitMourningSceneGraphics()
{
    switch (gMain.state)
    {
        default:
            gMain.state++;
            break;
        case 0:
            SetVBlankCallback(NULL);
            ResetGpuRegisters();
            ScanlineEffect_Stop();
            ResetTasks();
            gMain.state++;
            break;
        case 1:
            DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
            DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
            DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
            FillPalette(RGB_BLACK, 0, PLTT_SIZE);
            gMain.state++;
            break;
        case 2:
            ResetSpriteData();
            FreeAllSpritePalettes();
            ResetPaletteFade();
            reset_temp_tile_data_buffers();
            InitMapMusic();
            ResetMapMusic();
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
            sMourningScene->bgTilemapBuffer0 = AllocZeroed(BG_SCREEN_SIZE);
            sMourningScene->bgTilemapBuffer1 = AllocZeroed(BG_SCREEN_SIZE);
            sMourningScene->bgTilemapBuffer2 = AllocZeroed(BG_SCREEN_SIZE);
            SetBgTilemapBuffer(BG_TEXT, sMourningScene->bgTilemapBuffer0);
            SetBgTilemapBuffer(BG_MON, sMourningScene->bgTilemapBuffer1);
            SetBgTilemapBuffer(BG_HEADSTONE, sMourningScene->bgTilemapBuffer2);
            gMain.state++;
            break;
        case 3:
            LZDecompressVram(sHeadstone_Gfx, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sHeadstone_Tilemap, (void*)(BG_SCREEN_ADDR(29)));
            LoadPalette(sHeadstone_Palette, 0, sizeof(sHeadstone_Palette));
            LZDecompressVram(sMonBgSprite_Tilemap, (void *)(BG_SCREEN_ADDR(28)));
            gMain.state++;
            break;
        case 4:
            ScanlineEffect_InitWave(0, DISPLAY_HEIGHT, 8, 2, 1, SCANLINE_EFFECT_REG_BG1HOFS, TRUE, &gBattle_BG1_Y);

            InitWindows(sWindows);
            LoadStdWindowFrame();
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(BG_TEXT);
            ShowBg(BG_MON);
            ShowBg(BG_HEADSTONE);
            gMain.state++;
            break;
    }
}

static void LoadMournedMonGfx(u16 species, u32 personality, u32 otId)
{
    LoadCompressedPalette(GetMonSpritePalStructFromOtIdPersonality(species, otId, personality)->data, 0x10, 0x20);
    LoadSpecialPokePic_DontHandleDeoxys(
        &gMonFrontPicTable[species],
        gDecompressionBuffer,
        species,
        personality,
        TRUE);
    RequestDma3Copy(gDecompressionBuffer, (void *)(BG_CHAR_ADDR(0)), gMonFrontPicTable[species].size, 0);
}

#define tFrameCount data[0]
#define tHeadstoneOffset data[1]

static void CB2_MourningSetup(void)
{
    u8 taskId;
    InitMourningSceneGraphics();
    if (gMain.state >= 5)
    {
        PlayBGM(MUS_END);
        BeginNormalPaletteFade(0xFFFFFFFF, 4, 16, 0, RGB_BLACK);
        SetVBlankCallback(VblankCallback_MourningScene);
        SetMainCallback2(CB2_MourningMain);
        taskId = CreateTask(Task_MourningMain, 0);
        gTasks[taskId].tHeadstoneOffset = MOURN_STONE_OFFSET_START;
        SetGpuReg(REG_OFFSET_BG2HOFS, -(gTasks[taskId].tHeadstoneOffset >> 1));
    }
}

static void CB2_MourningMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void VblankCallback_MourningScene(void)
{
    ScanlineEffect_InitHBlankDmaTransfer();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
}


static void UpdateBackgroundVerticalScrolls(u8 taskId)
{
    gTasks[taskId].tFrameCount += 0x28;
    if (gTasks[taskId].tFrameCount >= 0x1000)
        gTasks[taskId].tFrameCount %= 0x1000;
    
    gBattle_BG1_Y = Sin(gTasks[taskId].tFrameCount >> 4, 5) - 32;
}

static void Task_MourningMain(u8 taskId)
{
    UpdateBackgroundVerticalScrolls(taskId);
    
    if (sMourningScene->state > STATE_DELAY_1 && gTasks[taskId].tHeadstoneOffset > 0)
    {
        gTasks[taskId].tHeadstoneOffset--;
        SetGpuReg(REG_OFFSET_BG2HOFS, -(gTasks[taskId].tHeadstoneOffset >> 1));
    }

    switch (sMourningScene->state)
    {
    case STATE_WAIT_FADE_IN:
        if (!gPaletteFade.active) {
            sMourningScene->mournMessageDelayCounter = 0;
            sMourningScene->state = STATE_DELAY_1;
        }
        break;
    case STATE_DELAY_1:
        if (++sMourningScene->mournMessageDelayCounter > 3*30) {
            sMourningScene->mournMessageDelayCounter = 0;
            sMourningScene->state = STATE_DELAY_2;
        }
        break;
    case STATE_DELAY_2:
        if (++sMourningScene->mournMessageDelayCounter > 2*30) {
            sMourningScene->state = STATE_SELECT_MON;
        }
        break;
    case STATE_SELECT_MON:
        SelectNextMonToMourn();
        break;
    case STATE_FADE_IN_MON_PIC:
        FadeInMonPic();
        break;
    case STATE_SHOW_MOURN_MESSAGE:
        ShowMournMessage();
        break;
    case STATE_WAIT_MOURN_MESSAGE:
        WaitMournMessage();
        break;
    case STATE_WAIT_SECONDARY_MOURN_MESSAGE:
        WaitSecondaryMournMessage();
        break;
    case STATE_TALLY_EXP:
        TallyExpGain();
        break;
    case STATE_FADE_OUT_MON:
        FadeOutMonPic();
        break;
    case STATE_FADE_SCENE:
        BeginNormalPaletteFade(0xFFFF0FFF, 4, 0, 16, RGB_BLACK);
        sMourningScene->state = STATE_START_GRANT_EXP;
        break;
    case STATE_START_GRANT_EXP:
        if (!gPaletteFade.active)
        {
            sMourningScene->expTaskId = CreateTask(Task_InitGiveExpToParty, 3);
            sMourningScene->state = STATE_WAIT_GRANT_EXP;
        }
        break;
    case STATE_WAIT_GRANT_EXP:
        if (sMourningScene->expTaskId == 0xFF)
        {
            sMourningScene->state = STATE_START_EXIT;
        }
        break;
    case STATE_START_EXIT:
        // BeginNormalPaletteFade(0xFFFF0FFF, 0, 0, 16, RGB_BLACK);
        sMourningScene->state = STATE_EXIT;
        break;
    case STATE_EXIT:
        ExitMourningScene();
        break;
    }
}

static void SelectNextMonToMourn(void)
{
    struct BoxPokemon *mon = GetMonToMourn();
    sMourningScene->boxMon = mon;
    if (mon)
    {
        u16 species = GetBoxMonData(mon, MON_DATA_SPECIES);
        u32 otId = GetBoxMonData(mon, MON_DATA_OT_ID);
        u32 personality = GetBoxMonData(mon, MON_DATA_PERSONALITY);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        LoadMournedMonGfx(species, personality, otId);
        sMourningScene->fadeMonPicCounter = 0;
        sMourningScene->state = STATE_FADE_IN_MON_PIC;
    }
    else
    {
        sMourningScene->state = STATE_FADE_SCENE;
    }
}
static void FadeInMonPic(void)
{
    if (++sMourningScene->fadeMonPicCounter > FADE_IN_MON_PIC_FRAMES)
    {
        sMourningScene->state = STATE_SHOW_MOURN_MESSAGE;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    }
    else
    {
        int blend = (sMourningScene->fadeMonPicCounter * 16) / FADE_IN_MON_PIC_FRAMES;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(blend, 16 - blend));
    }
}

static void ShowMournMessage(void)
{
    u8 x;
    DrawStdWindowFrame(WIN_TEXT, TRUE);
    GetBoxMonData(sMourningScene->boxMon, MON_DATA_NICKNAME, gStringVar1);
    StringGetEnd10(gStringVar1);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 224);
    AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar1, x, 8, TEXT_SPEED_FF, NULL);
    sMourningScene->mournMessageDelayCounter = 0;
    sMourningScene->state = STATE_WAIT_MOURN_MESSAGE;
}

static void WaitMournMessage(void)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
#if TPP_MODE
        if (++sMourningScene->mournMessageDelayCounter >= MOURN_MESSAGE_DELAY_FRAMES)
#else
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
#endif
        {
            FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
            CopyWindowToVram(WIN_TEXT, 3);
            if (GetBoxMonAffectionLevel(sMourningScene->boxMon) >= AFFECTION_LEVEL_GRANT_MOURN_EXP)
            {
                GetBoxMonData(sMourningScene->boxMon, MON_DATA_NICKNAME, gStringVar1);
                StringExpandPlaceholders(gStringVar4, sText_TeamRemembersBattles);
                AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
                sMourningScene->mournMessageDelayCounter = 0;
                sMourningScene->state = STATE_WAIT_SECONDARY_MOURN_MESSAGE;
            }
            else
            {
                sMourningScene->fadeMonPicCounter = 0;
                sMourningScene->state = STATE_FADE_OUT_MON;
            }
        }
    }
}

static void WaitSecondaryMournMessage(void)
{
    int i;

    if (!IsTextPrinterActive(WIN_TEXT))
    {
#if TPP_MODE
        if (++sMourningScene->mournMessageDelayCounter >= MOURN_MESSAGE_DELAY_FRAMES)
#else
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
#endif
        {
            FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
            CopyWindowToVram(WIN_TEXT, 3);
            sMourningScene->state = STATE_TALLY_EXP;
        }
    }
}

static u16 GetMourningExpToGrant(struct BoxPokemon *deadMon, struct Pokemon *mon, u8 i)
{
    u8 level, affection;
    u16 species;
    u32 expGain, expMult;
    
    // Sanity check: Cannot give EXP to a nonexistant mon
    species = GetMonData(mon, MON_DATA_SPECIES);
    if (species == SPECIES_NONE || species == SPECIES_EGG) return 0;
    
    // Sanity check: Cannot get EXP from a nonexistant mon
    species = GetBoxMonData(deadMon, MON_DATA_SPECIES);
    if (species == SPECIES_NONE || species == SPECIES_EGG) return 0;
    
    // Sanity check: Cannot get EXP from an invalid mon
    level = GetLevelFromBoxMonExp(deadMon);
    if (level > 100 || level == 0) return 0;
    
    // If the dead mon did not get to affection level 1, no EXP
    affection = GetBoxMonAffectionLevel(deadMon);
    if (affection == 0) return 0;
    
    // Calculate EXP to gain
    expGain = gBaseStats[species].expYield * level / 7;
    if (expGain == 0) return 0;
    
    // Determine boost
    affection = GetMonAffectionLevel(mon);
    switch (affection)
    {
        default:                expMult = 100; break;
        case AFFECTION_LEVEL_1: expMult = 100; break;
        case AFFECTION_LEVEL_2: expMult = 115; break;
        case AFFECTION_LEVEL_3: expMult = 125; break;
        case AFFECTION_LEVEL_4: expMult = 160; break;
        case AFFECTION_LEVEL_5: expMult = 200; break;
    }
    expGain = (expGain * expMult) / 100;
    return expGain;
}

static void TallyExpGain(void)
{
    u8 i;
    u16 species;
    struct Pokemon *mon;
    
    CalculatePlayerPartyCount();
    for (i = 0; i < gPlayerPartyCount && i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon, MON_DATA_SPECIES);
        if (species == SPECIES_NONE) continue;
        if (species == SPECIES_EGG) continue;
        if (GetBoxMonData(mon, MON_DATA_IS_EGG)) continue;
        if (GetMonData(mon, MON_DATA_LEVEL) >= MAX_LEVEL) continue;
        
        sMourningScene->partyExpGain[i] += GetMourningExpToGrant(sMourningScene->boxMon, mon, i);
    }
    sMourningScene->fadeMonPicCounter = 0;
    sMourningScene->state = STATE_FADE_OUT_MON;
}

static void FadeOutMonPic(void)
{
    if (sMourningScene->fadeMonPicCounter == 0) 
    {
        u8 hasMourned = 1;
        SetBoxMonData(sMourningScene->boxMon, MON_DATA_HAS_MOURNED, &hasMourned);
        GetBoxMonData(sMourningScene->boxMon, MON_DATA_NICKNAME, gStringVar1);
        StringExpandPlaceholders(gStringVar4, sText_GoodbyeMon);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        sMourningScene->fadeMonPicCounter++;
    }
    
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        if (++sMourningScene->fadeMonPicCounter > FADE_OUT_MON_PIC_FRAMES)
        {
            ClearStdWindowAndFrameToTransparent(WIN_TEXT, TRUE);
            sMourningScene->mournMessageDelayCounter = 0;
            sMourningScene->state = STATE_DELAY_2;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        }
        else
        {
            int blend = (sMourningScene->fadeMonPicCounter * 16) / FADE_OUT_MON_PIC_FRAMES;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - blend, blend));
        }
    }
}

static void FreeCutsceneResources(void)
{
    FreeAllWindowBuffers();
    ResetSpriteData();
    FreeAllSpritePalettes();
    FREE_AND_SET_NULL(sMourningScene->bgTilemapBuffer0);
    FREE_AND_SET_NULL(sMourningScene->bgTilemapBuffer1);
    FREE_AND_SET_NULL(sMourningScene->bgTilemapBuffer2);
}

static void ExitMourningScene(void)
{
    if (!gPaletteFade.active)
    {
        FreeCutsceneResources();

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

        FREE_AND_SET_NULL(sMourningScene);
        FlagSet(FLAG_DISABLE_FADE_INIT);
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        // Overworld_PlaySpecialMapMusic();
    }
}

///////////////////////////////////////////////////////////////////////////////
// EXP and Level gains

#define DEBUG_COLOR(color)
// #define DEBUG_COLOR(color) CpuFill16(color, gPlttBufferFaded, 0x20)

#define tCurPartyIndex sMourningScene->curPartyIndex
#define tTotalExpToGain sMourningScene->expGain
#define tExpLeftToGain sMourningScene->curExpGain

static void CopyMonStats(struct Pokemon *mon, u16 *stats)
{
    stats[STAT_HP] = GetMonData(mon, MON_DATA_MAX_HP);
    stats[STAT_ATK] = GetMonData(mon, MON_DATA_ATK);
    stats[STAT_DEF] = GetMonData(mon, MON_DATA_DEF);
    stats[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK);
    stats[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF);
    stats[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED);
}

static void Task_InitGiveExpToParty(u8 taskId)
{
    tCurPartyIndex = 0;
    CalculatePlayerPartyCount();
    gTasks[taskId].func = Task_ChoosePartyMember;
    DEBUG_COLOR(RGB_RED);
}

static void Task_ChoosePartyMember(u8 taskId)
{
    struct Pokemon *mon;
    if (tCurPartyIndex >= gPlayerPartyCount)
    {
        DestroyTask(taskId);
        sMourningScene->expTaskId = 0xFF;
        DEBUG_COLOR(RGB_BLACK);
        return;
    }

    mon = &gPlayerParty[tCurPartyIndex];
    
    while (GetBoxMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE 
        || GetBoxMonData(mon, MON_DATA_IS_EGG)
        || GetMonData(mon, MON_DATA_LEVEL) >= MAX_LEVEL)
    {
        tCurPartyIndex++;
        if (tCurPartyIndex >= gPlayerPartyCount)
        {
            DestroyTask(taskId);
            sMourningScene->expTaskId = 0xFF;
            DEBUG_COLOR(RGB_BLACK);
            return;
        }

        mon = &gPlayerParty[tCurPartyIndex];
    }
    
    tTotalExpToGain = sMourningScene->partyExpGain[tCurPartyIndex];
    if (tTotalExpToGain > 0)
    {
        tExpLeftToGain = tTotalExpToGain;
        gTasks[taskId].func = Task_GiveExpToParty;
        DEBUG_COLOR(RGB_BLUE);
    }
    else
    {
        tCurPartyIndex++;
        DEBUG_COLOR(RGB_MAGENTA);
    }
}

static void Task_GiveExpToParty(u8 taskId)
{
    u16 species;
    u8 level;
    u32 curExp;
    u32 nextLevelExp;
    u16 expGain;
    struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];
    
    expGain = tExpLeftToGain;
    species = GetMonData(mon, MON_DATA_SPECIES);
    level = GetMonData(mon, MON_DATA_LEVEL);
    curExp = GetMonData(mon, MON_DATA_EXP);
    nextLevelExp = gExperienceTables[gBaseStats[species].growthRate][level + 1];

    if (curExp + expGain >= nextLevelExp)
    {
        CopyMonStats(mon, sMourningScene->statsBeforeLevelUp);
        SetMonData(mon, MON_DATA_EXP, &nextLevelExp);
        CalculateMonStats(mon);
        CopyMonStats(mon, sMourningScene->statsAfterLevelUp);
        tExpLeftToGain -= nextLevelExp - curExp;
        gTasks[taskId].func = Task_LevelUp;
        DEBUG_COLOR(RGB_GREEN);
    }
    else
    {
        curExp += expGain;
        SetMonData(mon, MON_DATA_EXP, &curExp);
        tCurPartyIndex++;
        gTasks[taskId].func = Task_ChoosePartyMember;
        DEBUG_COLOR(RGB_YELLOW);
    }
}

static void Task_LevelUp(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];
    DrawStdWindowFrame(WIN_TEXT, TRUE);
    PlayFanfareByFanfareNum(0);
    GetMonNickname(mon, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(mon, MON_DATA_LEVEL), 0, 3);
    StringExpandPlaceholders(gStringVar4, gText_PkmnMournGrewLevel);
    AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
    gTasks[taskId].func = Task_LevelUp_WaitMessage;
    DEBUG_COLOR(RGB_MAGENTA);
}

static void Task_LevelUp_WaitMessage(u8 taskId)
{
    u16 levelUpWindowId;
    if (!IsTextPrinterActive(WIN_TEXT) && WaitFanfare(FALSE))
    {
        levelUpWindowId = AddWindow(&sLevelUpWindow);
        DrawStdFrameWithCustomTileAndPalette(levelUpWindowId, TRUE, 0x214, 14);
        DrawLevelUpWindowPg1(levelUpWindowId, sMourningScene->statsBeforeLevelUp, sMourningScene->statsAfterLevelUp, 1, 2, 3);
        CopyWindowToVram(levelUpWindowId, 3);
        sMourningScene->levelUpWindowId = levelUpWindowId;
        gTasks[taskId].func = Task_LevelUp_WaitLevelupWindowPart1;
    }
}

static void Task_LevelUp_WaitLevelupWindowPart1(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        DrawLevelUpWindowPg2(sMourningScene->levelUpWindowId, sMourningScene->statsAfterLevelUp, 1, 2, 3);
        CopyWindowToVram(sMourningScene->levelUpWindowId, 3);
        sMourningScene->learningFirstMove = 1;
        gTasks[taskId].func = Task_LevelUp_WaitLevelupWindowPart2;
    }
}

static void Task_LevelUp_WaitLevelupWindowPart2(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(sMourningScene->levelUpWindowId, TRUE);
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        RemoveWindow(sMourningScene->levelUpWindowId);
        gTasks[taskId].func = Task_TeachMove;
    }
}

static void Task_TeachMove(u8 taskId)
{
    u16 result = MonTryLearningNewMove(&gPlayerParty[tCurPartyIndex], sMourningScene->learningFirstMove);
    sMourningScene->learningFirstMove = 0;
    switch (result)
    {
    case 0:
        gTasks[taskId].func = Task_TryEvolve;
        break;
    case 0xFFFF:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        GetMonNickname(&gPlayerParty[tCurPartyIndex], gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
        StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = Task_WaitReplaceMoveMessage;
        break;
    case 0xFFFE:
        // Mon already knows the move.
        break;
    default:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        GetMonNickname(&gPlayerParty[tCurPartyIndex], gStringVar1);
        StringCopy(gStringVar2, gMoveNames[result]);
        StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMovePause);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        PlayFanfare(MUS_FANFA1);
        gTasks[taskId].func = Task_LevelUp_WaitFinalMoveMessage;
        break;
    }
}

static void Task_WaitReplaceMoveMessage(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        PlaySE(SE_SELECT);
        CreateYesNoMenu(&sYesNoWindow, 0x214, 14, 0);
        gTasks[taskId].func = Task_GetReplaceMoveInput;
    }
}

static void Task_GetReplaceMoveInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        AddTextPrinterParameterized(WIN_TEXT, 1, gText_WhichMoveToForget, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = Task_WaitWhichMoveToForgetMessage;
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
        StringExpandPlaceholders(gStringVar4, gText_StopLearningMove2);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = Task_WaitStopLearningMoveMessage;
        break;
    }
}

static void Task_WaitWhichMoveToForgetMessage(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_WaitLearnNewMoveFade;
    }
}

static void Task_WaitReturnFromSummaryScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u8 selectedMoveIndex = sub_81C1B94();
        if (selectedMoveIndex == MAX_MON_MOVES)
        {
            StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
            StringExpandPlaceholders(gStringVar4, gText_StopLearningMove2);
            AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
            gTasks[sMourningScene->expTaskId].func = Task_WaitStopLearningMoveMessage;
        }
        else
        {
            struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];
            u16 move = GetMonData(mon, MON_DATA_MOVE1 + selectedMoveIndex);
            RemoveMonPPBonus(mon, selectedMoveIndex);
            SetMonMoveSlot(mon, gMoveToLearn, selectedMoveIndex);
            GetMonNickname(mon, gStringVar1);
            StringCopy(gStringVar2, gMoveNames[move]);
            StringExpandPlaceholders(gStringVar4, gText_12PoofForgotMove);
            AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
            gTasks[sMourningScene->expTaskId].func = Task_WaitSwappedMoveMessage;
        }
    }
}

static void CB2_ReturnFromSummaryScreen(void)
{
    InitMourningSceneGraphics();
    if (gMain.state >= 5)
    {
        u16 species = GetBoxMonData(sMourningScene->boxMon, MON_DATA_SPECIES);
        u32 otId = GetBoxMonData(sMourningScene->boxMon, MON_DATA_OT_ID);
        u32 personality = GetBoxMonData(sMourningScene->boxMon, MON_DATA_PERSONALITY);
        
        DrawStdWindowFrame(WIN_TEXT, TRUE);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        LoadMournedMonGfx(species, personality, otId);

        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_MourningMain, 0);
        sMourningScene->expTaskId = CreateTask(Task_WaitReturnFromSummaryScreen, 3);
        SetVBlankCallback(VblankCallback_MourningScene);
        SetMainCallback2(CB2_MourningMain);
    }
}

static void Task_Wait(u8 taskId)
{
}

static void Task_WaitSwappedMoveMessage(u8 taskId)
{
    if (WaitFanfare(FALSE) && !IsTextPrinterActive(WIN_TEXT))
    {
        struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
        StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMovePause);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        PlayFanfare(MUS_FANFA1);
        gTasks[sMourningScene->expTaskId].func = Task_LevelUp_WaitFinalMoveMessage;
    }
}

static void Task_WaitLearnNewMoveFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ShowSelectMovePokemonSummaryScreen(gPlayerParty, tCurPartyIndex, gPlayerPartyCount - 1, CB2_ReturnFromSummaryScreen, gMoveToLearn);
        FreeCutsceneResources();
        gTasks[taskId].func = Task_Wait;
    }
}

static void Task_WaitStopLearningMoveMessage(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        PlaySE(SE_SELECT);
        CreateYesNoMenu(&sYesNoWindow, 0x214, 14, 0);
        gTasks[taskId].func = Task_GetStopLearningMoveInput;
    }
}

static void Task_GetStopLearningMoveInput(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
        StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = Task_LevelUp_WaitFinalMoveMessage;
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
        StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
        AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = Task_WaitReplaceMoveMessage;
        break;
    }
}

static void Task_LevelUp_WaitFinalMoveMessage(u8 taskId)
{
    if (WaitFanfare(FALSE) && !IsTextPrinterActive(WIN_TEXT))
    {
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(WIN_TEXT, PIXEL_FILL(1));
        CopyWindowToVram(WIN_TEXT, 3);
        gTasks[taskId].func = Task_TeachMove;
    }
}

static void Task_WaitReturnFromEvolutionScene(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_GiveExpToParty;
}

static void CB2_ReturnFromEvolutionScene(void)
{
    InitMourningSceneGraphics();
    if (gMain.state >= 5)
    {
        u16 species = GetBoxMonData(sMourningScene->boxMon, MON_DATA_SPECIES);
        u32 otId = GetBoxMonData(sMourningScene->boxMon, MON_DATA_OT_ID);
        u32 personality = GetBoxMonData(sMourningScene->boxMon, MON_DATA_PERSONALITY);
        PlayBGM(MUS_END);
        
        DrawStdWindowFrame(WIN_TEXT, TRUE);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        LoadMournedMonGfx(species, personality, otId);

        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_MourningMain, 0);
        sMourningScene->expTaskId = CreateTask(Task_WaitReturnFromEvolutionScene, 3);
        SetVBlankCallback(VblankCallback_MourningScene);
        SetMainCallback2(CB2_MourningMain);
    }
}

static void Task_TryEvolve(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[tCurPartyIndex];
    u16 targetSpecies = GetEvolutionTargetSpecies(mon, 0, 0);

    if (targetSpecies != SPECIES_NONE)
    {
        FreeCutsceneResources();
        gCB2_AfterEvolution = CB2_ReturnFromEvolutionScene;
        BeginEvolutionScene(mon, targetSpecies, 1, tCurPartyIndex);
        gTasks[taskId].func = Task_Wait;
    }
    else
    {
        gTasks[taskId].func = Task_GiveExpToParty;
    }
}

///////////////////////////////////////////////////////////////////////////////

bool8 DoMourningCutscene(void)
{
    if (GetMonToMourn())
    {
        FlagSet(FLAG_DID_MOURNING_CUTSCENE);
        FlagClear(FLAG_DISABLE_FADE_INIT);
        sMourningScene = AllocZeroed(sizeof(*sMourningScene));
        SetMainCallback2(CB2_MourningSetup);
        return TRUE;
    }
    else
    {
        FlagClear(FLAG_DID_MOURNING_CUTSCENE);
        return FALSE;
    }
}

