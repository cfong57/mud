#include <mudlib.h>

inherit ROOM;

int sturgeon = 0;
object fish;

int players_present(object room) 
{ 
  return sizeof(filter_array(all_inventory(room), (: $1->query_player() :) )); 
} 

int examine_command(string cmd)
{
  if ( cmd == "water" ) {
    if(sturgeon == 1) {
      message("info", wrap("You examine the water but can find no trace "+
      "of any living creatures.\n"), this_player());
      message("info", wrap(""+this_player()->query_cap_name()+" examines "+
      "the water and doesn't seem troubled.\n"), environment(this_player()),
      this_player());
    } else {
      message("info", wrap("The water is too muddy to discern anything it may "+
      "hide. It makes you a bit uneasy, but you are probably just paranoid in "+
      "thinking there was something in the water waiting to attack you. On "+
      "the other hand, you don't feel like staying around to find out...\n"),
      this_player());
      message("info", wrap(""+this_player()->query_cap_name()+" examines the "+
      "water carefully, and looks a bit uneasy. You don't see anything "+
      "either, but maybe you should leave, in case there really is something "+
      "in there.\n"), environment(this_player()), this_player());
      call_out("sturgeon_warning", 20);
    }
    return 1;
  }
  return notify_fail("Examine what?\n");  
}

void extra_init() 
{ 
  add_action("examine_command", "examine");  
} 

void extra_create()
{
  set_short( "Floating in an underground river" );
  set_long(wrap("It's quite dark and wet here. The room would appear to be "+
  "an underground tunnel of some sort, almost like a sewer tunnel. A quite "+
  "powerful stream of muddy-looking water flows in from the north, swamping "+
  "the room completely full of water. The muddy color of the water prevents "+
  "you from seeing anything in it, and all your senses scream at you that it "+
  "was a bad idea to come in here. You are absolutely certain that something "+
  "is lurking in the water, waiting to attack you. You think it would be "+
  "prudent to examine the water more closely before chickening out and "+
  "leaving, though.\n"));
  set_item_desc((["water" : "Shouldn't you 'examine' it instead?\n",
  "stream" : "You have to fight hard to keep your balance, lest you be swept "+
  "away by the powerful flow of water.\n" ]));  
  set_sounds(75 + random(35), ({ 
  "The rushing water drowns out all but the loudest sounds, putting you on "+
  "edge.\n", 
  "You consider trying to move through the stream to the north, but the "+
  "current is just too strong.\n", 
  "Something bony floats past you, it looks like a goblin skeleton. There "+
  "must have been something here to kill it!\n" }) ); 
  set_light(-75);
  set_water(1000);
  set_exits((["up" : "/u/a/allanon/area/lumber_camp/rooms/g5.c"]));
}

void sturgeon_warning() 
{ 
  if (players_present(this_object()) != 0) { 
    foreach(object ob in all_inventory(this_object())) {
      message("info", wrap("Something brushes against you under the water. "+
      "It felt sharp, and you feel that you've been cut. Something is "+
      "*definitely* out there. You feel like you should leave while you still "+
      "have the chance!\n"), ob);
      ob->receive_damage(10);
    }
    call_out("sturgeon_attack", 15);
  } 
} 

void sturgeon_attack()
{
  if (players_present(this_object()) != 0) { 
    foreach(object ob in all_inventory(this_object())) {    
      message("info", wrap("Suddenly without warning a GIGANTIC sturgeon "+
      "leaps out of the water, snapping its jaws wildly! It turns and attacks "+
      "you without a second thought!\n"), ob);
    }
    fish = new("/u/a/allanon/area/lumber_camp/mon/sturgeon.c");
    fish->move(this_object(), 1);
    foreach(object mon in all_inventory(environment(fish)))
    fish->kill_ob(mon);
    sturgeon = 1;
  }
}

int query_players_present()
{
  return players_present(this_object());
}