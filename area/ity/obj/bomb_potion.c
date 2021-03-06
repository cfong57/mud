#include <mudlib.h>

inherit "/obj/potions/alch_potion.c";

int query_not_saveable() { return 1; }
int do_wear_off() { return 1; }

void extra_create()
{
  set_id(({"bomb potion", "potion", "vial", "bomb vial"}));
  set_short("a vial labeled as 'bomb'") ;
  set_long(wrap("The surface of the vial sparkles in the light, and the "+
  "smooth bright red liquid inside the potion seems to glitter a bit.\n"));
  set_potion_id("bomb potion");
  set_power(100);
  set_effect_time(200);
  set_value(500);
}

int do_effect()
{
  if(!drinker)
    this_object()->move("/d/std/void");
  if(!thrower)
  {
   message("info","The potion explodes in your stomach!\n",drinker);
              drinker->receive_damage(power+random(100));
              return 1;
  }
  message("info","The potion suddenly EXPLODES as the liquid inside it reacts "+
                      "with the air!\n",environment(thrower));
  foreach(object ob in all_inventory(environment(thrower)))
    {
      if(ob->query_npc()==1)
        {
          if(thrower)
            {
              ob->kill_ob(thrower);
            }
          else
            {
              message("info","The potion explodes in your stomach!\n",drinker);
              drinker->receive_damage(power+random(100));
              return 1;
            }
          if(time()-ob->query("bombed_last")>120)
            {
              if(ob==drinker)
                {
                  message("info",ob->query_cap_name()+" writhes as the blast "+
                  "from the exploding potion hits "+objective(ob)+
                          "\n",environment(ob));
                  ob->set("bombed_last",time());

                  ob->set_last_attacker(thrower);
                  ob->receive_damage(power+random(1000));
                }
              else
                {
                  message("info",ob->query_cap_name()+" writhes as the blast "+
                  "from the exploding potion hits "+objective(ob)+
                          "\n",environment(ob));
                  ob->set("bombed_last",time());

                  ob->set_last_attacker(thrower);
                  ob->receive_damage(power+random(300));
                }
            }
          else
            {
              message("info",ob->query_cap_name()+" recognizes the potion "+
              "and ducks the blast a bit.\n",
                      environment(ob));
              if(ob==drinker)
                {
                  ob->set_last_attacker(thrower);
                  ob->set("bombed_last",time());
                  ob->receive_damage(power+random(200));
                }
              else
                {
                  ob->set_last_attacker(thrower);
                  ob->set("bombed_last",time());
                  ob->receive_damage(power/2+random(150));
                }
            }
        }
    }
  return 1 ;
}
