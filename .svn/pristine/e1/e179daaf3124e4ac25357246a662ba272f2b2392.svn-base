#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

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
  set_race("treant");
  set_reputation("The Fellowship of Rangers", 7 + random(8));
  set_chat_chance(3);
  set_gender("neuter");
  switch (random(10)) {
    case 0 .. 1:
    set_long(wrap("A living tree stands tall before you. To your best "+
    "reckoning it is an oak tree, but you can't quite be sure because of all "+
    "the moss hanging from it. The tree hardly moves at all; instead it seems "+
    "to be waiting silently, as if it was on some sort of guard duty. You "+
    "notice that the treant faces north at all times, so perhaps it is "+
    "watching the lumber camp.\n"));
    set_short("Awakened oak tree, a silent sentinel");
    set_name("oak treant");
    set_id(({"Awakened oak tree", "awakened oak tree", "awakened tree", 
    "awakened oak", "silent sentinel", "sentinel", "tree", "treant", "oak",
    "t_ob"}));  
    set_level(21 + random(2));
    set_agrochance(35);
    set_following(0);
    set_stat("size", 250);
    add_natural_weapon("branches", "bludgeoning", 1);
    natural_weapon_damage(35, "branches");
    set_hand_priorities(({"branches"})); 
    set_chat_output(({"The oak treant is absolutely silent.\n"}));
    break;
    case 2 .. 4:
    set_long(wrap("This treant seems to be a yew tree, but you're not enough "+
    "of an arborist yet to tell for sure. It has fairly thin, whippy branches "+
    "that could deal out considerable damage if swung at a high velocity. The "+
    "treant moves slowly but surely from place to place, and you think that "+
    "it is patrolling the area at random, watchful for invaders or "+
    "lumberjacks.\n"));
    set_short("Awakened yew tree, patrolling slowly");
    set_id(({"Awakened yew tree", "awakened yew tree", "awakened tree", 
    "awakened yew", "patrolling tree", "slowly patrolling tree", "treant",
    "tree", "yew", "t_ob"}));
    set_name("yew treant");
    set_level(19 + random(2));
    set_agrochance(45);
    set_speed(45 + random(15)); 
    set_stat("size", 220);
    add_natural_weapon("branches", "bludgeoning", 1);
    natural_weapon_damage(40, "branches");
    set_hand_priorities(({"branches"})); 
    set_chat_output(({"The yew treant patrols around slowly.\n"}));
    break;
    case 5 .. 6:
    set_long(wrap("This treant would appear to be an elm tree. It has old "+
    "scars scored deeply into its thick bark, probably from a lifetime of "+
    "combat. The treant still seems to be in good shape, though, and it could "+
    "hold its own along with the rest of them. You would think twice about "+
    "attacking it.\n"));
    set_short("An awakened elm tree");
    set_name("elm treant");
    set_id(({"Awakened elm tree", "awakened elm tree", "awakened elm",
    "awakened tree", "elm tree", "treant", "tree", "elm", "t_ob"}));
    set_level(17 + random(2));
    set_agrochance(45);
    set_following(35);
    set_speed(55 + random(15));
    set_stat("size", 300);
    add_natural_weapon("branches", "bludgeoning", 1);
    natural_weapon_damage(45, "branches");
    set_hand_priorities(({"branches"})); 
    set_chat_output(({"The elm treant looks quite intimidating.\n"})); 
    break;
    case 7 .. 9:
    set_long(wrap("A fairly thin-looking fir tree is before you. It seems to "+
    "be less suited for combat than its fellows, because of its relatively "+
    "fragile and flexible trunk. It doesn't really even have leaves, and it's "+
    "actually a bit of a pitiful sight compared to the majestic oaks and "+
    "other trees around here.\n"));
    set_short("Awakened fir tree, looking pitiful");
    set_name("fir treant");
    set_id(({"Awakened fir tree", "awakened fir tree", "awakened fir",
    "awakened tree", "fir tree", "tree", "treant", "pitiful looking fir",
    "pitiful looking tree", "fir", "t_ob"}));
    set_level(15 + random(2));
    set_agrochance(25);
    set_following(25);
    set_speed(35 + random(15)); 
    set_stat("size", 170);
    add_natural_weapon("branches", "bludgeoning", 1);
    natural_weapon_damage(20, "branches");
    set_hand_priorities(({"branches"})); 
    set_chat_output(({"The fir treant nearly falls over from a "+
    "strong gust of wind.\n"}));
    break;
  }
  set_att_chat_output( ({ "The treant attacks savagely, probably imagining "+
  "that its foes are goblins.\n" })); 
  set_skin_data("type", "none");
  set_heartless(1);
  add_object("/u/a/allanon/area/lumber_camp/obj/branch");
  set_friends( ({"/u/a/allanon/area/lumber_camp/mon/treants.c"}) ); 
  set_friend_message("The treant becomes enraged and attacks as one of its "+
  "comrades is endangered!");
  set_forbidden_rooms(({
  "/u/a/allanon/area/lumber_camp/rooms/bw",
  "/u/a/allanon/area/lumber_camp/rooms/storehouse",
  "/u/a/allanon/area/lumber_camp/rooms/river",
  "/u/a/allanon/area/lumber_camp/rooms/fsecret",
  "/u/a/allanon/area/lumber_camp/rooms/treetop"}));
}

void kill_goblins(object target)
{
  message("aggro", ""+this_object()->query_cap_name()+" quivers with rage "+
  "and attacks "+target->query_cap_name()+" without a moment of "+
  "hesitation!\n", environment(this_object()));
  this_object()->kill_ob(target);
}