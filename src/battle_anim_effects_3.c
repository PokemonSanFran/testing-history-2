#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

extern u8 sub_807521C(s16 x, s16 y, u8 a3);
extern void sub_810E2C8(struct Sprite *);

extern const struct SpriteTemplate gUnknown_08593114;
extern const union AffineAnimCmd *const gUnknown_082FF6C0[];
extern const union AffineAnimCmd *const gUnknown_082FF694[];

void sub_815A0D4(struct Sprite *);
void sub_815A1B0(struct Sprite *);
void sub_815A254(struct Sprite *);
void sub_815A2F0(struct Sprite *);
void sub_815A6C4(struct Sprite *);
void sub_815A7B0(struct Sprite *);
void sub_815A7EC(struct Sprite *);
void sub_815A8AC(struct Sprite *);
void sub_815A934(struct Sprite *);
void sub_815AAA4(struct Sprite *);
void sub_815ABD0(struct Sprite *);
void sub_815ACD0(struct Sprite *);
void sub_815B27C(struct Sprite *);
void sub_815B394(struct Sprite *);
void sub_815B49C(struct Sprite *);
void sub_815B570(struct Sprite *);
void sub_815B70C(struct Sprite *);
void sub_815BE04(struct Sprite *);
void sub_815C400(struct Sprite *);
void sub_815C6B0(struct Sprite *);
void sub_815C95C(struct Sprite *);
void sub_815CB88(struct Sprite *);
void sub_815CC94(struct Sprite *);
void sub_815CDB4(struct Sprite *);
void sub_815D7B4(struct Sprite *);
void sub_815D870(struct Sprite *);
void sub_815DEBC(struct Sprite *);
void sub_815E01C(struct Sprite *);
void sub_815E404(struct Sprite *);
void sub_815E444(struct Sprite *);
void sub_815E6D8(struct Sprite *);
void sub_815E954(struct Sprite *);
void sub_815EA14(struct Sprite *);
void sub_815EE84(struct Sprite *);
void sub_815F18C(struct Sprite *);
void sub_815F48C(struct Sprite *);
void sub_815FE80(struct Sprite *);
void sub_81061C4(struct Sprite *);
void sub_8160338(struct Sprite *);
void sub_81603A8(struct Sprite *);
static void sub_815A114(struct Sprite *);
static void sub_815A1F4(struct Sprite *);
static void sub_815A234(struct Sprite *);
static void sub_815A31C(struct Sprite *);
static void sub_815A3AC(struct Sprite *);
static void sub_815A3F0(struct Sprite *);
static void sub_815A49C(struct Sprite *);
static void sub_815A52C(u8);
static void sub_815A5F0(u8);
static void sub_815A73C(struct Sprite *);
static void sub_815A76C(struct Sprite *);
static void sub_815A9A0(struct Sprite *);
static void sub_815AA6C(struct Sprite *);
static void sub_815AB5C(struct Sprite *);
static void sub_815AD4C(struct Sprite *);
static void sub_815AED8(u8);
static void sub_815B054(u8);
static void sub_815B23C(struct Sprite *);
static void sub_815B4D4(struct Sprite *);
static void sub_815B5D0(struct Sprite *);
static void sub_815BF44(struct Sprite *);
static void sub_815BFF4(struct Sprite *);
static void sub_815C050(struct Sprite *);
static void sub_815C548(u8);
static void sub_815C700(struct Sprite *);
static void sub_815C7C4(u8);
static void sub_815CC34(struct Sprite *);
static void sub_815CD0C(struct Sprite *);
static void sub_815CDFC(struct Sprite *);
static void sub_815D1BC(u8);
static void sub_815D398(u8);
static void sub_815D694(u8);
static void sub_815D804(struct Sprite *);
static void sub_815DD48(u8);
static void sub_815DDE0(u8, bool8);
static void sub_815DF64(u8);
static void sub_815E0DC(struct Sprite *);
static void sub_815E20C(u8);
static void sub_815E34C(s16, s16, s16, s16, u8, u8, s16 *, s16 *);
static void sub_815E5CC(u8);
static void sub_815E784(struct Sprite *);
static void sub_815E898(u8);
static void sub_815E9BC(struct Sprite *);
static void sub_815EA60(struct Sprite *);
static void sub_815ECE4(u8);
static void sub_815EF08(struct Sprite *);
static void sub_815F330(u8);
static void sub_815F4F0(struct Sprite *);
static void sub_815F79C(u8);
static void sub_815F7C4(struct Sprite *);

