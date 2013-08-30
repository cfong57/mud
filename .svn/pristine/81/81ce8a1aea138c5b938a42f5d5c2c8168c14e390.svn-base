#include <mudlib.h>
#include <modules.h>
#include <move.h>

inherit MONSTER;

int chatter = 0;

void set_chatter(int c)
{
    chatter = c;
}

void receive_message( mixed cl, mixed msg)
{
  object pob = query_partyob();
  object leader;
  string sayer,cmd,par;

  if ( !pob) 
  {
    :: receive_message(cl,msg);
    return;
  }

  leader = pob->query_leader();
  if ( leader == this_object()) 
  {
    :: receive_message(cl,msg);
    return;
  }

  if ( cl == "party") 
  {
      if ( sscanf( msg, "%([^[]+)%([^:]+:) %([^\n]+)", sayer, par, cmd) == 3) 
      {
	  if ( sayer == leader->query_cap_name()+" ") 
	  {
	      force_me(cmd);
	  }
      }
  } 
  else 
  if ( chatter) 
  {
      message("info","%^BOLD%^%^BLACK%^Franz '"+cl+"': "+msg+"%^RESET%^",
      leader);
  }

  :: receive_message(cl,msg);
}

int return_command( string cmd)
{
  object p = this_player();
  object to = this_object();
  if (!cmd)
  {
  message("info","%^YELLOW%^Franz says: I understand, I'll return to the "+
  "workroom now!%^RESET%^\n",environment(p),to);
  message("move","Franz shimmers a bit and suddenly disappears.\n",
  environment(p),to);
  this_object()->move("/u/a/allanon/workroom/allanon_workroom.c");
  return 1;
  }
}

void extra_init()
{
    add_action("return_command","return");
}

