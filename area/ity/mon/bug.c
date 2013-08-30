#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_race("insect");
  set_species("animal");
  set_short("Tiny black bug skittering around");
  set_long(wrap("A tiny black bug has fallen out of the hidden compartment in "+
  "the chair. It looks pretty harmless, being only 5 centimeters long and "+
  "having no particularly dangerous looking bodyparts. The bug stares at you "+
  "with its compound eyes before flitting away around the room.\n"));
  set_name("bug");
  set_id(({ "tiny black bug", "black bug", "tiny bug", "bug"}));
  set_level(5);
  set_body_parts(({
  "body", 30, 1.2, "body", 
  "eyes", 5, 2, "eyes", 
  "legs", 65, 1, "legs"}));     
  add_natural_weapon("mandibles", "piercing", 1);
  add_natural_weapon("claws", "slashing", 0);
  natural_weapon_damage(5, "claws");
  natural_weapon_damage(5, "mandibles");
  set_hand_priorities(({"mandibles", "claws"}));    
  set_stat("size", 5);
  set_gender("neuter");
  set_following(90);
}