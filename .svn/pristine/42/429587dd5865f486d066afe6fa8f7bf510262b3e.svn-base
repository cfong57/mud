#include <mudlib.h>
#include <damage.h>
#include <move.h>

inherit WEAPON;

/* THIS WEAPON IS NOT OBTAINABLE. Once the monster wielding it dies, all its 
inventory is deleted, including this. While I would like to put this weapon
in the game some day, it's quite obviously overpowered as is, at least for the
area it spawns in. */

void extra_create()
{
  set_identified(1);
  set_short("Sapphire-studded longsword");
  set_id(({"longsword", "sapphire longsword", "sapphire-studded longsword",
  "sword"}));
  set_long(wrap("This longsword is made of flawless, transparent blue iceron. "+
  "The crossguard, hilt, and pommel are all studded with perfect sapphire "+
  "gems, each about the size of a nailhead. From time to time, some "+
  "%^BLUE%^blue%^RESET%^ flames burn along the length of the blade, but they "+
  "seem to absorb heat instead of giving it off. The entire sword emits a "+
  "freezing aura, creating a thin veil of frozen water wapor around it at "+
  "all times. It is almost impossible to touch the blade without freezing "+
  "yourself to its icy surface.\n"));
  set_name("sapphire-studded longsword");
  set_wtype("longsword");
  set_material("iceron");
  add_magic_property("resist cold", 5);
  add_magic_property("resist fire", 5);
  set_quality(65);
  weapon_setup();
}

string query_special_feature() 
{return "It has a chance of temporarily freezing the enemy.";} 

int special_hit(object target)
{
  object fshadow;
  object sshadow;
  object p = this_object()->query_user();
  if (!target->query_frozen()) {
  //don't want the effects to stack, already strong
    if (!random(10)) {
      message("freeze", "Your sapphire-studded longsword flashes brilliantly "+
      "with %^BLUE%^blue%^RESET%^ fire as it strikes "+
      ""+target->query_cap_name()+"! "+capitalize(subjective(target))+" is "+
      "temporarily frozen solid!\n", p);      
      message("freeze", ""+p->query_cap_name()+"'s sapphire-studded "+
      "longsword flashes brilliantly with %^BLUE%^blue%^RESET%^ fire as it "+
      "strikes "+target->query_cap_name()+"! "+
      ""+capitalize(subjective(target))+" is temporarily frozen solid!\n",
      environment(p), ({p, target}));
      message("freeze", ""+p->query_cap_name()+"'s sapphire-studded "+
      "longsword flashes brilliantly with %^BLUE%^blue%^RESET%^ fire as it "+
      "strikes you! You are temporarily frozen solid!\n", target);
      fshadow = new("/u/a/allanon/area/lumber_camp/shadows/freeze_shadow.c");
      fshadow->move(target, 1);
      fshadow->shadow_object(target);
      fshadow->start_me();
      sshadow = new("/obj/spells/silence_shadow", target); 
      sshadow->shadow_object(target);
      return 1;
    }
  }
  return 0;
} 
//makes glow stay blue
mixed * query_dtypes() 
{
  return ({COLD, 75, PHYSICAL, 25});
} 