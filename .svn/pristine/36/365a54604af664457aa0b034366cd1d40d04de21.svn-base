#include <mudlib.h>

inherit OBJECT;

int unwrap_command(string cmd)
{
  if(this_object()->id(cmd))
  {
	object meat;
    message("info","You unwrap your hunk of meat and throw the packaging "+
    "away.\n",this_player());
    message("info",""+this_player()->query_cap_name()+" unwraps a hunk of "+
    "meat and throws the packaging away.\n",environment(this_player()),
    this_player());
    meat = new("/obj/food/raw_meat.c");
    meat->move(this_player(), 1);
    remove();
    return 1;
  }
  return notify_fail("Unwrap what?\n");
}

void extra_init()
{
  add_action("unwrap_command", "unwrap");
}

void extra_create() 
{
  set_short("Paper-wrapped hunk of meat");
  set_long(wrap("This is a hunk of meat wrapped in thick paper and tied with "+
  "twine. Although the paper is quite absorbent, it is still somewhat bloody, "+
  "so you know the meat is fresh. You could 'unwrap' it any time you felt "+
  "like eating.\n"));
  set_id(({"paper-wrapped hunk of meat", "hunk", "hunk of meat", "meat"}));
  set_name("paper-wrapped hunk of meat");
  set_value(250);
  set_mass(200);
  set_bulk(500);
}