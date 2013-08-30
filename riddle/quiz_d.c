#include <mudlib.h>
#include <daemons.h>

#define DEBUG(x) if(find_living("allanon")) message("info", wrap(x),find_living("allanon"))
#define DIR "/u/a/allanon/"
#define QUIZ_DIR DIR+"quiz_questions/"
#define SCRE(x) x[0]

string *quiz_questions;
string *categories = ({});
mixed *difficulties = ({});
string *difficulty_names = ({});
int *difficulty_values = ({});
mapping questions = ([]);

void create()
{
  string *tmp;
  string name;
  int i;
  seteuid(getuid());  
  quiz_questions = ({});  
  tmp = get_dir(QUIZ_DIR + "*.c");
  if(sizeof(tmp))
  {
    foreach(string file in tmp)
    {
      object ob;
      ob = load_object(QUIZ_DIR + file);
      if(!ob)
        continue;        
      if(ob->query_quiz_question())
      {
        name = file[0..<3];
        if(!ob->query_category() || !ob->query_difficulty() || 
        !ob->query_question() || !ob->query_answer() || 
        !stringp(ob->query_category()) || !arrayp(ob->query_difficulty()) || 
        !stringp(ob->query_question()) || !arrayp(ob->query_answer()))
        {          
          if(directory_exists(DIR+"logs"))
            write_file(DIR+"logs/quiz_log", ctime(time())+" "+file+" is not "+
            "complete and won't be included.\n");
            DEBUG(""+ctime(time())+" "+file+" is not complete and won't be "+
            "included.\n");        
          continue;
        }      
        i = member_array(ob->query_difficulty(), difficulties);
        if(i == -1)
        {
          if(member_array(ob->query_difficulty()[1],difficulty_names) != -1 ||
            member_array(ob->query_difficulty()[0],difficulty_values) != -1)
            {
            if(directory_exists(DIR+"logs")) 
              write_file(DIR+"logs/quiz_log", ctime(time())+" "+file+" has "+
              "conflicting difficulty values/names and won't be included.\n");
              DEBUG(""+ctime(time())+" "+file+" has conflicting difficulty "+
              "values/names and won't be included.\n");  
            continue;
          }
        }
        questions[name] = ([]);
        questions[name] += ([ "name" : replace_string(name,"_"," ") ]);
        questions[name] += ([ "category" : ob->query_category() ]);
        questions[name] += ([ "difficulty" : ob->query_difficulty() ]);
        questions[name] += ([ "question" : ob->query_question() ]);
        questions[name] += ([ "answer" : ob->query_answer() ]);
        if(ob->query_explanation())
        { // Optional
          questions[name] += ([ "explanation" : ob->query_explanation() ]);
        }
        else
        {
          questions[name] += ([ "explanation" : "" ]);
        }
        if(member_array(ob->query_category(), categories) == -1)
        {
          categories += ({ ob->query_category() });
        }
        if(member_array(ob->query_difficulty(), difficulties) == -1)
        {
          difficulties += ({ ob->query_difficulty() });
        }
        quiz_questions += ({ name });
      }
    }
  }
}

string *query_categories()
{
  return categories;
}

mixed *query_difficulties()
{
  return difficulties;
}

string *query_question_list()
{
  return quiz_questions;
}

mapping query_quiz_data()
{
  return questions;
}

mapping *query_questions(string cat, string dif)
{
  mapping *qq = ({});
  if(!sizeof(dif) && !sizeof(cat))
  {
    foreach(mapping q in values(questions))
    {
      qq += ({ q });
    }
    return qq;
  }  
  if(!sizeof(dif)){
    foreach(mapping q in values(questions))
    {
      if(lower_case(q["category"]) != lower_case(cat)) 
        continue;      
      qq += ({ q });
    }
    return qq;
  }  
  if(!sizeof(cat))
  {
    foreach(mapping q in values(questions))
    {
      if(lower_case(q["difficulty"][1]) != lower_case(dif)) 
        continue;      
      qq += ({ q });
    }
    return qq;
  }  
  foreach(mapping q in values(questions)) 
  {
    if ( lower_case(q["category"]) != lower_case(cat)) 
      continue;
    if ( lower_case(q["difficulty"][1]) != lower_case(dif)) 
      continue;      
    qq += ({ q });
  }
  return qq;
}

// Event stuff

int running=0;
int round=1;
int cnt=0;
object event_obj;
mapping scores = ([]);
mixed *score_l = ({});
void sort_scores();
int sort_list(mixed *a,mixed *b);
string *contestants;
object event_master;

int is_running()
{ 
	return running; 
}

void event_say(string str) 
{
  foreach(string message in explode(str, "\n")) 
  {
    CHANNEL_D->say("wiz-info", message, "riddler"); // Change this once in game
  }
}

