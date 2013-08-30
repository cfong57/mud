#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("ancient steel sabre");
  set_id(({"ancient steel sabre", "steel sabre", "sabre"}));
  set_long("It's an old sabre, passed down for generations. A tacky leather "+
  "strip has been wound around the handle to provide a grip. There is a "+
  "luminescent blue gem in the handle, reminding you of the ocean. The blade "+
  "has been honed to a fine edge.\n");
  set_name("sabre");
  set_wtype("sabre");
  set_material("steel");
  set_quality(30);
  add_magic_property("damage",1);
  add_magic_property("dexterity",1);
  add_magic_property("speed",1);
  weapon_setup();

}