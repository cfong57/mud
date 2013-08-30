#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Raban, a shifty-looking thief");
  set_long(
  wrap("You immediately check your belongings again after eyeing this shifty-looking "+
  "human. He looks able to steal just about anything...he's probably here on some "+
  "shady treasure-seeking venture. No doubt his appearance adds greatly to his "+
  "occupation - small, mousy, and furtive. His oily black hair has been grown out far "+
  "enough to serve as a sufficient eyeshade - it covers his right eye, leaving the left "+
  "one to stare you down silently. It is steel grey, and totally unreadable... He seems "+
  "to somehow avoid attention of all the bats and slimes.\n"));
  set_name("Raban");
  set_id( ({ "raban", "Raban", "thief", "human"}) );
  set_level(17);
  set_stat("size",160);
  set_race("human");
  set_gender("male");
  set_following(0);
  add_random_armour("rinexpensive_random_robe", 2);
  add_random_armour("rinexpensive_random_cape", 2);
  add_random_weapon("random_rapier", 1+random(2));
  add_random_weapon("random_knife", 3);
  add_random_stuff(1+random(3));
  set_agrochance(45);
  set_chat_chance(5);
  set_chat_output( ({ "Raban mutters a curse...something about a door.\n"}));
  set_inquiry(([
    "$GREET": ({"...What's your problem?..."}),
    "door" : "...It's locked. The treasure lies beyond...",
    "treasure" : "...I've heard it's good. What's it to you?...",
    "$DEFAULT": "...Leave me..."]) );
}