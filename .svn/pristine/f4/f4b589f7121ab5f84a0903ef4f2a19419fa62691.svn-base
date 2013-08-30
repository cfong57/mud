#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_short("%^ORANGE%^Gold%^RESET%^ hairpin, glittering bright");
  set_long(wrap("This is some sort of hair ornament consisting of a long, "+
  "thin needle and a clasp attached to a gold backing. The backing is in the "+
  "shape of a dragon. It looks quite realistic, with the detailed scales and "+
  "small rubies for eyes. The hairpin seems to glow softly, emitting a dull "+
  "light to the surroundings. It is definitely a thing for a noble person "+
  "to wear; as an adventurer, you find it a little preposterous to even "+
  "think of wearing something so attention-grabbing.\n"));
  set_id( ({"gold hairpin", "hairpin", "key"}) );
  set_name("gold hairpin");
  set_slots( ({"miscellaneous"}) );
  set_material("gold");
  set_type("full plate");
  set_type_desc("miscellaneous");
  set_light(35);
  set_size(50);
  set_quality(85);
  set_identified(1);
  armour_setup();
}

int query_size()                                                                          
{ 
  //makes this item fit anyone, regardless of size                                            
  object p = environment(this_object());                                                                    
  if (p && userp(p)) {
    return p->query_stat("size");
  } else { 
    return ::query_size(); 
  }
}  