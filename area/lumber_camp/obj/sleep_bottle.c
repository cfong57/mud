#include <mudlib.h>
#include <move.h>

inherit FOOD;

void extra_create()
{
  set_short("A weird bottle, made of tree bark");
  set_long(wrap("What a strange object. It is made out of pieces of tree bark "+
  "glued together with resin in such a way that it is watertight. When you "+
  "shake it a bit, you can hear some sloshing inside - it contains some "+
  "liquid. A stopper made of another gob of resin keeps it shut tight. You "+
  "have a feeling that the bottle is too fragile to open. Maybe, since it "+
  "is made of all-organic materials, it is meant to be eaten instead...?\n"+
  "There is a label on the bottle that reads: 'Sleep'.\n"));
  set_id( ({ "weird bottle", "bottle"}) );
  set_edible(1);
  set_food_value(10);
  set_ep_value(10);
  set_water_value(10);
  set_mass(10);
  set_bulk(10);
  set_rot_time(0);
  set_value(5000);
  set_eat_func("eat_me");
}

void eat_me()
{
  object sleep;
  object p = this_player();
  if ( p->query_mainguild() == "Initiates of Temperance") { 
	//"blah blah blah Monks Don't Sleep blah blah blah"
    message("info", wrap("After ingesting the bottle, you feel a slowly "+
    "spreading warmth throughout your whole body and feel very "+
    "drowsy for a moment...but then the feeling fades and nothing "+
    "seems to happen. Weird.\n"), p); 
    message("info", wrap(""+p->query_cap_name()+" looks drowsy for a moment, "+
    "but nothing happens.\n"), environment(p), p);
  } else {
    message("info", wrap("After ingesting the bottle, you feel a slowly "+
    "spreading warmth throughout your whole body and feel very "+
    "drowsy for a moment...you can't keep your eyes open...\n"), p);
    message("info", wrap(""+p->query_cap_name()+" looks very sleepy...\n"),
    environment(p), p);
    sleep = new("/obj/sleepobj");
    sleep->set_camp_rating(10); 
    sleep->move(p, 1); 
    p->set_asleep(1); 
    //seems to work even if the player recently slept. weird.
  } 
}