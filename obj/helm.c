#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"adamantium helmet", "helmet", "polished battle helm",
  "battle helm", "helm"}) );
  set_name("battle helm");
  set_short("Polished battle helm");
  set_long(wrap("This is a solid adamantium helmet. It has been polished "+
  "to a high sheen, and you could use it as a mirror if you needed to. Unlike "+
  "most other armours, this one is quite thin. The helmet is not very rigid, "+
  "but regardless of its unusual flexibility it manages to fit well on the "+
  "wearer's head. The brim of the helmet comes down to just above the "+
  "eyebrows, circles around the ears, and ends around the nape of the neck. "+
  "As an armour, you doubt you could ever find anything that would protect "+
  "you better than this helmet, except for maybe a full helm of the same "+
  "material. It is even imbued with protective magic, as well. You wonder "+
  "where such an amazing item as this came from.\n"));
  set_slots( ({"head"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("helmet");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}