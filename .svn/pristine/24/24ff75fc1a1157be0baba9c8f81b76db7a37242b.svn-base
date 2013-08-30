#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Grave of a ranger" );
  set_long( wrap("The smell of rot and decay is overpowering in this room. You sense "+
  "that the source is a large, ornate tomb in the center of the room. It looks like "+
  "it has recently been ransacked by graverobbers, or maybe goblins. The huge lid "+
  "is splintered and dented, and all the embedded finery has been removed. Somehow "+
  "you get the sense that whoever was buried here, is clearly not happy to have their "+
  "final resting place disturbed.\n"));
  add_monster("/u/a/allanon/area/caverns_of_slime/mon/spirit.c"); 
  set_item_desc(([({ "large tomb", "ornate tomb", "tomb"}) : "You think that it must have looked "+
                  "really impressive before being looted. All the gilding has been "+
                  "stripped, and no jewel was left behind. Small text on the tomb "+
                  "says: 'May the ashes herein remain forever undisturbed'. The name "+
                  "below the text has been worn away...you suppose you will never know "+
                  "the identity of the remains.\n", 
                  ({ "huge lid", "lid" }) : "A standard casket lid, once adorned "+
                  "with much finery. It seems to have been sundered from brute force.\n"]) );
  set_light(50);
  set_water(5);  
  set_sounds(120, ({ 
	                "You can't stand the stench much longer...you think you may faint soon.\n", 
	                "You can almost touch the deathly stillness of the room.\n"}) ); 
  set_exits(
     ([
       "northwest" : "/u/a/allanon/area/caverns_of_slime/rooms/pool4.c",
       "northeast"  : "/u/a/allanon/area/caverns_of_slime/rooms/stairway_d.c"]));
}