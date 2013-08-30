#include <mudlib.h>

inherit ARMOR ;

void extra_create()
{
  set_id( ({"forest-green boots", "green boots", "boots"}) );
  set_name("boots");
  set_short("forest-green boots");
  set_long("These boots are made of very fine leather, and are as green as the "+
  "forest itself. Lifelike golden leaf adornments are embroidered on each "+
  "boot. The soles are made of well-worn leather which makes no sound. It's "+
  "quite obvious that a wealthy Ranger once owned these.\n");
  set_slots( ({"foot", "foot"}) );
  set_material("leather");
  set_type("standard");
  set_type_desc("boots");
  set_quality(20);

  if(!random(10))
   add_magic_property("strength",1);

  set_cost_modifier(0.3);
  set_size(150);
  armour_setup();
}