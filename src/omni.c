#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "cutscene_yc_acceptance_letter.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "list_menu.h"
#include "mystery_event_menu.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"
#include "mystery_gift.h"

//sample text files
#include "omni.h"
#include "include/omni_text.h" //TODO why do I need to use include to show the file name here? https://discordapp.com/channels/442462691542695948/884605548560011284/884605550019620894

//https://github.com/pret/pokeemerald/wiki/printf-in-mGBA
#include "printf.h"
#include "mgba.h"
#include "../gflib/string_util.h" // for ConvertToAscii()

//extern const u8 gText_SuperMonolougeText1[];
/*

FUNCTION LIST

Visual Init of screen
Text init of screen
Activate scroller (pokedex?)
Show up and down arrows
Fade in
ShowAButtonWhenFinished

black text on white bg, no styling

print text

scroll up or down with direction pad
can we reuse the "go outside arrow" but point it downward?
text should cut off on bottom to show scroll

"press a to continue" should appear in bottom right. or maybe an "a" button press?

*/

void MySpecial(void)
{
	//create a struct of type Window Template with the name template
	struct WindowTemplate template;


	//create a task
	u8 taskId = CreateTask(Task_WaitPlayerInput, 0);
    mgba_printf(MGBA_LOG_DEBUG, "this is taskId: %d", taskId);

	//create the window
	
	//invoke SetWindowTemplateFields, defaults listed in comment
	// use the address of the struct template,
    // bg id 0
    // left id 
    // top id 1
    // width 28
    // height 3
    // paletteNum 15
    // baseblock 8
	SetWindowTemplateFields(&template, 0, 1, 1, 28, 30, 15, 8);

	//0th spot in the data array will invoke AddWindow with the address of the template
	gTasks[taskId].data[0] = AddWindow(&template); // save window id

	//run FillWindowPixelBuffer, using the windowId stored in data[0] and fill the pixels with 0 (pretty sure that's black)
	FillWindowPixelBuffer(gTasks[taskId].data[0], PIXEL_FILL(0));
	//Place the window stored at data[0] i guess?
	PutWindowTilemap(gTasks[taskId].data[0]);
	
	//draw the window frame, using the window id of template
	//do not copy to vram
	//base tile 214
	//palette number 14
    DrawStdFrameWithCustomTileAndPalette(gTasks[taskId].data[0], FALSE, 0x214, 14);
	//print stuff to it if you like
	AddTextPrinterParameterized(gTasks[taskId].data[0], 0, gText_SuperMonolougeText1,1, 1, 0, NULL);
     
	CopyWindowToVram(gTasks[taskId].data[0],3);
	}

void Task_WaitPlayerInput(u8 taskId)
{
	if (JOY_NEW(A_BUTTON))
		//switch page
		return;
	else if (JOY_NEW(DPAD_DOWN))
		//scroll
		return;
}
