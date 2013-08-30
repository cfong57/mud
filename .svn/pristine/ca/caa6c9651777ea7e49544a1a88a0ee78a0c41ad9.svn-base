#include <mudlib.h>
#include <move.h>

inherit MONSTER;

void extra_create()
{
  set_short("the monster that never truly dies");
  set_long(wrap("This monster respawns every time you kill it. Really.\n"));
  set_name("monster");
  set_id(({"monster"}));
  set_level(random(101));
  set_race("human");
  set_stat("size",random(1001));
}

void second_life()
{
  object monster = new("/u/a/allanon/monsters/endlessmob.c");
  monster->move(environment(this_object()),1);
  monster->kill_ob(this_object()->query_last_attacker());
}