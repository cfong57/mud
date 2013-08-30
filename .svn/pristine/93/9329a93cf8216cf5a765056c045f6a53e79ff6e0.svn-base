#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "On a wooden platform" );
  set_long(wrap("This is the 'second story' of the tree. You get dizzy just "+
  "looking down from here. The soft, carpet-like moss grows here as "+
  "well, and you wonder if maybe it didn't grow just by accident. The walls "+
  "at this height emit a slightly brighter light than before, but it is still "+
  "unpainful. There are some pools of water here and there in small "+
  "depressions; water lilies float atop the pools. It's a very strange sight"+
  "...You feel that the magic here is even more powerful than when you first "+
  "entered the tree. It seems that the source of all the magic lies at the "+
  "tree's top. The ladder stops here, and a long stairway carved right out "+
  "of the tree spirals to the top.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/birch_guard.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/treants.c");
  set_light(205);
  set_item_desc(([
  "walls" : "The walls seem to pulse with soft green light, which is easy on "+
  "the eyes and quite bright enough to see. Arcane symbols are painted "+
  "everywhere on the walls, as far as you can see.\n",
  ({"arcane symbols", "symbols"}) :
  "Symbols have been painted over every square inch of the wall. They are all "+
  "undecipherable to you.\n",
  ({"wooden staircase", "staircase"}) : "A staircase carved out of the tree's "+
  "walls starts at the platform and spirals around the inside, eventually "+
  "leading to the top of the tree.\n",
  "ladder" : "The ladder made of vines stops here. You realize, upon looking "+
  "back, just how far up you have climbed.\n",
  ({"pools of water", "pools", "water", "depressions", "water lilies",
  "lilies"}) : 
  "Small depressions in the floor of the platform have been filled with water."+
  " Water lilies grow freely in the pools. It's a very peculiar sight.\n",
  ({"carpet-like moss", "moss"}) : "Moss carpets the wooden floor of the "+
  "tree. It's quite soft and comfortable.\n"]));  
  set_sounds(134 + random(13), ({ 
  "The humming noise is a bit louder now, it's definitely coming from above.\n",
  "You sense that there is even stronger magic farther up in the tree.\n"}) ); 
  set_exits(([
  "stairway" : "/u/a/allanon/area/lumber_camp/rooms/treetop.c",
  "ladder" : "/u/a/allanon/area/lumber_camp/rooms/in_tree.c"]));
  set_exit_msg( ([ "stairway" : "$N goes up the stairway." ]) ); 
  set_exit_msg( ([ "ladder" : "$N climbs the ladder downwards." ]) ); 
}