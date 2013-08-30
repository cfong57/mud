#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"diamond earrings", "earrings"}));
  set_name("diamond earrings");
  set_short("A pair of diamond earrings");
  set_long(wrap("This is a pair of finely crafted diamond earrings. The base "+
  "material is 24k gold. The earrings measure around 2 centimeters in "+
  "length and they hang freely from the ears. You don't see anything special "+
  "about the item other than its fine craftmanship.\n"));
  set_slots( ({"ear", "ear"}) );
  set_material("gold");
  set_type("full plate");
  set_type_desc("earrings");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}