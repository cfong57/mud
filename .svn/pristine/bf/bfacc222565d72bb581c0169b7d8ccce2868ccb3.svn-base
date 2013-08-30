#include <mudlib.h>  

inherit SHADOW; 

int substitutes = 1;

int query_substituted() {return 1;} 

int query_x_times() { return substitutes + 1; }

void check_substitute_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 

  if(shadowed_object()->query_dead()) 
  destruct(this_object()); 

  call_out("check_substitute_status",5);
}

void add_substitute()
{
  substitutes++;	
}

varargs int receive_damage(int damage, int type, string slot, int precalculated)
{
  if (slot && random(2))
  //ignore area spells and some other special damages; 50% chance 
  {
    if(substitutes == 1)
    {
      message("substitute","All of "+shadowed_object()->query_cap_name()+"'s "+
      "substitutes disappear!\n",environment(shadowed_object()),
      shadowed_object());
      message("substitute","All of your substitutes disappear!\n",
      shadowed_object());
      destruct(this_object());
    }
    else
    {
      message("substitute","One of "+shadowed_object()->query_cap_name()+"'s "+
      "substitutes takes the hit for "+objective(shadowed_object())+" and "+
      "disappears.\n",environment(shadowed_object()),shadowed_object());
      message("substitute","One of your substitutes takes the hit for you and "+
      "disappears.\n",shadowed_object());
      substitutes--;
    }
  }
  else
  {
    shadowed_object()->receive_damage(damage, type, slot, precalculated);	 
  } 
}

varargs string query_short(int flag) 
{ 
  if(flag) 
    return shadowed_object()->query_short(flag); 
  else 
    return ""+query_x_times()+" times " + shadowed_object()->query_short(flag);
}