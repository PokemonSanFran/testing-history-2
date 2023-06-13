#include "global.h"
#include "battle.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "fieldmap.h"
#include "item.h"
#include "malloc.h"
#include "mazegen.h"
#include "quests.h"
#include "../gflib/string_util.h"
#include "quest_logic.h"
#include "hidden_grotto.h"
#include "overworld.h"
#include "random.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/sound.h"
#include "field_control_avatar.h"
#include "battle_main.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "money.h"

bool8 Taxi_CalculateFeeAndCharge(void){
    u32 amount;
    amount = 999999999;

    //PSF TODO implement distance based formula 
    //https://chat.openai.com/share/1c0c9adf-8b6a-41ec-9071-653ddb1e0a69

    VarSet(VAR_TAXI_DESTINATION,VarGet(gSpecialVar_Result));
    return IsEnoughMoney(&gSaveBlock1Ptr->money, amount);
}
