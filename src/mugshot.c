#include "global.h"
#include "international_string_util.h"
#include "blit.h"
#include "bg.h"
#include "decompress.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

//void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
//void ClearMugshot(void);

static const u16 sMugshotPal_Hilda[] = INCBIN_U16("graphics/mugshots/hilda.gbapal");
static const u32 sMugshotImg_Hilda[] = INCBIN_U32("graphics/mugshots/hilda.4bpp.lz");

static const u16 sMugshotPal_Marshal[] = INCBIN_U16("graphics/mugshots/marshal.gbapal");
static const u32 sMugshotImg_Marshal[] = INCBIN_U32("graphics/mugshots/marshal.4bpp.lz");

static const u16 sMugshotPal_Sabrina[] = INCBIN_U16("graphics/mugshots/sabrina.gbapal");
static const u32 sMugshotImg_Sabrina[] = INCBIN_U32("graphics/mugshots/sabrina.4bpp.lz");

static const struct Mugshot sMugshots[] = {
    [MUGSHOT_SABRINA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Sabrina, .palette = sMugshotPal_Sabrina},
    [MUGSHOT_HILDA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Hilda, .palette = sMugshotPal_Hilda},
    [MUGSHOT_MARSHAL] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Marshal, .palette = sMugshotPal_Marshal},
};

//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;
static EWRAM_DATA u8 sPortaitSpriteID = 0;
static EWRAM_DATA u8 sPortaitPaletteID = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}

//Name Msgbox Bottom - 240 x 8
#define MESSAGE_BOX_WIDTH  240
#define MESSAGE_BOX_HEIGHT 8
#define MESSAGE_BOX_X      0
#define MESSAGE_BOX_Y      24

