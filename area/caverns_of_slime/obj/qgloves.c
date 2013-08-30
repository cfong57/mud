#include <mudlib.h>

inherit ARMOR ;

void extra_create() {
  set_id( ({"forest-green gloves", "green gloves", "gloves"}) );
  set_name("gloves");
  set_short("forest-green gloves");
  set_long("These gloves are made of very fine silk, and are as green as the "+
  "forest itself. Lifelike golden leaf adornments are embroidered on the back "+
  "of each glove. The front of the gloves are covered in a peculiar substance "+
  "similar to tree sap which gives them a very good grip.\n");
  set_slots( ({"hand", "hand"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("gloves");
  set_quality(21);
  if(!random(10))
  add_magic_property("dexterity",1);
  else if(!random(100))
  add_magic_property("dexterity",2);
  set_size(150);
  armour_setup();
}