#include "global.h"
#include "main.h"
#include "pokeblock.h"
#include "alloc.h"
#include "decompress.h"
#include "graphics.h"
#include "palette.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "scanline_effect.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "sound.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "menu.h"
#include "gpu_regs.h"
#include "graphics.h"

struct UsePokeblockSubStruct
{
    /*0x00*/ void (*field_0)(void);
    /*0x04*/ void (*callback)(void);
    /*0x08*/ struct Pokeblock *pokeblock;
    /*0x0C*/ struct Pokemon *pokemon;
    /*0x10*/ u8 stringBuffer[0x40];
    /*0x50*/ u8 field_50;
    /*0x51*/ u8 field_51;
    /*0x52*/ u8 field_52;
    /*0x53*/ u8 field_53;
    /*0x54*/ u8 field_54;
    /*0x55*/ u8 field_55;
    /*0x56*/ u8 field_56;
    /*0x57*/ u8 field_57[5];
    /*0x5C*/ u8 field_5c[5];
    /*0x61*/ u8 field_61[5];
    /*0x66*/ s16 field_66[5];
    /*0x70*/ u8 field_70;
    /*0x71*/ u8 field_71;
    /*0x74*/ u8 (*unk74)(void);
    /*0x78*/ u8 unk78;
    /*0x79*/ u8 filler79[0x1];
    /*0x7A*/ u8 field_7A[0x22];
};

struct Unk7FB8
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
};

struct UsePokeblockStruct
{
    /*0x0000*/ u8 field_0[0x7B06];
    /*0x7B06*/ u8 field_7B06[7];
    /*0x7B0E*/ u16 field_7B0E;
    /*0x7B10*/ u8 field_7B10;
    /*0x7B11*/ u8 field_7B11[0xB];
    /*0x7B1C*/ struct Sprite *field_7B1C[10];
    /*0x7B44*/ struct Sprite *field_7B44[2];
    /*0x7B4C*/ u8 field_7B4C;
    /*0x7B4D*/ u8 filler7B4D[0x47];
    /*0x7B94*/ u8 filler7B94;
    /*0x7B95*/ u8 field_7B95[3][64];
    /*0x7C58*/ struct UnknownStruct_81D1ED4 field_7C58;
    /*0x7FB0*/ u8 unk7FB0[3];
    /*0x7FB3*/ s8 field_7FB3;
    /*0x7FB4*/ s8 field_7FB4;
    /*0x7FB5*/ s8 field_7FB5;
    /*0x7FB6*/ s8 field_7FB6;
    /*0x7FB8*/ struct Unk7FB8 field_7FB8[6];
    /*0x7FD0*/ struct UsePokeblockSubStruct info;
};

extern u16 gKeyRepeatStartDelay;

// this file's functions
void sub_816636C(void (*func)(void));
void sub_8166380(void);
void sub_816631C(void);
void sub_81662C0(void);
void sub_8166564(void);
void sub_8166304(void);
void sub_81668F8(void);
void sub_8167420(void);
void sub_8167760(void);
u8 sub_81672E4(u8 arg0);
static bool8 sub_8168328(void);
bool8 sub_8167930(void);
void sub_8167608(u8 arg0);
void sub_8167BA0(u16 arg0, u8 copyToVramMode);
void sub_8166634(void);
static void sub_8167CA0(bool8);
void sub_8166BEC(void);
void sub_8166D44(void);
s8 sub_8166DE4(void);
bool8 sub_8167268(void);
void sub_8166F50(void);
void sub_816681C(void);
void sub_8166F94(void);
u8 sub_81672A4(u8 a0);
void sub_8166A34(void);
void sub_8167104(void);
void sub_8167338(void);
void sub_81681F4(u8);
void sub_8166E24(void);
bool8 sub_8166EDC(void);
void Pokeblock_BufferEnhancedStatText(u8 *dest, u8 statID, s16 a2);
void Pokeblock_MenuWindowTextPrint(const u8 *message);
void sub_8167184(struct Pokeblock *, struct Pokemon *);
extern u32 sub_81D2C68(s32, s32, s32, u8 *);
void sub_81673DC(struct Sprite *sprite);
void sub_81674BC(void);
void sub_816753C(s16, u8);
static u8 sub_8167EA4(void);
static u8 sub_8167FA4(void);
static u8 sub_8168048(void);
extern void sub_81D2ED4(u8, u8, u16, u8, u8, u8, u8);
extern void sub_81D2F78(u8, u8, s16, u16, u8, u8, u8, u8);
extern void sub_81D3094(u8, u8, s16, u16, u8, u8, u8);
extern void sub_81D31D0(struct SpritePalette *, struct SpritePalette *, struct SpritePalette *);
extern void sub_81D321C(struct SpriteSheet *, struct SpriteTemplate *, struct SpritePalette*);
void sub_8168180(struct Sprite *sprite);
void sub_81681B4(struct Sprite *sprite);
extern void sub_81D32B0(struct SpriteSheet *, struct SpritePalette*);
extern void sub_81D21DC(u8);

extern const struct BgTemplate gUnknown_085DFCCC[4];
extern const struct WindowTemplate gUnknown_085DFCDC[];
extern u16 gSpecialVar_ItemId;
extern const struct WindowTemplate sUsePokeblockYesNoWinTemplate[];
extern const u8* sContestStatNames[];
extern const u32 gUnknown_085DFCB0[];
extern const u8 gUnknown_085DFCC4[];
extern const struct SpriteSheet gSpriteSheet_ConditionUpDown;
extern const struct SpritePalette gSpritePalette_ConditionUpDown;
extern const struct SpriteTemplate gSpriteTemplate_085DFD5C;
extern const s16 gUnknown_085DFD28[][2];
extern const u32 gUnknown_085DFB60[];
extern const u32 gUnknown_085DFA80[];
extern const u32 gUnknown_085DFA60[];
extern const u32 gUnknown_085DFC0C[];
extern const u16 gUnknown_086231E8[];
extern const u16 gUnknown_08623208[];
extern const u8 gUnknown_085DFCC9[];
extern const struct SpritePalette gUnknown_085DFDB8;
extern const struct SpriteTemplate gUnknown_085DFDA0;

extern const u8 *const gNatureNamePointers[];

// ram variables
EWRAM_DATA struct UsePokeblockSubStruct *gUnknown_0203BC90 = NULL;
EWRAM_DATA void (*gUnknown_0203BC94)(void) = NULL;
EWRAM_DATA struct Pokeblock *gUnknown_0203BC98 = NULL;
EWRAM_DATA u8 gPokeblockMonId = 0;
EWRAM_DATA s16 gPokeblockGain = 0;
EWRAM_DATA void *gUnknown_0203BCA0 = NULL;
EWRAM_DATA void *gUnknown_0203BCA4 = NULL;
EWRAM_DATA void *gUnknown_0203BCA8 = NULL;
EWRAM_DATA struct UsePokeblockStruct *gUnknown_0203BCAC = NULL;

// const rom data
// todo: make it static once the file is decompiled

// code
void ChooseMonToGivePokeblock(struct Pokeblock *pokeblock, void (*callback)(void))
{
    gUnknown_0203BCAC = AllocZeroed(sizeof(*gUnknown_0203BCAC));
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = pokeblock;
    gUnknown_0203BC90->callback = callback;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_816631C);
}

