#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Excalibur %^RESET%^%^BOLD%^%^WHITE%^<divine aura>%^RESET%^");
  set_id(({"mithril longsword", "longsword", "sword", "blade", "excalibur",
  "holy blade", "Excalibur"}));
  set_long(wrap("This holy blade is flawlessly made and deadly sharp. The "+
  "sword is perfectly balanced and made of shining mithril. The edge is sharp "+
  "enough to slice the air itself. A beautiful diamond that reflects light "+
  "most wonderfully has been set to the pommel.\n"));
  set_name("Excalibur");
  set_wtype("longsword");
  set_material("mithril");
  set_quality(100);
  add_magic_property("protection",5);
  add_magic_property("light",5);
  add_magic_property("speed",5);
  add_magic_property("accuracy",5);
  add_magic_property("damage",5);
  weapon_setup();
}

string query_special_feature() 
{ 
return "This weapon doesn't interfere with the casting process.";
} 

int query_not_offensive() 
{ 
return 1; 
}

int query_casterweapon()
{
	return 1;
}

int query_damage() { return 300; } 
int query_size() { return 50; }  
int query_speed() { return 1; }
int query_mass() {return 1; }
int query_bulk() {return 1; }