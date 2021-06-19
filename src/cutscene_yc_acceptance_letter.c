#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "list_menu.h"
#include "mystery_event_menu.h"
#include "naming_screen.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"
#include "mystery_gift.h"

//https://github.com/pret/pokeemerald/wiki/printf-in-mGBA
#include "printf.h"
#include "mgba.h"
#include "../gflib/string_util.h" // for ConvertToAscii()


/*

\\wsl$\Ubuntu-20.04\home\psf\Decomps\quest-menu\src\quests.c


FUNCTION LIST

Visual Init of screen
Text init of screen
Activate scroller (pokedex?)
Show up and down arrows
Fade in
ShowAButtonWhenFinished

black text on white bg, no styling

print text

scroll up or down with direction pad
can we reuse the "go outside arrow" but point it downward?
text should cut off on bottom to show scroll

"press A to continue" should appear in bottom right. or maybe an "A" button press?

https://discordapp.com/channels/442462691542695948/533083367818657792/846780935864582175
*/

static void AcceptanceLetter_VisualInit(void);
static void AcceptanceLetter_TextInit(void);
static void AcceptanceLetter_AllowScroll(void);
static void AcceptanceLetter_CreateArrow(void);
static void AcceptanceLetter_CreateLetter(void);
static void AcceptanceLetter_PushAToContinue(void);

static const struct BgTemplate sQuestMenuBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, 
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 1
    }
};

static const struct WindowTemplate sLetterWindowSections[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x07,
        .tilemapTop = 0x01,
        .width = 0x13,
        .height = 0x0c,
        .paletteNum = 0x0f,
        .baseBlock = 0x02bf
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x05,
        .tilemapTop = 0x0e,
        .width = 0x19,
        .height = 0x06,
        .paletteNum = 0x0d,
        .baseBlock = 0x0229
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x01,
        .width = 0x05,
        .height = 0x04,
        .paletteNum = 15,
        .baseBlock = 0x0215
    },
    DUMMY_WIN_TEMPLATE
};

static void AcceptanceLetter_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void AcceptanceLetter_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 AcceptanceLetter_VisualInit(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetItemMenuIconState();
        gMain.state++;
        break;
    case 6:
        ResetTasks();
        gMain.state++;
        break;
    case 7:
        if (QuestMenu_InitBgs())
        {
            sStateDataPtr->data[0] = 0;
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 8:
        if (QuestMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 9:
        QuestMenu_InitWindows();
        gMain.state++;
        break;
    case 10:
        QuestMenu_InitItems();
        QuestMenu_SetCursorPosition();
        QuestMenu_SetScrollPosition();
        gMain.state++;
        break;
    case 11:
        if (QuestMenu_AllocateResourcesForListMenu())
        {
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 12:
        QuestMenu_BuildListMenuTemplate();
        gMain.state++;
        break;
    case 13:
        QuestMenu_PrintHeader();
        gMain.state++;
        break;
    case 14:
        //sub_80985E4();
        gMain.state++;
        break;
    case 15:
        taskId = CreateTask(Task_QuestMenuMain, 0);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll, sListMenuState.row);
        gMain.state++;
        break;
    case 16:
        QuestMenu_PlaceTopMenuScrollIndicatorArrows();
        gMain.state++;
        break;
    case 17:
        //HelpSystem_SetSomeVariable2(29);
        gMain.state++;
        break;
    case 18:
        if (sListMenuState.initialized == 1)
        {
            BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        }
        gMain.state++;
        break;
    case 19:
        if (sListMenuState.initialized == 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        }
        else
        {
            BeginPCScreenEffect_TurnOn(0, 0, 0);
            QuestMenu_SetInitializedFlag(1);
            PlaySE(SE_PC_LOGIN);
        }
        gMain.state++;
        break;
    case 20:
        gMain.state++;
        break;
    default:
        SetVBlankCallback(QuestMenu_VBlankCB);
        SetMainCallback2(QuestMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

static void AcceptanceLetter_TextInit(void)
{

}
static void AcceptanceLetter_AllowScroll(void)
{

}
static void AcceptanceLetter_CreateArrow(void)
{

}
static void AcceptanceLetter_CreateLetter(void)
{

}
static void AcceptanceLetter_PushAToContinue(void)
{

}