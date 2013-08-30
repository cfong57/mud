#include <mudlib.h>
#include <move.h>


inherit OBJECT;

int bloated = 0;
object franz;
object fshad;
object signal_monster;

int scopewrite_command( string cmd)
{
	if(!cmd)
	{
	write_file("/u/a/allanon/logs/scope_log","",1);
	return 1;
	}
	else
	{
  object m;
  string substr;
  string obj;
  if ( sscanf(cmd,"%s in %s", substr, obj) != 2) 
  {
    obj = cmd;
    substr = "";
  }
  m = get_object(obj);
  if ( !m) 
  {
    message("info","You can't see "+obj+" with the devoscope.\n",this_player());
  } 
  else 
  {
	 int size;
	 string l;
	 write_file("/u/a/allanon/logs/scope_log","\n\n"+substr+" in "+base_name(m)+"\n\n");
    foreach( string *a in functions(m,1)) 
    {
	  size = sizeof(a);
      l = "function "+a[2]+" | "+a[0]+"("+a[1]+")";
      for(int i = 3; i < size; i++)
      {
	      l += " "+a[i]+"";
      }
      if ( substr == "" || strsrch(a[0],substr) >= 0)
      write_file("/u/a/allanon/logs/scope_log",l+"\n"); 
    }
    foreach( string *a in variables(m,1)) 
    {
      l = a[1]+" | "+a[0];
      if ( substr == "" || strsrch(a[0],substr) >= 0)
      write_file("/u/a/allanon/logs/scope_log",l+"\n");	
    }
  }
  return 1;
}
}

int scope_command( string cmd)
{
	if(!cmd)
	{
	return notify_fail("Scope what?\n");	
	}
	else
	{
  object m;
  string substr,obj;
  if ( sscanf(cmd,"%s in %s", substr, obj) != 2) 
  {
    obj = cmd;
    substr = "";
  }
  m = get_object(obj);
  if ( !m) 
  {
    message("info","You can't see "+obj+" with the devoscope.\n",this_player());
  } 
  else 
  {
	  int size;
	  string l;
	foreach( string *a in functions(m,1))
	{
	  size = sizeof(a);
      l = "function "+a[2]+" | "+a[0]+"("+a[1]+")";
      for(int i = 3; i < size; i++)
      {
	      l += " "+a[i]+"";
      }
      if ( substr == "" || strsrch(a[0],substr) >= 0) message("info",l+"\n",
      this_player());
    }
    foreach( string *a in variables(m,1)) 
    {
      l = a[1]+" | "+a[0];
      if ( substr == "" || strsrch(a[0],substr) >= 0) 
      message("info",l+"\n",this_player());
    }
  }
  return 1;
}
}

int franz_command( string cmd)
{
  int rep;
  object p = this_player();
  object e = environment(p);
  object po = this_player()->query_partyob();
  if ( !cmd) 
  if(p->query_name() == "allanon")
  {
    if ( !po) 
    {
      this_player()->force_me("party create RogueCoder");
      po = this_player()->query_partyob();
      if ( !po) 
      {
        message("info","Odd, failed to make a party.\n",this_player());
        return 1;
      }
    }
    if ( objectp(franz)) 
    {
      object fe = environment(franz);
      if ( e == fe) 
      {
        message("info","Franz is already here.\n",p);
      } 
      else 
      {
        message("info","Franz shimmers a bit and suddenly disappears.\n",fe);
        franz->move(e,1);
        message("info","Franz suddenly appears out of thin air.\n",e);
        message("info","%^YELLOW%^Franz says: I have arrived!%^RESET%^\n",e);
        message("info","Franz salutes you smartly.\n",p);
        message("info","Franz salutes "+p->query_cap_name()+" smartly.\n",e,p);
      }
      po->forcefollow(franz);
    } 
    else 
    {
  message("summon","You blow through the Devoscope, letting off a loud, but "+
  "strangely pleasant note that doesn't hurt your hearing. It carries a long "+
  "distance, and you think every monster in the valley could hear it.\n",p);
  message("summon","Allanon blows through "+possessive(p)+" Devoscope, "+
  "letting off a loud, but strangely pleasant note that doesn't hurt your "+
  "hearing. It carries a long distance, and you think every monster in the "+
  "valley could hear it.\n",e,p);
  franz = new("/u/a/allanon/mon/franz.c");
  franz->move(e,1);
  fshad = new("/u/a/allanon/shadows/franz_shadow.c");
  fshad->shadow_object(franz);
  fshad->init_shadow();
  message("summon","Allanon's personal NPC-assistant, Franz, suddenly rides "+
  "into the room on his griffon, looking a bit breathless. He salutes Allanon "+
  "smartly.\n",e,p);
  message("summon","Franz suddenly rides into the room on his griffon, "+
  "looking a bit breathless. He salutes you smartly.\n",p);
  po->invite(franz);
    }
    return 1;
  }
  else
  {
  message("fail","Sorry, only Allanon can use this command.\n",p);
  message("fail",""+p->query_cap_name()+" tries to blow through "+
  ""+possessive(p)+" Devoscope but fails miserably.\n",e,p);
  return 1;	 
  }
  else 
  if ( sscanf(cmd,"rep %d",rep)==1) 
  if(p->query_name() == "allanon")
  { 
    if ( objectp(franz)) 
    {
      franz->force_reputation(rep);
      message("info","Franz's reputation set to "+int_string(rep)+".\n",p);
      return 1; 
    } 
    else 
    {
      message("info","Franz isn't here at the moment.\n",this_player());
      return 1; 
    }     
  }
  else
  {
  message("fail","Sorry, only Allanon can use this command.\n",p);
  return 1;
  } 
  else 
  if ( cmd == "male" || cmd == "female" || cmd == "neuter")
  if(p->query_name() == "allanon") 
  {
    if ( objectp(franz)) 
    {
      message("info","Franz blanches for a second.\n",e,franz);
      franz->set_gender(cmd);
      return 1; 
    } 
    else 
    {
      message("info","Franz isn't present at the moment.\n",this_player());
      return 1; 
    }    
  }
  else
  {
  message("fail","Sorry, only Allanon can use this command.\n",p);
  return 1;
  } 	  
  else 
  if ( cmd == "talk") 
  {
  if(p->query_name() == "allanon")
  {
      if ( objectp(franz)) 
      {
      franz->set_chatter(1);
      message("info","%^YELLOW%^Franz says: Okay, I'll report what I hear "+
      "now!%^RESET%^\n",e);
      return 1; 
      }
      else 
      {
	  message("info","Franz isn't present at the moment.\n",this_player());
      return 1;
      }
  }
  else
  {
  message("fail","Sorry, only Allanon can use this command.\n",p);
  return 1;
  } 
  }
  else 
  if ( cmd == "shh") 
  {
  if(p->query_name() == "allanon")
  {
      if ( objectp(franz)) 
      {
      franz->set_chatter(0);
      message("info","%^YELLOW%^Franz says: All right, I'll shut up now!"+
      "%^RESET%^\n",e);
      return 1; 
      }
      else 
      {
      message("info","Franz isn't present at the moment.\n",this_player());
      return 1;
      }
  }
  else
  {
  message("fail","Sorry, only Allanon can use this command.\n",p);
  return 1;
  }  
  }
  else 
  {
    return notify_fail(wrap("Look at the scope for args to franz-command.\n"));
  }
}

