#include <mudlib.h>
#include <daemons.h> 

inherit ROOM;

string curr_phase; 
string foliage;
string longdesc;

mixed *exit_array = ({"north", "northeast", "east", "southeast", "south", 
"southwest", "west", "northwest"});
string correct = ""+exit_array[random(sizeof(exit_array))]+"";

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short( "Lost in the woods" );
  set_long(wrap("You are in an extremely old and dense part of the forest. "+
  "Trees, bushes, ferns, and all manner of other vegetation surround you on "+
  "every side. The hole you made to came here can barely be distinguished "+
  "among the greenery, but other than that you are totally at a loss for "+
  "exits. Although the vegetation is packed tightly together, you reckon that "+
  "you could go any direction from here; you might get lucky and stumble "+
  "onto a path somewhere among the thick foliage.\n"));
  longdesc = this_object()->query_long();
  set_item_desc(([
  ({ "vegatation", "plants", "foliage", "trees", "bushes", "ferns", 
  "greenery"}) : 
  "All manner of forest plants grow thickly around here. "+
  "It would be easy to get lost among it all.\n",
  "hole" : "This is the hole you made to get to here.\n"]));  
  set_sounds(73 + random(26), ({ 
  "It is absolutely silent in this part of the forest.\n",
  "You start to feel a little claustrophobic from all of the plants "+
  "pressing at you.\n"}) ); 
  set_epcost(25);
  set_exit_msg( ([ "hole" : "$N manages to squeeze back into the hole."]) ); 
  set_pre_exit_function( ([ ""+correct+"" : "check_move" ])); 
  set_hidden_exits( ({ "north", "northeast", "east", "southeast", "south", 
  "southwest", "west", "northwest"}) );
  set_exits(([
  "hole" : "/u/a/allanon/area/lumber_camp/rooms/f4.c",
  "north"  : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "northeast": "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "east"  : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "southeast" : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "south"  : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "southwest" : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "west" : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c",
  "northwest" : "/u/a/allanon/area/lumber_camp/rooms/lostwoods.c"]));
  call_out("phase_func", 0); 
  WEATHER_D->add_phase_listener(this_object());
}

string query_correct() 
{
  return correct;
}

int check_move()
{ 
  if (!random(3)) {
    call_out("move_me", 0);
  }
  //don't permit the move, then use a function to move the player manually
  return 0;
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

void move_me()
{
  //probably a cleaner way to do this
  message("info", "You think you saw a faint trail to the "+correct+". You "+
  "follow it.\n", this_player());
  message("info", ""+this_player()->query_cap_name()+" seems to find a faint "+
  "trail, and follows it, disappearing right into the foliage.\n", 
  environment(this_player()), this_player());
  this_player()->move("/u/a/allanon/area/lumber_camp/rooms/cottage_out.c"); 
}