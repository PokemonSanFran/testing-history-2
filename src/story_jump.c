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
#include "quests.h"
#include "random.h"
#include "region_map.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "story_jump.h"
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

extern u8 LetsGrabLunch_CheckRestorationProgress_Script[];
extern u8 ExhibitionBattle_TimeSkip_Script[];

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
    JUMPPLAYER_RESTOREMARIN,
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

static void JumpPlayerTo_swagbag(void);
static void JumpPlayerTo_ReadySetI(void);
static void JumpPlayerTo_EnterFalkner(void);
static void JumpPlayerTo_EnterBugsy(void);
static void JumpPlayerTo_EnterWhitney(void);
static void JumpPlayerTo_NewAssholeAppears(void);
static void JumpPlayerTo_OldAssholeAppears(void);
static void JumpPlayerTo_GroupofAssholesAppears(void);
static void JumpPlayerTo_FlyingBlind(void);
static void JumpPlayerTo_WowYoureStrong(void);
static void JumpPlayerTo_TheGangsAllHere(void);
static void JumpPlayerTo_AlwaysWatchingWazokwski(void);
static void JumpPlayerTo_EnterAriana(void);
static void JumpPlayerTo_HowDoWeGetHome(void);
static void JumpPlayerTo_AaandWereBack(void);
static void JumpPlayerTo_AssholesHome(void);
static void JumpPlayerTo_HousingProtest(void);
static void JumpPlayerTo_swagbag2(void);
static void JumpPlayerTo_EnterMorty(void);
static void JumpPlayerTo_SorryAboutMyFriends(void);
static void JumpPlayerTo_TheStorySoFar(void);
static void JumpPlayerTo_YoungPadawan(void);
static void JumpPlayerTo_WaitYouWentWhere(void);
static void JumpPlayerTo_EnterChuck(void);
static void JumpPlayerTo_YouLookTired(void);
static void JumpPlayerTo_Kogasraisondetre(void);
static void JumpPlayerTo_BeachBattle(void);
static void JumpPlayerTo_EnterJasmine(void);
static void JumpPlayerTo_ANewStrike(void);
static void JumpPlayerTo_AndWeMarchOn(void);
static void JumpPlayerTo_EnterPryce(void);
static void JumpPlayerTo_Battle8(void);
static void JumpPlayerTo_EnterClair(void);
static void JumpPlayerTo_TheStrikeStrikesBack(void);
static void JumpPlayerTo_VSGarbodor(void);
static void JumpPlayerTo_UnknownAlcatrazCutscene(void);
static void JumpPlayerTo_OffYouGo(void);
static void JumpPlayerTo_IGuessWeShouldBeNiceNow(void);
static void JumpPlayerTo_EntertheMaster(void);
static void JumpPlayerTo_HaveYouSeenTheNews(void);
static void JumpPlayerTo_WelcometotheWarRoom(void);
static void JumpPlayerTo_SurvivalChance333(void);
static void JumpPlayerTo_WhyAreYouHelpingThem(void);
static void JumpPlayerTo_WhyAreYouHelpingThemSleep(void);
static void JumpPlayerTo_HeresHowThisIsGoingToGo(void);
static void JumpPlayerTo_WhyDidntYouRatMeOut(void);
static void JumpPlayerTo_GroupStages(void);
static void JumpPlayerTo_Finals(void);
static void JumpPlayerTo_WaitHeDidWhat(void);
static void JumpPlayerTo_WelcometotheHallofFame(void);
static void JumpPlayerTo_BeingChampionisHard(void);
static void JumpPlayerTo_LetsGrabLunch(void);
static void JumpPlayerTo_RestoreChinatown(void);
static void JumpPlayerTo_RestoreTreasureIsland(void);
static void JumpPlayerTo_RestoreMarin(void);
static void JumpPlayerTo_RestoreHaightAshbury(void);
static void JumpPlayerTo_YouRealizeWereEvilRight(void);
static void JumpPlayerTo_YouRealizeTheyreEvilRight(void);
static void JumpPlayerTo_CongratsYoureanAsshole(void);
static void JumpPlayerTo_YouHaveYourOrders(void);
static void JumpPlayerTo_HowDisappointing(void);
static void JumpPlayerTo_LetsBurnThisMotherDown(void);
static void JumpPlayerTo_Manhunt(void);
static void JumpPlayerTo_ExhibitionBattle(void);
static void JumpPlayerTo_MaybeIFuckedUp(void);
static void JumpPlayerTo_OkayLetsFixit(void);
static void JumpPlayerTo_LetsGettheBandBackTogether(void);
static void JumpPlayerTo_MaskOff(void);
static void JumpPlayerTo_LetsFixThis(void);
static void JumpPlayerTo_LockedOut(void);
static void JumpPlayerTo_WarehouseRave(void);
static void JumpPlayerTo_SpeechSpeechSpeech(void);
static void JumpPlayerTo_OneDown(void);
static void JumpPlayerTo_Earthquake(void);
static void JumpPlayerTo_ThisIsntRandom(void);
static void JumpPlayerTo_WaitEvenThen(void);
static void JumpPlayerTo_LetsFinishThis(void);
static void JumpPlayerTo_ImIn(void);
static void JumpPlayerTo_YouCantStopMe(void);
static void JumpPlayerTo_WeCanStopYouActually(void);

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
        case JUMPPLAYER_RESTOREMARIN:
            JumpPlayerTo_RestoreMarin();
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
}

