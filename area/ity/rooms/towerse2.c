#include <mudlib.h>

inherit ROOM;

int spider_spawned = 0;

void extra_create()
{
  set_short( "Southeastern tower in the Bastion, second floor" );
  set_long(wrap("This is the second floor of the southeasten tower. There is "+
  "a narrow landing of sorts, with a small alclove cut into the interior "+
  "rock. A stone bench rests there for weary travellers to catch their "+
  "breath. As with the first floor, a window has been bored into the southern "+
  "tower wall; however, this one has an iron grill set into it, likely to "+
  "prevent people or things from falling out. There is a large spiderweb "+
  "that stretches all the way down from the ceiling, mostly obscuring further "+
  "movement upwards. You would have to agitate the web if you wanted to "+
  "get past...\n"));
  set_item_desc(([
  ({"small alclove", "alclove"}) : "A small space has been carved out of the "+
  "interior rock wall. A stone bench is set into the space, but otherwise "+
  "it is quite barren. You marvel at the smoothness of the alclove walls; "+
  "it looks like they were formed naturally, rather than chipped out by "+
  "hand and tool.\n",
  ({"stone bench", "bench"}) : "Three simple slabs of stone with iron bolts "+
  "holding them together. It doesn't look terribly comfortable, but a tired "+
  "traveller probably wouldn't care.\n",
  ({"iron bolt", "iron bolts", "iron grill", "grill"}) : "As with the front "+
  "doors of the Bastion, the iron parts here have rusted badly. The bolts "+
  "holding the bench together and the grill over the window would probably "+
  "break easily without much effort, though you can see no point in doing "+
  "so.\n",
  ({"large spiderweb", "spiderweb", "web"}): "A very large spiderweb blocks "+
  "the stairs leading upwards from here. You cannot see where the top of the "+
  "web might lead off; there could be something hiding up there, or maybe "+
  "not. The only way to tell would be to attempt to pass through, which "+
  "would surely alert anything to your presence.\n"]));
  set_sounds(200 + random(10), ({ 
  "A few strands of spider silk drift off the web and cling to you.\n"}) );
  set_pre_exit_function( ([ "up" : "spider_func" ]));  
  set_exits(([
  "down" : "/u/a/allanon/area/ity/rooms/towerse1.c",
  "up" : "/u/a/allanon/area/ity/rooms/towerse3.c"]));
}

int spider_func()
{ 
  object spider;
  if(spider_spawned == 0)
  {
    message("info","You attempt to break through the web, but a sudden "+
    "skittering noise catches your attention. Suddenly, a GIANT spider "+
    "comes rushing down the web, baring its mandibles at you angrily!\n",
    this_player());
    message("info",""+this_player()->query_cap_name()+" attempts to break "+
    "through the web, but suddenly stops. You hear a skittering noise, and "+
    "suddenly a GIANT spider comes rushing down the web, baring its "+
    "mandibles at you angrily!\n",this_object(),this_player());
    spider = new("/u/a/allanon/area/ity/mon/spider_guard.c");
    spider->move(this_object(),1);
    spider->kill_ob(this_player());
    spider_spawned = 1;
    return 1;
  }
  else if(present("spider_guard"))
  {
    message("info","The giant spider blocks your path!\n",this_player());
    return 1;
  }
  else
  {
    message("movement","You struggle through the web, vibrating the strands "+
    "crazily, but nothing comes down to attack you.\n",this_player());
    message("movement",""+this_player()->query_cap_name()+"	struggles through "+
    "the web, agitating the strands wildly, but nothing comes down to attack "+
    ""+objective(this_player())+".\n",this_object(),this_player());
    return 0;  
  }
}