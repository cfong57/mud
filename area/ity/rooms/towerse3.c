#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Southeastern tower in the Bastion, top floor" );
  set_long(wrap("Temporary room to make floor 2 work properly.\n"));
  set_exits(([
  "down" : "/u/a/allanon/area/ity/rooms/towerse2.c"]));
}