#include "global.h"
#include "pokemon.h"
#include "daycare.h"
#include "string_util.h"
#include "species.h"
#include "items.h"
#include "mail.h"
#include "pokemon_storage_system.h"
#include "event_data.h"
#include "rng.h"
#include "main.h"
#include "moves.h"

#define EGG_MOVES_ARRAY_COUNT           10
#define EGG_LVL_UP_MOVES_ARRAY_COUNT    50

extern u16 gMoveToLearn;

extern u8 GetCursorSelectionMonId(void);
extern u16 ItemIdToBattleMoveId(u16);

// this file's functions
static void ClearDaycareMonMisc(struct DaycareMiscMon *misc);
void SetInitialEggData(struct Pokemon *mon, u16 species, struct DayCare *daycare);

// RAM buffers used to assist with BuildEggMoveset()
EWRAM_DATA static u16 sHatchedEggLevelUpMoves[EGG_LVL_UP_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sHatchedEggFatherMoves[4] = {0};
EWRAM_DATA static u16 sHatchedEggFinalMoves[4] = {0};
EWRAM_DATA static u16 sHatchedEggEggMoves[EGG_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sHatchedEggMotherMoves[4] = {0};

#include "data/pokemon/egg_moves.h"

extern const u8 sJapaneseEggNickname[];

u8 *GetMonNick(struct Pokemon *mon, u8 *dest)
{
    u8 nickname[POKEMON_NAME_LENGTH * 2];

    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    return StringCopy10(dest, nickname);
}

u8 *GetBoxMonNick(struct BoxPokemon *mon, u8 *dest)
{
    u8 nickname[POKEMON_NAME_LENGTH * 2];

    GetBoxMonData(mon, MON_DATA_NICKNAME, nickname);
    return StringCopy10(dest, nickname);
}

u8 CountPokemonInDaycare(struct DayCare *daycare)
{
    u8 i, count;
    count = 0;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) != 0)
            count++;
    }

    return count;
}

void InitDaycareMailRecordMixing(struct DayCare *daycare, struct RecordMixingDayCareMail *daycareMail)
{
    u8 i;
    u8 numDaycareMons = 0;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) != SPECIES_NONE)
        {
            numDaycareMons++;
            if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_HELD_ITEM) == ITEM_NONE)
            {
                daycareMail->holdsItem[i] = FALSE;
            }
            else
            {
                daycareMail->holdsItem[i] = TRUE;
            }
        }
        else
        {
            daycareMail->holdsItem[i] = TRUE;
        }
    }

    daycareMail->numDaycareMons = numDaycareMons;
}

static s8 Daycare_FindEmptySpot(struct DayCare *daycare)
{
    u8 i;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) == 0)
            return i;
    }

    return -1;
}

