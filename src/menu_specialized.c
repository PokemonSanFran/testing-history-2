#include "global.h"
#include "alloc.h"
#include "battle_main.h"
#include "contest_effect.h"
#include "gpu_regs.h"
#include "menu.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_specialized.h"
#include "move_relearner.h"
#include "palette.h"
#include "player_pc.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "gba/io_reg.h"

EWRAM_DATA static u8 sUnknown_0203CF48[3] = {0};
EWRAM_DATA static struct ListMenuItem *sUnknown_0203CF4C = NULL;

static void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void sub_81D24A4(struct UnknownStruct_81D1ED4 *a0);
static void sub_81D2634(struct UnknownStruct_81D1ED4 *a0);
static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void nullsub_79(void);

static const struct WindowTemplate sUnknown_086253E8[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x8
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 1,
        .width = 8,
        .height = 18,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 11,
        .height = 8,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    }
};

static const u8 sUnknown_08625400[] =
{
    1, 2, 3
};

static const u8 sEmptyItemName[] = _("");

static const struct ScanlineEffectParams sUnknown_08625404 =
{
    .dmaDest = (void*)REG_ADDR_WIN0H,
    .dmaControl = SCANLINE_EFFECT_DMACNT_32BIT,
    .initState = 1,
};

static const u8 sUnknown_08625410[] =
{
    4,
    5,
    6,
    7,
    8,
    9, 9,
    10, 10,
    0xB, 0xB,
    0xC, 0xC,
    0xD, 0xD,
    0xD, 0xD,
    0xE, 0xE, 0xE, 0xE,
    0xF, 0xF, 0xF, 0xF,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
    0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15,
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A,
    0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
    0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
    0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D,
    0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x23
};


static const struct WindowTemplate sMoveRelearnerWindowTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0xA
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0xCA
    },
    {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 1,
        .width = 10,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0x18A
    },
    {
        .bg = 1,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x202
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 8,
        .width = 5,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x25A
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sMoveRelearnerYesNoMenuTemplate =
{
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 8,
    .width = 5,
    .height = 4,
    .paletteNum = 0xF,
    .baseBlock = 0x25A
};


static const struct ListMenuTemplate sMoveRelearnerMovesListTemplate =
{
    .items = NULL,
    .moveCursorFunc = MoveRelearnerCursorCallback,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 2,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

bool8 sub_81D1C44(u8 count)
{
    u8 i;

    sUnknown_0203CF4C = Alloc(count * sizeof(*sUnknown_0203CF4C) + sizeof(*sUnknown_0203CF4C));
    if (sUnknown_0203CF4C == NULL)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sUnknown_0203CF48); i++)
        sUnknown_0203CF48[i] = 0xFF;

    return TRUE;
}

u8 sub_81D1C84(u8 a0)
{
    if (sUnknown_0203CF48[a0] == 0xFF)
    {
        if (a0 == 2)
        {
            struct WindowTemplate template = sUnknown_086253E8[2];
            template.width = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            sUnknown_0203CF48[2] = AddWindow(&template);
        }
        else
        {
            sUnknown_0203CF48[a0] = AddWindow(&sUnknown_086253E8[a0]);
        }
        SetStandardWindowBorderStyle(sUnknown_0203CF48[a0], 0);
    }
    return sUnknown_0203CF48[a0];
}

void sub_81D1D04(u8 a0)
{
    ClearStdWindowAndFrameToTransparent(sUnknown_0203CF48[a0], 0);
    ClearWindowTilemap(sUnknown_0203CF48[a0]);
    RemoveWindow(sUnknown_0203CF48[a0]);
    sUnknown_0203CF48[a0] = 0xFF;
}

static u8 sub_81D1D34(u8 a0)
{
    return sUnknown_0203CF48[a0];
}

static void sub_81D1D44(u8 windowId, s32 itemId, u8 y)
{
    u8 buffer[30];
    u16 length;

	if (itemId == LIST_CANCEL)
        return;

    StringCopy(buffer, gSaveBlock1Ptr->mail[6 + itemId].playerName);
    sub_81DB52C(buffer);
    length = StringLength(buffer);
    if (length <= 5)
        ConvertInternationalString(buffer, LANGUAGE_JAPANESE);
    AddTextPrinterParameterized4(windowId, 1, 8, y, 0, 0, sUnknown_08625400, -1, buffer);
}

