#include <mudlib.h>
#include <move.h>

inherit MONSTER;

mixed *passwords = ({"asdf", "ETAOIN SHRDLU", "lorem ipsum", "password",
"qwerty", "zzzzz"}); 

string password = ""+passwords[random(sizeof(passwords))]+"";

void receive_paper(object paper);

void extra_create()
{
  set_short("Phaedra, pitiful elf maiden bound in chains");
  set_long(wrap("This elf maiden was probably a beauty once, but she seems "+
  "quite sad and disheveled sitting against the wall here. There is a large "+
  "chain bound around the maiden's waist which sticks firmly into the wall, "+
  "limiting her movement to a 2 meter semicircle. However her hands are left "+
  "free, and you notice that she almost absentmindedly picks at the chain "+
  "without thinking about it. Her captors must be very confident in the "+
  "strength of the chain to leave her faculties alone. The maiden glances at "+
  "you passively, as if she has already been here so long that all hopes of "+
  "rescue have left her mind long ago. You notice on one corner of her "+
  "clothing there is an embossed rune; it looks like a crimson dagger.\n"));
  set_name("phaedra");
  set_id( ({ "Phaedra", "phaedra", "elf", "elf maiden", "maiden"}) ); 
  set_race("elf");
  set_gender("female");
  set_level(100);
  add_random_armour("random_random_shirt", 10);
  add_random_armour("random_random_tights", 10);
  add_random_armour("random_random_boots", 10);
  set_receive_object((["/u/a/allanon/obj/paper" : "receive_paper"]));
  set_spell("floating letters", 100);
  set_skill("magic lore", 100);
  set_inquiry(([
  "$GREET" : "...'paper'? 'reset'?\n",
  "$DEFAULT" : "...'paper'? 'reset'?\n",
  "paper": "paper_inquiry",
  "reset" : "reset_inquiry"]));
  call_out("do_letters", 1);
}

void do_letters()
{
  force_me("destroy letters");
  force_me("cast floating letters at "+password+"");
  call_out("do_letters", 60);
}

void paper_inquiry()
{
  object paper;
  message("info", "Phaedra gives you a paper.\n", this_player());
  message("info", "Phaedra gives "+this_player()->query_cap_name()+" a "+
  "paper.\n", environment(this_player()), this_player());
  paper = new("/u/a/allanon/obj/paper.c");
  paper->move(this_player(), 1);
  return;
}

void reset_inquiry()
{
  password = ""+passwords[random(sizeof(passwords))]+"";
  force_me("say Password reset.");
  return;
}

void receive_paper(object paper)
{
  object shroom;
  force_me("say ...");
  if (paper->query_message() == password)
  {
    force_me("say That's correct.");
    message("info", "Phaedra gives you a mushroom.\n", this_player());
    message("info", "Phaedra gives "+this_player()->query_cap_name()+" a "+
    "mushroom.\n", environment(this_player()), this_player());
    shroom = new("/u/n/neurotico/obj/shroom.c");
    shroom->move(this_player(), 1);
  } else {
    force_me("say That's wrong.");
  }
  paper->remove();
  return;
}

string query_password()
{
  return password;
}