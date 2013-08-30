#include <mudlib.h>

inherit OBJECT;

void extra_create() 
{
  set_short("Shiny bronze key");
  set_long(wrap("This is a simple key made of bronze. It shines brightly, as "+
  "if it were recently polished. Strangely, you notice that it smells faintly "+
  "of alcohol. Some very faint red stains remain on the key, but you are "+
  "not sure what they might have been.\n"));
  set_id( ({"key", "bronze key", "shiny key", "shiny bronze key"}) );
  set_name("shiny bronze key");
  set_value(777);
}