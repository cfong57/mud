#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{ 
  set_no_teleport(1); 
  set_short( "Cellaria's dungeon, entrance to storage" );
  set_long(wrap("In the north part of the dungeon, the air is a bit warmer, "+
  "but that only makes the humidity worse. Here you can see some signs of "+
  "life, as the flawless walls from earlier devolve into merely packed dirt, "+
  "with an occasional tree root poking out. There is an iron cell door to "+
  "the north, and slumped against it is a recently-deceased body. The body's "+
  "hand reaches towards the door's keyhole, as if its last action was to "+
  "try to pick it.\n"));
  set_light(-35); 
  add_monster("/u/a/allanon/area/lumber_camp/mon/bandit.c");
  set_item_desc(([
  ({"walls", "dirt", "tree root", "root"}) : "Since you have gone in a ways, "+
  "you are probably right beneath the forest floor now, so it is only "+
  "natural that it would be harder to make a good tunnel.\n", 
  "body" : "The body seems fresh, as it is still leaking some blood. It has "+
  "not yet started to decompose; you don't feel like staying around to watch "+
  "that happen. Its hand reaches towards the door in a plaintive gesture. "+
  "Perhaps whoever it was tried in vain to open the door and flee from "+
  "assailants by locking themself inside. You notice with some curiosity that "+
  "the body seems to be somewhat frozen. But it certainly isn't that cold "+
  "here...right?\n",
  "keyhole" : "Upon closer examination, you find that the door's keyhole is "+
  "very strange. The tumbler is long and thin - you have never before seen "+
  "a key of such a shape.\n"]));            
  set_exits((["north" : 
  "/u/a/allanon/area/lumber_camp/rooms/dungeon_storage.c",
  "south" : "/u/a/allanon/area/lumber_camp/rooms/dungeon_entrance.c"]));
  create_door("north", "south",
  (["short" : "iron cell door",
  "long" : "The cell door is made of solid iron. It is perfectly fitted to "+
  "the dirt walls. Peering through the bars, you estimate it to be at "+
  "least 30 centimeters thick - no one is going to be breaking it down.\n",
  "key" : "/u/a/allanon/area/lumber_camp/obj/stiletto.c",
  "status" : "locked",
  "ids" : ({ "door", "iron door", "iron cell door", "cell door" }),
  "autoclose" : 5,
  "autolock" : 1,
  "quality" : 1001,
  "material" : "iron",
  "close_msg" : "The iron cell door swings shut.\n",
  "open_msg" : "You open the iron cell door.\n"  ]) ); 
}

int query_temperature() 
{ 
  return 12;
}