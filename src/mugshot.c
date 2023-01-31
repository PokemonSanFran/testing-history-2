#include "global.h"
#include "international_string_util.h"
#include "blit.h"
#include "bg.h"
#include "decompress.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"
#include "printf.h"
#include "mgba.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

//void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
//void ClearMugshot(void);

static const u16 sMugshotPal_Aaron[] = INCBIN_U16("graphics/mugshots/aaron.gbapal");
static const u32 sMugshotImg_Aaron[] = INCBIN_U32("graphics/mugshots/aaron.4bpp.lz");

static const u16 sMugshotPal_Alder[] = INCBIN_U16("graphics/mugshots/alder.gbapal");
static const u32 sMugshotImg_Alder[] = INCBIN_U32("graphics/mugshots/alder.4bpp.lz");

static const u16 sMugshotPal_Archer[] = INCBIN_U16("graphics/mugshots/archer.gbapal");
static const u32 sMugshotImg_Archer[] = INCBIN_U32("graphics/mugshots/archer.4bpp.lz");

static const u16 sMugshotPal_Argenta[] = INCBIN_U16("graphics/mugshots/argenta.gbapal");
static const u32 sMugshotImg_Argenta[] = INCBIN_U32("graphics/mugshots/argenta.4bpp.lz");

static const u16 sMugshotPal_Ariana[] = INCBIN_U16("graphics/mugshots/ariana.gbapal");
static const u32 sMugshotImg_Ariana[] = INCBIN_U32("graphics/mugshots/ariana.4bpp.lz");

static const u16 sMugshotPal_Benga[] = INCBIN_U16("graphics/mugshots/benga.gbapal");
static const u32 sMugshotImg_Benga[] = INCBIN_U32("graphics/mugshots/benga.4bpp.lz");

static const u16 sMugshotPal_Bertha[] = INCBIN_U16("graphics/mugshots/bertha.gbapal");
static const u32 sMugshotImg_Bertha[] = INCBIN_U32("graphics/mugshots/bertha.4bpp.lz");

static const u16 sMugshotPal_Bianca[] = INCBIN_U16("graphics/mugshots/bianca.gbapal");
static const u32 sMugshotImg_Bianca[] = INCBIN_U32("graphics/mugshots/bianca.4bpp.lz");

static const u16 sMugshotPal_Blaine[] = INCBIN_U16("graphics/mugshots/blaine.gbapal");
static const u32 sMugshotImg_Blaine[] = INCBIN_U32("graphics/mugshots/blaine.4bpp.lz");

static const u16 sMugshotPal_Brock[] = INCBIN_U16("graphics/mugshots/brock.gbapal");
static const u32 sMugshotImg_Brock[] = INCBIN_U32("graphics/mugshots/brock.4bpp.lz");

static const u16 sMugshotPal_Bruno[] = INCBIN_U16("graphics/mugshots/bruno.gbapal");
static const u32 sMugshotImg_Bruno[] = INCBIN_U32("graphics/mugshots/bruno.4bpp.lz");

static const u16 sMugshotPal_Brycen[] = INCBIN_U16("graphics/mugshots/brycen.gbapal");
static const u32 sMugshotImg_Brycen[] = INCBIN_U32("graphics/mugshots/brycen.4bpp.lz");

static const u16 sMugshotPal_Bugsy[] = INCBIN_U16("graphics/mugshots/bugsy.gbapal");
static const u32 sMugshotImg_Bugsy[] = INCBIN_U32("graphics/mugshots/bugsy.4bpp.lz");

static const u16 sMugshotPal_Burgh[] = INCBIN_U16("graphics/mugshots/burgh.gbapal");
static const u32 sMugshotImg_Burgh[] = INCBIN_U32("graphics/mugshots/burgh.4bpp.lz");

static const u16 sMugshotPal_Byron[] = INCBIN_U16("graphics/mugshots/byron.gbapal");
static const u32 sMugshotImg_Byron[] = INCBIN_U32("graphics/mugshots/byron.4bpp.lz");

static const u16 sMugshotPal_Caitlin[] = INCBIN_U16("graphics/mugshots/caitlin.gbapal");
static const u32 sMugshotImg_Caitlin[] = INCBIN_U32("graphics/mugshots/caitlin.4bpp.lz");

static const u16 sMugshotPal_Candice[] = INCBIN_U16("graphics/mugshots/candice.gbapal");
static const u32 sMugshotImg_Candice[] = INCBIN_U32("graphics/mugshots/candice.4bpp.lz");

static const u16 sMugshotPal_Cheren[] = INCBIN_U16("graphics/mugshots/cheren.gbapal");
static const u32 sMugshotImg_Cheren[] = INCBIN_U32("graphics/mugshots/cheren.4bpp.lz");

static const u16 sMugshotPal_Cheren_2[] = INCBIN_U16("graphics/mugshots/cheren_2.gbapal");
static const u32 sMugshotImg_Cheren_2[] = INCBIN_U32("graphics/mugshots/cheren_2.4bpp.lz");

static const u16 sMugshotPal_Chili[] = INCBIN_U16("graphics/mugshots/chili.gbapal");
static const u32 sMugshotImg_Chili[] = INCBIN_U32("graphics/mugshots/chili.4bpp.lz");

