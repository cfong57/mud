#pragma save_types
#include <mudlib.h>
//#include "chess.h"

inherit ROOM;

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

//OBJECT REFERENCES - 2D ARRAY
#define A1 CHESSBOARD[0][7]
#define B1 CHESSBOARD[1][7]
#define C1 CHESSBOARD[2][7]
#define D1 CHESSBOARD[3][7]
#define E1 CHESSBOARD[4][7]
#define F1 CHESSBOARD[5][7]
#define G1 CHESSBOARD[6][7]
#define H1 CHESSBOARD[7][7]
#define A2 CHESSBOARD[0][6]
#define B2 CHESSBOARD[1][6]
#define C2 CHESSBOARD[2][6]
#define D2 CHESSBOARD[3][6]
#define E2 CHESSBOARD[4][6]
#define F2 CHESSBOARD[5][6]
#define G2 CHESSBOARD[6][6]
#define H2 CHESSBOARD[7][6]
#define A3 CHESSBOARD[0][5]
#define B3 CHESSBOARD[1][5]
#define C3 CHESSBOARD[2][5]
#define D3 CHESSBOARD[3][5]
#define E3 CHESSBOARD[4][5]
#define F3 CHESSBOARD[5][5]
#define G3 CHESSBOARD[6][5]
#define H3 CHESSBOARD[7][5]
#define A4 CHESSBOARD[0][4]
#define B4 CHESSBOARD[1][4]
#define C4 CHESSBOARD[2][4]
#define D4 CHESSBOARD[3][4]
#define E4 CHESSBOARD[4][4]
#define F4 CHESSBOARD[5][4]
#define G4 CHESSBOARD[6][4]
#define H4 CHESSBOARD[7][4]
#define A5 CHESSBOARD[0][3]
#define B5 CHESSBOARD[1][3]
#define C5 CHESSBOARD[2][3]
#define D5 CHESSBOARD[3][3]
#define E5 CHESSBOARD[4][3]
#define F5 CHESSBOARD[5][3]
#define G5 CHESSBOARD[6][3]
#define H5 CHESSBOARD[7][3]
#define A6 CHESSBOARD[0][2]
#define B6 CHESSBOARD[1][2]
#define C6 CHESSBOARD[2][2]
#define D6 CHESSBOARD[3][2]
#define E6 CHESSBOARD[4][2]
#define F6 CHESSBOARD[5][2]
#define G6 CHESSBOARD[6][2]
#define H6 CHESSBOARD[7][2]
#define A7 CHESSBOARD[0][1]
#define B7 CHESSBOARD[1][1]
#define C7 CHESSBOARD[2][1]
#define D7 CHESSBOARD[3][1]
#define E7 CHESSBOARD[4][1]
#define F7 CHESSBOARD[5][1]
#define G7 CHESSBOARD[6][1]
#define H7 CHESSBOARD[7][1]
#define A8 CHESSBOARD[0][0]
#define B8 CHESSBOARD[1][0]
#define C8 CHESSBOARD[2][0]
#define D8 CHESSBOARD[3][0]
#define E8 CHESSBOARD[4][0]
#define F8 CHESSBOARD[5][0]
#define G8 CHESSBOARD[6][0]
#define H8 CHESSBOARD[7][0]

//STRING REFERENCES
#define a1 A1->query_view()
#define b1 B1->query_view()
#define c1 C1->query_view()
#define d1 D1->query_view()
#define e1 E1->query_view()
#define f1 F1->query_view()
#define g1 G1->query_view()
#define h1 H1->query_view()
#define a2 A2->query_view()
#define b2 B2->query_view()
#define c2 C2->query_view()
#define d2 D2->query_view()
#define e2 E2->query_view()
#define f2 F2->query_view()
#define g2 G2->query_view()
#define h2 H2->query_view()
#define a3 A3->query_view()
#define b3 B3->query_view()
#define c3 C3->query_view()
#define d3 D3->query_view()
#define e3 E3->query_view()
#define f3 F3->query_view()
#define g3 G3->query_view()
#define h3 H3->query_view()
#define a4 A4->query_view()
#define b4 B4->query_view()
#define c4 C4->query_view()
#define d4 D4->query_view()
#define e4 E4->query_view()
#define f4 F4->query_view()
#define g4 G4->query_view()
#define h4 H4->query_view()
#define a5 A5->query_view()
#define b5 B5->query_view()
#define c5 C5->query_view()
#define d5 D5->query_view()
#define e5 E5->query_view()
#define f5 F5->query_view()
#define g5 G5->query_view()
#define h5 H5->query_view()
#define a6 A6->query_view()
#define b6 B6->query_view()
#define c6 C6->query_view()
#define d6 D6->query_view()
#define e6 E6->query_view()
#define f6 F6->query_view()
#define g6 G6->query_view()
#define h6 H6->query_view()
#define a7 A7->query_view()
#define b7 B7->query_view()
#define c7 C7->query_view()
#define d7 D7->query_view()
#define e7 E7->query_view()
#define f7 F7->query_view()
#define g7 G7->query_view()
#define h7 H7->query_view()
#define a8 A8->query_view()
#define b8 B8->query_view()
#define c8 C8->query_view()
#define d8 D8->query_view()
#define e8 E8->query_view()
#define f8 F8->query_view()
#define g8 G8->query_view()
#define h8 H8->query_view()

