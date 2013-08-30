#include <mudlib.h>

inherit OBJECT;

void extra_create() {
  set_id( ({"big red key", "big key", "red key", "key"}) );
  set_name("big red key");
  set_short("big red key");
  set_long(wrap("This key is quite large and has been made of a red material.\n"));
}