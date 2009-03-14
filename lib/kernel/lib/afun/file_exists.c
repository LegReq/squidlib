nomask int file_exists (string str) {
  mixed *val;
  int *sizes;

  val = get_dir( str );
  sizes = val[1];
  if( !sizes || sizeof( sizes ) == 0 )
    return 0;
  if( sizes[0] == -2 )
    return -1;
  return 1;
}

