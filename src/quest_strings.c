#include "global.h"
#include "strings.h"

const u8 gText_QuestAnnounce[] = _("The quest '{STR_VAR_1}'\nis now {STR_VAR_2}.");

const u8 gText_Quest_PlayersAdventure_Name[] = _("{PLAYER}'s Adventure");
const u8 gText_Quest_PlayersAdventure_Desc[] = _("Get some sleep,\nyour big adventure starts tomorrow!");
const u8 gText_Quest_PlayersAdventure_DoneDesc[] = _("Completed Quest 1");
const u8 gText_Quest_PlayersAdventure_Map[] = _("SanFran Region");

const u8 gText_Quest_ReturnDoll_Name[] = _("Return Doll");
const u8 gText_Quest_ReturnDoll_Desc[] = _("Help Abigayle find her lost doll. The\nlast time she saw it was in Sunset.");
const u8 gText_Quest_ReturnDoll_DoneDesc[] = _("You found Abigayle's lost doll in Sunset\nand returned it to her.");
const u8 gText_Quest_ReturnDoll_Map[] = _("Bernalheights");

const u8 gText_Quest_BringFruit_Name[] = _("Bring Fruit");
const u8 gText_Quest_BringFruit_Desc[] = _("Hester can't leave his post, but needs\n6 Watmel Berries.\nYou have {STR_VAR_1} right now.");
const u8 gText_Quest_BringFruit_DoneDesc[] = _("You brought 6 Watmel Berries to Hester.");
const u8 gText_Quest_BringFruit_Map[] = _("Mission");

const u8 gText_Quest_BringFireType_Name[] = _("Bring Fire-type");
const u8 gText_Quest_BringFireType_Desc[] = _("Marcel wants to stop using propane\nin favor of a Fire-type Pokemon. Bring\nthem one!");
const u8 gText_Quest_BringFireType_DoneDesc[] = _("You brought Marcel a Fire-type\nto power their grill.");
const u8 gText_Quest_BringFireType_Map[] = _("Tenderloin");

const u8 gText_Quest_StopMugging_Name[] = _("Stop Mugging");
const u8 gText_Quest_StopMugging_Desc[] = _("Somebody is getting mugged in an alley way. Stop the perpatrators!");
const u8 gText_Quest_StopMugging_DoneDesc[] = _("You stopped a mugging from taking\nplace.");
const u8 gText_Quest_StopMugging_Map[] = _("SOMA");

const u8 gText_Quest_StolenTrade_Name[] = _("Stolen Trade");
const u8 gText_Quest_StolenTrade_Desc[] = _("She wanted to trade with you to evolve\nher Swirlix and then trade back,\nbut she ran away with your Gurdurr!");
const u8 gText_Quest_StolenTrade_DoneDesc[] = _("You hunted down the Trainer\nand got back your Conkeldurr.");
const u8 gText_Quest_StolenTrade_Map[] = _("Sunset");

const u8 gText_Quest_HauntABuilding_Name[] = _("Haunt a Building");
const u8 gText_Quest_HauntABuilding_Desc[] =_("Bring 2 Litwick, 2 Sinistea,1\nChandelure & 1 Trevenant to scare off\nthe property developer. Come at night.");
const u8 gText_Quest_HauntABuilding_DoneDesc[] =_("You scared off the developer!\nBut... perhaps the house was haunted\nafter all.");
const u8 gText_Quest_HauntABuilding_Map[] =_("Presidio");

const u8 gText_Quest_RabiesOutbreak_Name[] = _("Rabies Outbreak");
const u8 gText_Quest_RabiesOutbreak_Desc[] =_("Feral Glameow are endangering wildlife\nin Bernal Heights.");
const u8 gText_Quest_RabiesOutbreak_DoneDesc[] =_("You defeated the Glameow... but the\noutbreak was Pokérus, not rabies.");
const u8 gText_Quest_RabiesOutbreak_Map[] =_("Bernalheights");

const u8 gText_Quest_BlueRobbery_Name[] = _("Blue Robbery");
const u8 gText_Quest_BlueRobbery_Desc[] =_("Find the brunette and her Wobbuffet\nthat were breaking and entering in the\nTenderloin!");
const u8 gText_Quest_BlueRobbery_DoneDesc[] =_("You found the Trainer, but she refused\nto even hint at being guilty...");
const u8 gText_Quest_BlueRobbery_Map[] =_("Castro");

const u8 gText_Quest_IceCreamCrafting_Name[] = _("Ice Cream Crafting");
const u8 gText_Quest_IceCreamCrafting_Desc[] =_("Bring 3 Pecha, 2 Nanab, and 1 Rabuta\nBerry to the new ice cream shop to make\na Pokémon training smoothie!");
const u8 gText_Quest_IceCreamCrafting_DoneDesc[] =_("The Sherbert Surprise zeroes out your\nPokémon's EVs. It could be useful...");
const u8 gText_Quest_IceCreamCrafting_Map[] =_("Berkeley");

const u8 gText_Quest_VSDeoxys_Name[] = _("VS Deoxys");
const u8 gText_Quest_VSDeoxys_Desc[] =_("Subdue the rare, orange,\nforme-changing Pokémon from space!");
const u8 gText_Quest_VSDeoxys_DoneDesc[] =_("You found the Minior...");
const u8 gText_Quest_VSDeoxys_Map[] =_("Psfroute38");

const u8 gText_Quest_ChinatownTunnels_Name[] = _("Chinatown Tunnels");
const u8 gText_Quest_ChinatownTunnels_Desc[] =_("Find somebody who might know the oldest secrets of the treasures hidden under Chinatown.");
const u8 gText_Quest_ChinatownTunnels_DoneDesc[] =_("The eldest member of Chinatown tricked you into helping him recover a treasure - his childhood photos...");
const u8 gText_Quest_ChinatownTunnels_Map[] =_("Chinatown");

const u8 gText_Quest_FreshwaterEvolution_Name[] = _("Freshwater Evolution");
const u8 gText_Quest_FreshwaterEvolution_Desc[] =_("Finding the secret spring inside\nGldngtewilds and putting in an\nOctillery will turn it shiny!");
const u8 gText_Quest_FreshwaterEvolution_DoneDesc[] =_("There's a spring, but Octillery don't\nlike freshwater. There is something\nunusual about this place though....");
const u8 gText_Quest_FreshwaterEvolution_Map[] =_("Gldngtewilds");

const u8 gText_Quest_GemArtist_Name[] = _("Gem Artist");
const u8 gText_Quest_GemArtist_Desc[] =_("A local artist is willing to make rare\ngems from Unova. Bring them 10 Beach\nGlass!");
const u8 gText_Quest_GemArtist_DoneDesc[] =_("The artist made you powerful Gem for\nbattle, but the glass wasn't easy to\nfind...");
const u8 gText_Quest_GemArtist_Map[] =_("Pacifica");

const u8 gText_Quest_BetweenAStoneAndAHardPlace_Name[] = _("Between a Stone and a Hard Place");
const u8 gText_Quest_BetweenAStoneAndAHardPlace_Desc[] =_("Ride the cable ar enough times to get a rare stone to power up Pokemon.");
const u8 gText_Quest_BetweenAStoneAndAHardPlace_DoneDesc[] =_("You got a stone for riding the cable car\n3 times, but it was a Evolutionary\nStone, not a Mega Stone...");
const u8 gText_Quest_BetweenAStoneAndAHardPlace_Map[] =_("Tenderloin");

const u8 gText_Quest_RightingWrongs_Name[] = _("Righting Wrongs");
const u8 gText_Quest_RightingWrongs_Desc[] =_("Description");
const u8 gText_Quest_RightingWrongs_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RightingWrongs_Map[] =_("Castro");

const u8 gText_Quest_EnterTheDragon_Name[] = _("Enter the Dragon");
const u8 gText_Quest_EnterTheDragon_Desc[] =_("Description");
const u8 gText_Quest_EnterTheDragon_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_EnterTheDragon_Map[] =_("Chinatown");

const u8 gText_Quest_BreakTheInternet_Name[] = _("Break the Internet");
const u8 gText_Quest_BreakTheInternet_Desc[] =_("Description");
const u8 gText_Quest_BreakTheInternet_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BreakTheInternet_Map[] =_("SouthBay");

const u8 gText_Quest_ShutDownMedicineMan_Name[] = _("Shut Down Medicine Man");
const u8 gText_Quest_ShutDownMedicineMan_Desc[] =_("Description");
const u8 gText_Quest_ShutDownMedicineMan_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ShutDownMedicineMan_Map[] =_("Pacifica");

const u8 gText_Quest_BuildingScope_Name[] = _("Building Scope");
const u8 gText_Quest_BuildingScope_Desc[] =_("Description");
const u8 gText_Quest_BuildingScope_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BuildingScope_Map[] =_("Presidio");

const u8 gText_Quest_NoGoodDeed_Name[] = _("No Good Deed");
const u8 gText_Quest_NoGoodDeed_Desc[] =_("Description");
const u8 gText_Quest_NoGoodDeed_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_NoGoodDeed_Map[] =_("Oakland");

const u8 gText_Quest_ImprovBattling_Name[] = _("Improv Battling");
const u8 gText_Quest_ImprovBattling_Desc[] =_("Description");
const u8 gText_Quest_ImprovBattling_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ImprovBattling_Map[] =_("Presidio");

const u8 gText_Quest_ImprovBattlingChampionship_Name[] = _("Improv Battling Championship");
const u8 gText_Quest_ImprovBattlingChampionship_Desc[] =_("Description");
const u8 gText_Quest_ImprovBattlingChampionship_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ImprovBattlingChampionship_Map[] =_("Presidio");

