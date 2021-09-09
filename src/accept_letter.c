#include "global.h"
#include "diploma.h"
#include "palette.h"
#include "main.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "task.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "overworld.h"
#include "menu.h"
#include "pokedex.h"
#include "constants/rgb.h"

#include "accept_letter.h"
#include "accept_letter_text.h"
#include "printf.h"
#include "mgba.h" //https://github.com/pret/pokeemerald/wiki/printf-in-mGBA

static void MainCB2(void);
static void Task_DiplomaFadeIn(u8);
static void Task_DiplomaWaitForKeyPress(u8);
static void Task_DiplomaFadeOut(u8);
static void DisplayDiplomaText(void);
static void InitDiplomaBg(void);
static void InitDiplomaWindow(void);
static void PrintDiplomaText(u8 *, u8, u8);

EWRAM_DATA static u8 *sDiplomaTilemapPtr = NULL;

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u16 sDiplomaPalettes[][16] =
{
    INCBIN_U16("graphics/misc/diploma_national.gbapal"),
    INCBIN_U16("graphics/misc/diploma_hoenn.gbapal"),
};

static const u32 sDiplomaTilemap[] = INCBIN_U32("graphics/misc/diploma_map.bin.lz");
static const u32 sDiplomaTiles[] = INCBIN_U32("graphics/misc/diploma.4bpp.lz");

void MySpecial(void)
{
    mgba_printf(MGBA_LOG_DEBUG, "nice");
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    // why doesn't this one use the dma manager either?
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadPalette(sDiplomaPalettes, 0, 64);
    sDiplomaTilemapPtr = malloc(0x1000);
    InitDiplomaBg();
    InitDiplomaWindow();
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, &sDiplomaTiles, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(sDiplomaTilemap, sDiplomaTilemapPtr);
    CopyBgTilemapBufferToVram(1);
    DisplayDiplomaText();
    BlendPalettes(-1, 16, 0);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(MainCB2);
    CreateTask(Task_DiplomaFadeIn, 0);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_DiplomaFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DiplomaWaitForKeyPress;
}

static void Task_DiplomaWaitForKeyPress(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_DiplomaFadeOut;
    }
}

static void Task_DiplomaFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sDiplomaTilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldFadeFromBlack);
    }
}

static void DisplayDiplomaText(void)
{
    StringExpandPlaceholders(gStringVar4, gText_SuperMonolougeText1);
    PrintDiplomaText(gStringVar4, 0, 0);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static const struct BgTemplate sDiplomaBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static void InitDiplomaBg(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sDiplomaBgTemplates, ARRAY_COUNT(sDiplomaBgTemplates));
    SetBgTilemapBuffer(1, sDiplomaTilemapPtr);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static const struct WindowTemplate sDiplomaWinTemplates[2] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 26,
        .height = 20,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

static void InitDiplomaWindow(void)
{
    InitWindows(sDiplomaWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
}

static void PrintDiplomaText(u8 *text, u8 var1, u8 var2)
{
    u8 color[3] = {0, 1, 2};
    //u8 color[3] = {0, 2, 3};//original

    //Print text to the screen
    //windowId :0
    //fontId: 1
    //x coordinate: var1
    //y coordinate: var2
    //letterSpacing: 0
    //lineSpacing: 0
    //color
    //speed
    //text pointer
    AddTextPrinterParameterized4(0, 1, var1, var2, 0, 0, color, -1, text);
}
