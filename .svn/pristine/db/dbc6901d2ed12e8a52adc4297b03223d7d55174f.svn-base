#include <mudlib.h>
#include <damage.h>

inherit MONSTER;

object sorcshadow;

void extra_create()
{
 set_id ( ({ " elven woman", "elf", "woman", "sorcerer", "shashara"}) );

 set_short ( "A very Old Elven Woman" );

 set_long ( wrap("This is a very, very old elven woman. So old she has
wrinkles! "+
           "Her hair is braided into hundreds of tiny strands and hangs
down past her buttocks. " +
           "She has steel grey eyes, covered with a milky film, and long
fingers tipped with " +
           "well kept fingernails. " )
          );

 set_species ("humanoid");
 set_race ("dark elf");

 set_alignment (-250);

 set_level (20+random(5));

 set_living_name ("sorcerer");
 set_name ("Shashara");

--More--(38%)
 set_gender ("female");

 set_skill ("concentrated casting", query_skill("concentrated casting")
+100);

 set_spell ("energy vortex", query_skill("energy vortex") +80);

 set_skill ("energy flow control", query_skill("energy flow control") +80);
 set_skill ("regenerative vortex", query_skill("regenerative vortex") +80);
 set_skill ("essence of true ritual", query_skill("essence of true
ritual")+100);
 set_skill ("reversed vortex", query_skill ("reversed vortex") +80);

 set_stat ("intelligence", query_stat("intelligence") +200);

 set_cps ("casting", query_cps("casting") +50);

 add_spell ("energy vortex","random", 0);

 add_spell ("energy vortex","reversed vortex", 0);

 set_chance (30,0);


 set_inquiry (
 ([
   "^help$" : "I will help you soon, when my creator figures all this
out.",
   "@demon" : "He is big and evil and you must kill him!",
   "$GREET" : "Go AWay! Im not finished yet.",
   "$DEFAULT" : "I do not have time for silly questions.",
   "@healing" : "heal_inquiry"
  ]));


 set_chat_chance (1);

 set_chat_output (
--More--(76%)
 ({
   "Shashara mutters: Its been to long..",
   "Shashara shouts: WHEN WILL IT END!",
 })
               );


 sorcshadow = new ("/d/guilds/sorcerer/shadows/sorc_shadow.c");
 sorcshadow -> move ( this_object(),1 );

 sorcshadow -> shadow_object(this_object());

 add_weapon ("d/guilds/sorcerer/obj/guild_ob");

}

void heal_inquiry() {

   force_me ( "cast energy vortex at regenerative vortex");
}

void second_life() {
 deep_inventory (this_object() ) ->remove();
}