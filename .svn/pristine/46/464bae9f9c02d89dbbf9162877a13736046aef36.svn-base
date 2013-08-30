#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Silver mace of Leech");
  set_id(({"silver mace of Leech", "silver mace of leech", "silver mace", 
  "mace of Leech", "mace of leech", "mace"}));
  set_long(wrap("In design, it appears to be just like any other ordinary "+
  "mace. Acid drips in a constant stream from the spikes in the head, but "+
  "what is most conspicuous is the foul stench surrounding the weapon. It "+
  "reeks of rotten blood...You can detect a faint red overtone to the "+
  "weapon's coloration, if you look closely. The silver seems to have been "+
  "permanently tarnished to that color.\n"));
  set_name("mace of Leech");
  set_wtype("mace");
  set_material("silver");
  set_quality(40);
  add_magic_property("acid damage", 3);
  weapon_setup();
}

string query_special_feature() 
{ 
return "It sucks the life force of living things.";
} 

int special_hit(object target, int damage, string bodypart) 
{
  if (target->query_player() == 0) {
  //Don't want players to abuse as free healing
    if (target->query_species() == "undead") {
      object plr = this_object()->query_user();
      //only have messages for "reverse drain", as a warning alert for players
      message("damage", "As your mace strikes "+target->query_cap_name()+", "+
      ""+subjective(target)+" appears to be invigorated.\n", plr);    
      message("damage", "You feel drained.\n", plr);
      target->receive_healing(damage); 
      plr->receive_damage(damage);
    } else {
      object plr = this_object()->query_user();
      //adjust this value to easily tune healing, if too strong
      plr->receive_healing(damage);
    }
    return 1;
  }
  return 0;
}