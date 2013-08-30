/*Inspired by BoFII weapon of the same name. Coded by Allanon, enjoy.*/

#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

int df = 0;
object pshadow;
object shadow;

void extra_create()
{
  set_identified(1);
  set_short("Sacred blade 'NoTwinRP'");
  set_id(({"sacred blade", "blade", "NoTwinRP", "rapier", "notwinrp", 
  "silver rapier", "No Twin Rapier", "no twin rapier"}));
  set_long(wrap("This sacred blade has been blessed by all the elements. It "+
  "pulses with a chromatic light and a strong auru of holiness can be felt "+
  "surrounding the weapon. The weapon is so named because only one has been "+
  "known to exist, and weaponsmiths have found it impossible to forge a "+
  "suitable copy of it.\n"+
  "There's an inscription engraved in the blade...\n"+
  "'Sacred powers...Cast forth your purifying light on these corrupt souls.\n"+
  "Rest in peace, sinners!'\n"));
  set_name("No Twin Rapier");
  set_wtype("rapier");
  set_material("mithril");
  set_quality(100);
  set_wield_func("wield_me");
  set_remove_func("remove_me");
  add_magic_property("fire",5);
  add_magic_property("cold",5);
  add_magic_property("lightning",5);
  add_magic_property("light",5);
  weapon_setup();
}

string query_special_feature() 
{ 
return wrap("This weapon suffers no neophyte to wield it.\n"+
"The strength of this weapon depends heavily on your Divine Favors.\n"+
"It deals extra damage to undead.");
} 

int wield_me()
{  
  object p = this_player();
  if(p->query_player() == 0)
  {
  return 1;	  
  }
  else
  {
  message("info","You feel like the NoTwinRP tests your worthiness "+
  "before letting you wield it...\n",p);
  if(p->query_free_dfavor() < 250000)
  {
  message("wield_fail",wrap("A voice inside your head says: 'You who try to "+
  "wield this sacred blade...thou art not a devout follower of the elements! "+
  "Begone!'."),p);
  return 0;
  }
  else
  {
  message("wield_success",wrap("A voice inside your head says: Owner of this "+
  "sacred blade, the gods favor you with their blessings. Wield this weapon "+
  "with honor and strike down thy unworthy foes!'.\n"),p);
  df = p->query_free_dfavor();
  pshadow = new("/u/a/allanon/shadows/no_twin_pshadow.c");
  pshadow->shadow_object(this_player());
  pshadow->adjust_physresist();
  call_out("change_func",0);
  return 1;
  }
  }
}

int remove_me()
{
 object p = this_player();
 df = 0;
 p->remove_this_shadow();
 this_object()->remove_shadow_func();
 this_object()->set_short("Sacred blade 'NoTwinRP'");
 return 1;	
}

int special_hit(object target)
{
  object p = this_object()->query_user();	
  if(target->query_species() == "undead" || target->query_race() == "undead")
  {
      message("damage",""+p->query_cap_name()+"'s NoTwinRP glows "+
      "%^BOLD%^%^WHITE%^BRIGHT WHITE%^RESET%^ as a bolt of chromatic energy "+
      "flies from the blade, striking you!\n",target);
      message("damage",""+p->query_cap_name()+"'s NoTwinRP glows "+
      "%^BOLD%^%^WHITE%^BRIGHT WHITE%^RESET%^ as a bolt of chromatic energy "+
      "flies from its blade, striking "+target->query_cap_name()+"!\n",
      environment(target),({target,p}));
      message("damage","Your NoTwinRP glows "+
      "%^BOLD%^%^WHITE%^BRIGHT WHITE%^RESET%^ as a bolt of chromatic energy "+
      "flies from its blade, striking "+target->query_cap_name()+"!\n",p);
      target->receive_damage(0.01*df+random(1500), LIGHTNING);
      if(target->query_hp()>1)
      {
	  target->receive_damage(0.03*df+random(1250), FIRE);   
      }
      if(target->query_hp()>1)
      {
	  target->receive_damage(0.05*df+random(750), COLD);  
      }  
      if(target->query_hp()>1)
      {
	  target->receive_damage(0.04*df+random(1000), PHYSICAL);   
      }
  }
}

int query_df()
{
 return df;	
}

void change_func()
{
  shadow = new("/u/a/allanon/shadows/no_twin_rp_shadow.c");
  shadow->shadow_object(this_object());
  shadow->init_shadow();
}

int query_damage() { return (1 + (df * 0.001)); }  