static void StorePokemonInDaycare(struct Pokemon *mon, struct DaycareMon *daycareMon)
{
    if (MonHasMail(mon))
    {
        u8 mailId;

        StringCopy(daycareMon->misc.OT_name, gSaveBlock2Ptr->playerName);
        GetMonNick(mon, daycareMon->misc.monName);
        StripExtCtrlCodes(daycareMon->misc.monName);
        daycareMon->misc.gameLanguage = LANGUAGE_ENGLISH;
        daycareMon->misc.monLanguage = GetMonData(mon, MON_DATA_LANGUAGE);
        mailId = GetMonData(mon, MON_DATA_MAIL);
        daycareMon->misc.mail = gSaveBlock1Ptr->mail[mailId];
        TakeMailFromMon(mon);
    }

    daycareMon->mon = mon->box;
    BoxMonRestorePP(&daycareMon->mon);
    daycareMon->steps = 0;
    ZeroMonData(mon);
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

static void StorePokemonInEmptyDaycareSlot(struct Pokemon *mon, struct DayCare *daycare)
{
    s8 slotId = Daycare_FindEmptySpot(daycare);
    StorePokemonInDaycare(mon, &daycare->mons[slotId]);
}

void StoreSelectedPokemonInDaycare(void)
{
    u8 monId = GetCursorSelectionMonId();
    StorePokemonInEmptyDaycareSlot(&gPlayerParty[monId], &gSaveBlock1Ptr->daycare);
}

// Shifts the second daycare pokemon slot into the first slot.
static void ShiftDaycareSlots(struct DayCare *daycare)
{
    // This condition is only satisfied when the player takes out the first pokemon from the daycare.
    if (GetBoxMonData(&daycare->mons[1].mon, MON_DATA_SPECIES) != 0
        && GetBoxMonData(&daycare->mons[0].mon, MON_DATA_SPECIES) == 0)
    {
        daycare->mons[0].mon = daycare->mons[1].mon;
        ZeroBoxMonData(&daycare->mons[1].mon);

        daycare->mons[0].misc = daycare->mons[1].misc;
        daycare->mons[0].steps = daycare->mons[1].steps;
        daycare->mons[1].steps = 0;
        ClearDaycareMonMisc(&daycare->mons[1].misc);
    }
}

static void ApplyDaycareExperience(struct Pokemon *mon)
{
    s32 i;
    bool8 firstMove;
    u16 learnedMove;

    for (i = 0; i < MAX_MON_LEVEL; i++)
    {
        // Add the mon's gained daycare experience level by level until it can't level up anymore.
        if (TryIncrementMonLevel(mon))
        {
            // Teach the mon new moves it learned while in the daycare.
            firstMove = TRUE;
            while ((learnedMove = MonTryLearningNewMove(mon, firstMove)) != 0)
            {
                firstMove = FALSE;
                if (learnedMove == 0xFFFF)
                {
                    // Mon already knows 4 moves.
                    DeleteFirstMoveAndGiveMoveToMon(mon, gMoveToLearn);
                }
            }
        }
        else
        {
            break;
        }
    }

    // Re-calculate the mons stats at its new level.
    CalculateMonStats(mon);
}

static u16 TakeSelectedPokemonFromDaycare(struct DaycareMon *daycareMon)
{
    u16 species;
    u32 experience;
    struct Pokemon pokemon;

    GetBoxMonNick(&daycareMon->mon, gStringVar1);
    species = GetBoxMonData(&daycareMon->mon, MON_DATA_SPECIES);
    BoxMonToMon(&daycareMon->mon, &pokemon);

    if (GetMonData(&pokemon, MON_DATA_LEVEL) != MAX_MON_LEVEL)
    {
        experience = GetMonData(&pokemon, MON_DATA_EXP) + daycareMon->steps;
        SetMonData(&pokemon, MON_DATA_EXP, &experience);
        ApplyDaycareExperience(&pokemon);
    }

    gPlayerParty[PARTY_SIZE - 1] = pokemon;
    if (daycareMon->misc.mail.itemId)
    {
        GiveMailToMon2(&gPlayerParty[PARTY_SIZE - 1], &daycareMon->misc.mail);
        ClearDaycareMonMisc(&daycareMon->misc);
    }

    ZeroBoxMonData(&daycareMon->mon);
    daycareMon->steps = 0;
    CompactPartySlots();
    CalculatePlayerPartyCount();
    return species;
}

static u16 TakeSelectedPokemonMonFromDaycareShiftSlots(struct DayCare *daycare, u8 slotId)
{
    u16 species = TakeSelectedPokemonFromDaycare(&daycare->mons[slotId]);
    ShiftDaycareSlots(daycare);
    return species;
}

u16 TakePokemonFromDaycare(void)
{
    return TakeSelectedPokemonMonFromDaycareShiftSlots(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

u8 GetLevelAfterDaycareSteps(struct BoxPokemon *mon, u32 steps)
{
    struct BoxPokemon tempMon = *mon;

    u32 experience = GetBoxMonData(mon, MON_DATA_EXP) + steps;
    SetBoxMonData(&tempMon, MON_DATA_EXP,  &experience);
    return GetLevelFromBoxMonExp(&tempMon);
}

u8 GetNumLevelsGainedFromSteps(struct DaycareMon *daycareMon)
{
    u8 levelBefore;
    u8 levelAfter;

    levelBefore = GetLevelFromBoxMonExp(&daycareMon->mon);
    levelAfter = GetLevelAfterDaycareSteps(&daycareMon->mon, daycareMon->steps);
    return levelAfter - levelBefore;
}

u8 GetNumLevelsGainedForDaycareMon(struct DaycareMon *daycareMon)
{
    u8 numLevelsGained = GetNumLevelsGainedFromSteps(daycareMon);
    ConvertIntToDecimalStringN(gStringVar2, numLevelsGained, STR_CONV_MODE_LEFT_ALIGN, 2);
    GetBoxMonNick(&daycareMon->mon, gStringVar1);
    return numLevelsGained;
}

static u32 GetDaycareCostForSelectedMon(struct DaycareMon *daycareMon)
{
    u32 cost;

    u8 numLevelsGained = GetNumLevelsGainedFromSteps(daycareMon);
    GetBoxMonNick(&daycareMon->mon, gStringVar1);
    cost = 100 + 100 * numLevelsGained;
    ConvertIntToDecimalStringN(gStringVar2, cost, STR_CONV_MODE_LEFT_ALIGN, 5);
    return cost;
}

static u16 GetDaycareCostForMon(struct DayCare *daycare, u8 slotId)
{
    return GetDaycareCostForSelectedMon(&daycare->mons[slotId]);
}

void GetDaycareCost(void)
{
    gSpecialVar_0x8005 = GetDaycareCostForMon(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

static void Debug_AddDaycareSteps(u16 numSteps)
{
    gSaveBlock1Ptr->daycare.mons[0].steps += numSteps;
    gSaveBlock1Ptr->daycare.mons[1].steps += numSteps;
}

u8 GetNumLevelsGainedFromDaycare(void)
{
    if (GetBoxMonData(&gSaveBlock1Ptr->daycare.mons[gSpecialVar_0x8004], MON_DATA_SPECIES) != 0)
        return GetNumLevelsGainedForDaycareMon(&gSaveBlock1Ptr->daycare.mons[gSpecialVar_0x8004]);

    return 0;
}

static void ClearDaycareMonMisc(struct DaycareMiscMon *misc)
{
    s32 i;

    for (i = 0; i < OT_NAME_LENGTH + 1; i++)
        misc->OT_name[i] = 0;
    for (i = 0; i < POKEMON_NAME_LENGTH + 1; i++)
        misc->monName[i] = 0;

    ClearMailStruct(&misc->mail);
}

static void ClearDaycareMon(struct DaycareMon *daycareMon)
{
    ZeroBoxMonData(&daycareMon->mon);
    daycareMon->steps = 0;
    ClearDaycareMonMisc(&daycareMon->misc);
}

static void ClearAllDaycareData(struct DayCare *daycare)
{
    u8 i;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
        ClearDaycareMon(&daycare->mons[i]);

    daycare->offspringPersonality = 0;
    daycare->stepCounter = 0;
}

// Determines what the species of an Egg would be based on the given species.
// It determines this by working backwards through the evolution chain of the
// given species.
u16 GetEggSpecies(u16 species)
{
    int i, j, k;
    bool8 found;

    // Working backwards up to 5 times seems arbitrary, since the maximum number
    // of times would only be 3 for 3-stage evolutions.
    for (i = 0; i < EVOS_PER_MON; i++)
    {
        found = FALSE;
        for (j = 1; j < NUM_SPECIES; j++)
        {
            for (k = 0; k < EVOS_PER_MON; k++)
            {
                if (gEvolutionTable[j].evolutions[k].targetSpecies == species)
                {
                    species = j;
                    found = TRUE;
                    break;
                }
            }

            if (found)
                break;
        }

        if (j == NUM_SPECIES)
            break;
    }

    return species;
}

static s32 GetSlotToInheritNature(struct DayCare *daycare)
{
    u32 species[DAYCARE_MON_COUNT];
    s32 i, slot = -1, dittoCount;

    // search for female gender
    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonGender(&daycare->mons[i].mon) == MON_FEMALE)
            slot = i;
    }

    // search for ditto
    for (dittoCount = 0, i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        species[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES);
        if (species[i] == SPECIES_DITTO)
            dittoCount++, slot = i;
    }

    // coin flip on ...two Dittos
    if (dittoCount == 2)
    {
        if (Random() >= USHRT_MAX / 2)
            slot = 0;
        else
            slot = 1;
    }

    // nature inheritance only if holds everstone
    if (GetBoxMonData(&daycare->mons[slot].mon, MON_DATA_HELD_ITEM) != ITEM_EVERSTONE
        || Random() >= USHRT_MAX / 2)
    {
        return -1;
    }

    return slot;
}

static void _TriggerPendingDaycareEgg(struct DayCare *daycare)
{
    s32 natureSlot;
    s32 natureTries = 0;

    SeedRng2(gMain.vblankCounter2);
    natureSlot = GetSlotToInheritNature(daycare);

    if (natureSlot < 0)
    {
        daycare->offspringPersonality = (Random2() << 0x10) | ((Random() % 0xfffe) + 1);
    }
    else
    {
        u8 wantedNature = GetNatureFromPersonality(GetBoxMonData(&daycare->mons[natureSlot].mon, MON_DATA_PERSONALITY, NULL));
        u32 personality;

        do
        {
            personality = (Random2() << 0x10) | (Random());
            if (wantedNature == GetNatureFromPersonality(personality) && personality != 0)
                break; // we found a personality with the same nature

            natureTries++;
        } while (natureTries <= 2400);

        daycare->offspringPersonality = personality;
    }

    FlagSet(FLAG_PENDING_DAYCARE_EGG);
}

static void _TriggerPendingDaycareMaleEgg(struct DayCare *daycare)
{
    daycare->offspringPersonality = (Random()) | (0x8000);
    FlagSet(FLAG_PENDING_DAYCARE_EGG);
}

void TriggerPendingDaycareEgg(void)
{
    _TriggerPendingDaycareEgg(&gSaveBlock1Ptr->daycare);
}

void TriggerPendingDaycareMaleEgg(void)
{
    _TriggerPendingDaycareMaleEgg(&gSaveBlock1Ptr->daycare);
}

// Removes the selected index from the given IV list and shifts the remaining
// elements to the left.
void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv)
{
    s32 i, j;
    u8 temp[NUM_STATS];

    ivs[selectedIv] = 0xff;
    for (i = 0; i < NUM_STATS; i++)
    {
        temp[i] = ivs[i];
    }

    j = 0;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (temp[i] != 0xff)
            ivs[j++] = temp[i];
    }
}

void InheritIVs(struct Pokemon *egg, struct DayCare *daycare)
{
    u8 i;
    u8 selectedIvs[3];
    u8 availableIVs[NUM_STATS];
    u8 whichParent[ARRAY_COUNT(selectedIvs)];
    u8 iv;

    // Initialize a list of IV indices.
    for (i = 0; i < NUM_STATS; i++)
    {
        availableIVs[i] = i;
    }

    // Select the 3 IVs that will be inherited.
    for (i = 0; i < ARRAY_COUNT(selectedIvs); i++)
    {
        // Randomly pick an IV from the available list.
        selectedIvs[i] = availableIVs[Random() % (NUM_STATS - i)];

        // Remove the selected IV index from the available IV indices.
        RemoveIVIndexFromList(availableIVs, i);
    }

    // Determine which parent each of the selected IVs should inherit from.
    for (i = 0; i < ARRAY_COUNT(selectedIvs); i++)
    {
        whichParent[i] = Random() % 2;
    }

    // Set each of inherited IVs on the egg mon.
    for (i = 0; i < ARRAY_COUNT(selectedIvs); i++)
    {
        switch (selectedIvs[i])
        {
            case 0:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_HP_IV);
                SetMonData(egg, MON_DATA_HP_IV, &iv);
                break;
            case 1:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_ATK_IV);
                SetMonData(egg, MON_DATA_ATK_IV, &iv);
                break;
            case 2:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_DEF_IV);
                SetMonData(egg, MON_DATA_DEF_IV, &iv);
                break;
            case 3:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_SPEED_IV);
                SetMonData(egg, MON_DATA_SPEED_IV, &iv);
                break;
            case 4:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_SPATK_IV);
                SetMonData(egg, MON_DATA_SPATK_IV, &iv);
                break;
            case 5:
                iv = GetBoxMonData(&daycare->mons[whichParent[i]].mon, MON_DATA_SPDEF_IV);
                SetMonData(egg, MON_DATA_SPDEF_IV, &iv);
                break;
        }
    }
}

