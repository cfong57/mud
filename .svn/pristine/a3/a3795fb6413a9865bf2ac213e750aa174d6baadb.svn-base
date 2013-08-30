#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

string type;
string adj;
string act;
void kill_treants(object target); 

void extra_init()
{
  string *ids;
  if (environment(this_object())) 
  {
    foreach (object o in all_inventory(environment(this_object()))) 
    { 
      ids = o->query_id();    
      if (member_array("t_ob", ids) != -1) 
      {
        if (o != this_object()) 
        {
          kill_treants(o);
          return;  
        }
      }
    }
  }
}

void extra_create()
{
  switch (random(10)) {
    case 0 .. 2:
    type = "puny";
    adj = "sick-looking";
    act = "breathing heavily";
    set_long(wrap("This sickly goblin looks very out of place in contrast to "+
    ""+possessive(this_player())+" well-muscled companions..."+
    ""+subjective(this_player())+" looks smaller and weaker than the average "+
    "goblin and "+possessive(this_player())+" color isn't too good either. "+
    "You think "+subjective(this_player())+" probably has been working overly "+
    "hard to try and measure up to "+possessive(this_player())+" peers. "+
    "Curiously you note a definite gleam of intelligence behind the goblin's "+
    "eyes, unlike "+possessive(this_player())+" other brutish, barbaric "+
    "goblin friends.\n"));
    set_level(12 + random(2));
    set_agrochance(50);
    add_random_stuff(1);
    set_following(10);
    set_speed(35 + random(15)); 
    set_stat("size", query_stat("size") - 15);
    set_stat("strength", query_stat("strength") - 2);
    set_stat("constitution", query_stat("constitution") - 2);
    set_stat("intelligence", query_stat("intelligence") + 5);
    set_stat("wisdom", query_stat("wisdom") + 3);
    set_skill("magic lore", 50);
    set_skill("concentrated casting", 50);
    set_spell("fire", 50);
    set_spell("wind", 50);
    set_spell("fire dart", 50);
    add_spell("wind of fire", "none", 0, 1);
    add_spell("fire dart", "random", 0, 1);
    set_chance(35, 0);
    add_random_weapon("random_broad axe", 2, ({"left hand", "right hand" }));
    set_chat_output(({
    "The puny goblin coughs painfully. You think "+
    ""+subjective(this_player())+" looks a bit malnourished.\n"}));
    break;
    case 3 .. 5:
    type = "tired";
    adj = "hard-working";
    act = "taking a break";
    set_long(wrap("A fairly typical goblin. Well-muscled and somewhat tanned "+
    "from long hours under the green sunlight of the forest, "+
    ""+subjective(this_player())+" looks capable of sustained hard labour. "+
    "You suppose that there's quite enough work to be done around here, so "+
    ""+subjective(this_player())+" is probably kept quite busy. Currently "+
    ""+subjective(this_player())+"'s taking a brief rest from work.\n"));
    set_level(13 + random(2));
    set_agrochance(35);
    add_random_stuff(1);
    set_speed(0); 
    set_following(0);
    add_random_weapon("random_great axe", 3, ({"left hand", "right hand" }));
    force_me("wield axe");
    set_chat_output(({
    "The hard-working goblin leans comfortably against a tree stump and "+
    "relaxes.\n"}));
    break;
    case 6 .. 7:
    type = "large";
    adj = "muscular";
    act = "cutting down a tree";
    set_long(wrap("This goblin is a bit bigger than average - "+
    ""+subjective(this_player())+" is well-muscled and looks perfectly suited "+
    "for the felling of trees. You notice that "+possessive(this_player())+" "+
    "axe is quite a bit larger than the other goblins', probably because of "+
    ""+possessive(this_player())+" added strength. The goblin works rather "+
    "methodically, cutting down one tree and patiently moving on to the next "+
    "without ever a word of complaint.\n"));
    set_level(17 + random(2));
    set_agrochance(30);
    add_random_stuff(2);
    set_following(15);
    set_speed(45 + random(25)); 
    set_stat("size", query_stat("size") + 10);
    set_stat("strength", query_stat("strength") + 1);
    set_stat("constitution", query_stat("constitution") + 1);
    add_random_weapon("random_bearded axe", 4, ({"left hand", "right hand" }));
    force_me("wield axe in left hand,right hand");
    set_chat_output(({
    "The large goblin finishes cutting down the tree and moves to another "+
    "one.\n"}));
    break;
    case 8 .. 9:
    type = "huge";
    adj = "burly";
    act = "felling trees with ease";
    set_long(wrap("This goblin is quite large compared to the average goblin; "+
    ""+subjective(this_player())+" must be at least two heads taller. "+
    "Impressive muscles complete the picture, resulting in a true lumberjack "+
    "image. The goblin is so strong that "+subjective(this_player())+" wields "+
    "two axes, unlike "+possessive(this_player())+" less gifted "+
    "co-workers.\n"));
    set_level(20 + random(2));
    set_agrochance(25);
    add_random_stuff(2);
    set_following(25);
    set_speed(55 + random(20)); 
    set_stat("size", query_stat("size") + 25);
    set_stat("strength", query_stat("strength") + 2);
    set_stat("constitution", query_stat("constitution") + 2);
    add_random_weapon("random_head axe", 5);
    add_random_weapon("random_head axe", 5);
    force_me("wield all");
    set_chat_output(({
    "The burly goblin cuts down a thin tree with a single mighty cleave.\n",
    "The burly goblin's twin axes cut a swath of devastation through the "+
    "forest.\n"}));
    break;
  }    
  set_chat_chance(3);
  set_att_chat_output( ({ "The goblin looks around hungrily, "+
  ""+subjective(this_player())+" is probably imagining "+
  ""+possessive(this_player())+" enemies are just more trees to cut down.\n"})); 
  set_short(type+", "+adj+" goblin, "+act);
  set_race("goblin");
  set_reputation("The Fellowship of Rangers", -5 - random(3));
  set_name(""+adj+" goblin");
  set_id( ({ "A "+type+", "+adj+" goblin, "+act+"", 
  "a "+type+", "+adj+" goblin, "+act+"", ""+type+" goblin", ""+adj+" goblin",
  "goblin "+act+"", "goblin", "g_ob"}));  
  set_inquiry(([
  "$GREET" : "Hullo, stranger! I am lumberjack! Cut down trees for living!\n",
  "$DEFAULT" : "Sorry, no know anything about that.\n",
  ({ "lumberjack", "lumberjacking", "cutting", "cut", "tree", 
  "trees", "lumber" }) :
  "We cuts down trees! Is lots of fun, more even than a fite! Heheehe!\n",
  ({ "Brant", "brant", "camp overseer", "overseer" }) :
  "We no like him much. He not very nice. Always scream at "+
  "us to work harder.\n",
  ({"tree spirit", "spirit"}) : 
  "Big scary spirit appear sometime! It very strong. Me "+
  "no like Brant, but he very strong. He drive back tree spirit...\n",
  ({"treant", "treants", "tree-treants"}) : "Tree-treants! Big living trees "+
  "that come and harrass us! We fite on site!\n"]));
  set_friends( ({"/u/a/allanon/area/lumber_camp/mon/goblins.c"}) ); 
  set_friend_message("%^BOLD%^%^YELLOW%^The "+adj+" goblin shouts: Hey! Me no "+
  "let you attack friend!%^RESET%^"); 
  set_forbidden_rooms(({
  "/u/a/allanon/area/lumber_camp/rooms/bw",
  "/u/a/allanon/area/lumber_camp/rooms/storehouse",
  "/u/a/allanon/area/lumber_camp/rooms/river",
  "/u/a/allanon/area/lumber_camp/rooms/tent",
  "/u/a/allanon/area/lumber_camp/rooms/fsecret",
  "/u/a/allanon/area/lumber_camp/rooms/treetop_secret"}));
}

void kill_treants(object target)
{
  force_me("say Ayaa, treant-tree! Me kill!");
  message("aggro", "The goblin grins maliciously and rushes "+
  "forward to attack "+target->query_cap_name()+"!\n",
  environment(this_player()), ({this_object(), target}));
  message("aggro", "The goblin grins maliciously and rushes "+
  "forward to attack you!\n", target);
  this_object()->kill_ob(target);
}