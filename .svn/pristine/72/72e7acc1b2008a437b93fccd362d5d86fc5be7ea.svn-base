#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_short( "The royal bedchambers of the Bastion" );
  set_long(wrap("This is some sort of bedroom, although it really looks "+
  "more like an armory to you. There are a variety of weapons and shields "+
  "hung up on the walls and on display in glass cases. Mannequins display "+
  "a variety of ceremonial armors in militaristic poses. Maps are also not "+
  "in short supply, being tacked on the walls and some just carelessly left "+
  "on the floor. In the center of the room is a large and luxurious "+
  "four-poster bed. A window looks to the outside, so that light shines "+
  "onto the head of the bed.\n"));
  set_item_desc(([
  ({"weapons", "shields", "glass cases", "cases"}) : "Weapons and "+
  "shields are on prominent display here. Many of them look like they were "+
  "not merely ceremonial, but actually used in real combat. Perhaps this is "+
  "a collection of war trophies that the King won from his foes.\n",
  ({"mannequins", "ceremonial armors", "armors"}) : "Unlike the weapons, "+
  "these armors are clearly made to be worn for show, not protection. They "+
  "are made of expensive but impractical materials like gold and silver. "+
  "Dragons are a prominent figure on all of them: engraved, embossed, or "+
  "painted on.\n",
  "walls" : "The walls are covered with maps, weapons, and shields.\n",
  ({"maps", "floor"}) : "There are many maps in this room, some tacked onto "+
  "the walls and others simply underfoot. Looking at a few, you determine "+
  "them to be battle strategies, charts of territories, and other documents "+
  "that would have been of use to the leader of an army.\n",
  ({"four-poster bed", "bed"}) : "The bed is rather luxurious, being made "+
  "of wrought iron and covered in layers of furs and silks. There are some "+
  "curtains around the sides which could be drawn to provide some privacy.\n",
  ({"window", "outside"}) : "The window is made of clear glass, and perfectly "+
  "positioned so the morning rays of the sun hit the head of the bed.\n"]));
  set_sounds(100 + random(100), ({ 
  "You admire the various equipment. It must have taken a lifetime to "+
  "collect.\n"}) );
  add_monster("/u/a/allanon/area/ity/mon/king.c");
  set_exits(([
  "south" : "/u/a/allanon/area/ity/rooms/guardroom.c"]));
  create_door("south", "north",
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