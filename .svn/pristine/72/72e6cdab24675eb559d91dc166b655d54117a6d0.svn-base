#include <mudlib.h>

inherit MONSTER;

int has_heart=0;
int receive_heart(object heart);

void extra_create()
{
  set_short("lucid ghost of the alchemist");
  set_long(
      wrap("Before you floats the pale white ghost of the alchemist. She seems "+
           "perturbed by something. You seem to recall that the reason "+
           "spirits are not allowed to leave for the Nether Plane is because "+
           "they have unfinished business in the world... you wonder if perhaps "+
           "you could help out?\n"));
  set_name("ghost");
  set_id( ({ "lucid ghost of the alchemist", "ghost of the alchemist", "ghost"}) );
  set_level(29);
  set_species("undead");
  set_race("elf");
  set_stat("size",175);
  set_gender("female");
  set_agrochance(50);
  set_spell("acid blast", 50);
  add_spell("acid blast", "random", 0);
  set_chance(50,0);
  set_receive_object( (["/u/a/allanon/area/caverns_of_slime/obj/heart" : "receive_heart" ]) );

  set_skin_data("type", "none");
  set_heartless(1);
  set_inquiry(([
    "$GREET" : "greet_inquiry",
    "help" :
      "Before I died, I created a good weapon using my newfound research. I "+
      "will give it to you if you bring me proof of slaying the huge black slime. He "+
      "is tainting this area and the surrounding forest with his foul "+
      "acid, but I can't stop him - I'm too afraid to go down there.\n",
    ({ "good weapon", "weapon"}) : "You'll just have to help me out and see what it is, eh?\n",
    ({ "newfound research", "research"}) :
      "A load of technical stuff. A commoner like you wouldn't understand it.\n",
    "proof" :
      "There is an item - the heart of gold - that would serve as sufficient proof "+
      "of slaying the huge black slime. Bring it to me after he has been slain.\n",
    "experiment" :
      "Yes, I messed up that experiment long ago. It blew up, and I died. What "+
      "more is there to tell?\n",
    ({ "slimes", "oozes", "flans" }) :
      "I don't know how they got made, but they are frightening and powerful.\n"]) );
}

void greet_inquiry()
{
  force_me("greet "+this_player()->query_name());
  force_me("say Greetings, wanderer. Have you come to help me?");
  return;
}

int receive_heart(object heart)
{
 object ob;
 string item;

 if(has_heart)
  {
   force_me("say I have already received the heart, but thanks anyway.");
   force_me("cackle "+this_player()->query_name());
   return 1;
  }
 else
  {
   has_heart = 1;
   force_me("say Thank you, I've finally got it back, and the huge black slime is "+
  	        "dead! As promised, here is the weapon.");
   heart->remove();

   switch(random(3))
    {
	 case 0:
	  ob = new("/u/a/allanon/area/caverns_of_slime/obj/acidaxe.c");
	  item = "an axe";
     break;
	 case 1:
	  ob = new("/u/a/allanon/area/caverns_of_slime/obj/acidsword.c");
	  item = "a sword";
     break;
	 case 2:
	  ob = new("/u/a/allanon/area/caverns_of_slime/obj/acidrapier.c");
	  item = "a rapier";
     break;
    }

   ob->move(this_player(),1);
   message("info", "The ghost gives you "+item+".\n",this_player());
   message("info", "The ghost gives "+this_player()->query_cap_name()+" "+item+".\n",
                   environment(this_player()),this_player());
   call_out("remove_ghost",3);
  }
}

void remove_ghost()
{
 message("info", "Having completed her business in the world, the ghost "+
	             "hurriedly departs for the Nether Plane.\n",environment(this_object()));
 deep_inventory(this_object())->remove();
 this_object()->remove();
 return;
}