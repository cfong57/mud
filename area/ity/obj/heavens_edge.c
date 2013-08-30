#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Sword of Separation - Heaven's Edge");
  set_id(({"sword", "sword of separation", "heaven's edge", "edge",
  "heavens edge", "crystal sword", "crystal executioner's sword",
  "crystal executioners sword", "executioner's sword", "executioners sword"}));
  set_long(wrap("This is one of the blades only spoken of in ancient legends "+
  "- the Sword of Separation, known as Heaven's Edge. A beautifully wrought "+
  "blade of purest crystal, it is said that no other weapon can equal its "+
  "sharpness. Heaven's Edge is said to have been used in the battle to "+
  "destroy Okka, the God of Magic; you know that no creature is any match "+
  "for a sword that can cut gods.\n"));
  set_name("Heaven's Edge");
  set_wtype("executioner's sword");
  set_material("crystal");
  set_quality(100);
  weapon_setup();
}

string query_special_feature() 
{ 
return "This weapon's edge is so sharp that it can cut through any living "+
"creature.";
}

int special_hit(object target, int damage, string bodypart) 
{
  target->wound(bodypart, damage, "magical");
  target->wound_loop();     	
  return 1;
}