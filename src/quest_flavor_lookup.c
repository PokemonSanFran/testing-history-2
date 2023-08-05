#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"
#include "quest_strings.h"
#include "battle_main.h"

#include "random.h"

//PSF TODO we should rewrite this whole function to be cleaner
//PSF TODO need to make sure we can reflect the quest states of the takedown quests and the false timeline quests

//PSF TODO for eastern and western SF portions, we should show an objective that you haven't completed... maybe randomly choose every time you open?

const u8 *GetQuestDesc_PlayersAdventure()
{
    u8 storyline = VarGet(VAR_STORYLINE_STATE);

    switch (storyline)
    {
        case STORY_CLEAR:
            return gText_PlayersAdventure_Flavor42;
        case STORY_WARP_TILE_ACCESSIBLE:
            return gText_PlayersAdventure_Flavor41;
        case STORY_BEFORE_SABRINA_BREAKIN:
            return gText_PlayersAdventure_Flavor40;
        case STORY_POST_DYNAMAX_BOSS:
            return gText_PlayersAdventure_Flavor39;
        case STORY_POST_EARTHQUAKE:
            if (VarGet(VAR_UNDERGROUNDLAB_STATE) <= SAVE_BEFORE_DYNAMAX)
                return gText_PlayersAdventure_Flavor38A;
            else
                return gText_PlayersAdventure_Flavor38;
        case STORY_PRE_EARTHQUAKE:
            if (VarGet(VAR_ALAMEDA_STATE) >= POST_EARTHQUAKE)
                return gText_PlayersAdventure_Flavor37A;
            else
                return gText_PlayersAdventure_Flavor37;
        case STORY_1ST_TAKEDOWN:
            return gText_PlayersAdventure_Flavor36A;
        case STORY_RAVE_AND_SPEECH_COMPLETE:
            return gText_PlayersAdventure_Flavor36;
        case STORY_RAVE_OR_SPEECH_COMPLETE:
            if (VarGet(VAR_WAREHOUSE_RAVE_STATE) >= TOLD_ARCHER_ABOUT_KOGA)
                return gText_PlayersAdventure_Flavor35A;
            else if (VarGet(VAR_ALCATRAZ_STATE) >= POST_SPEECHSPEECH)
                return gText_PlayersAdventure_Flavor35B;
            else
                return gText_PlayersAdventure_Flavor35;
        case STORY_RECIVED_RAVE_INVITE:
            return gText_PlayersAdventure_Flavor35;
        case STORY_START_TRUE_TIMELINE:
            return gText_PlayersAdventure_Flavor34;
        case STORY_POST_DIANTHA:
            return gText_PlayersAdventure_Flavor32;
        case STORY_SAVE_DIANTHA:
            return gText_PlayersAdventure_Flavor31;
        case STORY_TEAMROCKET_FINISHED:
            return gText_PlayersAdventure_Flavor30;
        case STORY_MORNING_OF_TIMELINE_SPLIT:
            if (FlagGet(FLAG_TIMELINE_TIMETRAVEL))
                return gText_PlayersAdventure_Flavor28;
            else
                return gText_PlayersAdventure_Flavor27;
        case STORY_POST_YOU_REALIZE_WERE_EVIL:
            if (VarGet(VAR_ALCATRAZ_STATE) >= POST_YOU_REALIZE_THEYRE_EVIL_RIGHT)
                return gText_PlayersAdventure_Flavor26;
            else if (VarGet(VAR_ALCATRAZ_STATE) < ARCHER_SUMMONED_ALCATRAZ)
                return gText_PlayersAdventure_Flavor26;
            else
                return gText_PlayersAdventure_Flavor25;
        case STORY_ARCHER_EXPLAIN_RESTORATION:
            return gText_PlayersAdventure_Flavor23;
        case STORY_POST_BATTLE_ARCHER_TREASUREISLAND:
            return gText_PlayersAdventure_Flavor22;
        case STORY_SAVE_ARCHER_TREASUREISLAND:
            return gText_PlayersAdventure_Flavor21;
        case STORY_EXPLORE_TREASUREISLAND:
            return gText_PlayersAdventure_Flavor20;
        case STORY_WON_FINALS:
            return gText_PlayersAdventure_Flavor19;
        case STORY_READY_FINALS:
            return gText_PlayersAdventure_Flavor18;
        case STORY_WATCH_SEMIFINAL:
            return gText_PlayersAdventure_Flavor17;
        case STORY_GROUP_STATE_COMPLETE:
            return gText_PlayersAdventure_Flavor16;
        case STORY_CHAMPIONSHIP_EXPLAINED:
            return gText_PlayersAdventure_Flavor14;
        case STORY_START_CHAMPIONSHIP:
            return gText_PlayersAdventure_Flavor13;
        case STORY_COMPLETED_NAVAL_BASE:
            return gText_PlayersAdventure_Flavor12;
        case STORY_ASSIGNED_SIEBOLD_QUESTS:
            if (VarGet(VAR_SALESFORCETOWER_CONFERENCE_STATE) > PRE_WELCOME_TO_THE_WAR_ROOM)
                return gText_PlayersAdventure_Flavor11;
            else if (VarGet(VAR_MUIRWOODS_STATE) == POST_HAVE_YOU_SEEN_THE_NEWS)
                return gText_PlayersAdventure_HeadToSalesforce;
            else if (VarGet(VAR_MUIRWOODS_STATE) > MUIRWOODS_MAZE_COMPLETE)
                return gText_PlayersAdventure_Flavor10;
            else if (VarGet(VAR_GOLDENGATEBRIDGE_STATE) > CALLED_BY_BIANCA)
                return gText_PlayersAdventure_Flavor9_B;
            else if (VarGet(VAR_GOLDENGATEBRIDGE_STATE) == CALLED_BY_BIANCA)
                return gText_PlayersAdventure_Flavor9_A;
            else
                return gText_PlayersAdventure_Flavor9;
        case STORY_NEED_SLEEP_BEFORE_SIEBOLD:
            return gText_PlayersAdventure_Flavor9;
        case STORY_CALLED_TO_CONSTRUCTION:
            if (VarGet(VAR_CONSTRUCTION_STRIKE_STATE) == START_VS_GARBODOR)
                return gText_PlayersAdventure_Flavor8;
            else
                return gText_PlayersAdventure_Flavor7;
        case STORY_DEFEAT_MORTY:
            if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1))
                return gText_PlayersAdventure_Flavor5;
            else
                return gText_PlayersAdventure_Flavor4;
        case STORY_FERRY_FIXED:
            return gText_PlayersAdventure_Flavor3;
        case STORY_WEST_SANFRAN_COMPLETE:
            return gText_PlayersAdventure_Flavor2;
        case STORY_WEST_SANFRAN_ONLY:
            if (VarGet(VAR_PLAYER_HOME_STATE) > POST_SWAGBAG)
            {
                return gText_PlayersAdventure_Flavor1;
            }
            else if (VarGet(VAR_PROLOGUE_STATE) == START_ADVENTURE)
            {
                return gText_PlayersAdventure_Flavor0;
            }
            else if (VarGet(VAR_PROLOGUE_STATE) == WIKSTROM_ANNOUNCE)
            {
                return gText_ChampionsAdventure_Flavor3;
            }
            else if (VarGet(VAR_PROLOGUE_STATE) > LOST_TO_DRASNA)
            {
                return gText_ChampionsAdventure_Flavor2;
            }
            else if (VarGet(VAR_PROLOGUE_STATE) > NOT_STARTED)
            {
                return gText_Quest_BecomeChampion_Desc;
            }
            else
                return gText_Quest_PlayersAdventure_Desc;
        default:
            if (storyline > 0)
            {
                return gText_PlayersAdventure_Flavor1;
            }
    }
}

