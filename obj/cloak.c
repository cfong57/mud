#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"beautiful silk cloak", "silk cloak", "cloak"}) );
  set_name("cloak");
  set_short("Beautiful silk cloak");
  set_long(wrap("This beautiful cloak is made of very expensive silk. It is "+
  "nearly transparent, yet not at all fragile - powerful magic has been "+
  "infused into it, and in fact you find that you can't damage it at all. "+
  "Despite being made of paper-thin silk, the cloak is very warm and it even "+
  "appears to be waterproof. You notice that the cloak is amazingly white, "+
  "considering that most white garments get dirty very quickly; either this "+
  "is a very new cloak, or the magic on it keeps it free of dirt, too. It's "+
  "quite an extrordinary item overall.\n"));
  set_slots( ({"cloak"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("cloak");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}