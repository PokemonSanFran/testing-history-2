#include "global.h"
#include "gba/flash_internal.h"
#include "save.h"
#include "game_stat.h"

extern struct SaveSectionOffsets gSaveSectionOffsets[0xE];
extern struct SaveSectionLocation gRamSaveSectionLocations[0xE];
extern void *gUnknown_03005D94;
extern u8 gDecompressionBuffer[];
extern u32 gFlashMemoryPresent;
extern u16 gUnknown_03006294;

extern void DoSaveFailedScreen(u8); // save_failed_screen
extern void LoadSerializedGame(void); // load_save
extern bool32 ProgramFlashSectorAndVerify(u8 sector, u8 *data);
extern void ReadFlash(u8 sector, u32 arg1, void* data, u32 size);

// iwram common
u16 gLastWrittenSector;
u32 gLastSaveCounter;
u16 gLastKnownGoodSector;
u32 gDamagedSaveSectors;
u32 gSaveCounter;
struct SaveSection *gFastSaveSection;
u16 gUnknown_03006208;
u16 gSaveUnusedVar;
u16 gUnknown_03006210;
void (*gGameContinueCallback)(void);

EWRAM_DATA struct SaveSection gSaveDataBuffer = {0};

void ClearSaveData(void)
{
    u16 i;

    for (i = 0; i < NUM_SECTORS_PER_SLOT; i++)
    {
        EraseFlashSector(i);
        EraseFlashSector(i + NUM_SECTORS_PER_SLOT); // clear slot 2.
    }
}

void ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gLastWrittenSector = 0;
    gDamagedSaveSectors = 0;
}

bool32 SetDamagedSectorBits(u8 op, u8 bit)
{
    bool32 retVal = FALSE;

    switch (op)
    {
    case ENABLE:
        gDamagedSaveSectors |= (1 << bit);
        break;
    case DISABLE:
        gDamagedSaveSectors &= ~(1 << bit);
        break;
    case CHECK: // unused
        if (gDamagedSaveSectors & (1 << bit))
            retVal = TRUE;
        break;
    }

    return retVal;
}

u8 save_write_to_flash(u16 a1, const struct SaveSectionLocation *location)
{
    u32 retVal;
    u16 i;

    gFastSaveSection = &gSaveDataBuffer;

    if (a1 != 0xFFFF) // for link
    {
        retVal = HandleWriteSector(a1, location);
    }
    else
    {
        gLastKnownGoodSector = gLastWrittenSector; // backup the current written sector before attempting to write.
        gLastSaveCounter = gSaveCounter;
        gLastWrittenSector++;
        gLastWrittenSector = gLastWrittenSector % 0xE; // array count save sector locations
        gSaveCounter++;
        retVal = 1;

        for (i = 0; i < 0xE; i++)
            HandleWriteSector(i, location);

        if (gDamagedSaveSectors != 0) // skip the damaged sector.
        {
            retVal = 0xFF;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }

    return retVal;
}

u8 HandleWriteSector(u16 a1, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;

    sector = a1 + gLastWrittenSector;
    sector %= 0xE;
    sector += 0xE * (gSaveCounter % 2);

    data = location[a1].data;
    size = location[a1].size;

    // clear save section.
    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = a1;
    gFastSaveSection->security = UNKNOWN_CHECK_VALUE;
    gFastSaveSection->counter = gSaveCounter;

    for (i = 0; i < size; i++)
        gFastSaveSection->data[i] = data[i];

    gFastSaveSection->checksum = CalculateChecksum(data, size);
    return TryWriteSector(sector, gFastSaveSection->data);
}

u8 HandleWriteSectorNBytes(u8 sector, u8 *data, u16 size)
{
    u16 i;
    struct SaveSection *section = &gSaveDataBuffer;

    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)section)[i] = 0;

    section->security = UNKNOWN_CHECK_VALUE;

    for (i = 0; i < size; i++)
        section->data[i] = data[i];

    section->id = CalculateChecksum(data, size); // though this appears to be incorrect, it might be some sector checksum instead of a whole save checksum and only appears to be relevent to HOF data, if used.
    return TryWriteSector(sector, section->data);
}

u8 TryWriteSector(u8 sector, u8 *data)
{
    if (ProgramFlashSectorAndVerify(sector, data) != 0) // is damaged?
    {
        SetDamagedSectorBits(ENABLE, sector); // set damaged sector bits.
        return 0xFF;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector); // unset damaged sector bits. it's safe now.
        return 1;
    }
}