static const u8 sMsgbox_Top_Small[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/msgbox_top_small.4bpp");
static const u16 gMessageBox_Pal[] = INCBIN_U16("graphics/ui_menus/msgbox/message_box.gbapal");

//Phone - 16 x 16
#define PHONE_WIDTH  16
#define PHONE_HEIGHT 16
#define PHONE_X      65
#define PHONE_Y      11

static const u8 sMsgbox_Phone_On[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/phone_on.4bpp");

//Name Box - 56 x 16
#define NAME_BOX_WIDTH  8
#define NAME_BOX_HEIGHT 16
#define NAME_BOX_X      8
#define NAME_BOX_Y      10

static const u8 sMsgbox_Name_Box[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/name_box.4bpp");

//Name Box Bottom - 8 x 16
#define NAME_BOX_BOTTOM_WIDTH  8
#define NAME_BOX_BOTTOM_HEIGHT 16
#define NAME_BOX_BOTTOM_X      0
#define NAME_BOX_BOTTOM_Y      10

static const u8 sMsgbox_Name_Box_Bottom[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/name_box_bottom.4bpp");

//Emotes - 48 x 32
#define EMOTES_WIDTH  48
#define EMOTES_HEIGHT 32
#define EMOTES_X      63
#define EMOTES_Y      2

static const u8 sMsgbox_Emote_Angry[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_angry.4bpp");
static const u8 sMsgbox_Emote_Confuse[] = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_confuse.4bpp");
static const u8 sMsgbox_Emote_Default[] = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_default.4bpp");
static const u8 sMsgbox_Emote_Happy[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_happy.4bpp");
static const u8 sMsgbox_Emote_Laugh[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_laugh.4bpp");
static const u8 sMsgbox_Emote_Love[]    = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_love.4bpp");
static const u8 sMsgbox_Emote_Sad[]     = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_sad.4bpp");
static const u8 sMsgbox_Emote_Shock[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_shock.4bpp");
static const u8 sMsgbox_Emote_Sweat[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_sweat.4bpp");

//Tails - 48 x 24
#define TAILS_WIDTH  48
#define TAILS_HEIGHT 24
#define TAILS_X      97
#define TAILS_Y      7

static const u8 sMsgbox_Tail_Shout[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_shout.4bpp");
static const u8 sMsgbox_Tail_Talk[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_talk.4bpp");
static const u8 sMsgbox_Tail_Thought[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_thought.4bpp");
static const u8 sMsgbox_Tail_Whisper[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_whisper.4bpp");

#define SPEAKER_NAME_LENGTH     20
#define SPEAKER_NAME_X          8
#define SPEAKER_NAME_Y          10
#define SPEAKER_FONT            7
#define SPEAKER_NAME_FONT_COLOR 10
#define SPEAKER_NAME_WIDTH      70
#define MAX_SPEAKER_NAME_WIDTH  79

struct SpeakerData
{
    const u8 name[SPEAKER_NAME_LENGTH];
    const u32 *speakerIcon;
    const u32 *speakerPal;
};

#include "data/speaker_data.h"

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
};

static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]    = {TEXT_COLOR_TRANSPARENT,  13,   11},
    [FONT_WHITE]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,       TEXT_COLOR_TRANSPARENT},
};

//Faces
#define GFXTAG_SPEAKER_ICON 0x2722 //same as money label
#define SPEAKER_ICON_PAL 15
#define SPEAKER_ICON_PAL_NUM 5
#define SPEAKER_ICON_X 77
#define SPEAKER_ICON_Y 78
#define SPEAKER_ICON_SUBPRIORITY 0
#define SPEAKER_ICON_PRIORITY 0

void DestroySpeakerIconSprite(void){
    if(sPortaitSpriteID != 0){
        FreeSpriteTilesByTag(GFXTAG_SPEAKER_ICON);
        FreeSpritePaletteByTag(sPortaitPaletteID);
        DestroySpriteAndFreeResources(&gSprites[sPortaitSpriteID]);
        sPortaitSpriteID = 0;
        VarSet(sPortaitPaletteID, 0);
    }
}

static void CreateSpeakerIconSprite(u16 speaker, u16 offset)
{
    u8 palnum, paltag;
    u8 spriteId = MAX_SPRITES;
    u16 SpriteTag = GFXTAG_SPEAKER_ICON;
    struct CompressedSpriteSheet sSpriteSheet_Speaker_Icon;
    struct CompressedSpritePalette spritePalette;
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;
    DestroySpeakerIconSprite();

    TempSpriteTemplate.tileTag = SpriteTag;
    //FreeSpritePaletteByTag(PaletteTag);
    palnum = AllocSpritePalette(SPEAKER_ICON_PAL_NUM);
    paltag = GetSpritePaletteTagByPaletteNum(palnum);
    sPortaitPaletteID = paltag;
    FreeSpritePaletteByTag(paltag);
    
    sSpriteSheet_Speaker_Icon.data = sSpeakerData[speaker].speakerIcon;
    sSpriteSheet_Speaker_Icon.size = 0x0800;
    sSpriteSheet_Speaker_Icon.tag = SpriteTag;
    LoadCompressedSpriteSheet(&sSpriteSheet_Speaker_Icon);

    spritePalette.data = sSpeakerData[speaker].speakerPal;
    spritePalette.tag = paltag;
    LoadCompressedSpritePalette(&spritePalette);

    spriteId = CreateSprite(&TempSpriteTemplate, 0, 0, 0);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x32);
        gSprites[spriteId].oam.size = SPRITE_SIZE(32x32);

        gSprites[spriteId].x = SPEAKER_ICON_X - offset;
        gSprites[spriteId].y = SPEAKER_ICON_Y;
        gSprites[spriteId].oam.priority = 4;
        gSprites[spriteId].oam.paletteNum = palnum;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
    }

    sPortaitSpriteID = spriteId;
    VarSet(VAR_MSGBOX_SPEAKER, SPEAKER_DEFAULT);
}

//TODO Write a constant coordinates for mugshots for protag (left) and other people (right)

#define WINDOW_SIZE 30 - 2
#define WINDOW_TITLEOFFSET 90
#define WINDOW_X 110
#define WINDOW_Y 109
#define NEW_WINDOW_WIDTH 240
#define NEW_WINDOW_HEIGHT 32
#define WINDOW_TILETOP 74 - 1
#define WINDOW_TILELEFT 0

static const u32 sMsgbox_Top_0[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_0.4bpp.lz");
static const u32 sMsgbox_Top_1[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_1.4bpp.lz");
static const u32 sMsgbox_Top_2[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_2.4bpp.lz");

void ClearMessageBoxAddOns(void){
    DestroySpeakerIconSprite();
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

void ForceClearMessageBoxData(void){
    sPortaitSpriteID = 0;
    sPortaitPaletteID = 0;
    sMugshotWindow = 0;
    VarSet(VAR_MSGBOX_PHONE, PHONE_OFF);
    VarSet(VAR_MSGBOX_EMOTE, EMOTE_DEFAULT);
    VarSet(VAR_MSGBOX_TAIL, TAIL_DEFAULT);
}

void DrawMessageBoxAddOns(u8 windowId){
    const u16* palette = gMessageBox_Pal;
    struct WindowTemplate t;
    int offset, offset2;
    u8 speaker = VarGet(VAR_MSGBOX_SPEAKER);
    const u8 *str = sSpeakerData[speaker].name;
    u8 emote = VarGet(VAR_MSGBOX_EMOTE);
    u8 tail = VarGet(VAR_MSGBOX_TAIL);
    u8 onPhone = VarGet(VAR_MSGBOX_PHONE);
    u8 i, x, y;
    
    if(sMugshotWindow != 0){
        ClearMessageBoxAddOns();
    }
    
    SetWindowTemplateFields(&t, 0, WINDOW_TILELEFT, WINDOW_TILETOP, NEW_WINDOW_WIDTH/8, NEW_WINDOW_HEIGHT/8, MUGSHOT_PALETTE_NUM, 0x40);
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
        
    LoadPalette(palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    //Top Left Part
    CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_0, 0, WINDOW_TITLEOFFSET);
    //Top Part
    for(i = 0; i < WINDOW_SIZE; i++)
        CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_1, 0, WINDOW_TITLEOFFSET + 1 + i);
    //Top Right Part
    CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_2, 0, WINDOW_TITLEOFFSET + 1 + WINDOW_SIZE);

    if(speaker != SPEAKER_DEFAULT && speaker < NUM_SPEAKERS){
        //Name Width
        if(onPhone)
            offset = GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH) - 8 - PHONE_WIDTH;
        else
            offset = GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH) - 16;
        offset2 = MAX_SPEAKER_NAME_WIDTH - GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH);
        if(EMOTES_X < offset)
            offset = EMOTES_X;
        //Name Box
        x = 0;
        y = 0;
        for(i = 0; i <= offset2/8; i++){
            BlitBitmapToWindow(windowId, sMsgbox_Name_Box, NAME_BOX_X + x, NAME_BOX_Y, NAME_BOX_WIDTH, NAME_BOX_HEIGHT);
            x = x + 8;
        }
        BlitBitmapToWindow(windowId, sMsgbox_Name_Box_Bottom, NAME_BOX_BOTTOM_X, NAME_BOX_BOTTOM_Y, NAME_BOX_BOTTOM_WIDTH, NAME_BOX_BOTTOM_HEIGHT);

        //Emotes
        switch(emote){
            case EMOTE_ANGRY:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Angry, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_CONFUSE:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Confuse, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_HAPPY:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Happy, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_LAUGH:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Laugh, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_LOVE:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Love, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SAD:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Sad, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SWEAT:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Sweat, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SHOCK:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Shock, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            default:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Default, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
        }

        //Tails
        switch(tail){
            case TAIL_TALK:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Talk, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_WHISPER:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Whisper, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_SHOUT:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Shout, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_THOUGHT:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Thought, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            default:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Talk, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
        }

        
        //Phone
        if(onPhone)
            BlitBitmapToWindow(windowId, sMsgbox_Phone_On, PHONE_X - offset, PHONE_Y, PHONE_WIDTH, PHONE_HEIGHT);

        //Speaker Icon
        CreateSpeakerIconSprite(speaker, offset);

        //Speaker Name
        //offset = GetStringCenterAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH);
        AddTextPrinterParameterized4(windowId, SPEAKER_FONT, SPEAKER_NAME_X, SPEAKER_NAME_Y, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, str);
    }

    PutWindowRectTilemap(windowId, 0, 0, NEW_WINDOW_WIDTH/8, NEW_WINDOW_HEIGHT/8);
    CopyWindowToVram(windowId, 3);
    //Cleans Vars before calling this again
    VarSet(VAR_MSGBOX_PHONE, PHONE_OFF);
    VarSet(VAR_MSGBOX_EMOTE, EMOTE_DEFAULT);
    VarSet(VAR_MSGBOX_TAIL, TAIL_DEFAULT);
}

