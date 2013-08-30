#include <mudlib.h>

inherit OBJECT;

void extra_create() 
{
  set_short("Medium-sized key made of bronze");
  set_long(wrap("This key is somewhere between being small and being large. "+
  "It is made of bronze, and is shaped somewhat like a dragon.\n"));
  set_id( ({"medium-sized key made of bronze", "medium-sized key", "key",
  "bronze key", "medium key" }) );
  set_name("bronze key");
  set_value(0);
  set_mass(1);
  set_bulk(1);
}