void CB2_ReturnAndChooseMonToGivePokeblock(void)
{
    gUnknown_0203BCAC = AllocZeroed(sizeof(*gUnknown_0203BCAC));
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = gUnknown_0203BC98;
    gUnknown_0203BC90->callback = gUnknown_0203BC94;
    gPokeblockMonId = sub_81672E4(gPokeblockMonId);
    gUnknown_0203BC90->field_56 = gPokeblockMonId < 4 ? 0 : 1;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_81662C0);
}

void sub_81662C0(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gUnknown_0203BC90->field_0 == sub_8166564)
    {
        gUnknown_0203BC90->field_50 = 0;
        SetMainCallback2(sub_8166304);
    }
}

void sub_8166304(void)
{
    sub_81668F8();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_816631C(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_8166340(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(&gUnknown_0203BCAC->field_7C58);
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_816636C(void (*func)(void))
{
    gUnknown_0203BC90->field_0 = func;
    gUnknown_0203BC90->field_50 = 0;
}

void sub_8166380(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        gUnknown_0203BCAC->field_7B10 = 0xFF;
        sub_81D1ED4(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gUnknown_0203BC90->field_50++;
        break;
    case 2:
        SetVBlankCallback(NULL);
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
        gUnknown_0203BC90->field_50++;
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_085DFCCC, ARRAY_COUNT(gUnknown_085DFCCC));
        InitWindows(gUnknown_085DFCDC);
        DeactivateAllTextPrinters();
        LoadUserWindowBorderGfx(0, 0x97, 0xE0);
        gUnknown_0203BC90->field_50++;
        break;
    case 4:
        gUnknown_0203BC90->field_50++;
        break;
    case 5:
        if (!sub_8168328())
            gUnknown_0203BC90->field_50++;
        break;
    case 6:
        gKeyRepeatStartDelay = 20;
        sub_8167420();
        gUnknown_0203BC90->field_50++;
        break;
    case 7:
        if (!sub_8167930())
            gUnknown_0203BC90->field_50++;
        break;
    case 8:
        sub_8167608(0);
        sub_8167760();
        gUnknown_0203BC90->field_50++;
        break;
    case 9:
        if (!sub_81D312C(&gUnknown_0203BCAC->field_7B0E))
            gUnknown_0203BC90->field_50++;
        break;
    case 10:
        gUnknown_0203BC90->field_50++;
        break;
    case 11:
        sub_81D2754(gUnknown_0203BCAC->field_7C58.unk0[0], gUnknown_0203BCAC->field_7C58.unk14[0]);
        sub_81D20AC(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 12:
        if (!sub_81D20BC(&gUnknown_0203BCAC->field_7C58))
        {
            sub_81D1F84(&gUnknown_0203BCAC->field_7C58, gUnknown_0203BCAC->field_7C58.unk14[0], gUnknown_0203BCAC->field_7C58.unk14[0]);
            gUnknown_0203BC90->field_50++;
        }
        break;
    case 13:
        sub_81D2230(&gUnknown_0203BCAC->field_7C58);
        gUnknown_0203BC90->field_50++;
        break;
    case 14:
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        sub_8167BA0(0, 1);
        gUnknown_0203BC90->field_50++;
        break;
    case 15:
        sub_816636C(sub_8166564);
        break;
    }
}

void sub_8166564(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(sub_8166340);
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            sub_81D3464(gUnknown_0203BCAC->field_7B1C);
            if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
            {
                u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
                sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
            }

            sub_816636C(sub_8166634);
        }
        break;
    }
}

void sub_8166634(void)
{    
    u8 var;
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        if (gMain.heldKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(TRUE);
            sub_81D3520(gUnknown_0203BCAC->field_7B1C);
            gUnknown_0203BC90->field_50 = 1;
        }
        else if (gMain.heldKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(FALSE);
            sub_81D3520(gUnknown_0203BCAC->field_7B1C);
            gUnknown_0203BC90->field_50 = 1;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_0203BC90->field_50 = 3;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gUnknown_0203BCAC->info.field_71 == gUnknown_0203BCAC->info.field_70 - 1)
                gUnknown_0203BC90->field_50 = 3;
            else
                gUnknown_0203BC90->field_50 = 5;
        }
        break;
    case 1:
        var = gUnknown_0203BCAC->info.unk74();
        if(!var)
            gUnknown_0203BC90->field_50 = var;
       break;
    case 2:
        break;
    case 3:
        sub_816636C(sub_8166BEC);
        break;
    case 4:
        break;
    case 5:
        sub_8166D44();
        gUnknown_0203BC90->field_50++;
        break;
    case 6:
        switch (sub_8166DE4())
        {
        case 1:
        case -1:
            gUnknown_0203BC90->field_50 = 0;
            break;
        case 0:
            if (sub_8167268())
            {
                sub_8166F50();
                gUnknown_0203BC90->field_50 = 7;
            }
            else
            {
                sub_816636C(sub_816681C);
            }
            break;
        }
        break;
    case 7:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            sub_8166F94();
            gUnknown_0203BC90->field_50 = 0;
        }
        break;
    }
}

void sub_816681C(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        gPokeblockMonId = sub_81672A4(gUnknown_0203BCAC->info.field_71);
        gUnknown_0203BC94 = gUnknown_0203BC90->callback;
        gUnknown_0203BC98 = gUnknown_0203BC90->pokeblock;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetVBlankCallback(NULL);
            Free(gUnknown_0203BCA0);
            gUnknown_0203BCA0 = NULL;
            Free(gUnknown_0203BCA4);
            gUnknown_0203BCA4 = NULL;
            Free(gUnknown_0203BCA8);
            gUnknown_0203BCA8 = NULL;
            Free(gUnknown_0203BCAC);
            gUnknown_0203BCAC = NULL;
            FreeAllWindowBuffers();
            gMain.savedCallback = CB2_ReturnAndChooseMonToGivePokeblock;
            CB2_PreparePokeblockFeedScene();
        }
        break;
    }
}

void sub_81668F8(void)
{
    u16 var;
    switch (gUnknown_0203BC90->field_50)
    {
    case 0:
        if (gUnknown_0203BCAC->info.field_71 != gPokeblockMonId)
        {
            sub_8167CA0(gUnknown_0203BC90->field_56);
            gUnknown_0203BC90->field_50++;
        }
        else
        {
            gUnknown_0203BC90->field_50 = 3;
        }
        break;
    case 1:
        var = gUnknown_0203BCAC->info.unk74();
        if (!var)
            gUnknown_0203BC90->field_50 = var;
        break;
    case 2:
        break;
    case 3:
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 4:
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        gUnknown_0203BC90->field_50++;
        break;
    case 5:
        SetVBlankCallback(sub_8166340);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            sub_81D3464(gUnknown_0203BCAC->field_7B1C);
            sub_816636C(sub_8166A34);
            SetMainCallback2(sub_816631C);
        }
        break;
    }
}