u8 sub_81D1DC0(struct PlayerPCItemPageStruct *page)
{
    u16 i;
    for (i = 0; i < page->count; i++)
    {
        sUnknown_0203CF4C[i].name = sEmptyItemName;
        sUnknown_0203CF4C[i].id = i;
    }

    sUnknown_0203CF4C[i].name = gText_Cancel2;
    sUnknown_0203CF4C[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = sUnknown_0203CF4C;
    gMultiuseListMenuTemplate.totalItems = page->count + 1;
    gMultiuseListMenuTemplate.windowId = sUnknown_0203CF48[1];
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.maxShowed = 8;
    gMultiuseListMenuTemplate.upText_Y = 9;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = sub_81D1E7C;
    gMultiuseListMenuTemplate.itemPrintFunc = sub_81D1D44;
    gMultiuseListMenuTemplate.fontId = 1;
    gMultiuseListMenuTemplate.cursorKind = 0;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    return ListMenuInit(&gMultiuseListMenuTemplate, page->itemsAbove, page->cursorPos);
}

static void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
}

void sub_81D1E90(struct PlayerPCItemPageStruct *page)
{
    page->scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(2, 0xC8, 12, 0x94, page->count - page->pageItems + 1, 0x6E, 0x6E, &page->itemsAbove);
}

void sub_81D1EC0(void)
{
    Free(sUnknown_0203CF4C);
}

void sub_81D1ED4(struct UnknownStruct_81D1ED4 *a0)
{
    u8 i, j;

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 10; i++)
        {
            a0->unk64[i][j].unk0 = 0;
            a0->unk64[i][j].unk2 = 0;
        }
        for (i = 0; i < 4; i++)
        {
            a0->unk0[i][j] = 0;
            a0->unk14[i][j].unk0 = 0x9B;
            a0->unk14[i][j].unk2 = 0x5B;
        }

        a0->unk12C[j].unk0 = 0;
        a0->unk12C[j].unk2 = 0;
    }

    a0->unk354 = 0;
    a0->unk352 = 0;
}

void sub_81D1F84(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 *arg1, struct UnknownSubStruct_81D1ED4 *arg2)
{
    u16 i, j;
    s32 r5, r6;

    for (i = 0; i < 5; i++)
    {
        r5 = arg1[i].unk0 << 8;
        r6 = ((arg2[i].unk0 - arg1[i].unk0) << 8) / 10;
        for (j = 0; j < 9; j++)
        {
            arg0->unk64[j][i].unk0 = (r5 >> 8) + ((r5 >> 7) & 1);
            r5 += r6;
        }
        arg0->unk64[j][i].unk0 = arg2[i].unk0;

        r5 = arg1[i].unk2 << 8;
        r6 = ((arg2[i].unk2 - arg1[i].unk2) << 8) / 10;
        for (j = 0; j < 9; j++)
        {
            arg0->unk64[j][i].unk2 = (r5 >> 8) + ((r5 >> 7) & 1);
            r5 += r6;
        }
        arg0->unk64[j][i].unk2 = arg2[i].unk2;
    }

    arg0->unk352 = 0;
}

bool32 sub_81D2074(struct UnknownStruct_81D1ED4 *a0)
{
    if (a0->unk352 < 10)
    {
        sub_81D2230(a0);
        return (++a0->unk352 != 10);
    }
    else
    {
        return FALSE;
    }
}

void sub_81D20AC(struct UnknownStruct_81D1ED4 *a0)
{
    a0->unk355 = 0;
}

bool8 sub_81D20BC(struct UnknownStruct_81D1ED4 *arg0)
{
    struct ScanlineEffectParams params;

    switch (arg0->unk355)
    {
    case 0:
        ScanlineEffect_Clear();
        arg0->unk355++;
        return TRUE;
    case 1:
        params = sUnknown_08625404;
        ScanlineEffect_SetParams(params);
        arg0->unk355++;
        return FALSE;
    default:
        return FALSE;
    }
}

void sub_81D2108(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i;

    if (arg0->unk354 == 0)
        return;

    sub_81D24A4(arg0);
    sub_81D2634(arg0);

    for (i = 0; i < 66; i++)
    {
        gScanlineEffectRegBuffers[1][(i + 55) * 2]     = gScanlineEffectRegBuffers[0][(i + 55) * 2]     = (arg0->unk140[i][0] << 8) | (arg0->unk140[i][1]);
        gScanlineEffectRegBuffers[1][(i + 55) * 2 + 1] = gScanlineEffectRegBuffers[0][(i + 55) * 2 + 1] = (arg0->unk248[i][0] << 8) | (arg0->unk248[i][1]);
    }

    arg0->unk354 = 0;
}

