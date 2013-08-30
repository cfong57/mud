#include <mudlib.h>
#include <daemons.h>

inherit MONSTER;

void extra_create()
{
  set_short("Ghost of the Queen, moving around haphazardly");
  set_long(wrap("This is the former Queen of the Bastion. While she might "+
  "have been beautiful in life, death has left her but a pale shade of her "+
  "living self. She seems to wander around without any particular purpose, "+
  "stopping here and there to relive long-ago memories, perhaps. One thing "+
  "you can't help but notice, though, is that the Queen's flaming red hair "+
  "persists even in death. This is odd, as ghosts tend to lose most of their "+
  "color. You also note with curiosity that whenever the Queen's hair touches "+
  "something, it seems to smolder...\n"));
  set_name("Queen's ghost");
  set_id(({ "ghost of the queen", "ghost", "queen", "human", "undead"}));
  set_level(30);
  set_race("human");
  set_species("undead");
  add_armour("/u/a/allanon/area/ity/obj/kingkey.c");
  set_gender("female");
  set_following(25);
}

int special_hit(object target) 
{
  if (!random(7)) 
  {
	message("info","A lock of the Queen's hair touches you!\n",target);
	message("info","A lock of the Queen's hair touches "+
	""+target->query_cap_name()+"!\n",environment(target),target);
    message("fire", "%^BOLD%^%^RED%^", target);
    DAMAGE_D->add_special_state(target, "flame", 30 + random(90), 
    35 + random(15), target->choose_body_part());
    message("fire", "%^RESET%^", target); 	
    return 1;
  }
  return 0;
}