const union AnimCmd gUnknown_085CE004[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE01C[] =
{
    gUnknown_085CE004,
};

const struct SpriteTemplate gUnknown_085CE020 =
{
    .tileTag = ANIM_TAG_SCRATCH,
    .paletteTag = ANIM_TAG_SCRATCH,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_085CE01C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_085CE038 =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_BLACK_SMOKE,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A0D4,
};

const struct SpriteTemplate gUnknown_085CE050 =
{
    .tileTag = ANIM_TAG_BLACK_BALL,
    .paletteTag = ANIM_TAG_BLACK_BALL,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A78AC,
};

const union AnimCmd gUnknown_085CE068[] =
{
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 40),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE078[] =
{
    gUnknown_085CE068,
};

const struct SpriteTemplate gUnknown_085CE07C =
{
    .tileTag = ANIM_TAG_OPENING_EYE,
    .paletteTag = ANIM_TAG_OPENING_EYE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE078,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_085CE094 =
{
    .tileTag = ANIM_TAG_ROUND_WHITE_HALO,
    .paletteTag = ANIM_TAG_ROUND_WHITE_HALO,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A1B0,
};

const struct SpriteTemplate gUnknown_085CE0AC =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_TEAL_ALERT,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A254,
};

const union AffineAnimCmd gUnknown_085CE0C4[] =
{
    AFFINEANIMCMD_FRAME(0x180, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, 0x18, 0, 5),
    AFFINEANIMCMD_FRAME(0x18, -0x20, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_085CE0E4[] =
{
    AFFINEANIMCMD_FRAME(0x30, 0x30, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE0FC[] =
{
    gUnknown_085CE0C4,
    gUnknown_085CE0E4,
};

const struct SpriteTemplate gUnknown_085CE104 =
{
    .tileTag = ANIM_TAG_EYE,
    .paletteTag = ANIM_TAG_EYE,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE0FC,
    .callback = sub_815A2F0,
};

const struct SpriteTemplate gUnknown_085CE11C =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A6C4,
};

const union AnimCmd gUnknown_085CE134[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE14C[] =
{
    gUnknown_085CE134,
};

const struct SpriteTemplate gUnknown_085CE150 =
{
    .tileTag = ANIM_TAG_LEER,
    .paletteTag = ANIM_TAG_LEER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE14C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A7B0,
};

const union AnimCmd gUnknown_085CE168[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE170[] =
{
    gUnknown_085CE168,
};

const union AffineAnimCmd gUnknown_085CE174[] =
{
    AFFINEANIMCMD_FRAME(-7, -7, -3, 16),
    AFFINEANIMCMD_FRAME(7, 7, 3, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE18C[] =
{
    gUnknown_085CE174,
};

const struct SpriteTemplate gUnknown_085CE190 =
{
    .tileTag = ANIM_TAG_LETTER_Z,
    .paletteTag = ANIM_TAG_LETTER_Z,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085CE170,
    .images = NULL,
    .affineAnims = gUnknown_085CE18C,
    .callback = sub_815A7EC,
};

const union AnimCmd gUnknown_085CE1A8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 16),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE1BC[] =
{
    gUnknown_085CE1A8,
};

const union AffineAnimCmd gUnknown_085CE1C0[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, -0x20, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE1D8[] =
{
    gUnknown_085CE1C0,
};

const struct SpriteTemplate gUnknown_085CE1DC =
{
    .tileTag = ANIM_TAG_FANG_ATTACK,
    .paletteTag = ANIM_TAG_FANG_ATTACK,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_085CE1BC,
    .images = NULL,
    .affineAnims = gUnknown_085CE1D8,
    .callback = sub_815A8AC,
};

const union AffineAnimCmd gUnknown_085CE1F4[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x0, 0, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE20C[] =
{
    AFFINEANIMCMD_FRAME(0x140, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, 0x0, 0, 19),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE224[] =
{
    gUnknown_085CE1F4,
    gUnknown_085CE20C,
};

const struct SpriteTemplate gUnknown_085CE22C =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE224,
    .callback = sub_815A934,
};

const struct SpriteTemplate gUnknown_085CE244 =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815AAA4,
};

const struct SpriteTemplate gUnknown_085CE25C =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815ABD0,
};

const union AnimCmd gUnknown_085CE274[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085CE284[] =
{
    gUnknown_085CE274,
};

const struct SpriteTemplate gUnknown_085CE288 =
{
    .tileTag = ANIM_TAG_RAPID_SPIN,
    .paletteTag = ANIM_TAG_RAPID_SPIN,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085CE284,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815ACD0,
};

const union AffineAnimCmd gUnknown_085CE2A0[] =
{
    AFFINEANIMCMD_FRAME(-12, 8, 0, 4),
    AFFINEANIMCMD_FRAME(20, -20, 0, 4),
    AFFINEANIMCMD_FRAME(-8, 12, 0, 4),
    AFFINEANIMCMD_END,
};

const union AnimCmd gUnknown_085CE2C0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE2C8[] =
{
    gUnknown_085CE2C0,
};

const union AffineAnimCmd gUnknown_085CE2CC[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 5, 40),
    AFFINEANIMCMD_FRAME(0, 0, 10, 10),
    AFFINEANIMCMD_FRAME(0, 0, 15, 10),
    AFFINEANIMCMD_FRAME(0, 0, 20, 40),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE2F4[] =
{
    gUnknown_085CE2CC,
};

const struct SpriteTemplate gUnknown_085CE2F8 =
{
    .tileTag = ANIM_TAG_TRI_FORCE_TRIANGLE,
    .paletteTag = ANIM_TAG_TRI_FORCE_TRIANGLE,
    .oam = &gUnknown_085249DC,
    .anims = gUnknown_085CE2C8,
    .images = NULL,
    .affineAnims = gUnknown_085CE2F4,
    .callback = sub_815B27C,
};

const union AnimCmd gUnknown_085CE310[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE334[] =
{
    gUnknown_085CE310,
};

const struct SpriteTemplate gUnknown_085CE338 =
{
    .tileTag = ANIM_TAG_ECLIPSING_ORB,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE334,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AffineAnimCmd gUnknown_085CE350[] =
{
    AFFINEANIMCMD_FRAME(-12, 20, 0, 8),
    AFFINEANIMCMD_FRAME(12, -20, 0, 8),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE370 =
{
    .tileTag = ANIM_TAG_POKEBALL,
    .paletteTag = ANIM_TAG_POKEBALL,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B394,
};

const struct SpriteTemplate gUnknown_085CE388 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B49C,
};

const struct SpriteTemplate gUnknown_085CE3A0 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B570,
};

const union AffineAnimCmd gUnknown_085CE3B8[] =
{
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 12),
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_LOOP(1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE3E0[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(0, -18, 0, 6),
    AFFINEANIMCMD_FRAME(-18, -18, 0, 3),
    AFFINEANIMCMD_FRAME(0, 0, 0, 15),
    AFFINEANIMCMD_FRAME(4, 4, 0, 13),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE418 =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B70C,
};

const union AffineAnimCmd gUnknown_085CE430[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(7, -30, 0, 6),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(-2, 3, 0, 20),
    AFFINEANIMCMD_END,
};

const s8 gUnknown_085CE460[] =
{
    0xE8, 
    0x18, 
    0xFC, 
    0x00,
};

const union AnimCmd gUnknown_085CE464[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE470[] =
{
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085CE478[] =
{
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE480[] =
{
    gUnknown_085CE464,
    gUnknown_085CE470,
    gUnknown_085CE478,
};

const struct SpriteTemplate gUnknown_085CE48C =
{
    .tileTag = ANIM_TAG_GREEN_STAR,
    .paletteTag = ANIM_TAG_GREEN_STAR,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085CE480,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815BE04,
};

const s8 gUnknown_085CE4A4[] =
{
    0x78,
    0x50,
    0x28,
    0x00,
};

const u8 gUnknown_085CE4A8[] =
{
    0,
    0,
    0,
    0,
    50,
};

const union AffineAnimCmd gUnknown_085CE4B0[] =
{
    AFFINEANIMCMD_FRAME(0, -15, 0, 7),
    AFFINEANIMCMD_FRAME(0, 15, 0, 7),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE4D0 =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_ANGER,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C400,
};

const union AnimCmd gUnknown_085CE4E8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE50C[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE530[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE538[] =
{
    gUnknown_085CE4E8,
    gUnknown_085CE50C,
    gUnknown_085CE530,
};

const struct SpriteTemplate gUnknown_085CE544 =
{
    .tileTag = ANIM_TAG_PINK_PETAL,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085CE538,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C6B0,
};

const u16 gUnknown_085CE55C[] = INCBIN_U16("graphics/unknown/unknown_85CE55C.gbapal");

const union AnimCmd gUnknown_085CE57C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 9),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE58C[] =
{
    gUnknown_085CE57C,
};

const struct SpriteTemplate gUnknown_085CE590 =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_PAIN_SPLIT,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085CE58C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C95C,
};

const struct SpriteTemplate gUnknown_085CE5A8 =
{
    .tileTag = ANIM_TAG_CONFETTI,
    .paletteTag = ANIM_TAG_CONFETTI,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815CB88,
};

const struct SpriteTemplate gUnknown_085CE5C0 =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE224,
    .callback = sub_815CC94,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85CE5D8 =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815CDB4,
};

const union AffineAnimCmd gUnknown_085CE5F0[] =
{
    AFFINEANIMCMD_FRAME(16, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, -3, 0, 16),
    AFFINEANIMCMD_FRAME(4, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(-5, 3, 0, 16),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE620[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE640[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE660[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE680[] =
{
    gUnknown_085CE620,
    gUnknown_085CE640,
    gUnknown_085CE660,
};

const struct SpriteTemplate gUnknown_085CE68C =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE680,
    .callback = sub_815D7B4,
};

const union AffineAnimCmd gUnknown_085CE6A4[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE6C4[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE6E4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE704[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 10, 0, 30),
    AFFINEANIMCMD_FRAME(-8, -10, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE724[] =
{
    gUnknown_085CE6A4,
    gUnknown_085CE6C4,
    gUnknown_085CE6E4,
    gUnknown_085CE704,
};

const struct SpriteTemplate gUnknown_085CE734 =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gUnknown_085249D4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE724,
    .callback = sub_815D870,
};

const union AffineAnimCmd gUnknown_085CE74C[] =
{
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_FRAME(16, -16, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE76C =
{
    .tileTag = ANIM_TAG_SWEAT_DROP,
    .paletteTag = ANIM_TAG_SWEAT_DROP,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815DEBC,
};

const u16 gUnknown_085CE784[] = INCBIN_U16("graphics/battle_anims/sprites/effect.gbapal");

const union AnimCmd gUnknown_085CE7B4[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE7C0[] =
{
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085CE7CC[] =
{
    gUnknown_085CE7B4,
    gUnknown_085CE7C0,
};

const struct SpriteTemplate gUnknown_085CE7D4 =
{
    .tileTag = ANIM_TAG_NOISE_LINE,
    .paletteTag = ANIM_TAG_NOISE_LINE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE7CC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E01C,
};

const struct SpriteTemplate gUnknown_085CE7EC =
{
    .tileTag = ANIM_TAG_SMALL_RED_EYE,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E404,
};

const struct SpriteTemplate gUnknown_085CE804 =
{
    .tileTag = ANIM_TAG_PAW_PRINT,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E444,
};

const union AffineAnimCmd gUnknown_085CE81C[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE82C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE844[] =
{
    gUnknown_085CE81C,
    gUnknown_085CE82C,
};

const struct SpriteTemplate gUnknown_085CE84C =
{
    .tileTag = ANIM_TAG_RED_BALL,
    .paletteTag = ANIM_TAG_RED_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE844,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_085CE864 =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E6D8,
};

const union AffineAnimCmd gUnknown_085CE87C[] =
{
    AFFINEANIMCMD_FRAME(0, -16, 0, 6),
    AFFINEANIMCMD_FRAME(0, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE894 =
{
    .tileTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .paletteTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E954,
};

const struct SpriteTemplate gUnknown_085CE8AC =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815EA14,
};

const struct SpriteTemplate gUnknown_085CE8C4 =
{
    .tileTag = ANIM_TAG_MAGNIFYING_GLASS,
    .paletteTag = ANIM_TAG_MAGNIFYING_GLASS,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815EE84,
};

const struct SpriteTemplate gUnknown_085CE8DC =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815F18C,
};

const struct SpriteTemplate gUnknown_085CE8F4 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81061C4,
};

const struct SpriteTemplate gUnknown_085CE90C =
{
    .tileTag = ANIM_TAG_X_SIGN,
    .paletteTag = ANIM_TAG_X_SIGN,
    .oam = &gUnknown_0852491C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815F48C,
};

const struct SpriteTemplate gUnknown_085CE924 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815FE80,
};

const union AnimCmd gUnknown_085CE93C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE948[] =
{
    gUnknown_085CE93C,
};

const union AffineAnimCmd gUnknown_085CE94C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE964[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE97C[] =
{
    gUnknown_085CE94C,
    gUnknown_085CE964,
};

const struct SpriteTemplate gUnknown_085CE984 =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_SLAM_HIT_2,
    .oam = &gUnknown_0852497C,
    .anims = gUnknown_085CE948,
    .images = NULL,
    .affineAnims = gUnknown_085CE97C,
    .callback = sub_8160338,
};

const union AffineAnimCmd gUnknown_085CE99C[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 64),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE9AC[] =
{
    gUnknown_085CE99C,
};

const struct SpriteTemplate gUnknown_085CE9B0 =
{
    .tileTag = ANIM_TAG_RECYCLE,
    .paletteTag = ANIM_TAG_RECYCLE,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE9AC,
    .callback = sub_81603A8,
};

const union AffineAnimCmd gUnknown_085CE9C8[] =
{
    AFFINEANIMCMD_FRAME(0, 16, 0, 4),
    AFFINEANIMCMD_FRAME(-2, 0, 0, 8),
    AFFINEANIMCMD_FRAME(0, 4, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(1, -5, 0, 16),
    AFFINEANIMCMD_END,
};

void sub_815A0D4(struct Sprite *sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];

    if (!gBattleAnimArgs[3])
        sprite->data[0] = gBattleAnimArgs[2];
    else
        sprite->data[0] = -gBattleAnimArgs[2];

    sprite->data[1] = gBattleAnimArgs[4];
    sprite->callback = sub_815A114;
}

static void sub_815A114(struct Sprite *sprite)
{
    if (sprite->data[1] > 0)
    {
        sprite->pos2.x = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[0];
        sprite->invisible ^= 1;
        sprite->data[1]--;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_815A160(u8 taskId)
{
    sub_807521C(
        GetBattlerSpriteCoord(gBattleAnimTarget, 2) + 8,
        GetBattlerSpriteCoord(gBattleAnimTarget, 3) + 8,
        0);
    DestroyAnimVisualTask(taskId);
}

void sub_815A1B0(struct Sprite *sprite)
{
    sprite->data[0] = 90;
    sprite->callback = WaitAnimForDuration;
    sprite->data[1] = 7;
    StoreSpriteCallbackInData6(sprite, sub_815A1F4);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], 16 - sprite->data[1]));
}

static void sub_815A1F4(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], 16 - sprite->data[1]));
    if (--sprite->data[1] < 0)
    {
        sprite->invisible = 1;
        sprite->callback = sub_815A234;
    }
}

static void sub_815A234(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void sub_815A254(struct Sprite *sprite)
{
    u16 rotation;
    u8 x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    u8 y = GetBattlerSpriteCoord(gBattleAnimTarget, 3);

    sub_80A6980(sprite, TRUE);

    rotation = ArcTan2Neg(sprite->pos1.x - x, sprite->pos1.y - y);
    rotation += 0x6000;
    if (IsContest())
        rotation += 0x4000;

    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = x;
    sprite->data[4] = y;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void sub_815A2F0(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    sprite->data[0] = 4;
    sprite->callback = sub_815A31C;
}

static void sub_815A31C(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]));

    if (sprite->data[1])
        sprite->data[0]--;
    else
        sprite->data[0]++;

    if (sprite->data[0] == 15 || sprite->data[0] == 4)
        sprite->data[1] ^= 1;

    if (sprite->data[2]++ > 70)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        StartSpriteAffineAnim(sprite, 1);
        sprite->data[2] = 0;
        sprite->invisible = 1;
        sprite->affineAnimPaused = 1;
        sprite->callback = sub_815A3AC;
    }
}

static void sub_815A3AC(struct Sprite *sprite)
{
    if (sprite->data[2]++ > 9)
    {
        sprite->invisible = 0;
        sprite->affineAnimPaused = 0;
        if (sprite->affineAnimEnded)
            sprite->callback = sub_815A3F0;
    }
}

static void sub_815A3F0(struct Sprite *sprite)
{
    switch (sprite->data[3])
    {
    case 0:
    case 1:
        sprite->pos2.x = 1;
        sprite->pos2.y = 0;
        break;
    case 2:
    case 3:
        sprite->pos2.x = -1;
        sprite->pos2.y = 0;
        break;
    case 4:
    case 5:
        sprite->pos2.x = 0;
        sprite->pos2.y = 1;
        break;
    case 6:
    default:
        sprite->pos2.x = 0;
        sprite->pos2.y = -1;
        break;
    }

    if (++sprite->data[3] > 7)
        sprite->data[3] = 0;

    if (sprite->data[4]++ > 15)
    {
        sprite->data[0] = 16;
        sprite->data[1] = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 0));
        sprite->callback = sub_815A49C;
    }
}

static void sub_815A49C(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]));

    if (sprite->data[1]++ > 1)
    {
        sprite->data[0]--;
        sprite->data[1] = 0;
    }

    if (sprite->data[0] == 0)
        sprite->invisible = 1;

    if (sprite->data[0] < 0)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimSprite(sprite);
    }
}

void sub_815A504(u8 taskId)
{
    gTasks[taskId].func = sub_815A52C;
    gAnimVisualTaskCount--;
}

static void sub_815A52C(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = sub_80A6D94();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[paletteIndex * 16 + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[paletteIndex * 16 + i + 1] = gPlttBufferFaded[paletteIndex * 16 + i];

        gPlttBufferFaded[paletteIndex * 16 + 1] = lastColor;
        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

void sub_815A5C8(u8 taskId)
{
    gTasks[taskId].func = sub_815A5F0;
    gAnimVisualTaskCount--;
}

static void sub_815A5F0(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = sub_80A6D94();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[paletteIndex * 16 + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[paletteIndex * 16 + i + 1] = gPlttBufferFaded[paletteIndex * 16 + i];
        gPlttBufferFaded[paletteIndex * 16 + 1] = lastColor;

        lastColor = gPlttBufferUnfaded[paletteIndex * 16 + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferUnfaded[paletteIndex * 16 + i + 1] = gPlttBufferUnfaded[paletteIndex * 16 + i];
        gPlttBufferUnfaded[paletteIndex * 16 + 1] = lastColor;

        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

void sub_815A6C4(struct Sprite *sprite)
{
    u16 x;
    u16 y;

    InitAnimSpritePos(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &x, &y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = x + gBattleAnimArgs[2];
    sprite->data[4] = y + gBattleAnimArgs[3];
    sprite->data[5] = -50;

    InitAnimArcTranslation(sprite);
    sprite->callback = sub_815A73C;
}

static void sub_815A73C(struct Sprite *sprite)
{
    if (TranslateAnimArc(sprite))
    {
        sprite->data[0] = 30;
        sprite->data[1] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, sub_815A76C);
    }
}

static void sub_815A76C(struct Sprite *sprite)
{
    if (sprite->data[1] & 1)
        sprite->invisible ^= 1;

    if (++sprite->data[1] == 16)
        DestroyAnimSprite(sprite);
}

void sub_815A7B0(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    sub_80A6864(sprite, gBattleAnimArgs[0]);
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// This is likely fakematching due to some strange type casting behavior.
void sub_815A7EC(struct Sprite *sprite)
{
    int var0;
    int var1;
    if (sprite->data[0] == 0)
    {
        SetSpriteCoordsToAnimAttackerCoords(sprite);
        sub_80A6864(sprite, gBattleAnimArgs[0]);
        if (!IsContest())
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            {
                sprite->data[1] = gBattleAnimArgs[2];
                sprite->data[2] = gBattleAnimArgs[3];
            }
            else
            {
                var1 = -gBattleAnimArgs[2];
                sprite->data[1] = var1;
                var1 = -gBattleAnimArgs[3];
                sprite->data[2] = var1;
            }
        }
        else
        {
            var1 = -gBattleAnimArgs[2];
            sprite->data[1] = var1;
            sprite->data[2] = gBattleAnimArgs[3];
        }
    }

    sprite->data[0]++;
    var0 = (sprite->data[0] * 20) & 0xFF;
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    sprite->pos2.x = (sprite->data[3] + (s32)((u32)sprite->data[3] >> 31)) >> 1;
    sprite->pos2.y = Sin(var0 & 0xFF, 5) + ((s32)(sprite->data[4] + ((u32)sprite->data[4] >> 31)) >> 1);

    if ((u16)(sprite->pos1.x + sprite->pos2.x) > 240)
        DestroyAnimSprite(sprite);
}

void sub_815A8AC(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

void AnimTask_IsTargetPlayerSide(u8 taskId)
{
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT)
        gBattleAnimArgs[7] = 0;
    else
        gBattleAnimArgs[7] = 1;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_IsHealingMove(u8 taskId)
{
    if (gAnimMoveDmg > 0)
        gBattleAnimArgs[7] = 0;
    else
        gBattleAnimArgs[7] = 1;

    DestroyAnimVisualTask(taskId);
}

void sub_815A934(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    sub_80A6980(sprite, FALSE);

    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = 1;
    sprite->callback = sub_815A9A0;
}

static void sub_815A9A0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->invisible = 0;
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
        break;
    case 1:
    case 3:
        sprite->data[1] += 117;
        sprite->pos2.x = sprite->data[1] >> 8;
        if (++sprite->data[2] == 21)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1] -= 117;
        sprite->pos2.x = sprite->data[1] >> 8;
        if (++sprite->data[2] == 41)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        ChangeSpriteAffineAnim(sprite, 1);
        sprite->data[0]++;
        break;
    case 5:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = 1;
            sprite->callback = sub_815AA6C;
        }
        break;
    }
}

static void sub_815AA6C(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
    DestroyAnimSprite(sprite);
}

void sub_815AAA4(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
    }

    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->oam.tileNum += 16;

    if (gBattleAnimArgs[2] == 0)
    {
        sprite->oam.matrixNum = 8;
        sprite->pos2.x = -12;
        sprite->data[1] = 2;
    }
    else
    {
        sprite->pos2.x = 12;
        sprite->data[1] = -2;
    }

    sprite->data[0] = gBattleAnimArgs[4];

    if (sprite->data[3] != 255)
        sprite->data[3] = gBattleAnimArgs[2];

    sprite->callback = sub_815AB5C;
}

static void sub_815AB5C(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->pos2.x += sprite->data[1];
        if (sprite->pos2.x == 0)
        {
            sprite->data[2]++;
            if (sprite->data[3] == 0)
            {
                PlaySE1WithPanning(SE_W227, BattleAnimAdjustPanning(-64));
            }
        }
    }
    else
    {
        sprite->pos2.x -= sprite->data[1];
        if (abs(sprite->pos2.x) == 12)
        {
            sprite->data[0]--;
            sprite->data[2]--;
        }

    }

    if (sprite->data[0] == 0)
        DestroyAnimSprite(sprite);
}

void sub_815ABD0(struct Sprite *sprite)
{
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->data[3] = 255;
    sub_815AAA4(sprite);
}

void sub_815ABEC(u8 taskId)
{
    if (IsContest())
    {
        SetGpuReg(REG_OFFSET_WININ, 0x1F3F);
        gBattle_WIN1H = 0x98F0;
        gBattle_WIN1V = 0x00A0;
        SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN0H);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN0V);
    }
    else
    {
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        gBattle_WIN1H = 0x00F0;
        gBattle_WIN1V = 0x78A0;
        SetGpuReg(REG_OFFSET_WIN1H, 0x00F0);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
    }

    DestroyAnimVisualTask(taskId);
}

void sub_815AC8C(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
    if (!IsContest())
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);

    DestroyAnimVisualTask(taskId);
}

void sub_815ACD0(struct Sprite *sprite)
{
    int var0;
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0) + gBattleAnimArgs[1];
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 0) + gBattleAnimArgs[1];
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1);
    }

    sprite->pos2.y = gBattleAnimArgs[2];
    var0 = 0;
    if (sprite->pos2.y > gBattleAnimArgs[3])
        var0 = 1;

    sprite->data[0] = var0;
    sprite->data[1] = 0;
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = sub_815AD4C;
}

static void sub_815AD4C(struct Sprite *sprite)
{
    sprite->data[1] = (sprite->data[1] + sprite->data[2]) & 0xFF;
    sprite->pos2.x = gSineTable[sprite->data[1]] >> 4;
    sprite->pos2.y += sprite->data[3];

    if (sprite->data[0])
    {
        if (sprite->pos2.y < sprite->data[4])
            DestroyAnimSprite(sprite);
    }
    else
    {
        if (sprite->pos2.y > sprite->data[4])
            DestroyAnimSprite(sprite);
    }
}

void sub_815ADB0(u8 taskId)
{
    s16 var0;
    u8 toBG2;
    s16 var2;
    int var3;
    int var4;
    s16 i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[0])
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
        toBG2 = sub_80A8364(gBattleAnimAttacker);
    }
    else
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimTarget);
        toBG2 = sub_80A8364(gBattleAnimTarget);
    }

    task->data[0] = var0 + 36;
    task->data[1] = task->data[0];
    task->data[2] = var0 - 33;
    if (task->data[2] < 0)
        task->data[2] = 0;

    task->data[3] = task->data[0];
    task->data[4] = 8;
    task->data[5] = gBattleAnimArgs[1];
    task->data[6] = 0;
    task->data[7] = 0;

    if (toBG2 == 1)
    {
        var3 = gBattle_BG1_X;
        task->data[8] = var3;
        var4 = var3 + 240;
    }
    else
    {
        var3 = gBattle_BG2_X;
        task->data[8] = var3;
        var4 = var3 + 240;
    }

    task->data[9] = var4;
    task->data[10] = gBattleAnimArgs[2];

    if (!gBattleAnimArgs[2])
    {
        task->data[11] = var4;
        var2 = task->data[8];
    }
    else
    {
        task->data[11] = var3;
        var2 = task->data[9];
    }

    task->data[15] = 0;

    i = task->data[2];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = var2;
        gScanlineEffectRegBuffers[1][i] = var2;
        i++;
    }

    if (toBG2 == 1)
        scanlineParams.dmaDest = &REG_BG1HOFS;
    else
        scanlineParams.dmaDest = &REG_BG2HOFS;

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);

    task->func = sub_815AED8;
}

