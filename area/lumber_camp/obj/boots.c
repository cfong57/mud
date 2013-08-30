#include <mudlib.h>

inherit ARMOR;

int tap_command(string cmd)
{
  if (cmd == "boots") 
  {
    if (this_object()->query_user()) 
    {
      object p = this_player();
      if (this_object()->query_current_energy() < 
      (this_object()->query_max_energy() / 2)) 
      {
	    //no effect when ~subtle glow
        message("fail", "You tap your boots, but...nothing seems to "+
        "happen.\n", p);
        message("fail", ""+p->query_cap_name()+" taps "+possessive(p)+" "+
        "boots...but nothing seems to happen.\n", environment(p), p); 
      } 
      else 
      {
        message("info", "You tap your boots, and some of the magical energy "+
        "flows out of the item and into the forcefield surrounding it.\n", p);
        message("info", ""+p->query_cap_name()+" taps "+possessive(p)+" "+
        "boots, and some of the magical energy flows out of the item and "+
        "into the forcefield surrounding it.\n", environment(p), p);
        this_object()->set_current_energy(this_object()->query_current_energy() 
        - 500);
        p->remove_floating(1);
        new("/obj/spells/float_shadow", p, 100 + random (200)); 
      }
    } 
    else 
    {
	  message("info", "But you aren't wearing the boots.\n", this_player());   
    }
    return 1;
  }
  return notify_fail("Tap what?\n");
}

void extra_init() 
{ 
  add_action("tap_command", "tap"); 
} 

void extra_create() 
{
  set_id( ({"wooden bark boots", "wooden boots", "bark boots", 
  "wood boots", "boots"}) );
  set_name("bark boots");
  set_short("Wooden bark boots"); 
  set_long(wrap("These boots are made of scales of wooden bark sewn onto "+
  "a leather backing. The wood looks like it came from an old oak tree. "+
  "Strangely the bark seems to glow with a mystifying green aura, giving the "+
  "item a strange appearance...the vitality of a forest seems to flow through "+
  "the boots. Since it's made of wood these obviously weren't made with "+
  "protection in mind, in fact the boots look to be of extremely poor "+
  "quality and they seem exceedingly fragile. However, you notice that the "+
  "scales are set to nearly a water-tight pattern...maybe these could at "+
  "least provide some protection in the rain.\n"));
  set_slots( ({"foot", "foot"}) );
  set_material("wood");
  set_type("scale mail");
  set_type_desc("boots");
  add_magic_property("hpregen", 2);
  set_size(175);
  set_quality(1);
  set_wear_func("wear_me");
  set_remove_func("remove_me");
  armour_setup();
}

string query_special_feature() 
{ 
  return "These boots magically repel water.\n"+
  "The effect might fade eventually.";
} 

int wear_me()
{
  object p = this_player();
  if (this_object()->query_current_energy() < 
  (this_object()->query_max_energy() / 2)) {
	//no effect when ~subtle glow
    message("wear", "As you pull on the boots...nothing seems to happen.\n", p); 
  } else {
    message("wear", "As you pull on the boots, some kind of forcefield seems "+
    "to develop around them.\nYou could 'tap' the boots to renew the "+
    "effect.\n", p);
    message("wear", "As "+p->query_cap_name()+" pulls on "+possessive(p)+" "+
    "boots, some kind of forcefield seems to develop around them. It looks "+
    "like "+subjective(p)+" could walk on water.\n",
    environment(p), p);
    this_object()->set_current_energy(this_object()->query_current_energy() 
    - 500);
    p->remove_floating(1);
    new("/obj/spells/float_shadow", p, 100 + random (200));
  }
  return 1;
}

int remove_me()
{
  object p = this_player();
  if (p->query_floating()) {
    message("remove", "As you remove the boots, the forcefield around them "+
    "fades.\n", p);
    message("remove", "As "+p->query_cap_name()+" removes "+possessive(p)+" "+
    "boots, the forcefield around them fades.\n", environment(p), p);
    p->remove_floating(1);
  }
  return 1;    
}