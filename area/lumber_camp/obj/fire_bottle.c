/* Creates a campfire to the room. Works anywhere, even in water rooms. Of 
course, the fire will die out soon after that. I also think it is okay that it 
works in 'indoors' rooms, since to be really effective a campfire needs a camp 
(which you couldn't build) plus various enchants, incense, etc. */

#include <mudlib.h>

inherit OBJECT;

int break_command(string cmd) 
{ 
  if (cmd == "bottle" || cmd == "glass bottle"|| 
  cmd == "sealed glass bottle" || cmd == "sealed bottle") { 
    object p = this_player();
    object cfire;
    message("info", "You smash the bottle on the ground, unleashing the "+
    "flames within!\n", p); 
    message("info", ""+p->query_cap_name()+" smashes "+possessive(p)+" "+
    "bottle of flames on the ground, unleashing the flames "+
    "within!\n", environment(p), p);     
    message("info", "The intense heat creates a small blaze on the ground, "+
    "which starts incinerating fuel, eventually becoming a small "+
    "campfire.\n", environment(p));   
    cfire = new("/obj/campfire.c");
    cfire->move(environment(p), 1);
    this_object()->remove();        
    return 1; 
  } 
  return notify_fail("Break what?\n"); 
} 
  
void extra_init() 
{ 
  add_action("break_command", "break"); 
} 

void extra_create()
{
  set_short("Sealed glass bottle, containing flames");
  set_long(wrap("This is a sealed bottle made out of glass. It seems to "+
  "contain flames inside of it. You could 'break' the bottle to let loose the "+
  "flames but you aren't sure what would happen. The bottle is of a strange "+
  "design: it was probably custom-made, since it is shaped vaguely like a "+
  "flame. It seems to be made out of some sort of hardened glass, and it "+
  "probably would not break during the rigors of combat.\nThere is a label on "+
  "the bottle that reads: 'Campfire'.\n"));
  set_id( ({ "glass bottle", "bottle", "sealed glass bottle", 
  "sealed bottle"}) );
  set_mass(1);
  set_bulk(1); 
  set_value(5000);
}