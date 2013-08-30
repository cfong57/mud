#include <mudlib.h>

inherit "/std/liquid_container";

int query_no_weight_message() 
{ 
  return 1; 
}

void create()
{
  set_short("A small spring, flowing into a stone basin");
  set_id(({ "small spring", "spring", "stone basin", "basin", "water" }) );
  set_name("a small spring flowing into a stone basin");
  set_long(wrap("A natural spring comes out of the grond and pools into a low "+
  "stone basin on the ground. The water never quite overflows the lip of the "+
  "basin, it is probably enchanted with some sort of magic. The water looks "+
  "clean and pure: you could drink it or fill a liquid container with it.\n"));
  set_prevent_get(1);
  set_liquid_type("spring water");
  set_mass(100000);
  set_bulk(500000);
  set_gulp_mass(100);
  set_value(0);
  set_drink_type(2);
  set_water_value(400);
  set_ep_value(35);
}