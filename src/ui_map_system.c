#include "global.h"
#include "ui_map_system.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/map_types.h"
#include "trig.h"
#include "secret_base.h"
#include "region_map.h"
#include "money.h"
#include "field_effect.h"
#include "constants/heal_locations.h"

#define MAP_WIDTH 28
#define MAP_HEIGHT 16
#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)
#define FLYDESTICON_RED_OUTLINE 6

#define CURSOR_NO_LOC 0
#define CURSOR_LOC 1

#define WARP_FAILED_PAUSE_END 0
#define WARP_FAILED_PAUSE_START 100
#define WARP_UBER 0
#define WARP_TAXI 1

/*
 *
 */

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    WINDOW_1,
    WINDOW_2,
};


//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA struct SFRegionMap *sRegionMap = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 RegionMap_LoadGraphics(void);
static void Menu_InitWindows(void);
void InitSFRegionMapData(struct SFRegionMap *regionMap);
static void PrintDefaultHeaderTitleToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

static void SpriteCB_CursorMapFull(struct Sprite *sprite);
static void SpriteCB_CursorMapFullLOC(struct Sprite *sprite);
static void SpriteCB_CursorMapZoomed(struct Sprite *sprite);
void CreateSFRegionMapCursor(u16 tileTag, u16 paletteTag);
static void FreeRegionMapCursorSprite(void);

static void UpdateSFRegionMapVideoRegs(void);
static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
static bool8 RegionMap_IsMapSecIdInNextRow(u16 y);
static void GetPositionOfCursorWithinMapSec(void);
static void InitMapBasedOnPlayerLocation(void);
static u8 *GetSFMapName(u8 *dest, u16 regionMapId, u16 padLength);
static u16 GetSFRegionMapSecIdAt(u16 x, u16 y);
static u8 GetMapsecType(u16 mapSecId);
static u16 GetMapSecIdAt(u16 x, u16 y);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
u8 DoInputCallback(void);

static void Task_ChangeBgYForZoom(u8 taskId);
static bool32 IsChangeBgYForZoomActive(void);
static void ChangeBgYForZoom(bool32 zoomIn);
bool8 UpdateSFRegionMapZoom(void);
void SetSFRegionMapDataForZoom(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void RegionMapZoomOut(u8 taskId);
static void RegionMapZoomIn(u8 taskId);

static void SFTrySetPlayerIconBlink(void);
static void SpriteCB_PlayerIcon(struct Sprite *sprite);
static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite);
static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite);
static void UnhideRegionMapPlayerIcon(void);
static void UnhideRegionMapCursorIcon(void);
static void HideRegionMapPlayerIcon(void);
static void HideRegionMapCursorIcon(void);
static void SFCreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag);

static u8 HandleWarpFailedNoCash(void);
static u8 HandleAttemptWarpInput(void);
u32 GetWarpPriceAtMapSec(u16 mapSecId, u8 warp_type);
static u8 HandleWarpConfirmInput(void);
static u8 HandleWarpCloseMenu(void);

static void PrintWarpPriceOnTooltip(u32 spriteId, u32 bgColor, u32 startTile);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 1
    },
    {
        .bg = 2, // Region Map Bg - Affine
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2
    }

};

static const struct WindowTemplate sMenuWindowTemplates[] =
{
    [WINDOW_1] =
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    [WINDOW_2] =
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 18,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1 + 60,     // tile start in VRAM
    },
};

static const struct WindowTemplate sTooltipWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 8,
    .height = 2,
    .paletteNum = 0,
    .baseBlock = 1 + 120
};

static const u32 sRegionMapTiles[] = INCBIN_U32("graphics/ui_menus/map_system/tiles.8bpp.lz");
static const u32 sRegionMapTilemap[] = INCBIN_U32("graphics/ui_menus/map_system/tiles.bin.lz");
static const u16 sRegionMapPalette[] = INCBIN_U16("graphics/ui_menus/map_system/map_tileset.gbapal");

static const u32 sBarsTiles[] = INCBIN_U32("graphics/ui_menus/map_system/bars.4bpp.lz");
static const u32 sBarsTilemap[] = INCBIN_U32("graphics/ui_menus/map_system/bars.bin.lz");
static const u16 sBarsPalette[] = INCBIN_U16("graphics/ui_menus/map_system/bars.gbapal");

static const u16 sRegionMapCursorPal[] = INCBIN_U16("graphics/ui_menus/map_system/cursor_small.gbapal");
static const u32 sRegionMapCursorSmallGfxLZ[] = INCBIN_U32("graphics/ui_menus/map_system/cursor_small.4bpp.lz");

static const u16 sRegionMapL2CursorPal[] = INCBIN_U16("graphics/ui_menus/map_system/L2_cursor.gbapal");
static const u32 sRegionMapCursorL2GfxLZ[] = INCBIN_U32("graphics/ui_menus/map_system/L2_cursor_test.4bpp.lz");

static const u8 sA_ButtonGfx[]         = INCBIN_U8("graphics/ui_menus/map_system/a_button.4bpp");
static const u8 sB_ButtonGfx[]         = INCBIN_U8("graphics/ui_menus/map_system/b_button.4bpp");
static const u8 sSelect_ButtonGfx[]         = INCBIN_U8("graphics/ui_menus/map_system/select_button.4bpp");
static const u8 sStart_ButtonGfx[]         = INCBIN_U8("graphics/ui_menus/map_system/start_button.4bpp");
//static const u16 sButtonsPalette[] = INCBIN_U16("graphics/ui_menus/map_system/buttons.gbapal");

static const u16 sRegionMapPlayerIcon_BrendanPal[] = INCBIN_U16("graphics/pokenav/region_map/brendan_icon.gbapal");
static const u8 sRegionMapPlayerIcon_BrendanGfx[] = INCBIN_U8("graphics/pokenav/region_map/brendan_icon.4bpp");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

enum {
    TAG_CURSOR,
    TAG_PLAYER_ICON,
    TAG_FLY_ICON,
    TAG_CURSOR_LOC,
};

static const u8 sRegionMap_MapSectionLayout[MAP_HEIGHT][MAP_WIDTH] = {
    {MAPSEC_NONE, MAPSEC_MUIRWOODS, MAPSEC_PSFROUTE61, MAPSEC_PSFROUTE61, MAPSEC_PSFROUTE61, MAPSEC_PSFROUTE61, MAPSEC_MARIN, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_PSFROUTE76, MAPSEC_BERKELEY, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_GLDNGTEBRIDGE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE76, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_ALCATRAZ, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE63, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_GLDNGTEBRIDGE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE15, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE63, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_GLDNGTEBRIDGE, MAPSEC_GLDNGTEBRIDGE, MAPSEC_FORTPOINT, MAPSEC_PSFROUTE2, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE1, MAPSEC_PSFROUTE1, MAPSEC_PSFROUTE1, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE63, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_PSFROUTE49, MAPSEC_PSFROUTE49, MAPSEC_PSFROUTE49, MAPSEC_PSFROUTE49, MAPSEC_PSFROUTE49, MAPSEC_PSFROUTE49, MAPSEC_PRESIDIO, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE2, MAPSEC_PSFROUTE1, MAPSEC_PSFROUTE1, MAPSEC_PSFROUTE1, MAPSEC_LOMBARDSTREET, MAPSEC_PSFROUTE1, MAPSEC_PSFROUTE1, MAPSEC_NONE, MAPSEC_TRANSPYRAMID, MAPSEC_NONE, MAPSEC_TREASUREISLAND, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE63, MAPSEC_PSFROUTE63, MAPSEC_PSFROUTE63, MAPSEC_LAKEMERRITT},
    {MAPSEC_PACIFICA, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE2, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE70, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE8, MAPSEC_PSFROUTE30, MAPSEC_PSFROUTE30, MAPSEC_PSFROUTE30, MAPSEC_PSFROUTE30, MAPSEC_PSFROUTE30, MAPSEC_OAKLAND, MAPSEC_OAKLAND, MAPSEC_NONE, MAPSEC_PSFROUTE62, MAPSEC_NONE},
    {MAPSEC_PSFROUTE5, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE2, MAPSEC_NONE, MAPSEC_JAPANTOWN, MAPSEC_NONE, MAPSEC_TENDERLOIN, MAPSEC_NONE, MAPSEC_CHINATOWN, MAPSEC_PSFROUTE8, MAPSEC_PSFROUTE8, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_OAKLAND, MAPSEC_OAKLAND, MAPSEC_NONE, MAPSEC_PSFROUTE62, MAPSEC_OAKLANDCOLISEUM},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_GLDNGTEPARK, MAPSEC_GLDNGTEPARK, MAPSEC_GLDNGTEPARK, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE2, MAPSEC_NONE, MAPSEC_PSFROUTE38, MAPSEC_PSFROUTE38, MAPSEC_TENDERLOIN, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_FERRYBUILDING, MAPSEC_PSFROUTE51, MAPSEC_PSFROUTE51, MAPSEC_PSFROUTE51, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE72, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_GLDNGTEPARK, MAPSEC_GLDNGTEPARK, MAPSEC_GLDNGTEPARK, MAPSEC_NONE, MAPSEC_HAIGHTASHBURY, MAPSEC_PSFROUTE43, MAPSEC_PSFROUTE43, MAPSEC_PAINTEDLADIES, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE9, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE8, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE51, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE72, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE13, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE9, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_SALESFORCETOWER, MAPSEC_SOMA, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE51, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE72, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE7, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE13, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_MISSION, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_SOMA, MAPSEC_SOMA, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE51, MAPSEC_PSFROUTE51, MAPSEC_PSFROUTE51, MAPSEC_NAVALBASE, MAPSEC_ALAMEDA, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE7, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_CASTRO, MAPSEC_CASTRO, MAPSEC_NONE, MAPSEC_PSFROUTE14, MAPSEC_PSFROUTE14, MAPSEC_MISSION, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE22, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_SUNSET, MAPSEC_PSFROUTE7, MAPSEC_PSFROUTE7, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_CASTRO, MAPSEC_CASTRO, MAPSEC_PSFROUTE14, MAPSEC_PSFROUTE14, MAPSEC_NONE, MAPSEC_PSFROUTE11, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE22, MAPSEC_CHASECENTER, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_PSFROUTE32, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE18, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_BERNALHEIGHTS, MAPSEC_PSFROUTE21, MAPSEC_PSFROUTE21, MAPSEC_NONE, MAPSEC_PSFROUTE22, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_LAKEMERCED, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE18, MAPSEC_PSFROUTE18, MAPSEC_PSFROUTE18, MAPSEC_PSFROUTE18, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_PSFROUTE17, MAPSEC_NONE, MAPSEC_PSFROUTE21, MAPSEC_PSFROUTE21, MAPSEC_DOGPATCH, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
    {MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_TWINPEAKS, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_SOUTHBAY, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE, MAPSEC_NONE},
};

