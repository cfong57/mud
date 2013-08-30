#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Gakarzur, experienced-looking spelunker");
  set_long(
  wrap("This dark elf seems to be an expert in the area of cave exploration. You "+
  "can automatically assume, then, that he is also a treasure seeker. His tall frame "+
  "is flexible and muscled from years of spelunking. You think that he might have chosen "+
  "his career, not because he liked it, but because it would never require exposure "+
  "to harmful sunlight. You note that spelunkers often make decent livings, and their "+
  "trade isn't exactly seen as dubious by society - a win-win situation all around. You "+
  "notice, with some curiosity, that he seems to be a well-educated dark elf... whatever "+
  "drove him off the path of the scholar, you will never know. He seems "+
  "to somehow avoid attention of all the bats and slimes.\n"));

  set_name("Gakarzur");
  set_id( ({ "Gakarzur", "gakarzur", "spelunker", "dark elf"}) );
  set_level(17);
  set_race("dark elf");
  set_gender("male");
  set_speed(60+random(60));
  add_object("/u/a/allanon/area/caverns_of_slime/obj/metalbit.c");
  add_random_armour("rinexpensive_random_hauberk", 3+random(2));
  add_random_weapon("random_sabre", 3+random(2));
  add_random_stuff(1+random(3));
  set_agrochance(35);
  set_following(35);
  set_chat_chance(5);
  set_chat_output( ({
  "Gakarzur mutters something about bits and pieces.\n",
  "Gakarzur fiddles around with a small metal object...he seems to be trying to make something out of it.\n",
  "Gakarzur mutters to himself: Where could that damned key be?...\n",
  "Gakarzur proclaims: Ahh, the irony! This mere door keeps me bound...hand, foot, and tongue!\n"}));
  set_inquiry(([
    "$GREET": ({"Hello there, I don't suppose you would happen to have found any...ahh, nevermind!"}),
    "door" : "I just need to find the key to it...then the treasure is mine!",
    "treasure" : "It's nothing you'd be interested in!",
    "key" : "I wish I could find it!",
    ({ "bits and pieces", "bits", "pieces"}) : "What? None of your business!"]) );

  set_forbidden_rooms( ({ "/u/a/allanon/area/caverns_of_slime/rooms/barren_clearing",
                          "/u/a/allanon/area/caverns_of_slime/rooms/basin",
                          "/u/a/allanon/area/caverns_of_slime/rooms/passage" }));
}