#include <mudlib.h>

inherit SHADOW;

int init_shadow() 
{ 
 call_out("check_status",5);
} 

int check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 
  call_out("check_status",5);
}

int remove_this_shadow()
{
	destruct(this_object()); 
}   		

mixed query_long() 
{ 
return wrap("Franz is a young-looking knight. "+
""+capitalize(subjective(this_object()))+" seems to be quite "+
"confident of "+possessive(this_object())+" skills, despite "+
""+possessive(this_object())+" young age. You take special note of "+
""+possessive(this_object())+" equipment, which is top-notch and in superb "+
"condition. Seems like "+subjective(this_object())+" takes "+
""+possessive(this_object())+" duties seriously. Franz's calm demeanor and "+
"easy smile puts you totally at ease with "+objective(this_object())+". "+
""+capitalize(subjective(this_object()))+" is riding a griffon.\n"); 
} 