#include <mudlib.h>
#include <move.h>

inherit ROOM;
int stumpsearched = 0; 

void extra_create()
{
  set_outside("f"); 
  set_outdoors("f");
  set_short( "A glade full of tree stumps" );
  set_long(wrap("You have entered what was once a small glade in the middle "+
  "of a lush forest. It seems that a team of lumberjacks has been through "+
  "here recently...almost all the trees in sight for about 25 meters have "+
  "been felled, leaving behind just stumps. They don't look dry or dead yet, "+
  "though, so this probably happened recently. You wonder why someone would "+
  "need to cut down so many trees. A small dirt path leads east into a "+
  "still densely wooded area.\n"));
  set_item_desc(([
  ({"trees", "stump", "stumps", "tree stumps"}) : "Tree stumps are all around "+
  "you, looking recently cut. You notice one of the stumps has a hole in "+
  "it.\n", 
  ({ "small dirt path", "small path", "dirt path", "path"}) : "There's a path "+
  "that leads east into an area that hasn't been deforested yet.\n"]));
  add_item( ({ "hole" }), 
  "One of the tree stumps has a hole in it, large enough to fit your hand "+
  "through. You could probably search it, but you can't see what's inside so "+
  "it might not be such a good idea...\n");             
  add_item_search( ({ "hole" }), "search_hole");   
  set_sounds(120 + random(35), ({ 
  "It's absolutely silent here. The silence seems oppressive and dead.\n", 
  "You see a thin trail of smoke drifting out of the forest to the "+
  "northeast.\n", 
  "Some trees to the southest seem to move, but you are probably just "+
  "imagining things.\n" }) ); 
  set_exits(([
  "east" : "/u/a/allanon/area/lumber_camp/rooms/bw.c",
  "out" : "/d/world/rooms/592,685.world"])); //change as needed
}

void search_hole()
{
  object dfly;
  if (!stumpsearched) {
    stumpsearched = 1;
    message("info", "You reach into the hole, and quickly pull your hand back "+
    "out when something tries to bite it!\n", this_player());
    message("info", ""+this_player()->query_cap_name()+" puts "+
    ""+possessive(this_player())+" hand into a hole in one of the tree "+
    "stumps, but quickly pulls it back out with a startled expression!\n",
    environment(this_player()), this_player());
    message("info", "A dragonfly springs out of the hole, furious at being "+
    "disturbed!\n", environment(this_player()));
    dfly = new("/u/a/allanon/area/lumber_camp/mon/dragonfly.c");
    dfly->move(environment(this_player())); 
    dfly->kill_ob(this_player());
  }
  else
  {
    message("info", "You stick your hand in the hole, feeling around, but "+
    "only come up with a handful of spiderwebs.\n", this_player());     
    message("info", this_player()->query_cap_name()+" puts "+
    ""+possessive(this_player())+" hand into a hole in one of the stumps, "+
    "but apparently doesn't find anything of interest.\n", 
    environment(this_player()), this_player());
  }
}