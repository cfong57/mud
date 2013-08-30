#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_short("Large vulture, feeding on corpses");
  set_long(wrap("A large-looking vulture is feeding on the corpses here. It "+
  "has a nasty hooked beak suitable for tearing flesh, but still it doesn't "+
  "look extremely dangerous. However it is an unclean creature; a wound from "+
  "its beak or claws might become infected. Its feathers are a dirty black "+
  "color, with red and brown mixed in from blood and other refuse of corpses. "+
  "As you look at it, the vulture turns its glassy eye on you, but then "+
  "resumes eating as it finds you are still a living creature.\n"));
  set_name("large vulture");
  set_id(({"large vulture", "vulture"}));
  set_race("vulture");
  set_species("animal");
  set_gender("neuter");
  set_level(12);
  add_natural_weapon("beak", "slashing", 1, ({PHYSICAL, 65, POISON, 35}));
  add_natural_weapon("claws", "slashing", 0, ({PHYSICAL, 65, POISON, 35}));
  natural_weapon_damage(25, "beak");
  natural_weapon_damage(20, "claws");
  set_hand_priorities(({"beak", "claws"})); 
  set_agrochance(10);
  set_chat_output(({
  "The vulture happily rends flesh from a corpse and eats it.\n"}));
  set_chat_chance(3);
}