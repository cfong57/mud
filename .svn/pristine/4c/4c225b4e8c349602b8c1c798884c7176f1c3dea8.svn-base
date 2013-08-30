#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"decorated bracelet", "bracelet"}) );
  set_name("bracelet");
  set_short("A decorated bracelet");
  set_long(wrap("A thin band that is worn around the wrist. It wasn't "+
  "made with the purpose of protection in mind, but it seems to be "+
  "indestructible. The bracelet is set with a few precious gems and a pearl "+
  "here and there; it's probably not even that expensive an item. "+
  "Nevertheless it looks very nice, and you feel envy for the lucky "+
  "shopper who happened to pick it up. The bracelet appears to contain "+
  "powerful magic, as the cherry that tops off the sundae.\n"));
  set_slots( ({"arm"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("bracelet");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}