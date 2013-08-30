#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("wandering, vaguely humanoid spirit");
  set_long(wrap("A strange spirit seems to be wandering at random around the "+
  "caverns. It looks like a human at first glance, but its outline is too "+
  "obscure to be sure. You'd guess that this is probably all that remains of "+
  "one of the numerous adventurers who were foolish enough to venture here. "+
  "It doesn't seem to be interested in matters of the living.\n"));
  set_name("spirit");
  set_race("spirit");
  set_id( ({ "wandering spirit", "humanoid spirit", "spirit"}) );
  set_level(15);

  add_random_weapon("random_random", 3);

  set_combat_kit("fighter 1");
  set_species("undead");
  set_resistance("physical",10+random(65));
  set_stat("size",50+random(300));
  set_skin_data("type", "none");
  set_speed(60+random(50));
  set_forbidden_rooms( ({ "/u/a/allanon/area/caverns_of_slime/rooms/barren_clearing",
                          "/u/a/allanon/area/caverns_of_slime/rooms/basin",
                          "/u/a/allanon/area/caverns_of_slime/rooms/passage" }));
}