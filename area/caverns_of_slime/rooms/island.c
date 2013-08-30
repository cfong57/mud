#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_objects(([ "/u/a/allanon/area/caverns_of_slime/obj/fakegreenkey.c" : 1 ]));
  set_monsters( ([ "/u/a/allanon/area/caverns_of_slime/mon/slime.c" : 3 ]) );
  set_short( "On a small island, in the middle of a basin" );
  set_long( wrap("You are standing on a small protrudence of land that sticks up "+
  "out of the basin like a finger. It seems to be a natural feature, in that it's "+
  "formed from hard granite rock. There is a rather large black orb made of some kind "+
  "of crystal which resides on a pedestal in the middle of the island. Crackles of "+
  "powerful magic surround it.\n"));
  set_item_desc((["rock" : "Sturdy granite, which has weathered the years well.\n",
                  "pedestal" : "A fancy thing, made of solid gold. It's too heavy to move around.\n"]) );
  add_item( ({ "large black orb", "large orb", "black orb", "orb" }),
"It is definitely some kind of magic device. Looking at it closely, you think you can see a vision of the weather outside. The crystal seems to be some form of diamond...it's too bad the orb is too large to move.\n");
  add_item_search( ({ "large black orb", "large orb", "black orb", "orb" }), "search_orb");
  set_sounds(120, ({ "Something about this island and the orb pique your curiosity..."+
  "there doesn't seem to be a way off the island, and the orb seems like it "+
  "could do much more than simply show the weather.\n" }) );
  set_exit_msg( ([ "portal" : "$N enters the portal and disappears!" ]) );
  set_post_exit_function( ([ "portal" : "close_portal" ]));
  set_pre_exit_function( ([ "basin" : "prevent_move" ]));
  set_exits((["basin" : "/u/a/allanon/area/caverns_of_slime/rooms/basin.c"]));
}

int search_orb()
{
    {
      message("info", "You stroke the orb, and suddenly a magical portal forms in front of you!\n",
              this_player());

      message("info", this_player()->query_cap_name()+" strokes the orb, and suddenly a magical portal forms in front of him!\n",
              environment(this_player()),this_player());

      add_exit("portal", "/u/a/allanon/area/caverns_of_slime/rooms/ledge.c");
    }
}

int close_portal()
{
    {
      message("info", "The portal closes behind you.\n",
              this_player());

      message("info", "The portal seals itself, leaving no trace of its existance.\n",
              environment(this_player()),this_player());

      remove_exit("portal");
    }
}

int prevent_move()
{
    {
      message("info", "A strange force blocks you from leaving the island!\n",
              this_player());

      message("info", this_player()->query_cap_name()+" tries to leave the island, but a strange force seems to prevent the movement.\n",
              environment(this_player()),this_player());
      return 1;
    }
}

