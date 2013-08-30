//This is not meant to be cloned by itself

#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

void extra_create()
{
  set_reputation("The City of Vaerlon", -1);
  set_name("reanimated corpse");
  set_gender("neuter");
  set_agrochance(random(25));
  set_aggressive(1);
  set_species("undead");
  set_speed(200+random(50));
  set_chat_chance(4);
  set_following(random(35));
}