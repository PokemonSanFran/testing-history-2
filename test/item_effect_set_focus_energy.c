#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Dire Hit increases a battler's critical hit chance by 2 stages")
{
    KNOWN_FAILING; // Displays Message "Foe Wobbuffet used Dire Hit.." when facing off against Wobbuffet. Doesnt happen against other species?
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(gItems[ITEM_DIRE_HIT].battleUsage == EFFECT_ITEM_SET_FOCUS_ENERGY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABOMASNOW);
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
