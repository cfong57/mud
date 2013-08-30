#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Ghostly servant, quietly cleaning up");
  set_long(wrap("This ghost bustles around the servant's quarters, sweeping a "+
  "little here, dusting a little there, and picking up any errant objects "+
  "that people could trip on. While its cleaning implements seem to be "+
  "incorporeal, they do a good enough job of interacting with the very real "+
  "dust and dirt that covers this room. The servant pays you no heed; whether "+
  "it can't sense you at all or it is actively ignoring you is anyone's "+
  "guess.\n"));
  set_name("Ghostly servant");
  set_id(({ "ghostly servant", "servant", "ghost", "human", "undead"}));
  set_level(15);
  set_race("human");
  set_species("undead");
  set_gender("neuter");
  set_autopickup(1);
  set_following(0);
}