#define LINE " |-+-+-+-+-+-+-+-|\n"
#define ROW8 "8|"+a8+"|"+b8+"|"+c8+"|"+d8+"|"+e8+"|"+f8+"|"+g8+"|"+h8+"|8\n"
#define ROW7 "7|"+a7+"|"+b7+"|"+c7+"|"+d7+"|"+e7+"|"+f7+"|"+g7+"|"+h7+"|7\n"
#define ROW6 "6|"+a6+"|"+b6+"|"+c6+"|"+d6+"|"+e6+"|"+f6+"|"+g6+"|"+h6+"|6\n"
#define ROW5 "5|"+a5+"|"+b5+"|"+c5+"|"+d5+"|"+e5+"|"+f5+"|"+g5+"|"+h5+"|5\n"
#define ROW4 "4|"+a4+"|"+b4+"|"+c4+"|"+d4+"|"+e4+"|"+f4+"|"+g4+"|"+h4+"|4\n"
#define ROW3 "3|"+a3+"|"+b3+"|"+c3+"|"+d3+"|"+e3+"|"+f3+"|"+g3+"|"+h3+"|3\n"
#define ROW2 "2|"+a2+"|"+b2+"|"+c2+"|"+d2+"|"+e2+"|"+f2+"|"+g2+"|"+h2+"|2\n"
#define ROW1 "1|"+a1+"|"+b1+"|"+c1+"|"+d1+"|"+e1+"|"+f1+"|"+g1+"|"+h1+"|1\n"

string theboard = "foo"; //placeholder for visual chessboard representation

//2D ARRAY: initialize the letters row (x, across)
mixed *CHESSBOARD = ({ 0, 0, 0, 0, 0, 0, 0, 0});

mapping STR_TO_OBJ = ([  //just to get mapping size to 64
"A8" : 0, "B8" : 0, "C8" : 0, "D8" : 0, "E8" : 0, "F8" : 0, "G8" : 0, "H8" : 0,
"A7" : 0, "B7" : 0, "C7" : 0, "D7" : 0, "E7" : 0, "F7" : 0, "G7" : 0, "H7" : 0,
"A6" : 0, "B6" : 0, "C6" : 0, "D6" : 0, "E6" : 0, "F6" : 0, "G6" : 0, "H6" : 0,
"A5" : 0, "B5" : 0, "C5" : 0, "D5" : 0, "E5" : 0, "F5" : 0, "G5" : 0, "H5" : 0,
"A4" : 0, "B4" : 0, "C4" : 0, "D4" : 0, "E4" : 0, "F4" : 0, "G4" : 0, "H4" : 0,
"A3" : 0, "B3" : 0, "C3" : 0, "D3" : 0, "E3" : 0, "F3" : 0, "G3" : 0, "H3" : 0,
"A2" : 0, "B2" : 0, "C2" : 0, "D2" : 0, "E2" : 0, "F2" : 0, "G2" : 0, "H2" : 0,
"A1" : 0, "B1" : 0, "C1" : 0, "D1" : 0, "E1" : 0, "F1" : 0, "G1" : 0, "H1" : 0
]);

object *players = ({}); //alternative to making a chess shadow
int game_in_progress = 0; //make sure we don't start two games at once
//value of 1 is used for a solo game

object *threat_array = ({}); //contains squares under threat from pieces
object current_player; //whose move it is, which player
string current_color; //whose move it is, red or magenta
string piece; //the piece to be moved - string reference
object opiece; //the piece to be moved - actual object
string destination; //where the piece is moving to - string reference
object odestination; //where the piece is moving to - actual object
int is_passant_possible = 0; //for capture en passant

