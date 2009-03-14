int cat_file( string filename ) {
  int i;
  string *lines;

  i = file_exists( filename );
  if( !i ) {
    write( "No such file.\n" );
    return( 0 );
  }
  if( i == -1 ) {
    write ( "Unable to cat directories.\n" );
    return( 0 );
  }
  lines = explode( read_file( filename ), "\n" );
  for( i = 0; i < sizeof( lines ); i++ ) {
    send_message( lines[i] + "\n" );
  }
  return( 1 );
}