const u8 gText_Quest_InstallNatureProbes_Name[] = _("Install Nature Probes");
const u8 gText_Quest_InstallNatureProbes_Desc[] =_("Help Liidia install three probes in\nMuirwoods! One deep in the forest, one\non a hill, and one near a shore.");
const u8 gText_Quest_InstallNatureProbes_DoneDesc[] =_("You helped Liidia install nature probes\nin Muirwoods! And then they got fired.");
const u8 gText_Quest_InstallNatureProbes_Map[] =_("Marin");

const u8 gText_Quest_ManOfManyHats_Name[] = _("Man of Many Hats");
const u8 gText_Quest_ManOfManyHats_Desc[] =_("Description");
const u8 gText_Quest_ManOfManyHats_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ManOfManyHats_Map[] =_("N/A");

const u8 gText_Quest_RecruitLocalArtists_Name[] = _("Recruit Local Artists");
const u8 gText_Quest_RecruitLocalArtists_Desc[] =_("Description");
const u8 gText_Quest_RecruitLocalArtists_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RecruitLocalArtists_Map[] =_("Mission");

const u8 gText_Quest_RestaurantExpansion1_Name[] = _("Restaurant Expansion 1");
const u8 gText_Quest_RestaurantExpansion1_Desc[] =_("Description");
const u8 gText_Quest_RestaurantExpansion1_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RestaurantExpansion1_Map[] =_("Mission");

const u8 gText_Quest_RestaurantExpansion2_Name[] = _("Restaurant Expansion 2");
const u8 gText_Quest_RestaurantExpansion2_Desc[] =_("Description");
const u8 gText_Quest_RestaurantExpansion2_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RestaurantExpansion2_Map[] =_("Mission");

const u8 gText_Quest_RestaurantExpansion3_Name[] = _("Restaurant Expansion 3");
const u8 gText_Quest_RestaurantExpansion3_Desc[] =_("Description");
const u8 gText_Quest_RestaurantExpansion3_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RestaurantExpansion3_Map[] =_("Mission");

const u8 gText_Quest_CulturalPurity_Name[] = _("Cultural Purity");
const u8 gText_Quest_CulturalPurity_Desc[] =_("Description");
const u8 gText_Quest_CulturalPurity_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_CulturalPurity_Map[] =_("Chinatown");

const u8 gText_Quest_HybridCulture_Name[] = _("Hybrid Culture");
const u8 gText_Quest_HybridCulture_Desc[] =_("Bugsy wants to better understandn the\nmixed culture of SanFran & Japantown.\nFind Japantown's cultural gems!");
const u8 gText_Quest_HybridCulture_DoneDesc[] =_("Bugsy has a lot to learn about SanFran\nculture, but is greateful for your\nhelp.");
const u8 gText_Quest_HybridCulture_Map[] =_("Japantown");

const u8 gText_Quest_AlohaFromAlola_Name[] = _("Aloha from Alola");
const u8 gText_Quest_AlohaFromAlola_Desc[] =_("Description");
const u8 gText_Quest_AlohaFromAlola_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_AlohaFromAlola_Map[] =_("Oakland");

const u8 gText_Quest_BuildingAnExhibit_Name[] = _("Building an Exhibit");
const u8 gText_Quest_BuildingAnExhibit_Desc[] =_("Description");
const u8 gText_Quest_BuildingAnExhibit_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BuildingAnExhibit_Map[] =_("SOMA");

const u8 gText_Quest_UnknownMortyQuestA_Name[] = _("Unknown Morty Quest A");
const u8 gText_Quest_UnknownMortyQuestA_Desc[] =_("Description");
const u8 gText_Quest_UnknownMortyQuestA_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownMortyQuestA_Map[] =_("N/A");

const u8 gText_Quest_UnknownMortyQuestB_Name[] = _("Unknown Morty Quest B");
const u8 gText_Quest_UnknownMortyQuestB_Desc[] =_("Description");
const u8 gText_Quest_UnknownMortyQuestB_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownMortyQuestB_Map[] =_("N/A");

const u8 gText_Quest_UnknownChuckQuestA_Name[] = _("Unknown Chuck Quest A");
const u8 gText_Quest_UnknownChuckQuestA_Desc[] =_("Description");
const u8 gText_Quest_UnknownChuckQuestA_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownChuckQuestA_Map[] =_("Alameda");

const u8 gText_Quest_UnknownChuckQuestB_Name[] = _("Unknown Chuck Quest B");
const u8 gText_Quest_UnknownChuckQuestB_Desc[] =_("Description");
const u8 gText_Quest_UnknownChuckQuestB_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownChuckQuestB_Map[] =_("FortPoint");

const u8 gText_Quest_BiomeResearch_Name[] = _("Biome Research");
const u8 gText_Quest_BiomeResearch_Desc[] =_("Description");
const u8 gText_Quest_BiomeResearch_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BiomeResearch_Map[] =_("GldnGteWilds");

const u8 gText_Quest_BerrySustainability_Name[] = _("Berry Sustainability");
const u8 gText_Quest_BerrySustainability_Desc[] =_("Description");
const u8 gText_Quest_BerrySustainability_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BerrySustainability_Map[] =_("Marin");

const u8 gText_Quest_TheOnlyHeadShopInTown_Name[] = _("The Only Head Shop in Town");
const u8 gText_Quest_TheOnlyHeadShopInTown_Desc[] =_("Description");
const u8 gText_Quest_TheOnlyHeadShopInTown_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_TheOnlyHeadShopInTown_Map[] =_("Berkeley");

const u8 gText_Quest_InverseHallucinogenic_Name[] = _("Inverse Hallucinogenic");
const u8 gText_Quest_InverseHallucinogenic_Desc[] =_("Description");
const u8 gText_Quest_InverseHallucinogenic_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_InverseHallucinogenic_Map[] =_("Haightashbury");

const u8 gText_Quest_UnknownClairQuestA_Name[] = _("Unknown Clair Quest A");
const u8 gText_Quest_UnknownClairQuestA_Desc[] =_("Description");
const u8 gText_Quest_UnknownClairQuestA_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownClairQuestA_Map[] =_("SouthBay");

const u8 gText_Quest_UnknownClairQuestB_Name[] = _("Unknown Clair Quest B");
const u8 gText_Quest_UnknownClairQuestB_Desc[] =_("Description");
const u8 gText_Quest_UnknownClairQuestB_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownClairQuestB_Map[] =_("Castro");

const u8 gText_Quest_ContractorPorygon_Name[] = _("Contractor Porygon");
const u8 gText_Quest_ContractorPorygon_Desc[] =_("Description");
const u8 gText_Quest_ContractorPorygon_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ContractorPorygon_Map[] =_("SOMA");

const u8 gText_Quest_AngelDelivery_Name[] = _("Angel Delivery");
const u8 gText_Quest_AngelDelivery_Desc[] =_("Description");
const u8 gText_Quest_AngelDelivery_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_AngelDelivery_Map[] =_("Haightashbury");

const u8 gText_Quest_GetTheBandBackTogether_Name[] = _("Get The Band Back Together");
const u8 gText_Quest_GetTheBandBackTogether_Desc[] =_("Description");
const u8 gText_Quest_GetTheBandBackTogether_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_GetTheBandBackTogether_Map[] =_("Dogpatch");

const u8 gText_Quest_FoodTruckBureacracy_Name[] = _("Food Truck Bureacracy");
const u8 gText_Quest_FoodTruckBureacracy_Desc[] =_("Description");
const u8 gText_Quest_FoodTruckBureacracy_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_FoodTruckBureacracy_Map[] =_("Sunset");

const u8 gText_Quest_DetectiveAriana_Name[] = _("Detective Ariana");
const u8 gText_Quest_DetectiveAriana_Desc[] =_("Description");
const u8 gText_Quest_DetectiveAriana_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_DetectiveAriana_Map[] =_("Berkeley");

const u8 gText_Quest_UnknownBruceLeeQuest_Name[] = _("Unknown Bruce Lee Quest");
const u8 gText_Quest_UnknownBruceLeeQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownBruceLeeQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownBruceLeeQuest_Map[] =_("Chinatown");

const u8 gText_Quest_ChallengeOfThe7Sisters_Name[] = _("Challenge of the 7 Sisters");
const u8 gText_Quest_ChallengeOfThe7Sisters_Desc[] =_("Description");
const u8 gText_Quest_ChallengeOfThe7Sisters_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ChallengeOfThe7Sisters_Map[] =_("Psfroute43");

const u8 gText_Quest_Esports_Name[] = _("Esports");
const u8 gText_Quest_Esports_Desc[] =_("Description");
const u8 gText_Quest_Esports_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_Esports_Map[] =_("Oakland");

const u8 gText_Quest_CutePokemon_Name[] = _("Cute Pokémon");
const u8 gText_Quest_CutePokemon_Desc[] =_("Description");
const u8 gText_Quest_CutePokemon_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_CutePokemon_Map[] =_("N/A");

const u8 gText_Quest_WallaceArmy_Name[] = _("Wallace Army");
const u8 gText_Quest_WallaceArmy_Desc[] =_("Description");
const u8 gText_Quest_WallaceArmy_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_WallaceArmy_Map[] =_("Marin");

const u8 gText_Quest_DexCompletion_Name[] = _("Dex Completion");
const u8 gText_Quest_DexCompletion_Desc[] =_("Description");
const u8 gText_Quest_DexCompletion_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_DexCompletion_Map[] =_("Berkeley");

const u8 gText_Quest_CableCarDancing_Name[] = _("Cable Car Dancing");
const u8 gText_Quest_CableCarDancing_Desc[] =_("Description");
const u8 gText_Quest_CableCarDancing_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_CableCarDancing_Map[] =_("Presidio");

const u8 gText_Quest_KitchenVolunteering_Name[] = _("Kitchen Volunteering");
const u8 gText_Quest_KitchenVolunteering_Desc[] =_("Description");
const u8 gText_Quest_KitchenVolunteering_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_KitchenVolunteering_Map[] =_("Tenderloin");

