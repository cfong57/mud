#include <mudlib.h>

inherit ROOM;

int counter = 0;

int query_counter()
{
  return counter;	
}

void set_counter(int x)
{
  counter = x;	
}

void increment_counter()
{
  set_counter(query_counter() + 1);	
}

void extra_create()
{
  set_short( "A blank room" );
  set_long("Long desc.\n");
}