static void sub_815AED8(u8 taskId)
{
    s16 i;
    struct Task *task = &gTasks[taskId];

    task->data[0] -= task->data[5];
    if (task->data[0] < task->data[2])
        task->data[0] = task->data[2];

    if (task->data[4] == 0)
    {
        task->data[1] -= task->data[5];
        if (task->data[1] < task->data[2])
        {
            task->data[1] = task->data[2];
            task->data[15] = 1;
        }
    }
    else
    {
        task->data[4]--;
    }

    if (++task->data[6] > 1)
    {
        task->data[6] = 0;
        task->data[7] = task->data[7] == 0 ? 1 : 0;

        if (task->data[7])
            task->data[12] = task->data[8];
        else
            task->data[12] = task->data[9];        
    }

    i = task->data[0];
    while (i < task->data[1])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[12];
        gScanlineEffectRegBuffers[1][i] = task->data[12];
        i++;
    }

    i = task->data[1];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[11];
        gScanlineEffectRegBuffers[1][i] = task->data[11];
        i++;
    }

    if (task->data[15])
    {
        if (task->data[10])
            gScanlineEffect.state = 3;

        DestroyAnimVisualTask(taskId);
    }
}

void sub_815AFF0(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    task->data[4] = 32;
    task->data[5] = -20;
    task->data[6] = 0;
    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->func = sub_815B054;
}

static void sub_815B054(u8 taskId)
{
    int var0, var1;
    s16 x, y;
    u16 i, j;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        var0 = task->data[2];
        if (task->data[1] & 1)
        {
            var1 = task->data[4];
            x = var0 - var1;
        }
        else
        {
            var1 = task->data[4];
            x = var0 + var1;
        }

        y = task->data[3] + task->data[5];
        spriteId = CreateSprite(&gUnknown_08593114, x, y, 6 - task->data[1]);
        PlaySE12WithPanning(SE_W118, BattleAnimAdjustPanning(-64));

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].hFlip = task->data[1] & 1;
            gSprites[spriteId].callback = SpriteCallbackDummy;
        }

        if (task->data[1] & 1)
        {
            task->data[4] -= 6;
            task->data[5] -= 6;
        }

        PrepareAffineAnimInTaskData(task, task->data[15], gUnknown_085CE2A0);
        task->data[1]++;
        task->data[0] = 1;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(task))
        {
            if (task->data[1] == 6)
            {
                task->data[6] = 8;
                task->data[0] = 3;
            }
            else
            {
                if (task->data[1] <= 2)
                    task->data[6] = 10;
                else
                    task->data[6] = 0;

                task->data[0] = 2;
            }
        }
        break;
    case 2:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 0;
        break;
    case 3:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 4;
        break;
    case 4:
        for (i = 0, j = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].template == &gUnknown_08593114)
            {
                gSprites[i].data[0] = taskId;
                gSprites[i].data[1] = 6;
                StartSpriteAnim(&gSprites[i], 2);
                gSprites[i].callback = sub_815B23C;

                if (++j == 6)
                    break;
            }
        }

        task->data[6] = j;
        task->data[0] = 5;
        break;
    case 5:
        if (task->data[6] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void sub_815B23C(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[0]].data[sprite->data[1]]--;
        DestroySprite(sprite);
    }
}

void sub_815B27C(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
        InitAnimSpritePos(sprite, FALSE);

    if (++sprite->data[0] < 40)
    {
        u16 var = sprite->data[0];
        if ((var & 1) == 0)
            sprite->invisible = 1;
        else
            sprite->invisible = 0;
    }

    if (sprite->data[0] > 30)
        sprite->invisible = 0;

    if (sprite->data[0] == 61)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[0] = 20;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
        sprite->callback = StartAnimLinearTranslation;
    }
}

