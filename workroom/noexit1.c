#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Room with no escape" );
  set_outside("f"); 
  set_outdoors("f");
  set_long("You can run, but you can't hide...\n");
  set_exits((["north"  : "/u/a/allanon/workroom/noexit2.c"]) );
}