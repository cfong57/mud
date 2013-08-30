#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Eastern hallway of the Bastion" );
  set_long(wrap("This hallway is fairly well-kept, considering that no one "+
  "has lived here for many years. The floor is lined with a rich red velvet "+
  "carpet - it lines the way going north, east, and south. Miraculously, "+
  "the carpet seems to have not even a scuff mark on it; perhaps the ghostly "+
  "servants take special care to maintain this room. To the east is a sort of "+
  "foyer, leading into what appears to be a dining room. There are some "+
  "frames on the walls here, all of which contain paintings.\n"));
  add_monster("/u/a/allanon/area/ity/mon/servant.c");
  set_item_desc(([
  ({"floor", "rich red velvet carpet", "rich velvet carpet", "rich carpet",
  "red velvet carpet", "red carpet", "velvet carpet", "carpet"}) : "The "+
  "carpet is blood-red in hue, and quite plush and comfortable. Not a spot "+
  "of dust can be seen on it, suggesting that someone or something works "+
  "to keep it clean.\n",
  ({"east", "foyer", "dining room"}) : "The hallway narrows in the east to "+
  "form a smaller sort of vestibule, set apart from the main room by some "+
  "curtains which are currently open. Beyond you can see a room with a long "+
  "table set with many chairs, so you assume it is a dining room.\n",
  ({"frames", "walls", "paintings"}) : "The walls are covered with a variety "+
  "of frames, some iron, others gold, which all contain paintings. The "+
  "scenes range from vivid sunsets to stormy oceans, but they all have a "+
  "certain class and appeal to them that you can't quite define. Whoever "+
  "picked these out had a real eye for aesthetics.\n"]));
  set_sounds(200 + random(10), ({ 
  "The carpet looks so plush and inviting that you consider putting down "+
  "your things and just taking a nap here.\n"}) ); 
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/towerne1.c",
  "east" : "/u/a/allanon/area/ity/rooms/dining.c",
  "south" : "/u/a/allanon/area/ity/rooms/towerse1.c"]));
}