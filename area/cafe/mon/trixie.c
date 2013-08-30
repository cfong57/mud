#include <mudlib.h>
#include <modules.h>
#include <daemons.h>
#include <move.h>
#include "../storage.h"

inherit MONSTER;
inherit M_REPUTATION;
inherit "/std/modules/m_talkmon.c";

#define MEMBER_LIST "/u/a/allanon/area/cafe/member_list.c"

int sitting = 0;
int booted = 0;

string shoe_chat = "Trixie whimpers a bit and bends down to rub her feet. Her "+
"shoes look really uncomfortable.\n";

string chair_chat = "Trixie mutters something to herself about not being able "+
"to sit down.\n";

string chatb = "I just wish they would give me a chair or something to sit "+
"down on. These shoes are killing me!";

mapping topicsb = ([
  "a" : "Well, you are quite pretty.",
  "b" : "I could find you a chair.",
  "c" : "Maybe you need some new footwear?",]);
  
string query_shoe_chat()
{
  return shoe_chat;
}

string query_chair_chat()
{
  return chair_chat;
}
  
string query_chatb()
{
  return chatb;	
}  
  
mapping query_topicsb()
{
  return topicsb;	
}

void remove_nonmembers()
{
  string look_msg = WEATHER_D->query_current_day_phase();
  
  //don't execute until placed in a room
  if(environment(this_object()))
  {
    //only execute at night	
    if(!strsrch(look_msg, "sun")>-1)
    {
	  string *removed = MEMBER_LIST->check_memberships();
	  foreach(string who in removed)
	  {
	    if(find_living(who))
	    {
          force_me("tell "+who+" Your membership to Wildcat Cafe has expired. "+
          "Talk to Slash if you wish to renew your membership."); 
	    }
	    else
	    {
		  force_me("tell &"+who+" Your membership to Wildcat Cafe has "+
		  "expired. Talk to Slash if you wish to renew your membership.");
	    }	
	  }	
      foreach(object ob in all_inventory(environment(this_object())))
      {
	    if(ob->query_player() && 
	    !MEMBER_LIST->query_is_member(ob->query_name()))
	    {
	      force_me("tell "+ob->query_name()+" I'm sorry, "+
	      ""+ob->query_cap_name()+", but you aren't a member. Only patrons "+
	      "with memberships are allowed to stay at night. Please talk to "+
	      "Slash in the morning if you wish to purchase a membership.");
	      message("info","Trixie ushers you out the side-door.\n",ob);
	      message("info","Trixie ushers "+ob->query_cap_name()+" out "+
	      "the side-door, since "+subjective(ob)+" isn't a member.\n",
	      environment(ob),ob);
	      if(get_from_store("foyer", ob, "all"))
	      {
	        message("info","You retrieve your things from the hooks on the "+
	        "way out.\n",ob);
          }
          ob->move("/u/a/allanon/area/cafe/rooms/entrance.c", 1);
	    }
      }
    }
  }
}

void remove_knife()
{
  if(!query_battleob())
  {
    force_me("remove knife");	  
  }
}

void phase_changed(mapping map)
{ 
  remove_nonmembers();
}

void extra_init()
{
  if(environment(this_object())) 
  {
	remove_knife();
    remove_nonmembers();
  }
}

void receive_chair(object chair)
{
  if(!sitting)
  {
    force_me("say Hmm...it's kind of crooked...but I guess it's better than "+
    "nothing. Thanks!");
    message("info","Trixie reaches into her purse and takes out some coins. "+
    "She happily gives them to you.\n",this_player());
    message("info","Trixie reaches into her purse and takes out some coins. "+
    "She happily gives them to "+this_player()->query_cap_name()+".\n",
    environment(this_object()),this_player());
    this_player()->credit("mithril", 50);
    set_short(({
	"Trixie, cute blonde receptionist at the desk (sitting on a chair)",
	"Trixie, cute blonde receptionist fighting for her life"}));
	chair_chat = "Trixie's chair leans at all sorts of crazy angles, but she "+
	"seems to be pleased with it anyway.\n";
	map_delete(topicsb, "b");
    if(booted != 2)
    {
      chatb = "I just wish I could find some new shoes to wear while I work. "+
      "These hurt so much.";
    }
    else
    {
	  chatb = "";
    }
    chair->remove();
  }
  else
  {
    force_me("say I already have a chair, thanks");
    force_me("give spiky chair to "+this_player()->query_name()+"");	  
  }
}

