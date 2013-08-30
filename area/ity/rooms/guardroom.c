#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_short( "Royal Guard's barracks in the Bastion" );
  set_long(wrap("You have come to a heavily fortified barracks. The way "+
  "north leads to a strongly reinforced door, and is obstructed by a number "+
  "of defensive mechanisms such as crossbow traps pointed at the south "+
  "entrance. There are some wooden beds along the walls; each of them has "+
  "a sword scabbard bolted right to the bed, providing easy access to "+
  "whatever weapons might once have been stored there. There is evidence that "+
  "this room has seem some fierce combat in ages past; ancient bloodstains "+
  "have never been cleaned off the stones, and there are numerous dents and "+
  "scratches along the floor and walls that look to have been made by "+
  "weaponry of various sorts.\n"));
  add_monster("/u/a/allanon/area/ity/mon/baresias.c");
  set_item_desc(([
  ({"defensive mechanisms", "crossbow traps", "traps"}) : "There are a "+
  "variety of devices in this room meant to hinder or stop progress to "+
  "the north. Some of them are crossbow traps, although the quarrels have "+
  "long since rotted away. Others are odd, tubular canisters with dragon's "+
  "heads on the ends. These have soot on the inside, but you are not sure "+
  "what they were used for. In any case, they have rusted badly and are "+
  "no longer functional.\n",
  ({"wooden beds", "beds"}) : "These beds are simple pallets of wood. They "+
  "have been varnished so as to prolong the life of the material.\n",
  ({"sword scabbard", "scabbard"}) : "These scabbards once held blades in "+
  "them, but they are all empty now. A sleeping guard could quickly and "+
  "easily wake up and draw steel in one smooth motion.\n",
  ({"ancient bloodstains", "bloodstains", "stones"}) : "There are some rusty "+
  "red blotches along the floor and walls.\n",
  ({"dents", "scratches"}) : "Some of the gouges are quite deep, and must "+
  "have been made with quite some force. Someone or something in the past "+
  "tried very hard to break through this room.\n"]));
  set_sounds(155 + random(65), ({ 
  "You wonder what lies to the north that needs such a heavy guard.\n"}) );
  set_exits(([
  "south" : "/u/a/allanon/area/ity/rooms/throne.c",
  "north" : "/u/a/allanon/area/ity/rooms/kingroom.c"]));
  create_door("north", "south",
  (["short" : "strongly reinforced iron door",
  "long" : "This door must be at least 30 centimeters of solid iron. The "+
  "lock is an odd one; it looks like a pinhole. What sort of key would "+
  "fit in that?\n",
  "ids" : ({ "strongly reinforced iron door", "strongly reinforced door",
  "reinforced door", "iron door", "door" }),
  "status" : "locked",
  "key" : "/u/a/allanon/area/ity/obj/kingkey.c",
  "autoclose" : 15,
  "autolock" : 1,
  "quality" : 1001,
  "material" : "iron",
  "close_msg" : "The iron door swings shut.\n",
  "open_msg" : "You open the iron door.\n"]) );
}