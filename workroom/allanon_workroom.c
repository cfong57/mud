#include <config.h>
#include <mudlib.h>
#include <move.h>

inherit ROOM;

int clean_up(int inh) 
{ 
  return 1; 
}

void reset() 
{ 
  return; 
}

string r = "%^RESET%^";
string m = "%^MAGENTA%^";
string g = "%^BOLD%^%^BLACK%^";
object ereldon;
//object spyshadow;

int climb_cmd(string cmd)
{
  if(cmd == "tree" || cmd == "oak tree" || cmd == "venerable tree")
  {
    message("climb","You climb up the tree, higher and higher and higher...\n"+
    "Eventually you even pass the cloud layer. You have some trouble "+
    "breathing here. Maybe you should think about going back down...\n",
    this_player());
    message("climb",""+this_player()->query_cap_name()+" climbs up the tree.\n",
    environment(this_player()),this_player());
    this_player()->move("/u/a/allanon/workroom/middle-tree.c",1);
    return 1;
  }
  return notify_fail("Climb what? Perhaps tree?\n");
}

int map_command(string cmd)
{
  if(!cmd)
  message("map",//The code is very messy but it looks good in game. Trust me.
  "\n"+//saves first line of map from prompt slicing
  ""+g+"P"+r+"^"+m+"#####"+r+"."+m+"#"+r+""+g+"J"+r+""+m+"#"+r+"."+m+"###"+r+""+
  "      ! - Magik Shoppe\n"+                             
  "^..............      & - Army of Vaerlon\n"+                           
  ""+m+"#"+r+"."+m+"#"+r+"."+m+"###"+r+"."+m+"#######"+r+"      "+
  "+ - Temple of the Elements\n"+                    
  ""+m+"#"+r+"."+m+"#"+r+"."+m+"###"+r+"."+m+"##"+r+""+g+"A"+r+"....      "+
  "0 - The Monument of Stonement\n"+                 
  ""+m+"#"+r+"."+m+"###"+r+""+g+"I"+r+""+m+"#"+r+"."+m+"###"+r+"."+
  ""+m+"#"+r+""+g+"S"+r+""+m+"#"+r+"      = - Snowfall\n"+                                  
  ""+m+"#"+r+"..."+m+"#"+r+"..."+m+"##"+r+""+g+"W"+r+"....      "+
  "A - Armour Shop\n"+                               
  ""+m+"#"+r+"."+m+"###"+r+""+g+"L"+r+""+m+"#"+r+"."+m+"#######"+r+"      "+
  "I - Double Dragon Inn\n"+                         
  ""+m+"#"+r+"..."+m+"###"+r+"@.......      J - Gem Shop\n"+                                  
  ""+m+"#"+r+"."+m+"#"+r+"."+m+"###"+r+"."+m+"###"+r+"."+m+"###"+r+"      "+
  "L - Locker office\n"+                             
  ""+m+"#"+r+"."+m+"#"+r+"."+g+"&"+r+""+m+"##"+r+"."+m+"##"+r+""+g+"!"+r+"...."+
  "      P - Palace\n"+                                    
  ""+m+"#"+r+"."+m+"#"+r+""+g+"W"+r+""+m+"##"+r+"."+m+"#"+r+"."+m+"##"+r+"."+
  ""+m+"###"+r+"      S - General Shop\n"+                              
  ""+m+"#"+r+"."+m+"###"+r+"."+m+"###"+r+"."+m+"#"+r+".."+g+"="+r+".      "+
  "W - Weapon Shop\n"+                               
  "."+m+"#"+r+"."+m+"##"+r+"."+m+"###"+r+"."+m+"#"+r+"."+m+"###"+r+"\n"+       
  ""+m+"#"+r+""+g+"0"+r+""+m+"#"+r+"..."+g+"+"+r+""+m+"##"+r+"."+m+"#"+r+""+
  "....      @ - You\n"+ 
  "."+m+"#"+r+"."+m+"##"+r+"."+m+"###"+r+"."+m+"#####"+r+"\n",this_player());
  return 1;
}

void extra_init()
{
  add_action("map_command","map");	
  add_action("climb_cmd","climb");
}

