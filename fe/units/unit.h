//unit.h - header file for all the data a unit could ever need

#define SUPPORTS "/u/a/allanon/fe/data/supports.c"
#define SUPPORT_TXT "/u/a/allanon/fe/data/support_text.c"
#define MAX_STATS "/u/a/allanon/fe/data/maximum_stats.c"
#define PROMO_GAINS "/u/a/allanon/fe/data/promotional_gains.c"
#define GEN_BASE_STATS "/u/a/allanon/fe/data/generic_base_stats.c"
#define CHAR_GROWTH_RATES "/u/a/allanon/fe/data/character_growth_rates.c"
#define GEN_GROWTH_RATES "/u/a/allanon/fe/data/generic_growth_rates.c"

//#define CHAR_BASE_STATS "/u/a/allanon/fe/data/character_base_stats.c"
//no point in making this, since each character has its own individual file

//each unit belongs to the player it is created for. enemy units have no owner,
//and friendly units belong to the respective player who is using them
object owner;

//for calculating distances and other stuff
int my_x;
int my_y;

//type of square I am standing on
string terrain;

mapping terrain_bonuses = (["defence" : 0, "avoid" : 0, "regen" : 0,
"condition" : 0, "resistance" : 0]);

//in fire emblem, the lowest level is level 1, and a unit can then level up 19
//times maximum to reach level 20. the 21st level is only available via
//promotion. after that they can level up another 19 times, to reach level 40.
//but...fire emblem "resets" the displayed level to 1 after promotion, and so
//someone at level 40 is really "level 20 promoted". fire emblem players 
//generally refer to level thusly: "x/y", with x being unpromoted levels and y
//being promoted levels. therefore, max level is "20/20". because this is the
//way both the game and the players refer to it, we will use that convention
//here as well
int unpromoted_level;
int promoted_level;
int promoted;
//there is no "int level" because that could be equal to either unpromoted level
//or promoted level, and it would just get confusing. instead, function
//query_level() decides which of those values to return

string unitname;
string class;
int experience;
int hp; //current hp
string affinity;
string condition;
object traveller;
int carrying;
string gender;

//for purposes of calculating movement:
//foot, armour, knight_a, knight_b, fighter, bandit, pirate, mage, flying,
//nomad, nomad_trooper
//for purposes of calculating effective bonus:
//armour, horse, dragon, flying, swordslayer, nergal
//other:
//morph
string *subtypes = ({});

object *inventory = ({});
object equipped;

//0 = no skill
//1 - 30 = E
//31 - 70 = D
//71 - 120 = C
//121 - 180 = B
//181 - 250 = A
//251+ = S
mapping wexp = (["swords" : 0, "axes" : 0, "lances" : 0, "bows": 0,
"light" : 0, "staves" : 0, "anima" : 0, "dark" : 0]);

//notes: recruitable characters start with the same stats always, except for
//ones that begin as enemies (hector hard mode only); bosses and NPCs also have
//fixed stats. generic enemies have somewhat randomized stats - there are
//generic base stats for each class, and generic growth rates as well. the same
//is true for arena-generated enemies, although they tend to be far stronger
//than the normal enemies (stat addition?) and wield stronger weapons based on
//the opponent's defences.

//recruitable characters use a different set of base stats and growth rates.

//promotional gains, maximum stats, and base stats are set in stone, these are 
//hard-coded values that never change during the game. therefore we can leave 
//their data in the respective data files.

//growth rates are also hard-coded, except for the afa's drops; however, since
//this header file has no way of knowing whether it will be used for a generic
//enemy or a recruitable character, there should be a mapping here for growth
//rates, which is set when the unit is created based on the data in either the
//generic growth rates or character growth rates databases.

int afas_drops = 0;

mapping growth_rates = (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0, 
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 0]);

//in fire emblem 7, a unit had EITHER strength OR magic; the stats were split
//in fire emblem 9 and 10. however, it's simpler to code as if all units had
//both stats and they were equivalent, and it also opens up more possibilities
//for new features in the future
mapping stats = (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0, 
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 0, "movement" : 0,
"constitution" : 0]);

//this is for temporary bonuses (or possibly penalties), for example +7 resist
//from using a Holy Water
mapping bonus_stats = (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0, 
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 0]);

//"unit" : points, e.g. "matthew" : 100
//0 - 79 = nothing
//80 - 159 = C
//160 - 239 = B
//240+ = A
mapping support_data = ([]);
mapping support_bonuses = (["attack" : 0, "accuracy" : 0, "avoid" : 0, 
"critical" : 0, "defence" : 0, "evade" : 0]);
object *allies = ({});
object *removelist = ({});
mapping support_partners = ([]);

