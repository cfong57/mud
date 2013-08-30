#include <mudlib.h>
#include <move.h>

inherit ROOM;
inherit DOOR;

int clean_up(int inh) 
{ 
  return 1; 
}

void reset() 
{ 
  return; 
}

int potionsearched = 0;

void extra_create()
{
  seteuid( getuid() );
  set_explorable(1);
  set_short( "Inside Cellaria's cottage" );
  set_long(wrap("You are standing inside the cottage. It is rather plainly "+
  "furnished, with a simple bed and some tables in a corner. One wall is "+
  "taken up by a huge shelf on which you see many potion racks. The fireplace "+
  "is lit, and it creates a pleasant and warm atmosphere to the otherwise "+
  "rather empty room. A thick layer of dust covers most things, as though "+
  "they have not been used for some time. In the middle of the room there "+
  "is a skeleton. It seems to have been here for a very long time, as the "+
  "bones are bleached white.\n"));
  add_monster("/u/a/allanon/area/lumber_camp/mon/cellaria.c");
  set_safe_room(1);
  set_no_teleport(1);  
  set_light(250);
  set_item_desc(([
  "cottage" : "You get the impression that the cottage is larger on the "+
  "inside than it appeared from the yard. Is it magic, or simply a miracle of "+
  "the construction? You ponder the question as you admire the quality of the "+
  "wood paneling along the floor.\n",
  ({"wood paneling", "paneling", "floor", "panels"}) : "The floor of the "+
  "cottage is made of panels of oak, each perfectly fitted and naturally "+
  "burnished from years of walking on them. You can't spot a single gap "+
  "between them.\n",
  ({"skeleton", "bones"}) : "The skeleton is humanoid in stature, perhaps "+
  "that of an elf. Oddly, the skeleton looks like it is in a "+
  "prone position, as if the person died while they were asleep. It has been "+
  "completely picked clean, and even the garments have rotted away.\n", 
  ({ "bed", "tables"}) : "It would appear that the occupant of this cottage "+
  "was somewhat of a messy person, since the bed and tables are littered with "+
  "all sorts of papers and other junk. There are a large number of beakers, "+
  "vials, and other glassware scattered about. It looks like an alchemist "+
  "used to live here.\n",
  ({ "beakers", "vials", "glassware" }) : "The glasswares have all been "+
  "heavily used: there are signs of etching from various chemicals and "+
  "cleaning solutions. A few still have some dried residue in them, but "+
  "you dare not investigate, since who knows what deadly concoction might "+
  "have been left behind?\n",
  ({ "fire", "fireplace" }) : "The fireplace is lit, but it seems to not "+
  "consume any fuel at all. It is just a flame sitting there in the hearth. "+
  "How strange. Only magic could be responsible for this.\n",
  "dust" : "Dust is on most of the surfaces. You can spot some tiny "+
  "footprints here and there, probably from rodents and other critters that "+
  "happened to find their way in here with the owner gone.\n"]));
  add_item( ({ "rack", "potion rack", "potions", "shelf", "boxes",
  "wooden boxes", "wall" }), 
  "One whole wall of the cottage is taken up by a huge wooden shelf, "+
  "containing many wooden boxes which you recognize as potion racks. While "+
  "many of the vials contained inside seem discolored, cracked, or broken, "+
  "there must be hundreds here, so a more thorough search is perhaps in "+
  "order.\n");             
  add_item_search( ({"rack", "potion rack", "potions", "shelf", "boxes",
  "wooden boxes", "wall" }), "search_potions");            
  set_exits((["out"  : "/u/a/allanon/area/lumber_camp/rooms/cottage_out.c"]));
  create_door("out", "in",
  (["short" : "door, made out of a solid slab of oak",
  "long" : "The door is made of a solid slab of oak. There is no lock, but "+
  "there are some braces where one could perhaps slide a log through to "+
  "keep the door barred. You don't see any logs in the cottage, though.\n",
  "status" : "closed",
  "ids" : ({ "door", "wood door", "wooden door" }),
  "autoclose" : 60,
  "quality" : 350,
  "material" : "wood",
  "close_msg" : "The heavy oaken door swings shut.\n",
  "open_msg" : "You open the wooden door.\n"]) ); 
  ::reset();
}

void search_potions()
{
  if (potionsearched) {
    message("search", "You scrounge through the potion racks, but merely "+
    "end up dirtied for your efforts. There doesn't seem to be a single "+
    "usable potion left on the racks.\n",
    this_player());     
    message("search", ""+this_player()->query_cap_name()+" rummages through "+
    "the potion racks, but doesn't seem to find anything of interest.\n",
    environment(this_player()), this_player());
  } else {
    object potion;
    if (!random(5)) {
      potionsearched = 1;
    }
    message("search", "You scrounge through the potions and eventually "+
    "find one that looks usable.\n", this_player());
    message("search", ""+this_player()->query_cap_name()+" rummages through "+
    "the potion racks and eventually finds something.\n",
    environment(this_player()), this_player());
    switch (random(100)) {
      case 0..19:
      potion = new("/u/a/allanon/area/lumber_camp/obj/regen_bottle.c");
      break;
      case 20..39:
      potion = new("/u/a/allanon/area/lumber_camp/obj/fire_bottle.c");
      break;
      case 40..84:
      potion = new("/u/a/allanon/area/lumber_camp/obj/sleep_bottle.c");
      break;
      case 85..99:
      potion = new("/u/a/allanon/area/lumber_camp/obj/death_bottle.c");
      if (present("Cellaria")) {
        message("say", "%^BOLD%^%^YELLOW%^Cellaria says: Ah, I wouldn't do "+
        "that if I were you. I never had a chance to test *that* potion "+
        "before I met my end; there might be some unpleasant surprises. I "+
        "cannot guarantee your safety or even your life if you choose to use "+
        "it.%^RESET%^\n", environment(this_player()));
      }
      break; 
    }
    if (potion->move(this_player()) != MOVE_OK) {
      message("info", "You can't carry the potion and drop it on the "+
      "ground.\n", this_player());
      message("info", ""+this_player()->query_cap_name()+" can't carry the "+
      "potion and drops it on the ground.\n", environment(this_player()),
      this_player());
      potion->move(environment(this_player()));
    }
  }
}