void sub_8166A34(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
        u8 var;
        case 0:
            gUnknown_0203BC90->pokemon = gPlayerParty;
            gUnknown_0203BC90->pokemon += gUnknown_0203BCAC->field_7FB8[gUnknown_0203BCAC->info.field_71].unk1;
            sub_81D3520(gUnknown_0203BCAC->field_7B1C);
            gUnknown_0203BC90->field_50++;
            break;
        case 1:
            if (gMain.newKeys & (A_BUTTON | B_BUTTON))
                gUnknown_0203BC90->field_50++;
            break;
        case 2:
            sub_8167104();
            sub_81D2754(gUnknown_0203BC90->field_5c, gUnknown_0203BCAC->field_7C58.unk14[3]);
            sub_81D1F84(&gUnknown_0203BCAC->field_7C58, gUnknown_0203BCAC->field_7C58.unk14[gUnknown_0203BCAC->field_7FB3], gUnknown_0203BCAC->field_7C58.unk14[3]);
            sub_8167338();
            gUnknown_0203BC90->field_50++;
            break;
        case 3:
			var = sub_81D2074(&gUnknown_0203BCAC->field_7C58);
			if(var)
				return;
			
            sub_81681F4(sub_81672A4(gUnknown_0203BCAC->info.field_71));
			
            if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
            {
                u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
                sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
            }
			
            gUnknown_0203BC90->field_52 = 0;
			gUnknown_0203BC90->field_50++;
            break;
        case 4:
            if ((++gUnknown_0203BC90->field_52) > 16)
            {
                sub_8166E24();
                gUnknown_0203BC90->field_50++;
            }
            break;
        case 5:
            if (gMain.newKeys & (A_BUTTON | B_BUTTON) && !sub_8166EDC())
            {
                TryClearPokeblock((u8)gSpecialVar_ItemId);
                sub_816636C(sub_8166BEC);
            }
            break;
    }
}

void sub_8166BEC(void)
{
    u8 i;
    u8 var;
    switch (gUnknown_0203BC90->field_50)
    {    
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203BC90->field_50++;
        break;
    case 1:
        if (!gPaletteFade.active)
            gUnknown_0203BC90->field_50 = 2;
        break;
    case 2:
        gScanlineEffect.state = 3;
        ScanlineEffect_InitHBlankDmaTransfer();
        gUnknown_0203BC90->field_50++;
        break;
    case 3:
        SetMainCallback2(gUnknown_0203BC90->callback);
        sub_81D354C(gUnknown_0203BCAC->field_7B1C);
        for (i = 0; i < 7; i++)
            DestroySprite(&gSprites[gUnknown_0203BCAC->field_7B06[i]]);
        
        FreeSpriteTilesByTag(0);
        FreeSpriteTilesByTag(1);
        FreeSpritePaletteByTag(0);
        FreeSpritePaletteByTag(1);
        
        for (i = 0; i < 2; i++)
            DestroySprite(gUnknown_0203BCAC->field_7B44[i]);
        
        if (gUnknown_0203BCAC->field_7B10 != 0xFF)
            DestroySprite(&gSprites[gUnknown_0203BCAC->field_7B10]);
        
        SetVBlankCallback(NULL);
        FREE_AND_SET_NULL(gUnknown_0203BCA0);
        FREE_AND_SET_NULL(gUnknown_0203BCA4);
        FREE_AND_SET_NULL(gUnknown_0203BCA8);
        FREE_AND_SET_NULL(gUnknown_0203BCAC);
        FreeAllWindowBuffers();
        break;
    }
}

void sub_8166D44(void)
{
    u8 stringBuffer[0x40];
    GetMonData(&gPlayerParty[sub_81672A4(gUnknown_0203BCAC->info.field_71)], MON_DATA_NICKNAME, stringBuffer);
    StringGetEnd10(stringBuffer);
    StringAppend(stringBuffer, gText_GetsAPokeBlockQuestion);
    StringCopy(gStringVar4, stringBuffer);
    FillWindowPixelBuffer(2, 17);
    sub_8098858(2, 151, 14);
    AddTextPrinterParameterized(2, 1, gStringVar4, 0, 1, 0, NULL);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
    CreateYesNoMenu(sUsePokeblockYesNoWinTemplate, 151, 14, 0);
}

s8 sub_8166DE4(void)
{
    s8 retval = Menu_ProcessInputNoWrapClearOnChoose();
    switch(retval)
    {
    case 0:
        break;
    case -1:
    case 1:
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(2);
        ClearWindowTilemap(2);
        break;
    }
    return retval;
}

void sub_8166E24(void)
{
    sub_8098858(2, 151, 14);
    FillWindowPixelBuffer(2, 17);

    for (gUnknown_0203BC90->field_53 = 0; gUnknown_0203BC90->field_53 < 5 && gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53] == 0; gUnknown_0203BC90->field_53++);
    
    if (gUnknown_0203BC90->field_53 < 5)
        Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53]);
    else
        Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, 0);
        
    Pokeblock_MenuWindowTextPrint(gStringVar4);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

bool8 sub_8166EDC(void)
{
    FillWindowPixelBuffer(2, 17);
    
    while (1)
    {
        gUnknown_0203BC90->field_53++;
        if (gUnknown_0203BC90->field_53 < 5)
        {
            if (gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53] != 0)
                break;
        }
        else
        {
            gUnknown_0203BC90->field_53 = 5;
            return FALSE;
        }
    }
    
    Pokeblock_BufferEnhancedStatText(gStringVar4, gUnknown_0203BC90->field_53, gUnknown_0203BC90->field_61[gUnknown_0203BC90->field_53]);
    Pokeblock_MenuWindowTextPrint(gStringVar4);
    CopyWindowToVram(2, 2);
    
    return TRUE;
}

