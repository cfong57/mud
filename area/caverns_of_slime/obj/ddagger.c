#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("brilliantly shining diamond dagger");
  set_id(({"brilliantly shining diamond dagger", "brilliantly shining dagger",
  "shining diamond dagger", "shining dagger", "diamond dagger", "dagger"}));
  set_long(wrap("This dagger seems to have been recently reforged from several "+
  "shards of diamond, but the quality is so exquisite that you can detect no "+
  "telltale signs of damage. The light reflects in arcs of luminescence off the "+
  "diamond blade, giving it an aura of brilliance. The blade has been honed to "+
  "deadly sharpness, and the tip is finer than that of a pin.\n"));
  set_name("dagger");
  set_wtype("dagger");
  set_material("diamond");
  set_quality(15);

  add_magic_property("speed",1);

  set_cost_modifier(0.3);
  weapon_setup();
}