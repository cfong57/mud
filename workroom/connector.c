#include <config.h>
#include <mudlib.h>
#include <move.h>

inherit ROOM;

void extra_create()
{
  set_short( "Allanon's connector-room" );
  set_long(wrap("This room contains exits to various places. Its sole purpose "+
  "is to make Central Square II look less cluttered.\n"));
  set_exits(([
  "back" : "/u/a/allanon/workroom/allanon_workroom",
  "underwater" : "/u/a/allanon/workroom/underwater_room",
  "example_tour" : "/examples/room/tour_portal",
  "clearing" : "/u/a/allanon/area/caverns_of_slime/rooms/barren_clearing",
  "graemor" : "/d/graemor/virtual/9,18.graemor-part1",
  "no_exit" : "/u/a/allanon/workroom/noexit1",
  "cell" : "/u/a/allanon/workroom/cell",
  "glade" : "/u/a/allanon/area/lumber_camp/rooms/glade",
  "atherton" : "/u/b/belannaer/virtual/14,13.atherton",
  "cenedoiss" : "/u/b/belannaer/virtual/18,27.cenedoiss",
  "teladan" : "/u/t/tarak/areas/town/rooms/f8",
  "ity" : "/u/i/ity/area/town/room/bastion",
  "wizzies" : "/d/std/wiz/wiz_cs",
  "portal" : "/u/a/allanon/workroom/portal",
  "void" : VOID,
  "shop" : "/u/a/allanon/workroom/shop",
  "arboreum" : "/u/a/allanon/workroom/arboreum",
  "chess" : "/u/a/allanon/chess/chessroom"]));
  set_exit_msg(([ 
  "back" : "$N goes back to Central Square II.",
  "graemor" : "$N goes to visit Virzuduz in Graemor.",
  "atherton" : "$N decides to visit unfinished, virtual Atherton.",
  "teladan" : "$N goes to visit the Forbidden City, Teladan.",
  "cenedoiss" : "$N decides to visit the new Teladan, Cenedoiss.",
  "wizzies" : "$N trudges wearily to Wiz's Domain.",
  "void" : "$N leaves to the ' '.",
  "shop" : "$N decides to go shopping.",
  "portal" : "$N steps through the Portal of Possibilities.",
  "arboreum" : "$N goes to test out the shrubbery commands.",
  "chess" : "$N goes to play chess."])); 
}