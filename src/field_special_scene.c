#include "global.h"
#include "task.h"
#include "sprite.h"
#include "field_map_obj.h"
#include "songs.h"
#include "sound.h"
#include "palette.h"
#include "script.h"
#include "vars.h"
#include "event_data.h"
#include "main.h"

#define SECONDS(value) ((signed) (60.0 * value + 0.5))

extern u8 GetSSTidalLocation(s8 *, s8 *, s16 *, s16 *); // should be in field_specials.h
extern void warp1_set(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
extern bool8 sub_80D3340(u8, u8, u8);
extern bool32 CountSSTidalStep(u16);
extern bool8 exec_movement(u8, u8, u8, u8 *);
extern void copy_saved_warp2_bank_and_enter_x_to_warp1(u8 unused);
extern void sp13E_warp_to_last_warp(void);
extern void saved_warp2_set(int unused, s8 mapGroup, s8 mapNum, s8 warpId);
extern void sub_80AF8B8(void);

// porthole states
enum
{
    INIT_PORTHOLE,
    IDLE_CHECK,
    EXECUTE_MOVEMENT,
    EXIT_PORTHOLE,
};

extern void SetCameraPanning(s16 x, s16 y);
extern void SetCameraPanningCallback(void ( *callback)());
extern void InstallCameraPanAheadCallback();
extern void pal_fill_black(void);
extern void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatileId);
extern void DrawWholeMapView();

extern s8 gTruckCamera_HorizontalTable[];

extern u8 gUnknown_0858E8AB[];
extern u8 gUnknown_0858E8AD[];

void Task_Truck3(u8);

s16 GetTruckCameraBobbingY(int a1)
{
    if (!(a1 % 120))
        return -1;
    else if ((a1 % 10) <= 4)
        return 1;

    return 0;
}

s16 GetTruckBoxMovement(int a1) // for the box movement?
{
    if (!((a1 + 120) % 180))
        return -1;

    return 0;
}

// smh STILL BROKEN IN EMERALD
void Task_Truck1(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 cameraYpan;
    s16 box1 = 0;
    s16 box2 = 0;
    s16 box3 = 0;
    u8 mapNum, mapGroup;
    register s16 zero asm("r4");

    box1 = GetTruckBoxMovement(data[0] + 30) * 4; // top box.
    sub_808E82C(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3, box1 + 3);
    box2 = GetTruckBoxMovement(data[0]) * 2; // bottom left box.
    sub_808E82C(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 0, box2 - 3);
    box3 = GetTruckBoxMovement(data[0]) * 4; // bottom right box.
    mapNum = gSaveBlock1Ptr->location.mapNum;
    mapGroup = gSaveBlock1Ptr->location.mapGroup;
    zero = 0;
    sub_808E82C(3, mapNum, mapGroup, -3, box3);

    if (++data[0] == SECONDS(500)) // this will never run
        data[0] = zero; // reset the timer if it gets stuck.

    cameraYpan = GetTruckCameraBobbingY(data[0]);
    SetCameraPanning(0, cameraYpan);
}

void Task_Truck2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 cameraYpan;
    s16 cameraXpan;
    s16 box1;
    s16 box2;
    s16 box3;

    data[0]++;
    data[2]++;

    if (data[0] > 5)
    {
        data[0] = 0;
        data[1]++;
    }
    if ((u16)data[1] == 19)
    {
        DestroyTask(taskId);
    }
    else
    {
        if (gTruckCamera_HorizontalTable[data[1]] == 2)
            gTasks[taskId].func = Task_Truck3;

        cameraXpan = gTruckCamera_HorizontalTable[data[1]];
        cameraYpan = GetTruckCameraBobbingY(data[2]);
        SetCameraPanning(cameraXpan, cameraYpan);
        box1 = GetTruckBoxMovement(data[2] + 30) * 4;
        sub_808E82C(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3 - cameraXpan, box1 + 3);
        box2 = GetTruckBoxMovement(data[2]) * 2;
        sub_808E82C(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -cameraXpan, box2 - 3);
        box3 = GetTruckBoxMovement(data[2]) * 4;
        sub_808E82C(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3 - cameraXpan, box3);
    }
}

void Task_Truck3(u8 taskId)
{
   s16 *data = gTasks[taskId].data;
   s16 cameraXpan;
   s16 cameraYpan;

   data[0]++;

   if (data[0] > 5)
   {
       data[0] = 0;
       data[1]++;
   }

   if ((u16)data[1] == 19)
   {
       DestroyTask(taskId);
   }
   else
   {
       cameraXpan = gTruckCamera_HorizontalTable[data[1]];
       cameraYpan = 0;
       SetCameraPanning(cameraXpan, 0);
       sub_808E82C(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3 - cameraXpan, cameraYpan + 3);
       sub_808E82C(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -cameraXpan, cameraYpan - 3);
       sub_808E82C(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3 - cameraXpan, cameraYpan);
   }
}

