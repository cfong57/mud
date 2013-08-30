#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"black boots", "boots"}) );
  set_name("black boots");
  set_short("A pair of black boots");
  set_long(wrap("These boots are both practical and fashionable. Even when "+
  "examining them from close up, it's very hard to tell that they're made out "+
  "of adamantium; they would provide excellent protection in any situation. "+
  "The boots come up to the knees, and have heels of about 8 centimeters. The "+
  "insides are comfortably lined with well-worn leather. While the boots are "+
  "not pointed, it would hurt a lot if someone kicked you while wearing "+
  "these.\n"));
  set_slots( ({"foot", "foot"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("boots");
  set_quality(100);
  set_size(175);
  add_magic_property("protection",5);
  armour_setup();
}