#include <mudlib.h>
#include <move.h>

inherit ROOM;

#define MAIN_TABLE "/u/a/allanon/area/ity/rooms/main_table.c"
#define CORNER_TABLE "/u/a/allanon/area/ity/rooms/corner_table.c"

int taken = 0;

int sit_command(string cmd)
{
  if(cmd)
  {
	if (!this_player()->query_battleob()) 
	{
	  string target;
      sscanf(cmd,"at %s",target);
	  if(target == "main table" || target == "larger table" || 
	  target == "wood table")
	  {
	    message("info","You sit down at the main table, although you dare "+
	    "not take a seat at the head of the table.\n",this_player());
	    message("info",""+this_player()->query_cap_name()+" sits down at "+
	    "the main table.\n",this_object(),this_player());
	    this_player()->move(MAIN_TABLE, 1);
	  }
	  else if(target == "smaller table" || target == "plain table" ||
	  target == "iron table" || target == "corner table")
	  {
	    message("info","You sit down at the corner table.\n",this_player());
	    message("info",""+this_player()->query_cap_name()+" sits down at the "+
	    "corner table.\n",this_object(),this_player());
	    this_player()->move(CORNER_TABLE, 1);
	  }
	  else
	  {
	    message("info","Sit at what table?\n",this_player());   
	  }
    }
    else
    {
	  message("info","You are too busy fighting to do that!\n",this_player());   
    }
    return 1;	
  }
}

int press_command(string cmd)
{
  object thing;
  if(cmd == "gem" || cmd == "gems")
  {
    message("info","You locate the bothersome gem and press it down. There is "+
    "a small *click*, and a panel in the back of the chair slides open. "+
    "Something falls out, and then the panel quickly closes again.\n",
    this_player());
    message("info",""+this_player()->query_cap_name()+"	presses something on "+
    "the larger thronelike chair. There is a small *click*, and a panel in "+
    "the back of the chair slides open. Something falls out, and then the "+
    "panel quickly closes again.\n",this_object(),this_player());
    if(!taken)
    {
	  thing = new("/u/a/allanon/area/ity/obj/shooter.c");
	  taken = 1;
    }
    else
    {
	  thing = new("/u/a/allanon/area/ity/mon/bug.c");
    }
    thing->move(this_object(),1);
    return 1;
  }
  return notify_fail("Press what?\n");
}

void extra_init()
{
  add_action("sit_command","sit");
  add_action("press_command","press");
}

