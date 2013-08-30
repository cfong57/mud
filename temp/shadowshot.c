#include <mudlib.h>
#include <damage.h>

inherit "/obj/gems/jewel";

object mon;
int charges = 5;
int shooting = 0;
int fkrit;
int cha;
int mlore;
int obint;
int obwis;
int offcheck;
int ready = 0;
string monstr;

void extra_create() 
{
  set_short("%^BOLD%^%^RED%^Shadowshot%^RESET%^");
  set_id(({"Shadowshot", "shadowshot", "gem"}));
  set_long(wrap("Long-range dark magic bolt.\n"+
  "'info shadowshot' for more information.\n"));
  set_gem_name("%^BOLD%^%^RED%^Shadowshot%^RESET%^");
  set_value((this_object()->query_value())+100000+random(50000));
  set_mass(1250);
  set_bulk(1500);
  set_rarity(100);
  set_quality(70);
  set_cut(10);
  set_identified(1);
}