void sub_81D21DC(u8 bg)
{
    u32 flags;

    if (bg > 3)
        bg = 0;

    // Unset the WINOUT flag for the bg.
    flags = (WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ) & ~(1 << bg);

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 0xF0));
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 0x9B));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0x38, 0x79));
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0x38, 0x79));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, flags);
}

void sub_81D2230(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i;
    for (i = 0; i < 5; i++)
        arg0->unk12C[i] = arg0->unk64[arg0->unk352][i];

    arg0->unk354 = 1;
}

/* TODO
static void sub_81D2278(struct UnknownStruct_81D1ED4 *arg0, u16 arg1[66][2], struct UnknownSubStruct_81D1ED4 *arg2, struct UnknownSubStruct_81D1ED4 *arg3, u8 arg4, u16 arg5[66][2])
{
    s32 var_2C = 0;
    u16 r8;
    s32 r10, r4, r2, r0, r1, var_30;

    if (arg2->unk2 < arg3->unk2)
    {
        r2 = arg2->unk2;
        r10 = arg2->unk2;
        r0 = arg3->unk2;
        r1 = arg2->unk0;
        r4 = r1 << 10;
        var_30 = arg3->unk0;
    }
    else
    {
        r0 = arg2->unk0;
        r10 = arg3->unk2;
        r1 = arg3->unk0;
        r4 = r1 << 10;
        var_30 = arg2->unk0;
        r2 = arg3->unk2;
    }
    r8 = r0 - r2;
    if (r8 != 0)
        var_2C = ((var_30 - r1) << 10) / r8;

    r8++;
    if (arg5 == NULL)
    {

    }
}
*/
NAKED
static void sub_81D2278(struct UnknownStruct_81D1ED4 *arg0, u16 arg1[66][2], struct UnknownSubStruct_81D1ED4 *arg2, struct UnknownSubStruct_81D1ED4 *arg3, u8 arg4, u16 arg5[66][2])
{
    asm_unified("\n\
                push {r4-r7,lr}\n\
                mov r7, r10\n\
                mov r6, r9\n\
                mov r5, r8\n\
                push {r5-r7}\n\
                sub sp, 0x18\n\
                str r0, [sp]\n\
                adds r6, r1, 0\n\
                adds r5, r2, 0\n\
                str r3, [sp, 0x4]\n\
                ldr r0, [sp, 0x38]\n\
                ldr r7, [sp, 0x3C]\n\
                lsls r0, 24\n\
                lsrs r0, 24\n\
                mov r9, r0\n\
                movs r0, 0\n\
                str r0, [sp, 0xC]\n\
                ldrh r0, [r5, 0x2]\n\
                ldrh r1, [r3, 0x2]\n\
                cmp r0, r1\n\
                bcs _081D22B2\n\
                adds r2, r0, 0\n\
                mov r10, r2\n\
                ldrh r0, [r3, 0x2]\n\
                ldrh r1, [r5]\n\
                lsls r4, r1, 10\n\
                ldrh r3, [r3]\n\
                str r3, [sp, 0x8]\n\
                b _081D22C6\n\
            _081D22B2:\n\
                ldrh r0, [r5, 0x2]\n\
                ldr r1, [sp, 0x4]\n\
                ldrh r1, [r1, 0x2]\n\
                mov r10, r1\n\
                ldr r2, [sp, 0x4]\n\
                ldrh r1, [r2]\n\
                lsls r4, r1, 10\n\
                ldrh r3, [r5]\n\
                str r3, [sp, 0x8]\n\
                mov r2, r10\n\
            _081D22C6:\n\
                subs r0, r2\n\
                lsls r0, 16\n\
                lsrs r0, 16\n\
                mov r8, r0\n\
                cmp r0, 0\n\
                beq _081D22DE\n\
                subs r0, r3, r1\n\
                lsls r0, 10\n\
                mov r1, r8\n\
                bl __divsi3\n\
                str r0, [sp, 0xC]\n\
            _081D22DE:\n\
                mov r0, r8\n\
                adds r0, 0x1\n\
                lsls r0, 16\n\
                lsrs r0, 16\n\
                mov r8, r0\n\
                cmp r7, 0\n\
                bne _081D2328\n\
                mov r0, r10\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r6, r0\n\
                movs r5, 0\n\
                mov r3, r9\n\
                lsls r3, 1\n\
                mov r12, r3\n\
                ldr r0, [sp, 0x8]\n\
                add r0, r9\n\
                str r0, [sp, 0x10]\n\
                cmp r7, r8\n\
                bcs _081D23B6\n\
                movs r7, 0x1\n\
            _081D2308:\n\
                adds r2, r3, r6\n\
                asrs r1, r4, 10\n\
                asrs r0, r4, 9\n\
                ands r0, r7\n\
                adds r1, r0\n\
                add r1, r9\n\
                strh r1, [r2]\n\
                ldr r1, [sp, 0xC]\n\
                adds r4, r1\n\
                adds r6, 0x4\n\
                adds r0, r5, 0x1\n\
                lsls r0, 16\n\
                lsrs r5, r0, 16\n\
                cmp r5, r8\n\
                bcc _081D2308\n\
                b _081D23B6\n\
            _081D2328:\n\
                ldr r2, [sp, 0xC]\n\
                cmp r2, 0\n\
                ble _081D23C0\n\
                mov r0, r10\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r7, r0\n\
                movs r5, 0\n\
                mov r3, r9\n\
                lsls r3, 1\n\
                mov r12, r3\n\
                ldr r0, [sp, 0x8]\n\
                add r0, r9\n\
                str r0, [sp, 0x10]\n\
                cmp r5, r8\n\
                bcs _081D237A\n\
                ldr r0, =0x00026bff\n\
                cmp r4, r0\n\
                bgt _081D237A\n\
                mov r1, r12\n\
                str r1, [sp, 0x14]\n\
            _081D2352:\n\
                ldr r3, [sp, 0x14]\n\
                adds r2, r3, r7\n\
                asrs r1, r4, 10\n\
                asrs r0, r4, 9\n\
                movs r3, 0x1\n\
                ands r0, r3\n\
                adds r1, r0\n\
                add r1, r9\n\
                strh r1, [r2]\n\
                ldr r0, [sp, 0xC]\n\
                adds r4, r0\n\
                adds r7, 0x4\n\
                adds r0, r5, 0x1\n\
                lsls r0, 16\n\
                lsrs r5, r0, 16\n\
                cmp r5, r8\n\
                bcs _081D237A\n\
                ldr r1, =0x00026bff\n\
                cmp r4, r1\n\
                ble _081D2352\n\
            _081D237A:\n\
                mov r2, r10\n\
                adds r1, r2, r5\n\
                ldr r3, [sp]\n\
                movs r2, 0xD4\n\
                lsls r2, 2\n\
                adds r0, r3, r2\n\
                strh r1, [r0]\n\
                ldrh r0, [r0]\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r6, r0\n\
                cmp r5, r8\n\
                bcs _081D23B6\n\
                mov r3, r12\n\
                movs r7, 0x1\n\
            _081D2398:\n\
                adds r2, r3, r6\n\
                asrs r1, r4, 10\n\
                asrs r0, r4, 9\n\
                ands r0, r7\n\
                adds r1, r0\n\
                add r1, r9\n\
                strh r1, [r2]\n\
                ldr r0, [sp, 0xC]\n\
                adds r4, r0\n\
                adds r6, 0x4\n\
                adds r0, r5, 0x1\n\
                lsls r0, 16\n\
                lsrs r5, r0, 16\n\
                cmp r5, r8\n\
                bcc _081D2398\n\
            _081D23B6:\n\
                subs r0, r6, 0x4\n\
                b _081D248C\n\
                .pool\n\
            _081D23C0:\n\
                ldr r1, [sp, 0xC]\n\
                cmp r1, 0\n\
                bge _081D2464\n\
                mov r0, r10\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r6, r0\n\
                movs r5, 0\n\
                mov r2, r9\n\
                lsls r2, 1\n\
                mov r12, r2\n\
                ldr r3, [sp, 0x8]\n\
                add r3, r9\n\
                str r3, [sp, 0x10]\n\
                cmp r5, r8\n\
                bcs _081D241E\n\
                adds r3, r2, r6\n\
                asrs r1, r4, 10\n\
                asrs r0, r4, 9\n\
                movs r2, 0x1\n\
                ands r0, r2\n\
                adds r1, r0\n\
                add r1, r9\n\
                strh r1, [r3]\n\
                b _081D2414\n\
            _081D23F2:\n\
                ldr r0, [sp, 0xC]\n\
                adds r4, r0\n\
                adds r6, 0x4\n\
                adds r0, r5, 0x1\n\
                lsls r0, 16\n\
                lsrs r5, r0, 16\n\
                cmp r5, r8\n\
                bcs _081D241E\n\
                mov r1, r12\n\
                adds r3, r1, r6\n\
                asrs r2, r4, 10\n\
                asrs r0, r4, 9\n\
                movs r1, 0x1\n\
                ands r0, r1\n\
                adds r2, r0\n\
                add r2, r9\n\
                strh r2, [r3]\n\
            _081D2414:\n\
                ldr r0, =0x00026bff\n\
                cmp r4, r0\n\
                bgt _081D23F2\n\
                movs r0, 0x9B\n\
                strh r0, [r3]\n\
            _081D241E:\n\
                mov r2, r10\n\
                adds r1, r2, r5\n\
                ldr r3, [sp]\n\
                movs r2, 0xD4\n\
                lsls r2, 2\n\
                adds r0, r3, r2\n\
                strh r1, [r0]\n\
                ldrh r0, [r0]\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r7, r0\n\
                cmp r5, r8\n\
                bcs _081D245A\n\
                mov r3, r12\n\
                movs r6, 0x1\n\
            _081D243C:\n\
                adds r2, r3, r7\n\
                asrs r1, r4, 10\n\
                asrs r0, r4, 9\n\
                ands r0, r6\n\
                adds r1, r0\n\
                add r1, r9\n\
                strh r1, [r2]\n\
                ldr r0, [sp, 0xC]\n\
                adds r4, r0\n\
                adds r7, 0x4\n\
                adds r0, r5, 0x1\n\
                lsls r0, 16\n\
                lsrs r5, r0, 16\n\
                cmp r5, r8\n\
                bcc _081D243C\n\
            _081D245A:\n\
                subs r0, r7, 0x4\n\
                b _081D248C\n\
                .pool\n\
            _081D2464:\n\
                ldr r1, [sp]\n\
                movs r2, 0xD4\n\
                lsls r2, 2\n\
                adds r0, r1, r2\n\
                mov r3, r10\n\
                strh r3, [r0]\n\
                mov r0, r10\n\
                subs r0, 0x38\n\
                lsls r0, 2\n\
                adds r6, r0\n\
                adds r7, r0\n\
                ldrh r0, [r5]\n\
                adds r0, 0x1\n\
                strh r0, [r6, 0x2]\n\
                ldr r1, [sp, 0x4]\n\
                ldrh r0, [r1]\n\
                strh r0, [r7]\n\
                movs r0, 0x9B\n\
                strh r0, [r7, 0x2]\n\
                b _081D2494\n\
            _081D248C:\n\
                add r0, r12\n\
                mov r2, sp\n\
                ldrh r2, [r2, 0x10]\n\
                strh r2, [r0]\n\
            _081D2494:\n\
                add sp, 0x18\n\
                pop {r3-r5}\n\
                mov r8, r3\n\
                mov r9, r4\n\
                mov r10, r5\n\
                pop {r4-r7}\n\
                pop {r0}\n\
                bx r0\n\
    ");
}

