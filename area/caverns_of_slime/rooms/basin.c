#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "in a large, slime-filled basin" );
  set_long( wrap("Oh dear! You seem to have misjudged the depth of the slime...it's "+
  "too deep, and you are drowning in it! You'd better get back to land, and quickly, before..."+
  "Hold on, what's this? Seems like this basin really is full of some type of green water after all. "+
  "You spot a smallish piece of land towards the center of the basin, perhaps you could reach it by a miracle. There's "+
  "also the wall behind you, it would take inhuman effort but you could climb back up "+
  "to the ledge if you really tried hard...\n"));
  set_item_desc((["slime" : "It is much more viscous than normal water, which makes it extremely hard to swim in!\n",
                  ({"green water", "water"}) : "You were sure that it was slime...from up on the ledge, anyways...\n",
                  "wall" : "Luckily for you it has a rough surface. Perhaps you could climb back up it.\n",
                  "ledge" : "The ledge you were standing on before jumping...it's quite high up from here.\n"]) );
  set_light(50);
  set_epcost(50);
  set_water(800);
  set_exits(
     ([
       "island" : "/u/a/allanon/area/caverns_of_slime/rooms/island.c",
       "wall" : "/u/a/allanon/area/caverns_of_slime/rooms/ledge.c"]));
  set_exit_msg( ([ "island" : "$N swims to the island with much effort.",
                   "wall" : "$N barely manages to climb up the wall!" ]) );
}