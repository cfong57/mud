#include <mudlib.h>

inherit MONSTER;

int increment_command(string cmd)
{
  if(!cmd)
  {
    object CELL = get_object("/u/a/allanon/workroom/cell.c");
    CELL->increment_counter();
    return 1; 
  }
  return notify_fail("No args.\n");
}

void extra_init()
{
  add_action("increment_command","increment");
}

void extra_create()
{
  set_short("Monster holding magic chains");
  set_long(wrap("foo.\n"));
  set_name("monster");
  set_id(({"monster"}));
  set_level(1);
  set_race("human");
  set_stat("size",random(1001));
}