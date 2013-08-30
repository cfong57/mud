// "player1" : ([start of membership : duration of membership]), "player2" ...
mapping members = ([]);

string query_list() //for debug
{
  return identify(members);	
}

void add_member(string who)
{
  members[who] = ([time() : 0]);
}

void remove_member(string who)
{
  map_delete(members, who);
}

void increase_membership(string who, int amount)
{
  members[who][1] += amount;
}

int query_is_member(string who)
{
  if(member_array(who, keys(members)))
  {
	return 1;
  }
  else
  {
    return 0;	  
  }
}

int query_membership_duration(string who)
{
  return members[who][1];
}

string * check_memberships()
{
  string *removed = ({});
  int temp = time();
  foreach(string who in keys(members))
  {
    if(temp - members[who][0] > members[who][1])
    {
	  removed += ({who});
      remove_member(who);
    }
  }
  return removed;
}

void delete_all_memberships()
{
  members = ([]);	
}