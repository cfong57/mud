#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Cruelly murdered mole");
  set_long(wrap("This mole looks pitiful indeed. There is an enormous gash "+
  "in its back which looks like it was inflicted with a shovel. You can see "+
  "spinal fluids leaking out of the wound. Nevertheless, the mole fights on "+
  "to the end, willing to do anything to protect its home. You cannot help "+
  "but admire its courage before ending its life.\n"));
  set_name("cruelly murdered mole");
  set_id(({"cruelly murdered mole", "mole"}));
  set_race("mole");
  set_species("animal");
  set_gender("neuter");
  set_level(5);
  add_natural_weapon("claws", "slashing", 1);
  add_natural_weapon("bite", "piercing", 0);
  natural_weapon_damage(10, "claws");
  natural_weapon_damage(5, "bite");
  set_hand_priorities(({"claws", "bite"})); 
  set_agrochance(100);
}