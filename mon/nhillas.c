#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

void extra_create()
{
  set_reputation("The City of Vaerlon", 1000);
  set_short("Ereldon's personal bodyguard, Nhillas");
  set_long(wrap("A quite invincible-looking elf stands at guard here. He "+
  "hovers protectively around Ereldon, attempting to guard him from any "+
  "threat. Now you know where all of Ereldon's 'donations' go towards: hiring "+
  "personal security. Best not mess with either of them.\n"));
  set_name("Nhillas");
  set_id( ({ "ereldon's personal bodyguard", "ereldon's bodyguard", "bodyguard", 
  "nhillas", "elf"}) );
  set_level(100);
  set_race("elf");
  set_gender("male");
  set_agrochance(100);
  add_weapon("/u/a/allanon/obj/no_twin_rp");
  add_weapon("/u/a/allanon/obj/excalibur");
  add_random_armour("adamantium_full plate_breastplate",10);
  add_random_armour("adamantium_full plate_greaves",10);
  add_random_armour("adamantium_full plate_bracers",10);
  add_random_armour("adamantium_full plate_helmet",10);
  add_random_armour("adamantium_full plate_gauntlets",10);
  add_random_armour("adamantium_full plate_neck guard",10);
  add_random_armour("adamantium_full plate_boots",10);
  set_combat_kit("figher 5");
  set_following(0);
  set_inquiry(([
  "$GREET" : "Lay a hand on Ereldon and you're dead.\n",
  "$DEFAULT" : "Go away.\n"]));
  set_chat_output(({
  "Nhillas eyes you menacingly.\n",
  "Nhillas circles around Ereldon slowly, swords at the ready.\n"}));
  set_att_chat_output(({"Nhillas' eyes blaze with righteous indignation.\n"})); 
  set_chat_chance(3); 
  set_friend_message(
  "%^BOLD%^%^YELLOW%^Nhillas shouts: CEASE AND DESIST!%^RESET%^"); 
  set_natural_ac(100000);
  set_ac(100000);
  set_random_resistances(0);
  set_resistances(([ "acid" : 99, "psionic" : 99, "poison" : 99, 
  "fire" : 99, "asphyxiation" : 99, "cold" : 99, "physical" : 99, 
  "lightning" : 99, "sonic" : 99, "magical" : 99 ]));
}

int special_hit(object target)
{
  if(!random(4) && target)
   {
    message("damage","Nhillas CHOPS "+target->query_cap_name()+" with all "+
    "his might, reducing "+possessive(target)+" hit points by half!\n",
    environment(target),target);
    message("damage","Nhillas CHOPS you with all his might, reducing your "+
    "hit points by half!\n",target);
    target->set_hp((target->query_hp())/2);
    return 1;
   }
 return 1;
}

int query_df() {return 1000000000;}