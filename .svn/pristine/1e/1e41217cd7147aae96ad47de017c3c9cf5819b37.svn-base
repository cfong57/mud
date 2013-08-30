#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"silk clothes", "simple silk blouse", "clothes", "silk blouse",
  "blouse", "simple blue blouse", "blue blouse"}) );
  set_name("silk blouse");
  set_short("Simple blue blouse");
  set_long(wrap("This is a rather plain blouse made of dark blue silk. It "+
  "has a few ivory buttons and short sleeves, and it comes down to right "+
  "about waist-length. It seems to be warm enough as clothes go. Truthfully "+
  "speaking, there is nothing remarkable about the item other than its high "+
  "degree of quality. It doesn't even appear to be very magical.\n"));
  set_slots( ({"clothes"}) );
  set_material("silk");
  set_type("standard");
  set_type_desc("clothes");
  set_warmth(10);
  set_quality(100);
  set_size(175);
  add_magic_property("protection",5);
  armour_setup();
}