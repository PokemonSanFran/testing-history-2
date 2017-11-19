
// Includes
#include "global.h"
#include "link.h"
#include "librfu.h"
#include "link_rfu.h"

// Static type declarations

// Static RAM declarations

struct UnkRfuStruct_1 gUnknown_03004140;
struct UnkRfuStruct_2 gUnknown_03005000;

IWRAM_DATA u8 gUnknown_03000D74;
ALIGNED(4) IWRAM_DATA u8 gUnknown_03000D78[8];
IWRAM_DATA u8 gUnknown_03000D80[16];
IWRAM_DATA u16 gUnknown_03000D90[8];

EWRAM_DATA u8 gUnknown_02022B10 = 0;
EWRAM_DATA struct UnkLinkRfuStruct_02022B14 gUnknown_02022B14 = {};
EWRAM_DATA struct UnkLinkRfuStruct_02022B2C gUnknown_02022B2C = {};

// Static ROM declarations

void sub_800C000(void);
void sub_800CEB0(u16 unk0);
void sub_800C7B4(u16 unk0, u16 unk1);
void sub_800D30C(u8 a0, u8 a1);
void sub_800D334(u8 a0);
void sub_800D610(void);
void sub_800C744(u32 a0);
void sub_800CF34(void);
void sub_800D158(void);
void sub_800D268(void);
void sub_800D434(void);

// .rodata

// .text

u32 sub_800BEC0(void)
{
    u32 r4;

    r4 = rfu_REQBN_softReset_and_checkID();
    if (r4 == 0x8001)
    {
        gUnknown_03004140.unk_08 = 1;
    }
    if (gUnknown_03004140.unk_04 != 0x17 && gUnknown_03004140.unk_04 != 0x01)
    {
        gUnknown_03004140.unk_05 = 0;
        gUnknown_03004140.unk_04 = 0;
    }
    gUnknown_03004140.unk_07 = 0;
    gUnknown_03004140.unk_0d = 0;
    gUnknown_03004140.unk_01 = 0;
    gUnknown_03004140.unk_00 = 0;
    gUnknown_03004140.unk_06 = -1;
    sub_800D610();
    return r4;
}

void rfu_REQ_sendData_wrapper(u8 r2)
{
    u8 val;
    if (!gUnknown_03007890->unk_00)
    {
        val = gUnknown_03004140.unk_02;
        r2 = 0;
        if (val == 1)
        {
            r2 = 1;
        }
    }
    else
    {
        gUnknown_03004140.unk_03 = 0;
    }
    rfu_REQ_sendData(r2);
}

int sub_800BF4C(void (*func1)(u8), void (*func2)(void))
{
    if (func1 == NULL)
    {
        return 4;
    }
    CpuFill16(0, &gUnknown_03004140, offsetof(struct UnkRfuStruct_1, filler_48));
    gUnknown_03004140.unk_06 = -1;
    gUnknown_03004140.unk_40 = func1;
    gUnknown_03004140.unk_44 = func2;
    rfu_setMSCCallback(sub_800CEB0);
    rfu_setREQCallback(sub_800C7B4);
    return 0;
}

void sub_800BFA0(void)
{
    CpuFill16(0, &gUnknown_03004140, offsetof(struct UnkRfuStruct_1, unk_40));
    gUnknown_03004140.unk_06 = -1;
}

void sub_800BFCC(struct UnkLinkRfuStruct_02022B2C *unk0)
{
    sub_800C000();
    gUnknown_03004140.unk_04 = 1;
    gUnknown_03004140.unk_05 = 2;
    gUnknown_03004140.unk_3c = unk0;
    gUnknown_03004140.unk_09 = unk0->unk_11;
    gUnknown_03004140.unk_32 = unk0->unk_12;
    gUnknown_03004140.unk_18 = unk0->unk_14;
    if (unk0->unk_10)
    {
        gUnknown_03004140.unk_0b = 1;
    }
}