u32 RestoreSaveBackupVarsAndIncrement(const struct SaveSectionLocation *location) // location is unused
{
    gFastSaveSection = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gLastWrittenSector++;
    gLastWrittenSector = gLastWrittenSector % 0xE;
    gSaveCounter++;
    gUnknown_03006208 = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

u32 RestoreSaveBackupVars(const struct SaveSectionLocation *location) // only ever called once, and gSaveBlock2 is passed to this function. location is unused
{
    gFastSaveSection = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gUnknown_03006208 = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

u8 sub_81529D4(u16 a1, const struct SaveSectionLocation *location)
{
    u8 retVal;

    if (gUnknown_03006208 < a1 - 1)
    {
        retVal = 1;
        HandleWriteSector(gUnknown_03006208, location);
        gUnknown_03006208++;
        if (gDamagedSaveSectors)
        {
            retVal = 0xFF;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }
    else
    {
        retVal = 0xFF;
    }

    return retVal;
}

u8 sub_8152A34(u16 a1, const struct SaveSectionLocation *location)
{
    u8 retVal = 1;

    ClearSaveData_2(a1 - 1, location);

    if (gDamagedSaveSectors)
    {
        retVal = 0xFF;
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
    }
    return retVal;
}

u8 ClearSaveData_2(u16 a1, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;
    u8 status;

    sector = a1 + gLastWrittenSector;
    sector %= 0xE;
    sector += 0xE * (gSaveCounter % 2);

    data = location[a1].data;
    size = location[a1].size;

    // clear temp save section.
    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = a1;
    gFastSaveSection->security = UNKNOWN_CHECK_VALUE;
    gFastSaveSection->counter = gSaveCounter;

    // set temp section's data.
    for (i = 0; i < size; i++)
        gFastSaveSection->data[i] = data[i];

    // calculate checksum.
    gFastSaveSection->checksum = CalculateChecksum(data, size);

    EraseFlashSector(sector);

    status = 1;

    for (i = 0; i < sizeof(struct UnkSaveSection); i++)
    {
        if (ProgramFlashByte(sector, i, ((u8 *)gFastSaveSection)[i]))
        {
            status = 0xFF;
            break;
        }
    }

    if (status == 0xFF)
    {
        SetDamagedSectorBits(ENABLE, sector);
        return 0xFF;
    }
    else
    {
        status = 1;

        for (i = 0; i < 7; i++)
        {
            if (ProgramFlashByte(sector, 0xFF9 + i, ((u8 *)gFastSaveSection)[0xFF9 + i]))
            {
                status = 0xFF;
                break;
            }
        }

        if (status == 0xFF)
        {
            SetDamagedSectorBits(ENABLE, sector);
            return 0xFF;
        }
        else
        {
            SetDamagedSectorBits(DISABLE, sector);
            return 1;
        }
    }
}

u8 sav12_xor_get(u16 a1, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = a1 + gLastWrittenSector; // no sub 1?
    sector %= 0xE;
    sector += 0xE * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), 0x25))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return 0xFF;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return 1;
    }
}

u8 sub_8152CAC(u16 a1, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = a1 + gLastWrittenSector - 1;
    sector %= 0xE;
    sector += 0xE * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), ((u8 *)gFastSaveSection)[sizeof(struct UnkSaveSection)]))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return 0xFF;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return 1;
    }
}

u8 sub_8152D44(u16 a1, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = a1 + gLastWrittenSector - 1; // no sub 1?
    sector %= 0xE;
    sector += 0xE * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), 0x25))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return 0xFF;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return 1;
    }
}

u8 sub_8152DD0(u16 a1, const struct SaveSectionLocation *location)
{
    u8 retVal;
    gFastSaveSection = &gSaveDataBuffer;
    if (a1 != 0xFFFF)
    {
        retVal = 0xFF;
    }
    else
    {
        retVal = GetSaveValidStatus(location);
        sub_8152E10(0xFFFF, location);
    }

    return retVal;
}

