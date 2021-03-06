/* Thanks to Ginjeet for the code for creating a hole.
note - room doesn't reset - otherwise generates multiple rings in one hole  */

#include <mudlib.h> 
#include <daemons.h> 

inherit ROOM;
inherit DOOR;

int clean_up(int inh) 
{ 
  return 1; 
}

void reset() 
{ 
  return; 
}

#define HOLE "/u/c/cantil/std/hole.c" 

void extra_create()
{ 
  set_no_teleport(1); 
  set_short( "Cellaria's dungeon, the storage room" );
  set_long(wrap("This is the storage room of the dungeon. Various crates and "+
  "boxes are scattered around on shelves, and there is a big heap of broken "+
  "alchemical equipment in a corner. Other than that, the room is barren, and "+
  "it doesn't look like anything valuable was left behind. There is a "+
  "constant drip-drip of moisture from the ceiling: water leaks down from "+
  "above, forming a tiny pool on the dirt floor that sinks into the soil "+
  "as quickly as it forms. In one corner of the ceiling, there is a tiny gap "+
  "to the surface between some tree roots, and a thin beam of light "+
  "from outside penetrates the gloom. To the south, the iron cell door leads "+
  "out.\n"));
  set_outside("F"); 
  set_outdoors("F");
  set_item_desc(([
  ({"crates", "boxes", "shelves", "heap"}) : "What a lot of junk. Half of "+
  "the stuff you don't even know what it is, and the other half seems to "+
  "be broken beyond any possibility of repair. You wonder why anyone would "+
  "go to the trouble of locking things like this away. Or maybe you just "+
  "can't appreciate its value; one man's junk is another man's treasure, or "+
  "so the human saying goes.\n", 
  ({"moisture", "ceiling"}) : "You remember passing a small stream earlier "+
  "when going through the forest. Maybe you are underneath it. Eventually "+
  "it would probably break through and flood these underground chambers, but "+
  "for now only the inevitable dripping of water can count the time until "+
  "that happens.\n",
  ({"corner", "gap", "tiny gap", "surface", "tree roots", "roots", "thin beam",
  "beam", "beam of light", "light", "outside", "gloom"}) : "A clever "+
  "architectural trick indeed, to give light to this dim room without the "+
  "need for torches or the like. You question the wisdom of doing it so close "+
  "to the water, though - even a tiny variation of the stream's flow and "+
  "this room would instantly cave in.\n"])); 
  add_item(({"tiny pool", "water", "pool", "soil"}), "The tiny pool of water "+
  "on the floor reminds you that you are on top of dirt, not bedrock. If "+
  "water can seep through this quickly, the soil must be pretty soft.\n");
  add_item_search( ({ "tiny pool", "water", "pool", "soil" }), 
  "search_ground");           
  set_exits((["south" : 
  "/u/a/allanon/area/lumber_camp/rooms/dungeon_north.c"]));
  create_door("south", "north",
  (["short" : "iron cell door",
  "long" : "The cell door is made of solid iron. It is perfectly fitted to "+
  "the dirt walls. Peering through the bars, you estimate it to be at "+
  "least 30 centimeters thick - no one is going to be breaking it down.\n",
  "key" : "/u/a/allanon/area/lumber_camp/obj/stiletto.c",
  "status" : "locked",
  "ids" : ({ "door", "iron door", "iron cell door", "cell door" }),
  "autoclose" : 5,
  "autolock" : 1,
  "quality" : 1001,
  "material" : "iron",
  "close_msg" : "The iron cell door swings shut.\n",
  "open_msg" : "You open the iron cell door.\n"  ]) ); 
  call_out("make_hole", 0);
  ::reset();
}

int query_temperature() 
{ 
  return 15; 
}

int make_hole(object who) 
{ 
  object ring = new("/u/a/allanon/area/lumber_camp/obj/old_ring"); 
  // Get the old hole if it exists. 
  object hole = HOLE_D->query_hole(file_name(this_object())); 
  if (!hole) { 
    // There's not a hole here yet; create it. 
    hole = new(HOLE); 
  } 
  ring->move(hole); 
  HOLE_D->add_hole(file_name(this_object()), hole); 
} 

void search_ground()
{
  message("search", "You notice signs of digging on the "+
  "ground.\n", this_player());
  message("search", ""+this_player()->query_cap_name()+" searches the ground "+
  "intently and seems to notice something interesting.\n",
  environment(this_player()), this_player());
}