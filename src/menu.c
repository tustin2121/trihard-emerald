#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "dma3.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "region_map.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/songs.h"

#define DESC_WINDOW_PALETTE_NUM 15
#define DESC_WINDOW_BASE_TILE_NUM 0x200
#define STD_WINDOW_PALETTE_NUM 14
#define STD_WINDOW_BASE_TILE_NUM 0x214
#define SIGN_WINDOW_PALETTE_NUM 13
#define SIGN_WINDOW_BASE_TILE_NUM 0x205
#define DLG_WINDOW_PALETTE_NUM 13
#define DLG_WINDOW_BASE_TILE_NUM 0x20B

struct MoveMenuInfoIcon
{
    u8 width;
    u8 height;
    u16 offset;
};

struct Menu
{
    u8 left;
    u8 top;
    s8 cursorPos;
    s8 minCursorPos;
    s8 maxCursorPos;
    u8 windowId;
    u8 fontId;
    u8 optionWidth;
    u8 optionHeight;
    u8 columns;
    u8 rows;
    bool8 APressMuted;
};

static EWRAM_DATA u8 sStartMenuWindowId = 0;
static EWRAM_DATA u8 sMapNamePopupWindowId = 0;
static EWRAM_DATA struct Menu sMenu = {0};
static EWRAM_DATA u16 sTileNum = 0;
static EWRAM_DATA u8 sPaletteNum = 0;
static EWRAM_DATA u8 sYesNoWindowId = 0;
static EWRAM_DATA u8 sWindowId = 0;
static EWRAM_DATA u8 sPopupTaskId = 0;
static EWRAM_DATA bool8 gUnknown_0203CDA4[4] = {FALSE};
static EWRAM_DATA u16 gUnknown_0203CDA8 = 0;
static EWRAM_DATA void *gUnknown_0203CDAC[0x20] = {NULL};

const u16 gTextBoxPalette[] = INCBIN_U16("graphics/interface/860F074.gbapal");
static const u8 gUnknown_0860F094[] = { 8, 4, 1, 0 };

static const struct WindowTemplate sStandardTextBox_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sYesNo_WindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x125
};

const u16 gUnknown_0860F0B0[] = INCBIN_U16("graphics/interface/860F0B0.gbapal");
const u8 gUnknown_0860F0D0[] = { 15, 1, 2 };

// Table of move info icon offsets in graphics/interface_fr/menu.png
const struct MoveMenuInfoIcon gMoveMenuInfoIcons[] =
{   // { width, height, offset }
    { 12, 12, 0x00 },       // Unused
    { 32, 12, 0x20 },       // Normal icon
    { 32, 12, 0x64 },       // Fight icon
    { 32, 12, 0x60 },       // Flying icon
    { 32, 12, 0x80 },       // Poison icon
    { 32, 12, 0x48 },       // Ground icon
    { 32, 12, 0x44 },       // Rock icon
    { 32, 12, 0x6C },       // Bug icon
    { 32, 12, 0x68 },       // Ghost icon
    { 32, 12, 0x88 },       // Steel icon
    { 32, 12, 0xA4 },       // ??? (Mystery) icon
    { 32, 12, 0x24 },       // Fire icon
    { 32, 12, 0x28 },       // Water icon
    { 32, 12, 0x2C },       // Grass icon
    { 32, 12, 0x40 },       // Electric icon
    { 32, 12, 0x84 },       // Psychic icon
    { 32, 12, 0x4C },       // Ice icon
    { 32, 12, 0xA0 },       // Dragon icon
    { 32, 12, 0x8C },       // Dark icon
    { 42, 12, 0xA8 },       // -Type- icon
    { 42, 12, 0xC0 },       // -Power- icon
    { 42, 12, 0xC8 },       // -Accuracy- icon
    { 42, 12, 0xE0 },       // -PP- icon
    { 42, 12, 0xE8 },       // -Effect- icon
    {  8,  8, 0xAE },       // Unused (Small white pokeball)
    {  8,  8, 0xAF },       // Unused (Small dark pokeball)
};


// Forward declarations
void WindowFunc_DrawStandardFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
void WindowFunc_DrawDialogueFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
void WindowFunc_DrawSignFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
void WindowFunc_DrawSignFrame2(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
void WindowFunc_DrawDescribeFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
void WindowFunc_ClearStdWindowAndFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearDialogWindowAndFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_DrawTextFrameWithCustomTileAndPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearTextWindowAndFrameNullPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_DrawStdFrameWithCustomTileAndPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearStdWindowAndFrameToTransparent(u8, u8, u8, u8, u8, u8);
void sub_8198C78(void);
void task_free_buf_after_copying_tile_data_to_vram(u8 taskId);
static void Task_SignLinePopup(u8 taskId);

void InitStandardTextBoxWindows(void)
{
    InitWindows(sStandardTextBox_WindowTemplates);
    sStartMenuWindowId = 0xFF;
    sMapNamePopupWindowId = 0xFF;
}

void FreeAllOverworldWindowBuffers(void)
{
    FreeAllWindowBuffers();
}

void sub_8197200(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    DeactivateAllTextPrinters();
    LoadStdWindowFrame();
}

u16 RunTextPrintersAndIsPrinter0Active(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(0);
}

u16 AddTextPrinterParameterized2(u8 windowId, u8 fontId, const u8 *str, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 fgColor, u8 bgColor, u8 shadowColor)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = 0;
    printer.y = 1;
    printer.currentX = 0;
    printer.currentY = 1;
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.unk = 0;
    printer.fgColor = fgColor;
    printer.bgColor = bgColor;
    printer.shadowColor = shadowColor;

    gTextFlags.useAlternateDownArrow = 0;
    return AddTextPrinter(&printer, speed, callback);
}

void AddTextPrinterForMessage(bool8 allowSkippingDelayWithButtonPress)
{
    void (*callback)(struct TextPrinterTemplate *, u16) = NULL;
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), callback, 2, 1, 3);
}

void AddTextPrinterForMessage_2(bool8 allowSkippingDelayWithButtonPress)
{
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), NULL, 2, 1, 3);
}

void AddTextPrinterWithCustomSpeedForMessage(bool8 allowSkippingDelayWithButtonPress, u8 speed)
{
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, speed, NULL, 2, 1, 3);
}

void LoadStdWindowFrame(void)
{
    LoadMessageBoxGfx(0, DESC_WINDOW_BASE_TILE_NUM, DESC_WINDOW_PALETTE_NUM * 0x10);
    LoadMessageSignGfx(0, SIGN_WINDOW_BASE_TILE_NUM, SIGN_WINDOW_PALETTE_NUM * 0x10);
    LoadMessageDialogueGfx(0, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM * 0x10);
    LoadUserWindowBorderGfx(0, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM * 0x10);
}

void DrawDialogueFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawDialogueFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawDescribeFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawDescribeFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawStdWindowFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawStandardFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawSignWindowFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawSignFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawSignWindowFrame2(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawSignFrame2);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void ClearDialogWindowAndFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearDialogWindowAndFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void ClearStdWindowAndFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearStdWindowAndFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

// (u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
void WindowFunc_DrawSignFrame(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    // Top
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l-2  , t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l-1  , t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 2), l    , t-1, w, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l+w-1, t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l+w  , t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    // Middle
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 3), l-2  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 4), l-1  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 5), l    , t  , w, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 4), l+w-1, t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 3), l+w  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    // Bottom
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l-2  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l-1  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 2), l    , t+h, w, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l+w-1, t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l+w  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
}