void sub_8166F50(void)
{
    FillWindowPixelBuffer(2, 17);
    sub_8098858(2, 151, 14);
    AddTextPrinterParameterized(2, 1, gText_WontEatAnymore, 0, 1, 0, NULL);
    PutWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

void sub_8166F94(void)
{
    rbox_fill_rectangle(2);
    ClearWindowTilemap(2);
    CopyWindowToVram(2, 3);
}

void Pokeblock_MenuWindowTextPrint(const u8 *message)
{
    AddTextPrinterParameterized(2, 1, gStringVar4, 0, 1, 0, NULL);
}

#ifdef NONMATCHING
void Pokeblock_BufferEnhancedStatText(u8 *dest, u8 statID, s16 a2)
{
    if (a2 != 0)
    {
        if (a2 > 0)
            a2 = 0;

        StringCopy(dest, sContestStatNames[statID]);
        StringAppend(dest, gText_WasEnhanced);
    }
    else
    {
        StringCopy(dest, gText_NothingChanged);
    }
}
#else
NAKED
void Pokeblock_BufferEnhancedStatText(u8 *dest, u8 statID, s16 a2)
{
    asm(".syntax unified\n\
push {r4,lr}\n\
    adds r4, r0, 0\n\
    lsls r1, 24\n\
    lsrs r3, r1, 24\n\
    lsls r2, 16\n\
    lsrs r0, r2, 16\n\
    asrs r2, 16\n\
    cmp r2, 0\n\
    beq _08167010\n\
    cmp r2, 0\n\
    ble _08166FEC\n\
    movs r0, 0\n\
_08166FEC:\n\
    lsls r0, 16\n\
    ldr r1, =sContestStatNames\n\
    lsls r0, r3, 2\n\
    adds r0, r1\n\
    ldr r1, [r0]\n\
    adds r0, r4, 0\n\
    bl StringCopy\n\
    ldr r1, =gText_WasEnhanced\n\
    adds r0, r4, 0\n\
    bl StringAppend\n\
    b _08167018\n\
    .pool\n\
_08167010:\n\
    ldr r1, =gText_NothingChanged\n\
    adds r0, r4, 0\n\
    bl StringCopy\n\
_08167018:\n\
    pop {r4}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

void Pokeblock_GetMonContestStats(struct Pokemon *pokemon, u8 *data)
{
    u16 i;

    for (i = 0; i < 5; i++)
        data[i] = GetMonData(pokemon, gUnknown_085DFCB0[i]);
}

void sub_8167054(struct Pokeblock *pokeblock, struct Pokemon *pokemon)
{
    u16 i;
    s16 cstat;
    u8 data;
    if (GetMonData(pokemon, MON_DATA_SHEEN) != 255)
    {
        sub_8167184(pokeblock, pokemon);
        for (i = 0; i < 5; i++)
        {
            data = GetMonData(pokemon, gUnknown_085DFCB0[i]);
            cstat = data +  gUnknown_0203BC90->field_66[i];
            if (cstat < 0)
                cstat = 0;
            if (cstat > 255)
                cstat = 255;
            data = cstat;
            SetMonData(pokemon, gUnknown_085DFCB0[i], &data);
        }

        cstat = (u8)GetMonData(pokemon, MON_DATA_SHEEN);
        cstat = cstat + pokeblock->feel;
        if (cstat > 255)
            cstat = 255;

        data = cstat;
        SetMonData(pokemon, MON_DATA_SHEEN, &data);
    }
}

void sub_8167104(void)
{
    u16 i;
    struct Pokemon *pokemon = gPlayerParty;
    pokemon += gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->info.field_71 * 4 + 9];
    Pokeblock_GetMonContestStats(pokemon, gUnknown_0203BC90->field_57);
    sub_8167054(gUnknown_0203BC90->pokeblock, pokemon);
    Pokeblock_GetMonContestStats(pokemon, gUnknown_0203BC90->field_5c);
    for (i=0; i<5; i++)
    {
        gUnknown_0203BC90->field_61[i] = gUnknown_0203BC90->field_5c[i] - gUnknown_0203BC90->field_57[i];
    }
}

void sub_8167184(struct Pokeblock *pokeblock, struct Pokemon *pokemon)
{
    s8 direction;
    s8 i;
    s16 amount;
    s8 boost;
    s8 taste;
    gUnknown_0203BC90->field_66[0] = pokeblock->spicy;
    gUnknown_0203BC90->field_66[1] = pokeblock->sour;
    gUnknown_0203BC90->field_66[2] = pokeblock->bitter;
    gUnknown_0203BC90->field_66[3] = pokeblock->sweet;
    gUnknown_0203BC90->field_66[4] = pokeblock->dry;
    if (gPokeblockGain > 0)
        direction = 1;
    else if (gPokeblockGain < 0)
        direction = -1;
    else
        return;

    for (i = 0; i < 5; i++)
    {
        amount = gUnknown_0203BC90->field_66[i];
        boost = amount / 10;
        if (amount % 10 >= 5) // round to the nearest
            boost++;

        taste = GetMonFlavorRelation(pokemon, gUnknown_085DFCC4[i]);
        if (taste == direction)
            gUnknown_0203BC90->field_66[i] += boost * taste;
    }
}

bool8 sub_8167268(void)
{
    u8 *mon;
    mon    = (u8 *) &gUnknown_0203BCAC->field_0[gUnknown_0203BCAC->info.field_71 * 4];
    if (sub_81D2C68(*(mon + 864 + 0x7C58), *(mon + 865 + 0x7C58), MON_DATA_SHEEN, 0) == 255)
        return TRUE;
    return FALSE;
}

u8 sub_81672A4(u8 a0)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            if (a0 == 0)
                return i;

            a0--;
        }
    }
    return 0;
}

u8 sub_81672E4(u8 partyCount)
{
    u8 i, numEggs;

    for (i = 0, numEggs = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            numEggs++;
    }

    return partyCount - numEggs;
}

u8 sub_8167324(u8 a0)
{
    return sub_81672A4(a0);
}

void sub_8167338(void)
{
    u16 flavor;
    u8 spriteidx;
    LoadSpriteSheet(&gSpriteSheet_ConditionUpDown);
    LoadSpritePalette(&gSpritePalette_ConditionUpDown);
    gUnknown_0203BC90->field_54 = 0;
    for (flavor = 0; flavor < 5; flavor++)
    {
        if (gUnknown_0203BC90->field_61[flavor] != 0)
        {
            spriteidx = CreateSprite(&gSpriteTemplate_085DFD5C, gUnknown_085DFD28[flavor][0], gUnknown_085DFD28[flavor][1], 0);
            if (spriteidx != MAX_SPRITES)
            {
                if (gUnknown_0203BC90->field_61[flavor] != 0)
                    gSprites[spriteidx].callback = sub_81673DC;

                gUnknown_0203BC90->field_54++;
            }
        }
    }
}

void sub_81673DC(struct Sprite *sprite)
{
    if (sprite->data[0] < 6)
        sprite->pos2.y -= 2;
    else if (sprite->data[0] < 12)
        sprite->pos2.y += 2;

    if (++sprite->data[0] > 60)
    {
        DestroySprite(sprite);
        gUnknown_0203BC90->field_54--;
    }
}

void sub_8167420(void)
{
    u16 i;
    u16 numMons;
    
    for (i = 0, numMons = 0;  i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            gUnknown_0203BCAC->field_7FB8[numMons].unk0 = 14;
            gUnknown_0203BCAC->field_7FB8[numMons].unk1 = i;
            gUnknown_0203BCAC->field_7FB8[numMons].unk2 = 0;
            numMons++;
        }
    }

    gUnknown_0203BCAC->info.field_71 = 0;
    gUnknown_0203BCAC->info.field_70 = numMons + 1;
    sub_81674BC();
}

void sub_81674BC(void)
{
    s16 var;
    s16 var2;
    
    sub_816753C(gUnknown_0203BCAC->info.field_71, 0);
    gUnknown_0203BCAC->field_7FB3 = 0;
    gUnknown_0203BCAC->field_7FB4 = 1;
    gUnknown_0203BCAC->field_7FB5 = 2;
    var = gUnknown_0203BCAC->info.field_71 + 1;
    if (var >= gUnknown_0203BCAC->info.field_70)
        var = 0;
    
    var2 = gUnknown_0203BCAC->info.field_71 - 1;
    if (var2 < 0)
        var2 = gUnknown_0203BCAC->info.field_70 - 1;
    
    sub_816753C(var, 1);
    sub_816753C(var2, 2);
}

