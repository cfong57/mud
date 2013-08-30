#include <mudlib.h>
#include <move.h>

inherit ROOM;

#define DINING "/u/a/allanon/area/ity/rooms/dining.c"

int stand_command(string cmd)
{
  if(!cmd)
  {
    message("info","You stand up and leave the main table.\n",this_player());
    message("info",""+this_player()->query_cap_name()+" stands and leaves "+
    "the main table.\n",this_object(),this_player());
    this_player()->move(DINING, 1);
    return 1;
  }
}

int signal_command(string cmd)
{
  object waiter;
  if(cmd == "waiter" || cmd == "a waiter")
  {
    if(present("waiter_id",this_object()))
    {
	  message("info","But there is already a waiter here.\n",this_player());  
    }
    else
    {
	  message("info","Not knowing exactly what to do, you sort of look "+
	  "around helplessly, before a ghostly waiter suddenly appears at the "+
	  "table and bows to you.\n",this_player());
	  message("info",""+this_player()->query_cap_name()+" looks around a bit "+
	  "confusedly, but suddenly a ghostly waiter appears at the table and "+
	  "bows to "+objective(this_player())+".\n",this_object(),this_player());
	  waiter = new("/u/a/allanon/area/ity/mon/waiter.c");
	  waiter->move(this_object(),1);
	  waiter->force_me("say May I assist you, "+
	  ""+this_player()->query_cap_name()+"?");
    }
    return 1;
  }
  else
  {
    return notify_fail("You could try to signal a waiter.\n");	  
  }	
}

void extra_init()
{
  add_action("stand_command","stand");
  add_action("signal_command","signal");
}

void extra_create()
{
  set_short( "Sitting at the main table, Bastion's dining room" );
  set_long(wrap("You are sitting at the main table in the Bastion's dining "+
  "room. The table is even grander up close, and you find yourself mentally "+
  "comparing it to every other table you have ever sat at. You remember that "+
  "you can signal a waiter whenever you're ready to order.\nStand to leave "+
  "the table.\n"));
  set_safe_room(1);
}