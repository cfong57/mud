#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("tainted black scimitar");
  set_id(({"tainted black scimitar","black scimitar","scimitar"}));
  set_long(wrap("This curved sword has a pure black blade. A simple crossguard "+
  "adorned with an old elven family crest protects the wielder's hands. There "+
  "is a foul-looking emerald embedded in the handle. Occasionally the blade "+
  "bursts into flames, leaving an acrid smell of burnt metal in the air. An "+
  "aura of tainted power surrounds the weapon.\n"));
  set_name("scimitar");
  set_wtype("scimitar");
  set_material("iron");
  set_quality(10);
  add_magic_property("fire damage",1);
  set_cost_modifier(0.3);
  weapon_setup();
}