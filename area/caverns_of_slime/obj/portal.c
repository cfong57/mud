#include <mudlib.h>

inherit OBJECT;

void extra_create() 
{
  set_id( ({"small portal filled with crackling energies", "small portal", 
  "portal", "portal_ob"}) );
  set_name("portal");
  set_short("Small portal, filled with crackling energies");
  set_long(wrap(
  "A smallish portal that seems to have appeared out of thin air. It hovers "+
  "right in front of you, and seems to be made entirely of crackling streams "+
  "of multicolored energy. You aren't quite sure if it would be a good idea to"+
  " enter it, since you have no idea where it may lead...\n"));
  set_mass(1);
  set_bulk(1);
  set_prevent_get(1);
  call_out("is_portal_present",1);
}

void extra_init()
{
  add_action("enter_function", "enter");
}

int enter_function(string cmd) 
{ 
	object b = this_object();
    object p = this_player();
    if ( cmd == "portal" ) 
    { 
	    message("movement","You step up to the portal and hesitantly stick "+
	    "your hand in it. With a great WOOSH you suddenly find yourself sucked"+
	    " in!\n",p); 
	    message("movement",""+p->query_cap_name()+" steps up to the portal and"+
	    " sticks a hand in. Without warning, "+p->query_cap_name()+" is "+
	    "suddenly sucked into the portal, and disappears without a "+
	    "trace!\n",environment(p),p); 
	    p->move("/u/a/allanon/area/caverns_of_slime/rooms/ledge");
	    message("info", "The portal closes behind you.\n",p);
        message("info", "The portal seals itself, leaving no trace of its "+
        "existance.\n",environment(b));
        destruct(b);
        return 1; 
    } 
    return notify_fail("Enter what?\n"); 
} 

void is_portal_present()
{
string *ids;
if(!environment(this_object()))
return;
foreach (object o in all_inventory(environment(this_object())))
  { 
    ids = o->query_id();	
    if (member_array("portal_ob", ids) != -1) 
    {
   	if (o != this_object()) 
   	  {
    message("info","The already-present portal dims and fades at the presence "+
    "of a new portal.\n",environment(this_object()));
    destruct(this_object());
   	return;     
	  }
    }
  }
}