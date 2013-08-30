#include <mudlib.h>
#include <move.h>

inherit OBJECT;

#define WORKROOM "/u/a/allanon/workroom/allanon_workroom"

int apply_command(string cmd)
{ 
  mapping stuff;
  object thing;
  if (this_object()->id(cmd) &&
  base_name(environment(this_player())) == WORKROOM)
  {
	message("info","You successfully redeem the coupon and receive a set of "+
	"Allanon's equipment.\n",this_player());
	message("info",""+this_player()->query_cap_name()+" successfully redeems "+
	""+possessive(this_player())+" Allanonian equipment coupon and receives "+
	"a set of Allanon's equipment.\n",environment(this_player()),this_player());
    stuff = ([ 
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
    "/u/a/allanon/obj/mapper.c" : 1  ]);
    for(int i = 0; i < sizeof(keys(stuff)); i++)
    {
	  for(int k = 0; k < values(stuff)[i]; k++)
	  {
	    thing = new(keys(stuff)[i]);
	    thing->move(this_player(),1);	  
	  }
    }
    this_object()->remove();
	return 1;
  }
}

void extra_init()
{
  add_action("apply_command","apply");
}

void extra_create()
{
  set_short("Allanonian equipment coupon");
  set_long(wrap("This is a pink piece of paper covered in girly floral "+
  "writing. Reading it, you determine that the bearer can 'apply' the coupon "+
  "in Allanon's Workroom, and receive a set of equipment that Allanon deems "+
  "necessary for everyday dev-wizarding activities.\n"));
  set_name("allanonian equipment coupon");
  set_id( ({ "allanonian equipment coupon", "allanonian coupon",
  "equipment coupon", "coupon" }) );
  set_mass(1);
  set_bulk(1);
  set_value(0);
}