#ifdef NONMATCHING
void sub_816753C(s16 a1, u8 a2)
{
    u8 *v3;
    int v5;
    int v6;
    
    v3 = &gUnknown_0203BCAC->field_0[a1 << 16 >> 14];
    v5 =  *(0x7FB8 + v3);
    v6 =  *(0x7FB9 + v3);
    
    sub_81D2ED4(gUnknown_0203BCAC->field_0[0x7B4D + 24 * a2], gUnknown_0203BCAC->field_0[0x7B95 + 64 * a2], v5, v6, a1, gUnknown_0203BCAC->info.field_70, 0);
    sub_81D2F78(gUnknown_0203BCAC->field_7C58[0], gUnknown_0203BCAC->field_0[0x7FB0], v5, v6, a1, a2, gUnknown_0203BCAC->info.field_70, 0);
    sub_81D3094(gUnknown_0203BCAC->field_0[(a2 << 13) + 0x304], gUnknown_0203BCAC->field_0[(a2 << 7) + 4], v5, v6, a1, gUnknown_0203BCAC->info.field_70, 0);
    //gUnknown_0203BCAC->field_0[0x7B4D + a1 * 40], gUnknown_0203BCAC->field_7FB8, gUnknown_0203BCAC->field_7FB9, gUnknown_203BCAC->field_0[0], gUnknown_203BCAC->info.field_70, 0)
}
#else
NAKED
void sub_816753C(s16 a1, u8 a2)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x10\n\
    adds r5, r0, 0\n\
    adds r4, r1, 0\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    ldr r0, =gUnknown_0203BCAC\n\
    mov r9, r0\n\
    ldr r1, [r0]\n\
    lsls r5, 16\n\
    asrs r0, r5, 14\n\
    adds r0, r1, r0\n\
    ldr r3, =0x00007fb8\n\
    adds r2, r0, r3\n\
    ldrb r7, [r2]\n\
    ldr r2, =0x00007fb9\n\
    adds r0, r2\n\
    ldrb r0, [r0]\n\
    mov r10, r0\n\
    adds r3, 0x88\n\
    adds r0, r1, r3\n\
    ldrb r6, [r0]\n\
    movs r0, 0\n\
    mov r8, r0\n\
    lsls r0, r4, 1\n\
    adds r0, r4\n\
    lsls r0, 3\n\
    ldr r2, =0x00007b4d\n\
    adds r0, r2\n\
    adds r0, r1, r0\n\
    lsls r2, r4, 6\n\
    ldr r3, =0x00007b95\n\
    adds r2, r3\n\
    adds r1, r2\n\
    lsrs r5, 16\n\
    str r5, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r2, r8\n\
    str r2, [sp, 0x8]\n\
    adds r2, r7, 0\n\
    mov r3, r10\n\
    bl sub_81D2ED4\n\
    mov r3, r9\n\
    ldr r1, [r3]\n\
    ldr r2, =0x00007c58\n\
    adds r0, r1, r2\n\
    ldr r3, =0x00007fb0\n\
    adds r1, r3\n\
    str r5, [sp]\n\
    str r4, [sp, 0x4]\n\
    str r6, [sp, 0x8]\n\
    mov r2, r8\n\
    str r2, [sp, 0xC]\n\
    adds r2, r7, 0\n\
    mov r3, r10\n\
    bl sub_81D2F78\n\
    lsls r0, r4, 13\n\
    movs r1, 0xC1\n\
    lsls r1, 2\n\
    adds r0, r1\n\
    mov r3, r9\n\
    ldr r1, [r3]\n\
    adds r0, r1, r0\n\
    lsls r4, 7\n\
    adds r4, 0x4\n\
    adds r1, r4\n\
    str r5, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r2, r8\n\
    str r2, [sp, 0x8]\n\
    adds r2, r7, 0\n\
    mov r3, r10\n\
    bl sub_81D3094\n\
    add sp, 0x10\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

#ifdef NONMATCHING
void sub_8167608(u8 arg0)
{
    u8 v4;
    u8 *v5;
    u8 *v6;
    u32 v7;
    struct SpritePalette array[5];
    if(gUnknown_0203BCAC->field_0[0x7B10] == 255)
    {
        sub_81D31D0(&array[3], &array[0], &array[4]);
        array[1] =  (struct SpritePallete *) ((u32) gUnknown_0203BCAC->field_0[(arg0 << 13) + 772]);
        array[2] =  (struct SpritePallete *) ((u32) gUnknown_0203BCAC->field_0[(arg0 << 7) + 4]);
        gUnknown_0203BCAC->field_0[0x7B12] = LoadSpritePalette(&array[3]);
        gUnknown_0203BCAC->field_0[0x7B14] = LoadSpritePalette(&array[4]);
        v4 = CreateSprite(array[0], 38, 104, 0);
        gUnknown_0203BCAC->field_0[0x7B10] = v4;
        if(v4 == 64)
        {
            FreeSpriteTilesByTag(100);
            FreeSpritePaletteByTag(100);
            gUnknown_0203BCAC->field_0[0x7B10] = 255;
        }
        else
        {
            gUnknown_0203BCAC->field_0[0x7B10] = v4;
            v5 = &gUnknown_0203BCAC->field_0[0];
            v6 = &gUnknown_0203BCAC->field_0[0x7B10];
            gSprites[v6].callback = sub_8168168;
            gSprites[v6].pos2.y -= 32;
            *(v5+0x7B18) = 32 * *(v5+0x7B14) + 0x06010000;
            *(v5+0x7B12) = 16 * *(v5+0x7B12) + 0x100;
        }
    }
    else
    {
        v7 = gUnknown_0203BCAC->field_0[0x7B18];
        REG_ADDR_DMA3SAD = gUnknown_0203BCAC->field_0[(arg0 << 13) + 772];
        REG_ADDR_DMA3DAD = v7;
        REG_ADDR_DMA3CNT = 0x80000400;
        LoadPalette(gUnknown_0203BCAC->field_0[arg0 << 7) + 4), gUnknown_0203BCAC->field_0[0x7B12], 32);
    }
}
#else
NAKED
void sub_8167608(u8 arg0)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    sub sp, 0x28\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    ldr r1, =gUnknown_0203BCAC\n\
    ldr r3, [r1]\n\
    ldr r0, =0x00007b10\n\
    mov r8, r0\n\
    adds r0, r3, r0\n\
    ldrb r0, [r0]\n\
    adds r7, r1, 0\n\
    cmp r0, 0xFF\n\
    bne _08167714\n\
    add r5, sp, 0x18\n\
    add r4, sp, 0x20\n\
    adds r0, r5, 0\n\
    mov r1, sp\n\
    adds r2, r4, 0\n\
    bl sub_81D31D0\n\
    lsls r0, r6, 13\n\
    movs r1, 0xC1\n\
    lsls r1, 2\n\
    adds r0, r1\n\
    ldr r1, [r7]\n\
    adds r0, r1, r0\n\
    str r0, [sp, 0x18]\n\
    lsls r0, r6, 7\n\
    adds r0, 0x4\n\
    adds r1, r0\n\
    str r1, [sp, 0x20]\n\
    adds r0, r4, 0\n\
    bl LoadSpritePalette\n\
    ldr r1, [r7]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    ldr r2, =0x00007b12\n\
    adds r1, r2\n\
    strh r0, [r1]\n\
    adds r0, r5, 0\n\
    bl LoadSpriteSheet\n\
    ldr r1, [r7]\n\
    ldr r3, =0x00007b14\n\
    adds r1, r3\n\
    strh r0, [r1]\n\
    mov r0, sp\n\
    movs r1, 0x26\n\
    movs r2, 0x68\n\
    movs r3, 0\n\
    bl CreateSprite\n\
    lsls r0, 24\n\
    lsrs r1, r0, 24\n\
    ldr r0, [r7]\n\
    ldr r2, =0x00007b10\n\
    adds r0, r2\n\
    strb r1, [r0]\n\
    cmp r1, 0x40\n\
    bne _081676AC\n\
    movs r0, 0x64\n\
    bl FreeSpriteTilesByTag\n\
    movs r0, 0x64\n\
    bl FreeSpritePaletteByTag\n\
    ldr r0, [r7]\n\
    add r0, r8\n\
    movs r1, 0xFF\n\
    strb r1, [r0]\n\
    b _08167742\n\
    .pool\n\
