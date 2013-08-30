#include <mudlib.h>
#include <modules.h>
#include <move.h>

inherit MONSTER;
inherit M_REPUTATION;

int has_axe = 0;
void receive_axe(object axe);
void kill_goblins(object target);

void extra_init()
{
  string *ids;
  if (environment(this_object())) {
    foreach (object o in all_inventory(environment(this_object()))) { 
      ids = o->query_id();    
      if (member_array("g_ob", ids) != -1) {
        if (o != this_object()) {
          kill_goblins(o);
          return;     
        }
      }
    }
  }
}

void extra_create()
{
  set_reputation("The Fellowship of Rangers", 70 + random(20));
  set_short("Cichele, a dryad spirit");
  set_long(wrap("Cichele may be a dryad spirit, but she bears close "+
  "resemblence to a human, at least you think so. Her form seems to be "+
  "comprised of fluorescing, etheral green light surrounded by a shroud of "+
  "pale grey fog. She has an air of magic about her, and it would probably be "+
  "a bad idea to anger her. Cichele seems to be the guardian spirit of this "+
  "forest. You guess without too much difficulty that she is not pleased with "+
  "the lumberjacks cutting down the forest.\n"));
  set_name("cichele");
  set_id( ({ "Cichele", "cichele", "dryad", "tree spirit", "spirit", "t_ob"}) ); 
  set_species("undead");
  set_race("dryad");
  set_gender("female");
  add_object("/u/a/allanon/area/lumber_camp/obj/leaf");
  set_level(25);
  set_stat("size", 175);
  if (!random(7))
  { 
    set_agrochance(55);
    add_weapon("/u/a/allanon/area/lumber_camp/obj/crapier");
    add_weapon("/u/a/allanon/area/lumber_camp/obj/cstaff");
    set_stat("strength", query_stat("strength") + 5);
    set_stat("constitution", query_stat("constitution") + 3);
    set_skill("twin weapons", 70);
  } else {
    set_agrochance(75);
    add_random_weapon("random_quarterstaff", 6, ({"left hand", "right hand" }));
    force_me("wield quarterstaff in left hand,right hand");
    set_stat("intelligence", query_stat("intelligence") + 5);
    set_stat("wisdom", query_stat("wisdom") + 3);
    set_spell("call lightning", 65);
    set_spell("mana blast", 65);
    set_spell("storm", 65);
    set_spell("ice", 65);
    set_skill("concentrated casting", 65);
    set_skill("magic lore", 85);
    add_spell("call lightning", "random", 0, 1);
    add_spell("mana blast", "random", 0, 1);
    add_spell("storm of ice", "none", 0, 1);
    set_chance(100, 0);
  }
  set_chat_output(({
  "The spirit spies a goblin cutting down a tree, and quivers with rage.\n",
  "The spirit mutters to herself, 'I will kill that derro...' .\n",
  "A treant in the distance falls from a succession of axe blows. A single "+
  "tear falls from the eyes of Cichele.\n",
  "Cichele eyes the stone carefully, as if to make sure it's still there.\n"}));
  set_chat_chance(3);
  set_skin_data("type", "none");
  set_heartless(1);
  set_receive_object((["/u/a/allanon/area/lumber_camp/obj/gaxe" : 
  "receive_axe"]));
  set_inquiry(([
  "$GREET" : "greet_inquiry",
  ({ "cut", "cut down trees", "trees", "forest" }) :
  "Lately there have been goblins invading this forest and cutting down "+
  "my trees for wood. I cannot stand it, and yet I am powerless to do "+
  "anything about it! My duty is to guard the main tree...All I am able "+
  "to do is incite my treants to attack the lumber camp once in a while. "+
  "Of course, this is ultimately futile because the goblins just keep on "+
  "coming...Damn that derro!\n",
  ({ "evil derro", "derro", "Brant", "brant" }) :
  "I have seen a derro with a large axe strutting along with those "+
  "disgusting goblins. He must be their ringleader! Oh, how I would love to "+
  "give him a taste of my fury...But, I am bound to this tree. Perhaps "+
  "some day a kind adventurer would come along and slay him for me...That "+
  "would please me to no end. I'd even have a reward for them, too...\n",
  ({ "wrath", "fury" }) : 
  "I may not look very substantial, but I wasn't picked to be guardian of "+
  "the tree for nothing...It would be wise to think twice before "+
  "angering me!\n",
  ({"goblin", "goblins"}) :
  "Foul and disgusting creatures! I would not tolerate them here even if "+
  "they weren't cutting down trees. Sadly they seem to be easily "+
  "replacable workers, and I have trouble eliminating even just half of "+
  "them before more are carted in.\n",
  ({"stone", "amber"}) : "This stone is the source of all the tree's magic. "+
  "It's what has enabled it to grow so tall. The power of the "+
  "stone nourishes and sustains this forest. I protect not only this tree, "+
  "but its heart - the stone - as well.\n",
  "tree" : "This tree existed even before the Ice, and managed to survive "+
  "somehow. It is a very ancient and powerful relic, and you couldn't find "+
  "another to replace it anywhere else in this world.\n",
  "reward" : "The powers of nature are many and wondrous to behold, and "+
  "while I could not give you the full gifts of the forest, I believe a "+
  "magical item would suffice for an adventurer.\n"]));
}

void greet_inquiry()
{
  force_me("frown "+this_player()->query_name());
  force_me("say Are you here to cut down my trees, too? If you're working "+
  "for that evil derro, Brant, you should leave before I decide to vent my "+
  "wrath on you.");
}

void receive_axe(object axe)
{
  object ob;
  if (has_axe) {
    force_me("say Some kind person has already slaim the foul menace, Brant, "+
    "for us. I have no need for this.");
    axe->move(this_player(), 1);
    message("info", "Cichele gives back the axe.\n", this_player());
    message("info", "Cichele gives the axe back to "+
    ""+this_player()->query_cap_name()+".\n",
    environment(this_player()), this_player());
  } else {
    has_axe = 1;
    force_me("say The foul menace has been slain! I rejoice merrily...To show "+
    "my heartfelt gratitude, please take this!");
    axe->remove();
    message("info", "Cichele gives you an armour.\n", this_player());
    message("info", "Cichele gives an armour to "+
    ""+this_player()->query_cap_name()+".\n",
    environment(this_player()), this_player());
    ob = new("/u/a/allanon/area/lumber_camp/obj/boots.c");
    if (ob->move(this_player()) != MOVE_OK) {
      message("info", "You can't carry the armour and drop it on the ground.\n",
      this_player());
      message("info", ""+this_player()->query_cap_name()+" can't carry the "+
      "armour and drops it on the ground.\n",environment(this_player()),
      this_player());
      ob->move(environment(this_player()));
    } 
  }
}

void kill_goblins(object target)
{
  message("aggro", "Cichele quivers with rage and attacks "+
  ""+target->query_cap_name()+" without a moment of hesitation!\n",
  environment(this_object()));
  this_object()->kill_ob(target);
}