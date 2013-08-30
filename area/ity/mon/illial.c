#include <mudlib.h>
#include <move.h>

inherit MONSTER;

int total = 0;
object rope;
object container;

int query_total()
{
  return total;	
}

void make_rope()
{
  force_me("say Thanks for your business, hon. Here's the rope, as promised");
  rope = new("/std/riding/obj/rope.c");
  rope->move(this_object(),1);
  force_me("drop rope");
}

void receive_box(object box)
{
  box->calculate_totals();
  total += box->query_total_value();
  deep_inventory(box)->remove();
  box->remove();
  force_me("nodnod");
  if(total >= 30000)
  {
    make_rope();
    total = 0;	  
  }
}

void extra_create()
{
  set_short("Illial, beguiling ghost of an adventurer");
  set_long(wrap("Before you stands the ghost of a young human female of "+
  "perhaps 18 years. She has blonde hair tied back in a ponytail that reaches "+
  "almost to her waist, and she is garbed in some very tight leathers which "+
  "leave nothing to the imagination. However, you do note the large "+
  "executioner's sword held in her hands; this girl clearly knows how to "+
  "defend herself, and there is a definite aura of danger around her that "+
  "belies her age. Illial doesn't seem to be in any hurry to leave this room. "+
  "In fact, given the way she reclines absentmindedly on the heap of stones, "+
  "you almost get the feeling that she has been waiting here for others to "+
  "come by. You notice that there are many ropes sticking out of Illial's "+
  "pack. Maybe she would sell you one?\n"));
  set_name("Illial");
  set_living_name("illial"); 
  set_id( ({"illial", "beguiling ghost of an adventurer", "human", "undead"
  "beguiling adventurer", "ghost adventurer", "adventurer", "ghost"}) );
  set_level(75);
  set_race("human");
  set_species("undead");
  set_gender("female");
  //set_receive_object( (["/std/coins" : "receive_coins" ]) ); DOESN'T WORK
  set_receive_object( (["/u/a/allanon/area/ity/obj/box" : "receive_box" ]) );
  set_following(0);
  set_combat_kit("fighter 5");
  set_agrochance(100);
  add_random_stuff(20);
  add_object("/std/riding/obj/rope.c");
  add_object("/obj/misc/maps/monster_map.c");
  add_object("/std/enchant_skill_item.c");
  add_object("/std/enchant_item.c");
  add_weapon("/u/a/allanon/area/ity/obj/heavens_edge.c", 
  ({"left hand", "right hand" }));
  add_random_armour("gold_full plate_earrings", 10);
  add_random_armour("gold_full plate_necklace", 10);
  add_random_armour("leather_standard_cloak", 10);
  add_random_armour("leather_standard_gloves", 10);
  add_random_armour("leather_standard_tights", 10);
  add_random_armour("leather_standard_boots", 10);
  add_random_armour("gold_full plate_ring", 10);
  add_random_armour("gold_full plate_ring", 10);
  add_random_armour("leather_standard_coat", 10);
  set_skin_data(([ "skin_value": 30000,"skin_type": "leather","skin_bonuses": 
  ([]) ]));
  set_chat_output(({
  "Illial yawns and stretches, pulling her already-tight leathers even "+
  "thinner. You can't help but stare.\n",
  "Illial scuffs the floor with the heel of her boot, looking bored.\n",
  "Illial nonchalantly flips a mithril coin...it comes up heads.\n",
  "Illial nonchalantly flips a mithril coin...it comes up tails.\n"}));
  set_chat_chance(5);
  set_inquiry(([
  "$GREET" : "greet_inquiry",
  ({ "sex", "fuck", "sleep", "porn", "strip", "cunt"/*, etc...*/ }) :
  "dirty_inquiry",
  "discipline" : "discipline_inquiry",
  "treasure" : "My treasure senses are tingling. I'd bet you anything that "+
  "something is at the top of this tower. Too bad the stairway is out, huh? "+
  "Lucky for you, I have some rope here in my pack...\n",
  "help" :"Huhu...what kind of 'help' did you need, darling...\n",
  ({ "rope", "buy", "sell"}) : "That's right, love. I'm carrying all sorts of "+
  "ropes, and you can have one for 30000 silver. Good for all your tying "+
  "needs...and then some. You just hand over a 'box' with 30000 worth of "+
  "coins inside and I'll get you all set up...I don't give change, but I'll "+
  "tell you my 'total' if you want. *giggle*\n",
  "box" : "box_inquiry",
  "total" : "total_inquiry",
  "$DEFAULT" : "default_inquiry"]));
  set_att_chat_output( ({ "Illial laughs maniacally as blood spatters "+
  "everywhere. 'Isn't it glorious?'\n",
  "Illial takes advantage of a momentary pause in combat to lick some blood "+
  "off herself. She smiles wickedly.\n",
  "Illial whispers hornily, 'Harder...'\n"}));
}

void greet_inquiry()
{
  force_me("tkiss "+this_player()->query_name());
  force_me("say Mmm...and hello, "+this_player()->query_cap_name()+". What's "+
  "a fellow adventurer like you doing here? Looking for treasure, perhaps? "+
  "Maybe I can help...");
}

void dirty_inquiry()
{
  force_me("slap illial butt sexily");
  force_me("say You're such a naughty little thing, "+
  ""+this_player()->query_cap_name()+". Don't make me discipline you...");
}

void discipline_inquiry()
{
  force_me("moan sensually");
  force_me("say Uuuh...you want it that badly, huh? Come and get it...");
  message("danger","Illial slowly raises her executioner's sword and licks "+
  "its razor-sharp edge. She gets a wild gleam in her eyes as a trickle of "+
  "blood runs down her chin. You suddenly lose all libido and decide to "+
  "back away from the crazy bitch.\n"+
  "...or do you?\n",environment(this_object()));
  set_hp(query_max_hp() * 0.95);
}

void default_inquiry()
{
  force_me("giggle naughtily");
  message("whoa","You can't help but notice the way Illial's chest jiggles "+
  "when she laughs.\n",environment(this_object()));	
}

void box_inquiry()
{
  force_me("say I only accept payments that come in these special boxes. You "+
  "can have one...*wink*");
  container=new("/u/a/allanon/area/ity/obj/box.c");
  container->move(this_object(),1);
  force_me("give box to "+this_player()->query_name()+"");
}

void total_inquiry()
{
  force_me("say Well, baby, I currently have "+query_total()+" silvers worth "+
  "of money. Looks like you'll need a little more, huh...");
}
  
void second_life() 
{
  force_me("say Where there is light, there is darkness...at least make use "+
  "of me...");
}