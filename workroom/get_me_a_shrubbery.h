//get_me_a_shrubbery.h

varargs mixed * get_me_all_the_shrubberies(string shrubbery, object container)
{
  mixed *shrubs = ({ });
  if(container)
  {
	foreach(object ob in all_inventory(container)) 
	{
      if(base_name(ob) == replace_string(shrubbery, ".c", "") ||
      ob->id(shrubbery) || ob->query_short() == shrubbery) 
      {
        shrubs += ({ ob });
      } 
    }
  }
  else
  {
    foreach(object ob in all_inventory(this_object())) 
	{
      if(base_name(ob) == replace_string(shrubbery, ".c", "") ||
      ob->id(shrubbery) || ob->query_short() == shrubbery) 
      {
        shrubs += ({ ob });
      }   
    }	  
  }
  return shrubs;
}

varargs object get_me_a_shrubbery(string shrubbery, object container)
{
  object shrub;
  if(container)
  {
    object *inventory = all_inventory(container);
    int max = sizeof(inventory);
    if(max)
    {
      int index = 0;
      for(int quit = 0; quit == 0; index++)
      {
        if(index < max)
        {
          if(base_name(inventory[index]) == 
          replace_string(shrubbery, ".c", "") ||
          inventory[index]->id(shrubbery) ||
          inventory[index]->query_short() == shrubbery)
          {         
            quit++;
            shrub = inventory[index];
          }
        }
        else
        {
          quit++;
        }
      }
    }
  }
  else
  {
    object *inventory = all_inventory(this_object());
    int max = sizeof(inventory);
    if(max)
    {
      int index = 0;
      for(int quit = 0; quit == 0; index++)
      {
        if(index < max)
        {
          if(base_name(inventory[index]) == 
          replace_string(shrubbery, ".c", "") ||
          inventory[index]->id(shrubbery) ||
          inventory[index]->query_short() == shrubbery)
          {         
            quit++;
            shrub = inventory[index];
          }
        }
        else
        {
          quit++;
        }
      }
    }	  
  }
  return shrub;
}

varargs int query_shrub(string target, object thing)
{
  if(thing)
  {
	object foo;
    foo = get_me_a_shrubbery(target, thing);
    if(foo)
    {
	  return 1;
    }
  }
  else
  {
    object foo;
    foo = get_me_a_shrubbery(target, this_object());
    if(foo)
    {
	  return 1;
    }
  }
  return 0;
}