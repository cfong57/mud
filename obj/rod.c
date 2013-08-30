#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("The Magic Fishing Rod, complete with Magical Hook");
  set_id(({"magic fishing rod", "magic rod", "fishing rod", "rod"}));
  set_long(wrap("This is Allanon's Magic Fishing Rod. Better than an ordinary "+
  "fishing rod, it is made from sturdy but flexible adamantium. The barbed hook "+
  "is made of mithril, and is unbendable. This rod doubles as an excellent "+
  "weapon too!\n"));
  set_name("Magic Fishing Rod");
  set_wtype("spear");
  set_material("adamantium");
  set_quality(999);
  add_magic_property("skill fishing",5);
  add_magic_property("strength",5);
  add_magic_property("dexterity",5);
  add_magic_property("constitution",5);
  add_magic_property("intelligence",5);
  add_magic_property("wisdom",5);
  add_magic_property("charisma",5);
  add_magic_property("accuracy",5);
  add_magic_property("speed",5);
  add_magic_property("damage",5);
  add_magic_property("light",5);
  add_magic_property("fire",5);
  add_magic_property("cold",5);
  add_magic_property("poison",5);
  add_magic_property("acid",5);
  add_magic_property("lightning",5);
  add_magic_property("psionic",5);
  add_magic_property("asphyxiation",5);
  add_magic_property("sonic",5);
  add_magic_property("magical",5);
  weapon_setup();
}

string query_type() 
{
return "fishing rod"; 
}

int query_not_offensive() 
{ 
return 1; 
}

mixed * query_dtypes()  { return ({ MAGICAL, 100 }); } 