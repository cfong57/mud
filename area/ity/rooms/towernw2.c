#include <mudlib.h>

inherit ROOM;
inherit DOOR;

int blast_command(string str)
{
  if(str == "gate" || str == "iron gate" || str == "lock")
  {
    object potion = present("bomb potion",this_player());
    if(potion)
    {
      mapping doors = this_object()->query_doors();
      if(!doors || !sizeof(keys(doors)))
      {
        message("bug","Something has bugged in this room - couldn't find the "+
        "doors. Contact a wiz.\n",this_object());  
      }
      foreach(string dir, mapping data in doors)
      {
        if(data["short"] == "iron gate barring the stairs")
        {
          if(data["status"] == "locked")
          {
            message("info","You carefully insert the bomb potion into the "+
            "iron gate's lock. Backing away, you find a small rock and deftly "+
            "toss it at the potion. The vial cracks, and the potion suddenly "+
            "EXPLODES as the liquid inside it reacts with the air! The lock "+
            "is blown clear off the gate.\n",this_player());
	        message("info",""+this_player()->query_cap_name()+" carefully "+
	        "inserts a bomb potion into the iron gate's lock. Backing away, "+
	        ""+subjective(this_player())+" finds a small rock and deftly "+
	        "tosses it at the potion. The vial cracks, and the potion "+
	        "suddenly EXPLODES as the liquid inside it reacts with the air! "+
	        "The lock is blown clear off the gate.\n",this_object(),
	        this_player());
	        destroy_door();
	        potion->remove();
          }
          else
          {
	        message("info","But the gate is already unlocked.\n",this_player());   
          }
        }
      }	    
    }
    else
    {
      message("info","But you don't have a bomb potion.\n",this_player());
    }
    return 1;
  }
  else
  {
    return notify_fail("Blast what?\n");	  
  }	
}

void extra_init()
{
  add_action("blast_command", "blast");
}

void extra_create()
{
  set_short( "Northwestern tower of the Bastion, second floor" );
  set_long(wrap("This is the second floor of the guard tower. An iron gate "+
  "prevents anyone from going down or up the stairs. There are a few holding "+
  "cells here. Inside each cell is a bed of straw, a bucket, and a wooden "+
  "bench. Each cell is also alloted a small window to the outside, which of "+
  "course is covered by an iron grill. There are skeletons in some of the "+
  "cells, testifying that prisoners were held here once. There is an iron "+
  "ladder in the middle of the room leading to the top floor of the tower, "+
  "soldered to the floor to prevent it from moving.\n"));
  set_item_desc(([
  "cells" : "The cells are solid cubes made of iron, but they have rusted "+
  "badly. None of them even have doors anymore, except for the cell in the "+
  "northern part of the room.\n",
  ({"cell", "northern cell"}) : "This is the only cell with a functioning "+
  "door, but even it has rusted to the point of being almost useless.\n",
  ({"bed of straw", "straw", "bed", "bucket", "wooden bench", "bench"}) : 
  "The cells are outfitted with pretty typical prisoner fare.\n",
  ({"window", "small window", "iron grill", "grill"}) : "It shows a little "+
  "bit of humanity that the builders of this place at least allowed the "+
  "prisoners a view of the outside.\n",
  ({"skeleton", "skeletons"}) : "Some of the cells are occupied by skeletons, "+
  "most of them curled into a fetal position or otherwise looking as if they "+
  "were asleep. These prisoners passed away peacefully; they at least had "+
  "that much luck.\n",
  ({"iron ladder", "ladder", "floor"}) : "An iron ladder is soldered to the "+
  "floor. Curiously, unlike the cells, it has not rusted very much. The "+
  "ladder is quite sturdy and would hold a lot of weight.\n"]));
  set_sounds(200 + random(50), ({ 
  "You wonder why the northern cell is the only one with a functioning "+
  "door.\n"}) );
  set_exits(([
  "down": "/u/a/allanon/area/ity/rooms/towernw1.c",
  "ladder": "/u/a/allanon/area/ity/rooms/towernw3.c",
  "cell" : "/u/a/allanon/area/ity/rooms/cell.c"]));
  create_door("down", "up",
  (["short" : "iron gate barring the stairs",
  "long" : "A heavy iron gate bars the stairway down. Since the iron is at "+
  "least ten centimeters thick, you don't think it would be possible to break "+
  "it down.\n"+
  "There doesn't seem to be a way to open the gate from this side. However, "+
  "you note that this side of the lock looks different. It is a hollow, "+
  "cylindrical sort of shape, which somehow reminds you of a potion.\n",
  "ids" : ({ "iron gate", "gate" }),
  "status" : "locked",
  "autoclose" : 15,
  "autolock" : 1,
  "quality" : 1001,
  "material" : "iron",
  "close_msg" : "The iron gate swings shut.\n",
  "open_msg" : "You open the iron gate.\n"]) );
  create_door("cell", "out",
  (["short" : "iron cell door",
  "long" : "This thick iron door has rusted badly, and while the door itself "+
  "might hold for a while longer, the lock looks like it would fall apart "+
  "at a child's touch. You could open it with no resistance.\n",
  "ids" : ({ "iron cell door", "cell door", "iron door" }),
  "status" : "open",
  "quality" : 0,
  "material" : "iron",
  "close_msg" : "The iron cell door swings shut.\n",
  "open_msg" : "You open the iron cell door.\n"]) );
}