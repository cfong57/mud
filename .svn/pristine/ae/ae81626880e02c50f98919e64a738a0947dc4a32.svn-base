#include <mudlib.h>

inherit CONTAINER;

int break_command(string cmd) 
{ 
	object b = this_object();
	mapping map = ([ ]);  
    foreach( object o in all_inventory(b))
    if ( cmd == "bottle" ) 
    { 
	    object p = this_player();
	    object vortex;
        message("info","You smash the bottle on the ground, releasing the "+
        "vortex contained within.\n",p); 
        message("info",""+p->query_cap_name()+" smashes "+possessive(p)+" "+
        "bottle on the ground, releasing the vortex contained within.\n",
        environment(p),p);           
        map[ file_name(o)] = o;  
        o->remove();
        vortex = new("/u/a/allanon/objects/vortex.c");
        vortex->move(environment(p),1);
        vortex->calculate_bonus(p);
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
  set_short("Miniscule glass bottle");
  set_long(wrap("This is a clear glass bottle. Inside it you see a small "+
  "%^BOLD%^%^GREEN%^vortex%^RESET%^ of energies. You could probably 'break' "+
  "the bottle to set the %^BOLD%^%^GREEN%^vortex%^RESET%^ free. The bottle is "+
  "very, very small and it looks like you could fit maybe just a single coin "+
  "inside it, but you don't see what the point would be of doing that.\n"));
  set_id( ({ "vortex-in-a-bottle", "miniscule glass bottle", "miniscule bottle", 
  "glass bottle", "bottle"}) );
  set_mass(1);
  set_bulk(1);
  set_capacity(0);
  set_volume(0);
  set_dynamic_bulk(0);
  set_value(10000+random(10000));
  set_start_contents((["/u/a/allanon/obj/vortex.c": 1 ]));
}