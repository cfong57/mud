#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Sealed container");
  set_long(wrap("This is a container sealed with iron bands. Although the "+
  "bands have rusted a long time ago, the container still looks sturdy "+
  "enough to take a few hits. You think on how best to tackle this "+
  "obstacle.\n"));
  set_name("Sealed container");
  set_id(({ "sealed container", "container"}));
  set_level(1);
  set_race("container");
  set_species("undead");
  set_gender("neuter");
  set_body_parts(({"container", 100, 1, "body"}));   
  set_following(0);
  set_inquiry((["$GREET" : "greet_inquiry",
  "$DEFAULT" : "default_inquiry"]));
}

void greet_inquiry()
{
  message("info","Do you like talking to inanimate objects?\n",this_player());
}

void default_inquiry()
{
  message("info","Do you like talking to inanimate objects?\n",this_player());
}

void calculate_reward()
{
  switch(this_object()->query_level())
  {
	case 1..20:
    set_alt_corpse("/u/a/allanon/area/ity/obj/coins.c");
    break;
    case 21..40:
    set_alt_corpse("/obj/misc/maps/monster_map.c");
    break;
    case 41..75:
    set_alt_corpse("/std/enchant_skill_item.c");
    break;
    case 76..100:
    set_alt_corpse("/std/enchant_item.c");
    break;
    default:
    set_alt_corpse("/obj/food/waybread.c");
    break; 	  
  }
}

void second_life()
{
  deep_inventory(this_object())->remove();
}
