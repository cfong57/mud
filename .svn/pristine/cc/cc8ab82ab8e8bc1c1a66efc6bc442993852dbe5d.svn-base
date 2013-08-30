#include <mudlib.h>
#include <damage.h>
#include <move.h>

inherit WEAPON;

int special = 0;

#define LOCATION "/u/a/allanon/area/ity/rooms/hallwaysw.c"

void destroy_me()
{
  message("break","Your sapphire-studded longsword suddenly SHATTERS into "+
  "a million tiny fragments!\n",this_player());
  message("break",""+this_player()->query_cap_name()+"'s "+
  "sapphire-studded longsword suddenly SHATTERS into a million tiny "+
  "fragments!\n",environment(this_player()),this_player());
  this_object()->remove();	
}

int stab_command(string cmd) 
{ 
  if (cmd == "patch" || cmd == "wall" || cmd == "ice") 
  { 
    object p = this_player();
    if(p->query_environment()->query_hallway())
    {
	   message("info","You grasp the sapphire-studded longsword firmly, and "+
	   "then determinedly STAB it into the icy patch on the wall. There is "+
	   "a great HISS as the blue flames from the sword eat away at the "+
	   "ice. After a short time, the ice is gone, leaving the hole "+
	   "unobstructed.\n",this_player());
	   message("info",""+this_player()->query_cap_name()+" grasps "+
	   ""+possessive(this_player())+" sapphire-studded longsword firmly, and "+
	   "then determinedly STABS it into the icy patch on the wall. There is "+
	   "a great HISS as the blue flames from the sword eat away at the ice. "+
	   "After a short time, the ice is gone, leaving the hole "+
	   "unobstructed.\n",environment(this_player()),this_player());
	   LOCATION->thaw_ice();
	   destroy_me();
	   return 1;
    }
  }  
}

void extra_init() 
{ 
  add_action("stab_command", "stab"); 
} 

void extra_create()
{
  set_identified(1);
  set_short("Sapphire-studded longsword");
  set_id(({"longsword", "sapphire longsword", "sapphire-studded longsword",
  "sword"}));
  set_long(wrap("This longsword is made of flawless, transparent blue iceron. "+
  "The crossguard, hilt, and pommel are all studded with perfect sapphire "+
  "gems, each about the size of a nailhead. From time to time, some "+
  "%^BLUE%^blue%^RESET%^ flames burn along the length of the blade, but they "+
  "seem to absorb heat instead of giving it off. The entire sword emits a "+
  "freezing aura, creating a thin veil of frozen water wapor around it at "+
  "all times. It is almost impossible to touch the blade without freezing "+
  "yourself to its icy surface.\n"));
  set_name("sapphire-studded longsword");
  set_wtype("longsword");
  set_material("iceron");
  add_magic_property("resist cold", 5);
  add_magic_property("resist fire", 5);
  set_quality(90);
  weapon_setup();
}

string query_special_feature() 
{return "The blade is extremely cold, but also very brittle...";} 

int special_hit(object target)
{
  if(special == 0)
  {
    object fshadow;
    object sshadow;
    object p = this_object()->query_user();
    message("freeze", "Your sapphire-studded longsword flashes brilliantly "+
    "with %^BLUE%^blue%^RESET%^ fire as it strikes "+
    ""+target->query_cap_name()+"! "+capitalize(subjective(target))+" is "+
    "frozen solid!\n", p);      
    message("freeze", ""+p->query_cap_name()+"'s sapphire-studded "+
    "longsword flashes brilliantly with %^BLUE%^blue%^RESET%^ fire as it "+
    "strikes "+target->query_cap_name()+"! "+
    ""+capitalize(subjective(target))+" is frozen solid!\n",
    environment(p), ({p, target}));
    message("freeze", ""+p->query_cap_name()+"'s sapphire-studded "+
    "longsword flashes brilliantly with %^BLUE%^blue%^RESET%^ fire as it "+
    "strikes you! You are frozen solid!\n", target);
    fshadow = new("/u/a/allanon/area/ity/shadows/freeze_shadow.c");
    fshadow->move(target, 1);
    fshadow->shadow_object(target);
    fshadow->start_me();
    sshadow = new("/obj/spells/silence_shadow", target); 
    sshadow->shadow_object(target);
    call_out("destroy_me",1);
    special = 1;
    return 1;
  }
  else
  {
    return 0;	  
  }
} 

mixed * query_dtypes() 
{
  return ({COLD, 100});
} 