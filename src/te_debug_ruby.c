// Functions imported from PokeRuby's debug menu
#include "global.h"
#include "main.h"
#include "menu.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "task.h"

///////////////////////////////////////////////////////////////////////////////
// Create Items
/*
static const u8 ItemDebug_StringWhichItem[] = _("Which item?");
static const u8 ItemDebug_StringHowMany[] = _("How　many？");

static void Task_PrintMakeItemDebugMenu(u8 taskId);
static void Task_DebugItemHowMany(u8 taskId);
static void Task_DebugItemAddItem(u8 taskId);
static void DebugItem_CancelMenu(u8 taskId);

static void ItemDebug_PrintDialogBox(u16 itemId, u16 quantity)
{
    Menu_BlankWindowRect(4, 17, 22, 18);
    ConvertIntToDecimalStringN(gStringVar1, itemId, STR_CONV_MODE_RIGHT_ALIGN, 3);
    Menu_PrintText(gStringVar1, 4, 17);
    Menu_PrintText(ItemId_GetName(itemId), 8, 17);
    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
    Menu_PrintText(gStringVar1, 18, 17);
}

void Debug_CreateTaskMakeItem()
{
    u8 taskId = CreateTask(Task_PrintMakeItemDebugMenu, 80);
    Menu_EraseScreen();
    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = 1;
}

static void Task_PrintMakeItemDebugMenu(u8 taskId)
{
    struct Task *task = gTasks + taskId;
    Menu_DisplayDialogueFrame();
    Menu_PrintText(ItemDebug_StringWhichItem, 2, 15);
    ItemDebug_PrintDialogBox(task->data[1], task->data[2]);
    task->func = Task_DebugItemHowMany;
}

static void Task_DebugItemHowMany(u8 taskId)
{
    struct Task *task = gTasks + taskId;
    if (gMain.newKeys & A_BUTTON)
    {
        Menu_DisplayDialogueFrame();
        Menu_PrintText(ItemDebug_StringHowMany, 2, 15);
        ItemDebug_PrintDialogBox(task->data[1], task->data[2]);
        task->func = Task_DebugItemAddItem;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        task->func = DebugItem_CancelMenu;
    }
    else if (DebugMenu_8077DD8(task->data + 1, 1, ITEM_15C, gMain.newAndRepeatedKeys) == TRUE)
    {
        ItemDebug_PrintDialogBox(task->data[1], task->data[2]);
    }
}

static void Task_DebugItemAddItem(u8 taskId)
{
    struct Task *task = gTasks + taskId;
    if (gMain.newKeys & A_BUTTON)
    {
        if (AddBagItem(task->data[1], task->data[2]) == TRUE)
            PlaySE(SE_SELECT);
        task->func = Task_PrintMakeItemDebugMenu;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        task->func = Task_PrintMakeItemDebugMenu;
    }
    else if (DebugMenu_8077DD8(task->data + 2, 1, 99, gMain.newAndRepeatedKeys) == TRUE)
    {
        ItemDebug_PrintDialogBox(task->data[1], task->data[2]);
    }
}

static void DebugItem_CancelMenu(u8 taskId)
{
    // Menu_EraseScreen();
    ScriptContext2_Disable();
    DestroyTask(taskId);
    // DebugMenu_8077048();
}
/*/
void Debug_CreateTaskMakeItem() {}
//*/