#include <mudlib.h>

inherit ROOM;

void extra_create()
{ 
  set_no_teleport(1); 
  set_short( "Cellaria's dungeon, icy room" );
  set_long(wrap("The first thing you notice about this room is the "+
  "temperature - it's cold! The ceiling of this room is just dirt, and "+
  "ice crystals are apparent where water has seeped through. The rest of the "+
  "room is shrouded in a dense fog, and you have trouble seeing anything, "+
  "except for one thing in the middle of the room: a casket. The fog (and "+
  "the chill) seem to be billowing out of it. You get a sense of dread from "+
  "looking at the casket, and feel like it might have been a bad idea to come "+
  "here.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/torturer.c");
  set_light(-50);
  set_item_desc(([
  ({"ceiling", "crystals", "ice", "ice crystals"}) : "Where the walls were "+
  "once bedrock, they are now merely dirt, and this allows moisture to "+
  "trickle down from the forest above. It has frozen immediately upon "+
  "entering the room: the temperature is clearly below freezing.\n", 
  ({ "fog", "casket"}) : "In the midst of the thick fog, a casket lies "+
  "open. There might have been a lid once, containing the cold, but it is "+
  "gone now.\n"]));            
  set_exits((["west" : 
  "/u/a/allanon/area/lumber_camp/rooms/dungeon_entrance.c"]));
}

int query_temperature() 
{ 
  return -10; 
}