const u8 *GetQuestDoneDesc_PlayersAdventure()
{
	if (!FlagGet(FLAG_TIMELINE_TIMETRAVEL))
	{
		return gText_PlayersAdventure_Flavor43;
	}
	else
	{
		return gText_PlayersAdventure_Flavor42;
	}
}

const u8 *GetQuestDesc_BringFruit()
{
	u8 berryCount = 0, i = 0;

	for (i = 0; i < 7; i++)
		if (CheckBagHasItem(ITEM_WATMEL_BERRY, i))
		{
			berryCount = i;
		}

	ConvertIntToDecimalStringN(gStringVar3, berryCount,
	                           STR_CONV_MODE_LEFT_ALIGN, 6);
	StringExpandPlaceholders(gStringVar2, gText_Quest_BringFruit_Desc);

	return gStringVar2;
}

const u8 *GetQuestDesc_RabiesOutbreak()
{
	u8 defeatedGlameowCount = VarGet(VAR_DEFEATED_GLAMEOW_COUNT);

	ConvertIntToDecimalStringN(gStringVar3, 10 - defeatedGlameowCount,
	                           STR_CONV_MODE_LEFT_ALIGN, 6);
	StringExpandPlaceholders(gStringVar2, gText_RabiesOutbreak_Flavor1);
	return gStringVar2;
}

const u8  *GetQuestDesc_BetweenAStoneAndAHardPlace()
{
    u8 goalNumTrolleyRides = 10;
    u8 numTrolleyRides = GetGameStat(GAME_STAT_TROLLEY_RIDES);
    u8 numRemainingTrolleyRides = (goalNumTrolleyRides - numTrolleyRides);

    ConvertIntToDecimalStringN(gStringVar3,
            numRemainingTrolleyRides,
            STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar2,
            gText_BetweenAStoneAndAHardPlace_Flavor1);
    return gStringVar2;
}