void set_owner(object x)
{
  owner = x;	
}

object query_owner()
{
  return owner;	
}

void set_my_x(int x)
{
  my_x = x;	
}

void set_my_y(int y)
{
  my_y = y;	
}

int query_my_x()
{
  return my_x;	
}

int query_my_y()
{
  return my_y;	
}

void set_terrain(string str)
{
  terrain = str;	
}

string query_terrain()
{
  return terrain;	
}

void set_terrain_bonuses(mapping map)
{
  terrain_bonuses = map;	
}

void clear_terrain_bonuses()
{
  terrain_bonuses = (["defence" : 0, "avoid" : 0, "regen" : 0, "condition" : 0,
  "resistance" : 0]);	
}

mapping query_terrain_bonuses()
{
  return terrain_bonuses;	
}

int query_terrain_bonus(string bonus)
{
  return terrain_bonuses[bonus];
}

void set_unitname(string str)
{
  unitname = str;	
}

string query_unitname()
{
  return unitname;	
}

void set_unpromoted_level(int x)
{
  unpromoted_level = x;	
}

int query_unpromoted_level()
{
  return unpromoted_level;	
}

void set_promoted_level(int x)
{
  promoted_level = x;	
}

int query_promoted_level()
{
  return promoted_level;	
}

void set_promoted(int x)
{
  promoted = x;	
}

int query_promoted()
{
  return promoted;	
}

//for purposes of displaying level in status screens, and calculating exp
int query_level()
{
  if(query_promoted())
  {
    return query_promoted_level(); 
  }
  else
  {
    return query_unpromoted_level();	  
  }
}

void set_class(string str)
{
  class = str;	
}

string query_class()
{
  return class;	
}

void set_experience(int exp)
{
  experience = exp;	
}

int query_experience()
{
  return experience;	
}

//fire emblem 7 uses a different randomly generated number for each potential
//stat growth; if the number is LESS than the growth rate, +1 to that stat
//e.g. hp growth rate = 70%
//if hp_rand <= 29, then +1hp (random(100) returns 0..99)
string * level_up()
{
  int hp_rand = random(100);
  int str_mag_rand = random(100);
  int skill_rand = random(100);
  int speed_rand = random(100);
  int luck_rand = random(100);
  int defence_rand = random(100);
  int resistance_rand = random(100);
  mapping growth_rand = (["maxhp" : hp_rand, "strength" : str_mag_rand,
  "magic" : str_mag_rand, "skill" : skill_rand, "speed" : speed_rand, 
  "luck" : luck_rand, "defence" : defence_rand, 
  "resistance" : resistance_rand]);
  
  string *improved = ({});

  foreach(string stat in keys(growth_rand))
  {
    if(growth_rand[stat] < query_growth_rates(stat) && 
    query_stats(stat) < query_maximum_stats(stat))
    {
	  set_stats(stat, query_stats(stat) + 1);
	  improved += ({stat});
    }
  }
  if(query_promoted())
  {
    set_promoted_level(query_promoted_level() + 1);	  
  }
  else
  {
    set_unpromoted_level(query_unpromoted_level() + 1);	  
  }
  //need some way to tell the player what stats improved
  return improved;
}

string promote_me()
{
  set_unpromoted_level(1);
  set_promoted(1);
  string new_weapon;
  
  foreach(string stat in keys(query_stats()))
  {
    set_stats(stat, query_stats(stat) + query_promotional_gains(stat));
    if(query_stats(stat) > query_maximum_stats(stat))
    {
	  set_stats(stat, query_maximum_stats(stat));
    }
  }
  mapping temp = query_maximum_stats("wexp");
  foreach(string wep in keys(temp))
  {
	if(query_wexp(wep) == 0)
	{
	  new_weapon = wep;
	}
    add_wexp(wep, temp[wep]);
  }
  //"you can now use bows"
  return new_weapon;
}

//allow exp to accumulate past max level, just for fun
void add_experience(int exp)
{
  experience += exp;
  if(query_level() != 20)
  {
    if(experience == 100)
    {
      set_experience(0);
      level_up();  
    }
    else if(experience > 100)
    {
      set_experience(experience - 100);
      level_up();  
    }
  }
}

int query_class_power()
{
  int returnme;
  switch(query_class())
  {
    case "soldier":
    returnme = 2;
    break;
    case "thief":
    returnme = 2;
    break;
    default:
    returnme = 3;
    break;	  
  }
  return returnme;	
}

