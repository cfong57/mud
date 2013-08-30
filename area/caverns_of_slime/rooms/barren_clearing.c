#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_outside("p");
  set_light( (: query_ambient_light :) );
  set_short( "A barren clearing in the middle of the forest" );
  set_long( wrap("The ground here is badly blackened, seemingly from an old "+
  "explosion. The blast area stretches for at least 20 feet in both "+
  "directions. The gutted, fire-charred remains of a laboratory, now almost "+
  "destroyed by the forces of nature, stands in the middle. Curious slime "+
  "trails and puddles of sickly ooze dot the clearing, giving off a strong, "+
  "pungent odor. A large, forbidding-looking hole with a ladder leads "+
  "downwards. Pale green fog billows out of it, making it difficult to "+
  "breathe.\n"));

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/ghost.c");
  set_item_desc(([
                  "ground" : "It's scorched pretty badly.\n",
                  ({ "remains", "laboratory"}) : "The remains look like they could collapse any "+
                  "day now.\n",
                  ({ "slime", "trails", "ooze", "puddles"}) : "It almost seems like they were made by giant "+
                  "slugs.\n",
                  "hole" : "You can go down if you want.\n",
                  "fog" : "The fog is pale green, and seems to float around at "+
                  "random. It's difficult to breathe it and you wonder if "+
                  "it's possibly toxic.\n"  ]) );
  set_sounds(120, ({
	                "A nearby puddle bubbles a little bit and lets off more "+
	                "odors.\n",
	                "The fog follows you around and makes you cough.\n",
	                "You thought you just heard a squelching sound, but you "+
	                "don't see anything.\n" }) );
  set_exits(([
       "hole"  : "/u/a/allanon/area/caverns_of_slime/rooms/hole.c",
       "path"  : "/d/world/rooms/612,598.world"]));
}
