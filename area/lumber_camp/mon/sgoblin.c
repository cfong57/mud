#include <mudlib.h>
#include <modules.h>
#include <move.h>

inherit MONSTER;
inherit M_REPUTATION;

void extra_create()
{
  set_reputation("The Fellowship of Rangers", -15 - random(7));
  set_short("A skinny goblin eating voraciously");
  set_long(wrap("This goblin is greedily eating everything in sight, "+
  "devouring the lumber camp's precious food supplies. He has an axe at his "+
  "side, so he must have been a lumberjack also. You think that his hunger "+
  "finally got the better of him, and he broke into this storehouse when "+
  "nobody was watching to eat his fill. There is a slightly mad gleam to his "+
  "eyes, you think it would be a bad idea to interrupt his gorging.\n"));
  set_name("Skinny goblin");
  set_id( ({ "A skinny goblin eating voraciously", 
  "a skinny goblin eating voraciously", "a skinny goblin", 
  "skinny goblin eating voraciously", "skinny goblin", "goblin"}) );
  set_level(21);
  set_race("goblin");
  set_gender("male");
  set_agrochance(25);
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/crisp_rye-bread.c");
  add_object("/obj/food/waybread.c");
  add_object("/obj/food/waybread.c");
  add_object("/obj/food/waybread.c");
  add_object("/obj/food/waybread.c");
  add_random_weapon("fine steel_battle axe", 5, ({"left hand", "right hand" }));
  set_following(0);
  set_chat_output(({
  "The skinny goblin continues to scarf down food, apparently oblivious to "+
  "your presence.\n",
  "The skinny goblin demolishes a loaf of bread in less than ten seconds.\n",
  "Crumbs and debris fly everywhere as the skinny goblin eats.\n"}));
  set_att_chat_output(({"Skinny goblin attacks ferociously, extremely "+
  "irritated at having his meal interrupted.\n"})); 
  set_chat_chance(3);
}

int special_hit(object target)
{
  if (!random(7) && target) {
    object bread;
    message("damage", "The goblin chucks a loaf of bread at "+
    ""+target->query_cap_name()+"!\n", environment(target), target);
    message("damage", "The goblin chucks a loaf of bread at you!\n", target);
    target->receive_damage(5 + random(5));
    switch (random(3))
    {
      case 0:
      bread = new("/obj/food/crisp_rye-bread.c");
      break;
      case 1:
      bread = new("/obj/food/waybread.c");
      break;
      case 2:
      bread = new("/obj/food/bread.c");
      break;
    }
    bread->move(target);
    return 1;
  }
  return 0;
}