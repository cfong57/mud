#include <mudlib.h>

inherit OBJECT;

void write_msg(string v);
void write_me(string v);
string msg;

int write_command(string cmd) 
{        
  if (!cmd) { 
    object p = this_player();
    message("info", "You set the paper on a flat surface and prepare to "+
    "write...\n", p);
    message("info", ""+p->query_cap_name()+" sets "+possessive(p)+" paper on "+
    "a flat surface and prepare to write...\n", environment(p), p);
    call_out("write_me", 0);
    return 1;
  }  
}
  
void write_msg(string v)
{
  object p = this_player(); 
  if (!(v == "yes" || v == "y" || v == "Yes")) {
    write_me("");
    return;
  }  
  message("info", "You scribble your message to the sheet of paper, using "+
  "your own blood as an ink.\n", p);
  message("info", ""+p->query_cap_name()+" scribbles something to "+
  ""+possessive(p)+" sheet of paper.\n", environment(p), p);
  this_object()->set_long(wrap(""+this_object()->query_long()+""+msg+"\n"));
  p->set_hp(p->query_hp() - sizeof(msg));
  return;
}

void write_me(string v)
{
  object p = this_player();
  if (!sizeof(v)) {
    message("info", "Imput your message: \n", p);
    input_to("write_me");
    return;
  }
  msg = v;
  message("info", "Are you sure that is what you want to write? [y,n]\n", p);
  input_to("write_msg");
}

void extra_init() 
{ 
    add_action("write_command", "write");
} 

void extra_create()
{
  set_short("White sheet of paper");
  set_long(wrap("It's a sheet of plain white paper that you could 'write' on. "+
  "There is a small crimson rune in the corner that resembles a dagger. You "+
  "recognize it immediately as a 'Rune of Retribution': this item exacts a "+
  "price on its user. This paper can only be written on with the blood of the "+
  "writer, so you'd better not make any mistakes...\n"+
  "The following has been written to the paper:\n\n"));
  set_id( ({ "white sheet of paper", "sheet of paper", "paper", "sheet"}) );
  set_mass(1);
  set_bulk(1);
  set_value(0);
}

string query_message()
{
  return msg;	
}