static void sub_81D24A4(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i, r6, varMax;

    if (arg0->unk12C[0].unk2 < arg0->unk12C[1].unk2)
    {
        r6 = arg0->unk12C[0].unk2;
        sub_81D2278(arg0, arg0->unk140, &arg0->unk12C[0], &arg0->unk12C[1], 1, NULL);
    }
    else
    {
        r6 = arg0->unk12C[1].unk2;
        sub_81D2278(arg0, arg0->unk140, &arg0->unk12C[1], &arg0->unk12C[0], 0, NULL);
    }

    sub_81D2278(arg0, arg0->unk140, &arg0->unk12C[1], &arg0->unk12C[2], 1, NULL);

    i = (arg0->unk12C[2].unk2 <= arg0->unk12C[3].unk2);
    sub_81D2278(arg0, arg0->unk140, &arg0->unk12C[2], &arg0->unk12C[3], i, arg0->unk248);
    for (i = 56; i < r6; i++)
    {
        arg0->unk140[i - 56][0] = 0;
        arg0->unk140[i - 56][1] = 0;
    }

    for (i = arg0->unk12C[0].unk2; i <= arg0->unk350; i++)
        arg0->unk140[i - 56][0] = 155;

    varMax = max(arg0->unk350, arg0->unk12C[2].unk2);
    for (i = varMax + 1; i < 122; i++)
    {
        arg0->unk140[i - 56][0] = 0;
        arg0->unk140[i - 56][1] = 0;
    }

    for (i = 56; i < 122; i++)
    {
        if (arg0->unk140[i - 56][0] == 0 && arg0->unk140[i - 56][1] != 0)
            arg0->unk140[i - 56][0] = 155;
    }
}

