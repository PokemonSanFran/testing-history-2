#include "global.h"
#include "safari_zone.h"
#include "event_data.h"
#include "game_stat.h"
#include "main.h"
#include "battle.h"
#include "string_util.h"

struct PokeblockFeeder
{
    /*0x00*/ s16 x;
    /*0x02*/ s16 y;
    /*0x04*/ s8 mapNum;
    /*0x05*/ u8 stepCounter;
    /*0x08*/ struct Pokeblock pokeblock;
};

#define NUM_POKEBLOCK_FEEDERS 10

extern u8 gBattleOutcome;
extern void* gFieldCallback;

extern u8 gUnknown_082A4B8A[];
extern u8 gUnknown_082A4B6F[];
extern u8 gUnknown_082A4B4C[];
extern u8 gUnknown_082A4B9B[];
extern const u8* const gPokeblockNames[];

extern void sub_80EE44C(u8, u8);
extern void IncrementGameStat(u8 index);
extern void ScriptContext1_SetupScript(u8*);
extern void ScriptContext2_RunNewScript(u8*);
extern void c2_exit_to_overworld_2_switch(void);
extern void c2_exit_to_overworld_1_continue_scripts_restart_music(void);
extern void c2_load_new_map(void);
extern void sub_80AF6F0(void);
extern void ScriptContext1_Stop(void);
extern void warp_in(void);
extern void GetXYCoordsOneStepInFrontOfPlayer(s16* x, s16* y);
extern void PlayerGetDestCoords(s16* x, s16* y);

EWRAM_DATA u8 gNumSafariBalls = 0;
EWRAM_DATA static u16 sSafariZoneStepCounter = 0;
EWRAM_DATA static u8 sSafariZoneCaughtMons = 0;
EWRAM_DATA static u8 sSafariZoneFleedMons = 0;
EWRAM_DATA static struct PokeblockFeeder sPokeblockFeeders[NUM_POKEBLOCK_FEEDERS] = {0};

static void ClearAllPokeblockFeeders(void);
static void DecrementFeederStepCounters(void);

bool32 GetSafariZoneFlag(void)
{
    return FlagGet(SYS_SAFARI_MODE);
}

void SetSafariZoneFlag(void)
{
    FlagSet(SYS_SAFARI_MODE);
}

void ResetSafariZoneFlag(void)
{
    FlagReset(SYS_SAFARI_MODE);
}

void EnterSafariMode(void)
{
    IncrementGameStat(GAME_STAT_ENTERED_SAFARI_ZONE);
    SetSafariZoneFlag();
    ClearAllPokeblockFeeders();
    gNumSafariBalls = 30;
    sSafariZoneStepCounter = 500;
    sSafariZoneCaughtMons = 0;
    sSafariZoneFleedMons = 0;
}

void ExitSafariMode(void)
{
    sub_80EE44C(sSafariZoneCaughtMons, sSafariZoneFleedMons);
    ResetSafariZoneFlag();
    ClearAllPokeblockFeeders();
    gNumSafariBalls = 0;
    sSafariZoneStepCounter = 0;
}

bool8 SafariZoneTakeStep(void)
{
    if (GetSafariZoneFlag() == FALSE)
    {
        return FALSE;
    }

    DecrementFeederStepCounters();
    sSafariZoneStepCounter--;
    if (sSafariZoneStepCounter == 0)
    {
        ScriptContext1_SetupScript(gUnknown_082A4B8A);
        return TRUE;
    }
    return FALSE;
}

void SafariZoneRetirePrompt(void)
{
    ScriptContext1_SetupScript(gUnknown_082A4B6F);
}

