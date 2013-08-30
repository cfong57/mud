#include <mudlib.h>
#include <move.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

int flowers = 25 + random(15); 

int query_flowers() 
{ 
  return flowers; 
}

int pick_command(string cmd)
{
  if ( cmd == "flower" ) {
    if (flowers == 0) {
      message("info", "The flower patch looks like it has suffered enough "+
      "damage already. You decide to let a few more grow back before you "+
      "pick them.\n", this_player());
      message("info", ""+this_player()->query_cap_name()+" eyes the flower "+
      "patch, but seems to think twice about picking one.\n",
      environment(this_player()), this_player());
    } else {
      object p = this_player();
      object flower;
      message("info", "You bend down and pick a beautiful flower.\n", p); 
      message("info", ""+p->query_cap_name()+" bends down and picks a "+
      "beautiful flower.\n", environment(p), p);
      flower = new("/u/a/allanon/area/lumber_camp/obj/flower.c");
      flower->move(p, 1); //force the move, these are tiny
      flowers--; 
    }
    return 1;
  }
  return notify_fail("Pick what?\n");
}  

void extra_init() 
{ 
  add_action("pick_command", "pick");  
} 

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short( "In a deep forest, next to a flower patch" );
  set_long(wrap("You're walking in a deep, flourishing forest. There is "+
  "abundant wildlife, dense vegetation, and an overall feeling of peace and "+
  "calmness. A small patch of flowers has established itself here, "+
  "you think it looks very beautiful. Perhaps you could pick one?\n"));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/lumber_camp/mon/treants.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/animals.c");
  set_item_desc(([
  ({"abundant wildlife", "wildlife"}) : "Deer, rabbits, owls, and other "+
  "animals of the forest can be easily spotted here. You would never even "+
  "think of killing such happy, carefree creatures.\n", 
  ({"dense vegatation", "vegatation", "foliage", "forest"}) : "It's nice to "+
  "see some plants after the utter desolation of the battleground. They are "+
  "an eternal symbol of life and vitality.\n",
  ({"small patch of flowers", "patch of flowers", "flowers"}) : "A small "+
  "patch of flowers growing here in the forest. They are very beautiful and "+
  "you think you should pick a few.\n"]));  
  set_sounds(100 + random(34), ({ 
  "The flower patch makes this place bright and cheerful.\n"}) ); 
  set_exits(([
  "west"  : "/u/a/allanon/area/lumber_camp/rooms/f1.c",
  "south"  : "/u/a/allanon/area/lumber_camp/rooms/f3.c"]));
  call_out("grow_flowers", 300);
  call_out("phase_func", 0); 
  WEATHER_D->add_phase_listener(this_object());
}

void grow_flowers()
{
  if (flowers < 10) {
  //don't want to end up with a million flowers
    message("info", "A few more flowers magically spring up in the flower "+
    "patch.\n", this_object());
    flowers = query_flowers() + 3 + random(4);
  }
  call_out("grow_flowers", 300);    
}

void phase_func()
{
  curr_phase = GOD_D->query_current_phase();
  switch (curr_phase)
  {
    case "fire":
    foliage = "The foliage around you is a brilliant %^RED%^red%^RESET%^.\n";
    break;
    case "air":
    foliage = "The foliage around you is a shimmering %^CYAN%^cyan%^RESET%^.\n";
    break;
    case "water":
    foliage = "The foliage around you is a rippling %^BLUE%^blue%^RESET%^.\n";
    break;
    case "earth":
    foliage = "The foliage around you is a solid %^ORANGE%^brown%^RESET%^.\n";
    break;
    case "magic":
    foliage = "The foliage around you %^BOLD%^wavers%^RESET%^ mysteriously.\n";
    break;
  }	
  set_long(wrap(longdesc + foliage));
}

void phase_changed(mapping map)
{ 
  call_out("phase_func", 0);
} 