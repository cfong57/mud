#include <mudlib.h>

inherit ARMOR;

void extra_create() {
  set_id( ({"slimy black breastplate", "black breastplate", "breastplate"}) );
  set_name("slimy black breastplate");
  set_short("slimy black breastplate");
  set_long(wrap("This was once a simple breastplate made of silk, "+
  "but after being stuck within the slime for so long it has turned sickly "+
  "black and is permanently covered in a thin coating of slime. However, it "+
  "still functions fine as an armor, and you think it has picked up some "+
  "magical properties over time.\n"));
  set_slots( ({"torso"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("breastplate");
  add_magic_property("dexterity",1);
  add_magic_property("resist acid",5);
  set_size(150);
  set_quality(10);
  armour_setup();
}