#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_short("A shining, dark-purple dragonfly");
  set_long(wrap("You may not be an expert on insects, but it's impossible to "+
  "look at this dragonfly and not see that it is highly venomous. You regret "+
  "already that you disturbed it, because it is almost certainly going to "+
  "take your life. It has the usual gossamer wings of dragonflies, "+
  "multifacteded insect eyes, and six legs ending in small but sharp claws. "+
  "There is a wicked-looking stinger on its tail, something you are sure is "+
  "not seen often. Its mandibles are coated in a vile-looking yellow liquid, "+
  "you know it is poison.\n"));
  set_name("Dragonfly");
  set_id(({ "A shining, dark-purple dragonfly", 
  "a shining, dark-purple dragonfly", "shining, dark-purple dragonfly", 
  "shining dragonfly", "dark-purple dragonfly", "dragonfly"}));
  set_level(12);
  set_body_parts(({
  "body", 40, 1, "body", 
  "eyes", 5, 2, "eyes", 
  "wings", 25, 1.2, "wings", 
  "tail", 30, 1, "tail"}));     
  add_natural_weapon("mandibles", "biting", 1, ({PHYSICAL, 15, POISON, 85}));
  add_natural_weapon("claws", "slashing");
  add_natural_weapon("stinger", "piercing", 0, ({PHYSICAL, 35, POISON, 65}));
  natural_weapon_damage(45);
  set_hand_priorities(({"claws", "mandibles", "stinger"}));    
  set_stat("size", 25);
  set_species("dragonfly");
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
    "body as the dragonfly stings you!\n", target);
    message("poison", ""+target->query_cap_name()+" cries out in pain as "+
    "the dragonfly stings "+objective(target)+"!\n",
    environment(target), target);
    target->poison(25 + random(15), 5, 10 + random(10), 1); 
    return 1;
  }
  return 0;
}