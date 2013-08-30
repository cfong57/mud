#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Bastion's audience chamber" );
  set_long(wrap("This is the Audience Chamber, which Ity will be finishing "+
  "at some point.\n"));
  set_exits(([
  "west" : "/u/a/allanon/area/ity/rooms/hallwaynw.c",
  "north" : "/u/a/allanon/area/ity/rooms/throne.c",
  "south" : "/u/i/ity/area/town/room/courtyard_entrance.c", //fix this later
  "east": "/u/a/allanon/area/ity/rooms/hallwayne.c"]));
}