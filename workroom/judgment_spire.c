#include <mudlib.h> 
#include <damage.h>

inherit ROOM;
object target;

int judge_cmd(string str)
{
  message("info","You call a lightning bolt to the room...\n",this_player());
  message("info",""+this_player()->query_cap_name()+" calls a lightning bolt "+
  "to the room...\n",environment(this_player()),this_player());
  if(str)
  {
    if(!find_living(str))
    {
      message("info","The target could not be found. Zap aborted.\n",
      this_player());
      message("info","The lightning bolt fades away.\n",
      environment(this_player()),this_player());
    }
    else
    {
      target = find_living(str);
      message("info","You send the lightning bolt to zap "+
      ""+target->query_cap_name()+" "+
      "("+capitalize(target->query_short())+").\n",this_player());
      message("info",""+this_player()->query_cap_name()+" sends the lightning "+
      "bolt to zap "+target->query_cap_name()+" "+
      "("+capitalize(target->query_short())+")!\n",environment(this_player()),
      this_player());
      message("info","A lightning bolt appears from thin air, striking you!\n",
      target);
      message("info","A lightning bolt forms from nowhere and descends on "+
      ""+target->query_cap_name()+"!\n",environment(target),target);
      if(target->query_stunned()) 
      {  
        target->add_stun_duration(100); 
      } 
      else 
      { 
        object ss = new("/obj/battle/stun_shadow",target); 
        if(target->query_stunned())
        {
          target->add_stun_duration(100-ss->query_stun_duration()); 
        }
      } 
      target->receive_damage(100000,LIGHTNING);
    }
    return 1;
  }
  message("info","The lightning bolt fades away.\n",environment(this_player()),
  this_player());
  return notify_fail("You can't decide who to zap, and the lightning bolt "+
  "fades away.\n");
}

int spy_cmd(string str)
{
  if(str)
  {
    if(!find_living(str))
    {
	  message("info","Couldn't find "+str+", aborting spy.\n",this_player());
    }
    else
    {
      target = find_living(str);
      message("info","You decide to spy on "+target->query_cap_name()+" "+
      "("+capitalize(target->query_short())+").\n",this_player());
      message("spy",""+environment(target)->query_look()+"\n"+
      ""+target->query_look()+"\n",this_player());
    }
    return 1;
  }
  return notify_fail("Spy on who?\n");
}

int scan_cmd(string str)
{
  if(str)
  {
	string tar;
    string func;
    sscanf(str,"%s %s",tar,func);
    if(func)
    {
	  if(find_living(tar))
	  {
	    target = find_living(tar);
        message("info","You decide to scan "+target->query_cap_name()+" "+
        "("+capitalize(target->query_short())+") ("+func+" only).\n",
        this_player());
        call_out("scan_func",0,func,target);
      }
      else
      {
	    message("info","Couldn't find "+tar+", aborting scan.\n",this_player());  
      }  
    }
    else
    {
	  if(find_living(str))
	  {
	    target = find_living(str);
        message("info","You decide to scan "+target->query_cap_name()+" "+
        "("+capitalize(target->query_short())+").\n",this_player());
        call_out("scan_func",0,"level",target);
        call_out("scan_func",1,"points",target);
        call_out("scan_func",2,"df",target);
        call_out("scan_func",3,"money",target);
        call_out("scan_func",4,"stats",target);
        call_out("scan_func",5,"resistances",target);
        call_out("scan_func",6,"skills",target);
        call_out("scan_func",7,"spells",target);
        call_out("scan_func",8,"inventory",target);
      }
      else
      {
	    message("info","Couldn't find "+str+", aborting scan.\n",this_player());    
      }
    }
    return 1;
  }
  return notify_fail("Scan who?\n");
}

string text_mapping(mapping things)
{
  string returnme = "";
  mixed *indices = keys(things);
  mixed *values = values(things);
  for(int i = 0; i < sizeof(indices); i++)
  {
    returnme += ""+indices[i]+" : "+values[i]+", ";
  }
  return returnme;
}

