#include <mudlib.h>

inherit FOOD;

void extra_create()
{
  set_short("Plate of delicious food");
  set_long(wrap("This is a huge plate heaped with your favorite kind of food. "+
  "It looks absolutely delicious, and you can't wait to eat it. A faint aura "+
  "of magic surrounds the food, and you get a sort of healing feeling from "+
  "it.\n"));
  set_id( ({ "food", "plate of delicious food", "plate", "delicious food"}) );
  set_edible(1);
  set_food_value(999);
  set_ep_value(0);
  set_mass(1);
  set_bulk(1);
  set_rot_time(0);
  set_prevent_get(1);
  set_prevent_drop(1);
  set_eat_func("eat_me");
}

void eat_me()
{
  message("info","That food tasted amazing!\nYou feel fully recovered!\n",
  this_player());
  message("info",""+this_player()->query_cap_name()+" seems to recover fully "+
  "after eating the food.\n",environment(this_player()),this_player());
  this_player()->receive_healing(this_player()->query_max_hp(),"hp");
  this_player()->receive_healing(this_player()->query_max_sp(),"sp");
  this_player()->receive_healing(this_player()->query_max_ep(),"ep");
  this_player()->receive_healing(this_player()->query_max_psp(),"psp");
  this_player()->set_blind(0);
  this_player()->remove_all_diseases();
  this_player()->remove_stun();
  this_player()->set_uncon(0);
  this_player()->unblock_me();
  this_player()->remove_wound();
  this_player()->remove_silence_shadow();
}