static const u16 sMugshotPal_Chuck[] = INCBIN_U16("graphics/mugshots/chuck.gbapal");
static const u32 sMugshotImg_Chuck[] = INCBIN_U32("graphics/mugshots/chuck.4bpp.lz");

static const u16 sMugshotPal_Cilan[] = INCBIN_U16("graphics/mugshots/cilan.gbapal");
static const u32 sMugshotImg_Cilan[] = INCBIN_U32("graphics/mugshots/cilan.4bpp.lz");

static const u16 sMugshotPal_Clair[] = INCBIN_U16("graphics/mugshots/clair.gbapal");
static const u32 sMugshotImg_Clair[] = INCBIN_U32("graphics/mugshots/clair.4bpp.lz");

static const u16 sMugshotPal_Clay[] = INCBIN_U16("graphics/mugshots/clay.gbapal");
static const u32 sMugshotImg_Clay[] = INCBIN_U32("graphics/mugshots/clay.4bpp.lz");

static const u16 sMugshotPal_Colress[] = INCBIN_U16("graphics/mugshots/colress.gbapal");
static const u32 sMugshotImg_Colress[] = INCBIN_U32("graphics/mugshots/colress.4bpp.lz");

static const u16 sMugshotPal_Crasher_Wake[] = INCBIN_U16("graphics/mugshots/crasher_wake.gbapal");
static const u32 sMugshotImg_Crasher_Wake[] = INCBIN_U32("graphics/mugshots/crasher_wake.4bpp.lz");

static const u16 sMugshotPal_Cress[] = INCBIN_U16("graphics/mugshots/cress.gbapal");
static const u32 sMugshotImg_Cress[] = INCBIN_U32("graphics/mugshots/cress.4bpp.lz");

static const u16 sMugshotPal_Cynthia[] = INCBIN_U16("graphics/mugshots/cynthia.gbapal");
static const u32 sMugshotImg_Cynthia[] = INCBIN_U32("graphics/mugshots/cynthia.4bpp.lz");

static const u16 sMugshotPal_Dahlia[] = INCBIN_U16("graphics/mugshots/dahlia.gbapal");
static const u32 sMugshotImg_Dahlia[] = INCBIN_U32("graphics/mugshots/dahlia.4bpp.lz");

static const u16 sMugshotPal_Darach[] = INCBIN_U16("graphics/mugshots/darach.gbapal");
static const u32 sMugshotImg_Darach[] = INCBIN_U32("graphics/mugshots/darach.4bpp.lz");

static const u16 sMugshotPal_Dawn[] = INCBIN_U16("graphics/mugshots/dawn.gbapal");
static const u32 sMugshotImg_Dawn[] = INCBIN_U32("graphics/mugshots/dawn.4bpp.lz");

static const u16 sMugshotPal_Drayden[] = INCBIN_U16("graphics/mugshots/drayden.gbapal");
static const u32 sMugshotImg_Drayden[] = INCBIN_U32("graphics/mugshots/drayden.4bpp.lz");

static const u16 sMugshotPal_Elesa[] = INCBIN_U16("graphics/mugshots/elesa.gbapal");
static const u32 sMugshotImg_Elesa[] = INCBIN_U32("graphics/mugshots/elesa.4bpp.lz");

static const u16 sMugshotPal_Elesa_2[] = INCBIN_U16("graphics/mugshots/elesa_2.gbapal");
static const u32 sMugshotImg_Elesa_2[] = INCBIN_U32("graphics/mugshots/elesa_2.4bpp.lz");

static const u16 sMugshotPal_Erika[] = INCBIN_U16("graphics/mugshots/erika.gbapal");
static const u32 sMugshotImg_Erika[] = INCBIN_U32("graphics/mugshots/erika.4bpp.lz");

static const u16 sMugshotPal_Ethan[] = INCBIN_U16("graphics/mugshots/ethan.gbapal");
static const u32 sMugshotImg_Ethan[] = INCBIN_U32("graphics/mugshots/ethan.4bpp.lz");

static const u16 sMugshotPal_Falkner[] = INCBIN_U16("graphics/mugshots/falkner.gbapal");
static const u32 sMugshotImg_Falkner[] = INCBIN_U32("graphics/mugshots/falkner.4bpp.lz");

static const u16 sMugshotPal_Fantina[] = INCBIN_U16("graphics/mugshots/fantina.gbapal");
static const u32 sMugshotImg_Fantina[] = INCBIN_U32("graphics/mugshots/fantina.4bpp.lz");

static const u16 sMugshotPal_Flint[] = INCBIN_U16("graphics/mugshots/flint.gbapal");
static const u32 sMugshotImg_Flint[] = INCBIN_U32("graphics/mugshots/flint.4bpp.lz");

static const u16 sMugshotPal_Gardenia[] = INCBIN_U16("graphics/mugshots/gardenia.gbapal");
static const u32 sMugshotImg_Gardenia[] = INCBIN_U32("graphics/mugshots/gardenia.4bpp.lz");

static const u16 sMugshotPal_Ghetsis[] = INCBIN_U16("graphics/mugshots/ghetsis.gbapal");
static const u32 sMugshotImg_Ghetsis[] = INCBIN_U32("graphics/mugshots/ghetsis.4bpp.lz");