void sub_800C000(void)
{
    u8 i;

    gUnknown_03004140.unk_05 = 0;
    gUnknown_03004140.unk_04 = 0;
    gUnknown_03004140.unk_06 = -1;
    gUnknown_03004140.unk_07 = 0;
    gUnknown_03004140.unk_10 = 0;
    gUnknown_03004140.unk_0c = 0;
    gUnknown_03004140.unk_24 = 0;
    gUnknown_03004140.unk_30 = 0;
    for (i = 0; i < 4; i++)
    {
        gUnknown_03004140.unk_28[i] = 0;
        gUnknown_03004140.unk_34[i] = 0;
    }
}

void sub_800C048(void)
{
    gUnknown_03004140.unk_04 = 0x15;
}

u8 sub_800C054(u8 r5, u16 r7, u16 r8, u16 *r6)
{
    u8 i;
    u16 *buffer;

    if (gUnknown_03004140.unk_04 != 0 && (gUnknown_03004140.unk_04 != 0x08 || r5 != 1))
    {
        gUnknown_03004140.unk_14 = 1;
        sub_800D30C(0xf3, 0x01);
        return 1;
    }
    if (!rfu_getMasterSlave())
    {
        gUnknown_03004140.unk_14 = 2;
        sub_800D30C(0xf3, 0x01);
        return 2;
    }
    for (i = 0, buffer = r6; i < 16; i++)
    {
        if (*buffer++ == 0xFFFF)
        {
            break;
        }
    }
    if (i == 16)
    {
        gUnknown_03004140.unk_14 = 4;
        sub_800D30C(0xf3, 0x01);
        return 4;
    }
    if (r5 > 1)
    {
        gUnknown_03004140.unk_07 = 1;
        r5 = 1;
        r7 = 0;
    }
    else
    {
        gUnknown_03004140.unk_07 = 0;
    }
    if (r5 != 0)
    {
        gUnknown_03004140.unk_04 = 5;
    }
    else
    {
        gUnknown_03004140.unk_04 = 9;
        if (gUnknown_03004140.unk_0b)
        {
            gUnknown_03004140.unk_0b = 2;
        }
    }
    gUnknown_03004140.unk_06 = r5;
    gUnknown_03004140.unk_1a = r7;
    gUnknown_03004140.unk_26 = r8;
    gUnknown_03004140.unk_20 = r6;
    return 0;
}

u8 sub_800C12C(u16 r6, u16 r8)
{
    u8 i;
    struct RfuUnk5 *tmp;

    if (gUnknown_03004140.unk_04 != 0 && (gUnknown_03004140.unk_04 < 9 || gUnknown_03004140.unk_04 > 11))
    {
        gUnknown_03004140.unk_14 = 1;
        sub_800D30C(0xF3, 0x01);
        return 1;
    }
    if (!rfu_getMasterSlave())
    {
        gUnknown_03004140.unk_14 = 2;
        sub_800D30C(0xF3, 0x01);
        return 2;
    }
    for (i = 0; i < gUnknown_03007890->unk_08; i++)
    {
        tmp = &gUnknown_03007890[i];
        if (tmp->unk_14 == r6)
        {
            break;
        }
    }
    if (gUnknown_03007890->unk_08 == 0 || i == gUnknown_03007890->unk_08)
    {
        gUnknown_03004140.unk_14 = 3;
        sub_800D30C(0xF3, 0x01);
        return 3;
    }
    if (gUnknown_03004140.unk_04 == 0 || gUnknown_03004140.unk_04 == 9)
    {
        gUnknown_03004140.unk_04 = 12;
        gUnknown_03004140.unk_05 = 13;
    }
    else
    {
        gUnknown_03004140.unk_04 = 11;
        gUnknown_03004140.unk_05 = 12;
    }
    gUnknown_03004140.unk_1e = r6;
    gUnknown_03004140.unk_1a = r8;
    if (gUnknown_03004140.unk_07 != 0)
    {
        gUnknown_03004140.unk_07 = 7;
    }
    return 0;
}

void sub_800C210(u8 a0)
{
    u8 i;

    if (a0 & gUnknown_03004140.unk_30)
    {
        gUnknown_03004140.unk_30 &= ~a0;
        for (i = 0; i < 4; i++)
        {
            if ((a0 >> i) & 1)
            {
                gUnknown_03004140.unk_34[i] = 0;
            }
        }
        i = gUnknown_03007890->unk_03 & a0;
        if (i)
        {
            sub_800D334(i);
        }
        gUnknown_03004140.unk_14 = i;
        sub_800D30C(0x33, i);
    }
}

