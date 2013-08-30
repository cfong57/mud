#include <mudlib.h>

inherit ARMOR ;

void extra_create()
{
  set_id( ({"forest-green tights", "green tights", "tights"}) );
  set_name("tights");
  set_short("forest-green tights");
  set_long(wrap("These tights are made of very fine silk, and are as green as the "+
  "forest itself. Lifelike golden leaf adornments are embroidered along the "+
  "outside of the legs. This is distinctly a Ranger item, and a wealthy Ranger "+
  "at that.\n"));
  set_slots( ({"leg", "leg"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("tights");
  set_quality(10);
  if(!random(5))
  add_magic_property("dexterity",1);
  set_size(150);
  armour_setup();
}