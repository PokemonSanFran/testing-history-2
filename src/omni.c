#include "global.h"
#include "save.h" //enable saving
#include "pokemon.h"
#include "script.h"
#include "event_scripts.h"

//https://github.com/pret/pokeemerald/wiki/printf-in-mGBA
#include "printf.h"
#include "mgba.h"
#include "../gflib/string_util.h" // for ConvertToAscii()

bool8 MySpecial(void){
    //ScriptContext1_SetupScript(DebugGiveMons);
//    ScriptContext1_SetupScript(FallarborTown_EventScript_Gentleman);
    return TRUE;
};