int query_class_bonus_a()
{
  if(query_promoted_level() > 0)
  {
    return 20;	  
  }
  else
  {
	return 0;
  }	
}

int query_class_bonus_b()
{
  int returnme;
  if(query_promoted_evel() > 0)
  {
    returnme = 0;	  
  }
  else
  {
    switch(query_class())
    {
	  case "assassin":
	  returnme = 40;
	  break;
	  case "valkyrie":
	  returnme = 40;
	  break;
	  case "bishop":
	  if(query_gender() == "female")
	  {
	    returnme = 40;	  
	  }
	  break;
	  default:
	  returnme = 60;
	  break;
    }
  }
  return returnme;
}

void calculate_experience(object enemy, int assassinated)
{
  int mode_coefficient = 1;
  int boss_bonus = 0;
  int thief_bonus = 0;
  float assassinate_coefficient = 0.0;
  
  
  if(enemy->query_boss())
  {
    boss_bonus = 40;	  
  }
  if(enemy->query_class() == "thief" || enemy->query_class() == "assassin")
  {
    thief_bonus = 20;	  
  }
  if(assassinated)
  {
    assassinate_coefficient = 1.8;	  
  }

  int exp_from_damage = (31 + 
  (enemy->query_level() + enemy->query_class_bonus_a()) - 
  (query_level() + query_class_bonus_a())) / query_class_power();
  
  int exp_from_base = ((enemy->query_level() * enemy->query_class_power()) +
  enemy->query_class_bonus_b()) - 
  (((query_level() * query_class_power()) + 
  query_class_bonus_b()) / mode_coefficient);
  
  //recalculate
  if(exp_from_base <= 0)
  {
    mode_coefficient = 2;
    exp_from_base = ((enemy->query_level() * enemy->query_class_power()) +
    enemy->query_class_bonus_b()) - 
    (((query_level() * query_class_power()) + 
    query_class_bonus_b()) / mode_coefficient);
  }
  
  float total_exp = (exp_from_damage + 
  (exp_from_base + 20 + boss_bonus + thief_bonus)) * assassinate_coefficient;
  
  if(mode_coefficient == 2)
  {
    total_exp = ceil(total_exp);	  
  }
  
  add_experience(to_int(total_exp));
}

void set_hp(int x)
{
  hp = x;	
}

int query_hp()
{
  return hp;	
}

void set_affinity(string affin)
{
  affinity = affin;	
}

string query_affinity()
{
  return affinity;
}

void set_condition(string cond)
{
  condition = cond;	
}

string query_condition()
{
  return condition;
}

void set_traveller(object trav)
{
  traveller = trav;	
}

void remove_traveller()
{
  traveller = 0;	
}

object query_traveller()
{
  return traveller;
}

void set_gender(string gen)
{
  gender = gen;	
}

string query_gender()
{
  return gender;	
}

void set_subtypes(string *types)
{
  subtypes = types;	
}

void add_subtype(string type)
{
  subtypes += ({type});	
}

string * query_subtypes()
{
  return subtypes;	
}

void set_inventory(object *obs)
{
  inventory = obs;	
}

void clear_inventory()
{
  foreach(object ob in inventory)
  {
    ob->remove();	  
  }
  inventory = ({});
}

int add_to_inventory(object ob)
{
  if(sizeof(inventory) < 5)
  {
    inventory += ({ob});
    return 1;	  
  }
  return 0;
}

void remove_from_inventory(object ob)
{
  inventory -= ({ob});
}

object * query_inventory()
{
  return inventory;	
}

//returns number of items in inventory with matching id
int held(string what)
{
  int quantity = 0;
  foreach(object ob in query_inventory())
  {
    if(ob->id(what))
    {
	  quantity++;
    }	  
  }
  return quantity;
}

int set_equipped(object ob)
{
  int returnme = 0;
  if(ob->query_is_weapon())
  {
    if(ob->query_preferred())
    {
	  if(query_unitname() == ob->query_preferred())
	  {
	    equipped = ob;
	    returnme = 1;
	  }
    }
    else if(ob->query_restricted())
	{
	  if(member_array(query_class(), query_restricted()) &&
	  wexp[ob->query_wtype()] > ob->query_rank())
	  {
		equipped = ob;
	    returnme = 1;    
	  }	  
	}
    else if(wexp[ob->query_wtype()] > ob->query_rank())
    {
	  equipped = ob;
	  returnme = 1;    
    }
  }
  return returnme;
}

object query_equipped()
{
  return equipped;	
}

void set_wexp(mixed arg1, int arg2)
{
  if(stringp(arg1) && arg2)
  {
    wexp[arg1] = arg2;
  }
  else if(mapp(arg1))
  {
    wexp = arg1;	  
  }
}