void receive_boot(object boot)
{
  if(booted == 0)
  {
    if(boot->query_size() >= 149 && boot->query_size() <= 202)
    {
	  force_me("say Oh! I really like this boot. I can't just wear one, "+
	  "though. Do you have another?");
	  booted = 1;
    }
    else
    {
	  force_me("say I really like this boot, but it won't fit me...");
	  force_me("give elegant lady's riding boot to "+
	  ""+this_player()->query_name()+"");   
    }
  }
  else if(booted == 1)
  {
    if(boot->query_size() >= 149 && boot->query_size() <= 202)
    { 
	  set_script(({"say Great! Now I have a matching pair. Let's try them "+
	  "on...", 2, 
      "remove shoes_ob", 2, 
      "wear elegant lady's riding boot", 1,
      "wear all elegant lady's riding boot", 2,
      "say Wow...these are so much more comfortable. I can't thank you "+
      "enough, these will make my work much more pleasant. It's not much of a "+
      "reward, but please take these", 1,
      "give shoes_ob to "+this_player()->query_name()+"", 1,
      "say Those were expensive, you know"}));  
	  booted = 2;
	  shoe_chat = "Trixie looks down and admires her elegant lady's riding "+
	  "boots with obvious pleasure.\n";
	  map_delete(topicsb, "c");
    }
    else
    {
	  force_me("say Well, it is another boot, but it won't fit me...");
      boot->move(this_player(), 1);
      message("command","Trixie gives an "+boot->query_short()+" to you.\n",
      this_player());
      message("command","Trixie gives an "+boot->query_short()+" to "+
      ""+this_player()->query_cap_name()+".\n",environment(this_object()),
      this_player());
    }
  }
  else
  {
    force_me("say I already have a nice pair of boots, thanks");
    boot->move(this_player(), 1);
    message("command","Trixie gives an "+boot->query_short()+" to you.\n",
    this_player());
    message("command","Trixie gives an "+boot->query_short()+" to "+
    ""+this_player()->query_cap_name()+".\n",environment(this_object()),
    this_player());
  }
}

void receive_boots(object boots)
{
  if(booted == 0)
  {
    if(boots->query_size() >= 149 && boots->query_size() <= 202)
    {
	  boots->set_id(({"boots", "leather boots", "zaec_boots"}));
	  set_script(({"say Ooh...these look a bit kinky. Let's try them on...", 2, 
      "remove shoes_ob", 2, 
      "wear zaec_boots", 1,
      "say These aren't any more comfortable, but they make me feel so..."+
      "naughty. I'd be lying if I said I wasn't happy. Here, you can have "+
      "these; I don't want them anymore", 1,
      "give shoes_ob to "+this_player()->query_name()+"", 1,
      "say Those were expensive, you know"}));  
	  booted = 2;
	  shoe_chat = "Trixie absentmindedly runs a hand over her long leather "+
	  "boots and shivers a bit in delight.\n";
	  map_delete(topicsb, "c");
    }
    else
    {
	  force_me("say These are nice boots, but they won't fit me...");
      boots->move(this_player(), 1);
      message("command","Trixie gives "+boots->query_short()+" to you.\n",
      this_player());
      message("command","Trixie gives "+boots->query_short()+" to "+
      ""+this_player()->query_cap_name()+".\n",environment(this_object()),
      this_player()); 
    }
  }
  else if(booted == 1)
  {
    if(boots->query_size() >= 149 && boots->query_size() <= 202)
    { 
	  boots->set_id(({"boots", "leather boots", "zaec_boots"}));
	  set_script(({"say Ooh...these look a bit kinky. Let's try them on...", 2, 
      "remove shoes_ob", 2, 
      "wear zaec_boots", 1,
      "say These aren't any more comfortable, but they make me feel so..."+
      "naughty. I'd be lying if I said I wasn't happy. Here, you can have "+
      "these; I don't want them anymore", 1,
      "give shoes_ob to "+this_player()->query_name()+"", 1,
      "say Those were expensive, you know", 2,
      "say Oh...I was holding onto this as well, but I never got another to "+
      "make a matching pair, so I guess I don't need it anymore. Why don't "+
      "you take it?", 1,
      "give elegant lady's riding boot to "+this_player()->query_name()+""}));  
	  booted = 2;
	  shoe_chat = "Trixie absentmindedly runs a hand over her long leather "+
	  "boots and shivers a bit in delight.\n";
	  map_delete(topicsb, "c");
    }
    else
    {
	  force_me("say These are nice boots, but they won't fit me...");
      boots->move(this_player(), 1);
      message("command","Trixie gives "+boots->query_short()+" to you.\n",
      this_player());
      message("command","Trixie gives "+boots->query_short()+" to "+
      ""+this_player()->query_cap_name()+".\n",environment(this_object()),
      this_player());
    }
  }
  else
  {
    force_me("say I already have a nice pair of boots, thanks");
    boots->move(this_player(), 1);
    message("command","Trixie gives "+boots->query_short()+" to you.\n",
    this_player());
    message("command","Trixie gives "+boots->query_short()+" to "+
    ""+this_player()->query_cap_name()+".\n",environment(this_object()),
    this_player());
  }
}

