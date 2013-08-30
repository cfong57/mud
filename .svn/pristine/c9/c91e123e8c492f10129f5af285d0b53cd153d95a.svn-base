#include <mudlib.h>

inherit "/std/ranged";

void extra_create() 
{
  set_short("Six-shooter hand crossbow called 'Revolver'");
  set_id( ({ "six-shooter hand crossbow", "six-shooter", "six-shooter crossbow",
  "hand crossbow", "crossbow", "revolver" }) ) ;
  set_basic_long("What an odd crossbow. It is made of iron, although the "+
  "stock is wood for comfort's sake. In the place where an ordinary crossbow "+
  "would nock the quarrel, there is a sort of rotating mechanism with six "+
  "slots in it. It seems that every time the trigger is pulled and a shot "+
  "fires, the mechanism ratchets to the next position, and another quarrel "+
  "could be ready for launch. While this feature makes the crossbow "+
  "convenient for continuous fire, it will take a lot more time to load a "+
  "new quarrel into the mechanism.\n");
  set_ranged_type("crossbow");
  set_wtype("hand crossbow");
  set_material("iron");
  set_quality(100);
  set_identified(1);
  set_dam_mod(100);
  set_strength_value(0);
  set_hit_mod(30);
  set_aim_time(-100);
  set_load_time(15); 
  set_max_ammo(6);
  set_durability(1000);   
  weapon_setup();
}