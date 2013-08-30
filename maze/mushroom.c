#include <mudlib.h>
#include <damage.h>
#include <move.h>

inherit MONSTER;

void extra_create()
{
  set_short("Angry-looking red and white fly agaric");
  set_long(wrap("This is a mushroom called fly agaric with white spots on the "+
  "red background. The stem of the mushroom is snow-white. It looks tasteful "+
  "but you remember that it is quite poisonous and shouldn't be eaten.\n"+
  "Something is odd about this mushroom, though - it is 'alive', and quite "+
  "angrily attacking you for disturbing it! The mushroom seems to have grown "+
  "tiny white fists attached to spindly arms, with which it is attempting to "+
  "beat you to death. As if that wasn't enough, it also shakes out clouds of "+
  "poisonous, choking spores on occasion. You have heard of deadly mushrooms "+
  "before, but nothing ever quite like this.\n"));
  set_name("Red and white fly agaric");
  set_id(({"mushroom", "red mushroom", "agaric", "fly agaric",
  "red fly agaric"}));
  set_level(15);
  set_body_parts(({
  "crown", 60, 1, "crown",  
  "fists", 15, 1, "fists", 
  "stem", 25, 1, "stem"}));     
  add_natural_weapon("spores", "bludgeoning", 1,
  ({POISON, 50, ASPHYXIATION, 50})); //wish there was a "choking" 2nd arg
  add_natural_weapon("fists", "bludgeoning");
  natural_weapon_damage(65); //can't specify for spores or it negates dtypes
  set_stat("size", 25);
  set_species("mushroom");
  set_gender("neuter");
  set_resistance("poison", 50);
  set_aggressive(1);
  set_following(0);
  set_heartless(1);
  set_skin_data("type", "none");
}