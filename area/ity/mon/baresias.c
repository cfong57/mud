#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Baresias, the last Royal Guard");
  set_long(wrap("This ghost is wearing a magnificent coat of mail that has "+
  "the emblem of a dragon blazing forth from the chest. You suspect that he "+
  "might have been part of the king's Royal Guard in life. He carries on his "+
  "worldly duties even in death, barring the way forward with his lance "+
  "at the ready. You cannot help but feel some admiration towards this most "+
  "loyal of servants.\n"));
  set_name("baresias");
  set_living_name("baresias"); 
  set_id( ({"baresias", "guard", "royal guard", "human", "ghost", "undead"}) );
  set_level(45);
  set_race("human");
  set_species("undead");
  set_gender("male");
  set_following(0);
  set_combat_kit("fighter 5");
  set_agrochance(100);
  add_weapon("/u/a/allanon/area/ity/obj/lightning_lance.c");
  set_inquiry((["$DEFAULT" : "None shall pass!",
  "$GREET" : "None shall pass!"]));
  set_blocking_dirs( (["north" : "The guard bars your way, brandishing his "+
  "weapon menacingly.\n" ]) );
}