static const u8 sMapHealLocations[][3] =
{
    [MAPSEC_SOUTHBAY] = {MAP_GROUP(SOUTHBAY), MAP_NUM(SOUTHBAY), HEAL_LOCATION_SOUTHBAY_COMPOUND_2F},
    [MAPSEC_ALAMEDA]={MAP_GROUP(ALAMEDA),MAP_NUM(ALAMEDA),HEAL_LOCATION_ALAMEDA},
    [MAPSEC_ALCATRAZ]={MAP_GROUP(ALCATRAZ),MAP_NUM(ALCATRAZ),HEAL_LOCATION_ALCATRAZ},
    [MAPSEC_BERKELEY]={MAP_GROUP(BERKELEY),MAP_NUM(BERKELEY),HEAL_LOCATION_BERKELEY},
    [MAPSEC_BERNALHEIGHTS]={MAP_GROUP(BERNALHEIGHTS),MAP_NUM(BERNALHEIGHTS),HEAL_LOCATION_BERNALHEIGHTS},
    [MAPSEC_CASTRO]={MAP_GROUP(CASTRO),MAP_NUM(CASTRO),HEAL_LOCATION_CASTRO},
    [MAPSEC_CHINATOWN]={MAP_GROUP(CHINATOWN),MAP_NUM(CHINATOWN),HEAL_LOCATION_CHINATOWN},
    [MAPSEC_DOGPATCH]={MAP_GROUP(DOGPATCH),MAP_NUM(DOGPATCH),HEAL_LOCATION_DOGPATCH},
    [MAPSEC_FISHERMANSWHARF]={MAP_GROUP(FISHERMANSWHARF),MAP_NUM(FISHERMANSWHARF),HEAL_LOCATION_FISHERMANSWHARF},
    [MAPSEC_FORTPOINT]={MAP_GROUP(FORTPOINT),MAP_NUM(FORTPOINT),HEAL_LOCATION_FORTPOINT},
    [MAPSEC_GLDNGTEBRIDGE]={MAP_GROUP(GLDNGTEBRIDGE),MAP_NUM(GLDNGTEBRIDGE),HEAL_LOCATION_GLDNGTEBRIDGE},
    [MAPSEC_GLDNGTEPARK]={MAP_GROUP(GLDNGTEPARK),MAP_NUM(GLDNGTEPARK),HEAL_LOCATION_GLDNGTEPARK},
    [MAPSEC_HAIGHTASHBURY]={MAP_GROUP(HAIGHTASHBURY),MAP_NUM(HAIGHTASHBURY),HEAL_LOCATION_HAIGHTASHBURY},
    [MAPSEC_JAPANTOWN]={MAP_GROUP(JAPANTOWN),MAP_NUM(JAPANTOWN),HEAL_LOCATION_JAPANTOWN},
    [MAPSEC_LAKEMERCED]={MAP_GROUP(LAKEMERCED),MAP_NUM(LAKEMERCED),HEAL_LOCATION_LAKEMERCED},
    [MAPSEC_LAKEMERRITT]={MAP_GROUP(LAKEMERRITT),MAP_NUM(LAKEMERRITT),HEAL_LOCATION_LAKEMERRITT},
    [MAPSEC_LOMBARDSTREET]={MAP_GROUP(LOMBARDSTREET),MAP_NUM(LOMBARDSTREET),HEAL_LOCATION_LOMBARDSTREET},
    [MAPSEC_MARIN]={MAP_GROUP(MARIN),MAP_NUM(MARIN),HEAL_LOCATION_MARIN},
    [MAPSEC_MISSION]={MAP_GROUP(MISSION),MAP_NUM(MISSION),HEAL_LOCATION_MISSION},
    [MAPSEC_MUIRWOODS]={MAP_GROUP(MUIRWOODS_INNER),MAP_NUM(MUIRWOODS_INNER),HEAL_LOCATION_MUIRWOODS_INNER},
    [MAPSEC_OAKLAND]={MAP_GROUP(OAKLAND),MAP_NUM(OAKLAND),HEAL_LOCATION_OAKLAND},
    [MAPSEC_OAKLANDCOLISEUM       ]={MAP_GROUP(OAKLAND_COLISEUM_OUTSIDE),MAP_NUM(OAKLAND_COLISEUM_OUTSIDE),HEAL_LOCATION_OAKLAND_COLISEUM_OUTSIDE},
    [MAPSEC_PACIFICA]={MAP_GROUP(PACIFICA),MAP_NUM(PACIFICA),HEAL_LOCATION_PACIFICA},
    [MAPSEC_PAINTEDLADIES]={MAP_GROUP(PAINTEDLADIES),MAP_NUM(PAINTEDLADIES),HEAL_LOCATION_PAINTEDLADIES},
    [MAPSEC_PALACEFINEARTS]={MAP_GROUP(PALACEFINEARTS),MAP_NUM(PALACEFINEARTS),HEAL_LOCATION_PALACEFINEARTS},
    [MAPSEC_PRESIDIO]={MAP_GROUP(PRESIDIO),MAP_NUM(PRESIDIO),HEAL_LOCATION_PRESIDIO},
    [MAPSEC_PSFROUTE1]={MAP_GROUP(PSFROUTE1),MAP_NUM(PSFROUTE1),HEAL_LOCATION_PSFROUTE1},
    [MAPSEC_PSFROUTE11]={MAP_GROUP(PSFROUTE11),MAP_NUM(PSFROUTE11),HEAL_LOCATION_PSFROUTE11},
    [MAPSEC_PSFROUTE12]={MAP_GROUP(PSFROUTE12),MAP_NUM(PSFROUTE12),HEAL_LOCATION_PSFROUTE12},
    [MAPSEC_PSFROUTE13]={MAP_GROUP(PSFROUTE13),MAP_NUM(PSFROUTE13),HEAL_LOCATION_PSFROUTE13},
    [MAPSEC_PSFROUTE14]={MAP_GROUP(PSFROUTE14),MAP_NUM(PSFROUTE14),HEAL_LOCATION_PSFROUTE14},
    [MAPSEC_PSFROUTE15]={MAP_GROUP(PSFROUTE15),MAP_NUM(PSFROUTE15),HEAL_LOCATION_PSFROUTE15},
    [MAPSEC_PSFROUTE17]={MAP_GROUP(PSFROUTE17),MAP_NUM(PSFROUTE17),HEAL_LOCATION_PSFROUTE17},
    [MAPSEC_PSFROUTE18]={MAP_GROUP(PSFROUTE18),MAP_NUM(PSFROUTE18),HEAL_LOCATION_PSFROUTE18},
    [MAPSEC_PSFROUTE19]={MAP_GROUP(PSFROUTE19),MAP_NUM(PSFROUTE19),HEAL_LOCATION_PSFROUTE19},
    [MAPSEC_PSFROUTE2]={MAP_GROUP(PSFROUTE2),MAP_NUM(PSFROUTE2),HEAL_LOCATION_PSFROUTE2},
    [MAPSEC_PSFROUTE20]={MAP_GROUP(PSFROUTE20),MAP_NUM(PSFROUTE20),HEAL_LOCATION_PSFROUTE20},
    [MAPSEC_PSFROUTE21]={MAP_GROUP(PSFROUTE21),MAP_NUM(PSFROUTE21),HEAL_LOCATION_PSFROUTE21},
    [MAPSEC_PSFROUTE22]={MAP_GROUP(PSFROUTE22),MAP_NUM(PSFROUTE22),HEAL_LOCATION_PSFROUTE22},
    [MAPSEC_PSFROUTE30]={MAP_GROUP(PSFROUTE30),MAP_NUM(PSFROUTE30),HEAL_LOCATION_PSFROUTE30},
    [MAPSEC_PSFROUTE32]={MAP_GROUP(PSFROUTE32),MAP_NUM(PSFROUTE32),HEAL_LOCATION_PSFROUTE32},
    [MAPSEC_PSFROUTE38]={MAP_GROUP(PSFROUTE38),MAP_NUM(PSFROUTE38),HEAL_LOCATION_PSFROUTE38},
    [MAPSEC_PSFROUTE43]={MAP_GROUP(PSFROUTE43),MAP_NUM(PSFROUTE43),HEAL_LOCATION_PSFROUTE43},
    [MAPSEC_PSFROUTE49]={MAP_GROUP(PSFROUTE49),MAP_NUM(PSFROUTE49),HEAL_LOCATION_PSFROUTE49},
    [MAPSEC_PSFROUTE5]={MAP_GROUP(PSFROUTE5),MAP_NUM(PSFROUTE5),HEAL_LOCATION_PSFROUTE5},
    [MAPSEC_PSFROUTE51]={MAP_GROUP(PSFROUTE51),MAP_NUM(PSFROUTE51),HEAL_LOCATION_PSFROUTE51},
    [MAPSEC_PSFROUTE61]={MAP_GROUP(PSFROUTE61),MAP_NUM(PSFROUTE61),HEAL_LOCATION_PSFROUTE61},
    [MAPSEC_PSFROUTE62]={MAP_GROUP(PSFROUTE62),MAP_NUM(PSFROUTE62),HEAL_LOCATION_PSFROUTE62},
    [MAPSEC_PSFROUTE63]={MAP_GROUP(PSFROUTE63),MAP_NUM(PSFROUTE63),HEAL_LOCATION_PSFROUTE63},
    [MAPSEC_PSFROUTE7]={MAP_GROUP(PSFROUTE7),MAP_NUM(PSFROUTE7),HEAL_LOCATION_PSFROUTE7},
    [MAPSEC_PSFROUTE70]={MAP_GROUP(PSFROUTE70),MAP_NUM(PSFROUTE70),HEAL_LOCATION_PSFROUTE70},
    [MAPSEC_PSFROUTE72]={MAP_GROUP(PSFROUTE72),MAP_NUM(PSFROUTE72),HEAL_LOCATION_PSFROUTE72},
    [MAPSEC_PSFROUTE76]={MAP_GROUP(PSFROUTE76),MAP_NUM(PSFROUTE76),HEAL_LOCATION_PSFROUTE76},
    [MAPSEC_PSFROUTE8]={MAP_GROUP(PSFROUTE8),MAP_NUM(PSFROUTE8),HEAL_LOCATION_PSFROUTE8},
    [MAPSEC_PSFROUTE9]={MAP_GROUP(PSFROUTE9),MAP_NUM(PSFROUTE9),HEAL_LOCATION_PSFROUTE9},
    [MAPSEC_SOMA]={MAP_GROUP(SOMA),MAP_NUM(SOMA),HEAL_LOCATION_SOMA},
    [MAPSEC_SOUTHBAY]={MAP_GROUP(SOUTHBAY),MAP_NUM(SOUTHBAY),HEAL_LOCATION_SOUTHBAY},
    [MAPSEC_SUNSET]={MAP_GROUP(SUNSET),MAP_NUM(SUNSET),HEAL_LOCATION_SUNSET},
    [MAPSEC_TENDERLOIN]={MAP_GROUP(TENDERLOIN),MAP_NUM(TENDERLOIN),HEAL_LOCATION_TENDERLOIN},
    [MAPSEC_TREASUREISLAND]={MAP_GROUP(TREASUREISLAND),MAP_NUM(TREASUREISLAND),HEAL_LOCATION_TREASUREISLAND},
    [MAPSEC_TWINPEAKS]={MAP_GROUP(TWINPEAKS),MAP_NUM(TWINPEAKS),HEAL_LOCATION_TWINPEAKS},
};

