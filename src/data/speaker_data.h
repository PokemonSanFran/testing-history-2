#include "main.h"
#include "constants/mugshots.h"

static const u32 gSpeakerIcon_Blaine[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/blaine.4bpp.lz");
static const u32 sSpeakerPal_Blaine[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/blaine.gbapal.lz");

static const u32 gSpeakerIcon_Brock[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/brock.4bpp.lz");
static const u32 sSpeakerPal_Brock[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/brock.gbapal.lz");

static const u32 gSpeakerIcon_Bruno[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bruno.4bpp.lz");
static const u32 sSpeakerPal_Bruno[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bruno.gbapal.lz");

static const u32 gSpeakerIcon_Bug_Catcher[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bug_catcher.4bpp.lz");
static const u32 sSpeakerPal_Bug_Catcher[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bug_catcher.gbapal.lz");

static const u32 gSpeakerIcon_Bugsy[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bugsy.4bpp.lz");
static const u32 sSpeakerPal_Bugsy[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bugsy.gbapal.lz");

static const u32 gSpeakerIcon_Chuck[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/chuck.4bpp.lz");
static const u32 sSpeakerPal_Chuck[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/chuck.gbapal.lz");

static const u32 gSpeakerIcon_Clair[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/clair.4bpp.lz");
static const u32 sSpeakerPal_Clair[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/clair.gbapal.lz");

static const u32 gSpeakerIcon_Elm[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/elm.4bpp.lz");
static const u32 sSpeakerPal_Elm[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/elm.gbapal.lz");

static const u32 gSpeakerIcon_Erika[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/erika.4bpp.lz");
static const u32 sSpeakerPal_Erika[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/erika.gbapal.lz");

static const u32 gSpeakerIcon_Falkner[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/falkner.4bpp.lz");
static const u32 sSpeakerPal_Falkner[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/falkner.gbapal.lz");

static const u32 gSpeakerIcon_Fisherman[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/fisherman.4bpp.lz");
static const u32 sSpeakerPal_Fisherman[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/fisherman.gbapal.lz");

static const u32 gSpeakerIcon_Giovanni[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/giovanni.4bpp.lz");
static const u32 sSpeakerPal_Giovanni[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/giovanni.gbapal.lz");

static const u32 gSpeakerIcon_Girl[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/girl.4bpp.lz");
static const u32 sSpeakerPal_Girl[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/girl.gbapal.lz");

static const u32 gSpeakerIcon_Green[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/green.4bpp.lz");
static const u32 sSpeakerPal_Green[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/green.gbapal.lz");

static const u32 gSpeakerIcon_Janine[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/janine.4bpp.lz");
static const u32 sSpeakerPal_Janine[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/janine.gbapal.lz");

static const u32 gSpeakerIcon_Jasmine[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/jasmine.4bpp.lz");
static const u32 sSpeakerPal_Jasmine[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/jasmine.gbapal.lz");

static const u32 gSpeakerIcon_Karen[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/karen.4bpp.lz");
static const u32 sSpeakerPal_Karen[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/karen.gbapal.lz");

static const u32 gSpeakerIcon_Kid[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kid.4bpp.lz");
static const u32 sSpeakerPal_Kid[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kid.gbapal.lz");

static const u32 gSpeakerIcon_Koga[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/koga.4bpp.lz");
static const u32 sSpeakerPal_Koga[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/koga.gbapal.lz");

static const u32 gSpeakerIcon_Kurt[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kurt.4bpp.lz");
static const u32 sSpeakerPal_Kurt[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kurt.gbapal.lz");

static const u32 gSpeakerIcon_Lance[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lance.4bpp.lz");
static const u32 sSpeakerPal_Lance[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lance.gbapal.lz");

static const u32 gSpeakerIcon_Lt_Surge[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lt_surge.4bpp.lz");
static const u32 sSpeakerPal_Lt_Surge[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lt_surge.gbapal.lz");

static const u32 gSpeakerIcon_Man[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/man.4bpp.lz");
static const u32 sSpeakerPal_Man[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/man.gbapal.lz");

static const u32 gSpeakerIcon_Misty[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/misty.4bpp.lz");
static const u32 sSpeakerPal_Misty[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/misty.gbapal.lz");

static const u32 gSpeakerIcon_Morty[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/morty.4bpp.lz");
static const u32 sSpeakerPal_Morty[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/morty.gbapal.lz");

static const u32 gSpeakerIcon_Old_Man[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/old_man.4bpp.lz");
static const u32 sSpeakerPal_Old_Man[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/old_man.gbapal.lz");

static const u32 gSpeakerIcon_Old_Woman[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/old_woman.4bpp.lz");
static const u32 sSpeakerPal_Old_Woman[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/old_woman.gbapal.lz");

static const u32 gSpeakerIcon_Policeman[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/policeman.4bpp.lz");
static const u32 sSpeakerPal_Policeman[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/policeman.gbapal.lz");

static const u32 gSpeakerIcon_Pryce[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/pryce.4bpp.lz");
static const u32 sSpeakerPal_Pryce[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/pryce.gbapal.lz");

static const u32 gSpeakerIcon_Red[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/red.4bpp.lz");
static const u32 sSpeakerPal_Red[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/red.gbapal.lz");

static const u32 gSpeakerIcon_Rocket_Grunt_F[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/rocket_grunt_f.4bpp.lz");
static const u32 sSpeakerPal_Rocket_Grunt_F[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/rocket_grunt_f.gbapal.lz");

static const u32 gSpeakerIcon_Rocket_Grunt_M[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/rocket_grunt_m.4bpp.lz");
static const u32 sSpeakerPal_Rocket_Grunt_M[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/rocket_grunt_m.gbapal.lz");

static const u32 gSpeakerIcon_Sabrina[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/sabrina.4bpp.lz");
static const u32 sSpeakerPal_Sabrina[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/sabrina.gbapal.lz");

static const u32 gSpeakerIcon_Silver[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/silver.4bpp.lz");
static const u32 sSpeakerPal_Silver[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/silver.gbapal.lz");

static const u32 gSpeakerIcon_Steven[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/steven.4bpp.lz");
static const u32 sSpeakerPal_Steven[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/steven.gbapal.lz");

static const u32 gSpeakerIcon_Swimmer_M[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/swimmer_m.4bpp.lz");
static const u32 sSpeakerPal_Swimmer_M[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/swimmer_m.gbapal.lz");

static const u32 gSpeakerIcon_Whitney[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/whitney.4bpp.lz");
static const u32 sSpeakerPal_Whitney[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/whitney.gbapal.lz");

static const u32 gSpeakerIcon_Will[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/will.4bpp.lz");
static const u32 sSpeakerPal_Will[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/will.gbapal.lz");

static const u32 gSpeakerIcon_Woman[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/woman.4bpp.lz");
static const u32 sSpeakerPal_Woman[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/woman.gbapal.lz");

static const u32 gSpeakerIcon_Youngster[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/youngster.4bpp.lz");
static const u32 sSpeakerPal_Youngster[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/youngster.gbapal.lz");

//
static const u32 gSpeakerIcon_Ace_Trainer_F[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ace_trainer_f.4bpp.lz");
static const u32 sSpeakerPal_Ace_Trainer_F[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ace_trainer_f.gbapal.lz");

static const u32 gSpeakerIcon_Ace_Trainer_M[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ace_trainer_m.4bpp.lz");
static const u32 sSpeakerPal_Ace_Trainer_M[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ace_trainer_m.gbapal.lz");

static const u32 gSpeakerIcon_Archer[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/archer.4bpp.lz");
static const u32 sSpeakerPal_Archer[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/archer.gbapal.lz");

static const u32 gSpeakerIcon_Ariana[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ariana.4bpp.lz");
static const u32 sSpeakerPal_Ariana[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/ariana.gbapal.lz");

static const u32 gSpeakerIcon_Aroma_Lady[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/aroma_lady.4bpp.lz");
static const u32 sSpeakerPal_Aroma_Lady[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/aroma_lady.gbapal.lz");

static const u32 gSpeakerIcon_Battle_Girl[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/battle_girl.4bpp.lz");
static const u32 sSpeakerPal_Battle_Girl[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/battle_girl.gbapal.lz");

static const u32 gSpeakerIcon_Beauty[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/beauty.4bpp.lz");
static const u32 sSpeakerPal_Beauty[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/beauty.gbapal.lz");

static const u32 gSpeakerIcon_Bill[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bill.4bpp.lz");
static const u32 sSpeakerPal_Bill[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bill.gbapal.lz");

static const u32 gSpeakerIcon_Bird_Keeper[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bird_keeper.4bpp.lz");
static const u32 sSpeakerPal_Bird_Keeper[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/bird_keeper.gbapal.lz");

static const u32 gSpeakerIcon_Black_Belt[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/black_belt.4bpp.lz");
static const u32 sSpeakerPal_Black_Belt[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/black_belt.gbapal.lz");

static const u32 gSpeakerIcon_Boarder[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/boarder.4bpp.lz");
static const u32 sSpeakerPal_Boarder[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/boarder.gbapal.lz");

static const u32 gSpeakerIcon_Collector[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/collector.4bpp.lz");
static const u32 sSpeakerPal_Collector[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/collector.gbapal.lz");

static const u32 gSpeakerIcon_Eusine[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/eusine.4bpp.lz");
static const u32 sSpeakerPal_Eusine[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/eusine.gbapal.lz");

static const u32 gSpeakerIcon_Juggler[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/juggler.4bpp.lz");
static const u32 sSpeakerPal_Juggler[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/juggler.gbapal.lz");

static const u32 gSpeakerIcon_Kimono_Girl[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kimono_girl.4bpp.lz");
static const u32 sSpeakerPal_Kimono_Girl[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/kimono_girl.gbapal.lz");

static const u32 gSpeakerIcon_Lass[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lass.4bpp.lz");
static const u32 sSpeakerPal_Lass[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/lass.gbapal.lz");

static const u32 gSpeakerIcon_Li[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/li.4bpp.lz");
static const u32 sSpeakerPal_Li[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/li.gbapal.lz");

static const u32 gSpeakerIcon_Medium[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/medium.4bpp.lz");
static const u32 sSpeakerPal_Medium[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/medium.gbapal.lz");

static const u32 gSpeakerIcon_Medium_2[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/medium_2.4bpp.lz");
static const u32 sSpeakerPal_Medium_2[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/medium_2.gbapal.lz");

static const u32 gSpeakerIcon_Mom[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/mom.4bpp.lz");
static const u32 sSpeakerPal_Mom[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/mom.gbapal.lz");

static const u32 gSpeakerIcon_Petrel[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/petrel.4bpp.lz");
static const u32 sSpeakerPal_Petrel[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/petrel.gbapal.lz");

static const u32 gSpeakerIcon_Poke_Maniac[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/poke_maniac.4bpp.lz");
static const u32 sSpeakerPal_Poke_Maniac[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/poke_maniac.gbapal.lz");

static const u32 gSpeakerIcon_Proton[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/proton.4bpp.lz");
static const u32 sSpeakerPal_Proton[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/proton.gbapal.lz");

static const u32 gSpeakerIcon_Sage[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/sage.4bpp.lz");
static const u32 sSpeakerPal_Sage[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/sage.gbapal.lz");

static const u32 gSpeakerIcon_Super_Nerd[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/super_nerd.4bpp.lz");
static const u32 sSpeakerPal_Super_Nerd[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/super_nerd.gbapal.lz");

static const u32 gSpeakerIcon_Waiter[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/waiter.4bpp.lz");
static const u32 sSpeakerPal_Waiter[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/waiter.gbapal.lz");

static const u32 gSpeakerIcon_Firebreather[] = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/firebreather.4bpp.lz");
static const u32 sSpeakerPal_Firebreather[]  = INCBIN_U32("graphics/ui_menus/msgbox/character_heads/firebreather.gbapal.lz");

static const struct SpeakerData sSpeakerData[NUM_SPEAKERS] = {
    [SPEAKER_DEFAULT] =
    {
        .name = _("NPC"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_JASMINE] =
    {
        .name = _("Jasmine"),
        .speakerIcon = gSpeakerIcon_Jasmine,
        .speakerPal = sSpeakerPal_Jasmine,
    },
    [SPEAKER_GRUNT] =
    {
        .name = _("Rocket Grunt"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_BLAINE] =
    {
        .name = _("Blaine"),
        .speakerIcon = gSpeakerIcon_Blaine,
        .speakerPal = sSpeakerPal_Blaine,
    },
    [SPEAKER_BROCK] =
    {
        .name = _("Brock"),
        .speakerIcon = gSpeakerIcon_Brock,
        .speakerPal = sSpeakerPal_Brock,
    },
    [SPEAKER_BRUNO] =
    {
        .name = _("Bruno"),
        .speakerIcon = gSpeakerIcon_Bruno,
        .speakerPal = sSpeakerPal_Bruno,
    },
    [SPEAKER_BUG_CATCHER] =
    {
        .name = _("Bug Catcher"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_BUGSY] =
    {
        .name = _("Bugsy"),
        .speakerIcon = gSpeakerIcon_Bugsy,
        .speakerPal = sSpeakerPal_Bugsy,
    },
    [SPEAKER_CHUCK] =
    {
        .name = _("Chuck"),
        .speakerIcon = gSpeakerIcon_Chuck,
        .speakerPal = sSpeakerPal_Chuck,
    },
    [SPEAKER_CLAIR] =
    {
        .name = _("Clair"),
        .speakerIcon = gSpeakerIcon_Clair,
        .speakerPal = sSpeakerPal_Clair,
    },
    [SPEAKER_ELM] =
    {
        .name = _("Elm"),
        .speakerIcon = gSpeakerIcon_Elm,
        .speakerPal = sSpeakerPal_Elm,
    },
    [SPEAKER_ERIKA] =
    {
        .name = _("Erika"),
        .speakerIcon = gSpeakerIcon_Erika,
        .speakerPal = sSpeakerPal_Erika,
    },
    [SPEAKER_FALKNER] =
    {
        .name = _("Falkner"),
        .speakerIcon = gSpeakerIcon_Falkner,
        .speakerPal = sSpeakerPal_Falkner,
    },
    [SPEAKER_FISHERMAN] =
    {
        .name = _("Fisherman"),
        .speakerIcon = gSpeakerIcon_Fisherman,
        .speakerPal = sSpeakerPal_Fisherman,
    },
    [SPEAKER_GIOVANNI] =
    {
        .name = _("Giovanni"),
        .speakerIcon = gSpeakerIcon_Giovanni,
        .speakerPal = sSpeakerPal_Giovanni,
    },
    [SPEAKER_GIRL] =
    {
        .name = _("Girl"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_GREEN] =
    {
        .name = _("Green"),
        .speakerIcon = gSpeakerIcon_Green,
        .speakerPal = sSpeakerPal_Green,
    },
    [SPEAKER_JANINE] =
    {
        .name = _("Janine"),
        .speakerIcon = gSpeakerIcon_Janine,
        .speakerPal = sSpeakerPal_Janine,
    },
    [SPEAKER_KAREN] =
    {
        .name = _("Karen"),
        .speakerIcon = gSpeakerIcon_Karen,
        .speakerPal = sSpeakerPal_Karen,
    },
    [SPEAKER_KID] =
    {
        .name = _("Kid"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_KOGA] =
    {
        .name = _("Koga"),
        .speakerIcon = gSpeakerIcon_Koga,
        .speakerPal = sSpeakerPal_Koga,
    },
    [SPEAKER_KURT] =
    {
        .name = _("Kurt"),
        .speakerIcon = gSpeakerIcon_Kurt,
        .speakerPal = sSpeakerPal_Kurt,
    },
    [SPEAKER_LANCE] =
    {
        .name = _("Lance"),
        .speakerIcon = gSpeakerIcon_Lance,
        .speakerPal = sSpeakerPal_Lance,
    },
    [SPEAKER_LT_SURGE] =
    {
        .name = _("Lt.Surge"),
        .speakerIcon = gSpeakerIcon_Lt_Surge,
        .speakerPal = sSpeakerPal_Lt_Surge,
    },
    [SPEAKER_MAN] =
    {
        .name = _("Man"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_MISTY] =
    {
        .name = _("Misty"),
        .speakerIcon = gSpeakerIcon_Misty,
        .speakerPal = sSpeakerPal_Misty,
    },
    [SPEAKER_MORTY] =
    {
        .name = _("Morty"),
        .speakerIcon = gSpeakerIcon_Morty,
        .speakerPal = sSpeakerPal_Morty,
    },
    [SPEAKER_OLD_MAN] =
    {
        .name = _("Old Man"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_POLICEMAN] =
    {
        .name = _("Policeman"),
        .speakerIcon = gSpeakerIcon_Policeman,
        .speakerPal = sSpeakerPal_Policeman,
    },
    [SPEAKER_PRYCE] =
    {
        .name = _("Pryce"),
        .speakerIcon = gSpeakerIcon_Pryce,
        .speakerPal = sSpeakerPal_Pryce,
    },
    [SPEAKER_RED] =
    {
        .name = _("Red"),
        .speakerIcon = gSpeakerIcon_Red,
        .speakerPal = sSpeakerPal_Red,
    },
    [SPEAKER_ROCKET_GRUNT_MALE] =
    {
        .name = _("Rocket Grunt"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_ROCKET_GRUNT_FEMALE] =
    {
        .name = _("Rocket Grunt"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_F,
        .speakerPal = sSpeakerPal_Rocket_Grunt_F,
    },
    [SPEAKER_SABRINA] =
    {
        .name = _("Sabrina"),
        .speakerIcon = gSpeakerIcon_Sabrina,
        .speakerPal = sSpeakerPal_Sabrina,
    },
    [SPEAKER_SILVER] =
    {
        .name = _("Silver"),
        .speakerIcon = gSpeakerIcon_Silver,
        .speakerPal = sSpeakerPal_Silver,
    },
    [SPEAKER_STEVEN] =
    {
        .name = _("Steven"),
        .speakerIcon = gSpeakerIcon_Steven,
        .speakerPal = sSpeakerPal_Steven,
    },
    [SPEAKER_SWIMMER_MALE] =
    {
        .name = _("Swimmer"),
        .speakerIcon = gSpeakerIcon_Swimmer_M,
        .speakerPal = sSpeakerPal_Swimmer_M,
    },
    [SPEAKER_WHITNEY] =
    {
        .name = _("Whitney"),
        .speakerIcon = gSpeakerIcon_Whitney,
        .speakerPal = sSpeakerPal_Whitney,
    },
    [SPEAKER_WILL] =
    {
        .name = _("Will"),
        .speakerIcon = gSpeakerIcon_Will,
        .speakerPal = sSpeakerPal_Will,
    },
    [SPEAKER_WOMAN] =
    {
        .name = _("Woman"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_YOUNGSTER] =
    {
        .name = _("Youngster"),
        .speakerIcon = gSpeakerIcon_Youngster,
        .speakerPal = sSpeakerPal_Youngster,
    },
    [SPEAKER_FIREBREATHER] =
    {
        .name = _("Firebreather"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_BEAUTY] =
    {
        .name = _("Beauty"),
        .speakerIcon = gSpeakerIcon_Beauty,
        .speakerPal = sSpeakerPal_Beauty,
    },
    [SPEAKER_BIRD_KEEPER] =
    {
        .name = _("Bird Keeper"),
        .speakerIcon = gSpeakerIcon_Bird_Keeper,
        .speakerPal = sSpeakerPal_Bird_Keeper,
    },
    [SPEAKER_BLACK_BELT] =
    {
        .name = _("Black Belt"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_EUSINE] =
    {
        .name = _("Eusine"),
        .speakerIcon = gSpeakerIcon_Eusine,
        .speakerPal = sSpeakerPal_Eusine,
    },
    [SPEAKER_PROTON] =
    {
        .name = _("Proton"),
        .speakerIcon = gSpeakerIcon_Proton,
        .speakerPal = sSpeakerPal_Proton,
    },
    [SPEAKER_PETREL] =
    {
        .name = _("Petrel"),
        .speakerIcon = gSpeakerIcon_Petrel,
        .speakerPal = sSpeakerPal_Petrel,
    },
    [SPEAKER_ARIANA] =
    {
        .name = _("Ariana"),
        .speakerIcon = gSpeakerIcon_Ariana,
        .speakerPal = sSpeakerPal_Ariana,
    },
    [SPEAKER_ARCHER] =
    {
        .name = _("Archer"),
        .speakerIcon = gSpeakerIcon_Archer,
        .speakerPal = sSpeakerPal_Archer,
    },
    [SPEAKER_COLLECTOR] =
    {
        .name = _("Collector"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_BILL] =
    {
        .name = _("Bill"),
        .speakerIcon = gSpeakerIcon_Bill,
        .speakerPal = sSpeakerPal_Bill,
    },
    [SPEAKER_BOARDER] =
    {
        .name = _("Boarder"),
        .speakerIcon = gSpeakerIcon_Boarder,
        .speakerPal = sSpeakerPal_Boarder,
    },
    [SPEAKER_JUGGLER] =
    {
        .name = _("Juggler"),
        .speakerIcon = gSpeakerIcon_Juggler,
        .speakerPal = sSpeakerPal_Juggler,
    },
    [SPEAKER_KIMONO_GIRL] =
    {
        .name = _("Kimono Girl"),
        .speakerIcon = gSpeakerIcon_Kimono_Girl,
        .speakerPal = sSpeakerPal_Kimono_Girl,
    },
    [SPEAKER_LASS] =
    {
        .name = _("Lass"),
        .speakerIcon = gSpeakerIcon_Lass,
        .speakerPal = sSpeakerPal_Lass,
    },
    [SPEAKER_MEDIUM] =
    {
        .name = _("Medium"),
        .speakerIcon = gSpeakerIcon_Medium,
        .speakerPal = sSpeakerPal_Medium,
    },
    [SPEAKER_MEDIUM_2] =
    {
        .name = _("Medium"),
        .speakerIcon = gSpeakerIcon_Medium_2,
        .speakerPal = sSpeakerPal_Medium_2,
    },
    [SPEAKER_POKE_MANIAC] =
    {
        .name = _("Poke Maniac"),
        .speakerIcon = gSpeakerIcon_Poke_Maniac,
        .speakerPal = sSpeakerPal_Poke_Maniac,
    },
    [SPEAKER_SAGE] =
    {
        .name = _("Sage"),
        .speakerIcon = gSpeakerIcon_Sage,
        .speakerPal = sSpeakerPal_Sage,
    },
    [SPEAKER_SUPER_NERD] =
    {
        .name = _("Super Nerd"),
        .speakerIcon = gSpeakerIcon_Super_Nerd,
        .speakerPal = sSpeakerPal_Super_Nerd,
    },
    [SPEAKER_ACE_TRAINER_M] =
    {
        .name = _("Ace Trainer"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_M,
        .speakerPal = sSpeakerPal_Ace_Trainer_M,
    },
    [SPEAKER_ACE_TRAINER_F] =
    {
        .name = _("Ace Trainer"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_F,
        .speakerPal = sSpeakerPal_Ace_Trainer_F,
    },
    [SPEAKER_LI] =
    {
        .name = _("Li"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },
    [SPEAKER_AROMA_LADY] =
    {
        .name = _("Aroma Lady"),
        .speakerIcon = gSpeakerIcon_Aroma_Lady,
        .speakerPal = sSpeakerPal_Aroma_Lady,
    },
    [SPEAKER_BATTLE_GIRL] =
    {
        .name = _("Battle Girl"),
        .speakerIcon = gSpeakerIcon_Battle_Girl,
        .speakerPal = sSpeakerPal_Battle_Girl,
    },
    [SPEAKER_MOM] =
    {
        .name = _("Mom"),
        .speakerIcon = gSpeakerIcon_Mom,
        .speakerPal = sSpeakerPal_Mom,
    },
    [SPEAKER_WAITER] =
    {
        .name = _("Waiter"),
        .speakerIcon = gSpeakerIcon_Waiter,
        .speakerPal = sSpeakerPal_Waiter,
    },
    [SPEAKER_NEWS] =
    {
        .name = _("News"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_ZOEY] =
    {
        .name = _("Zoey"),
        .speakerIcon = gSpeakerIcon_Mom,
        .speakerPal = sSpeakerPal_Mom,
    },
    [SPEAKER_BIANCA] =
    {
        .name = _("Bianca"),
        .speakerIcon = gSpeakerIcon_Silver,
        .speakerPal = sSpeakerPal_Silver,
    },
    [SPEAKER_BART] =
    {
        .name = _("B.A.R.T."),
        .speakerIcon = gSpeakerIcon_Policeman,
        .speakerPal = sSpeakerPal_Policeman,
    },
    [SPEAKER_MARKETING_STAFF] =
    {
        .name = _("Marketing Staff"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_ANNOUNCER] =
    {
        .name = _("Announcer"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_MALVA] =
    {
        .name = _("Malva"),
        .speakerIcon = gSpeakerIcon_Will,
        .speakerPal = sSpeakerPal_Will,
    },
    [SPEAKER_CROWD_A] =
    {
        .name = _("Crowd Member"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_M,
        .speakerPal = sSpeakerPal_Ace_Trainer_M,
    },
    [SPEAKER_CROWD_B] =
    {
        .name = _("Crowd Member"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_F,
        .speakerPal = sSpeakerPal_Ace_Trainer_F,
    },
    [SPEAKER_CROWD_C] =
    {
        .name = _("Crowd Member"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_CROWD_D] =
    {
        .name = _("Crowd Member"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_RUPERT] =
    {
        .name = _("Rupert"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_OAK] =
    {
        .name = _("Oak"),
        .speakerIcon = gSpeakerIcon_Elm,
        .speakerPal = sSpeakerPal_Elm,
    },
    [SPEAKER_RESIDENT_A] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_M,
        .speakerPal = sSpeakerPal_Ace_Trainer_M,
    },
    [SPEAKER_RESIDENT_B] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_F,
        .speakerPal = sSpeakerPal_Ace_Trainer_F,
    },
    [SPEAKER_RESIDENT_C] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_RESIDENT_D] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_SIARL] =
    {
        .name =_("Siarl"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_SIEBOLD] =
    {
        .name =_("Siebold"),
        .speakerIcon = gSpeakerIcon_Bruno,
        .speakerPal = sSpeakerPal_Bruno,
    },
    [SPEAKER_DAGMAR] =
    {
        .name = _("Dagmar"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_GURL] =
    {
        .name = _("Gurl"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_LEAGUE_STAFF_A] =
    {
        .name = _("League Staff"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_DAVID] =
    {
        .name = _("David"),
        .speakerIcon = gSpeakerIcon_Waiter,
        .speakerPal = sSpeakerPal_Waiter,
    },
    [SPEAKER_ISHAN] =
    {
        .name =_("Ishan"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_F,
        .speakerPal = sSpeakerPal_Rocket_Grunt_F,
    },
    [SPEAKER_ROCKET_MEMBER_A] =
    {
        .name = _("Teamrocket Member"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_M,
        .speakerPal = sSpeakerPal_Rocket_Grunt_M,
    },
    [SPEAKER_ROCKET_MEMBER_B] =
    {
        .name = _("Teamrocket Member"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_F,
        .speakerPal = sSpeakerPal_Rocket_Grunt_F,
    },
    [SPEAKER_ROSE] =
    {
        .name = _("Rose"),
        .speakerIcon = gSpeakerIcon_Proton,
        .speakerPal = sSpeakerPal_Proton,
    },
    [SPEAKER_VITOMIR] =
    {
        .name = _("Vitomir"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_F,
        .speakerPal = sSpeakerPal_Rocket_Grunt_F,
    },
    [SPEAKER_RABIA] =
    {
        .name = _("Rabia"),
        .speakerIcon = gSpeakerIcon_Rocket_Grunt_F,
        .speakerPal = sSpeakerPal_Rocket_Grunt_F,
    },
    [SPEAKER_LANDLORD] =
    {
        .name = _("Landlord"),
        .speakerIcon = gSpeakerIcon_Juggler,
        .speakerPal = sSpeakerPal_Juggler,
    },
    [SPEAKER_PROTEST_A] =
    {
        .name = _("Protestor"),
        .speakerIcon = gSpeakerIcon_Aroma_Lady,
        .speakerPal = sSpeakerPal_Aroma_Lady,
    },
    [SPEAKER_PROTEST_B] =
    {
        .name = _("Protestor"),
        .speakerIcon = gSpeakerIcon_Beauty,
        .speakerPal = sSpeakerPal_Beauty,
    },
    [SPEAKER_PROTEST_C] =
    {
        .name = _("Protestor"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_PROTEST_D] =
    {
        .name = _("Protestor"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_JULIUS] =
    {
        .name = _("Julius"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_MADISON] =
    {
        .name = _("Madison"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_STRANDED_A] =
    {
        .name = _("Stranded Citizen"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_STRANDED_B] =
    {
        .name = _("Stranded Citizen"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_RESIDENT_E] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_RESIDENT_F] =
    {
        .name = _("Resident"),
        .speakerIcon = gSpeakerIcon_Fisherman,
        .speakerPal = sSpeakerPal_Fisherman,
    },
    [SPEAKER_DRASNA] =
    {
        .name = _("Drasna"),
        .speakerIcon = gSpeakerIcon_Steven,
        .speakerPal = sSpeakerPal_Steven,
    },
    [SPEAKER_WIKSTROM] =
    {
        .name = _("Wikstrom"),
        .speakerIcon = gSpeakerIcon_Karen,
        .speakerPal = sSpeakerPal_Karen,
    },
    [SPEAKER_ALEKSANDER] =
    {
        .name = _("Aleksander"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_SUMMER] =
    {
        .name = _("Summer"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_MAID] =
    {
        .name = _("Maid"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_NEWS_B] =
    {
        .name = _("News"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },
        [SPEAKER_ARNAV] =
    {
        .name = _("Arnav"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },
    [SPEAKER_OLIVER] =
    {
        .name = _("Oliver"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },
    [SPEAKER_CHIEF] =
    {
        .name = _("Chief"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },
    [SPEAKER_CILAN] =
    {
        .name = _("Cilan"),
        .speakerIcon = gSpeakerIcon_Brock,
        .speakerPal = sSpeakerPal_Brock,
    },
    [SPEAKER_LENORA] =
    {
        .name = _("Lenora"),
        .speakerIcon = gSpeakerIcon_Misty,
        .speakerPal = sSpeakerPal_Misty,
    },
    [SPEAKER_DOOR] =
    {
        .name = _("Door"),
        .speakerIcon = gSpeakerIcon_Misty,
        .speakerPal = sSpeakerPal_Misty,
    },
    [SPEAKER_TEODORO] =
    {
        .name = _("Teodoro"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_DUDLEY] =
    {
        .name = _("Dudley"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_CHERIE] =
    {
        .name = _("Cherie"),
        .speakerIcon = gSpeakerIcon_Medium,
        .speakerPal = sSpeakerPal_Medium,
    },
    [SPEAKER_MATTHEW] =
    {
        .name = _("Matthew"),
        .speakerIcon = gSpeakerIcon_Swimmer_M,
        .speakerPal = sSpeakerPal_Swimmer_M,
    },
    [SPEAKER_FANNY] =
    {
        .name = _("Fanny"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_CRAIG] =
    {
        .name = _("Craig"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_ANTONE] =
    {
        .name = _("Antone"),
        .speakerIcon = gSpeakerIcon_Boarder,
        .speakerPal = sSpeakerPal_Boarder,
    },
    [SPEAKER_ORI] =
    {
        .name = _("Ori"),
        .speakerIcon = gSpeakerIcon_Old_Woman,
        .speakerPal = sSpeakerPal_Old_Woman,
    },
    [SPEAKER_HIKO] =
    {
        .name = _("Hiko"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_POLICE] =
    {
        .name = _("Police"),
        .speakerIcon = gSpeakerIcon_Policeman,
        .speakerPal = sSpeakerPal_Policeman,
    },
    [SPEAKER_MACK] =
    {
        .name = _("Mack"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_TYZONN] =
    {
        .name = _("Tyzonn"),
        .speakerIcon = gSpeakerIcon_Fisherman,
        .speakerPal = sSpeakerPal_Fisherman,
    },
    [SPEAKER_WILL2] =
    {
        .name = _("Will"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_RONNY] =
    {
        .name = _("Ronny"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_DAX] =
    {
        .name = _("Dax"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_BRENNAN] =
    {
        .name = _("Brennan"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_ATTENDANT] =
    {
        .name = _("Exhibit Attendant"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_SPEAKER] =
    {
        .name = _("Speaker"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_GHOST] =
    {
        .name = _("Ghost"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_ISMAIL] =
    {
        .name = _("Ismail"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_SERGEY] =
    {
        .name = _("Sergey"),
        .speakerIcon = gSpeakerIcon_Collector,
        .speakerPal = sSpeakerPal_Collector,
    },
    [SPEAKER_REPORTER] =
    {
        .name = _("Reporter"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_STAN_SOMA] =
    {
        .name = _("Wallace Stan"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_TROLLEY_GUY] =
    {
        .name = _("Trolley Guy"),
        .speakerIcon = gSpeakerIcon_Man,
        .speakerPal = sSpeakerPal_Man,
    },
    [SPEAKER_HESTER] =
    {
        .name = _("Hester"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_YCOMBINATOR_STAFF] =
    {
        .name = _("Ycombinator Staff"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_TONALLI] =
    {
        .name = _("Tonalli"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_DRUMMER_B] =
    {
        .name = _("Drummer"),
        .speakerIcon = gSpeakerIcon_Swimmer_M,
        .speakerPal = sSpeakerPal_Swimmer_M,
    },
    [SPEAKER_DRUMMER_C] =
    {
        .name = _("Drummer"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_DRUMMER_D] =
    {
        .name = _("Drummer"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_LIIDIA] =
    {
        .name = _("Liidia"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
    [SPEAKER_RAINER] =
    {
        .name = _("Rainer"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_BRONSON] =
    {
        .name = _("Bronson"),
        .speakerIcon = gSpeakerIcon_Lt_Surge,
        .speakerPal = sSpeakerPal_Lt_Surge,
    },
    [SPEAKER_SHASHI] =
    {
        .name = _("Shashi"),
        .speakerIcon = gSpeakerIcon_Erika,
        .speakerPal = sSpeakerPal_Erika,
    },
    [SPEAKER_LEAH] =
    {
        .name = _("Leah"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_GUARD] =
    {
        .name = _("Guard"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_SHOPKEEPER] =
    {
        .name = _("Shopkeeper"),
        .speakerIcon = gSpeakerIcon_Green,
        .speakerPal = sSpeakerPal_Green,
    },
    [SPEAKER_ELIOR] =
    {
        .name = _("Elior"),
        .speakerIcon = gSpeakerIcon_Fisherman,
        .speakerPal = sSpeakerPal_Fisherman,
    },
    [SPEAKER_LELAND] =
    {
        .name = _("Leland"),
        .speakerIcon = gSpeakerIcon_Old_Man,
        .speakerPal = sSpeakerPal_Old_Man,
    },
    [SPEAKER_AMBROGIO] =
    {
        .name = _("Ambrogio"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_JORIS] =
    {
        .name = _("Joris"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
    [SPEAKER_NURSE] =
    {
        .name = _("Nurse"),
        .speakerIcon = gSpeakerIcon_Woman,
        .speakerPal = sSpeakerPal_Woman,
    },
        [SPEAKER_AUGUSTE] =
    {
        .name = _("Auguste"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },
    [SPEAKER_JULIA] =
    {
        .name = _("Julia"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_F,
        .speakerPal = sSpeakerPal_Ace_Trainer_F,
    },
    [SPEAKER_ALICE] =
    {
        .name = _("Alice"),
        .speakerIcon = gSpeakerIcon_Bill,
        .speakerPal = sSpeakerPal_Bill,
    },
    [SPEAKER_FERRAN] =
    {
        .name = _("Ferran"),
        .speakerIcon = gSpeakerIcon_Poke_Maniac,
        .speakerPal = sSpeakerPal_Poke_Maniac,
    },
    [SPEAKER_ANTHONY] =
    {
        .name = _("Anthony"),
        .speakerIcon = gSpeakerIcon_Swimmer_M,
        .speakerPal = sSpeakerPal_Swimmer_M,
    },
    [SPEAKER_SEVENSISTERS_TINA] =
	{
        .name = _("Tina"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_F,
        .speakerPal = sSpeakerPal_Ace_Trainer_F,
    },

	[SPEAKER_SEVENSISTERS_PAUL] =
	{
        .name = _("Paul"),
        .speakerIcon = gSpeakerIcon_Kurt,
        .speakerPal = sSpeakerPal_Kurt,
    },

	[SPEAKER_SEVENSISTERS_JON] =
	{
        .name = _("Jon"),
        .speakerIcon = gSpeakerIcon_Lass,
        .speakerPal = sSpeakerPal_Lass,
    },

	[SPEAKER_SEVENSISTERS_BRADLEY] =
	{
        .name = _("Bradley"),
        .speakerIcon = gSpeakerIcon_Li,
        .speakerPal = sSpeakerPal_Li,
    },

	[SPEAKER_SEVENSISTERS_JO] =
	{
        .name = _("Jo"),
        .speakerIcon = gSpeakerIcon_Bird_Keeper,
        .speakerPal = sSpeakerPal_Bird_Keeper,
    },

	[SPEAKER_SEVENSISTERS_HANNAH] =
	{
        .name = _("Hannah"),
        .speakerIcon = gSpeakerIcon_Bug_Catcher,
        .speakerPal = sSpeakerPal_Bug_Catcher,
    },

	[SPEAKER_SEVENSISTERS_RACHEL] =
	{
        .name = _("Rachel"),
        .speakerIcon = gSpeakerIcon_Battle_Girl,
        .speakerPal = sSpeakerPal_Battle_Girl,
    },
    [SPEAKER_KATHARINA] =
    {
        .name = _("Katharina"),
        .speakerIcon = gSpeakerIcon_Aroma_Lady,
        .speakerPal = sSpeakerPal_Aroma_Lady,
    },
    [SPEAKER_OFFICIANT] =
    {
        .name = _("Officiant"),
        .speakerIcon = gSpeakerIcon_Old_Woman,
        .speakerPal = sSpeakerPal_Old_Woman,
    },
    [SPEAKER_HELEN] =
    {
        .name = _("Helen"),
        .speakerIcon = gSpeakerIcon_Fisherman,
        .speakerPal = sSpeakerPal_Fisherman,
    },
        [SPEAKER_RUSTY] =
    {
        .name = _("Rusty"),
        .speakerIcon = gSpeakerIcon_Kid,
        .speakerPal = sSpeakerPal_Kid,
    },
        [SPEAKER_WILLOW] =
    {
        .name = _("Willow"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
        [SPEAKER_GRIFF] =
    {
        .name = _("Griff"),
        .speakerIcon = gSpeakerIcon_Youngster,
        .speakerPal = sSpeakerPal_Youngster,
    },
        [SPEAKER_LUNA] =
    {
        .name = _("Luna"),
        .speakerIcon = gSpeakerIcon_Bill,
        .speakerPal = sSpeakerPal_Bill,
    },
        [SPEAKER_MAX] =
    {
        .name = _("Max"),
        .speakerIcon = gSpeakerIcon_Bird_Keeper,
        .speakerPal = sSpeakerPal_Bird_Keeper,
    },
    [SPEAKER_BLAZE] =
    {
        .name = _("B-Boy Blaze"),
        .speakerIcon = gSpeakerIcon_Petrel,
        .speakerPal = sSpeakerPal_Petrel,
    },
    [SPEAKER_KIKI] =
    {
        .name = _("Krumpin' Kiki"),
        .speakerIcon = gSpeakerIcon_Blaine,
        .speakerPal = sSpeakerPal_Blaine,
    },
    [SPEAKER_EJ] =
    {
        .name = _("Electric EJ"),
        .speakerIcon = gSpeakerIcon_Poke_Maniac,
        .speakerPal = sSpeakerPal_Poke_Maniac,
    },
    [SPEAKER_WAITE] =
    {
        .name = _("Waite"),
        .speakerIcon = gSpeakerIcon_Ace_Trainer_M,
        .speakerPal = sSpeakerPal_Ace_Trainer_M,
    },
    [SPEAKER_DEBRA] =
    {
        .name = _("Debra"),
        .speakerIcon = gSpeakerIcon_Battle_Girl,
        .speakerPal = sSpeakerPal_Battle_Girl,
    },
    [SPEAKER_WALDRON] =
    {
        .name = _("Waldron"),
        .speakerIcon = gSpeakerIcon_Swimmer_M,
        .speakerPal = sSpeakerPal_Swimmer_M,
    },
    [SPEAKER_ISIDORE] =
    {
        .name = _("Isidore"),
        .speakerIcon = gSpeakerIcon_Black_Belt,
        .speakerPal = sSpeakerPal_Black_Belt,
    },
    [SPEAKER_FILIP] =
    {
        .name = _("Filip"),
        .speakerIcon = gSpeakerIcon_Petrel,
        .speakerPal = sSpeakerPal_Petrel,
    },
    [SPEAKER_GERTRUDE] =
    {
        .name =_("Gertrude"),
        .speakerIcon = gSpeakerIcon_Erika,
        .speakerPal = sSpeakerPal_Erika,
    },
    [SPEAKER_KHALEEL] =
    {
    .name = _("Khaleel"),
    .speakerIcon = gSpeakerIcon_Medium_2,
    .speakerPal = sSpeakerPal_Medium_2,
    },
    [SPEAKER_AUGUSTA] =
    {
        .name = _("Augusta"),
        .speakerIcon = gSpeakerIcon_Bill,
        .speakerPal = sSpeakerPal_Bill,
    },
    [SPEAKER_NANCY] =
    {
        .name = _("Nancy"),
        .speakerIcon = gSpeakerIcon_Kurt,
        .speakerPal = sSpeakerPal_Kurt,
    },
    [SPEAKER_PANNEN] =
    {
        .name = _("Pannen"),
        .speakerIcon = gSpeakerIcon_Super_Nerd,
        .speakerPal = sSpeakerPal_Super_Nerd,
    },
    [SPEAKER_MADRONE] =
    {
        .name = _("Professor Madrone"),
        .speakerIcon = gSpeakerIcon_Elm,
        .speakerPal = sSpeakerPal_Elm,
    },
    [SPEAKER_TWITTER_CEO] =
    {
        .name = _("Twitter CEO"),
        .speakerIcon = gSpeakerIcon_Medium_2,
        .speakerPal = sSpeakerPal_Medium_2,
    },
    [SPEAKER_AMAZON_CEO] =
    {
        .name = _("Amazon CEO"),
        .speakerIcon = gSpeakerIcon_Steven,
        .speakerPal = sSpeakerPal_Steven,
    },
    [SPEAKER_UBER_DRIVER1] =
    {
        .name = _("Uber Driver 1"),
        .speakerIcon = gSpeakerIcon_Brock,
        .speakerPal = sSpeakerPal_Brock,
    },
    [SPEAKER_UBER_DRIVER2] =
    {
        .name = _("Uber Driver 2"),
        .speakerIcon = gSpeakerIcon_Firebreather,
        .speakerPal = sSpeakerPal_Firebreather,
    },
    [SPEAKER_UBER_DRIVER3] =
    {
        .name = _("Uber Driver 3"),
        .speakerIcon = gSpeakerIcon_Boarder,
        .speakerPal = sSpeakerPal_Boarder,
    },
    [SPEAKER_PERSUASIVE_LANDLORD] =
    {
        .name = _("Landlord"),
        .speakerIcon = gSpeakerIcon_Blaine,
        .speakerPal = sSpeakerPal_Blaine,
    },
    [SPEAKER_PERSUASIVE_SIBLING] =
    {
        .name =_("Sibling"),
        .speakerIcon = gSpeakerIcon_Battle_Girl,
        .speakerPal = sSpeakerPal_Battle_Girl,
    },
    [SPEAKER_UBER_GRUNT1] =
    {
        .name =_("Uber Grunt 1"),
        .speakerIcon = gSpeakerIcon_Medium_2,
        .speakerPal = sSpeakerPal_Medium_2,
    },
    [SPEAKER_UBER_GRUNT2] =
    {
        .name =_("Uber Grunt 2"),
        .speakerIcon = gSpeakerIcon_Policeman,
        .speakerPal = sSpeakerPal_Policeman,
    },
    [SPEAKER_UBER_CEO] =
    {
        .name = _("Uber CEO"),
        .speakerIcon = gSpeakerIcon_Policeman,
        .speakerPal = sSpeakerPal_Policeman,
    },
    [SPEAKER_GYM_ATTENDANT] =
    {
        .name = _("Gym Attendant"),
        .speakerIcon = gSpeakerIcon_Bugsy,
        .speakerPal = sSpeakerPal_Bugsy,
    },
    [SPEAKER_IMPROV_1] =
    {
        .name = _("Improv 1"),
        .speakerIcon = gSpeakerIcon_Medium,
        .speakerPal = sSpeakerPal_Medium,
    },
    [SPEAKER_IMPROV_2] =
    {
        .name = _("Improv 2"),
        .speakerIcon = gSpeakerIcon_Girl,
        .speakerPal = sSpeakerPal_Girl,
    },
    [SPEAKER_IMPROV_3] =
    {
        .name = _("Improv 3"),
        .speakerIcon = gSpeakerIcon_Beauty,
        .speakerPal = sSpeakerPal_Beauty,
    },
    [SPEAKER_CHRIS] =
    {
        .name = _("Chris"),
        .speakerIcon = gSpeakerIcon_Green,
        .speakerPal = sSpeakerPal_Green,
    }
};
