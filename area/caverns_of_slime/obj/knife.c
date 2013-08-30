#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("short bone knife");
  set_id(({"bone knife", "knife"}));
  set_long("The blade may be made of bone, but it looks as sharp as any metal "+
  "knife you have seem. It cuts with ease through even tough leather. Aside "+
  "from its unusual sharpness, you can find nothing out of the ordinary with "+
  "this weapon. A single rune graces the hilt.\n");
  set_name("knife");
  set_wtype("knife");
  set_material("bone");
  set_quality(25);
  add_magic_property("skill leatherworking",2);
  weapon_setup();

}