mixed query_wexp(string type)
{
  if(type)
  {
    return wexp[type];
  }
  else
  {
    return wexp;	  
  }
}

//allow weapon exp to accumulate past S rank, just for fun
int add_wexp(string type, int amount)
{
  int old_wexp = query_wexp(type);
  
  int have_s_rank = 0;
  if(query_class() != "archsage" && query_class() != "dark druid")
  {
    foreach(string wtype in keys(wexp))
    {
	  if(wexp[wtype] > 250)
	  {
	    have_s_rank++;	  
	  }
    }
  }
  wexp[type] += amount;
  //if already have one S rank and new total would give another S rank, top out
  if(have_s_rank > 0 && wexp[type] > 250)
  {
    wexp[type] = 250;
  }
  //unpromoted units can't get an S rank
  if(wexp[type] > 181 && query_promoted() == 0)
  {
    wexp[type] = 181;	  
  }
  
  int new_wexp = query_wexp(type);
  
  if((old_wexp <= 30 && new_wexp >= 31) || (old_wexp <= 70 && new_wexp >= 71) ||
  (old_wexp <= 120 && new_wexp >= 121) || 
  (old_wexp <= 180 && new_wexp >= 181) || (old_wexp <= 250 && new_wexp >= 251))
  {
    return 1; //return 1 if weapon skill increased to a new category  
  }
  else
  {
    return 0;
  }
}

void calculate_wexp(object weapon, int swings, int fatality, int indirect)
{
  int wx;
  wx = weapon->query_wexp() * swings;
  //runesword wexp always = 0
  //swings resulting in broken weapons give no exp - make sure to call this
  //function with correct number of valid swings

  //stop if light brand or wind sword used indirectly
  if(!indirect)
  {
    if(fatality)
    {
      wx = wx * 2;	  
    }	  
    add_wexp(weapon->query_wtype(), wx);
  }
}

void set_afas_drops(int x)
{
  afas_drops = x;	
}

//otherwise no way to tell what unit the item has been used on unless we wanted
//to compare the growth rates data with the hard-coded data, which is less
//efficient
int query_afas_drops()
{
  return afas_drops;	
}

void do_afas_drops()
{
  foreach(string stat in keys(query_growth_rates()))
  {
    set_growth_rates(stat, query_growth_rates(stat));  
  }
}

mixed query_promotional_gains(string stat)
{
  if(!stat)
  {
    return PROMO_GAINS->query_gains(query_class(), query_gender());
  }
  else
  {
    return PROMO_GAINS->query_gains(query_class(), query_gender())[stat];
  }
}

mixed query_maximum_stats(string stat)
{
  if(!stat)
  {
    return MAX_STATS->query_max_stats(query_class(), query_gender());	
  }
  else
  {
	return MAX_STATS->query_max_stats(query_class(), query_gender())[stat];
  }	
}

mixed query_base_stats(string stat)
{
  if(!stat)
  {
    return GEN_BASE_STATS->query_base_stats(query_class(), query_gender());
  }
  else
  {
    return GEN_BASE_STATS->query_base_stats(query_class(),
    query_gender())[stat];
  }
}

void set_growth_rates(mixed arg1, int arg2)
{
  if(mapp(arg1))
  {  
    growth_rates = map;
  }
  else if(stringp(arg1) && arg2)
  {
    growth_rates[arg1] = arg2;	  
  }
}

mixed query_growth_rates(string stat)
{
  if(!stat)
  {
    return growth_rates;	  
  }
  else
  {
    return growth_rates[stat];	  
  }
}

void set_stats(mixed arg1, int arg2)
{
  if(mapp(arg1))
  {
    stats = arg1;	  
  }
  else if(stringp(arg1) && arg2)
  {
    stats[arg1] = arg2;	  
  }
}

mixed query_stats(string stat)
{
  if(!stat)
  {
    return stats;	  
  }
  else if(stat == "luck" && member_array("morph", query_subtypes()))
  {
    return 0; //all morph units have a flat 0 luck
  }
  else
  {
    return stats[stat] + bonus_stats[stat];
  }
}

void set_bonus_stat(string stat, int amount)
{
  bonus_stats[stat] = amount;
}

void add_bonus_stat(string stat, int amount)
{
  bonus_stats[stat] += amount;	
}

void subtract_bonus_stat(string stat, int amount)
{
  bonus_stats[stat] -= amount;	
}

void set_bonus_stats(mapping map)
{
  bonus_stats = map;	
}

