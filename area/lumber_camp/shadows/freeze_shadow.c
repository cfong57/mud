#include <mudlib.h> 

inherit SHADOW; 

int time = 10 + random(10);

int start_me()
{
  call_out("check_status", 0);
  call_out("timer_func", 0);    
}

int check_status()
{
  if (!shadowed_object()) { 
    destruct(this_object());
  } 
  if (shadowed_object()->query_dead()) {
    destruct(this_object()); 
  }
  call_out("check_status", 5);
}

int query_time() 
{
  return time;
}

int timer_func()
{
  if (time < 5) {
    call_out("thaw_me", 0);      
  } else {
    time = query_time() - 3 - random(8);
  }
  call_out("timer_func", 1 + random(3));
}

int query_immobile() 
{
  return 1;
} 

int block_attack() 
{
  return query_time();
}

int query_frozen() 
{
  return 1;
}
 
string query_immobile_message() 
{
  return "You are frozen solid and can't move!\n";
} 

int thaw_me()
{
  remove_call_out("timer_func");
  remove_call_out("check_status");
  shadowed_object()->remove_silence_shadow();
  message("defrost", "You feel better as the ice on you melts away. You are "+
  "no longer frozen solid.\n", shadowed_object());
  message("defrost", ""+shadowed_object()->query_cap_name()+" looks better "+
  "as the ice on "+objective(shadowed_object())+" melts. "+
  ""+capitalize(subjective(shadowed_object()))+" is no longer frozen "+
  "solid.\n", environment(shadowed_object()), shadowed_object()); 
  destruct(this_object()); 
}