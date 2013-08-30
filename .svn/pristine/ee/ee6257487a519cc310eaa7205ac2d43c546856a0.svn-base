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

int query_immobile() { return 1; }  
string query_immobile_message() {return "You are frozen to the spot and can't move!\n";} 

int unblock_me()
{
  	destruct(this_object()); 
}