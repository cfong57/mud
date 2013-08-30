#include <mudlib.h>

inherit OBJECT;

mixed *types = ({"silver", "gold", "platinum", "mithril"}); 

string type = ""+types[random(sizeof(types))]+"";

int amount = 1 + random(5);

int polish_command(string cmd) 
{ 
  if (cmd == "pile" || cmd == "pile of coins"|| 
  cmd == "coins" || cmd == "pile of dirty coins" || cmd == "dirty coins") { 
    object p = this_player();
    message("info", "You carefully polish the coins, revealing them to be "+
    ""+type+" coins.\n", p); 
    message("info", ""+p->query_cap_name()+" carefully polishes "+
    ""+possessive(p)+" pile of dirty coins, revealing them to be "+type+" "+
    "coins.\n", environment(p), p);     
    p->credit(""+type+"", amount);
    this_object()->remove();      
    return 1; 
  } 
  //don't need a return notify_fail, this is an emote already
} 

void extra_init()
{
  add_action("polish_command", "polish");
}

void extra_create() 
{
  set_id( ({"pile", "pile of coins", "coins", "pile of dirty coins", 
  "dirty coins"}) );
  set_name("pile of dirty coins");
  set_short("Pile of dirty coins");
  set_long(wrap("This is a pile of coins, but you are not sure of what type "+
  "they are because they are covered in a layer of dirt, mud, and other "+
  "grime. You won't be able to use these until you polish them.\n"));
  set_value(0);
  set_mass(50);
  set_bulk(50);
}