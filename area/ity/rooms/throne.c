#include <mudlib.h>

inherit ROOM;

#define GUARDROOM "/u/a/allanon/area/ity/rooms/towernw1.c"

int speak_command(string str)
{
  if(str)
  {
    message("info","You lean in close to the tube and say: '"+str+"'.\n",
    this_player());
    message("info",""+this_player()->query_cap_name()+" leans in close to the "+
    "tube and says: '"+str+"'.\n",this_object(),this_player());
    GUARDROOM->receive_speak(str);
    return 1;
  }
  return notify_fail("You could 'speak <message>'.\n");	
}

void extra_init()
{
  add_action("speak_command","speak");	
}

void extra_create()
{
  set_short( "Throne room of the Bastion" );
  set_long(wrap("You have come to the throne room of the castle. Your "+
  "attention is immediately caught by the two chairs set on a raised dais at "+
  "the back of the room. One of them is clearly the king's throne, as it is "+
  "much more massive and made of gold and other precious materials. The other "+
  "chair, which you surmise to be for the queen, is somewhat smaller and made "+
  "out of iron. There are banners draped all around the room which have "+
  "golden dragons on them. Two archways in the northwest and the northeast "+
  "are cordoned off with silk curtains. The rest of the room, oddly enough, "+
  "is rather bare. Perhaps the king was more of a practical mind. There is a "+
  "hole in one of the walls, with an iron tube protruding out of it.\n"));
  add_monster("/u/a/allanon/area/ity/mon/queen.c");
  set_item_desc(([
  ({"raised dais", "dais"}) : "The dais is about 20 centimeters high and made "+
  "of granite. The two thrones sit atop it.\n",
  ({"queen's throne", "smaller chair", "smaller throne", "iron throne",
  "iron chair", "other chair", "other throne"}) : "The queen's throne is made "+
  "of wrought iron, and somewhat resembles a dragon's open mouth.\n",
  ({"banners", "golden dragons", "dragons"}) : "The dragons on the banners "+
  "seem to almost be alive as they move with the cloth. You note that they "+
  "are all pointing their claws, seemingly in the direction of the king's "+
  "throne.\n",
  ({"archways", "northwest", "northeast", "silk curtains", "curtains"}) : 
  "The archways lead off to side rooms, although the curtains prevent you "+
  "from seeing what lies beyond. Perhaps they are rooms for the advisors.\n",
  ({"hole", "iron tube", "tube"}) : "The tube is several centimeters in "+
  "diameter, and widens out like a trumpet at the end. Perhaps it is a "+
  "speaking tube, used to communicate with the guard tower. You are tempted "+
  "to try speaking into it, although you would never know if it works unless "+
  "there was someone on the other side.\n"]));
  add_item(({"king's throne", "throne"}), "The throne is a masterwork of "+
  "metallurgy and woodworking. Gold inlays, platinum dragon motifs, and "+
  "gemstones of various sorts cover the back and sides, while the sitting "+
  "portion itself is upholstered with silk.\n");
  add_item_search(({"king's throne", "throne"}), "search_throne"); 
  set_sounds(200 + random(50), ({ 
  "The king's throne is really quite fascinating. You consider inspecting "+
  "it further.\n"}) );
  set_hidden_exits( ({ "north" }) );
  set_exits(([
  "south" : "/u/a/allanon/area/ity/rooms/audience.c",
  "north": "/u/a/allanon/area/ity/rooms/guardroom.c",
  "northwest" : "/u/a/allanon/area/ity/rooms/advisornw.c",
  "northeast": "/u/a/allanon/area/ity/rooms/advisorne.c" ]));
  set_exit_msg( ([ "north" : 
  "$N approaches the northern wall behind the thone and seems to go right "+
  "through it." ]));
}

void receive_speak(string message)
{
  message("speak","You hear a voice from the tube. It says: '"+message+"'.\n",
  this_object());	
}

void search_throne()
{
  message("info","You carefully inspect all parts of the throne, but find "+
  "nothing of interest. All the while, you get the nagging feeling of a "+
  "slight breeze that seems to be coming from the north, but there are no "+
  "windows there...\n",this_player());
  message("info",""+this_player()->query_cap_name()+" searches the throne "+
  "all over very thoroughly, but doesn't seem to find anything.\n",
  this_object(),this_player());
}