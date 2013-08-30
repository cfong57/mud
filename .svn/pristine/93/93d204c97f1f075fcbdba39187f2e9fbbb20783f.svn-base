#include <mudlib.h>

inherit MONSTER;

void extra_create()
{
  set_short("Carrion crawler, feeding on corpses");
  set_long(wrap("This carrion crawler is disgusting in appearance. It looks "+
  "like a gigantic maggot with the head of a squid. It has eight wildly "+
  "swinging tentacles growing out of its mouth, strong enough to be used as "+
  "weapons. The carrion crawler seems to be content feeding upon the corpses "+
  "here; you don't think it would bother to attack you. Still, you decide to "+
  "keep a distance from it. You have heard some nasty rumors about carrion "+
  "crawlers in the sewers of Vaerlon who have killed strong adventurers like "+
  "yourself.\n"));
  set_name("carrion crawler");
  set_id(({"carrion crawler", "crawler"}));
  set_species("monster");
  set_race("carrion crawler");
  set_gender("neuter");
  set_level(12);
  set_stat("size", 250);
  set_agrochance(15);
  set_chat_output(({
  "Carrion crawler feasts on the corpses, tearing them apart with ease.\n"}));
  set_chat_chance(3);
}