#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Northeastern tower in the Bastion, top floor" );
  set_long(wrap("Temporary room to make floor 2 work properly.\n"));
  set_exits(([
  "portal" : "/u/a/allanon/area/ity/rooms/towerne2.c"]));
}