// (u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
void WindowFunc_DrawSignFrame2(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    // Top
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l-2  , t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l-1  , t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 2), l    , t-1, w, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l+w, t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l+w+1, t-1, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    // Middle
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 3), l-2  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 4), l-1  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(SIGN_WINDOW_BASE_TILE_NUM + 5), l    , t  , w, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 4), l+w  , t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(SIGN_WINDOW_BASE_TILE_NUM + 3), l+w+1, t  , 1, h, SIGN_WINDOW_PALETTE_NUM);
    // Bottom
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l-2  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l-1  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 2), l    , t+h, w, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 1), l+w  , t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(SIGN_WINDOW_BASE_TILE_NUM + 0), l+w+1, t+h, 1, 1, SIGN_WINDOW_PALETTE_NUM);
}

// (u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
void WindowFunc_DrawDialogueFrame(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    s8 tailOff = gSpecialVar_DialogTailOffset - 32;
    // Top
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+0), l-2  , t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+1), l-1  , t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+2), l    , t-1,w-1,1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+1), l+w-1, t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+0), l+w-0, t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    // Top-Middle
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+3), l-2  , t+0, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+4), l-1  , t+0, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+7), l    , t+0,w-1,1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+4), l+w-1, t+0, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+3), l+w-0, t+0, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    // Middle
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+6), l-2  , t+1, 1, h-2, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+7), l-1  , t+1, 1, h-2, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+7), l    , t+1,w-1,h-2, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+7), l+w-1, t+1, 1, h-2, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+6), l+w-0, t+1, 1, h-2, DLG_WINDOW_PALETTE_NUM);
    // Bottom-Middle
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DLG_WINDOW_BASE_TILE_NUM+3), l-2  , t+h-1, 1, 1, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DLG_WINDOW_BASE_TILE_NUM+4), l-1  , t+h-1, 1, 1, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+7), l    , t+h-1,w-1,1, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DLG_WINDOW_BASE_TILE_NUM+4), l+w-1, t+h-1, 1, 1, DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DLG_WINDOW_BASE_TILE_NUM+3), l+w-0, t+h-1, 1, 1, DLG_WINDOW_PALETTE_NUM);
    // Bottom
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DLG_WINDOW_BASE_TILE_NUM+0), l-2  , t+h, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DLG_WINDOW_BASE_TILE_NUM+1), l-1  , t+h, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DLG_WINDOW_BASE_TILE_NUM+2), l    , t+h,w-1,1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DLG_WINDOW_BASE_TILE_NUM+1), l+w-1, t+h, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DLG_WINDOW_BASE_TILE_NUM+0), l+w-0, t+h, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    // 
    if (tailOff < 0) {
        FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DLG_WINDOW_BASE_TILE_NUM+5), l+(w-1)+tailOff  , t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    } else {
        FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DLG_WINDOW_BASE_TILE_NUM+5), l+(tailOff)  , t-1, 1, 1  , DLG_WINDOW_PALETTE_NUM);
    }
}

void WindowFunc_DrawStandardFrame(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    int i;

    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 0, l-1, t-1, 1, 1, STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 1, l  , t-1, w, 1, STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 2, l+w, t-1, 1, 1, STD_WINDOW_PALETTE_NUM);

    for (i = t; i < t+h; i++)
    {
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 3, l-1, i  , 1, 1, STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 5, l+w, i  , 1, 1, STD_WINDOW_PALETTE_NUM);
    }

    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 6, l-1, t+h, 1, 1, STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 7, l  , t+h, w, 1, STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, STD_WINDOW_BASE_TILE_NUM + 8, l+w, t+h, 1, 1, STD_WINDOW_PALETTE_NUM);
}

void WindowFunc_DrawDescribeFrame(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DESC_WINDOW_BASE_TILE_NUM + 0), l-2  , t-1, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DESC_WINDOW_BASE_TILE_NUM + 1), l-1  , t-1, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DESC_WINDOW_BASE_TILE_NUM + 2), l    , t-1,w-1,1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DESC_WINDOW_BASE_TILE_NUM + 1), l+w-1, t-1, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DESC_WINDOW_BASE_TILE_NUM + 0), l+w  , t-1, 1, 1, DESC_WINDOW_PALETTE_NUM);
    
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DESC_WINDOW_BASE_TILE_NUM + 3), l-2  , t  , 1, 5, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(DESC_WINDOW_BASE_TILE_NUM + 4), l-1  , t  ,w+1,5, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(DESC_WINDOW_BASE_TILE_NUM + 3), l+w  , t  , 1, 5, DESC_WINDOW_PALETTE_NUM);
    
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DESC_WINDOW_BASE_TILE_NUM + 0), l-2  , t+h, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DESC_WINDOW_BASE_TILE_NUM + 1), l-1  , t+h, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(DESC_WINDOW_BASE_TILE_NUM + 2), l    , t+h,w-1,1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DESC_WINDOW_BASE_TILE_NUM + 1), l+w-1, t+h, 1, 1, DESC_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(DESC_WINDOW_BASE_TILE_NUM + 0), l+w  , t+h, 1, 1, DESC_WINDOW_PALETTE_NUM);
}

void WindowFunc_ClearStdWindowAndFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, STD_WINDOW_PALETTE_NUM);
}

void WindowFunc_ClearDialogWindowAndFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, STD_WINDOW_PALETTE_NUM);
}

void SetStandardWindowBorderStyle(u8 windowId, bool8 copyToVram)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, copyToVram, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
}

void Menu_LoadAndDisplayTextBoxCustomPalette(u8 windowId, bool8 copyToVram)
{
    LoadMessageBoxGfx(windowId, DESC_WINDOW_BASE_TILE_NUM, DESC_WINDOW_PALETTE_NUM * 0x10);
    DrawTextFrameWithCustomTileAndPalette(windowId, copyToVram, DESC_WINDOW_BASE_TILE_NUM, 0xF);
}

void sub_819789C(void)
{
    LoadPalette(gTextBoxPalette, STD_WINDOW_PALETTE_NUM * 0x10, 0x14);
}

void Menu_LoadStdPalAt(u16 offset)
{
    LoadPalette(gTextBoxPalette, offset, 0x14);
}

const u16 *sub_81978C8(void)
{
    return gTextBoxPalette;
}

u16 sub_81978D0(u8 colorNum)
{
    if (colorNum > 15)
        colorNum = 0;
    return gTextBoxPalette[colorNum];
}

void DisplayItemMessageOnField(u8 taskId, const u8 *string, TaskFunc callback)
{
    LoadStdWindowFrame();
    DisplayMessageAndContinueTask(taskId, 0, DESC_WINDOW_BASE_TILE_NUM, DESC_WINDOW_PALETTE_NUM, 1, GetPlayerTextSpeedDelay(), string, callback);
    CopyWindowToVram(0, 3);
}

void DisplayYesNoMenuDefaultYes(void)
{
    CreateYesNoMenu(&sYesNo_WindowTemplates, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, 0);
}

void DisplayYesNoMenuWithDefault(u8 initialCursorPos)
{
    CreateYesNoMenu(&sYesNo_WindowTemplates, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, initialCursorPos);
}