int query_bonus_stat(string stat)
{
  return bonus_stats[stat];
}

mapping query_bonus_stats()
{
  return bonus_stats;	
}

void reset_bonus_stats()
{
  bonus_stats = (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0, 
  "speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 0, "movement" : 0,
  "constitution" : 0]);
}

int * query_range()
{
  return query_equipped()->query_range();
}

void set_carrying(int x)
{
  carrying = x;
}

int query_carrying()
{
  return carrying;	
}

int query_attack_speed()
{
  int temp = query_equipped->query_weight() - query_stats("constitution");
  if(temp < 0)
  {
    temp = 0;	  
  }
  if(query_carrying())
  {
    return (query_stats("speed") / 2) - temp;	  
  }
  else
  {
    return query_stats("speed") - temp;
  }	
}

int wielding_brave()
{
  if(query_equipped()->query_brave())
  {
    return 1;	  
  }
  else
  {	
    return 0;
  }
}

int query_uncounterable()
{
  return query_equipped->query_uncounterable();
}

int number_of_attacks(object enemy)
{
  int num = 0;
  if(member_array(distance_to(enemy), query_range()))
  {  
    if(query_attack_speed() - enemy->query_attack_speed() >= 4)
    {
	  num = 2;
    }
    else
    {
      num = 1;	  
    }
    if(wielding_brave())
    {
      num = num * 2;	  
    }
  }
  return num;
}

//because these swords are SPECIAL
string light_brand_and_wind_sword_attack()
{
  int indirect = (query_stats("strength") / 2) + 
  query_equipped()->query_might() + query_support_bonus("attack");
  int direct = query_stats("strength") + query_equipped()->query_might() +
  query_support_bonus("attack");	  
  return ""+direct+" ("+indirect+" ranged)";	
}

int calculate_triangle_attack(object enemy)
{
  int effect = 0;
  
  //stupid light brand and wind sword
  if(query_equipped()->query_type() == "light brand")
  {
    if(distance_to(enemy) == 1)
    {
	  if(enemy->query_equipped()->query_wtype() == "lance")
	  {
		effect = -1;
	  }
	  if(enemy->query_equipped()->query_wtype() == "axe")
	  {
	    effect = 1;	  
	  }
    }
    else
    {
	  if(enemy->query_equipped()->query_wtype() == "anima")
	  {
		effect = -1;
	  }
	  if(enemy->query_equipped()->query_wtype() == "dark")
	  {
	    effect = 1;	  
	  }
    }
  }
  else if(query_equipped()->query_type() == "wind sword")
  {
    if(distance_to(enemy) == 1)
    {
	  if(enemy->query_equipped()->query_wtype() == "lance")
	  {
		effect = -1;
	  }
	  if(enemy->query_equipped()->query_wtype() == "axe")
	  {
	    effect = 1;	  
	  }	    
    }
    else
    {
	  if(enemy->query_equipped()->query_wtype() == "dark")
	  {
		effect = -1;
	  }
	  if(enemy->query_equipped()->query_wtype() == "light")
	  {
	    effect = 1;	  
	  }	    
    }
  }
  else 
  {
    if(enemy->query_equipped()->query_wtype() == 
    query_equipped()->query_strong_against())
    {
      effect = 1;
    }
    if(enemy->query_equipped()->query_wtype() == 
    query_equipped()->query_weak_against())
    {
      effect = -1;	  
    }  
   
    //reaver weapon = double bonus, except when both weapons are reaver
    int reavers = 0;
    if(enemy->query_equipped()->query_reaver())
    {
      reavers++;
    }
    if(query_equipped()->query_reaver())
    {
      reavers++;	  
    }
    if(reavers == 1)
    {
      effect = effect * 2;	  
    }
  }
  return effect;
}