void sub_800C27C(bool8 a0)
{
    u8 r2;

    r2 = 0;
    gUnknown_03004140.unk_07 = 0;
    if (a0)
    {
        sub_800C000();
        gUnknown_03004140.unk_04 = 23;
    }
    else
    {
        switch (gUnknown_03004140.unk_04)
        {
            case 5:
                gUnknown_03004140.unk_04 = 8;
                gUnknown_03004140.unk_05 = 0;
                r2 = 0x13;
                break;
            case 6:
                gUnknown_03004140.unk_04 = 7;
                gUnknown_03004140.unk_05 = 8;
                break;
            case 7:
                gUnknown_03004140.unk_04 = 7;
                gUnknown_03004140.unk_05 = 8;
                break;
            case 8:
                break;
            case 9:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x21;
                break;
            case 10:
                gUnknown_03004140.unk_04 = 11;
                gUnknown_03004140.unk_05 = 0;
                break;
            case 11:
                gUnknown_03004140.unk_04 = 11;
                gUnknown_03004140.unk_05 = 0;
                break;
            case 12:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x23;
                break;
            case 13:
                gUnknown_03004140.unk_04 = 14;
                break;
            case 14:
                gUnknown_03004140.unk_04 = 14;
                break;
            case 15:
                break;
            case 16:
                gUnknown_03004140.unk_04 = gUnknown_03004140.unk_11;
                gUnknown_03004140.unk_05 = gUnknown_03004140.unk_12;
                sub_800D334(gUnknown_03007890->unk_03);
                gUnknown_03004140.unk_14 = gUnknown_03007890->unk_03;
                sub_800D30C(0x33, 0x01);
                return;
            case 17:
                gUnknown_03004140.unk_04 = 18;
                break;
            case 18:
                gUnknown_03004140.unk_04 = 18;
                break;
            default:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x43;
                break;
        }
        if (gUnknown_03004140.unk_04 == 0)
        {
            sub_800D30C(r2, 0);
        }
    }
}

bool8 sub_800C36C(u16 a0)
{
    bool8 retVal;
    u8 i;
    u8 sp0;
    u8 sp1;
    u8 sp2;
    u8 flags;

    retVal = FALSE;
    rfu_REQBN_watchLink(a0, &sp0, &sp1, &sp2);
    if (sp0)
    {
        gUnknown_03004140.unk_14 = sp0;
        gUnknown_03004140.unk_16 = sp1;
        if (gUnknown_03004140.unk_09)
        {
            gUnknown_03004140.unk_0a = 1;
            if (gUnknown_03004140.unk_06 == 0 && sp1 == 0)
            {
                gUnknown_03004140.unk_0a = 4;
            }
            if (gUnknown_03004140.unk_0a == 1)
            {
                for (i = 0; i < 4; i++)
                {
                    if ((sp0 >> i) & 1)
                    {
                        gUnknown_03004140.unk_30 |= (1 << i);
                        gUnknown_03004140.unk_34[i] = gUnknown_03004140.unk_32;
                    }
                }
                sub_800D30C(0x31, 0x01);
            }
            else
            {
                gUnknown_03004140.unk_0a = 0;
                sub_800D334(sp0);
                retVal = TRUE;
                sub_800D30C(0x33, 0x01);
            }
        }
        else
        {
            sub_800D334(sp0);
            retVal = TRUE;
            sub_800D30C(0x30, 0x02);
        }
        sub_800D610();
    }
    if (gUnknown_03007890->unk_00 == 1)
    {
        if (sp2)
        {
            for (i = 0; i < 4; i++)
            {
                if ((gUnknown_03004140.unk_30 >> i) & 1 && (sp2 >> i) & 1)
                {
                    gUnknown_03004140.unk_34[i] = 0;
                }
            }
            gUnknown_03004140.unk_30 &= ~sp2;
            gUnknown_03004140.unk_14 = sp2;
            sub_800D30C(0x32, 0x01);
        }
        if (gUnknown_03004140.unk_30)
        {
            flags = 0;
            for (i = 0; i < 4; i++)
            {
                if ((gUnknown_03004140.unk_30 >> i) & 1 && gUnknown_03004140.unk_34[i] && --gUnknown_03004140.unk_34[i] == 0)
                {
                    gUnknown_03004140.unk_30 &= ~(1 << i);
                    flags |= (1 << i);
                }
            }
            if (flags)
            {
                sub_800D334(flags);
                retVal = TRUE;
                gUnknown_03004140.unk_14 = flags;
                sub_800D30C(0x33, 0x01);
            }
        }
        if (!gUnknown_03004140.unk_30)
        {
            gUnknown_03004140.unk_0a = 0;
        }
    }
    return retVal;
}

