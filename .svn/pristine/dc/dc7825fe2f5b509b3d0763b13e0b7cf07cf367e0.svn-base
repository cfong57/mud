#include <mudlib.h>
#include <move.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

int bushwhack_command(string cmd)
{
  if ( cmd == "southeast" ) {
    if (!this_player()->query_battleob()) {
      //no check for ep. let players exhaust themselves to death if they want.  
      object p = this_player();
      message("info", "You start chopping down the vegetation like someone "+
      "possessed, tryig to reach southeast.\n", p);
      message("info", "You feel exhausted from the effort.\n", p);
      p->set_ep(p->query_ep() - 25); 
      message("info", ""+p->query_cap_name()+" starts to hack at the "+
      "vegetation, attempting to get somewhere.\n", environment(p), p);
      if (!random(3)) {
        message("info", "You eventually succeed, and tumble headlong into "+
        "the small hole you briefly manage to carve into the impenetrable "+
        "green wall of plants!\n", p);
        message("info", ""+p->query_cap_name()+" finally manages to make a "+
        "hole big enough to crawl through, and jumps in before the forest "+
        "closes around the anomaly!\n", environment(p), p);
        p->move("/u/a/allanon/area/lumber_camp/rooms/lostwoods.c");
      } else {
        message("info", "No matter how hard you try, you just can't seem to "+
        "clear a hole before the gap is stuffed full of more plants.\n", p);
        message("info", ""+p->query_cap_name()+" tries and tries, but just "+
        "can't seem to clear a path.\n", environment(p), p); 
      }
    } else {
      message("info", "You are too busy fighting to do that!\n", this_player());  
    }
    return 1;
  }
  return notify_fail("Bushwhack in which direction?\n");
}  

void extra_init() 
{ 
  add_action("bushwhack_command", "bushwhack");  
} 

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short( "Deep in a forest, next to a small spring" );
  set_long(wrap("You are in the furthest part of the forest. There is almost "+
  "no wildlife here; instead, plants rule supreme. The vegetation is so think "+
  "that you doubt a team of trained gardeners could cut it all down. Because "+
  "of the heavy amount of plants, the air here is quite rich with oxygen, and "+
  "has a pleasant foresty smell to it. A small spring bubbles out of the "+
  "ground here into a low stone basin. Somehow (you suspect magic), the water "+
  "never quite overflows the lip of the basin. It would appear to be an "+
  "ancient relic.\n"));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/lumber_camp/mon/treants.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/animals.c");
  add_object("/u/a/allanon/area/lumber_camp/obj/basin.c");
  set_item_desc(([
  ({"plants", "vegetation", "foliage", "forest", "wall", "green"}) : "All "+
  "manner of forest plants grow thickly in this area of the forest. It's "+
  "almost like a green wall.\n"]));  
  set_sounds(115 + random(25), ({ 
  "The spring bubbles quietly.\n",
  "You inhale deeply, appreciating the excellent air quality.\n",
  "The curious spring makes you wonder if you can go somewhere.\n",
  "You catch a whiff of smoke on the air. It seems to be coming "+
  "through the vegetation to the southeast of here. Maybe you could "+
  "bushwhack your way through?\n"}) ); 
  set_hidden_exits( ({ "somewhere" }) );
  set_exits(([
  "north" : "/u/a/allanon/area/lumber_camp/rooms/f3.c",
  "west" : "/u/a/allanon/area/lumber_camp/rooms/tree_entrance.c",
  "somewhere" : "/u/a/allanon/area/lumber_camp/rooms/fsecret.c"]));
  set_exit_msg(([ "somewhere" : "$N flails through the vegetation, leaving to "+
  "some direction." ])); 
  call_out("phase_func", 0); 
  WEATHER_D->add_phase_listener(this_object());
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
