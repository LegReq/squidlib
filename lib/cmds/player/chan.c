/* An interface to the channel daemon
 * 
 * Fudge
 */
#include <channel.h>

void chan_cmd( string chan, string cmd );

void main( string str ) {
  string chan;
  string cmd;

  if( str == "" ) {
    write( "Usage: chan <channel> </command>\n Command can be join, leave, quit, new, admin, wiz, hist, permanent, who, list, info, or delete.\n" );
    return;
  }
  if( sscanf( str, "%s %s", chan, cmd ) != 2 ) {
    chan = str;
    cmd = "/info";
  }

  chan_cmd( chan, cmd );
}

void chan_cmd( string chan, string cmd ) {

  switch( cmd ) {
  case "/on":
    CHANNEL_D->chan_join( chan, this_player() );
    this_player()->add_channel( chan );
    break;
  case "/off":
    CHANNEL_D->chan_leave( chan, this_player() );
    this_player()->remove_channel( chan );
    break;
  case "/new":
    CHANNEL_D->chan_new( chan, ALL );
    break;
  case "/admin":
    CHANNEL_D->chan_set_flag( chan, ADMIN_ONLY );
    break;
  case "/wiz":
    CHANNEL_D->chan_set_flag( chan, WIZ_ONLY );
    break;
  case "/readonly":
    CHANNEL_D->chan_set_flag( chan, READ_ONLY );
    break;
  case "/permanent": 
    CHANNEL_D->chan_make_permanent( chan );
    break;
  case "":
  case "/who":
  case "/list":
    CHANNEL_D->chan_who( chan );
    break;
  case "/hist":
    CHANNEL_D->show_history( chan );
    break;
  case "/delete":
    break;
  case "/info":
    /*this_player()->message(CHANNEL_D->query_debug());*/
    break;
  default:
    if( strlen( cmd ) > 8 )
      if( cmd[..5] == "/color" ) {
	/* Let's change the color of the channel */
	CHANNEL_D->chan_set_color( chan, cmd[7..] );
	break;
      } else if( cmd[..4] == "/imud" ) {
	CHANNEL_D->chan_imud( chan, cmd[6..] );
	break;
      } else if( cmd[..5] == "/guild" ) {
	CHANNEL_D->chan_set_guild( chan, cmd[7..] );
	break;
      }
    if( cmd[0] == ';' ) {
      CHANNEL_D->chan_emote( chan, cmd[1..] );
      break;
    }
    
    CHANNEL_D->chan_say( chan, cmd );
    return;
  }
}
