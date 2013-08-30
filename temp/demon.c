#include <mudlib.h>

inherit MONSTER;

int chains = 0;

int query_chains()
{
  return chains;
}

void increment_chains()
{
  chains++;
}

int foo_command(string cmd)
{
  if(!cmd)
  {
    int x;
    int y;
    mapping m = ([1 : 2, 3 : 4, 5 : 6]);
    int *k = keys(m);
    int n = sizeof(k);
    message("info","([1 : 2, 3 : 4, 5 : 6])\n",this_player());
    for(int i = 0; i < n; i++) 
    {
      x = k[i];
      y = m[x];
      printf("%i : %i\n", x, y);
    }  
    return 1;
  }
  return notify_fail("No args.\n");
}

void extra_init()
{
  add_action("foo_command","foo");	
}

void ask_spell() 
{ 
  set_script(({"say I can cast mighty spells!", 4, 
  ":Magician starts concentrating on a spell.", 10, 
  ":Magician fumbles badly and grows a six inch nose."})); 
} 

void extra_create()
{
  set_short("Asdf");
  set_long(wrap("foo.\n"));
  set_name("asdf");
  set_id(({"asdf"}));
  set_living_name("asdf");
  set_level(1);
  set_stat("size",random(1001));
}