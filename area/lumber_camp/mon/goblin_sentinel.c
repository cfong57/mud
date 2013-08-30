#include <mudlib.h>
#include <modules.h>

inherit MONSTER;
inherit M_REPUTATION;

void kill_treants(object target); 

void extra_init()
{
  string *ids;
  if (environment(this_object())) 
  {
    foreach (object o in all_inventory(environment(this_object()))) 
    { 
      ids = o->query_id();    
      if (member_array("t_ob", ids) != -1) 
      {
        if (o != this_object()) 
        {
          kill_treants(o);
          return;  
        }
      }
    }
  }
}

void extra_create()
{
  set_reputation("The Fellowship of Rangers", -18 - random(9));
  set_short("A goblin sentinel, standing guard");
  set_long(wrap("A rather plain-looking, but strong goblin stands guard here. "+
  "You wonder what she could be guarding against, but then remember the "+
  "horrific bloodshed you have seen earlier and immediately understand her "+
  "purpose. She is wearing some standard-issue armour and wielding an axe "+
  "that you think was intended for more than cutting down trees. The goblin "+
  "gives you an appraising look as you draw near.\n"));
  set_name("Goblin sentinel");
  set_id( ({ "Goblin sentinel, standing guard", 
  "goblin sentinel, standing guard", "goblin sentinel standing guard", 
  "goblin sentinel", "sentinel", "goblin guard", "goblin", "guard", "g_ob"}) );
  set_level(22);
  set_race("goblin");
  set_gender("female");
  set_agrochance(45);
  add_random_weapon("random_battle axe", 6, ({"left hand", "right hand" }));
  add_random_armour("random_scale mail_breastplate", 4);
  add_random_armour("random_ring mail_leggings", 4);
  add_random_armour("random_augmented chain mail_bracers", 4);
  add_random_armour("random_double chain mail_helmet", 4);
  set_following(0);
  set_inquiry(([
  "$GREET" : "Hullo, stranger! I am guard of lumberjack camp! We cuts down "+
  "trees for a living!\n",
  "$DEFAULT" : "Sorry, no know anything about that.\n",
  ({ "lumberjack", "lumberjacking", "cutting", "cut", "tree", 
  "trees", "lumber" }) :
  "We cuts down trees! Is lots of fun, more even than a fite! Heheehe!\n",
  ({ "Brant", "brant", "camp overseer", "overseer" }) :
  "We no like him much. He not very nice. Always scream at "+
  "us to work harder. He make me stand here on 'guard duty' and I no get to "+
  "cut down trees. Is no fun, I say you!\n",
  ({"tree spirit", "spirit"}) : 
  "Big scary spirit appear sometime! It very strong. Me "+
  "no like Brant, but he very strong. He drive back tree spirit...\n",
  ({"treant", "treants", "tree-treants"}) : "Tree-treants! Big living trees "+
  "that come and harrass us! We fite on site!\n"]));
  set_chat_output(({
  "The guard states to herself: I guarding against tree-treants.\n",
  "The guard mutters to herself: Must not let tree-treants pass.\n",
  "The guard eyes you guardedly.\n"}));
  set_att_chat_output( ({ "The sentinel squeaks, 'Dieee! Kehehehee!'\n"})); 
  set_chat_chance(3);
  set_blocking_dirs( (["tent" : "The goblin bars your entry, muttering, "+
  "'Must protect Master Brant...!'\n" ]) );
}

int special_hit(object target, int damage, string bodypart) 
{
  if (!random(15) && target) {
    message("damage", "The goblin SLAMS "+target->query_cap_name()+" with all "+
    "her might, causing "+objective(target)+" to reel in pain!\n",
    environment(target), target);
    message("damage", "The goblin SLAMS you with all her might, causing you "+
    "to reel in pain!\n", target);
    target->receive_damage(damage * 2, bodypart);
    return 1;
  }
  return 0;
}

void kill_treants(object target)
{
  force_me("say Ayaa, treant-tree! Me kill!");
  message("aggro", "The goblin sentinel grins maliciously and rushes "+
  "forward to attack "+target->query_cap_name()+"!\n",
  environment(this_player()), ({this_object(), target}));
  message("aggro", "The goblin sentinel grins maliciously and rushes "+
  "forward to attack you!\n", target);
  this_object()->kill_ob(target);
}