_081676AC:\n\
    ldr r0, [r7]\n\
    add r0, r8\n\
    strb r1, [r0]\n\
    ldr r4, =gSprites\n\
    ldr r2, [r7]\n\
    mov r0, r8\n\
    adds r3, r2, r0\n\
    ldrb r1, [r3]\n\
    lsls r0, r1, 4\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r1, r4, 0\n\
    adds r1, 0x1C\n\
    adds r0, r1\n\
    ldr r1, =sub_8168168\n\
    str r1, [r0]\n\
    ldrb r1, [r3]\n\
    lsls r0, r1, 4\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r4\n\
    ldrh r1, [r0, 0x26]\n\
    subs r1, 0x22\n\
    strh r1, [r0, 0x26]\n\
    ldr r3, =0x00007b18\n\
    adds r1, r2, r3\n\
    subs r3, 0x4\n\
    adds r0, r2, r3\n\
    ldrh r0, [r0]\n\
    lsls r0, 5\n\
    ldr r3, =0x06010000\n\
    adds r0, r3\n\
    str r0, [r1]\n\
    ldr r0, =0x00007b12\n\
    adds r2, r0\n\
    ldrh r0, [r2]\n\
    lsls r0, 4\n\
    movs r1, 0x80\n\
    lsls r1, 1\n\
    adds r0, r1\n\
    strh r0, [r2]\n\
    b _08167742\n\
    .pool\n\
_08167714:\n\
    lsls r1, r6, 13\n\
    movs r0, 0xC1\n\
    lsls r0, 2\n\
    adds r1, r0\n\
    adds r1, r3, r1\n\
    ldr r2, =0x00007b18\n\
    adds r0, r3, r2\n\
    ldr r2, [r0]\n\
    ldr r0, =0x040000d4\n\
    str r1, [r0]\n\
    str r2, [r0, 0x4]\n\
    ldr r1, =0x80000400\n\
    str r1, [r0, 0x8]\n\
    ldr r0, [r0, 0x8]\n\
    lsls r0, r6, 7\n\
    adds r0, 0x4\n\
    adds r0, r3, r0\n\
    ldr r2, =0x00007b12\n\
    adds r1, r3, r2\n\
    ldrh r1, [r1]\n\
    movs r2, 0x20\n\
    bl LoadPalette\n\
_08167742:\n\
    add sp, 0x28\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

