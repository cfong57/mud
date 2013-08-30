#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Southeastern tower in the Bastion, first floor" );
  set_long(wrap("You have come to the first floor of a rectangular tower. "+
  "There is a stairway made of stone that spirals up out of sight, and exits "+
  "to the west and north that lead to hallways. A small window has been bored "+
  "into the stone wall on the south side, giving a view outside. Some moss has "+
  "grown along the windowsill, providing a convenient armrest. Little else of "+
  "note is to be seen; a few potted plants once made this place a little "+
  "cheerier, but they have long since died from neglect.\n"));
  set_item_desc(([
  "stairway" : "The stairway is made of carefully laid stones. It spirals "+
  "around itself, so you cannot see what is above from this angle.\n",
  ({"west", "north", "hallways", "hallway"}) : "To the west and north are "+
  "hallways that stretch off into the distance.\n",
  ({"small window", "window", "stone wall", "wall", "tower wall"}) : "On the "+
  "south side of the tower wall, a window has been bored into the rock after "+
  "the stonework was originally laid. Perhaps it is mostly meant to "+
  "improve the castle's airflow; it can get stuffy in places like this.\n",
  ({"rock", "stonework", "stones", "stone", "stone block", "block"}): "It "+
  "must have taken an expert mason to fit stones together this perfectly, "+
  "with almost no imperfections to be seen. Each stone block is about one "+
  "meter by one meter, and about half again as thick, you estimate.\n",
  ({"moss", "windowsill", "armrest"}) : "Some fuzzy green moss has grown "+
  "along the windowsill. Whether it was intended to be there or not, you "+
  "have no idea, but it does make leaning in the window fairly "+
  "comfortable.\n",
  ({"potted plants", "pots", "pot", "plants", "plant", "potted plant"}) : 
  "There are a few clay pots filled with soil sitting near the window. A few "+
  "limp brown stalks and withered husks indicate that there were once plants "+
  "growing in them, but they have died a long time ago.\n",
  ({"soil", "limp brown stalks", "brown stalks", "limp stalks", "stalks",
  "withered husks", "husks", "remains"}) : "The soil in each pot is littered "+
  "with the sad remains of domestic plants.\n"]));
  set_sounds(200 + random(10), ({ 
  "A cool wind blows in from the window, rustling the long-dead leaves of "+
  "the potted plants.\n"}) ); 
  set_exits(([
  "west" : "/u/a/allanon/area/ity/rooms/hallwayse.c",
  "north" : "/u/a/allanon/area/ity/rooms/hallwaye.c",
  "up" : "/u/a/allanon/area/ity/rooms/towerse2.c"]));
}