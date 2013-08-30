#include <mudlib.h>

inherit OBJECT;

void extra_create() 
{
  set_id( ({"golden leaf", "leaf"}) );
  set_name("golden leaf");
  set_short("a golden leaf");
  set_long(wrap(
  "You are certain that this didn't come from just any tree. The leaf is "+
  "wafer-thin, yet flexible enough to bend and flutter. It seems to be made "+
  "of gold, but it weighs so little you can blow it along with a gentle "+
  "breeze. The veins and markings are such a good replica of a real leaf that "+
  "you could probably mistake the two from a distance. The leaf glitters like "+
  "the sun when it catches the light, and a faint woody fragrance seems to "+
  "come from it, reminding you of the forest...\n"));
  set_value(15000);
  set_mass(50);
  set_bulk(50);
}