void extra_create()
{
  set_short( "Bastion's large dining room" );
  set_long(wrap("The dining room of the Bastion is a grand place indeed. The "+
  "main table alone must have cost a fortune, since it is easily over 20 "+
  "meters long and seems to be made out of a single tree. The chairs are just "+
  "as magnificent, being made of beautifully wrought iron with platinum "+
  "adornments. At the head of the table there are two chairs which are "+
  "distinctly set apart from the others by their size and grandeur; they "+
  "remind you of thrones. Curiously, each place at the table has a setting, "+
  "and there are even some covered dishes that smell like they have food "+
  "on them. Off in a corner there is a smaller, plain table made of iron, "+
  "which you suspect is where the servants and commoners eat.\nThere is a "+
  "small gold plaque hung on the wall.\n"));
  set_item_desc(([
  ({"main table", "larger table", "wood table"}) : "This massive table is a "+
  "masterpiece of woodwork. As there are no parts or breaks in it, you guess "+
  "that it has been carved from the heart of a single giant tree. Just "+
  "finding such a specimen must have been a challenge in itself. The table is "+
  "varnished with a rich black laquer that reflects the light beautifully.\n",
  ({"chairs", "platinum adornments", "adornments"}) : "The chairs are wrought "+
  "iron, accentuated with platinum adornments. Most of them are in the shape "+
  "of dragons, which coil themselves around the legs and up the backs of the "+
  "chairs. Unlike most things in the castle, these chairs show no signs of "+
  "rust at all.\n",
  ({"thrones", "head of the table", "two chairs"}) : "The two chairs at the "+
  "head of the table are stunning pieces of woodwork, inlaid with gold, "+
  "silver, and jewels, and covered in comfortable-looking velvet cushions. "+
  "Although they look almost impossible to move, upon closer inspection you "+
  "notice that some ingenious artisan has built a sort of frame with wheels "+
  "attached to it, and each chair sits slightly raised on one of these.\n",
  ({"frame with wheels", "frame", "wheels"}) : "You get a strange image in "+
  "your head while looking at the contraption. What if such a frame could be "+
  "mounted to a smaller, flat board, suitable for someone to stand on? It "+
  "could be an interesting sort of transportation device...\n",
  "jewels" : "The thronelike chairs are set with all manner of jewels. "+
  "Normally such finery would seem gaudy for a simple chair, but somehow you "+
  "feel it is only right that the noblest of nobles should have a chair "+
  "befitting of his or her status.\n", 
  ({"place", "setting"}) : "Fine utensils and cutlery are laid out at each "+
  "place on the table, along with a fluffy white napkin folded neatly over "+
  "a large ceramic dinner plate.\n",
  ({"utensils", "cutlery", "napkin", "dinner plate", "plate"}) : "Even the "+
  "small things in this room are opulent. The utensils look to be made of "+
  "titanium, and the cutlery of mithril. The ceramic dinner plates are at "+
  "least three centimeters thick, and the napkins are made of real silk.\n",
  ({"covered dishes", "dishes"}) : "You can't identify what sorts of smells "+
  "are drifting around the room, but they are delicious indeed. Strangely, "+
  "you can't seem to raise the lid on any of the dishes to see what is "+
  "underneath.\n",
  ({"smaller table", "plain table", "iron table", "corner table"}) : "The "+
  "smaller table sits in a corner, and while it is clearly meant for the "+
  "lesser peoples to eat at, it is by no means a poor table. The iron has "+
  "been filed and polished down to a smooth sheen, so there are no sharp "+
  "edges to run into. Not a spot of rust can be seen anywhere on the table. "+
  "The chairs at the smaller table are just plain wood, but they are carved "+
  "with some beautiful dragon designs like the other ones. As with the larger "+
  "table, there are settings at each place at the table, and there are a few "+
  "covered dishes that smell delectable.\n",
  ({"gem", "gems"}) : "One gem on the larger chair seems to be slightly ajar, "+
  "as if it were raised slightly out of position. Maybe you could press it "+
  "back into place.\n",
  ({"wall", "small gold plaque", "small plaque", "gold plaque", "plaque"}) :
  "On the wall is a small gold plaque. It reads, \"Honored guests: please "+
  "seat yourselves and signal for a waiter at your leisure. Please remember "+
  "that no food or drink is to leave the table.\"\n",
  "table" : "There are two tables in the room, the main table and the corner "+
  "table.\n",
  ({"slight shadow", "shadow", "walls"}) : "Upon closer inspection, you "+
  "find that there is actually a well-disguised door made of stone which is "+
  "set almost perfectly flush with the wall. As you approach, it magically "+
  "slides open on its own, revealing a passage beyond.\n"]));
  set_sounds(200 + random(50), ({ 
  "There seems to be a slight shadow along one of the walls, with nothing "+
  "that could be casting it.\n",
  "Something about one of the gems on the larger thronelike chair bothers "+
  "you, but you can't figure out why.\n"}) );
  set_hidden_exits( ({ "passage" }) ); 
  set_exits(([
  "passage" : "/u/a/allanon/area/ity/rooms/passage.c",
  "west" : "/u/a/allanon/area/ity/rooms/hallwaye.c"]));
  set_exit_msg( ([ "passage" : 
  "$N seems to walk right through one of the walls." ]));
}