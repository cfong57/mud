int autonumber = 0;

mapping add = ([]);
mapping remove = ([]);
mapping steal = ([]);

//"action" : (["actor1" : ({event1, event2, ...})])
//event = "ob->query_cap_name(),(base_name(ob)),ctime(time())"

mapping actions = (["add" : add, "remove" : remove, "steal" : steal]);

object *events; //temp array for operations

string query_contents(string what, string who, int tail)
{
  string returnme = "";
  if(member_array(what, keys(actions)))
  {
    if(who)
    {
	  if(member_array(who, keys(actions[what])))
	  {
	    if(tail) //starts listing from bottom/most recent
	    {
		  returnme += "Tail of report for "+who+" doing "+what+":\n";
		  for(int i = sizeof(actions[what][who]) - 1; i >= 0; i--)
		  {
		    returnme += actions[what][who][i];
		  }
	    }
	    else
	    {
		  returnme += "Report for "+who+" doing "+what+":\n";
		  for(int i = 0; i < sizeof(actions[what][who]); i++)
		  {
		    returnme += actions[what][who][i];
		  }   
	    }
	  }
	  else
	  {
	    returnme = "No such person recorded in log for "+what+".\n";
	  }  
    }
    else
    {
	  returnme = "No person specified.\n";
    }
  }
  else
  {
    returnme = "Invalud argument "+what+" - must be 'add', 'remove', "+
    "'steal'.\n";  
  }
  return returnme;
}

void check_for_events(string act, string who)
{
  //iterate through the people already in the mapping. if person is already in
  //the mapping, get person's previously recorded events and add to events array
  foreach(string x in keys(actions[act]))
  {
    if(x == who)
    {
	  events = actions[act][who];
    }	  
  }
}

void add_event(string act, string who, object what)
{
  events = ({}); //reset events array
  check_for_events(act, who);
  events += ({""+autonumber+","+what->query_cap_name()+","+base_name(what)+","+
  ","+ctime(time())+"\n"}); //add newest event to events array
  //overwrite previous value with new events array
  actions[act][who] = events;
  autonumber++;
}

void remove_event(int x)
{
  int temp;
  foreach(string act in keys(actions))
  {
    foreach(string who in keys(actions[act]))
    {
	  int index = 0;
	  foreach(string event in actions[act][who])
	  {
	    sscanf(event, "%d", temp);
	    if(x == temp)
	    {
		  actions[act][who] -= ({actions[act][who][index]});   
	    }
	    index++;
	  }
    }
  }	
}

void delete_actions(string argument)
{
  if(argument == "all")
  {
    add = ([]);
    remove = ([]);
    steal = ([]);
  }
  else if(member_array(argument, keys(actions)))
  {
    actions[argument] = ([]);
  }
  else
  {
    message("error","Not a valid argument - "+argument+"\n",this_player());
  }
}