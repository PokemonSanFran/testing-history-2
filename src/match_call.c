
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"

#define NELEMS(a) (s32)( sizeof (a) / sizeof (*(a)) )

// Static type declarations

struct MatchCallSusbtruct0 {
    const u8 *text;
    u16 v4;
    u16 v6;
};

struct MatchCallStructCommon {
    u8 type;
    u8 v1;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const struct MatchCallSusbtruct0 *vC;
};

struct MatchCallStruct1 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
};

struct MatchCallSubstruct2 {
    u16 v0;
    u8 v2;
};

struct MatchCallStruct2 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *v8;
    const u8 *vC;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
};

struct MatchCallStruct4 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const struct MatchCallSusbtruct0 *vC;
};

typedef union {
    struct MatchCallStructCommon *common;
    struct MatchCallStruct0 *type0;
    struct MatchCallStruct1 *type1;
    struct MatchCallStruct2 *type2;
    struct MatchCallStruct3 *type3;
    struct MatchCallStruct4 *type4;
} match_call_t;

// Static RAM declarations

// Static ROM declarations

// .rodata

extern const match_call_t gUnknown_086252A8[];
extern bool32 (*const gUnknown_086252FC[])(const match_call_t);
extern u8 (*const gUnknown_08625310[])(const match_call_t);
extern bool32 (*const gUnknown_08625324[])(const match_call_t);

// .text

s32 sub_81D1574(const match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}

s32 sub_81D15BC(s32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 sub_81D15CC(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < NELEMS(gRematchTable); rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 sub_81D15F4(u32 idx)
{
    match_call_t matchCall;
    s32 v0;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    v0 = sub_81D1574(matchCall);
    return gUnknown_086252FC[v0](matchCall);
}

bool32 sub_81D1628(match_call_t matchCall)
{
    if (matchCall.type0->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type0->flag);
}

bool32 sub_81D164C(match_call_t matchCall)
{
    if (matchCall.type1->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type1->flag);
}

bool32 sub_81D1670(match_call_t matchCall)
{
    if (matchCall.type2->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type2->flag);
}

bool32 sub_81D1694(match_call_t matchCall)
{
    if (matchCall.type4->v1 != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type4->flag);
}

bool32 sub_81D16CC(match_call_t matchCall)
{
    return FlagGet(matchCall.type3->flag);
}

u8 sub_81D16DC(u32 idx)
{
    match_call_t matchCall;
    s32 v0;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    v0 = sub_81D1574(matchCall);
    return gUnknown_08625310[v0](matchCall);
}

u8 sub_81D1714(match_call_t matchCall)
{
    return matchCall.type0->v1;
}

u8 sub_81D1718(match_call_t matchCall)
{
    return matchCall.type1->v1;
}

u8 sub_81D171C(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.type2->v10[i].v0 != 0xffff; i++)
    {
        if (!FlagGet(matchCall.type2->v10[i].v0))
            break;
    }
    return matchCall.type2->v10[i].v2;
}

u8 sub_81D1750(match_call_t matchCall)
{
    return 0xd5;
}

u8 sub_81D1754(match_call_t matchCall)
{
    return 0xd5;
}

bool32 sub_81D1758(u32 idx)
{
    match_call_t matchCall;
    s32 v0;

    if (idx > 20)
        return 0;
    matchCall = gUnknown_086252A8[idx];
    v0 = sub_81D1574(matchCall);
    return gUnknown_08625324[v0](matchCall);
}

bool32 sub_81D178C(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1790(match_call_t matchCall)
{
    if (matchCall.type1->v4 > 0x48)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.type1->v4] ? TRUE : FALSE;
}

bool32 sub_81D17C0(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.type2->v4] ? TRUE : FALSE;
}

bool32 sub_81D17E0(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E4(match_call_t matchCall)
{
    return FALSE;
}

