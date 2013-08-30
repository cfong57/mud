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
  set_reputation("The Fellowship of Rangers", 18 + random(9));
  set_short("Tall birch treant, standing guard");
  set_long(wrap("This birch treant is impressively tall and massive. It looks "+
  "quite strong, and you wouldn't want to fight it. Many deep cuts and "+
  "amputated branches give evidence to past battles. The treant seems to be "+
  "guarding the way to the top of the tree, so that no goblins can "+
  "approach the heart of the forest.\n"));
  set_name("Birch treant");
  set_id( ({ "tall birch treant", "tall birch", "tall treant", "guard", "birch", 
  "treant", "tree"}));
  set_level(22);
  set_race("treant");
  set_stat("size", 400);
  set_gender("neuter");
  set_agrochance(45);
  set_following(0);
  add_object("/u/a/allanon/area/lumber_camp/obj/branch");
  add_natural_weapon("branches", "bludgeoning", 1);
  natural_weapon_damage(85, "branches");
  set_hand_priorities(({"branches"}));
  set_skin_data("type", "none");
  set_heartless(1); 
  set_chat_output(({
  "The birch treant patiently stands guard, not moving or making a sound.\n"}));
  set_att_chat_output( ({ "The birch treant fights savagely, doing its utmost "+
  "to protect the forest.\n"})); 
  set_chat_chance(3);
  set_blocking_dirs( (["stairway" : "The birch treant blocks your passage. "+
  "You could almost swear that it 'shakes its head' at you in denial.\n"   ]) );
}

int special_hit(object target, int damage, string bodypart) 
{
  if (!random(15) && target)
  {
    message("damage", "The treant slams mightily with its branches, sending "+
    ""+target->query_cap_name()+" flying before "+subjective(target)+" "+
    "crashes sickeningly to the ground.\n", environment(target), target);
    message("damage", "The treant slams mightily with its branches, sending "+
    "you flying through the air before you crash sickeningly to the ground.\n",
    target);
    target->receive_damage(damage * 2, bodypart);
    return 1;
  }
  return 0;
}

void kill_goblins(object target)
{
  message("aggro", "Birch treant quivers with rage and attacks "+
  ""+target->query_cap_name()+" without a moment of hesitation!\n",
  environment(this_object()), ({this_object(), target}));
  message("aggro", "Birch treant quivers with rage and attacks "+
  "you without a moment of hesitation!\n",target);
  this_object()->kill_ob(target);
}