#include <mudlib.h>

inherit ARMOR;

void extra_create()
{
  set_short("demonhide shirt of stealthiness");
  set_long(wrap("This shirt is made of rugged demonhide, and is colored in a "+
  "way which makes hiding in the shadows easy. The buttons are made of fine "+
  "mahogeny wood, the likes of which not even the highest nobles have at their "+
  "disposal. You think they probably came straight from the tree itself.\n"));
  set_name("shirt");
  set_id(({"shirt", "demonhide shirt", "demonhide shirt of stealthiness", 
  "shirt of stealthiness"}));
  set_slots(({"torso"}));
  set_material("demonhide");
  set_type("standard");
  set_type_desc("shirt");
  set_quality(10);
  add_magic_property("dexterity",1);
  //add_magic_property("skill hide in shadows",3); "No such skill" error in Dev
  set_size(175);
  armour_setup();
}