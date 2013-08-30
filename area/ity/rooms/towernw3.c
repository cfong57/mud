#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Northwestern tower of the Bastion, top floor" );
  set_long(wrap("Another temporary room.\n"));
  set_exits(([
  "ladder": "/u/a/allanon/area/ity/rooms/towernw2.c"]));
}