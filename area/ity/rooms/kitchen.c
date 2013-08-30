#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Bastion's once-bustling kitchen" );
  set_long(wrap("You have come to a rather large room with high ceilings. "+
  "Far overhead you can see some grates which have been set into the roof, "+
  "leading to the outside. The room is filled with fire pits, roasting spits, "+
  "pots and pans, knives, and all sorts of other cooking implements; this "+
  "must be the kitchen of the castle. Even though the inhabitants of the "+
  "castle are long since deceased, you still smell something wonderful "+
  "cooking somewhere - perhaps some ghostly memory that refuses to go away. "+
  "In the middle of the room there is a large hole with a ladder leading "+
  "down into it.\n"));
  add_monster("/u/a/allanon/area/ity/mon/cook.c");
  add_monster("/u/a/allanon/area/ity/mon/server.c");
  set_item_desc(([
  ({"ceilings", "grates", "roof"}) : "The ceilings are several meters "+
  "above your head, and some iron grates have been fitted over some holes "+
  "which lead outside. These are probably to let out smoke and other "+
  "unpleasant odors produced during cooking.\n",
  ({"fire pits", "pits", "roasting spits", "spits", "pots",
  "pans", "knives", "cooking implements", "implements"}) : "There are a "+
  "great variety of cooking tools, some of which you aren't even sure what "+
  "they might be used for. Then again, compared to the typical adventurer, "+
  "cooking for an entire castle is probably a lot different than roasting "+
  "some meat you just carved from a dead animal.\n",
  ({"large hole", "hole", "ladder"}) : "There is a large hole in the middle "+
  "of the room. It is circular in shape, and all around the edges you can see "+
  "various stains and discolorations. Perhaps this was the garbage dump, "+
  "where kitchen refuse was thrown away. A ladder leads down into the hole, "+
  "presumably to help out any unfortunate person that might have fallen in "+
  "accidentally.\n",
  ({"slight shadow", "shadow", "walls"}) : "Upon closer inspection, you "+
  "find that there is actually a well-disguised door made of stone which is "+
  "set almost perfectly flush with the wall. As you approach, it magically "+
  "slides open on its own, revealing a passage beyond.\n"]));
  set_sounds(200 + random(50), ({ 
  "There seems to be a slight shadow along one of the walls, with nothing "+
  "that could be casting it.\n"}) );
  set_hidden_exits( ({ "passage" }) ); 
  set_exits(([
  "passage" : "/u/a/allanon/area/ity/rooms/passage.c",
  "east" : "/u/a/allanon/area/ity/rooms/hallwayw.c",
  "west" : "/u/a/allanon/area/ity/rooms/servantquarters.c",
  "south" : "/u/a/allanon/area/ity/rooms/storage.c"]));
  set_exit_msg( ([ "passage" : 
  "$N seems to walk right through one of the walls." ]));
}