void sub_815B338(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gUnknown_085CE350);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815B394(struct Sprite *sprite)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        sprite->data[1] = 256;
        sprite->data[2] = 256;
        sprite->data[0]++;
        break;
    case 1:
        sprite->data[1] += 96;
        sprite->data[2] -= 26;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 5)
            sprite->data[0]++;
        // fall through
    case 2:
        sprite->data[1] += 96;
        sprite->data[2] += 48;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 9)
        {
            sprite->data[3] = 0;
            gSprites[spriteId].invisible = 1;
            ResetSpriteRotScale(spriteId);
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->pos2.y -= 6;
        if (sprite->pos1.y + sprite->pos2.y < -32)
            DestroyAnimSprite(sprite);
        break;
    }
}

void sub_815B49C(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos1.x = -16;
    else
        sprite->pos1.x = 256;

    sprite->pos1.y = 0;
    sprite->callback = sub_815B4D4;
}

static void sub_815B4D4(struct Sprite *sprite)
{
    u32 newX;

    sprite->data[0] += 72;
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos2.x = sprite->data[0] >> 4;
    else
        sprite->pos2.x = -(sprite->data[0] >> 4);

    sprite->data[1] += 16;
    sprite->pos2.y += sprite->data[1] >> 8;

    if (++sprite->data[2] % 3 == 0)
    {
        CreateSpriteAndAnimate(
            &gUnknown_085CE3A0,
            sprite->pos1.x + sprite->pos2.x,
            sprite->pos1.y + sprite->pos2.y,
            sprite->subpriority + 1);
    }

    newX = sprite->pos1.x + sprite->pos2.x + 32;
    if (newX > 304)
        DestroyAnimSprite(sprite);
}

void sub_815B570(struct Sprite *sprite)
{
    u8 rand;
    s8 y;

    rand = Random2() & 3;
    if (rand == 0)
        sprite->oam.tileNum += 4;
    else
        sprite->oam.tileNum += 5;

    y = Random2() & 7;
    if (y > 3)
        y = -y;

    sprite->pos2.y = y;
    sprite->callback = sub_815B5D0;
}

static void sub_815B5D0(struct Sprite *sprite)
{
    if (++sprite->data[0] < 30)
    {
        if (++sprite->data[1] == 2)
        {
            sprite->invisible ^= 1;
            sprite->data[1] = 0;
        }
    }
    else
    {
        if (sprite->data[1] == 2)
            sprite->invisible = 0;

        if (sprite->data[1] == 3)
        {
            sprite->invisible = 1;
            sprite->data[1] = -1;
        }

        sprite->data[1]++;
    }

    if (sprite->data[0] > 60)
        DestroySprite(sprite);
}

void sub_815B65C(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gUnknown_085CE3B8);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void sub_815B6B4(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gUnknown_085CE3E0);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void sub_815B70C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        InitAnimSpritePos(sprite, FALSE);
        sprite->data[1] = 0x900;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
        sprite->data[0]++;
        break;
    case 1:
        sprite->pos2.y -= sprite->data[1] >> 8;
        sprite->data[1] -= 96;
        if (sprite->pos1.y + sprite->pos2.y > sprite->data[2])
            DestroyAnimSprite(sprite);
        break;
    }
}

void sub_815B778(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gUnknown_085CE430);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void sub_815B7D0(u8 taskId)
{
    int i, j;
    u8 position;
    struct UnknownAnimStruct2 unknownStruct;
    u8 *dest;
    u8 *src;
    u16 *unk4;
    u16 stretch;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        if (sub_80A8364(gBattleAnimAttacker) == 1)
            SetAnimBgAttribute(1, BG_ANIM_MOSAIC, 1);
        else
            SetAnimBgAttribute(2, BG_ANIM_MOSAIC, 1);

        gTasks[taskId].data[10] = gBattleAnimArgs[0];
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[2]++ > 1)
        {
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[1]++;
            stretch = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 4) | stretch);
            if (stretch == 15)
                gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        HandleSpeciesGfxDataChange(gBattleAnimAttacker, gBattleAnimTarget, gTasks[taskId].data[10]);
        sub_80A6BFC(&unknownStruct, gBattleAnimAttacker);

        if (IsContest())
            position = 0;
        else
            position = GetBattlerPosition(gBattleAnimAttacker);

        src = gMonSpritesGfxPtr->sprites[position] + (gBattleMonForms[gBattleAnimAttacker] << 11);
        dest = unknownStruct.bgTiles;
        CpuCopy32(src, dest, 0x800);
        LoadBgTiles(1, unknownStruct.bgTiles, 0x800, unknownStruct.tilesOffset);
        if (IsContest())
        {
            if (IsSpeciesNotUnown(gContestResources->field_18->species) != IsSpeciesNotUnown(gContestResources->field_18->unk2))
            {
                unk4 = (u16 *)unknownStruct.unk4;
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        u16 temp = unk4[j + i * 0x20];
                        unk4[j + i * 0x20] = unk4[(7 - j) + i * 0x20];
                        unk4[(7 - j) + i * 0x20] = temp;
                    }
                }

                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                       unk4[j + i * 0x20] ^= 0x400;
                    }
                }
            }

            if (IsSpeciesNotUnown(gContestResources->field_18->unk2))
                gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gUnknown_082FF6C0;
            else
                gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gUnknown_082FF694;

            StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], 0);
        }

        gTasks[taskId].data[0]++;
        break;
    case 3:
        if (gTasks[taskId].data[2]++ > 1)
        {
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[1]--;
            stretch = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 4) | stretch);

            if (stretch == 0)
                gTasks[taskId].data[0]++;
        }
        break;
    case 4:
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        if (sub_80A8364(gBattleAnimAttacker) == 1)
            SetAnimBgAttribute(1, BG_ANIM_MOSAIC, 0);
        else
            SetAnimBgAttribute(2, BG_ANIM_MOSAIC, 0);

        if (!IsContest())
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            {
                if (gTasks[taskId].data[10] == 0)
                    SetBattlerShadowSpriteCallback(gBattleAnimAttacker, gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies);
            }
        }

        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815BB18(u8 taskId)
{
    gBattleAnimArgs[7] = gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].invisible;
    DestroyAnimVisualTask(taskId);
}

void sub_815BB58(u8 taskId)
{
    HandleSpeciesGfxDataChange(gBattleAnimAttacker, gBattleAnimTarget, TRUE);
    DestroyAnimVisualTask(taskId);
}

void sub_815BB84(u8 taskId)
{
    struct UnknownAnimStruct2 unknownStruct;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

        sub_80A6B30(&unknownStruct);
        sub_80A6D60(&unknownStruct, &gUnknown_08C2A6EC, 0);
        if (IsContest())
        {
            gBattle_BG1_X = -56;
            gBattle_BG1_Y = 0;
        }
        else
        {
            if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
                gBattle_BG1_X = -135;
            else
                gBattle_BG1_X = -10;

            gBattle_BG1_Y = 0;
        }

        sub_80A6CC0(unknownStruct.bgId, gUnknown_08C2A634, unknownStruct.tilesOffset);
        LoadCompressedPalette(gUnknown_08C2A6D4, unknownStruct.unk8 << 4, 32);

        gTasks[taskId].data[10] = gBattle_BG1_X;
        gTasks[taskId].data[11] = gBattle_BG1_Y;

        gTasks[taskId].data[0]++;
        PlaySE12WithPanning(SE_W234, BattleAnimAdjustPanning(-64));
        break;
    case 1:
        if (gTasks[taskId].data[4]++ > 0)
        {
            gTasks[taskId].data[4] = 0;
            if (++gTasks[taskId].data[1] > 12)
                gTasks[taskId].data[1] = 12;
            
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

            if (gTasks[taskId].data[1] == 12)
                gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        if (--gTasks[taskId].data[1] < 0)
            gTasks[taskId].data[1] = 0;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

        if (!gTasks[taskId].data[1])
        {
            gBattle_BG1_X = gUnknown_085CE460[gTasks[taskId].data[2]] + gTasks[taskId].data[10];
            if (++gTasks[taskId].data[2] == 4)
                gTasks[taskId].data[0] = 4;
            else
                gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (++gTasks[taskId].data[3] == 4)
        {
            gTasks[taskId].data[3] = 0;
            gTasks[taskId].data[0] = 1;
            PlaySE12WithPanning(SE_W234, BattleAnimAdjustPanning(-64));
        }
        break;
    case 4:
        sub_80A6B30(&unknownStruct);
        sub_80A6C68(unknownStruct.bgId);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815BE04(struct Sprite *sprite)
{
    s16 xOffset;
    u8 spriteId1;
    u8 spriteId2;

    xOffset = Random2();
    xOffset &= 0x3F;
    if (xOffset > 31)
        xOffset = 32 - xOffset;
    
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0) + xOffset;
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 32;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];

    spriteId1 = CreateSprite(&gUnknown_085CE48C, sprite->pos1.x, sprite->pos1.y, sprite->subpriority + 1);
    spriteId2 = CreateSprite(&gUnknown_085CE48C, sprite->pos1.x, sprite->pos1.y, sprite->subpriority + 1);
    StartSpriteAnim(&gSprites[spriteId1], 1);
    StartSpriteAnim(&gSprites[spriteId2], 2);

    gSprites[spriteId1].data[1] = gBattleAnimArgs[0];
    gSprites[spriteId1].data[2] = gBattleAnimArgs[1];
    gSprites[spriteId2].data[1] = gBattleAnimArgs[0];
    gSprites[spriteId2].data[2] = gBattleAnimArgs[1];
    gSprites[spriteId1].data[7] = -1;
    gSprites[spriteId2].data[7] = -1;
    gSprites[spriteId1].invisible = 1;
    gSprites[spriteId2].invisible = 1;
    gSprites[spriteId1].callback = sub_815C050;
    gSprites[spriteId2].callback = sub_815C050;

    sprite->data[6] = spriteId1;
    sprite->data[7] = spriteId2;
    sprite->callback = sub_815BF44;
}

static void sub_815BF44(struct Sprite *sprite)
{
    int var0;
    s8 var1;
    
    var0 = (u16)sprite->data[2] + (u16)sprite->data[3];
    var1 = var0 >> 8;
    sprite->pos2.y -= var1;
    sprite->data[3] = var0 & 0xFF;
    if (sprite->data[4] == 0 && sprite->pos2.y < -8)
    {
        gSprites[sprite->data[6]].invisible = 0;
        sprite->data[4]++;
    }

    if (sprite->data[4] == 1 && sprite->pos2.y < -16)
    {
        gSprites[sprite->data[7]].invisible = 0;
        sprite->data[4]++;
    }

    if (--sprite->data[1] == -1)
    {
        sprite->invisible = 1;
        sprite->callback = sub_815BFF4;
    }
}

static void sub_815BFF4(struct Sprite *sprite)
{
    if (gSprites[sprite->data[6]].callback == SpriteCallbackDummy
     && gSprites[sprite->data[7]].callback == SpriteCallbackDummy)
    {
        DestroySprite(&gSprites[sprite->data[6]]);
        DestroySprite(&gSprites[sprite->data[7]]);
        DestroyAnimSprite(sprite);
    }
}

static void sub_815C050(struct Sprite *sprite)
{
    u16 d2;
    register u16 d3 asm("r1");
    int var0;
    s8 var1;
    
    if (!sprite->invisible)
    {
        d2 = sprite->data[2];
        d3 = sprite->data[3];
        var0 = d2 + d3;
        var1 = var0 >> 8;
        sprite->pos2.y -= var1;
        sprite->data[3] = var0 & 0xFF;
        if (--sprite->data[1] == -1)
        {
            sprite->invisible = 1;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_815C0A4(u8 taskId)
{
    struct UnknownAnimStruct2 unknownStruct;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, 13));
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

        sub_80A6B30(&unknownStruct);
        sub_80A6D60(&unknownStruct, &gUnknown_08C2A6EC, 0);
        if (IsContest())
        {
            gBattle_BG1_X = -56;
            gBattle_BG1_Y = 0;
        }
        else
        {
            u8 position = GetBattlerPosition(gBattleAnimTarget);
            if (IsDoubleBattle() == TRUE)
            {
                if (position == B_POSITION_OPPONENT_LEFT)
                    gBattle_BG1_X = -155;
                if (position == B_POSITION_OPPONENT_RIGHT)
                    gBattle_BG1_X = -115;
                if (position == B_POSITION_PLAYER_LEFT)
                    gBattle_BG1_X = 14;
                if (position == B_POSITION_PLAYER_RIGHT)
                    gBattle_BG1_X = -20;
            }
            else
            {
                if (position == B_POSITION_OPPONENT_LEFT)
                    gBattle_BG1_X = -135;
                if (position == B_POSITION_PLAYER_LEFT)
                    gBattle_BG1_X = -10;
            }

            gBattle_BG1_Y = 0;
        }

        sub_80A6CC0(unknownStruct.bgId, gUnknown_08C2A634, unknownStruct.tilesOffset);
        LoadCompressedPalette(gUnknown_08C2A6D4, unknownStruct.unk8 << 4, 32);
        gTasks[taskId].data[10] = gBattle_BG1_X;
        gTasks[taskId].data[11] = gBattle_BG1_Y;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[3] = 0;
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT)
            gBattle_BG1_X = gTasks[taskId].data[10] + gUnknown_085CE4A4[gTasks[taskId].data[2]];
        else
            gBattle_BG1_X = gTasks[taskId].data[10] - gUnknown_085CE4A4[gTasks[taskId].data[2]];

        if (++gTasks[taskId].data[2] == 5)
            gTasks[taskId].data[0] = 5;
        else
            gTasks[taskId].data[0]++;
        break;
    case 2:
        if (--gTasks[taskId].data[1] <= 4)
            gTasks[taskId].data[1] = 5;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 5)
            gTasks[taskId].data[0]++;
        break;
    case 3:
        if (++gTasks[taskId].data[3] > gUnknown_085CE4A8[gTasks[taskId].data[2]])
            gTasks[taskId].data[0]++;
        break;
    case 4:
        if (++gTasks[taskId].data[1] > 13)
            gTasks[taskId].data[1] = 13;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 13)
            gTasks[taskId].data[0] = 1;
        break;
    case 5:
        sub_80A6B30(&unknownStruct);
        sub_80A6C68(unknownStruct.bgId);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);
        
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815C3A8(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(0), gUnknown_085CE4B0);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void sub_815C400(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        InitAnimSpritePos(sprite, 0);
        sprite->data[0]++;
    }
    else if (sprite->data[0]++ > 20)
    {
        sprite->data[1] += 160;
        sprite->data[2] += 128;

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            sprite->pos2.x = -(sprite->data[1] >> 8);
        else
            sprite->pos2.x = sprite->data[1] >> 8;

        sprite->pos2.y += sprite->data[2] >> 8;
        if (sprite->pos2.y > 64)
            DestroyAnimSprite(sprite);
    }
}

