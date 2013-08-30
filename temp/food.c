#include <mudlib.h>

inherit FOOD;

void extra_create()
{
  set_short("Ambrosia");
  set_long("This is the fabled 'Food of the Wizards'.\n");
  set_id( ({ "food", "ambrosia"}) );
  set_edible(1);
  set_food_value(1000);
  set_ep_value(1000);
  set_water_value(1000);
  set_mass(1);
  set_bulk(1);
  set_rot_time(0);
}