int calculate_triangle_hit(object enemy)
{
  int effect = 0;
  
  //god I hate the light brand and wind sword
  if(query_equipped()->query_type() == "light brand")
  {
    if(distance_to(enemy) == 1)
    {
	  if(enemy->query_equipped()->query_wtype() == "lance")
	  {
		effect = -15;
	  }
	  if(enemy->query_equipped()->query_wtype() == "axe")
	  {
	    effect = 15;	  
	  }
    }
    else
    {
	  if(enemy->query_equipped()->query_wtype() == "anima")
	  {
		effect = -15;
	  }
	  if(enemy->query_equipped()->query_wtype() == "dark")
	  {
	    effect = 15;	  
	  }
    }
  }
  else if(query_equipped()->query_type() == "wind sword")
  {
    if(distance_to(enemy) == 1)
    {
	  if(enemy->query_equipped()->query_wtype() == "lance")
	  {
		effect = -15;
	  }
	  if(enemy->query_equipped()->query_wtype() == "axe")
	  {
	    effect = 15;	  
	  }	    
    }
    else
    {
	  if(enemy->query_equipped()->query_wtype() == "dark")
	  {
		effect = -15;
	  }
	  if(enemy->query_equipped()->query_wtype() == "light")
	  {
	    effect = 15;	  
	  }	    
    }
  }
  else 
  {
    if(enemy->query_equipped()->query_wtype() == 
    query_equipped()->query_strong_against())
    {
      effect = 15;
    }
    if(enemy->query_equipped()->query_wtype() == 
    query_equipped()->query_weak_against())
    {
      effect = -15;	  
    }  
   
    //reaver weapon = double bonus, except when both weapons are reaver
    int reavers = 0;
    if(enemy->query_equipped()->query_reaver())
    {
      reavers++;
    }
    if(query_equipped()->query_reaver())
    {
      reavers++;	  
    }
    if(reavers == 1)
    {
      effect = effect * 2;	  
    }
  }
  return effect;
}

int calculate_effective(object enemy)
{
  int effect = 1;
  foreach(string what in query_equipped()->query_slays())
  {
	if(!(enemy->held("delphi shield") && what == "flying"))
	{
      if(member_array(what, enemy->query_subtypes()))
      {
	    effect = 2;
      }
    }
  }
  return effect;
}

//if no enemy, return listed attack
int query_attack(object enemy)
{
  if(!enemy)
  {
    if(query_equipped()->query_type() == "runesword")
    {
	  return (query_stats("strength") / 2) + query_equipped()->query_might() +
	  query_support_bonus("attack");
    }
    else if(query_equipped()->query_type() == "magic")
    {
      return query_stats("magic") + query_equipped()->query_might() +
	  query_support_bonus("attack");    	  
    }
    else
    {
      return query_stats("strength") + query_equipped()->query_might() +
	  query_support_bonus("attack");	  
    }
  }
  else
  {
    int triangle = calculate_triangle_attack(enemy);
    int effective = calculate_effective(enemy);
    
    if(query_equipped()->query_type() == "runesword" ||
    (query_equipped()->query_type() == "light brand" 
    && distance_to(enemy) == 2) ||
    (query_equipped()->query_type() == "wind sword" 
    && distance_to(enemy) == 2))
    {
	  return (query_stats("strength") / 2) + ((query_equipped()->query_might() +
	  triangle) * effective) + query_support_bonus("attack");
    }
    else if(query_equipped()->query_type() == "magic")
    {
      return query_stats("magic") + ((query_equipped()->query_might() +
	  triangle) * effective) + query_support_bonus("attack");    	  
    }
    else
    {
      return query_stats("strength") + ((query_equipped()->query_might() +
	  triangle) * effective) + query_support_bonus("attack");	  
    }     
  }
}

int query_defence()
{
  return query_stats("defence") + query_support_bonus("defence") + 
  query_terrain_bonus("defence");
}

//different than staff avoid
int query_magic_defence()
{
  return query_stats("resistance") + query_support_bonus("defence") + 
  query_terrain_bonus("defence");	
}

void set_support_bonuses(mapping map)
{
  support_bonuses = map;	
}

void set_support_bonus(string bonus, int amount)
{
  support_bonuses[bonus] = amount;	
}

void clear_support_bonuses()
{
  support_bonuses = (["attack" : 0, "accuracy" : 0, "avoid" : 0, 
  "critical" : 0, "defence" : 0, "evade" : 0]);	
}

mapping query_support_bonuses()
{
  return support_bonuses;	
}

int query_support_bonus(string bonus)
{
  return to_int(support_bonuses[bonus]);	
}

