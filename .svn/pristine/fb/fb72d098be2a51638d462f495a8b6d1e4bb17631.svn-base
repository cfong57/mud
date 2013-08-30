#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Bastion living quarters for the servants" );
  set_long(wrap("These are the living quarters for the servants. You can tell "+
  "due to the vast number of beds in the room, plus the general level of "+
  "dirtiness. Even though the nobles like to have their things clean, the "+
  "servants aren't paid to clean their own rooms. Next to each bed is a small "+
  "dresser, and some skins cover the floor to serve as rugs. There are a few "+
  "windows set high up on the walls, although they have iron grills on them "+
  "to prevent anything from passing through.\n"));
  add_monster("/u/a/allanon/area/ity/mon/servant.c");
  set_item_desc(([
  ({"bed", "beds", "dresser"}) : "The beds are simple affairs, being made of "+
  "piles of straw, cloth, and other semi-soft but cheap materials. You find "+
  "it odd that these things have not rotted away; perhaps the servant spirits "+
  "still keep things in order around here. Next to each bed is a small wooden "+
  "dresser where the servants would have stored their personal goods.\n",
  ({"rugs", "skins"}) : "The rugs are made of various animal skins stitched "+
  "together, although of course none of them are expensive. They help at "+
  "least a little bit to keep the room suitable for habitation.\n",
  ({"windows", "walls", "iron grills", "grills"}) : "The windows are "+
  "set high up enough that you could not reach them easily. The grills sort "+
  "of remind you of the bars that would cover a jail cell window. As with "+
  "the rest of the castle, the grills have rusted.\n"]));
  set_sounds(100 + random(100), ({ 
  "You sneeze as a mote of dust works its way up your nose.\n"}) );
  set_exits(([
  "east" : "/u/a/allanon/area/ity/rooms/kitchen.c"]));
}