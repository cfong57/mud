#include <mudlib.h>
#include <move.h>

inherit OBJECT;

int charges = 15;
object shadow;

int query_charges() {return charges;}

int activate_command(string cmd)
{ 
  if (cmd == "card" || cmd == "mage card" || cmd == "card of the mages")
  {
	if(charges == 0)
	{
	  message("fail","Your Card of the Mages seems to be all out of power.\n",
	  this_player());	
	}
	else
	{
    if(this_player()->query_substituted())
    {
	  message("substitute","You activate your Card of the Mages, adding "+
	  "another substitute around you.\n",this_player());
	  message("substitute",""+this_player()->query_cap_name()+" activates "+
	  ""+possessive(this_player())+" Card of the Mages, adding another "+
	  "substitute around "+objective(this_player())+".\n",
	  environment(this_player()),this_player());
	  this_player()->add_substitute();
	  charges--;
    } 
    else
    {
	  message("substitute","You activate your Card of the Mages, summoning a "+
	  "doppelganger copy of yourself. It hovers around you protectively.\n",
	  this_player());
	  message("substitute",""+this_player()->query_cap_name()+" activates "+
	  ""+possessive(this_player())+" Card of the Mages, summoning a "+
	  "doppelganger copy of "+objective(this_player())+"self. It hovers around "+
	  ""+objective(this_player())+" protectively.\n",
	  environment(this_player()),this_player());
      shadow = new("/u/a/allanon/area/ity/shadows/mage_shadow.c");
	  shadow->move(this_player(),1);
	  shadow->shadow_object(this_player());
	  this_player()->check_substitute_status();
	  charges--;
    }
    this_object()->set_long(wrap("Card with a picture of Aquail on it. You "+
    "can 'activate' the card to draw out its powers.\n"+
    "It seems to have "+query_charges()+" charge(s) left.\n"));
    } 	
	return 1;
  }
  return notify_fail("Try 'activate card'.\n"); 
}  

void extra_init()
{
  add_action("activate_command","activate");
}

void extra_create()
{
  set_short("Card of the Mages");
  set_long(wrap("Card with a picture of Aquail on it. You can 'activate' "+
  "the card to draw out its powers.\n"+
  "It seems to have "+query_charges()+" charge(s) left.\n"));
  set_name("card of the mages");
  set_id( ({ "card of the mages", "card", "mage card" }) );
  set_mass(1);
  set_bulk(1);
  set_value(50000);
}