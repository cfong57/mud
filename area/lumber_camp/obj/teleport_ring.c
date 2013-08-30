#include <mudlib.h>
#include <move.h>

inherit ARMOR;

string htst;
string destination;
int charges = 5;

int teleport_command(string cmd)
{
  if (!cmd) {
    if (!this_player()->query_battleob()) {
      if(!environment(this_player())->query_no_teleport()) {    
        object p = this_player();
        switch (this_player()->query_home_town()) {
        case "vaerlon":
        htst = "Vaerlon";
        destination = "/d/valkor/vaerlon/rooms/streets/h4.c";
        break;

        case "graemor":
        htst = "Graemor";
        destination = "/d/graemor/virtual/9,18.graemor-part1.c";
        break;

        case "teladan":
        htst = "Teladan";
        destination = "/u/t/tarak/areas/town/rooms/f8.c";
        break;
            
        case "cenedoiss":
        htst = "Cenedoiss";
        destination = "/u/b/belannaer/virtual/18,27.cenedoiss.c";
        break;
      
        //case "mahrakc": ?
  
        case "atherton":
        htst = "Atherton";
        destination = "/u/b/belannaer/virtual/14,13.atherton.c";
        break;

        default:
        htst = "Vaerlon";
        destination = "/d/valkor/vaerlon/rooms/streets/h4.c";
        break;
        }
        message("teleport", "You rub the Ring of Teleportation while thinking "+
        "of your hometown. The air around you shimmers and suddenly you find "+
        "yourself standing in the central square of "+htst+".\n", p);
        message("teleport", ""+p->query_cap_name()+" rubs "+possessive(p)+" "+
        "Ring of Teleportation. The air around "+objective(p)+" starts to "+
        "distort, and suddenly in the blink of an eye "+subjective(p)+" "+
        "disappears.\n", environment(p), p);
        p->move(destination);
        charges--;
        if (charges < 1) {
        call_out("destruct_me", 1);
        }
      } else {
        message("info", "Strange energy fluctuations in this room prevent "+
        "you from teleporting...\n", this_player()); 
      }
    } else {
	  message("info", "You are too busy fighting to do that!\n", this_player());   
    }
    return 1;
  }
}

void extra_init() 
{ 
  add_action("teleport_command", "teleport"); 
} 

void extra_create() 
{
  set_identified(1);
  set_short("Golden Ring of Teleportation");
  set_long(wrap("Other than being an exemplary piece of craftsmanship, there "+
  "does not seem to be anything particularly special about this ring. It "+
  "does not have any sort of magical aura, nor are there any markings on "+
  "it to indicate its true nature. However, for some inexplicable reason, "+
  "merely looking at the ring makes you feel terribly homesick. Images of "+
  "your hometown appear unbidden in your mind's eye, bringing nostalgic "+
  "tears to your eyes which you hurriedly wipe away. What sorcery is "+
  "this...?\n"));
  set_id(({"ring of teleportation", "ring", "golden ring", "gold ring",
  "golden ring of teleportation" }));
  set_name("Ring of Teleportation");
  set_slots(({"finger"}));
  set_material("gold");
  set_type("full plate");
  set_type_desc("ring");
  set_quality(75);
  set_size(175);
  armour_setup();
}

string query_special_feature() 
{ 
  return "This ring can 'teleport' you back to your hometown.\n"+
  "It seems to have "+charges+" use(s) left.";
} 

int query_charges()
{
  return charges;    
}

void destruct_me()
{
  object p = this_player();
  message("destruct", "Your Ring of Teleportation gives off a bright pulse of "+
  "light and slowly fades away to nothingness.\n", p);
  message("destruct", ""+p->query_cap_name()+"'s Ring of Teleportation gives "+
  "off a bright pulse of light and slowly fades away to nothingness.\n",
  environment(p), p);
  this_object()->remove();
  return;
}