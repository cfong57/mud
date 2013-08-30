#include <mudlib.h>

inherit ROOM;

void brazier_lit()
{
  message("info","The brazier blazes into flame with a FWOOSH. All of a "+
  "sudden, there is a crackling in the air, and then a portal magically "+
  "appears in the middle of the room.\n",this_object());
  add_item(({"portal"}), "In the middle of the room is a crackling portal "+
  "which gives off arcane energies in small bolts. The bolts leave marks on "+
  "the floor, but don't seem to harm you at all.\n");
  add_exit("portal","/u/a/allanon/area/ity/rooms/towerne3.c");
}

void brazier_extinguished()
{
  message("info","As the fire in the brazier dies, the portal in the middle "+
  "of the room suddenly starts shrinking, and soon it vanishes completely.\n",
  this_object());
  remove_item(({"portal"}));
  remove_exit("portal");
}

void extra_create()
{
  set_short( "Northeastern tower of the Bastion, second floor" );
  set_long(wrap("The second floor of the tower is less opulent than the "+
  "first, but it is much more open and airy. This is due to several windows "+
  "being carved into the walls all around the room, each about a meter high "+
  "and fitted with glass rather than iron grills. You have a wonderful view "+
  "of the outside. There is a conspicuous spot in the middle of the floor "+
  "where there is a circular discoloration.\n"));
  add_object("/u/a/allanon/area/ity/obj/brazier.c");
  set_item_desc(([
  ({"windows", "walls", "glass"}) : "Windows are set into the walls all "+
  "around the room, and they are fitted with expensive sheets of thick glass. "+
  "The glass has been taken good care of, as it is still perfectly clear and "+
  "you almost can't tell it's there. You wonder how the outside gets "+
  "cleaned.\n",
  ({"view", "outside"}) : "Looking out in the distance you can see part of "+
  "the rest of the valley where the castle is situated.\n",
  ({"conspicuous spot", "spot", "floor", "circular discoloration", 
  "discoloration"}) : "In the middle of the floor, there is a circular spot "+
  "where the stone looks like it was burned by arcane energies. You wonder "+
  "what it might mean.\n"]));
  set_sounds(100 + random(100), ({ 
  "This room would make for an excellent spot to stargaze.\n"}) ); 
  set_exits(([
  "down" : "/u/a/allanon/area/ity/rooms/towerne1.c"]));
}