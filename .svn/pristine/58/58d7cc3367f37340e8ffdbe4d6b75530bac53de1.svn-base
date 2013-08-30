#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Corrosive executioner's sword");
  set_id(({"corrosive executioner's sword","executioner's sword","sword"}));
  set_long(wrap("This blade drips with corrosive acid. It steams as it hits "+
  "the ground, and you'd hate to see what it does to flesh. The blade itself "+
  "is perfectly straight, without any signs of curvage. There is an old "+
  "elven family crest stamped to the otherwise unadorned crossguard, and a "+
  "smallish diamond has been embedded to the hilt...or at least you think "+
  "that's what it used to be, the acid seems to have corroded it so badly "+
  "that it's hard to tell anymore.\n"));
  set_name("executioner's sword");
  set_wtype("executioner's sword");
  set_material("fine steel");
  set_quality(35);
  add_magic_property("acid damage",3);
  add_magic_property("strength",1);
  add_magic_property("constitution",1);
  weapon_setup();
}