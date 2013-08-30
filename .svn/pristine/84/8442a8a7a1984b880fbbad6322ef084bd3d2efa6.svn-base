#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

void extra_create()
{
  set_short("huge and horrifying black slime");
  set_long(wrap("A huge blob of black ooze sits before you. It lets off a "+
  "disgusting odor, and glue-like mucus pools around it. An enormous eyeball, "+
  "the size of a dinner plate, stares at you from deep within the "+
  "semitransparent blob. The slime's size has enabled it to form permanent "+
  "bodyparts: you spot eight tentacle-like arms and some odd pipe-like "+
  "appendages. Something golden glints within the blob, but you have no "+
  "idea what it could be.\n"));

  set_name("black slime");
  set_id(({"black slime", "slime", "huge slime"}));
  set_level(25);
  set_race("slime");
  set_species("monster");
  set_aggressive(1);
  
  /* Zal was here 060905
  set_body_parts(({
	               "body", 40, 1, "body",
	               "eye", 1, 10, "eye",
	               "first tentacle", 5, 2, "first tentacle",
	               "second tentacle", 5, 2, "second tentacle",
	               "third tentacle", 5, 2, "third tentacle",
	               "fourth tentacle", 5, 2, "fourth tentacle",
	               "fifth tentacle", 5, 2, "fifth tentacle",
	               "sixth tentacle", 5, 2, "sixth tentacle",
	               "seventh tentacle", 5, 2, "seventh tentacle",
	               "eighth tentacle", 5, 2, "eighth tentacle",
	               "appendages",19, 7, "appendages"}));
  */  
	set_body_parts(({
	               "body", 40, 1, "body",
	               "eye", 1, 4, "eye",
	               "first tentacle", 5, 1, "first tentacle",
	               "second tentacle", 5, 1, "second tentacle",
	               "third tentacle", 5, 1, "third tentacle",
	               "fourth tentacle", 5, 1, "fourth tentacle",
	               "fifth tentacle", 5, 1, "fifth tentacle",
	               "sixth tentacle", 5, 1, "sixth tentacle",
	               "seventh tentacle", 5, 1, "seventh tentacle",
	               "eighth tentacle", 5, 1, "eighth tentacle",
	               "appendages",19, 2, "appendages"}));
	             
  set_stat("size",300);

  add_natural_weapon("first tentacle", "bludgeoning", 1, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("second tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("third tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("fourth tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("fifth tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("sixth tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("seventh tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));
  add_natural_weapon("eighth tentacle", "bludgeoning", 0, ({PHYSICAL, 50, ACID, 50}));

  natural_weapon_damage(10);
  set_hand_priorities(({"first tentacle", "second tentacle", "third tentacle",
                        "fourth tentacle", "fifth tentacle", "sixth tentacle",
                        "seventh tentacle", "eighth tentacle", }));

  set_gender("neuter");
  set_skin_data("type", "none");
  add_object("/u/a/allanon/area/caverns_of_slime/obj/heart");
  add_object("/u/a/allanon/area/caverns_of_slime/obj/blackbplate");
  set_resistance("acid",150);
  set_following(0);
}

int special_hit(object target)
{
  if(!random(15) && target)
   {
    message("damage","Black slime wiggles for a second before shooting a "+
    "large wash of acid from one of its pipe-like "+
    "appendages, hitting "+target->query_cap_name()+"!\n",
    environment(target),target);
    message("damage","Black slime wiggles for a second before shooting a "+
    "large wash of acid at you from one of its pipe-like appendages!\n",target);
    target->receive_damage(70+random(40), ACID);
    return 1;
   }

 return 1;
}