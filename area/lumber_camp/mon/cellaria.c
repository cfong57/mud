#include <mudlib.h>
#include <move.h>

inherit MONSTER;

void receive_ring(object ring);

void extra_create()
{
  set_short("Cellaria, beautiful ghost of an elf mage");
  set_long(wrap("You would recognize this person anywhere, no matter that she "+
  "seems to be deceased now. Every adventurer has heard the tales of "+
  "Cellaria, legendary mage, chronomancer, and alchemist. Said to be a "+
  "secretive recluse, she was rumored to have hidden away deep in some "+
  "forest, conducting top-secret experiments involving magic, teleportation, "+
  "and of course potion-making. Although she was on the cutting edge of "+
  "research and was highly respected by all, she met a tragic end (or so it "+
  "is said) when attempting to test a new sleeping potion. She miscalculated "+
  "the potion's strength and ended up putting herself to sleep for so long "+
  "that she died. It is quite a story, and now you have found the mage "+
  "herself. She is as beautiful, if more incorporeal, in death as she was "+
  "in life.\n"));
  set_name("cellaria");
  set_id( ({ "Cellaria", "cellaria", "ghost", "elf", "mage"}) );
  set_level(50); //in a safe room anyway, doesn't matter
  set_species("undead");
  set_race("elf");
  set_gender("female");
  set_receive_object( (["/u/a/allanon/area/lumber_camp/obj/old_ring" : 
  "receive_ring" ]) );
  set_inquiry(([
  "$GREET" : "greet_inquiry",
  ({ "help", "living soul" }) :
  "You have probably heard the story regarding my untimely death. Let "+
  "us just say that the gods were not with me on that fateful day. While "+
  "I did conduct the majority of my research on potions, I also did "+
  "experiments regarding that phenomenon known as 'teleportation'. Maybe "+
  "you have met Ereldon, the Sage of Vaerlon? His 'Teleport' spell is "+
  "a fascinating thing, but even he does not know quite how it works. "+
  "Well, eventually I discovered what he could not. But before I could "+
  "make my findings public, the ring...\n",
  ({ "the ring", "ring"}) : "Oh, did I mention that? Yes, umm...well, "+
  "I suppose since I have died, secrecy is no matter anymore...You see, "+
  "I was eventually able to derive the 'Teleport' spell down to its most "+
  "basic essence and imbue it into a catalyst, in this case a specially "+
  "prepared ring. But, alas, my last ring was lost long ago. I have all "+
  "of my 'supplies' stored in a dungeon beneath this cottage, but the "+
  "cell is locked, with the key lost somewhere in the flow of time. I can "+
  "still sense that it is nearby, but I haven't a clue where.\n",
  ({ "untimely death", "death", "story", "skeleton", "sleeping potion"}) : 
  "Let's not discuss that, shall we? Suffice it to say that while my soul "+
  "has been brought back, I am fixed to this place and cannot leave. It is "+
  "most inconvenient.\n",
  ({ "research", "potions", "beakers", "vials", "glassware" }) : "I wonder "+
  "how Yaudric is doing these days? I had always intended to visit him "+
  "again. His knowledge of alchemy was most impressive, even rivalling my "+
  "own.\n",
  ({ "alchemy", "magic", "chronomancy" }) : "A most fascinating subject. As "+
  "I can attest, one's whole life could be devoted to it, and you would not "+
  "even begin to scratch the surface of the subject. Even an immortal would "+
  "need countless ages to learn everything.\n",
  ({ "teleportation", "teleport", "ereldon", "Ereldon" }) :
  "I suspect that Ereldon used to be a Chronomancer himself, or else he "+
  "stumbled upon that 'Teleport' spell by pure coincidence. He certainly "+
  "didn't learn it from the Air Priests! The actual theory behind such "+
  "a concept is so complex that I fear I would talk you to death if I got "+
  "started.\n",
  ({ "cells", "dungeon", "supplies", "key" }) : "This cottage actually "+
  "wasn't mine originally. A master torturer used to live here, but when he "+
  "refused to sell the place to me, I gave him some fireballs for free. I "+
  "could never quite bring myself to clean the place up, though. Be careful "+
  "down there - some of his 'things' may still be lying around.\n",
  ({ "fire", "fireplace" }) : "I never thought the 'Light Fire' spell would "+
  "ever come in handy, but it allows me to keep the fireplace going even "+
  "though I am no longer capable of going to collect firewood. I have kept "+
  "it lit in the hopes of attracting adventurers such as yourself, you "+
  "see.\n"]) );
}

void greet_inquiry()
{
  force_me("greet "+this_player()->query_name());
  force_me("say Greetings! I am surprised that you found me here. It has "+
  "been many ages since I last saw a living soul - I have been waiting so "+
  "long for help to arrive.");
}

void receive_ring(object ring)
{
  object ob;
  force_me("say ...");
  ring->remove();
  ob = new("/u/a/allanon/area/lumber_camp/obj/teleport_ring.c");
  ob->move(this_player(), 1);
  message("info", "Cellaria concentrates for a moment, and the ring seems "+
  "to glow with an inner light. She gives it back to you.\n", this_player());
  message("info", "Cellaria takes the ring from"+
  ""+this_player()->query_cap_name()+" and concentrates for a moment. The "+
  "ring seems to glow with an inner light before she hands it back.\n",
  environment(this_player()), this_player());
  call_out("remove_me", 1);
}

void remove_me()
{
  force_me("say Thank you. After years of painstaking research, and ages "+
  "more waiting for some mortal to stumble upon this place and help me, my "+
  "greatest research is finally complete...now I can rest in peace.");
  message("info", "Cellaria slowly fades away into nothingness.\n",
  environment(this_object()));
  deep_inventory(this_object())->remove();
  this_object()->remove();
}