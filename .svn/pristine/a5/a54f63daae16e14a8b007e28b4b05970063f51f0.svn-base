#include <mudlib.h> 

inherit SHADOW; 

void check_status()
{
  if(!shadowed_object())
  {
	remove_call_out(); 
    destruct(this_object());
  } 
  call_out("check_status", 5);
}

int extinguish_me(object extinguisher, object tool)
{
  message("info","Try as you might, the fire keeps sputtering back into "+
  "life.\n",environment(shadowed_object()));
  return 0;
  //shadowed_object()->extinguish_me(object extinguisher, object tool);
}