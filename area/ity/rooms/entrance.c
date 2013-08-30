#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_short( "Bastion's grand entranceway" );
  set_long(wrap("You have come to the once-grand entranceway of the Bastion. "+
  "There are heaps of cloth scraps near the walls which were probably once "+
  "grand tapestries. The floor is tiled in richly hued granite, but "+
  "it is covered in a layer of dust. There are some pedestals of white marble "+
  "that form a ceremonial flanking column heading towards the north, where "+
  "a courtyard lies. While the pedestals are still intact, the statues that "+
  "once stood on them are little more than heaps of broken metal.\n"));
  set_item_desc(([
  ({"dust", "footprints", "tiny footprints", "cracks", "ceiling", "tracks",
  "animal tracks"}) : "There are some cracks in the ceiling, which let in "+
  "moisture and other things from the sky above. Dust drifts throughout the "+
  "room, and a thin layer of it coats the floor. There are some splotches "+
  "where water has dripped down and washed away the dust, but you can still "+
  "see little animal tracks here and there.\n",
  ({"heaps", "cloth", "cloth scraps", "scraps"}) : "Some piles of decaying "+
  "cloth sit near the walls, probably the remnants of tapestries. It is quite "+
  "a shame, too, since a few of them look to be made of expensive materials "+
  "such as silk.\n",
  ({"floor", "granite", "tile", "tiles"}) : "The floor is tiled with square "+
  "blocks of granite, which have been masterfully cut and polished to a high "+
  "sheen. You can see many beautiful colors in the rock's texture, such as "+
  "rosy reds and jet-black voids set on a field of alabaster.\n",
  ({"pedestals", "pedestal", "marble", "column", "columns"}) : "Simple but "+
  "elegant pedestals carved from pure white marble form two columns down the "+
  "middle of the room, visually directing the eye towards the courtyard in "+
  "the north.\n",
  ({"statues", "statue", "heap", "heaps", "broken metal", "metal"}) : "There "+
  "are some piles of scrap at the feet of each of the pedestals. The statues "+
  "that once stood here must have fallen down, broken, and then deteriorated "+
  "over the years.\n",
  ({"courtyard", "north"}) : "To the north is an open courtyard. Some snow "+
  "and bits of detritus drift in, since there is no door to bar the way, but "+
  "somehow the entranceway has stayed relatively clean.\n",
  ({"snow", "bits", "detritus", "bits of detritus"}) : "Due to the lack of "+
  "a door leading to the courtyard, the elements have been able to enter this "+
  "room. At the same time, you would have expected more damage to come from "+
  "such an open area. Perhaps magic was involved in preserving the artwork "+
  "here...although it has long since failed.\n"]));
  set_sounds(100 + random(20), ({ 
  "Dust filters down from the ceiling, which has a few cracks in it.\n", 
  "There are many tiny footprints in the dust, showing that rats and other "+
  "critters have made this place their home.\n"}) ); 
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/courtyard.c",
  "west" : "/u/a/allanon/area/ity/rooms/hallwaysw.c",
  "east" : "/u/a/allanon/area/ity/rooms/hallwayse.c",
  "south" : "/u/a/allanon/area/ity/rooms/entrydoors.c"]));

  create_door("south", "north",
  (["short" : "huge set of rusted iron doors",
  "long" : "Two massive iron doors which have rusted badly over time. There "+
  "might have been some sort of lock at one time, but the doors open easily "+
  "at your touch, despite being so heavy. The hinges must still be "+
  "well-greased.\n",
  "status" : "unlocked",
  "autoclose" : 45,
  "quality" : 50,
  "material" : "iron",
  "close_msg" : "The huge iron doors swing shut.\n",
  "open_msg" : "You open the huge iron doors.\n"]) );

  create_door("east", "west",
  (["short" : "ornate door",
  "long" : "An ornate door made of iron leads to the east. It is easily tall "+
  "enough for a b'rogh to use. There are intricate etchings on the door which "+
  "depict ancient historical events that no one alive today would remember.\n",
  "status" : "unlocked",
  "autoclose" : 45,
  "quality" : 50,
  "material" : "iron",
  "close_msg" : "The ornate door swings shut.\n",
  "open_msg" : "You open the ornate door.\n"]) );

  create_door("west", "east",
  (["short" : "gilded door",
  "long" : "This door is made of iron, but has some superb detailing done "+
  "in gold. The material seems to positively flow down the surface like a "+
  "shining river. Since the door is easily tall enough for a b'rogh to use, "+
  "it must have cost a pretty penny to make.\n",
  "status" : "unlocked",
  "autoclose" : 45,
  "quality" : 50,
  "material" : "iron",
  "close_msg" : "The gilded door swings shut.\n",
  "open_msg" : "You open the gilded door.\n"]) );
}