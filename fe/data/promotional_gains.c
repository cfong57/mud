//promotional_gains.c
//database of what each class gains when they promote
//note: fire emblem 7 only has data for male promotions for many of the classes
//taking artistic liberty and borrowing the female promotion stats from
//fire emblem 8 (or using some other stats if no gender distinction)

mapping gains = ([
"blade lord" : (["maxhp" : 3, "strength" : 2, "magic" : 2, "skill" : 0, 
  "speed" : 0, "defence" : 3, "resistance" : 5, "movement" : 1, 
  "constitution" : 1, "wexp" : (["bows" : 31])]),
"knight lord" : (["maxhp" : 4, "strength" : 2, "magic" : 2, "skill" : 0, 
  "speed" : 1, "defence" : 1, "resistance" : 3, "movement" : 2, 
  "constitution" : 2, "wexp" : (["lances" : 31])]),
"great lord" : (["maxhp" : 3, "strength" : 0, "magic" : 0, "skill" : 2, 
  "speed" : 3, "defence" : 1, "resistance" : 5, "movement" : 0, 
  "constitution" : 2, "wexp" : (["swords" : 31])]),
"paladin" : (["female" : (["maxhp" : 1, "strength" : 1, "magic" : 1, 
  "skill" : 1, "speed" : 2, "defence" : 1, "resistance" : 2, "movement" : 1, 
  "constitution" : 0, "wexp" : (["swords" : 31, "lances" : 31, "axes" : 1])]),
  "male" : (["maxhp" : 2, "strength" : 1, "magic" : 1, "skill" : 1, 
  "speed" : 1, "defence" : 2, "resistance" : 1, "movement" : 1, 
  "constitution" : 2, "wexp" : (["swords" : 31, "lances" : 31, "axes" : 1])])]),
"general" : (["female" : (["maxhp" : 3, "strength" : 2, "magic" : 2, 
  "skill" : 3, "speed" : 2, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["lances" : 30, "axes" : 1])]),
  "male" : (["maxhp" : 4, "strength" : 2, "magic" : 2, "skill" : 2, 
  "speed" : 3, "defence" : 2, "resistance" : 3, "movement" : 1, 
  "constitution" : 2, "wexp" : (["lances" : 30, "axes" : 1])])]),
//no gender distinction
"hero" : (["maxhp" : 4, "strength" : 0, "magic" : 1, "skill" : 2, "speed" : 2,
  "defence" : 2, "resistance" : 2, "movement" : 1, "constitution" : 1, 
  "wexp" : (["swords" : 40, "axes" : 1])]),
"swordmaster" : (["female" : (["maxhp" : 4, "strength" : 2, "magic" : 2, 
  "skill" : 1, "speed" : 0, "defence" : 2, "resistance" : 1, "movement" : 1, 
  "constitution" : 2, "wexp" : (["swords" : 40])]),
  "male" : (["maxhp" : 5, "strength" : 2, "magic" : 2, "skill" : 0, 
  "speed" : 0, "defence" : 2, "resistance" : 1, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 40])])]),
//fe8 female assassin: +1skl +1spd -1hp -1res +1con
"assassin" : (["female" : (["maxhp" : 2, "strength" : 1, "magic" : 1, 
  "skill" : 1, "speed" : 1, "defence" : 2, "resistance" : 1, "movement" : 0, 
  "constitution" : 1, "wexp" : ([])]),
  "male" : (["maxhp" : 3, "strength" : 1, "magic" : 1, "skill" : 0, 
  "speed" : 0, "defence" : 2, "resistance" : 2, "movement" : 0, 
  "constitution" : 0, "wexp" : ([])])]),
"sniper" : (["female" : (["maxhp" : 4, "strength" : 3, "magic" : 3, "skill" : 1, 
  "speed" : 1, "defence" : 2, "resistance" : 2, "movement" : 1, 
  "constitution" : 1, "wexp" : (["bows" : 40])]),
  "male" : (["maxhp" : 3, "strength" : 1, "magic" : 1, "skill" : 2, 
  "speed" : 2, "defence" : 2, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["bows" : 40])])]),
