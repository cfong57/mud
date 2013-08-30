#include <mudlib.h> 

inherit SHADOW; 

int time = 7200; //one Icesus day or two real life hours
int weapons = 0;
int containers = 0;
int potions = 0;

void set_time(int x)
{
  time = x;	
}

int query_timer_shadow()
{
  return 1;	
}

void increment_weapons()
{
  weapons++;	
}

void increment_containers()
{
  containers++;	
}

void increment_potions()
{
  potions++;	
}

int query_containers()
{
  return containers;	
}

int query_weapons()
{
  return weapons;	
}

int query_potions()
{
  return potions;	
}

void check_status()
{
  if (!shadowed_object()) {
	remove_call_out(); 
    destruct(this_object());
  } 
  if (shadowed_object()->query_dead()) {
	remove_call_out();
    destruct(this_object()); 
  }
  call_out("check_status", 5);
}

int query_time()
{
  return time;	
}

void timer_func()
{
  if (time <= 0) {
	remove_call_out();
    destruct(this_object());      
  } else {
    time--;
  }
  call_out("timer_func", 1);
}

void start_me()
{
  check_status();
  timer_func();   
}