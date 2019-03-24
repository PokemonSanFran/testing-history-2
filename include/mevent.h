#ifndef GUARD_MEVENT_H
#define GUARD_MEVENT_H

struct MEvent_Str_1
{
    u16 unk_000;
    size_t unk_004;
    const void * unk_008;
};

struct MEvent_Str_2
{
    u8 fill_00[0x40];
};

struct MEventStruct_Unk1442CC
{
    u32 unk_00;
    u16 unk_04;
    u32 unk_08;
    u16 unk_0C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16[4];
    struct MEventBuffer_3430_Sub unk_20;
    u8 unk_44;
    u8 unk_45[7];
    u8 unk_4C[4];
    u16 unk_50[6];
    u8 unk_5C[4];
    u8 unk_60;
};

void sub_801AFD8(void);
struct MEventBuffer_3120_Sub *sub_801B00C(void);
struct MEventBuffer_32E0_Sub *sav1_get_mevent_buffer_1(void);
struct MEventBuffer_3430_Sub *sav1_get_mevent_buffer_2(void);
struct MysteryEventStruct *sub_801B044(void);
u16 *sub_801B058(void);
void sub_801B06C(void);
bool32 sub_801B078(const struct MEventBuffer_3120_Sub *src);
bool32 sub_801B0CC(void);
bool32 sub_801B128(void);
bool32 sub_801B1A4(const u8 *src);
void sub_801B1E8(void);
bool32 sub_801B21C(const struct MEventBuffer_32E0_Sub *data);
bool32 sub_801B27C(void);
bool32 sub_801B308(void);
u16 sub_801B39C(void);
void sub_801B3C0(struct MEventBuffer_32E0_Sub *buffer);
bool32 sub_801B3F8(void);
bool32 sub_801B508(const u16 *data);
void sub_801B580(struct MEventStruct_Unk1442CC *data, bool32 a1);
bool32 sub_801B6A0(const struct MEventStruct_Unk1442CC *data, bool32 a1);
u32 sub_801B6EC(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, void *unused);
u32 sub_801B708(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, void *unused);
bool32 sub_801B748(const struct MEventStruct_Unk1442CC *a0, const u16 *a1);
u16 sub_801B784(const struct MEventStruct_Unk1442CC *a0, u32 command);
u16 mevent_081445C0(u32 command);
void sub_801B940(void);
bool32 sub_801B94C(u16 a0);

#endif //GUARD_MEVENT_H
