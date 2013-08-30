#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Above the clouds, in a tree" );
  set_long(wrap("You are above the cloud layer, standing in the branches of "+
  "an impossibly tall oak tree. Staring down, you can't see the bottom of "+
  "the tree, and staring up you can't see the top either. It is frigid cold "+
  "up here, and the thin air makes it harder to breathe. Frost forms "+
  "whenever you breathe, and your perspiration forms hailstones. Above you, "+
  "there is a dark barrier of clouds, ominously flashing lightning and "+
  "letting off rumbling thunder. If you keep climbing you will pass straight "+
  "through them. You wonder what is at the top of this tree...\n"));
  set_item_desc(([({ "barrier", "dark barrier", "clouds", 
  "dark barrier of clouds", "barrier of clouds", "lightning" }) : "The "+
  "clouds above you are very dark in colour, indicating heavy moisture "+
  "content. You can feel the electric tension even from here. The lightning "+
  "seems to be contained in the clouds, you shouldn't get struck here.\n"]));  
  set_exits(([
  "up" : "/u/a/allanon/workroom/judgment_spire",
  "down" : "/u/a/allanon/workroom/allanon_workroom"]));
  set_exit_msg((["up": "$N climbs up higher, through the dark clouds.",
  "down": "$N climbs down."]));
}

int query_temperature() { return -100; }