u32 GetPlayerTextSpeed(void)
{
    if (gTextFlags.forceMidTextSpeed)
        return OPTIONS_TEXT_SPEED_MID;
    return gSaveBlock2Ptr->optionsTextSpeed;
}

u8 GetPlayerTextSpeedDelay(void)
{
    u32 speed;
    if (gSaveBlock2Ptr->optionsTextSpeed > OPTIONS_TEXT_SPEED_FAST)
        gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    speed = GetPlayerTextSpeed();
    return gUnknown_0860F094[speed];
}

u8 GetTextSpeedDelay(u8 speed)
{
    return gUnknown_0860F094[speed];
}

u8 sub_81979C4(u8 a1)
{
    if (sStartMenuWindowId == 0xFF)
        sStartMenuWindowId = sub_8198AA4(0, 0x16, 1, 7, (a1 * 2) + 2, 0xF, 0x139);
    return sStartMenuWindowId;
}

u8 GetStartMenuWindowId(void)
{
    return sStartMenuWindowId;
}

void RemoveStartMenuWindow(void)
{
    if (sStartMenuWindowId != 0xFF)
    {
        RemoveWindow(sStartMenuWindowId);
        sStartMenuWindowId = 0xFF;
    }
}

u16 sub_8197A30(void)
{
    return DLG_WINDOW_BASE_TILE_NUM;
}

u16 sub_8197A38(void)
{
    return STD_WINDOW_BASE_TILE_NUM;
}

u8 AddMapNamePopUpWindow(void)
{
    if (sMapNamePopupWindowId == 0xFF)
        sMapNamePopupWindowId = sub_8198AA4(0, 1, 1, 10, 3, 14, 0x107);
    return sMapNamePopupWindowId;
}

u8 GetMapNamePopUpWindowId(void)
{
    return sMapNamePopupWindowId;
}

void RemoveMapNamePopUpWindow(void)
{
    if (sMapNamePopupWindowId != 0xFF)
    {
        RemoveWindow(sMapNamePopupWindowId);
        sMapNamePopupWindowId = 0xFF;
    }
}

void AddTextPrinterWithCallbackForMessage(bool8 a1, void (*callback)(struct TextPrinterTemplate *, u16))
{
    gTextFlags.canABSpeedUpPrint = a1;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), callback, 2, 1, 3);
}

void sub_8197AE8(bool8 copyToVram)
{
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x11);
    if (copyToVram == TRUE)
        CopyBgTilemapBufferToVram(0);
}

void DrawTextFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 tileNum, u8 paletteNum)
{
    sTileNum = tileNum;
    sPaletteNum = paletteNum;
    CallWindowFunction(windowId, WindowFunc_DrawTextFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

// Never used.
void DrawTextFrameWithCustomTile(u8 windowId, bool8 copyToVram, u16 tileNum)
{
    sTileNum = tileNum;
    sPaletteNum = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, WindowFunc_DrawTextFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_DrawTextFrameWithCustomTileAndPalette(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(sTileNum + 0), l-2  , t-1, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(sTileNum + 1), l-1  , t-1, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(sTileNum + 2), l    , t-1,w-1,1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(sTileNum + 1), l+w-1, t-1, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(sTileNum + 0), l+w  , t-1, 1, 1, sPaletteNum);
    //
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(sTileNum + 3), l-2  , t  , 1, 5, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE____FLIP(sTileNum + 4), l-1  , t  ,w+1,5, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE_H__FLIP(sTileNum + 3), l+w  , t  , 1, 5, sPaletteNum);
    //
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(sTileNum + 0), l-2  , t+h, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(sTileNum + 1), l-1  , t+h, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE__V_FLIP(sTileNum + 2), l    , t+h,w-1,1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(sTileNum + 1), l+w-1, t+h, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, BG_TILE_HV_FLIP(sTileNum + 0), l+w  , t+h, 1, 1, sPaletteNum);
}

void ClearTextWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram)
{
    // The palette slot doesn't matter, since the tiles are transparent.
    CallWindowFunction(windowId, WindowFunc_ClearTextWindowAndFrameNullPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_ClearTextWindowAndFrameNullPalette(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, 0);
}

void DrawStdFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum)
{
    sTileNum = baseTileNum;
    sPaletteNum = paletteNum;
    CallWindowFunction(windowId, WindowFunc_DrawStdFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

// Never used.
void DrawStdFrameWithCustomTile(u8 windowId, bool8 copyToVram, u16 baseTileNum)
{
    sTileNum = baseTileNum;
    sPaletteNum = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, WindowFunc_DrawStdFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_DrawStdFrameWithCustomTileAndPalette(u8 bg, u8 l, u8 t, u8 w, u8 h, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, sTileNum + 0, l-1, t-1, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, sTileNum + 1, l  , t-1, w, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, sTileNum + 2, l+w, t-1, 1, 1, sPaletteNum);
    
    FillBgTilemapBufferRect(bg, sTileNum + 3, l-1, t  , 1, h, sPaletteNum);
    FillBgTilemapBufferRect(bg, sTileNum + 5, l+w, t  , 1, h, sPaletteNum);
    
    FillBgTilemapBufferRect(bg, sTileNum + 6, l-1, t+h, 1, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, sTileNum + 7, l  , t+h, w, 1, sPaletteNum);
    FillBgTilemapBufferRect(bg, sTileNum + 8, l+w, t+h, 1, 1, sPaletteNum);
}

void ClearStdWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearStdWindowAndFrameToTransparent);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_ClearStdWindowAndFrameToTransparent(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0);
}

u8 sub_81980F0(u8 bg, u8 xPos, u8 yPos, u8 palette, u16 baseTile)
{
    struct WindowTemplate window;
    memset(&window, 0, sizeof(window));

    if (bg > 3)
        window.bg = 0;
    else
        window.bg = bg;

    window.tilemapTop = yPos;
    window.height = 2;
    window.tilemapLeft = 0x1E - xPos;
    window.width = xPos;
    window.paletteNum = palette;
    window.baseBlock = baseTile;

    sWindowId = AddWindow(&window);

    if (palette > 15)
        palette = 15 * 16;
    else
        palette *= 16;

    LoadPalette(gUnknown_0860F0B0, palette, sizeof(gUnknown_0860F0B0));
    return sWindowId;
}

void sub_8198180(const u8 *string, u8 a2, bool8 copyToVram)
{
    u16 width = 0;

    if (sWindowId != 0xFF)
    {
        PutWindowTilemap(sWindowId);
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        width = GetStringWidth(0, string, 0);
        AddTextPrinterParameterized3(sWindowId,
                  0,
                  0xEC - (GetWindowAttribute(sWindowId, WINDOW_TILEMAP_LEFT) * 8) - a2 - width,
                  1,
                  gUnknown_0860F0D0,
                  0,
                  string);
        if (copyToVram)
            CopyWindowToVram(sWindowId, 3);
    }
}