static void sub_81D2634(struct UnknownStruct_81D1ED4 *arg0)
{
    s32 i, r6, varMax;

    if (arg0->unk12C[0].unk2 < arg0->unk12C[4].unk2)
    {
        r6 = arg0->unk12C[0].unk2;
        sub_81D2278(arg0, arg0->unk248, &arg0->unk12C[0], &arg0->unk12C[4], 0, NULL);
    }
    else
    {
        r6 = arg0->unk12C[4].unk2;
        sub_81D2278(arg0, arg0->unk248, &arg0->unk12C[4], &arg0->unk12C[0], 1, NULL);
    }

    sub_81D2278(arg0, arg0->unk248, &arg0->unk12C[4], &arg0->unk12C[3], 0, NULL);

    for (i = 56; i < r6; i++)
    {
        arg0->unk140[i + 10][0] = 0;
        arg0->unk140[i + 10][1] = 0;
    }

    for (i = arg0->unk12C[0].unk2; i <= arg0->unk350; i++)
        arg0->unk140[i + 10][1] = 155;

    varMax = max(arg0->unk350, arg0->unk12C[3].unk2 + 1);
    for (i = varMax; i < 122; i++)
    {
        arg0->unk140[i + 10][0] = 0;
        arg0->unk140[i + 10][1] = 0;
    }

    for (i = 0; i < 66; i++)
    {
        if (arg0->unk248[i][0] >= arg0->unk248[i][1])
        {
            arg0->unk248[i][1] = 0;
            arg0->unk248[i][0] = 0;
        }
    }
}

