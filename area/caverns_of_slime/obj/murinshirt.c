#include <mudlib.h>

inherit ARMOR ;

void extra_create()
{
  set_id( ({"shirt", "demonhide shirt"}) );
  set_name("shirt");
  set_short("green leather shirt of stealthiness");
  set_long("This shirt is made of rugged leather, and is colored in a "+
  "way which makes hiding in the shadows easy. The buttons are made of fine "+
  "mahogeny wood, the likes of which not even the highest nobles have at their "+
  "disposal. You think they probably came straight from the tree itself.\n");
  set_slots( ({"torso"}) );
  set_material("leather");
  set_type("standard");
  set_type_desc("shirt");
  set_quality(10);

  if(!random(10))
   add_magic_property("dexterity",1);

  add_magic_property("skill hide in shadows",1+random(3));

  set_cost_modifier(0.3);
  set_size(150);
  armour_setup();
}