const u8 gText_Quest_ArtisanBalls1_Name[] = _("Artisan Balls");
const u8 gText_Quest_ArtisanBalls1_Desc[] =_("Help test the craftman's Pokeballs.\nCatch a Pokemon in each one, & talk to\nhim if you need more.");
const u8 gText_Quest_ArtisanBalls1_DoneDesc[] =_("The craft Balls are a success! You can\nbuy these balls to make catching\neasier.");
const u8 gText_Quest_ArtisanBalls1_Map[] =_("Japantown");

const u8 gText_Quest_ArtisanBalls2_Name[] = _("Artisan Balls 2");
const u8 gText_Quest_ArtisanBalls2_Desc[] =_("Sergey needs to find an office manager,\nmarketing manager, & a customer\nservice rep.");
const u8 gText_Quest_ArtisanBalls2_DoneDesc[] =_("Sergey is done hiring and is ready to\nexpand his business! He can sell their\nwhole collection now.");
const u8 gText_Quest_ArtisanBalls2_Map[] =_("Japantown");

const u8 gText_Quest_ArtisanBalls3_Name[] = _("Artisan Balls 3");
const u8 gText_Quest_ArtisanBalls3_Desc[] =_("Defeat one of the Gym Leaders using a\nPokémon in Sergey's craft PokéBalls!");
const u8 gText_Quest_ArtisanBalls3_DoneDesc[] =_("Serey's PokéBalls got enough publicity to get acquired by Silph Co.!");
const u8 gText_Quest_ArtisanBalls3_Map[] =_("Japantown");

const u8 gText_Quest_ShelterSwitcheroo_Name[] = _("Shelter Switcheroo");
const u8 gText_Quest_ShelterSwitcheroo_Desc[] =_("Description");
const u8 gText_Quest_ShelterSwitcheroo_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ShelterSwitcheroo_Map[] =_("SouthBay");

const u8 gText_Quest_ShelterTaxiSolution_Name[] = _("Shelter Taxi Solution");
const u8 gText_Quest_ShelterTaxiSolution_Desc[] =_("Description");
const u8 gText_Quest_ShelterTaxiSolution_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ShelterTaxiSolution_Map[] =_("SouthBay");

const u8 gText_Quest_LastMusicVenueInSanFrancisco_Name[] = _("Last Music Venue in SanFran");
const u8 gText_Quest_LastMusicVenueInSanFrancisco_Desc[] =_("Help Ladislau find local musicians\nlooking for a regular venue to perform\nin.");
const u8 gText_Quest_LastMusicVenueInSanFrancisco_DoneDesc[] =_("The drum circle you previously battled\nare thrilled to have a new venue to\nperform in!");
const u8 gText_Quest_LastMusicVenueInSanFrancisco_Map[] =_("Japantown");

const u8 gText_Quest_GardenCleanup_Name[] = _("Garden Cleanup");
const u8 gText_Quest_GardenCleanup_Desc[] =_("Description");
const u8 gText_Quest_GardenCleanup_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_GardenCleanup_Map[] =_("BernalHeights");

const u8 gText_Quest_GardenCleanupAdvanced_Name[] = _("Garden Cleanup Advanced");
const u8 gText_Quest_GardenCleanupAdvanced_Desc[] =_("Description");
const u8 gText_Quest_GardenCleanupAdvanced_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_GardenCleanupAdvanced_Map[] =_("Psfroute21");

const u8 gText_Quest_EmployedEverAfter_Name[] = _("Employed Ever After");
const u8 gText_Quest_EmployedEverAfter_Desc[] =_("Description");
const u8 gText_Quest_EmployedEverAfter_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_EmployedEverAfter_Map[] =_("PalaceFineArts");

const u8 gText_Quest_ButOnlyInMyBackyard_Name[] = _("But Only in My Backyard");
const u8 gText_Quest_ButOnlyInMyBackyard_Desc[] =_("Description");
const u8 gText_Quest_ButOnlyInMyBackyard_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_ButOnlyInMyBackyard_Map[] =_("GldnGtePark");

const u8 gText_Quest_NeighborhoodCleanUp_Name[] = _("Neighborhood Clean Up");
const u8 gText_Quest_NeighborhoodCleanUp_Desc[] =_("Description");
const u8 gText_Quest_NeighborhoodCleanUp_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_NeighborhoodCleanUp_Map[] =_("Dogpatch");

const u8 gText_Quest_NeighborhoodCleanUp2_Name[] = _("Neighborhood Clean Up 2");
const u8 gText_Quest_NeighborhoodCleanUp2_Desc[] =_("Description");
const u8 gText_Quest_NeighborhoodCleanUp2_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_NeighborhoodCleanUp2_Map[] =_("Dogpatch");

const u8 gText_Quest_NeighborhoodCleanUp3_Name[] = _("Neighborhood Clean Up 3");
const u8 gText_Quest_NeighborhoodCleanUp3_Desc[] =_("Description");
const u8 gText_Quest_NeighborhoodCleanUp3_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_NeighborhoodCleanUp3_Map[] =_("BernalHeights");

const u8 gText_Quest_NeighborhoodCleanUp4_Name[] = _("Neighborhood Clean Up 4");
const u8 gText_Quest_NeighborhoodCleanUp4_Desc[] =_("Description");
const u8 gText_Quest_NeighborhoodCleanUp4_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_NeighborhoodCleanUp4_Map[] =_("Tenderloin");

const u8 gText_Quest_RockCollector_Name[] = _("Rock Collector");
const u8 gText_Quest_RockCollector_Desc[] =_("Description");
const u8 gText_Quest_RockCollector_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RockCollector_Map[] =_("Presidio");

const u8 gText_Quest_Hang20_Name[] = _("Hang 20");
const u8 gText_Quest_Hang20_Desc[] =_("Description");
const u8 gText_Quest_Hang20_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_Hang20_Map[] =_("Pacifica");

const u8 gText_Quest_AllThatGlittersMightBeGold_Name[] = _("All That Glitters Might Be Gold?");
const u8 gText_Quest_AllThatGlittersMightBeGold_Desc[] =_("Description");
const u8 gText_Quest_AllThatGlittersMightBeGold_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_AllThatGlittersMightBeGold_Map[] =_("FishermansWharf");

const u8 gText_Quest_UnknownFishingQuest_Name[] = _("Unknown Fishing Quest");
const u8 gText_Quest_UnknownFishingQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownFishingQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownFishingQuest_Map[] =_("Alameda");

const u8 gText_Quest_HiddenGrottoMapping_Name[] = _("Hidden Grotto Mapping");
const u8 gText_Quest_HiddenGrottoMapping_Desc[] =_("Description");
const u8 gText_Quest_HiddenGrottoMapping_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_HiddenGrottoMapping_Map[] =_("GldnGtePark");

const u8 gText_Quest_HiddenGrottoMapping2_Name[] = _("Hidden Grotto Mapping 2");
const u8 gText_Quest_HiddenGrottoMapping2_Desc[] =_("Description");
const u8 gText_Quest_HiddenGrottoMapping2_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_HiddenGrottoMapping2_Map[] =_("GldnGtePark");

const u8 gText_Quest_UltraWormholeResearch_Name[] = _("Ultra Wormhole Research");
const u8 gText_Quest_UltraWormholeResearch_Desc[] =_("Description");
const u8 gText_Quest_UltraWormholeResearch_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UltraWormholeResearch_Map[] =_("SOMA");

const u8 gText_Quest_UnknownGovernmentSocialMediaQuest_Name[] = _("Unknown Government Social Media Quest");
const u8 gText_Quest_UnknownGovernmentSocialMediaQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownGovernmentSocialMediaQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownGovernmentSocialMediaQuest_Map[] =_("N/A");

const u8 gText_Quest_DrumCircle_Name[] = _("Drum Circle");
const u8 gText_Quest_DrumCircle_Desc[] =_("Description");
const u8 gText_Quest_DrumCircle_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_DrumCircle_Map[] =_("Haightashbury");

const u8 gText_Quest_UnknownProp22Quest_Name[] = _("Unknown Prop 22 Quest");
const u8 gText_Quest_UnknownProp22Quest_Desc[] =_("Description");
const u8 gText_Quest_UnknownProp22Quest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownProp22Quest_Map[] =_("N/A");

const u8 gText_Quest_UnknownTimeTravelQuest_Name[] = _("Unknown Time Travel Quest");
const u8 gText_Quest_UnknownTimeTravelQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownTimeTravelQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownTimeTravelQuest_Map[] =_("N/A");

const u8 gText_Quest_UnknownConstructionStrikeQuest_Name[] = _("Unknown Construction Strike Quest");
const u8 gText_Quest_UnknownConstructionStrikeQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownConstructionStrikeQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownConstructionStrikeQuest_Map[] =_("N/A");

const u8 gText_Quest_IBelieveICanFly_Name[] = _("I Believe I Can Fly");
const u8 gText_Quest_IBelieveICanFly_Desc[] =_("Description");
const u8 gText_Quest_IBelieveICanFly_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_IBelieveICanFly_Map[] =_("Marin");

const u8 gText_Quest_WildfireRisk_Name[] = _("Wildfire Risk");
const u8 gText_Quest_WildfireRisk_Desc[] =_("Description");
const u8 gText_Quest_WildfireRisk_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_WildfireRisk_Map[] =_("Sunset");

const u8 gText_Quest_TheBoyWhoCriesWithWolves_Name[] = _("The Boy Who Cries With Wolves");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Desc[] =_("Description");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Map[] =_("Lakemerced");