void extra_create()
{
  seteuid( getuid() );
  set_outside("-"); 
  set_outdoors("-");
  set_start_ok(1);
  set_short("Central Park II"); //wrap() breaks this
  set_long("...%^RESET%^%^MAGENTA%^#%^RESET%^%^MAGENTA%^#%^RESET%^ You are "+
"standing in the center of the Central Park of \n%^BOLD%^L%^RESET%^"+
"%^MAGENTA%^#%^RESET%^.%^RESET%^%^MAGENTA%^#%^RESET%^%^MAGENTA%^#"+
"%^RESET%^ Vaerlon. Shorty Street goes to the east and Main Street \n"+
"%^MAGENTA%^##%^RESET%^@%^RESET%^.%^RESET%^.%^RESET%^ continues to "+
"the north and south. You can hear birds singing \n%^MAGENTA%^##%^RESET%^"+
".%^RESET%^%^MAGENTA%^#%^RESET%^%^MAGENTA%^#%^RESET%^ and see "+
"squirrels jumping from tree to tree. There is a \n%^MAGENTA%^##%^RESET%^"+
".%^RESET%^%^MAGENTA%^#%^RESET%^%^MAGENTA%^#%^RESET%^ map nailed "+
"on a nearby tree. \nA sign is hanging on the wall, with the headline 'City "+
"rules repealed'\n"+
  "\n"+
  "You are in the Universe of Allanon.\n");
  add_monster("/u/a/allanon/mon/nhillas");
  add_monster("/u/a/allanon/mon/phaedra");
  add_monster("/u/n/neurotico/mon/eq_channeler");
  add_object("/d/valkor/obj/misc/lamp");
  add_object("/obj/misc/trashcan");
  add_object("/obj/food/fountain");
  add_object("/u/n/neurotico/obj/fc_dispenser");
  set_item_desc(([
  "map" : "The map nailed on the tree looks like the map of Vaerlon. You "+
  "could type 'map'.\n",
  "tree" : "A venerable oak tree. It was probably here before Vaerlon was "+
  "even built. It's so tall that you can't see the top. There are some "+
  "footholds that you can reach, perhaps you could 'climb tree'.\n",
  "sign" : "As you take a closer look at the sign, you notice it's made of "+
  "paper and it reads with a large text:\n"+
  "\n\t\tCity rules in Vaerlon - repealed"+
  "\n\t\t================================"+
  "\n\n\t1) FOREIGN TRAVELLERS MAY WIELD WEAPONS IN THE CITY\n\t"+
  "2) THE ENEMIES OF VAERLON WILL NOT BE KILLED ON SIGHT"+
  "\n\t3) A TOLL FEE NEED NOT BE PAID, WHEN ASKED AT THE CITY GATES\n\t"+
  "4) FIGHTING IS ALLOWED IN THE CITY\n\t"+
  "5) SLEEPING ON THE STREETS IS PERMITTED"+
  "\n\n\t\n\t\t\t-- The Council of Vaerlon\n\n"]));  
  set_exits(([ 
  "south" : "/d/valkor/vaerlon/rooms/streets/i4", 
  "north" : "/d/valkor/vaerlon/rooms/streets/g4", 
  "east" : "/d/valkor/vaerlon/rooms/streets/h5", 
  "other" : "/u/a/allanon/workroom/connector"]));
  set_exit_msg(([ 
  "other": "$N leaves through a hidden fold in between the 0's and 1's."])); 
  call_out("finish_create", 1);
  ::reset();
}

void finish_create()
{
  ereldon = new("/d/valkor/vaerlon/monsters/ereldon");
  ereldon->move(this_object(),1);
  ereldon->set_friends(({"/u/a/allanon/mon/nhillas"}));	
  ereldon->set_ac(1000000);
  ereldon->set_natural_ac(1000000);
  ereldon->set_resistances(([ "fire" : 99, "magical" : 99, "sonic" : 99, 
  "psionic" : 99, "poison" : 99, "cold" : 99, "asphyxiation" : 99,
  "physical" : 99, "lightning" : 99, "acid" : 99 ]));
  /*spyshadow = new("/u/a/allanon/shadows/spyshadow.c");
  spyshadow->move(ereldon,1);
  spyshadow->shadow_object(ereldon);
  spyshadow->check_status();*/
}