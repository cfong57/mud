#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Blade of the Magi");
  set_id(({"Blade of the Magi", "blade of the magi", "magi blade", "blade"}));
  set_long(wrap("You cannot even discern what the material of this sword is. "+
  "The handle, hilt, pommel, and crossguard all appear to be made of fine "+
  "steel, but the very-incorporeal looking blade seems to be made of pure "+
  "magic. It flows, ebbs, twists, and does all manner of strange movements "+
  "that are impossible for any solid material. The magical aura of this "+
  "weapon is almost overpowering.\n"));
  set_name("blade of the magi");
  set_wtype("longsword");
  set_quality(10);
  set_material("fine steel");
  add_magic_property("skill cast magical", 5);
  weapon_setup();
}

int query_casterweapon()
{
	return 1;
}

mixed * query_dtypes()  
{
  return ({ MAGICAL, 100 });
} 

string query_special_feature() 
{ 
  return "This weapon doesn't interfere with the casting process.";
} 