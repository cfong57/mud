#include <mudlib.h>

inherit ROOM;

void extra_create()
{
  set_short( "Noble Advisor's room in the Bastion" );
  set_long(wrap("This room is probably some sort of bedroom or study, but it "+
  "is excessively gaudy...or was, at any rate. The room has been completely "+
  "trashed, with burn marks and scorching covering most surfaces. The charred "+
  "remains of a desk, a chair, and some bookshelves can be made out. In the "+
  "center of the room is a skeleton, its bones blackened from intense heat. "+
  "Wiping away some of the soot, you can see that the room's decorations "+
  "were done in gold. Perhaps this was the room of the Noble Advisor. The "+
  "room is still hot, and you can see embers in some places; it seems like "+
  "the flames are unnatural and won't die down for a long time.\n"));
  set_item_desc(([
  ({"burn marks", "scorching", "surfaces"}) : "Ugly black burns cover most "+
  "of the surfaces here, obscuring what beauty there might once have been.\n",
  ({"charred remains", "remains", "desk", "chair", "bookshelves"}) : "These "+
  "remains sort of resemble the original things, if you can imagine them "+
  "being tossed in a fire and then trampled upon.\n",
  ({"skeleton", "bones"}) : "Yeesh. You would not have wanted to be this "+
  "guy, since his death looks to have been very painful.\n",
  ({"soot", "decorations"}) : "Soot covers the things that have not been "+
  "burned to a crisp, mostly the gold decorations around the room.\n",
  ({"embers", "flames"}) : "The room is still stiflingly hot, as if the "+
  "fire occurred only recently.\n"]));
  set_sounds(135 + random(45), ({ 
  "Smoke rises from some still-smoldering object, choking you.\n"}) );
  set_exits(([
  "southwest": "/u/a/allanon/area/ity/rooms/throne.c"]));
}