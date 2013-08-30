#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Dorrah, riled-looking graverobber");
  set_long(
  wrap("An angry little leprechaun female stands defiantly before you. She seems "+
  "determined to block your passage, for reasons unknown to you. Drool escapes her "+
  "quivering jaws and her eyes betray madness...you wonder how she even manages "+
  "to make a decent living with that sort of appearance. While she looks harmless enough "+
  "in this mental state, you take note that she has an unsheathed blade ready at hand. "+
  "It probably would be wise to leave her alone to her insanity. She seems "+
  "to somehow avoid attention of all the bats and slimes.\n"));
  set_name("Dorrah");
  set_id( ({ "dorrah", "graverobber", "leprechaun"}) );
  set_level(17);
  set_race("leprechaun");
  set_gender("female");
  add_random_armour("random_random_random", 2);
  add_random_armour("random_random_random", 2);
  add_random_weapon("random_dagger", 3);
  add_random_stuff(1+random(3));
  set_agrochance(60);
  set_chat_chance(5);
  add_object("/u/a/allanon/area/caverns_of_slime/obj/fakebluekey");
  set_inquiry(([
    "$GREET": ({"Yew! What yew doin' here? Git lost!"}),
    "$DEFAULT" : ({"What yew want? Git lawst, Ah sehd!"})]) );
  set_chat_output( ({ "Dorrah shouts: Bits an' pieces, bits an' pieces! Set o' four! Hee hee...",
                      "Dorrah carefully strokes a small blue something in her hands." }));
  set_att_chat_output( ({ "Dorrah hollers: Yew bast...bast...bast...Yew evyl person!\n" }));
  set_blocking_dirs( (["east" : "The deranged little leprechaun cackles and bars your way east.\n" ]) );
}

