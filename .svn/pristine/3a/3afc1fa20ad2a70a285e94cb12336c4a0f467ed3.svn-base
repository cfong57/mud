#include <mudlib.h>

inherit ROOM;

/* This room is purposfully left empty; there are enough "action" rooms in
the area already. All it does is give a hint as to what the key for the storage
room might be, if one is observant. Suppose I could stick in a zombie or 
something if necessary, but... */

void extra_create()
{ 
  set_no_teleport(1); 
  set_short( "Cellaria's dungeon, torture chamber" );
  set_long(wrap("The air here reeks with the scent of decay. Bodies have "+
  "been thrown all over, in various states of decomposition. The room is "+
  "tiled in white, and it would be pretty if not for the copious bloodstains "+
  "all over everything. It is quickly apparent where they come from: all "+
  "over the room are torture devices. Dried rivulets of blood lead from each "+
  "one to the center of the room, where a depression in the floor is "+
  "stained almost black with what must be liters of dried blood. This place "+
  "makes you sick to your stomach and you wish to leave immediately.\n"));
  set_light(-30);
  set_item_desc(([
  "bodies" : "The bodies are of all different races, but most seem to be "+
  "humans, elves, or dwarves. You wonder if they might have been Vaerlon "+
  "citizens, and what they did to deserve such a fate. Some bodies have been "+
  "so disfigured that you aren't even sure what they were in the first place. "+
  "The owner of this chamber of killing must have been cruel indeed.\n", 
  ({ "torture devices", "devices"}) : "All manner of cruel instruments adorn "+
  "the room: iron maidens, piles of thumb screws, fire pits with cold iron "+
  "brands resting in them, and others whose usage you don't even want to "+
  "guess at. You notice that next to each device, there is a small weapons "+
  "rack that looks like it would hold some sort of long, thin weapon.\n",
  ({"rivulets", "blood", "tiles", "grooves"}) : "Although you hate to admire "+
  "such a thing, the construction of this room is superly done: there are "+
  "microscopic grooves in the tiles which direct the flow of blood towards "+
  "the depression in the center.\n",
  "depression" : "A crude pit in the center of the room where the blood must "+
  "have flowed in copious amounts. The smell of death hangs heavy about it, "+
  "and you can't even approach it without waves of nausea hitting you.\n"]));            
  set_exits((["north" : 
  "/u/a/allanon/area/lumber_camp/rooms/dungeon_entrance.c"]));
}

int query_temperature() 
{
  return 12; 
}