#include <mudlib.h>

inherit ARMOR;

void extra_create() 
{
  set_identified(1);
  set_id( ({"beautiful silver ring", "silver ring", "ring"}));
  set_name("silver ring");
  set_short("A beautiful silver ring");
  set_long(wrap("A very well-made silver ring. It is graced by a single, small "+
  "emerald. Even without knowing who it belonged to, you can feel that this "+
  "ring is the memento of many joyful memories. This almost gives the ring "+
  "a magical aura wholly different from that of other items. This item has "+
  "been held close to the heart, and is highly prized by someone as a symbol "+
  "of the past.\n"));
  set_slots( ({"finger"}) );
  set_material("silver");
  set_type("full plate");
  set_type_desc("ring");
  set_quality(100);
  add_magic_property("protection",5);
  set_size(175);
  armour_setup();
}