static const u16 sMugshotPal_Ghetsis_2[] = INCBIN_U16("graphics/mugshots/ghetsis_2.gbapal");
static const u32 sMugshotImg_Ghetsis_2[] = INCBIN_U32("graphics/mugshots/ghetsis_2.4bpp.lz");

static const u16 sMugshotPal_Giovanni[] = INCBIN_U16("graphics/mugshots/giovanni.gbapal");
static const u32 sMugshotImg_Giovanni[] = INCBIN_U32("graphics/mugshots/giovanni.4bpp.lz");

static const u16 sMugshotPal_Grimsley[] = INCBIN_U16("graphics/mugshots/grimsley.gbapal");
static const u32 sMugshotImg_Grimsley[] = INCBIN_U32("graphics/mugshots/grimsley.4bpp.lz");

static const u16 sMugshotPal_Hilbert[] = INCBIN_U16("graphics/mugshots/hilbert.gbapal");
static const u32 sMugshotImg_Hilbert[] = INCBIN_U32("graphics/mugshots/hilbert.4bpp.lz");

static const u16 sMugshotPal_Hilda[] = INCBIN_U16("graphics/mugshots/hilda.gbapal");
static const u32 sMugshotImg_Hilda[] = INCBIN_U32("graphics/mugshots/hilda.4bpp.lz");

static const u16 sMugshotPal_Hugh[] = INCBIN_U16("graphics/mugshots/hugh.gbapal");
static const u32 sMugshotImg_Hugh[] = INCBIN_U32("graphics/mugshots/hugh.4bpp.lz");

static const u16 sMugshotPal_Iris[] = INCBIN_U16("graphics/mugshots/iris.gbapal");
static const u32 sMugshotImg_Iris[] = INCBIN_U32("graphics/mugshots/iris.4bpp.lz");

static const u16 sMugshotPal_Janine[] = INCBIN_U16("graphics/mugshots/janine.gbapal");
static const u32 sMugshotImg_Janine[] = INCBIN_U32("graphics/mugshots/janine.4bpp.lz");

static const u16 sMugshotPal_Jasmine[] = INCBIN_U16("graphics/mugshots/jasmine.gbapal");
static const u32 sMugshotImg_Jasmine[] = INCBIN_U32("graphics/mugshots/jasmine.4bpp.lz");

static const u16 sMugshotPal_Karen[] = INCBIN_U16("graphics/mugshots/karen.gbapal");
static const u32 sMugshotImg_Karen[] = INCBIN_U32("graphics/mugshots/karen.4bpp.lz");

static const u16 sMugshotPal_Lance[] = INCBIN_U16("graphics/mugshots/lance.gbapal");
static const u32 sMugshotImg_Lance[] = INCBIN_U32("graphics/mugshots/lance.4bpp.lz");

static const u16 sMugshotPal_Lenora[] = INCBIN_U16("graphics/mugshots/lenora.gbapal");
static const u32 sMugshotImg_Lenora[] = INCBIN_U32("graphics/mugshots/lenora.4bpp.lz");

static const u16 sMugshotPal_Lt_Surge[] = INCBIN_U16("graphics/mugshots/lt_surge.gbapal");
static const u32 sMugshotImg_Lt_Surge[] = INCBIN_U32("graphics/mugshots/lt_surge.4bpp.lz");

static const u16 sMugshotPal_Lucas[] = INCBIN_U16("graphics/mugshots/lucas.gbapal");
static const u32 sMugshotImg_Lucas[] = INCBIN_U32("graphics/mugshots/lucas.4bpp.lz");

static const u16 sMugshotPal_Lucian[] = INCBIN_U16("graphics/mugshots/lucian.gbapal");
static const u32 sMugshotImg_Lucian[] = INCBIN_U32("graphics/mugshots/lucian.4bpp.lz");

static const u16 sMugshotPal_Lyra[] = INCBIN_U16("graphics/mugshots/lyra.gbapal");
static const u32 sMugshotImg_Lyra[] = INCBIN_U32("graphics/mugshots/lyra.4bpp.lz");

static const u16 sMugshotPal_Marlon[] = INCBIN_U16("graphics/mugshots/marlon.gbapal");
static const u32 sMugshotImg_Marlon[] = INCBIN_U32("graphics/mugshots/marlon.4bpp.lz");

static const u16 sMugshotPal_Marshal[] = INCBIN_U16("graphics/mugshots/marshal.gbapal");
static const u32 sMugshotImg_Marshal[] = INCBIN_U32("graphics/mugshots/marshal.4bpp.lz");

static const u16 sMugshotPal_Maylene[] = INCBIN_U16("graphics/mugshots/maylene.gbapal");
static const u32 sMugshotImg_Maylene[] = INCBIN_U32("graphics/mugshots/maylene.4bpp.lz");

static const u16 sMugshotPal_Misty[] = INCBIN_U16("graphics/mugshots/misty.gbapal");
static const u32 sMugshotImg_Misty[] = INCBIN_U32("graphics/mugshots/misty.4bpp.lz");

