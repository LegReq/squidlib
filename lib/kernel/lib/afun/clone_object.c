static object clone_object( string path ) {
  object ob;

  if( strlen(path) > 2 ) {
    if( path[strlen(path)-2] == '.' && path[strlen(path)-1] == 'c' )
      path = path[..strlen(path)-3];
  }

  if( ob = find_object( path ) )
    return ::clone_object( ob );
  else
    return ::clone_object( compile_object( path ) );
}

