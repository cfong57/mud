#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Crackling executioner's sword");
  set_id(({"crackling executioner's sword","executioner's sword","sword"}));
  set_long(wrap("This long, straight blade is wickedly sharp. It crackles "+
  "with electrical energy, which runs in arcs up and down its length. The "+
  "crossbar is perfectly horizontal to the blade, forming a cross; the handle "+
  "extends straight out from the blade, and is wrapped with tacky leather to "+
  "provide a better grip. Actually, if not for the lightning, you'd say the "+
  "sword looks rather plain.\n"));
  set_name("executioner's sword");
  set_wtype("executioner's sword");
  set_material("fine steel");
  set_quality(40);
  add_magic_property("lightning damage",3);
  add_magic_property("dexterity",2);
  weapon_setup();
}