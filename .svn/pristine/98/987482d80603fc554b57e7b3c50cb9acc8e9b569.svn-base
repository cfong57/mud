#include <mudlib.h>
#include <damage.h>
#include <daemons.h>
#include <move.h>

inherit WEAPON;

string bodypart;

void extra_create()
{
  set_identified(1);
  set_short("Silver shortsword called 'Black Key'");
  set_id(({"black key", "sword", "shortsword", "silver sword",
  "silver shortsword"}));
  set_long(wrap("This is a peculiar sword. It is short, maybe about 60 "+
  "centimeters long, and thin like a rapier. The blade is made of silver and "+
  "has no ornamentations whatsoever. The handle and crossguard are made of "+
  "some sort of red wood. Overall, the sword has the appearance of a "+
  "miniature stake or cross. Although it is obviously a quality piece of "+
  "work, there doesn't seem to be anything special or magical about this "+
  "weapon. Perhaps it is merely a ceremonial weapon.\n"));
  set_name("black key");
  set_wtype("shortsword");
  set_material("silver");
  set_quality(75);
  weapon_setup();
}

int throw_hit_func(object target, object thrower, object thing_thrown) 
{
  if(target->id("key_id")) {
    message("hit", "The Black Key %^BOLD%^EXPLODES%^RESET%^ as it hits "+
    ""+target->query_cap_name()+", releasing a huge burst of chaotic energy!\n",
    environment(target), target);
    message("hit", ""+thrower->query_cap_name()+"'s Black Key "+
    "%^BOLD%^EXPLODES%^RESET%^ as it hits you, releasing a huge burst of "+
    "chaotic energy!\n", target);
    bodypart = BATTLEOB->get_body_part(thrower, target)[0];
    target->receive_damage(2500, CHAOS, bodypart);
    //chaos = damage type #11; currently unsupported
    thing_thrown->remove();
  }
  else {
    message("return", "The Black Key returns to "+
    ""+thrower->query_cap_name()+"'s hand.\n", environment(target), thrower);
    message("return", "The Black Key returns to your hand.\n", thrower);
    thing_thrown->move(thrower, 1);
  }
  target->kill_ob(thrower);
  return 0;
}

int throw_no_hit_func(object target, object thrower, object thing_thrown)
{
  message("return", "The Black Key returns to "+thrower->query_cap_name()+"'s "+
  "hand.\n", environment(target), thrower);
  message("return", "The Black Key returns to your hand.\n", thrower);
  thing_thrown->move(thrower, 1);
  target->kill_ob(thrower);
  return 0;
}