const u8 gText_Quest_UnknownTrolleyProblem_Name[] = _("Unknown Trolley Problem");
const u8 gText_Quest_UnknownTrolleyProblem_Desc[] =_("Description");
const u8 gText_Quest_UnknownTrolleyProblem_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownTrolleyProblem_Map[] =_("SOMA");

const u8 gText_Quest_UnknownLandfillQuest_Name[] = _("Unknown Landfill Quest");
const u8 gText_Quest_UnknownLandfillQuest_Desc[] =_("Description");
const u8 gText_Quest_UnknownLandfillQuest_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_UnknownLandfillQuest_Map[] =_("N/A");

const u8 gText_Quest_TaxicabTurnaroundSea_Name[] = _("Taxicab Turnaround - Sea");
const u8 gText_Quest_TaxicabTurnaroundSea_Desc[] =_("Description");
const u8 gText_Quest_TaxicabTurnaroundSea_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_TaxicabTurnaroundSea_Map[] =_("Marin");

const u8 gText_Quest_TaxicabTurnaroundAir_Name[] = _("Taxicab Turnaround - Air");
const u8 gText_Quest_TaxicabTurnaroundAir_Desc[] =_("Description");
const u8 gText_Quest_TaxicabTurnaroundAir_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_TaxicabTurnaroundAir_Map[] =_("Berkeley");

const u8 gText_Quest_TaxicabTurnaroundLand_Name[] = _("Taxicab Turnaround - Land");
const u8 gText_Quest_TaxicabTurnaroundLand_Desc[] =_("Description");
const u8 gText_Quest_TaxicabTurnaroundLand_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_TaxicabTurnaroundLand_Map[] =_("Alameda");

const u8 gText_Quest_PersuasivePassenger_Name[] = _("Persuasive Passenger");
const u8 gText_Quest_PersuasivePassenger_Desc[] =_("Description");
const u8 gText_Quest_PersuasivePassenger_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_PersuasivePassenger_Map[] =_("BernalHeights");

const u8 gText_Quest_BodegaBurnout_Name[] = _("Bodega Burnout");
const u8 gText_Quest_BodegaBurnout_Desc[] =_("Description");
const u8 gText_Quest_BodegaBurnout_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_BodegaBurnout_Map[] =_("Tenderloin");

const u8 gText_Quest_WarehouseWarfare_Name[] = _("Warehouse Warfare");
const u8 gText_Quest_WarehouseWarfare_Desc[] =_("Description");
const u8 gText_Quest_WarehouseWarfare_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_WarehouseWarfare_Map[] =_("Pacifica");

const u8 gText_Quest_RestoreToTheirFormerGlory_Name[] = _("Restore to their Former Glory");
const u8 gText_Quest_RestoreToTheirFormerGlory_Desc[] =_("Description");
const u8 gText_Quest_RestoreToTheirFormerGlory_DoneDesc[] =_("DoneDescription");
const u8 gText_Quest_RestoreToTheirFormerGlory_Map[] =_("N/A");

//subquests
const u8 gText_Quest_HauntABuilding_Sub1_Name[] = _("Litwick");
const u8 gText_Quest_HauntABuilding_Sub1_Desc[] = _("You brought Hunter a Litwick.");
const u8 gText_Quest_HauntABuilding_Sub1_Map[] = _("Presidio");
const u8 gText_Quest_HauntABuilding_Sub2_Name[] = _("Litwick");
const u8 gText_Quest_HauntABuilding_Sub2_Desc[] = _("You brought Hunter a second Litwick.");
const u8 gText_Quest_HauntABuilding_Sub2_Map[] = _("Presidio");
const u8 gText_Quest_HauntABuilding_Sub3_Name[] = _("Sinistea");
const u8 gText_Quest_HauntABuilding_Sub3_Desc[] = _("You brought Hunter a Sinistea.");
const u8 gText_Quest_HauntABuilding_Sub3_Map[] = _("Presidio");
const u8 gText_Quest_HauntABuilding_Sub4_Name[] = _("Sinistea");
const u8 gText_Quest_HauntABuilding_Sub4_Desc[] = _("You brought Hunter a Sinistea.");
const u8 gText_Quest_HauntABuilding_Sub4_Map[] = _("Presidio");
const u8 gText_Quest_HauntABuilding_Sub5_Name[] = _("Chandelure");
const u8 gText_Quest_HauntABuilding_Sub5_Desc[] = _("You brought Hunter a Chandelure.");
const u8 gText_Quest_HauntABuilding_Sub5_Map[] = _("Presidio");
const u8 gText_Quest_HauntABuilding_Sub6_Name[] = _("Trevanant");
const u8 gText_Quest_HauntABuilding_Sub6_Desc[] = _("You brought Hunter a Trevenant.");
const u8 gText_Quest_HauntABuilding_Sub6_Map[] = _("Presidio");

const u8 gText_Quest_ConsolationPrize_Sub1_Name[] = _("Fetch Quest 1");
const u8 gText_Quest_ConsolationPrize_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ConsolationPrize_Sub1_Map[] = _("GldnGtePark");
const u8 gText_Quest_ConsolationPrize_Sub2_Name[] = _("Fetch Quest 2");
const u8 gText_Quest_ConsolationPrize_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ConsolationPrize_Sub2_Map[] = _("SOMA");
const u8 gText_Quest_ConsolationPrize_Sub3_Name[] = _("Fetch Quest 3");
const u8 gText_Quest_ConsolationPrize_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ConsolationPrize_Sub3_Map[] = _("Berkeley");
const u8 gText_Quest_ConsolationPrize_Sub4_Name[] = _("Fetch Quest 4");
const u8 gText_Quest_ConsolationPrize_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ConsolationPrize_Sub4_Map[] = _("Presidio");
const u8 gText_Quest_ConsolationPrize_Sub5_Name[] = _("Fetch Quest 5");
const u8 gText_Quest_ConsolationPrize_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ConsolationPrize_Sub5_Map[] = _("Sunset");
const u8 gText_Quest_RightingWrongs_Sub1_Name[] = _("Evidence 1");
const u8 gText_Quest_RightingWrongs_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RightingWrongs_Sub1_Map[] = _("Treasureisland");
const u8 gText_Quest_RightingWrongs_Sub2_Name[] = _("Evidence 2");
const u8 gText_Quest_RightingWrongs_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RightingWrongs_Sub2_Map[] = _("Tenderloin");
const u8 gText_Quest_RightingWrongs_Sub3_Name[] = _("Evidence 3");
const u8 gText_Quest_RightingWrongs_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RightingWrongs_Sub3_Map[] = _("Alameda");
const u8 gText_Quest_RightingWrongs_Sub4_Name[] = _("Turned In");
const u8 gText_Quest_RightingWrongs_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RightingWrongs_Sub4_Map[] = _("GldnGtePark");

const u8 gText_Quest_BreakTheInternet_Sub1_Name[] = _("False Story 1");
const u8 gText_Quest_BreakTheInternet_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BreakTheInternet_Sub1_Map[] = _("Marin");
const u8 gText_Quest_BreakTheInternet_Sub2_Name[] = _("False Story 2");
const u8 gText_Quest_BreakTheInternet_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BreakTheInternet_Sub2_Map[] = _("Oakland");
const u8 gText_Quest_BreakTheInternet_Sub3_Name[] = _("Missing Reporter");
const u8 gText_Quest_BreakTheInternet_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BreakTheInternet_Sub3_Map[] = _("Chinatown");

const u8 gText_Quest_ImprovBattling_Sub1_Name[] = _("Poké Cup");
const u8 gText_Quest_ImprovBattling_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ImprovBattling_Sub1_Map[] = _("Presidio");
const u8 gText_Quest_ImprovBattling_Sub2_Name[] = _("Great Cup");
const u8 gText_Quest_ImprovBattling_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ImprovBattling_Sub2_Map[] = _("Presidio");
const u8 gText_Quest_ImprovBattling_Sub3_Name[] = _("Ultra Cup");
const u8 gText_Quest_ImprovBattling_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ImprovBattling_Sub3_Map[] = _("Presidio");
const u8 gText_Quest_ImprovBattling_Sub4_Name[] = _("Master Cup");
const u8 gText_Quest_ImprovBattling_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ImprovBattling_Sub4_Map[] = _("Presidio");

const u8 gText_Quest_InstallNatureProbes_Sub1_Name[] = _("Forest");
const u8 gText_Quest_InstallNatureProbes_Sub1_Desc[] = _("You installed a probe for tracking\nPokemon on a hill.");
const u8 gText_Quest_InstallNatureProbes_Sub1_Map[] = _("MuirWoods");
const u8 gText_Quest_InstallNatureProbes_Sub2_Name[] = _("Hill");
const u8 gText_Quest_InstallNatureProbes_Sub2_Desc[] = _("You installed a probe for tracking\nPokemon deep in the forest.");
const u8 gText_Quest_InstallNatureProbes_Sub2_Map[] = _("MuirWoods");
const u8 gText_Quest_InstallNatureProbes_Sub3_Name[] = _("Shore");
const u8 gText_Quest_InstallNatureProbes_Sub3_Desc[] = _("You installed a probe for tracking\nPokemon by the lakeshore.");
const u8 gText_Quest_InstallNatureProbes_Sub3_Map[] = _("MuirWoods");

const u8 gText_Quest_RestaurantExpansion1_Sub1_Name[] = _("Center 1");
const u8 gText_Quest_RestaurantExpansion1_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion1_Sub1_Map[] = _("SOMA");
const u8 gText_Quest_RestaurantExpansion1_Sub2_Name[] = _("Center 2");
const u8 gText_Quest_RestaurantExpansion1_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion1_Sub2_Map[] = _("Tenderloin");
const u8 gText_Quest_RestaurantExpansion1_Sub3_Name[] = _("Center 3");
const u8 gText_Quest_RestaurantExpansion1_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion1_Sub3_Map[] = _("SOMA");
const u8 gText_Quest_RestaurantExpansion1_Sub4_Name[] = _("Center 4");
const u8 gText_Quest_RestaurantExpansion1_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion1_Sub4_Map[] = _("Marin");

