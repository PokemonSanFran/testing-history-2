#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Dire Hit increases a battler's critical hit chance by 2 stages")
{
    /* KNOWN_FAILING due to message mismatch for "Wobbuffet used Dire Hit to get pumped!"
     * As of the time of writing, this test passes if the above mentioned message is removed
     * For more details refer to description of PR #2940 */
    KNOWN_FAILING;
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(gItems[ITEM_DIRE_HIT].battleUsage == EFFECT_ITEM_SET_FOCUS_ENERGY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_DIRE_HIT, partyIndex: 0); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        MESSAGE("Wobbuffet used Dire Hit to get pumped!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("A critical hit!");
    }
}
