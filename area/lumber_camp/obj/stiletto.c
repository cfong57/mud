#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Fine crystal stiletto");
  set_id(({"fine crystal stiletto", "fine stiletto", "crystal stiletto",
  "stiletto", "shortsword", "crystal shortsword", "key"}));
  set_long(wrap("A fine blade made out of crystal. It's about the same length "+
  "as a shortsword, but even thinner and lighter than a dagger. Thin steel "+
  "quillions protect the wielder's hand while stabbing. The handle is "+
  "carefully wrapped with leather strips to ensure a firm grip. A decorative, "+
  "ambiguous gem has been set into the pommel. The tip is deadly sharp and "+
  "it's a quite potent, if somewhat small, weapon.\n"));
  set_name("stiletto");
  set_wtype("shortsword");
  set_material("crystal");
  set_quality(70);
  weapon_setup();
}