void extra_create()
{
  set_reputation("The City of Vaerlon", 150);
  set_short(({"Trixie, cute blonde receptionist at the desk (standing)",
  "Trixie, cute blonde receptionist fighting for her life"}));
  set_long(wrap("The receptionist is a cute blonde human, looking to be "+
  "perhaps 25 or so. Her hair is perfectly straight and reaches down to her "+
  "waist, although it is tied into a ponytail right now. She is wearing a "+
  "little badge that says 'Hello, my name is Trixie'. Trixie looks up briefly "+
  "and smiles at you warmly, making you feel most welcome just standing here "+
  "in the foyer. The book of records seems to take up a lot of Trixie's time, "+
  "as patrons are constantly coming and going.\n"));
  set_name("trixie");
  set_living_name("trixie");
  set_id(({"trixie", "blonde", "receptionist", "cute blonde",
  "cute receptionist", "cute blonde receptionist", "human"}));
  set_level(30);
  set_race("human");
  set_species("humanoid");
  set_gender("female");
  set_following(0);
  set_combat_kit("mage 3");
  set_agrochance(100);
  //keep knife hidden, wield in combat, unwield out of combat
  add_object("/u/a/allanon/area/cafe/obj/vacuum_blade.c");
  set_skill("draw weapon", 100); 
  add_armour("/u/a/allanon/area/cafe/obj/dress.c");
  add_armour("/u/a/allanon/area/cafe/obj/shoes.c");
  add_armour("/u/a/allanon/area/cafe/obj/blouse.c");
  add_armour("/u/a/allanon/area/cafe/obj/purse.c");
  set_volume(100000); //need lots of room for chair
  set_receive_object((["/u/c/cantor/orctown/other/chair" : "receive_chair"]));
  set_receive_object((["/u/m/misrobo/areas/gnomepost/obj/ridingboot" :
  "receive_boot"]));
  set_receive_object((["/u/z/zaec/areas/everglades/obj/slavemaster_boots" :
  "receive_boots"]));
  set_chat_output(({
  "Trixie flips through the pages of the book of records, checking for any "+
  "inaccuracies.\n",
  "An angry-looking patron storms up to Trixie, demanding something or other. "+
  "Her cute smile and pleasant voice soon calms the angry customer.\n",
  ""+query_shoe_chat()+"",
  ""+query_chair_chat()+""}));
  set_chat_chance(5);
  set_inquiry((["$DEFAULT" : "default_inquiry", "$GREET" : "greet_inquiry"]));
  talk_map = ([
  "greeting" : (["chat" : "Oh! Hello, "+this_player()->query_cap_name()+". "+
  "I'm always so busy working here that I don't have much time to chat with "+
  "the patrons.",]), 
  "ending" : (["chat" : "Please enjoy your time here at Wildcat Cafe!",]), 
  "start" : (["topics" : ([ 
  "a" : "You seem to get a pretty diverse crowd here.", 
  "b" : "What's your work like?",
  "c" : "Where do I purchase a membership?",]),]), 
  "a" : ([ 
  "chat" : "Yes, all kinds of people frequent this place. We definitely get "+
  "some strange customers on occasion, but it's okay as long as they pay the "+
  "bill at the end, you know?", 
  "topics" : ([ 
  "a" : "Strange customers?", 
  "b" : "Do you ever get any famous visitors?",]),]), 
  "aa" : ([ 
  "chat" : "I don't just mean some of the less common races, or the "+
  "occasional mad wizard. We have gotten some decidedly odd customers of "+
  "late...it's just the way they behave, I guess. Or maybe their dress. They "+
  "wear black robes that hide their faces, and always sit at the corner "+
  "tables muttering about this or that ritual. I guess I can't complain, "+
  "though, because they tip well and all of them bought memberships.", 
  "topics" : ([
  "a" : "Hmm, intriguing. So where do I buy a membership?"]),]),
  "aaa" : ([
  "chat" : "You shouldn't be seeing this, or else talk_map bugged. Inform a "+
  "wizard.",
  "topics" : ([]),
  "func" : "to_c",]),
  "ab" : ([ 
  "chat" : "Why, yes! We have the honor to serve some of the most famous "+
  "local Vaerlonians. Ereldon drops by on occasion, and we also see Danton, "+
  "Ceanna, Dwydran, and Vilbor sometimes. The people from the smithy - "+
  "Baltag, Ra'Shar, Vinda, Kirguz, and Karruz - hold their monthly parties "+
  "here as well. There are others, too...Andolal, Laewran, Denso, the "+
  "stablemaster...we even had the privilege to host a banquet for Sir Pemriel "+
  "and his fellow Templars once. All of this publicity has been great for "+
  "business - even though we are a new establishment, I am happy to say that "+
  "Wildcat Cafe is doing excellently!", 
  "topics" : ([]),]), 
  "b" : ([
  "chat" : "Oh, it's not bad at all. I think I got hired mostly as a "+
  "decoration, just to look pretty...while there is a lot of work to do "+
  "keeping the book of records in order, I don't have any particular talent "+
  "at it.\n"+query_chatb()+"", 
  "topics" : query_topicsb(),]), 
  "ba" : ([
  "chat" : "Ha ha...you really know how to make a girl blush. But thank you "+
  "for the compliment. Slash never says anything nice to me.", 
  "topics" : ([
  "a" : "Slash? Who's that?",]),]), 
  "baa" : ([
  "chat" : "You shouldn't be seeing this, or else talk_map bugged. Inform a "+
  "wizard.",
  "topics" : ([]),
  "func" : "to_c",]),
  "bb" : ([
  "chat" : "Really? I would love that. If you bring me a chair, I'd be happy "+
  "to share a portion of my wages with you.",
  "topics" : ([]),]),
  "bc" : ([
  "chat" : "I would love to have something new to wear. These shoes are "+
  "adorable, but it's painful to stand around in them for hours on end. I "+
  "have been visiting the shops whenever I get a chance, but nothing suitable "+
  "has ever crossed my eye. I'm thinking that some boots would be ideal..."+
  "something leather, black perhaps. Oh, but they would need to have heels; "+
  "Slash won't stand for me looking like a common serving girl. You would "+
  "think that this skimpy dress would be enough, but apparently not...anyway, "+
  "I would be in your debt if you could find me some good boots.",
  "topics" : ([
  "a" : "Who is Slash?"]),]),
  "bca" : ([
  "chat" : "You shouldn't be seeing this, or else talk_map bugged. Inform a "+
  "wizard.",
  "topics" : ([]),
  "func" : "to_c",]),
  "c" : ([
  "chat" : "Slash is the barkeeper here, and also my boss. He works in the "+
  "dining room. I think he took one too many blows to the head during his "+
  "career in the arena, but don't tell him I said that. If you wanted to buy "+
  "a membership, Slash would be the one to talk to.", 
  "topics" : ([
  "a" : "What are the benefits of a membership?"]),]),
  "ca" : ([
  "chat" : "While we can't offer a discount on our products, a membership "+
  "allows you to be here at night, so you are welcome to visit any time you "+
  "wish. Also, being a member gives access to our exclusive Member's Area, "+
  "which is in the rooms to the east. I won't spoil all of the surprises for "+
  "you, but there are some additional shops and services. I hear that members "+
  "can also get a tour of the kitchen. You should meet our chefs sometime; "+
  "they are...interesting.",
  "topics" : ([]),]),]);
  WEATHER_D->add_phase_listener(this_object());
  remove_nonmembers();
}

