#include <mudlib.h>

inherit ARMOR;

void extra_create()
{
  set_short("Hunter's clothes");
  set_long(wrap("These clothes are made of leather, and they are skintight. "+
  "The leather itself isn't spectacular in any way, it seems to be just "+
  "ordinary leather. There's an image of a knocked bow and arrow embroidered "+
  "on the clothes, aimed at a yellow crescent moon.\n"));
  set_id(({"hunter's clothes", "clothes", "Hunter's clothes", 
  "leather clothes"}));
  set_name("hunter's clothes");
  set_slots(({"clothes"}));
  set_material("leather");
  set_type("standard");
  set_type_desc("clothes");
  set_quality(5);
  set_warmth(2);
  add_magic_property("skill hunting", 3);
  set_size(180);
  armour_setup();
}