void rfu_syncVBlank_(void)
{
    if (rfu_syncVBlank())
    {
        sub_800D30C(0xF1, 0x00);
        sub_800D610();
    }
}

void sub_800C54C(u32 a0)
{
    u8 r2;

    if (gUnknown_03004140.unk_40 == NULL && gUnknown_03004140.unk_04 != 0)
    {
        gUnknown_03004140.unk_04 = 0;
    }
    else
    {
        if (gUnknown_03004140.unk_07 != 0)
        {
            sub_800C744(a0);
        }
        do {

            if (gUnknown_03004140.unk_04 != 0)
            {
                rfu_waitREQComplete();
                gUnknown_03004140.unk_0e = 1;
                switch (gUnknown_03004140.unk_04)
                {
                    case 23:
                        r2 = sub_800BEC0() == 0x8001 ? 0x44 : 0xFF;
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                        sub_800D30C(r2, 0);
                        break;
                    case 1:
                        if (sub_800BEC0() == 0x8001)
                        {
                            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                            gUnknown_03004140.unk_05 = 3;
                        }
                        else
                        {
                            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                            sub_800D30C(0xFF, 0);
                        }
                        break;
                    case 2:
                        rfu_REQ_reset();
                        break;
                    case 3:
                        rfu_REQ_configSystem(gUnknown_03004140.unk_3c->unk_02, gUnknown_03004140.unk_3c->unk_00, gUnknown_03004140.unk_3c->unk_01);
                        break;
                    case 4:
                        rfu_REQ_configGameData(gUnknown_03004140.unk_3c->unk_04, gUnknown_03004140.unk_3c->unk_06, gUnknown_03004140.unk_3c->unk_08, gUnknown_03004140.unk_3c->unk_0c);
                        break;
                    case 5:
                        rfu_REQ_startSearchChild();
                        break;
                    case 6:
                        rfu_REQ_pollSearchChild();
                        break;
                    case 7:
                        rfu_REQ_endSearchChild();
                        break;
                    case 8:
                        break;
                    case 9:
                        rfu_REQ_startSearchParent();
                        break;
                    case 10:
                        rfu_REQ_pollSearchParent();
                        break;
                    case 11:
                        rfu_REQ_endSearchParent();
                        break;
                    case 12:
                        rfu_REQ_startConnectParent(gUnknown_03004140.unk_1e);
                        break;
                    case 13:
                        rfu_REQ_pollConnectParent();
                        break;
                    case 14:
                        rfu_REQ_endConnectParent();
                        break;
                    case 15:
                        break;
                    case 16:
                        rfu_REQ_CHILD_startConnectRecovery(gUnknown_03007890->unk_03);
                        break;
                    case 17:
                        rfu_REQ_CHILD_pollConnectRecovery();
                        break;
                    case 18:
                        rfu_REQ_CHILD_endConnectRecovery();
                        break;
                    case 19:
                        rfu_REQ_changeMasterSlave();
                        break;
                    case 20:
                        break;
                    case 21:
                        rfu_REQ_stopMode();
                        break;
                    case 22:
                        break;
                }
                rfu_waitREQComplete();
                gUnknown_03004140.unk_0e = 0;
            }
        } while (gUnknown_03004140.unk_04 == 18 || gUnknown_03004140.unk_04 == 19);
        if (gUnknown_03007890->unk_00 != 1 || !sub_800C36C(0))
        {
            sub_800CF34();
            sub_800D158();
            sub_800D268();
            sub_800D434();
        }
    }
}