void WarpPlayerAfterVarSet()
{
    DoWarp();
    ScriptContext_SetupScript(ExhibitionBattle_TimeSkip_Script);
    ResetInitialPlayerAvatarState();
}

void JumpPlayerTo_swagbag()
{
    VarSet(VAR_PLAYER_HOME_STATE,POST_SWAGBAG);
    FlagSet(FLAG_SYS_POKENAV_GET);
    FlagSet(FLAG_SYS_QUEST_MENU_GET);
    QuestMenu_GetSetQuestState(QUEST_PLAYERSADVENTURE,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_PLAYERSADVENTURE,FLAG_SET_ACTIVE);
    SetWarpDestination(2,0,0,-1,-1);
}

void JumpPlayerTo_ReadySetI()
{
    JumpPlayerTo_swagbag();
    VarSet(VAR_PLAYER_HOME_STATE,OPENED_FASHION_CASE);
    FlagSet(FLAG_RECIEVED_LEFTOVERS);
    gSpecialVar_Result = AddBagItem(ITEM_LEFTOVERS,1);

    SetWarpDestination(2,0,0,-1,-1);

}
void JumpPlayerTo_EnterFalkner(){
    JumpPlayerTo_ReadySetI();
    gSpecialVar_Result = AddBagItem(ITEM_TM01,1);
    FlagSet(FLAG_BADGE01_GET);
    VarSet(VAR_FALKNER_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_GYM_1_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,8,0,-1,-1);
}
void JumpPlayerTo_EnterBugsy(){
    JumpPlayerTo_ReadySetI();
    gSpecialVar_Result = AddBagItem(ITEM_TM02,1);
    FlagSet(FLAG_BADGE02_GET);
    VarSet(VAR_FALKNER_STATE,BATTLE_2_COMPLETE);
    VarSet(VAR_GYM_2_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,18,0,-1,-1);
}
void JumpPlayerTo_EnterWhitney(){
    JumpPlayerTo_ReadySetI();
    gSpecialVar_Result = AddBagItem(ITEM_TM03,1);
    FlagSet(FLAG_BADGE03_GET);
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,DEFEATED_WHITNEY);
    VarSet(VAR_WHITNEY_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_GYM_3_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,7,4,-1,-1);

}
void JumpPlayerTo_NewAssholeAppears(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_PSFROUTE9_STATE,DEFEATED_ARCHER_PSFROUTE9);
    SetWarpDestination(0,9,0,-1,-1);

}
void JumpPlayerTo_OldAssholeAppears(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_LOMBARDSTREET_STATE,DEFEATED_BIANCA_LOMBARD);
    SetWarpDestination(0,19,0,-1,-1);

}
void JumpPlayerTo_GroupofAssholesAppears(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_GROUP_OF_ASSHOLES_STATE,PLAYER_HAS_DEFEATED_TEAM_ROCKET);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,21,0,-1,-1);

}
void JumpPlayerTo_FlyingBlind(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_FAINTED_FOG_STATE,1);
    SetWarpDestination(0,22,0,-1,-1);

}
void JumpPlayerTo_WowYoureStrong(){
    JumpPlayerTo_EnterWhitney();
    VarSet(VAR_SOMA_STATE,POST_WOW_YOURE_STRONG);
    SetWarpDestination(0,7,0,-1,-1);

}
void JumpPlayerTo_TheGangsAllHere(){
    JumpPlayerTo_WowYoureStrong();
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,POST_THE_GANGS_ALL_HERE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(10,18,255,5,53);

}
void JumpPlayerTo_AlwaysWatchingWazokwski(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_SALESFORCETOWER_PRODUCTION_STATE,POST_ALWAYS_WATCHING_WAZOWSKI);
    SetWarpDestination(10,17,255,9,7);

}
void JumpPlayerTo_EnterAriana(){
    JumpPlayerTo_ReadySetI();
    gSpecialVar_Result = AddBagItem(ITEM_MEGA_RING,1);
    SetWarpDestination(0,10,255,2,40);

}
void JumpPlayerTo_HowDoWeGetHome(){
    JumpPlayerTo_ReadySetI();
    VarSet(VAR_DOGPATCH_STATE,POST_HOW_DO_WE_GET_HOME);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,5,255,11,21);

}

