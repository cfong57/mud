#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Disembodied hand, searching for victims");
  set_long(wrap(
  "This is a disembodied hand. Basically, the hand of some creature that has "+
  "been severed from the corpse and animated by clandestine means. The hand "+
  "levitates about half a meter above the ground, somehow managing to "+
  "negotiate its way around obstacles and avoiding collisions. The hand is "+
  "not quite skeletal yet, but a lot of the flesh has already decomposed and "+
  "the nails have fallen off. The hand clutches a weapon and is covered in a "+
  "glove, and it looks to be actively hunting fresh blood. As it notices you "+
  "eyeing it, it suddenly turns in your direction and zooms straight at you, "+
  "weapon at the ready.\n"));
  set_name("disembodied hand");
  set_id(({ "disembodied hand", "hand"})); 
  set_species("undead");
  set_gender("neuter");
  set_level(50);
  set_agrochance(100);
  set_aggressive(1);
  set_speed(50+random(25));
  set_following(100);
  set_env("MIN", "$N floats into the room from $D."); 
  set_env("MOUT", "$N floats $D and out of the room.");
  set_body_parts(({"hand", 100, 1, "hand"}));
  set_slots((["hand" : (["hand" : 0 ])]));
  set_weapon_slots(([ "hand" : 0 ]));
  add_armour("/u/a/allanon/area/caywin/obj/glove");
  switch(random(15))
  {
  case 0:
  add_random_weapon("random_sabre",random(8));
  break;
  case 1:
  add_random_weapon("random_rapier",random(8));
  break;
  case 2:
  add_random_weapon("random_dagger",random(8));
  break;
  case 3:
  add_random_weapon("random_knife",random(8));
  break;
  case 4:
  add_random_weapon("random_cutlass",random(8));
  break;
  case 5:
  add_random_weapon("random_hand axe",random(8));
  break;
  case 6:
  add_random_weapon("random_hammer",random(8));
  break;
  case 7:
  add_random_weapon("random_club",random(8));
  break;
  case 8:
  add_random_weapon("random_mace",random(8));
  break;
  case 9:
  add_random_weapon("random_morningstar",random(8));
  break;
  case 10:
  add_random_weapon("random_shortsword",random(8));
  break;
  case 11:
  add_random_weapon("random_whip",random(8));
  break;
  case 12:
  add_random_weapon("random_sickle",random(8));
  break;
  case 13:
  add_random_weapon("random_crowbar",random(8));
  break;
  case 14:
  add_random_weapon("random_pick",random(8));
  break;
  }
  set_stat("size",50);
  set_stat("strength",(this_object()->query_stat("strength"))+20);
  set_stat("dexterity",(this_object()->query_stat("dexterity"))+15);
  set_heartless(1);
  set_wealth(([ "mithril" : 0, "platinum" : 0, "gold" : 0, "silver" : 0 ]));  
  set_friends(({"/u/a/allanon/area/caywin/mob/hand"}));
  set_friend_message(
  "Another hand advances on you as you attack Disembodied hand!");
  set_skill("melee", 100);
  set_skill("parry", 100);
  set_skill("weapon parry", 100);
  set_skill("block", 100);
  set_skill("dodge", 100);
  set_skill("avoid hits", 100);
  set_skill("swords", 100);
  set_skill("hammers", 100);
  set_skill("maces", 100);
  set_skill("flails", 100);
  set_skill("axes", 100);
  set_skill("hammers", 100);
  set_skill("continuous assault", 100);
  set_skill("slashing weapons", 100);
  set_skill("piercing weapons", 100);
  set_skill("bludgeoning weapons", 100);
  set_skill("contact reflexes", 100);
  set_skill("concentrated attack", 100);
  set_skill("concentrated defence", 100);
  set_skill("light armours", 100);
  set_skill("medium armours", 100);
  set_skill("heavy armours", 100);
  set_skill("enhance criticals", 100);
  set_skill("blind fighting", 100);
  set_skill("combat analysis", 100);
  set_skill("combat sense", 100);
  set_skill("controlled retreat", 100);
  set_skill("counter-attack", 100);
  set_skill("defensive battle strategy", 100);
  set_skill("offensive battle strategy", 100);
  set_skill("find weakness", 100);
  set_skill("target focusing", 100);
  set_skill("knowledge of weapons", 100);
  set_skill("magical defences", 100);
  set_skill("martial arts", 100);
  set_skill("brawling", 100);
  set_skill("natural", 100);
  set_skill("unarmed fighting", 100);
  set_skill("vital points", 100);
  set_skill("wilderness retreat", 100);
  set_skill("wipe tracks", 100);
  set_skill("rural combat", 100);
  set_skill("swing", 100);
  set_skill("slash", 100);
  set_skill("pierce", 100);
  set_skill("bludgeon", 100);
  set_skill("chop", 100);
  set_skill("flail", 100);
  set_skill("impale", 100);
  set_skill("thrust", 100);
  set_skill("crush", 100);
  set_skill("pound", 100);
  set_skill("cleave", 100);
  set_skill("slash", 100);
  set_skill("stab", 100);
  set_skill("move silently", 100);
  set_skill("hide in shadows", 100);
  set_skill("camouflage", 100);
  set_skill("rural concealment", 100);
  set_skill("blind fighting", 100);
  set_skill("tracking", 100);
  set_skill("pathfinding", 100);
  set_natural_weapons((["fist" : ([ "type" : "bludgeoning", "dam" : 75 ])]));
  //Otherwise can't wield weapons in 'hand'...
}