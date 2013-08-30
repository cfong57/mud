#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"pants", "heavy cloth pants", "dark blue pants", "blue pants" }) );
  set_name("dark blue pants");
  set_short("A pair of skinny blue jeans");
  set_long(wrap("These pants have been flawlessly made - there are no visible "+
  "seams. They have been so designed that you can pull them on easily, and "+
  "there is a simple zipper and button closure. The pants fit very tightly on "+
  "the wearer, but they also allow freedom of movement. The colour is "+
  "interesting: it is a peculiar shade of dark blue that you have never seen "+
  "before, but you find it to be an attractive colour anyways. The material, "+
  "too, is a novelty to you. It is not exactly rough to the touch, but it's "+
  "heavier than most types of cloth and looks to be more damage-resistant.\n"));
  set_slots( ({"leg", "leg"}) );
  set_material("heavy cloth");
  set_type("standard");
  set_type_desc("pants");
  set_quality(100);
  add_magic_property("protection",5);  
  set_size(175);
  armour_setup();
}