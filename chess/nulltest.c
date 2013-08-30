#include <mudlib.h>

inherit OBJECT;

#define blah ""
#define A1 map[0]

int nulltest_command(string str)
{
  mapping map = allocate_mapping(2);
  object obj;
  obj = new("/obj/torch.c");
  map[0] = obj;
  map[1] = blah;
  if(!str)
  {
    message("info",""+identify(map)+"\n",this_player());
    message("info",""+identify(A1)+"\n",this_player());
    return 1;
  }
  return notify_fail("No args.\n");
}

void extra_init()
{
  add_action("nulltest_command", "null");
}

void extra_create()
{
  set_short("foo ob");
  set_long("foo\n");
  set_id(({"foo"}));
}