u8 sub_8152E10(u16 a1, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u16 v3 = 0xE * (gSaveCounter % 2);
    u16 id;

    for (i = 0; i < 0xE; i++)
    {
        DoReadFlashWholeSection(i + v3, gFastSaveSection);
        id = gFastSaveSection->id;
        if (id == 0)
            gLastWrittenSector = i;
        checksum = CalculateChecksum(gFastSaveSection->data, location[id].size);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE
         && gFastSaveSection->checksum == checksum)
        {
            u16 j;
            for (j = 0; j < location[id].size; j++)
                ((u8 *)location[id].data)[j] = gFastSaveSection->data[j];
        }
    }

    return 1;
}

u8 GetSaveValidStatus(const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u32 saveSlot1Counter = 0;
    u32 saveSlot2Counter = 0;
    u32 slotCheckField = 0;
    bool8 securityPassed = FALSE;
    u8 saveSlot1Status;
    u8 saveSlot2Status;

    // check save slot 1.
    for (i = 0; i < 0xE; i++)
    {
        DoReadFlashWholeSection(i, gFastSaveSection);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, location[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                saveSlot1Counter = gFastSaveSection->counter;
                slotCheckField |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot1Status = 1;
        else
            saveSlot1Status = 255;
    }
    else
    {
        saveSlot1Status = 0;
    }

    slotCheckField = 0;
    securityPassed = FALSE;

    // check save slot 2.
    for (i = 0; i < 0xE; i++)
    {
        DoReadFlashWholeSection(i + 0xE, gFastSaveSection);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, location[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                saveSlot2Counter = gFastSaveSection->counter;
                slotCheckField |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot2Status = 1;
        else
            saveSlot2Status = 255;
    }
    else
    {
        saveSlot2Status = 0;
    }

    if (saveSlot1Status == 1 && saveSlot2Status == 1)
    {
        if ((saveSlot1Counter == -1 && saveSlot2Counter == 0) || (saveSlot1Counter == 0 && saveSlot2Counter == -1))
        {
            if ((unsigned)(saveSlot1Counter + 1) < (unsigned)(saveSlot2Counter + 1))
            {
                gSaveCounter = saveSlot2Counter;
            }
            else
            {
                gSaveCounter = saveSlot1Counter;
            }
        }
        else
        {
            if (saveSlot1Counter < saveSlot2Counter)
            {
                gSaveCounter = saveSlot2Counter;
            }
            else
            {
                gSaveCounter = saveSlot1Counter;
            }
        }
        return 1;
    }

    if (saveSlot1Status == 1)
    {
        gSaveCounter = saveSlot1Counter;
        if (saveSlot2Status == 255)
            return 255;
        return 1;
    }

    if (saveSlot2Status == 1)
    {
        gSaveCounter = saveSlot2Counter;
        if (saveSlot1Status == 255)
            return 255;
        return 1;
    }

    if (saveSlot1Status == 0 && saveSlot2Status == 0)
    {
        gSaveCounter = 0;
        gLastWrittenSector = 0;
        return 0;
    }

    gSaveCounter = 0;
    gLastWrittenSector = 0;
    return 2;
}

u8 sub_81530DC(u8 a1, u8 *data, u16 size)
{
    u16 i;
    struct SaveSection *section = &gSaveDataBuffer;
    DoReadFlashWholeSection(a1, section);
    if (section->security == UNKNOWN_CHECK_VALUE)
    {
        u16 checksum = CalculateChecksum(section->data, size);
        if (section->id == checksum)
        {
            for (i = 0; i < size; i++)
                data[i] = section->data[i];
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
}

u8 DoReadFlashWholeSection(u8 sector, struct SaveSection *section)
{
    ReadFlash(sector, 0, section->data, sizeof(struct SaveSection));
    return 1;
}

u16 CalculateChecksum(void *data, u16 size)
{
    u16 i;
    u32 checksum = 0;

    for (i = 0; i < (size / 4); i++)
        checksum += *((u32 *)data)++;

    return ((checksum >> 16) + checksum);
}

#ifdef NONMATCHING
// the initial allocation of the pointer and toAdd variable doesnt match up with the original function. however, forcing it is impossible since gRamSaveSectionLocations is loaded first.
void UpdateSaveAddresses(void)
{
    int i = 0;
    gRamSaveSectionLocations[i].data = gSaveBlock2Ptr + gSaveSectionOffsets[0].toAdd;
    gRamSaveSectionLocations[i].size = gSaveSectionOffsets[0].size;

    for(i = 1; i < 5; i++)
    {
        gRamSaveSectionLocations[i].data = gSaveBlock1Ptr + gSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = gSaveSectionOffsets[i].size;
    }

    for(i = 5; i < 14; i++)
    {
        gRamSaveSectionLocations[i].data = gUnknown_03005D94 + gSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = gSaveSectionOffsets[i].size;
    }
}
#else
__attribute__((naked))
void UpdateSaveAddresses(void)
{
    asm(".syntax unified\n\
    push {r4,r5,lr}\n\
    ldr r3, =gRamSaveSectionLocations\n\
    ldr r0, =gSaveBlock2Ptr\n\
    ldr r2, =gSaveSectionOffsets\n\
    ldrh r1, [r2]\n\
    ldr r0, [r0]\n\
    adds r0, r1\n\
    str r0, [r3]\n\
    ldrh r0, [r2, 0x2]\n\
    strh r0, [r3, 0x4]\n\
    ldr r5, =gSaveBlock1Ptr\n\
    adds r3, 0x8\n\
    adds r2, 0x4\n\
    movs r4, 0x3\n\
_081531AC:\n\
    ldrh r0, [r2]\n\
    ldr r1, [r5]\n\
    adds r1, r0\n\
    str r1, [r3]\n\
    ldrh r0, [r2, 0x2]\n\
    strh r0, [r3, 0x4]\n\
    adds r3, 0x8\n\
    adds r2, 0x4\n\
    subs r4, 0x1\n\
    cmp r4, 0\n\
    bge _081531AC\n\
    movs r4, 0x5\n\
    ldr r1, =gRamSaveSectionLocations\n\
    ldr r5, =gUnknown_03005D94\n\
    ldr r0, =gSaveSectionOffsets\n\
    adds r3, r1, 0\n\
    adds r3, 0x28\n\
    adds r2, r0, 0\n\
    adds r2, 0x14\n\
_081531D2:\n\
    ldrh r0, [r2]\n\
    ldr r1, [r5]\n\
    adds r1, r0\n\
    str r1, [r3]\n\
    ldrh r0, [r2, 0x2]\n\
    strh r0, [r3, 0x4]\n\
    adds r3, 0x8\n\
    adds r2, 0x4\n\
    adds r4, 0x1\n\
    cmp r4, 0xD\n\
    ble _081531D2\n\
    pop {r4,r5}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif

extern u32 GetGameStat(u8 index); // rom4
extern void IncrementGameStat(u8 index); // rom4
extern void SaveSerializedGame(void); // load_save
extern u32 gUnknown_0203CF5C;

u8 HandleSavingData(u8 saveType)
{
    u8 i;
    u32 backupVar = gUnknown_0203CF5C;
    u8 *tempAddr;

    gUnknown_0203CF5C = 0;
    UpdateSaveAddresses();
    switch (saveType)
    {
    case HOF_DELETE_SAVE: // deletes HOF before overwriting HOF completely. unused
        for (i = 0xE * 2 + 0; i < 32; i++)
            EraseFlashSector(i);
    case HOF_SAVE: // hall of fame.
        if (GetGameStat(GAME_STAT_ENTERED_HOF) < 999)
            IncrementGameStat(GAME_STAT_ENTERED_HOF);
        SaveSerializedGame();
        save_write_to_flash(0xFFFF, gRamSaveSectionLocations);
        tempAddr = (u8 *)0x201C000; // FIXME: make this a label.
        HandleWriteSectorNBytes(0x1C, tempAddr, 0xF80);
        HandleWriteSectorNBytes(0x1D, tempAddr + 0xF80, 0xF80);
        break;
    case NORMAL_SAVE: // normal save. also called by overwriting your own save.
    default:
        SaveSerializedGame();
        save_write_to_flash(0xFFFF, gRamSaveSectionLocations);
        break;
    case LINK_SAVE: // _081532C4
    case LINK2_SAVE:
        SaveSerializedGame();
        for(i = 0; i < 5; i++)
            ClearSaveData_2(i, gRamSaveSectionLocations);
        for(i = 0; i < 5; i++)
            sav12_xor_get(i, gRamSaveSectionLocations);
        break;
    // support for Ereader was removed in Emerald.
    /*
    case EREADER_SAVE: // used in mossdeep "game corner" before/after battling old man e-reader trainer
        SaveSerializedGame();
        save_write_to_flash(0, gRamSaveSectionLocations);
        break;
    */
    case DIFFERENT_FILE_SAVE:
        for (i = (0xE * 2 + 0); i < 32; i++)
            EraseFlashSector(i); // erase HOF.
        SaveSerializedGame();
        save_write_to_flash(0xFFFF, gRamSaveSectionLocations);
        break;
    }
    gUnknown_0203CF5C = backupVar;
    return 0;
}

u8 TrySavingData(u8 saveType) // TrySave
{
    if(gFlashMemoryPresent == TRUE)
    {
        HandleSavingData(saveType);
        if(gDamagedSaveSectors)
            DoSaveFailedScreen(saveType);
        else
            goto OK; // really?
    }
    gUnknown_03006294 = 0xFF;
    return 0xFF;

OK:
    gUnknown_03006294 = 1;
    return 1;
}

u8 sub_8153380(void) // trade.s save
{
    if (gFlashMemoryPresent != TRUE)
        return 1;
    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVarsAndIncrement(gRamSaveSectionLocations);
    return 0;
}

bool8 sub_81533AC(void) // trade.s save
{
    u8 retVal = sub_81529D4(0xE, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(0);
    if (retVal == 0xFF)
        return 1;
    else
        return 0;
}

u8 sub_81533E0(void) // trade.s save
{
    sub_8152A34(0xE, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(0);
    return 0;
}

u8 sub_8153408(void) // trade.s save
{
    sub_8152CAC(0xE, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(0);
    return 0;
}

u8 sub_8153430(void)
{
    if (gFlashMemoryPresent != TRUE)
        return 1;

    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVars(gRamSaveSectionLocations);
    sub_8152A34(gUnknown_03006208 + 1, gRamSaveSectionLocations);
    return 0;
}

bool8 sub_8153474(void)
{
    u8 retVal = FALSE;
    u16 val = ++gUnknown_03006208;
    if (val <= 4)
    {
        sub_8152A34(gUnknown_03006208 + 1, gRamSaveSectionLocations);
        sub_8152D44(val, gRamSaveSectionLocations);
    }
    else
    {
        sub_8152D44(val, gRamSaveSectionLocations);
        retVal = TRUE;
    }
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(1);
    return retVal;
}

u8 sub_81534D0(u8 a1)
{
    u8 result;

    if (gFlashMemoryPresent != TRUE)
    {
        gUnknown_03006210 = 4;
        return 0xFF;
    }

    UpdateSaveAddresses();
    switch (a1)
    {
    case 0:
    default:
        result = sub_8152DD0(0xFFFF, gRamSaveSectionLocations);
        LoadSerializedGame();
        gUnknown_03006210 = result;
        gGameContinueCallback = 0;
        break;
    case 3:
        result = sub_81530DC(0x1C, gDecompressionBuffer, 0xF80);
        if(result == 1)
            result = sub_81530DC(0x1D, gDecompressionBuffer + 0xF80, 0xF80);
        break;
    }

    return result;
}

u16 sub_815355C(void)
{
    u16 i, v3;
    struct SaveSection* savSection;

    savSection = gFastSaveSection = &gSaveDataBuffer;
    if (gFlashMemoryPresent != 1)
        return 0;
    UpdateSaveAddresses();
    GetSaveValidStatus(gRamSaveSectionLocations);
    v3 = 0xE * (gSaveCounter % 2);
    for (i = 0; i < 14; i++)
    {
        DoReadFlashWholeSection(i + v3, gFastSaveSection);
        if (gFastSaveSection->id == 0)
            return savSection->data[10] +
                   savSection->data[11] +
                   savSection->data[12] +
                   savSection->data[13];
    }
    return 0;
}

u32 sub_81535DC(u8 sector, u8* dst)
{
    s32 i;
    s32 size;
    u8* savData;

    if (sector != 30 && sector != 31)
        return 0xFF;
    ReadFlash(sector, 0, &gSaveDataBuffer, sizeof(struct SaveSection));
    if (*(u32*)(&gSaveDataBuffer.data[0]) != 0xB39D)
        return 0xFF;
    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        dst[i] = savData[i];
    return 1;
}

u32 sub_8153634(u8 sector, u8* src)
{
    s32 i;
    s32 size;
    u8* savData;
    void* savDataBuffer;

    if (sector != 30 && sector != 31)
        return 0xFF;
    savDataBuffer = &gSaveDataBuffer;
    *(u32*)(savDataBuffer) = 0xB39D;

    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        savData[i] = src[i];
    if (ProgramFlashSectorAndVerify(sector, savDataBuffer) != 0)
        return 0xFF;
    return 1;
}