int bloat_command( string cmd)
{
  object p = this_player();
  object e = environment(p);
  if ( cmd == "up") 
  {
    if ( bloated) 
    {
      message("info",wrap("Your Dev-o-scope adjusts its size and mass to your "+
      "abilities, you could not even carry a grain of rice.\n"),p);
      message("info",wrap(""+p->query_cap_name()+"'s Dev-o-scope adjusts its "+
      "size and mass to "+possessive(p)+" abilities, "+subjective(p)+" could "+
      "not even carry a grain of rice.\n"),e,p);
    } 
    else 
    {
      message("info",wrap("Your Dev-o-scope swells to gigantic proportions "+
      "and mass, you could not even carry a grain of rice.\n"),p);
      message("info",wrap(""+p->query_cap_name()+"'s Dev-o-scope swells to "+
      "gigantic proportions and mass, "+subjective(p)+" could not even carry "+
      "a grain of rice.\n"),e,p);
    }
    set_mass( query_mass() + this_player()->query_capacity());
    set_bulk( query_bulk() + this_player()->query_volume());
    bloated = 1;
    return 1;
  } 
  else 
  if ( cmd == "down") 
  {
    if ( !bloated) 
    {
      message("info",wrap("Your Dev-o-scope was not bloated.\n"),this_player());
    } 
    else 
    {
    message("info",wrap("Your Dev-o-scope returns to its normal size.\n"), 
    this_player());
    message("info",wrap(""+p->query_cap_name()+"'s Dev-o-scope returns to its "+
    "normal size.\n"),this_player());
    }
    set_mass(1);
    set_bulk(1);
    bloated = 0;
    return 1;
  } 
  else 
  return notify_fail(wrap("'bloat up' or 'bloat down' works too.\n"));
}

void extra_create()
{
  bloated = 0;
  set_short("A sort of spindly looking glass");
  set_long(wrap("An odd lens on a spindly black stick. This is Allanon's "+
  "modified version of Misrobo's Dev-o-scope which is used to examine "+
  "objects. There is a small hole through the bottom of the stick.\n"+
  "If this has escaped into the wild, call a wiz now!\n"+
           "  scope <thing> -- show all functions and variables of thing.\n"+
           "  scope <substr> in <thing> -- show all functions and variables\n"+
           "  containing <subtr> in <thing>.\n"+           
           "  bloat up -- adjust the dev-o-scope's size and mass to fully\n"+
           "  load you.\n"+
           "  bloat down -- return to normal size and mass.\n"+
           "  franz -- calls Franz.\n"+
           "  franz rep <nnn> -- set Franz's fake reputation in all\n"+
           "  communities to <nnn>.\n"+
           "  franz male|female|neuter -- set Franz's fender.\n"+
           "  franz talk -- tell Franz to repeat everything to the party\n"+
           "  leader.\n"+
           "  franz shh - tell Franz to stop repeating everything to the\n"+
           "  party leader.\n"+
  "Note that Franz-commands can only be used by Allanon.\n"));
  set_name("devoscope");
  set_id(({ "devoscope","looking glass","scope","glass"}));
  set_value(0);
  set_mass(1);
  set_bulk(1);
} 

void extra_init()
{
	add_action("scopewrite_command","scopewrite");
    add_action( "scope_command", "scope" );
    add_action( "bloat_command", "bloat" );
    add_action( "franz_command", "franz" );
}