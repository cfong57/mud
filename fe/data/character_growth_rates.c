//character_growth_rates.c
//database of the growth rates for recruitable characters

mapping growths = ([
"eliwood" : (["maxhp" : 80, "strength" : 45, "magic" : 45, "skill" : 50,
"speed" : 40, "luck" : 45, "defence" : 30, "resistance" : 35]),
"lyn" : (["maxhp" : 70, "strength" : 40, "magic" : 40, "skill" : 60,
"speed" : 60, "luck" : 55, "defence" : 20, "resistance" : 30]),
"hector" : (["maxhp" : 90, "strength" : 60, "magic" : 60, "skill" : 45,
"speed" : 35, "luck" : 30, "defence" : 50, "resistance" : 25]),
"sain" : (["maxhp" : 80, "strength" : 60, "magic" : 60, "skill" : 35,
"speed" : 40, "luck" : 35, "defence" : 20, "resistance" : 20]),
"kent" : (["maxhp" : 85, "strength" : 40, "magic" : 40, "skill" : 50,
"speed" : 45, "luck" : 20, "defence" : 25, "resistance" : 25]),
"florina" : (["maxhp" : 60, "strength" : 40, "magic" : 40, "skill" : 50,
"speed" : 55, "luck" : 50, "defence" : 15, "resistance" : 35]),
"wil" : (["maxhp" : 75, "strength" : 50, "magic" : 50, "skill" : 50,
"speed" : 40, "luck" : 40, "defence" : 20, "resistance" : 25]),
"dorcas" : (["maxhp" : 80, "strength" : 60, "magic" : 60, "skill" : 40,
"speed" : 20, "luck" : 45, "defence" : 25, "resistance" : 15]),
"serra" : (["maxhp" : 50, "strength" : 50, "magic" : 50, "skill" : 30,
"speed" : 40, "luck" : 60, "defence" : 15, "resistance" : 55]),
"erk" : (["maxhp" : 65, "strength" : 40, "magic" : 40, "skill" : 40,
"speed" : 50, "luck" : 30, "defence" : 20, "resistance" : 40]),
"rath" : (["maxhp" : 80, "strength" : 50, "magic" : 50, "skill" : 40,
"speed" : 50, "luck" : 30, "defence" : 10, "resistance" : 25]),
"matthew" : (["maxhp" : 75, "strength" : 30, "magic" : 30, "skill" : 40,
"speed" : 70, "luck" : 50, "defence" : 25, "resistance" : 20]),
"wallace" : (["maxhp" : 70, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 20, "luck" : 30, "defence" : 35, "resistance" : 35]),
"lowen" : (["maxhp" : 90, "strength" : 30, "magic" : 30, "skill" : 30,
"speed" : 30, "luck" : 50, "defence" : 40, "resistance" : 30]),
"rebecca" : (["maxhp" : 60, "strength" : 40, "magic" : 40, "skill" : 50,
"speed" : 60, "luck" : 50, "defence" : 15, "resistance" : 30]),
"marcus" : (["maxhp" : 65, "strength" : 30, "magic" : 30, "skill" : 50,
"speed" : 25, "luck" : 30, "defence" : 15, "resistance" : 35]),
"bartre" : (["maxhp" : 85, "strength" : 50, "magic" : 50, "skill" : 35,
"speed" : 40, "luck" : 30, "defence" : 30, "resistance" : 25]),
"oswin" : (["maxhp" : 90, "strength" : 40, "magic" : 40, "skill" : 30,
"speed" : 30, "luck" : 35, "defence" : 55, "resistance" : 30]),
"guy" : (["maxhp" : 75, "strength" : 30, "magic" : 30, "skill" : 50,
"speed" : 70, "luck" : 45, "defence" : 15, "resistance" : 25]),
"merlinus" : (["maxhp" : 120, "strength" : 0, "magic" : 0, "skill" : 90,
"speed" : 90, "luck" : 100, "defence" : 30, "resistance" : 15]),
"priscilla" : (["maxhp" : 45, "strength" : 40, "magic" : 40, "skill" : 50,
"speed" : 40, "luck" : 65, "defence" : 15, "resistance" : 50]),
"raven" : (["maxhp" : 85, "strength" : 55, "magic" : 55, "skill" : 40,
"speed" : 45, "luck" : 35, "defence" : 25, "resistance" : 15]),
"lucius" : (["maxhp" : 55, "strength" : 60, "magic" : 60, "skill" : 50,
"speed" : 40, "luck" : 20, "defence" : 10, "resistance" : 60]),
"canas" : (["maxhp" : 70, "strength" : 45, "magic" : 45, "skill" : 40,
"speed" : 35, "luck" : 25, "defence" : 25, "resistance" : 45]),
"dart" : (["maxhp" : 70, "strength" : 65, "magic" : 65, "skill" : 20,
"speed" : 60, "luck" : 35, "defence" : 20, "resistance" : 15]),
"fiora" : (["maxhp" : 70, "strength" : 35, "magic" : 35, "skill" : 60,
"speed" : 50, "luck" : 30, "defence" : 20, "resistance" : 50]),
"legault" : (["maxhp" : 60, "strength" : 25, "magic" : 25, "skill" : 45,
"speed" : 60, "luck" : 60, "defence" : 25, "resistance" : 25]),
"nils" : (["maxhp" : 85, "strength" : 5, "magic" : 5, "skill" : 5,
"speed" : 70, "luck" : 80, "defence" : 30, "resistance" : 70]),
"ninian" : (["maxhp" : 85, "strength" : 5, "magic" : 5, "skill" : 5,
"speed" : 70, "luck" : 80, "defence" : 30, "resistance" : 70]),
"isadora" : (["maxhp" : 75, "strength" : 30, "magic" : 30, "skill" : 35,
"speed" : 50, "luck" : 45, "defence" : 20, "resistance" : 25]),
"heath" : (["maxhp" : 80, "strength" : 50, "magic" : 50, "skill" : 50,
"speed" : 45, "luck" : 20, "defence" : 30, "resistance" : 20]),
"hawkeye" : (["maxhp" : 50, "strength" : 40, "magic" : 40, "skill" : 30,
"speed" : 25, "luck" : 40, "defence" : 20, "resistance" : 35]),
"geitz" : (["maxhp" : 85, "strength" : 50, "magic" : 50, "skill" : 30,
"speed" : 40, "luck" : 40, "defence" : 20, "resistance" : 20]),
"farina" : (["maxhp" : 75, "strength" : 50, "magic" : 50, "skill" : 40,
"speed" : 45, "luck" : 45, "defence" : 25, "resistance" : 30]),
"pent" : (["maxhp" : 50, "strength" : 30, "magic" : 30, "skill" : 20,
"speed" : 40, "luck" : 40, "defence" : 30, "resistance" : 35]),
"louise" : (["maxhp" : 60, "strength" : 40, "magic" : 40, "skill" : 40,
"speed" : 40, "luck" : 30, "defence" : 20, "resistance" : 30]),
"karel" : (["maxhp" : 70, "strength" : 30, "magic" : 30, "skill" : 50,
"speed" : 50, "luck" : 30, "defence" : 10, "resistance" : 15]),
"harken" : (["maxhp" : 80, "strength" :35, "magic" : 35, "skill" : 30,
"speed" : 40, "luck" : 20, "defence" : 30, "resistance" : 25]),
"nino" : (["maxhp" : 55, "strength" : 50, "magic" : 50, "skill" : 55,
"speed" : 60, "luck" : 45, "defence" : 15, "resistance" : 50]),
"jaffar" : (["maxhp" : 65, "strength" : 15, "magic" : 15, "skill" : 40,
"speed" : 35, "luck" : 20, "defence" : 30, "resistance" : 30]),
"vaida" : (["maxhp" : 60, "strength" : 45, "magic" : 45, "skill" : 25,
"speed" : 40, "luck" : 30, "defence" : 25, "resistance" : 15]),
"karla" : (["maxhp" : 60, "strength" : 25, "magic" : 25, "skill" : 45,
"speed" : 55, "luck" : 40, "defence" : 10, "resistance" : 20]),
"renault" : (["maxhp" : 60, "strength" : 40, "magic" : 40, "skill" : 30,
"speed" : 35, "luck" : 15, "defence" : 20, "resistance" : 40]),
"athos" : (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0,
"speed" : 0, "luck" : 0, "defence" : 0, "resistance" : 0])]);

mapping query_growths(string unitname)
{
  return growths[unitname];
}