static const u16 sMugshotPal_Morty[] = INCBIN_U16("graphics/mugshots/morty.gbapal");
static const u32 sMugshotImg_Morty[] = INCBIN_U32("graphics/mugshots/morty.4bpp.lz");

static const u16 sMugshotPal_N[] = INCBIN_U16("graphics/mugshots/n.gbapal");
static const u32 sMugshotImg_N[] = INCBIN_U32("graphics/mugshots/n.4bpp.lz");

static const u16 sMugshotPal_Nate[] = INCBIN_U16("graphics/mugshots/nate.gbapal");
static const u32 sMugshotImg_Nate[] = INCBIN_U32("graphics/mugshots/nate.4bpp.lz");

static const u16 sMugshotPal_Palmer[] = INCBIN_U16("graphics/mugshots/palmer.gbapal");
static const u32 sMugshotImg_Palmer[] = INCBIN_U32("graphics/mugshots/palmer.4bpp.lz");

static const u16 sMugshotPal_Petrel[] = INCBIN_U16("graphics/mugshots/petrel.gbapal");
static const u32 sMugshotImg_Petrel[] = INCBIN_U32("graphics/mugshots/petrel.4bpp.lz");

static const u16 sMugshotPal_Proton[] = INCBIN_U16("graphics/mugshots/proton.gbapal");
static const u32 sMugshotImg_Proton[] = INCBIN_U32("graphics/mugshots/proton.4bpp.lz");

static const u16 sMugshotPal_Pryce[] = INCBIN_U16("graphics/mugshots/pryce.gbapal");
static const u32 sMugshotImg_Pryce[] = INCBIN_U32("graphics/mugshots/pryce.4bpp.lz");

static const u16 sMugshotPal_Roark[] = INCBIN_U16("graphics/mugshots/roark.gbapal");
static const u32 sMugshotImg_Roark[] = INCBIN_U32("graphics/mugshots/roark.4bpp.lz");

static const u16 sMugshotPal_Rosa[] = INCBIN_U16("graphics/mugshots/rosa.gbapal");
static const u32 sMugshotImg_Rosa[] = INCBIN_U32("graphics/mugshots/rosa.4bpp.lz");

static const u16 sMugshotPal_Roxie[] = INCBIN_U16("graphics/mugshots/roxie.gbapal");
static const u32 sMugshotImg_Roxie[] = INCBIN_U32("graphics/mugshots/roxie.4bpp.lz");

static const u16 sMugshotPal_Sabrina[] = INCBIN_U16("graphics/mugshots/sabrina.gbapal");
static const u32 sMugshotImg_Sabrina[] = INCBIN_U32("graphics/mugshots/sabrina.4bpp.lz");

static const u16 sMugshotPal_Shauntal[] = INCBIN_U16("graphics/mugshots/shauntal.gbapal");
static const u32 sMugshotImg_Shauntal[] = INCBIN_U32("graphics/mugshots/shauntal.4bpp.lz");

static const u16 sMugshotPal_Silver[] = INCBIN_U16("graphics/mugshots/silver.gbapal");
static const u32 sMugshotImg_Silver[] = INCBIN_U32("graphics/mugshots/silver.4bpp.lz");

static const u16 sMugshotPal_Skyla[] = INCBIN_U16("graphics/mugshots/skyla.gbapal");
static const u32 sMugshotImg_Skyla[] = INCBIN_U32("graphics/mugshots/skyla.4bpp.lz");

static const u16 sMugshotPal_Thorton[] = INCBIN_U16("graphics/mugshots/thorton.gbapal");
static const u32 sMugshotImg_Thorton[] = INCBIN_U32("graphics/mugshots/thorton.4bpp.lz");

static const u16 sMugshotPal_Volkner[] = INCBIN_U16("graphics/mugshots/volkner.gbapal");
static const u32 sMugshotImg_Volkner[] = INCBIN_U32("graphics/mugshots/volkner.4bpp.lz");

static const u16 sMugshotPal_Whitney[] = INCBIN_U16("graphics/mugshots/whitney.gbapal");
static const u32 sMugshotImg_Whitney[] = INCBIN_U32("graphics/mugshots/whitney.4bpp.lz");

//TODO Write a constant coordinates for mugshots for protag (left) and other people (right)

