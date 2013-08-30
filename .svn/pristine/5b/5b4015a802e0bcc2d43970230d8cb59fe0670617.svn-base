#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Inside a massive tree" );
  set_long(wrap("You are standing inside of a massive tree. The interior "+
  "is even bigger than it looks from the outside. A softly pulsating green "+
  "light seems to emit from the walls of the tree, which are covered in "+
  "ancient arcane symbols. Lush green moss seems to grow everywhere on the "+
  "floor of the tree, providing a living carpet. All said, the tree strikes "+
  "you with a deep sense of the spirit of life and the vitality of nature. An "+
  "incredibly long ladder, made of vines, reaches down from a platform high "+
  "up in the tree.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/treants.c");
  set_light(200);
  set_item_desc(([
  "walls" : "The walls seem to pulse with soft green light, which is easy on "+
  "the eyes and quite bright enough to see. Arcane symbols are painted "+
  "everywhere on the walls, as far as you can see.\n",
  ({"ancient arcane symbols", "ancient symbols", "arcane symbols", "symbols"}) :
  "Symbols have been painted over every square inch of the wall. They are all "+
  "undecipherable to you.\n",
  ({"long ladder", "ladder", "vines"}) : "A vine ladder hangs down "+
  "from a platform, many meters or so above here. You really don't feel like "+
  "climbing all that way up on some fragile vines, but there is no other "+
  "way.\n",
  "platform" : "You can see a platform high overhead. It would appear to be "+
  "the 'second floor' of the tree.\n",
  ({"lush green moss", "lush moss", "green moss", "moss"}) : "Moss carpets "+
  "the wooden floor of the tree. It's quite soft and comfortable.\n"]));  
  set_sounds(106 + random(27), ({ 
  "It is silent, and yet you can still hear a very faint humming sound that "+
  "seems to emate from the tree.\n",
  "You sense that there is even stronger magic father up in the tree.\n"}) ); 
  set_exits(([
  "ladder" : "/u/a/allanon/area/lumber_camp/rooms/platform.c",
  "exit" : "/u/a/allanon/area/lumber_camp/rooms/tree_entrance.c"]));
  set_exit_msg( ([ "exit" : "$N exits the tree." ]) ); 
  set_exit_msg( ([ "ladder" : "$N climbs the ladder upwards." ]) ); 
}