// Counts the number of egg moves a pokemon learns and stores the moves in
// the given array.
static u8 GetEggMoves(struct Pokemon *pokemon, u16 *eggMoves)
{
    u16 eggMoveIdx;
    u16 numEggMoves;
    u16 species;
    u16 i;

    numEggMoves = 0;
    eggMoveIdx = 0;
    species = GetMonData(pokemon, MON_DATA_SPECIES);
    for (i = 0; i < ARRAY_COUNT(gEggMoves) - 1; i++)
    {
        if (gEggMoves[i] == species + EGG_MOVES_SPECIES_OFFSET)
        {
            eggMoveIdx = i + 1;
            break;
        }
    }

    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
    {
        if (gEggMoves[eggMoveIdx + i] > EGG_MOVES_SPECIES_OFFSET)
        {
            // TODO: the curly braces around this if statement are required for a matching build.
            break;
        }

        eggMoves[i] = gEggMoves[eggMoveIdx + i];
        numEggMoves++;
    }

    return numEggMoves;
}

void BuildEggMoveset(struct Pokemon *egg, struct BoxPokemon *father, struct BoxPokemon *mother)
{
    u16 numSharedParentMoves;
    u32 numLevelUpMoves;
    u16 numEggMoves;
    u16 i, j;

    numSharedParentMoves = 0;
    for (i = 0; i < 4; i++)
    {
        sHatchedEggMotherMoves[i] = 0;
        sHatchedEggFatherMoves[i] = 0;
        sHatchedEggFinalMoves[i] = 0;
    }
    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
        sHatchedEggEggMoves[i] = 0;
    for (i = 0; i < EGG_LVL_UP_MOVES_ARRAY_COUNT; i++)
        sHatchedEggLevelUpMoves[i] = 0;

    numLevelUpMoves = GetLevelUpMovesBySpecies(GetMonData(egg, MON_DATA_SPECIES), sHatchedEggLevelUpMoves);
    for (i = 0; i < 4; i++)
    {
        sHatchedEggFatherMoves[i] = GetBoxMonData(father, MON_DATA_MOVE1 + i);
        sHatchedEggMotherMoves[i] = GetBoxMonData(mother, MON_DATA_MOVE1 + i);
    }

    numEggMoves = GetEggMoves(egg, sHatchedEggEggMoves);

    for (i = 0; i < 4; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < numEggMoves; j++)
            {
                if (sHatchedEggFatherMoves[i] == sHatchedEggEggMoves[j])
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == 0xffff)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            {
                if (sHatchedEggFatherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01 + j) && CanMonLearnTMHM(egg, j))
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == 0xffff)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                }
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (sHatchedEggFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < 4; j++)
        {
            if (sHatchedEggFatherMoves[i] == sHatchedEggMotherMoves[j] && sHatchedEggFatherMoves[i] != MOVE_NONE)
                sHatchedEggFinalMoves[numSharedParentMoves++] = sHatchedEggFatherMoves[i];
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (sHatchedEggFinalMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numLevelUpMoves; j++)
        {
            if (sHatchedEggLevelUpMoves[j] != MOVE_NONE && sHatchedEggFinalMoves[i] == sHatchedEggLevelUpMoves[j])
            {
                if (GiveMoveToMon(egg, sHatchedEggFinalMoves[i]) == 0xffff)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFinalMoves[i]);
                break;
            }
        }
    }
}

