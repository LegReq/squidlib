void out( string str ) {
  if( !this_user()  )
    return;
  this_player()->message_orig( str );
/*   this_user()->put_message( str ); */
  if( this_player()->is_snooped() )
    this_player()->do_snoop( str );
}

