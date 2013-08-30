#include <mudlib.h>
#include <money.h>
#include <shop.h>
inherit "/std/shop.c"; 

void extra_create() 
{
  seteuid(getuid());
  set_light(25);
  set_shop_id(file_name(this_object()));
  set_home_town("vaerlon");
  set_community("The City of Vaerlon");  
  set_short("Allanon's test shop");
  set_long(wrap("This is Allanon's test shop, where the buying and selling of "+
  "many types of goods takes place. It defaults to being a weapon shop.\n"+
  "call here;set_shop_type;<int>.\n"+
  "1 = armour, 2 = weapons, 4 = general, 8 = food, 16 = skins, 32 = gem.\n"));
  set_profit(101);
  set_max_stuff(2000);
  set_shop_type(WEAPON_SHOP);
  //set_flags(NO_BUYING);
  set_money(1000000000);
  set_shopkeeper("/u/a/allanon/area/caywin/obj/mage_card.c");
  set_exits( ([ "out" : "/u/a/allanon/workroom/connector"]) ) ; 
  set_items(([ 
  "/u/a/allanon/obj/amulet.c" : 1,
  "/u/a/allanon/obj/armour.c" : 1,
  "/u/a/allanon/obj/bandana.c" : 1,
  "/u/a/allanon/obj/belt.c" : 1,
  "/u/a/allanon/obj/blouse.c" : 1,
  "/u/a/allanon/obj/boots.c" : 1,
  "/u/a/allanon/obj/bracelet.c" : 2,
  "/u/a/allanon/obj/capture_jar.c" : 1,
  "/u/a/allanon/obj/cloak.c" : 1, 
  "/u/a/allanon/obj/earrings.c" : 1,
  "/u/a/allanon/obj/gauntlets.c" : 1,
  "/u/a/allanon/obj/helm.c" : 1,
  "/u/a/allanon/obj/necklace.c" : 1,
  "/u/a/allanon/obj/pants.c" : 1, 
  "/u/a/allanon/obj/ring.c" : 1,
  "/u/a/allanon/obj/ring2.c" : 1,
  "/u/a/allanon/obj/scope.c" : 1,
  "/u/a/allanon/obj/seven_nights.c" : 2,
  "/u/a/allanon/obj/testwand.c" : 1,
  "/u/a/allanon/obj/wand.c" : 1,
  "/u/a/allanon/obj/mapper.c" : 1 ]));
}