#include "global.h"
#include "menu.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"
#include "field_message_box.h"

struct FieldMessageData
{
    u8 mode:4;
    u8 boxType:4;
};

static EWRAM_DATA struct FieldMessageData sFieldMessageData = {0};

static void textbox_fdecode_auto_and_task_add(const u8*, bool32);
static void textbox_auto_and_task_add(void);

void InitFieldMessageBox(void)
{
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
    gTextFlags.canABSpeedUpPrint = 0;
    gTextFlags.useAlternateDownArrow = 0;
    gTextFlags.autoScroll = 0;
    gTextFlags.forceMidTextSpeed = 0;
}

void THE_LoadMessageBoxPalette_Dream();
static void DrawFieldDialogFrame(u8 windowId, bool8 copyToVram)
{
    switch (sFieldMessageData.boxType)
    {
        case FIELD_MESSAGE_TYPE_DREAM:
            THE_LoadMessageBoxPalette_Dream();
            // fallthrough
        default:
        case FIELD_MESSAGE_TYPE_DESCRIBE:
            DrawDescribeFrame(windowId, copyToVram);
            break;
        case FIELD_MESSAGE_TYPE_STANDARD:
            DrawStdWindowFrame(windowId, copyToVram);
            break;
        case FIELD_MESSAGE_TYPE_DIALOG:
            DrawDialogueFrame(windowId, copyToVram);
            break;
        case FIELD_MESSAGE_TYPE_SIGN:
            DrawSignWindowFrame(windowId, copyToVram);
            break;
    }
}

static void Task_DisplayTextBox(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
           LoadStdWindowFrame();
           task->data[0]++;
           break;
        case 1:
           DrawFieldDialogFrame(0, 1);
           task->data[0]++;
           break;
        case 2:
            if (RunTextPrintersAndIsPrinter0Active() != 1)
            {
                sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
                sFieldMessageData.boxType = 0;
                DestroyTask(taskId);
            }
    }
}

static void CreateDisplayTextboxTask(void)
{
    CreateTask(Task_DisplayTextBox, 0x50);
}

static void DeleteDisplayTextboxTask(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DisplayTextBox);
    if (taskId != 0xFF)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sFieldMessageData.mode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    textbox_fdecode_auto_and_task_add(str, 1);
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

void sub_8098214(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 sub_8098238(const u8 *str)
{
    if (sFieldMessageData.mode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(sub_8098214, 0);
    StartMatchCallFromScript(str);
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sFieldMessageData.mode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    textbox_fdecode_auto_and_task_add(str, 0);
    return TRUE;
}

bool8 sub_80982A0(u8 *str)
{
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    textbox_fdecode_auto_and_task_add(str, 1);
    return TRUE;
}

bool8 sub_80982B8(void)
{
    if (sFieldMessageData.mode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_NORMAL;
    sFieldMessageData.boxType = FIELD_MESSAGE_TYPE_DIALOG;
    textbox_auto_and_task_add();
    return TRUE;
}

static void textbox_fdecode_auto_and_task_add(const u8* str, bool32 allowSkippingDelayWithButtonPress)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    CreateDisplayTextboxTask();
}

static void textbox_auto_and_task_add(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateDisplayTextboxTask();
}

void HideFieldMessageBox(void)
{
    DeleteDisplayTextboxTask();
    ClearDialogWindowAndFrame(0, 1);
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageData.mode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageData.mode == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    return FALSE;
}

void SetFieldMessageBoxType(u8 type)
{
    sFieldMessageData.boxType = type;
}

void sub_8098358(void) //Unused?
{
    DeleteDisplayTextboxTask();
    DrawStdWindowFrame(0, 1);
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
}

void sub_8098374(void)
{
    DeleteDisplayTextboxTask();
    sFieldMessageData.mode = FIELD_MESSAGE_BOX_HIDDEN;
}
