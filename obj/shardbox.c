#include <mudlib.h>
#include <move.h>

inherit CONTAINER;

object SHARD;
mixed TARGETS;
string FOO;
string POWER;
string TYPE;
int COUNTER;
int CHARGES = 10;

void set_charges(int foo) { CHARGES = foo; } //for debugging

string query_look()
{
  string look;
  
  look = this_object()->query_long()+"\nThe box has "+CHARGES+""+
  " charges left.\n";
  return look;
}

int wish_command(string cmd)
{
  if(CHARGES <= 0)
  {
    message("fail","The box has no charges left.\n",this_player());  
    return 1;
  }	
  if (!cmd)
  { 
    if(random(2))
	{
      SHARD = new("/std/enchant_item.c");
      SHARD->move(this_object(), 1);
      message("info", "Created magic shard, "+
      "'"+SHARD->query_short()+"'.\n", this_player());
    }
    else
    {
	  SHARD = new("/std/enchant_skill_item.c");
	  SHARD->move(this_object(), 1);
      message("info", "Created skill shard, "+
      "'"+SHARD->query_short()+"'.\n", this_player());
    }
    CHARGES--;
    return 1;
  }
  COUNTER = 0; 
  TARGETS = explode(cmd, ",");
  if(sizeof(TARGETS) != 3)
  {
    message("fail", "Wrong argument(s).\nUse "+
    "'wish <magic/skill>,<shard strength>,<name of shard>' .\n",this_player());
    return 1;
  }
  FOO = TARGETS[0];
  POWER = TARGETS[1];
  TYPE = TARGETS[2];
  switch(FOO)
  {
  case "magic":
    SHARD = new("/std/enchant_item.c");
    SHARD->move(this_object(), 1);
    while(SHARD->query_short() != 
    ""+POWER+" shard of crystallized "+TYPE+" magic" && COUNTER < 500)
    {
      SHARD->remove();
      SHARD = new("/std/enchant_item.c");
      SHARD->move(this_object(), 1);
      COUNTER++;
    }
  break;
  case "skill":
    SHARD = new("/std/enchant_skill_item.c");
    SHARD->move(this_object(), 1);
    while(SHARD->query_short() != 
    ""+POWER+" shard of crystallized "+TYPE+" skill essence" && COUNTER < 500)
    {
      SHARD->remove();
      SHARD = new("/std/enchant_skill_item.c");
      SHARD->move(this_object(), 1);
      COUNTER++;
    }
  break;
  default:
    message("fail", "Wrong argument(s).\nUse "+
    "'wish <magic/skill>,<shard strength>,<name of shard>' .\n",this_player());
    return 1;
  break;
  }
  if(COUNTER >= 500)
  {
	SHARD->remove();	
    message("info", "Failed to make the "+POWER+" "+TYPE+" shard.\n",
    this_player());
  }
  else
  {
    message("info", "Successfully created the "+POWER+" "+TYPE+" shard.\n",
    this_player()); 
  }
  CHARGES--;
  return 1;
}

void extra_init()
{
  add_action("wish_command","wish");
}

void extra_create()
{
  set_short("Box of Shard Creation");
  set_long(wrap("This is a small wooden box with a simple lid. It is "+
  "just about big enough to hold shards, and not much else. You can use the "+
  "'wish' command to generate a random shard. Otherwise, you can gamble:\n"+
  "'wish <magic/skill>,<shard strength>,<name of shard>'\n"+
  "For example, 'wish skill,inferior,combat sense' will attempt to create an "+
  "'Inferior shard of crystallized combat sense skill essence'. The box "+
  "will automatically stop trying after 500 iterations; in theory, this "+
  "should prevent infinite loops. Note that since there are way more skills "+
  "than there are magic effects, getting a skill shard will take more "+
  "luck.\n"));
  set_name("box of shard creation");
  set_id( ({ "box of shard creation", "box"}) );
  set_mass(1);
  set_bulk(1);
  set_possible_to_close(1);
  set_capacity(1);
  set_volume(1);
  set_dynamic_bulk(100);
}