const u8 gText_Quest_RestaurantExpansion2_Sub1_Name[] = _("Hostess");
const u8 gText_Quest_RestaurantExpansion2_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion2_Sub1_Map[] = _("Castro");
const u8 gText_Quest_RestaurantExpansion2_Sub2_Name[] = _("Chef");
const u8 gText_Quest_RestaurantExpansion2_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion2_Sub2_Map[] = _("SouthBay");
const u8 gText_Quest_RestaurantExpansion2_Sub3_Name[] = _("Janitor");
const u8 gText_Quest_RestaurantExpansion2_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion2_Sub3_Map[] = _("Presidio");
const u8 gText_Quest_RestaurantExpansion2_Sub4_Name[] = _("Bus Boy");
const u8 gText_Quest_RestaurantExpansion2_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion2_Sub4_Map[] = _("Alameda");
const u8 gText_Quest_RestaurantExpansion2_Sub5_Name[] = _("Cashier");
const u8 gText_Quest_RestaurantExpansion2_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestaurantExpansion2_Sub5_Map[] = _("Haightashbury");

const u8 gText_Quest_HybridCulture_Sub1_Name[] = _("Food");
const u8 gText_Quest_HybridCulture_Sub1_Desc[] = _("Poffins stuffed with flavors not\nnative to Sinnoh are a popular dessert\nat the ramen restaurant.");
const u8 gText_Quest_HybridCulture_Sub1_Map[] = _("Japantown");
const u8 gText_Quest_HybridCulture_Sub2_Name[] = _("Fashion");
const u8 gText_Quest_HybridCulture_Sub2_Desc[] = _("Tourists from Sinnoh wear the latest\nfashion from their country, which in\nturn inspires designers in SanFran.");
const u8 gText_Quest_HybridCulture_Sub2_Map[] = _("Japantown");
const u8 gText_Quest_HybridCulture_Sub3_Name[] = _("Traditions");
const u8 gText_Quest_HybridCulture_Sub3_Desc[] = _("The best way to get berries only found\nin Sinnoh is to defeat their Trainers in\nbattle.");
const u8 gText_Quest_HybridCulture_Sub3_Map[] = _("Japantown");

const u8 gText_Quest_BuildingAnExhibit_Sub1_Name[] = _("Ticket Stub");
const u8 gText_Quest_BuildingAnExhibit_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BuildingAnExhibit_Sub1_Map[] = _("Pacifica");
const u8 gText_Quest_BuildingAnExhibit_Sub2_Name[] = _("Champion's Cape");
const u8 gText_Quest_BuildingAnExhibit_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BuildingAnExhibit_Sub2_Map[] = _("GldnGtePark");
const u8 gText_Quest_BuildingAnExhibit_Sub3_Name[] = _("Toxic Spikes");
const u8 gText_Quest_BuildingAnExhibit_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BuildingAnExhibit_Sub3_Map[] = _("Castro");
const u8 gText_Quest_BuildingAnExhibit_Sub4_Name[] = _("Bobblehead");
const u8 gText_Quest_BuildingAnExhibit_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BuildingAnExhibit_Sub4_Map[] = _("Oakland");

const u8 gText_Quest_BiomeResearch_Sub1_Name[] = _("Jynx");
const u8 gText_Quest_BiomeResearch_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub1_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub2_Name[] = _("Jynx");
const u8 gText_Quest_BiomeResearch_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub2_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub3_Name[] = _("Baltoy");
const u8 gText_Quest_BiomeResearch_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub3_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub4_Name[] = _("Baltoy");
const u8 gText_Quest_BiomeResearch_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub4_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub5_Name[] = _("Pidgey");
const u8 gText_Quest_BiomeResearch_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub5_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub6_Name[] = _("Pidgey");
const u8 gText_Quest_BiomeResearch_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub6_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub7_Name[] = _("Seviper");
const u8 gText_Quest_BiomeResearch_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub7_Map[] = _("N/A");
const u8 gText_Quest_BiomeResearch_Sub8_Name[] = _("Seviper");
const u8 gText_Quest_BiomeResearch_Sub8_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BiomeResearch_Sub8_Map[] = _("N/A");

const u8 gText_Quest_BerrySustainability_Sub1_Name[] = _("Berry 1");
const u8 gText_Quest_BerrySustainability_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub1_Map[] = _("N/A");
const u8 gText_Quest_BerrySustainability_Sub2_Name[] = _("Berry 2");
const u8 gText_Quest_BerrySustainability_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub2_Map[] = _("N/A");
const u8 gText_Quest_BerrySustainability_Sub3_Name[] = _("Berry 3");
const u8 gText_Quest_BerrySustainability_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub3_Map[] = _("N/A");
const u8 gText_Quest_BerrySustainability_Sub4_Name[] = _("Berry 4");
const u8 gText_Quest_BerrySustainability_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub4_Map[] = _("N/A");
const u8 gText_Quest_BerrySustainability_Sub5_Name[] = _("Berry 5");
const u8 gText_Quest_BerrySustainability_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub5_Map[] = _("N/A");
const u8 gText_Quest_BerrySustainability_Sub6_Name[] = _("Berry 6");
const u8 gText_Quest_BerrySustainability_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BerrySustainability_Sub6_Map[] = _("N/A");

const u8 gText_Quest_ContractorPorygon_Sub1_Name[] = _("Curry");
const u8 gText_Quest_ContractorPorygon_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ContractorPorygon_Sub1_Map[] = _("Mission");
const u8 gText_Quest_ContractorPorygon_Sub2_Name[] = _("Dumplings");
const u8 gText_Quest_ContractorPorygon_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ContractorPorygon_Sub2_Map[] = _("Sunset");
const u8 gText_Quest_ContractorPorygon_Sub3_Name[] = _("Salad");
const u8 gText_Quest_ContractorPorygon_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ContractorPorygon_Sub3_Map[] = _("Berkeley");

const u8 gText_Quest_GetTheBandBackTogether_Sub1_Name[] = _("Person A");
const u8 gText_Quest_GetTheBandBackTogether_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_GetTheBandBackTogether_Sub1_Map[] = _("Berkeley");
const u8 gText_Quest_GetTheBandBackTogether_Sub2_Name[] = _("Person B");
const u8 gText_Quest_GetTheBandBackTogether_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_GetTheBandBackTogether_Sub2_Map[] = _("Pacifica");
const u8 gText_Quest_GetTheBandBackTogether_Sub3_Name[] = _("Person C");
const u8 gText_Quest_GetTheBandBackTogether_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_GetTheBandBackTogether_Sub3_Map[] = _("Oakland");
const u8 gText_Quest_GetTheBandBackTogether_Sub4_Name[] = _("Person D");
const u8 gText_Quest_GetTheBandBackTogether_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_GetTheBandBackTogether_Sub4_Map[] = _("Marin");
const u8 gText_Quest_GetTheBandBackTogether_Sub5_Name[] = _("Person E");
const u8 gText_Quest_GetTheBandBackTogether_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_GetTheBandBackTogether_Sub5_Map[] = _("Japantown");

const u8 gText_Quest_FoodTruckBureacracy_Sub1_Name[] = _("Discount Code");
const u8 gText_Quest_FoodTruckBureacracy_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_FoodTruckBureacracy_Sub1_Map[] = _("Sunset");
const u8 gText_Quest_FoodTruckBureacracy_Sub2_Name[] = _("Zoning Plans");
const u8 gText_Quest_FoodTruckBureacracy_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_FoodTruckBureacracy_Sub2_Map[] = _("SOMA");
const u8 gText_Quest_FoodTruckBureacracy_Sub3_Name[] = _("Router");
const u8 gText_Quest_FoodTruckBureacracy_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_FoodTruckBureacracy_Sub3_Map[] = _("Castro");
const u8 gText_Quest_FoodTruckBureacracy_Sub4_Name[] = _("Waste Approval");
const u8 gText_Quest_FoodTruckBureacracy_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_FoodTruckBureacracy_Sub4_Map[] = _("Presidio");

const u8 gText_Quest_DetectiveAriana_Sub1_Name[] = _("Photographs");
const u8 gText_Quest_DetectiveAriana_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_DetectiveAriana_Sub1_Map[] = _("SOMA");
const u8 gText_Quest_DetectiveAriana_Sub2_Name[] = _("Fly");
const u8 gText_Quest_DetectiveAriana_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_DetectiveAriana_Sub2_Map[] = _("Marin");
const u8 gText_Quest_DetectiveAriana_Sub3_Name[] = _("Uniforms");
const u8 gText_Quest_DetectiveAriana_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_DetectiveAriana_Sub3_Map[] = _("Alameda");