void sub_81D2754(u8 *arg0, struct UnknownSubStruct_81D1ED4 *arg1)
{
    u8 r2, r7;
    s8 r12;
    u16 i;

    r2 = sUnknown_08625410[*(arg0++)];
    arg1->unk0 = 155;
    arg1->unk2 = 91 - r2;

    r7 = 64;
    r12 = 0;
    for (i = 1; i < 5; i++)
    {
        r7 += 51;
        if (--r12 < 0)
            r12 = 4;

        if (r12 == 2)
            r7++;

        r2 = sUnknown_08625410[*(arg0++)];
        arg1[r12].unk0 = 155 + ((r2 * gSineTable[64 + r7]) >> 8);
        arg1[r12].unk2 = 91  - ((r2 * gSineTable[r7]) >> 8);

        if (r12 < 3 && (r2 != 32 || r12 != 2))
            arg1[r12].unk0 = 156 + ((r2 * gSineTable[64 + r7]) >> 8);
    }
}

void InitMoveRelearnerWindows(bool8 useContextWindow)
{
    u8 i;

    InitWindows(sMoveRelearnerWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xE0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);

    for (i = 0; i < 5; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(1));
    }

    if (!useContextWindow)
    {
        PutWindowTilemap(0);
        DrawStdFrameWithCustomTileAndPalette(0, 0, 0x1, 0xE);
    }
    else
    {
        PutWindowTilemap(1);
        DrawStdFrameWithCustomTileAndPalette(1, 0, 1, 0xE);
    }
    PutWindowTilemap(2);
    PutWindowTilemap(3);
    DrawStdFrameWithCustomTileAndPalette(2, 0, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(3, 0, 1, 0xE);
    nullsub_79();
    schedule_bg_copy_tilemap_to_vram(1);
}

static void nullsub_79(void)
{

}

