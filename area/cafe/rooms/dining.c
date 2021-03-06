#include <mudlib.h>
#include <money.h>
#include <shop.h>

inherit "/std/shop.c"; 

void do_fire()
{
  object fire = new("/obj/campfire.c");
  object fireshadow = new("/u/a/allanon/area/cafe/shadows/fireshadow.c");
  fire->move(this_object(), 1);
  fire->set_max_fuel(86400);
  fire->set_fuel(86400);
  fireshadow->move(this_object(), 1);
  fireshadow->shadow_object(fire);
  fireshadow->check_status();
}

void extra_create()
{
  set_outside("p");
  set_outdoors("p");
  set_no_teleport(1);
  seteuid(getuid());
  set_light(25);
  set_shop_id(file_name(this_object()));
  set_home_town("vaerlon");
  set_community("The City of Vaerlon");  
  set_short("Dining room of Wildcat Cafe");
  set_long(wrap("This is the spacious dining room of Wildcat Cafe. There are "+
  "plenty of tables to sit at, even though there are many patrons already "+
  "seated. The bar also looks to be pretty popular; most of the stools are "+
  "spoken for. In the center of the room, a pit has been dug out for a "+
  "cooking fire, and several large rocks form a ring around it to protect "+
  "from stray sparks. A large stack of wood is in the corner of the room, and "+
  "above the fire there is a hole in the ceiling to let the smoke out. A "+
  "grate covers the hole to prevent debris from falling in, although you "+
  "wonder what they do when it rains or snows.\n"));
  set_profit(101);
  set_max_stuff(2000);
  set_shop_type(FOOD_SHOP);
  set_money(1000000000);
  set_shopkeeper("/u/a/allanon/area/cafe/mon/slash.c");
  set_items(([ 
  "/u/a/allanon/area/cafe/obj/meat.c" : 500,
  "/obj/food/flask.c" : 50,
  "/obj/food/crisp_rye-bread.c" : 50,
  "/obj/food/bread.c" : 50,
  "/obj/food/waybread.c" : 50,
  "/obj/food/beer_keg.c" : 50,
  "/obj/food/beer.c" : 50,
  "/obj/food/wine.c" : 50]));
  set_sounds(200 + random(50), ({ 
  "The patrons are a rather varied crowd. You see members of every race and "+
  "guild in the valley, plus a few odd figures unknown to you.\n",
  "The wonderful smell of food saturates the air. You feel yourself getting "+
  "hungry just standing here.\n"})); 
  set_exits(([
  "east" : "/u/a/allanon/area/cafe/rooms/foyer.c",
  "west" : "/u/a/allanon/area/cafe/rooms/tanner.c"]));
  do_fire();
}