int temp1; //for sscanf in move_pieces()
int temp2; //for sscanf in move_pieces()
int temp3; //for sscanf in move_pieces()
int temp4; //for sscanf in move_pieces()
int xdiff; //for move_pieces()
int ydiff; //for move_pieces()
int tempx; //for move_pieces()
int tempy; //for move_pieces()
string xdir; //for move_pieces()
string ydir; //for move_pieces()
string tempcolor; //for do_move()
string temptype; //for do_move()

int query_is_passant_possible()
{
  return is_passant_possible;	
}

void set_is_passant_possible(int i)
{
  is_passant_possible = i;	
}

void set_current_color(string str)
{
  current_color = str;	
}

string query_current_color()
{
  return current_color;	
}

void toggle_current_color()
{
  switch(query_current_color())
  {
    case "magenta":
    set_current_color("red");
    break;
    case "red":
    set_current_color("magenta");
    break;
    default:
    message("chess","Error: toggle_current_color() was called, but with "+
    ""+query_current_color()+".\n",this_player());
    break;
  }	
}

void set_current_player(object ob)
{
  current_player = ob;	
}

object query_current_player()
{
  return current_player;	
}

void clear_threat_array()
{
  threat_array = ({});	
}

void add_player(object obj)
{
  players += obj;	
}

void remove_player(object obj)
{
  players -= obj;
}

void clear_players()
{
  players = ({});	
}

object * query_players()
{
  return players;	
}

void set_game_in_progress(int i)
{
  game_in_progress = i;	
}

int query_game_in_progress()
{
  return game_in_progress;	
}

void create_chessboard()
{
  for(int i = 0; i < sizeof(CHESSBOARD); i++)
  {
    CHESSBOARD[i] = ({ 0, 0, 0, 0, 0, 0, 0, 0}); //makes 8x8 2D array
  }
}