void sub_8198204(const u8 *string, const u8 *string2, u8 a3, u8 a4, bool8 copyToVram)
{
    u8 color[3];
    u16 width = 0;

    if (sWindowId != 0xFF)
    {
        if (a3 != 0)
        {
            color[0] = 0;
            color[1] = 1;
            color[2] = 2;
        }
        else
        {
            color[0] = 15;
            color[1] = 1;
            color[2] = 2;
        }
        PutWindowTilemap(sWindowId);
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        if (string2 != NULL)
        {
            width = GetStringWidth(0, string2, 0);
            AddTextPrinterParameterized3(sWindowId,
                      0,
                      0xEC - (GetWindowAttribute(sWindowId, WINDOW_TILEMAP_LEFT) * 8) - a4 - width,
                      1,
                      color,
                      0,
                      string2);
        }
        AddTextPrinterParameterized4(sWindowId, 1, 4, 1, 0, 0, color, 0, string);
        if (copyToVram)
            CopyWindowToVram(sWindowId, 3);
    }
}

void sub_81982D8(void)
{
    if (sWindowId != 0xFF)
        CopyWindowToVram(sWindowId, 3);
}

void sub_81982F0(void)
{
    if (sWindowId != 0xFF)
    {
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        CopyWindowToVram(sWindowId, 3);
    }
}

void sub_8198314(void)
{
    if (sWindowId != 0xFF)
    {
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(sWindowId);
        CopyWindowToVram(sWindowId, 3);
        RemoveWindow(sWindowId);
        sWindowId = 0xFF;
    }
}

u8 sub_8198348(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos, u8 a7)
{
    s32 pos;

    sMenu.left = left;
    sMenu.top = top;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = numChoices - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = fontId;
    sMenu.optionHeight = cursorHeight;
    sMenu.APressMuted = a7;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    Menu_MoveCursor(0);
    return sMenu.cursorPos;
}

u8 sub_81983AC(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos)
{
    return sub_8198348(windowId, fontId, left, top, cursorHeight, numChoices, initialCursorPos, 0);
}

u8 sub_81983EC(u8 windowId, u8 fontId, u8 left, u8 top, u8 numChoices, u8 initialCursorPos)
{
    u8 cursorHeight = GetMenuCursorDimensionByFont(fontId, 1);
    return sub_81983AC(windowId, fontId, left, top, cursorHeight, numChoices, initialCursorPos);
}

void RedrawMenuCursor(u8 oldPos, u8 newPos)
{
    u8 width, height;

    width = GetMenuCursorDimensionByFont(sMenu.fontId, 0);
    height = GetMenuCursorDimensionByFont(sMenu.fontId, 1);
    FillWindowPixelRect(sMenu.windowId, PIXEL_FILL(1), sMenu.left, sMenu.optionHeight * oldPos + sMenu.top, width, height);
    AddTextPrinterParameterized(sMenu.windowId, sMenu.fontId, gText_SelectorArrow3, sMenu.left, sMenu.optionHeight * newPos + sMenu.top, 0, 0);
}

u8 Menu_MoveCursor(s8 cursorDelta)
{
    u8 oldPos = sMenu.cursorPos;
    int newPos = sMenu.cursorPos + cursorDelta;

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, sMenu.cursorPos);
    return sMenu.cursorPos;
}

u8 Menu_MoveCursorNoWrapAround(s8 cursorDelta)
{
    u8 oldPos = sMenu.cursorPos;
    int newPos = sMenu.cursorPos + cursorDelta;

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, sMenu.cursorPos);
    return sMenu.cursorPos;
}

u8 Menu_GetCursorPos(void)
{
    return sMenu.cursorPos;
}