void JumpPlayerTo_AaandWereBack(){
    JumpPlayerTo_EnterFalkner();
    JumpPlayerTo_EnterBugsy();
    JumpPlayerTo_EnterWhitney();
    JumpPlayerTo_NewAssholeAppears();
    JumpPlayerTo_OldAssholeAppears();
    JumpPlayerTo_GroupofAssholesAppears();
    JumpPlayerTo_WowYoureStrong();
    JumpPlayerTo_TheGangsAllHere();
    JumpPlayerTo_EnterAriana();
    JumpPlayerTo_HowDoWeGetHome();
    VarSet(VAR_STORYLINE_STATE,STORY_FERRY_FIXED);
    VarSet(VAR_PLAYER_HOME_STATE,FINISHED_1_1);
    SetWarpDestination(2,1,0,-1,-1);
}
void JumpPlayerTo_AssholesHome(){
    JumpPlayerTo_AaandWereBack();
    VarSet(VAR_ALAMEDA_STATE,DEFEATED_ARCHER_ALAMEDA);
    VarSet(VAR_STORYLINE_STATE,STORY_DEFEAT_ARCHER_ALAMEDA);
    SetWarpDestination(0,23,255,20,5);

}
void JumpPlayerTo_HousingProtest(){
    JumpPlayerTo_AssholesHome();
    VarSet(VAR_STORYLINE_STATE,STORY_DEFEAT_BERKELEY_PROTEST);
    VarSet(VAR_PSFROUTE63_STATE,DEFEATED_TEAMROCKET_PSFROUTE63);
    SetWarpDestination(0,28,255,7,14);

}
void JumpPlayerTo_swagbag2(){
    JumpPlayerTo_HousingProtest();
    VarSet(VAR_BERKELEY_STATE, SWAGBAG_2_COMPLETE);
    SetWarpDestination(0,29,1,-1,-1);

}
void JumpPlayerTo_EnterMorty(){
    JumpPlayerTo_swagbag2();
    gSpecialVar_Result = AddBagItem(ITEM_TM04,1);
    FlagSet(FLAG_CONSTRUCTION_BREAKING_NEWS);
    FlagSet(FLAG_BADGE04_GET);
    VarSet(VAR_MORTY_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_GYM_4_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_BERKELEY_STATE,DEFEATED_MORTY);
    VarSet(VAR_STORYLINE_STATE,STORY_DEFEAT_MORTY);
    SetWarpDestination(0,29,0,-1,-1);

}
void JumpPlayerTo_SorryAboutMyFriends(){
    JumpPlayerTo_EnterMorty();
    VarSet(VAR_BERKELEY_STATE,GOT_ALCATRAZ_TICKET);
    VarSet(VAR_FERRY_STATE,FERRY_ALCATRAZ_AVAILABLE);
    gSpecialVar_Result = AddBagItem(ITEM_MYSTIC_TICKET,1);
    SetWarpDestination(0,29,0,-1,-1);

}
void JumpPlayerTo_TheStorySoFar(){
    JumpPlayerTo_SorryAboutMyFriends();
    VarSet(VAR_ALCATRAZ_EXHIBIT_STATE,ALCATRAZ_EXHIBIT_REWARD);
    VarSet(VAR_ALCATRAZ_STATE,FIRST_ARRIVED_ALCATRAZ);
    SetWarpDestination(0,30,255,37,59);

}
void JumpPlayerTo_YoungPadawan(){
    u8 storyline = 0;
    storyline = VarGet(VAR_STORYLINE_STATE);

    JumpPlayerTo_TheStorySoFar();
    if (storyline < STORY_COMPLETE_ALCATRAZ){
        VarSet(VAR_STORYLINE_STATE,STORY_COMPLETE_ALCATRAZ);
    }else{
        VarSet(VAR_STORYLINE_STATE,storyline);
    }

    VarSet(VAR_ALCATRAZ_STATE,BATTLED_MALVA);
    VarSet(VAR_ALCATRAZ_EXHIBIT_STATE,ALCATRAZ_EXHIBIT_COMPLETE);
    gSpecialVar_Result = AddBagItem(ITEM_GO_GOGGLES,1);
    SetWarpDestination(0,30,255,37,59);

}
void JumpPlayerTo_WaitYouWentWhere(){
    JumpPlayerTo_YoungPadawan();
    VarSet(VAR_WAIT_YOU_WENT_WHERE,POST_WAITYOUWENTWHERE);
    SetWarpDestination(0,13,255,3,1);

}
void JumpPlayerTo_EnterChuck(){
    JumpPlayerTo_YoungPadawan();
    gSpecialVar_Result = AddBagItem(ITEM_TM05,1);
    FlagSet(FLAG_BADGE05_GET);
    VarSet(VAR_GYM_5_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_CHUCK_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_FORTPOINT_STATE,DEFEATED_CHUCK);
    SetWarpDestination(0,31,0,-1,-1);

}
void JumpPlayerTo_YouLookTired(){
    JumpPlayerTo_EnterChuck();
    VarSet(VAR_FORTPOINT_STATE,MET_KOGA_OUTSIDE_GYM);
    SetWarpDestination(0,31,0,-1,-1);

}
void JumpPlayerTo_Kogasraisondetre(){
    JumpPlayerTo_YouLookTired();
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_KOGA_RAISON_DETRE_STATE, POST_KOGA_RAISON_DETRE);
    VarSet(VAR_KOGA_MANSION_STATE,FINISHED_KOGA_RAISON) ;
    SetWarpDestination(8,0,0,-1,-1);
}
void JumpPlayerTo_BeachBattle(){
    JumpPlayerTo_YoungPadawan();
    VarSet(VAR_BEACH_BATTLE_STATE,POST_BEACH_BATTLE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,34,255,10,23);
}
void JumpPlayerTo_EnterJasmine(){
    JumpPlayerTo_YoungPadawan();
    gSpecialVar_Result = AddBagItem(ITEM_TM06,1);
    FlagSet(FLAG_BADGE06_GET);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_GYM_6_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_JASMINE_STATE,BATTLE_1_COMPLETE);
    SetWarpDestination(0,37,0,-1,-1);
}
void JumpPlayerTo_ANewStrike(){
    JumpPlayerTo_YoungPadawan();
    FlagClear(FLAG_CONSTRUCTION_BREAKING_NEWS);
}
void JumpPlayerTo_AndWeMarchOn(){
    JumpPlayerTo_YoungPadawan();
    VarSet(VAR_HAIGHTASHBURY_STATE,PARADE_COMPLETE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,38,255,23,7);
}
void JumpPlayerTo_EnterPryce(){
    JumpPlayerTo_YoungPadawan();
    gSpecialVar_Result = AddBagItem(ITEM_TM07,1);
    FlagSet(FLAG_BADGE07_GET);
    VarSet(VAR_PRYCE_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_GYM_7_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,38,0,-1,-1);
}
void JumpPlayerTo_Battle8(){
    JumpPlayerTo_YoungPadawan();
    VarSet(VAR_BATTLE_8_STATE,DEFEATED_ARCHER_PAINTEDLADIES);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,40,255,19,16);
}
void JumpPlayerTo_EnterClair(){
    JumpPlayerTo_YoungPadawan();
    gSpecialVar_Result = AddBagItem(ITEM_TM08,1);
    FlagSet(FLAG_BADGE08_GET);
    VarSet(VAR_CLAIR_STATE,BATTLE_1_COMPLETE);
    VarSet(VAR_GYM_8_STATE,GYM_DEFEATED_LEADER);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,42,0,-1,-1);
}
void JumpPlayerTo_TheStrikeStrikesBack(){
    JumpPlayerTo_Kogasraisondetre();
    JumpPlayerTo_BeachBattle();
    JumpPlayerTo_EnterJasmine();
    JumpPlayerTo_ANewStrike();
    JumpPlayerTo_AndWeMarchOn();
    JumpPlayerTo_EnterPryce();
    JumpPlayerTo_Battle8();
    JumpPlayerTo_EnterClair();
    VarSet(VAR_CONSTRUCTION_STRIKE_STATE,START_VS_GARBODOR);
    VarSet(VAR_STORYLINE_STATE,STORY_CALLED_TO_CONSTRUCTION);
    SetWarpDestination(0,6,0,-1,-1);
}
void JumpPlayerTo_VSGarbodor(){
    JumpPlayerTo_TheStrikeStrikesBack();
    VarSet(VAR_CONSTRUCTION_STRIKE_STATE,TEAM_ROCKET_ARRESTED);
    VarSet(VAR_STORYLINE_STATE,STORY_NEED_SLEEP_BEFORE_SIEBOLD);
    SetWarpDestination(0,6,0,-1,-1);
}
void JumpPlayerTo_UnknownAlcatrazCutscene(){
}
void JumpPlayerTo_OffYouGo(){
    JumpPlayerTo_VSGarbodor();
    VarSet(VAR_GOLDENGATEBRIDGE_STATE,POST_OFF_YOU_GO);
    VarSet(VAR_STORYLINE_STATE,STORY_ASSIGNED_SIEBOLD_QUESTS);
    VarSet(VAR_ROBINWILLIAMSTUNNEL_STATE,BIANCA_INSIDE_TUNNEL);
    SetWarpDestination(2,1,0,-1,-1);
}
void JumpPlayerTo_IGuessWeShouldBeNiceNow(){
    JumpPlayerTo_OffYouGo();
    VarSet(VAR_MUIRWOODS_STATE,BIANCA_WAITING_MUIRWOODS);
    VarSet(VAR_MARIN_STATE,BIANCA_INVITED_AIRBNB);
    VarSet(VAR_ROBINWILLIAMSTUNNEL_STATE,SIEBOLD_BOSS_DEFEATED);
    SetWarpDestination(0,46,0,-1,-1);
}
void JumpPlayerTo_EntertheMaster(){
    JumpPlayerTo_IGuessWeShouldBeNiceNow();
    VarSet(VAR_MUIRWOODS_STATE,MET_SIEBOLD);
    SetWarpDestination(0,48,0,-1,-1);
}
void JumpPlayerTo_HaveYouSeenTheNews(){
    JumpPlayerTo_EntertheMaster();
    VarSet(VAR_MUIRWOODS_STATE, POST_HAVE_YOU_SEEN_THE_NEWS);
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_WELCOME_TO_THE_WAR_ROOM);
    SetWarpDestination(10,18,255,17,29);
}
void JumpPlayerTo_WelcometotheWarRoom(){
    JumpPlayerTo_HaveYouSeenTheNews();
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,POST_WELCOME_TO_THE_WAR_ROOM);
    VarSet(VAR_FERRYBUILDING_STATE,CHIEF_LEFT_WAR_ROOM);
    SetWarpDestination(10,18,255,17,29);
}
void JumpPlayerTo_SurvivalChance333(){
    JumpPlayerTo_WelcometotheWarRoom();
    VarSet(VAR_ALAMEDA_STATE,POST_SURVIVAL_CHANCE);
    VarSet(VAR_FERRYBUILDING_STATE,DEFEATED_SURVIVAL_CHANCE_BATTLE);
    SetWarpDestination(0,23,0,-1,-1);
}
void JumpPlayerTo_WhyAreYouHelpingThem(){
    JumpPlayerTo_SurvivalChance333();
    VarSet(VAR_NAVALBASE_STATE,DEFEATED_ARCHER_NAVALBASE);
    VarSet(VAR_PLAYER_HOME_STATE,NEXT_DAY_CHAMPIONSHIP);
    VarSet(VAR_STORYLINE_STATE,STORY_COMPLETED_NAVAL_BASE);
    SetWarpDestination(0,23,0,-1,-1);
}

