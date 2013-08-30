#include <mudlib.h>
#include <move.h>

inherit ROOM;
int poolsearched=0;

void extra_create()
{
  set_short( "Deep in the caves, next to a pool of ooze" );
  set_monsters( ([ "/u/a/allanon/area/caverns_of_slime/mon/slime.c" : 2 ]) );
  set_long( wrap("You are standing next to an enormous pool of luminescent "+
  "green ooze. It burbles and squelches quite loudly, and huge bubbles rise "+
  "and pop on the surface occasionally. You see that the fog comes from the "+
  "pool. Some skeletal limbs can be spotted sticking out of the ooze, and you "+
  "keep a wary distance from the edge of the pool.\n"));
  set_item_desc((["bubbles" : "They splatter ooze whenever they pop, but "+
                  "you don't really care, you're dirty enough as it is.\n",
                  "limbs" : "The remains of those poor unlucky fools who "+
                  "drowned in the pool.\n",
                  "fog" : "The fog is pale green, and seems to float around at"+
                  " random. It's difficult to breathe it and you wonder if "+
                  "it's possibly toxic.\n",
                  "pool": "The pool is full of noxious slime and looks really "+
                          "non-inviting", ]) );

  add_item( ({ "pool" }),
            "It's huge. You know of no creature that could make this, but at "+
            "the same time you doubt it is a natural feature.\n");

  add_item_search( ({ "pool" }), "search_pool");

  set_light(50);
  set_water(5);
  set_sounds(120, ({
	                "The pool squelches loudly. Large bubbles rise to the "+
	                "surface and burst.\n",
	                "Clouds of the fog drift around lazily. They make you feel"+
	                " sleepy...\n",
	                "You are curious as to what may be hidden in the ooze.\n"}) );
  set_exits(
  (["north" : "/u/a/allanon/area/caverns_of_slime/rooms/hole.c"]));
}


int search_pool()
{
  object key;

  if(poolsearched)
    {
      message("info", "You reach deep into the pool, but you don't find "+
      "anything.\n",
              this_player());

      message("info", this_player()->query_cap_name()+" reaches deep into the "+
      "pool, but doesn't find anything.\n",
              environment(this_player()),this_player());

      return 1;
    }

  poolsearched = 1;

  message("info", "You reach deep into the pool, and after fishing around for "+
  "a while pull out a key.\n",this_player());
  message("info", this_player()->query_cap_name()+" searches the pool and "+
          "finds a key.\n",
          environment(this_player()), this_player());

  key = new("/u/a/allanon/area/caverns_of_slime/obj/fakeredkey.c");

  if(key->move(this_player()) != MOVE_OK)
    {
      message("info", "You can't carry the key and drop it on the ground.\n",

              this_player());
      key->move(environment(this_player()));
    }

  return 1;
}
