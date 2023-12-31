#include "global.h"
#include "braille_puzzles.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "party_menu.h"
#include "sprite.h"
#include "constants/field_effects.h"

#include "field_puzzles.h"

// static functions
static void FieldCallback_Dig(void);
static void StartDigFieldEffect(void);

// text
bool8 SetUpFieldMove_Dig(void)
{
    //If on Psfroute8, allow player to dig AND hasn't already uncovered the lab
    if (ShouldDoSecretLabDigEffect())
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Dig;
        return TRUE;
    }
    else if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Dig;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void FieldCallback_Dig(void)
{
    Overworld_ResetStateAfterDigEscRope();
    FieldEffectStart(FLDEFF_USE_DIG);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_UseDig(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartDigFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartDigFieldEffect;
    //if (!ShouldDoBrailleDigEffect())
    if (!ShouldDoSecretLabDigEffect())
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

static void StartDigFieldEffect(void)
{
    u8 taskId;

    FieldEffectActiveListRemove(FLDEFF_USE_DIG);
    //if (ShouldDoBrailleDigEffect()) //removed for PSF
    if (ShouldDoSecretLabDigEffect())
    {
        //DoBrailleDigEffect(); //removed for PSF
        DoSecretLabDigEffect();
    }
    else
    {
        taskId = CreateTask(Task_UseDigEscapeRopeOnField, 8);
        gTasks[taskId].data[0] = 0;
    }
}
