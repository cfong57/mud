#include <mudlib.h>
#include <move.h>

inherit ROOM;

mixed *exit_array = ({"/u/a/allanon/maze/room1.c", "/u/a/allanon/maze/room2.c", 
"/u/a/allanon/maze/room3.c", "/u/a/allanon/maze/room4.c", 
"/u/a/allanon/maze/room5.c"});

string get_room()
{
  return ""+exit_array[random(sizeof(exit_array))]+"";
}

int pick_mushroom(string cmd)
{
  if(cmd == "mushroom" || cmd == "mushrooms")
  {
	object mushroom;
    if(random(2))
    {
	  message("mushroom","You reach out and pick one of the red mushrooms.\n"+
	  "Taking just one more wouldn't hurt...\n",this_player());
	  message("mushroom",""+this_player()->query_cap_name()+" reaches out and "+
	  "picks one of the red mushrooms.\n",this_object(),this_player());
	  mushroom = new("/u/b/belannaer/mushrooms/fly_agaric.c");
	  mushroom->move(this_player(),1);
    }
    else
    {
	  message("monster","You reach out to pick one of the red mushrooms...but "+
	  "it suddenly springs to life!\n",this_player());
	  message("monster",""+this_player()->query_cap_name()+" reaches out to "+
	  "pick one of the red mushrooms...but it suddenly springs to life!\n",
	  this_object(),this_player());
	  mushroom = new("/u/a/allanon/maze/mushroom.c");
	  mushroom->move(this_object(),1);
	  mushroom->kill_ob(this_player());   
    }
    return 1;	  
  }
  return notify_fail("Pick what?\n");	
}

void extra_init()
{
  add_action("pick_mushroom", "pick");	
}

void extra_create()
{
  set_outside("F"); 
  set_outdoors("F");
  set_short("Stuck in Geno's Maze");
  set_long(wrap("You are lost somewhere inside Geno's Maze, from Super Mario "+
  "RPG: Legend of the Seven Stars. There are bushes everywhere, some "+
  "sprouting red mushrooms. Angry bees buzz around your head, but they don't "+
  "come quite close enough to sting...or swat. There are exits to the north, "+
  "south, east, and west, but they all lead to places that look EXACTLY THE "+
  "SAME as where you are now. How did you ever manage to get lost in here?\n"+
  "And more importantly, how are you going to get out?\n"));
  set_item_desc(([
  ({"bushes", "bush"}) : "The bushes are lush and green, with large, broad "+
  "leaves that are vaguely spade-shaped. Some of them are sprouting red "+
  "mushrooms.\n",
  ({"red mushrooms", "mushrooms", "mushroom"}) : "Red mushrooms are growing "+
  "on some of the bushes. You consider picking a few, but they smell rather "+
  "poisonous. Some of them even look like they might be 'alive'...\n",
  ({"bees", "bee"}) : "These insects are quite annoying and persistent, but "+
  "they never come close enough so that you could do anything about them. For "+
  "now, you will just have to bear with the irritating buzzing.\n"])); 
  set_sounds(73 + random(26), ({ 
  "If you don't die from thirst or starvation, the buzzing of the bees will "+
  "surely drive you mad before you find the exit...\n",
  "Some of the mushrooms almost look like they are...moving. But how could "+
  "that be?\n"}) );
  set_exits(([
  "north" : get_room(),
  "east"  : get_room(),
  "south": get_room(),
  "west"  : get_room()]));
}