#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_id( ({"amber leaf", "leaf", "golden leaf"}) );
  set_name("amber leaf");
  set_short("%^ORANGE%^Golden%^RESET%^ leaf, embedded in amber");
  set_long(wrap("This is a curious object. It seems to be a leaf which has "+
  "been totally coated in amber. You're not too sure since amber is the same "+
  "color, but it would appear that the leaf itself used to be golden. There "+
  "is a small patch of sticky resin on one side of the leaf - perhaps it "+
  "is meant to be worn as some kind of armour. The object reflects light "+
  "exceptionally well, multiplying the merest photon into a piercing beam "+
  "of brilliance.\n"));
  set_slots( ({"miscellaneous"}) );
  set_material("stone");
  set_type("scale mail");
  set_type_desc("miscellaneous");
  set_light(100);
  set_size(50);
  set_quality(65);
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