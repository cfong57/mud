#include <mudlib.h>
#include <daemons.h>
#include "../storage.h"

inherit ROOM;
inherit DOOR;

//controls both doors
void door_func()
{
  string look_msg = WEATHER_D->query_current_day_phase();
  mapping doors = this_object()->query_doors();
  if(!doors || !sizeof(keys(doors)))
  {
    message("bug","Something has bugged in this room - couldn't find the "+
    "doors. Contact a wiz.\n",this_object());  
  }
  //members door is locked during day, open at night
  //entrance door is open during day, locked at night
  if(strsrch(look_msg, "sun")>-1)
  {
    doors["south"]["status"] = "open"; 
	doors["east"]["status"] = "locked";
  }
  else
  {
    doors["south"]["status"] = "locked";
	doors["east"]["status"] = "open";
  }
}

void phase_changed(mapping map)
{ 
  door_func();
}

string hookfunc()
{
  string returnme = "Some steel hooks have been set into the walls near the "+
  "doors. Patrons could 'hang' their coats here while they dine, and "+
  "'retrieve' them when they leave. A small sign next to the hooks warns "+
  "you that Wildcat Cafe is not responsible for what happens to your items "+
  "should you fail to retrieve them before leaving the establishment.\n"+
  "There's nothing stopping you from 'steal'ing some patron's belongings, "+
  "although you feel it would be a BAD idea...\n";
  string temp = query_contents("foyer");
  if(temp != "")
  {
    returnme += temp;
  }
  else
  {
    returnme += "The hooks are empty right now.\n";		  
  }
  return returnme;
}

int hang_command(string cmd)
{
  if(cmd)
  {
    int max = sizeof(all_inventory(this_player()));
    int index = 0;
    for(int quit = 0; quit == 0; index++)
    {
      if(index < max)
      {
        if(all_inventory(this_player())[index]->id(cmd) ||
        all_inventory(this_player())[index]->query_short() == cmd)
        {        
	      if(kept(all_inventory(this_player())[index]))
	      {
		    message("info","You don't want to relinquish your hold on "+
		    ""+all_inventory(this_player())[index]->query_short()+" even for "+
		    "a moment.\n",this_player());  
	      }
	      else if(all_inventory(this_player())[index]->query_prevent_drop())
	      {
		    message("info","You can't move the "+
		    ""+all_inventory(this_player())[index]->query_short()+"!\n",
		    this_player());
	      }
	      else
	      {
		    message("info","You hang your "+
		    ""+all_inventory(this_player())[index]->query_short()+" on one of "+
		    "the hooks. Make sure to 'retrieve' it later.\n",this_player());
		    message("info",""+this_player()->query_cap_name()+" hangs "+
		    ""+possessive(this_player())+" "+
		    ""+all_inventory(this_player())[index]->query_short()+" on one of "+
		    "the hooks.\n",this_object(),this_player());
		    move_to_store("foyer", this_player()->query_name(), 
		    all_inventory(this_player())[index]);
	      }	      
          quit++;
        }
      }
      else
      {
	    message("info","You don't have a "+cmd+" to hang.\n",this_player());
        quit++;
      }
    }
    return 1;
  }
  return notify_fail("Hang what?\n"); 	 
}

int retrieve_command(string cmd)
{
  if(cmd)
  {
	if(get_from_store("foyer", this_player(), cmd))
	{
	  if(cmd == "all")
	  {
	    message("info","You retrieve all your things from the hooks.\n",
	    this_player());
	    message("info",""+this_player()->query_cap_name()+" retrieves all "+
	    ""+possessive(this_player())+" things from the hooks.\n",
	    this_object(),this_player());
	  }
	  else
	  {
	    message("info","You retrieve your "+cmd+" from the hook.\n",
	    this_player());
	    message("info",""+this_player()->query_cap_name()+" retrieves "+
	    ""+possessive(this_player())+" "+cmd+" from the hook.\n",
	    this_object(),this_player()); 
	  }	
	}
	else
	{
	  if(cmd == "all")
	  {
		message("info","But you don't have anything hanging on the hooks.\n",
		this_player());  
	  }
	  else
	  {
	    message("info","You don't have a "+cmd+" hanging on the hooks.\n",
	    this_player());
      }
	}
	return 1;
  }
  return notify_fail("Usage: Retrieve <thing|all>\n"); 	
}

int steal_command(string cmd)
{
  if(cmd)
  {
	string who;
	string thing;
	sscanf(cmd, "%s's %s", who, thing);
	if(who && thing)
	{
	  if(!is_thing_stored(thing))
	  {
	    message("info","There doesn't seem to be a "+thing+" hanging on the "+
	    "hooks.\n",this_player());
	  }
	  else if(who == this_player()->query_name())
	  {
	    message("info","Why would you steal from yourself? Just 'retrieve' "+
	    "it instead.\n",this_player());	  
	  }
	  else if(!is_an_owner(who))
	  {
	    message("info",""+capitalize(who)+"	doesn't have anything hanging on "+
	    "the hooks.\n",this_player());  
	  }
	  else if(!owner_has_thing(who, thing))
	  {
	    message("info",""+capitalize(who)+" doesn't seem to have a "+thing+" "+
	    "hanging on the hooks.\n",this_player());
	  }
      else if(find_living(who)) //ok to be linkdead, but not to leave game
      {
	    message("info","You dare not steal the "+thing+". "+capitalize(who)+" "+
	    "might come back for it.\n",this_player()); 
      }
      else
      {
	    steal_from_store(this_player(), who, thing);
	    message("info","You wait until no one is looking and then quickly "+
	    "snatch "+who+"'s "+thing+" off the hooks.\n",this_player());
	    message("info",""+this_player()->query_cap_name()+" makes some fast "+
	    "movements near the hooks, but you're not quite sure what "+
	    ""+subjective(this_player())+" did.\n",this_object(),this_player());
      }
	  return 1;
    }
  }
  return notify_fail("Usage: Steal <owner>'s <thing>\n");
}

