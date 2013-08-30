#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Janitor of the Void");
  set_long(wrap("This monster cleans up all the litter people dump in the "+
  "Void.\n"));
  set_name("janitor");
  set_id(({"janitor"}));
  set_level(50);
  set_race("human");
  set_stat("size",150);
  set_autopickup(1);
}

void autopickup(object ob)
{
  ob->remove();
}