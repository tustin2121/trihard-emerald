#include "global.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "task.h"

static EWRAM_DATA u8 sEscalatorAnim_TaskId = 0;

static void EscalatorChangeTiles(u8 taskId, const s16 *list, u16 isImpassableFlag)
{
    s16 r5 = gTasks[taskId].data[4] - 1;
    s16 r3 = gTasks[taskId].data[5] - 1;
    s16 r4 = gTasks[taskId].data[1];
    s16 y;
    s16 x;

    if (gTasks[taskId].data[2] == 0)
    {
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < 3; x++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(r5 + x, r3 + y);

                if (list[r4] == metatileId)
                {
                    if (r4 != 2)
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[r4 + 1]);
                    else
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[0]);
                }
            }
        }
    }
    else
    {
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < 3; x++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(r5 + x, r3 + y);

                if (list[2 - r4] == metatileId)
                {
                    if (r4 != 2)
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[1 - r4]);
                    else
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[2]);
                }
            }
        }
    }
}

static const u16 sEscalatorMetatiles_UpA[] = {0x284, 0x282, 0x280};
static const u16 sEscalatorMetatiles_UpB[] = {0x285, 0x283, 0x281};
static const u16 sEscalatorMetatiles_UpC[] = {0x28C, 0x28A, 0x288};
static const u16 sEscalatorMetatiles_UpD[] = {0x28D, 0x28B, 0x289};
static const u16 sEscalatorMetatiles_DownA[] = {0x2A0, 0x2A2, 0x2A4};
static const u16 sEscalatorMetatiles_DownB[] = {0x2A1, 0x2A3, 0x2A5};
static const u16 sEscalatorMetatiles_DownC[] = {0x2A8, 0x2AA, 0x2AC};
static const u16 sEscalatorMetatiles_DownPlant[] = {0x308, 0x309, 0x30A};

static void Task_EscalatorAnimateTiles(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[3] = 1;

    switch (data[0])
    {
        case 0:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_UpA, 0);
            break;
        case 1:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_UpB, 0);
            break;
        case 2:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_UpC, METATILE_COLLISION_MASK);
            break;
        case 3:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_UpD, 0);
            break;
        case 4:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_DownA, METATILE_COLLISION_MASK);
            break;
        case 5:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_DownB, 0);
            break;
        case 6:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_DownC, 0);
            break;
        case 7:
            EscalatorChangeTiles(taskId, sEscalatorMetatiles_DownPlant, METATILE_COLLISION_MASK);
            break;
    }

    data[0] = (data[0] + 1) & 7;
    if (!data[0])
    {
        DrawWholeMapView();
        data[1] = (data[1] + 1) % 3;
        data[3] = 0;
    }
}

static u8 CreateEscaltorAnimationTask(u16 var)
{
    u8 taskId = CreateTask(Task_EscalatorAnimateTiles, 0);
    s16 *data = gTasks[taskId].data;

    PlayerGetDestCoords(&data[4], &data[5]);
    data[0] = 0;
    data[1] = 0;
    data[2] = var;
    Task_EscalatorAnimateTiles(taskId);
    return taskId;
}

void sub_80E1558(u8 var)
{
    sEscalatorAnim_TaskId = CreateEscaltorAnimationTask(var);
}

void sub_80E1570(void)
{
    DestroyTask(sEscalatorAnim_TaskId);
}

bool8 sub_80E1584(void)
{
    if (gTasks[sEscalatorAnim_TaskId].data[3] == 0 && gTasks[sEscalatorAnim_TaskId].data[1] == 2)
        return FALSE;
    else
        return TRUE;
}
