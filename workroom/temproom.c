#include <mudlib.h>

inherit ROOM;

int temp = 0;

void extra_create()
{
  set_short( "Room with extreme temperature" );
  set_long("This room can be modified to become really hot or really cold.\n");
  set_exits((["out"  : "/u/a/allanon/workroom/connector"]) );
}

int query_temperature() { return temp; }

void set_temperature(int i)
{
  temp = i;
}