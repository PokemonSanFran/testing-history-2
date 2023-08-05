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
#include "quest_logic.h"
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

enum
{
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
	//JUMPPLAYER_THESTORYSOFAR,
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
	//JUMPPLAYER_RESTOREHAIGHTASHBURY,
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
    JUMPPLAYER_PERSUASIVEPASSENGER,
    JUMPPLAYER_BREAKTHEINTERNET,
    JUMPPLAYER_WAREHOUSEWARFARE,
	JUMPPLAYER_ONEDOWN,
	JUMPPLAYER_EARTHQUAKE,
	JUMPPLAYER_THISISNTRANDOM,
	JUMPPLAYER_WAITEVENTHEN,
	JUMPPLAYER_LETSFINISHTHIS,
	JUMPPLAYER_IMIN,
	JUMPPLAYER_YOUCANTSTOPME,
	JUMPPLAYER_WECANSTOPYOUACTUALLY
};

static void IncrementStorylineVariable();
static void PreventVariableFromReversion(u16, u8, u8);
static void JumpPlayerTo_swagbag();
static void JumpPlayerTo_ReadySetI();
static void JumpPlayerTo_EnterFalkner();
static void JumpPlayerTo_EnterBugsy();
static void JumpPlayerTo_EnterWhitney();
static void JumpPlayerTo_NewAssholeAppears();
static void JumpPlayerTo_OldAssholeAppears();
static void JumpPlayerTo_GroupofAssholesAppears();
static void JumpPlayerTo_FlyingBlind();
static void JumpPlayerTo_WowYoureStrong();
static void JumpPlayerTo_TheGangsAllHere();
static void JumpPlayerTo_AlwaysWatchingWazokwski();
static void JumpPlayerTo_EnterAriana();
static void JumpPlayerTo_HowDoWeGetHome();
static void JumpPlayerTo_AaandWereBack();
static void JumpPlayerTo_AssholesHome();
static void JumpPlayerTo_HousingProtest();
static void JumpPlayerTo_swagbag2();
static void JumpPlayerTo_EnterMorty();
static void JumpPlayerTo_SorryAboutMyFriends();
//static void JumpPlayerTo_TheStorySoFar();
static void JumpPlayerTo_YoungPadawan();
static void JumpPlayerTo_WaitYouWentWhere();
static void JumpPlayerTo_EnterChuck();
static void JumpPlayerTo_YouLookTired();
static void JumpPlayerTo_Kogasraisondetre();
static void JumpPlayerTo_BeachBattle();
static void JumpPlayerTo_EnterJasmine();
static void JumpPlayerTo_ANewStrike();
static void JumpPlayerTo_AndWeMarchOn();
static void JumpPlayerTo_EnterPryce();
static void JumpPlayerTo_Battle8();
static void JumpPlayerTo_EnterClair();
static void JumpPlayerTo_TheStrikeStrikesBack();
static void JumpPlayerTo_VSGarbodor();
static void JumpPlayerTo_OffYouGo();
static void JumpPlayerTo_IGuessWeShouldBeNiceNow();
static void JumpPlayerTo_EntertheMaster();
static void JumpPlayerTo_HaveYouSeenTheNews();
static void JumpPlayerTo_WelcometotheWarRoom();
static void JumpPlayerTo_SurvivalChance333();
static void JumpPlayerTo_WhyAreYouHelpingThem();
static void JumpPlayerTo_WhyAreYouHelpingThemSleep();
static void JumpPlayerTo_HeresHowThisIsGoingToGo();
static void JumpPlayerTo_WhyDidntYouRatMeOut();
static void JumpPlayerTo_GroupStages();
static void JumpPlayerTo_Finals();
static void JumpPlayerTo_WaitHeDidWhat();
static void JumpPlayerTo_WelcometotheHallofFame();
static void JumpPlayerTo_BeingChampionisHard();
static void JumpPlayerTo_LetsGrabLunch();
static void JumpPlayerTo_RestoreChinatown();
static void JumpPlayerTo_RestoreTreasureIsland();
static void JumpPlayerTo_RestoreMarin();
//static void JumpPlayerTo_RestoreHaightAshbury();
static void JumpPlayerTo_YouRealizeWereEvilRight();
static void JumpPlayerTo_YouRealizeTheyreEvilRight();
static void JumpPlayerTo_CongratsYoureanAsshole();
static void JumpPlayerTo_YouHaveYourOrders();
static void JumpPlayerTo_HowDisappointing();
static void JumpPlayerTo_LetsBurnThisMotherDown();
static void JumpPlayerTo_Manhunt();
static void JumpPlayerTo_ExhibitionBattle();
static void JumpPlayerTo_MaybeIFuckedUp();
static void JumpPlayerTo_OkayLetsFixit();
static void JumpPlayerTo_LetsGettheBandBackTogether();
static void JumpPlayerTo_MaskOff();
static void JumpPlayerTo_LetsFixThis();
static void JumpPlayerTo_LockedOut();
static void JumpPlayerTo_WarehouseRave();
static void JumpPlayerTo_SpeechSpeechSpeech();
static void JumpPlayerTo_Persuasivepassenger();
static void JumpPlayerTo_Breaktheinternet();
static void JumpPlayerTo_Warehousewarfare();
static void JumpPlayerTo_OneDown();
static void JumpPlayerTo_Earthquake();
static void JumpPlayerTo_ThisIsntRandom();
static void JumpPlayerTo_WaitEvenThen();
static void JumpPlayerTo_LetsFinishThis();
static void JumpPlayerTo_ImIn();
static void JumpPlayerTo_YouCantStopMe();
static void JumpPlayerTo_WeCanStopYouActually();

void JumpPlayerToStoryPoint(u8 chosenStoryPoint, u8 taskId)
{
	switch (chosenStoryPoint)
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
            /*
		case JUMPPLAYER_THESTORYSOFAR:
		JumpPlayerTo_TheStorySoFar();
		break;
		*/
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
            /*
		case JUMPPLAYER_RESTOREHAIGHTASHBURY:
			JumpPlayerTo_RestoreHaightAshbury();
            */
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
        case JUMPPLAYER_PERSUASIVEPASSENGER:
            JumpPlayerTo_Persuasivepassenger();
            break;
        case JUMPPLAYER_BREAKTHEINTERNET:
            JumpPlayerTo_Breaktheinternet();
            break;
        case JUMPPLAYER_WAREHOUSEWARFARE:
            JumpPlayerTo_Warehousewarfare();
            break;
        case JUMPPLAYER_ONEDOWN:
			JumpPlayerTo_OneDown();
            break;
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
	ResetInitialPlayerAvatarState();
}

