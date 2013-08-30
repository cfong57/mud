#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"beautiful golden ring", "gold ring", "ring"}));
  set_name("golden ring");
  set_short("A beautiful golden ring");
  set_long(wrap("A very well-made gold ring. It is graced by a single, small "+
  "diamond. You would estimate that the ring's value is not measured in "+
  "karats, but instead in the memory of a promise that it symbolizes.\n"));
  set_slots( ({"finger"}) );
  set_material("gold");
  set_type("full plate");
  set_type_desc("ring");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}