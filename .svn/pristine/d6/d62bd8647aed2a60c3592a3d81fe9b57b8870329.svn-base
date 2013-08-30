#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Forester's axe");
  set_id(({"forester's axe", "axe", "great axe", "brass great axe",
  "brass axe"}));
  set_long(wrap("This axe appears to be used for cutting down trees. It has a "+
  "very well-forged blade, still quite sharp even after years of hacking into "+
  "solid tree trunks. The shaft too shows not a sign of imperfection. All in "+
  "all, it's an impressive piece of work, and in fine condition. A single red "+
  "rune, resembling a tree stump, is stamped into the axe head.\n"));
  set_name("forester's axe");
  set_wtype("great axe");
  set_material("brass");
  set_quality(25);
  add_magic_property("strength", 2);
  weapon_setup();
}

string query_special_feature() 
{ 
  return "It is especially effective against Treants.";
} 

int special_hit(object target, int damage, string bodypart) 
{
  if (target->query_race() == "treant") {
    if (!random(3)) {
      message("damage", "You scream in pain as the axe blade bites "+
      "deep!\n", target);
      message("damage", ""+target->query_cap_name()+" screams in pain as the "+
      "axe digs deep into "+possessive(target)+" body!\n", 
      environment(target), target);
      target->receive_damage(damage * 3, bodypart);
      return 1;
    }
  }
  return 0;
}