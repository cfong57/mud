#include <mudlib.h>
#include <move.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

int clean_up(int inh) 
{ 
  return 1; 
}

void reset() 
{ 
  return; 
}

int climb_command(string cmd)
{
  if ( cmd == "branches" ) {
    if (!this_player()->query_battleob()) {
      object p = this_player();
      message("info", "You start to carefully climb along the branches...but "+
      "you suddenly fall through a gap in them that you didn't see! Expecting "+
      "to fall, you close your eyes, but you seem to land on something soft. "+
      "You open your eyes and stand up.\n", p); 
      message("info", ""+p->query_cap_name()+" starts to carefully climb "+
      "along the branches...but suddenly falls through a gap among "+
      "them! You cringe, waiting to hear a *thud*, but strangely it never "+
      "comes.\n", environment(p), p);
      p->move("/u/a/allanon/area/lumber_camp/rooms/treetop_secret.c");
    } else {
      message("info", "You are too busy fighting to do that!\n", this_player());
    }
    return 1;
  }
  return notify_fail("Climb what?\n");
}  

void extra_init() 
{ 
  add_action("climb_command", "climb");  
} 

void extra_create()
{
  seteuid( getuid() );
  set_outside("F"); 
  set_outdoors("F");
  set_short( "At the top of a massive tree" );
  set_long(wrap("You're standing at the top of a massive tree. The branches "+
  "and leaves all around you form an enormous sea of green. You can literally "+
  "see for miles this high up. From here it's very easy to spot the goblin "+
  "camp to the north; the clear-cut area is like a jagged scar upon the "+
  "forest. Near the center of the tree, at the exact top and middle, lies a "+
  "large stone. It is carved in the shape of a tree, very similar to the one "+
  "you're standing in. All the magic you have felt so far stems from this "+
  "stone, and you wonder at its significance. The wooden stairway leads back "+
  "down.\n"));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/lumber_camp/mon/cichele.c");
  add_object("/u/a/allanon/area/lumber_camp/obj/stone.c");
  set_item_desc(([
  ({"branches", "leaves", "foliage"}) : "Curiously, this tree has no branches "+
  "or leaves past the top 'platform' - they all just fan out horizontally. "+
  "This makes for an essentially flat-topped tree. Oh well, you've seen "+
  "stranger.\n",
  ({"wooden stairway", "stairway"}) : "It's the stairway you climbed to get "+
  "up here.\n",
  ({"goblin camp", "camp", "jagged scar", "scar"}) : "The goblin camp to the "+
  "north is an unsettling discontinuity in the otherwise beautiful tapestry "+
  "of trees.\n",
  ({"tapestry", "sea", "trees", "green"}) : "With the exception of the goblin "+
  "camp to the north, there is nothing to see all around as far as the eye "+
  "can see, except trees and more trees.\n"]));
  add_item_search( ({ "stone", "large stone", "amber" }), "search_stone");  
  set_sounds(121 + random(17), ({ 
  "There's a quite distinct hum emanating from the stone. It is like the hum "+
  "of an insect's wings, but not quite.\n",
  "The magical presence here is so strong that you are at a loss to describe "+
  "it.\n",
  "The branches look strong enough to support your weight, but you daren't "+
  "try to climb them.\n"}) ); 
  set_exits((["stairway" : "/u/a/allanon/area/lumber_camp/rooms/platform.c"]));
  set_exit_msg( ([ "stairway" : "$N goes down the stairway." ]) );
  call_out("phase_func", 0); 
  WEATHER_D->add_phase_listener(this_object());
  ::reset();
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

void search_stone()
{
  message("search", wrap("You find a slot in the top of the stone. It looks "+
  "as if some things might be inserted, but you are not sure what.\n"),
  this_player());
  message("search", wrap(""+this_player()->query_cap_name()+" searches the "+
  "stone and seems to find something interesting.\n"),
  environment(this_player()), this_player());
}