varargs void scan_func(string what, object tar)
{
  string printme;
  mapping map = ([]);
  mixed *things = ({ });
  if(!tar)
  {
    tar = this_player();	  
  }
  switch(what)
  {
    case "level":
	message("scan","\nLevel: "+tar->query_level()+"\n",this_player());
	break;
	case "points":
    message("scan","HP: "+tar->query_hp()+" / "+
	""+tar->query_max_hp()+"\n",this_player());
	message("scan","SP: "+tar->query_sp()+" / "+
	""+tar->query_max_sp()+"\n",this_player());
	message("scan","EP: "+tar->query_ep()+" / "+
	""+tar->query_max_ep()+"\n",this_player());
	message("scan","PSP: "+tar->query_psp()+" / "+
	""+tar->query_max_psp()+"\n",this_player());
	break;
	case "df":
	message("scan","Divine favor: "+tar->query_free_dfavor()+"\n",
	this_player());
	break;
	case "money":
    message("scan","Bank credit: "+tar->query_total_bank_balance()+"\n",
    this_player());
    map = tar->query_wealth();
    printme = text_mapping(map);
	message("scan","Money: "+printme+"\n",this_player());
	break;
	case "stats":
	map = tar->query_stats();
	printme = text_mapping(map);
	message("scan","Stats: "+printme+"\n",this_player());
	break;
	case "resistances":
	map = tar->query_resistances();
	printme = text_mapping(map);
	message("scan","Resistances: "+printme+"\n",this_player());
	break;
	case "skills":	
	map = tar->query_skills();
	printme = text_mapping(map);
	message("scan","Skills: "+printme+"\n",this_player());
	break;
	case "spells":	
	map = tar->query_spells();
	printme = text_mapping(map);
	message("scan","Spells: "+printme+"\n",this_player());
	break;
	case "inventory":
	things = tar->query_deep_inventory();
	printme = "";
	foreach(object ob in things)
	{
	  printme += ""+identify(ob)+", ";
	}
	message("scan","Inventory: "+printme+"\n",this_player());
	break;
	default:
	message("scan","Unknown scan function, aborting.\n",this_player());
	break;
  }	  
}

void extra_init()
{
  add_action("judge_cmd","judge");
  add_action("spy_cmd","spy");
  add_action("scan_cmd","scan");
}

void extra_create()
{ 
  set_short("Judgment Spire");
  set_long(wrap("You have reached the top of the tree, but what you find is "+
  "not quite what you expected...Rising from the very top of the oak, which "+
  "you are standing on, is a steep steel spire. Black clouds of foreboding "+
  "whirl beneath you in a frenzied dance of darkness. Lightning bolts flash "+
  "constantly, frequently striking the spire. You are so high up now that you "+
  "can easily see the stars and planets. It is so cold that the moisture from "+
  "your breath freezes and solidifies before it leaves your mouth. The air is "+
  "also so thin that you can barely breathe. You wonder what purpose this "+
  "place has, and moreover, who could tolerate these living conditions.\n"+
  "There's a plaque on the spire that you could look at.\n"));
  set_item_desc(([({"spire", "steel spire", "steep spire", 
  "steep steel spire"}) : "An enormous spire made of steel, rising right out "+
  "of the tree's trunk. It acts somewhat like a lightning rod, and you wonder "+
  "if it was built to protect people from being zapped. There is a plaque on "+
  "the spire that you could look at.\n",
  ({"clouds", "black clouds", "lightning", "lightning bolts"}) : "Black "+
  "clouds seem to form a sable sea beneath you. Lightning flashes through "+
  "like furious white wolves. It truly is a magnificent, and terrifying, "+
  "sight to behold.\n",
  ({"stars", "planets", "sky"}) : "Due to being so high up, you can clearly "+
  "see the stars, planets, and other extraterrestrial sights.\n",
  "plaque" : "The plaque is made of gold with very fancy engraving. You can't "+
  "quite make out what it says...it looks like a lightning bolt scored a "+
  "direct hit. There are a few words left, 'judge', 'spy', 'scan'...you "+
  "wonder what the rest of the plaque said.\n"]));  
  set_exits((["down" : "/u/a/allanon/workroom/middle-tree"]));
  set_exit_msg((["down": "$N descends the Spire."]));
} 

int query_temperature() { return -255; }