void extra_create()
{
  set_gender("male");
  set_short("Franz, a faithful knight (riding on a griffon)");
  set_long(wrap("Franz is a young-looking knight. "+
  ""+capitalize(subjective(this_object()))+" seems to be quite "+
  "confident of "+possessive(this_object())+" skills, despite "+
  ""+possessive(this_object())+" young age. You take special note of "+
  ""+possessive(this_object())+" equipment, which is top-notch and in superb "+
  "condition. Seems like "+subjective(this_object())+" takes "+
  ""+possessive(this_object())+" duties seriously. Franz's calm demeanor and "+
  "easy smile puts you totally at ease with "+objective(this_object())+". "+
  ""+capitalize(subjective(this_object()))+" is riding a griffon.\n"));
  set_name("Franz");
  set_id( ({ "Franz", "franz", "faithful knight", "knight"}) );
  set_level(100);
  set_race("human");
  set_stat("size",170);
  set_agrochance(100);
  set_following(0);
  switch(random(2))
  {
  case 0:
  add_random_weapon("mithril_javelin", 10);
  break;
  case 1:
  add_random_weapon("mithril_executioner's sword", 10);
  break;
  }
  add_random_weapon("titanium_knight shield", 10);
  add_random_armour("titanium_full plate_breastplate", 10);
  add_random_armour("titanium_full plate_bracers", 10);
  add_random_armour("titanium_full plate_neck guard", 10);
  add_random_armour("titanium_full plate_full helm", 10);
  add_random_armour("titanium_full plate_gauntlets", 10);
  add_random_armour("titanium_full plate_greaves", 10);
  add_random_armour("titanium_full plate_boots", 10);
  set_stat("strength", query_stat("strength")+100);
  set_stat("dexterity", query_stat("dexterity")+100);
  set_stat("constitution", query_stat("constitution")+100);
  set_stat("intelligence", query_stat("intelligence")+100);
  set_stat("wisdom", query_stat("wisdom")+100);
  set_stat("charisma", query_stat("charisma")+100);
  set_skill("weapon parry",999); 
  set_skill("shield parry",999); 
  set_skill("light armours",999); 
  set_skill("medium armours",999); 
  set_skill("heavy armours",999); 
  set_skill("melee",999); 
  set_skill("piercing weapons",999); 
  set_skill("swords",999); 
  set_skill("spears",999); 
  set_skill("impale",999); 
  set_skill("thrust",999); 
  set_skill("slashing weapons",999); 
  set_skill("chop",999); 
  set_skill("cleave",999); 
  set_skill("swing",999); 
  set_skill("pierce",999); 
  set_skill("slash",999); 
  set_skill("dodge",999); 
  set_skill("avoid hits",999); 
  set_skill("block",999); 
  set_skill("twin weapons",999); 
  set_skill("enhance criticals",999); 
  set_skill("bludgeoning weapons",999); 
  set_skill("shields",999); 
  set_skill("pound",999); 
  set_skill("crush",999); 
  set_skill("warding",999); 
  set_skill("animal lore",999);
  set_skill("befriend animal",999); 
  set_skill("blind fighting",999); 
  set_skill("cold tolerance",999); 
  set_skill("combat analysis",999); 
  set_skill("combat sense",999);  
  set_skill("concentrated attack",150); 
  set_skill("concentrated defence",999); 
  set_skill("concentrated casting",150); 
  set_skill("contact reflexes",999); 
  set_skill("continuous assault",150); 
  set_skill("controlled retreat",999); 
  set_skill("counter-attack",150); 
  set_skill("defensive battle strategy",999); 
  set_skill("defensive",999); 
  set_skill("detect traps",999); 
  set_skill("determination",999); 
  set_skill("divine intervention",999); 
  set_skill("kick",999); 
  set_skill("double kick",999); 
  set_skill("elemental phase protection",999); 
  set_skill("essence of true ritual",999); 
  set_skill("etiquette",999); 
  set_skill("fake offensive rituals",999); 
  set_skill("find weakness",999); 
  set_skill("first aid",999); 
  set_skill("chirurgy",999); 
  set_skill("bladesinging",999); 
  set_skill("body of divinity",999); 
  set_skill("cast lightning",999); 
  set_skill("lightning focusing",999);
  set_skill("mastery of lightning",999); 
  set_skill("cast magical",999); 
  set_skill("magic lore",999); 
  set_skill("magic flow control",999); 
  set_skill("doctrine of fury",999); 
  set_skill("air lore",999); 
  set_skill("air doctrine",999); 
  set_skill("air rituals",999); 
  set_skill("fishing",999); 
  set_skill("hunting",999); 
  set_skill("camouflage",999); 
  set_skill("flail",999); 
  set_skill("headbutt",999);  
  set_skill("herbalism",999); 
  set_skill("hide in shadows",999); 
  set_skill("honour the slain",999); 
  set_skill("horsemanship",999); 
  set_skill("knowledge of ingredients",999); 
  set_skill("knowledge of mushrooms",999); 
  set_skill("knowledge of weapons",999); 
  set_skill("create incense",999); 
  set_skill("create powder",999); 
  set_skill("camping",999); 
  set_skill("carving",999); 
  set_skill("skinning",999); 
  set_skill("combine potions",999); 
  set_skill("consider",999); 
  set_skill("cooking",999); 
  set_skill("decant potion",999); 
  set_skill("drifting",999); 
  set_skill("evaluate potion",999); 
  set_skill("leatherworking",999); 
  set_skill("magical defences",999); 
  set_skill("magical focusing",999); 
  set_skill("martial arts",999); 
  set_skill("mastery of magical",999); 
  set_skill("mastery of throwing",999); 
  set_skill("melee massacre",999); 
  set_skill("mix poison",999); 
  set_skill("mixing",999); 
  set_skill("move silently",999); 
  set_skill("natural",999); 
  set_skill("brawling",999); 
  set_skill("offensive battle strategy",999); 
  set_skill("pain tolerance",999); 
  set_skill("pain threshold",999); 
  set_skill("parry",999); 
  set_skill("pathfinding",999); 
  set_skill("piercing hurl",999); 
  set_skill("plant lore",999); 
  set_skill("pound",999); 
  set_skill("prayer",999); 
  set_skill("preserve meat",999); 
  set_skill("preserve skin",999); 
  set_skill("recant potions",999); 
  set_skill("resist exhaustion",999); 
  set_skill("revive",999); 
  set_skill("ride exotic creatures",999); 
  set_skill("riding",999); 
  set_skill("rite of success",999);
  set_skill("rite of power",999); 
  set_skill("rituals of fury",999); 
  set_skill("rural combat",999); 
  set_skill("rural concealment",999); 
  set_skill("self-control",999);  
  set_skill("shield bash",999); 
  set_skill("shield rush",999); 
  set_skill("shield punch",999); 
  set_skill("shocking throw",999); 
  set_skill("stab",999); 
  set_skill("stalk",999); 
  set_skill("suppress magic flow",999); 
  set_skill("theory of alchemy",999); 
  set_skill("throw axes",999); 
  set_skill("throw hammers",999); 
  set_skill("throw spears",999); 
  set_skill("throwing",999); 
  set_skill("tracking",999); 
  set_skill("trapping",999); 
  set_skill("true stillness",999); 
  set_skill("unarmed fighting",999); 
  set_skill("tuning",999); 
  set_skill("unbending defence",999); 
  set_skill("vital points",999); 
  set_skill("wilderness retreat",999); 
  set_skill("wipe tracks",999); 
  set_skill("strike",999); 
  set_skill("strike mighty blow",999); 
  set_skill("wounding",999); 
  set_skill("stunning",999); 
  set_skill("injuring",999); 
  set_spell("call lightning",999);
  set_spell("heal",999);
  add_spell("call lightning", "random", 0);
  set_chance(100,0);
  force_me("battle -c warding");
  set_inquiry(([
  "$GREET" : "Hi. My name's Franz. I'm Allanon's personal NPC-assistant.\n",
  "$DEFAULT" : "I don't know. Why don't you ask Allanon?\n",
  ({"Franz", "franz"}) : "That's my name!\n",
  ({"Allanon", "allanon"}) : "She's the greatest!\n",
  ({"NPC", "npc", "assistant", "NPC-assistant", "npc-assistant",
  "personal NPC-assistant", "personal npc-assistant",
  "Allanon's personal NPC-assistant", "allanon's personal NPC-assistant",
  "Allanon's personal npc-assistant", "allanon's personal npc-assistant"}):
  "Yes, that's my job. I do whatever Allanon asks me to. I'm much more "+
  "convenient than those 'testmonsters', you know.\n"]));
  set_wealth(([]));
  if(clonep(this_object()))
  { 
  call_out("ride_mount",0); 
  } 
}

