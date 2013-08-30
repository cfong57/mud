#include <mudlib.h>
#include <modules.h>

inherit MONSTER;

void extra_create()
{
  set_short("Githrin, an old elf mage");
  set_long(wrap("Githrin may be an old elf, but you sense a definite aura of "+
  "magical power around him. His eyes sparkle with wisdom gained over a "+
  "lifetime, and while his movements are stiff, none are without purpose. "+
  "He gives you an appraising once-over and nods a bit in approval. The elf "+
  "uses the support of a staff to move around, but you notice the callouses "+
  "on his hands: he probably knows how to fight with it, too.\n"));
  set_name("Githrin");
  set_id( ({ "githrin", "old elf mage", "old elf", "old mage", "elf mage",
  "elf", "mage", "githrin_ob"}) );
  set_gender("male");
  set_level(25);
  set_race("elf");
  set_agrochance(100);
  set_following(0);
  set_combat_kit("mage 5");
  add_random_weapon("random_staff", 6);
  add_object("/u/a/allanon/area/ity/obj/noblekey.c");
  set_inquiry(([
  "$GREET" : "Greetings, $TPQCN. I am Githrin, mage by trade, but adventurer "+
  "by blood.\n",
  "$DEFAULT" : "Hmm, I'm afraid I don't know anything about that.\n",
  ({"adventurer", "mage"}) : "The life of studying books and casting spells "+
  "all day long got boring to me very quickly, so I took to the road as a "+
  "battle mage. My spells and my staff have claimed the lives of many a "+
  "villain. Perhaps you are also restless for some adventure? I would be "+
  "pleased to accompany you, although I will not leave this castle.\n",
  "castle" : "This castle is a convenient place for me to stay. It is much "+
  "more comfortable than an inn, and I am rarely bothered by anyone or "+
  "anything.\n",
  "accompany" : "Just invite me to your party.\n",
  ({"key", "^door$"}) : "Yes, I have the key to the Nobles Room door. I would "+
  "prefer to hold onto it myself, since I live there. If you need me to open "+
  "the door, just 'ask' me to do so.\n",
  ({"open door", "open the door"}) : "open_inquiry"]));
  set_forbidden_rooms(({"/u/a/allanon/area/ity/rooms/drawbridge"}));
}

void party_invite(object mon) 
{ 
  if(mon->query_player()) 
  { 
    force_me("party join"); 
    force_me("say Let's do this thing before I just play 3");
  } 
  else
  { 
    force_me("say Sorry, "+mon->query_cap_name()+", I only party with players");
  } 
}

void open_inquiry()
{
  force_me("unlock door with key");
}