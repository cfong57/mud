#include <mudlib.h>

inherit MONSTER;

void kill_bandit(object target);

void extra_init()
{
  string *ids;
  if (environment(this_object())) 
  {
    foreach (object o in all_inventory(environment(this_object()))) 
    { 
      ids = o->query_id();    
      if (member_array("bandit_ob", ids) != -1) 
      {
        if (o != this_object()) 
        {
          kill_bandit(o);  
          return;
        }
      }
    }    
  }
}

void extra_create()
{
  set_short("Icy spirit of the cruel torturer");
  set_long(wrap("If the torturer that ran this dungeon was frightening in "+
  "life, he is even moreso in death. Wielding twin swords, he coldly advances "+
  "upon you without mercy, intent on continuing what he did best - eliciting "+
  "pain and eventually death from living creatures. Two red orbs glow where "+
  "the eyes once would have been, but nonetheless you can swear they smirk "+
  "at you in an amused way - perhaps entertained that you were foolish enough "+
  "to come to this chamber of killing.\n"));
  set_name("Torturer");
  set_id( ({ "spirit", "torturer"}) );
  set_species("undead");
  set_race("human");
  set_level(15 + random(6));
  set_skill("twin weapons", 75);
  set_stat("size", 175);
  set_stat("strength", query_stat("strength") + 3);
  set_stat("strength", query_stat("dexterity") + 3);
  add_weapon("/u/a/allanon/area/lumber_camp/obj/ice_sword");
  add_weapon("/u/a/allanon/area/lumber_camp/obj/ice_sword");
  set_aggressive(1);
  set_following(50);
  set_gender("male");
  set_skin_data("type", "none");
  set_heartless(1);  
  set_forbidden_rooms(({"/u/a/allanon/area/lumber_camp/rooms/cottage_out"}));
}
  
void second_life()
{
  deep_inventory(this_object())->remove();
  message("info", "The spirit rages, 'mY...sTiLLeTO!' before disappearing "+
  "into a puff of nothingness. Apparently, it has departed for the Nether "+
  "Plane before finding whatever it was looking for.\n",
  environment(this_object()));
  deep_inventory(this_object())->remove(); 
  this_object()->remove(); 
}

/* could make a receive_object(stiletto), but that would be sort of weird since
he is an aggressive monster ... and what reward would he give, anyway? */

void kill_bandit(object target)
{
  message("aggro", ""+this_object()->query_cap_name()+" grins maliciously "+
  "and advances upon "+target->query_cap_name()+"!\n",
  environment(this_object()));
  this_object()->kill_ob(target);
}   