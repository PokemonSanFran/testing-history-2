#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

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