void sub_815C478(u8 taskId)
{
    u8 side;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    if (gBattleAnimArgs[2] < 0)
        gBattleAnimArgs[2] = 0;
    if (gBattleAnimArgs[2] > 2)
        gBattleAnimArgs[2] = 2;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 8 - (2 * gBattleAnimArgs[2]);
    task->data[4] = 0x100 + (gBattleAnimArgs[2] * 128);
    task->data[5] = gBattleAnimArgs[2] + 2;
    task->data[6] = gBattleAnimArgs[1] - 1;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    if (!gBattleAnimArgs[0])
        side = GetBattlerSide(gBattleAnimAttacker);
    else
        side = GetBattlerSide(gBattleAnimTarget);

    if (side == B_SIDE_OPPONENT)
    {
        task->data[4] *= -1;
        task->data[5] *= -1;
    }

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = sub_815C548;
}

static void sub_815C548(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gSprites[task->data[15]].pos2.x += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        gSprites[task->data[15]].pos2.x -= task->data[5];
        task->data[2] += task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3] * 2)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        gSprites[task->data[15]].pos2.x += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            if (task->data[6])
            {
                task->data[6]--;
                task->data[1] = 0;
                task->data[0] = 0;
            }
            else
            {
                task->data[0]++;
            }
        }
        break;
    case 3:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815C6B0(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->pos1.x = 0;
        sprite->pos1.y = gBattleAnimArgs[0];
    }
    else
    {
        sprite->pos1.x = 240;
        sprite->pos1.y = gBattleAnimArgs[0] - 30;
    }

    sprite->data[2] = gBattleAnimArgs[2];
    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    sprite->callback = sub_815C700;
}

static void sub_815C700(struct Sprite *sprite)
{
    sprite->data[0] += 3;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->pos1.x += 5;
        sprite->pos1.y -= 1;

        if (sprite->pos1.x > 240)
            DestroyAnimSprite(sprite);

        sprite->pos2.y = Sin(sprite->data[0] & 0xFF, 16);
    }
    else
    {
        sprite->pos1.x -= 5;
        sprite->pos1.y += 1;

        if (sprite->pos1.x < 0)
            DestroyAnimSprite(sprite);

        sprite->pos2.y = Cos(sprite->data[0] & 0xFF, 16);
    }
}

void sub_815C770(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[12] = 0x20;
    task->data[13] = 0x40;
    task->data[14] = 0x800;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = sub_815C7C4;
}

static void sub_815C7C4(u8 taskId)
{
    int temp;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[2] += 0x200;
        if (task->data[2] >= task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((div & 1) == 0)
            {
                task->data[2] = task->data[14] - mod;
                task->data[0] = 1;
            }
            else
            {
                task->data[2] = mod - task->data[14];
            }
        }
        break;
    case 1:
        task->data[2] -= 0x200;
        if (task->data[2] <= -task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((1 & div) == 0)
            {
                task->data[2] = mod - task->data[14];
                task->data[0] = 0;
            }
            else
            {
                task->data[2] = task->data[14] - mod;
            }
        }
        break;
    case 2:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        return;
    }

    SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
    SetBattlerSpriteYOffsetFromRotation(task->data[15]);
    gSprites[task->data[15]].pos2.x = -(((temp = task->data[2]) >= 0 ? task->data[2] : temp + 63) >> 6);
    
    if (++task->data[1] > 8)
    {
        if (task->data[12])
        {
            task->data[12]--;
            task->data[14] -= task->data[13];
            if (task->data[14] < 16)
                task->data[14] = 16;
        }
        else
        {
            task->data[0] = 2;
        }
    }
}

void sub_815C95C(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        if (!gBattleAnimArgs[2])
        {
            sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
            sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
        }

        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[1] = 0x80;
        sprite->data[2] = 0x300;
        sprite->data[3] = gBattleAnimArgs[1];
        sprite->data[0]++;
    }
    else
    {
        sprite->pos2.x = sprite->data[1] >> 8;
        sprite->pos2.y += sprite->data[2] >> 8;
        if (sprite->data[4] == 0 && sprite->pos2.y > -sprite->data[3])
        {
            sprite->data[4] = 1;
            sprite->data[2] = (-sprite->data[2] / 3) * 2;
        }

        sprite->data[1] += 192;
        sprite->data[2] += 128;
        if (sprite->animEnded)
            DestroyAnimSprite(sprite);
    }
}

void sub_815CA20(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[0] == 0)
    {
        if (gBattleAnimArgs[0] == 0)
            gTasks[taskId].data[11] = gBattleAnimAttacker;
        else
            gTasks[taskId].data[11] = gBattleAnimTarget;

        spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        gTasks[taskId].data[10] = spriteId;
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);

        switch (gBattleAnimArgs[1])
        {
        case 0:
            SetSpriteRotScale(spriteId, 0xE0, 0x140, 0);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            break;
        case 1:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF00);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].pos2.y += 16;
            break;
        case 2:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF100);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].pos2.y += 16;
            break;
        }

        gSprites[spriteId].pos2.x = 2;
        gTasks[taskId].data[0]++;
    }
    else
    {
        spriteId = gTasks[taskId].data[10];
        if (++gTasks[taskId].data[2] == 3)
        {
            gTasks[taskId].data[2] = 0;
            gSprites[spriteId].pos2.x = -gSprites[spriteId].pos2.x;
        }

        if (++gTasks[taskId].data[1] == 13)
        {
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].pos2.x = 0;
            gSprites[spriteId].pos2.y = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
}

void sub_815CB88(struct Sprite *sprite)
{
    u8 tileOffset;
    int rand1;
    int rand2;

    tileOffset = Random2() % 12;
    sprite->oam.tileNum += tileOffset;
    rand1 = Random2() & 0x1FF;
    rand2 = Random2() & 0xFF;

    if (rand1 & 1)
        sprite->data[0] = 0x5E0 + rand1;
    else
        sprite->data[0] = 0x5E0 - rand1;

    if (rand2 & 1)
        sprite->data[1] = 0x480 + rand2;
    else
        sprite->data[1] = 0x480 - rand2;

    sprite->data[2] = gBattleAnimArgs[0];
    if (sprite->data[2] == 0)
        sprite->pos1.x = -8;
    else
        sprite->pos1.x = 248;

    sprite->pos1.y = 104;
    sprite->callback = sub_815CC34;
}

static void sub_815CC34(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->pos2.x += sprite->data[0] >> 8;
        sprite->pos2.y -= sprite->data[1] >> 8;
    }
    else
    {
        sprite->pos2.x -= sprite->data[0] >> 8;
        sprite->pos2.y -= sprite->data[1] >> 8;
    }

    sprite->data[0] -= 22;
    sprite->data[1] -= 48;
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;

    if (++sprite->data[3] == 31)
        DestroyAnimSprite(sprite);
}

void sub_815CC94(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    sprite->data[0] = gBattleAnimArgs[2];
    sub_80A6980(sprite, FALSE);
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = 1;
    sprite->callback = sub_815CD0C;
}

static void sub_815CD0C(struct Sprite *sprite)
{
    switch (sprite->data[1])
    {
    case 0:
        sprite->invisible = 0;
        if (sprite->affineAnimEnded)
            sprite->data[1]++;
        break;
    case 1:
        if (--sprite->data[0] == 0)
        {
            ChangeSpriteAffineAnim(sprite, 1);
            sprite->data[1]++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = 1;
            sprite->data[1]++;
        }
        break;
    case 3:
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
        DestroyAnimSprite(sprite);
        break;
    }
}

void sub_815CDB4(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->callback = sub_815CDFC;
    sprite->callback(sprite);
}

static void sub_815CDFC(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->pos2.y = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;

    if ((u16)sprite->data[1] < 64 || sprite->data[1] > 195)
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
    else
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + 1;

    if (!sprite->data[5])
    {
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
    }
    else if (sprite->data[5] == 1)
    {
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
            DestroyAnimSprite(sprite);
    }
}



extern void sub_815D160(u8);

void sub_815CED8(u8 taskId)
{
    u8 isBackPic;
    u32 personality;
    u32 otId;
    u16 species;
    s16 xOffset;
    u32 priority;
    u8 spriteId;
    s16 coord1, coord2;

    GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (IsContest())
    {
        isBackPic = 1;
        personality = gContestResources->field_18->unk10;
        otId = gContestResources->field_18->unkC;
        species = gContestResources->field_18->unk2;
        xOffset = 20;
        priority = sub_80A8328(gBattleAnimAttacker);
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            isBackPic = 0;
            personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = 20;
            priority = sub_80A8328(gBattleAnimAttacker);
        }
        else
        {
            isBackPic = 1;
            personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = -20;
            priority = sub_80A8328(gBattleAnimAttacker);
        }
    }

    coord1 = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
    coord2 = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
    spriteId = sub_80A8394(species, isBackPic, 0, coord1 + xOffset, coord2, 5, personality, otId, gBattleAnimTarget, 1);

    gSprites[spriteId].oam.priority = priority;
    gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    FillPalette(RGB(31, 31, 31), (gSprites[spriteId].oam.paletteNum << 4) + 0x100, 32);
    gSprites[spriteId].oam.priority = priority;
    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = sub_815D160;
}

