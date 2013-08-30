#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_race("spider");
  set_species("animal");
  set_short("Huge spider, eyes glowing bright");
  set_long(wrap("A very large and angry spider is crouched in front of you, "+
  "its eight eyes staring you down in what almost seems a challenge. The "+
  "body of the spider is pitch black, with some dark red spots that "+
  "resemble blood. Its mandibles are long and sharp-looking, and appear to "+
  "drip some sort of greenish liquid. You would not be surprised to find out "+
  "that this spider is poisonous - and based on its predisposition towards "+
  "you, fighting it seems inevitable at this point.\n"));
  set_name("Huge spider");
  set_id(({ "huge spider", "spider"}));
  set_level(20);
  set_body_parts(({
  "body", 30, 1.2, "body", 
  "eyes", 5, 2, "eyes", 
  "legs", 65, 1, "legs"}));     
  add_natural_weapon("mandibles", "piercing", 1, ({PHYSICAL, 15, POISON, 85}));
  add_natural_weapon("claws", "slashing", 0);
  natural_weapon_damage(75, "claws");
  natural_weapon_damage(55, "mandibles");
  set_hand_priorities(({"mandibles", "claws"}));    
  set_stat("size", 200);
  set_gender("neuter");
  set_skill("dodge", 65);
  set_skill("avoid hits", 65);
  set_resistance("poison", 50);
  set_aggressive(1);
  set_following(90);
}

int special_hit(object target)
{
  if (!random(7)) {
    message("poison", "You feel a burning sensation all through your "+
    "body as the spider bites you!\n", target);
    message("poison", ""+target->query_cap_name()+" cries out in pain as "+
    "the spider bites "+objective(target)+"!\n", environment(target), target);
    target->poison(25 + random(15), 5, 10 + random(10), 1); 
    return 1;
  }
  return 0;
}