static const struct Mugshot sMugshots[] = {
    [MUGSHOT_AARON] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Aaron, .palette = sMugshotPal_Aaron},
    [MUGSHOT_ARCHER] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Archer, .palette = sMugshotPal_Archer},
    [MUGSHOT_ARGENTA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Argenta, .palette = sMugshotPal_Argenta},
    [MUGSHOT_ARIANA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Ariana, .palette = sMugshotPal_Ariana},
    [MUGSHOT_BERTHA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Bertha, .palette = sMugshotPal_Bertha},
    [MUGSHOT_BLAINE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Blaine, .palette = sMugshotPal_Blaine},
    [MUGSHOT_BROCK] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Brock, .palette = sMugshotPal_Brock},
    [MUGSHOT_BRUNO] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Bruno, .palette = sMugshotPal_Bruno},
    [MUGSHOT_BUGSY] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Bugsy, .palette = sMugshotPal_Bugsy},
    [MUGSHOT_BYRON] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Byron, .palette = sMugshotPal_Byron},
    [MUGSHOT_CANDICE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Candice, .palette = sMugshotPal_Candice},
    [MUGSHOT_CHUCK] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Chuck, .palette = sMugshotPal_Chuck},
    [MUGSHOT_CLAIR] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Clair, .palette = sMugshotPal_Clair},
    [MUGSHOT_CRASHER_WAKE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Crasher_Wake, .palette = sMugshotPal_Crasher_Wake},
    [MUGSHOT_CYNTHIA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Cynthia, .palette = sMugshotPal_Cynthia},
    [MUGSHOT_DAHLIA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Dahlia, .palette = sMugshotPal_Dahlia},
    [MUGSHOT_DARACH] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Darach, .palette = sMugshotPal_Darach},
    [MUGSHOT_DAWN] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Dawn, .palette = sMugshotPal_Dawn},
    [MUGSHOT_ERIKA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Erika, .palette = sMugshotPal_Erika},
    [MUGSHOT_ETHAN] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Ethan, .palette = sMugshotPal_Ethan},
    [MUGSHOT_FALKNER] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Falkner, .palette = sMugshotPal_Falkner},
    [MUGSHOT_FANTINA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Fantina, .palette = sMugshotPal_Fantina},
    [MUGSHOT_FLINT] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Flint, .palette = sMugshotPal_Flint},
    [MUGSHOT_GARDENIA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Gardenia, .palette = sMugshotPal_Gardenia},
    [MUGSHOT_GIOVANNI] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Giovanni, .palette = sMugshotPal_Giovanni},
    [MUGSHOT_JANINE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Janine, .palette = sMugshotPal_Janine},
    [MUGSHOT_JASMINE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Jasmine, .palette = sMugshotPal_Jasmine},
    [MUGSHOT_KAREN] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Karen, .palette = sMugshotPal_Karen},
    [MUGSHOT_LANCE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Lance, .palette = sMugshotPal_Lance},
    [MUGSHOT_LT_SURGE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Lt_Surge, .palette = sMugshotPal_Lt_Surge},
    [MUGSHOT_LUCAS] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Lucas, .palette = sMugshotPal_Lucas},
    [MUGSHOT_LUCIAN] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Lucian, .palette = sMugshotPal_Lucian},
    [MUGSHOT_LYRA] = {.x = 20, .y = 6, .width = 96, .height = 64, .image = sMugshotImg_Lyra, .palette = sMugshotPal_Lyra},
    [MUGSHOT_MAYLENE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Maylene, .palette = sMugshotPal_Maylene},
    [MUGSHOT_MISTY] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Misty, .palette = sMugshotPal_Misty},
    [MUGSHOT_MORTY] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Morty, .palette = sMugshotPal_Morty},
    [MUGSHOT_PALMER] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Palmer, .palette = sMugshotPal_Palmer},
    [MUGSHOT_PETREL] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Petrel, .palette = sMugshotPal_Petrel},
    [MUGSHOT_PROTON] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Proton, .palette = sMugshotPal_Proton},
    [MUGSHOT_PRYCE] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Pryce, .palette = sMugshotPal_Pryce},
    [MUGSHOT_ROARK] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Roark, .palette = sMugshotPal_Roark},
    [MUGSHOT_SABRINA] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Sabrina, .palette = sMugshotPal_Sabrina},
    [MUGSHOT_SILVER] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Silver, .palette = sMugshotPal_Silver},
    [MUGSHOT_THORTON] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Thorton, .palette = sMugshotPal_Thorton},
    [MUGSHOT_VOLKNER] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Volkner, .palette = sMugshotPal_Volkner},
    [MUGSHOT_WHITNEY] = {.x = 16, .y = 5, .width = 96, .height = 64, .image = sMugshotImg_Whitney, .palette = sMugshotPal_Whitney},
    [MUGSHOT_ALDER] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Alder, .palette = sMugshotPal_Alder},
    [MUGSHOT_BENGA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Benga, .palette = sMugshotPal_Benga},
    [MUGSHOT_BIANCA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Bianca, .palette = sMugshotPal_Bianca},
    [MUGSHOT_BRYCEN] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Brycen, .palette = sMugshotPal_Brycen},
    [MUGSHOT_BURGH] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Burgh, .palette = sMugshotPal_Burgh},
    [MUGSHOT_CAITLIN] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Caitlin, .palette = sMugshotPal_Caitlin},
    [MUGSHOT_CHEREN] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Cheren, .palette = sMugshotPal_Cheren},
    [MUGSHOT_CHEREN_2] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Cheren_2, .palette = sMugshotPal_Cheren_2},
    [MUGSHOT_CHILI] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Chili, .palette = sMugshotPal_Chili},
    [MUGSHOT_CILAN] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Cilan, .palette = sMugshotPal_Cilan},
    [MUGSHOT_CLAY] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Clay, .palette = sMugshotPal_Clay},
    [MUGSHOT_COLRESS] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Colress, .palette = sMugshotPal_Colress},
    [MUGSHOT_CRESS] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Cress, .palette = sMugshotPal_Cress},
    [MUGSHOT_DRAYDEN] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Drayden, .palette = sMugshotPal_Drayden},
    [MUGSHOT_ELESA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Elesa, .palette = sMugshotPal_Elesa},
    [MUGSHOT_ELESA_2] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Elesa_2, .palette = sMugshotPal_Elesa_2},
    [MUGSHOT_GHETSIS] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Ghetsis, .palette = sMugshotPal_Ghetsis},
    [MUGSHOT_GHETSIS_2] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Ghetsis_2, .palette = sMugshotPal_Ghetsis_2},
    [MUGSHOT_GRIMSLEY] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Grimsley, .palette = sMugshotPal_Grimsley},
    [MUGSHOT_HILBERT] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Hilbert, .palette = sMugshotPal_Hilbert},
    [MUGSHOT_HILDA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Hilda, .palette = sMugshotPal_Hilda},
    [MUGSHOT_HUGH] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Hugh, .palette = sMugshotPal_Hugh},
    [MUGSHOT_IRIS] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Iris, .palette = sMugshotPal_Iris},
    [MUGSHOT_LENORA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Lenora, .palette = sMugshotPal_Lenora},
    [MUGSHOT_MARLON] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Marlon, .palette = sMugshotPal_Marlon},
    [MUGSHOT_MARSHAL] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Marshal, .palette = sMugshotPal_Marshal},
    [MUGSHOT_N] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_N, .palette = sMugshotPal_N},
    [MUGSHOT_NATE] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Nate, .palette = sMugshotPal_Nate},
    [MUGSHOT_ROSA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Rosa, .palette = sMugshotPal_Rosa},
    [MUGSHOT_ROXIE] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Roxie, .palette = sMugshotPal_Roxie},
    [MUGSHOT_SHAUNTAL] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Shauntal, .palette = sMugshotPal_Shauntal},
    [MUGSHOT_SKYLA] = {.x = 16, .y = 5, .width = 128, .height = 64, .image = sMugshotImg_Skyla, .palette = sMugshotPal_Skyla},
};



