#include "global.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_screen_effect.h"
#include "item.h"
#include "malloc.h"
#include "mazegen.h"
#include "quests.h"
#include "../gflib/string_util.h"
#include "quest_logic.h"
#include "story_jump.h"
#include "constants/songs.h"
#include "sound.h"
#include "field_effect.h"

#include "overworld.h"
#include "random.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "field_control_avatar.h"
#include "event_scripts.h"
#include "map_name_popup.h"
#include "hidden_grotto.h"

void HiddenGrotto_WarpPlayerToGrotto(u32 grottoMapGroup, u32 grottpMapNum);

static const u8* const discoveredGrottoTextArray[] =
{
    gText_LookIveFound,\
    gText_WowHiddenPath,\
    gText_OhWhatsThis,\
    gText_AmazingHiddenTrail,\
    gText_HmmConcealedPath,\
    gText_MysteriousRoute,\
    gText_OhMyConcealedGrotto,\
    gText_IntriguingSecretPassage,\
    gText_WhoaHiddenEntrance,\
    gText_HiddenTrailEmerges,\
    gText_OhWhatDoWeHave,\
    gText_ConcealedPathwayAppears,\
    gText_MyCuriosityPiqued,\
    gText_LookClandestinePassage,\
    gText_OhSecretRoute,\
    gText_HmmObscuredPath,\
    gText_ConcealedEntranceDiscovered,\
    gText_WhatsThisCovertPathway,\
    gText_IntriguingHiddenTrail,\
    gText_HiddenGrottoMaterializes
};
const u32 routeGrottoArray[NUM_GROTTO_ROUTES][2]=
{
    {MAP_PSFROUTE1,MAP_PSFROUTE1_GROTTO},
    {MAP_PSFROUTE30,MAP_PSFROUTE30_GROTTO},
    {MAP_PSFROUTE9,MAP_PSFROUTE9_GROTTO},
    {MAP_PSFROUTE70,MAP_PSFROUTE70_GROTTO},
    {MAP_PSFROUTE17,MAP_PSFROUTE17_GROTTO},
    {MAP_PSFROUTE22,MAP_PSFROUTE22_GROTTO},
    {MAP_PSFROUTE20,MAP_PSFROUTE20_GROTTO},
    {MAP_PSFROUTE49,MAP_PSFROUTE49_GROTTO},
    {MAP_PSFROUTE38,MAP_PSFROUTE38_GROTTO},
    {MAP_PSFROUTE14,MAP_PSFROUTE14_GROTTO},
    {MAP_PSFROUTE21,MAP_PSFROUTE21_GROTTO},
    {MAP_PSFROUTE7,MAP_PSFROUTE7_GROTTO},
    {MAP_PSFROUTE63,MAP_PSFROUTE63_GROTTO},
    {MAP_PSFROUTE11,MAP_PSFROUTE11_GROTTO},
    {MAP_PSFROUTE32,MAP_PSFROUTE32_GROTTO},
    {MAP_PSFROUTE62,MAP_PSFROUTE62_GROTTO},
    {MAP_PSFROUTE76,MAP_PSFROUTE76_GROTTO},
    {MAP_PSFROUTE72,MAP_PSFROUTE72_GROTTO},
    {MAP_PSFROUTE18,MAP_PSFROUTE18_GROTTO},
    {MAP_PSFROUTE61,MAP_PSFROUTE61_GROTTO},
    {MAP_PSFROUTE43,MAP_PSFROUTE43_GROTTO},
    {MAP_PSFROUTE5,MAP_PSFROUTE5_GROTTO},
    {MAP_PSFROUTE15,MAP_PSFROUTE15_GROTTO},
    {MAP_PSFROUTE51,MAP_PSFROUTE51_GROTTO},
    {MAP_PSFROUTE8,MAP_PSFROUTE8_GROTTO},
    {MAP_PSFROUTE13,MAP_PSFROUTE13_GROTTO},
};

void HiddenGrotto_LoadDiscoveredGrottoText(void){
    u16 randomDialogIndex = Random() % (ARRAY_COUNT(discoveredGrottoTextArray));

    StringCopy(gStringVar1,discoveredGrottoTextArray[randomDialogIndex]);
}

void HiddenGrotto_LoadGrottoAndWarpPlayer(void){
    u8 i;
    u32 grottoMapGroup = gSaveBlock1Ptr->location.mapGroup;
    u32 grottoMapNum = gSaveBlock1Ptr->location.mapNum;

    for (i = 0; i < ARRAY_COUNT(routeGrottoArray); i++){
        if (routeGrottoArray[i][0] == (grottoMapNum | (grottoMapGroup << 8))){
            grottoMapGroup = ((routeGrottoArray[i][1]) >> 8);
            grottoMapNum = ((routeGrottoArray[i][1]) & 0xFF);
            break;
        }
    }
    HiddenGrotto_WarpPlayerToGrotto(grottoMapGroup,grottoMapNum);
}

void HiddenGrotto_WarpPlayerToGrotto(u32 grottoMapGroup, u32 grottoMapNum){
    SetWarpDestinationToMapWarp(grottoMapGroup,grottoMapNum,0);
	DoWarp();
	ResetInitialPlayerAvatarState();
    PlaySE(SE_EXIT);
}