void RemoveEggFromDayCare(struct DayCare *daycare)
{
    daycare->offspringPersonality = 0;
    daycare->stepCounter = 0;
}

void RejectEggFromDayCare(void)
{
    RemoveEggFromDayCare(&gSaveBlock1Ptr->daycare);
}

void AlterEggSpeciesWithIncenseItem(u16 *species, struct DayCare *daycare)
{
    u16 motherItem, fatherItem;
    if (*species == SPECIES_WYNAUT || *species == SPECIES_AZURILL)
    {
        motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
        fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);
        if (*species == SPECIES_WYNAUT && motherItem != ITEM_LAX_INCENSE && fatherItem != ITEM_LAX_INCENSE)
        {
            *species = SPECIES_WOBBUFFET;
        }

        if (*species == SPECIES_AZURILL && motherItem != ITEM_SEA_INCENSE && fatherItem != ITEM_SEA_INCENSE)
        {
            *species = SPECIES_MARILL;
        }
    }
}

void GiveVoltTackleIfLightBall(struct Pokemon *mon, struct DayCare *daycare)
{
    u32 motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
    u32 fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);

    if (motherItem == ITEM_LIGHT_BALL || fatherItem == ITEM_LIGHT_BALL)
    {
        if (GiveMoveToMon(mon, MOVE_VOLT_TACKLE) == 0xFFFF)
            DeleteFirstMoveAndGiveMoveToMon(mon, MOVE_VOLT_TACKLE);
    }
}

