#include <mudlib.h>
#include <damage.h>

inherit OBJECT;

string colour;
string hilite;

int query_not_saveable() 
{ 
  return 1; 
}

int sniff_command(string cmd)
{
  if ( cmd == "flower" ) {
    object p = this_player();
    message("info", "You sniff the "+colour+" flower, and get a happy "+
    "feeling.\n", p); 
    message("info", ""+p->query_cap_name()+" sniffs "+possessive(p)+" "+
    ""+colour+" flower and smiles happily.\n",environment(p), p);
    switch (random(4)) {
      case 0:
      message("heal_hp", "You feel very slightly healed.\n", p);
      p->receive_healing(50 + random(10));
      break;
      case 1:
      message("heal_sp", "Your magical powers are recovered slightly.\n", p);
      p->receive_healing(50 + random(10), "sp");
      break;
      case 2:
      message("heal_ep", "You feel slightly less tired.\n", p);
      p->receive_healing(50 + random(10), "ep");
      break;
      case 3:
      message("heal_psp", "Your mental powers are recovered slightly.\n", p);
      p->receive_healing(50 + random(10), "psp");
      break;
    }
    message("info", "The "+this_object()->query_name()+" wilts and shrivels "+
    "away to dust.\n", environment(this_player()));
    this_object()->remove();
    return 1;
  }
  return notify_fail("Sniff what?\n");  
}  

void extra_init() 
{ 
  add_action("sniff_command", "sniff"); 
} 

void extra_create() 
{
  switch (random(15)) {
    case 0:
    colour = "black";
    break;
    case 1:
    colour = "red";
    break;
    case 2:
    colour = "pink";
    break;
    case 3:
    colour = "dark green";
    break;
    case 4:
    colour = "bright green";
    break;
    case 5:
    colour = "orange";
    break;
    case 6:
    colour = "yellow";
    break;
    case 7:
    colour = "blue";
    break;
    case 8:
    colour = "sea-blue";
    break;
    case 9:
    colour = "cyan";
    break;
    case 10:
    colour = "sky-blue";
    break;
    case 11:
    colour = "dark magenta";
    break;
    case 12:
    colour = "bright magenta";
    break;
    case 13:
    colour = "grey";
    break;
    case 14:
    colour = "white";
    break;
  }
  //could the following also be done with a switch?
  if (colour == "black") {
    hilite = "BOLD%^BLACK";
  }
  if (colour == "red") {
    hilite = "RED";
  }
  if (colour == "pink") {
    hilite = "BOLD%^RED";
  }
  if (colour == "dark green") {
    hilite = "GREEN";
  }
  if (colour == "bright green") {
    hilite = "BOLD%^GREEN";
  }
  if (colour == "orange") {
    hilite = "ORANGE";
  }
  if (colour == "yellow") {
    hilite = "YELLOW";
  }
  if (colour == "blue") {
    hilite = "BLUE";
  }
  if (colour == "sea-blue") {
    hilite = "BOLD%^BLUE";
  }
  if (colour == "cyan") {
    hilite = "CYAN";
  }
  if (colour == "sky-blue") {
    hilite = "BOLD%^CYAN";
  }
  if (colour == "dark magenta") {
    hilite = "MAGENTA";
  }
  if (colour == "bright magenta") {
    hilite = "BOLD%^MAGENTA";
  }
  if (colour == "grey") {
    hilite = "WHITE";
  }
  if (colour == "white") {
    hilite = "BOLD%^WHITE";
  }
  set_short("A beautiful %^"+hilite+"%^"+colour+"%^RESET%^ flower");
  set_id( ({"beautiful "+colour+" flower", "beautiful flower", "flower",
  ""+colour+" flower"}) );
  set_name(""+colour+" flower");
  set_long(wrap("It's a beautiful "+
  "%^"+hilite+"%^"+colour+"-coloured%^RESET%^ flower. It smells wonderful, "+
  "and you consider sniffing it.\n"));
  set_value(1);
  set_mass(1);
  set_bulk(1);
}