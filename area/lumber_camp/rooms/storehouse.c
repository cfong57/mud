#include <mudlib.h>
#include <move.h>

inherit ROOM;
inherit DOOR;

int bread = 8 + random(3); 

int pilfer_command(string cmd)
{
  if ( cmd == "box" ) {
    if(bread == 0) {
      message("info", "You reach through the crack in the box, but find "+
      "nothing. It seems someone has already cleaned it out.\n", this_player());
      message("info", ""+this_player()->query_cap_name()+" reaches through "+
      "the crack in the box, but finds nothing.\n",
      environment(this_player()), this_player());
    } else {
      object p = this_player();
      object food;
      message("info", "You stick your hand through the crack in the box and "+
      "pilfer some bread.\n", p); 
      message("info", ""+p->query_cap_name()+" reaches "+possessive(p)+" hand "+
      "through the crack in the box and pilfers some bread.\n",
      environment(p), p);  
      switch (random(3))
      {
        case 0:
        food = new("/obj/food/crisp_rye-bread.c");
        break;
        case 1:
        food = new("/obj/food/waybread.c");
        break;
        case 2:
        food = new("/obj/food/bread.c");
        break;
      }
      if (food->move(this_player()) != MOVE_OK) {
        message("info", "You can't carry the bread and drop it on the "+
        "ground.\n", this_player());
        message("info", ""+this_player()->query_cap_name()+" can't carry the "+
        "bread and drops it on the ground.\n", environment(this_player()),
        this_player());
        food->move(environment(this_player()));
      }
      bread--; 
    }
    return 1;
  }
  return notify_fail("Pilfer what?\n");
}  

void extra_init() 
{ 
  add_action("pilfer_command", "pilfer");  
} 

void extra_create()
{
  set_short( "Inside a storehouse" );
  set_long(wrap("Lots of boxes, crates, and the like fill this somewhat small "+
  "room to the ceiling. From the smell, they are all stuffed full of various "+
  "food items. You consider taking something to eat, but most containers are "+
  "sealed shut with iron bands reinforced with steel nails. Some of the "+
  "containers have been split open, seemingly by an axe or some sort of other "+
  "heavy slashing object. Their contents are spilled around the floor - "+
  "bread and meat is scattered every which way. Berries seem to be in the mix "+
  "as well, but someone has already squashed them underfoot, leaving a sticky "+
  "mess everywhere. There's a substantial crack in one of the boxes.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/sgoblin.c");
  set_light(10);
  set_item_desc(([
  ({"boxes", "crates", "containers"}) : "There are various containers in here "+
  "meant to ship food. Most are made of wood reinforced with iron bands and "+
  "steel nails to prevent breakage.\n", 
  ({ "iron bands", "bands", "steel nails", "nails"}) : "The containers have "+
  "been reinforced with iron bands, which were hammered in using steel nails. "+
  "Your chances of prying them off are pretty much zero.\n",
  ({"contents", "bread", "meat", "berries"}) : "Whoever has split open the "+
  "containers didn't bother to make a neat job of it; food has been spilled "+
  "everywhere in the room. Most of it has been stepped on, leaving trampled "+
  "bread, over-tenderized meat, and squashed berries. All in all, it's pretty "+
  "disgusting.",
  ({"substantial crack", "crack" }) : "One box has a huge crack in it. You "+
  "could reach inside and 'pilfer' its contents if you wanted to.\n"]));              
  set_sounds(125 + random(18), ({ 
  "There's going to be an awful stench once all the spilt food starts "+
  "to decay; you should leave before that happens.\n"}) ); 
  set_exits((["out" : "/u/a/allanon/area/lumber_camp/rooms/g4.c"]));
  create_door("out", "in",
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
}