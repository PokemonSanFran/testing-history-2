#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "party_menu.h"
#include "fldeff.h"

#include "event_scripts.h" //PSF allows for calling of mapscript to set secret lab

bool8 ShouldDoSecretLabDigEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_DIG)
     && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE8)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE8)))
    {
         if ((gSaveBlock1Ptr->pos.x > 9 && gSaveBlock1Ptr->pos.x < 13) && (gSaveBlock1Ptr->pos.y > 15 && gSaveBlock1Ptr->pos.y < 19))
             return TRUE;
    }

    return FALSE;
}

void DoSecretLabDigEffect(void)
{
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 17 + MAP_OFFSET, METATILE_General_CaveEntrance_Bottom);
    DrawWholeMapView();
    ScriptContext1_SetupScript(Psfroute8_UncoverSecretLab_Script);
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_BRAILLE_DIG);
    ScriptContext2_Disable();
}
