#include <mudlib.h>

inherit OBJECT;

void extra_create() {
  set_id( ({"bent blue key", "bent key", "blue key", "key"}) );
  set_name("bent blue key");
  set_short("bent blue key");
  set_long(wrap("This key has been bent and is made of a blue material.\n"));
}