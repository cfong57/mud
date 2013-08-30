#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"plain necklace", "necklace", "silver necklace"}) );
  set_name("plain silver necklace");
  set_short("A plain silver necklace");
  set_long(wrap("This necklace is rather plain. It is made of an inestimable "+
  "number of tiny silver chains linked to each other, and a clasp of the "+
  "same material keeps it closed. There are no ornaments on the necklace, "+
  "in fact it could almost be mistaken for a silvery piece of string. It "+
  "probably provides at least a modicum of protection to the neck.\n"));
  set_slots( ({"neck"}) );
  set_material("silver");
  set_type("double chain mail");
  set_type_desc("necklace");
  set_quality(100);
  add_magic_property("protection",5);  
  set_size(175);
  armour_setup();
}