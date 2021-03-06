#include <mudlib.h>
#include <void.h>  
#include <move.h>
#include <daemons.h> 

inherit ROOM;

int touch_command(string str)
{
  if(str == "evanescence")
  {
    object room;
    message("info","You touch the strand of evanescence and it sucks you "+
    "in completely!\n",this_player());
    message("info",""+this_player()->query_cap_name()+" touches the strand "+
    "of evanescence and it sucks "+objective(this_player())+" in "+
    "completely!\n",this_object(),this_player());
    room = VOID_D->get_free_room();
    this_player()->move(room,1);
    return 1; 	  
  }
  return notify_fail("Touch what?\n");
}

void extra_init()
{
  add_action("touch_command","touch");	
}

void extra_create()
{
  set_explorable(1);
  set_short( "A strange fluctuating space" );
  set_long(wrap("You find yourself floating in a strange fluctuating space. "+
  "There is no floor, yet somehow you can will yourself in any direction "+
  "that you like. Up above you, you can see an image of the Nobles Room, and "+
  "below is the guest room. While the colors keep shifting rapidly all around "+
  "you, there is one strand of evanescence reaching out into the infinite "+
  "distance which remains pefectly colorless. You get the odd feeling that "+
  "touching it would bring you far, far away from here.\n"));
  set_exits(([
  "up": "/u/a/allanon/area/ity/rooms/noblesroom.c",
  "down" : "/u/a/allanon/area/ity/rooms/guestroom.c"]));
}