#ifdef NONMATCHING
void sub_8167760(void)
{
    s32 i;
    u8 v1;
    u8 v2;
    u8 v3;
    u32 v4;
    struct SpriteSheet *v6;
    struct SpriteTemplate *v7;
    void (*funcCB) (void);
    struct SpritePalette *v9;
    struct SpriteSheet *v10;
    struct SpritePalette *v11;
    
    sub_81D321C(v6, v7, v9);
    LoadSpriteSheets(v6);
    LoadSpritePalettes(v9);
    for(i = 0; i < gUnknown_0203BCAC->info.field_70 - 1; i++)
    {
        v1 = CreateSprite(v7, 226, (0x140000 * i + 0x80000) >> 16, 0);
        if(v1 == 64)
        {
            gUnknown_0203BCAC->field_0[0x7B06 + i] = -1;
        }
        else
        {
            gUnknown_0203BCAC->field_0[0x7B06 + i] = v1;
            gSprites[v1].data[0] = i;
            gSprites[v1].callback = (SpriteCallback) sub_8168180;    
        }
    }
    for(v7->tileTag = 103; i <= 5; i++)
    {
        v2 = CreateSprite(v7, 230, (0x140000 * i + 0x80000) >> 16, 0);
        if(v2 == 64 )
        {
            gUnknown_0203BCAC->field_0[0x7B06 + i] = -1;
        }
        else
        {
            gUnknown_0203BCAC->field_0[0x7B06 + i] = v2;
            gSprites[v2].oam.tileNum &= 0x3F;
        }
    }
    v7->tileTag = 102;
    funcCB = sub_81681B4;
    v3 = CreateSprite(v7, 222, (0x140000 * i + 0x80000) >> 16, 0);
    if(v3 == 64)
    {
        gUnknown_0203BCAC->field_0[0x7B06 + i] = -1;
    }        
    else 
    {
        gUnknown_0203BCAC->field_0[0x7B06 + i] = v3;
        v4 = 68 * v3 + 0x2020630;
        (v4 + 1) = gSprites[v2].oam.affineMode & (0x3F | 0x40);
        (v4 + 3) = (v4 + 3) & (0x3F | 0x80);
    }
    sub_81D32B0(v10, v11);
    LoadSpriteSheet(v10);
    LoadSpritePalette(v11);    
}
#else
NAKED
void sub_8167760(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x60\n\
    add r5, sp, 0x20\n\
    add r4, sp, 0x38\n\
    mov r0, sp\n\
    adds r1, r5, 0\n\
    adds r2, r4, 0\n\
    bl sub_81D321C\n\
    mov r0, sp\n\
    bl LoadSpriteSheets\n\
    adds r0, r4, 0\n\
    bl LoadSpritePalettes\n\
    movs r4, 0\n\
    ldr r1, =gUnknown_0203BCAC\n\
    ldr r0, [r1]\n\
    ldr r2, =0x00008040\n\
    adds r0, r2\n\
    ldrb r0, [r0]\n\
    subs r0, 0x1\n\
    adds r6, r5, 0\n\
    add r2, sp, 0x50\n\
    mov r9, r2\n\
    add r2, sp, 0x58\n\
    mov r10, r2\n\
    cmp r4, r0\n\
    bge _0816781C\n\
    adds r5, r1, 0\n\
    ldr r7, =gSprites\n\
    movs r0, 0x1C\n\
    adds r0, r7\n\
    mov r8, r0\n\
_081677AC:\n\
    lsls r2, r4, 2\n\
    adds r2, r4\n\
    lsls r2, 18\n\
    movs r1, 0x80\n\
    lsls r1, 12\n\
    adds r2, r1\n\
    asrs r2, 16\n\
    adds r0, r6, 0\n\
    movs r1, 0xE2\n\
    movs r3, 0\n\
    bl CreateSprite\n\
    lsls r0, 24\n\
    lsrs r3, r0, 24\n\
    cmp r3, 0x40\n\
    beq _081677FC\n\
    ldr r0, [r5]\n\
    ldr r2, =0x00007b06\n\
    adds r0, r2\n\
    adds r0, r4\n\
    strb r3, [r0]\n\
    lsls r0, r3, 4\n\
    adds r0, r3\n\
    lsls r0, 2\n\
    adds r1, r0, r7\n\
    strh r4, [r1, 0x2E]\n\
    add r0, r8\n\
    ldr r1, =sub_8168180\n\
    str r1, [r0]\n\
    b _08167808\n\
    .pool\n\
_081677FC:\n\
    ldr r0, [r5]\n\
    ldr r1, =0x00007b06\n\
    adds r0, r1\n\
    adds r0, r4\n\
    movs r1, 0xFF\n\
    strb r1, [r0]\n\
_08167808:\n\
    adds r0, r4, 0x1\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    ldr r0, [r5]\n\
    ldr r2, =0x00008040\n\
    adds r0, r2\n\
    ldrb r0, [r0]\n\
    subs r0, 0x1\n\
    cmp r4, r0\n\
    blt _081677AC\n\
_0816781C:\n\
    movs r0, 0x67\n\
    strh r0, [r6]\n\
    cmp r4, 0x5\n\
    bhi _0816788A\n\
    ldr r5, =gUnknown_0203BCAC\n\
    ldr r7, =gSprites\n\
_08167828:\n\
    lsls r2, r4, 2\n\
    adds r2, r4\n\
    lsls r2, 18\n\
    movs r0, 0x80\n\
    lsls r0, 12\n\
    adds r2, r0\n\
    asrs r2, 16\n\
    adds r0, r6, 0\n\
    movs r1, 0xE6\n\
    movs r3, 0\n\
    bl CreateSprite\n\
    lsls r0, 24\n\
    lsrs r3, r0, 24\n\
    cmp r3, 0x40\n\
    beq _08167874\n\
    ldr r0, [r5]\n\
    ldr r1, =0x00007b06\n\
    adds r0, r1\n\
    adds r0, r4\n\
    strb r3, [r0]\n\
    lsls r1, r3, 4\n\
    adds r1, r3\n\
    lsls r1, 2\n\
    adds r1, r7\n\
    ldrb r2, [r1, 0x3]\n\
    movs r0, 0x3F\n\
    ands r0, r2\n\
    strb r0, [r1, 0x3]\n\
    b _08167880\n\
    .pool\n\
_08167874:\n\
    ldr r0, [r5]\n\
    ldr r2, =0x00007b06\n\
    adds r0, r2\n\
    adds r0, r4\n\
    movs r1, 0xFF\n\
    strb r1, [r0]\n\
_08167880:\n\
    adds r0, r4, 0x1\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    cmp r4, 0x5\n\
    bls _08167828\n\
_0816788A:\n\
    movs r0, 0x66\n\
    strh r0, [r6]\n\
    ldr r0, =sub_81681B4\n\
    str r0, [r6, 0x14]\n\
    lsls r2, r4, 2\n\
    adds r2, r4\n\
    lsls r2, 18\n\
    movs r0, 0x80\n\
    lsls r0, 12\n\
    adds r2, r0\n\
    asrs r2, 16\n\
    adds r0, r6, 0\n\
    movs r1, 0xDE\n\
    movs r3, 0\n\
    bl CreateSprite\n\
    lsls r0, 24\n\
    lsrs r3, r0, 24\n\
    cmp r3, 0x40\n\
    beq _081678F4\n\
    ldr r0, =gUnknown_0203BCAC\n\
    ldr r0, [r0]\n\
    ldr r1, =0x00007b06\n\
    adds r0, r1\n\
    adds r0, r4\n\
    strb r3, [r0]\n\
    ldr r0, =gSprites\n\
    lsls r2, r3, 4\n\
    adds r2, r3\n\
    lsls r2, 2\n\
    adds r2, r0\n\
    ldrb r3, [r2, 0x1]\n\
    movs r1, 0x3F\n\
    adds r0, r1, 0\n\
    ands r0, r3\n\
    movs r3, 0x40\n\
    orrs r0, r3\n\
    strb r0, [r2, 0x1]\n\
    ldrb r0, [r2, 0x3]\n\
    ands r1, r0\n\
    movs r0, 0x80\n\
    orrs r1, r0\n\
    strb r1, [r2, 0x3]\n\
    b _08167902\n\
    .pool\n\
_081678F4:\n\
    ldr r0, =gUnknown_0203BCAC\n\
    ldr r0, [r0]\n\
    ldr r2, =0x00007b06\n\
    adds r0, r2\n\
    adds r0, r4\n\
    movs r1, 0xFF\n\
    strb r1, [r0]\n\
_08167902:\n\
    mov r0, r9\n\
    mov r1, r10\n\
    bl sub_81D32B0\n\
    mov r0, r9\n\
    bl LoadSpriteSheet\n\
    mov r0, r10\n\
    bl LoadSpritePalette\n\
    add sp, 0x60\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

bool8 sub_8167930(void)
{
    bool8 retvalue;
    switch(gUnknown_0203BCAC->info.unk78)
        {
            case 0:
                ChangeBgX(0, 0, 0);
                ChangeBgY(0, 0, 0);
                ChangeBgX(1, 0, 0);
                ChangeBgY(1, 0, 0);
                ChangeBgX(2, 0, 0);
                ChangeBgY(2, 0, 0);
                ChangeBgX(3, 0, 0);
                ChangeBgY(3, 136 << 6, 0);
                SetGpuReg(REG_OFFSET_DISPCNT, 28736);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2|BLDCNT_EFFECT_BLEND|BLDCNT_TGT2_BG1);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
                break;
            case 1:
                (u32 *) gUnknown_0203BCA4 = Alloc(6656);
                (u32 *) gUnknown_0203BCA0 = Alloc(1280);
                (u32 *) gUnknown_0203BCA8 = Alloc(1280);
                break;
            case 2:
                LZ77UnCompVram(gUnknown_085DFB60, gUnknown_0203BCA8);
                break;
            case 3:
                LoadBgTiles(3, gUnknown_085DFA80, 224, 0);
                break;
            case 4:
                 LoadBgTilemap(3, gUnknown_0203BCA8, 1280, 0);
                break;
            case 5:
                LoadPalette(gUnknown_085DFA60, 208, 32);
                gUnknown_0203BCAC->field_7B0E = 0xFFB0;
                break;
            case 6:
                LZ77UnCompVram(gUsePokeblockGraph_Gfx, gUnknown_0203BCA4);
                break;
            case 7:
                LZ77UnCompVram(gUsePokeblockGraph_Tilemap, gUnknown_0203BCA0);
                LoadPalette(gUsePokeblockGraph_Pal, 32, 32);
                break;
            case 8:
                LoadBgTiles(1, gUnknown_0203BCA4, 6656, 160 << 2);
                break;
            case 9:
                SetBgTilemapBuffer(1, gUnknown_0203BCA0);
                CopyToBgTilemapBufferRect(1, gUsePokeblockNatureWin_Pal, 0, 13, 12, 4);
                CopyBgTilemapBufferToVram(1);
                break;
            case 10:
                LZ77UnCompVram(gUnknown_085DFC0C, &gUnknown_0203BCAC->field_0[0x7304]);
                break;
            case 11:
                LoadBgTilemap(2, &gUnknown_0203BCAC->field_0[0x7304], 1280, 0);
                LoadPalette(gUnknown_086231E8, 48, 32);
                LoadPalette(gUnknown_08623208, 240, 32);
                sub_81D21DC(2);
                break;
            default:
                gUnknown_0203BCAC->info.unk78 = 0;
                retvalue = 0;
                return retvalue;
        }
        gUnknown_0203BCAC->info.unk78++;
        retvalue = 1;
        return retvalue;
}

void sub_8167BA0(u16 arg0, u8 copyToVramMode)
{
    u8 partyIndex;
    u8 nature;
    u8 *str;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
    {
        AddTextPrinterParameterized(0, 1, gUnknown_0203BCAC->field_7B95[arg0], 0, 1, 0, NULL);
        partyIndex = sub_81672A4(gUnknown_0203BCAC->info.field_71);
        nature = GetNature(&gPlayerParty[partyIndex]);
        str = StringCopy(gUnknown_0203BCAC->info.field_7A, gText_NatureSlash);
        str = StringCopy(str, gNatureNamePointers[nature]);
        AddTextPrinterParameterized3(1, 1, 2, 1, gUnknown_085DFCC9, 0, gUnknown_0203BCAC->info.field_7A);
    }

    if (copyToVramMode)
    {
        CopyWindowToVram(0, 3);
        CopyWindowToVram(1, 3);
    }
    else
    {
        CopyWindowToVram(0, 2);
        CopyWindowToVram(1, 2);
    }
}

