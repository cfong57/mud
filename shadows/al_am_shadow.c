#include <mudlib.h>

inherit SHADOW;

mixed *hilites = ({"%^BOLD%^BLACK%^", "%^RED%^", "%^BOLD%^RED%^", "%^GREEN%^", 
"%^BOLD%^GREEN%^", "%^ORANGE%^", "%^YELLOW%^", "%^BLUE%^", "%^BOLD%^BLUE%^", 
"%^CYAN%^", "%^BOLD%^CYAN%^", "%^MAGENTA%^", "%^BOLD%^MAGENTA%^", "%^WHITE%^",
"%^BOLD%^WHITE%^"});  
string r = "%^RESET%^";
string lite;

int init_shadow() 
{ 
 call_out("check_status",5);
 call_out("define_func",1);
 call_out("name_changer",5);
} 

int check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 
  call_out("check_status",5);
}

int remove_shadow_1()
{
	destruct(this_object()); 
}

int define_func()
{
shadowed_object()->set_short(
""+hilites[random(sizeof(hilites))]+"A"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"o"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"i"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+" "+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"m"+r+""+
""+hilites[random(sizeof(hilites))]+"u"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"e"+r+""+
""+hilites[random(sizeof(hilites))]+"t"+r+"");    
shadowed_object()->set_name(
""+hilites[random(sizeof(hilites))]+"A"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"o"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"i"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+" "+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"m"+r+""+
""+hilites[random(sizeof(hilites))]+"u"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"e"+r+""+
""+hilites[random(sizeof(hilites))]+"t"+r+"");    		
}

int name_changer()
{
shadowed_object()->set_name(shadowed_object()->query_short());
}

string query_short(int flag) 
{ 
if(flag) 
return shadowed_object()->query_short(flag); 
else
call_out("define_func",0);
return ""+hilites[random(sizeof(hilites))]+"A"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"o"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+""+
""+hilites[random(sizeof(hilites))]+"i"+r+""+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"n"+r+" "+
""+hilites[random(sizeof(hilites))]+"a"+r+""+
""+hilites[random(sizeof(hilites))]+"m"+r+""+
""+hilites[random(sizeof(hilites))]+"u"+r+""+
""+hilites[random(sizeof(hilites))]+"l"+r+""+
""+hilites[random(sizeof(hilites))]+"e"+r+""+
""+hilites[random(sizeof(hilites))]+"t"+r+"";
call_out("name_changer",0);
} 