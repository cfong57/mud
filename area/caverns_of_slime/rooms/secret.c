#include <mudlib.h>
#include <move.h>

inherit ROOM;
int bedsearched=0;
int pillowsearched=0;
int clean_up(int inh) { return 1; }
void reset() { return; }

void extra_create()
{
  set_explorable(1);
  set_short( "hidden abode" );
  set_long(wrap("You've stepped into a curious alcove in the rocks, which "+
  "seems to be recently made. A clever illusionary spell gives the impression "+
  "of a solid rock wall to the south, keeping out those stupid enough not to "+
  "pay attention to their surroundings. The room is sparsely furnished. You "+
  "spot a chair with a small desk, a lantern, and a bed.\n"));
  add_monster("/u/a/allanon/area/caverns_of_slime/mon/murin.c");
  set_item_desc(([
                  ({ "spell", "wall"}) : "It looks quite real!\n",
                  "chair" : "A plain chair made of wood.\n",
                  "desk" : "A simple desk made of wood.\n",
                  "lantern" : "It gives off enough light to read and write "+
                  "by. There is an adequate amount of fuel in it.\n",
                  "bed" : "The bed is more like a pile of straw on the floor. "+
                  "A crisp cotton blanket covers it, and a sack filled with "+
                  "some type of feather serves as a crude pillow.\n",
                  "blanket" : "It's just an ordinary blanket.\n"]) );
  add_item( ({ "pile", "straw" }),
            "Something seemed to glint from within the pile. Perhaps you "+
            "should search it?\n");
  add_item( ({ "sack", "pillow" }),
            "The pillow seems to have a large lump.\n");

  add_item_search( ({ "pile", "straw" }), "search_bed");
  add_item_search( ({ "sack", "pillow" }), "search_pillow");

  set_light(70);
  set_sounds(200, ({ "The room is absolutely silent.\n"}) );
  set_exits(
  (["south" : "/u/a/allanon/area/caverns_of_slime/rooms/intersection.c"]));
  set_exit_msg(([ "south" : "$N passes through the illusionary south wall."]));
  ::reset();
}
int search_bed()
{
  object dagr;

  if(bedsearched)
    {
      message("info", "You search the bed, but you don't find anything.\n",
              this_player());

      message("info", this_player()->query_cap_name()+" searched the bed, but "+
      "doesn't find anything.\n",
              environment(this_player()),this_player());

      return 1;
    }

  bedsearched = 1;

  message("info", "You search the bed and find a dagger.\n",this_player());
  message("info", this_player()->query_cap_name()+" searches the bed and "+
          "finds a dagger.\n",
          environment(this_player()), this_player());

  dagr = new("/u/a/allanon/area/caverns_of_slime/obj/dagger.c");

  if(dagr->move(this_player()) != MOVE_OK)
    {
      message("info", "You can't carry the dagger and drop it on the ground.\n",

              this_player());
      dagr->move(environment(this_player()));
    }

  return 1;
}

int search_pillow()
{
  object knife;

  if(pillowsearched)
    {
      message("info", "You search the pillow, finding nothing but feathers.\n",
              this_player());

      message("info", this_player()->query_cap_name()+" searches the pillow, "+
      "but doesn't find anything.\n",
              environment(this_player()),this_player());

      return 1;
    }

  pillowsearched = 1;

  message("info", "You search the pillow and find a knife.\n",this_player());
  message("info", this_player()->query_cap_name()+" searches the pillow and "+
          "finds a knife.\n",
          environment(this_player()), this_player());

  knife = new("/u/a/allanon/area/caverns_of_slime/obj/knife.c");

  if(knife->move(this_player()) != MOVE_OK)
    {
      message("info", "You can't carry the knife and drop it on the ground.\n",

              this_player());
      knife->move(environment(this_player()));
    }

  return 1;
}