void sub_815D160(u8 taskId)
{
    if (gTasks[taskId].data[10]++ > 1)
    {
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].data[1]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 10)
        {
            gTasks[taskId].data[10] = 256;
            gTasks[taskId].data[11] = 256;
            gTasks[taskId].func = sub_815D1BC;
        }
    }
}

static void sub_815D1BC(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    gTasks[taskId].data[10] -= 16;
    gTasks[taskId].data[11] += 128;
    gSprites[spriteId].oam.affineMode |= ST_OAM_AFFINE_DOUBLE_MASK;
    TrySetSpriteRotScale(&gSprites[spriteId], TRUE, gTasks[taskId].data[10], gTasks[taskId].data[11], 0);
    if (++gTasks[taskId].data[12] == 9)
    {
        sub_80A749C(&gSprites[spriteId]);
        sub_80A8610(&gSprites[spriteId]);
        gTasks[taskId].func = sub_80A6814;
    }
}

void sub_815D240(u8 taskId)
{
    u8 battler;
    u16 bgX, bgY;
    s16 y, i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 16;
    task->data[4] = 0;
    task->data[5] = battler;
    task->data[6] = 32;
    task->data[7] = 0;
    task->data[8] = 24;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        task->data[8] *= -1;

    task->data[13] = GetBattlerYCoordWithElevation(battler) - 34;
    if (task->data[13] < 0)
        task->data[13] = 0;

    task->data[14] = task->data[13] + 66;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    if (sub_80A8364(battler) == 1)
    {
        scanlineParams.dmaDest = &REG_BG1HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        scanlineParams.dmaDest = &REG_BG2HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2);
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    for (y = 0, i = 0; y < 160; y++, i += 2)
    {
        gScanlineEffectRegBuffers[0][i] = bgX;
        gScanlineEffectRegBuffers[1][i] = bgX;
        gScanlineEffectRegBuffers[0][i + 1] = bgY;
        gScanlineEffectRegBuffers[1][i + 1] = bgY;
    }

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_32BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);
    task->func = sub_815D398;
}

static void sub_815D398(u8 taskId)
{
    struct Task *task;
    s16 var1;
    s16 var2;
    s16 bgX, bgY;
    s16 offset;
    s16 var0;
    s16 i;
    s16 sineIndex;
    s16 var3;

    task = &gTasks[taskId];
    if (sub_80A8364(task->data[5]) == 1)
    {
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    switch (task->data[0])
    {
    case 0:
        offset = task->data[14] * 2;
        var1 = 0;
        var2 = 0;
        i = 0;
        task->data[1] = (task->data[1] + 2) & 0xFF;
        sineIndex = task->data[1];
        task->data[9] = 0x7E0 / task->data[6];
        task->data[10] = -((task->data[7] * 2) / task->data[9]);
        task->data[11] = task->data[7];
        var3 = task->data[11] >> 5;
        task->data[12] = var3;
        var0 = task->data[14];
        while (var0 > task->data[13])
        {
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset + 1] = (i - var2) + bgY;
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset] = bgX + var3 + (gSineTable[sineIndex] >> 5);
            sineIndex = (sineIndex + 10) & 0xFF;
            task->data[11] += task->data[10];
            var3 = task->data[11] >> 5;
            task->data[12] = var3;

            i++;
            offset -= 2;
            var1 += task->data[6];
            var2 = var1 >> 5;
            var0--;
        }

        var0 *= 2;
        while (var0 >= 0)
        {
            gScanlineEffectRegBuffers[0][var0] = bgX + 240;
            gScanlineEffectRegBuffers[1][var0] = bgX + 240;
            var0 -= 2;
        }

        if (++task->data[6] > 63)
        {
            task->data[6] = 64;
            task->data[2]++;
            if (task->data[2] & 1)
                task->data[3]--;
            else
                task->data[4]++;

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
            if (task->data[3] == 0 && task->data[4] == 16)
            {
                task->data[2] = 0;
                task->data[3] = 0;
                task->data[0]++;
            }
        }
        else
        {
            task->data[7] += task->data[8];
        }
        break;
    case 1:
        if (++task->data[2] > 12)
        {
            gScanlineEffect.state = 3;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        task->data[2]++;
        if (task->data[2] & 1)
            task->data[3]++;
        else
            task->data[4]--;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
        if (task->data[3] == 16 && task->data[4] == 0)
        {
            task->data[2] = 0;
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815D64C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(&gTasks[taskId], task->data[15], gUnknown_085CE5F0);
    task->func = sub_815D694;
}

static void sub_815D694(u8 taskId)
{
    u16 var0;

    struct Task *task = &gTasks[taskId];
    var0 = task->data[0];
    task->data[0]++;
    var0 -= 20;
    if (var0 < 23)
    {
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            if (task->data[2] & 1)
                gSprites[task->data[15]].pos2.x = 1;
            else
                gSprites[task->data[15]].pos2.x = -1;
        }
    }
    else
    {
        gSprites[task->data[15]].pos2.x = 0;
    }

    if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        DestroyAnimVisualTask(taskId);
}

void sub_815D72C(struct Sprite *sprite, s16 b, s16 c, s16 d, s16 e, u16 f)
{
    sprite->pos1.x = b;
    sprite->pos1.y = c;
    sprite->data[4] = b << 4;
    sprite->data[5] = c << 4;
    sprite->data[6] = ((d - b) << 4) / f;
    sprite->data[7] = ((e - c) << 4) / f;
}

void sub_815D794(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[6];
    sprite->data[5] += sprite->data[7];
    sprite->pos1.x = sprite->data[4] >> 4;
    sprite->pos1.y = sprite->data[5] >> 4;
}

void sub_815D7B4(struct Sprite *sprite)
{
    s16 x = sprite->pos1.x;
    s16 y = sprite->pos1.y;

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    sub_815D72C(sprite, sprite->pos1.x, sprite->pos1.y, x, y, 64);
    sprite->data[0] = 0;
    sprite->callback = sub_815D804;
}

static void sub_815D804(struct Sprite *sprite)
{
    int index;

    sprite->data[0]++;
    index = (sprite->data[0] * 8) & 0xFF;
    sub_815D794(sprite);
    sprite->pos2.y = Sin(index, 8);
    if (sprite->data[0] > 58)
    {
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            sprite->invisible = sprite->data[2] & 1;
            if (sprite->data[2] > 3)
                DestroySpriteAndMatrix(sprite);
        }
    }
}

void sub_815D870(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[3];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) + gBattleAnimArgs[1];
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) + gBattleAnimArgs[2];
    sprite->callback = sub_810E2C8;
}

static void sub_815D8D8(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = 0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = gTasks[taskId].data[7];
    var1 = gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].pos2.x = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].pos2.x = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].pos2.y = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].pos2.y = gTasks[taskId].data[10] + (var1 >> 8);

    if (gTasks[taskId].data[0] < 1)
    {
        DestroyTask(taskId);
        gAnimVisualTaskCount--;
    }
}

static void sub_815DA20(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = var0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = (gTasks[taskId].data[2] & 0x7FFF) + gTasks[taskId].data[7];
    var1 = (gTasks[taskId].data[3] & 0x7FFF) + gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].pos2.x = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].pos2.x = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].pos2.y = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].pos2.y = gTasks[taskId].data[10] + (var1 >> 8);

    gTasks[taskId].data[7] = var0;
    gTasks[taskId].data[8] = var1;
    if (gTasks[taskId].data[0] < 1)
    {
        gTasks[taskId].data[0] = 30;
        gTasks[taskId].data[13] = 0;
        gTasks[taskId].func = sub_815D8D8;
    }
}

void sub_815DB90(u8 taskId)
{
    gTasks[taskId].data[15] = gBattlerSpriteIds[gBattleAnimAttacker];
    gTasks[taskId].data[14] = gBattleAnimArgs[0];
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[13] = gBattleAnimArgs[6];
    if (gBattleAnimArgs[3])
        gTasks[taskId].data[6] = gTasks[taskId].data[6] | -0x8000;

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
    }
    else
    {
        if (gBattleAnimArgs[1] & 0x8000)
            gTasks[taskId].data[2] = gBattleAnimArgs[1] & 0x7FFF;
        else
            gTasks[taskId].data[2] = gBattleAnimArgs[1] | -0x8000;

        if (gBattleAnimArgs[2] & 0x8000)
            gTasks[taskId].data[3] = gBattleAnimArgs[2] & 0x7FFF;
        else
            gTasks[taskId].data[3] = gBattleAnimArgs[2] | -0x8000;
    }

    gTasks[taskId].data[8] = 0;
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].func = sub_815DA20;
}

void sub_815DCA4(u8 taskId)
{
    u8 battler;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
        DestroyAnimVisualTask(taskId);
    
    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = gBattleAnimArgs[1];
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->data[4] = GetBattlerSpriteCoord(battler, 0);
    task->data[5] = GetBattlerSpriteCoord(battler, 1);
    task->data[6] = GetBattlerSpriteSubpriority(battler);
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(task, task->data[15], gUnknown_085CE74C);
    task->func = sub_815DD48;
}

static void sub_815DD48(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] == 6)
            sub_815DDE0(taskId, TRUE);

        if (task->data[1] == 18)
            sub_815DDE0(taskId, FALSE);

        if (!RunAffineAnimFromTaskData(task))
        {
            if (--task->data[3] == 0)
            {
                task->data[0]++;
            }
            else
            {
                task->data[1] = 0;
                PrepareAffineAnimInTaskData(task, task->data[15], gUnknown_085CE74C);
            }
        }
        break;
    case 1:
        if (task->data[2] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void sub_815DDE0(u8 taskId, bool8 arg1)
{
    u8 i;
    s8 xOffset, yOffset;
    struct Task *task;
    s16 xCoords[4];
    s16 yCoords[2];

    task = &gTasks[taskId];
    if (!arg1)
    {
        xOffset = 18;
        yOffset = -20;
    }
    else
    {
        xOffset = 30;
        yOffset = 20;
    }

    xCoords[0] = task->data[4] - xOffset;
    xCoords[1] = task->data[4] - xOffset - 4;
    xCoords[2] = task->data[4] + xOffset;
    xCoords[3] = task->data[4] + xOffset + 4;
    yCoords[0] = task->data[5] + yOffset;
    yCoords[1] = task->data[5] + yOffset + 6;

    for (i = 0; i < 4; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_085CE76C, xCoords[i], yCoords[i & 1], task->data[6] - 5);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = 0;
            gSprites[spriteId].data[1] = i < 2 ? -2 : 2;
            gSprites[spriteId].data[2] = -1;
            gSprites[spriteId].data[3] = taskId;
            gSprites[spriteId].data[4] = 2;
            task->data[2]++;
        }
    }
}

void sub_815DEBC(struct Sprite *sprite)
{
    sprite->pos1.x += sprite->data[1];
    sprite->pos1.y += sprite->data[2];
    if (++sprite->data[0] > 6)
    {
        gTasks[sprite->data[3]].data[sprite->data[4]]--;
        DestroySprite(sprite);
    }
}

void sub_815DF0C(u8 taskId)
{
    u8 spriteId;

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    gTasks[taskId].data[2] = 0x100 + gSprites[spriteId].oam.paletteNum * 16;
    gTasks[taskId].func = sub_815DF64;
}

