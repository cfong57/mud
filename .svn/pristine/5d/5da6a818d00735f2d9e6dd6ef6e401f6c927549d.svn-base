#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("shining silver dagger");
  set_id(({"dagger"}));
  set_long("It's a fairly ordinary silver dagger. Poison has been enchanted "+
  "into the weapon, causing slight black tarnishes. Seeing as it is made of "+
  "fine silver and not some other, better material, you can guess with good "+
  "reason that it is a weapon of the nobles, more for its showy effect than "+
  "for its usefulness as a real weapon.\n");
  set_name("dagger");
  set_wtype("dagger");
  set_material("silver");
  set_quality(20);

  set_cost_modifier(0.3);
  weapon_setup();
}

string query_special_feature()
{
return "The poison on this weapon may poison enemies.";
}

int special_hit(object target)
{
  object pob;

  if (!random(10))
    {
      if (pob = present("poisonob",target))
        {
          message("damage", "The dagger's puncture feels odd!\n", target);

          pob->set_pdamage(pob->query_pdamage()+random(10)+10);
          pob->set_counter(pob->query_counter()+25);
        }
      else
        {
          message("damage", "The dagger's puncture feels odd!\n", target);
          pob = new("/obj/poisonob");
          pob->set_pdamage(10+random(10));
          pob->set_counter(25+random(5));
          pob->set_cycle(15);
          pob->set_incubation(50);
          pob->move(target);
        }

      return 1;
    }


  return 0;
}