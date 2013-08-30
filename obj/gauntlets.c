#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"adamantium gauntlets", "gauntlets", "black gauntlets"}) );
  set_name("black gauntlets");
  set_short("A pair of black gauntlets");
  set_long(wrap("This is a pair of black gauntlets. They are very thin, but "+
  "they also provide excellent protection as they are made of adamantium. The "+
  "gauntlets have been designed in such a way that they're almost more like "+
  "gloves and gauntlets; they are very flexible.\n"));
  set_slots( ({"hand", "hand"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("gauntlets");
  add_magic_property("protection",5);
  set_quality(100);
  set_size(175);
  armour_setup();
}