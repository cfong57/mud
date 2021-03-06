#include <mudlib.h>

inherit ROOM;
inherit DOOR;

int take_command(string str)
{
  if(str == "potion" || str == "bomb potion")
  {
    object shadow;
    object potion;
    if(this_player()->query_potions() < 5)
    {
      message("info","You take a potion out of the pouch.\n",this_player());
      message("info",""+this_player()->query_cap_name()+" takes a potion out "+
      "of the pouch.\n",environment(this_player()),this_player());
      potion = new("/u/a/allanon/area/ity/obj/bomb_potion.c");
      potion->move(this_player(),1);
      if(!this_player()->query_timer_shadow())
      {
        shadow = new("/u/a/allanon/area/ity/shadows/timer_shadow.c");
        shadow->move(this_player(),1);
        shadow->shadow_object(this_player());
        shadow->start_me();
      }
      this_player()->increment_potions();
    }
    else
    {
      message("info","On second thought, haven't you taken enough potions "+
      "for now? It's not like they are going anywhere.\n",this_player());
      message("info",""+this_player()->query_cap_name()+" reaches out for "+
      "the pouch, but seems to reconsider.\n",environment(this_player()),
      this_player());  
    }
    return 1;
  }
  return notify_fail("Take what?\n");
}

void extra_init()
{
  add_action("take_command","take");	
}

void extra_create()
{
  set_short( "Cell in the northwestern tower of the Bastion" );
  set_long(wrap("You are standing in a fairly cramped holding cell made of "+
  "a solid cube of iron. There is a window to the outside covered with an "+
  "iron grill, a bucket, a bed of straw, and a wooden bench to sit on. This "+
  "particular cell does not have a skeleton in it, however. Perhaps its "+
  "prisoner was taken out and executed. You wonder if whoever it was may have "+
  "left something behind.\n"));
  set_item_desc(([
  ({"window", "outside"}) : "You can see to the outside through the window, "+
  "although your view is somewhat obscured due to the iron grill. A faint "+
  "breeze flows through and tickles you playfully.\n",
  ({"grill", "iron grill"}) : "The grill is made of iron and has rusted quite "+
  "badly. One of the bars is missing.\n",
  ({"iron bar", "bar"}) : "The iron bar has been filed down to a sharp point "+
  "which, while crude, would serve as an effective weapon and writing tool.\n",
  ({"bucket", "wooden bench", "bench"}) : "The bucket and the bench are "+
  "both made of wood, and are quite ordinary.\n",
  "message" : "Someone has used the iron bar to scratch a message into the "+
  "floor of the cell. It reads: \"They've come for me at last, my time is "+
  "over. To any who come after me: the gate is susceptible to a 'blast' from "+
  "a bomb potion. I had hoped to use my stash here to escape, but it seems "+
  "that won't be necessary now. Good luck. ~Cieros\"\n",
  "pouch" : "A small leather pouch with bomb potions inside. It is very "+
  "carefully padded to prevent them from exploding unnecessarily. You could "+
  "take one if you needed to.\n"]));
  add_item(({"bed", "bed of straw", "straw"}), "It's a pile of straw that "+
  "provides at least a little comfort for sleeping.\n");
  add_item_search( ({ "bed", "bed of straw", "straw" }), "search_bed");
  set_sounds(200 + random(50), ({ 
  "The bed looks unnecessarily lumpy, as if there were things hidden "+
  "underneath it.\n"}) );
  set_exits(([
  "out": "/u/a/allanon/area/ity/rooms/towernw2.c"]));
  create_door("out", "cell",
  (["short" : "iron cell door",
  "long" : "This thick iron door has rusted badly, and while the door itself "+
  "might hold for a while longer, the lock looks like it would fall apart "+
  "at a child's touch. You could open it with no resistance.\n",
  "ids" : ({ "iron cell door", "cell door", "iron door" }),
  "status" : "open",
  "material" : "iron",
  "close_msg" : "The iron cell door swings shut.\n",
  "open_msg" : "You open the iron cell door.\n"]) );
}

void search_bed()
{
  message("info","As you search through the bed, you feel some lumps. Moving "+
  "the straw aside, you find an iron bar, a pouch, and a message scratched "+
  "into the floor.\n",this_player());
  message("info",""+this_player()->query_cap_name()+" searches through the "+
  "bed and seems to find some objects of interest.\n",this_object(),
  this_player());
}