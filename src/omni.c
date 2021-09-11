/*

fade screen to black
display speech box
load Zoey text and display there
load game's text and display there
prompt user to save
show squares on screen
load pokemon in squares
show game text
create cursor
display cursor
move cursor
pick pokemon
display desc text
give pokemon to player

*/
#include "global.h"
#include "save.h" //enable saving
#include "pokemon.h"
#include "event_scripts.h" //for needed script text
#include "../gflib/text.h" //expanded defines
#include "script.h"


//https://github.com/pret/pokeemerald/wiki/printf-in-mGBA
#include "printf.h"
#include "mgba.h"
#include "../gflib/string_util.h" // for ConvertToAscii()

extern const u8 EventScript_SelectWithoutRegisteredItem[];

void MySpecial(){
    ScriptContext1_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return;
};
