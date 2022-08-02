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

enum {
    TWITTER_MENU_ITEM_QUESTS,
    TWITTER_MENU_ITEM_CANCEL,
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

#define TWITTER_MAIN_MENU_HEIGHT 8
#define TWITTER_MAIN_MENU_WIDTH 11

static void Twitter_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
void Twitter_ShowMainMenu(void);
void Twitter_ShowQuestMenu(void);
static void Twitter_DestroyMenu(u8);
static void TwitterAction_Cancel(u8);
static void TwitterTask_HandleMainMenuInput(u8);
static void TwitterTask_HandleMenuInput_Quests(u8);

static void TwitterAction_OpenQuestsList(u8);

static void TwitterMenu_Actions_Quests_RabiesOutbreak_Script(u8);
static void TwitterMenu_Actions_Quests_BlueRobbery_Script(u8);
static void TwitterMenu_Actions_Quests_IceCreamCrafting_Script(u8);
static void TwitterMenu_Actions_Quests_VSDeoxys_Script(u8);
static void TwitterMenu_Actions_Quests_ChinatownTunnels_Script(u8);
static void TwitterMenu_Actions_Quests_FreshwaterEvolution_Script(u8);
static void TwitterMenu_Actions_Quests_GemArtist_Script(u8);
static void TwitterMenu_Actions_Quests_BetweenAStoneAndAHardPlace_Script(u8);

extern u8 TwitterPost_RabiesOutbreak_Script[];
extern u8 TwitterPost_BlueRobbery_Script[];
extern u8 TwitterPost_IceCreamCrafting_Script[];
extern u8 TwitterPost_VSDeoxys_Script[];
extern u8 TwitterPost_ChinatownTunnels_Script[];
extern u8 TwitterPost_FreshwaterEvolution_Script[];
extern u8 TwitterPost_GemArtist_Script[];
extern u8 TwitterPost_BetweenAStoneAndAHardPlace_Script[];

static const u8 gTwitterText_Cancel[] = _("Cancel");
static const u8 gTwitterText_Quests[] = _("Quests");

static const struct ListMenuItem sTwitterMenuItems[] =
{
    [TWITTER_MENU_ITEM_QUESTS] = {gTwitterText_Quests, TWITTER_MENU_ITEM_QUESTS},
    [TWITTER_MENU_ITEM_CANCEL] = {gTwitterText_Cancel, TWITTER_MENU_ITEM_CANCEL}
};

//PSF TODO If the player has not spoken to the reporter yet, the quests beyond BlueRobbery should not be available.

static const struct ListMenuItem sTwitterMenuQuests[] =
{
    [TWITTER_RABIESOUTBREAK] = {gText_Quest_RabiesOutbreak_Name,  TWITTER_RABIESOUTBREAK},
    [TWITTER_BLUEROBBERRY] = {gText_Quest_BlueRobbery_Name,    TWITTER_BLUEROBBERRY},
    [TWITTER_ICECREAMCRAFTING] = {gText_Quest_IceCreamCrafting_Name,    TWITTER_ICECREAMCRAFTING },
    [TWITTER_VSDEOXYS] = {gText_Quest_VSDeoxys_Name,    TWITTER_VSDEOXYS },
    [TWITTER_CHINATOWNTUNNELS] = {gText_Quest_ChinatownTunnels_Name,    TWITTER_CHINATOWNTUNNELS },
    [TWITTER_FRESHWATEREVOLUTION] = {gText_Quest_FreshwaterEvolution_Name,     TWITTER_FRESHWATEREVOLUTION  },
    [TWITTER_GEMARTIST] = {gText_Quest_GemArtist_Name,   TWITTER_GEMARTIST},
    [TWITTER_BETWEENASTONEANDAHARD] = {gText_Quest_BetweenAStoneAndAHardPlace_Name,   TWITTER_BETWEENASTONEANDAHARD}
};

static void (*const sTwitterMenuActions[])(u8) =
{
    [TWITTER_MENU_ITEM_QUESTS] = TwitterAction_OpenQuestsList,
    [TWITTER_MENU_ITEM_CANCEL] = TwitterAction_Cancel
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
};

static const struct ListMenuTemplate sTwitterQuestsMenu_ListTemplate =
{
    .items = sTwitterMenuQuests,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sTwitterMenuQuests),
    .maxShowed = TWITTER_MAIN_MENU_HEIGHT,
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
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(HandleInput,3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Twitter_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
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
        EnableBothScriptContexts();
    }
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

static void TwitterAction_OpenQuestsList(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    Twitter_ShowMenu(TwitterTask_HandleMenuInput_Quests, sTwitterQuestsMenu_ListTemplate);
}


static void TwitterAction_Cancel(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
}

static void TwitterMenu_Actions_Quests_RabiesOutbreak_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_RabiesOutbreak_Script);
}
static void TwitterMenu_Actions_Quests_BlueRobbery_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_BlueRobbery_Script);
}
static void TwitterMenu_Actions_Quests_IceCreamCrafting_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_IceCreamCrafting_Script);
}
static void TwitterMenu_Actions_Quests_VSDeoxys_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_VSDeoxys_Script);
}
static void TwitterMenu_Actions_Quests_ChinatownTunnels_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_ChinatownTunnels_Script);
}
static void TwitterMenu_Actions_Quests_FreshwaterEvolution_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_FreshwaterEvolution_Script);
}
static void TwitterMenu_Actions_Quests_GemArtist_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_GemArtist_Script);
}
static void TwitterMenu_Actions_Quests_BetweenAStoneAndAHardPlace_Script(u8 taskId)
{
    Twitter_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(TwitterPost_BetweenAStoneAndAHardPlace_Script);
}
