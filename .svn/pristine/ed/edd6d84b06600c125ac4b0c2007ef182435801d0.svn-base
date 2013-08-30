#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("A spiny ridge, made of mithril");
  set_id(({"mithril ridge", "ridge", "spiny ridge", "mithril spiny ridge"}));
  set_long("This odd weapon looks a lot like the racial weapon of "+
  "Thri-kreens, the spiny ridge. Except this one is made of mithril.\n");
  set_name("spiny ridge");
  set_wtype("spiny ridge");
  set_material("mithril");
  set_quality(999);
  add_magic_property("poison",5);
  add_magic_property("strength",5);
  add_magic_property("dexterity",5);
  add_magic_property("constitution",5);
  add_magic_property("intelligence",5);
  add_magic_property("wisdon",5);
  add_magic_property("charisma",5);
  add_magic_property("light",5);
  add_magic_property("accuracy",5);
  add_magic_property("damage",5);
  weapon_setup();
}

string query_special_feature() 
{ 
return "This weapon doesn't interfere with the casting process.";
} 

int query_casterweapon()
{
	return 1;
}

mixed * query_dtypes()  { return ({ POISON, 100 }); } 