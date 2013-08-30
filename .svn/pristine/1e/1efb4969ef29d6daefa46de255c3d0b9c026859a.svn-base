#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;
    
int maneuvering = 0;

int query_no_combat_kit() 
{ 
  return 1; 
}

void extra_create()
{
  object shadow;
  set_reputation("The Fellowship of Rangers", 100 + random(15));
  set_short("Tekalu, chitine ranger recluse");
  set_long(wrap("The ranger standing before you looks to be a fearful "+
  "adversary indeed. With four weapons, you imagine that he slices and dices "+
  "opponents with practiced ease. He backs away from you cautiously, almost "+
  "fearfully, when you look at him - perhaps he has a phobia of other "+
  "persons. His multifaceted eyes gleam brightly, but not quite with madness; "+
  "still, you are definitely sure he is possessed with something. It would be "+
  "prudent not to rouse this chitine's passionate emotions. He seems to be "+
  "extremely untrusting, and probably won't talk to anyone he doesn't think "+
  "he can confide in.\n"));
  set_name("Tekalu");
  set_id( ({ "Tekalu", "tekalu", "chitine ranger recluse", "chitine ranger", 
  "chitine recluse", "ranger recluse", "ranger", "recluse"}) );
  set_level(25);
  set_race("chitine");
  set_gender("male");
  set_agrochance(50);
  add_weapon("/u/a/allanon/area/lumber_camp/obj/falchion");
  add_weapon("/u/a/allanon/area/lumber_camp/obj/falchion");
  add_weapon("/u/a/allanon/area/lumber_camp/obj/falchion");
  add_weapon("/u/a/allanon/area/lumber_camp/obj/falchion");
  add_random_armour("random_standard_cap", 4);
  add_random_armour("random_standard_boots", 4);
  add_random_armour("random_standard_vest", 4);
  add_random_armour("random_standard_gloves", 4);
  add_random_armour("random_standard_bracers", 4);
  add_random_armour("random_standard_collar", 4);
  add_random_armour("random_standard_leggings", 4);
  set_skill("melee", 75);
  set_skill("slashing weapons", 70);
  set_skill("swords", 50);
  set_skill("dodge", 60);
  set_skill("block", 60);
  set_skill("avoid hits", 60);
  set_skill("cleave", 40);
  set_skill("light armours", 60);
  set_skill("concentrated attack", 35);
  set_skill("concentrated defence", 35);
  set_skill("weapon parry", 75);
  set_skill("offensive", 55);
  set_skill("combat sense", 35);
  set_skill("combat analysis", 50);
  set_skill("find weakness", 35);
  set_skill("contact reflexes", 60);
  set_skill("continuous assault", 48);
  set_skill("swing", 54);
  set_skill("whirling blades", 70);
  set_skill("bladesinging", 50);
  set_skill("offensive patterns", 60);
  set_skill("defensive patterns", 60);
  set_skill("improvised combinations", 50);
  set_skill("weapon parry", 75);
  set_skill("twin weapons", 75);
  set_inquiry(([
  "$GREET": "greet_inquiry",
  "$DEFAULT" : "I have no idea what you're talking about.\n",
  ({"@old home", "@home"}) :
  "This tree is my home. I'll do anything to protect it. Absolutely "+
  "anything! My last home was a beautiful oak tree ensconsed deep "+
  "within a lush green forest. But then the dreaded winter came, and the "+
  "snow...and the ice...They destroyed my tree! First it was the leaves, "+
  "then the bark, and finally the mighty trunk itself was cleaved in two "+
  "by frigid blasts of ice! I couldn't fight it. I couldn't do anything "+
  "to stop it...That is why I went on this quest.",
  "@quest" : 
  "After my home was destroyed I spent many years wandering the "+
  "valley desolutely, seeking another tree in which I might make myself a "+
  "home. But none were to be found, none that compared to my old oak. I "+
  "joined the rangers to better understand the nature of trees, so that I "+
  "might be more capable of finding a perfect one. Finally one day, I "+
  "stumbled upon this tree...",
  "@tree" :
  "This tree here is even more magnificent than my old oak. It must be at "+
  "least a hundred years older. I've made my home here because it's such a "+
  "well-protected tree. Have you seen all those treants outside and that "+
  "tree spirit up above? They will keep most people from even scratching "+
  "my home. I'm so happy living here...I just wish that I could get along "+
  "better with people, now. My years of silent wandering steeled me against "+
  "relations with people, any sort of people, no matter what race. The only "+
  "sort of folk I really trust anymore are Rangers, because I have gotten "+
  "to know them as I trained with them. And they would never, ever harm a "+
  "magnificent tree like this.",
  ({"@goblins", "@lumberjack", "@lumberjacks", "@goblin", "@brant", "@Brant",
  "@derro" }) : 
  "Bah, don't even mention that in my hearing! Those evil, foul, "+
  "disgusting, vile, damned creatures are the bane of trees everywhere! I "+
  "would make then pay - in - blood!...but I'm too afraid to leave my tree. "+
  "What if they cut it down when I'm away? No no, I mustn't let that "+
  "happen..."]) ); 
  /* Should get whirling blades.
  if (clonep(this_object())) {
    shadow = new("/d/guilds/ranger/shadows/ranger_battle_shadow.c");
    shadow->shadow_object(this_object());
  }
  */
  }

void greet_inquiry()
{
  force_me("eye "+this_player()->query_name());
  if (this_player()->query_mainguild() == "ranger") {
    force_me("whisper "+this_player()->query_name()+" Ah, a comrade at last! "+
    "I see that you are a member of the Rangers, "+
    ""+this_player()->query_cap_name()+". I only trust and talk to members of "+
    "the Rangers, now, after what happened to my old home...");
  } else {
    force_me("say "+this_player()->query_cap_name()+", eh? What do you "+
    "want with me?");
  }
}

int special_hit(object target)
{
  if (!random(20) && target) {
    message("fall", "Tekalu gets a mean look in his eye and pushes you off "+
    "the edge of the platform. You hang motionless for a second before you "+
    "begin the long fall downwards.\n", target);
    message("fall", "Tekalu gets a mean look in his eyes and pushes "+
    ""+target->query_cap_name()+" off the edge of the platform..."+
    ""+subjective(target)+" is suspended motionless for a split second before "+
    ""+subjective(target)+" starts the long fall downwards.\n",
    environment(target), target);
    target->move("/u/a/allanon/area/lumber_camp/rooms/tree_entrance.c");
    message("damage", "You finish falling and start hitting the ground. "+
    "*THUD*\n", target);
    message("damage", ""+target->query_cap_name()+" falls down from high "+
    "above and hits the ground with a *THUD*. Ouch!\n",
    environment(target), target);
    target->receive_damage(target->query_max_hp() / 2 - 
    random(target->query_hp() / 3));
  }
  if(maneuvering != 1 && 
  "/cmds/skills/whirling_blades"->start_maneuver(this_object()) == 1) {
    maneuvering = 1;
    call_out("maneuver", 4 + random(5));
  }
 return 1;
}

int maneuver()
{
  "/cmds/skills/whirling_blades"->do_maneuver(this_object());
  call_out("maneuver_again", 6 + random(7));
  return 1;
}

/* , "with singing blades" */

int maneuver_again()
{
  maneuvering = 0;
  return 1;
}