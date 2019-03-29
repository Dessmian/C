int pedirOpcionMenu ( char texto [] ) {
    int opcion ;
    printf ( "%s%s" , texto , "\nElija una opcion: " ) ;
        scanf ( "%d", &opcion ) ;
        fflush ( stdin ) ;
        return opcion ;
}
