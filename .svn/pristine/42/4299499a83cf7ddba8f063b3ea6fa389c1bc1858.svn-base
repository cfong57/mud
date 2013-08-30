#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("wicked black scimitar");
  set_id(({"wicked black scimitar","black scimitar","scimitar"}));
  set_long(wrap("This curved sword has a pure black blade. A simple crossguard"+
  "adorned with an old elven family crest protects the wielder's hands. There "+
  "is an evil-looking blood ruby embedded in the handle that seems to be "+
  "giving off some psychic emations and a distinct smell of poison is easily "+
  "detectable from the blade... best to be cautious with it.\n"));
  set_name("scimitar");
  set_wtype("scimitar");
  set_material("steel");
  set_quality(10);
  add_magic_property("psionic damage",1);
  add_magic_property("poison damage",1);
  weapon_setup();
}