static const u8 sMenuWindowFontColors[][3] =
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

static const struct OamData sRegionMapCursorOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1
};

static const union AnimCmd sRegionMapCursorAnim1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sRegionMapCursorAnim2[] =
{
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sRegionMapCursorAnimTable[] =
{
    sRegionMapCursorAnim1,
    sRegionMapCursorAnim2
};

static const struct SpritePalette sRegionMapCursorSpritePalette =
{
    .data = sRegionMapCursorPal,
    .tag = TAG_CURSOR
};

static const struct SpriteTemplate sRegionMapCursorSpriteTemplate =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sRegionMapCursorOam,
    .anims = sRegionMapCursorAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CursorMapFull
};

static const struct OamData sRegionMapL2CursorOam =
{
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 2
};

static const union AnimCmd sRegionMapL2CursorAnim1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sRegionMapL2CursorAnim2[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sRegionMapL2CursorAnimTable[] =
{
    sRegionMapL2CursorAnim1,
    sRegionMapL2CursorAnim2
};

static const struct SpritePalette sRegionMapL2CursorSpritePalette =
{
    .data = sRegionMapL2CursorPal,
    .tag = TAG_CURSOR_LOC
};

static const struct SpriteTemplate sRegionMapL2CursorSpriteTemplate =
{
    .tileTag = TAG_CURSOR_LOC,
    .paletteTag = TAG_CURSOR_LOC,
    .oam = &sRegionMapL2CursorOam,
    .anims = sRegionMapL2CursorAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CursorMapFullLOC,
};

static const struct OamData sRegionMapPlayerIconOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const union AnimCmd sRegionMapPlayerIconAnim1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sRegionMapPlayerIconAnimTable[] =
{
    sRegionMapPlayerIconAnim1
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMapSystemFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        MapSystem_Init(CB2_ReturnToUIMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void MapSystem_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    if ((sRegionMap = AllocZeroed(sizeof(struct SFRegionMap))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    gMain.state = 0;
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    UpdateSFRegionMapVideoRegs();
}

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        HideBg(1);
        HideBg(2);
        HideBg(3);
        SetBgMode(1);
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        //LoadMessageBoxAndBorderGfx();
        Menu_InitWindows();
        InitSFRegionMapData(sRegionMap);
        gMain.state++;
        break;
    case 4:
        if (RegionMap_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 5:
        sRegionMap->mapSecType = GetMapsecType(sRegionMap->mapSecId);
        if (sRegionMap->mapSecType != MAPSECTYPE_NONE)
            sRegionMap->active_cursor = CURSOR_LOC;
        else
            sRegionMap->active_cursor = CURSOR_NO_LOC;
        CreateSFRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
        PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        //SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        //SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_256COLOR
        //                                                | BGCNT_AFF512x512
        //                                                | BGCNT_CHARBASE(2)
        //                                                | BGCNT_SCREENBASE(28));
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    try_free(sRegionMap);
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
    if (sRegionMap->playerIconSprite != NULL)
    {
        DestroySprite(sRegionMap->playerIconSprite);
        FreeSpriteTilesByTag(sRegionMap->playerIconTileTag);
        FreeSpritePaletteByTag(sRegionMap->playerIconPaletteTag);
    }
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    //SetGpuReg(REG_OFFSET_BLDCNT, 0);
    //SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    //SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_AFF256x256);

    return TRUE;
}

void InitSFRegionMapData(struct SFRegionMap *regionMap)
{
    sRegionMap = regionMap;
    sRegionMap->initStep = 0;
    sRegionMap->zoomed = FALSE;
    sRegionMap->inputCallback = ProcessRegionMapInput_Full;
    sRegionMap->bgNum = 2;
    sRegionMap->charBaseIdx = 2;
    sRegionMap->mapBaseIdx = 28;
    sRegionMap->bgManaged = FALSE;
    return;
}

static void SpriteCB_CursorMapFull(struct Sprite *sprite)
{
    if (sRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->x += 2 * sRegionMap->cursorDeltaX;
        sprite->y += 2 * sRegionMap->cursorDeltaY;
        sRegionMap->cursorMovementFrameCounter--;
    }
}

static void SpriteCB_CursorMapFullLOC(struct Sprite *sprite)
{
    if (sRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->x += 2 * sRegionMap->cursorDeltaX;
        sprite->y += 2 * sRegionMap->cursorDeltaY;
    }
}

static void SpriteCB_CursorMapZoomed(struct Sprite *sprite)
{
    sprite->x2 = -2 * sRegionMap->scrollX;
    sprite->y2 = -2 * sRegionMap->scrollY;
}

void CreateSFRegionMapCursor(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    u8 spriteIdLOC;
    struct SpriteTemplate template;
    struct SpritePalette palette;
    struct SpriteSheet sheet;

    palette = sRegionMapCursorSpritePalette;
    template = sRegionMapCursorSpriteTemplate;
    sheet.tag = tileTag;
    template.tileTag = tileTag;
    sRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    sRegionMap->cursorPaletteTag = paletteTag;
    sheet.data = sRegionMap->cursorSmallImage;
    sheet.size = sizeof(sRegionMap->cursorSmallImage);
    template.callback = SpriteCB_CursorMapFull;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSpriteAtEnd(&template, 0x38, 0x48, 0);

    tileTag = TAG_CURSOR_LOC;
    paletteTag = TAG_CURSOR_LOC;
    palette = sRegionMapL2CursorSpritePalette;
    template = sRegionMapL2CursorSpriteTemplate;
    sheet.tag = tileTag;
    template.tileTag = tileTag;
    sRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    sRegionMap->cursorPaletteTag = paletteTag;
    sheet.data = sRegionMap->cursorLargeImage;
    sheet.size = sizeof(sRegionMap->cursorLargeImage);
    template.callback = SpriteCB_CursorMapFullLOC;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteIdLOC = CreateSprite(&template, 0x38, 0x48, 0);


    if ((spriteId != MAX_SPRITES) && (spriteIdLOC != MAX_SPRITES))
    {
        sRegionMap->cursorSprite = &gSprites[spriteId];
        sRegionMap->cursorSpriteLOC = &gSprites[spriteIdLOC];

        sRegionMap->cursorSpriteLOC->oam.size = SPRITE_SIZE(64x64);
        sRegionMap->cursorSpriteLOC->x = 8 * sRegionMap->cursorPosX + 4;
        sRegionMap->cursorSpriteLOC->y = 8 * sRegionMap->cursorPosY + 4;

        sRegionMap->cursorSprite->oam.size = SPRITE_SIZE(16x16);
        sRegionMap->cursorSprite->x = 8 * sRegionMap->cursorPosX + 4;
        sRegionMap->cursorSprite->y = 8 * sRegionMap->cursorPosY + 4;
        //StartSpriteAnim(sRegionMap->cursorSprite, 0);

        if((sRegionMap->cursorPosY * 8 + 4) >= 80)
        {
            StartSpriteAnim(sRegionMap->cursorSpriteLOC, 1);
            sRegionMap->cursorSpriteLOC->y -= 10;
            sRegionMap->cursor_flipped = TRUE;
        }
        else
        {
            StartSpriteAnim(sRegionMap->cursorSpriteLOC, 0);
            sRegionMap->cursorSpriteLOC->y += 16;
            sRegionMap->cursor_flipped = FALSE;
        }

        if (sRegionMap->active_cursor == CURSOR_LOC)
        {
            sRegionMap->cursorSpriteLOC->invisible = FALSE;
            sRegionMap->cursorSprite->invisible = TRUE;
        }
        else
        {
            sRegionMap->cursorSpriteLOC->invisible = TRUE;
            sRegionMap->cursorSprite->invisible = FALSE;
        }

        sRegionMap->cursorSprite->data[1] = 2;
        sRegionMap->cursorSprite->data[2] = (IndexOfSpritePaletteTag(TAG_CURSOR) << 4) + 0x101;
        sRegionMap->cursorSprite->data[3] = TRUE;

        sRegionMap->cursorSpriteLOC->data[1] = 2;
        sRegionMap->cursorSpriteLOC->data[2] = (IndexOfSpritePaletteTag(TAG_CURSOR_LOC) << 4) + 0x101;
        sRegionMap->cursorSpriteLOC->data[3] = TRUE;

        PrintWarpPriceOnTooltip(spriteIdLOC, 2, 0xcc0);
        PrintWarpPriceOnTooltip(spriteIdLOC, 2, 0x4c0);
    }
    return;
}

static void FreeRegionMapCursorSprite(void)
{
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
    if (sRegionMap->cursorSpriteLOC != NULL)
    {
        DestroySprite(sRegionMap->cursorSpriteLOC);
        FreeSpriteTilesByTag(sRegionMap->cursorLOCTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorLOCPaletteTag);
    }
}

static bool8 RegionMap_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        LZ77UnCompVram(sRegionMapTiles, (u16 *)BG_CHAR_ADDR(2));
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        LZ77UnCompVram(sRegionMapTilemap, (u16 *)BG_SCREEN_ADDR(28));
        sMenuDataPtr->gfxLoadState++;
        LoadPalette(sRegionMapPalette, 0, 0x60);
        break;
    case 2:
        ResetTempTileDataBuffers();
        LZ77UnCompVram(sBarsTiles, (u16 *)BG_CHAR_ADDR(1));
        sMenuDataPtr->gfxLoadState++;
        break;
    case 3:
        LZ77UnCompVram(sBarsTilemap, (u16 *)BG_SCREEN_ADDR(30));
        sMenuDataPtr->gfxLoadState++;
        break;
    case 4:
        if (!FreeTempTileDataBuffersIfPossible()){
            LoadPalette(sBarsPalette, 0, 32);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 5:
        LZ77UnCompWram(sRegionMapCursorSmallGfxLZ, sRegionMap->cursorSmallImage);
        LZ77UnCompWram(sRegionMapCursorL2GfxLZ, sRegionMap->cursorLargeImage);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 6:
        sMenuDataPtr->gfxLoadState++;
        break;
    case 7:
        InitMapBasedOnPlayerLocation();
        sRegionMap->playerIconSpritePosX = sRegionMap->cursorPosX;
        sRegionMap->playerIconSpritePosY = sRegionMap->cursorPosY;
        //sRegionMap->mapSecId = CorrectSpecialMapSecId_Internal(sRegionMap->mapSecId);
        sRegionMap->mapSecType = GetMapsecType(sRegionMap->mapSecId);
        GetSFMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 8:
        if (sRegionMap->zoomed == FALSE)
        {
            CalcZoomScrollParams(0, 0, 0, 0, 0x100, 0x100, 0);
        }
        else
        {
            sRegionMap->scrollX = sRegionMap->cursorPosX * 8 - 0x34;
            sRegionMap->scrollY = sRegionMap->cursorPosY * 8 - 0x44;
            sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
            sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
            CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
        }
        sMenuDataPtr->gfxLoadState++;
        break;
    case 9:
        GetPositionOfCursorWithinMapSec();
        UpdateSFRegionMapVideoRegs();
        sRegionMap->cursorSprite = NULL;
        sRegionMap->cursorSpriteLOC = NULL;
        sRegionMap->playerIconSprite = NULL;
        sRegionMap->cursorMovementFrameCounter = 0;
        sRegionMap->blinkPlayerIcon = FALSE;
        SFCreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
        TrySetPlayerIconBlink();
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        SetBgAttribute(2, BG_ATTR_SCREENSIZE, 2);
        SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 2);
        SetBgAttribute(2, BG_ATTR_MAPBASEINDEX, 28);
        SetBgAttribute(2, BG_ATTR_WRAPAROUND, 1);
        SetBgAttribute(2, BG_ATTR_PALETTEMODE, 1);
        SetBgAttribute(1, BG_ATTR_PALETTEMODE, 0);
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_1, 0);
    FillWindowPixelBuffer(WINDOW_2, 0);

    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    //LoadUserWindowBorderGfx(WINDOW_2, 720, 14 * 16);

    PutWindowTilemap(WINDOW_1);
    PutWindowTilemap(WINDOW_2);

    CopyWindowToVram(WINDOW_1, 3);
    CopyWindowToVram(WINDOW_2, 3);
}

static const u8 sText_Money_Bar[]         = _("Money: ¥{STR_VAR_1}");
static const u8 sText_Money_BarSmall[]         = _("¥{STR_VAR_1}");
static const u8 sText_Money_BarSmall2[]         = _("¥{CLEAR 1}{STR_VAR_1}");
static const u8 sText_A_Button_BarDef[]         = _("Go");
static const u8 sText_B_Button_BarDef[]         = _("Cancel");
static const u8 sText_Select_Button_BarDef[]         = _("Marker");
static const u8 sText_Start_Button_BarDef[]         = _("Landmarks");
static const u8 sText_NotEnoughMoney[]         = _("Not Enough ¥");
static const u8 sText_WarpConfirm[]         = _("Do you want to go to ");
static const u8 sText_QuestionMark[]         = _("?");
static const u8 sText_MoneySign[]         = _("¥");

static void PrintDefaultHeaderTitleToWindow(u8 windowId, u8 colorIdx)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, sText_Money_Bar);

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(windowId, 7, (20*8)+4, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    AddTextPrinterParameterized4(windowId, 7, 4, 0, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sRegionMap->mapSecName);

    AddTextPrinterParameterized4(WINDOW_2, 7, 16, 1, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_A_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (5*8)+4, 1, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_B_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (13*8) - 7, 1, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Select_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (21 * 8) - 7, 1, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Start_Button_BarDef);

    //LoadPalette(sButtonsPalette, (32*15), 32);

    BlitBitmapToWindow(WINDOW_2, sA_ButtonGfx, 0, (1), 16, 16);
    BlitBitmapToWindow(WINDOW_2, sB_ButtonGfx, (4*8)-4, (1), 16, 16);
    BlitBitmapToWindow(WINDOW_2, sSelect_ButtonGfx, (9*8) - 3, (1), 32, 16);
    BlitBitmapToWindow(WINDOW_2, sStart_ButtonGfx, (16*8), (1), 32, 16);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
    PutWindowTilemap(WINDOW_2);
    CopyWindowToVram(WINDOW_2, 3);
    return;
}

static void PrintHeaderWarpConfirmToWindow(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, sText_Money_BarSmall);

    StringCopy(gStringVar1, sText_WarpConfirm);
    StringAppend(gStringVar1, gRegionMapEntries[sRegionMap->mapSecId].name);
    StringAppend(gStringVar1, sText_QuestionMark);

    FillWindowPixelBuffer(WINDOW_1, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(WINDOW_1, 7, 4, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    AddTextPrinterParameterized4(WINDOW_1, 7, (24*8)+3, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

    AddTextPrinterParameterized4(WINDOW_2, 7, 16, 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_A_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (5*8)+4, 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_B_Button_BarDef);


    BlitBitmapToWindow(WINDOW_2, sA_ButtonGfx, 0, (1), 16, 16);
    BlitBitmapToWindow(WINDOW_2, sB_ButtonGfx, (4*8)-4, (1), 16, 16);

    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    PutWindowTilemap(WINDOW_2);
    CopyWindowToVram(WINDOW_2, 3);
}

static void PrintL2HeaderTitleToWindow(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, sText_Money_Bar);

    FillWindowPixelBuffer(WINDOW_1, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(WINDOW_1, 7, (20*8)+4, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    AddTextPrinterParameterized4(WINDOW_1, 7, 4, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sRegionMap->mapSecName);

    AddTextPrinterParameterized4(WINDOW_2, 7, 16, 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_A_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (5*8)+4, 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_B_Button_BarDef);
    AddTextPrinterParameterized4(WINDOW_2, 7, (13*8) - 7, 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Select_Button_BarDef);

    BlitBitmapToWindow(WINDOW_2, sA_ButtonGfx, 0, (1), 16, 16);
    BlitBitmapToWindow(WINDOW_2, sB_ButtonGfx, (4*8)-4, (1), 16, 16);
    BlitBitmapToWindow(WINDOW_2, sSelect_ButtonGfx, (9*8) - 3, (1), 32, 16);

    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    PutWindowTilemap(WINDOW_2);
    CopyWindowToVram(WINDOW_2, 3);
}

static u8 *AddTextPrinterAndCreateWindowOnTooltip(const u8 *str, u32 x, u32 y, u32 bgColor, u32 *windowId)
{
    u16 winId;
    u8 color[3];
    struct WindowTemplate winTemplate = sTooltipWindowTemplate;

    winId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(winId, PIXEL_FILL(bgColor));

    color[0] = bgColor;
    color[1] = 1;
    color[2] = 5;

    AddTextPrinterParameterized4(winId, FONT_SMALL_NARROW, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);

    *windowId = winId;
    return (u8 *)(GetWindowAttribute(winId, WINDOW_TILE_DATA));
}

static void WarpPriceTextIntoTooltipObject(void *dest, u8 *windowTileData, u32 windowWidth)
{
    CpuCopy32(windowTileData + 256, dest, windowWidth * TILE_SIZE_4BPP);
}

static void PrintWarpPriceOnTooltip(u32 spriteId, u32 bgColor, u32 startTile) // 0xbc0 for one part of the tooltip
{
    u8 *windowTileData;
    u32 windowId, tilesCount, x, healthboxTileNum;
    u8 text[28], *txtPtr;

    void *objVram = (void *)(OBJ_VRAM0);
    //txtPtr = text;
    //*txtPtr++ = CHAR_CURRENCY;
    //txtPtr = ConvertIntToDecimalStringN(txtPtr, GetWarpPriceAtMapSec(sRegionMap->mapSecId, WARP_UBER), STR_CONV_MODE_LEFT_ALIGN, 4);

    ConvertIntToDecimalStringN(gStringVar1, GetWarpPriceAtMapSec(sRegionMap->mapSecId, WARP_UBER), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, sText_Money_BarSmall2);

    windowTileData = AddTextPrinterAndCreateWindowOnTooltip(gStringVar4, 2, 5, bgColor, &windowId);
    WarpPriceTextIntoTooltipObject(objVram + startTile, windowTileData, 4);
    RemoveWindow(windowId);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void UpdateRegionMapCursor(void)
{
    if ((sRegionMap->mapSecType != MAPSECTYPE_NONE))
    {
        if(sRegionMap->active_cursor == CURSOR_NO_LOC)
        {
            sRegionMap->active_cursor = CURSOR_LOC;
            sRegionMap->cursorSprite->invisible = TRUE;
            sRegionMap->cursorSpriteLOC->invisible = FALSE;

        }
        if((sRegionMap->cursorPosY * 8 + 4) >= 80 && sRegionMap->cursor_flipped == FALSE)
        {
            StartSpriteAnim(sRegionMap->cursorSpriteLOC, 1);
            sRegionMap->cursorSpriteLOC->y -= 26;
            sRegionMap->cursor_flipped = TRUE;
        }
        else if((sRegionMap->cursorPosY * 8 + 4) < 80 && sRegionMap->cursor_flipped == TRUE)
        {
            StartSpriteAnim(sRegionMap->cursorSpriteLOC, 0);
            sRegionMap->cursorSpriteLOC->y += 26;
            sRegionMap->cursor_flipped = FALSE;
        }
    }
    else
    {
        if(sRegionMap->active_cursor == CURSOR_LOC)
        {
            sRegionMap->active_cursor = CURSOR_NO_LOC;
            sRegionMap->cursorSprite->invisible = FALSE;
            sRegionMap->cursorSpriteLOC->invisible = TRUE;
        }

    }
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    switch (DoInputCallback())
        {
        case MAP_INPUT_NONE:
        case MAP_INPUT_MOVE_START:
        case MAP_INPUT_MOVE_CONT:
            break;
        case MAP_INPUT_MOVE_END:
            PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
            UpdateRegionMapCursor();
            break;
        case MAP_INPUT_START_BUTTON:
            if (!sRegionMap->zoomed)
            {
                PrintL2HeaderTitleToWindow();
                CreateTask(RegionMapZoomIn, 0xFF);
                sRegionMap->inputCallback = ProcessRegionMapInput_Zoomed;
            }
            else
            {
                PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
                CreateTask(RegionMapZoomOut, 0xFF);
                sRegionMap->inputCallback = ProcessRegionMapInput_Full;
            }
            break;
        case MAP_INPUT_A_BUTTON:
            sRegionMap->inputCallback = HandleAttemptWarpInput;
            break;
        case MAP_INPUT_B_BUTTON:
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_MenuTurnOff;
            break;
        }
}

u8 DoInputCallback(void)
{
    return sRegionMap->inputCallback();
}

static u8 ProcessRegionMapInput_Full(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->cursorDeltaX = 0;
    sRegionMap->cursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && sRegionMap->cursorPosY > MAPCURSOR_Y_MIN)
    {
        sRegionMap->cursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && sRegionMap->cursorPosY < MAPCURSOR_Y_MAX)
    {
        sRegionMap->cursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && sRegionMap->cursorPosX > MAPCURSOR_X_MIN)
    {
        sRegionMap->cursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && sRegionMap->cursorPosX < MAPCURSOR_X_MAX)
    {
        sRegionMap->cursorDeltaX = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sRegionMap->cursorMovementFrameCounter = 4;
        sRegionMap->inputCallback = MoveRegionMapCursor_Full;
        return input;
    }
    if (JOY_NEW(START_BUTTON))
    {
        input = MAP_INPUT_START_BUTTON;
    }
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }

    return input;
}

static u8 ProcessRegionMapInput_Zoomed(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->zoomedCursorDeltaX = 0;
    sRegionMap->zoomedCursorDeltaY = 0;
    if (JOY_NEW(START_BUTTON))
    {
        input = MAP_INPUT_START_BUTTON;
    }
    if(JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }
    return input;
}

static u8 HandleAttemptWarpInput(void)
{
    u16 mapSecId;
    mapSecId = GetMapSecIdAt(sRegionMap->cursorPosX, sRegionMap->cursorPosY);
    sRegionMap->mapSecType = GetMapsecType(mapSecId);

    if(sRegionMap->mapSecType == MAPSECTYPE_CITY_CANFLY)
    {
        if(GetWarpPriceAtMapSec(mapSecId, WARP_UBER) > GetMoney(&gSaveBlock1Ptr->money))
        {
            sRegionMap->inputCallback = HandleWarpFailedNoCash;
            sRegionMap->warp_counter = WARP_FAILED_PAUSE_START;
        }
        else
        {
            sRegionMap->warp_counter = 0;
            sRegionMap->inputCallback =  HandleWarpConfirmInput;
        }
    }
    else
    {
        sRegionMap->inputCallback = ProcessRegionMapInput_Full;
    }

    return MAP_INPUT_NONE;
}

static u8 HandleWarpConfirmInput(void)
{
    switch(sRegionMap->warp_counter)
    {
        case 0:
            PlaySE(SE_SELECT);
            PrintHeaderWarpConfirmToWindow();
            //sRegionMap->cursorSpriteLOC->invisible = TRUE;
            sRegionMap->warp_counter = 1;
            break;
        case 1: // Handle Input
            if (JOY_NEW(A_BUTTON))
            {
                sRegionMap->warp_counter = 0;
                PlaySE(SE_SELECT);
                RemoveMoney(&gSaveBlock1Ptr->money, GetWarpPriceAtMapSec(sRegionMap->mapSecId, WARP_UBER));
                sRegionMap->inputCallback = HandleWarpCloseMenu;
            }
            if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                sRegionMap->inputCallback = ProcessRegionMapInput_Full;
                GetSFMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
                PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
            }
            break;
    }
    return MAP_INPUT_NONE;
}

static u8 HandleWarpCloseMenu(void)
{
    switch(sRegionMap->warp_counter)
    {
        case 0:
            if (sMapHealLocations[sRegionMap->mapSecId][2] != HEAL_LOCATION_NONE)
                SetWarpDestinationToHealLocation(sMapHealLocations[sRegionMap->mapSecId][2]);
            else
                SetWarpDestinationToMapWarp(sMapHealLocations[sRegionMap->mapSecId][0], sMapHealLocations[sRegionMap->mapSecId][1], WARP_ID_NONE);
            sRegionMap->warp_counter = 1;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                Menu_FreeResources();
                ReturnToFieldFromRegionMapWarpSelect();
                sRegionMap->warp_counter = 2;
            }
            break;
    }
    return MAP_INPUT_NONE;
}

static u8 HandleWarpFailedNoCash(void)
{
    switch(sRegionMap->warp_counter)
    {
        case WARP_FAILED_PAUSE_START:
            PlaySE(SE_SELECT);
            StringCopy(sRegionMap->mapSecName, sText_NotEnoughMoney);
            PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
            sRegionMap->cursorSpriteLOC->invisible = TRUE;
            sRegionMap->warp_counter--;
            break;
        case WARP_FAILED_PAUSE_END:
            sRegionMap->cursorSpriteLOC->invisible = FALSE;
            sRegionMap->inputCallback = ProcessRegionMapInput_Full;
            GetSFMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
            PrintDefaultHeaderTitleToWindow(WINDOW_1, FONT_WHITE);
            break;
        default:
            sRegionMap->warp_counter--;
            break;
    }
    return MAP_INPUT_NONE;

}

u32 GetWarpPriceAtMapSec(u16 mapSecId, u8 warp_type)
{
    return 2000;
}

static u8 MoveRegionMapCursor_Full(void)
{
    u16 mapSecId;

    if (sRegionMap->cursorMovementFrameCounter != 0)
        return MAP_INPUT_MOVE_CONT;

    if (sRegionMap->cursorDeltaX > 0)
    {
        sRegionMap->cursorPosX++;
    }
    if (sRegionMap->cursorDeltaX < 0)
    {
        sRegionMap->cursorPosX--;
    }
    if (sRegionMap->cursorDeltaY > 0)
    {
        sRegionMap->cursorPosY++;
    }
    if (sRegionMap->cursorDeltaY < 0)
    {
        sRegionMap->cursorPosY--;
    }

    mapSecId = GetMapSecIdAt(sRegionMap->cursorPosX, sRegionMap->cursorPosY);
    sRegionMap->mapSecType = GetMapsecType(mapSecId);
    if (mapSecId != sRegionMap->mapSecId)
    {
        sRegionMap->mapSecId = mapSecId;
        GetSFMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
    }

    GetPositionOfCursorWithinMapSec();

    sRegionMap->inputCallback = ProcessRegionMapInput_Full;
    return MAP_INPUT_MOVE_END;
}

static u16 GetMapSecIdAt(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;
    return sRegionMap_MapSectionLayout[y][x]; // Where the hardcoded map positions need to be changed to label the areas properly
}

static u8 GetMapsecType(u16 mapSecId) // Hardcoded Fly Flag locations
{
    switch (mapSecId)
    {
    case MAPSEC_NONE:
        return MAPSECTYPE_NONE;
    case MAPSEC_SOUTHBAY:
        return MAPSECTYPE_CITY_CANFLY; //FlagGet(FLAG_VISITED_LITTLEROOT_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_OLDALE_TOWN:
        return FlagGet(FLAG_VISITED_OLDALE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_DEWFORD_TOWN:
        return FlagGet(FLAG_VISITED_DEWFORD_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_LAVARIDGE_TOWN:
        return FlagGet(FLAG_VISITED_LAVARIDGE_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FALLARBOR_TOWN:
        return FlagGet(FLAG_VISITED_FALLARBOR_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_VERDANTURF_TOWN:
        return FlagGet(FLAG_VISITED_VERDANTURF_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_PACIFIDLOG_TOWN:
        return FlagGet(FLAG_VISITED_PACIFIDLOG_TOWN) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_PETALBURG_CITY:
        return FlagGet(FLAG_VISITED_PETALBURG_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SLATEPORT_CITY:
        return FlagGet(FLAG_VISITED_SLATEPORT_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_MAUVILLE_CITY:
        return FlagGet(FLAG_VISITED_MAUVILLE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_RUSTBORO_CITY:
        return FlagGet(FLAG_VISITED_RUSTBORO_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_FORTREE_CITY:
        return FlagGet(FLAG_VISITED_FORTREE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_LILYCOVE_CITY:
        return FlagGet(FLAG_VISITED_LILYCOVE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_MOSSDEEP_CITY:
        return FlagGet(FLAG_VISITED_MOSSDEEP_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_SOOTOPOLIS_CITY:
        return FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_EVER_GRANDE_CITY:
        return FlagGet(FLAG_VISITED_EVER_GRANDE_CITY) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY;
    case MAPSEC_BATTLE_FRONTIER:
        return FlagGet(FLAG_LANDMARK_BATTLE_FRONTIER) ? MAPSECTYPE_BATTLE_FRONTIER : MAPSECTYPE_NONE;
    case MAPSEC_SOUTHERN_ISLAND:
        return FlagGet(FLAG_LANDMARK_SOUTHERN_ISLAND) ? MAPSECTYPE_ROUTE : MAPSECTYPE_NONE;
    default:
        return MAPSECTYPE_CITY_CANFLY; // Where Routes and anything else filters out right now, just set to always Flyable
    }
}

static u16 GetSFRegionMapSecIdAt(u16 x, u16 y)
{
    return GetMapSecIdAt(x, y);
}

static u8 *GetSFMapName(u8 *dest, u16 regionMapId, u16 padLength)
{
    u8 *str;
    u16 i;

    if (regionMapId == MAPSEC_SECRET_BASE)
    {
        str = GetSecretBaseMapName(dest);
    }
    else if (regionMapId < MAPSEC_NONE)
    {
        str = StringCopy(dest, gRegionMapEntries[regionMapId].name);
    }
    else
    {
        if (padLength == 0)
        {
            padLength = 18;
        }
        return StringFill(dest, CHAR_SPACE, padLength);
    }
    if (padLength != 0)
    {
        for (i = str - dest; i < padLength; i++)
        {
            *str++ = CHAR_SPACE;
        }
        *str = EOS;
    }
    return str;
}

static void InitMapBasedOnPlayerLocation(void)
{
    const struct MapHeader *mapHeader;
    u16 mapWidth;
    u16 mapHeight;
    u16 x;
    u16 y;
    u16 dimensionScale;
    u16 xOnMap;
    struct WarpData *warp;

    switch (GetMapTypeByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
    default:
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_UNDERWATER:
    case MAP_TYPE_OCEAN_ROUTE:
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        sRegionMap->playerIsInCave = FALSE;
        mapWidth = gMapHeader.mapLayout->width;
        mapHeight = gMapHeader.mapLayout->height;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        if (sRegionMap->mapSecId == MAPSEC_UNDERWATER_SEAFLOOR_CAVERN || sRegionMap->mapSecId == MAPSEC_UNDERWATER_MARINE_CAVE)
            sRegionMap->playerIsInCave = TRUE;
        break;
    case MAP_TYPE_UNDERGROUND:
    case MAP_TYPE_UNKNOWN:
        if (gMapHeader.allowEscaping)
        {
            mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = mapHeader->mapLayout->width;
            mapHeight = mapHeader->mapLayout->height;
            x = gSaveBlock1Ptr->escapeWarp.x;
            y = gSaveBlock1Ptr->escapeWarp.y;
        }
        else
        {
            sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = 1;
            mapHeight = 1;
            x = 1;
            y = 1;
        }
        break;
    case MAP_TYPE_SECRET_BASE:
        mapHeader = Overworld_GetMapHeaderByGroupAndId((u16)gSaveBlock1Ptr->dynamicWarp.mapGroup, (u16)gSaveBlock1Ptr->dynamicWarp.mapNum);
        sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        sRegionMap->playerIsInCave = TRUE;
        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->dynamicWarp.x;
        y = gSaveBlock1Ptr->dynamicWarp.y;
        break;
    case MAP_TYPE_INDOOR:
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        if (sRegionMap->mapSecId != MAPSEC_DYNAMIC)
        {
            warp = &gSaveBlock1Ptr->escapeWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
        }
        else
        {
            warp = &gSaveBlock1Ptr->dynamicWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        }

        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = warp->x;
        y = warp->y;
        break;
    }

    xOnMap = x;

    dimensionScale = mapWidth / gRegionMapEntries[sRegionMap->mapSecId].width;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    x /= dimensionScale;
    if (x >= gRegionMapEntries[sRegionMap->mapSecId].width)
    {
        x = gRegionMapEntries[sRegionMap->mapSecId].width - 1;
    }

    dimensionScale = mapHeight / gRegionMapEntries[sRegionMap->mapSecId].height;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    y /= dimensionScale;
    if (y >= gRegionMapEntries[sRegionMap->mapSecId].height)
    {
        y = gRegionMapEntries[sRegionMap->mapSecId].height - 1;
    }

    switch (sRegionMap->mapSecId)
    {
    default:
        break; // For Overrides Where the Position of the Player Should be offset to the normal location
    }
    sRegionMap->cursorPosX = gRegionMapEntries[sRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    sRegionMap->cursorPosY = gRegionMapEntries[sRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static void GetPositionOfCursorWithinMapSec(void)
{
    u16 x;
    u16 y;
    u16 posWithinMapSec;

    if (sRegionMap->mapSecId == MAPSEC_NONE)
    {
        sRegionMap->posWithinMapSec = 0;
        return;
    }
    if (!sRegionMap->zoomed)
    {
        x = sRegionMap->cursorPosX;
        y = sRegionMap->cursorPosY;
    }
    else
    {
        x = sRegionMap->zoomedCursorPosX;
        y = sRegionMap->zoomedCursorPosY;
    }
    posWithinMapSec = 0;
    while (1)
    {
        if (x <= MAPCURSOR_X_MIN)
        {
            if (RegionMap_IsMapSecIdInNextRow(y))
            {
                y--;
                x = MAPCURSOR_X_MAX + 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            x--;
            if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
            {
                posWithinMapSec++;
            }
        }
    }
    sRegionMap->posWithinMapSec = posWithinMapSec;
}

static bool8 RegionMap_IsMapSecIdInNextRow(u16 y)
{
    u16 x;

    if (y-- == 0)
    {
        return FALSE;
    }
    for (x = MAPCURSOR_X_MIN; x <= MAPCURSOR_X_MAX; x++)
    {
        if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
{
    s32 var1;
    s32 var2;
    s32 var3;
    s32 var4;

    sRegionMap->bg2pa = e * gSineTable[rotation + 64] >> 8;
    sRegionMap->bg2pc = e * -gSineTable[rotation] >> 8;
    sRegionMap->bg2pb = f * gSineTable[rotation] >> 8;
    sRegionMap->bg2pd = f * gSineTable[rotation + 64] >> 8;

    var1 = (scrollX << 8) + (c << 8);
    var2 = d * sRegionMap->bg2pb + sRegionMap->bg2pa * c;
    sRegionMap->bg2x = var1 - var2;

    var3 = (scrollY << 8) + (d << 8);
    var4 = sRegionMap->bg2pd * d + sRegionMap->bg2pc * c;
    sRegionMap->bg2y = var3 - var4;

    sRegionMap->needUpdateVideoRegs = TRUE;
}

static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y)
{
    sRegionMap->bg2x = (x << 8) + 0x1c00;
    sRegionMap->bg2y = (y << 8) + 0x2400;
    sRegionMap->needUpdateVideoRegs = TRUE;
}

static void UpdateSFRegionMapVideoRegs(void)
{
    if (sRegionMap->needUpdateVideoRegs)
    {
        SetGpuReg(REG_OFFSET_BG2PA, sRegionMap->bg2pa);
        SetGpuReg(REG_OFFSET_BG2PB, sRegionMap->bg2pb);
        SetGpuReg(REG_OFFSET_BG2PC, sRegionMap->bg2pc);
        SetGpuReg(REG_OFFSET_BG2PD, sRegionMap->bg2pd);
        SetGpuReg(REG_OFFSET_BG2X_L, sRegionMap->bg2x);
        SetGpuReg(REG_OFFSET_BG2X_H, sRegionMap->bg2x >> 16);
        SetGpuReg(REG_OFFSET_BG2Y_L, sRegionMap->bg2y);
        SetGpuReg(REG_OFFSET_BG2Y_H, sRegionMap->bg2y >> 16);
        sRegionMap->needUpdateVideoRegs = FALSE;
    }
}

static void RegionMapZoomIn(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PlaySE(SE_SELECT);
        gTasks[taskId].data[0]++;
        return;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return;
        gTasks[taskId].data[0]++;
        //ChangeBgYForZoom(TRUE);
        SetSFRegionMapDataForZoom();
        return;
    case 2:
        if (UpdateSFRegionMapZoom())// || IsChangeBgYForZoomActive())
            return;
        gTasks[taskId].data[0]++;
        return;
    case 3:
        if(IsDma3ManagerBusyWithBgCopy())
            return;
        gTasks[taskId].data[0]++;
        return;
    }

    DestroyTask(taskId);
    return;
}

static void RegionMapZoomOut(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PlaySE(SE_SELECT);
        //ChangeBgYForZoom(FALSE);
        SetSFRegionMapDataForZoom();
        gTasks[taskId].data[0]++;
        return;
    case 1:
        if (UpdateSFRegionMapZoom())// || IsChangeBgYForZoomActive())
            return;
        gTasks[taskId].data[0]++;
        return;
    case 2:
        if(IsDma3ManagerBusyWithBgCopy())
            return;
        gTasks[taskId].data[0]++;
        return;
    }

    DestroyTask(taskId);
    return;
}

#define tZoomIn data[0]

static void ChangeBgYForZoom(bool32 zoomIn)
{
    u8 taskId = CreateTask(Task_ChangeBgYForZoom, 3);
    gTasks[taskId].tZoomIn = zoomIn;
}

static bool32 IsChangeBgYForZoomActive(void)
{
    return FuncIsActiveTask(Task_ChangeBgYForZoom);
}

static void Task_ChangeBgYForZoom(u8 taskId)
{
    if (gTasks[taskId].tZoomIn)
    {
        if (ChangeBgY(2, 0x480, BG_COORD_ADD) >= 0)
        {
            ChangeBgY(2, 0, BG_COORD_SET);
            DestroyTask(taskId);
        }

        //UpdateCityZoomTextPosition();
    }
    else
    {
        if (ChangeBgY(2, 0x480, BG_COORD_SUB) <= -0x6000)
        {
            ChangeBgY(2, -0x6000, BG_COORD_SET);
            DestroyTask(taskId);
        }

        //UpdateCityZoomTextPosition();
    }
}

#undef tZoomIn

bool8 UpdateSFRegionMapZoom(void)
{
    bool8 retVal;

    if (sRegionMap->unk_06e >= 16)
    {
        return FALSE;
    }
    sRegionMap->unk_06e++;
    if (sRegionMap->unk_06e == 16)
    {
        sRegionMap->unk_044 = 0;
        sRegionMap->unk_048 = 0;
        sRegionMap->scrollX = sRegionMap->unk_060;
        sRegionMap->scrollY = sRegionMap->unk_062;
        sRegionMap->unk_04c = (sRegionMap->zoomed == FALSE) ? (128 << 8) : (256 << 8);
        sRegionMap->zoomed = !sRegionMap->zoomed;
        UnhideRegionMapPlayerIcon();
        UnhideRegionMapCursorIcon();
        retVal = FALSE;
    }
    else
    {
        sRegionMap->unk_03c += sRegionMap->unk_044;
        sRegionMap->unk_040 += sRegionMap->unk_048;
        sRegionMap->scrollX = sRegionMap->unk_03c >> 8;
        sRegionMap->scrollY = sRegionMap->unk_040 >> 8;
        sRegionMap->unk_04c += sRegionMap->unk_050;
        if ((sRegionMap->unk_044 < 0 && sRegionMap->scrollX < sRegionMap->unk_060) || (sRegionMap->unk_044 > 0 && sRegionMap->scrollX > sRegionMap->unk_060))
        {
            sRegionMap->scrollX = sRegionMap->unk_060;
            sRegionMap->unk_044 = 0;
        }
        if ((sRegionMap->unk_048 < 0 && sRegionMap->scrollY < sRegionMap->unk_062) || (sRegionMap->unk_048 > 0 && sRegionMap->scrollY > sRegionMap->unk_062))
        {
            sRegionMap->scrollY = sRegionMap->unk_062;
            sRegionMap->unk_048 = 0;
        }
        if (sRegionMap->zoomed == FALSE)
        {
            if (sRegionMap->unk_04c < (128 << 8))
            {
                sRegionMap->unk_04c = (128 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        else
        {
            if (sRegionMap->unk_04c > (256 << 8))
            {
                sRegionMap->unk_04c = (256 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        retVal = TRUE;
    }
    CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, sRegionMap->unk_04c >> 8, sRegionMap->unk_04c >> 8, 0);
    return retVal;
}


void SetSFRegionMapDataForZoom(void)
{
    if (sRegionMap->zoomed == FALSE)
    {
        sRegionMap->scrollY = 0;
        sRegionMap->scrollX = 0;
        sRegionMap->unk_040 = 0;
        sRegionMap->unk_03c = 0;
        sRegionMap->unk_060 = sRegionMap->cursorPosX * 8 - 0x34;
        sRegionMap->unk_062 = sRegionMap->cursorPosY * 8 - 0x44;
        sRegionMap->unk_044 = (sRegionMap->unk_060 << 8) / 16;
        sRegionMap->unk_048 = (sRegionMap->unk_062 << 8) / 16;
        sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
        sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
        sRegionMap->unk_04c = 0x10000;
        sRegionMap->unk_050 = -0x800;
    }
    else
    {
        sRegionMap->unk_03c = sRegionMap->scrollX * 0x100;
        sRegionMap->unk_040 = sRegionMap->scrollY * 0x100;
        sRegionMap->unk_060 = 0;
        sRegionMap->unk_062 = 0;
        sRegionMap->unk_044 = -(sRegionMap->unk_03c / 16);
        sRegionMap->unk_048 = -(sRegionMap->unk_040 / 16);
        sRegionMap->cursorPosX = sRegionMap->zoomedCursorPosX;
        sRegionMap->cursorPosY = sRegionMap->zoomedCursorPosY;
        sRegionMap->unk_04c = 0x8000;
        sRegionMap->unk_050 = 0x800;
    }
    sRegionMap->unk_06e = 0;
    //FreeRegionMapCursorSprite();
    HideRegionMapPlayerIcon();
    HideRegionMapCursorIcon();
}

static void SFCreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteSheet sheet = {sRegionMapPlayerIcon_BrendanGfx, 0x80, tileTag};
    struct SpritePalette palette = {sRegionMapPlayerIcon_BrendanPal, paletteTag};
    struct SpriteTemplate template = {tileTag, paletteTag, &sRegionMapPlayerIconOam, sRegionMapPlayerIconAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy};

    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0, 0, 1);
    sRegionMap->playerIconSprite = &gSprites[spriteId];
    if (!sRegionMap->zoomed)
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
    }
    else
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
    }
}

static void HideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        sRegionMap->playerIconSprite->invisible = TRUE;
        sRegionMap->playerIconSprite->callback = SpriteCallbackDummy;
    }
}

static void UnhideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
        else
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
            sRegionMap->playerIconSprite->x2 = 0;
            sRegionMap->playerIconSprite->y2 = 0;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
    }
}

static void HideRegionMapCursorIcon(void)
{
    if(sRegionMap->active_cursor == CURSOR_NO_LOC)
    {
        if (sRegionMap->cursorSprite != NULL)
        {
            sRegionMap->cursorSprite->invisible = TRUE;
            sRegionMap->cursorSprite->callback = SpriteCallbackDummy;
        }
    }
    if(sRegionMap->active_cursor == CURSOR_LOC)
    {
        if (sRegionMap->cursorSpriteLOC != NULL)
        {
            sRegionMap->cursorSpriteLOC->invisible = TRUE;
            sRegionMap->cursorSpriteLOC->callback = SpriteCallbackDummy;
        }
    }
}

static void UnhideRegionMapCursorIcon(void)
{

    if (sRegionMap->cursorSprite != NULL)
    {
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->cursorSprite->x = sRegionMap->cursorPosX * 16 - 0x30;
            sRegionMap->cursorSprite->y = sRegionMap->cursorPosY * 16 - 0x42;
            sRegionMap->cursorSprite->callback = SpriteCB_CursorMapZoomed;
            //sRegionMap->cursorSprite->invisible = FALSE;
        }
        else
        {
            sRegionMap->cursorSprite->x = sRegionMap->cursorPosX * 8 + 4;
            sRegionMap->cursorSprite->y = sRegionMap->cursorPosY * 8 + 4;
            sRegionMap->cursorSprite->x2 = 0;
            sRegionMap->cursorSprite->y2 = 0;
            sRegionMap->cursorSprite->callback = SpriteCB_CursorMapFull;
            //sRegionMap->cursorSprite->invisible = FALSE;
        }
    }
    if (sRegionMap->cursorSpriteLOC != NULL)
    {
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->cursorSpriteLOC->x = sRegionMap->cursorPosX * 16 - 0x30;
            sRegionMap->cursorSpriteLOC->y = sRegionMap->cursorPosY * 16 - 0x42;
            if((sRegionMap->cursorPosY * 8 + 4) >= 80)
                sRegionMap->cursorSpriteLOC->y -= 10;
            else
                sRegionMap->cursorSpriteLOC->y += 16;
            sRegionMap->cursorSpriteLOC->callback = SpriteCB_CursorMapZoomed;
            //sRegionMap->cursorSpriteLOC->invisible = FALSE;
        }
        else
        {
            sRegionMap->cursorSpriteLOC->x = sRegionMap->cursorPosX * 8 + 4;
            sRegionMap->cursorSpriteLOC->y = sRegionMap->cursorPosY * 8 + 4;
            sRegionMap->cursorSpriteLOC->x2 = 0;
            sRegionMap->cursorSpriteLOC->y2 = 0;
            sRegionMap->cursorSpriteLOC->callback = SpriteCB_CursorMapFullLOC;
            if((sRegionMap->cursorPosY * 8 + 4) >= 80)
                sRegionMap->cursorSpriteLOC->y -= 10;
            else
                sRegionMap->cursorSpriteLOC->y += 16;
            //sRegionMap->cursorSpriteLOC->invisible = FALSE;
        }
    }

    if(sRegionMap->active_cursor == CURSOR_LOC)
        sRegionMap->cursorSpriteLOC->invisible = FALSE;
    else
        sRegionMap->cursorSprite->invisible = FALSE;
}

#define sY       data[0]
#define sX       data[1]
#define sVisible data[2]
#define sTimer   data[7]

static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite)
{
    sprite->x2 = -2 * sRegionMap->scrollX;
    sprite->y2 = -2 * sRegionMap->scrollY;
    sprite->sY = sprite->y + sprite->y2 + sprite->centerToCornerVecY;
    sprite->sX = sprite->x + sprite->x2 + sprite->centerToCornerVecX;
    if (sprite->sY < -8 || sprite->sY > DISPLAY_HEIGHT + 8 || sprite->sX < -8 || sprite->sX > DISPLAY_WIDTH + 8)
        sprite->sVisible = FALSE;
    else
        sprite->sVisible = TRUE;

    if (sprite->sVisible == TRUE)
        SpriteCB_PlayerIcon(sprite);
    else
        sprite->invisible = TRUE;
}

static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite)
{
    SpriteCB_PlayerIcon(sprite);
}

static void SpriteCB_PlayerIcon(struct Sprite *sprite)
{
    if (sRegionMap->blinkPlayerIcon)
    {
        if (++sprite->sTimer > 16)
        {
            sprite->sTimer = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

static void SFTrySetPlayerIconBlink(void)
{
    if (sRegionMap->playerIsInCave)
        sRegionMap->blinkPlayerIcon = TRUE;
}

#undef sY
#undef sX
#undef sVisible
#undef sTimer
