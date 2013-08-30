#include <mudlib.h>
#include <damage.h>
#include <daemons.h>

inherit MONSTER;

int type = 0;

int bluefire()
{
  if(type != 0)
   message("info", "Suddenly the nether bat transforms in front of you into a bluefire "+
                   "bat.\n",environment(this_object()));

  type = 0;
  set_id(({"bluefire bat", "bat"}));
  set_short("bluefire bat, covered in freezing fire");
  set_long(wrap("This monster is a distant cousin of the common cave bat. A "+
  "genetic mutation has given them the peculiar ability to resist ice, "+
  "enough so that they are constantly engulfed in freezing blue flames. "+
  "Cold, icy-blue eyes and teeth sharper than stilettos give it a quite fearsome "+
  "appearance. A chill wind akin to that of death seems to follow in its wake.\n"));

  set_race("bluefire bat");
  set_name("bluefire bat");

  add_natural_weapon("claws", "slashing", 1, ({PHYSICAL, 70, COLD, 30}));
  add_natural_weapon("fangs", "piercing", 0, ({PHYSICAL, 90, COLD, 10}));
  add_natural_weapon("body", "bludgeoning", 0, ({PHYSICAL, 10, COLD, 90}));
  add_natural_weapon("wings", "bludgeoning", 0, ({PHYSICAL, 50, COLD, 50}));

  set_hand_priorities( ({ "body", "wings", "claws", "fangs" }) );
  set_resistance("cold",200);
  set_resistance("fire",-25);
  set_skin_data("bonuses", (["resist cold": 1+random(1),
                             "spell ice": 1,
                             "skill mastery of ice": 1]));
}

int nether_bat()
{
  if(type != 1)
   message("info", "Suddenly the bluefire bat transforms in front of you into a "+
                   "nether bat!\n",environment(this_object()));

  type = 1;
  set_id(({"nether bat", "bat"}));
  set_short("nether bat, covered in scorching flames");
  set_long(wrap("This monster is a distant cousin of the common cave bat. A "+
  "genetic mutation has given them the peculiar ability to resist fire, "+
  "enough so that they are constantly aflame. Flaring red eyes and teeth "+
  "sharper than stilettos give it a quite fearsome appearance. It constantly "+
  "drips fire as it flies around, and you are glad that it is confined to this "+
  "cave - it would cause untold ruin if let loose in the wild.\n"));

  set_race("nether bat");
  set_name("nether bat");

  add_natural_weapon("claws", "slashing", 1, ({PHYSICAL, 70, FIRE, 30}));
  add_natural_weapon("fangs", "piercing", 0, ({PHYSICAL, 90, FIRE, 10}));
  add_natural_weapon("body", "bludgeoning", 0, ({PHYSICAL, 10, FIRE, 90}));
  add_natural_weapon("wings", "bludgeoning", 0, ({PHYSICAL, 50, FIRE, 50}));
  set_hand_priorities( ({ "body", "wings", "claws", "fangs" }) );

  set_resistance("fire",200);
  set_resistance("cold",-25);
  set_skin_data("bonuses", (["resist fire": 2+random(3),
                             "spell fire": 1,
                             "skill mastery of fire": 1,]));
}

void extra_create()
{
  bluefire();
  set_level(16);
  set_species("undead");
  set_body_parts(({
	               "body", 20, 1, "body",
	               "left wing", 15, 2, "left wing",
	               "right wing", 15, 2, "right wing",
	               "left leg", 10, 3, "left leg",
	               "right leg", 10, 3, "right leg",
	               "eyes", 3, 5, "eyes",
	               "head", 7, 4, "head",
	               "right claw", 10, 3, "right claw",
	               "left claw", 10, 3, "left claw"}));

  add_natural_weapon("claws", "slashing", 1, ({PHYSICAL, 70, FIRE, 30}));
  add_natural_weapon("fangs", "piercing", 0, ({PHYSICAL, 90, FIRE, 10}));
  add_natural_weapon("body", "bludgeoning", 0, ({PHYSICAL, 10, FIRE, 90}));
  add_natural_weapon("wings", "bludgeoning", 0, ({PHYSICAL, 50, FIRE, 50}));
  set_hand_priorities( ({ "body", "wings", "claws", "fangs" }) );
          
  set_slots(([
              "body" : ([ "body" : 0 ]),
              "wing" : (["right wing" : 0, "left wing" : 0 ]),
  			  "leg" : ([ "left leg" : 0, "right leg" : 0 ]),
  			  "eyes" : ([ "eyes" : 0 ]),
  			  "head" : ([ "head" : 0  ]),
  			  "claw" : (["right claw" : 0, "left claw" : 0 ]) ]));

  set_stat("size",75);
  set_gender("neuter");
  set_aggressive(1);
  set_skin_data("value", 500+random(1000));
  set_skin_data("type", "demonhide");

  set_speed(60 + random(45));
  set_forbidden_rooms( ({ "/u/a/allanon/area/caverns_of_slime/rooms/barren_clearing",
                          "/u/a/allanon/area/caverns_of_slime/rooms/basin",
                          "/u/a/allanon/area/caverns_of_slime/rooms/passage" }));
 call_out("check_type",5);
}

int special_hit(object target)
{
 if(!random(15) && target)
  {
   switch(type)
    {
	 case 0:
      message("damage","Bluefire bat suddenly rushes forwards, tackling "+
                       target->query_cap_name()+" with ice!\n",environment(target),target);
      message("damage","Bluefire bat suddenly rushes forwards, hitting "+
                       "you with a freezing tackle!\n",target);
      target->receive_damage(50+random(25), COLD);
	 break;
	 case 1:
      message("damage","Nether bat suddenly rushes forwards, tackling "+
                       target->query_cap_name()+" with fire!\n",environment(target),target);
      message("damage","Nether bat suddenly rushes forwards, hitting "+
                       "you with a burning tackle!\n",target);
      target->receive_damage(50+random(25), FIRE);
	 break;
    }
  }

 return 1;
}

int query_is_day()
{
 string look_msg=WEATHER_D->query_current_day_phase();
 return strsrch(look_msg,"sun")>-1;
}

int check_type()
{
 if(this_object()->query_battleob())
  {
   call_out("check_type",5);
   return 1;
  }
 
 if(query_is_day() == 1 && type == 1)
  bluefire();
 else if(query_is_day() == 0 && type == 0)
  nether_bat();

 call_out("check_type",5);
}