void Task_HandleTruckSequence(u8 taskId)
{
   s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        /*
        Each case has a timer which is handled with data[1], incrementing
        until it reaches the if function's condition, which sets the next task up.
        */
    case 0:
        data[1]++;
        if (data[1] == SECONDS(1.5))
        {
            SetCameraPanningCallback(NULL);
            data[1] = 0; // reset the timer.
            data[2] = CreateTask(Task_Truck1, 0xA);
            data[0] = 1; // run the next case.
            PlaySE(SE_TRACK_MOVE);
        }
        break;
    case 1:
        data[1]++;
        if (data[1] == SECONDS(2.5))
        {
            pal_fill_black();
            data[1] = 0;
            data[0] = 2;
        }
        break;
    case 2:
        data[1]++;
        if (!gPaletteFade.active && data[1] > SECONDS(5))
        {
            data[1] = 0;
            DestroyTask(data[2]);
            data[3] = CreateTask(Task_Truck2, 0xA);
            data[0] = 3;
            PlaySE(SE_TRACK_STOP);
        }
        break;
    case 3:
        if (!gTasks[data[3]].isActive) // is Truck2 no longer active (is Truck3 active?)
        {
            InstallCameraPanAheadCallback();
            data[1] = 0;
            data[0] = 4;
        }
        break;
    case 4:
        data[1]++;
        if (data[1] == 90)
        {
            PlaySE(SE_TRACK_HAIK);
            data[1] = 0;
            data[0] = 5;
        }
        break;
    case 5:
        data[1]++;
        if (data[1] == 120)
        {
            MapGridSetMetatileIdAt(11, 8, 520);
            MapGridSetMetatileIdAt(11, 9, 528);
            MapGridSetMetatileIdAt(11, 10, 536);
            DrawWholeMapView();
            PlaySE(SE_TRACK_DOOR);
            DestroyTask(taskId);
            ScriptContext2_Disable();
        }
        break;
    }
}

void ExecuteTruckSequence(void)
{
    MapGridSetMetatileIdAt(11, 8, 525);
    MapGridSetMetatileIdAt(11, 9, 533);
    MapGridSetMetatileIdAt(11, 10, 541);
    DrawWholeMapView();
    ScriptContext2_Enable();
    CpuFastFill(0, gPlttBufferFaded, 0x400);
    CreateTask(Task_HandleTruckSequence, 0xA);
}

void EndTruckSequence(u8 taskId)
{
    if (!FuncIsActiveTask(Task_HandleTruckSequence))
    {
        sub_808E82C(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3, 3);
        sub_808E82C(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 0, -3);
        sub_808E82C(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3, 0);
    }
}

bool8 sub_80FB59C(void)
{
    s8 mapGroup, mapNum;
    s16 x, y;

    if (GetSSTidalLocation(&mapGroup, &mapNum, &x, &y))
    {
        return FALSE;
    }
    else
    {
        warp1_set(mapGroup, mapNum, -1, x, y);
        return TRUE;
    }
}

void Task_HandlePorthole(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *var = GetVarPointer(VAR_PORTHOLE);
    struct WarpData *location = &gSaveBlock1Ptr->location;

    switch (data[0])
    {
    case INIT_PORTHOLE: // finish fading before making porthole finish.
        if (!gPaletteFade.active)
        {
            data[1] = 0;
            data[0] = EXECUTE_MOVEMENT; // execute movement before checking if should be exited. strange?
        }
        break;
    case IDLE_CHECK: // idle and move.
        if (gMain.newKeys & A_BUTTON)
            data[1] = 1;
        if (!sub_80D3340(0xFF, location->mapNum, location->mapGroup))
            return;
        if (CountSSTidalStep(1) == TRUE)
        {
            if (*var == 2)
                *var = 9;
            else
                *var = 10;
            data[0] = 3;
            return;
        }
        data[0] = 2;
    case EXECUTE_MOVEMENT: // execute movement.
        if (data[1])
        {
            data[0] = EXIT_PORTHOLE; // exit porthole.
            return;
        }
        // run this once.
        if (*var == 2) // which direction?
        {
            exec_movement(0xFF, location->mapNum, location->mapGroup, gUnknown_0858E8AB);
            data[0] = IDLE_CHECK; // run case 1.
        }
        else
        {
            exec_movement(0xFF, location->mapNum, location->mapGroup, gUnknown_0858E8AD);
            data[0] = IDLE_CHECK; // run case 1.
        }
        break;
    case EXIT_PORTHOLE: // exit porthole.
        FlagReset(0x4001);
        FlagReset(0x4000);
        copy_saved_warp2_bank_and_enter_x_to_warp1(0);
        sp13E_warp_to_last_warp();
        DestroyTask(taskId);
        break;
    }
}

void sub_80FB6EC(void)
{
    u8 spriteId = AddPseudoFieldObject(0x8C, SpriteCallbackDummy, 112, 80, 0);

    gSprites[spriteId].coordOffsetEnabled = FALSE;

    if (VarGet(0x40B4) == 2)
    {
        StartSpriteAnim(&gSprites[spriteId], FieldObjectDirectionToImageAnimId(4));
    }
    else
    {
        StartSpriteAnim(&gSprites[spriteId], FieldObjectDirectionToImageAnimId(3));
    }
}

void sub_80FB768(void)
{
    sub_80FB6EC();
    gMapObjects[gPlayerAvatar.mapObjectId].mapobj_bit_13 = TRUE;
    pal_fill_black();
    CreateTask(Task_HandlePorthole, 80);
    ScriptContext2_Enable();
}

void sub_80FB7A4(void)
{
    FlagSet(SYS_CRUISE_MODE);
    FlagSet(0x4001);
    FlagSet(0x4000);
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    sub_80FB59C();
    sub_80AF8B8();
}
