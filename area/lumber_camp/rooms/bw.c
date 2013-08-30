#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short( "Western edge of a battleground" );
  set_long(wrap("You're standing in a dense forest. A few trees have deep "+
  "cuts in them, as if someone was trying to cut them down but was "+
  "interrupted. The ground vegetation is quite scuffed here - it seems like "+
  "many people have moved through the area recently. There are a few "+
  "bloodstains dotting the ground here and there, and they make you feel "+
  "ill-at-ease. What exactly is going on here, you wonder?\n"));
  set_item_desc(([
  ({"trees", "deep cuts", "cuts", "dense forest", "forest"}) : "Seems like "+
  "lumberjacks tried to cut these trees down but had to stop before "+
  "finishing.\n", 
  ({ "ground vegetation", "vegetation", "ground", "small bushes", "bushes", 
  "grass", "flowers", "plants"}) : "Small bushes, grass, flowers and the "+
  "like. Many footprints can be found and a lot of the plants have been "+
  "trampled.\n",
  "footprints" : "The heavy tread of lumberjack boots can be spotted easily "+
  "in the soft soil.\n",
  ({"soft soil", "soil"}) : "The earth here is very soft and lush, suitable "+
  "for any kind of vegetation to thrive.\n",
  ({"bloodstains", "blood"}) : "There is some blood on the ground, but it is "+
  "brown and dry so it must have been spilled some time ago.\n"]));  
  set_sounds(100 + random(26), ({ 
  "You feel like moving somewhere else, the bloodstains aren't exactly "+
  "comforting.\n", 
  "Some sounds of civilization can be heard coming from the north.\n", 
  "You wonder where all the forest aminals have gone.\n" }) ); 
  set_exits(([
  "west" : "/u/a/allanon/area/lumber_camp/rooms/glade.c",
  "east" : "/u/a/allanon/area/lumber_camp/rooms/bc.c"]));
}