u16 DetermineEggSpeciesAndParentSlots(struct DayCare *daycare, u8 *parentSlots)
{
    u16 i;
    u16 species[2];
    u16 eggSpecies;

    // Determine which of the daycare mons is the mother and father of the egg.
    // The 0th index of the parentSlots array is considered the mother slot, and the
    // 1st index is the father slot.
    for (i = 0; i < 2; i++)
    {
        species[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES);
        if (species[i] == SPECIES_DITTO)
        {
            parentSlots[0] = i ^ 1;
            parentSlots[1] = i;
        }
        else if (GetBoxMonGender(&daycare->mons[i].mon) == MON_FEMALE)
        {
            parentSlots[0] = i;
            parentSlots[1] = i ^ 1;
        }
    }

    eggSpecies = GetEggSpecies(species[parentSlots[0]]);
    if (eggSpecies == SPECIES_NIDORAN_F && daycare->offspringPersonality & 0x8000)
    {
        eggSpecies = SPECIES_NIDORAN_M;
    }
    if (eggSpecies == SPECIES_ILLUMISE && daycare->offspringPersonality & 0x8000)
    {
        eggSpecies = SPECIES_VOLBEAT;
    }

    // Make Ditto the "mother" slot if the other daycare mon is male.
    if (species[parentSlots[1]] == SPECIES_DITTO && GetBoxMonGender(&daycare->mons[parentSlots[0]].mon) != MON_FEMALE)
    {
        u8 temp = parentSlots[1];
        parentSlots[1] = parentSlots[0];
        parentSlots[0] = temp;
    }

    return eggSpecies;
}

