#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_id( ({"flower necklace", "necklace of flowers", "necklace"}) );
  set_name("flower necklace");
  set_short("Flower necklace, held together with amber");
  set_long(wrap("This is a necklace consisting of twenty-five beautiful "+
  "flowers all strung together on a filament made of amber. Upon closer "+
  "inspection, the 'filament' is made up of what seems to be hundreds of very "+
  "tiny amber chains - only magic could have forged something so intricate. "+
  "The flowers must have been very beautiful before, but now they are even "+
  "more so, preserved for all eternity in a sepia shell of fossilized tree "+
  "sap. There is a tingle of magic about the item which makes you feel more "+
  "refreshed, and the heady scent of fresh wildflowers rises to your nose as "+
  "you inhale.\n"));
  set_slots( ({"miscellaneous"}) );
  set_material("stone");
  set_type("scale mail");
  set_type_desc("miscellaneous");
  switch (random(4)) {
    case 0:
    add_magic_property("hpregen", 1 + random(2)); 
    break;
    case 1:
    add_magic_property("spregen", 1 + random(2)); 
    break;
    case 2:
    add_magic_property("epregen", 1 + random(2)); 
    break;
    case 3:
    add_magic_property("pspregen", 1 + random(2)); 
    break;
  }
  set_size(100);
  set_quality(65);
  set_identified(1);
  call_out("change_magic", 10 + random(21));
  armour_setup();
}

void change_magic()
{
  this_object()->clear_magic_map();
  switch (random(4)) {
    case 0:
    add_magic_property("hpregen", 1 + random(2)); 
    break;
    case 1:
    add_magic_property("spregen", 1 + random(2)); 
    break;
    case 2:
    add_magic_property("epregen", 1 + random(2)); 
    break;
    case 3:
    add_magic_property("pspregen", 1 + random(2)); 
    break;
  }
  this_object()->magic_setup();
  refresh_stats();
  call_out("change_magic", 10 + random(21));
  return;
}

string query_special_feature() 
{
  return "This item's regenerative properties randomly shift.";
}
