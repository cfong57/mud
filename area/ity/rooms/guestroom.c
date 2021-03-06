#include <mudlib.h>

inherit ROOM;
inherit DOOR;

#define HALLWAY "/u/a/allanon/area/ity/rooms/hallwaynw.c"

int websearched = 0;

string peepfunc()
{
  message("info","You take a look through the peephole at the hallway "+
  "outside...\n",this_player());
  message("info",""+this_player()->query_cap_name()+" takes a look through "+
  "the peephole at the hallway outside.\n",this_object(),this_player());
  return HALLWAY->query_look();
}

void extra_create()
{
  set_short( "Guest room of the Bastion" );
  set_long(wrap("This is the castle's guest bedroom. It could hold a fair "+
  "number of people comfortably. Sleeping pallets are scattered about, and "+
  "each one is adjoined by a small chest for keeping one's belongings. The "+
  "room is a bit dusty, and there is a large spiderweb in one corner. A few "+
  "windows to the south and east look out onto the courtyard. The only other "+
  "object of interest here is a large painting hung on the west wall."));
  set_item_desc(([
  ({"sleeping pallets", "pallets"}) : "The pallets are rectangular pieces of "+
  "wood with a few wool blankets on top of them.\n",
  ({"wool blankets", "blankets"}) : "The blankets are scratchy and not too "+
  "comfortable, but they would keep one warm.\n",
  ({"chest", "small chest"}) : "Next to each pallet is a small wooden chest "+
  "with a lock on it. The guests would store their belongings here.\n",
  ({"peephole", "small peephole"}) : (: peepfunc :),
  ({"windows", "courtyard"}) : "These windows are fitted with glass windows, "+
  "although they are not particularly clean so the view of the courtyard is "+
  "not too great.\n",
  ({"large painting", "painting", "west wall", "wall"}) : "This painting "+
  "shows an adventurous scene of some brave knights fighting a mighty dragon "+
  "in its lair. The realism is quite striking; it is almost as if you could "+
  "reach right into the painting and touch everything.\n"]));
  add_item( ({ "spiderweb", "large spiderweb", "web", "corner" }), 
  "A spiderweb stretches over one corner of the room. There might be "+
  "something behind it, or maybe not. You won't know unless you search it.\n");             
  add_item_search( ({ "spiderweb", "large spiderweb", "web", "corner" }), 
  "search_web");
  set_sounds(125 + random(75), ({ 
  "For a guest room, this place is pretty comfortable. You have slept in "+
  "worse places.\n"}) );
  set_hidden_exits( ({ "painting" }) ); 
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/hallwaynw.c",
  "painting" : "/u/a/allanon/area/ity/rooms/void.c"]));
  set_exit_msg( ([ "painting" : 
  "$N seems to walk right through the west wall." ]));
  create_door("north", "south",
  (["short" : "wooden door",
  "long" : "This wooden door is made of oak. There is a small peephole that "+
  "lets you look to the room outside.\n",
  "ids" : ({ "wooden door", "door" }),
  "status" : "closed",
  "autoclose" : 15,
  "material" : "wood",
  "close_msg" : "The wooden door swings shut.\n",
  "open_msg" : "You open the wooden door.\n"]) );
}

void search_web()
{
  object spider;
  if (!websearched) 
  {
    websearched = 1;
    message("info", "You curiously pick at the spiderweb, trying to break "+
    "through to the other side. Something from within the web emits a "+
    "high-pitched shriek, and suddenly a huge spider lunges out at you!\n",
    this_player());
    message("info", ""+this_player()->query_cap_name()+" curiously picks at "+
    "the spiderweb, trying to break through to the other side. Something from "+
    "within the web emits a high-pitched shriek, and suddenly a huge spider "+
    "lunges out at you!\n", environment(this_player()), this_player());
    spider = new("/u/a/allanon/area/ity/mon/spider.c");
    spider->move(environment(this_player())); 
    spider->kill_ob(this_player());
  }
  else
  {
    message("info", "You search the spiderweb, but only manage in getting "+
    "many sticky threads stuck to yourself. There is nothing hidden in the "+
    "corner.\n", this_player());     
    message("info", this_player()->query_cap_name()+" searches the spiderweb, "+
    "but only manages to get covered in sticky threads.\n", 
    environment(this_player()), this_player());
  }
}