#include <mudlib.h>
#include "get_me_a_shrubbery.h"

inherit ROOM;

int clean_up(int inh) { return 1; }
void reset() { return; }

#define LOCATION "/u/a/allanon/area/ity/rooms/towersw2.c"

int roped = 0;

int query_roped()
{
  return roped;	
}

int throw_command(string cmd)
{
  if(cmd == "rope at beam")
  {
    object rope = get_me_a_shrubbery("/std/riding/obj/rope",this_player());
    if (rope)
    {
      if (!this_player()->query_battleob()) 
      { 
	    if(roped == 0)
	    {
          message("info","After several failed attempts, you manage to launch "+
          "the end of your rope over the beam with enough slack left on both "+
          "sides to create a loop. You tie the loose ends together.\n",
          this_player());
          message("info","After several failed attempts, "+
          ""+this_player()->query_cap_name()+" manages to launch the end of "+
          ""+possessive(this_player())+" rope over an overhead beam. "+
          ""+capitalize(subjective(this_player()))+" ties the ends of the "+
          "rope together.\n",
          this_object(),this_player());
          add_exit("rope", "/u/a/allanon/area/ity/rooms/towersw2.c");        
          set_long(wrap(query_long()+
          "A rope hangs down from the floor above.\n"));
          add_item(({"rope"}), "A rope is looped over the beam on the "+
          "second floor. The ends are tied together.\n");
          roped = 1;
          if(!LOCATION->query_roped())
          {
            LOCATION->add_rope();
          }
          rope->remove();
        }
        else
        {
	      message("info","There is already a rope hanging over the beam.\n",
	      this_player());  
        }   
      } 
      else 
      {
        message("info", "You are too busy fighting to do that!\n",
        this_player());   
      }
    } 
    else 
    {
      message("info", "You don't have a suitable rope to throw!\n",
      this_player());
    }
    return 1;
  }
  return notify_fail("Usage: throw <item> at <target>\n");
}  

void extra_init() 
{ 
  add_action("throw_command", "throw");  
} 

void extra_create()
{
  seteuid( getuid() );
  set_short( "Southwestern tower in the Bastion, first floor" );
  set_long(wrap("This is the first floor of a cylindrical tower. The most "+
  "obvious feature is the wooden stairway leading to the next floor...or at "+
  "least, the remnants of it. The stairway has rotted away, and even if there "+
  "were still steps within your reach, it would be too dangerous to try "+
  "climbing them. Far overhead you can see the second floor, which looks to "+
  "be little more than a ledge jutting out of the wall. A large heap of "+
  "stones in the middle of the floor is probably the remains of the second "+
  "floor. You wonder why this section of the Bastion has collapsed; since "+
  "there are no windows in this tower, it could not have been due to the "+
  "elements. Then again, the hallway to the east is collapsed, and there is "+
  "a strong draft from the northern hallway, so who knows?\n"));
  set_item_desc(([
  ({"wooden stairway", "stairway"}) : "The stairway was probably made of "+
  "richly laquered wood at one point, but rot has consumed the greater "+
  "portion of it. There are still a few steps hanging precariously to the "+
  "ledge above, but they are out of your reach and far too dangerous to "+
  "stand on, anyway.\n",
  "steps" : "There are still a few wooden steps attached to the ledge above, "+
  "but they are liable to fall down any second. You don't want to be around "+
  "when that happens.\n",
  ({"second floor", "ledge"}) : "A ledge juts out of the wall far overhead. "+
  "It was originally much larger, but for some reason most of that level has "+
  "crumbled, forming a large heap of stones that lie uselessly in the center "+
  "of this floor. You notice one beam that extends over the edge of the "+
  "ledge.\n",
  ({"large heap of stones", "large heap", "heap of stones", "heap", "stones"}) :
  "In the middle of the floor is a large heap of stones, presumably remnants "+
  "of the second floor. There don't seem to be any signs of damage, or other "+
  "visible causes of distress, so you aren't sure why the floor collapsed. "+
  "Perhaps this tower was built by inferior workers who cut some corners; "+
  "that would also explain the stairway being made out of wood rather than "+
  "stone.\n",
  "beam" : "A wooden beam extends outwards a few meters from the second story "+
  "ledge. It seems rather incongruous, but if it is securely attached to "+
  "something...you could try to throw a rope at it, if you had one.\n"]));
  set_sounds(175 + random(5), ({ 
  "As you watch, another stone falls from the ledge above. You narrowly dodge "+
  "it as it slams into the floor.\n"}) );
  add_monster("/u/a/allanon/area/ity/mon/illial.c");
  set_exit_msg( ([ "rope" : "$N climbs up the rope."]) );
  set_exits(([
  "east" : "/u/a/allanon/area/ity/rooms/hallwaysw.c",
  "north" : "/u/a/allanon/area/ity/rooms/hallwayw.c"]));
  ::reset();
}

void remove_rope()
{
  remove_exit("rope");
  remove_item(({"rope"}));
  message("info","Someone on the ledge above pulls the rope up with them.\n",
  this_object());
  set_long(wrap("This is the first floor of a cylindrical tower. The most "+
  "obvious feature is the wooden stairway leading to the next floor...or at "+
  "least, the remnants of it. The stairway has rotted away, and even if there "+
  "were still steps within your reach, it would be too dangerous to try "+
  "climbing them. Far overhead you can see the second floor, which looks to "+
  "be little more than a ledge jutting out of the wall. A large heap of "+
  "stones in the middle of the floor is probably the remains of the second "+
  "floor. You wonder why this section of the Bastion has collapsed; since "+
  "there are no windows in this tower, it could not have been due to the "+
  "elements. Then again, the hallway to the east is collapsed, and there is "+
  "a strong draft from the northern hallway, so who knows?\n"));
  roped = 0;	
}

void add_rope()
{
  message("info","Someone on the ledge above throws down a new rope.\n",
  this_object());
  add_exit("rope", "/u/a/allanon/area/ity/rooms/towersw2.c");        
  set_long(wrap(query_long()+"A rope hangs down from the floor above.\n"));
  add_item(({"rope"}), "A rope is looped over the beam on the "+
  "second floor. The ends are tied together.\n");
  roped = 1;
}