#include <mudlib.h>

inherit OBJECT;

/* Need 10 shards - Belannaer */
int fix_command(string cmd)
{
 object plr = this_player();
 mixed *shards = ({ });

 if(cmd == "shards" || cmd == "all shards")
  {
   foreach(object ob in all_inventory(plr))
    {
     /* if not our shard, then go on to next object */
     if(base_name(ob) != "/u/a/allanon/area/caverns_of_slime/obj/dshard")
      continue;

     shards += ({ ob });

     if(sizeof(shards) > 9)
      {
       object n = clone_object("/u/a/allanon/area/caverns_of_slime/obj/ddagger");
       n->move(plr,1);   /* don't let it fail, they were already holding the shards */
       message("info","You manage to fix all the shards into a single weapon!\n",plr);
       shards->remove();
       return 1;
      }
    }

   message("info","You don't have enough shards.\n",plr);
   return 1;
  }

 return notify_fail("Fix what?\n");
}

void extra_init()
{
    add_action("fix_command","fix");
}

void extra_create() {
  set_id( ({"diamond shard", "shard"}) );
  set_name("diamond shard");
  set_short("diamond shard");
  set_long(wrap(
  "This is an extremely thin, small, and sharp shard. It is made of diamond, which "+
  "is strange since you're almost certain that diamonds never grow to this shape "+
  "naturally. Perhaps it was once part of a weapon, which has shattered. You "+
  "suppose if you had enough shards, you just might be able to fix the weapon.\n"));
  set_value(500+random(500));
}