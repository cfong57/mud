#include <mudlib.h>

inherit ROOM;
inherit DOOR;

void extra_create()
{
  set_outside("p"); 
  set_outdoors("p");
  set_short( "At the gates of the Bastion" );
  set_long(wrap("You are standing in front of a huge set of rusted iron "+
  "doors, easily tall enough to accomodate a b'rogh. The once-ornate copper "+
  "door knockers have become tarnished and worn over time, and what must have "+
  "once been an intricate pattern of metalwork is now just dusty flakes of "+
  "decaying metal. Time and ice have not been kind to this place: frost rimes "+
  "the door, and you can see many places where the cobbles have been "+
  "split or unearthed from the pressure of freezing. In a few more years, the "+
  "doors themselves are likely to cave in, leaving this castle completely "+
  "undefended against the elements.\n"));
  set_item_desc(([
  ({"copper door knockers", "door knockers", "copper knockers", "knockers"}) : 
  "These copper door knockers are in the shape of a lion's head, with heavy "+
  "steel rings hanging out of the mouths. Although the rings are in "+
  "relatively good shape, the lion's heads are covered in greenish tarnish.\n",
  ({"greenish tarnish", "tarnish"}) : "A patina of discolored copper covers "+
  "the lion's heads. It flakes off a bit at your touch, leaving behind a "+
  "powdery residue.\n",
  ({"lion's head", "lion's heads", "heads", "head"}) : "Upon closer "+
  "inspection, you see that each lion's head is set with two shining gems for "+
  "eyes.\n",
  ({"shining gems", "gems", "eyes"}) : "The gemstomes are of indeterminate "+
  "type, but they still shine fiercely. It must have taken a master "+
  "jewelcrafter many years to produce such a fine cut.\n", 
  ({"heavy steel rings", "steel rings", "rings"}) : "You raise one of the "+
  "rings and let it fall back with a CRASH. Yup, still effective.\n",
  ({"intricate pattern of metalwork", "intricate pattern", "pattern", 
  "metalwork"}) : "Some sort of design was engraved on these doors, but they "+
  "are so rusted over now that it is impossible to tell what kind of image "+
  "was once depicted.\n",
  ({"ice", "frost" }): "Even though this place has recently been thawed from "+
  "a cold prison, the time spent in captivity continues to leave its mark.\n",
  ({"cobbles", "cobblestones", "cracks", "path"}) : "The cobblestones which "+
  "pave the path have come loose over time due to ice poking up between the "+
  "cracks and, likely, some seismic activity.\n",
  "castle" : "The Bastion looms over you, looking dark and forboding despite "+
  "its decaying visage.\n"]));
  set_sounds(120 + random(35), ({ 
  "The wind whistles slightly, but otherwise the area in front of the castle "+
  "is totally silent. You cannot even hear a single animal.\n", 
  "As you watch, a flake of rust peels off the iron doors and floats "+
  "away.\n"}) ); 
  set_exits(([
  "north" : "/u/a/allanon/area/ity/rooms/entrance.c",
  "south" : "/u/a/allanon/area/ity/rooms/drawbridge.c"]));
  set_pre_exit_function( ([ "south" : "githrin_func" ]));
  create_door("north", "south",
  (["short" : "huge set of rusted iron doors",
  "long" : "Two massive iron doors which have rusted badly over time. There "+
  "might have been some sort of lock at one time, but the doors open easily "+
  "at your touch, despite being so heavy. The hinges must still be "+
  "well-greased.\n",
  "status" : "unlocked",
  "autoclose" : 45,
  "quality" : 50,
  "material" : "iron",
  "close_msg" : "The huge iron doors swing shut.\n",
  "open_msg" : "You open the huge iron doors.\n"]) );
}

int githrin_func()
{ 
  if(this_player()->id("githrin_ob"))
  {
	this_player()->force_me("party say I am sorry, but I will "+
	"have to wait for you here.");
    return 1;	  
  }
  return 0;
}