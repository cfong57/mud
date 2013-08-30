#include <mudlib.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short( "Standing before a massive tree" );
  set_long(wrap("Before you is a massive tree. It is easily over 5 meters "+
  "in diameter and several times as tall. You wonder what sort of "+
  "fast-growing tree it is, because surely, no ordinary tree could have grown "+
  "to this size. Then again, maybe this exceptional specimen existed before "+
  "the Ice, in which case it is truly a mighty tree. You sense a strong aura "+
  "of life around it, more powerful than any magic you have ever felt "+
  "before.\n"));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/lumber_camp/mon/treants.c");
  set_item_desc(([
  ({"massive tree", "tree"}) : "The tree is absolutely huge, ancient beyond "+
  "reckoning. Strangely its bark, branches, roots, and leaves show no sign "
  "whatsoever of old age - it might as well have grown yesterday. Perhaps the "+
  "tree's life-force is so strong that it has the power to regenerate "+
  "itself.\n",
  "foliage" : "All of the leaves and branches of the surrounding trees seem "+
  "to be 'pointing' towards the massive tree, as if in reverance.\n",
  ({"bark", "branches", "roots", "leaves"}) : "The tree is in a prime state "+
  "of health, showing no signs whatsoever of age or decay.\n"]));  
  set_sounds(112 + random(31), ({ 
  "You can feel strong magic coming from the tree, like a gentle but strong "+
  "wave in your subconscious.\n"}) ); 
  set_exits(([
  "enter" : "/u/a/allanon/area/lumber_camp/rooms/in_tree.c",
  "east" : "/u/a/allanon/area/lumber_camp/rooms/f4.c",
  "northeast" : "/u/a/allanon/area/lumber_camp/rooms/f3.c"]));
  set_exit_msg( ([ "enter" : "$N enters the tree." ]) ); 
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
