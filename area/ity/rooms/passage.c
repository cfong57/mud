#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Servant's passage, underneath the Bastion's courtyard" );
  set_long(wrap("This is a long passageway leading from one side of the "+
  "Bastion to the other. It runs directly underneath the castle's courtyard, "+
  "although you are far enough underground that you are insulated from any "+
  "sounds that might happen up there. Based on the smoothness of the stones "+
  "which make up the floor, many feet have passed through this tunnel over "+
  "time. Most likely, the servants used this passage as a shortcut to move "+
  "quickly - and unseen - between the kitchen and the dining room. There are "+
  "doors at either end of the passage.\n"));
  set_item_desc(([
  ({"stones", "floor"}) : "The floor is comprised of several regularly spaced "+
  "stones. Originally there must have been some roughness and irregularity, "+
  "but the passage of time and many feet has smoothed the stones to an almost "+
  "mirror-like sheen.\n",
  ({"door", "doors"}) : "The door to the west leads to the kitchen, while the "+
  "one to the east leads to the dining room. Both doors move silently by "+
  "some unseen force and do not even need to be touched to open - a most "+
  "useful feature for a busy servant with its hands full.\n"]));
  set_sounds(125 + random(75), ({ 
  "While the floor is lined with stone, the walls and ceiling are just dirt. "+
  "You marvel that neither have caved in.\n"}) );
  set_exits(([
  "west" : "/u/a/allanon/area/ity/rooms/kitchen.c",
  "east" : "/u/a/allanon/area/ity/rooms/dining.c"]));
}