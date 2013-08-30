/*
*   Zaltaiz notes:
*    regeob for allanon's bottle, basically a moderated vortex regeob
*    should work, haven't tested though (stripped the controlling shadow)
*    -Zal 020105
*/
#include <mudlib.h>
#include <daemons.h>
#include <damage.h>

inherit OBJECT;

int hp_bonus = 0;
int ep_bonus = 0;
int sp_bonus = 0;
int psp_bonus = 0;
int ticks = 10;
object caster;
    
void extra_create()
{
  set_short("A small %^BOLD%^%^GREEN%^vortex%^RESET%^ of energies");
  set_long(wrap("A small whirlpool-like %^BOLD%^%^GREEN%^vortex%^RESET%^ "+
  "rotates in midair before you. It seems to be absorbing the energies of the "+
  "environment and sending them out in soothing pulses. The shape of the "+
  "vortex is changing too constantly for you to discern much more than a "+
  "general conelike shape. Eerie green light seems to come from the vortex at "+
  "occasional intervals. Somehow you think that this is not quite the same "+
  "kind of vortex created by Sorcerers, yet it is very similar.\n"));
  set_name("%^BOLD%^%^GREEN%^vortex%^RESET%^");
  set_id(({"small vortex of energies", "small vortex", "vortex of energies", 
  "vortex", "regen_ob"}) );
  set_prevent_get(1);
  set_prevent_drop(1);
  set_value(0);
  set_light(100);
  set_special_long(1);
  call_out("is_vortex_present", 1);
}

void vortex_remove() 
{
  message("info", "The %^BOLD%^%^GREEN%^vortex%^RESET%^ suddenly starts to "+
  "grow smaller, and after a few feeble pulses it fades away into "+
  "nothingness.\n", environment(this_object()));    
  if (find_call_out("heal_all") != -1) {
    remove_call_out("heal_all");
  }
  destruct(this_object());
}


void calculate_bonus() 
{
  object c;
  c = this_player();
  hp_bonus = 16 + random(10) + (this_player()->query_level() / 10);
  ep_bonus = 16 + random(10) + (this_player()->query_level() / 10);
  sp_bonus = 16 + random(10) + (this_player()->query_level() / 10);
  psp_bonus = 16 + random(10) + (this_player()->query_level() / 10);    
  call_out("heal_all", 10);
}


void heal_all()
{
  object *foo;
  string *ids;
  int tim;
  if (!environment(this_object())) {
    return;
  }
  ticks--; 
  if (ticks < 1) {
    vortex_remove();
    return;    
  }
  tim = 30 - random(6);   
  foreach (object o in all_inventory(environment(this_object()))) { 
    ids = o->query_id();    
    if (member_array("campfire", ids) != -1) {
      if (o != this_object()) {
        message("info", "The %^BOLD%^%^GREEN%^vortex%^RESET%^ fades away at "+
        "the presence of the campfire.\n", environment(this_object()));
        destruct(this_object());
        return;    
      }
    }
  }
  
  foo = filter_array(all_inventory(environment(this_object())), (:living($1):));
  foreach(object ob in foo) {
    if((ob->query_species() == "undead") || (ob->query_summoned())) {
      continue;
    }
    if(!ob->query_uncon()) {
      message("healing","%^CYAN%^A soothing pulse of energy flows from the "+
      "%^RESET%^%^BOLD%^%^GREEN%^vortex%^RESET%^%^CYAN%^.%^RESET%^\n", ob);
      ob->receive_healing(hp_bonus);
      ob->receive_healing(sp_bonus, "sp");
      ob->receive_healing(ep_bonus, "ep");
      ob->receive_healing(psp_bonus, "psp");
    }
  }
  call_out("heal_all", tim);
}

void is_vortex_present()
{
  string *ids;
  if (!environment(this_object())) {
    return;
  }
  foreach (object o in all_inventory(environment(this_object()))) { 
    ids = o->query_id();    
    if (member_array("regen_ob", ids) != -1) {
      if (o != this_object()) {
        message("info","The already-present %^BOLD%^%^GREEN%^vortex%^RESET%^ "+
        "dims and fades at the presence of a new vortex.\n",
        environment(this_object()));
        destruct(this_object());
        return;     
      }
    }
  }
}