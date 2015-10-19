inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: muzzle [-h] PLAYER" });
   lines += ({ " " });
   lines += ({ "Muzzle a player so they can no longer shout." });
   lines += ({ "If PLAYER is already muzzled it unmuzzles them." });
   lines += ({ " " });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tmuzzle sirdude" });
   lines += ({ "See also:" });
   lines += ({ "\tban, forcequit, halt, heal, zap" });

   return lines;
}

static void main(string str) {
   int val;
   object usr, *usrs;

   if (empty_str(str)) {
      write("You need to specify a player name.\n");
   } else {
      if (sscanf(str, "-%s", str)) {
         this_player()->more(usage());
      } else if (usr = USER_D->find_player(str)) {
	 val = usr->toggle_muzzle();
	 if (val) {
	    write(capitalize(str) + " muzzled.\n");
	    usr->message("You have been muzzled by:" +
	       this_player()->query_Name() + "\n");
	 } else {
	    write(capitalize(str) + " unmuzzled.\n");
	    usr->message("You have been unmuzzled by:" +
	       this_player()->query_Name() + "\n");
	 }
      } else {
	 write("Who are you looking for?  I can't find: " + str + "!\n");
      }
   }
}
