#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"bandana", "red bandana"}));
  set_name("bandana");
  set_short("A red bandana, worn as a neckerchief");
  set_long(wrap("This bright red square of cloth is maybe 30 centimeters to a "+
  "side. It has no pattern to the cloth, and yet you can't stop staring at "+
  "it, as if it was made to attract attention. The bandana is a bit too large "+
  "to be worn on the head, so you think it would be worn as a neckerchief. A "+
  "cloth like this is useful in many situations: trekking through a blizzard, "+
  "emergency tourniquet, bloodstain wiper, and so on.\n"));
  set_slots( ({"miscellaneous"}) );
  set_material("heavy cloth");
  set_type("standard");
  set_type_desc("miscellaneous");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}