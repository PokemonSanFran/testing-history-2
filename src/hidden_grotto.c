#include "global.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "fieldmap.h"
#include "item.h"
#include "malloc.h"
#include "mazegen.h"
#include "quests.h"
#include "../gflib/string_util.h"
#include "quest_logic.h"

#include "overworld.h"
#include "random.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "field_control_avatar.h"
#include "event_scripts.h"
#include "map_name_popup.h"

static const u8 gText_Quest_Hiddengrotto_LookYouveFound[];
static const u8 gText_LookIveFound[];
static const u8 gText_WowHiddenPath[];
static const u8 gText_OhWhatsThis[];
static const u8 gText_AmazingHiddenTrail[];
static const u8 gText_HmmConcealedPath[];
static const u8 gText_MysteriousRoute[];
static const u8 gText_OhMyConcealedGrotto[];
static const u8 gText_IntriguingSecretPassage[];
static const u8 gText_WhoaHiddenEntrance[];
static const u8 gText_HiddenTrailEmerges[];
static const u8 gText_OhWhatDoWeHave[];
static const u8 gText_ConcealedPathwayAppears[];
static const u8 gText_MyCuriosityPiqued[];
static const u8 gText_LookClandestinePassage[];
static const u8 gText_OhSecretRoute[];
static const u8 gText_HmmObscuredPath[];
static const u8 gText_ConcealedEntranceDiscovered[];
static const u8 gText_WhatsThisCovertPathway[];
static const u8 gText_IntriguingHiddenTrail[];
static const u8 gText_HiddenGrottoMaterializes[];
static const u8 gText_Quest_Hiddengrotto_LookYouveFound[];

const u8* gTextArray[] = 
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


u16 HiddenGrotto_ChooseDialogueAndLoadCorrespondingWarp(void){
    u16 dialogVar = Random() % 20;

    StringCopy(gStringVar1,gTextArray[dialogVar]);
    SetDynamicWarpWithCoords(0,MAP_GROUP(PSFROUTE17_GROTTO),MAP_NUM(PSFROUTE17_GROTTO),0,0,0);

    return dialogVar;
}
