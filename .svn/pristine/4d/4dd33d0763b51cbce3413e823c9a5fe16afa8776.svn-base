#include <mudlib.h>
#include <dynamic.h>
#include <daemons.h>
#include "../area.h"

inherit ROOM;

mixed *exit_array = ({"north", "northeast", "east", "southeast", "south",
"southwest", "west", "northwest", "up", "down"});

string correct = ""+exit_array[random(sizeof(exit_array))]+"";

void adjust_light() {
 if (WEATHER_D->query_is_night()) {
        set_light( (: query_ambient_light :) );
 } else {
   set_light(-515);
 }
}

void extra_create()
{
 set_short(dynamic("{daytime?Dark:Glowing} crevice of ice and rock"));
 set_long(dynamic("{wrap}{daytime?Everything is hidden in shadows, "+
 "the massive chunks of ice and rock towering above you, cutting off all "+
 "sight of the sky.:This is a tight crevice between massive chunks of ice"+
 "and rock, and there is barely enough room to walk.\n" +
   "    A strange, soft blue glow seems to eminate from everything.}\n"));

 set_pre_exit_function ( ([ ""+correct+"" : "check_move"]));

 add_exit ("north", ROOM_PATH + "maze_21");
 add_exit ("south", ROOM_PATH + "maze_21");
 add_exit ("northeast", ROOM_PATH + "maze_21");
 add_exit ("southwest", ROOM_PATH + "maze_21");
 add_exit ("southeast", ROOM_PATH + "maze_21");
 add_exit ("northwest", ROOM_PATH + "maze_21");
 add_exit ("east", ROOM_PATH + "maze_21");
 add_exit ("west", ROOM_PATH + "maze_21");
 add_exit ("down", ROOM_PATH + "maze_21");
 add_exit ("up", ROOM_PATH + "maze_1");

            
 set_chat_delay(350);

 add_chat_output (dynamic("{wrap}{daytime?The darkness is "+
 "opressive:A cool blue glow permeates the area, and seems "+
 "to infuse you with the peace, even in "+
     "this tight space\n.}"));
 
   adjust_light();
   WEATHER_D->add_phase_listener(this_object());

}
void phase_changed(mapping map) {
 adjust_light();
}

string query_correct()
{
 return correct;
}

void sure_step()
{
  this_player()->move_player ("u/i/ity/area/town/room/maze_22",
  ""+this_player()->query_cap_name()+" slides gracefully behind a large "+
  "chunk of ice.\n",
  ""+this_player()->query_cap_name()+" smoothly slips into the area from "+
  "behind a chunk of ice.\n");	 
}

void slip_step()
{
  this_player()->move_player ("u/i/ity/area/town/room/maze_21",
  ""+this_player()->query_cap_name()+" slips on the ice.\n",
  ""+this_player()->query_cap_name()+" slides along the ice.\n");	
}

int check_move()
{
  if(this_player()->query_level() > 30) //don't permit low level players in
  {
    if(!random(2))
    {  
      call_out("sure_step",0); //use call_outs to break out of move function
	}
    else
    {  
      call_out("slip_step",0);
	}
  }
  return 0;	//don't permit the move; use manual code
}