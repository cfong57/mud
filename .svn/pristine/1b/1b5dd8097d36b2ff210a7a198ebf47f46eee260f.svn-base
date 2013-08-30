#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_short("Ghostly servitor, wandering aimlessly");
  set_long(wrap("This pale ghost of a human wanders around the Bastion, "+
  "seemingly without purpose or direction. It may have been someone of "+
  "importance in life, and then again it may not have; the ghost doesn't "+
  "have enough features left to tell much about it. A chilling aura emanates "+
  "from the ghost, but other than that it is mostly a featureless, "+
  "human-shaped blob. Perhaps in time even this ghost will fade away to "+
  "nothingness, called back to the Nether Plane as all spirits eventually "+
  "are.\n"));
  set_name("Ghostly servitor");
  set_id(({ "ghostly servitor", "servitor", "ghost", "human", "undead"}));
  set_level(20);
  set_race("human");
  set_species("undead");
  set_gender("neuter");
  set_following(25);
}

int special_hit(object target) 
{
  if (!random(7)) 
  {
	message("damage","Water vapor condenses around the ghost, taking the "+
	"form of deadly ice slivers which RUSH ONWARDS towards "+
	"you!\n",target);
	message("damage","Water vapor condenses around the ghost, taking the "+
	"form of deadly ice slivers which RUSH ONWARDS towards "+
	""+target->query_cap_name()+"!\n",environment(target),target);
    target->wound(target->choose_body_part(), 300, "cold");
    target->wound_loop();     	
    return 1;
  }
  return 0;
}