void add_score(object plr,int point)
{
  if(!sizeof(scores[plr->query_name()]))
  {
    scores[plr->query_name()] = point;
  }
  else
  {
    scores[plr->query_name()] += point;
  }
  if(event_obj)
  {
  event_obj->force_me("tell "+plr->query_name()+" Ok, you now have a total of "+
      sprintf("%d",scores[plr->query_name()])+"!");
  }
  sort_scores();
}

void sort_scores()
{
  score_l = ({});
  foreach(string name,int points in scores)
  {
    score_l +=({({points,name})});
  }
  score_l = sort_array(scores,"sort_list");
}

int sort_list(mixed *a,mixed *b)
{
  if(SCRE(a) > SCRE(b))
  return -1;  
  else if(SCRE(a) < SCRE(b))
  return 1;
}

void start()
{
  event_obj = find_object_or_load(DIR+"riddle/riddler");
  if(running)
  return;  
  if(!event_obj)
  return;  
  event_say("This is it, it's time to test your brains against each other in "+
  "the famous Icesus riddle competition. Meet the riddler at "+
  "<location> in 5 minutes.");
  call_out("almost_riddle_event",120);
}

void run() 
{
  start();
}

void emergency_stop()
{
  if(running)
    {
      this_object()->stop_riddle_event();
      return;
    }
  event_say("Due to divine intervention the riddle event has been CANCELLED!");
  running = 0;
  return;
}

void almost_riddle_event()
{
  if(running)
  return;  
  switch(cnt)
  {
    case 0:
    event_say("Still 3 minutes until the riddle event starts!");
    break;
    case 1:
    event_say("Only 2 minutes left! Get your brain into gear!");
    break;
    case 2:
    event_say("60 seconds to Icesus's riddle-contest!");
    call_out("start_riddle_event",60);
    return;
    break;
    default:
    break;
  }  
  cnt++;
  call_out("almost_riddle_event",60);
}

void start_riddle_event()
{
  if(running)
    return;
  running = 1;
  event_say("The riddle contest has started! The following have entered "+
   implode_and(contestants)+". Good luck to them!\n");
}

void add_contestant(object plr)
{
  if(plr)
  {
    contestants += ({plr->query_cap_name()});
  }
}

string announce_statistics(int flag)
{
  string lista = "";
  string paino;
  int number = 0;
  if(running)
  {      
     if(sizeof(scores) < 1 && flag == 1)
     {
       return "No scores yet!";
     }
      else
      {
        if(flag == 0 || flag == 2)
        {
          foreach(mixed mm in scores)
          {
            number++;
            if(number<6 && number <= sizeof(scores))
            {
              paino = sprintf("%d",mm[1]);
              lista += sprintf("     %2d. %15s %10s points \n",number,
              capitalize(mm[0]),paino);
            }
          }
          if(flag == 2)
          {
            return lista;
          }
        }
      if(flag == 1)
      {
        foreach(mixed mm in scores)
        {
          number++;
          if(number < 21 && number <= sizeof(scores) && mm[0] && mm[1])
          {
            paino = sprintf("%d",mm[1]);
            lista += sprintf("     %2d. %15s %10s points \n",number,
            capitalize(mm[0]),paino);
          }
        }
        return lista;
      }
      if(running == 1)
      {
        event_say("After round "+round+" the scores are now :\n"+lista);
      }
    }
  }
}

void stop_riddle_event()
{
  int counter = 0;
  object plr;
  int reward;
  sort_scores();
  event_say("The riddle event is now over, and the final scores are : \n"+
    announce_statistics(2));  
  running = 0;  
  foreach(mixed mm in scores)
  {
    counter++;
    plr = find_player(mm[1]);
    if(!plr)
    {
      continue;
    }
    if(counter>25)
    {
      continue;
    }
    switch(counter)
    {
      case 1:
      event_obj->force_me("tell "+plr->query_name()+" Congratulations, you "+
      "have won Icesus's riddle competition.");
      // Reward goes here
      break;
      case 2:
      event_obj->force_me("tell "+plr->query_name()+" Congratulations, you "+
      "have come second in Icesus's riddle competition.");
      // Reward goes here
      break;
      case 3:
      event_obj->force_me("tell "+plr->query_name()+" Congratulations, you "+
      "have come third in Icesus's riddle competition.");
      // Reward goes here
      break;
      default:
      event_obj->force_me("tell "+plr->query_name()+" Congratulations, you "+
      "have come "+counter+"th in Icesus's riddle competition.");
      // Reward goes here
        break;
    }
  write_file(DIR+"logs/quiz_log","\n"+plr->query_cap_name()+" came in "+
  ""+counter+" place in the riddle event on "+ctime(time()));
  reward = mm[1] * 200; // Put exp reward here if you want
  if(!plr->query_linkdead())
    plr->add_exp(reward);
  message("info","You feel more experienced!\n",plr);
  }
}