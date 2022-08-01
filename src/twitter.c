#include "global.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "constants/songs.h"
#include "quest_strings.h"

#define TWITTER_MAIN_MENU_HEIGHT 7
#define TWITTER_MAIN_MENU_WIDTH 11



static void Twitter_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
void Twitter_ShowMainMenu(void);
void Twitter_ShowQuestMenu(void);
static void Twitter_DestroyMenu(u8);
static void TwitterAction_Cancel(u8);
static void TwitterTask_HandleMainMenuInput(u8);
static void TwitterTask_HandleMenuInput_Quests(u8);

static void TwitterMenu_Actions_Quests_RabiesOutbreak_Script(u8);
static void TwitterMenu_Actions_Quests_BlueRobbery_Script(u8);
static void TwitterMenu_Actions_Quests_IceCreamCrafting_Script(u8);
static void TwitterMenu_Actions_Quests_VSDeoxys_Script(u8);
static void TwitterMenu_Actions_Quests_ChinatownTunnels_Script(u8);
static void TwitterMenu_Actions_Quests_FreshwaterEvolution_Script(u8);
static void TwitterMenu_Actions_Quests_GemArtist_Script(u8);
static void TwitterMenu_Actions_Quests_BetweenAStoneAndAHardPlace_Script(u8);

enum {
    TWITTER_MENU_ITEM_CANCEL,
    TWITTER_MENU_ITEM_QUESTS,
};

enum {
    TWITTER_RABIESOUTBREAK,
    TWITTER_BLUEROBBERRY,
    TWITTER_ICECREAMCRAFTING,
    TWITTER_VSDEOXYS,
    TWITTER_CHINATOWNTUNNELS,
    TWITTER_FRESHWATEREVOLUTION,
    TWITTER_GEMARTIST,
    TWITTER_BETWEENASTONEANDAHARD,
};

static const u8 gTwitterText_Cancel[] = _("Cancel");
static const u8 gTwitterText_Quests[] = _("Quests");

static const struct ListMenuItem sTwitterMenuItems[] =
{
    [TWITTER_MENU_ITEM_CANCEL] = {gTwitterText_Quests, TWITTER_MENU_ITEM_CANCEL},
    [TWITTER_MENU_ITEM_QUESTS] = {gTwitterText_Cancel, TWITTER_MENU_ITEM_QUESTS}
};

static void (*const sTwitterMenuActions[])(u8) =
{
    [TWITTER_MENU_ITEM_QUESTS] = TwitterAction_OpenQuestsList,
    [TWITTER_MENU_ITEM_CANCEL] = TwitterAction_Cancel
};

static const struct ListMenuItem sTwitterMenuQuests[] =
{
    [TWITTER_RABIESOUTBREAK] = {gText_Quest_RabiesOutbreak_Name,  TWITTER_RABIESOUTBREAK},
    [TWITTER_BLUEROBBERRY] = {gText_Quest_RabiesOutbreak_Name,    TWITTER_BLUEROBBERRY},
    [TWITTER_ICECREAMCRAFTING] = {gText_Quest_RabiesOutbreak_Name,    TWITTER_ICECREAMCRAFTING },
    [TWITTER_VSDEOXYS] = {gText_Quest_RabiesOutbreak_Name,    TWITTER_VSDEOXYS },
    [TWITTER_CHINATOWNTUNNELS] = {gText_Quest_RabiesOutbreak_Name,    TWITTER_CHINATOWNTUNNELS },
    [TWITTER_FRESHWATEREVOLUTION] = {gText_Quest_RabiesOutbreak_Name,     TWITTER_FRESHWATEREVOLUTION  },
    [TWITTER_GEMARTIST] = {gText_Quest_RabiesOutbreak_Name,   TWITTER_GEMARTIST},
    [TWITTER_BETWEENASTONEANDAHARD] = {gText_Quest_RabiesOutbreak_Name,   TWITTER_BETWEENASTONEANDAHARD},
};

static void (*const sTwitterMenu_Actions_Quests[])(u8) = 
{
    [TWITTER_RABIESOUTBREAK] = TwitterMenu_Actions_Quests_RabiesOutbreak_Script,
    [TWITTER_BLUEROBBERRY] = TwitterMenu_Actions_Quests_BlueRobbery_Script,
    [TWITTER_ICECREAMCRAFTING] = TwitterMenu_Actions_Quests_IceCreamCrafting_Script,
    [TWITTER_VSDEOXYS] = TwitterMenu_Actions_Quests_VSDeoxys_Script,
    [TWITTER_CHINATOWNTUNNELS] = TwitterMenu_Actions_Quests_ChinatownTunnels_Script,
    [TWITTER_FRESHWATEREVOLUTION] = TwitterMenu_Actions_Quests_FreshwaterEvolution_Script,
    [TWITTER_GEMARTIST] = TwitterMenu_Actions_Quests_GemArtist_Script,
    [TWITTER_BETWEENASTONEANDAHARD] = TwitterMenu_Actions_Quests_BetweenAStoneAndAHardPlace_Script,    
};

static const struct WindowTemplate sTwitterMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = TWITTER_MAIN_MENU_WIDTH,
    .height = 2 * TWITTER_MAIN_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sTwitterMenuListTemplate =
{
    .items = sTwitterMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sTwitterMenuItems),
    .maxShowed = TWITTER_MAIN_MENU_HEIGHT,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sTwitterQuestsMenu_ListTemplate =
{
    .items = sTwitterMenuQuests,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sTwitterMenuQuests),
};

void Twitter_ShowMainMenu(void) {
    Twitter_ShowMenu(TwitterTask_HandleMainMenuInput, sTwitterMenuListTemplate);
}

static void Twitter_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sTwitterMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = LMtemplate;
    //menuTemplate = sTwitterMenuListTemplate;
    menuTemplate.windowId = windowId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(TwitterTask_HandleMainMenuInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Twitter_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void TwitterTask_HandleMainMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sTwitterMenuActions[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Twitter_DestroyMenu(taskId);
    }
}

static void TwitterAction_OpenQuestsList(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    Twitter_ShowMenu(TwitterTask_HandleMenuInput_Quests, sTwitterQuestsMenu_ListTemplate);
}

static void TwitterTask_HandleMenuInput_Quests(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sTwitterMenu_Actions_Quests[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Twitter_DestroyMenu(taskId);
        Twitter_ShowMainMenu();
    }
}

static void TwitterAction_Cancel(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
}

static void TwitterMenu_Actions_Quests_RabiesOutbreak_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_BlueRobbery_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_IceCreamCrafting_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_VSDeoxys_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_ChinatownTunnels_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_FreshwaterEvolution_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_GemArtist_Script(u8 taskId)
{
    return;
}
static void TwitterMenu_Actions_Quests_BetweenAStoneAndAHardPlace_Script(u8 taskId)
{
    return;
}

