#include <mudlib.h> 

inherit SHADOW; 

int check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 

  if(shadowed_object()->query_dead()) 
  destruct(this_object()); 

  call_out("check_status",5);
}

int special_hit(object target)
{
  if(!random(4) && target)
   {
    message("death",""+shadowed_object()->query_cap_name()+" grabs "+
    ""+target->query_cap_name()+" firmly at the neck, applying the Vulcan "+
    "Death Grip and killing "+objective(target)+" instantly!\n",
    environment(target),target);
    message("death",""+shadowed_object()->query_cap_name()+" grabs you firmly "+
    "at the neck, applying the Vulcan Death Grip and killing you instantly!\n",
    target);
    target->set_hp(-1);
    return 1;
   }
 return 1;
}