void party_invite(object mon) 
{ 
if(mon->query_name() == "allanon") 
{ 
force_me("party join"); 
force_me("greet allanon");
force_me("say Let's rock!"); 
} 
else 
force_me("say Sorry, "+mon->query_cap_name()+", I only party with Allanon."); 
} 

int ride_mount() 
{ 
 object shadow; 
 set_short("Franz, a faithful knight"); 
 shadow = new("/u/b/belannaer/riding/generic_mount_shadow"); 
 shadow->move(this_object(),1); 
 shadow->hp_tuner(100); 
 shadow->ep_tuner(100); 
 shadow->name_tuner("0","0"); 
 shadow->start_riding(this_object(),
                      "griffon",1000,1000,
                     ([ "mount" : 1, 
                        "warfare" : 1, 
                        "kneel" : 1, 
                        "air combat" : 1, 
                        "flight mount" : 1, 
                        "hauling" : 1, 
                        "race tolerance" : 1, 
                        "steady ride" : 1,
                        "hunt" : 1, 
                        "magic" : 1, 
                        "jousting" : 0, 
                        "saddle" : 1, 
                        "leadrope" : 1 ]));  
} 

void second_life() 
{ 
 object mount; 
 object TO = this_object();

 if(TO->query_riding()) 
  { 
   mount = new("/u/b/belannaer/riding/generic_mount"); 
   mount->hp_tuner((TO->query_mount_hp()*100)/TO->query_mount_max_hp());
   mount->ep_tuner((TO->query_mount_ep()*100)/TO->query_mount_max_ep());
   mount->mounttype(TO->query_mount_type(),1000,1000,TO->query_feats()); 
   mount->name_tuner("0","0"); 
   mount->move(environment(TO)); 
   mount->kill_ob(TO->query_last_attacker());
  } 
}