static void IncrementStorylineVariable()
{
	VarSet(VAR_STORYLINE_STATE, (VarGet(VAR_STORYLINE_STATE) + 1));
}

static void PreventVariableFromReversion(u16 adjustedVariable,
            u8 originalValue, u8 newValue)
{
	if (originalValue < newValue)
	{
		VarSet(adjustedVariable, newValue);
	}
	else
	{
		VarSet(adjustedVariable, originalValue);
	}
}

void JumpPlayerTo_swagbag()
{
    VarSet(VAR_PROLOGUE_STATE,START_ADVENTURE);
	VarSet(VAR_PLAYER_HOME_STATE, POST_SWAGBAG);
	FlagSet(FLAG_SYS_POKENAV_GET);
	FlagSet(FLAG_SYS_QUEST_MENU_GET);
    FlagSet(FLAG_SET_WALL_CLOCK);
	QuestMenu_GetSetQuestState(QUEST_PLAYERSADVENTURE, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_PLAYERSADVENTURE, FLAG_SET_ACTIVE);
	SetWarpDestination(MAP_GROUP(SOUTHBAY_COMPOUND_1F), MAP_NUM(SOUTHBAY_COMPOUND_1F), 0, USE_WARP_ID, USE_WARP_ID);
    ScriptContext_SetupScript(ThereCanOnlyBeOne_Debug_Script);
}

