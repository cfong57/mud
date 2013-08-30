#include <mudlib.h>

inherit SHADOW;

int res;

int check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 
  call_out("check_status",5);
}

int adjust_physresist()
{
  res = shadowed_object()->query_resistance("physical");
  shadowed_object()->set_resistance("physical", res + 15);
}

int remove_this_shadow()
{
 shadowed_object()->set_resistance("physical", res);
 remove_call_out("check_status");
 destruct(this_object());
}