void _GiveEggFromDaycare(struct DayCare *daycare) // give_egg
{
    struct Pokemon egg;
    u16 species;
    u8 parentSlots[2]; // 0th index is "mother" daycare slot, 1st is "father"
    bool8 isEgg;

    species = DetermineEggSpeciesAndParentSlots(daycare, parentSlots);
    AlterEggSpeciesWithIncenseItem(&species, daycare);
    SetInitialEggData(&egg, species, daycare);
    InheritIVs(&egg, daycare);
    BuildEggMoveset(&egg, &daycare->mons[parentSlots[1]].mon, &daycare->mons[parentSlots[0]].mon);

    if (species == SPECIES_PICHU)
        GiveVoltTackleIfLightBall(&egg, daycare);

    isEgg = TRUE;
    SetMonData(&egg, MON_DATA_IS_EGG, &isEgg);
    gPlayerParty[PARTY_SIZE - 1] = egg;
    CompactPartySlots();
    CalculatePlayerPartyCount();
    RemoveEggFromDayCare(daycare);
}

void CreateEgg(struct Pokemon *mon, u16 species, bool8 setHotSpringsLocation)
{
    u8 metLevel;
    u16 ball;
    u8 language;
    u8 metLocation;
    u8 isEgg;

    CreateMon(mon, species, EGG_HATCH_LEVEL, 0x20, FALSE, 0, FALSE, 0);
    metLevel = 0;
    ball = ITEM_POKE_BALL;
    language = LANGUAGE_JAPANESE;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    SetMonData(mon, MON_DATA_NICKNAME, sJapaneseEggNickname);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    SetMonData(mon, MON_DATA_MET_LEVEL, &metLevel);
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    if (setHotSpringsLocation)
    {
        metLocation = 253; // hot springs; see PokemonSummaryScreen_PrintEggTrainerMemo
        SetMonData(mon, MON_DATA_MET_LOCATION, &metLocation);
    }

    isEgg = TRUE;
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);
}

void SetInitialEggData(struct Pokemon *mon, u16 species, struct DayCare *daycare)
{
    u32 personality;
    u16 ball;
    u8 metLevel;
    u8 language;

    personality = daycare->offspringPersonality;
    CreateMon(mon, species, EGG_HATCH_LEVEL, 0x20, TRUE, personality, FALSE, 0);
    metLevel = 0;
    ball = ITEM_POKE_BALL;
    language = LANGUAGE_JAPANESE;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    SetMonData(mon, MON_DATA_NICKNAME, sJapaneseEggNickname);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &gBaseStats[species].eggCycles);
    SetMonData(mon, MON_DATA_MET_LEVEL, &metLevel);
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
}

void GiveEggFromDaycare(void)
{
    _GiveEggFromDaycare(&gSaveBlock1Ptr->daycare);
}
