#include <mudlib.h>

inherit ARMOR;

string mat;
string typ;
int designation;

/*
standard

chain mail
double chain mail
augmented chain mail
scale mail
lamellar
brigandine
laminated
plate mail
full plate

studded
ring mail
bezainted

1 = metals; all but standard
2 = cloths and clay; standard only
3 = chitin, stone, wood; scale mail only
4 = bone, dragonscale, and ancient dragonscale; standard or scale mail

studded $: chitinium silk, heavy cloth, leather, soft leather
$ ring mail: leather, heavy cloth
$ bezainted: leather, cuir-boulli
*/

void extra_create() 
{
  switch(random(31)) //Picks a random material. Stone and wood are included.
  {
  case 0:
  mat = "adamantium";
  designation = 1; //Designation is used by next switch to pick acceptable type.
  break;
  case 1:
  mat = "aluminium";
  designation = 1;
  break;
  case 2:
  mat = "bone";
  designation = 3;
  break;
  case 3:
  mat = "bronze";
  designation = 1;
  break;
  case 4:
  mat = "chitin";
  designation = 3;
  break;
  case 5:
  mat = "chitinium silk";
  designation = 2;
  break;
  case 6:
  mat = "clay";
  designation = 2;
  break;
  case 7:
  mat = "cloth";
  designation = 2;
  break;
  case 8:
  mat = "heavy cloth";
  designation = 2;
  break;
  case 9:
  mat = "copper";
  designation = 1;
  break;
  case 10:
  mat = "cuir-boulli";
  designation = 2;
  break;
  case 11:
  mat = "demonhide";
  designation = 2;
  break;
  case 12:
  mat = "dragonscale";
  designation = 3;
  break;
  case 13:
  mat = "ancient dragonscale";
  designation = 3;
  break;
  case 14:
  mat = "fur"; 
  designation = 2;
  break;
  case 15:
  mat = "gold";
  designation = 1;
  break;
  case 16:
  mat = "iceron";
  designation = 1;
  break;
  case 17:
  mat = "iron";
  designation = 1;
  break;
  case 18:
  mat = "lead";
  designation = 1;
  break;
  case 19:
  mat = "leather";
  designation = 2;
  break;
  case 20:
  mat = "soft leather";
  designation = 2;
  break;
  case 21:
  mat = "mithril";
  designation = 1;
  break;
  case 22:
  mat = "platinum";
  designation = 1;
  break;
  case 23:
  mat = "silk";
  designation = 2;
  break;
  case 24:
  mat = "silver";
  designation = 1;
  break;
  case 25:
  mat = "steel";
  designation = 1;
  break;
  case 26:
  mat = "fine steel";
  designation = 1;
  break;
  case 27:
  mat = "stone";
  designation = 3;
  break;
  case 28:
  mat = "tin";
  designation = 1;
  break;
  case 29:
  mat = "titanium";
  designation = 1;
  break;
  case 30:
  mat = "wood";
  designation = 3;
  break;
  }
  switch(designation)//Picks the type and/or foundation based on designation #.
  {  
  case 1:    
  switch(random(12)) 
  {                 
  case 0:
  typ = "chain mail"; 
  break;
  case 1:
  typ = "double chain mail"; 
  break;	
  case 2:
  typ = "augmented chain mail"; 
  break;	
  case 3:
  typ = "scale mail"; 
  break;	
  case 4:
  typ = "lamellar"; 
  break;	
  case 5:
  typ = "laminated"; 
  break;	
  case 6:
  typ = "brigandine"; 
  break;	
  case 7:
  typ = "plate mail"; 
  break;	
  case 8:
  typ = "full plate"; 
  break;  
  case 9:
  typ = "studded $";  
  switch(random(4))
  {
  case 0:
  set_foundation("chitinium silk");
  break;
  case 1:
  set_foundation("heavy cloth");
  break;
  case 2:
  set_foundation("leather");
  break;
  case 3:
  set_foundation("soft leather");
  break;	  
  }  
  break;  
  case 10:
  typ = "$ ring mail"; 
  switch(random(2))
  {
  case 0:
  set_foundation("leather");
  break;
  case 1:
  set_foundation("heavy cloth");
  break;
  }	  
  break; 
  case 11:
  typ = "$ bezainted";
  switch(random(2))
  {
  case 0:
  set_foundation("cuir-boulli");
  break;
  case 1:
  set_foundation("leather");
  break;	  
  }
  break;
  }
  break; 
  case 2:
  typ = "standard";
  break;
  case 3:
  typ = "scale mail";
  break;
  }
  set_auto_short(1);
  set_long(wrap("A rather simple piece of clothing, this "+mat+" glove "+
  "still provides some protection. It is quite thin, but then again that "+
  "increases finger mobility.\n"));
  set_id( ({""+mat+" "+typ+" glove", ""+mat+" glove", ""+typ+" glove", 
  "glove"}));
  set_name(""+mat+" glove");
  set_slots( ({"hand"}) );
  set_material(""+mat+"");
  set_type(""+typ+"");
  set_type_desc("glove");
  set_quality(random(75));
  set_size(20);
  armour_setup();
}