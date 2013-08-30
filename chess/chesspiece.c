#pragma save_types

#include <mudlib.h>

#define R "%^BOLD%^%^RED%^R%^RESET%^" //enemy rook
#define N "%^BOLD%^%^RED%^N%^RESET%^" //enemy knight
#define B "%^BOLD%^%^RED%^B%^RESET%^" //enemy bishop
#define Q "%^BOLD%^%^RED%^Q%^RESET%^" //enemy queen
#define K "%^BOLD%^%^RED%^K%^RESET%^" //enemy king
#define P "%^BOLD%^%^RED%^P%^RESET%^" //enemy pawn
#define T "%^BOLD%^%^RED%^ %^RESET%^" //square the enemy is threatening
#define r "%^BOLD%^%^MAGENTA%^r%^RESET%^" //player rook
#define n "%^BOLD%^%^MAGENTA%^n%^RESET%^" //player knight
#define b "%^BOLD%^%^MAGENTA%^b%^RESET%^" //player bishop
#define q "%^BOLD%^%^MAGENTA%^q%^RESET%^" //player queen
#define k "%^BOLD%^%^MAGENTA%^k%^RESET%^" //player king
#define p "%^BOLD%^%^MAGENTA%^p%^RESET%^" //player pawn
#define t "%^BOLD%^%^MAGENTA%^ %^RESET%^" //square the player is threatening
#define z "%^BOLD%^%^YELLOW%^ %^RESET%^" //square both players are threatening

inherit OBJECT;

string type = "blank";
string color = "blank";
string temp1 = ""; //for sscanf
string temp2 = ""; //for sscanf
int has_moved = 0; //for castling, pawn's initial charge
string chess_id; //unique chesspiece id code

set_chess_id(string str)
{
  chess_id = str;	
}

string query_chess_id()
{
  return chess_id;
}

void set_type(string str)
{
  type = str;	
}

string query_type()
{
  return type;	
}

void set_color(string str)
{
  color = str;
}

string query_color()
{
  return color;	
}

void set_has_moved(int i)
{
  has_moved = i;	
}

int query_has_moved()
{
  return has_moved;	
}

varargs void initialize(string str, int i, int j)
{ 
  if(i && j)
  {
    set_chess_id(""+i+" "+j+"");	  
  }
  sscanf(str,"%s %s",temp1,temp2);
  switch(temp1)
  {
    case "red":
	set_color("red");
	break;
	case "magenta":
	set_color("magenta");
	break;
	case "both":
	set_color("both");
	break;
	case "blank":
	set_color("blank");
	break;
	default:
    message("error","Error: invalid color to initialize(). "+
    "Attempted "+temp1+".\n",this_player());
    break;
  }
  switch(temp2)
  {
    case "pawn":
    set_type("pawn");
    break;
    case "rook":
    set_type("rook");
    break;
    case "knight":
    set_type("knight");
    break;
    case "bishop": 
    set_type("bishop");
    break;
    case "queen":
    set_type("queen");
    break;
    case "king":
    set_type("king");
    break;
    case "threat":
    set_type("threat");
    break;
    case "blank":
    set_type("blank");
    break;
    default:
    message("error","Error: invalid piece type to initialize(). Attempted "+
    ""+temp2+".\n",this_player());
    break;
  }	
}

void promote_me(string str)
{
  if(query_type() != "pawn")
  {
    message("error","Error: promote_me() was called on a non-pawn piece. Type "+
    "was "+query_type()+".\n",this_player());	  
  }
  else
  {
    switch(str)
    {
      case "rook":
      initialize(""+query_color()+" rook");
      break;
      case "knight":
      initialize(""+query_color()+" knight");
      break;
      case "bishop": 
      initialize(""+query_color()+" bishop");
      break;
      case "queen":
      initialize(""+query_color()+" queen");
      break;
      default:
      message("error","Error: bad piece type to promote_me(). Tried "+
      ""+str+".\n",this_player());
      break;  
    }
  }
}

string query_view()
{
  string temp = ""+query_color()+" "+query_type()+"";
  string returnme = "";
  switch(temp)
  {
    case "red rook":
    returnme = R;
    break;
    case "red knight":
    returnme = N;
    break;
    case "red bishop":
    returnme = B;
    break;
    case "red queen":
    returnme = Q;
    break;
    case "red king":
    returnme = K;
    break;
    case "red pawn":
    returnme = P;
    break;
    case "red threat":
    returnme = T;
    break;
    case "magenta rook":
    returnme = r;
    break;
    case "magenta knight":
    returnme = n;
    break;
    case "magenta bishop":
    returnme = b;
    break;
    case "magenta queen":
    returnme = q;
    break;
    case "magenta king":
    returnme = k;
    break;
    case "magenta pawn":
    returnme = p;
    break;
    case "magenta threat":
    returnme = t;
    break;
    case "both threat":
    returnme = z;
    break;
    case "blank blank":
    returnme = " ";
    break;
    default:
    message("chess","Error: bad args to query_view(). Attempted "+
    ""+query_color()+" "+query_type()+".\n",this_player());
    break;
  }
  return returnme;
}

void extra_create()
{
  set_short("A chess piece");
  set_long(wrap("This desc should not be seeable.\n"));
  set_id(({"piece", "chess piece", "a chess piece"}));
}