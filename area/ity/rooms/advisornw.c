#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Common Advisor's room in the Bastion" );
  set_long(wrap("This is a plainly decorated bedroom/study. There are a few "+
  "bookshelves along the walls, although all of the books have rotted away "+
  "by now. A wooden desk and matching chair face a window set into the "+
  "north wall, and opposite on the southern side there is a simple wooden "+
  "bed covered in fur blankets. A plain carpet made of wool lines the floor, "+
  "preventing one's feet from being chilled by the cold stones. A wastebasket "+
  "in the corner has some ancient, yellowed documents wadded up inside it.\n"));
  set_item_desc(([
  ({"bookshelves", "books"}) : "The bookshelves are simple affairs made of "+
  "wood. They used to hold a variety of interesting-looking books on them, "+
  "but sadly you find that most of the bindings have rotted away, and the "+
  "pages are moth-eaten.\n",
  ({"wooden desk", "desk"}) : "The desk is made of oak, and it is sized for "+
  "an average human. A dragon emblem has been carved into the surface.\n",
  ({"wooden chair", "chair"}) : "The chair is made of oak, and it is sized "+
  "for an average human. A dragon emblem has been carved into the back.\n",
  ({"emblem", "dragon emblem"}) : "A dragon, curled around itself like a "+
  "serpent. Its eyes seem to follow you.\n",
  ({"window", "north wall"}) : "A window has been set into the northern "+
  "wall. It gives some light to the room.\n",
  ({"simple wooden bed", "simple bed", "wooden bed", "bed"}) : "The bed is "+
  "set against the southern wall. It is simply constructed of some oak "+
  "planks in a box formation and held together with iron nails.\n",
  ({"fur blankets", "blankets"}) : "The blankets are made of a variety of "+
  "different furs. None of them look very rich, but they certainly are warm.\n",
  ({"plain carpet", "carpet"}) : "The carpet is made of wool. It's a bit "+
  "dirty and could use a good scrubbing, but it is effective as a barrier "+
  "against the cold stone floor.\n",
  ({"stone floor", "floor"}) : "The floor is tiled with stone. It is rather "+
  "cold to the touch.\n",
  "wastebasket" : "The wastebasket is made of a fine iron chainmail wrapped "+
  "around a wooden frame. There are some documents wadded up inside it.\n",
  ({"documents", "paper"}) : "You take a wad of paper out of the wastebasket "+
  "and uncrumple it. It looks like part of a journal entry. The only passage "+
  "you can make out reads: '...if only I could prove his treachery, the "+
  "King and Queen would know what to do; but alas, I am merely the Common "+
  "Advisor...'\n"]));
  set_sounds(135 + random(45), ({ 
  "While this room is plainly furnished, you feel like this would be a good "+
  "place to get some serious work done.\n"}) );
  set_exits(([
  "southeast": "/u/a/allanon/area/ity/rooms/throne.c"]));
}