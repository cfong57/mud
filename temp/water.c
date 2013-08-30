#include <mudlib.h>

inherit "/std/liquid_container";

void create()
{   
  set_id(({"magical bottle", "bottle"}));
  set_short("a magical bottle");
  set_long(wrap("It's a magic bottle. It holds an infinite amount of water."));
  set_mass(1);
  set_bulk(1);
  set_gulp_mass(1);
  set_value(0);
  set_drink_type(2);
  set_water_value(999);
  set_ep_value(5);
}