//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;
static EWRAM_DATA u8 sPortaitSpriteID = 0;
static EWRAM_DATA u8 sPortaitPaletteID = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}

//Name Msgbox Bottom - 240 x 8
#define MESSAGE_BOX_WIDTH  240
#define MESSAGE_BOX_HEIGHT 8
#define MESSAGE_BOX_X      0
#define MESSAGE_BOX_Y      24

static const u8 sMsgbox_Top_Small[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/msgbox_top_small.4bpp");
static const u16 gMessageBox_Pal[] = INCBIN_U16("graphics/ui_menus/msgbox/message_box.gbapal");

//Phone - 16 x 16
#define PHONE_WIDTH  16
#define PHONE_HEIGHT 16
#define PHONE_X      65
#define PHONE_Y      11

static const u8 sMsgbox_Phone_On[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/phone_on.4bpp");

//Name Box - 56 x 16
#define NAME_BOX_WIDTH  8
#define NAME_BOX_HEIGHT 16
#define NAME_BOX_X      8
#define NAME_BOX_Y      10

static const u8 sMsgbox_Name_Box[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/name_box.4bpp");

//Name Box Bottom - 8 x 16
#define NAME_BOX_BOTTOM_WIDTH  8
#define NAME_BOX_BOTTOM_HEIGHT 16
#define NAME_BOX_BOTTOM_X      0
#define NAME_BOX_BOTTOM_Y      10

static const u8 sMsgbox_Name_Box_Bottom[] = INCBIN_U8("graphics/ui_menus/msgbox/phone/name_box_bottom.4bpp");

//Emotes - 48 x 32
#define EMOTES_WIDTH  48
#define EMOTES_HEIGHT 32
#define EMOTES_X      63
#define EMOTES_Y      2

static const u8 sMsgbox_Emote_Angry[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_angry.4bpp");
static const u8 sMsgbox_Emote_Confuse[] = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_confuse.4bpp");
static const u8 sMsgbox_Emote_Default[] = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_default.4bpp");
static const u8 sMsgbox_Emote_Happy[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_happy.4bpp");
static const u8 sMsgbox_Emote_Laugh[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_laugh.4bpp");
static const u8 sMsgbox_Emote_Love[]    = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_love.4bpp");
static const u8 sMsgbox_Emote_Sad[]     = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_sad.4bpp");
static const u8 sMsgbox_Emote_Shock[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_shock.4bpp");
static const u8 sMsgbox_Emote_Sweat[]   = INCBIN_U8("graphics/ui_menus/msgbox/emotes/emote_sweat.4bpp");

//Tails - 48 x 24
#define TAILS_WIDTH  48
#define TAILS_HEIGHT 24
#define TAILS_X      97
#define TAILS_Y      7

static const u8 sMsgbox_Tail_Shout[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_shout.4bpp");
static const u8 sMsgbox_Tail_Talk[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_talk.4bpp");
static const u8 sMsgbox_Tail_Thought[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_thought.4bpp");
static const u8 sMsgbox_Tail_Whisper[] = INCBIN_U8("graphics/ui_menus/msgbox/tails/tail_whisper.4bpp");

#define SPEAKER_NAME_LENGTH     12
#define SPEAKER_NAME_X          8
#define SPEAKER_NAME_Y          10
#define SPEAKER_FONT            7
#define SPEAKER_NAME_FONT_COLOR 10
#define SPEAKER_NAME_WIDTH      70
#define MAX_SPEAKER_NAME_WIDTH  79

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
};

static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]    = {TEXT_COLOR_TRANSPARENT,  13,   11},
    [FONT_WHITE]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,       TEXT_COLOR_TRANSPARENT},
};

//Faces
#define GFXTAG_SPEAKER_ICON 0x2722 //same as money label
#define SPEAKER_ICON_PAL 15
#define SPEAKER_ICON_PAL_NUM 5
#define SPEAKER_ICON_X 77
#define SPEAKER_ICON_Y 86
#define SPEAKER_ICON_SUBPRIORITY 0
#define SPEAKER_ICON_PRIORITY 0

static const u32 gSpeakerIcon_Grunt[] = INCBIN_U32("graphics/ui_menus/msgbox/npcs_icons/grunt.4bpp.lz");
static const u32 sSpeakerPal_Grunt[] = INCBIN_U32("graphics/ui_menus/msgbox/npcs_icons/grunt.gbapal.lz");

static const u32 gSpeakerIcon_Jasmine[] = INCBIN_U32("graphics/ui_menus/msgbox/npcs_icons/jasmine.4bpp.lz");
static const u32 sSpeakerPal_Jasmine[] = INCBIN_U32("graphics/ui_menus/msgbox/npcs_icons/jasmine.gbapal.lz");

struct SpeakerData
{
    const u8 name[SPEAKER_NAME_LENGTH];
    const u32 *speakerIcon;
    const u32 *speakerPal;
};

#define NUM_SPEAKERS 200
static const struct SpeakerData sSpeakerData[NUM_SPEAKERS] = {
    [SPEAKER_DEFAULT] =
    {
        .name = _("NPC"),
        .speakerIcon = gSpeakerIcon_Grunt,
        .speakerPal = sSpeakerPal_Grunt,
    },
    [SPEAKER_JASMINE] =
    {
        .name = _("Jasmine"),
        .speakerIcon = gSpeakerIcon_Jasmine,
        .speakerPal = sSpeakerPal_Jasmine,
    },
    [SPEAKER_GRUNT] =
    {
        .name = _("Grunt"),
        .speakerIcon = gSpeakerIcon_Grunt,
        .speakerPal = sSpeakerPal_Grunt,
    },
};

void DestroySpeakerIconSprite(void){
    if(sPortaitSpriteID != 0){
        FreeSpriteTilesByTag(GFXTAG_SPEAKER_ICON);
        FreeSpritePaletteByTag(sPortaitPaletteID);
        DestroySpriteAndFreeResources(&gSprites[sPortaitSpriteID]);
        sPortaitSpriteID = 0;
        VarSet(sPortaitPaletteID, 0);
        mgba_printf(MGBA_LOG_WARN, "Destroyed Sprite Num: %d", sPortaitSpriteID);
    }
}

static void CreateSpeakerIconSprite(u16 speaker, u8 offset)
{
    u8 palnum, paltag;
    u8 spriteId = MAX_SPRITES;
    u16 SpriteTag = GFXTAG_SPEAKER_ICON;
    struct CompressedSpriteSheet sSpriteSheet_Speaker_Icon;
    struct CompressedSpritePalette spritePalette;
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;
    DestroySpeakerIconSprite();

    TempSpriteTemplate.tileTag = SpriteTag;
    //FreeSpritePaletteByTag(PaletteTag);
    palnum = AllocSpritePalette(SPEAKER_ICON_PAL_NUM);
    paltag = GetSpritePaletteTagByPaletteNum(palnum);
    sPortaitPaletteID = paltag;
    FreeSpritePaletteByTag(paltag);
    
    sSpriteSheet_Speaker_Icon.data = sSpeakerData[speaker].speakerIcon;
    sSpriteSheet_Speaker_Icon.size = 0x0800;
    sSpriteSheet_Speaker_Icon.tag = SpriteTag;
    LoadCompressedSpriteSheet(&sSpriteSheet_Speaker_Icon);

    spritePalette.data = sSpeakerData[speaker].speakerPal;
    spritePalette.tag = paltag;
    LoadCompressedSpritePalette(&spritePalette);

    spriteId = CreateSprite(&TempSpriteTemplate, 0, 0, 0);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x32);
        gSprites[spriteId].oam.size = SPRITE_SIZE(32x32);

        gSprites[spriteId].x = SPEAKER_ICON_X - offset;
        gSprites[spriteId].y = SPEAKER_ICON_Y;
        gSprites[spriteId].oam.priority = 4;
        gSprites[spriteId].oam.paletteNum = palnum;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
    }

    sPortaitSpriteID = spriteId;
    VarSet(VAR_MSGBOX_SPEAKER, SPEAKER_DEFAULT);
    mgba_printf(MGBA_LOG_WARN, "New Sprite: %d", spriteId);
}

//TODO Write a constant coordinates for mugshots for protag (left) and other people (right)

#define WINDOW_SIZE 30 - 2
#define WINDOW_TITLEOFFSET 90
#define WINDOW_X 110
#define WINDOW_Y 109
#define NEW_WINDOW_WIDTH 240
#define NEW_WINDOW_HEIGHT 32
#define WINDOW_TILETOP 74
#define WINDOW_TILELEFT 0

static const u32 sMsgbox_Top_0[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_0.4bpp.lz");
static const u32 sMsgbox_Top_1[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_1.4bpp.lz");
static const u32 sMsgbox_Top_2[] = INCBIN_U32("graphics/ui_menus/msgbox/msgbox_top_smallest_2.4bpp.lz");

void ClearMessageBoxAddOns(void){
    DestroySpeakerIconSprite();
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

void DrawMessageBoxAddOns(u8 windowId){
    const u16* palette = gMessageBox_Pal;
    struct WindowTemplate t;
    int offset, offset2;
    u8 speaker = VarGet(VAR_MSGBOX_SPEAKER);
    const u8 *str = sSpeakerData[speaker].name;
    u8 emote = VarGet(VAR_MSGBOX_EMOTE);
    u8 tail = VarGet(VAR_MSGBOX_TAIL);
    u8 onPhone = VarGet(VAR_MSGBOX_PHONE);
    u8 i, x, y;
    
    if(sMugshotWindow != 0){
        ClearMessageBoxAddOns();
    }
    
    SetWindowTemplateFields(&t, 0, WINDOW_TILELEFT, WINDOW_TILETOP, NEW_WINDOW_WIDTH/8, NEW_WINDOW_HEIGHT/8, MUGSHOT_PALETTE_NUM, 0x40);
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
        
    LoadPalette(palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    //Top Left Part
    CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_0, 0, WINDOW_TITLEOFFSET);
    //Top Part
    for(i = 0; i < WINDOW_SIZE; i++)
        CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_1, 0, WINDOW_TITLEOFFSET + 1 + i);
    //Top Right Part
    CopyToWindowPixelBuffer(windowId, (const void*)sMsgbox_Top_2, 0, WINDOW_TITLEOFFSET + 1 + WINDOW_SIZE);

    if(speaker != SPEAKER_DEFAULT && speaker < NUM_SPEAKERS){
        //Name Width
        if(onPhone)
            offset = GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH) - 8 - PHONE_WIDTH;
        else
            offset = GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH) - 16;
        offset2 = MAX_SPEAKER_NAME_WIDTH - GetStringRightAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH);
        if(EMOTES_X < offset)
            offset = EMOTES_X;
        mgba_printf(MGBA_LOG_WARN, "offset %d", offset);
        //Name Box
        x = 0;
        y = 0;
        for(i = 0; i <= offset2/8; i++){
            BlitBitmapToWindow(windowId, sMsgbox_Name_Box, NAME_BOX_X + x, NAME_BOX_Y, NAME_BOX_WIDTH, NAME_BOX_HEIGHT);
            x = x + 8;
            mgba_printf(MGBA_LOG_WARN, "Time %d X Value: %d", i, NAME_BOX_X + x);
        }
        BlitBitmapToWindow(windowId, sMsgbox_Name_Box_Bottom, NAME_BOX_BOTTOM_X, NAME_BOX_BOTTOM_Y, NAME_BOX_BOTTOM_WIDTH, NAME_BOX_BOTTOM_HEIGHT);

        //Emotes
        switch(emote){
            case EMOTE_ANGRY:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Angry, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_CONFUSE:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Confuse, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_HAPPY:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Happy, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_LAUGH:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Laugh, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_LOVE:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Love, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SAD:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Sad, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SWEAT:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Sweat, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            case EMOTE_SHOCK:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Shock, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
            default:
                BlitBitmapToWindow(windowId, sMsgbox_Emote_Default, EMOTES_X - offset, EMOTES_Y, EMOTES_WIDTH, EMOTES_HEIGHT);
            break;
        }

        //Tails
        switch(tail){
            case TAIL_TALK:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Talk, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_WHISPER:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Whisper, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_SHOUT:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Shout, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            case TAIL_THOUGHT:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Thought, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
            default:
                BlitBitmapToWindow(windowId, sMsgbox_Tail_Talk, TAILS_X - offset, TAILS_Y, TAILS_WIDTH, TAILS_HEIGHT);
            break;
        }

        
        //Phone
        if(onPhone)
            BlitBitmapToWindow(windowId, sMsgbox_Phone_On, PHONE_X - offset, PHONE_Y, PHONE_WIDTH, PHONE_HEIGHT);

        //Speaker Icon
        CreateSpeakerIconSprite(speaker, offset);

        //Speaker Name
        //offset = GetStringCenterAlignXOffset(SPEAKER_FONT, str, MAX_SPEAKER_NAME_WIDTH);
        AddTextPrinterParameterized4(windowId, SPEAKER_FONT, SPEAKER_NAME_X, SPEAKER_NAME_Y, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, str);
    }

    PutWindowRectTilemap(windowId, 0, 0, NEW_WINDOW_WIDTH/8, NEW_WINDOW_HEIGHT/8);
    CopyWindowToVram(windowId, 3);
    //Cleans Vars before calling this again
    VarSet(VAR_MSGBOX_PHONE, PHONE_OFF);
    VarSet(VAR_MSGBOX_EMOTE, EMOTE_DEFAULT);
    VarSet(VAR_MSGBOX_TAIL, TAIL_DEFAULT);
}