//using fe8 "ranger" for female: +1skl -1hp
"nomad trooper" : (["female" : (["maxhp" : 2, "strength" : 2, "magic" : 2, 
  "skill" : 2, "speed" : 1, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 1, "bows" : 40])]),
  "male" : (["maxhp" : 3, "strength" : 2, "magic" : 2, "skill" : 1, 
  "speed" : 1, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 1, "bows" : 40])])]),
//using fe8 wyvern lord for female: +2str +2def -2spd -2res
"wyvern lord" : (["female" : (["maxhp" : 4, "strength" : 2, "magic" : 2, 
  "skill" : 2, "speed" : 0, "defence" : 2, "resistance" : 0, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 1, "lances" : 40])]),
  "male" : (["maxhp" : 4, "strength" : 0, "magic" : 0, "skill" : 2, 
  "speed" : 2, "defence" : 0, "resistance" : 2, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 1, "lances" : 40])])]),
"sage" : (["female" : (["maxhp" : 3, "strength" : 1, "magic" : 1, "skill" : 1, 
  "speed" : 0, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 1, "anima" : 40])]),
  "male" : (["maxhp" : 4, "strength" : 1, "magic" : 1, "skill" : 0, 
  "speed" : 0, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 1, "anima" : 40])])]),
"bishop" : (["female" : (["maxhp" : 3, "strength" : 1, "magic" : 1, "skill" : 2, 
  "speed" : 1, "defence" : 2, "resistance" : 2, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 40, "light" : 31])]),
  "male" : (["maxhp" : 3, "strength" : 2, "magic" : 2, "skill" : 1, 
  "speed" : 0, "defence" : 3, "resistance" : 2, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 71, "light" : 30])])]),
//using fe8 "summoner" for female: +1skl +1res -1hp -1def
"druid" : (["female" : (["maxhp" : 3, "strength" : 0, "magic" : 0, "skill" : 1, 
  "speed" : 3, "defence" : 1, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 1, "dark" : 40])]),
  "male" : (["maxhp" : 4, "strength" : 0, "magic" : 0, "skill" : 0, 
  "speed" : 3, "defence" : 2, "resistance" : 2, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 1, "dark" : 40])])]),
"warrior" : (["maxhp" : 3, "strength" : 1, "magic" : 1, "skill" : 2, 
  "speed" : 0, "defence" : 3, "resistance" : 3, "movement" : 1, 
  "constitution" : 2, "wexp" : (["axes" : 40, "bows" : 1])]),
"berserker" : (["maxhp" : 4, "strength" : 1, "magic" : 1, "skill" : 1, 
  "speed" : 1, "defence" : 2, "resistance" : 2, "movement" : 1, 
  "constitution" : 3, "wexp" : (["axes" : 40])]),
"falcoknight" : (["maxhp" : 5, "strength" : 2, "magic" : 2, "skill" : 0, 
  "speed" : 0, "defence" : 2, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["swords" : 1, "lances" : 40])]),
"valkyrie" : (["maxhp" : 3, "strength" : 2, "magic" : 2, "skill" : 1, 
  "speed" : 0, "defence" : 2, "resistance" : 3, "movement" : 1, 
  "constitution" : 1, "wexp" : (["staves" : 40, "anima" : 1])]),
"transporter" : (["maxhp" : 0, "strength" : 0, "magic" : 0, "skill" : 0, 
  "speed" : 0, "defence" : 0, "resistance" : 0, "movement" : 5, 
  "constitution" : 0, "wexp" : ([])])]);
  
mapping query_gains(string class, string gender)
{
  if(gains[class][gender])
  {
    return gains[class][gender]; 
  }	
  else
  {
    return gains[class];	  
  }
}