mapping calculate_support_bonuses(object supporter)
{
  string my_affinity = query_affinity();
  string their_affinity = supporter->query_affinity();
  
  int level;
  switch(support_data[supporter->query_unitname()])
  {
    case 0..79:
    level = 0;
    break;
    case 80..159:
    level = 1;
    break;
    case 160..239:
    level = 2;
    break;
    default: //240+
    level = 3;
  }
  
  int attack = 0;
  int accuracy = 0;
  int avoid = 0;
  int critical = 0;
  int defence = 0;
  int evade = 0;
  
  mapping bonuses = (["attack" : attack, "accuracy" : accuracy, "avoid" : avoid,
  "critical" : critical, "defence" : defence, "evade" : evade]);
  
  switch(my_affinity)
  {
    case "fire":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    break;
    case "thunder":
    avoid += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    evade += 2.5 * level;
    break;
    case "wind":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    critical += 2.5 * level;
    evade += 2.5 * level;
    break;
    case "ice":
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    defence += 0.5 * level;
    evade += 2.5 * level;
    break;
    case "dark":
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    evade += 2.5 * level;
    break;
    case "light":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    break;
    case "anima":
    attack += 0.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    break;
  }
  switch(their_affinity)
  {
    case "fire":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    break;
    case "thunder":
    avoid += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    evade += 2.5 * level;
    break;
    case "wind":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    critical += 2.5 * level;
    evade += 2.5 * level;
    break;
    case "ice":
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    defence += 0.5 * level;
    evade += 2.5 * level;
    break;
    case "dark":
    accuracy += 2.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    evade += 2.5 * level;
    break;
    case "light":
    attack += 0.5 * level;
    accuracy += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    break;
    case "anima":
    attack += 0.5 * level;
    avoid += 2.5 * level;
    critical += 2.5 * level;
    defence += 0.5 * level;
    break;
  }
  return bonuses;
}

int distance_from(object unit)
{
  int x1 = query_my_x();
  int y1 = query_my_y();
  int x2 = unit->query_my_x();
  int y2 = unit->query_my_y();
  
  int xdistance = (x1 - x2);
  int ydistance = (y1 - y2);
  
  if(xdistance < 0)
  {
    xdistance = xdistance * -1;	  
  }
  if(ydistance < 0)
  {
    ydistance = ydistance * -1;	  
  }
  
  return xdistance + ydistance;
}

/*
TODO: fix this, since not using unit.c anymore, each character has their own
file...

for each map, put pieces in the room, then query room contents?

void update_support_bonuses()
{
  clear_support_bonuses();
  
  //first, get all units currently loaded
  allies = children("/u/a/allanon/fe/units/unit.c");
  removelist = ({});
  
  //next, put all units not in my map into another array
  foreach(object unit in allies)
  {
    if(unit->query_owner() != query_owner())
    {
	  removelist += ({unit});   
    }
  }
  
  //finally, subtract out all units not in my map from original array
  allies -= removelist;
  
  mapping temp = ([]);
  foreach(object unit in allies)
  {
    if(member_array(unit->query_unitname(), keys(support_data)))
    {
	  if(distance_from(unit) <= 3)
	  {
	    temp = calculate_support_bonuses(unit);
	    foreach(string key in keys(support_bonuses))
	    {
	      support_bonuses[key] += temp[key];
	    }
      }
    }	  
  }
}
*/

void set_support_data(mixed arg1, int arg2)
{
  if(mapp(arg))
  {
    support_data = map;
  }
  else if(stringp(arg1) && arg2)
  {
    support_data[arg1] = arg2;	  
  }
}

void set_support_partners(mixed arg1, mixed arg2, int arg3)
{
  if(mapp(arg1))
  {
    support_partners = arg1;	  
  }
  else if(stringp(arg1))
  {
    if(mapp(arg2))
    {
	  support_partners[arg1] = arg2;   
    }
    else if(intp(arg2) && arg3)
    {
      support_partners[arg1] = (["start" : arg2, "gain" : arg3]);
    }
  }
}

mixed query_support_data(string who)
{
  if(who)
  {
	return support_data[who];
  }
  else
  {
    return support_data;	  
  }	
}

mixed query_support_partners(string who)
{
  if(who)
  {
	return support_partners[who];
  }
  else
  {
    return support_partners;	  
  }	
}

int query_starting_support(string who)
{
  return support_partners[who]["start"];
}

int query_support_gain(string who)
{
  return support_partners[who]["gain"];
}

void add_support_points(string who)
{
  if(member_array(who, keys(support_partners)))
  {
    support_data[who] += query_support_gain(who);
  }
}

int calculate_s_bonus(object weapon)
{
  if(wexp[weapon->query_type()] >= 251)
  {
    return 5;
  }
  else
  {
    return 0;	  
  }
}

int calculate_crit_bonus()
{
  if(query_class() == "berserker" || query_class == "swordmaster")
  {
    return 15;	  
  }
  else
  {
	return 0;
  }
}

int query_crit(object enemy)
{
  if(query_equipped()->query_type() == "runesword" ||
  (query_equipped()->query_type() == "light brand" 
  && distance_to(enemy) == 2) ||
  (query_equipped()->query_type() == "wind sword" && distance_to(enemy) == 2))
  {
    return 0;	  
  }
  else
  {
    return query_equipped()->query_critical() + (query_stats("skill") / 2) +
    query_support_bonus("critical") + calculate_crit_bonus() +
    calculate_s_bonus(query_equipped());
  }
}

