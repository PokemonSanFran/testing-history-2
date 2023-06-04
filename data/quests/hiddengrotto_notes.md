hidden grotto planning

STORY AND FLOW
each route has a grotto on it, accessed by walking up, arrows appear, and player interacts with tile in front of them,pressing A does a warp inside

first hidden grotto shows NPC inside, walking towards the entrance, greetss players, explains hidden grottos, surprised they're here, starts quests, tells you about his home in Gldgtewilds

each hidden grotto has a page of his journal, sparkling on ground until player grabs them

asks you to find a grotto near water, a grotto near a forest, and a grotto near a cave

go to house, wife says he hasn't been seen, but she was told about you, and gives you a reward for bringing data on the three biomes you went to

finish quest 1

asks if you could find him, he's probably in the other grottos

show up with a letter, starts quest 2
she takes letters, pins them to the wall for you to read
takes every letter you give her, one letter for each grotto

giving her all the letters, thanks you but is unable to make any progress

gives you a key item of some kind as a reward

key item reacts near the salesforce tower, leads you to the basement somehow, doesn't work until after you beat Rose

researcher is there, aged up by 50 years, uses his totem mon to open a wormhole, asks you to catch the pokemon inside

it respawns if you don't catch it

after first ultra beast catch, quest 3 starts, researcher tells you the wormholes opened across the region - if you catch the pokemon that crawled out of them, he can open the wormhole in the lab and let you go there to battle against another ultra beast

LOGIC
each grotto type has a subquest attached, just walking inside when quest is active will mark it off

going into first grotto starts onframe cutscene with him

three grottos have hidden page of journal, sparkles on ground, found near the "back" of the grotto, picking it up subquest and it never spawns again

after first talking to wife, journal pieces are all taken and quest is actually revealed to you, you don't go into reward mode until wife has all the journal pieces, and then immediately completes

downtown SOMA sets off the key item from wife but only after beating rose and only happens once, reacts again when inside rose's office, and once more in front of a bookcase in rose's office, talking to bookcase with item in bag will open a secret elevator down (tracked with a var)

ultra beast temp flag will only respawn if subquest not marked as complete
subquest is marked as complete when you catch
there is no reward, thanks you, goes back to research

GROTTO SECRETS

each grotto has a flag for its secret
when set, every 256 steps, there is a 5% chance of it being unset
is set when the selected pokemon or item is defeated / captured
does not get rerolled

40% chance its a hidden item
40% chance its a visible item
20% chance its a pokemon

all grottos share a single item table except for one wilcard 1% item in the visible section

each route has 3 or 4 pokemon in its table each with varying rates

for each grotto, save block will remember the ID in the table, so we only need to store like this

grottos[i] = {4, 5,...}

meaning that for the 0th grotto, option 4 was rolled

looking up the table reveals that option 4 is for grotto 0 is a wooper

uses variable object ID to choose a sprite and a script

Psfroute1_Grotto	Mountain
Psfroute30_Grotto	Island
Psfroute9_Grotto	Mountain
Psfroute70_Grotto	Mountain
Psfroute17_Grotto	Plains
Psfroute22_Grotto	Island
Psfroute20_Grotto	Island
Psfroute49_Grotto	Island
Psfroute38_Grotto	Mountain
Psfroute14_Grotto	Mountain
Psfroute21_Grotto	Plains
Psfroute19_Grotto	Deprecated
Psfroute7_Grotto	Forest
Psfroute63_Grotto	Plains
Psfroute12_Grotto	Deprecated
Psfroute11_Grotto	Plains
Psfroute32_Grotto	Swamp
Psfroute62_Grotto	Swamp
Psfroute76_Grotto	Island
Psfroute72_Grotto	Island
Psfroute18_Grotto	Mountain
Psfroute61_Grotto	Forest
Psfroute43_Grotto	Forest
Psfroute5_Grotto	Forest
Psfroute15_Grotto	Island
Psfroute51_Grotto	Island
Psfroute25_Grotto	Underground
Psfroute8_Grotto	Plains
Psfroute13_Grotto	Plains