void JumpPlayerTo_WhyAreYouHelpingThemSleep(){
    JumpPlayerTo_WhyAreYouHelpingThem();
    VarSet(VAR_STORYLINE_STATE,STORY_START_CHAMPIONSHIP);
    VarSet(VAR_ALAMEDA_STATE,SLEPT_AFTER_RAID);
    SetWarpDestination(0,54,255,9,6);
}

void JumpPlayerTo_HeresHowThisIsGoingToGo(){
    JumpPlayerTo_WhyAreYouHelpingThemSleep();
    VarSet(VAR_STORYLINE_STATE,STORY_CHAMPIONSHIP_EXPLAINED);
    SetWarpDestination(0,54,0,-1,-1);
}
void JumpPlayerTo_WhyDidntYouRatMeOut(){
    JumpPlayerTo_HeresHowThisIsGoingToGo();
    VarSet(VAR_STORYLINE_STATE,STORY_BIANCA_WON_GROUP);
    SetWarpDestination(0,55,0,-1,-1);
}
void JumpPlayerTo_GroupStages(){
    JumpPlayerTo_WhyDidntYouRatMeOut();
    VarSet(VAR_CHASECENTER_TOURNAMENT_STATE,PRE_BATTLE_4);
    FlagSet(FLAG_CHASECENTER_TOURNAMENT_HAPPENING);
    VarSet(VAR_STORYLINE_STATE,STORY_GROUP_STATE_COMPLETE);
    SetWarpDestination(0,54,255,10,3);
}
void JumpPlayerTo_Finals(){
    JumpPlayerTo_GroupStages();
    VarSet(VAR_CHASECENTER_TOURNAMENT_STATE,PRE_BATTLE_5);
    VarSet(VAR_STORYLINE_STATE,STORY_SEMIFINAL_COMPLETE);
    SetWarpDestination(0,54,255,10,3);
}
void JumpPlayerTo_WaitHeDidWhat(){
    VarSet(VAR_STORYLINE_STATE,STORY_SAVE_FINALS);
    SetWarpDestination(0,56,0,-1,-1);
    JumpPlayerTo_Finals();
}
void JumpPlayerTo_WelcometotheHallofFame(){
    JumpPlayerTo_WaitHeDidWhat();
    VarSet(VAR_CHASECENTER_TOURNAMENT_STATE,NO_TOURNAMENT);
    FlagClear(FLAG_CHASECENTER_TOURNAMENT_HAPPENING);
    VarSet(VAR_STORYLINE_STATE,STORY_WON_FINALS); 
    FlagSet(FLAG_IS_CHAMPION);
    HealPlayerParty();
    FlagSet(FLAG_SYS_GAME_CLEAR);
    SetWarpDestination(0,58,255,11,4);
}
void JumpPlayerTo_BeingChampionisHard(){
    JumpPlayerTo_WelcometotheHallofFame();
    VarSet(VAR_STORYLINE_STATE,STORY_EXPLORE_TREASUREISLAND);
    SetWarpDestination(0,58,255,7,9);
}
void JumpPlayerTo_LetsGrabLunch(){
    JumpPlayerTo_BeingChampionisHard();
    VarSet(VAR_STORYLINE_STATE,STORY_ARCHER_EXPLAIN_RESTORATION);
    SetWarpDestination(0,60,255,14,9);
}
void JumpPlayerTo_RestoreChinatown(){
    JumpPlayerTo_LetsGrabLunch();
    QuestMenu_GetSetQuestState(QUEST_RESTORECHINATOWN,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_RESTORECHINATOWN,FLAG_SET_COMPLETED);
    ScriptContext_SetupScript(LetsGrabLunch_CheckRestorationProgress_Script);
    SetWarpDestination(0,17,255,21,4);
}
void JumpPlayerTo_RestoreTreasureIsland(){
    JumpPlayerTo_LetsGrabLunch();
    QuestMenu_GetSetQuestState(QUEST_RESTORETREASUREISLAND,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_RESTORETREASUREISLAND,FLAG_SET_COMPLETED);
    ScriptContext_SetupScript(LetsGrabLunch_CheckRestorationProgress_Script);
    SetWarpDestination(0,59,255,3,15);
}
void JumpPlayerTo_RestoreMarin(){
    JumpPlayerTo_LetsGrabLunch();
    VarSet(VAR_QUEST_RESTOREMARIN,DEFEATED_LENORA);
    QuestMenu_GetSetQuestState(QUEST_RESTOREMARIN,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_RESTOREMARIN,FLAG_SET_COMPLETED);
    ScriptContext_SetupScript(LetsGrabLunch_CheckRestorationProgress_Script);
    SetWarpDestination(0,46,255,8,18);
}
void JumpPlayerTo_RestoreHaightAshbury(){
    JumpPlayerTo_LetsGrabLunch();
    QuestMenu_GetSetQuestState(QUEST_RESTOREHAIGHTASHBURY,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_RESTOREHAIGHTASHBURY,FLAG_SET_COMPLETED);
    ScriptContext_SetupScript(LetsGrabLunch_CheckRestorationProgress_Script);
    SetWarpDestination(0,38,255,7,27);
}
void JumpPlayerTo_YouRealizeWereEvilRight(){
    JumpPlayerTo_RestoreHaightAshbury();
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,POST_YOU_REALIZE_WERE_EVIL_RIGHT);
    FlagSet(FLAG_ARCHER_CALL_ALCATRAZ);
    VarSet(VAR_STORYLINE_STATE,STORY_POST_YOU_REALIZE_WERE_EVIL);
    SetWarpDestination(10,18,255,17,29);
}
void JumpPlayerTo_YouRealizeTheyreEvilRight(){
    JumpPlayerTo_YouRealizeWereEvilRight();
    VarSet(VAR_ALCATRAZ_STATE,POST_YOU_REALIZE_THEYRE_EVIL_RIGHT);
    VarSet(VAR_STORYLINE_STATE,STORY_MORNING_OF_TIMELINE_SPLIT);
    FlagClear(FLAG_ARCHER_CALL_ALCATRAZ);
}
void JumpPlayerTo_CongratsYoureanAsshole(){
    u8 storyline = 0;

    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,START_FALSE_TIMELINE);
    FlagSet(FLAG_TIMELINE_FALSE);

    storyline = VarGet(VAR_STORYLINE_STATE);
    JumpPlayerTo_YouRealizeTheyreEvilRight();

    if (storyline < STORY_1ST_TEAMROCKET_TAKEDOWN){
        VarSet(VAR_STORYLINE_STATE,STORY_START_FALSE_TIMELINE);
    }else{
        VarSet(VAR_STORYLINE_STATE,storyline);
    }
    SetWarpDestination(10,18,255,17,29);
}
void JumpPlayerTo_YouHaveYourOrders(){
    JumpPlayerTo_CongratsYoureanAsshole();
    QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING,FLAG_SET_ACTIVE);
    VarSet(VAR_HOW_DISAPPOINTING_STATE,MISSION_ASSIGNED);
    SetWarpDestination(0,17,255,33,8);
}
void JumpPlayerTo_HowDisappointing(){
    JumpPlayerTo_YouHaveYourOrders();
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING,FLAG_SET_COMPLETED);
    VarSet(VAR_HOW_DISAPPOINTING_STATE,HOW_DISAPPOINTING_COMPLETE);
    SetWarpDestination(10,18,255,32,53);
}
void JumpPlayerTo_LetsBurnThisMotherDown(){
    JumpPlayerTo_CongratsYoureanAsshole();
    QuestMenu_GetSetQuestState(QUEST_LETS_BURN_THIS_MOTHER_DOWN,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_LETS_BURN_THIS_MOTHER_DOWN,FLAG_SET_COMPLETED);
    VarSet(VAR_LETS_BURN_THIS_MOTHER_STATE,BURN_MOTHER_COMPLETE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(10,18,255,34,5);
}
void JumpPlayerTo_Manhunt(){
    JumpPlayerTo_CongratsYoureanAsshole();
    QuestMenu_GetSetQuestState(QUEST_MANHUNT,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_MANHUNT,FLAG_SET_COMPLETED);
    VarSet(VAR_MANHUNT_STATE,MANHUNT_COMPLETE);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(10,18,255,5,5);
}
void JumpPlayerTo_ExhibitionBattle(){
    JumpPlayerTo_Manhunt();
    JumpPlayerTo_LetsGettheBandBackTogether();
    JumpPlayerTo_HowDisappointing();
    VarSet(VAR_STORYLINE_STATE,STORY_CONGRATULATED_BY_ROSE);
    SetWarpDestination(0,54,2,-1,-1);
}
void JumpPlayerTo_MaybeIFuckedUp(){
    JumpPlayerTo_ExhibitionBattle();
    VarSet(VAR_STORYLINE_STATE,STORY_RECIEVED_BAMBOO_STAR);
    SetWarpDestination(0,6,1,-1,-1);
}
void JumpPlayerTo_OkayLetsFixit(){
    JumpPlayerTo_MaybeIFuckedUp();
    FlagSet(FLAG_TIMELINE_TIMETRAVEL);
    FlagClear(FLAG_TIMELINE_FALSE);
    VarSet(VAR_STORYLINE_STATE,STORY_MORNING_OF_TIMELINE_SPLIT);
    VarSet(VAR_MANHUNT_STATE,NOT_ASSIGNED);
    VarSet(VAR_HOW_DISAPPOINTING_STATE,NOT_ASSIGNED);
    VarSet(VAR_HOW_DISAPPOINTING_STATE,NOT_ASSIGNED);
    SetWarpDestination(0,58,0,-1,-1);
}
void JumpPlayerTo_LetsGettheBandBackTogether(){
    JumpPlayerTo_YouRealizeTheyreEvilRight();
    VarSet(VAR_ALCATRAZ_STATE,START_TRUE_TIMELINE);
    VarSet(VAR_STORYLINE_STATE,STORY_START_TRUE_TIMELINE);
    FlagSet(FLAG_TIMELINE_TRUE);
    VarSet(VAR_MASK_OFF_STATE,ASSIGNED_MASK_OFF);
    SetWarpDestination(0,62,0,-1,-1);
}
void JumpPlayerTo_MaskOff(){
    JumpPlayerTo_LetsGettheBandBackTogether();
    VarSet(VAR_MASK_OFF_STATE,DEFEATED_MASK_OFF_GIOVANNI);
    VarSet(VAR_STORYLINE_STATE,STORY_DEFEATED_GIOVANNI);
    SetWarpDestination(0,65,255,22,26);
}
void JumpPlayerTo_LockedOut(){
    JumpPlayerTo_MaskOff();
    FlagSet(FLAG_LOCKEDOUT_PLAYED);
    SetWarpDestination(0,73,0,-1,-1);
}
void JumpPlayerTo_LetsFixThis(){
    u8 storyline = 0;

    storyline = VarGet(VAR_STORYLINE_STATE);
    JumpPlayerTo_LockedOut();
    VarSet(VAR_STORYLINE_STATE,STORY_RECIVED_RAVE_INVITE);

    if (storyline < STORY_RAVE_OR_SPEECH_COMPLETE){
        VarSet(VAR_STORYLINE_STATE,STORY_RECIVED_RAVE_INVITE);
    }else{
        VarSet(VAR_STORYLINE_STATE,storyline);
    }

    VarSet(VAR_ALAMEDA_STATE,PRE_SPEECHSPEECH);
    VarSet(VAR_WAREHOUSE_RAVE_STATE,GOT_RAVE_MESSAGE);
    FlagSet(FLAG_LOCKEDOUT_PLAYED);
    SetWarpDestination(0,73,0,-1,-1);
}
void JumpPlayerTo_WarehouseRave(){
    JumpPlayerTo_LetsFixThis();
    VarSet(VAR_WAREHOUSE_RAVE_STATE,TOLD_ARCHER_ABOUT_KOGA);
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    SetWarpDestination(0,27,1,-1,-1);
}
void JumpPlayerTo_SpeechSpeechSpeech(){
    JumpPlayerTo_LetsFixThis();
    VarSet(VAR_STORYLINE_STATE,(VarGet(VAR_STORYLINE_STATE)+1));
    VarSet(VAR_ALCATRAZ_STATE,POST_SPEECHSPEECH);
    SetWarpDestination(0,62,0,-1,-1);
}
void JumpPlayerTo_OneDown(){
    JumpPlayerTo_SpeechSpeechSpeech();
    JumpPlayerTo_WarehouseRave();
    VarSet(VAR_STORYLINE_STATE,STORY_PRE_EARTHQUAKE);
    SetWarpDestination(0,62,0,-1,-1);
}
void JumpPlayerTo_Earthquake(){
    JumpPlayerTo_OneDown();
    VarSet(VAR_ALAMEDA_STATE,MEET_AT_PSFROUTE8);
    VarSet(VAR_STORYLINE_STATE,STORY_POST_EARTHQUAKE);
    SetWarpDestination(0,14,255,11,17);
}
void JumpPlayerTo_ThisIsntRandom(){
    JumpPlayerTo_Earthquake();
    VarSet(VAR_UNDERGROUNDLAB_STATE,FREED_LAB_POKEMON_2);
    SetWarpDestination(0,78,255,30,5);
}
void JumpPlayerTo_WaitEvenThen(){
    JumpPlayerTo_ThisIsntRandom();
    VarSet(VAR_UNDERGROUNDLAB_STATE,DEFEATED_DYNAMAX);
    VarSet(VAR_ALAMEDA_STATE,POST_THIS_ISNT_RANDOM);
    VarSet(VAR_STORYLINE_STATE,STORY_POST_DYNAMAX_BOSS);
    SetWarpDestination(0,23,255,32,13);
}
void JumpPlayerTo_LetsFinishThis(){
    JumpPlayerTo_WaitEvenThen();
    VarSet(VAR_STORYLINE_STATE,STORY_BEFORE_SABRINA_BREAKIN);
    SetWarpDestination(0,69,255,13,19);
}
void JumpPlayerTo_ImIn(){
    JumpPlayerTo_LetsFinishThis();
    VarSet(VAR_STORYLINE_STATE,STORY_WARP_TILE_ACCESSIBLE);
    VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,TRUE_RAID_START);
    VarSet(VAR_TOWER_RAID_STATE,DEFEATED_BIANCA_SALESFORCETOWER);
    gSpecialVar_Result = AddBagItem(ITEM_MAGMA_EMBLEM,1);
    SetWarpDestination(0,79,0,-1,-1);
}
void JumpPlayerTo_YouCantStopMe(){
    JumpPlayerTo_ImIn();
    VarSet(VAR_TOWER_RAID_STATE,SAVE_ROSE_SALESFORCETOWER);
    SetWarpDestination(10,19,255,15,6);
}
void JumpPlayerTo_WeCanStopYouActually(){
    JumpPlayerTo_YouCantStopMe();
    VarSet(VAR_STORYLINE_STATE,STORY_CLEAR);
    VarSet(VAR_TOWER_RAID_STATE,DEFEATED_ROSE_SALESFORCETOWER);
    SetWarpDestination(0,80,0,-1,-1);
}

