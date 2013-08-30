#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"belt", "leather belt", "worn leather belt"}));
  set_name("belt");
  set_short("Worn leather belt");
  set_long(wrap("This belt is made of leather. It has been used a lot, and "+
  "it's nicely broken in; the leather bends easily but does not crack. The "+
  "buckle is made of burnished silver, and is unadorned. A belt like this is "+
  "practical, and it doesn't look half bad, either.\n"));
  set_slots( ({"belt"}) );
  set_material("leather");
  set_type("standard");
  set_type_desc("belt");
  set_quality(100);
  set_size(175);
  add_magic_property("protection",5);
  armour_setup();
}