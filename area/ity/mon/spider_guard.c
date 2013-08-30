#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_race("spider");
  set_species("animal");
  set_short("Giant spider, bristling with aggression");
  set_long(wrap("This truly giant spider blocks your path forward. Its eight "+
  "eyes stare at you eerily while its large mandibles gnash together with a "+
  "terrible sound. The spider's body is a dull black which blends in well "+
  "with the shadows; you keep losing sight of it when it dashes into a "+
  "corner. Whether the spider is actually angry or merely hungry, you are not "+
  "sure, but either way it seems determined to make a meal out of you...\n"));
  set_name("Giant spider");
  set_id(({ "giant spider", "spider", "spider_guard"}));
  set_level(25);
  set_body_parts(({
  "body", 30, 1.2, "body", 
  "eyes", 5, 2, "eyes", 
  "legs", 65, 1, "legs"}));     
  add_natural_weapon("mandibles", "piercing", 1, ({PHYSICAL, 10, POISON, 90}));
  add_natural_weapon("claws", "slashing", 0);
  natural_weapon_damage(80, "claws");
  natural_weapon_damage(60, "mandibles");
  set_hand_priorities(({"mandibles", "claws"}));    
  set_stat("size", 300);
  set_gender("neuter");
  set_skill("dodge", 75);
  set_skill("avoid hits", 75);
  set_resistance("poison", 75);
  set_aggressive(1);
  set_following(0);
}

int special_hit(object target)
{
  if (!random(5)) {
    message("poison", "You feel a burning sensation all through your "+
    "body as the spider bites you!\n", target);
    message("poison", ""+target->query_cap_name()+" cries out in pain as "+
    "the spider bites "+objective(target)+"!\n", environment(target), target);
    target->poison(30 + random(20), 3, 15 + random(15), 3); 
    return 1;
  }
  return 0;
}