const u8 gText_Quest_ChallengeOfThe7Sisters_Sub1_Name[] = _("SS Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub1_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub2_Name[] = _("S Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub2_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub3_Name[] = _("A Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub3_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub4_Name[] = _("B Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub4_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub5_Name[] = _("C Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub5_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub6_Name[] = _("D Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub6_Map[] = _("PaintedLadies");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub7_Name[] = _("E Rank");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ChallengeOfThe7Sisters_Sub7_Map[] = _("PaintedLadies");

const u8 gText_Quest_CutePokemon_Sub1_Name[] = _("Duskull");
const u8 gText_Quest_CutePokemon_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_CutePokemon_Sub1_Map[] = _("Bernalheights");
const u8 gText_Quest_CutePokemon_Sub2_Name[] = _("Scrafty");
const u8 gText_Quest_CutePokemon_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_CutePokemon_Sub2_Map[] = _("Sunset");
const u8 gText_Quest_CutePokemon_Sub3_Name[] = _("Teddiursa");
const u8 gText_Quest_CutePokemon_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_CutePokemon_Sub3_Map[] = _("Pacifica");
const u8 gText_Quest_CutePokemon_Sub4_Name[] = _("Eiscue");
const u8 gText_Quest_CutePokemon_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_CutePokemon_Sub4_Map[] = _("Alameda");

const u8 gText_Quest_WallaceArmy_Sub2_Name[] = _("Stan A");
const u8 gText_Quest_WallaceArmy_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WallaceArmy_Sub2_Map[] = _("Alameda");
const u8 gText_Quest_WallaceArmy_Sub3_Name[] = _("Stan B");
const u8 gText_Quest_WallaceArmy_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WallaceArmy_Sub3_Map[] = _("Haightashbury");
const u8 gText_Quest_WallaceArmy_Sub4_Name[] = _("Stan C");
const u8 gText_Quest_WallaceArmy_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WallaceArmy_Sub4_Map[] = _("SOMA");
const u8 gText_Quest_WallaceArmy_Sub5_Name[] = _("Stan D");
const u8 gText_Quest_WallaceArmy_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WallaceArmy_Sub5_Map[] = _("Berkeley");
const u8 gText_Quest_WallaceArmy_Sub6_Name[] = _("Stan E");
const u8 gText_Quest_WallaceArmy_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WallaceArmy_Sub6_Map[] = _("Marin");

const u8 gText_Quest_DexCompletion_Sub1_Name[] = _("50% Complete");
const u8 gText_Quest_DexCompletion_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_DexCompletion_Sub1_Map[] = _("Berkeley");
const u8 gText_Quest_DexCompletion_Sub2_Name[] = _("100% Complete");
const u8 gText_Quest_DexCompletion_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_DexCompletion_Sub2_Map[] = _("Berkeley");

const u8 gText_Quest_KitchenVolunteering_Sub1_Name[] = _("Item 1");
const u8 gText_Quest_KitchenVolunteering_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_KitchenVolunteering_Sub1_Map[] = _("Tenderloin");
const u8 gText_Quest_KitchenVolunteering_Sub2_Name[] = _("Item 2");
const u8 gText_Quest_KitchenVolunteering_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_KitchenVolunteering_Sub2_Map[] = _("Tenderloin");
const u8 gText_Quest_KitchenVolunteering_Sub3_Name[] = _("Item 3");
const u8 gText_Quest_KitchenVolunteering_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_KitchenVolunteering_Sub3_Map[] = _("Tenderloin");
const u8 gText_Quest_KitchenVolunteering_Sub4_Name[] = _("Item 4");
const u8 gText_Quest_KitchenVolunteering_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_KitchenVolunteering_Sub4_Map[] = _("Tenderloin");
const u8 gText_Quest_KitchenVolunteering_Sub5_Name[] = _("Item 5");
const u8 gText_Quest_KitchenVolunteering_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_KitchenVolunteering_Sub5_Map[] = _("Tenderloin");

const u8 gText_Quest_ArtisanBalls_Sub1_Name[] = _("Fast Ball");
const u8 gText_Quest_ArtisanBalls_Sub1_Desc[] = _("You caught a Pokémon in a\nFast Ball.");
const u8 gText_Quest_ArtisanBalls_Sub1_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub2_Name[] = _("Level Ball");
const u8 gText_Quest_ArtisanBalls_Sub2_Desc[] = _("Sub You caught a Pokémon in a\nLevel Ball.");
const u8 gText_Quest_ArtisanBalls_Sub2_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub3_Name[] = _("Lure Ball");
const u8 gText_Quest_ArtisanBalls_Sub3_Desc[] = _("You caught a Pokémon in a\nLure Ball.");
const u8 gText_Quest_ArtisanBalls_Sub3_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub4_Name[] = _("Heavy Ball");
const u8 gText_Quest_ArtisanBalls_Sub4_Desc[] = _("Sub You caught a Pokémon in a\nHeavy Ball.");
const u8 gText_Quest_ArtisanBalls_Sub4_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub5_Name[] = _("Love Ball");
const u8 gText_Quest_ArtisanBalls_Sub5_Desc[] = _("You caught a Pokémon in a\nLove Ball.");
const u8 gText_Quest_ArtisanBalls_Sub5_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub6_Name[] = _("Friend Ball");
const u8 gText_Quest_ArtisanBalls_Sub6_Desc[] = _("Sub You caught a Pokémon in a\nFriend Ball.");
const u8 gText_Quest_ArtisanBalls_Sub6_Map[] = _("N/A");
const u8 gText_Quest_ArtisanBalls_Sub7_Name[] = _("Moon Ball");
const u8 gText_Quest_ArtisanBalls_Sub7_Desc[] = _("You caught a Pokémon in a\nMoon Ball.");
const u8 gText_Quest_ArtisanBalls_Sub7_Map[] = _("N/A");

const u8 gText_Quest_ArtisanBalls2_Sub1_Name[] = _("Office Manager");
const u8 gText_Quest_ArtisanBalls2_Sub1_Desc[] = _("You battled an Office Manager that is\ninterested in working with Sergey.");
const u8 gText_Quest_ArtisanBalls2_Sub1_Map[] = _("Psfroute21");
const u8 gText_Quest_ArtisanBalls2_Sub2_Name[] = _("Marketing");
const u8 gText_Quest_ArtisanBalls2_Sub2_Desc[] = _("You battled a Marketing Director that is\ninterested in working with Sergey.");
const u8 gText_Quest_ArtisanBalls2_Sub2_Map[] = _("Psfroute70");
const u8 gText_Quest_ArtisanBalls2_Sub3_Name[] = _("Customer Service");
const u8 gText_Quest_ArtisanBalls2_Sub3_Desc[] = _("You battled a Customer Service rep that\nis interested in working with Sergey.");
const u8 gText_Quest_ArtisanBalls2_Sub3_Map[] = _("Psfroute61");

const u8 gText_Quest_ShelterSwitcheroo_Sub1_Name[] = _("Shelter 1");
const u8 gText_Quest_ShelterSwitcheroo_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterSwitcheroo_Sub1_Map[] = _("GldnGtePark");
const u8 gText_Quest_ShelterSwitcheroo_Sub2_Name[] = _("Shelter 2");
const u8 gText_Quest_ShelterSwitcheroo_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterSwitcheroo_Sub2_Map[] = _("Dogpatch");
const u8 gText_Quest_ShelterSwitcheroo_Sub3_Name[] = _("Shelter 3");
const u8 gText_Quest_ShelterSwitcheroo_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterSwitcheroo_Sub3_Map[] = _("Marin");
const u8 gText_Quest_ShelterSwitcheroo_Sub4_Name[] = _("Shelter 4");
const u8 gText_Quest_ShelterSwitcheroo_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterSwitcheroo_Sub4_Map[] = _("Mission");
const u8 gText_Quest_ShelterSwitcheroo_Sub5_Name[] = _("Shelter 5");
const u8 gText_Quest_ShelterSwitcheroo_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterSwitcheroo_Sub5_Map[] = _("Chinatown");

const u8 gText_Quest_ShelterTaxiSolution_Sub1_Name[] = _("Shelter 1");
const u8 gText_Quest_ShelterTaxiSolution_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterTaxiSolution_Sub1_Map[] = _("GldnGtePark");
const u8 gText_Quest_ShelterTaxiSolution_Sub2_Name[] = _("Shelter 2");
const u8 gText_Quest_ShelterTaxiSolution_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterTaxiSolution_Sub2_Map[] = _("Dogpatch");
const u8 gText_Quest_ShelterTaxiSolution_Sub3_Name[] = _("Shelter 3");
const u8 gText_Quest_ShelterTaxiSolution_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterTaxiSolution_Sub3_Map[] = _("Marin");
const u8 gText_Quest_ShelterTaxiSolution_Sub4_Name[] = _("Shelter 4");
const u8 gText_Quest_ShelterTaxiSolution_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterTaxiSolution_Sub4_Map[] = _("Mission");
const u8 gText_Quest_ShelterTaxiSolution_Sub5_Name[] = _("Shelter 5");
const u8 gText_Quest_ShelterTaxiSolution_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_ShelterTaxiSolution_Sub5_Map[] = _("Chinatown");

const u8 gText_Quest_NeighborhoodCleanUp_Sub1_Name[] = _("Punk 1");
const u8 gText_Quest_NeighborhoodCleanUp_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp_Sub1_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp_Sub2_Name[] = _("Punk 2");
const u8 gText_Quest_NeighborhoodCleanUp_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp_Sub2_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp_Sub3_Name[] = _("Punk 3");
const u8 gText_Quest_NeighborhoodCleanUp_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp_Sub3_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp_Sub4_Name[] = _("Punk 4");
const u8 gText_Quest_NeighborhoodCleanUp_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp_Sub4_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp_Sub5_Name[] = _("Punk 5");
const u8 gText_Quest_NeighborhoodCleanUp_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp_Sub5_Map[] = _("Dogpatch");

const u8 gText_Quest_NeighborhoodCleanUp2_Sub1_Name[] = _("Punk 1");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub1_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub2_Name[] = _("Punk 2");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub2_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub3_Name[] = _("Punk 3");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub3_Map[] = _("Dogpatch");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub4_Name[] = _("Punk 4");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp2_Sub4_Map[] = _("Dogpatch");

const u8 gText_Quest_NeighborhoodCleanUp3_Sub1_Name[] = _("Punk 1");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub1_Map[] = _("BernalHeights");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub2_Name[] = _("Punk 2");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub2_Map[] = _("BernalHeights");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub3_Name[] = _("Punk 3");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_NeighborhoodCleanUp3_Sub3_Map[] = _("BernalHeights");

const u8 gText_Quest_RockCollector_Sub1_Name[] = _("Fire");
const u8 gText_Quest_RockCollector_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub1_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub2_Name[] = _("Water");
const u8 gText_Quest_RockCollector_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub2_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub3_Name[] = _("Thunder");
const u8 gText_Quest_RockCollector_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub3_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub4_Name[] = _("Leaf");
const u8 gText_Quest_RockCollector_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub4_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub5_Name[] = _("Moon");
const u8 gText_Quest_RockCollector_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub5_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub6_Name[] = _("Sun");
const u8 gText_Quest_RockCollector_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub6_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub7_Name[] = _("Shiny");
const u8 gText_Quest_RockCollector_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub7_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub8_Name[] = _("Dusk");
const u8 gText_Quest_RockCollector_Sub8_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub8_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub9_Name[] = _("Dawn");
const u8 gText_Quest_RockCollector_Sub9_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub9_Map[] = _("Presidio");
const u8 gText_Quest_RockCollector_Sub10_Name[] = _("Ice");
const u8 gText_Quest_RockCollector_Sub10_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RockCollector_Sub10_Map[] = _("Presidio");

const u8 gText_Quest_HiddenGrottoMapping_Sub1_Name[] = _("Grotto 1");
const u8 gText_Quest_HiddenGrottoMapping_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping_Sub1_Map[] = _("Psfroute17");
const u8 gText_Quest_HiddenGrottoMapping_Sub2_Name[] = _("Grotto 2");
const u8 gText_Quest_HiddenGrottoMapping_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping_Sub2_Map[] = _("Psfroute32");
const u8 gText_Quest_HiddenGrottoMapping_Sub3_Name[] = _("Grotto 3");
const u8 gText_Quest_HiddenGrottoMapping_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping_Sub3_Map[] = _("MuirWoods");
const u8 gText_Quest_HiddenGrottoMapping_Sub4_Name[] = _("Grotto 4");
const u8 gText_Quest_HiddenGrottoMapping_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping_Sub4_Map[] = _("Psfroute30");
const u8 gText_Quest_HiddenGrottoMapping_Sub5_Name[] = _("Grotto 5");
const u8 gText_Quest_HiddenGrottoMapping_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping_Sub5_Map[] = _("Psfroute25");

const u8 gText_Quest_HiddenGrottoMapping2_Sub1_Name[] = _("New Grotto 1");
const u8 gText_Quest_HiddenGrottoMapping2_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping2_Sub1_Map[] = _("Psfroute18");
const u8 gText_Quest_HiddenGrottoMapping2_Sub2_Name[] = _("New Grotto 2");
const u8 gText_Quest_HiddenGrottoMapping2_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping2_Sub2_Map[] = _("Psfroute14");
const u8 gText_Quest_HiddenGrottoMapping2_Sub3_Name[] = _("New Grotto 3");
const u8 gText_Quest_HiddenGrottoMapping2_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_HiddenGrottoMapping2_Sub3_Map[] = _("Psfroute49");

const u8 gText_Quest_UltraWormholeResearch_Sub1_Name[] = _("Poipole");
const u8 gText_Quest_UltraWormholeResearch_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub1_Map[] = _("Psfroute9");
const u8 gText_Quest_UltraWormholeResearch_Sub2_Name[] = _("Dusclops");
const u8 gText_Quest_UltraWormholeResearch_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub2_Map[] = _("Psfroute70");
const u8 gText_Quest_UltraWormholeResearch_Sub3_Name[] = _("Volcarona");
const u8 gText_Quest_UltraWormholeResearch_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub3_Map[] = _("Psfroute7");
const u8 gText_Quest_UltraWormholeResearch_Sub4_Name[] = _("Camerupt");
const u8 gText_Quest_UltraWormholeResearch_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub4_Map[] = _("GldnGteWilds");
const u8 gText_Quest_UltraWormholeResearch_Sub5_Name[] = _("Deino");
const u8 gText_Quest_UltraWormholeResearch_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub5_Map[] = _("Psfroute5");
const u8 gText_Quest_UltraWormholeResearch_Sub6_Name[] = _("Noivern");
const u8 gText_Quest_UltraWormholeResearch_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub6_Map[] = _("Psfroute15");
const u8 gText_Quest_UltraWormholeResearch_Sub7_Name[] = _("Shuckle");
const u8 gText_Quest_UltraWormholeResearch_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub7_Map[] = _("Psfroute19");
const u8 gText_Quest_UltraWormholeResearch_Sub8_Name[] = _("Kingler");
const u8 gText_Quest_UltraWormholeResearch_Sub8_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub8_Map[] = _("Psfroute62");
const u8 gText_Quest_UltraWormholeResearch_Sub9_Name[] = _("Orbeetle");
const u8 gText_Quest_UltraWormholeResearch_Sub9_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub9_Map[] = _("Psfroute63");
const u8 gText_Quest_UltraWormholeResearch_Sub10_Name[] = _("Donphan");
const u8 gText_Quest_UltraWormholeResearch_Sub10_Desc[] = _("Sub Lorem");
const u8 gText_Quest_UltraWormholeResearch_Sub10_Map[] = _("Psfroute8");

const u8 gText_Quest_WildfireRisk_Sub1_Name[] = _("100 Fire types");
const u8 gText_Quest_WildfireRisk_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WildfireRisk_Sub1_Map[] = _("N/A");
const u8 gText_Quest_WildfireRisk_Sub2_Name[] = _("100 Flying types");
const u8 gText_Quest_WildfireRisk_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WildfireRisk_Sub2_Map[] = _("N/A");
const u8 gText_Quest_WildfireRisk_Sub3_Name[] = _("100 Electric types");
const u8 gText_Quest_WildfireRisk_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WildfireRisk_Sub3_Map[] = _("N/A");

const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Name[] = _("Item 1");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Name[] = _("Item 2");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Name[] = _("Item 3");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Name[] = _("Item 4");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Name[] = _("Item 5");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Name[] = _("Item 6");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Name[] = _("Item 7");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Name[] = _("Item 8");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Map[] = _("Lakemerced");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Name[] = _("Item 9");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Map[] = _("Lakemerced");


const u8 gText_Quest_TaxicabTurnAroundSea_Sub1_Name[] = _("Water 1");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub1_Map[] = _("Treasureisland");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub2_Name[] = _("Water 2");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub2_Map[] = _("Sunset");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub3_Name[] = _("Water 3");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub3_Map[] = _("GldnGtePark");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub4_Name[] = _("Water 4");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub4_Map[] = _("Presidio");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub5_Name[] = _("Water 5");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundSea_Sub5_Map[] = _("Pacifica");

const u8 gText_Quest_TaxicabTurnAroundAir_Sub1_Name[] = _("Flyer 1");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub1_Map[] = _("Castro");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub2_Name[] = _("Flyer 2");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub2_Map[] = _("Mission");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub3_Name[] = _("Flyer 3");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub3_Map[] = _("Dogpatch");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub4_Name[] = _("Flyer 4");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub4_Map[] = _("SouthBay");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub5_Name[] = _("Flyer 5");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundAir_Sub5_Map[] = _("Oakland");

const u8 gText_Quest_TaxicabTurnAroundLand_Sub1_Name[] = _("Runner 1");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub1_Map[] = _("Marin");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub2_Name[] = _("Runner 2");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub2_Map[] = _("Berkeley");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub3_Name[] = _("Runner 3");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub3_Map[] = _("Tenderloin");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub4_Name[] = _("Runner 4");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub4_Map[] = _("Chinatown");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub5_Name[] = _("Runner 5");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub5_Map[] = _("Japantown");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub6_Name[] = _("Runner 6");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub6_Map[] = _("SOMA");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub7_Name[] = _("Runner 7");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_TaxicabTurnAroundLand_Sub7_Map[] = _("BernalHeights");

const u8 gText_Quest_PersuasivePassenger_Sub1_Name[] = _("Driver 1");
const u8 gText_Quest_PersuasivePassenger_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_PersuasivePassenger_Sub1_Map[] = _("Alameda");
const u8 gText_Quest_PersuasivePassenger_Sub2_Name[] = _("Driver 2");
const u8 gText_Quest_PersuasivePassenger_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_PersuasivePassenger_Sub2_Map[] = _("Haightashbury");
const u8 gText_Quest_PersuasivePassenger_Sub3_Name[] = _("Bad Driver");
const u8 gText_Quest_PersuasivePassenger_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_PersuasivePassenger_Sub3_Map[] = _("Oakland");

const u8 gText_Quest_BodegaBurnout_Sub1_Name[] = _("Store 1");
const u8 gText_Quest_BodegaBurnout_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub1_Map[] = _("Treasureisland");
const u8 gText_Quest_BodegaBurnout_Sub2_Name[] = _("Store 2");
const u8 gText_Quest_BodegaBurnout_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub2_Map[] = _("Sunset");
const u8 gText_Quest_BodegaBurnout_Sub3_Name[] = _("Store 3");
const u8 gText_Quest_BodegaBurnout_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub3_Map[] = _("GldnGtePark");
const u8 gText_Quest_BodegaBurnout_Sub4_Name[] = _("Store 4");
const u8 gText_Quest_BodegaBurnout_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub4_Map[] = _("Presidio");
const u8 gText_Quest_BodegaBurnout_Sub5_Name[] = _("Store 5");
const u8 gText_Quest_BodegaBurnout_Sub5_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub5_Map[] = _("Pacifica");
const u8 gText_Quest_BodegaBurnout_Sub6_Name[] = _("Store 6");
const u8 gText_Quest_BodegaBurnout_Sub6_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub6_Map[] = _("Castro");
const u8 gText_Quest_BodegaBurnout_Sub7_Name[] = _("Store 7");
const u8 gText_Quest_BodegaBurnout_Sub7_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub7_Map[] = _("Mission");
const u8 gText_Quest_BodegaBurnout_Sub8_Name[] = _("Store 8");
const u8 gText_Quest_BodegaBurnout_Sub8_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub8_Map[] = _("Dogpatch");
const u8 gText_Quest_BodegaBurnout_Sub9_Name[] = _("Store 9");
const u8 gText_Quest_BodegaBurnout_Sub9_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub9_Map[] = _("SouthBay");
const u8 gText_Quest_BodegaBurnout_Sub10_Name[] = _("Store 10");
const u8 gText_Quest_BodegaBurnout_Sub10_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub10_Map[] = _("Marin");
const u8 gText_Quest_BodegaBurnout_Sub11_Name[] = _("Store 11");
const u8 gText_Quest_BodegaBurnout_Sub11_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub11_Map[] = _("Berkeley");
const u8 gText_Quest_BodegaBurnout_Sub12_Name[] = _("Store 12");
const u8 gText_Quest_BodegaBurnout_Sub12_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub12_Map[] = _("Tenderloin");
const u8 gText_Quest_BodegaBurnout_Sub13_Name[] = _("Store 13");
const u8 gText_Quest_BodegaBurnout_Sub13_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub13_Map[] = _("Chinatown");
const u8 gText_Quest_BodegaBurnout_Sub14_Name[] = _("Store 14");
const u8 gText_Quest_BodegaBurnout_Sub14_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub14_Map[] = _("Japantown");
const u8 gText_Quest_BodegaBurnout_Sub15_Name[] = _("Store 15");
const u8 gText_Quest_BodegaBurnout_Sub15_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub15_Map[] = _("SOMA");
const u8 gText_Quest_BodegaBurnout_Sub16_Name[] = _("Store 16");
const u8 gText_Quest_BodegaBurnout_Sub16_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub16_Map[] = _("BernalHeights");
const u8 gText_Quest_BodegaBurnout_Sub17_Name[] = _("Store 17");
const u8 gText_Quest_BodegaBurnout_Sub17_Desc[] = _("Sub Lorem");
const u8 gText_Quest_BodegaBurnout_Sub17_Map[] = _("Alameda");

const u8 gText_Quest_WarehouseWarfare_Sub1_Name[] = _("Warehouse East");
const u8 gText_Quest_WarehouseWarfare_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WarehouseWarfare_Sub1_Map[] = _("Psfroute51");
const u8 gText_Quest_WarehouseWarfare_Sub2_Name[] = _("Warehouse West");
const u8 gText_Quest_WarehouseWarfare_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WarehouseWarfare_Sub2_Map[] = _("Psfroute20");
const u8 gText_Quest_WarehouseWarfare_Sub3_Name[] = _("Warehouse North");
const u8 gText_Quest_WarehouseWarfare_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_WarehouseWarfare_Sub3_Map[] = _("Psfroute76");

const u8 gText_Quest_RestoreToTheirFormerGlory_Sub1_Name[] = _("Chinatown");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub1_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub1_Map[] = _("Chinatown");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub2_Name[] = _("Treasureisland");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub2_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub2_Map[] = _("Treasureisland");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub3_Name[] = _("Marin");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub3_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub3_Map[] = _("Marin");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub4_Name[] = _("Haightashbury");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub4_Desc[] = _("Sub Lorem");
const u8 gText_Quest_RestoreToTheirFormerGlory_Sub4_Map[] = _("Haightashbury");

//quest flavor
const u8 gText_PlayersAdventure_Flavor1[] =_("Explore everything eastern SanFran has\nto offer on your way to the\nChampionship.");
const u8 gText_PlayersAdventure_Flavor2[] =_("Head back to the Compound in Southbay\nand get a good night's sleep.");
const u8 gText_PlayersAdventure_Flavor3[] =_("Go to the Ferrybuilding and take the\nferry to Alameda. Head to Berkeley for\nyour next badge!");
const u8 gText_PlayersAdventure_Flavor4[] =_("Backtrack down Psfroute22 to get back\nto the Alameda Ferry.");
const u8 gText_PlayersAdventure_Flavor5[] =_("Complete the challenge on Alcatraz and\nlearn more about SanFran's history.");
const u8 gText_PlayersAdventure_Flavor6[] =_("Explore everything western SanFran has\nto offer on your way to the\nChampionship.");
const u8 gText_PlayersAdventure_Flavor7[] =_("Head to the Chasecenter construction\nsite on Psfroute22.");
const u8 gText_PlayersAdventure_Flavor8[] =_("Defeat the Garbordor holding the\nstadium hostage!");
const u8 gText_PlayersAdventure_Flavor9[] =_("Head back to the Compound in Southbay\nand get a good night's sleep.");
const u8 gText_PlayersAdventure_Flavor10[] =_("Complete all of Siebold's challenges in\nMuirwoods.");
const u8 gText_PlayersAdventure_Flavor11[] =_("Join the police raid on Team Rocket's\nbase!");
const u8 gText_PlayersAdventure_Flavor12[] =_("Head back to the Compound in Southbay.\nThe Championship begins first thing\ntomorrow!");
const u8 gText_PlayersAdventure_Flavor13[] =_("Go the Chasecenter and get ready for\nthe Championship!");
const u8 gText_PlayersAdventure_Flavor14[] =_("Take a walk, cool your head before the\nmatches start.");
const u8 gText_PlayersAdventure_Flavor15[] =_("Head to the Arena for your Group Stage\nmatch. Good luck!");
const u8 gText_PlayersAdventure_Flavor16[] =_("Head to the Arena for your Semifinal\nmatch. Good luck!");
const u8 gText_PlayersAdventure_Flavor17[] =_("Watch Archer vs Bianca from the Skybox.");
const u8 gText_PlayersAdventure_Flavor18[] =_("Go the Arena, and face Archer for the\nChampionship!");
const u8 gText_PlayersAdventure_Flavor19[] =_("You're the Champion. Congratulations!");
const u8 gText_PlayersAdventure_Flavor20[] =_("Take a break; explore Treasureisland.");
const u8 gText_PlayersAdventure_Flavor21[] =_("Defeat Archer on Treasureisland.");
const u8 gText_PlayersAdventure_Flavor22[] =_("Have lunch with Archer on\nTreasureisland.");
const u8 gText_PlayersAdventure_Flavor23[] =_("Help Archer out with his project. Talk\nto them on Treasureisland to figure\nout where to start.");
const u8 gText_PlayersAdventure_Flavor24[] =_("Head to the Salesforcetower to talk to\nYcombinator.");
const u8 gText_PlayersAdventure_Flavor25[] =_("Head to Alcatraz to talk to Teamrocket.");
const u8 gText_PlayersAdventure_Flavor26[] =_("Head back to the Compound in Presidio\nand get some rest. You've got a big\ndecision to make.");
const u8 gText_PlayersAdventure_Flavor27[] =_("Go to Alcatraz to help Team Rocket, or\ngo to Salesforcetower to help\nYcombinator.");
const u8 gText_PlayersAdventure_Flavor28[] =_("You're back to the day of the big\ndecision. Will you help Teamrocket at\nAlcatraz this time?");
const u8 gText_PlayersAdventure_Flavor29[] =_("Head to the Salesforcetower to help\ntake down Teamrocket once and for all.");
const u8 gText_PlayersAdventure_Flavor30[] =_("Teamrocket is finished. You've done it.");
const u8 gText_PlayersAdventure_Flavor31[] =_("Enter the Chasecenter Arena for your\nexhibition battle!");
const u8 gText_PlayersAdventure_Flavor32[] =_("Teamrocket is disbanded. You're the\nChampion. Life is good.");
const u8 gText_PlayersAdventure_Flavor33[] =_("If you want a do-over, head to the top\nof Twin Peaks.");
const u8 gText_PlayersAdventure_Flavor34[] =_("Look all over SanFran to find clues on\nthe location of Wikstrom.");
const u8 gText_PlayersAdventure_Flavor35[] =_("Head to Oakland for the warehouse rave,\nor Alcatraz for the all hands meeting.");
const u8 gText_PlayersAdventure_Flavor36[] =_("Which corporation should Teamrocket\ntackle first? Head to Alcatraz to\nstart working on it!");
const u8 gText_PlayersAdventure_Flavor37[] =_("Head back to Archer's house in Alameda\nand get a good night's sleep.");
const u8 gText_PlayersAdventure_Flavor38[] =_("Is the message a clue? Meet the team at\nPsfroute8.");
const u8 gText_PlayersAdventure_Flavor39[] =_("Head back to Alcatraz to regroup.");
const u8 gText_PlayersAdventure_Flavor40[] =_("Head into the belly of the beast. Meet\nat Sabrina's house in Sunset.");
const u8 gText_PlayersAdventure_Flavor41[] =_("Sabrina's home in the sunset has a warp\ntile directly into the Salesforce. It's\ntime to finish this!");
const u8 gText_PlayersAdventure_Flavor42[] =_("You became Champion, made some\nmistakes, but the region is just a\nlittle better because of your efforts.");
const u8 gText_PlayersAdventure_Flavor43[] =_("You became Champion, stamped out\nYcombinator, and the region is a just a\nlittle better because of your efforts.");

const u8 gText_RabiesOutbreak_Flavor1[] =_("Feral Glameow are endangering wildlife\nin Bernalheights. Defeat {STR_VAR_3} of them\nand report back to he ASPCA Officer.");

const u8 gText_BetweenAStoneAndAHardPlace_Flavor1[] =_("Take {STR_VAR_3} more trolley ride(s), and get a\nstone 'capable of pushing a Pokemon\nfurther beyond'!");
