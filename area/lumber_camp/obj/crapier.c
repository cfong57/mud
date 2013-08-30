#include <mudlib.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
 set_short("Brass rapier of Nature %^BOLD%^%^YELLOW%^(sizzling)%^RESET%^");
  set_id(({"brass rapier of Nature", "brass rapier of nature", 
  "brass rapier", "rapier", "rapier of Nature", "rapier of nature"}));
  set_long(wrap("The blade of this rapier seems to be charged with lightning. "+
  "It crackles and sizzles, throwing off electric sparks at random. The "+
  "charge is so strong that the rapier seems to vibrate of its own accord. A "+
  "single rune in the shape of a massive tree graces the blade, perhaps "+
  "reminiscent of a treant. Somehow, the weapon reminds you of the natural "+
  "vitality that positively bursts from a healthy, green forest.\n"));
  set_name("rapier of nature");
  set_wtype("rapier");
  set_material("brass");
  set_quality(25);
  add_magic_property("hpmax", 1);
  add_magic_property("lightning damage", 1);
  weapon_setup();
}

string query_special_feature() 
{ 
  return "It can sometimes stun opponents with its electrical charge.";
} 

int special_hit(object target)
{
  if (!random(10)) {
    if (target->query_stunned()) {  
      object plr = this_object()->query_user();
      message("stun", ""+target->query_cap_name()+" writhes as an electrical "+
      "discharge from your rapier stuns "+objective(target)+" further.\n", 
      plr);
      message("stun", ""+target->query_cap_name()+" writhes as an electrical "+
      "discharge from "+plr->query_cap_name()+"'s rapier stuns "+
      ""+objective(target)+" further.\n", environment(target), ({target, plr}));
      message("stun", "An electrical discharge from "+
      ""+plr->query_cap_name()+"'s rapier hits you, prolonging your stun.\n",
       target);
      target->add_stun_duration(5); 
    } else {
      object plr = this_object()->query_user();         
      message("stun", ""+target->query_cap_name()+" gets stunned from a bolt "+
      "of lightning which leaps from your rapier!\n", plr);
      message("stun", ""+target->query_cap_name()+" gets stunned from a bolt "+
      "of lightning which leaps from "+plr->query_cap_name()+"'s "+
      "rapier!\n", environment(target), ({target, plr}));
      message("stun", "A bolt of lightning leaps from "+
      ""+plr->query_cap_name()+"'s rapier, stunning you!\n", target);
      target->stun(10);         
    } 
    return 1;
  }
  return 0;
}