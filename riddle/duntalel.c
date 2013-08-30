#include <mudlib.h>
#include <modules.h>

#define QUIZ_D "/u/a/allanon/riddle/quiz_d"
#define DEBUG(x) message("info", wrap(x),find_living("allanon"))

inherit MONSTER;
inherit M_REPUTATION;

mapping question_data;
void check_answer(string v);
void read_difficulty(string v);
void read_question();
void read_category(string v);
string answer;
int event_running=0;

void extra_create()
{
  set_short("Duntalel, gnome riddle-master");
  set_reputation("The Gnomish Trading Post", 85+random(25));
  set_long(wrap("Before you stands a wizened-looking gnome wearing a pair of "+
  "shiny crystal spectacles. He is slightly hunchbacked, and moves around "+
  "with a bit of a limp, but his eyes still reflect an enormous intelligence. "+
  "He looks around searchingly, as if he is trying to find someone. Perhaps "+
  "you might want to say hello?\n"));
  set_name("Duntalel");
  set_gender("male");
  set_id(({"duntalel", "gnome riddle-master", "riddle-master", "gnome"}));
  set_level(65+random(15));
  set_race("gnome");
  add_random_weapon("random_staff", 6, ({"left hand", "right hand" }));
  add_armour("/u/a/allanon/riddle/specs.c");
  set_stat("size",(this_object()->query_stat("size"))-5);
  set_spell("mana blast",100);
  set_skill("magic lore",100);
  set_skill("concentrated casting",100);
  add_spell("mana blast", "random", 0, 1);
  set_chance(100,0);
  set_agrochance(100);
  set_following(0);
  set_speed(0);
  set_chat_output(({
  "Duntalel looks around for people to quiz.\n",
  "Duntalel mutters '...riddle...'.\n",
  "Duntalel eyes you and 'hmms' thoughtfully.\n"}));
  set_chat_chance(3);
  set_inquiry(([
    "$GREET" : "greet_inquiry",
    "riddle" :
      "I am an old gnome, young one. Over the many years of my life I have "+
      "accumumated a vast number of facts, figures, and other pieces of "+
      "information. Recently I have decided that I would like to share it out "+
      "to everyone! But...I thought it would be more entertaining to give out "+
      "riddles instead of just writing a book, you see. If you'd like to "+
      "challenge your knowledge, just ask me about a 'question'!\n",
    "$DEFAULT" : "I'm sorry, what did you say?\n",
     "question" : "riddle_me"]));
}

void greet_inquiry()
{
  force_me("smile "+this_player()->query_name()+" wisely");
  force_me("say And a good day to you, "+this_player()->query_cap_name()+"! "+
  "Are you here, perhaps, to ask for a riddle?");
  return;
}

void riddle_me()
{
	read_category("");
}

void read_category(string v)
{
  int i;
  string *categories = QUIZ_D->query_categories();
  object p = this_player();
  if(!sizeof(categories))
  {
  message("info", "BUG! There are no questions in the directory. Inform "+
  "someone in command!\n",p);
  return 0;
  }
  if(!sizeof(v))
  {
    string def = "";
    for(i = 0; i < sizeof(categories); i++)
    {
      def += "["+sprintf("%d",i+1)+"] "+categories[i]+"\n";
    }
    message("info","Categories available:\n"+def+"Which category "+
    "[1-"+sprintf("%d",i)+",random,q]?\n",p);
    input_to("read_category");
    return;
  }
  if(v == "q") 
    return;    
  if(v == "random")
  {
    p->set("quiz/category","");
    read_difficulty("");
    return;
  }    
  if(atoi(v))
  {
    p->set("quiz/category",categories[atoi(v)-1]);
    read_difficulty("");
    return;
  }
  message("info","A number 1 - "+sprintf("%d",i+1)+", random or "+
  "q, please.\n",p);
  read_category("");
}

void read_difficulty(string v)
{
  int i;
  mixed *difficulties = QUIZ_D->query_difficulties();
  object p = this_player();
  if(!sizeof(v))
  {
    string def = "";
    for(i = 0; i < sizeof(difficulties); i++)
    {
      def += "["+sprintf("%d",i+1)+"] "+difficulties[i][1]+"\n";
    }
    message("info","Difficulties available:\n"+def+"Which difficulty "+
    "[1-"+sprintf("%d",i)+",random,q]?\n",p);
    input_to("read_difficulty");
    return;
  }
  if(v == "q") 
    return;    
  if(v == "random")
  {
    p->set("quiz/difficulty","");
    read_question();
    return;
  }    
  if(atoi(v))
  {
    p->set("quiz/difficulty",difficulties[atoi(v)-1][1]);
    read_question();
    return;
  }
  message("info","A number 1 - "+sprintf("%d",i+1)+", random or "+
  "q, please.\n",p);
  read_difficulty("");
}

void read_question()
{
  object p = this_player();  
  question_data = QUIZ_D->query_questions(p->query("quiz/category"),
  p->query("quiz/difficulty"))
    [random(sizeof(QUIZ_D->query_questions(p->query("quiz/category"),
  p->query("quiz/difficulty"))))];  
  p->set("quiz/data",question_data);
  message("info","Question: "+question_data["question"]+"\n",p);
  check_answer("");
}

void confirm_answer(string v)
{
  object p = this_player();
  mapping temp_data;
  temp_data = p->query("quiz/data");  
  if(!(v == "yes" || v == "y" || v == "Yes"))
  {
    check_answer("");
    return;
  }  
  foreach(string s in temp_data["answer"])
  {
    if(strsrch(implode(temp_data["answer"],","),answer) != -1)
    { // This is quite generous, the player only has to mention the answer.
      message("info", "Well done! That is correct.\n",p);
      if(sizeof(temp_data["explanation"]))
      {
	      message("info",temp_data["explanation"]+"\n",p);
      }
      return;
    }
  }
  message("info", "Sorry, that is incorrect.\n",p);
}

void check_answer(string v)
{
  object p = this_player();
  if(!sizeof(v))
  {
    message("info","Answer: \n",p);
    input_to("check_answer");
    return;
  }
  answer = v;
  message("info", "Are you sure that is your answer? [y,n]\n",p);
  input_to("confirm_answer");
}