int chat_func(string func_name, object plr, object target) 
{ 
  if(func_name == "to_c") 
  { 
    chatted_with[plr->query_name()] = "c"; 
  } 
} 

string default_inquiry()
{
  return "Trixie is fully absorbed in her work and doesn't seem to hear you.\n";	
}

string greet_inquiry()
{
  return "Trixie glances at you and gives a little smile, but she is so busy "+
  "that she doesn't seem to have time for idle conversation. Maybe you could "+
  "'talk' to her and engage in deeper conversation.\n";
}

//trigger if unarmed
int special_hit(object target) 
{
  if(query_weapon_slots() == (["left hand" : 0, "right hand" : 0])) 
  {
	force_me("wield knife");
	force_me("say You picked the wrong girl to mess with!");
    return 1;
  }
  return 0;
}

void second_life()
{
  if(sitting)
  {
    object chair = new("/u/c/cantor/orctown/other/chair.c");
    chair->move(environment(this_object()));
  }
  foreach(object ob in all_inventory(this_object()))
  {
	if(ob->query_trixie_eq())
	{
	  ob->do_bloody();	  
	}
  }
  //there MUST be an easier way to do this
  MEMBER_LIST->check_memberships();
  foreach(object ob in all_inventory(environment(this_object())))
  {
    if(ob->id("battleob"))
    {
	  object *temp = battleob->query_fighters();
	  if(member_array(this_object(), temp))
	  {
	    foreach(object obj in temp)
	    {
		  if(MEMBER_LIST->query_is_member(obj->query_name()))
		  {
		    message("info","Due to your despicable actions, your membership "+
		    "to Wildcat Cafe has been terminated.\n",obj);
		    MEMBER_LIST->remove_member(obj->query_name());
		  }
	    }
	  }   
    }	  
  }
}