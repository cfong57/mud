#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_outside("p"); 
  set_outdoors("p");
  set_short( "Western edge of the lumber camp" );
  set_long(wrap("You are at the western edge of the lumber camp. This section "+
  "seems to be a bit cleaner, there is less clutter and the logs have been "+
  "stacked neatly. A smallish tent lies a bit to the west, and judging from "+
  "the quality of the material it is fairly expensive. You would guess that "+
  "this is the residence of the camp's overseer; it's unlikely that he (or "+
  "she) would sleep amongst the goblins. Goblins around this area continue "+
  "to cut down trees at the edges of the camp, adding to the growing lumber "+
  "piles.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblin_sentinel.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  set_item_desc(([
  ({"logs", "lumber piles", "lumber"}) : "Large stacks of timber can be "+
  "seen everywhere in the camp. The logs have been cut with remarkable skill "+
  "and precision, considering who the lumberjacks are. Someone is going to "+
  "make a fortune from these.\n", 
  ({ "smallish tent", "tent" }) : "Made out of nice, but plain, white canvas, "+
  "the tent sticks out like a sore thumb among the shanty town-like status of "+
  "the camp. It's nothing an adventurer couldn't afford with relative ease, "+
  "but compared to the primitive sleeping places made by the goblins it must "+
  "be excellent.\n"]));  
  set_sounds(121 + random(12), ({ 
  "The constant *thunkthunk* of axes into trees is starting to give you a "+
  "headache.\n"}) ); 
  set_exits((["east"  : "/u/a/allanon/area/lumber_camp/rooms/g2.c",
  "tent" : "/u/a/allanon/area/lumber_camp/rooms/tent.c"]));
}