void JumpPlayerTo_ReadySetI()
{
	JumpPlayerTo_swagbag();
	VarSet(VAR_PLAYER_HOME_STATE, OPENED_FASHION_CASE);
	FlagSet(FLAG_RECIEVED_LEFTOVERS);
	AddBagItem(ITEM_LEFTOVERS, 1);
	SetWarpDestination(MAP_GROUP(SOUTHBAY_COMPOUND_1F), MAP_NUM(SOUTHBAY_COMPOUND_1F), 0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_EnterFalkner()
{
	JumpPlayerTo_ReadySetI();
	AddBagItem(ITEM_TM01, 1);
	FlagSet(FLAG_BADGE01_GET);
	FlagSet(TRAINER_FLAGS_START + TRAINER_FALKNER);
	VarSet(VAR_FALKNER_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_GYM_1_STATE, GYM_DEFEATED_LEADER);
	IncrementStorylineVariable();
    SetWarpDestination(MAP_GROUP(MISSION_GYM),MAP_NUM(MISSION_GYM),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_EnterBugsy()
{
	JumpPlayerTo_ReadySetI();
	AddBagItem(ITEM_TM02, 1);
	FlagSet(FLAG_BADGE02_GET);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BUGSY);
	VarSet(VAR_BUGSY_STATE, BATTLE_2_COMPLETE);
	VarSet(VAR_GYM_2_STATE, GYM_DEFEATED_LEADER);
	IncrementStorylineVariable();
    SetWarpDestination(MAP_GROUP(JAPANTOWN_GYM),MAP_NUM(JAPANTOWN_GYM),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_EnterWhitney()
{
	JumpPlayerTo_ReadySetI();
	AddBagItem(ITEM_TM03, 1);
	FlagSet(FLAG_BADGE03_GET);
	FlagSet(TRAINER_FLAGS_START + TRAINER_WHITNEY);
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, DEFEATED_WHITNEY);
	VarSet(VAR_WHITNEY_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_GYM_3_STATE, GYM_DEFEATED_LEADER);
	IncrementStorylineVariable();
    SetWarpDestination(MAP_GROUP(SOMA_GYM),MAP_NUM(SOMA_GYM),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_NewAssholeAppears()
{
	JumpPlayerTo_ReadySetI();
	IncrementStorylineVariable();
	VarSet(VAR_PSFROUTE9_STATE, DEFEATED_ARCHER_PSFROUTE9);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_NEWASSHOLEAPPEARS);
    SetWarpDestination(MAP_GROUP(PSFROUTE9),MAP_NUM(PSFROUTE9),NO_WARP_ID,2,4);
}
void JumpPlayerTo_OldAssholeAppears()
{
	JumpPlayerTo_ReadySetI();
	IncrementStorylineVariable();
	VarSet(VAR_LOMBARDSTREET_STATE, DEFEATED_BIANCA_LOMBARD);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BIANCA_OLDASSHOLEAPPEARS);
    SetWarpDestination(MAP_GROUP(LOMBARDSTREET),MAP_NUM(LOMBARDSTREET),NO_WARP_ID,15,11);

}
void JumpPlayerTo_GroupofAssholesAppears()
{
	JumpPlayerTo_ReadySetI();
	AddBagItem(ITEM_MACH_BIKE, 1);
	VarSet(VAR_GROUP_OF_ASSHOLES_STATE, PLAYER_HAS_DEFEATED_TEAMROCKET);
	IncrementStorylineVariable();
	FlagSet(TRAINER_FLAGS_START + TRAINER_IHSAN_AND_EMMITT);
    SetWarpDestination(MAP_GROUP(FISHERMANSWHARF),MAP_NUM(FISHERMANSWHARF),NO_WARP_ID,31,5);

}
void JumpPlayerTo_FlyingBlind()
{
	JumpPlayerTo_ReadySetI();
	VarSet(VAR_FAINTED_FOG_STATE, LEARNED_ABOUT_FOG);
	SetWarpDestination(MAP_GROUP(PSFROUTE1), MAP_NUM(PSFROUTE1), NO_WARP_ID, 79, 15);

}
void JumpPlayerTo_WowYoureStrong()
{
	JumpPlayerTo_EnterWhitney();
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_WOW_YOURE_STRONG);
    SetWarpDestination(MAP_GROUP(SOMA),MAP_NUM(SOMA),8, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_TheGangsAllHere()
{
	JumpPlayerTo_WowYoureStrong();
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_THE_GANGS_ALL_HERE);
	IncrementStorylineVariable();
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 5, 53);

}
void JumpPlayerTo_AlwaysWatchingWazokwski()
{
	JumpPlayerTo_WowYoureStrong();
	VarSet(VAR_SALESFORCETOWER_PRODUCTION_STATE,
	       POST_ALWAYS_WATCHING_WAZOWSKI);
    SetWarpDestination(MAP_GROUP(SALESFORCETOWER_PRODUCTION),MAP_NUM(SALESFORCETOWER_PRODUCTION),NO_WARP_ID,9,7);

}
void JumpPlayerTo_EnterAriana()
{
	JumpPlayerTo_ReadySetI();
	AddBagItem(ITEM_MEGA_RING, 1);
    SetWarpDestination(MAP_GROUP(TENDERLOIN),MAP_NUM(TENDERLOIN),NO_WARP_ID,2,40);

}
void JumpPlayerTo_HowDoWeGetHome()
{
	JumpPlayerTo_ReadySetI();
	VarSet(VAR_DOGPATCH_STATE, POST_HOW_DO_WE_GET_HOME);
	IncrementStorylineVariable();
    SetWarpDestination(MAP_GROUP(DOGPATCH),MAP_NUM(DOGPATCH),NO_WARP_ID,11,21);
}

void JumpPlayerTo_AaandWereBack()
{
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
	VarSet(VAR_STORYLINE_STATE, STORY_FERRY_FIXED);
	VarSet(VAR_PLAYER_HOME_STATE, FINISHED_1_1);
    SetWarpDestination(MAP_GROUP(SOUTHBAY),MAP_NUM(SOUTHBAY),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_AssholesHome()
{
	JumpPlayerTo_AaandWereBack();
	VarSet(VAR_ALAMEDA_STATE, DEFEATED_ARCHER_ALAMEDA);
	VarSet(VAR_STORYLINE_STATE, STORY_DEFEAT_ARCHER_ALAMEDA);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_ASSHOLEHOME);
    SetWarpDestination(MAP_GROUP(ALAMEDA),MAP_NUM(ALAMEDA),NO_WARP_ID,20,5);
}
void JumpPlayerTo_HousingProtest()
{
	JumpPlayerTo_AssholesHome();
	VarSet(VAR_STORYLINE_STATE, STORY_DEFEAT_BERKELEY_PROTEST);
	VarSet(VAR_PSFROUTE63_STATE, DEFEATED_TEAMROCKET_PSFROUTE63);
	FlagSet(TRAINER_FLAGS_START + TRAINER_HOUSINGPROTEST_ROCKET);
	SetWarpDestination(0, 28, NO_WARP_ID, 7, 14);
    SetWarpDestination(MAP_GROUP(PSFROUTE63),MAP_NUM(PSFROUTE63),NO_WARP_ID,7,14);
}
void JumpPlayerTo_swagbag2()
{
	JumpPlayerTo_HousingProtest();
	VarSet(VAR_BERKELEY_STATE, SWAGBAG_2_COMPLETE);
    SetWarpDestination(MAP_GROUP(BERKELEY),MAP_NUM(BERKELEY),NO_WARP_ID,4,13);
}
void JumpPlayerTo_EnterMorty()
{
	JumpPlayerTo_swagbag2();
	AddBagItem(ITEM_TM04, 1);
	FlagSet(FLAG_CONSTRUCTION_BREAKING_NEWS);
	FlagSet(FLAG_BADGE04_GET);
	FlagSet(TRAINER_FLAGS_START + TRAINER_MORTY);
	VarSet(VAR_MORTY_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_GYM_4_STATE, GYM_DEFEATED_LEADER);
	VarSet(VAR_BERKELEY_STATE, DEFEATED_MORTY);
	VarSet(VAR_STORYLINE_STATE, STORY_DEFEAT_MORTY);
    SetWarpDestination(MAP_GROUP(BERKELEY_GYM),MAP_NUM(BERKELEY_GYM),0,USE_WARP_ID,USE_WARP_ID);

}
void JumpPlayerTo_SorryAboutMyFriends()
{
	JumpPlayerTo_EnterMorty();
	VarSet(VAR_BERKELEY_STATE, GOT_ALCATRAZ_TICKET);
	VarSet(VAR_FERRY_STATE, FERRY_ALCATRAZ_AVAILABLE);
	AddBagItem(ITEM_MYSTIC_TICKET, 1);
    SetWarpDestination(MAP_GROUP(BERKELEY),MAP_NUM(BERKELEY),0,USE_WARP_ID,USE_WARP_ID);
}


// The script on Alcatraz makes it so if you talk to the attendant, your progress variable gets reset unless you're done. Rather than fix the story jump here, the better solution is just to code a debug way to trigger completion of all the Trainers.
/*
void JumpPlayerTo_TheStorySoFar(){
    JumpPlayerTo_SorryAboutMyFriends();
    FlagSet(TRAINER_FLAGS_START + TRAINER_ALBERTO);
    FlagSet(TRAINER_FLAGS_START + TRAINER_ED);
    FlagSet(TRAINER_FLAGS_START + TRAINER_DECLAN);
    FlagSet(TRAINER_FLAGS_START + TRAINER_FREDRICK);
    FlagSet(TRAINER_FLAGS_START + TRAINER_ZANDER);
    FlagSet(TRAINER_FLAGS_START + TRAINER_LEAH);
    VarSet(VAR_ALCATRAZ_EXHIBIT_STATE,ALCATRAZ_EXHIBIT_FINISH);
    SetWarpDestination(0,30,NO_WARP_ID,37,59);
}
*/

void JumpPlayerTo_YoungPadawan()
{
	u8 storyline = VarGet(VAR_STORYLINE_STATE);
	JumpPlayerTo_SorryAboutMyFriends();
	PreventVariableFromReversion(VAR_STORYLINE_STATE, storyline,
	                             STORY_COMPLETE_ALCATRAZ);
	VarSet(VAR_ALCATRAZ_STATE, BATTLED_MALVA);
	VarSet(VAR_ALCATRAZ_EXHIBIT_STATE, ALCATRAZ_EXHIBIT_COMPLETE);
	AddBagItem(ITEM_GO_GOGGLES, 1);
	AddBagItem(ITEM_MACHO_BRACE, 1);
    SetWarpDestination(MAP_GROUP(ALCATRAZ),MAP_NUM(ALCATRAZ),NO_WARP_ID,37,59);
}

void JumpPlayerTo_WaitYouWentWhere()
{
	JumpPlayerTo_YoungPadawan();
	VarSet(VAR_WAIT_YOU_WENT_WHERE, POST_WAITYOUWENTWHERE);
    SetWarpDestination(MAP_GROUP(PSFROUTE19),MAP_NUM(PSFROUTE19),NO_WARP_ID,3,1);
}
void JumpPlayerTo_EnterChuck()
{
	JumpPlayerTo_YoungPadawan();
	IncrementStorylineVariable();
	AddBagItem(ITEM_TM05, 1);
	FlagSet(FLAG_BADGE05_GET);
	VarSet(VAR_GYM_5_STATE, GYM_DEFEATED_LEADER);
	VarSet(VAR_CHUCK_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_FORTPOINT_STATE, DEFEATED_CHUCK);
	FlagSet(TRAINER_FLAGS_START + TRAINER_CHUCK);
	SetWarpDestination(MAP_GROUP(FORTPOINT_ROOF),MAP_NUM(FORTPOINT_ROOF), 0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_YouLookTired()
{
	JumpPlayerTo_EnterChuck();
	VarSet(VAR_FORTPOINT_STATE, MET_KOGA_OUTSIDE_GYM);
	SetWarpDestination(MAP_GROUP(FORTPOINT), MAP_NUM(FORTPOINT), 0, USE_WARP_ID, USE_WARP_ID);
}

void JumpPlayerTo_Kogasraisondetre()
{
	JumpPlayerTo_YouLookTired();
	IncrementStorylineVariable();
	VarSet(VAR_KOGA_RAISON_DETRE_STATE, POST_KOGA_RAISON_DETRE);
	VarSet(VAR_KOGA_MANSION_STATE, FINISHED_KOGA_RAISON);
    SetWarpDestination(MAP_GROUP(PRESIDIO),MAP_NUM(PRESIDIO),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_BeachBattle()
{
	JumpPlayerTo_YoungPadawan();
	IncrementStorylineVariable();
	VarSet(VAR_BEACH_BATTLE_STATE, POST_BEACH_BATTLE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BIANCA_BEACHBATTLE);
	SetWarpDestination(MAP_GROUP(PACIFICA), MAP_NUM(PACIFICA), NO_WARP_ID, 10, 23);
}
void JumpPlayerTo_EnterJasmine()
{
	JumpPlayerTo_YoungPadawan();
	IncrementStorylineVariable();
	AddBagItem(ITEM_TM06, 1);
	FlagSet(FLAG_BADGE06_GET);
	VarSet(VAR_GYM_6_STATE, GYM_DEFEATED_LEADER);
	VarSet(VAR_JASMINE_STATE, BATTLE_1_COMPLETE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_JASMINE);
	SetWarpDestination(MAP_GROUP(GLDNGTEPARK_GYM), MAP_NUM(GLDNGTEPARK_GYM),2, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_ANewStrike()
{
	JumpPlayerTo_YoungPadawan();
	FlagClear(FLAG_CONSTRUCTION_BREAKING_NEWS);
}
void JumpPlayerTo_AndWeMarchOn()
{
	JumpPlayerTo_YoungPadawan();
	VarSet(VAR_HAIGHTASHBURY_STATE, PARADE_COMPLETE);
	SetWarpDestination(MAP_GROUP(HAIGHTASHBURY),MAP_NUM(HAIGHTASHBURY),NO_WARP_ID, 23, 7);
}
void JumpPlayerTo_EnterPryce()
{
	JumpPlayerTo_AndWeMarchOn();
	IncrementStorylineVariable();
	AddBagItem(ITEM_TM07, 1);
	FlagSet(FLAG_BADGE07_GET);
	VarSet(VAR_PRYCE_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_GYM_7_STATE, GYM_DEFEATED_LEADER);
	FlagSet(TRAINER_FLAGS_START + TRAINER_PRYCE);
	SetWarpDestination(MAP_GROUP(HAIGHTASHBURY_GYM_LOBBY), MAP_NUM(HAIGHTASHBURY_GYM_LOBBY), 1, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_Battle8()
{
	JumpPlayerTo_YoungPadawan();
	IncrementStorylineVariable();
	VarSet(VAR_BATTLE_8_STATE, DEFEATED_ARCHER_PAINTEDLADIES);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_BATTLE8);
    SetWarpDestination(MAP_GROUP(PAINTEDLADIES),MAP_NUM(PAINTEDLADIES),NO_WARP_ID,19,16);
}
void JumpPlayerTo_EnterClair()
{
	JumpPlayerTo_YoungPadawan();
	IncrementStorylineVariable();
	AddBagItem(ITEM_TM08, 1);
	FlagSet(FLAG_BADGE08_GET);
	VarSet(VAR_CLAIR_STATE, BATTLE_1_COMPLETE);
	VarSet(VAR_GYM_8_STATE, GYM_DEFEATED_LEADER);
	FlagSet(TRAINER_FLAGS_START + TRAINER_JUAN_1);
    SetWarpDestination(MAP_GROUP(CASTRO_GYM),MAP_NUM(CASTRO_GYM),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_TheStrikeStrikesBack()
{
	JumpPlayerTo_Kogasraisondetre();
	JumpPlayerTo_BeachBattle();
	JumpPlayerTo_EnterJasmine();
	JumpPlayerTo_ANewStrike();
	JumpPlayerTo_EnterPryce();
	JumpPlayerTo_Battle8();
	JumpPlayerTo_EnterClair();
	JumpPlayerTo_ANewStrike();
	VarSet(VAR_CONSTRUCTION_STRIKE_STATE, START_VS_GARBODOR);
	VarSet(VAR_STORYLINE_STATE, STORY_CALLED_TO_CONSTRUCTION);
    SetWarpDestination(MAP_GROUP(PSFROUTE22),MAP_NUM(PSFROUTE22),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_VSGarbodor()
{
	JumpPlayerTo_TheStrikeStrikesBack();
	VarSet(VAR_CONSTRUCTION_STRIKE_STATE, TEAMROCKET_ARRESTED);
	VarSet(VAR_INNER_CONSTRUCTION_SITE_STATE, PLAYER_LEFT_SIDE);
	FlagSet(FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY);
	FlagSet(FLAG_DEFEATED_RIVAL_ROUTE_104);
	FlagSet(FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE);
	FlagSet(FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE);
	VarSet(VAR_STORYLINE_STATE, STORY_NEED_SLEEP_BEFORE_SIEBOLD);
    SetWarpDestination(MAP_GROUP(SOUTHBAY_COMPOUND_1F),MAP_NUM(SOUTHBAY_COMPOUND_1F),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_OffYouGo()
{
	JumpPlayerTo_VSGarbodor();
	VarSet(VAR_GOLDENGATEBRIDGE_STATE, POST_OFF_YOU_GO);
	VarSet(VAR_STORYLINE_STATE, STORY_ASSIGNED_SIEBOLD_QUESTS);
	VarSet(VAR_ROBINWILLIAMSTUNNEL_STATE, BIANCA_INSIDE_TUNNEL);
    SetWarpDestination(MAP_GROUP(GLDNGTEBRIDGE),MAP_NUM(GLDNGTEBRIDGE),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_IGuessWeShouldBeNiceNow()
{
	JumpPlayerTo_OffYouGo();
	VarSet(VAR_MUIRWOODS_STATE, BIANCA_WAITING_MUIRWOODS);
	VarSet(VAR_MARIN_STATE, BIANCA_INVITED_AIRBNB);
	VarSet(VAR_ROBINWILLIAMSTUNNEL_STATE, SIEBOLD_BOSS_DEFEATED);
    SetWarpDestination(MAP_GROUP(MARIN),MAP_NUM(MARIN),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_EntertheMaster()
{
	JumpPlayerTo_IGuessWeShouldBeNiceNow();
	VarSet(VAR_MUIRWOODS_STATE, MET_SIEBOLD);
	QuestMenu_GetSetQuestState(QUEST_SIEBOLDSTRAINING, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_SIEBOLDSTRAINING, FLAG_SET_ACTIVE);
    SetWarpDestination(MAP_GROUP(MUIRWOODS_INNER),MAP_NUM(MUIRWOODS_INNER),2,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_HaveYouSeenTheNews()
{
	JumpPlayerTo_EntertheMaster();
	VarSet(VAR_MUIRWOODS_STATE, POST_HAVE_YOU_SEEN_THE_NEWS);
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_WELCOME_TO_THE_WAR_ROOM);
    Quest_Generic_CompleteSubquests(QUEST_SIEBOLDSTRAINING);
	QuestMenu_GetSetQuestState(QUEST_SIEBOLDSTRAINING, FLAG_REMOVE_ACTIVE);
	QuestMenu_GetSetQuestState(QUEST_SIEBOLDSTRAINING, FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(MUIRWOODS_INNER),MAP_NUM(MUIRWOODS_INNER),1,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_WelcometotheWarRoom()
{
	JumpPlayerTo_HaveYouSeenTheNews();
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,
	       POST_WELCOME_TO_THE_WAR_ROOM);
	VarSet(VAR_FERRYBUILDING_STATE, CHIEF_LEFT_WAR_ROOM);
    SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS),MAP_NUM(SALESFORCETOWER_LEAGUEOPS),NO_WARP_ID,17,29);
}
void JumpPlayerTo_SurvivalChance333()
{
	JumpPlayerTo_WelcometotheWarRoom();
	VarSet(VAR_ALAMEDA_STATE, POST_SURVIVAL_CHANCE);
	VarSet(VAR_FERRYBUILDING_STATE, DEFEATED_SURVIVAL_CHANCE_BATTLE);
    SetWarpDestination(MAP_GROUP(ALAMEDA),MAP_NUM(ALAMEDA),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_WhyAreYouHelpingThem()
{
	JumpPlayerTo_SurvivalChance333();
	VarSet(VAR_NAVALBASE_STATE, DEFEATED_ARCHER_NAVALBASE);
	VarSet(VAR_PLAYER_HOME_STATE, NEXT_DAY_CHAMPIONSHIP);
	VarSet(VAR_STORYLINE_STATE, STORY_COMPLETED_NAVAL_BASE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_WHYAREYOUHELPINGTHEM);
    SetWarpDestination(MAP_GROUP(PRESIDIO_COMPOUND_1F),MAP_NUM(PRESIDIO_COMPOUND_1F),NO_WARP_ID,11,4);
}

void JumpPlayerTo_WhyAreYouHelpingThemSleep()
{
	JumpPlayerTo_WhyAreYouHelpingThem();
	VarSet(VAR_STORYLINE_STATE, STORY_START_CHAMPIONSHIP);
	VarSet(VAR_ALAMEDA_STATE, SLEPT_AFTER_RAID);
    SetWarpDestination(MAP_GROUP(CHASECENTER_LOCKERS),MAP_NUM(CHASECENTER_LOCKERS),NO_WARP_ID,9,6);
}

void JumpPlayerTo_HeresHowThisIsGoingToGo()
{
	JumpPlayerTo_WhyAreYouHelpingThemSleep();
	VarSet(VAR_STORYLINE_STATE, STORY_CHAMPIONSHIP_EXPLAINED);
    SetWarpDestination(MAP_GROUP(CHASECENTER_LOCKERS),MAP_NUM(CHASECENTER_LOCKERS),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_WhyDidntYouRatMeOut()
{
	JumpPlayerTo_HeresHowThisIsGoingToGo();
	VarSet(VAR_STORYLINE_STATE, STORY_BIANCA_WON_GROUP);
	SetWarpDestination(MAP_GROUP(CHASECENTER_SKYBOX),MAP_NUM(CHASECENTER_SKYBOX),0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_GroupStages()
{
	JumpPlayerTo_WhyDidntYouRatMeOut();
	VarSet(VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_4);
	FlagSet(FLAG_CHASECENTER_TOURNAMENT_HAPPENING);
	VarSet(VAR_STORYLINE_STATE, STORY_GROUP_STATE_COMPLETE);
    SetWarpDestination(MAP_GROUP(CHASECENTER_LOCKERS),MAP_NUM(CHASECENTER_LOCKERS),NO_WARP_ID,10,3);
}
void JumpPlayerTo_Finals()
{
	JumpPlayerTo_GroupStages();
	VarSet(VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_5);
	VarSet(VAR_STORYLINE_STATE, STORY_SEMIFINAL_COMPLETE);
    SetWarpDestination(MAP_GROUP(CHASECENTER_LOCKERS),MAP_NUM(CHASECENTER_LOCKERS),NO_WARP_ID,10,3);
}
void JumpPlayerTo_WaitHeDidWhat()
{
	JumpPlayerTo_Finals();
	VarSet(VAR_STORYLINE_STATE, STORY_READY_FINALS);
    SetWarpDestination(MAP_GROUP(CHASECENTER_SKYBOX),MAP_NUM(CHASECENTER_SKYBOX),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_WelcometotheHallofFame()
{
	JumpPlayerTo_WaitHeDidWhat();
	VarSet(VAR_CHASECENTER_TOURNAMENT_STATE, NO_TOURNAMENT);
	VarSet(VAR_STORYLINE_STATE, STORY_WON_FINALS);
	FlagClear(FLAG_CHASECENTER_TOURNAMENT_HAPPENING);
	FlagSet(FLAG_IS_CHAMPION);
	FlagSet(FLAG_SYS_GAME_CLEAR);
	HealPlayerParty();
    SetWarpDestination(MAP_GROUP(PRESIDIO_COMPOUND_1F),MAP_NUM(PRESIDIO_COMPOUND_1F),NO_WARP_ID,11,4);
}
void JumpPlayerTo_BeingChampionisHard()
{
	JumpPlayerTo_WelcometotheHallofFame();
	VarSet(VAR_STORYLINE_STATE, STORY_EXPLORE_TREASUREISLAND);
    SetWarpDestination(MAP_GROUP(PRESIDIO_COMPOUND_1F),MAP_NUM(PRESIDIO_COMPOUND_1F),NO_WARP_ID,7,9);
}
void JumpPlayerTo_LetsGrabLunch()
{
	JumpPlayerTo_BeingChampionisHard();
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_LETSGRABLUNCH);
	VarSet(VAR_STORYLINE_STATE, STORY_ARCHER_EXPLAIN_RESTORATION);
    SetWarpDestination(MAP_GROUP(TREASUREISLAND),MAP_NUM(TREASUREISLAND),NO_WARP_ID,14,9);
}
void JumpPlayerTo_RestoreChinatown()
{
	JumpPlayerTo_LetsGrabLunch();
	QuestMenu_GetSetQuestState(QUEST_RESTORECHINATOWN, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_RESTORECHINATOWN, FLAG_SET_COMPLETED);

	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_A);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_B);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_C);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_D);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_E);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_F);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BLACKBELT_G);

    Quest_Generic_CompleteSubquests(QUEST_RESTORECHINATOWN);
	VarSet(VAR_QUEST_RESTORECHINATOWN, RESTORECHINATOWN_COMPLETE);
    SetWarpDestination(MAP_GROUP(CHINATOWN_GYM),MAP_NUM(CHINATOWN_GYM),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_RestoreTreasureIsland()
{
	JumpPlayerTo_LetsGrabLunch();
	QuestMenu_GetSetQuestState(QUEST_RESTORETREASUREISLAND,
	                           FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_RESTORETREASUREISLAND);
	QuestMenu_GetSetQuestState(QUEST_RESTORETREASUREISLAND,
	                           FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(TREASUREISLAND),MAP_NUM(TREASUREISLAND),NO_WARP_ID,3,15);
}
void JumpPlayerTo_RestoreMarin()
{
    JumpPlayerTo_LetsGrabLunch();
    VarSet(VAR_QUEST_RESTOREMARIN, DEFEATED_LENORA);
    QuestMenu_GetSetQuestState(QUEST_RESTOREMARIN, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_RESTOREMARIN);
    QuestMenu_GetSetQuestState(QUEST_RESTOREMARIN, FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(MARIN),MAP_NUM(MARIN),NO_WARP_ID,8,18);
}
/*
void JumpPlayerTo_RestoreHaightAshbury()
{
	JumpPlayerTo_LetsGrabLunch();
	QuestMenu_GetSetQuestState(QUEST_RESTOREHAIGHTASHBURY, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_RESTOREHAIGHTASHBURY,
	                           FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(HAIGHTASHBURY_GYM),MAP_NUM(HAIGHTASHBURY_GYM),NO_WARP_ID,7,27);
}*/
void JumpPlayerTo_YouRealizeWereEvilRight()
{
    JumpPlayerTo_RestoreMarin();
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE,
	       POST_YOU_REALIZE_WERE_EVIL_RIGHT);
	FlagSet(FLAG_ARCHER_CALL_ALCATRAZ);
	VarSet(VAR_STORYLINE_STATE, STORY_POST_YOU_REALIZE_WERE_EVIL);
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 17, 29);
}
void JumpPlayerTo_YouRealizeTheyreEvilRight()
{
	JumpPlayerTo_YouRealizeWereEvilRight();
	VarSet(VAR_ALCATRAZ_STATE, POST_YOU_REALIZE_THEYRE_EVIL_RIGHT);
	FlagClear(FLAG_ARCHER_CALL_ALCATRAZ);
	SetWarpDestination(MAP_GROUP(PRESIDIO_COMPOUND_1F), MAP_NUM(PRESIDIO_COMPOUND_1F), 0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_CongratsYoureanAsshole()
{
	u8 storyline = VarGet(VAR_STORYLINE_STATE);

	JumpPlayerTo_YouRealizeTheyreEvilRight();
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, START_FALSE_TIMELINE);
	FlagSet(FLAG_TIMELINE_FALSE);
	PreventVariableFromReversion(VAR_STORYLINE_STATE, storyline,
	                             STORY_START_FALSE_TIMELINE);
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 17,29);
}
void JumpPlayerTo_YouHaveYourOrders()
{
	JumpPlayerTo_CongratsYoureanAsshole();
	QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING, FLAG_SET_UNLOCKED);
    if (!QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING,FLAG_GET_ACTIVE) == FLAG_GET_ACTIVE){
        QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING, FLAG_SET_ACTIVE);
    }
	VarSet(VAR_HOW_DISAPPOINTING_STATE, MISSION_ASSIGNED);
	SetWarpDestination(MAP_GROUP(CHINATOWN), MAP_NUM(CHINATOWN), NO_WARP_ID, 33, 8);
}
void JumpPlayerTo_HowDisappointing()
{
	JumpPlayerTo_YouHaveYourOrders();
	IncrementStorylineVariable();
	QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING, FLAG_SET_COMPLETED);
	VarSet(VAR_HOW_DISAPPOINTING_STATE, HOW_DISAPPOINTING_COMPLETE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARIANA_HOWDISAPPOINTING);
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 32,53);
}
void JumpPlayerTo_LetsBurnThisMotherDown()
{
	JumpPlayerTo_CongratsYoureanAsshole();
	QuestMenu_GetSetQuestState(QUEST_LETS_BURN_THIS_MOTHER_DOWN,
	                           FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_LETS_BURN_THIS_MOTHER_DOWN,
	                           FLAG_SET_COMPLETED);
	VarSet(VAR_LETS_BURN_THIS_MOTHER_STATE, BURN_MOTHER_COMPLETE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ARCHER_LETSBURNTHISMOTHERDOWN);
	IncrementStorylineVariable();
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 34,5);
}
void JumpPlayerTo_Manhunt()
{
	JumpPlayerTo_CongratsYoureanAsshole();
	QuestMenu_GetSetQuestState(QUEST_MANHUNT, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(QUEST_MANHUNT, FLAG_SET_COMPLETED);
	VarSet(VAR_MANHUNT_STATE, MANHUNT_COMPLETE);
	FlagSet(TRAINER_FLAGS_START + TRAINER_GIOVANNI);
	IncrementStorylineVariable();
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), NO_WARP_ID, 5,5);
}
void JumpPlayerTo_ExhibitionBattle()
{
	JumpPlayerTo_Manhunt();
	JumpPlayerTo_LetsGettheBandBackTogether();
	JumpPlayerTo_HowDisappointing();
	VarSet(VAR_STORYLINE_STATE, STORY_CONGRATULATED_BY_ROSE);
    SetWarpDestination(MAP_GROUP(CHASECENTER_LOCKERS),MAP_NUM(CHASECENTER_LOCKERS),2,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_MaybeIFuckedUp()
{
	JumpPlayerTo_ExhibitionBattle();
	VarSet(VAR_STORYLINE_STATE, STORY_RECIEVED_BAMBOO_STAR);
	AddBagItem(ITEM_METEORITE, 1);
    SetWarpDestination(MAP_GROUP(PSFROUTE22),MAP_NUM(PSFROUTE22),1,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_OkayLetsFixit()
{
	JumpPlayerTo_MaybeIFuckedUp();
	FlagSet(FLAG_TIMELINE_TIMETRAVEL);
	FlagClear(FLAG_TIMELINE_FALSE);
	VarSet(VAR_STORYLINE_STATE, STORY_MORNING_OF_TIMELINE_SPLIT);
	VarSet(VAR_MANHUNT_STATE, NOT_ASSIGNED);
	VarSet(VAR_HOW_DISAPPOINTING_STATE, NOT_ASSIGNED);
	VarSet(VAR_HOW_DISAPPOINTING_STATE, NOT_ASSIGNED);
    QuestMenu_GetSetQuestState(QUEST_MANHUNT,FLAG_REMOVE_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_HOW_DISAPPOINTING,FLAG_REMOVE_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_LETS_BURN_THIS_MOTHER_DOWN,FLAG_REMOVE_COMPLETED);
    RemoveBagItem(ITEM_METEORITE,1);
	SetWarpDestination(MAP_GROUP(PRESIDIO_COMPOUND_1F), MAP_NUM(PRESIDIO_COMPOUND_1F), 0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_LetsGettheBandBackTogether()
{
	JumpPlayerTo_YouRealizeTheyreEvilRight();
	VarSet(VAR_ALCATRAZ_STATE, START_TRUE_TIMELINE);
	VarSet(VAR_STORYLINE_STATE, STORY_START_TRUE_TIMELINE);
	FlagSet(FLAG_TIMELINE_TRUE);
	VarSet(VAR_MASK_OFF_STATE, ASSIGNED_MASK_OFF);
	SetWarpDestination(MAP_GROUP(ALCATRAZ_B2F),MAP_NUM(ALCATRAZ_B2F), 0, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_MaskOff()
{
	JumpPlayerTo_LetsGettheBandBackTogether();
	VarSet(VAR_MASK_OFF_STATE, DEFEATED_MASK_OFF_GIOVANNI);
	VarSet(VAR_STORYLINE_STATE, STORY_DEFEATED_GIOVANNI);
	FlagSet(TRAINER_FLAGS_START + TRAINER_GIOVANNI);
    SetWarpDestination(MAP_GROUP(LAKEMERRITT),MAP_NUM(LAKEMERRITT),NO_WARP_ID,22,26);
}
void JumpPlayerTo_LockedOut()
{
	JumpPlayerTo_MaskOff();
	FlagSet(FLAG_LOCKEDOUT_PLAYED);
    SetWarpDestination(MAP_GROUP(ALAMEDA_ARCHER_HOUSE),MAP_NUM(ALAMEDA_ARCHER_HOUSE),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_LetsFixThis()
{
	u8 storyline = VarGet(VAR_STORYLINE_STATE);
	u8 alcatrazState = VarGet(VAR_ALCATRAZ_STATE);
	u8 warehouseState = VarGet(VAR_WAREHOUSE_RAVE_STATE);

	JumpPlayerTo_LockedOut();
	PreventVariableFromReversion(VAR_STORYLINE_STATE, storyline,
	                             STORY_RECIVED_RAVE_INVITE);
	PreventVariableFromReversion(VAR_ALCATRAZ_STATE, alcatrazState,
	                             PRE_SPEECHSPEECH);
	PreventVariableFromReversion(VAR_WAREHOUSE_RAVE_STATE, warehouseState,
	                             GOT_RAVE_MESSAGE);
    SetWarpDestination(MAP_GROUP(ALAMEDA_ARCHER_HOUSE),MAP_NUM(ALAMEDA_ARCHER_HOUSE),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_WarehouseRave()
{
	JumpPlayerTo_LetsFixThis();
	IncrementStorylineVariable();
	VarSet(VAR_WAREHOUSE_RAVE_STATE, TOLD_ARCHER_ABOUT_KOGA);
    SetWarpDestination(MAP_GROUP(OAKLAND),MAP_NUM(OAKLAND),1,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_SpeechSpeechSpeech()
{
	JumpPlayerTo_LetsFixThis();
	IncrementStorylineVariable();
	VarSet(VAR_ALCATRAZ_STATE, POST_SPEECHSPEECH);
    SetWarpDestination(MAP_GROUP(ALCATRAZ_B2F),MAP_NUM(ALCATRAZ_B2F),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_Persuasivepassenger()
{
    JumpPlayerTo_SpeechSpeechSpeech();
    VarSet(VAR_QUEST_PERSUASIVE_PASSENGER_STATE,SAVED_BEFORE_UBER_CEO);
    VarSet(VAR_STORYLINE_STATE,STORY_1ST_TAKEDOWN);
    FlagSet(FLAG_QUEST_PERSUASIVE_SIBLING);
    FlagSet(FLAG_QUEST_PERSUASIVE_PASSENGER_PLAYER_KIDNAPPED);
    FlagSet(TRAINER_FLAGS_START + TRAINER_UBER_CEO);
	QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_PERSUASIVEPASSENGER);
	QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER, FLAG_SET_COMPLETED);
	QuestMenu_GetSetQuestState(QUEST_TAXICABTURNAROUND, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_TAXICABTURNAROUND);
	QuestMenu_GetSetQuestState(QUEST_TAXICABTURNAROUND, FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(UBER_HQ_FLOOR2),MAP_NUM(UBER_HQ_FLOOR2),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_Breaktheinternet()
{
    JumpPlayerTo_SpeechSpeechSpeech();
    VarSet(VAR_QUEST_BREAKTHEINTERNET_STATE,SAVED_BEFORE_TWITTER_CEO);
    VarSet(VAR_STORYLINE_STATE,STORY_1ST_TAKEDOWN);
    FlagSet(TRAINER_FLAGS_START + TRAINER_TWITTER6);
    FlagSet(TRAINER_FLAGS_START + TRAINER_TWITTER_CEO);

    QuestMenu_GetSetQuestState(QUEST_RABIESOUTBREAK,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_BLUEROBBERRY,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_ICECREAMCRAFTING,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_VSDEOXYS,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_CHINATOWNTUNNELS,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_FRESHWATEREVOLUTION,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_GEMARTIST,FLAG_SET_UNLOCKED);
    QuestMenu_GetSetQuestState(QUEST_BETWEENASTONEANDAHARD,FLAG_SET_UNLOCKED);

    QuestMenu_GetSetQuestState(QUEST_RABIESOUTBREAK,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_BLUEROBBERRY,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_ICECREAMCRAFTING,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_VSDEOXYS,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_CHINATOWNTUNNELS,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_FRESHWATEREVOLUTION,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_GEMARTIST,FLAG_SET_COMPLETED);
    QuestMenu_GetSetQuestState(QUEST_BETWEENASTONEANDAHARD,FLAG_SET_COMPLETED);

    QuestMenu_GetSetQuestState(QUEST_BREAKTHEINTERNET, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_BREAKTHEINTERNET);
    QuestMenu_GetSetQuestState(QUEST_BREAKTHEINTERNET, FLAG_SET_COMPLETED);
    SetWarpDestination(MAP_GROUP(FAKENEWS_WAREHOUSE),MAP_NUM(FAKENEWS_WAREHOUSE),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_Warehousewarfare()
{
    JumpPlayerTo_SpeechSpeechSpeech();
    VarSet(VAR_QUEST_WAREHOUSEWARFARE_STATE,SAVED_BEFORE_AMAZON_CEO);
    VarSet(VAR_STORYLINE_STATE,STORY_1ST_TAKEDOWN);
    FlagSet(FLAG_QUEST_WAREHOUSE_WARFARE_EXPLAINED);
    FlagSet(FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_WORKERS_CLEAR);
    FlagSet(FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_ENGINE_CLEAR);
    FlagSet(FLAG_QUEST_WAREHOUSEWARFARE_BARGE3_ENGINE_CLEAR);
    FlagSet(TRAINER_FLAGS_START + TRAINER_AMAZON_CEO);

	QuestMenu_GetSetQuestState(QUEST_WAREHOUSEWARFARE, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_WAREHOUSEWARFARE);
	QuestMenu_GetSetQuestState(QUEST_WAREHOUSEWARFARE, FLAG_SET_COMPLETED);

	QuestMenu_GetSetQuestState(QUEST_BODEGABURNOUT, FLAG_SET_UNLOCKED);
    Quest_Generic_CompleteSubquests(QUEST_BODEGABURNOUT);
	QuestMenu_GetSetQuestState(QUEST_BODEGABURNOUT, FLAG_SET_COMPLETED);

    SetWarpDestination(MAP_GROUP(AMAZON_BARGE_3),MAP_NUM(AMAZON_BARGE_3),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_OneDown()
{
	JumpPlayerTo_SpeechSpeechSpeech();
	JumpPlayerTo_WarehouseRave();
	VarSet(VAR_STORYLINE_STATE, STORY_PRE_EARTHQUAKE);
    SetWarpDestination(MAP_GROUP(ALCATRAZ_B2F),MAP_NUM(ALCATRAZ_B2F),0,USE_WARP_ID,USE_WARP_ID);
}
void JumpPlayerTo_Earthquake()
{
	JumpPlayerTo_OneDown();
	VarSet(VAR_ALAMEDA_STATE, MEET_AT_PSFROUTE8);
	VarSet(VAR_STORYLINE_STATE, STORY_POST_EARTHQUAKE);
    SetWarpDestination(MAP_GROUP(ALAMEDA),MAP_NUM(ALAMEDA),NO_WARP_ID,11,17);
}
void JumpPlayerTo_ThisIsntRandom()
{
	JumpPlayerTo_Earthquake();
	VarSet(VAR_UNDERGROUNDLAB_STATE, FREED_LAB_POKEMON_2);
    SetWarpDestination(MAP_GROUP(UNDERGROUNDLAB),MAP_NUM(UNDERGROUNDLAB),NO_WARP_ID,24,4);
}
void JumpPlayerTo_WaitEvenThen()
{
	JumpPlayerTo_ThisIsntRandom();
	VarSet(VAR_UNDERGROUNDLAB_STATE, DEFEATED_DYNAMAX);
	VarSet(VAR_ALAMEDA_STATE, POST_THIS_ISNT_RANDOM);
	VarSet(VAR_STORYLINE_STATE, STORY_POST_DYNAMAX_BOSS);
    SetWarpDestination(MAP_GROUP(ALAMEDA),MAP_NUM(ALAMEDA),NO_WARP_ID,32,13);
}
void JumpPlayerTo_LetsFinishThis()
{
	JumpPlayerTo_WaitEvenThen();
	VarSet(VAR_STORYLINE_STATE, STORY_BEFORE_SABRINA_BREAKIN);
    SetWarpDestination(MAP_GROUP(SUNSET),MAP_NUM(SUNSET),NO_WARP_ID,13,19);
}
void JumpPlayerTo_ImIn()
{
	JumpPlayerTo_LetsFinishThis();
	VarSet(VAR_STORYLINE_STATE, STORY_WARP_TILE_ACCESSIBLE);
	VarSet(VAR_SALESFORCETOWER_CONFERENCE_STATE, TRUE_RAID_START);
	VarSet(VAR_TOWER_RAID_STATE, DEFEATED_BIANCA_SALESFORCETOWER);
	AddBagItem(ITEM_MAGMA_EMBLEM, 1);
	FlagSet(TRAINER_FLAGS_START + TRAINER_BIANCA_IMIN);
	SetWarpDestination(MAP_GROUP(SALESFORCETOWER_LEAGUEOPS), MAP_NUM(SALESFORCETOWER_LEAGUEOPS), 1, USE_WARP_ID, USE_WARP_ID);
}
void JumpPlayerTo_YouCantStopMe()
{
	JumpPlayerTo_ImIn();
	VarSet(VAR_TOWER_RAID_STATE, SAVE_ROSE_SALESFORCETOWER);
    SetWarpDestination(MAP_GROUP(SALESFORCETOWER_TOP),MAP_NUM(SALESFORCETOWER_TOP),NO_WARP_ID,15,6);
}
void JumpPlayerTo_WeCanStopYouActually()
{
	JumpPlayerTo_YouCantStopMe();
	VarSet(VAR_STORYLINE_STATE, STORY_CLEAR);
	VarSet(VAR_TOWER_RAID_STATE, DEFEATED_ROSE_SALESFORCETOWER);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ROSE_A);
	FlagSet(TRAINER_FLAGS_START + TRAINER_ROSE_B);
    SetWarpDestination(MAP_GROUP(ALAMEDA_ARCHER_HOUSE),MAP_NUM(ALAMEDA_ARCHER_HOUSE),0,USE_WARP_ID,USE_WARP_ID);
}
