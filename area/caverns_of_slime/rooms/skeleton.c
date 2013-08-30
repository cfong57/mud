#include <mudlib.h>
#include <move.h>

inherit ROOM;
int skeletonsearched=0; 

void extra_create()
{
  set_short( "A room full of remains" );
  add_monster("/u/a/allanon/area/caverns_of_slime/mon/shade.c"); 
  set_long( wrap("The rancid smell of decay permeates this room. Ancient dust, most "+
  "likely from crushed bones, stirs underfoot, creating eddies and swirls. The room "+
  "is jam-packed with skeletons, corpses, cadavers, and all sorts of other macabre "+
  "remains. It makes you sick just to imagine this amount of people being killed..."+
  "suddenly the caves appear dark and foreboding. You wonder what sort of monster lives here.\n"));
  set_item_desc(([
                  ({ "skeletons", "corpses", "cadavers", "remains" }) : "A huge collection of dead bodies. "+
                  "One pure-white skeleton in particular catches your attention.\n", 
                  "dust" : "White-yellow bone powder. It's finer than sand.\n"  ]) );
  
  add_item( ({ "pure-white skeleton", "skeleton", "bones" }), 
            "You think you saw something lodged in its bones.\n"); 
            
  add_item_search( ({ "pure-white skeleton", "skeleton", "bones" }), "search_skeleton");                     
  set_light(50);
  set_water(5);  
  set_sounds(120, ({"For a second you thought you saw something curious in the pure-white skeleton.\n" }) ); 
  set_exits((["northeast" : "/u/a/allanon/area/caverns_of_slime/rooms/hole.c"]));
}

int search_skeleton()
{
  object note;

  if(skeletonsearched) 
    {
      message("info", "You search the skeleton, but you don't find "+
      "anything.\n",
              this_player());
      
      message("info", this_player()->query_cap_name()+" searches the skeleton, "+
      "but doesn't find anything.\n",
              environment(this_player()),this_player());

      return 1; 
    }

  skeletonsearched = 1;

  message("info", "You search the skeleton and find a small scrap of parchment.\n",this_player());
  message("info", this_player()->query_cap_name()+" searches the skeleton and "+
          "finds a small scrap of parchment.\n",
          environment(this_player()), this_player());

  note = new("/u/a/allanon/area/caverns_of_slime/obj/note.c");

  if(note->move(this_player()) != MOVE_OK) 
    {
      message("info", "You can't carry the note and drop it on the ground.\n",

              this_player());
      note->move(environment(this_player()));
    }

  return 1;
}
