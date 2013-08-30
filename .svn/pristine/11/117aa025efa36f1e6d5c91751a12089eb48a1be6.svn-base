#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_short( "A four-way intersection" );
  set_long( wrap("The slime suddenly ends here, and a stone road that looks "+
  "quite out of place is here instead. This is a three-way intersection, "+
  "with exits leading east, south, and west. Two tall torches are stuck into "+
  "piles of bones on either side of a hole leading down. A huge trapdoor inscribed "+
  "with runes blocks the exit in that direction. You can see that the odor and "+
  "the warm air is coming up from under the trapdoor.\n"));
  set_item_desc((["road" : "It's paved with perfectly cut and fitted stones. "+
                  "You wonder what it is doing down here. Weird, it seems to "+
                  "continue straigth into north too but there's just a wall\n",
                  "torches" : "Two ordinary torches. They burn darkly and "+
                  "somehow make you feel less at ease.\n",
                  "wall": "The wall seems somehow vague.\n",
                  ({ "piles", "bones"}) : "You are really getting tired of seeing bones by "+
                  "now.\n"]));
  set_light(50);
  set_water(5);
  set_sounds(120, ({
	                "The torches flicker malevolantly.\n",
	                "The road seems very odd and suspicious.\n",
	                "The bones make you feel nervous and jumpy. You keep "+
	                "looking over your shoulder.\n",
	                "You notice that the road runs north, but it seems to go "+
	                "right under the wall. Isn't that odd?\n" }) );
  set_hidden_exits( ({ "north" }) );
  set_exits(
  ([
    "south" : "/u/a/allanon/area/caverns_of_slime/rooms/stairway_u.c",
    "east" : "/u/a/allanon/area/caverns_of_slime/rooms/guarded.c",
    "west" : "/u/a/allanon/area/caverns_of_slime/rooms/hole.c",
    "down" : "/u/a/allanon/area/caverns_of_slime/rooms/klair.c",
    "north" : "/u/a/allanon/area/caverns_of_slime/rooms/secret.c"]));
  set_exit_msg( ([ "north" : "$N passes right through the northern wall!" ]) );

    create_door("down", "up",
     (["short" : "enormous brass trapdoor inscribed with runes",
                 "long" : "It's absolutely massive. Ancient runes have been "+
                 "inscribed into its surface. A smallish lock keeps it closed "+
                 "tight. With the stone road, it looks curiously like a manhole.\n",
                 "key" : "/u/a/allanon/area/caverns_of_slime/obj/key.c",
                 "status" : "locked",
                 "autolock" : 1,
                  "ids" : ({ "door", "brass door", "trapdoor", "brass trapdoor" }),
                 "autoclose" : 300,
                 "quality" : 1001,
                 "material" : "brass",
                 "close_msg" : "You close the huge brass trapdoor.\n",
                 "open_msg" : "You open the huge brass trapdoor.\n"  ]) );

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/bluefire_bat.c");
}