int query_assassinate(object enemy)
{
  int rate = 50;
  if(query_class() == "assassin")
  {
    if(enemy->query_boss())
    {
	  rate = 25;  
    }
    if(enemy->query_class() == "dragon")
    {
	  rate = 0;   
    }	  
  }
  return rate;
}

int query_backfire()
{
  return 31 - query_stats("luck");	
}

int query_steal(object enemy)
{
  if(sizeof(inventory) < 5)
  {
    if(query_stats("speed") >= enemy->query_stats("speed"))
    {
      return 1;  
    }
  }
  return 0;
}

//in real game, tactician bonus varies from +0 - +10 based on how well the
//player does on the previous map; but that would be a bitch and a half to code,
//so just use average value of +5
//flag - for critical evade; also equal to +0 - +10 in real game, but not
//bound by affinity, so just return +5 always
int calculate_tactician_bonus(int flag)
{
  if(!flag)
  {
    if(query_affinity() == query_owner()->query_affinity())
    {
      return 5;	  
    }
    else
    {
      return 0;	  
    }
  }
  else
  {
    return 5;	  
  }
}

//in real game, this stat is never shown, but it was in later games
//don't see any reason not to show it in the interface
int query_crit_evade()
{
  if(held("iron rune"))
  {
   	return 999;  
  }
  else
  {
    return query_stats("luck") + query_support_bonus("evade") + 
    calculate_tactician_bonus(1);
  }
}

//if no enemy, return listed hit
int query_hit(object enemy)
{
  if(!enemy)
  {
    return query_equipped()->query_hit() + (query_stats("skill") * 2) +
    (query_stats("luck") / 2) + query_support_bonus("accuracy") + 
    calculate_s_bonus(query_equipped()) + calculate_tactician_bonus();
  }
  else
  {
    return query_equipped()->query_hit() + (query_stats("skill") * 2) +
    (query_stats("luck") / 2) + query_support_bonus("accuracy") + 
    calculate_s_bonus(query_equipped()) + calculate_tactician_bonus() +
    calculate_triangle_hit(enemy); 	  
  }
}

int query_staff_hit()
{
  return 30 + (query_stats("magic") * 5) + query_stats("skill");
}

void calculate_terrain_bonuses()
{
  int defence = 0;
  int avoid = 0;
  int regen = 0;
  int condition = 0;
  int resistance = 0;
  switch(query_terrain())
  {
	case "sand":
	avoid = 5;
	break;
	case "desert":
	avoid = 5;
	break;
    case "house":
    avoid = 10;
    break;
    case "shop":
    avoid = 10;
    break;
    case "arena":
    avoid = 10;
    break;
    case "village":
    avoid = 10;
    break;
    case "ruins" :
    avoid = 10;
    break;
    case "sea":
    avoid = 10;
    break;
    case "lake":
    avoid = 10;
    break;
    case "forest":
    defence = 1;
    avoid = 20;
    break;
    case "pillar":
    defence = 1;
    avoid = 20;
    break;
    case "mountain":
    defence = 1;
    avoid = 30;
    break;
    case "fort":
    defence = 2;
    avoid = 20;
    regen = 0.2;
    break;
    case "gate":
    defence = 2;
    avoid = 20;
    regen = 0.1;
    break;
    case "throne":
    defence = 2;
    avoid = 20;
    regen = 0.1;
    condition = 1;
    resistance = 5;
    break;
    case "peak":
    defence = 2;
    avoid = 40;
    break;
    default:
    break;
  }
  if(member_array("flying", subtypes))
  {
    defence = 0;
    avoid = 0;
    resistance = 0;
    condition = 0;	  
  }
  set_terrain_bonuses(([
  "defence" : defence, "avoid" : avoid, "regen" : regen,
  "condition" : condition, "resistance" : resistance]));
}

int query_staff_avoid(object enemy)
{
  return (query_stats("resistance") * 5) + (distance_from(enemy) * 2);
}

int query_avoid()
{
  return (query_attack_speed() * 2) + query_stats("luck") + 
  query_support_bonus("avoid") + query_terrain_bonus("avoid") + 
  calculate_tactician_bonus();
}

int query_aid()
{
  if(member_array("mounted", subtypes) || member_array("flying", subtypes))
  {
    if(query_gender() == "male")
    {
	  return 25 - query_stats("constitution");
    }
    else
    {
	  return 20 - query_stats("constitution");
    }	  
  }
  else
  {
    return query_stats("constitution") - 1;
  }
}