static void sub_815DF64(u8 taskId)
{
    if (gTasks[taskId].data[1])
    {
        BlendPalette(gTasks[taskId].data[2], 16, 8, gUnknown_085CE784[gTasks[taskId].data[0]]);
        if (++gTasks[taskId].data[0] > 23)
            gTasks[taskId].data[0] = 0;
        
        gTasks[taskId].data[1]--;
    }
    else
    {
        BlendPalette(gTasks[taskId].data[2], 16, 0, RGB(0, 0, 0));
        DestroyAnimVisualTask(taskId);
    }
}

void sub_815DFCC(u8 taskId)
{
    sub_8117854(
        taskId,
        0,
        0x1A0,
        gBattleAnimAttacker,
        gBattleAnimArgs[0],
        10,
        2,
        30,
        gUnknown_08C2DC68,
        gUnknown_08C2DDC4,
        gUnknown_08C2DDA4);
}

void sub_815E01C(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0) + gBattleAnimArgs[0];
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + gBattleAnimArgs[1];
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->data[0] = 640;
        sprite->data[1] = -640;
    }
    else if (gBattleAnimArgs[2] == 1)
    {
        sprite->vFlip = 1;
        sprite->data[0] = 640;
        sprite->data[1] = 640;
    }
    else
    {
        StartSpriteAnim(sprite, 1);
        sprite->data[0] = 640;
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->data[0] = -sprite->data[0];
        sprite->hFlip = 1;
    }

    sprite->callback = sub_815E0DC;
}

static void sub_815E0DC(struct Sprite *sprite)
{
    sprite->data[6] += sprite->data[0];
    sprite->data[7] += sprite->data[1];
    sprite->pos2.x = sprite->data[6] >> 8;
    sprite->pos2.y = sprite->data[7] >> 8;
    if (++sprite->data[5] == 14)
        DestroyAnimSprite(sprite);
}

void sub_815E114(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (IsContest())
    {
        task->data[5] = 8;
        task->data[6] = 3;
        task->data[7] = 1;
    }
    else
    {
        task->data[5] = 12;
        task->data[6] = 3;
        task->data[7] = 0;
    }

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        task->data[11] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) + sub_80A861C(gBattleAnimAttacker, 0) / 4;
    else
        task->data[11] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) - sub_80A861C(gBattleAnimAttacker, 0) / 4;

    task->data[12] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) - sub_80A861C(gBattleAnimAttacker, 0) / 4;
    task->data[13] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    task->func = sub_815E20C;
}

static void sub_815E20C(u8 taskId)
{
    u8 i;
    s16 x, y;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 3)
        {
            task->data[1] = 0;
            sub_815E34C(
                task->data[11],
                task->data[12],
                task->data[13],
                task->data[14],
                task->data[5],
                task->data[2],
                &x,
                &y);

            for (i = 0; i < 2; i++)
            {
                u8 spriteId = CreateSprite(&gUnknown_085CE7EC, x, y, 35);
                if (spriteId != MAX_SPRITES)
                {
                    if (task->data[7] == 0)
                    {
                        if (i == 0)
                            gSprites[spriteId].pos2.x = gSprites[spriteId].pos2.y = -task->data[6];
                        else
                            gSprites[spriteId].pos2.x = gSprites[spriteId].pos2.y = task->data[6];
                    }
                    else
                    {
                        if (i == 0)
                        {
                            gSprites[spriteId].pos2.x = -task->data[6];
                            gSprites[spriteId].pos2.y = task->data[6];
                        }
                        else
                        {
                            gSprites[spriteId].pos2.x = task->data[6];
                            gSprites[spriteId].pos2.y = -task->data[6];
                        }
                    }

                    gSprites[spriteId].data[0] = 0;
                    gSprites[spriteId].data[1] = taskId;
                    gSprites[spriteId].data[2] = 10;
                    task->data[10]++;
                }
            }

            if (task->data[2] == task->data[5])
                task->data[0]++;

            task->data[2]++;
        }
        break;
    case 1:
        if (task->data[10] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void sub_815E34C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, s16 *x, s16 *y)
{
    int x2;
    int y2;

    if (arg5 == 0)
    {
        *x = arg0;
        *y = arg1;
        return;
    }

    if (arg5 >= arg4)
    {
        *x = arg2;
        *y = arg3;
        return;
    }

    arg4--;
    x2 = (arg0 << 8) + arg5 * (((arg2 - arg0) << 8) / arg4);
    y2 = (arg1 << 8) + arg5 * (((arg3 - arg1) << 8) / arg4);
    *x = x2 >> 8;
    *y = y2 >> 8;
}

void sub_815E404(struct Sprite *sprite)
{
    if (++sprite->data[0] > 36)
    {
        gTasks[sprite->data[1]].data[sprite->data[2]]--;
        DestroySprite(sprite);
    }
}

void sub_815E444(struct Sprite *sprite)
{
    sprite->pos1.x = gBattleAnimArgs[0];
    sprite->pos1.y = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[0] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = sub_80A70C0;
}

void sub_815E47C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[11] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    task->data[12] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    task->data[13] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, 3) + sub_80A861C(gBattleAnimTarget, 0) / 4;
    task->data[15] = CreateSprite(&gUnknown_085CE84C, task->data[11], task->data[12], GetBattlerSpriteSubpriority(gBattleAnimTarget) - 5);
    if (task->data[15] != MAX_SPRITES)
    {
        gSprites[task->data[15]].data[0] = 16;
        gSprites[task->data[15]].data[2] = task->data[13];
        gSprites[task->data[15]].data[4] = task->data[14];
        gSprites[task->data[15]].data[5] = -32;
        InitAnimArcTranslation(&gSprites[task->data[15]]);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            StartSpriteAffineAnim(&gSprites[task->data[15]], 1);
        
        task->func = sub_815E5CC;
    }
    else
    {
        DestroyAnimVisualTask(taskId);
    }
}

static void sub_815E5CC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            TranslateAnimArc(&gSprites[task->data[15]]);
            if (++task->data[2] > 7)
                task->data[0]++;
        }
        break;
    case 1:
        if (TranslateAnimArc(&gSprites[task->data[15]]))
        {
            task->data[1] = 0;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            gSprites[task->data[15]].invisible = task->data[2] & 1;
            if (task->data[2] == 16)
            {
                FreeOamMatrix(gSprites[task->data[15]].oam.matrixNum);
                DestroySprite(&gSprites[task->data[15]]);
                task->data[0]++;
            }
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815E6D8(struct Sprite *sprite)
{
    u8 battler;

    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    sprite->oam.tileNum += 16;
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[1] == 0 ? -1 : 1;
    sprite->pos1.y = GetBattlerSpriteCoord(battler, 3);
    if (gBattleAnimArgs[1] == 0)
    {
        sprite->oam.matrixNum |= 0x8;
        sprite->pos1.x = sub_80A861C(battler, 4) - 8;
    }
    else
    {
        sprite->pos1.x = sub_80A861C(battler, 5) + 8;
    }

    sprite->callback = sub_815E784;
}

static void sub_815E784(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->pos2.x += sprite->data[7];
            if (++sprite->data[2] == 12)
                sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] == 8)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->pos2.x -= sprite->data[7] * 4;
        if (++sprite->data[1] == 6)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->pos2.x += sprite->data[7] * 3;
        if (++sprite->data[1] == 8)
        {
            if (--sprite->data[6])
            {
                sprite->data[1] = 0;
                sprite->data[0]--;
            }
            else
            {
                DestroyAnimSprite(sprite);
            }
        }
        break;
    }
}

void sub_815E840(u8 taskId)
{
    if (gBattleAnimArgs[0] == 0)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0] = gBattleAnimArgs[1];
        gTasks[taskId].data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        PrepareAffineAnimInTaskData(&gTasks[taskId], gTasks[taskId].data[15], gUnknown_085CE87C);
        gTasks[taskId].func = sub_815E898;
    }
}

static void sub_815E898(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (++task->data[1] > 1)
    {
        task->data[1] = 0;
        if (!(task->data[2] & 1))
            gSprites[task->data[15]].pos2.x = 2;
        else
            gSprites[task->data[15]].pos2.x = -2;
    }

    if (!RunAffineAnimFromTaskData(task))
    {
        gSprites[task->data[15]].pos2.x = 0;
        if (--task->data[0])
        {
            PrepareAffineAnimInTaskData(&gTasks[taskId], gTasks[taskId].data[15], gUnknown_085CE87C);
            task->data[1] = 0;
            task->data[2] = 0;
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

void sub_815E954(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
        sprite->pos1.y = sub_80A861C(gBattleAnimAttacker, 2);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->pos1.y = sub_80A861C(gBattleAnimTarget, 2);
    }

    if (sprite->pos1.y < 8)
        sprite->pos1.y = 8;

    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = 0;
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->callback = sub_815E9BC;
}

static void sub_815E9BC(struct Sprite *sprite)
{
    if (++sprite->data[0] >= sprite->data[1])
    {
        sprite->data[0] = 0;
        sprite->data[2] = (sprite->data[2] + 1) & 1;
        sprite->invisible = sprite->data[2];
        if (sprite->data[2] && --sprite->data[3] == 0)
            DestroyAnimSprite(sprite);
    }
}

void sub_815EA14(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->oam.matrixNum |= 0x8;
        sprite->pos1.x = 100;
        sprite->data[7] = 1;
    }
    else
    {
        sprite->pos1.x = 140;
        sprite->data[7] = -1;
    }

    sprite->pos1.y = 56;
    sprite->callback = sub_815EA60;
}

static void sub_815EA60(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.y -= sprite->data[7] * 2;
        if (sprite->data[1] & 1)
            sprite->pos1.x -= sprite->data[7] * 2;

        if (++sprite->data[1] == 9)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] == 4)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1]++;
        sprite->pos1.y += sprite->data[7] * 3;
        sprite->pos2.x = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 12)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] == 2)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        sprite->data[1]++;
        sprite->pos1.y -= sprite->data[7] * 3;
        sprite->pos2.x = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 12)
            sprite->data[0]++;
        break;
    case 5:
        sprite->data[1]++;
        sprite->pos1.y += sprite->data[7] * 3;
        sprite->pos2.x = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 15)
            sprite->oam.tileNum += 16;
        
        if (sprite->data[1] == 18)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 6:
        sprite->pos1.x += sprite->data[7] * 6;
        if (++sprite->data[1] == 9)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 7:
        sprite->pos1.x += sprite->data[7] * 2;
        if (++sprite->data[1] == 1)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 8:
        sprite->pos1.x -= sprite->data[7] * 3;
        if (++sprite->data[1] == 5)
            DestroyAnimSprite(sprite);
        break;
    }
}

void sub_815EC48(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (!IsContest())
    {
        if (IsDoubleBattle() == TRUE)
        {
            int x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
            int y = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimAttacker), 0);
            if (x > y)
                task->data[14] = 1;
            else
                task->data[14] = -1;
        }
        else
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
                task->data[14] = -1;
            else
                task->data[14] = 1;
        }
    }
    else
    {
        task->data[14] = 1;
    }

    task->func = sub_815ECE4;
}

static void sub_815ECE4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] == 13)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        gSprites[task->data[15]].pos2.x -= task->data[14] * 3;
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        gSprites[task->data[15]].pos2.x += task->data[14] * 3;
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (++task->data[1] == 2)
        {
            task->data[1] = 0;
            if (task->data[2] == 0)
            {
                task->data[2]++;
                task->data[0] = 1;
            }
            else
            {
                task->data[0]++;
            }
        }
        break;
    case 4:
        gSprites[task->data[15]].pos2.x += task->data[14];
        if (++task->data[1] == 3)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 5:
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 6:
        gSprites[task->data[15]].pos2.x -= task->data[14] * 4;
        if (++task->data[1] == 5)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 7:
        gSprites[task->data[15]].pos2.x += task->data[14] * 4;
        if (++task->data[1] == 5)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 8:
        gSprites[task->data[15]].pos2.x = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_815EE84(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        InitAnimSpritePos(sprite, TRUE);
        sprite->data[7] = gBattleAnimAttacker;
    }
    else
    {
        sprite->data[7] = gBattleAnimTarget;
    }

    if (GetBattlerSide(sprite->data[7]) == B_SIDE_OPPONENT)
        sprite->oam.matrixNum = 8;

    sprite->oam.priority = sub_80A8328(sprite->data[7]);
    sprite->oam.objMode = ST_OAM_OBJ_BLEND;
    sprite->callback = sub_815EF08;
}

