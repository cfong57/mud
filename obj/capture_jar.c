#include <mudlib.h>

inherit CONTAINER;

int break_command(string cmd)
{
	if ( cmd == "jar" )
	{
        object p = this_player();
        object b = this_object(); 
        foreach( object o in all_inventory(b))
        {
      message("info","You smash the jar on the ground and pick up the "+
      "contents.\n",p); 
      message("info",""+p->query_cap_name()+" smashes "+possessive(p)+" "+
      "Capture Jar on the ground and picks up the "+
      "contents.\n",environment(p),p);
      message("info",""+p->query_cap_name()+" breaks "+possessive(p)+" "+
      "Capture Jar! You are free...until suddenly "+p->query_cap_name()+" "+
      "bends down and picks you up! How cruel!\n",o);
	  b->remove();
	  return 1;
       }
  return notify_fail("Break what?\n");  
    }
}  

int capture_command(string cmd)
{ 
  {
  object p = this_player();
  object b = this_object(); 	 
  object *inventory; 
  inventory=all_inventory(environment(p));
  filter_array(inventory,(:!$1->query_player():));
  foreach(object ob in inventory)
  if ( ob->id(cmd))
     {
	  message("info","You aim the Capture Jar at "+
	  ""+capitalize(ob->query_short())+", and a small tractor beam shoots out "+
	  "of it! Within no time "+capitalize(ob->query_short())+" is inside your "+
	  "Capture Jar.\n",p); 
	  message("info",""+p->query_cap_name()+" aims "+possessive(p)+" Capture "+
	  "Jar at "+capitalize(ob->query_short())+", and a small tractor beam "+
	  "shoots out of it! Within no time "+capitalize(ob->query_short())+" is "+
	  "inside "+possessive(p)+" Capture Jar.\n",environment(p),p);
	  message("info",""+p->query_cap_name()+" aims "+possessive(p)+" Capture "+
	  "Jar at you, and a small tractor beam shoots out of it! Within no time "+
	  "you are inside "+possessive(p)+" Capture Jar.\n",ob);
	  ob->move(b,1);
	  return 1;
     }
  return notify_fail("Capture what?\n");
  }  
}  
	
	
int empty_command(string cmd) 
{        
 if ( cmd == "jar" ) 
 { 
        object p = this_player();
        object b = this_object(); 
        mapping jar = ([ ]);  
        foreach( object o in all_inventory(b))
        {
	    jar[ file_name(o)] = o; 
        message("info","You empty the Capture Jar.\n",p); 
        message("info",""+p->query_cap_name()+" empties "+possessive(p)+" "+
        "Capture Jar.\n",environment(p),p);
        message("info",""+p->query_cap_name()+" decides to empty "+
        ""+possessive(p)+" Capture Jar. You are deleted!\n",o);
        foreach( string k, object r in jar) if ( r != this_object())r->remove();
        deep_inventory(this_object())->remove();
        return 1; 
        }           
 } 
    return notify_fail("Empty what? -OR- The Capture Jar is already empty.\n");        
} 

int release_command(string cmd)
{
  object p = this_player();
  object b = this_object(); 	 
  mapping release = ([ ]);  
  foreach( object o in all_inventory(b))
  if ( o->id(cmd))
  {
	  release[ file_name(o)] = o; 
	  message("info","You release "+capitalize(o->query_short())+" from your "+
	  "Capture Jar.\n",p); 
	  message("info",""+p->query_cap_name()+" releases "+capitalize(o->query_short())+" "+
	  "from "+possessive(p)+" Capture Jar.\n",environment(p),p);
	  message("info",""+p->query_cap_name()+" releases you from "+
	  ""+possessive(p)+" Capture Jar.\n",o);
	  o->move(environment(p),1);
	  return 1;
  }
  return notify_fail("Release what? Are you sure that thing is in your "+
  "Capture Jar?\n");  
}  
  
void extra_init() 
{ 
    add_action("break_command","break"); 
    add_action("capture_command","capture"); 
    add_action("empty_command","empty"); 
    add_action("release_command","release"); 
} 

void extra_create()
{
  set_short("A Capture Jar");
  set_long(wrap("This special item is used to capture things. It also "+
  "functions as a normal container. You can do the following in addition: \n"+
  "'empty jar' to delete everything in Jar;\n"+
  "'break jar' to, well, break your jar. This moves everything in Jar to your "+
  "inventory. Be careful with the 'break' command, if the object(s) in the "+
  "jar are monsters or if they are not normally movable, then you must "+
  "'move xxx to here' to get them out of your inventory.\n"+
  "TO CAPTURE: 'capture xxx'.\n"+
  "TO RELEASE: 'release xxx'.\n"+
  "Note: Please don't use this on other players. It may cause bugs.\n"));
  set_name("capture jar");
  set_id( ({ "capture jar", "jar"}) );
  set_mass(1);
  set_bulk(1);
  set_possible_to_close(1);
  set_capacity(2147483647);
  set_volume(2147483647);
  set_dynamic_bulk(100);
}