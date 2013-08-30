#include <mudlib.h>

inherit ARMOR;

object shadow1;
object shadow2;

void extra_create() 
{
  set_identified(1);
  set_short("Allanonian amulet");
  set_long("This unique amulet can only be worn by Allanon. It grants various "+
  "special effects. The amulet itself is made of adamantium and looks nigh "+
  "indestructible.\n");
  set_id( ({"allanonian amulet", "amulet"}) );
  set_name("Allanonian amulet");
  set_slots( ({"amulet"}) );
  set_material("adamantium");
  set_type("full plate");
  set_type_desc("amulet");
  set_quality(100);
  set_size(175);
  set_wear_func("wear_me");
  set_remove_func("remove_me");
  armour_setup();
}

string query_special_feature() 
{ 
return "This amulet can only be worn by Allanon. It has some special features.";

} 

int wear_me()
{
  object p = this_player();
  if(p->query_name() == "allanon")
  { 
  message("wear","Your amulet pulsates in rainbow colors as you wear it.\n",p);
  message("wear","Allanon's amulet pulsates in rainbow colors as "+
  ""+subjective(p)+" wears it.\n",environment(p),p);
  shadow2 = new("/u/a/allanon/shadows/al_ef_shadow.c");
  shadow2->shadow_object(p);
  shadow2->check_status();
  shadow2->heal_me();
  call_out("change_func",0);
  return 1;
  }
  else
  {
  message("fail","Sorry, only Allanon can wear this eq.\n",p);
  return 0; 
  }
}

int remove_me()
{
 object p = this_player();
 this_object()->remove_shadow_1();
 p->remove_shadow_2();
 this_object()->set_short("Allanonian amulet");
 this_object()->set_name("Allanonian amulet");
 return 1;	
}

void change_func()
{
  shadow1 = new("/u/a/allanon/shadows/al_am_shadow.c");  
  shadow1->shadow_object(this_object());  
  shadow1->init_shadow();
}