u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices)
{
    gMultiuseListMenuTemplate = sMoveRelearnerMovesListTemplate;
    gMultiuseListMenuTemplate.totalItems = numChoices;
    gMultiuseListMenuTemplate.items = items;

    if (numChoices < 6)
    {
        gMultiuseListMenuTemplate.maxShowed = numChoices;
    }
    else
    {
        gMultiuseListMenuTemplate.maxShowed = 6;
    }
    return gMultiuseListMenuTemplate.maxShowed;
}

static void MoveRelearnerLoadBattleMoveDescription(u32 chosenMove)
{
    s32 x;
    const struct BattleMove *move;
    u8 buffer[0x20];
    const u8 *str;

    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    str = gText_MoveRelearnerBattleMoves;
    x = GetStringCenterAlignXOffset(1, str, 0x80);
    AddTextPrinterParameterized(0, 1, str, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerPP;
    AddTextPrinterParameterized(0, 1, str, 4, 0x29, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerPower;
    x = GetStringRightAlignXOffset(1, str, 0x6A);
    AddTextPrinterParameterized(0, 1, str, x, 0x19, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerAccuracy;
    x = GetStringRightAlignXOffset(1, str, 0x6A);
    AddTextPrinterParameterized(0, 1, str, x, 0x29, TEXT_SPEED_FF, NULL);
    if (chosenMove == LIST_CANCEL)
    {
        CopyWindowToVram(0, 2);
        return;
    }
    move = &gBattleMoves[chosenMove];
    str = gTypeNames[move->type];
    AddTextPrinterParameterized(0, 1, str, 4, 0x19, TEXT_SPEED_FF, NULL);

    x = 4 + GetStringWidth(1, gText_MoveRelearnerPP, 0);
    ConvertIntToDecimalStringN(buffer, move->pp, 0, 2);
    AddTextPrinterParameterized(0, 1, buffer, x, 0x29, TEXT_SPEED_FF, NULL);

    if (move->power < 2)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->power, 0, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(0, 1, str, 0x6A, 0x19, TEXT_SPEED_FF, NULL);

    if (move->accuracy == 0)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->accuracy, 0, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(0, 1, str, 0x6A, 0x29, TEXT_SPEED_FF, NULL);

    str = gMoveDescriptionPointers[chosenMove - 1];
    AddTextPrinterParameterized(0, 7, str, 0, 0x41, 0, NULL);
}

static void MoveRelearnerMenuLoadContestMoveDescription(u32 chosenMove)
{
    s32 x;
    const u8 *str;
    const struct ContestMove *move;

    MoveRelearnerShowHideHearts(chosenMove);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    str = gText_MoveRelearnerContestMovesTitle;
    x = GetStringCenterAlignXOffset(1, str, 0x80);
    AddTextPrinterParameterized(1, 1, str, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerAppeal;
    x = GetStringRightAlignXOffset(1, str, 0x5C);
    AddTextPrinterParameterized(1, 1, str, x, 0x19, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerJam;
    x = GetStringRightAlignXOffset(1, str, 0x5C);
    AddTextPrinterParameterized(1, 1, str, x, 0x29, TEXT_SPEED_FF, NULL);

    if (chosenMove == MENU_NOTHING_CHOSEN)
    {
        CopyWindowToVram(1, 2);
        return;
    }

    move = &gContestMoves[chosenMove];
    str = gContestMoveTypeTextPointers[move->contestCategory];
    AddTextPrinterParameterized(1, 1, str, 4, 0x19, TEXT_SPEED_FF, NULL);

    str = gContestEffectDescriptionPointers[move->effect];
    AddTextPrinterParameterized(1, 7, str, 0, 0x41, TEXT_SPEED_FF, NULL);

    CopyWindowToVram(1, 2);
}

static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
    MoveRelearnerLoadBattleMoveDescription(itemIndex);
    MoveRelearnerMenuLoadContestMoveDescription(itemIndex);
}

void MoveRelearnerPrintText(u8 *str)
{
    u8 speed;

    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    gTextFlags.canABSpeedUpPrint = TRUE;
    speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized2(3, 1, str, speed, NULL, TEXT_COLOR_DARK_GREY, TEXT_COLOR_WHITE, 3);
}

bool16 MoveRelearnerRunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(3);
}

void MoveRelearnerCreateYesNoMenu(void)
{
    CreateYesNoMenu(&sMoveRelearnerYesNoMenuTemplate, 1, 0xE, 0);
}