s8 Menu_ProcessInput(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(-1);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(1);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputNoWrap(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 ProcessMenuInput_other(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(-1);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(1);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputNoWrapAround_other(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

void PrintTextArray(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized(windowId, fontId, strs[i].text, left, (lineHeight * i) + top, 0xFF, NULL);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_81987BC(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, u8 a6, u8 a7)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized5(windowId, fontId, strs[i].text, left, (lineHeight * i) + top, 0xFF, NULL, a6, a7);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198854(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *strs)
{
    PrintTextArray(windowId, fontId, GetFontAttribute(fontId, 0), 1, lineHeight, itemCount, strs);
}

void AddItemMenuActionTextPrinters(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    printer.x = left;
    printer.currentX = left;

    for (i = 0; i < itemCount; i++)
    {
        printer.currentChar = strs[a8[i]].text;
        printer.y = (lineHeight * i) + top;
        printer.currentY = printer.y;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81989B8(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, const u8 *a5)
{
    AddItemMenuActionTextPrinters(windowId, fontId, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH), 1, GetFontAttribute(fontId, FONTATTR_LETTER_SPACING), lineHeight, itemCount, strs, a5);
}

void SetWindowTemplateFields(struct WindowTemplate *template, u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    template->bg = bg;
    template->tilemapLeft = left;
    template->tilemapTop = top;
    template->width = width;
    template->height = height;
    template->paletteNum = paletteNum;
    template->baseBlock = baseBlock;
}

struct WindowTemplate CreateWindowTemplate(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, bg, left, top, width, height, paletteNum, baseBlock);
    return template;
}

u16 sub_8198AA4(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, bg, left, top, width, height, paletteNum, baseBlock);
    return AddWindow(&template);
}

void sub_8198AF8(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate printer;

    sYesNoWindowId = AddWindow(window);
    DrawStdFrameWithCustomTileAndPalette(sYesNoWindowId, TRUE, baseTileNum, paletteNum);

    printer.currentChar = gText_YesNo;
    printer.windowId = sYesNoWindowId;
    printer.fontId = fontId;
    printer.x = GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH) + left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);

    AddTextPrinter(&printer, 0xFF, NULL);

    sub_81983AC(sYesNoWindowId, fontId, left, top, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_HEIGHT), 2, initialCursorPos);
}

void sub_8198C34(const struct WindowTemplate *window, u8 fontId, u16 baseTileNum, u8 paletteNum)
{
    sub_8198AF8(window, fontId, 0, 1, baseTileNum, paletteNum, 0);
}

s8 Menu_ProcessInputNoWrapClearOnChoose(void)
{
    s8 result = Menu_ProcessInputNoWrap();
    if (result != MENU_NOTHING_CHOSEN)
        sub_8198C78();
    return result;
}

void sub_8198C78(void)
{
    ClearStdWindowAndFrameToTransparent(sYesNoWindowId, TRUE);
    RemoveWindow(sYesNoWindowId);
}

void sub_8198C94(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7, const struct MenuAction *strs)
{
    u8 i;
    u8 j;
    for (i = 0; i < a7; i++)
    {
        for (j = 0; j < a6; j++)
        {
            AddTextPrinterParameterized(windowId, fontId, strs[(i * a6) + j].text, (a4 * j) + left, (a5 * i) + top, 0xFF, NULL);
        }
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198D54(u8 windowId, u8 fontId, u8 a2, u8 a3, u8 a4, u8 a5, const struct MenuAction *strs)
{
    sub_8198C94(windowId, fontId, GetFontAttribute(fontId, 0), 0, a2, a3, a4, a5, strs);
}

void sub_8198DBC(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 itemCount, u8 itemCount2, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    u8 j;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);

    for (i = 0; i < itemCount2; i++)
    {
        for (j = 0; j < itemCount; j++)
        {
            printer.currentChar = strs[a8[(itemCount * i) + j]].text;
            printer.x = (a4 * j) + left;
            printer.y = (GetFontAttribute(fontId, 1) * i) + top;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

void sub_8198EF8(u8 windowId, u8 fontId, u8 a2, u8 a3, u8 a4, u8 a5, const struct MenuAction *strs, const u8 *a8)
{
    sub_8198DBC(windowId, fontId, GetFontAttribute(fontId, 0), 0, a2, a4, a5, strs, a8);
}

u8 sub_8198F58(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 cursorHeight, u8 a6, u8 a7, u8 numChoices, u8 a9)
{
    s32 pos;

    sMenu.left = left;
    sMenu.top = top;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = numChoices - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = fontId;
    sMenu.optionWidth = a4;
    sMenu.optionHeight = cursorHeight;
    sMenu.columns = a6;
    sMenu.rows = a7;

    pos = a9;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    sub_8199134(0, 0);
    return sMenu.cursorPos;
}

u8 sub_8198FD4(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7)
{
    u8 cursorHeight = GetMenuCursorDimensionByFont(fontId, 1);
    u8 numChoices = a5 * a6;
    return sub_8198F58(windowId, fontId, left, top, a4, cursorHeight, a5, a6, numChoices, a7);
}

void sub_8199060(u8 oldCursorPos, u8 newCursorPos)
{
    u8 cursorWidth = GetMenuCursorDimensionByFont(sMenu.fontId, 0);
    u8 cursorHeight = GetMenuCursorDimensionByFont(sMenu.fontId, 1);
    u8 xPos = (oldCursorPos % sMenu.columns) * sMenu.optionWidth + sMenu.left;
    u8 yPos = (oldCursorPos / sMenu.columns) * sMenu.optionHeight + sMenu.top;
    FillWindowPixelRect(sMenu.windowId,
                        PIXEL_FILL(1),
                        xPos,
                        yPos,
                        cursorWidth,
                        cursorHeight);
    xPos = (newCursorPos % sMenu.columns) * sMenu.optionWidth + sMenu.left;
    yPos = (newCursorPos / sMenu.columns) * sMenu.optionHeight + sMenu.top;
    AddTextPrinterParameterized(sMenu.windowId,
                      sMenu.fontId,
                      gText_SelectorArrow3,
                      xPos,
                      yPos,
                      0,
                      0);
}

u8 sub_8199134(s8 deltaX, s8 deltaY)
{
    u8 oldPos = sMenu.cursorPos;

    if (deltaX != 0)
    {
        if ((sMenu.cursorPos % sMenu.columns) + deltaX < 0)
        {
            sMenu.cursorPos += sMenu.columns - 1;
        }
        else if ((sMenu.cursorPos % sMenu.columns) + deltaX >= sMenu.columns)
        {
            sMenu.cursorPos = (sMenu.cursorPos / sMenu.columns) * sMenu.columns;
        }
        else
        {
            sMenu.cursorPos += deltaX;
        }
    }

    if (deltaY != 0)
    {
        if ((sMenu.cursorPos / sMenu.columns) + deltaY < 0)
        {
            sMenu.cursorPos += sMenu.columns * (sMenu.rows - 1);
        }
        else if ((sMenu.cursorPos / sMenu.columns) + deltaY >= sMenu.rows)
        {
            sMenu.cursorPos -= sMenu.columns * (sMenu.rows - 1);
        }
        else
        {
            sMenu.cursorPos += (sMenu.columns * deltaY);
        }
    }

    if (sMenu.cursorPos > sMenu.maxCursorPos)
    {
        sMenu.cursorPos = oldPos;
        return sMenu.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, sMenu.cursorPos);
        return sMenu.cursorPos;
    }
}

u8 sub_81991F8(s8 deltaX, s8 deltaY)
{
    u8 oldPos = sMenu.cursorPos;

    if (deltaX != 0)
    {
        if (((sMenu.cursorPos % sMenu.columns) + deltaX >= 0) &&
        ((sMenu.cursorPos % sMenu.columns) + deltaX < sMenu.columns))
        {
            sMenu.cursorPos += deltaX;
        }
    }

    if (deltaY != 0)
    {
        if (((sMenu.cursorPos / sMenu.columns) + deltaY >= 0) &&
        ((sMenu.cursorPos / sMenu.columns) + deltaY < sMenu.rows))
        {
            sMenu.cursorPos += (sMenu.columns * deltaY);
        }
    }

    if (sMenu.cursorPos > sMenu.maxCursorPos)
    {
        sMenu.cursorPos = oldPos;
        return sMenu.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, sMenu.cursorPos);
        return sMenu.cursorPos;
    }
}

s8 sub_8199284(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, -1);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, 1);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
    {
        PlaySE(SE_SELECT);
        sub_8199134(-1, 0);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
    {
        PlaySE(SE_SELECT);
        sub_8199134(1, 0);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputGridLayout(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (oldPos != sub_81991F8(0, -1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (oldPos != sub_81991F8(0, 1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
    {
        if (oldPos != sub_81991F8(-1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
    {
        if (oldPos != sub_81991F8(1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 sub_81993D8(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, -1);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, 1);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_LEFT || sub_812210C() == 1)
    {
        PlaySE(SE_SELECT);
        sub_8199134(-1, 0);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_RIGHT || sub_812210C() == 2)
    {
        PlaySE(SE_SELECT);
        sub_8199134(1, 0);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 sub_8199484(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return MENU_B_PRESSED;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        if (oldPos != sub_81991F8(0, -1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        if (oldPos != sub_81991F8(0, 1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_LEFT || sub_812210C() == 1)
    {
        if (oldPos != sub_81991F8(-1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_RIGHT || sub_812210C() == 2)
    {
        if (oldPos != sub_81991F8(1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

u8 InitMenuInUpperLeftCorner(u8 windowId, u8 itemCount, u8 initialCursorPos, bool8 APressMuted)
{
    s32 pos;

    sMenu.left = 0;
    sMenu.top = 1;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = itemCount - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = 1;
    sMenu.optionHeight = 16;
    sMenu.APressMuted = APressMuted;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    return Menu_MoveCursor(0);
}

u8 InitMenuInUpperLeftCornerPlaySoundWhenAPressed(u8 windowId, u8 itemCount, u8 initialCursorPos)
{
    return InitMenuInUpperLeftCorner(windowId, itemCount, initialCursorPos, FALSE);
}

void PrintMenuTable(u8 windowId, u8 itemCount, const struct MenuAction *strs)
{
    u32 i;

    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized(windowId, 1, strs[i].text, 8, (i * 16) + 1, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81995E4(u8 windowId, u8 itemCount, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.x = 8;
    printer.currentX = 8;

    for (i = 0; i < itemCount; i++)
    {
        printer.currentChar = strs[a8[i]].text;
        printer.y = (i * 16) + 1;
        printer.currentY = (i * 16) + 1;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void CreateYesNoMenu(const struct WindowTemplate *_window, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate printer;
    struct WindowTemplate template = *_window;
    u8 strWidth;
    
    CompileYesNoString();
    strWidth = GetStringWidth(1, gYesNoStringVar, 1); //extra block for cursor
    strWidth = ((strWidth % 8 != 0)? 2 : 1) + (strWidth >> 3);
    template.width = max(strWidth, _window->width);
    // Hack for now to actually get left / top into the yes no menu creation
    if (gSpecialVar_YesNoBoxOffset != 0) {
        template.tilemapLeft = (gSpecialVar_YesNoBoxOffset >> 8) + 1;
        template.tilemapTop = (gSpecialVar_YesNoBoxOffset & 0xFF) + 1;
        gSpecialVar_YesNoBoxOffset = 0;
    }

    sYesNoWindowId = AddWindow(&template);
    DrawStdFrameWithCustomTileAndPalette(sYesNoWindowId, TRUE, baseTileNum, paletteNum);
    
    printer.currentChar = gYesNoStringVar; //gText_YesNo;
    printer.windowId = sYesNoWindowId;
    printer.fontId = 1;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    AddTextPrinter(&printer, 0xFF, NULL);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sYesNoWindowId, 2, initialCursorPos);
}

void PrintMenuGridTable(u8 windowId, u8 optionWidth, u8 columns, u8 rows, const struct MenuAction *strs)
    {
    u32 i, j;

    for (i = 0; i < rows; i++)
        {
        for (j = 0; j < columns; j++)
            AddTextPrinterParameterized(windowId, 1, strs[(i * columns) + j].text, (optionWidth * j) + 8, (i * 16) + 1, 0xFF, NULL);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_819983C(u8 windowId, u8 a4, u8 itemCount, u8 itemCount2, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    u8 j;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    for (i = 0; i < itemCount2; i++)
    {
        for (j = 0; j < itemCount; j++)
        {
            printer.currentChar = strs[a8[(itemCount * i) + j]].text;
            printer.x = (a4 * j) + 8;
            printer.y = (16 * i) + 1;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

u8 sub_8199944(u8 windowId, u8 optionWidth, u8 columns, u8 rows, u8 initialCursorPos)
{
    s32 pos;

    sMenu.left = 0;
    sMenu.top = 1;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = (columns * rows) - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = 1;
    sMenu.optionWidth = optionWidth;
    sMenu.optionHeight = 16;
    sMenu.columns = columns;
    sMenu.rows = rows;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    sub_8199134(0, 0);
    return sMenu.cursorPos;
}

void clear_scheduled_bg_copies_to_vram(void)
{
    memset(gUnknown_0203CDA4, 0, sizeof(gUnknown_0203CDA4));
}

void schedule_bg_copy_tilemap_to_vram(u8 bgId)
{
    gUnknown_0203CDA4[bgId] = TRUE;
}

void do_scheduled_bg_tilemap_copies_to_vram(void)
{
    if (gUnknown_0203CDA4[0] == TRUE)
    {
        CopyBgTilemapBufferToVram(0);
        gUnknown_0203CDA4[0] = FALSE;
    }
    if (gUnknown_0203CDA4[1] == TRUE)
    {
        CopyBgTilemapBufferToVram(1);
        gUnknown_0203CDA4[1] = FALSE;
    }
    if (gUnknown_0203CDA4[2] == TRUE)
    {
        CopyBgTilemapBufferToVram(2);
        gUnknown_0203CDA4[2] = FALSE;
    }
    if (gUnknown_0203CDA4[3] == TRUE)
    {
        CopyBgTilemapBufferToVram(3);
        gUnknown_0203CDA4[3] = FALSE;
    }
}

void reset_temp_tile_data_buffers(void)
{
    int i;
    for (i = 0; i < (s32)ARRAY_COUNT(gUnknown_0203CDAC); i++)
    {
        gUnknown_0203CDAC[i] = NULL;
    }
    gUnknown_0203CDA8 = 0;
}

bool8 free_temp_tile_data_buffers_if_possible(void)
{
    int i;

    if (!IsDma3ManagerBusyWithBgCopy())
    {
        if (gUnknown_0203CDA8)
        {
            for (i = 0; i < gUnknown_0203CDA8; i++)
            {
                FREE_AND_SET_NULL(gUnknown_0203CDAC[i]);
            }
            gUnknown_0203CDA8 = 0;
        }
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void *decompress_and_copy_tile_data_to_vram(u8 bgId, const void *src, u32 size, u16 offset, u8 mode)
{
    u32 sizeOut;
    if (gUnknown_0203CDA8 < ARRAY_COUNT(gUnknown_0203CDAC))
    {
        void *ptr = malloc_and_decompress(src, &sizeOut);
        if (!size)
            size = sizeOut;
        if (ptr)
        {
            copy_decompressed_tile_data_to_vram(bgId, ptr, size, offset, mode);
            gUnknown_0203CDAC[gUnknown_0203CDA8++] = ptr;
        }
        return ptr;
    }
    return NULL;
}

void DecompressAndLoadBgGfxUsingHeap(u8 bgId, const void *src, u32 size, u16 offset, u8 mode)
{
    u32 sizeOut;
    void *ptr = malloc_and_decompress(src, &sizeOut);
    if (!size)
        size = sizeOut;
    if (ptr)
    {
        u8 taskId = CreateTask(task_free_buf_after_copying_tile_data_to_vram, 0);
        gTasks[taskId].data[0] = copy_decompressed_tile_data_to_vram(bgId, ptr, size, offset, mode);
        SetWordTaskArg(taskId, 1, (u32)ptr);
    }
}

void task_free_buf_after_copying_tile_data_to_vram(u8 taskId)
{
    if (!CheckForSpaceForDma3Request(gTasks[taskId].data[0]))
    {
        Free((void *)GetWordTaskArg(taskId, 1));
        DestroyTask(taskId);
    }
}

void *malloc_and_decompress(const void *src, u32 *size)
{
    void *ptr;
    u8 *sizeAsBytes = (u8 *)size;
    u8 *srcAsBytes = (u8 *)src;

    sizeAsBytes[0] = srcAsBytes[1];
    sizeAsBytes[1] = srcAsBytes[2];
    sizeAsBytes[2] = srcAsBytes[3];
    sizeAsBytes[3] = 0;

    ptr = Alloc(*size);
    if (ptr)
        LZ77UnCompWram(src, ptr);
    return ptr;
}

u16 copy_decompressed_tile_data_to_vram(u8 bgId, const void *src, u16 size, u16 offset, u8 mode)
{
    switch (mode)
    {
        case 0:
            return LoadBgTiles(bgId, src, size, offset);
        case 1:
            return LoadBgTilemap(bgId, src, size, offset);
        default:
            return -1;
    }
}

void sub_8199C30(u8 bgId, u8 left, u8 top, u8 width, u8 height, u8 palette)
{
    u8 i;
    u8 j;
    u16 *ptr = GetBgTilemapBuffer(bgId);

    for (i = top; i < top + height; i++)
    {
        for (j = left; j < left + width; j++)
        {
            ptr[(i * 32) + j] = (ptr[(i * 32) + j] & 0xFFF) | (palette << 12);
        }
    }
}

void sub_8199CBC(u8 bgId, u16 *dest, u8 left, u8 top, u8 width, u8 height)
{
    u8 i;
    u8 j;
    const u16 *src = GetBgTilemapBuffer(bgId);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            dest[(i * width) + j] = src[(i + top) * 32 + j + left];
        }
    }
}

void sub_8199D3C(void *ptr, int delta, int width, int height, bool32 is8BPP)
{
    int i;
    int area = width * height;
    if (is8BPP == TRUE)
    {
        u8 *as8BPP = ptr;
        for (i = 0; i < area; i++)
        {
            as8BPP[i] += delta;
        }
    }
    else
    {
        u16 *as4BPP = ptr;
        for (i = 0; i < area; i++)
        {
            as4BPP[i] = (as4BPP[i] & 0xFC00) | ((as4BPP[i] + delta) & 0x3FF);
        }
    }
}

void ResetBgPositions(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgY(3, 0, 0);
}

void sub_8199DF0(u32 bg, u8 a1, int a2, int a3)
{
    int temp = (!GetBgAttribute(bg, BG_ATTR_PALETTEMODE)) ? 0x20 : 0x40;
    void *addr = (void *)((GetBgAttribute(bg, BG_ATTR_CHARBASEINDEX) * 0x4000) + (GetBgAttribute(bg, BG_ATTR_BASETILE) + a2) * temp);
    RequestDma3Fill(a1 << 24 | a1 << 16 | a1 << 8 | a1, addr + VRAM, a3 * temp, 1);
}

void AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 left, u8 top, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];

    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];

    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized5(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 letterSpacing, u8 lineSpacing)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = left;
    printer.currentY = top;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;

    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);

    AddTextPrinter(&printer, speed, callback);
}

void PrintPlayerNameOnWindow(u8 windowId, const u8 *src, u16 x, u16 y)
{
    int count = 0;
    while (gSaveBlock2Ptr->playerName[count] != EOS)
        count++;

    StringExpandPlaceholders(gStringVar4, src);

    AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, 0xFF, 0);
}

//Screw this function, it's long and unreferenced and ugh

struct UnkStruct_819A080 {
    u8 *unk00;
    u16 unk04;
    u16 unk06;
};

#ifdef NONMATCHING
void sub_819A080(struct UnkStruct_819A080 *a0, struct UnkStruct_819A080 *a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7)
{
    // r3 = a3
    // r4 = a5
    // r1 = a6
    // r5 = a7
    // sp+00 = a0
    // sp+04 = a1
    // sp+08 = a2
    // sp+0c = a4
    int sp10 = a1->unk04 - a4 < a6 ? a1->unk04 - a4 + a2 : a6 + a2;
    int sp14 = a0->unk06 - a5 < a7 ? a3 + a0->unk06 - a5 : a3 + a7;
    int sp18 = (a0->unk04 + (a0->unk04 & 0x7)) / 8;
    int sp1c = (a1->unk04 + (a1->unk04 & 0x7)) / 8;
    int r12; // sp+20
    int r8;  // sp+24
    int r5;
    int r6;
    u16 r2;

    for (r12 = a3, r8 = a5; r12 < sp14; r12++, r8++)
    {
        for (r5 = a2, r6 = a4; a5 < sp10; a5++, a6++)
        {
            u8 *r3 = a0->unk00 + ((r5 >> 1) & 0x3) + ((r5 >> 3) << 5) + (((r12 >> 3) * sp18) << 5) + ((r12 & 0x7) << 2);
            u8 *r4 = a1->unk00 + ((r6 >> 1) & 0x3) + ((r6 >> 3) << 5) + (((r8 >> 3) * sp1c) << 5) + ((r8 & 0x7) << 2);
            if (((uintptr_t)r4) & 0x1)
            {
                u16 *r4_2 = (u16 *)(r4 - 1);
                if (r6 & 0x1)
                {
                    r2 = *r4_2 & 0x0fff;
                    if (r5 & 0x1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 8);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 12);
                }
                else
                {
                    r2 = *r4_2 * 0xf0ff;
                    if (r5 & 0x1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 4);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 8);
                }
            }
            else
            {
                u16 *r4_2 = (u16 *)r4;
                if (r6 & 1)
                {
                    r2 = *r4_2 & 0xff0f;
                    if (r5 & 1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 0);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 4);
                }
                else
                {
                    r2 = *r4_2 & 0xfff0;
                    if (r5 & 1)
                        *r4_2 = r2 | ((*r3 & 0xf0) >> 4);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) >> 0);
                }
            }
        }
    }
}
#else
NAKED
void sub_819A080(struct UnkStruct_819A080 *a0, struct UnkStruct_819A080 *a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, #0x28\n\
    str r0, [sp]\n\
    str r1, [sp, #0x4]\n\
    ldr r0, [sp, #0x48]\n\
    ldr r4, [sp, #0x4C]\n\
    ldr r1, [sp, #0x50]\n\
    ldr r5, [sp, #0x54]\n\
    lsl r2, #16\n\
    lsr r2, #16\n\
    str r2, [sp, #0x8]\n\
    lsl r3, #16\n\
    lsr r3, #16\n\
    lsl r0, #16\n\
    lsr r0, #16\n\
    str r0, [sp, #0xC]\n\
    lsl r4, #16\n\
    lsr r4, #16\n\
    lsl r1, #16\n\
    lsr r1, #16\n\
    lsl r5, #16\n\
    lsr r5, #16\n\
    ldr r2, [sp, #0x4]\n\
    ldrh r0, [r2, #0x4]\n\
    ldr r2, [sp, #0xC]\n\
    sub r0, r2\n\
    ldr r2, [sp, #0x8]\n\
    add r2, r1, r2\n\
    str r2, [sp, #0x10]\n\
    cmp r0, r1\n\
    bge _0819A0CC\n\
    ldr r1, [sp, #0x8]\n\
    add r0, r1\n\
    str r0, [sp, #0x10]\n\
_0819A0CC:\n\
    ldr r2, [sp, #0x4]\n\
    ldrh r1, [r2, #0x6]\n\
    sub r0, r1, r4\n\
    cmp r0, r5\n\
    bge _0819A0DE\n\
    add r0, r3, r1\n\
    sub r0, r4\n\
    str r0, [sp, #0x14]\n\
    b _0819A0E2\n\
_0819A0DE:\n\
    add r5, r3, r5\n\
    str r5, [sp, #0x14]\n\
_0819A0E2:\n\
    ldr r0, [sp]\n\
    ldrh r1, [r0, #0x4]\n\
    mov r2, #0x7\n\
    add r0, r1, #0\n\
    and r0, r2\n\
    add r1, r0\n\
    asr r1, #3\n\
    str r1, [sp, #0x18]\n\
    ldr r0, [sp, #0x4]\n\
    ldrh r1, [r0, #0x4]\n\
    add r0, r1, #0\n\
    and r0, r2\n\
    add r1, r0\n\
    asr r1, #3\n\
    str r1, [sp, #0x1C]\n\
    mov r12, r3\n\
    mov r8, r4\n\
    ldr r1, [sp, #0x14]\n\
    cmp r12, r1\n\
    blt _0819A10C\n\
    b _0819A24A\n\
_0819A10C:\n\
    ldr r5, [sp, #0x8]\n\
    ldr r6, [sp, #0xC]\n\
    mov r2, r12\n\
    add r2, #0x1\n\
    str r2, [sp, #0x20]\n\
    mov r0, r8\n\
    add r0, #0x1\n\
    str r0, [sp, #0x24]\n\
    ldr r1, [sp, #0x10]\n\
    cmp r5, r1\n\
    blt _0819A124\n\
    b _0819A23A\n\
_0819A124:\n\
    mov r7, #0x1\n\
    mov r2, #0xF0\n\
    mov r10, r2\n\
    mov r0, #0xF\n\
    mov r9, r0\n\
_0819A12E:\n\
    asr r0, r5, #1\n\
    mov r1, #0x3\n\
    and r0, r1\n\
    ldr r2, [sp]\n\
    ldr r1, [r2]\n\
    add r1, r0\n\
    asr r0, r5, #3\n\
    lsl r0, #5\n\
    add r1, r0\n\
    mov r2, r12\n\
    asr r0, r2, #3\n\
    ldr r2, [sp, #0x18]\n\
    mul r0, r2\n\
    lsl r0, #5\n\
    add r1, r0\n\
    mov r2, r12\n\
    lsl r0, r2, #29\n\
    lsr r0, #27\n\
    add r3, r1, r0\n\
    asr r0, r6, #1\n\
    mov r1, #0x3\n\
    and r0, r1\n\
    ldr r2, [sp, #0x4]\n\
    ldr r1, [r2]\n\
    add r1, r0\n\
    asr r0, r6, #3\n\
    lsl r0, #5\n\
    add r1, r0\n\
    mov r2, r8\n\
    asr r0, r2, #3\n\
    ldr r2, [sp, #0x1C]\n\
    mul r0, r2\n\
    lsl r0, #5\n\
    add r1, r0\n\
    mov r2, r8\n\
    lsl r0, r2, #29\n\
    lsr r0, #27\n\
    add r4, r1, r0\n\
    add r0, r4, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A1DA\n\
    sub r4, #0x1\n\
    add r0, r6, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A1B2\n\
    ldrh r0, [r4]\n\
    ldr r2, =0x00000fff\n\
    and r2, r0\n\
    add r0, r5, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A1A8\n\
    ldrb r1, [r3]\n\
    mov r0, r10\n\
    and r0, r1\n\
    lsl r0, #8\n\
    b _0819A22A\n\
    .pool\n\
_0819A1A8:\n\
    ldrb r1, [r3]\n\
    mov r0, r9\n\
    and r0, r1\n\
    lsl r0, #12\n\
    b _0819A22A\n\
_0819A1B2:\n\
    ldrh r0, [r4]\n\
    ldr r2, =0x0000f0ff\n\
    and r2, r0\n\
    add r0, r5, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A1D0\n\
    ldrb r1, [r3]\n\
    mov r0, r10\n\
    and r0, r1\n\
    lsl r0, #4\n\
    b _0819A22A\n\
    .pool\n\
_0819A1D0:\n\
    ldrb r1, [r3]\n\
    mov r0, r9\n\
    and r0, r1\n\
    lsl r0, #8\n\
    b _0819A22A\n\
_0819A1DA:\n\
    add r0, r6, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A206\n\
    ldrh r0, [r4]\n\
    ldr r2, =0x0000ff0f\n\
    and r2, r0\n\
    add r0, r5, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A1FC\n\
    ldrb r1, [r3]\n\
    mov r0, r10\n\
    b _0819A228\n\
    .pool\n\
_0819A1FC:\n\
    ldrb r1, [r3]\n\
    mov r0, r9\n\
    and r0, r1\n\
    lsl r0, #4\n\
    b _0819A22A\n\
_0819A206:\n\
    ldrh r0, [r4]\n\
    ldr r2, =0x0000fff0\n\
    and r2, r0\n\
    add r0, r5, #0\n\
    and r0, r7\n\
    cmp r0, #0\n\
    beq _0819A224\n\
    ldrb r1, [r3]\n\
    mov r0, r10\n\
    and r0, r1\n\
    lsr r0, #4\n\
    b _0819A22A\n\
    .pool\n\
_0819A224:\n\
    ldrb r1, [r3]\n\
    mov r0, r9\n\
_0819A228:\n\
    and r0, r1\n\
_0819A22A:\n\
    orr r2, r0\n\
    strh r2, [r4]\n\
    add r5, #0x1\n\
    add r6, #0x1\n\
    ldr r0, [sp, #0x10]\n\
    cmp r5, r0\n\
    bge _0819A23A\n\
    b _0819A12E\n\
_0819A23A:\n\
    ldr r1, [sp, #0x20]\n\
    mov r12, r1\n\
    ldr r2, [sp, #0x24]\n\
    mov r8, r2\n\
    ldr r0, [sp, #0x14]\n\
    cmp r12, r0\n\
    bge _0819A24A\n\
    b _0819A10C\n\
_0819A24A:\n\
    add sp, #0x28\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n");
}
#endif

void sub_819A25C(u8 palOffset, u16 speciesId)
{
    LoadPalette(GetValidMonIconPalettePtr(speciesId), palOffset, 0x20);
}

void sub_819A27C(u8 windowId, u16 speciesId, u32 personality, u16 x, u16 y)
{
    BlitBitmapToWindow(windowId, GetMonIconPtr(speciesId, personality, 1), x, y, 32, 32);
}

void sub_819A2BC(u8 palOffset, u8 palId)
{
    const u16 *palette;

    switch (palId)
    {
        case 0:
        default:
            palette = gFireRedMenuElements1_Pal;
            break;
        case 1:
            palette = gFireRedMenuElements2_Pal;
            break;
        case 2:
            palette = gFireRedMenuElements3_Pal;
            break;
    }

    LoadPalette(palette, palOffset, 0x20);
}

void blit_move_info_icon(u8 windowId, u8 iconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(windowId, gFireRedMenuElements_Gfx + gMoveMenuInfoIcons[iconId].offset * 32, 0, 0, 128, 128, x, y, gMoveMenuInfoIcons[iconId].width, gMoveMenuInfoIcons[iconId].height);
}

void sub_819A344(u8 a0, u8 *dest, u8 color)
{
    s32 curFlag;
    s32 flagCount;
    u8 *endOfString;
    u8 *string = dest;

    *(string++) = EXT_CTRL_CODE_BEGIN;
    *(string++) = EXT_CTRL_CODE_COLOR;
    *(string++) = color;
    *(string++) = EXT_CTRL_CODE_BEGIN;
    *(string++) = EXT_CTRL_CODE_SHADOW;
    *(string++) = color + 1;

    switch (a0)
    {
        case 0:
            StringCopy(string, gSaveBlock2Ptr->playerName);
            break;
        case 1:
            if (IsNationalPokedexEnabled())
                string = ConvertIntToDecimalStringN(string, GetNationalPokedexCount(1), 0, 3);
            else
                string = ConvertIntToDecimalStringN(string, GetHoennPokedexCount(1), 0, 3);
            *string = EOS;
            break;
        case 2:
            string = ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->playTimeHours, 0, 3);
            *(string++) = CHAR_COLON;
            ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->playTimeMinutes, 2, 2);
            break;
        case 3:
            sub_81245DC(string, gMapHeader.regionMapSectionId);
            break;
        case 4:
            for (curFlag = FLAG_BADGE01_GET, flagCount = 0, endOfString = string + 1; curFlag <= FLAG_BADGE08_GET; curFlag++)
            {
                if (FlagGet(curFlag))
                    flagCount++;
            }
            *string = flagCount + CHAR_0;
            *endOfString = EOS;
            break;
    }
}


void PopupSignMessageBox(u8 nTiles)
{
    sPopupTaskId = CreateTask(Task_SignLinePopup, 90);
    SetGpuReg(REG_OFFSET_BG0VOFS, -8 * nTiles); //-40 => 5*8
    gTasks[sPopupTaskId].data[2] = -8 * nTiles;
}

bool8 IsSignPoppedUp(void)
{
    return sPopupTaskId != 0;
}

static void Task_SignLinePopup(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    
    task->data[2] += 8;
    if (task->data[2] >= 0)
    {
        task->data[2] = 0;
        DestroyTask(sPopupTaskId);
        sPopupTaskId = 0;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->data[2]);
}

