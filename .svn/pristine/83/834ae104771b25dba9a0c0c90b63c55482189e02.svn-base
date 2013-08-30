#include <mudlib.h>
#include <daemons.h>

inherit ROOM;
inherit DOOR;

string longdesc;

void phase_func()
{
  string look_msg=WEATHER_D->query_current_day_phase();
  if(strsrch(look_msg,"sun")>-1)
  {
    set_long(wrap(longdesc + "It is day, and the sun shines through the "+
    "window.\n"));
  }
  else
  {
    set_long(wrap(longdesc + "It is night, and the moons shine through the "+
    "window.\n"));	  
  }
}

void phase_changed(mapping map)
{ 
  phase_func();
} 

string outsidefunc()
{
  string look_msg=WEATHER_D->query_current_day_phase();
  if(strsrch(look_msg,"sun")>-1)
  {
    return "It is daytime outside. The sun shines through and warms you a "+
    "bit.\n";
  }
  else
  {
    return "It is nighttime outside. A cool breeze flows through, making you "+
    "shiver a bit.\n"; 
  } 	
}

void extra_create()
{
  set_short( "Northwestern hallway of the Bastion" );
  set_long(wrap("This hallway is rather plain. There are no decorations to "+
  "adorn the stone walls, the floor is bare, and nothing hangs from the "+
  "ceiling. The room is very clean, however; you can't find any dust at all. "+
  "To the east is a spacious room that looks like the audience chamber. "+
  "At the northern wall is a window looking outside, fitted with an iron "+
  "grill. "));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/ity/mon/servant.c");
  set_item_desc(([
  ({"stone walls", "walls", "floor", "ceiling"}) : "The whole room is just "+
  "barren stone. There are not even any interesting stains to break the "+
  "monotony.\n",
  ({"iron grill", "grill"}) : "This grill has rusted only a little bit. "+
  "Signs of filing show that someone has been attempting to keep it in "+
  "working order.\n",
  ({"east", "audience chamber"}) : "A spacious room to the east filled with "+
  "pews looks like an audience chamber.\n",
  ({"window", "outside"}) : (: outsidefunc :)]));
  set_sounds(165 + random(35), ({ 
  "You wish all the places you explored could be as clean as this room.\n"}) );
  set_exits(([
  "west" : "/u/a/allanon/area/ity/rooms/towernw1.c",
  "east" : "/u/a/allanon/area/ity/rooms/audience.c",
  "south" : "/u/a/allanon/area/ity/rooms/guestroom.c"]));
  create_door("south", "north",
  (["short" : "wooden door with a plaque on it",
  "long" : "This wooden door is made of oak, and it has a plaque on it that "+
  "reads 'Guest Room'. This is probably where the lesser visitors got to "+
  "stay.\n",
  "ids" : ({ "wooden door", "wooden door with a plaque on it", "plaque",
  "door" }),
  "status" : "closed",
  "autoclose" : 15,
  "material" : "wood",
  "close_msg" : "The wooden door swings shut.\n",
  "open_msg" : "You open the wooden door.\n"]) );
  WEATHER_D->add_phase_listener(this_object());
  phase_func();
}