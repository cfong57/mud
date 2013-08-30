#include <mudlib.h>

inherit ARMOR ;

void extra_create()
{
  set_id( ({"forest-green tunic", "green tunic", "tunic"}) );
  set_name("boots");
  set_short("forest-green tunic");
  set_long("This tunic is made of very fine silk, and is as green as the "+
  "forest itself. A lifelike golden leaf adornment is embroidered above the "+
  "left breast. Though sleeveless, the tunic provides sufficient warmth.\n");
  set_slots( ({"clothes"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("clothes");
  set_quality(20);
  set_warmth(2);
  if(!random(100))
  add_magic_property("dexterity",1);
  if(!random(10))
  add_magic_property("epmax",2);
  set_size(150);
  armour_setup();
}