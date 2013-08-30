#include <mudlib.h>
#include <modules.h>

inherit M_UNDERWATER_ROOM;

void extra_create()
{
  set_short( "A room deep underwater" );
  set_outside("~"); 
  set_outdoors("~");
  set_long(wrap("This is a room full of water. Players and monsters without "+
  "underwater breathing ability will drown!\n"));
  set_exits( (["out" : "/u/a/allanon/workroom/connector"]) );
}
