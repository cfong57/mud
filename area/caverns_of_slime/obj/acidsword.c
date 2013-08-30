#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("brilliant purple longsword");
  set_id(({"brilliant purple longsword", "longsword", "sword"}));
  set_long(wrap("This longsword has been painted a brilliant metallic purple. "+
  "Both of its edges drip with acid. The blade narrows to a broad but sharp "+
  "point. The grip of the weapon is firm, and it feels well balanced. It looks "+
  "deadly sharp.\n"));
  set_name("longsword");
  set_wtype("longsword");
  set_material("steel");
  set_quality(10);
  add_magic_property("acid damage",2);
  weapon_setup();

}