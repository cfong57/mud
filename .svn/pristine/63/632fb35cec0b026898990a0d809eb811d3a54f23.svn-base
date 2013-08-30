#include <mudlib.h>
#include "get_me_a_shrubbery.h"

inherit ROOM;

int shrub_function(string cmd)
{
  if(cmd)
  {
	object obj;
	string obid;
	string target;
	sscanf(cmd,"%s %s",target,obid);
    if(obid)
    {	    
	  if(find_living(obid))
	  { 
	    obj = find_living(obid);	  
	  }
	  else if(get_me_a_shrubbery(obid,this_player()))
	  {
	    obj = get_me_a_shrubbery(obid,this_player());
      }
      else if(get_me_a_shrubbery(obid,this_object()))
	  {
	    obj = get_me_a_shrubbery(obid,this_object());
      }
	  else
	  {
        message("info","Couldn't locate "+obid+", aborting.\n",this_player());
        return 1;
	  }
	  message("shrub","Attempting to shrub with string "+target+" and "+
	  "container "+obid+"...\n"+
	  "Result: returned "+query_shrub(target, obj)+".\n",this_player());
      return 1;
    }
    else
    {
	  message("shrub","Attempting to shrub with string "+cmd+" and container "+
      "this room...\nResult: returned "+query_shrub(cmd)+".\n",
      this_player());
      return 1;  
    }
  }
  return notify_fail("Syntax: 'shrub <string> <optional:container>'\n");
}

int allshrub_function(string cmd)
{
  if(cmd)
  {
	mixed *things = ({ });
	object obj;
	string obid;
	string target;
	sscanf(cmd,"%s %s",target,obid);
    if(obid)
    {	    
	  if(find_living(obid))
	  { 
	    obj = find_living(obid);	  
	  }
	  else if(get_me_a_shrubbery(obid,this_player()))
	  {
	    obj = get_me_a_shrubbery(obid,this_player());
      }
      else if(get_me_a_shrubbery(obid,this_object()))
	  {
	    obj = get_me_a_shrubbery(obid,this_object());
      }
	  else
	  {
        message("info","Couldn't locate "+obid+", aborting.\n",this_player());
        return 1;
	  }
	  message("allshrub","Attempting to allshrub with string "+target+" and "+
	  "container "+obid+". Found the following things:\n",this_player());
	  things = get_me_all_the_shrubberies(target,obj);
	  foreach(object ob in things)
	  {
	    message("allshrub",""+ob->query_short()+"\n",this_player());  
	  }
      return 1;
    }
    else
    {
	  message("allshrub","Attempting to allshrub with string "+cmd+" and "+
	  "container this room. Found the following things:\n",this_player());
	  things = get_me_all_the_shrubberies(cmd);
	  foreach(object ob in things)
	  {
	    message("allshrub",""+ob->query_short()+"\n",this_player());  
	  }
      return 1;  
    }
  }
  return notify_fail("Syntax: 'allshrub <string> <optional:container>'\n");
}

int present_function(string cmd)
{
  if(cmd)
  {
	object obj;
	object temp;
	string obid;
	string target;
	int found;
	sscanf(cmd,"%s %s",target,obid);
    if(obid)
    {	    
	  if(find_living(obid))
	  { 
	    obj = find_living(obid);	  
	  }
	  else if(present(obid,this_player()))
	  {
	    obj = present(obid,this_player());
      }
      else if(present(obid,this_object()))
	  {
	    obj = present(obid,this_object());
      }
	  else
	  {
        message("info","Couldn't locate "+obid+", aborting.\n",this_player());
        return 1;
	  }
	  temp = present(target, obj);
	  if(temp)
	  {		
	    found = 1;
	  }
	  else
	  {
	    found = 0;
	  }
	  message("present","Attempting to present with string "+target+" and "+
	  "container "+obid+"...\nResult: returned "+found+".\n",this_player());
      return 1;
    }
    else
    {
      temp = present(cmd);
	  if(temp)
	  {
	    found = 1;
	  }
	  else
	  {
	    found = 0;
	  }
	  message("present","Attempting to present with string "+cmd+" and "+
	  "container this room...\n"+
	  "Result: returned "+found+".\n",this_player());
      return 1;  
    }
  }
  return notify_fail("Syntax: 'present <string> <optional:container>'\n");
}

void extra_init()
{
  add_action("shrub_function","shrub");
  add_action("allshrub_function","allshrub");	
  add_action("present_function","present");
}

void extra_create()
{
  set_short( "Allanon's Arboreum" );
  set_long(wrap("This room is filled with all kinds of shrubs, in various "+
  "shapes and sizes. The functions in <get_me_a_shrubbery.h> are tested "+
  "here, in the hopes that one day they will be coded by real wizards. You "+
  "can also contrast the results with the existing present() function.\n"+
  "'shrub <string> <optional:container>'\n"+
  "'present <string> <optional:container>'\n"+
  "Both functions attempt to find <string> in <container>, or defaults to "+
  "searching in this room; however, shrub's <string> can search by "+
  "filename, id, or short.\n"+
  "'allshrub <string> <optional:container>'\n"+
  "Same as shrub, but returns all of the matching objects instead of just "+
  "the first one.\n"+
  "0 is false (couldn't find), 1 is true (found).\n"+
  "Supposedly you can do present(object ob), but I don't know how...\n"));
  set_exits(([
  "out" : "/u/a/allanon/workroom/connector.c"]));
  add_object("/u/a/allanon/obj/shardbox.c");
}