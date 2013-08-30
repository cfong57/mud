#include <mudlib.h>

inherit OBJECT;

int AREA = 1920000;
int ERRORS = 0;

void clear_progress()
{
  AREA = 1920000;
  write_file("/u/a/allanon/logs/temp_log","",1);	
}

// 1------X1-------2
// |               |
// |               Y
// |    A1         1
// |               |
// 4-----5---------3
// |     |
// |  A  Y
// |  2  2
// |     |
// 7-X2--6
/*
string check_if_mapped(int x, int y, int length, int height)
{
	
  if(NE[0] < X1 && SE[1] < Y1)
  {
    return "0 0 0 0"; //wholly inside A1, do nothing
  } 
  else if(NE[0] < X2 && SE[1] < Y1 + Y2)
  {
    return "0 0 0 0"; //wholly inside A2 or A1, do nothing
  }
  else if(NE[0] > X1 && SE[1] < Y2)
  {
    string new_start;
    new_start = ""+NE[0] - X1+" "+NE[1]+"";
  }
  else
  {
    return 1;	  
  }
  
  return ""+x+" "+y+" "+length+" "+height+"";
}*/

int worldmap_command(string cmd)
{
  //1600 x 1200 = 1920000
  object room;
  int x;
  int y;
  string failures = "";
  if(cmd)
  {
	sscanf(cmd,"%d %d",x,y);
	if(x >= 0 && y >= 0 && x + 10 <= 1600 && y + 10 <= 1200)
	{
	  //int newx;
	  //int newy;
	  //int newlengthx;
	  //int newlengthy;
	  //string temp;
	  //temp = check_if_mapped(startx, starty, lengthx, lengthy);
	  //sscanf(temp,"%d %d %d %d",newx,newy,newlengthx,newlengthy);
	  for(int i = y; i < y + 10; i++)
      {
        for(int j = x; j < x + 10; j++)
        {
	      string err;
	      err = catch(room = 
	      load_object(sprintf("/d/world/rooms/%d,%d.world",j,i)));
          if(!room || err)
          {       
	        if(err)
	        {
		      write(err+"\n");      
	        }
            failures += ""+j+","+i+" ";
            ERRORS++;
          }
          else
          {
	        AREA--;
            if(room->query_outside() == "?")
            {
	          message("info",""+identify(room->query_coordinates())+" "+
	          ""+room->query_outside()+" ",
	          this_player());
	          write_file("/u/a/allanon/logs/temp_log",
	          ""+identify(room->query_coordinates())+" :\n");
            }
          }
        }
      }
      message("info","Finished mapping 10x10 world map "+
      "starting at "+x+","+y+".\n",this_player());
      if(failures != "")
      {
        message("info","Failed to find a room at the following coordinates: "+
        ""+failures+" .\n",this_player());
      }
    }
    else
    {
	  message("info","Failed to get a positive x and/or y, or x and/or y "+
	  "length too large. (1600x1200)\n",this_player());   
    }
    return 1;
  }
  return notify_fail("Usage: 'worldmap <x> <y>'.\n");
}

int progress_command(string cmd)
{
  if(cmd == "wipe")
  {
    clear_progress();
    message("info","Wiped the progress map.\n",this_player());	
    return 1;  
  }
  else if(!cmd)
  {
    message("info","Found "+AREA+" unmapped rooms ("+ERRORS+" errors).\n",
    this_player());
    return 1;
  }
  else
  {
    return notify_fail("No args, or 'progress wipe'.\n");	  
  }	
}

int allmap_command(string cmd)
{
  if(!cmd)
  {
	int z = 0;
    for(int i = 0; i < 1201; i += 10)
    {
	  for(int j = 0; j < 1601; j += 10)
	  {
	    call_out("worldmap_command",z,""+j+" "+i+"");
	    z++;
	  }
    }
    return 1;
  }
  return notify_fail("No args.\n");	
}

void STOP_ME()
{
  remove_call_out();	
}

void extra_init()
{
  add_action("worldmap_command","worldmap");
  add_action("progress_command","progress");
  add_action("allmap_command","allmap");
  
}

void extra_create()
{
  set_short("The Mapper(tm)");
  set_long(wrap("This object is used to map the world and find the "+
  "coordinates of '?'. 'worldmap <x> <y> <length x> <length y>' scans a "+
  "<length x> x <length y> block starting at <x>,<y>. 'progress' shows how "+
  "many more rooms are left to map plus errors, and 'progress wipe' clears "+
  "the progress map. Note that it will only work if one starts at 0,0 and "+
  "goes right, then down, then right, like reading a book. 'allmap' attempts "+
  "to do the entire world map in one go.\n"));
  set_name("the mapper");
  set_id( ({ "the mapper", "mapper" }) );
  set_mass(1);
  set_bulk(1);
}