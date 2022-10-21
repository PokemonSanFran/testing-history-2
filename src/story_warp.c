#include "global.h"
#include "battle.h"
#include "coins.h"
#include "credits.h"
#include "data.h"
#include "daycare.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "naming_screen.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "region_map.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "pokemon_summary_screen.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/weather.h"

enum {
    JUMPPLAYER_SWAGBAG,
    JUMPPLAYER_READYSETI,
    JUMPPLAYER_ENTERFALKNER,
    JUMPPLAYER_ENTERBUGSY,
    JUMPPLAYER_ENTERWHITNEY,
    JUMPPLAYER_NEWASSHOLEAPPEARS,
    JUMPPLAYER_OLDASSHOLEAPPEARS,
    JUMPPLAYER_GROUPOFASSHOLESAPPEARS,
    JUMPPLAYER_FLYINGBLIND,
    JUMPPLAYER_WOWYOURESTRONG,
    JUMPPLAYER_THEGANGSALLHERE,
    JUMPPLAYER_ALWAYSWATCHINGWAZOKWSKI,
    JUMPPLAYER_ENTERARIANA,
    JUMPPLAYER_HOWDOWEGETHOME,
    JUMPPLAYER_AAANDWEREBACK,
    JUMPPLAYER_ASSHOLESHOME,
    JUMPPLAYER_HOUSINGPROTEST,
    JUMPPLAYER_SWAGBAG2,
    JUMPPLAYER_ENTERMORTY,
    JUMPPLAYER_SORRYABOUTMYFRIENDS,
    JUMPPLAYER_THESTORYSOFAR,
    JUMPPLAYER_YOUNGPADAWAN,
    JUMPPLAYER_WAITYOUWENTWHERE,
    JUMPPLAYER_ENTERCHUCK,
    JUMPPLAYER_YOULOOKTIRED,
    JUMPPLAYER_KOGASRAISONDETRE,
    JUMPPLAYER_BEACHBATTLE,
    JUMPPLAYER_ENTERJASMINE,
    JUMPPLAYER_ANEWSTRIKE,
    JUMPPLAYER_ANDWEMARCHON,
    JUMPPLAYER_ENTERPRYCE,
    JUMPPLAYER_BATTLE8,
    JUMPPLAYER_ENTERCLAIR,
    JUMPPLAYER_THESTRIKESTRIKESBACK,
    JUMPPLAYER_VSGARBODOR,
    JUMPPLAYER_UNKNOWNALCATRAZCUTSCENE,
    JUMPPLAYER_OFFYOUGO,
    JUMPPLAYER_IGUESSWESHOULDBENICENOW,
    JUMPPLAYER_ENTERTHEMASTER,
    JUMPPLAYER_HAVEYOUSEENTHENEWS,
    JUMPPLAYER_WELCOMETOTHEWARROOM,
    JUMPPLAYER_SURVIVALCHANCE333,
    JUMPPLAYER_WHYAREYOUHELPINGTHEM,
    JUMPPLAYER_WHYAREYOUHELPINGTHEMSLEEP,
    JUMPPLAYER_HERESHOWTHISISGOINGTOGO,
    JUMPPLAYER_WHYDIDNTYOURATMEOUT,
    JUMPPLAYER_GROUPSTAGES,
    JUMPPLAYER_FINALS,
    JUMPPLAYER_WAITHEDIDWHAT,
    JUMPPLAYER_WELCOMETOTHEHALLOFFAME,
    JUMPPLAYER_BEINGCHAMPIONISHARD,
    JUMPPLAYER_LETSGRABLUNCH,
    JUMPPLAYER_RESTORECHINATOWN,
    JUMPPLAYER_RESTORETREASUREISLAND,
    JUMPPLAYER_RESTOREMAIN,
    JUMPPLAYER_RESTOREHAIGHTASHBURY,
    JUMPPLAYER_YOUREALIZEWEREEVILRIGHT,
    JUMPPLAYER_YOUREALIZETHEYREEVILRIGHT,
    JUMPPLAYER_CONGRATSYOUREANASSHOLE,
    JUMPPLAYER_YOUHAVEYOURORDERS,
    JUMPPLAYER_HOWDISAPPOINTING,
    JUMPPLAYER_LETSBURNTHISMOTHERDOWN,
    JUMPPLAYER_MANHUNT,
    JUMPPLAYER_EXHIBITIONBATTLE,
    JUMPPLAYER_MAYBEIFUCKEDUP,
    JUMPPLAYER_OKAYLETSFIXIT,
    JUMPPLAYER_LETSGETTHEBANDBACKTOGETHER,
    JUMPPLAYER_MASKOFF,
    JUMPPLAYER_LETSFIXTHIS,
    JUMPPLAYER_LOCKEDOUT,
    JUMPPLAYER_WAREHOUSERAVE,
    JUMPPLAYER_SPEECHSPEECHSPEECH,
    JUMPPLAYER_ONEDOWN,
    JUMPPLAYER_EARTHQUAKE,
    JUMPPLAYER_THISISNTRANDOM,
    JUMPPLAYER_WAITEVENTHEN,
    JUMPPLAYER_LETSFINISHTHIS,
    JUMPPLAYER_IMIN,
    JUMPPLAYER_YOUCANTSTOPME,
    JUMPPLAYER_WECANSTOPYOUACTUALLY
};

