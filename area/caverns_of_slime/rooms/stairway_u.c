#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "A room with stairs leading down" );
  set_long( wrap("The slime resumes again. It seems to cover everything - the floor, "+
  "walls, ceiling...even the stairs leading down are covered in it. It has started "+
  "to give off an eerie glow which is almost light, but not quite. Several times "+
  "you notice small objects stuck in it: old bones, rocks, miscellaneous knickknacks...\n"));
  set_item_desc(([({ "floor", "walls", "ceiling"}) : "It's completely covered in slime.\n",
                  ({ "small objects", "objects", "old bones", "bones", "rocks",
                  "miscellaneous knickknacks", "knickknacks"}) : "It's all junk..."+
                  "nothing of interest is to be found.\n",
                  "stairs" : "They lead downwards. You should take care with them, "+
                  "as the steps are quite slippery with slime.\n"  ]) );
  set_light(50);
  set_water(5);
  set_sounds(120, ({
	                "You have trouble keeping your balance on the slippery slime.\n" }) );
  set_exits(
     ([
       "stairs" : "/u/a/allanon/area/caverns_of_slime/rooms/stairway_d.c",
       "north"  : "/u/a/allanon/area/caverns_of_slime/rooms/intersection.c"]));

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/shade.c");
}