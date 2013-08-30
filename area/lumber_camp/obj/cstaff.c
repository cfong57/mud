#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Rotten wood staff");
  set_id(({"rotten wood staff", "rotten staff", "wood staff", "staff"}));
  set_long(wrap("A staff seemingly made from a tree branch. The wood is black "+
  "and pocked full of holes, clearly rotten and worm-infested. Still, it "+
  "seems to be quite strong and sturdy; it doesn't even bend when you apply "+
  "all your strength to it. It probably is of a magical nature, then.\n"));
  set_name("rotten wood staff");
  set_wtype("staff");
  set_material("wood");
  set_quality(15);
  add_magic_property("epmax", -2);
  add_magic_property("hpreg", -1);
  add_magic_property("strength", 2);
  add_magic_property("damage", 1);
  add_magic_property("accuracy", -1);
  add_magic_property("poison damage", 3);
  weapon_setup();
}

string query_special_feature() 
{ 
  return "It can poison opponents with its strange, powerful toxins.";
} 

int special_hit(object target)
{
  if (!random(10)) {
    message("poison", "You feel a burning sensation throughout your "+
    "whole body!\n", target);
    message("poison", "Something seems to have infected "+
    ""+target->query_cap_name()+"!\n", environment(target), target);
    target->poison(55 + random(15), 10 + random(5), 30 + random(10), 1); 
    return 1;
  }
  return 0;
}