#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_short( "In some kind of lair" );
  set_long( wrap("The caves suddenly spread far outwards here, forming a "+
  "vast, bowl-shaped cavern. The domed ceiling is at least a hundred feet over your "+
  "head at its peak. Slime drips down the ceiling and walls, splatting onto the floor "+
  "occasionally. The odors are suffocating. It feels like a sauna in here - a "+
  "stifling, pungent sauna of torture. An enormous magical orb hovering over "+
  "the middle of the room throws out a sickly yellow light. This room has more "+
  "bones in it than any of the previous ones. The trapdoor that you came through "+
  "is situated at a point in the ceiling close to the ground.\n"));

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/kslime.c");

  set_item_desc(([
                  ({ "cavern", "ceiling"}) : "This place is huge! If not for the slime, it "+
                  "would be a wondrous sight indeed.\n",
                  "slime" : "You are getting thoroughly sick with slime by "+
                  "now.\n",
                  "orb" : "It seems to be a huge 'orb of light'. You've never "+
                  "seen one this big before.\n",
                  "bones" : "Some of these bones don't even look vaguely "+
                  "human. You spot goblin, kobold, ogre, and even a few dragon "+
                  "bones. You come to the conclusion that some of these bones "+
                  "were here well before the others.\n",
                  "trapdoor" : "It's the door you entered from.\n"]) );
  set_light(70);
  set_sounds(120, ({"Some slime falls from the ceiling, hitting you square in "+
	                "the face.\n",
	                "You nearly retch on the stench, where's the fresh air!\n",
	                "The moist, warm air makes you sweat profusely.\n" }) );
  set_exits(
  (["up" : "/u/a/allanon/area/caverns_of_slime/rooms/intersection.c"]));

  create_door("up", "down",
           (["short" : "enormous brass trapdoor inscribed with runes",
             "long" : "It's absolutely massive. Ancient runes have been "+
             "inscribed into its surface. A smallish lock keeps it closed "+
             "tight.\n",
             "key" : "/u/a/allanon/area/caverns_of_slime/obj/key.c",
             "status" : "locked",
             "autolock" : 1,
             "autoclose" : 300,
             "quality" : 1001,
             "material" : "brass",
             "close_msg" : "You close the huge brass trapdoor.\n",
             "open_msg" : "You open the huge brass trapdoor.\n"]) );
}

