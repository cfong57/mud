#include <mudlib.h>
#include <modules.h>
#include <damage.h>

inherit MONSTER;
inherit M_REPUTATION;

void kill_mages(object target);

void extra_init()
{
  string guild;
  if (environment(this_object())) {
    foreach (object o in all_inventory(environment(this_object()))) { 
      guild = o->query_mainguild();    
      if (guild == "Mages of Valkor") {
        if (o != this_object()) {
          kill_mages(o);
          return;  
        }
      }
    }
  }
}

void extra_create()
{
  set_reputation("Guild of the Magi", -100 - random(50));
  set_short("Giliwyr, fallen High Priest of Magic");
  set_long(wrap("Giliwyr is dressed in a manner befitting an elemental priest "+
  "of the highest rank, but you don't recognize his outfit immediately - it "+
  "is the one worn by the Magic followers of old. You wonder why in the world "+
  "he would dress this way, unless he really was a priest of Magic...in which "+
  "case he must be extremely old. There is a gleam of insanity in his aged "+
  "eyes; you think that the death of his god finally cracked him. A powerful, "+
  "easily visible magic aura surrounds him, hissing and crackling with its "+
  "intense power. He looks to be a dangerous adversary indeed, and you don't "+
  "care to think of what would happen should he roam out of this forest.\n"));
  set_name("Giliwyr");
  set_id( ({ "Giliwyr", "giliwyr", "fallen high priest of magic", 
  "fallen priest", "high priest of magic", "high priest", "priest of magic", 
  "priest"}) );
  set_level(25);
  set_race("human");
  set_gender("male");
  set_agrochance(85);
  add_random_weapon("titanium_quarterstaff", 10,
  ({"left hand", "right hand" }));
  add_random_armour("ancient dragonscale_scale mail_robe", 10);
  set_skill("magic lore", 100);
  set_skill("concentrated casting", 65);
  set_skill("essence of true ritual", 65);
  set_skill("magic flow control", 65);
  set_skill("cast magical", 100); 
  set_skill("time manipulation", 65);  
  set_skill("plane manipulation", 65);
  set_spell("magic", 75);  
  set_spell("ball", 75);
  set_spell("large", 75);
  set_spell("small", 75);
  set_spell("haste", 65);
  add_spell("small ball of magic","random", 0, 1);
  add_spell("ball of magic", 0, 1);
  add_spell("large ball of magic","random", 0, 1);
  add_spell("haste", "me", 2);
  set_chance(100, 0);
  set_chat_output(({"Giliwyr dances around in a random pattern, performing "+
  "some obscure ritual you have no clue about.\n",
  "%^BOLD%^YELLOW%^Giliwyr sneers: Those spineless Mages of Valkor! They are "+
  "defectors, traiterous turncoats, ALL of them! They have turned from Okka, "+
  "and for that I shall SLAY them all! Bahahahha!...%^RESET%^\n",
  "Giliwyr's magical aura flashes violently as he uses his massive powers to "+
  "further feed the growing vortex.\n",
  "%^BOLD%^%^YELLOW%^Giliwyr howls: Think you can expel ME from the Order of "+
  "Mages, Aquail?! Think again! Once I have revived Okka we shall STRIKE you "+
  "down!! You and ALL your false brothers and sisters!%^RESET%^\n"})); 
  set_att_chat_output(({"Giliwyr cackles insanely as he fights you. His "+
  "dementia frightens you to the very core.\n"}));
  set_chat_chance(3);
  set_heartless(1);
  set_skin_data("type", "none");
  set_inquiry(([
  "$GREET": "greet_inquiry",
  "$DEFAULT" : "!cackle",
  "revival" : "Yess indeed! Here today, I, Giliwyr, devoted servant of the "+
  "Magic God Okka, am going to bring back His Holiness to Aegic! It is the "+
  "start of a new era! An era of MAGIC!!\n",
  "vortex" : 
  "The vortex of magical powers! It is the pathway through which I shall "+
  "summon Okka!\n",
  "altar" :
  "This is the very last remaining Altar dedicated to Okka! I must protect "+
  "it at all costs!\n",
  ({"Okka", "okka"}) : "Do not speak the God of Magic's name in vain!\n",
  ({"mage", "mages", "mages of valkor", "Mages of Valkor"}) : "AYYY! Don't "+
  "mention those slimeballs in my presence! I hate them, and I shall kill "+
  "them all, for turning from the teachings of Okka! Our God and Guide! His "+
  "Holiness! What do they do all day?! Sit around in dusty study halls and "+
  "practice spells! They do not even say their daily prayers to Okka, nor "+
  "do they even attempt to help revive them! Heretics! All must burn!\n",
  ({"Aquail", "aquail"}) : "aquail_inquiry"]) );
  set_alt_corpse("/u/a/allanon/area/lumber_camp/obj/blade.c");  
}

void greet_inquiry()
{
  force_me("cackle "+this_player()->query_name());
  force_me("say Ahahahahaha!...You're just in time for the revival, "+
  ""+this_player()->query_cap_name()+"! You are about to witness one of the "+
  "greatest events ever performed on the face of Aegic!");
}

void aquail_inquiry()
{
  force_me("eye "+this_player()->query_name()+" coldly");
  message("say","%^BOLD%^%^YELLOW%^Giliwyr utters in a low, icy, flat voice:"+
  " ...He will pay for what he has done. I shall slay him. Make no mistake "+
  "of that.%^RESET%^\n", environment(this_object()), this_object());
}

int special_hit(object target, int damage, string bodypart) 
{
  string t = target->query_cap_name();
  if (!random(20) && target) {
    message("damage", "Giliwyr makes a tight fist, closing his eyes for a "+
    "split second before punching the air in your direction.\n", target);
    message("damage", "Giliwyr makes a tight fist, closing his eyes for a "+
    "split second before punching the air in "+t+"'s direction.\n",
    environment(target), target);
    message("damage", "A strong wave of pure magical force knocks you over, "+
    "stunning you with its impact!\n", target);
    message("damage", "A strong wave of pure magical force knocks "+t+" over, "+
    "stunning "+objective(target)+" with its impact!\n",
    environment(target), target);
    target->receive_damage(damage * 0.5, bodypart);
    if (target->query_stunned()) {  
      target->add_stun_duration(5); 
    } else { 
      target->stun(10); 
    } 
    return 1;
  }
  return 0;
}

void second_life()
{
  deep_inventory(this_object())->remove();
  message("info", "Giliwyr gasps his dying breath, 'I--have failed you..."+
  "Okka...' before collapsing to the ground. His corpse begins to shine with "+
  "a bright light, before BURSTING out in a hundred directions. Afterwards "+
  "all that remains is a glowing magical blade.\n", environment(this_object())); 
}

void kill_mages(object target)
{
  force_me("say A mage DARES to defile this holy sanctuary?!");
  message("aggro", "Giliwyr flies at "+target->query_cap_name()+" in a "+
  "berserker rage, spittle flying from his frothing mouth!\n",
  environment(this_object()), target);
  message("aggro", "Giliwyr flies at you in a berserker rage, spittle "+
  "flying from his frothing mouth!\n", target);
  this_object()->kill_ob(target);
}