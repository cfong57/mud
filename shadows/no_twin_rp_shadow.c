#include <mudlib.h>

inherit SHADOW;

string h1;
string h2;
string h3;
string h4;
string h5;
string h6;
string h7;
string h8;
string h9;
string h10;
string h11;
string h12;
string h13;
string r;

int init_shadow()
{
 call_out("check_status",5);
 call_out("define_func",5);	
}

int check_status()
{
  if(!shadowed_object()) 
  destruct(this_object()); 
  call_out("check_status",5);
}

int remove_shadow_func()
{
	remove_call_out("check_status");
	destruct(this_object()); 
}

int define_func()
{
	r = "%^RESET%^";
	switch(random(15))
	{
	case 0:
	h1 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h1 = "%^RED%^";
	break;
	case 2:
	h1 = "%^BOLD%^RED%^";
	break;
	case 3:
	h1 = "%^GREEN%^";
	break;
	case 4:
	h1 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h1 = "%^ORANGE%^";
	break;
	case 6:
	h1 = "%^YELLOW%^";
	break;
	case 7:
	h1 = "%^BLUE%^";
	break;
	case 8:
	h1 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h1 = "%^CYAN%^";
	break;
	case 10:
	h1 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h1 = "%^MAGENTA%^";
	break;
	case 12:
	h1 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h1 = "%^WHITE%^";
	break;
	case 14:
	h1 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h2 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h2 = "%^RED%^";
	break;
	case 2:
	h2 = "%^BOLD%^RED%^";
	break;
	case 3:
	h2 = "%^GREEN%^";
	break;
	case 4:
	h2 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h2 = "%^ORANGE%^";
	break;
	case 6:
	h2 = "%^YELLOW%^";
	break;
	case 7:
	h2 = "%^BLUE%^";
	break;
	case 8:
	h2 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h2 = "%^CYAN%^";
	break;
	case 10:
	h2 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h2 = "%^MAGENTA%^";
	break;
	case 12:
	h2 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h2 = "%^WHITE%^";
	break;
	case 14:
	h2 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h3 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h3 = "%^RED%^";
	break;
	case 2:
	h3 = "%^BOLD%^RED%^";
	break;
	case 3:
	h3 = "%^GREEN%^";
	break;
	case 4:
	h3 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h3 = "%^ORANGE%^";
	break;
	case 6:
	h3 = "%^YELLOW%^";
	break;
	case 7:
	h3 = "%^BLUE%^";
	break;
	case 8:
	h3 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h3 = "%^CYAN%^";
	break;
	case 10:
	h3 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h3 = "%^MAGENTA%^";
	break;
	case 12:
	h3 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h3 = "%^WHITE%^";
	break;
	case 14:
	h3 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h4 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h4 = "%^RED%^";
	break;
	case 2:
	h4 = "%^BOLD%^RED%^";
	break;
	case 3:
	h4 = "%^GREEN%^";
	break;
	case 4:
	h4 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h4 = "%^ORANGE%^";
	break;
	case 6:
	h4 = "%^YELLOW%^";
	break;
	case 7:
	h4 = "%^BLUE%^";
	break;
	case 8:
	h4 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h4 = "%^CYAN%^";
	break;
	case 10:
	h4 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h4 = "%^MAGENTA%^";
	break;
	case 12:
	h4 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h4 = "%^WHITE%^";
	break;
	case 14:
	h4 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h5 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h5 = "%^RED%^";
	break;
	case 2:
	h5 = "%^BOLD%^RED%^";
	break;
	case 3:
	h5 = "%^GREEN%^";
	break;
	case 4:
	h5 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h5 = "%^ORANGE%^";
	break;
	case 6:
	h5 = "%^YELLOW%^";
	break;
	case 7:
	h5 = "%^BLUE%^";
	break;
	case 8:
	h5 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h5 = "%^CYAN%^";
	break;
	case 10:
	h5 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h5 = "%^MAGENTA%^";
	break;
	case 12:
	h5 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h5 = "%^WHITE%^";
	break;
	case 14:
	h5 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h6 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h6 = "%^RED%^";
	break;
	case 2:
	h6 = "%^BOLD%^RED%^";
	break;
	case 3:
	h6 = "%^GREEN%^";
	break;
	case 4:
	h6 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h6 = "%^ORANGE%^";
	break;
	case 6:
	h6 = "%^YELLOW%^";
	break;
	case 7:
	h6 = "%^BLUE%^";
	break;
	case 8:
	h6 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h6 = "%^CYAN%^";
	break;
	case 10:
	h6 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h6 = "%^MAGENTA%^";
	break;
	case 12:
	h6 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h6 = "%^WHITE%^";
	break;
	case 14:
	h6 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h7 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h7 = "%^RED%^";
	break;
	case 2:
	h7 = "%^BOLD%^RED%^";
	break;
	case 3:
	h7 = "%^GREEN%^";
	break;
	case 4:
	h7 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h7 = "%^ORANGE%^";
	break;
	case 6:
	h7 = "%^YELLOW%^";
	break;
	case 7:
	h7 = "%^BLUE%^";
	break;
	case 8:
	h7 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h7 = "%^CYAN%^";
	break;
	case 10:
	h7 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h7 = "%^MAGENTA%^";
	break;
	case 12:
	h7 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h7 = "%^WHITE%^";
	break;
	case 14:
	h7 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h8 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h8 = "%^RED%^";
	break;
	case 2:
	h8 = "%^BOLD%^RED%^";
	break;
	case 3:
	h8 = "%^GREEN%^";
	break;
	case 4:
	h8 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h8 = "%^ORANGE%^";
	break;
	case 6:
	h8 = "%^YELLOW%^";
	break;
	case 7:
	h8 = "%^BLUE%^";
	break;
	case 8:
	h8 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h8 = "%^CYAN%^";
	break;
	case 10:
	h8 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h8 = "%^MAGENTA%^";
	break;
	case 12:
	h8 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h8 = "%^WHITE%^";
	break;
	case 14:
	h8 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h9 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h9 = "%^RED%^";
	break;
	case 2:
	h9 = "%^BOLD%^RED%^";
	break;
	case 3:
	h9 = "%^GREEN%^";
	break;
	case 4:
	h9 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h9 = "%^ORANGE%^";
	break;
	case 6:
	h9 = "%^YELLOW%^";
	break;
	case 7:
	h9 = "%^BLUE%^";
	break;
	case 8:
	h9 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h9 = "%^CYAN%^";
	break;
	case 10:
	h9 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h9 = "%^MAGENTA%^";
	break;
	case 12:
	h9 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h9 = "%^WHITE%^";
	break;
	case 14:
	h9 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h10 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h10 = "%^RED%^";
	break;
	case 2:
	h10 = "%^BOLD%^RED%^";
	break;
	case 3:
	h10 = "%^GREEN%^";
	break;
	case 4:
	h10 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h10 = "%^ORANGE%^";
	break;
	case 6:
	h10 = "%^YELLOW%^";
	break;
	case 7:
	h10 = "%^BLUE%^";
	break;
	case 8:
	h10 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h10 = "%^CYAN%^";
	break;
	case 10:
	h10 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h10 = "%^MAGENTA%^";
	break;
	case 12:
	h10 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h10 = "%^WHITE%^";
	break;
	case 14:
	h10 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h11 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h11 = "%^RED%^";
	break;
	case 2:
	h11 = "%^BOLD%^RED%^";
	break;
	case 3:
	h11 = "%^GREEN%^";
	break;
	case 4:
	h11 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h11 = "%^ORANGE%^";
	break;
	case 6:
	h11 = "%^YELLOW%^";
	break;
	case 7:
	h11 = "%^BLUE%^";
	break;
	case 8:
	h11 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h11 = "%^CYAN%^";
	break;
	case 10:
	h11 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h11 = "%^MAGENTA%^";
	break;
	case 12:
	h11 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h11 = "%^WHITE%^";
	break;
	case 14:
	h11 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h12 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h12 = "%^RED%^";
	break;
	case 2:
	h12 = "%^BOLD%^RED%^";
	break;
	case 3:
	h12 = "%^GREEN%^";
	break;
	case 4:
	h12 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h12 = "%^ORANGE%^";
	break;
	case 6:
	h12 = "%^YELLOW%^";
	break;
	case 7:
	h12 = "%^BLUE%^";
	break;
	case 8:
	h12 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h12 = "%^CYAN%^";
	break;
	case 10:
	h12 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h12 = "%^MAGENTA%^";
	break;
	case 12:
	h12 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h12 = "%^WHITE%^";
	break;
	case 14:
	h12 = "%^BOLD%^WHITE%^";
	break;
    }
    switch(random(15))
	{
	case 0:
	h13 = "%^BOLD%^BLACK%^";
	break;
	case 1:
	h13 = "%^RED%^";
	break;
	case 2:
	h13 = "%^BOLD%^RED%^";
	break;
	case 3:
	h13 = "%^GREEN%^";
	break;
	case 4:
	h13 = "%^BOLD%^GREEN%^";
	break;
	case 5:
	h13 = "%^ORANGE%^";
	break;
	case 6:
	h13 = "%^YELLOW%^";
	break;
	case 7:
	h13 = "%^BLUE%^";
	break;
	case 8:
	h13 = "%^BOLD%^BLUE%^";
	break;
	case 9:
	h13 = "%^CYAN%^";
	break;
	case 10:
	h13 = "%^BOLD%^CYAN%^";
	break;
	case 11:
	h13 = "%^MAGENTA%^";
	break;
	case 12:
	h13 = "%^BOLD%^MAGENTA%^";
	break;
	case 13:
	h13 = "%^WHITE%^";
	break;
	case 14:
	h13 = "%^BOLD%^WHITE%^";
	break;
    }
shadowed_object()->set_short("Sacred blade 'NoTwinRP' <"+
""+h1+"c"+r+""+h2+"h"+r+""+h3+"r"+r+""+h4+"o"+r+""+
""+h5+"m"+r+""+h6+"a"+r+""+h7+"t"+r+""+h8+"i"+r+""+h9+"c"+r+" "+h10+"g"+r+""+   
""+h11+"l"+r+""+h12+"o"+r+""+h13+"w"+r+">"); 		
}

string query_short(int flag) 
{ 
if(flag) 
return shadowed_object()->query_short(flag); 
else
call_out("define_func",0);
return "Sacred blade 'NoTwinRP' <"+
""+h1+"c"+r+""+h2+"h"+r+""+h3+"r"+r+""+h4+"o"+r+""+
""+h5+"m"+r+""+h6+"a"+r+""+h7+"t"+r+""+h8+"i"+r+""+h9+"c"+r+" "+h10+"g"+r+""+   
""+h11+"l"+r+""+h12+"o"+r+""+h13+"w"+r+">";
} 