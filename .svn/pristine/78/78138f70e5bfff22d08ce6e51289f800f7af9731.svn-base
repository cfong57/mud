#include <mudlib.h>
#include <daemons.h>

inherit ROOM;
inherit DOOR;

void door_func()
{
  string look_msg = WEATHER_D->query_current_day_phase();
  mapping doors = this_object()->query_doors();
  if(!doors || !sizeof(keys(doors)))
  {
    message("bug","Something has bugged in this room - couldn't find the "+
    "door. Contact a wiz.\n",this_object());  
  }
  if(strsrch(look_msg, "sun")>-1)
  {
	doors["north"]["status"] = "open"; //open during the day
  }
  else
  {
	doors["north"]["status"] = "locked"; //lock during the night
  }
}

void phase_changed(mapping map)
{ 
  door_func();
} 

void extra_create()
{
  set_outside("-"); 
  set_outdoors("-");
  set_short("In front of Wildcat Cafe");
  set_long(wrap("You are standing in front of what used to be Vaerlon's soup "+
  "kitchen for the poor. The old building has been completely demolished, and "+
  "in its place a new and much larger place has been recently erected. You "+
  "must say that it is quite an improvement over the small and grubby shack "+
  "that previously occupied this lot. There is a sign hanging over the doors "+
  "that proudly proclaims in red paint, 'Wildcat Cafe'. Oddly, there are no "+
  "windows on the building whatsoever, so there is no way to see inside.\n"+
  "There is a notice nailed to the wall, next to the doors.\n"));
  set_item_desc(([
  ({"building", "place", "cafe"}) : "The new building is constructed of solid "+
  "oaken planks that must have been quite expensive. The effect is rather "+
  "classy though, especially compared to the surrounding properties of the "+
  "Poor Quarter. You wonder who would pick such a shoddy location for a fine "+
  "building, and why.\n",
  ({"solid oaken planks", "solid planks", "oaken planks", "planks"}) : "The "+
  "planks have all been cut from individual trees - they are simply too large "+
  "to have been from the same one. Whoever built this place has done a superb "+
  "job of insulating it from the elements, as you cannot spot even a single "+
  "crack. The planks look pretty thick, too...the place is probably quite "+
  "soundproof.\n",
  "sign" : "The sign is also made of oak. Written in bold red paint are "+
  "the words, 'Wildcat Cafe'.\n",
  ({"bold red paint", "bold paint", "red paint", "paint"}) : "The paint is "+
  "still relatively fresh. It has the exact same shade of red as blood.\n", 
  "wall" : "There is a notice nailed to the wall, next to the doors.\n",
  ({"notice", "sheet", "large sheet", "large sheet of vellum",
  "sheet of vellum", "vellum"}) : "A large sheet of vellum is nailed to the "+
  "wall with a gleaming steel nail. Neat handwriting forms the message: "+
  "'Wildcat Cafe is open to all for business during the day. Only premium "+
  "members are allowed in during the night. Talk to Slash to purchase a "+
  "membership.\n",
  ({"neat handwriting", "handwriting", "message"}): "The message is written "+
  "with the same blood-red ink as the sign.\n",
  ({"gleaming steel nail", "gleaming nail", "steel nail", "nail"}) : "This "+
  "nail has a rather odd head. It is a loop, rather than a flat circle. "+
  "Actually, now that you look at it more closely, the nail is probably a "+
  "skewer. You wonder why someone would use a cooking implement as "+
  "hardware.\n"]));
  set_sounds(120 + random(35), ({ 
  "The notice flaps a bit in the breeze.\n", 
  "For some reason you feel awfully hungry just standing here.\n",
  "A delicious aroma wafts from the direction of the cafe. It smells like "+
  "meat, but you cannot identify what kind.\n"})); 
  set_exits(([
  "north" : "/u/a/allanon/area/cafe/rooms/foyer.c",
  "south" : "/d/valkor/vaerlon/rooms/streets/k12.c"])); //near rat warehouse
  create_door("north", "south",
  (["short" : "ornate oaken double-doors",
  "long" : "These wooden doors are made of oak and have been polished to a "+
  "shiny finish. There are no visible handles, or even a lock. You get the "+
  "feeling that magic is used to keep these doors open or shut.\n",
  "ids" : ({"door", "doors", "ornate oaken double-doors", "ornate double-doors",
  "ornate door", "ornate doors", "oaken double-doors", "oaken door", 
  "oaken doors"}),
  "status" : "locked",
  "autoclose" : 0,
  "autolock" : 0,
  "quality" : 1001,
  "material" : "wood",
  "close_msg" : "The ornate oaken double-doors snap shut with a BANG.\n",
  "open_msg" : "The ornate oaken double-doors suddenly swing open.\n"]));
  WEATHER_D->add_phase_listener(this_object());
  door_func();
}