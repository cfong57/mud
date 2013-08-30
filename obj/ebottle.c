#include <mudlib.h>

inherit CONTAINER;

int break_command(string cmd) 
{ 
    if ( cmd == "bottle" ) 
    { 
	    object p = this_player(); 
	    object b = this_object();
        message("info","You smash the bottle on the ground, setting Ereldon "+
        "free.\n",p); 
        message("info",""+p->query_cap_name()+" smashes "+possessive(p)+" "+
        "bottle on the ground, letting free the Ereldon that was inside it.\n",
        environment(p),p);
        foreach( object o in all_inventory(b))
        o->move(environment(p),1);
        this_object()->remove();
        return 1; 
    } 
    return notify_fail("Break what?\n"); 
} 

void extra_init() 
{ 
    add_action("break_command","break"); 
} 

void extra_create()
{
  set_short("Glass bottle containing an annoying elf sage");
  set_long("It's a novelty Ereldon-in-a-bottle!\n");
  set_id( ({ "ereldon-in-a-bottle", "glass bottle", "bottle",
  "glass bottle containing an annoying elf sage",
  "bottle containing an annoying elf sage"}) );
  set_mass(1);
  set_bulk(1);
  set_capacity(55000);  
  set_volume(48000);
  set_dynamic_bulk(0);
  set_value(100000);
  set_start_contents((["/d/valkor/vaerlon/monsters/ereldon": 1 ]));
}