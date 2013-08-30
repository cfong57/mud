#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "A room with stairs leading up" );
  set_long( wrap("A simple flight of stairs does nothing to stop the slime. It "+
  "still covers everything - the floor, walls, and ceiling...and, of course, the "+
  "stairs leading back up. It gives off an eerie glow which is almost light, but "+
  "not quite. Several times you notice small objects stuck in it: old bones, "+
  "rocks, miscellaneous knickknacks...A tunnel leads southwest from here.\n"));

  set_item_desc(([({ "floor", "walls", "ceiling"}) : "It's completely covered in slime.\n",
                  ({ "small objects", "objects", "old bones", "bones", "rocks",
                  "miscellaneous knickknacks", "knickknacks"}) : "It's all junk..."+
                  "nothing of interest is to be found.\n",
                  "stairs" : "They lead upwards. You should take care with them, "+
                  "as the steps are quite slippery with slime.\n"  ]) );
  set_light(50);
  set_water(5);
  set_sounds(120, ({
	                "You have trouble keeping your balance on the slippery slime.\n",
	                "The reeking smell of decay seems to come from the southwest.\n"}) );
  set_exits(
     ([
       "stairs" : "/u/a/allanon/area/caverns_of_slime/rooms/stairway_u.c",
       "southwest"  : "/u/a/allanon/area/caverns_of_slime/rooms/tomb.c"]));

  add_monster("/u/a/allanon/area/caverns_of_slime/mon/bluefire_bat.c");
}
