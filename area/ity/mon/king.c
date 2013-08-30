#include <mudlib.h>
#include <daemons.h>

inherit MONSTER;

void extra_create()
{
  set_short("A temporary ghost, representing the King");
  set_long(wrap("This ghost is a stand-in for the King that Ity will code "+
  "eventually. He has a mind-melting special.\n"));
  set_name("temporary king");
  set_id(({ "temporary ghost", "ghost", "undead", "human", "king"}));
  set_level(35);
  set_race("human");
  set_species("undead");
  set_gender("male");
  set_following(25);
}

int special_hit(object target) 
{
  if (!random(7)) 
  {
	force_me("say Kneel before me!");
    message("psionic", "%^BOLD%^%^MAGENTA%^", target);
    DAMAGE_D->add_special_state(target, "psionic", 30 + random(45), 
    35 + random(15), target->choose_body_part());
    message("psionic", "%^RESET%^", target); 	
    return 1;
  }
  return 0;
}