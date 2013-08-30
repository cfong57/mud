#include <mudlib.h>

inherit ROOM;
inherit DOOR;

#define HALLWAY "/u/a/allanon/area/ity/rooms/hallwayne.c"

int clean_up(int inh) { return 1; }
void reset() { return; }

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
  seteuid( getuid() );
  set_short( "Nobles room of the Bastion" );
  set_long(wrap("This is the castle's room where nobles and other important "+
  "people would stay. It is richly decorated - every possible surface has "+
  "been painted, covered in silk, laminated with gold, or otherwise "+
  "made attractive. You notice that the room seems to have an aversion to "+
  "right angles, as everything is smooth and rounded, including the "+
  "four-poster beds for sleeping. Even the typical dressers or lockers next "+
  "to each bed have been replaced with spherical chests that open like clam "+
  "shells. Some windows to the south and west look out onto the courtyard. "+
  "There is a large painting hung on the east wall.\n"));
  add_monster("/u/a/allanon/area/ity/mon/githrin.c");
  set_item_desc(([
  ({"four-poster beds", "beds"}) : "The beds are made of oak, and each one is "+
  "furnished with silky sheets and fluffy pillows.\n",
  ({"sheets", "pillows"}) : "You get sleepy just looking at these comfortable "+
  "furnishings. When was the last time you slept in a real bed?\n",
  "chests" : "The chests are vaguely shaped like clam shells, with hinges "+
  "at the middle. They are all locked.\n",
  ({"peephole", "small peephole"}) : (: peepfunc :),
  ({"windows", "courtyard"}) : "These windows are fitted with glass windows, "+
  "and they have been polished to a mirror-like shine so the view is "+
  "great.\n",
  ({"large painting", "painting", "east wall", "wall"}) : "This painting "+
  "shows an adventurous scene of some brave knights fighting a mighty dragon "+
  "in its lair. The realism is quite striking; it is almost as if you could "+
  "reach right into the painting and touch everything.\n"]));
  set_sounds(125 + random(75), ({ 
  "It sure must be nice being someone of importance, if your accomodations "+
  "get to be like this.\n"}) );
  set_hidden_exits( ({ "painting" }) );
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/hallwayne.c",
  "painting" : "/u/a/allanon/area/ity/rooms/void.c"]));
  set_exit_msg( ([ "painting" : 
  "$N seems to walk right through the east wall." ]));
  create_door("north", "south",
  (["short" : "ornate bronze door",
  "long" : "This bronze door has been embellished with the figures of dragons "+
  "embossed onto its surface. A small peephole lets you look to the room "+
  "outside.\n",
  "ids" : ({ "ornate bronze door", "bronze door", "ornate door", "door" }),
  "key" : "/u/a/allanon/area/ity/obj/noblekey.c",
  "status" : "locked",
  "autolock" : 1,
  "autoclose" : 15,
  "material" : "bronze",
  "quality" : 1001,
  "close_msg" : "The bronze door swings shut.\n",
  "open_msg" : "You open the bronze door.\n"]) );
  ::reset();
}

int knock_open_door() 
{  
   object githrin;
   githrin = present("githrin_ob", this_object());
   if(githrin)
   {
      githrin->force_me("unlock door with key");
      githrin->force_me("open door");
   }
}

int special_knock_function(object ob) 
{
  knock_open_door();
  return 1;
}