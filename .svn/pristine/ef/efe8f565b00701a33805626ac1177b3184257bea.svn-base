#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

int has_heart=0;
int maneuvering=0;
int query_no_combat_kit() { return 1; }

void extra_create()
{
  object shadow;
  set_reputation("The Fellowship of Rangers", 15+random(15));
  set_short("Qialnean, a tough elven ranger");
  set_long(wrap(
  "This ranger, garbed in simple, forest-green clothing, is a young elf "+
  "female - she looks to be maybe 120 years old or so. Her jade-green eyes "+
  "and shining, pale blond hair lend an air of youthfulness, and she appears "+
  "quite beautiful. You sense that she will grow to be a well-formed "+
  "elf female in later years. Her graceful, powerful movements are "+
  "characteristic of an experienced ranger.\n"));
  set_name("Qialnean");
  set_id( ({ "Qialnean", "qialnean", "elven ranger", "ranger", "elf"}) );
  set_level(25);
  set_race("elf");
  set_speed(0);
  set_following(0);
  set_stat("size",175);
  set_gender("female");
  set_agrochance(75);
  add_weapon("/u/a/allanon/area/caverns_of_slime/obj/qscimitar.c", 
  ({"right hand"}));
  add_weapon("/u/a/allanon/area/caverns_of_slime/obj/qscimitar2.c", 
  ({"left hand"}));
  add_armour("/u/a/allanon/area/caverns_of_slime/obj/qshirt.c");
  add_armour("/u/a/allanon/area/caverns_of_slime/obj/qtights.c");
  add_armour("/u/a/allanon/area/caverns_of_slime/obj/qgloves.c");
  add_armour("/u/a/allanon/area/caverns_of_slime/obj/qboots.c");
  set_skill("melee",75);
  set_skill("weapon parry",60);
  set_skill("slashing weapons",70);
  set_skill("swords",50);
  set_skill("dodge",60);
  set_skill("block",60);
  set_skill("avoid hits",60);
  set_skill("cleave",40);
  set_skill("light armours",60);
  set_skill("concentrated attack",35);
  set_skill("concentrated defence",35);
  set_skill("weapon parry",75);
  set_skill("offensive",55);
  set_skill("combat sense",35);
  set_skill("combat analysis",50);
  set_skill("find weakness",35);
  set_skill("contact reflexes",60);
  set_skill("continuous assault",48);
  set_skill("swing",54);
  set_skill("whirling blades", 70);
  set_skill("bladesinging", 50);
  set_skill("offensive patterns", 60);
  set_skill("defensive patterns", 60);
  set_skill("improvised combinations", 50);
  set_skill("twin weapons", 60);
  set_inquiry(([
    "$GREET": 
    ({"!nod $TPQN", "Hello, $TPQCN. Are you also here to assist the rangers?"}),
    "rangers" : "Protectors of the forest, we are...all flora and fauna, "+
    "actually.\n",
    "assist" :
      "The forest around this area is becoming badly tainted with the foul "+
      "excretements of these...monsters. For a ranger, this is an extreme "+
      "emergency! I'm here on assignment from Weloq, for surveillance and "+
      "espionage purposes. My main goal, however, is to recover something "+
      "valuable stolen by a long-dead alchemist. It was a prized heirloom in "+
      "my family, and is sorely missed. I'd give out a nice reward to the "+
      "lucky soul who returns it.\n",
    "recover" : "I'll give a reward to someone if they can find and return the "+
    "heirloom.\n",
    "heirloom": "It's called 'the heart of gold'. Have you seen it?\n",
    "reward" : "Well, you won't find out unless you return the heirloom!\n",
    ({ "the heart of gold", "heart of gold", "heart"}) :
      "Yes, it's the family heirloom. Please return it!\n"]) );
  set_receive_object( (["/u/a/allanon/area/caverns_of_slime/obj/heart": 
  "receive_heart" ]) );
  set_friends( ({"/u/a/allanon/area/caverns_of_slime/mon/murin.c"}) ); 
  set_friend_message("%^BOLD%^%^YELLOW%^Qialnean cries: Don't pick on my "+
  "sister!%^RESET%^");
  /* if(clonep(this_object()))
  {
   shadow=new("/d/guilds/ranger/shadows/ranger_battle_shadow.c");
   shadow->shadow_object(this_object());
  }*/
}

int receive_heart(object heart)
{
 object sabre;
 if(has_heart)
  {
   force_me("say I have already received the heart...");
   force_me("eye "+this_player()->query_name());
   force_me("hrm "+this_player()->query_name());
   force_me("say This must be a fake. You'll not be needing it anymore, so "+
   "I'll keep it.");
   heart->remove();
   return 1;
  }
 else
  {
   has_heart = 1;
   force_me("say Ahh! The Heart! Thank you! Here is your reward.");
   heart->remove();
   message("info", "Qialnean gives you a sabre.\n",this_player());
   message("info", "Qialnean gives "+this_player()->query_cap_name()+" "+
   "something.\n",
                   environment(this_player()),this_player());
   sabre = new("/u/a/allanon/area/caverns_of_slime/obj/sabre.c");
   sabre->move(this_player(),1);
   return 1;
  }
}

int special_hit()
{
 if(maneuvering != 1 && "/cmds/skills/whirling_blades"->start_maneuver(this_object()) == 1)
  {
   maneuvering = 1;
   call_out("maneuver", 4 + random(5));
  }
 return 1;
}

int maneuver()
{
 "/cmds/skills/whirling_blades"->do_maneuver(this_object());
 call_out("maneuver_again", 6+random(7));
 return 1;
}

/* , "with singing blades" */

int maneuver_again()
{
 maneuvering = 0;
 return 1;
}