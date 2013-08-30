//generic_growth_rates.c
//database of the growth rates for generic enemies
//even the recruitable character-specific classes have data here...just in case
//we ever wanted to make enemies of them
//also, as far as I'm aware, every generic enemy in the game is male (for
//classes that support both genders), so I assume they all use the male growth
//rates...not that they are significantly different anyway
//note: fe7 doesn't have data for female versions of some classes, so I'm
//adding those in using fe8 data

mapping growths = ([
"archer" : (["female" : (["maxhp" : 70, "strength" : 35, "magic" : 35,
"skill" : 40, "speed" : 32, "luck" : 35, "defence" : 15, "resistance" : 20]),
"male" : (["maxhp" : 70, "strength" : 35, "magic" : 35, "skill" : 40, 
"speed" : 32, "luck" : 35, "defence" : 15, "resistance" : 15])]),
"archsage" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30,
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 35]),
"assassin" : (["female" : (["maxhp" : 50, "strength" : 5, "magic" : 5,
"skill" : 45, "speed" : 40, "luck" : 40, "defence" : 5, "resistance" : 20]),
"male" : (["maxhp" : 50, "strength" : 5, "magic" : 5, "skill" : 45, 
"speed" : 40, "luck" : 40, "defence" : 5, "resistance" : 20])]),
"bard" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30,
"speed" : 60, "luck" : 70, "defence" : 0, "resistance" : 13]),
"berserker" : (["maxhp" : 75, "strength" : 50, "magic" : 50, "skill" : 35,
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 13]),
"bishop" : (["female" : (["maxhp" : 45, "strength" : 35, "magic" : 35,
"skill" : 25, "speed" : 22, "luck" : 40, "defence" : 8, "resistance" : 50]),
"male" : (["maxhp" : 45, "strength" : 35, "magic" : 35, "skill" : 25, 
"speed" : 22, "luck" : 40, "defence" : 8, "resistance" : 40])]),
"blade lord" : (["maxhp" : 90, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 12]),
"brigand" : (["maxhp" : 82, "strength" : 50, "magic" : 50, "skill" : 30,
"speed" : 20, "luck" : 15, "defence" : 10, "resistance" : 13]),
"cavalier" : (["female" : (["maxhp" : 75, "strength" : 35, "magic" : 35,
"skill" : 40, "speed" : 28, "luck" : 30, "defence" : 15, "resistance" : 15]),
"male" : (["maxhp" : 75, "strength" : 35, "magic" : 35, "skill" : 40, 
"speed" : 28, "luck" : 30, "defence" : 15, "resistance" : 15])]),
"civilian" : (["maxhp" : 10, "strength" : 0, "magic" : 0, "skill" : 0,
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 10]),
"cleric" : (["maxhp" : 50, "strength" : 30, "magic" : 30, "skill" : 35,
"speed" : 32, "luck" : 45, "defence" : 8, "resistance" : 50]),
"corsair" : (["maxhp" : 75, "strength" : 50, "magic" : 50, "skill" : 35,
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 13]),
"dancer" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30,
"speed" : 60, "luck" : 70, "defence" : 0, "resistance" : 13]),
"dark druid" : (["maxhp" : 45, "strength" : 55, "magic" : 55, "skill" : 30,
"speed" : 25, "luck" : 20, "defence" : 10, "resistance" : 35]),
"druid" : (["female" : (["maxhp" : 45, "strength" : 55, "magic" : 55,
"skill" : 30, "speed" : 25, "luck" : 20, "defence" : 10, "resistance" : 35]),
"male" : (["maxhp" : 45, "strength" : 55, "magic" : 55, "skill" : 30, 
"speed" : 25, "luck" : 20, "defence" : 10, "resistance" : 35])]),
"falcoknight" : (["maxhp" : 60, "strength" : 30, "magic" : 30, "skill" : 30,
"speed" : 30, "luck" : 30, "defence" : 12, "resistance" : 30]),
"fighter" : (["maxhp" : 85, "strength" : 55, "magic" : 55, "skill" : 35,
"speed" : 30, "luck" : 15, "defence" : 15, "resistance" : 15]),
"fire dragon" : (["maxhp" : 95, "strength" : 40, "magic" : 40, "skill" : 30,
"speed" : 20, "luck" : 25, "defence" : 0, "resistance" : 20]),
"general" : (["female" : (["maxhp" : 75, "strength" : 30, "magic" : 30,
"skill" : 25, "speed" : 10, "luck" : 20, "defence" : 23, "resistance" : 25]),
"male" : (["maxhp" : 75, "strength" : 30, "magic" : 30, "skill" : 20, 
"speed" : 10, "luck" : 20, "defence" : 23, "resistance" : 25])]),
"great lord" : (["maxhp" : 90, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 20]),
"hero" : (["female" : (["maxhp" : 75, "strength" : 30, "magic" : 30,
"skill" : 30, "speed" : 20, "luck" : 25, "defence" : 20, "resistance" : 20]),
"male" : (["maxhp" : 75, "strength" : 30, "magic" : 30, "skill" : 30, 
"speed" : 20, "luck" : 25, "defence" : 20, "resistance" : 20])]),
"knight" : (["female" : (["maxhp" : 80, "strength" : 40, "magic" : 40,
"skill" : 30, "speed" : 15, "luck" : 25, "defence" : 28, "resistance" : 20]),
"male" : (["maxhp" : 80, "strength" : 40, "magic" : 40, "skill" : 30, 
"speed" : 15, "luck" : 25, "defence" : 238 "resistance" : 20])]),
"knight lord" : (["maxhp" : 90, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 15]),
"lord_eliwood" : (["maxhp" : 90, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 15]),
"lord_hector" : (["maxhp" : 90, "strength" : 45, "magic" : 45 "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 12]),
"lord_lyn" : (["maxhp" : 90, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 45, "luck" : 40, "defence" : 15, "resistance" : 20]),
"mage" : (["female" : (["maxhp" : 55, "strength" : 55, "magic" : 55,
"skill" : 40, "speed" : 35, "luck" : 20, "defence" : 5, "resistance" : 40]),
"male" : (["maxhp" : 55, "strength" : 55, "magic" : 55, "skill" : 40, 
"speed" : 35, "luck" : 20, "defence" : 5, "resistance" : 30])]),
"magic seal" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30,
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 35]),
"mercenary" : (["female" : (["maxhp" : 80, "strength" : 40, "magic" : 40,
"skill" : 40, "speed" : 32, "luck" : 30, "defence" : 18, "resistance" : 30]),
"male" : (["maxhp" : 80, "strength" : 40, "magic" : 40, "skill" : 40, 
"speed" : 32, "luck" : 30, "defence" : 18, "resistance" : 20])]),
"monk" : (["maxhp" : 50, "strength" : 30, "magic" : 30, "skill" : 35,
"speed" : 32, "luck" : 45, "defence" : 8, "resistance" : 40]),
"myrmidon" : (["female" : (["maxhp" : 70, "strength" : 35, "magic" : 35,
"skill" : 40, "speed" : 40, "luck" : 30, "defence" : 15, "resistance" : 20]),
"male" : (["maxhp" : 70, "strength" : 35, "magic" : 35, "skill" : 40, 
"speed" : 40, "luck" : 30, "defence" : 15, "resistance" : 20])]),
"nomad trooper" : (["female" : (["maxhp" : 60, "strength" : 25, "magic" : 25,
"skill" : 30, "speed" : 35, "luck" : 25, "defence" : 15, "resistance" : 20]),
"male" : (["maxhp" : 60, "strength" : 25, "magic" : 25, "skill" : 30, 
"speed" : 35, "luck" : 25, "defence" : 15, "resistance" : 15])]),
"nomad" : (["female" : (["maxhp" : 65, "strength" : 30, "magic" : 30,
"skill" : 40, "speed" : 45, "luck" : 30, "defence" : 12, "resistance" : 15]),
"male" : (["maxhp" : 65, "strength" : 30, "magic" : 30, "skill" : 40, 
"speed" : 45, "luck" : 30, "defence" : 12, "resistance" : 15])]),
"paladin" : (["female" : (["maxhp" : 70, "strength" : 25, "magic" : 25,
"skill" : 35, "speed" : 25, "luck" : 25, "defence" : 12, "resistance" : 25]),
"male" : (["maxhp" : 70, "strength" : 25, "magic" : 25, "skill" : 30, 
"speed" : 18, "luck" : 25, "defence" : 12, "resistance" : 20])]),
"pegasus knight" : (["maxhp" : 65, "strength" : 35, "magic" : 35, "skill" : 40,
"speed" : 40, "luck" : 35, "defence" : 12, "resistance" : 35]),
"pirate" : (["maxhp" : 75, "strength" : 50, "magic" : 50, "skill" : 35,
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 13]),
"prince" : (["maxhp" : 10, "strength" : 0, "magic" : 0, "skill" : 0,
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 10]),
"sage" : (["female" : (["maxhp" : 45, "strength" : 45, "magic" : 45,
"skill" : 30, "speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 40]),
"male" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30, 
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 40]),
//limstella - but not sure why she has a separate entry, they're the same
"morph" : (["maxhp" : 45, "strength" : 45, "magic" : 45, "skill" : 30, 
"speed" : 25, "luck" : 15, "defence" : 10, "resistance" : 40])]),
"shaman" : (["female" : (["maxhp" : 50, "strength" : 45, "magic" : 45,
"skill" : 32, "speed" : 30, "luck" : 20, "defence" : 10, "resistance" : 40]),
"male" : (["maxhp" : 50, "strength" : 50, "magic" : 50, "skill" : 32, 
"speed" : 30, "luck" : 20, "defence" : 10, "resistance" : 30])]),
"sniper" : (["female" : (["maxhp" : 65, "strength" : 30, "magic" : 30,
"skill" : 30, "speed" : 20, "luck" : 30, "defence" : 15, "resistance" : 25]),
"male" : (["maxhp" : 65, "strength" : 30, "magic" : 30, "skill" : 30, 
"speed" : 20, "luck" : 30, "defence" : 15, "resistance" : 20])]),
"soldier" : (["maxhp" : 80, "strength" : 50, "magic" : 50, "skill" : 30,
"speed" : 20, "luck" : 25, "defence" : 12, "resistance" : 15]),
"swordmaster" : (["female" : (["maxhp" : 65, "strength" : 25, "magic" : 25,
"skill" : 30, "speed" : 30, "luck" : 25, "defence" : 15, "resistance" : 22]),
"male" : (["maxhp" : 65, "strength" : 25, "magic" : 25, "skill" : 30, 
"speed" : 30, "luck" : 25, "defence" : 15, "resistance" : 22])]),
"thief" : (["female" : (["maxhp" : 45, "strength" : 5, "magic" : 5,
"skill" : 45, "speed" : 40, "luck" : 40, "defence" : 5, "resistance" : 25]),
"male" : (["maxhp" : 50, "strength" : 5, "magic" : 5, "skill" : 45, 
"speed" : 40, "luck" : 40, "defence" : 5, "resistance" : 20])]),
"transporter" : (["wagon" : (["maxhp" : 10, "strength" : 0, "magic" : 0,
"skill" : 0, "speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 10]),
"tent" : (["maxhp" : 10, "strength" : 0, "magic" : 0, "skill" : 0, 
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 10])]),
"troubadour" : (["maxhp" : 50, "strength" : 25, "magic" : 25, "skill" : 35,
"speed" : 55, "luck" : 45, "defence" : 12, "resistance" : 40]),
"valkyrie" : (["maxhp" : 45, "strength" : 35, "magic" : 35, "skill" : 25,
"speed" : 45, "luck" : 40, "defence" : 10, "resistance" : 40]),
"warrior" : (["maxhp" : 80, "strength" : 45, "magic" : 45, "skill" : 25,
"speed" : 20, "luck" : 15, "defence" : 16, "resistance" : 17]),
"wyvern lord" : (["female" : (["maxhp" : 75, "strength" : 40, "magic" : 40,
"skill" : 30, "speed" : 20, "luck" : 20, "defence" : 20, "resistance" : 17]),
"male" : (["maxhp" : 75, "strength" : 40, "magic" : 40, "skill" : 30, 
"speed" : 20, "luck" : 20, "defence" : 20, "resistance" : 17])]),
"wyvern rider" : (["female" : (["maxhp" : 80, "strength" : 45, "magic" : 45,
"skill" : 35, "speed" : 30, "luck" : 25, "defence" : 25, "resistance" : 17]),
"male" : (["maxhp" : 80, "strength" : 45, "magic" : 45, "skill" : 35, 
"speed" : 30, "luck" : 25, "defence" : 25, "resistance" : 15])])]);

//there are a few oddly-named classes, like "lord_eliwood", but those are
//special classes that the game doesn't use anyway, so I can deal with that
//later when doing custom stuff
mapping query_growth_rates(string class, string gender)
{
  if(max_stats[class][gender])
  {
    return max_stats[class][gender];	  
  }
  else
  {
    return max_stats[class];
  }	
}