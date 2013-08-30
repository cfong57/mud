#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "A passage leading north" );
  set_long( wrap("Green fog suddenly envelops you in this room. You can see "+
                 "about 3 feet in front of you, and not much more than that. "+
                 "This room feels really eerie and you have a bad feeling that "+
                 "maybe you shouldn't be here.\n"));
  set_item_desc(([({ "green fog", "fog"}) : "The fog makes vision all but impossible in this room.\n"]) );
  set_light(50);
  set_water(5);

  set_no_vision("The fog prevents sight.\n");
  set_sounds(120, ({
	                "The fog follows you around and makes you cough.\n",
	                "You can't see a thing...\n" }) );
  set_hidden_exits( ({ "north", "south" }) );
  set_exits(
     ([
       "north" : "/u/a/allanon/area/caverns_of_slime/rooms/ledge.c",
       "south" : "/u/a/allanon/area/caverns_of_slime/rooms/hole.c"]));
  set_exit_msg( ([ "north": "You think you heard some movement, but you aren't sure.",
                   "south": "You think you heard some movement, but you aren't sure." ]) );

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/rspirit.c");
}