void sub_80FC190(void)
{
    sSafariZoneFleedMons += gBattleResults.field_1F;
    if (gBattleOutcome == BATTLE_CAUGHT)
        sSafariZoneCaughtMons++;
    if (gNumSafariBalls != 0)
    {
        SetMainCallback2(c2_exit_to_overworld_2_switch);
    }
    else if (gBattleOutcome == 8)
    {
        ScriptContext2_RunNewScript(gUnknown_082A4B4C);
        warp_in();
        gFieldCallback = sub_80AF6F0;
        SetMainCallback2(c2_load_new_map);
    }
    else if (gBattleOutcome == BATTLE_CAUGHT)
    {
        ScriptContext1_SetupScript(gUnknown_082A4B9B);
        ScriptContext1_Stop();
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
}

static void ClearPokeblockFeeder(u8 index)
{
    memset(&sPokeblockFeeders[index], 0, sizeof(struct PokeblockFeeder));
}

static void ClearAllPokeblockFeeders(void)
{
    memset(sPokeblockFeeders, 0, sizeof(sPokeblockFeeders));
}

static void GetPokeblockFeederInFront(void)
{
    s16 x, y;
    u16 i;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sPokeblockFeeders[i].mapNum
         && sPokeblockFeeders[i].x == x
         && sPokeblockFeeders[i].y == y)
        {
            gScriptResult = i;
            StringCopy(gStringVar1, gPokeblockNames[sPokeblockFeeders[i].pokeblock.color]);
            return;
        }
    }

    gScriptResult = -1;
}

void GetPokeblockFeederWithinRange(void)
{
    s16 x, y;
    u16 i;

    PlayerGetDestCoords(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sPokeblockFeeders[i].mapNum)
        {
            //Get absolute value of x and y distance from Pokeblock feeder on current map
            x -= sPokeblockFeeders[i].x;
            y -= sPokeblockFeeders[i].y;
            if (x < 0)
                x *= -1;
            if (y < 0)
                y *= -1;
            if ((x + y) <= 5)
            {
                gScriptResult = i;
                return;
            }
        }
    }

    gScriptResult = -1;
}

// unused
struct Pokeblock *SafariZoneGetPokeblockInFront(void)
{
    GetPokeblockFeederInFront();

    if (gScriptResult == 0xFFFF)
        return NULL;
    else
        return &sPokeblockFeeders[gScriptResult].pokeblock;
}

struct Pokeblock *SafariZoneGetActivePokeblock(void)
{
    GetPokeblockFeederWithinRange();

    if (gScriptResult == 0xFFFF)
        return NULL;
    else
        return &sPokeblockFeeders[gScriptResult].pokeblock;
}

void SafariZoneActivatePokeblockFeeder(u8 pkblId)
{
    s16 x, y;
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        // Find free entry in sPokeblockFeeders
        if (sPokeblockFeeders[i].mapNum == 0
         && sPokeblockFeeders[i].x == 0
         && sPokeblockFeeders[i].y == 0)
        {
            // Initialize Pokeblock feeder
            GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
            sPokeblockFeeders[i].mapNum = gSaveBlock1Ptr->location.mapNum;
            sPokeblockFeeders[i].pokeblock = gSaveBlock1Ptr->pokeblocks[pkblId];
            sPokeblockFeeders[i].stepCounter = 100;
            sPokeblockFeeders[i].x = x;
            sPokeblockFeeders[i].y = y;
            break;
        }
    }
}

static void DecrementFeederStepCounters(void)
{
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (sPokeblockFeeders[i].stepCounter != 0)
        {
            sPokeblockFeeders[i].stepCounter--;
            if (sPokeblockFeeders[i].stepCounter == 0)
                ClearPokeblockFeeder(i);
        }
    }
}

// unused
bool8 GetInFrontFeederPokeblockAndSteps(void)
{
    GetPokeblockFeederInFront();

    if (gScriptResult == 0xFFFF)
    {
        return FALSE;
    }

    ConvertIntToDecimalStringN(gStringVar2,
        sPokeblockFeeders[gScriptResult].stepCounter,
        STR_CONV_MODE_LEADING_ZEROS, 3);

    return TRUE;
}
