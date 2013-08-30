#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"adamantium breastplate", "breastplate", "polished battle armour",
  "battle armour", "armour"}) );
  set_name("battle armour");
  set_short("Polished battle armour");
  set_long(wrap("This is a solid adamantium breastplate. It has been polished "+
  "to a high sheen, and you could use it as a mirror if you needed to. Unlike "+
  "most other armours, this one is quite thin. It conforms very tightly to "+
  "the wearer's body, and is so designed that you can wear it underneath "+
  "ordinary clothing. It is actually warm to the touch, and feels like a "+
  "garment: although made of metal, it is highly flexible. As an armour, "+
  "though, you doubt you could ever find anything that would protect you "+
  "better - and it is imbued with protective magic, as well. You wonder "+
  "where such an amazing item as this came from.\n"));
  set_slots( ({"torso"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("breastplate");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}