static void sub_8167CA0(bool8 arg0)
{
    u16 var0;
    int var1;
    int r8;
    int r4;

    if (arg0)
        var0 = gUnknown_0203BCAC->field_7FB5;
    else
        var0 = gUnknown_0203BCAC->field_7FB4;

    sub_81D1F84(
        &gUnknown_0203BCAC->field_7C58,
        gUnknown_0203BCAC->field_7C58.unk14[gUnknown_0203BCAC->field_7FB3],
        gUnknown_0203BCAC->field_7C58.unk14[var0]);

    r8 = (gUnknown_0203BCAC->info.field_71 ^ (gUnknown_0203BCAC->info.field_70 - 1)) ? 1 : 0;
    if (arg0)
    {
        gUnknown_0203BCAC->field_7FB5 = gUnknown_0203BCAC->field_7FB4;
        gUnknown_0203BCAC->field_7FB4 = gUnknown_0203BCAC->field_7FB3;
        gUnknown_0203BCAC->field_7FB3 = var0;
        gUnknown_0203BCAC->field_7FB6 = gUnknown_0203BCAC->field_7FB5;

        gUnknown_0203BCAC->info.field_71 = gUnknown_0203BCAC->info.field_71 == 0
            ? gUnknown_0203BCAC->info.field_70 - 1
            : gUnknown_0203BCAC->info.field_71 - 1;

        gUnknown_0203BCAC->field_7B4C = gUnknown_0203BCAC->info.field_71 == 0
            ? gUnknown_0203BCAC->info.field_70 - 1
            : gUnknown_0203BCAC->info.field_71 - 1;
    }
    else
    {
        gUnknown_0203BCAC->field_7FB4 = gUnknown_0203BCAC->field_7FB5;
        gUnknown_0203BCAC->field_7FB5 = gUnknown_0203BCAC->field_7FB3;
        gUnknown_0203BCAC->field_7FB3 = var0;
        gUnknown_0203BCAC->field_7FB6 = gUnknown_0203BCAC->field_7FB4;

        gUnknown_0203BCAC->info.field_71 = gUnknown_0203BCAC->info.field_71 < gUnknown_0203BCAC->info.field_70 - 1
            ? gUnknown_0203BCAC->info.field_71 + 1
            : 0;

        gUnknown_0203BCAC->field_7B4C = gUnknown_0203BCAC->info.field_71 < gUnknown_0203BCAC->info.field_70 - 1
            ? gUnknown_0203BCAC->info.field_71 + 1
            : 0;
    }

    r4 = (gUnknown_0203BCAC->info.field_71 ^ (gUnknown_0203BCAC->info.field_70 - 1)) ? 1 : 0;
    sub_81D3520(gUnknown_0203BCAC->field_7B1C);

    if (!r8)
        gUnknown_0203BCAC->info.unk74 = sub_8167EA4;
    else if (!r4)
        gUnknown_0203BCAC->info.unk74 = sub_8167FA4;
    else
        gUnknown_0203BCAC->info.unk74 = sub_8168048;
}

static u8 sub_8167EA4(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_8167608(gUnknown_0203BCAC->field_7FB3);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        if (!sub_81D3178(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
        {
            sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 3:
        sub_81D3464(gUnknown_0203BCAC->field_7B1C);
        if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
        {
            u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
            sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
        }

        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8167FA4(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        if (!sub_81D31A4(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
            gUnknown_0203BCAC->info.unk78++;
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 3:
        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8168048(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_81D2074(&gUnknown_0203BCAC->field_7C58);
        if (!sub_81D3150(&gUnknown_0203BCAC->field_7B0E))
        {
            sub_8167608(gUnknown_0203BCAC->field_7FB3);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 1:
        sub_8167BA0(gUnknown_0203BCAC->field_7FB3, 0);
        gUnknown_0203BCAC->info.unk78++;
        break;
    case 2:
        if (!sub_81D3178(&gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7B0E))
        {
            sub_816753C(gUnknown_0203BCAC->field_7B4C, gUnknown_0203BCAC->field_7FB6);
            gUnknown_0203BCAC->info.unk78++;
        }
        break;
    case 3:
        sub_81D3464(gUnknown_0203BCAC->field_7B1C);
        if (gUnknown_0203BCAC->info.field_71 != gUnknown_0203BCAC->info.field_70 - 1)
        {
            u8 var0 = gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3];
            sub_81D3480(gUnknown_0203BCAC->field_7B1C, gUnknown_0203BCAC->field_7B10, var0);
        }

        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return TRUE;
}

void sub_8168168(struct Sprite *sprite)
{
    sprite->pos1.x = gUnknown_0203BCAC->field_7B0E + 38;
}

void sub_8168180(struct Sprite *sprite)
{
    if (sprite->data[0] == gUnknown_0203BCAC->info.field_71)
        StartSpriteAnim(sprite, 0);
    else
        StartSpriteAnim(sprite, 1);
}

void sub_81681B4(struct Sprite *sprite)
{
    if (gUnknown_0203BCAC->info.field_71 == gUnknown_0203BCAC->info.field_70 - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(101);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(102);
}

void sub_81681F4(u8 monIndex)
{
    u8 sheen = GetMonData(&gPlayerParty[monIndex], MON_DATA_SHEEN);
    gUnknown_0203BCAC->unk7FB0[gUnknown_0203BCAC->field_7FB3] = sheen != 255
        ? sheen / 29
        : 9;
}

static void sub_8168248(void)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spritePalette = gUnknown_085DFDB8;
    spriteSheet.data = gUsePokeblockCondition_Gfx;
    spriteSheet.size = 0x800;
    spriteSheet.tag = 1;
    LoadCompressedSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
}

static void sub_8168294(void)
{
    u16 i;
    s16 xDiff, xStart;
    int yStart = 17;
    int var = 8;
    struct Sprite **sprites = gUnknown_0203BCAC->field_7B44;
    const struct SpriteTemplate *template = &gUnknown_085DFDA0;

    for (i = 0, xDiff = 64, xStart = -96; i < 2; i++)
    {
        u8 spriteId = CreateSprite(template, i * xDiff + xStart, yStart, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = var;
            gSprites[spriteId].data[1] = (i * xDiff) | 32;
            gSprites[spriteId].data[2] = i;
            StartSpriteAnim(&gSprites[spriteId], i);
            sprites[i] = &gSprites[spriteId];
        }
    }
}

static bool8 sub_8168328(void)
{
    switch (gUnknown_0203BCAC->info.unk78)
    {
    case 0:
        sub_8168248();
        gUnknown_0203BCAC->info.unk78++;
        return TRUE;
    case 1:
        sub_8168294();
        gUnknown_0203BCAC->info.unk78 = 0;
        return FALSE;
    }

    return FALSE;
}

void sub_8168374(struct Sprite *sprite)
{
    s16 prevX = sprite->pos1.x;
    sprite->pos1.x += sprite->data[0];
    if ((prevX <= sprite->data[1] && sprite->pos1.x >= sprite->data[1])
     || (prevX >= sprite->data[1] && sprite->pos1.x <= sprite->data[1]))
    {
        sprite->pos1.x = sprite->data[1];
        sprite->callback = SpriteCallbackDummy;
    }
}
