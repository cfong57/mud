#include <mudlib.h>

inherit OBJECT;

void extra_create() {
  set_id( ({"small steel key", "steel key", "key"}) );
  set_name("small steel key surrounded by eerie glow");
  set_short("small steel key surrounded by eerie glow");
  set_long("It is a small key made of steel. You spot a small rune or two
  engraved on it. An eerie glow surrounds the key.\n");
}