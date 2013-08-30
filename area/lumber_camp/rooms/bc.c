#include <mudlib.h>
#include <move.h>

inherit ROOM;

int searched = 0; 

void extra_create()
{
  set_outside("m"); 
  set_outdoors("m");
  set_short( "In the center of a bloody battleground" );
  set_long(wrap("The stench of decay is stifling as you stand in the middle "+
  "of a bloody clearing. Dead bodies are everywhere, and they appear to be..."+
  "Goblins? You wonder what they would be doing out here in the boondocks..."+
  "Vultures and other carrion-eating creatures have found their way here and "+
  "feast greedily upon the deceased. You notice that there are deep "+
  "trench-like marks in the earth here. They certainly couldn't come from any "+
  "of the creatures you know of. They look like they were made by the roots "+
  "of a giant tree. Blood stains most surfaces here and some of it is fresh. "+
  "You constantly fight not to gag, but the crimson everywhere makes you sick "+
  "to your stomach. Curiously you note that all the vegetation has been "+
  "eliminated here, seemingly burned away by fire. A small stream winds its "+
  "way through here from north to south, but it has become heavily clogged "+
  "with corpses and now runs red. Chunks of rotting flesh float down its "+
  "almost-stagnant waters.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/vulture.c");
  add_monster("/u/a/allanon/area/lumber_camp/mon/carrion_crawler.c");
  set_item_desc(([
  ({"dead bodies", "bodies", "goblins"}) : "Dead bodies of goblins litter the "+
  "battleground. From their clothing, you determine that they were "+
  "lumberjacks. Remembering the cut trees west of here, you wonder if maybe "+
  "these lumberjacks were attacked because someone didn't want them to cut "+
  "down the trees. Most of the bodies have begun to decay, and the stench is "+
  "overpowering. A few of the bodies are twisted into bizzare positions, "+
  "almost as if they were crushed beneath something extremely heavy.\n", 
  ({ "vultures", "carrion-eaters", "creatures"}) : "Vultures and other "+
  "carrion-eaters have gathered to feast on the dead bodies. You consider "+
  "killing them but don't think it would matter...more would just come to "+
  "take their place.\n",
  ({"deep trench-like marks", "deep marks", "trench-like marks", "marks"}) : 
  "Much wider and deeper than the ruts of a well-used wagon path, these were "+
  "made by something extremely big and heavy. They look a lot like the marks "+
  "left over when a tree is pulled. You remember hearing of giant, living "+
  "trees called treants; perhaps they were the cause of these.\n",
  ({"blood", "stains", "crimson"}) : "Most surfaces here are stained deep "+
  "crimson with fresh or recently spilt blood. It only compounds the "+
  "already-omnipresent stench of decay, and you don't think you can handle it "+
  "much longer.\n",
  "vegetation" : "Not a single blade of grass can be seen on the battlefield. "+
  "You don't think a natural fire would be so destructive, it must have been "+
  "intentionally caused by someone.\n",
  ({"chunks", "rotting flesh", "flesh"}) : "Pieces of corpses have fallen "+
  "into the stream. They now float down it slowly, and provide an excellent "+
  "habitat for maggots and the like.\n",
  ({"sewer pipe", "pipe", "tunnel", "grate"}) : "The pipe looks like it is a "+
  "recent addition to this place, since it has not rusted yet. A steel grate "+
  "keeps anything from entering the flowing water.\n"])); 
  add_item( ({ "red stream", "stream", "small stream", "water" }), "The "+
  "stream is completely red from all the blood in it. Corpses have mostly "+
  "clogged its flow and now the waters barely move at all. Pieces of rotting "+
  "flesh float on the surface. Overall it is extremely disgusting. You don't "+
  "think the stream is very deep, but because of the blood tint you can't see "+
  "the bottom. The stream's origin seems to be a sewer pipe-like tunnel in "+
  "the ground, but it is grated securely - you couldn't possibly get in "+
  "there.\n");             
  add_item_search(({ "red stream", "stream", "small stream" }),"search_stream");  
  set_sounds(90 + random(15), ({ 
  "You feel like moving somewhere else, quickly, before the awesome stench "+
  "suffocates you.\n", 
  "You wonder what could have been the cause behind this horrible bloodshed.\n", 
  "It feels like your nostrils have been killed...better move before your "+
  "sense of smell is dead entirely.\n" }) ); 
  set_exits(([
  "west" : "/u/a/allanon/area/lumber_camp/rooms/bw.c",
  "east" : "/u/a/allanon/area/lumber_camp/rooms/be.c",
  "north" : "/u/a/allanon/area/lumber_camp/rooms/g1.c"]));
}

void search_stream()
{
  object key;
  if (searched) {
    message("search", "You grimace, reaching through the rotten flesh and "+
    "bloody water until your hand hits the bone-covered bottom. Pulling "+
    "your completely desecrated hand back up, you find nothing of interest. "+
    "You feel like you should have gotten some sort of reward for such a "+
    "brazen act.\n", this_player());     
    message("search", ""+this_player()->query_cap_name()+" reaches into the "+
    "stream of vile filth, looking disgusted, but comes up empty-handed.\n",
    environment(this_player()), this_player());
  } else {
    searched = 1;
    message("search", "You grimace, reaching through the rotten flesh and "+
    "bloody water until your hand hits the bone-covered bottom. Pulling "+
    "your completely desecrated hand back up, you amazingly discover that "+
    "you have found a key. It is covered in rot and stained crimson, "+
    "though, and it's almost as disgusting as the stream it came from.\n",
    this_player());
    message("search", ""+this_player()->query_cap_name()+" searches the "+
    "stream, something you would be loath to do yourself, and finds a key.\n",
    environment(this_player()), this_player());
    key = new("/u/a/allanon/area/lumber_camp/obj/rotten_key.c");
    if (key->move(this_player()) != MOVE_OK) {
      message("info", "You can't carry the key and drop it on the ground.\n",
      this_player());
      message("info", ""+this_player()->query_cap_name()+" can't carry the "+
      "key and drops it on the ground.\n", environment(this_player()), 
      this_player());
      key->move(environment(this_player()));
    }
  }
}