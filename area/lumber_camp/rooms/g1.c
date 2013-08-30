#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_outside("p"); 
  set_outdoors("p");
  set_short( "Edge of the forest" );
  set_long(wrap("The battleground seems to stop abruptly as you stand at "+
  "the edge of the forest. Perhaps someone has cleaned it up. The forest "+
  "doesn't seem to end naturally here, rather it seems that someone has "+
  "made an enormous clearing in the forest. It's completely clear-cut, with "+
  "only a pitiful carpet of grass left to grow. A large camp has been set up "+
  "in the clearing, in rather helter-skelter style. Crude campsites are "+
  "scattered randomly around in no particular order. You can spot a single "+
  "tent and a hastily erected wooden building or two as well.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  set_item_desc(([
  ({ "forest", "vegetation"}) : "The vegetation ends abruptly here, which is "+
  "a strange sight to behold. It must have taken a lot of work to clear away "+
  "all of the plants, since a forest this old is quite dense.\n",
  ({"carpet of grass", "grass"}) : "Even the grass seems like it has been "+
  "attacked, there are many burn marks scorching the ground here and there.\n",
  ({"burn marks", "marks"}) : "The burn marks on the ground seem unnatural, "+
  "as if they were made by magic and not by ordinary fire.\n", 
  ({ "large camp", "camp", "crude campsites", "campsites", "tent", 
  "wooden building"}) : "It's a poorly made but functional camp. Estimating "+
  "from the size of it, a lot of people - or somethings - must live here.\n"]));  
  set_sounds(140 + random(5), ({ 
  "The din of the camp can easily be heard from this close.\n", 
  "You ponder whether it would be a good idea to enter the camp or not.\n"}) ); 
  set_exits(([
  "south" : "/u/a/allanon/area/lumber_camp/rooms/bc.c",
  "north" : "/u/a/allanon/area/lumber_camp/rooms/g2.c"]));
}