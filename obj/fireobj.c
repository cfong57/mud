/*
  the fireobject

  stays on for FIRE_LASTS minutes. water helps.
  
  spreads to adjancent rooms. how easily it spreads depends on the 
  roomtype. if there is water on the room is slows the spreading process
  down or may even stop it.
  
  when the room is full burnt, if becomes 'a' - ash.
  then it slowly starts to turn into what it was.
*/

/* how long the fire lasts, in 30 sec call_out rounds */

#include <mudlib.h>

#define FIRE_LASTS 60*30     // 30 minutes
#define SPREAD_CHANCE 25   // chance in percents per 30 seconds of spreading
#define CALL_OUT_LENGTH 30   // 30 for the real thing

#define BURNING ({"p", "m", "M", "w", "W", "f", "F", "e", "E", "d", "D"})


// BADlands, badlands, plains, meadow, deep meadow
#define GROWTH_ARRAY ({"Z", "z", "p", "m", "M"})




#define MY_DAEMON "/adm/daemons/world_d"

int    time_left = FIRE_LASTS;  // time left to burn.
string orig_type = "";          // the original outworld room type. 
int    x;                       // the coordinates
int    y;                       // we're at
object our_env;

int *spread_map = ({ -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 });
    


int create()
{
  ; // no definitions yet
}

int move(mixed dest)
{
  object to_ob;
  string err;
  
  if (stringp(dest))
  {
    err = catch(to_ob = load_object(dest));
    if (!to_ob || err)
    {
      if (err)
        write(err+"\n");

      return 0;
    }
  }
  else
    to_ob = dest;

  move_object(to_ob);
}



int start()
{
  int *tmp_coords;
  
  // no environment? not outside?

  if(! (our_env = environment(this_object())) || 
     ! (tmp_coords = our_env->query_coordinates()))
    {
      GDEBUG("returns " + base_name(environment(this_object())));
      destruct(this_object());
      return 0;
    }
  
  x = tmp_coords[0];
  y = tmp_coords[1];
  orig_type = our_env->query_outside();

  // fire is burning hot yeah baby!
  our_env->set_base_temp(3000);
  
  // change the map into \", which is fire.
  MY_DAEMON->modify_map(x,y,"\"");
  call_out("call_out_cycle", CALL_OUT_LENGTH);

  return 1;
}


void remove()
{
  string *g_arr;
  
  if(x && y)
    MY_DAEMON->modify_map(x,y,"a");
  if(our_env)
    our_env->set_base_temp(0);
  
  switch(orig_type)
    {
    case "p":
      g_arr = GROWTH_ARRAY[0..2];
      break;
    case "m":
      g_arr = GROWTH_ARRAY[0..3];
      break;
    case "M":
      g_arr = GROWTH_ARRAY[0..4];
      break;
    case "f":
      g_arr = GROWTH_ARRAY[0..4] + ({"f"});
      break;
    case "F":
      g_arr = GROWTH_ARRAY[0..4] + ({"f","F"});
      break;
    case "w":
      g_arr = GROWTH_ARRAY[0..4] + ({"w"});
      break;
    case "W":
      g_arr = GROWTH_ARRAY[0..4] + ({"w","W"});
      break;
    case "d":
      g_arr = GROWTH_ARRAY[0..4] + ({"d"});
      break;
    case "D":
      g_arr = GROWTH_ARRAY[0..4] + ({"d","D"});
      break;
    case "e":
      g_arr = GROWTH_ARRAY[0..4] + ({"e"});
      break;
    case "E":
      g_arr = GROWTH_ARRAY[0..4] + ({"e","E"});
      break;
    }

  MY_DAEMON->add_data(x, y, "modified", (["time_left" : 4, 
                                         "time" : 3, 
                                         "mod_array" : g_arr]) );
  
  destruct(this_object());
}

void call_out_cycle()
{
  time_left--;
  if(time_left < 1)
    remove();

  if(random(100) < SPREAD_CHANCE)
    {
      int direction = (random(8))*2;
      int newx = x+spread_map[direction];
      int newy = y+spread_map[direction+1];
      object fire_obj;
      object new_room =
load_object(sprintf("/d/world/rooms/%d,%d.world",newx,newy));

      if(!new_room)
        {       
          GDEBUG("no new room found at " + newx + ","+newy);
          return;
        }
      // if its non burning, let's not spread
      
      if(member_array(new_room->query_outside(), BURNING) == -1)
        return;

      if(present("/d/world/fireobj", new_room))
         return;

      // frozen rooms do not burn
      if(new_room->query_frozen())
        return;

      // doesn't go to rooms with water either
      if(new_room->query_water())
        return;

      fire_obj = new("/d/world/fireobj");
     
fire_obj->move(find_object(sprintf("/d/world/rooms/%d,%d.world",newx,newy)));
      fire_obj->start();


    }

  call_out("call_out_cycle", CALL_OUT_LENGTH);
}