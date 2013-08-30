#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "On a ledge above a basin" );
  set_monsters( ([ "/u/a/allanon/area/caverns_of_slime/mon/slime.c" : 3 ]) );
  set_long( wrap("You're standing on a ledge overlooking the southern side of a huge basin. "+
  "Seemingly it is the result of some sort of liquid eating away at the rock for a long "+
  "time, eventually forming a bowl-shaped depression. Subsequently it has been "+
  "filled with slime, which drips from the ceiling into the basin. It's not a very "+
  "long way down, and you suppose you could reach the basin if you wanted to. The fog "+
  "that so blinded you in the previous room seems to have dissipated suddenly.\n"));
  set_item_desc(([({ "huge basin", "basin"}) : 
  "The basin is about 60 feet in diameter. Vaguely rounded in shape, it reminds "+
  "you of just a larger version of one of the ubiquitous slime puddles. You spot "+
  "a small island-like piece of rock jutting up out of the slime...you could "+
  "probably reach it once you're in the basin.\n"]) );
  set_light(50);
  set_water(5);   
  set_sounds(120, ({   
	                "The surface of the basin is serenely calm.\n", 
	                "You wonder at the size of the basin. These caves don't seem very old, and "+
	                "you doubt that simple water would be able to make something like this...\n" }) ); 
  set_exits(
     ([
       "basin" : "/u/a/allanon/area/caverns_of_slime/rooms/basin.c",
       "south" : "/u/a/allanon/area/caverns_of_slime/rooms/passage.c"]));
  set_exit_msg( ([ "basin" : "$N jumps down to the basin." ]) ); 
}