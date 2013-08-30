#include <mudlib.h>
#include <daemons.h>

inherit FOOD;

void extra_create()
{
  set_short("An ominous bottle %^BOLD%^<eerie glow>%^RESET%^");
  set_long(wrap("This strange bottle gives you chills just looking at it. It "+
  "is made out of some sort of soft, squishy material that you don't really "+
  "want to identify. You can't find any opening to the bottle; perhaps it "+
  "is meant to be ingested as is. Every couple of seconds or so, the bottle "+
  "seems to become very warm and then suddenly very cold in your hands, and "+
  "then returns to normal temperature. You have no clue what could be inside, "+
  "and for some reason don't really feel like finding out...\n"+
  "There is a label on the bottle that reads: 'Liquid Death'.\n"));
  set_id( ({ "ominous bottle", "bottle"}) );
  set_edible(1);
  set_food_value(-200);
  set_ep_value(-50);
  set_water_value(-200);
  set_mass(25);
  set_bulk(25);
  set_rot_time(0);
  set_value(5000 + random(5001));
  set_eat_func("eat_me");
}

void eat_me()
{
  object p = this_player();
  message("info", wrap("After ingesting the bottle, you feel an intense "+
  "%^BOLD%^PAIN%^RESET%^ run through every cell of your being! This was "+
  "a bad idea after all!\n"), p);
  message("info", wrap(""+p->query_cap_name()+" suddenly doubles over in "+
  "* %^BOLD%^PAIN%^RESET%^*!\n"), environment(p), p);
  switch (random(7))
  {
    case 0:
    message("poison", "%^BOLD%^%^BLUE%^", p);
    p->poison(35 + random(15), 30 + random(45), 10 + random(10), 1);
    message("poison", "%^RESET%^", p);
    break;
    case 1:
    message("fire", "%^BOLD%^%^RED%^", p);
    DAMAGE_D->add_special_state(p, "flame", 30 + random(90), 
    35 + random(15), p->choose_body_part());
    message("fire", "%^RESET%^", p);
    break;
    case 2:
    p->wound(p->choose_body_part(), 35 + random(15), "magical");
    break;
    case 3:   
    p->stun(30 + random(45));
    break;
    case 4:
    message("acid", "%^BOLD%^%^GREEN%^", p);
    DAMAGE_D->add_special_state(p, "acid", 30 + random(45), 
    35 + random(15), p->choose_body_part());
    message("acid", "%^RESET%^", p);
    break;
    case 5:
    message("frozen", "%^BOLD%^%^BLUE%^", p);
    DAMAGE_D->add_special_state(p, "frozen", 30 + random(45), 
    35 + random(15), p->choose_body_part());
    message("frozen", "%^RESET%^", p);
    break;
    case 6:
    message("psionic", "%^BOLD%^%^MAGENTA%^", p);
    DAMAGE_D->add_special_state(p, "psionic", 30 + random(45), 
    35 + random(15), p->choose_body_part());
    message("psionic", "%^RESET%^", p);
    break;
  }
  return;
}

int throw_hit_func(object target, object thrower, object thing_thrown) 
{
  message("hit", "The ominous bottle %^BOLD%^EXPLODES%^RESET%^ as it hits "+
  ""+target->query_cap_name()+", covering "+objective(target)+" in a foul "+
  "liquid that quickly absorbs into "+possessive(target)+" skin!\n",
  environment(target), target);
  message("hit", ""+thrower->query_cap_name()+"'s ominous bottle "+
  "%^BOLD%^EXPLODES%^RESET%^ as it hits you, covering you in a foul liquid "+
  "that quickly absorbs into your skin!\n", target);
  switch (random(7))
  {
    case 0:
    message("poison", "%^BOLD%^%^BLUE%^", target);
    target->poison(35 + random(15), 30 + random(45), 10 + random(10), 1);
    message("poison", "%^RESET%^", target);
    break;
    case 1:
    message("fire", "%^BOLD%^%^RED%^", target);
    DAMAGE_D->add_special_state(target, "flame", 30 + random(90), 
    35 + random(15), target->choose_body_part());
    message("fire", "%^RESET%^", target);
    break;
    case 2:
    target->wound(target->choose_body_part(), 35 + random(15), "magical");
    break;
    case 3:   
    target->stun(30 + random(45));
    break;
    case 4:
    message("acid", "%^BOLD%^%^GREEN%^", target);
    DAMAGE_D->add_special_state(target, "acid", 30 + random(45), 
    35 + random(15), target->choose_body_part());
    message("acid", "%^RESET%^", target);
    break;
    case 5:
    message("frozen", "%^BOLD%^%^BLUE%^", target);
    DAMAGE_D->add_special_state(target, "frozen", 30 + random(45), 
    35 + random(15), target->choose_body_part());
    message("frozen", "%^RESET%^", target);
    break;
    case 6:
    message("psionic", "%^BOLD%^%^MAGENTA%^", target);
    DAMAGE_D->add_special_state(target, "psionic", 30 + random(45), 
    35 + random(15), target->choose_body_part());
    message("psionic", "%^RESET%^", target);
    break;
  }
  thing_thrown->remove();
  return 0;
}

int throw_no_hit_func(object target, object thrower, object thing_thrown)
{
  message("miss", "The ominous bottle flies right past "+
  ""+target->query_cap_name()+", hitting the ground and breaking. The "+
  "contents quickly evaporate, leaving no trace at all.\n", environment(target),
  target);
  message("miss", ""+thrower->query_cap_name()+"'s ominous bottle misses and "+
  "hits the ground. It breaks, and the contents quickly evaporate, leaving no "+
  "trace at all.\n", target);
  target->kill_ob(thrower);
  thing_thrown->remove();
  return 0;
}