void JumpPlayerToStoryPoint(u8 chosenStoryPoint, u8 taskId)
{

    switch(chosenStoryPoint)
    {
        case JUMPPLAYER_SWAGBAG:
            JumpPlayerTo_swagbag();
            break;
        case JUMPPLAYER_READYSETI:
            JumpPlayerTo_ReadySetI();
            break;
        case JUMPPLAYER_ENTERFALKNER:
            JumpPlayerTo_EnterFalkner();
            break;
        case JUMPPLAYER_ENTERBUGSY:
            JumpPlayerTo_EnterBugsy();
            break;
        case JUMPPLAYER_ENTERWHITNEY:
            JumpPlayerTo_EnterWhitney();
            break;
        case JUMPPLAYER_NEWASSHOLEAPPEARS:
            JumpPlayerTo_NewAssholeAppears();
            break;
        case JUMPPLAYER_OLDASSHOLEAPPEARS:
            JumpPlayerTo_OldAssholeAppears();
            break;
        case JUMPPLAYER_GROUPOFASSHOLESAPPEARS:
            JumpPlayerTo_GroupofAssholesAppears();
            break;
        case JUMPPLAYER_FLYINGBLIND:
            JumpPlayerTo_FlyingBlind();
            break;
        case JUMPPLAYER_WOWYOURESTRONG:
            JumpPlayerTo_WowYoureStrong();
            break;
        case JUMPPLAYER_THEGANGSALLHERE:
            JumpPlayerTo_TheGangsAllHere();
            break;
        case JUMPPLAYER_ALWAYSWATCHINGWAZOKWSKI:
            JumpPlayerTo_AlwaysWatchingWazokwski();
            break;
        case JUMPPLAYER_ENTERARIANA:
            JumpPlayerTo_EnterAriana();
            break;
        case JUMPPLAYER_HOWDOWEGETHOME:
            JumpPlayerTo_HowDoWeGetHome();
            break;
        case JUMPPLAYER_AAANDWEREBACK:
            JumpPlayerTo_AaandWereBack();
            break;
        case JUMPPLAYER_ASSHOLESHOME:
            JumpPlayerTo_AssholesHome();
            break;
        case JUMPPLAYER_HOUSINGPROTEST:
            JumpPlayerTo_HousingProtest();
            break;
        case JUMPPLAYER_SWAGBAG2:
            JumpPlayerTo_swagbag2();
            break;
        case JUMPPLAYER_ENTERMORTY:
            JumpPlayerTo_EnterMorty();
            break;
        case JUMPPLAYER_SORRYABOUTMYFRIENDS:
            JumpPlayerTo_SorryAboutMyFriends();
            break;
        case JUMPPLAYER_THESTORYSOFAR:
            JumpPlayerTo_TheStorySoFar();
            break;
        case JUMPPLAYER_YOUNGPADAWAN:
            JumpPlayerTo_YoungPadawan();
            break;
        case JUMPPLAYER_WAITYOUWENTWHERE:
            JumpPlayerTo_WaitYouWentWhere();
            break;
        case JUMPPLAYER_ENTERCHUCK:
            JumpPlayerTo_EnterChuck();
            break;
        case JUMPPLAYER_YOULOOKTIRED:
            JumpPlayerTo_YouLookTired();
            break;
        case JUMPPLAYER_KOGASRAISONDETRE:
            JumpPlayerTo_Kogasraisondetre();
            break;
        case JUMPPLAYER_BEACHBATTLE:
            JumpPlayerTo_BeachBattle();
            break;
        case JUMPPLAYER_ENTERJASMINE:
            JumpPlayerTo_EnterJasmine();
            break;
        case JUMPPLAYER_ANEWSTRIKE:
            JumpPlayerTo_ANewStrike();
            break;
        case JUMPPLAYER_ANDWEMARCHON:
            JumpPlayerTo_AndWeMarchOn();
            break;
        case JUMPPLAYER_ENTERPRYCE:
            JumpPlayerTo_EnterPryce();
            break;
        case JUMPPLAYER_BATTLE8:
            JumpPlayerTo_Battle8();
            break;
        case JUMPPLAYER_ENTERCLAIR:
            JumpPlayerTo_EnterClair();
            break;
        case JUMPPLAYER_THESTRIKESTRIKESBACK:
            JumpPlayerTo_TheStrikeStrikesBack();
            break;
        case JUMPPLAYER_VSGARBODOR:
            JumpPlayerTo_VSGarbodor();
            break;
        case JUMPPLAYER_UNKNOWNALCATRAZCUTSCENE:
            JumpPlayerTo_UnknownAlcatrazCutscene();
            break;
        case JUMPPLAYER_OFFYOUGO:
            JumpPlayerTo_OffYouGo();
            break;
        case JUMPPLAYER_IGUESSWESHOULDBENICENOW:
            JumpPlayerTo_IGuessWeShouldBeNiceNow();
            break;
        case JUMPPLAYER_ENTERTHEMASTER:
            JumpPlayerTo_EntertheMaster();
            break;
        case JUMPPLAYER_HAVEYOUSEENTHENEWS:
            JumpPlayerTo_HaveYouSeenTheNews();
            break;
        case JUMPPLAYER_WELCOMETOTHEWARROOM:
            JumpPlayerTo_WelcometotheWarRoom();
            break;
        case JUMPPLAYER_SURVIVALCHANCE333:
            JumpPlayerTo_SurvivalChance333();
            break;
        case JUMPPLAYER_WHYAREYOUHELPINGTHEM:
            JumpPlayerTo_WhyAreYouHelpingThem();
            break;
        case JUMPPLAYER_WHYAREYOUHELPINGTHEMSLEEP:
            JumpPlayerTo_WhyAreYouHelpingThemSleep();
            break;
        case JUMPPLAYER_HERESHOWTHISISGOINGTOGO:
            JumpPlayerTo_HeresHowThisIsGoingToGo();
            break;
        case JUMPPLAYER_WHYDIDNTYOURATMEOUT:
            JumpPlayerTo_WhyDidntYouRatMeOut();
            break;
        case JUMPPLAYER_GROUPSTAGES:
            JumpPlayerTo_GroupStages();
            break;
        case JUMPPLAYER_FINALS:
            JumpPlayerTo_Finals();
            break;
        case JUMPPLAYER_WAITHEDIDWHAT:
            JumpPlayerTo_WaitHeDidWhat();
            break;
        case JUMPPLAYER_WELCOMETOTHEHALLOFFAME:
            JumpPlayerTo_WelcometotheHallofFame();
            break;
        case JUMPPLAYER_BEINGCHAMPIONISHARD:
            JumpPlayerTo_BeingChampionisHard();
            break;
        case JUMPPLAYER_LETSGRABLUNCH:
            JumpPlayerTo_LetsGrabLunch();
            break;
        case JUMPPLAYER_RESTORECHINATOWN:
            JumpPlayerTo_RestoreChinatown();
            break;
        case JUMPPLAYER_RESTORETREASUREISLAND:
            JumpPlayerTo_RestoreTreasureIsland();
            break;
        case JUMPPLAYER_RESTOREMAIN:
            JumpPlayerTo_RestoreMain();
            break;
        case JUMPPLAYER_RESTOREHAIGHTASHBURY:
            JumpPlayerTo_RestoreHaightAshbury();
            break;
        case JUMPPLAYER_YOUREALIZEWEREEVILRIGHT:
            JumpPlayerTo_YouRealizeWereEvilRight();
            break;
        case JUMPPLAYER_YOUREALIZETHEYREEVILRIGHT:
            JumpPlayerTo_YouRealizeTheyreEvilRight();
            break;
        case JUMPPLAYER_CONGRATSYOUREANASSHOLE:
            JumpPlayerTo_CongratsYoureanAsshole();
            break;
        case JUMPPLAYER_YOUHAVEYOURORDERS:
            JumpPlayerTo_YouHaveYourOrders();
            break;
        case JUMPPLAYER_HOWDISAPPOINTING:
            JumpPlayerTo_HowDisappointing();
            break;
        case JUMPPLAYER_LETSBURNTHISMOTHERDOWN:
            JumpPlayerTo_LetsBurnThisMotherDown();
            break;
        case JUMPPLAYER_MANHUNT:
            JumpPlayerTo_Manhunt();
            break;
        case JUMPPLAYER_EXHIBITIONBATTLE:
            JumpPlayerTo_ExhibitionBattle();
            break;
        case JUMPPLAYER_MAYBEIFUCKEDUP:
            JumpPlayerTo_MaybeIFuckedUp();
            break;
        case JUMPPLAYER_OKAYLETSFIXIT:
            JumpPlayerTo_OkayLetsFixit();
            break;
        case JUMPPLAYER_LETSGETTHEBANDBACKTOGETHER:
            JumpPlayerTo_LetsGettheBandBackTogether();
            break;
        case JUMPPLAYER_MASKOFF:
            JumpPlayerTo_MaskOff();
            break;
        case JUMPPLAYER_LETSFIXTHIS:
            JumpPlayerTo_LetsFixThis();
            break;
        case JUMPPLAYER_LOCKEDOUT:
            JumpPlayerTo_LockedOut();
            break;
        case JUMPPLAYER_WAREHOUSERAVE:
            JumpPlayerTo_WarehouseRave();
            break;
        case JUMPPLAYER_SPEECHSPEECHSPEECH:
            JumpPlayerTo_SpeechSpeechSpeech();
            break;
        case JUMPPLAYER_ONEDOWN:
            JumpPlayerTo_OneDown();
            break;
        case JUMPPLAYER_EARTHQUAKE:
            JumpPlayerTo_Earthquake();
            break;
        case JUMPPLAYER_THISISNTRANDOM:
            JumpPlayerTo_ThisIsntRandom();
            break;
        case JUMPPLAYER_WAITEVENTHEN:
            JumpPlayerTo_WaitEvenThen();
            break;
        case JUMPPLAYER_LETSFINISHTHIS:
            JumpPlayerTo_LetsFinishThis();
            break;
        case JUMPPLAYER_IMIN:
            JumpPlayerTo_ImIn();
            break;
        case JUMPPLAYER_YOUCANTSTOPME:
            JumpPlayerTo_YouCantStopMe();
            break;
        case JUMPPLAYER_WECANSTOPYOUACTUALLY:
            JumpPlayerTo_WeCanStopYouActually();
            break;
    }
    WarpPlayerAfterVarSet();
}

void WarpPlayerAfterVarSet()
{
    DoWarp();
    ResetInitialPlayerAvatarState();
    DebugAction_DestroyExtraWindow(taskId);
}

void JumpPlayerTo_swagbag()
{
    VarSet(VAR_PLAYER_HOME_STATE,POST_SWAGBAG);
    FlagSet(FLAG_SYS_POKENAV_GET);
    FlagSet(FLAG_SYS_QUEST_MENU_GET);
    QuestMenu_GetSetQuestState(QUEST_PLAYERSADVENTURE,QUEST_MENU_SET_ACTIVE);
    SetWarpDestinationToMapWarp(0, MAP_SOUTHBAY_COMPOUND_1F,0;

}

void JumpPlayerTo_ReadySetI()
{
    Storywarp_swagbag();
    VarSet(VAR_PLAYER_HOME_STATE,OPENED_FASHION_CASE)
    FlagSet(FLAG_RECIEVED_LEFTOVERS)
    gSpecialVar_Result = AddBagItem(ITEM_LEFTOVERS,1);
    SetWarpDestinationToMapWarp(0,MAP_SOUTHBAY,0;
}
