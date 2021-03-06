#include <mudlib.h>

inherit "/std/liquid_container";

int query_no_weight_message() { return 1; }

void create()
{   
  set_short("Refreshing glass of lemonade");
  set_id(({"refreshing glass of lemonade", "glass", "refreshing lemonade", 
  "lemonade"}));
  set_long(wrap("This glass of lemonade is cold to the touch and looks "+
  "very refreshing. A slice of lemon has been stuck to the rim, and there "+
  "are some bits of shaved ice to keep the drink from warming up. A small "+
  "pile of sugar is at the bottom of the drink, and a long spoon has been "+
  "included to stir it into the mix. You notice that more lemonade fills up "+
  "the glass every time you sip from it, although it never quite overflows "+
  "the rim.\n"));
  set_mass(1);
  set_bulk(1);
  /*set_gulpleft(3);
  set_gulp_mass(1000);
  set_gulpnumber(1);  ????? */
  set_value(0);
  set_drink_type(2); //infinite because only way to make non-buggy drink...
  set_water_value(999);
  set_ep_value(0);
  set_prevent_get(1);
  set_prevent_drop(1);
}