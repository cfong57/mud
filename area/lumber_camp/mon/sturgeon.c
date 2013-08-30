#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("A GIGANTIC sturgeon, attacking wildly");
  set_long(wrap("The typical sturgeon is a huge, heavy, bony-plated fish with "+
  "a sharklike tail that lives in large rivers and lakes. They are "+
  "nicknamed 'living fossils' because they are probably millions of years "+
  "old. Sturgeons are the longest living and biggest fish of Icesus.\n"
  "This sturgeon, however, is a true monster of a fish. Its scales sheen "+
  "dully in the light as it wildly thrashes, smashing against sharp rocks "+
  "without so much as a scratch - they must be made out of iron! The sturgeon "+
  "is over two and a half meters long, a length unheard of until now. It has "+
  "jaws that look like they could crush stone, and its bony fins look deadly "+
  "sharp. The sturgeon is attacking in a berserk rage, and you are the first "+
  "target in its sights.\n"));
  set_name("Gigantic sturgeon");
  set_id(({ "GIGANTIC sturgeon", "gigantic sturgeon", "sturgeon", "fish"}));
  set_level(27);
  set_body_parts(({
  "head", 20, 1.2, "head", 
  "body", 40, 1, "body", 
  "tail", 25, 1, "tail", 
  "fins", 15, 1.1, "fins"}));     
  add_natural_weapon("jaws", "piercing", 1);
  add_natural_weapon("fins", "slashing", 0);
  add_natural_weapon("tail", "bludgeoning", 0);
  natural_weapon_damage(95, "jaws");
  natural_weapon_damage(105, "fins");
  natural_weapon_damage(80, "tail");
  set_hand_priorities(({"jaws", "tail", "fins"}));  
  set_natural_ac(150);  
  set_stat("size", 300);
  set_species("sturgeon");
  set_gender("neuter");
  set_skill("unarmed fighting", 75);
  set_skill("berserk", 85);
  set_skill("melee", 90);
  set_aggressive(1);
  set_following(0);
  set_skin_data("bonuses", (["protection": 1]));
  set_skin_data("value", 3500 + random(2500));
  set_skin_data("type", "iron");
  force_me("battle -c berserk");
}