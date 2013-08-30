#include <mudlib.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

void extra_create()
{
  set_explorable(1); 
  set_outside("F"); 
  set_outdoors("F");
  set_short( "In a secluded forest glade" );
  set_long(wrap("You have stumbled into a little glade hidden away in the "+
  "dense foliage. Grass grows here, but it is curiously golden in color. "+
  "Actually, now that you look around, all the colors look strange - the sky "+
  "is purple, trees are red, and your hands are turning blue and green. You "+
  "wonder what in the world is going on before you notice the vortex in the "+
  "room. It is sending off wild, almost-destructive magical power to the "+
  "entire room...The surrounding forest seems to have enough power of its own "+
  "to contain this wild magic, but just barely. You wonder at its origin, an "+
  "intricately carved stone altar.\n"));
  longdesc = this_object()->query_long();
  add_monster("/u/a/allanon/area/lumber_camp/mon/giliwyr.c");
  set_item_desc(([
  ({"stone altar", "altar"}) : "To your surprise, this altar looks like it "+
  "is dedicated to Okka, the god of Magic, long dead.\n",
  "vortex" : "A chromatic vortex of intense magical powers. It's incredibly "+
  "strong, even blurring the light of the room and distorting colors. You "+
  "can't get a good look at it because of its constantly shifting shape.\n",
  "foliage" : "The vegetation is so thick that you momentarily can't even "+
  "find the way that you came from. The plants seem unnaturally vigorous "+
  "here; perhaps they are feeding off the magical energy.\n"]));
  set_sounds(134 + random(12), ({ 
  "The vortex sends out wild streams of pure magical energy.\n",
  "All the shifting colors are making your head spin dizzily.\n"}) ); 
  set_exits(([
  "out"  : "/u/a/allanon/area/lumber_camp/rooms/f4.c"]));
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
