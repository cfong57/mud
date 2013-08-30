#include <mudlib.h>
#include <move.h>

inherit ROOM;

int clean_up(int inh) 
{ 
  return 1; 
}

void reset() 
{ 
  return; 
}

int desksearched = 0;

void extra_create()
{
  seteuid( getuid() );
  set_short( "Tent of the camp overseer" );
  set_long(wrap("You're standing inside a smallish white tent. The floor is "+
  "tidily made up, considering that it's dirt. A pile of straw in one corner "+
  "serves as a bed. There is a small desk and a matching chair, both of a "+
  "size suitable for a derro. Other than these humble furnishings, the tent "+
  "is rather bare.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/brant.c");
  set_light(200);
  set_item_desc(([
  ({"small desk", "chair", "desk"}) : "A nice mahogany desk with a matching "+
  "chair. They are small, designed for use by a derro. There are a few papers "+
  "on the desk and one of the drawers is open.\n", 
  ({ "papers on desk", "papers"}) : "Various documents detailing the status "+
  "of the camp. There's nothing here of interest to you.\n",
  ({"pile of straw", "pile", "straw", "bed"}) : "It's just a pile of straw "+
  "with a sack for a pillow and a blanket. About the most primitive bed you "+
  "can get, but pretty comfortable.\n",
  ({"sack", "pillow"}) : "A sack stuffed full of straw made to serve as a "+
  "pillow. It never needs fluffing.\n",
  "blanket" : "A simple white sheet of cloth. Keeps you warm at night.\n",
  ({"floor", "dirt", "marks", "scratch marks", "crude scratch marks"}) : 
  "There are some crude scratch marks in the dirt. Looked at from the right "+
  "angle, you think they depict a mass of goblins cutting down a tree, with "+
  "another figure off to the side watching in idle amusement.\n"]));
  add_item( ({ "drawer", "drawers" }), 
  "One of the desk drawers is open. If you were feeling naughty, you could "+
  "search it, but the owner might not like that.\n");             
  add_item_search( ({ "drawer", "drawers" }), "search_desk");            
  set_exits((["out" : "/u/a/allanon/area/lumber_camp/rooms/g3.c"]));
  set_exit_msg( ([ "out" : "$N opens the tent flap and leaves." ]) ); 
  ::reset();
}

void search_desk()
{
  if (present("Brant")) {
    message("info", "%^BOLD%^%^YELLOW%^Brant eyes you suspiciously and "+
    "says: "+this_player()->query_cap_name()+", just what do you think you're "+
    "doing searching through my desk?%^RESET%^\n", this_player());
    message("info", "%^BOLD%^%^YELLOW%^Brant eyes "+
    ""+this_player()->query_cap_name()+" suspiciously and says: "+
    ""+this_player()->query_cap_name()+", just what do you think you're "+
    "doing searching through my desk?%^RESET%^\n",
    environment(this_player()), this_player());
  } else {
    if (desksearched) {
      message("info", "You open the drawer and find, to your amazement..."+
      "absolutely nothing! It seems like someone has already searched here.\n",
      this_player());     
      message("info", this_player()->query_cap_name()+" opens the drawer and "+
      "looks surprised when "+objective(this_player())+" doesn't find "+
      "anything.\n", environment(this_player()), this_player());
    } else {
      object stiletto;
      desksearched = 1;
      message("info", "You open the drawer and find a small "+
      "blade.\n", this_player());
      message("info", this_player()->query_cap_name()+" searches the drawer "+
      "and finds a small blade.\n", environment(this_player()), this_player());
      stiletto = new("/u/a/allanon/area/lumber_camp/obj/stiletto.c");
      if (stiletto->move(this_player()) != MOVE_OK) {
        message("info", "You can't carry the blade and drop it on the "+
        "ground.\n", this_player());
        message("info", ""+this_player()->query_cap_name()+" can't carry the "+
        "blade and drops it on the ground.\n", environment(this_player()),
        this_player());
        stiletto->move(environment(this_player()));
      }
    }
  }
}