#include <mudlib.h>
#include "get_me_a_shrubbery.h"

inherit ROOM;

int clean_up(int inh) { return 1; }
void reset() { return; }

#define LOCATION "/u/a/allanon/area/ity/rooms/towersw1.c"

int roped = 1;

int query_roped()
{
  return roped;	
}

int tie_command(string cmd)
{
  if(cmd == "rope onto beam")
  {
    object rope = get_me_a_shrubbery("/std/riding/obj/rope",this_player());
    if (rope)
    {
      if (!this_player()->query_battleob()) 
      { 
	    if(roped == 0)
	    {
          message("info","You take your rope and loop it over the beam, "+
          "leaving the ends to trail down into the room below.\n",
          this_player());
          message("info",""+this_player()->query_cap_name()+" takes "+
          ""+possessive(this_player())+" rope and loops it over the beam, "+
          "leaving the ends to trail down into the room below.\n",
          this_object(),this_player());
          add_exit("rope", "/u/a/allanon/area/ity/rooms/towersw1.c");        
          set_long(wrap("You have climbed up to the narrow ledge that "+
          "constitutes the second 'floor' of this tower. Calling it a floor "+
          "is really a joke, though...you are balanced precariously on little "+
          "more than 50 centimeters of crumbling stone. The wooden beam looks "+
          "like it was placed here delibarately, as it is not connected to "+
          "anything else and is simply bolted to the wall. Thankfully, the "+
          "staircase is intact on this level, and you could climb up without "+
          "much hassle.\n"+
          "A rope looped over the beam hangs down to the floor below.\n"));
          add_item(({"rope"}), "A rope is looped over the beam. The ends "+
          "are tied together. You could grab the rope and take it with you, "+
          "if you wanted to...\n");
          roped = 1;
          if(!LOCATION->query_roped())
          {
            LOCATION->add_rope();
          }
          rope->remove();
        }
        else
        {
	      message("info","There is already a rope tied to the beam.\n",
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
      message("info", "You have no suitable rope to tie!\n", this_player());
    }
    return 1;
  }
  return notify_fail("Tie what onto what?\n");
}  

int grab_command(string cmd)
{
  object rope;
  if(cmd == "rope")
  {
    if (!this_player()->query_battleob()) 
    { 
      message("info","You grab the rope and take it with you.\n",this_player());
      message("info",""+this_player()->query_cap_name()+" grabs the rope and "+
      "takes it with "+objective(this_player())+".\n",this_object(),
      this_player());
      rope = new("/std/riding/obj/rope.c");
      rope->move(this_player(),1);
      remove_exit("rope");
      LOCATION->remove_rope();
      set_long(wrap("You have climbed up to the narrow ledge that constitutes "+
      "the second 'floor' of this tower. Calling it a floor is really a joke, "+
      "though...you are balanced precariously on little more than 50 "+
      "centimeters of crumbling stone. The wooden beam looks like it was "+
      "placed here delibarately, as it is not connected to anything else and "+
      "is simply bolted to the wall. Thankfully, the staircase is intact on "+
      "this level, and you could climb up without much hassle.\n"+
      "The rope is missing; you could tie one onto the beam.\n"));
      remove_item(({"rope"}));
      roped = 0;
    } 
    else 
    {
      message("info", "You are too busy fighting to do that!\n",this_player());   
    }
    return 1;
  } 
}  

void extra_init() 
{ 
  add_action("grab_command", "grab");
  add_action("tie_command", "tie");
} 

void extra_create()
{
  seteuid( getuid() );
  set_short( "Southeastern tower in the Bastion, second floor" );
  set_long(wrap("You have climbed up to the narrow ledge that constitutes "+
  "the second 'floor' of this tower. Calling it a floor is really a joke, "+
  "though...you are balanced precariously on little more than 50 centimeters "+
  "of crumbling stone. The wooden beam looks like it was placed here "+
  "delibarately, as it is not connected to anything else and is simply "+
  "bolted to the wall. Thankfully, the staircase is intact on this level, "+
  "and you could climb up without much hassle.\n"+
  "A rope looped over the beam hangs down to the floor below.\n"));
  set_item_desc(([
  ({"staircase", "railing"}) : "The staircase is intact here, and you can see "+
  "that it is indeed made with rich wood, perhaps oak or mahogany. The "+
  "railing provides some comfort, since you could catch it if you were about "+
  "to fall.\n",
  ({"ledge", "narrow ledge", "crumbling stone", "stone"}) : "Bits and pieces "+
  "of the floor continue to fall down to the first floor as you watch. This "+
  "ledge won't last forever...\n",
  ({"wooden beam", "beam", "wall", "bolts"}) : "Hmm, very strange indeed. "+
  "The wooden beam is about half a meter thick, and it looks quite new - "+
  "there is no mold damage. The bolts that secure it to the wall are made "+
  "with titanium, not the iron that seems to occupy the rest of the Bastion. "+
  "You have a sneaking suspicion that someone deliberately sabotaged the "+
  "second floor after placing this beam here.\n"]));
  add_item(({"rope"}), "A rope is looped over the beam. The ends "+
  "are tied together. You could grab the rope and take it with you, "+
  "if you wanted to...\n");
  set_sounds(100 + random(45), ({ 
  "You struggle nervously to keep your balance on the narrow ledge.\n"}) ); 
  set_exit_msg( ([ "rope" : "$N climbs down the rope."]) );
  set_exits(([
  "up" : "/u/a/allanon/area/ity/rooms/towersw3.c",
  "rope" : "/u/a/allanon/area/ity/rooms/towersw1.c"]));
  ::reset();
}

void add_rope()
{
  message("info","Someone on the floor below throws up a new rope.\n",
  this_object());
  add_exit("rope", "/u/a/allanon/area/ity/rooms/towersw1.c");        
  set_long(wrap("You have climbed up to the narrow ledge that constitutes "+
  "the second 'floor' of this tower. Calling it a floor is really a joke, "+
  "though...you are balanced precariously on little more than 50 centimeters "+
  "of crumbling stone. The wooden beam looks like it was placed here "+
  "delibarately, as it is not connected to anything else and is simply "+
  "bolted to the wall. Thankfully, the staircase is intact on this level, "+
  "and you could climb up without much hassle.\n"+
  "A rope looped over the beam hangs down to the floor below.\n"));
  add_item(({"rope"}), "A rope is looped over the beam. The ends "+
  "are tied together. You could grab the rope and take it with you, "+
  "if you wanted to...\n");
  roped = 1;
}