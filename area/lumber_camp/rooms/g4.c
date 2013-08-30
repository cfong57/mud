#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_outside("p"); 
  set_outdoors("p");
  set_short( "Eastern edge of the lumber camp" );
  set_long(wrap("You are at the eastern edge of the lumber camp. You notice "+
  "immediately that most of the goblins here aren't doing anything...they "+
  "just lie around and eat food. In fact you notice there seems to be quite a "+
  "lot of food being passed around. There's a squat, hastily erected wooden "+
  "building here. Perhaps it is the camp's food storehouse. A few of the less "+
  "greedy goblins continue to work doggedly on, ignoring the pliant cries "+
  "of their gaunt stomaches.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/goblins.c");
  set_item_desc(([
  ({"wooden building", "building", "storehouse"}) : "The building is "+
  "constructed in a very simple manner. It reminds you somewhat of a log "+
  "cabin...There's an iron door set into the front with a lock to keep out "+
  "goblins who want food before it's time to hand out rations. There are some "+
  "gaps between the logs, which have been poorly fitted together...Peering "+
  "inside, you notice that someone has broken in, but you are not sure how. "+
  "Food has been spilt everywhere.\n"]));  
  set_sounds(117 + random(18), ({ 
  "Watching the goblins eat makes you hungry. You unconsciously start walking "+
  "towards the storehouse.\n"}) ); 
  set_exits((["west"  : "/u/a/allanon/area/lumber_camp/rooms/g2.c",
  "in" : "/u/a/allanon/area/lumber_camp/rooms/storehouse.c"]));
  create_door("in", "out",
  (["short" : "sturdy iron door with a padlock",
  "long" : "A sturdy iron door that looks unbreakable. There's a "+
  "steel padlock attached to keep it shut tight.\n",
  "key" : "/u/a/allanon/area/lumber_camp/obj/bronze_key.c",
  "status" : "locked",
  "autolock" : 1,
  "autoclose" : 45,
  "quality" : 1001,
  "material" : "steel",
  "close_msg" : "The sturdy iron door swings shut.\n",
  "open_msg" : "You open the sturdy iron door.\n"]) );
  set_exit_msg( ([ "in" : "$N enters the storehouse." ]) ); 
}