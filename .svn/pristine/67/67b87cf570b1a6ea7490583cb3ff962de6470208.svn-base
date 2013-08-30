#include <mudlib.h>

inherit OBJECT;

int combine_command(string cmd)
{
 object plr = this_player();
 mixed *bits = ({ });

 if(cmd == "bits" || cmd == "all bits")
  {
   foreach(object ob in all_inventory(plr))
    {
     /* if not our shard, then go on to next object */
     if(base_name(ob) != "/u/a/allanon/area/caverns_of_slime/obj/metalbit")
      continue;

     bits += ({ ob });

     if(sizeof(bits) > 3)
      {
       object n = clone_object("/u/a/allanon/area/caverns_of_slime/obj/key");
       n->move(plr,1);
       message("info","You combine four bits into one.\n",plr);
       bits->remove();
       return 1;
      }
    }

   message("info","You don't have enough bits.\n",plr);
   return 1;
  }

 return notify_fail("Combine what?\n");
}

void extra_init()
{
 add_action("combine_command","combine");
}

void extra_create() {
  set_id( ({"small metal bit", "metal bit", "small bit", "bit"}) );
  set_name("small metal bit");
  set_short("small metal bit");
  set_long(wrap("It is a small bit of steel, but you have no idea what it's "+
  "used for. It looks like part of something, you just can't quite figure "+
  "out what. Perhaps it needs to be combined with something else?\n"));
}