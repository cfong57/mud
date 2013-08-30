#include <mudlib.h>
#include <move.h>

inherit CONTAINER;

object coins;
object *inventory;
int total = 0;
int total_value;
int silver = 0;
int gold = 0;
int platinum = 0;
int mithril = 0;

int query_total_value()
{
  return total_value;	
}

void calculate_totals()
{
  int cvalue;
  total = 0;
  total_value = 0;
  silver = 0;
  gold = 0;
  platinum = 0;
  mithril = 0;
  inventory = filter_array(all_inventory(this_object()), 
  (:$1->query_is_money():));
  foreach(object ob in inventory)
  {
    switch(ob->query_type())
    {
      case "silver":
      cvalue = 1;
      silver += ob->query_number();
      break;
      case "gold":
      cvalue = 10;
      gold += ob->query_number();
      break;
      case "platinum":
      cvalue = 100;
      platinum += ob->query_number();
      break;
      case "mithril":
      cvalue = 1000;
      mithril += ob->query_number();
      break;
    }
    total += ob->query_number();
    total_value += ob->query_number()*cvalue;
  }
}

string query_look()
{
  string look;
  calculate_totals();
  look = this_object()->query_long()+"The box has "+total+" coins in it, "+
  "worth "+total_value+" silvers: "+silver+" silver, "+gold+" gold, "+
  ""+platinum+" platinum, and "+mithril+" mithril.\n";
  return look;
}

int add_command(string cmd)
{
  int number;
  string type;
  if(cmd)
  {
    sscanf(cmd, "%d %s", number, type);
  }
  if(number && type)
  {
	if(number > 30000 || total + number > 30000)
	{
	  message("info","You can't fit more than 30000 coins inside the box.\n",
	  this_player());	
	}
	else if(this_player()->debit(type,number))
    {
	  message("info","You put "+number+" "+type+" coins into the box.\n",
	  this_player());
	  message("info",""+this_player()->query_cap_name()+" puts "+number+" "+
	  ""+type+" coins into "+possessive(this_player())+" box.\n",
	  environment(this_player()),this_player());
	  coins=clone_object("/std/coins.c");
	  coins->set_type(type);
	  coins->set_number(number);
	  coins->move(this_object(),1);
	  calculate_totals();
    }
    else
    {
	  message("info","You don't seem to have "+number+" "+type+" coins.\n",
	  this_player());
    }
    return 1;
  }
  return notify_fail("Syntax: 'add <number> <coin type>'\n");
}

void extra_init() 
{ 
  add_action("add_command","add");
} 

void extra_create()
{
  set_short("Cubical box with a slot in the top");
  set_long(wrap("This is a plain wooden box carved into the shape of a cube. "+
  "There is a slot in the top that is just big enough to fit a coin-sized "+
  "object inside. You could 'add' some money to the box. It looks like it "+
  "would hold up to 30000 coins.\n"));
  set_name("cubical box");
  set_id( ({ "cubical box with a slot in the top", "cubical box", "box"}) );
  set_mass(1);
  set_bulk(1);
  set_possible_to_close(0);
  set_capacity(1);
  set_volume(1);
  set_dynamic_bulk(100);
}