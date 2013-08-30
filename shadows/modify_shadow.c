#include <mudlib.h>  

inherit SHADOW;

void check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 

  if(shadowed_object()->query_dead()) 
  destruct(this_object()); 

  call_out("check_status",5);
}

varargs int receive_damage(int damage, int type, string slot, int precalculated)
{
  shadowed_object()->force_me("say Received damage of type number "+type+"");
  shadowed_object()->receive_damage(damage, type, slot, precalculated);	 
}