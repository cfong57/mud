#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Western hallway of the Bastion" );
  set_long(wrap("This hallway looks to be constructed in a fairly shoddy "+
  "manner. The stones are fit together imperfectly, leaving many small cracks "+
  "that allow the wind to whistle through. The floor here is also unpaved, "+
  "instead being made of hard-packed dirt. Given the relative opulence of the "+
  "rest of the castle, you guess that this must be the hallway by which the "+
  "servants move. It is only natural that architectural perfection was not "+
  "high on the priority list for this room.\n"));
  set_item_desc(([
  ({"stones", "small cracks", "cracks"}) : "The walls here are made "+
  "of stone, but no one has bothered to fit them together very well, or even "+
  "seal the gaps. As a result, there are many small cracks to be seen, and "+
  "the wind passes straight through this hallway, creating a strong draft.\n",
  ({"floor", "hard-packed dirt", "dirt"}) : "Unlike the rest of the castle, "+
  "the floor here is made of hard-packed dirt which has been tamped down over "+
  "the centuries by many feet. You would have expected some plants to grow "+
  "here, but perhaps due to the lack of sunlight, the dirt remains "+
  "barren.\n"]));
  set_sounds(125 + random(20), ({ 
  "The wind blows through the cracks in the walls, chilling you.\n"}) );
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/towernw1.c",
  "west" : "/u/a/allanon/area/ity/rooms/kitchen.c",
  "south" : "/u/a/allanon/area/ity/rooms/towersw1.c"]));
}