static void sub_815EF08(struct Sprite *sprite)
{
    u16 x, y;

    switch (sprite->data[5])
    {
    case 0:
        switch (sprite->data[6])
        {
        default:
            sprite->data[6] = 0;
        case 0:
        case 4:
            x = sub_80A861C(sprite->data[7], 5) - 4;
            y = sub_80A861C(sprite->data[7], 3) - 4;
            break;
        case 1:
            x = sub_80A861C(sprite->data[7], 5) - 4;
            y = sub_80A861C(sprite->data[7], 2) + 4;
            break;
        case 2:
            x = sub_80A861C(sprite->data[7], 4) + 4;
            y = sub_80A861C(sprite->data[7], 3) - 4;
            break;
        case 3:
            x = sub_80A861C(sprite->data[7], 4) + 4;
            y = sub_80A861C(sprite->data[7], 2) - 4;
            break;
        case 5:
            x = GetBattlerSpriteCoord(sprite->data[7], 2);
            y = GetBattlerSpriteCoord(sprite->data[7], 3);
            break;
        }

        if (sprite->data[6] == 4)
            sprite->data[0] = 24;
        else if (sprite->data[6] == 5)
            sprite->data[0] = 6;
        else
            sprite->data[0] = 12;

        sprite->data[1] = sprite->pos1.x;
        sprite->data[2] = x;
        sprite->data[3] = sprite->pos1.y;
        sprite->data[4] = y;
        InitAnimLinearTranslation(sprite);
        sprite->data[5]++;
        break;
    case 1:
        if (TranslateAnimLinear(sprite))
        {
            switch (sprite->data[6])
            {
            default:
                sprite->pos1.x += sprite->pos2.x;
                sprite->pos1.y += sprite->pos2.y;
                sprite->pos2.y = 0;
                sprite->pos2.x = 0;
                sprite->data[0] = 0;
                sprite->data[5]++;
                sprite->data[6]++;
                break;
            case 4:
                sprite->pos1.x += sprite->pos2.x;
                sprite->pos1.y += sprite->pos2.y;
                sprite->pos2.y = 0;
                sprite->pos2.x = 0;
                sprite->data[5] = 0;
                sprite->data[6]++;
                break;
            case 5:
                sprite->data[0] = 0;
                sprite->data[1] = 16;
                sprite->data[2] = 0;
                sprite->data[5] = 3;
                break;
            }
        }
        break;
    case 2:
        if (++sprite->data[0] == 4)
            sprite->data[5] = 0;
        break;
    case 3:
        if (!(sprite->data[0] & 1))
            sprite->data[1]--;
        else
            sprite->data[2]++;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], sprite->data[2]));
        if (++sprite->data[0] == 32)
        {
            sprite->invisible = 1;
            sprite->data[5]++;
        }
        break;
    case 4:
        DestroyAnimSprite(sprite);
        break;
    }
}

static void sub_815F10C(struct Sprite *sprite)
{
    sprite->pos2.x = ((sprite->data[2] - sprite->data[0]) * sprite->data[5]) / sprite->data[4];
    sprite->pos2.y = ((sprite->data[3] - sprite->data[1]) * sprite->data[5]) / sprite->data[4];
    if (!(sprite->data[5] & 1))
    {
        CreateSprite(
            &gUnknown_085CE3A0,
            sprite->pos1.x + sprite->pos2.x,
            sprite->pos1.y + sprite->pos2.y, 5);
    }
    
    if (sprite->data[5] == sprite->data[4])
        DestroyAnimSprite(sprite);

    sprite->data[5]++;
}

void sub_815F18C(struct Sprite *sprite)
{
    GetBattlerSpriteCoord(gBattleAnimTarget, 2); // unused local variable
    GetBattlerSpriteCoord(gBattleAnimTarget, 3); // unused local variable

    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER || IsContest())
    {
        sprite->data[0] = sprite->pos1.x - gBattleAnimArgs[0];
        sprite->data[2] = sprite->pos1.x - gBattleAnimArgs[2];
    }
    else
    {
        sprite->data[0] = sprite->pos1.x + gBattleAnimArgs[0];
        sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    }

    sprite->data[1] = sprite->pos1.y + gBattleAnimArgs[1];
    sprite->data[3] = sprite->pos1.y + gBattleAnimArgs[3];
    sprite->data[4] = gBattleAnimArgs[4];
    sprite->pos1.x = sprite->data[0];
    sprite->pos1.y = sprite->data[1];
    sprite->callback = sub_815F10C;
}

void AnimTask_MonToSubstitute(u8 taskId)
{
    int i;
    u8 spriteId = GetAnimBattlerSpriteId(0);

    if (gTasks[taskId].data[0] == 0)
    {
        PrepareBattlerSpriteForRotScale(spriteId, FALSE);
        gTasks[taskId].data[1] = 0x100;
        gTasks[taskId].data[2] = 0x100;
        gTasks[taskId].data[0]++;
    }
    else if (gTasks[taskId].data[0] == 1)
    {
        gTasks[taskId].data[1] += 0x60;
        gTasks[taskId].data[2] -= 0xD;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[1], gTasks[taskId].data[2], 0);
        if (++gTasks[taskId].data[3] == 9)
        {
            gTasks[taskId].data[3] = 0;
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].invisible = 1;
            gTasks[taskId].data[0]++;
        }
    }
    else
    {
        LoadBattleMonGfxAndAnimate(gBattleAnimAttacker, 0, spriteId);
        if (IsContest())
        {
            gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gUnknown_082FF6C0;
            StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], 0);
        }

        for (i = 0; i < 16; i++)
            gTasks[taskId].data[i] = 0;
        
        gTasks[taskId].func = sub_815F330;
    }
}

static void sub_815F330(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gSprites[spriteId].pos2.y = -200;
        gSprites[spriteId].pos2.x = 200;
        gSprites[spriteId].invisible = 0;
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 112;
        gSprites[spriteId].pos2.y += gTasks[taskId].data[10] >> 8;
        if (gSprites[spriteId].pos1.y + gSprites[spriteId].pos2.y >= -32)
            gSprites[spriteId].pos2.x = 0;

        if (gSprites[spriteId].pos2.y > 0)
            gSprites[spriteId].pos2.y = 0;

        if (gSprites[spriteId].pos2.y == 0)
        {
            PlaySE12WithPanning(SE_W145B, BattleAnimAdjustPanning(-64));
            gTasks[taskId].data[10] -= 0x800;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        gTasks[taskId].data[10] -= 112;
        if (gTasks[taskId].data[10] < 0)
            gTasks[taskId].data[10] = 0;

        gSprites[spriteId].pos2.y -= gTasks[taskId].data[10] >> 8;
        if (gTasks[taskId].data[10] == 0)
            gTasks[taskId].data[0]++;
        break;
    case 3:
        gTasks[taskId].data[10] += 112;
        gSprites[spriteId].pos2.y += gTasks[taskId].data[10] >> 8;
        if (gSprites[spriteId].pos2.y > 0)
            gSprites[spriteId].pos2.y = 0;

        if (gSprites[spriteId].pos2.y == 0)
        {
            PlaySE12WithPanning(SE_W145B, BattleAnimAdjustPanning(-64));
            DestroyAnimVisualTask(taskId);
        }
        break;
    }
}

void sub_815F48C(struct Sprite *sprite)
{
    s16 y2;

    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 2;
        y2 = -144;
    }
    else
    {
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 2;
        y2 = -96;
    }

    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sprite->pos2.y = y2;
    sprite->callback = sub_815F4F0;
}

static void sub_815F4F0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.y += 10;
        if (sprite->pos2.y >= 0)
        {
            PlaySE12WithPanning(SE_W166, BattleAnimAdjustPanning(63));
            sprite->pos2.y = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->data[1] += 4;
        sprite->pos2.y = -(gSineTable[sprite->data[1]] >> 3);
        if (sprite->data[1] > 127)
        {
            PlaySE12WithPanning(SE_W166, BattleAnimAdjustPanning(63));
            sprite->data[1] = 0;
            sprite->pos2.y = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1] += 6;
        sprite->pos2.y = -(gSineTable[sprite->data[1]] >> 4);
        if (sprite->data[1] > 127)
        {
            sprite->data[1] = 0;
            sprite->pos2.y = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] > 8)
        {
            PlaySE12WithPanning(SE_W043, BattleAnimAdjustPanning(63));
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            sprite->invisible = sprite->data[2] & 1;
            if (sprite->data[2] == 7)
                DestroyAnimSprite(sprite);
        }
        break;
    }
}

void sub_815F620(u8 taskId)
{
    s16 spriteId1, spriteId2;

    if (IsContest())
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    spriteId1 = CloneBattlerSpriteWithBlend(ANIM_TARGET);
    if (spriteId1 < 0)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    spriteId2 = CloneBattlerSpriteWithBlend(ANIM_TARGET);
    if (spriteId2 < 0)
    {
        obj_delete_but_dont_free_vram(&gSprites[spriteId1]);
        DestroyAnimVisualTask(taskId);
        return;
    }

    gSprites[spriteId2].pos2.x += 24;
    gSprites[spriteId1].pos2.x -= 24;
    gSprites[spriteId2].data[0] = 0;
    gSprites[spriteId1].data[0] = 0;
    gSprites[spriteId2].data[1] = 0;
    gSprites[spriteId1].data[1] = 0;
    gSprites[spriteId2].data[2] = 0;
    gSprites[spriteId1].data[2] = 0;
    gSprites[spriteId2].data[3] = 16;
    gSprites[spriteId1].data[3] = -16;
    gSprites[spriteId2].data[4] = 0;
    gSprites[spriteId1].data[4] = 128;
    gSprites[spriteId2].data[5] = 24;
    gSprites[spriteId1].data[5] = 24;
    gSprites[spriteId2].data[6] = taskId;
    gSprites[spriteId1].data[6] = taskId;
    gSprites[spriteId2].data[7] = 0;
    gSprites[spriteId1].data[7] = 0;
    gTasks[taskId].data[0] = 2;

    if (!gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].invisible)
    {
        gSprites[spriteId2].invisible = 0;
        gSprites[spriteId1].invisible = 1;
    }
    else
    {
        gSprites[spriteId2].invisible = 1;
        gSprites[spriteId1].invisible = 1;
    }

    
    gSprites[spriteId2].oam.objMode = ST_OAM_OBJ_NORMAL;
    gSprites[spriteId1].oam.objMode = ST_OAM_OBJ_NORMAL;
    gSprites[spriteId2].callback = sub_815F7C4;
    gSprites[spriteId1].callback = sub_815F7C4;
    gTasks[taskId].func = sub_815F79C;
}

static void sub_815F79C(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
        DestroyAnimVisualTask(taskId);
}

static void sub_815F7C4(struct Sprite *sprite)
{
    int zero = 0;
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        if (!gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].invisible)
            sprite->invisible ^= 1;
    }

    sprite->data[4] = sprite->data[4] + sprite->data[3];
    sprite->data[4] &= 0xFF;
    sprite->pos2.x = Cos(sprite->data[4], sprite->data[5]);
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] == 60)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[2] > 0)
        {
            sprite->data[2] = 0;
            sprite->data[5] -= 2;
            if (sprite->data[5] < 0)
            {
                gTasks[sprite->data[6]].data[sprite->data[7]]--;
                obj_delete_but_dont_free_vram(sprite);
            }
        }
        break;
    }
}
