#include <mudlib.h>

inherit OBJECT;

int query_not_saveable() 
{ 
  return 1; 
}

void extra_create() 
{
  set_short("A rotten key, covered in mold");
  set_long(wrap("The key might have been bronze once, but it is now covered "+
  "in a thick blanket of slimy yet fuzzy mold. Where the mold hasn't grown, "+
  "you spot some serious tarnish in the form of bloodstains. You feel "+
  "revulsion just touching the key, much less thinking about where it came "+
  "from. At the very least, this key is unusable in its current state, and "+
  "you would not be surprised if it simply fell apart without notice.\n"));
  set_id( ({"rotten key covered in mold", "rotten key", "key"}) );
  set_name("rotten key covered in mold");
  set_value(1);
}