#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Ghostly cook, chopping ghostly vegetables");
  set_long(wrap("A ghostly cook bustles around the kitchen, busily attending "+
  "to food that has no physical substance. It chops vegetables, slices meat, "+
  "tastes soup, and garnishes dishes. Even though none of these items exist "+
  "in the real world, you note that the chef's knife is quite corporeal. You "+
  "narrowly avoid getting stabbed in the face as the busy ghost brushes right "+
  "past you with no concern.\n"));
  set_name("Ghostly cook");
  set_id(({ "ghostly cook", "cook", "ghost", "human", "undead"}));
  set_level(25);
  set_race("human");
  set_species("undead");
  set_gender("neuter");
  set_following(0);
  add_random_weapon("titanium_knife", 10);
}