#include <mudlib.h>
#include <damage.h>

inherit "/std/ranged";

void extra_create() 
{
  set_id( ({ "artemis bow", "bow" }) ) ;
  set_short("Artemis Bow");
  set_basic_long("This is the sacred Bow of White Lightning.\n");
  set_ranged_type("compound bow");
  set_wtype("long bow");
  set_material("mithril");
  set_quality(100);
  set_identified(1);
  set_dam_mod(100);
  set_strength_value(0);
  set_hit_mod(100);
  set_aim_time(-100);
  set_load_time(0); 
  set_max_ammo(2);
  set_durability(1000);  
  add_magic_property("lightning",5);
  add_magic_property("speed",5);
  add_magic_property("accuracy",5);
  add_magic_property("damage",5);
  add_magic_property("strength",5);
  add_magic_property("dexterity",5);
  weapon_setup();
}

mixed * query_dtypes()  { return ({ LIGHTNING, 100 }); } 