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

const u8 *GetQuestDesc_PlayersAdventure()
{
	u8 storyline = VarGet(VAR_STORYLINE_STATE);

	if (storyline == STORY_WARP_TILE_ACCESSIBLE)
	{
		return gText_PlayersAdventure_Flavor41;
	}

	else if (storyline == STORY_BEFORE_SABRINA_BREAKIN)
	{
		return gText_PlayersAdventure_Flavor40;
	}

	else if (storyline == STORY_POST_DYNAMAX_BOSS)
	{
		return gText_PlayersAdventure_Flavor39;
	}

	else if (storyline == STORY_POST_EARTHQUAKE)
	{
		return gText_PlayersAdventure_Flavor38;
	}

	else if (storyline == STORY_PRE_EARTHQUAKE
	            && (VarGet(VAR_ALAMEDA_STATE) >= POST_EARTHQUAKE))
	{
		return gText_PlayersAdventure_Flavor37A;
	}


	else if (storyline == STORY_PRE_EARTHQUAKE)
	{
		return gText_PlayersAdventure_Flavor37;
	}

	else if (storyline == STORY_RAVE_AND_SPEECH_COMPLETE)
	{
		return gText_PlayersAdventure_Flavor36;
	}

	else if (storyline == STORY_RAVE_OR_SPEECH_COMPLETE 
	            && (VarGet(VAR_WAREHOUSE_RAVE_STATE) >= TOLD_ARCHER_ABOUT_KOGA))
    {
        return gText_PlayersAdventure_Flavor35A;
    }

	else if (storyline == STORY_RAVE_OR_SPEECH_COMPLETE
	            && (VarGet(VAR_ALCATRAZ_STATE) >= POST_SPEECHSPEECH))
    {
        return gText_PlayersAdventure_Flavor35B;
    }

    else if (storyline == STORY_RECIVED_RAVE_INVITE)
    {
        return gText_PlayersAdventure_Flavor35;
    }

	else if (storyline > STORY_START_TRUE_TIMELINE)
	{
		return gText_PlayersAdventure_Flavor34A;
	}

	else if (storyline == STORY_START_TRUE_TIMELINE)
	{
		return gText_PlayersAdventure_Flavor34;
	}

	else if (storyline > STORY_CONGRATULATED_BY_ROSE)
	{
		return gText_PlayersAdventure_Flavor33;
	}

	else if (storyline > STORY_POST_DIANTHA)
	{
		return gText_PlayersAdventure_Flavor32;
	}

	else if (storyline == STORY_SAVE_DIANTHA)
	{
		return gText_PlayersAdventure_Flavor31;
	}

	else if (storyline == STORY_TEAMROCKET_FINISHED)
	{
		return gText_PlayersAdventure_Flavor30;
	}

	else if (storyline > STORY_MORNING_OF_TIMELINE_SPLIT)
	{
		return gText_PlayersAdventure_Flavor29;
	}

	else if (storyline == STORY_MORNING_OF_TIMELINE_SPLIT
	            && FlagGet(FLAG_TIMELINE_TIMETRAVEL))
	{
		return gText_PlayersAdventure_Flavor28;
	}

	else if (storyline == STORY_MORNING_OF_TIMELINE_SPLIT)
	{
		return gText_PlayersAdventure_Flavor27;
	}

	else if (storyline == STORY_POST_YOU_REALIZE_WERE_EVIL
	            && (VarGet(VAR_ALCATRAZ_STATE) >= POST_YOU_REALIZE_THEYRE_EVIL_RIGHT))
	{
		return gText_PlayersAdventure_Flavor26;
	}

	else if (storyline == STORY_POST_YOU_REALIZE_WERE_EVIL
	            && (VarGet(VAR_ALCATRAZ_STATE) < POST_YOU_REALIZE_THEYRE_EVIL_RIGHT))
	{
		return gText_PlayersAdventure_Flavor25;
	}

	else if (storyline > STORY_ARCHER_EXPLAIN_RESTORATION)
	{
		return gText_PlayersAdventure_Flavor24;
	}

	else if (storyline == STORY_ARCHER_EXPLAIN_RESTORATION)
	{
		return gText_PlayersAdventure_Flavor23;
	}

	else if (storyline == STORY_POST_BATTLE_ARCHER_TREASUREISLAND)
	{
		return gText_PlayersAdventure_Flavor22;
	}

	else if (storyline == STORY_SAVE_ARCHER_TREASUREISLAND)
	{
		return gText_PlayersAdventure_Flavor21;
	}

	else if (storyline == STORY_EXPLORE_TREASUREISLAND)
	{
		return gText_PlayersAdventure_Flavor20;
	}

	else if (storyline == STORY_WON_FINALS)
	{
		return gText_PlayersAdventure_Flavor19;
	}

	else if (storyline > STORY_READY_FINALS)
	{
		return gText_PlayersAdventure_Flavor18;
	}

	else if (storyline == STORY_WATCH_SEMIFINAL)
	{
		return gText_PlayersAdventure_Flavor17;
	}

	else if (storyline == STORY_GROUP_STATE_COMPLETE)
	{
		return gText_PlayersAdventure_Flavor16;
	}

	else if (storyline > STORY_CHAMPIONSHIP_EXPLAINED)
	{
		return gText_PlayersAdventure_Flavor15;
	}

	else if (storyline == STORY_CHAMPIONSHIP_EXPLAINED)
	{
		return gText_PlayersAdventure_Flavor14;
	}

	else if (storyline == STORY_START_CHAMPIONSHIP)
	{
		return gText_PlayersAdventure_Flavor13;
	}

	else if (storyline == STORY_COMPLETED_NAVAL_BASE)
	{
		return gText_PlayersAdventure_Flavor12;
	}

	else if (storyline == STORY_ASSIGNED_SIEBOLD_QUESTS
	            && (VarGet(VAR_SALESFORCETOWER_CONFERENCE_STATE) > PRE_WELCOME_TO_THE_WAR_ROOM))
	{
		return gText_PlayersAdventure_Flavor11;
	}

    else if (storyline == STORY_ASSIGNED_SIEBOLD_QUESTS
                && (VarGet(VAR_MUIRWOODS_STATE) > MUIRWOODS_MAZE_COMPLETE))
	{
		return gText_PlayersAdventure_Flavor10;
	}

	else if (storyline == STORY_ASSIGNED_SIEBOLD_QUESTS
                && (VarGet(VAR_GOLDENGATEBRIDGE_STATE) > CALLED_BY_BIANCA))
	{
		return gText_PlayersAdventure_Flavor9_B;
	}

    else if (storyline == STORY_ASSIGNED_SIEBOLD_QUESTS && (VarGet(VAR_GOLDENGATEBRIDGE_STATE) == CALLED_BY_BIANCA))
	{
		return gText_PlayersAdventure_Flavor9_A;
	}

	else if (storyline == STORY_NEED_SLEEP_BEFORE_SIEBOLD)
	{
		return gText_PlayersAdventure_Flavor9;
	}

	else if (storyline == STORY_CALLED_TO_CONSTRUCTION
	            && (VarGet(VAR_CONSTRUCTION_STRIKE_STATE) == START_VS_GARBODOR))
	{
		return gText_PlayersAdventure_Flavor8;
	}

	else if (storyline == STORY_CALLED_TO_CONSTRUCTION)
	{
		return gText_PlayersAdventure_Flavor7;
	}

	else if (storyline > STORY_DEFEAT_MORTY)
	{
		return gText_PlayersAdventure_Flavor6;
	}

	else if (storyline == STORY_DEFEAT_MORTY
	            && (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1)))
	{
		return gText_PlayersAdventure_Flavor5;
	}

	else if (storyline == STORY_DEFEAT_MORTY)
	{
		return gText_PlayersAdventure_Flavor4;
	}

	else if (storyline == STORY_FERRY_FIXED)
	{
		return gText_PlayersAdventure_Flavor3;
	}

	else if (storyline == STORY_WEST_SANFRAN_COMPLETE)
	{
		return gText_PlayersAdventure_Flavor2;
	}

	else if (storyline > 0)
	{
		return gText_PlayersAdventure_Flavor1;
	}

	else if ((storyline == 0)
	            && ((VarGet(VAR_PLAYER_HOME_STATE) > POST_SWAGBAG)))
	{
		return gText_PlayersAdventure_Flavor1;
	}

    else if ((storyline == 0) && !FlagGet(FLAG_SYS_QUEST_MENU_GET))
    {
        return gText_PlayersAdventure_Flavor0;
    }

	else
	{
		return gText_Quest_PlayersAdventure_Desc;
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
