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

void receive_message(mixed cl, mixed msg)
{
  write_file("/u/a/allanon/logs/workroom_log", ctime(time())+": "+msg+"\n");	  
}