object * populate_threat_array(string piece, int x, int y)
{
  object *returnme = ({});
  int temp1;
  int temp2;
  switch(piece)
  {
    case "rook": //ROOK
    temp1 = x - 1;
	while(temp1 >= 0) //LEFT
	{
	  if(CHESSBOARD[temp1][y]->query_type() != "blank" &&
	  CHESSBOARD[temp1][y]->query_type() != "threat")
	  {
	    temp1 = 0; //another piece is in the way, so stop
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][y];
      }
	  temp1--;
	}
	temp1 = x + 1;
	while(temp1 <= 7) //RIGHT
	{
      if(CHESSBOARD[temp1][y]->query_type() != "blank" &&
	  CHESSBOARD[temp1][y]->query_type() != "threat")
	  {
		temp1 = 7;
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][y];
      }
	  temp1++;
    }
	temp1 = y - 1;
	while(temp1 >= 0) //DOWN
	{
      if(CHESSBOARD[x][temp1]->query_type() != "blank" &&
	  CHESSBOARD[x][temp1]->query_type() != "threat")
	  {
		temp1 = 0;
	  }
	  else
	  {
	    returnme += CHESSBOARD[x][temp1];
      }
	  temp1--;
	}
	temp1 = y + 1;
	while(temp1 <= 7) //UP
	{
	  if(CHESSBOARD[x][temp1]->query_type() != "blank" &&
	  CHESSBOARD[x][temp1]->query_type() != "threat")
	  {
	    temp1 = 7;	  
	  }
	  else
	  {
	    returnme += CHESSBOARD[x][temp1];
      }
	  temp1++;
	}
	break;
	case "bishop": //BISHOP
	temp1 = x + 1;
	temp2 = y - 1;
	while(temp1 <= 7 && temp2 >= 0) //NORTHEAST
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() != "blank" &&
	  CHESSBOARD[temp1][temp2]->query_type() != "threat")
	  {
	    temp1 = 7;
	    temp2 = 0;	  
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }
	  temp1++;
	  temp2--;	  	
	}
	temp1 = x - 1;
	temp2 = y - 1;
	while(temp1 >= 0 && temp2 >= 0) //NORTHWEST
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() != "blank" &&
	  CHESSBOARD[temp1][temp2]->query_type() != "threat")
	  {
	    temp1 = 0;
	    temp2 = 0;	  
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }
	  temp1--;
	  temp2++;	  	
	}
	temp1 = x + 1;
	temp2 = y + 1;
	while(temp1 <= 7 && temp2 <= 7) //SOUTHEAST
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() != "blank" &&
	  CHESSBOARD[temp1][temp2]->query_type() != "threat")
	  {
	    temp1 = 7;
	    temp2 = 7;	  
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }
	  temp1++;
	  temp2++;	  	
	}
	temp1 = x - 1;
	temp2 = y + 1;
	while(temp1 >= 0 && temp2 <= 7) //SOUTHWEST
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() != "blank" &&
	  CHESSBOARD[temp1][temp2]->query_type() != "threat")
	  {
	    temp1 = 0;
	    temp2 = 7;	  
	  }
	  else
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }
	  temp1--;
	  temp2++;	  	
	}
	break;
	case "queen":
	object *ob1 = populate_threat_array("rook",x,y); //straight
	object *ob2 = populate_threat_array("bishop",x,y); //diagonal
	returnme = ob1 + ob2;
	break;
	case "king":
    temp1 = x - 1; //LEFT
    if(temp1 >= 0)
    {
	  if(CHESSBOARD[temp1][y]->query_type() == "blank" ||
	  CHESSBOARD[temp1][y]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][y];
      }
    }
	temp1 = x + 1; //RIGHT
	if(temp1 <= 7)
	{
      if(CHESSBOARD[temp1][y]->query_type() == "blank" ||
	  CHESSBOARD[temp1][y]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][y];
      }
    }
	temp1 = y - 1; //DOWN
	if(temp1 >= 0)
	{
      if(CHESSBOARD[x][temp1]->query_type() == "blank" ||
	  CHESSBOARD[x][temp1]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[x][temp1];
      }
	}
	temp1 = y + 1; //UP
	if(temp1 <= 7)
	{
	  if(CHESSBOARD[x][temp1]->query_type() == "blank" ||
	  CHESSBOARD[x][temp1]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[x][temp1];
      }
	}
	temp1 = x + 1;
	temp2 = y - 1; //NORTHEAST
	if(temp1 <= 7 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }  	
	}
	temp1 = x - 1;
	temp2 = y - 1; //NORTHWEST
	if(temp1 >= 0 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 	
	}
	temp1 = x + 1;
	temp2 = y + 1; //SOUTHEAST
	if(temp1 <= 7 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      }
	}
	temp1 = x - 1;
	temp2 = y + 1; //SOUTHWEST
	if(temp1 >= 0 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 	
	}
	break;
	case "knight":
	temp1 = x - 1;
	temp2 = y - 2; //NNW
	if(temp1 >= 0 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x + 1;
	temp2 = y - 2; //NNE
	if(temp1 <= 7 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x + 2;
	temp2 = y - 1; //EEN
	if(temp1 <= 7 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x + 2;
	temp2 = y + 1; //EES
	if(temp1 <= 7 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x + 1;
	temp2 = y + 2; //SSE
	if(temp1 <= 7 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x - 1;
	temp2 = y + 2; //SSW
	if(temp1 >= 0 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x - 2;
	temp2 = y + 1; //WWS
	if(temp1 >= 0 && temp2 <= 7)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	temp1 = x - 2;
	temp2 = y - 1; //WWN
	if(temp1 >= 0 && temp2 >= 0)
	{
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 			
	}
	break;
	case "redpawn":
    temp1 = x + 1;
    temp2 = y + 1; //SE
    if(temp1 <= 7 && temp2 <= 7)
    {
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 		    
    }
    temp1 = x - 1;
    temp2 = y + 1; //SW
    if(temp1 >= 0 && temp2 <= 7)
    {
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 		    
    }
    break;
	case "magentapawn":
    temp1 = x + 1;
    temp2 = y - 1; //NE
    if(temp1 <= 7 && temp2 >= 0)
    {
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 		    
    }
    temp1 = x - 1;
    temp2 = y - 1; //NW
    if(temp1 >= 0 && temp2 >= 0)
    {
	  if(CHESSBOARD[temp1][temp2]->query_type() == "blank" ||
	  CHESSBOARD[temp1][temp2]->query_type() == "threat")
	  {
	    returnme += CHESSBOARD[temp1][temp2];
      } 		    
    }
    break;        
	default:
	message("chess","Error: populate_threat_array() bugged with piece "+
	""+piece+", x "+x+", y "+y+".\n",this_player());
	break;
  }
  return returnme;
}

void calculate_threat()
{
  clear_threat_array();
  for(int i = 0; i < sizeof(CHESSBOARD); i++)
  {
    for(int j = 0; j < sizeof(CHESSBOARD); j++)
	{
      switch(CHESSBOARD[j][i]->query_color())
      {
	    case "magenta":
	    switch(CHESSBOARD[j][i]->query_type())
	    {
		  case "pawn":
		  threat_array = populate_threat_array("magentapawn",j,i);
		  break;
		  case "rook":
          threat_array = populate_threat_array("rook",j,i);
          break;
          case "bishop":
          threat_array = populate_threat_array("bishop",j,i);
          break;
          case "knight":
          threat_array = populate_threat_array("knight",j,i);
          break;
          case "king":
          threat_array = populate_threat_array("king",j,i);
          break;
          case "queen":
          threat_array = populate_threat_array("queen",j,i);
          break;
          case "threat": //ignore threat squares
          break;
          default:
          message("chess","Error: found something weird on the chessboard "+
          "at "+j+","+i+".\n",this_player());
          break;
	    }
	    foreach(object ob in threat_array())
        {
	      if(ob->query_color() == "blank" || ob->query_color() == "magenta")
	      {	      
		    ob->initialize("magenta threat");
	      }
	      else
	      {
		    ob->initialize("both threat");    
	      }   
        }
	    break;
	    case "red":
	    switch(CHESSBOARD[j][i]->query_type())
	    {
		  case "pawn":
		  threat_array = populate_threat_array("redpawn",j,i);
		  break;
		  case "rook":
          threat_array = populate_threat_array("rook",j,i);
          break;
          case "bishop":
          threat_array = populate_threat_array("bishop",j,i);
          break;
          case "knight":
          threat_array = populate_threat_array("knight",j,i);
          break;
          case "king":
          threat_array = populate_threat_array("king",j,i);
          break;
          case "queen":
          threat_array = populate_threat_array("queen",j,i);
          break;
          case "threat":
          break;
          default:
          message("chess","Error: found something weird on the chessboard "+
          "with odd type at "+j+","+i+".\n",this_player());
          break;
	    }
	    foreach(object ob in threat_array())
        {
	      if(ob->query_color() == "blank" || ob->query_color() == "red")
	      {	      
		    ob->initialize("red threat");
	      }
	      else
	      {
		    ob->initialize("both threat");    
	      }   
        }
	    break;
	    case "blank": //ignore blank squares
	    break;
	    case "both": //ignore "both threat" squares
	    break;
	    default:
	    message("chess","Error: found something weird on the chessboard "+
	    "with odd color at "+j+","+i+".\n",this_player());
	    break;
      }
    }  
  }  	
}

void populate_str_to_obj()
{
STR_TO_OBJ = ([
"A8":A8,"B8":B8,"C8":C8,"D8":D8,"E8":E8,"F8":F8,"G8":G8,"H8":H8,
"A7":A7,"B7":B7,"C7":C7,"D7":D7,"E7":E7,"F7":F7,"G7":G7,"H7":H7,
"A6":A6,"B6":B6,"C6":C6,"D6":D6,"E6":E6,"F6":F6,"G6":G6,"H6":H6,
"A5":A5,"B5":B5,"C5":C5,"D5":D5,"E5":E5,"F5":F5,"G5":G5,"H5":H5,
"A4":A4,"B4":B4,"C4":C4,"D4":D4,"E4":E4,"F4":F4,"G4":G4,"H4":H4,
"A3":A3,"B3":B3,"C3":C3,"D3":D3,"E3":E3,"F3":F3,"G3":G3,"H3":H3,
"A2":A2,"B2":B2,"C2":C2,"D2":D2,"E2":E2,"F2":F2,"G2":G2,"H2":H2,
"A1":A1,"B1":B1,"C1":C1,"D1":D1,"E1":E1,"F1":F1,"G1":G1,"H1":H1]);	
}

int reset_command(string str)
{
  if(str == "board" || str == "silent")
  {
	if(!sizeof(players))
	{
      for(int i = 0; i < sizeof(CHESSBOARD); i++)
      {
	    for(int j = 0; j < sizeof(CHESSBOARD); j++)
	    {
		  if(!objectp(CHESSBOARD[j][i]))
		  { //if nothing here, make new object
		    CHESSBOARD[j][i] = new("/u/a/allanon/chess/chesspiece.c");
	  	  } //set to blank square and assign unique id using varargs
	      CHESSBOARD[j][i]->initialize("blank blank",j,i); 
        }  
      }
      A1->initialize("magenta rook");
      B1->initialize("magenta knight");	
      C1->initialize("magenta bishop");	
      D1->initialize("magenta queen");
      E1->initialize("magenta king");	
      F1->initialize("magenta bishop");
      G1->initialize("magenta knight");	
      H1->initialize("magenta rook"); 
      A2->initialize("magenta pawn");
      B2->initialize("magenta pawn");		
      C2->initialize("magenta pawn");	
      D2->initialize("magenta pawn");	
      E2->initialize("magenta pawn");	
      F2->initialize("magenta pawn");	
      G2->initialize("magenta pawn");	
      H2->initialize("magenta pawn");
      A7->initialize("red pawn");
      B7->initialize("red pawn");	
      C7->initialize("red pawn");	
      D7->initialize("red pawn");	
      E7->initialize("red pawn");	
      F7->initialize("red pawn");	
      G7->initialize("red pawn");	
      H7->initialize("red pawn");    
      A8->initialize("red rook");
      B8->initialize("red knight");	
      C8->initialize("red bishop");	
      D8->initialize("red queen");	
      E8->initialize("red king");	
      F8->initialize("red bishop");	
      G8->initialize("red knight");	
      H8->initialize("red rook"); 
      calculate_threat(); 
      if(str == "board")	//only do message if !silent mode
      {
        message("chess","The chessboard has been reset.\n",this_object()); 
      }
      else
      {
	    populate_str_to_obj(); //this only gets called once
      } 
    }
    else
    {
	  message("chess","But a game is still in progress.\n",this_player());
    }
    return 1;
  }
}

void do_chessboard(int flag) //flag for first usage only
{
  if(flag)
  {
    reset_command("silent"); //populate the empty board with new pieces
  }	
  theboard = "\n"+
  "  A B C D E F G H\n"+
  " ,---------------.\n"+
  ""+ROW8+""+
  ""+LINE+""+
  ""+ROW7+""+
  ""+LINE+""+
  ""+ROW6+""+
  ""+LINE+""+
  ""+ROW5+""+
  ""+LINE+""+
  ""+ROW4+""+
  ""+LINE+""+
  ""+ROW3+""+
  ""+LINE+""+
  ""+ROW2+""+
  ""+LINE+""+
  ""+ROW1+""+
  " `---------------'\n"+
  "  A B C D E F G H\n";
}

int play_command(string str)
{
  if(!query_game_in_progress())
  {
    if(str == "1")
    {
	  message("chess","You start up a solo game (magenta moves first).\n",
	  this_player());
	  message("chess",""+this_player->query_cap_name()+" starts up a solo "+
	  "game.\n",this_object(),this_player());
	  add_player(this_player());
	  set_game_in_progress(1);
	  set_current_color("magenta");
      return 1;
    }
    else if(str == "2")
    {
	  message("chess","You start up a two-player game (magenta moves "+
	  "first).\n",this_player());
	  message("chess",""+this_player->query_cap_name()+" starts up a "+
	  "two-player game.\n",this_object(),this_player());
	  add_player(this_player());
	  set_game_in_progress(2);
	  set_current_color("magenta");
      return 1;	  
    }
    else if(str == "npc")
    {
	  message("chess","Thank you for your interest, but Allanon is still "+
	  "working on coding a not-stupid chess AI.\n",this_player());
      return 1;	  
    }
    else
    {
      return notify_fail("Usage: 'play <1|2|npc>'\n");	  
    }
  }
  else
  {
    message("chess","But there is already a game in progress.\n",this_player());
    return 1;	  
  }
}

int join_command(string str)
{
  if(str == "game")
  {
	if(sizeof(players) == 1)
	{
      message("chess","You join the chess game.\n",this_player());
      message("chess",""+this_player()->query_cap_name()+" joins the chess "+
      "game.\n",this_object(),this_player());
      if(!query_current_player()->member_array(players))
      { //last person whose turn it was left the game, so make this player
	    set_current_player(this_player());    //the new current player
      }
      add_player(this_player());
      set_game_in_progress(2);
	}
	else if(!sizeof(players))
	{
	  message("chess","There isn't a game in progress. You could start "+
	  "one with the 'play' command.\n",this_player());
	}
	else
	{
	  message("chess","But there are already two players.\n",this_player());	
	}
    return 1;
  }
}

int do_move(object piece, int xstart, int ystart, int xchange, int ychange)
{
  int returnme;
  if(xstart + xchange < 0 || xstart + xchange > 7 || 
  ystart + ychange < 0 || ystart + ychange > 7)
  {
    returnme = 0; //off the board	  
  }
  else
  {
    switch(piece->query_type())
    {
	  case "blank":
	  returnme = 0; //tried to move a blank square
	  break;
	  case "threat":
	  returnme = 0; //tried to move a blank square
	  break;
	  case "pawn":
	  switch(query_current_color()) //determine what color pawn it is
	  {
	    case "magenta": //pawn moves up
	    
	    
	    
	    
	    
	    break;
	    case "red": //pawn moves down
	    
	    
	    
	    
	    
	    break;
	    default:
	    message("chess","Error: got some weird color, "+
	    ""+query_current_color()+", to do_move().\n",this_player());
	    returnme = 0;
	    break;
      }
	  break;
	  case "rook":
	  break;
	  case "bishop":
	  break;
	  case "knight":
	  break;
	  case "king":
	  break;
	  case "queen":  
	  break;
	  default:
	  message("chess","Error: got a weird piece type to do_move() - "+
	  ""+piece->query_type()+".\n",this_player());
	  returnme = 0;
	  break; 
    }	  
  }
  
  
  return returnme;	
}

int move_pieces(object piece1, object piece2)
{
  int returnme;
  if(piece1->query_color() == query_current_color())
  {
    sscanf(piece1->query_chess_id(),temp1,temp2);
    sscanf(piece2->query_chess_id(),temp3,temp4);
    if(temp1 > temp3)
    {
      xdiff = temp1 - temp3;
      xdir = "left";	  
    }
    else if(temp3 > temp1)
    {
      xdiff = temp3 - temp1;
      xdir = "right";
    }
    else //temp1 == temp3
    {
	  xdiff = 0;
	  xdir = "none";
    }
    if(temp2 > temp4)
    {
      ydiff = temp2 - temp4;
      ydir = "down";	  
    }
    else if(temp4 > temp2)
    {
      ydiff = temp4 - temp2;
      ydir = "up";
    }
    else //temp2 == temp4
    {
	  ydiff = 0;
	  ydir = "none";   
    }
    switch(xdir)
    {
	  case "left":
	  switch(ydir)
	  {
	    case "down":
	    returnme = do_move(piece1, temp1, temp2, -xdiff, ydiff);
	    break;
	    case "up":
	    returnme = do_move(piece1, temp1, temp2, -xdiff, -ydiff);
	    break;
	    case "none":
	    returnme = do_move(piece1, temp1, temp2, -xdiff, ydiff);
	    break;
	    default:
	    message("chess","Error: weird case "+ydir+" to move_pieces().\n",
	    this_player());
	    break;
      }
      break;
      case "right":
      switch(ydir)
	  {
	    case "down":
	    returnme = do_move(piece1, temp1, temp2, xdiff, ydiff);
	    break;
	    case "up":
	    returnme = do_move(piece1, temp1, temp2, xdiff, -ydiff);
	    break;
	    case "none":
	    returnme = do_move(piece1, temp1, temp2, xdiff, ydiff);
	    break;
	    default:
	    message("chess","Error: weird case "+ydir+" to move_pieces().\n",
	    this_player());
	    break;
      }
      break;
      case "none":
      switch(ydir)
	  {
	    case "down":
	    returnme = do_move(piece1, temp1, temp2, xdiff, ydiff);
	    break;
	    case "up":
	    returnme = do_move(piece1, temp1, temp2, xdiff, -ydiff);
	    break;
	    default:
	    message("chess","Error: weird case "+ydir+" to move_pieces(). "+
	    "Possibly none-none?\n",this_player());
	    break;
      }
      break;
      default:
      message("chess","Error: weird case "+xdir+" to move_pieces().\n",
      this_player());
      break;
    }
  }
  else
  {
    returnme = 0; //move failed, not my turn
  }
  return returnme;
}

object string_to_object(string str)
{
  object returnme;
  if(STR_TO_OBJ[str])
  {
    returnme = STR_TO_OBJ[str];
  }
  return returnme;
}

int move_command(string str)
{
  if(str)
  {
    sscanf(str,"%s %s",piece,destination);
    if(piece && destination)
    {
      if(regexp(piece,"[A-H][1-8]") && regexp(destination,"[A-H][1-8]"))
      {
	    opiece = string_to_object(piece);
	    odestination = string_to_object(destination);
	    if(move_pieces(opiece, odestination))
	    {
	      message("chess","You move "+piece+" ("+opiece->query_view()+") to "+
	      ""+destination+".\n",this_player());
	      message("chess",""+this_player()->query_cap_name()+" moves "+
	      ""+piece+" ("+opiece->query_view()+") to "+destination+".\n",
	      this_object(),this_player());
	      calculate_threat();
	      toggle_current_color();
	    }
	    else
	    {
	      message("chess","You can't make that move.\n",this_player());
	    }
	    return 1;
      }   
    }
  }
}

int castle_command(string str)
{
  if(str)
  {
    return 1;
  }
  return notify_fail("Usage: 'castle'\n");
}

int passant_command(string str)
{
  if(str)
  {
    return 1;
  }
  return notify_fail("Usage: 'passant'\n");
}

int view_command(string str)
{
  if(!str)
  {
	do_chessboard(0);
    message("chess",""+theboard+"",this_player());
    return 1;
  }
  return notify_fail("Usage: 'view'\n");
}

int leavegame_command(string str)
{
  if(!str)
  {	
	message("chess","You leave the chess game.\n",this_player());
	message("chess",""+this_player()->query_cap_name()+" leaves the chess "+
	"game.\n",this_object(),this_player());
	remove_player(this_player()); 
	if(!sizeof(players))
	{
	  set_game_in_progress(0);
	  reset_command("board");	
	} 
    return 1;
  }
  return notify_fail("Usage: 'leavegame' (NOT 'leave game')\n");
}

string signfunc()
{
  return
  "\nCHESS\n"+
  "=====\n"+
  "\n"+
  "Rules of Chess:\n"+
  "  The goal of chess is to force the opponent's king ("+K+" or "+k+") \n"+
  "  into a 'check' position, whereby he cannot move without being put into \n"+
  "  capture range of one of your pieces. Players take turns moving one \n"+
  "  piece per turn. If a piece is moved onto a square that an opponent's \n"+
  "  piece occupies, the opponent's piece is captured. For a description of \n"+
  "  the various pieces and how they move/capture, look at the plaque.\n"+
  "\n"+
  "Commands available in this room:\n"+
  "  play <1|2|npc>\t\tPlay solo, with another, or with NPC\n"+
  "  join game\t\t\t\t\tJoin a game already in progress\n"+
  "  move <square1> <square2>\tMove your piece at <square1> to <square2>\n"+
  "  castle <left/right>\tAttempt to castle (see plaque, rook/king)\n"+
  "  passant\tAttempt to capture en passant (see plaque, pawn)\n"+
  "  view\t\t\t\tView the board (brief mode)\n"+
  "  look,l\t\t\tView the board (verbose mode)\n"+
  "  leavegame\t\t\tLeave the (chess) game, no penalty\n"+
  "\n";
  //"  reset board\t\t\tReset the board if no one is playing\n";
  //behind-the-scenes command that players do not use
}

string plaquefunc()
{
  return
  "\nCHESS PIECES\n"+
  "============\n"+
  "\n"+
  "Pawns:\n"+
  "  Pawns can move forward one square (two from their starting position)\n"+
  "  and they capture pieces diagonally in front of them by one square.\n"+
  "  ...\n";
}

string query_look()
{
  string look;
  do_chessboard(0);
  look = "\n"+
  "    == CHESS =="+
  "\n"+
  ""+theboard+""+
  "There is a wooden sign hanging on the wall.\n"+
  "There's also a small golden plaque on the opposite wall.\n"+
  "\n"+
  "        The only obvious exit is %^BOLD%^%^GREEN%^out%^RESET%^.\n"+
  ""+this_object()->query_look_contents()+"";
  return look;
}

void extra_init()
{
  add_action("play_command","play");
  add_action("join_command","join");
  add_action("move_command","move");
  add_action("castle_command","castle");
  add_action("passant_command","passant");    
  add_action("view_command","view");
  add_action("leavegame_command","leavegame");
  add_action("reset_command","loremipsum"); //not for player's use
}

void extra_create()
{
  set_short( "Chessboard" );
  set_long(wrap("This long desc should not be seeable.\n"));
  set_item_desc(([
  ({"wooden sign", "sign"}) : (: signfunc :),
  ({"small golden plaque", "small plaque", "golden plaque", "plaque"}) :
  (: plaquefunc :)]));
  set_safe_room(1);
  set_no_teleport(1);
  set_pre_exit_function( ([ "out" : "playing_check" ])); 
  set_exits(([
  "out" : "/u/a/allanon/workroom/connector.c"]));
  do_chessboard(1);
  create_chessboard();
}

int playing_check()
{
  if(this_player()->member_array(players))
  {
    message("info","You are in the middle of a chess game, you can't "+
    "just up and leave.\n",this_player());
    return 1;
  }
  return 0;
}