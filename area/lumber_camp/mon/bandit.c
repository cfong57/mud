#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Frightened bandit, brandishing his sword at you");
  set_long(wrap("Something has clearly scared this bandit half-mad, as "+
  "without even looking at you, he is brandishing his weapon and uttering "+
  "a battlecry. You wonder what could drive a man to such desperation. Maybe "+
  "the body on the floor belonged to his comrade, and he is so scared of the "+
  "assailant that he is blindly attacking anything that draws near. The man "+
  "has some nasty, fresh cuts on his body - you are clearly not the first "+
  "to be drawn into his insanity.\n"));
  set_name("Frightened bandit");
  set_id( ({ "frightened bandit", "bandit", "bandit_ob"}));
  set_level(10 + random(2));
  set_aggressive(1);
  set_race("human");
  set_gender("male");
  add_random_weapon("random_scimitar", 4, ({"left hand", "right hand" }));
  add_random_armour("leather_standard_cap", 2);
  add_random_armour("leather_standard_boots", 2);
  add_random_armour("leather_standard_shirt", 2);
  add_random_armour("leather_standard_cloak", 2);
  add_random_armour("leather_standard_pants", 2);
  set_following(0);
  set_att_chat_output( ({ "The bandit cowers in fear, obviously unwilling - "+
  "or unable - to put up a solid fight.\n"})); 
  set_chat_chance(3);
}