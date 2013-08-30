#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Northeastern tower of the Bastion, first floor" );
  set_long(wrap("This is a richly decorated tower. The walls have been draped "+
  "with colorful silks, and the floor is covered in a red velvet carpet. "+
  "There is a stairway leading up, with a handrail made of crystal. A few "+
  "chairs are seated at the corners of the room, and each has a plump downy "+
  "pillow on it. You are not sure what this tower is used for, but the first "+
  "floor certainly seems like a waiting room of some sort.\n"));
  add_monster("/u/a/allanon/area/ity/mon/servant.c");
  set_item_desc(([
  ({"walls", "colorful silks", "silks"}) : "Pretty silks are draped over the "+
  "walls to hide the barren stones. They represent a wide variety of colors, "+
  "ranging from wild magentas to subtle greens. Somehow, the color scheme is "+
  "just right, and nothing clashes.\n",
  ({"floor", "red velvet carpet", "red carpet", "velvet carpet", "carpet"}) : 
  "A red velvet carpet covers the floor. It is immaculate, having not even "+
  "the slightest hint of a footprint anywhere.\n",
  ({"stairway", "handrail"}) : "The stairway is tastefully accentuated with "+
  "more carpet, and the handrail is made of clear crystal.\n",
  ({"chairs", "corners", "pillow"}) : "There are a few chairs set about in "+
  "each corner of the room. A very inviting-looking pillow sits atop each "+
  "chair, just begging to be sat on.\n"]));
  set_sounds(100 + random(100), ({ 
  "Whoever decorated this room really had an eye for beauty.\n"}) ); 
  set_exits(([
  "west" : "/u/a/allanon/area/ity/rooms/hallwayne.c",
  "south" : "/u/a/allanon/area/ity/rooms/hallwaye.c",
  "up" : "/u/a/allanon/area/ity/rooms/towerne2.c"]));
}