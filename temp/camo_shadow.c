#include <mudlib.h>

#define SO shadowed_object()

inherit SHADOW;

varargs
string query_short(int flag);

string query_short2();

string long;
string short;
string *id;
string race;
string name;
string gender;
string species;
int size;
int merged;

void create(object plr)
{
  if(!clonep(this_object()))
    return;
  
  if(!plr)
    destruct(this_object());  
  shadow_object(plr);
  if(!SO)
    destruct(this_object());
  long = SO->query_long();
  short = SO->query_short();
  race = SO->query_race();
  size = SO->query_stat("size");
  name = SO->query_name();
  gender = SO->query_gender();
  species = SO->query_species();
  id = SO->query_id();
}

int remove_camo_shadow()
{
  destruct(this_object());
}

void change_back()
{
  message("info","Your eyes blur again and you feel that you have lost your "+
   "merged state.\n",SO);
  message("info",query_short2()+" changes before your eyes to "+SO->query_cap_name()+
   ", amazing!\n",environment(SO),SO);
  remove_camo_shadow();
}

object query_camo_shadow()
{
  return this_object();
}

void merge_user(string l, string s, string *i, string r, int sz, string n, 
                string g, string sp)
{
  long = l;
  short = s;
  id = i;
  race = r;
  merged = 1;
  size = sz;
  name = n;
  gender = g;
  species = sp;
  call_out("change_back",600);
}

string query_long()
{
  return long;
}

string query_look()
{
  string look, sub;
  
  switch(gender){
    case "male":
    sub = "He";
    break;
    case "female":
    sub = "She";
    break;
    case "neuter":
    sub = "It";
    break;
    default:
    sub = "It";
    break;
  }
  look = long+sub+" is "+article(race)+" "+race+" and "+verbalize_size(size,350)+" of size.\n"+
         capitalize(name)+" "+"/cmds/std/_shape.c"->shape_desc(SO->query_hp(), 
         SO->query_max_hp(), species);
  return look;
}

varargs
string query_short(int flag) 
{ 
  if(flag) 
    return SO->query_short(flag); 
  else if(merged)
    if(SO->query_hp() * 1.0 / SO->query_max_hp() >= 1.0)
      return "%^RESET%^"+this_player()->query_lite("monster")+capitalize(short)+"%^RESET%^";
    else
      return "%^RESET%^"+this_player()->query_lite("woundedmonster")+capitalize(short)+"%^RESET%^";
  else
    return SO->query_short(flag);
}

string query_short2()
{
      return "%^RESET%^"+capitalize(short)+"%^RESET%^";
}
string *query_id()
{
  return id;
}

string query_race()
{
  return race;
}

string query_species()
{
  return species;
}

int query_stat(string str)
{
  switch(str){
    case "size":
    return size;
    default:
    return SO->query_stat(str);
  }
}

varargs int kill_ob(object target, int flag)
{
  SO->kill_ob(target, flag);
  change_back();
}

varargs int receive_damage(int damage, int type, string slot, int precalculated)
{
  SO->receive_damage(damage, type, slot, precalculated);
  change_back();
}

