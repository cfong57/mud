#include <mudlib.h>

inherit MONSTER;

void set_password(string str)
{
  add_inquiry(({"@"+str+"", "@"+lower_case(str)+""}),"unlock_gate");
}

void extra_create()
{
  set_short("A ghostly guardsman, standing in front of the gate");
  set_long(wrap("The ghost of a former guardsman still stands in front of the "+
  "gate, guarding it for all eternity. He looks at you stoically, not moving "+
  "anything except his eyes. While most of the ghost's equipment seems to be "+
  "stuck in the spirit realm, the spear he carries is very real "+
  "indeed. You would do best not to irritate this ghost.\n"));
  set_name("Ghostly guardsman");
  set_id(({"ghostly guardsman", "guardsman", "guard", "ghost", "human",
  "undead"}));
  set_level(25);
  set_combat_kit("fighter 3");
  set_race("human");
  set_species("undead");
  set_gender("male");
  set_agrochance(40);
  set_following(0);
  add_random_weapon("random_spear", 6);
  set_inquiry(([
  "$GREET" : "If you don't know the password, move along.\n",
  "$DEFAULT" : "...\n"]));
}

void unlock_gate()
{
  mapping doors = environment(this_object())->query_doors();
  if(!doors || !sizeof(keys(doors)))
  {
    message("bug","Something has bugged in this room - couldn't find the "+
    "door. Contact a wiz.\n",environment(this_object()));	  
  }
  foreach(string dir, mapping data in doors)
  {
    if(data["status"] == "locked")
    {
      environment(this_object())->set_door_status (dir, "closed");
      environment(this_object())->update_link (dir);
      message("unlock","The ghostly guardsman unlocks the gate.\n",
      environment(this_object()));
      force_me("say Be careful, the gate re-locks automatically");
    }
    else
    {
	  force_me("say The gate's already unlocked");   
    }
  }
}