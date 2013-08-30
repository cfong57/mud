#include <mudlib.h>
#include <damage.h>

inherit WEAPON;

void extra_create()
{
  set_identified(1);
  set_short("Shining sword, stamped with a falcon crest %^BOLD%^(humming)%^RESET%^");
  set_id(({"shining sword", "sword", "falchion", "crystal falchion", 
  "crystal sword", "falcon falchion", "falcon's falchion"}));
  set_long(wrap("This falchion seems to have been fashioned out of a single "+
  "long piece of clear mountain crystal. Although it is nearly transparent, "+
  "and the cutting edge is sharp, the blade itself is rather crude - in other "+
  "words, it merely looks pretty. A striking crest resembling a rising falcon "+
  "is stamped to the blade, marking it as a piece forged by the legendary "+
  "smith of the same name, Falcon. You remember that he was so named because "+
  "his weapons were said to be able to magically rend the air itself. His "+
  "works were highly prized and found their way all throughout the valley; "+
  "you wonder what incredible journey this particular weapon has been "+
  "through.\n"));
  set_name("falcon's falchion");
  set_wtype("falchion");
  set_material("crystal");
  set_quality(25);
  weapon_setup();
}

//do this instead of add_magic_property() to keep df value down
mixed * query_dtypes() 
{ 
  return ({ SONIC, 10, PHYSICAL, 90 }); 
} 

//do these to keep value down; cost_modifier doesn't degrade enough

int query_base_value()
{
  return 10000;
}

int query_value()
{
  return 10000;
}