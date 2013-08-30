#include <mudlib.h>
#include <modules.h>
#include <move.h>

inherit MONSTER;
inherit M_REPUTATION;

int has_leaf = 0;
void receive_leaf(object leaf);
void receive_branch(object branch);
void receive_key(object key);
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
  set_short("Brant, the camp overseer");
  set_reputation("The Fellowship of Rangers", -85 - random(25));
  set_long(wrap("This derro seems to be the one in charge of operations here. "+
  "Like any typical derro, he is somewhat short and stocky, with a stringy "+
  "beard and ample muscle. His white eyes give you the once-over as you look "+
  "at him, making you feel like you are being evaluated. The goblin workers "+
  "seem to take orders from him. You notice that he holds an axe as well; "+
  "he was probably a lumberjack himself in days past. It is a bit surprising, "+
  "since derros generally dislike coming to the surface, but you suppose "+
  "everyone has to make a living somehow.\n"));
  set_name("brant");
  set_id(({"Brant", "brant", "camp overseer", "overseer", "derro", "g_ob"}));
  set_level(25);
  set_race("derro");
  set_gender("male");
  set_combat_kit("fighter 3"); //add strike and stuff
  set_agrochance(40);
  add_random_stuff(5);
  set_following(0);
  if (!random(7)) {
    add_random_weapon("random_great axe", 6, ({"left hand", "right hand" }));
  } else {
    add_weapon("/u/a/allanon/area/lumber_camp/obj/gaxe");
  }
  set_chat_output(({
  "Brant mutters something about lazy goblins and consults the papers on his "+
  "desk with a shake of the head.\n",
  "The derro paces back and forth, apparently bored witless.\n",
  "Brant rifles his pockets, apparently searching for something he lost, but "+
  "can't seem to find it. He mutters, 'Where's that damn storage key?...'\n"}));
  set_chat_chance(3);
  set_receive_object( 
  (["/u/a/allanon/area/lumber_camp/obj/branch" : "receive_branch",
  "/u/a/allanon/area/lumber_camp/obj/leaf" : "receive_leaf",
  "/u/a/allanon/area/lumber_camp/obj/rotten_key" : "receive_key" ]) );
  set_inquiry(([
  "$GREET" : "greet_inquiry",
  ({ "volunteer", "help", "treant", "treants", "tree spirit", "spirit" }) :
  "So, you want to help out, eh? Here's the deal...We're plenty fast "+
  "cutting down these here trees. But there's a troublesome patch of "+
  "treants a ways past our camp that just won't be cut down. They are "+
  "alive, after all...If you could destroy some of them and bring back "+
  "their branches as proof, I'd reward you. There is also a meddlesome "+
  "tree spirit that sometimes harasses my workers...if you could kill it, "+
  "I'd greatly appreciate it. Just bring proof of the deed and I'll "+
  "reward you.\n",
  "supervise" : "Goblins may be hard workers, and they're plenty strong and "+
  "thorough, but the fact is - they're plain stupid. Which is why they need "+
  "a smart derro like me to keep an eye out for 'em.\n",
  "reward" : "I don't have much to give away, but trust me, I will reward "+
  "you suitably. First you need to help me out, of course.\n",
  "goblins" :
  "I watched a goblin lumberjack cut down a great big evergreen one day "+
  "all by his lonesome. They're darn good at cutting things down. That's "+
  "why goblins were picked for this lumber camp.\n",
  ({ "key", "storage key"}) :
  "Aah, don't mind me grumbling. We have a storehouse here in the camp "+
  "where all the food is kept, and I was just thinking I would pop on over "+
  "to grab a snack, but I seem to have misplaced the key somewhere. I "+
  "definitely had it before that battle at the stream, when I fought against "+
  "the damn tree spirit.\n"]));
}

void greet_inquiry()
{
  force_me("smile "+this_player()->query_name());
  force_me("say Good day to you, too, "+this_player()->query_cap_name()+"! "+
  "Life here passes a day at a time in the same routine...Cutting down trees "+
  "all day long. You think we'd get tired of it, but it never happens. I "+
  "don't actually take part in the cutting process myself, I just supervise.");
  force_me("say You know, I could always use more workers. If you'd care to "+
  "'volunteer', just ask me about it. I will of course reward hard workers.");
}

void receive_branch(object branch)
{
  force_me("say Ahh, it's one of those treant branches. Thanks for your "+
  "help! Here is your reward.");
  branch->remove();
  this_player()->credit("gold", 200 + random(150));
  message("money", "Brant gives you some gold coins.\n", this_player());
  message("money", "Brant gives "+this_player()->query_cap_name()+" some "+
  "gold coins.\n", environment(this_player()), this_player());
}

void receive_leaf(object leaf)
{
  object ob;
  if (has_leaf) {
    force_me("say Uh...Sorry, but someone already killed the tree spirit. I "+
    "don't have any reward to give you, so you can have this back.");
    leaf->move(this_player(), 1);
    message("info", "Brant gives you back your leaf.\n", this_player());
    message("info", "Brant gives the leaf back to "+
    ""+this_player()->query_cap_name()+".\n",
    environment(this_player()), this_player());
  } else {
    has_leaf = 1;
    force_me("gasp");
    force_me("say Oh! This is that golden leaf the tree spirit was always "+
    "holding. You must have killed it! I can't begin to express my gratitude. "+
    "It's not much, but please, take this as a reward!");
    leaf->remove();
    message("info", "Brant gives you a mace.\n", this_player());
    message("info", "Brant gives "+this_player()->query_cap_name()+" a "+
    "mace.\n", environment(this_player()), this_player());
    ob = new("/u/a/allanon/area/lumber_camp/obj/mace.c");
    if(ob->move(this_player()) != MOVE_OK) {
      message("info", "You can't carry the mace and drop it on the ground.\n",
      this_player());
      message("info", ""+this_player()->query_cap_name()+" can't carry the "+
      "mace and drops it on the ground.\n", environment(this_player()),
      this_player());
      ob->move(environment(this_player()));
    }  
  }
}

void receive_key(object key)
{
  object obj;
  force_me("say Oh, the storage key! What happened to it?...Well, let me "+
  "just clean that off for you.");
  key->remove();
  message("info", "Brant takes your key, pops it into a hip flask he pulls "+
  "from his belt, and shakes vigorously. He then hands you the now very "+
  "shiny key.\n", this_player());
  message("info", "Brant takes "+this_player()->query_cap_name()+"'s key "+
  "and pops it into a hip flask he pulls from his belt. After some vigorous "+
  "shaking, he hands the now shiny key back to "+
  ""+this_player()->query_cap_name()+".\n", environment(this_player()),
  this_player());
  obj = new("/u/a/allanon/area/lumber_camp/obj/bronze_key.c");
  obj->move(this_player(), 1);
  force_me("say The wonders of 100 proof...Well, as a reward for finding "+
  "our storage key, feel free to help yourself to a little snack. Dhubr knows "+
  "you deserve it more than those goblins, har!");
}

void kill_treants(object target) 
{
  force_me("say What in tarnation is one of them trees doin' here?!");
  message("aggro", "Brant rushes forward to attack "+
  ""+target->query_cap_name()+"!\n", environment(this_object()));
  this_object()->kill_ob(target);
}