void extra_init()
{
  add_action("hang_command","hang");
  add_action("retrieve_command","retrieve");
  add_action("steal_command","steal");
}

void extra_create()
{
  set_no_teleport(1);
  set_short("Foyer of Wildcat Cafe");
  set_long(wrap("This is the foyer of Wildcat Cafe. There are some hooks set "+
  "into the walls near the doors for patrons to hang their coats on. Lush red "+
  "carpeting covers the floor, and there are some pleasant potted ferns in "+
  "the corners of the room. A receptionist's desk is set up in the middle. "+
  "There are two arrow-shaped signs attached to the receptionist's desk, one "+
  "pointing west and one pointing east. To the west is a spacious-looking "+
  "dining room; a door to the east hides whatever is in that room. A small "+
  "side-door leads back outside, but it looks like it only opens one way.\n"));
  set_item_desc(([
  ({"hooks", "walls", "coats"}) : (: hookfunc :),
  ({"lush red carpeting", "red carpeting", "carpeting", "lush carpeting"}) : 
  "The carpet is very plush; it looks brand-new. You are not sure what type "+
  "of fiber it is made of, but it is dyed a familiar blood-red.\n",
  "floor" : "The floor is covered with red carpet in most places. The exposed "+
  "areas are richly done with tiles, also in red.\n",
  ({"exposed areas", "areas", "tiles", "tile"}) : "You are not sure what kind "+
  "of rock was used to make these tiles so red. It certainly seems to be a "+
  "popular color with the decorators here.\n",
  ({"potted ferns", "ferns"}) : "There are some pots in the corners of the "+
  "room, housing nondescript ferns. The green of the ferns is a welcome "+
  "contrast to the red covering much of the room.\n",
  "corners": "Some potted ferns reside in the corners of the room. Otherwise, "+
  "they are empty - and immaculately dust-free.\n",
  ({"receptionist's desk", "receptionist desk", "desk"}) : "This desk is made "+
  "of maple, and it has been polished to a shiny finish. A book of records "+
  "lies open on top, with a quill and inkwell sitting next to it. There are "+
  "two arrow-shaped signs attached to the receptionist's desk.\n",
  ({"book of records", "book", "records"}) : "The book is full of names. Next "+
  "to each name is written a time and date, and sometimes the word 'member'. "+
  "Looks like this is the log of all the comings and goings of patrons.\n",
  ({"quill", "inkwell"}) : "A quill and inkwell sit next to the book of "+
  "records. The quill is from some bird with red plumage, and the ink in the "+
  "inkwell is, unsurprisingly, also red.\n",
  "ink" : "The ink has the same shade as blood.\n",
  ({"arrow-shaped signs", "signs"}) : "The sign pointing to the west says "+
  "'Dining'. The sign pointing to the east says 'Members Only'.\n",
  "side-door" : "This is a small nondescript door next to the main entrance. "+
  "It looks like it only opens outwards, so it can't be used to get back "+
  "inside.\n"]));
  add_monster("/u/a/allanon/area/cafe/mon/trixie.c");
  set_sounds(180 + random(15), ({ 
  "The carpet is spotless. They must do a good cleaning job here, since "+
  "adventurers aren't known for cleanliness.\n", 
  "The smell of meat is in the air. It is coming from both the west and the "+
  "east, but the aroma from the east is somehow more...appetizing. You wonder "+
  "what kind of meat is in there.\n"})); 
  set_exits(([
  "west" : "/u/a/allanon/area/cafe/rooms/dining.c",
  "east" : "/u/a/allanon/area/cafe/rooms/members_items.c",
  "south" : "/u/a/allanon/area/cafe/rooms/entrance.c",
  "side-door" : "/u/a/allanon/area/cafe/rooms/entrance.c"]));
  create_door("south", "north",
  (["short" : "ornate oaken double-doors",
  "long" : "These wooden doors are made of oak and have been polished to a "+
  "shiny finish. There are no visible handles, or even a lock. You get the "+
  "feeling that magic is used to keep these doors open or shut.\n",
  "ids" : ({"door", "doors", "ornate oaken double-doors", "ornate double-doors",
  "ornate door", "ornate doors", "oaken double-doors", "oaken door", 
  "oaken doors"}),
  "status" : "locked",
  "autoclose" : 0,
  "autolock" : 0,
  "quality" : 1001,
  "material" : "wood",
  "close_msg" : "The ornate oaken double-doors snap shut with a BANG.\n",
  "open_msg" : "The ornate oaken double-doors suddenly swing open.\n"]));
  create_door("east", "west",
  (["short" : "heavy iron door",
  "long" : "This door is made of a solid slab of iron, several centimeters "+
  "thick. Like the front doors, it has no lock, and is probably controlled by "+
  "magic. The door has been kept immaculately free of rust, although like the "+
  "rest of the building it looks quite new.\n",
  "ids" : ({"door", "iron door", "heavy door", "heavy iron door"}),
  "status" : "locked",
  "autoclose" : 0,
  "autolock" : 0,
  "quality" : 1001,
  "material" : "iron",
  "close_msg" : "The heavy iron door SLAMS shut.\n",
  "open_msg" : "The heavy iron door suddenly swings open.\n"]));
  WEATHER_D->add_phase_listener(this_object());
  door_func();
}