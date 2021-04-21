#include "thora.h"

thora hora_actual(){
    time_t t;
    struct tm* tm;
    thora aux;

    t = time( NULL );
    tm = localtime( &t );
// como digo podria usar directamente el tipo de dato ya definido en la lib
// time.h, pero bueno 

    aux.hor = tm->tm_hour;
    aux.min = tm->tm_min;
    aux.seg = tm->tm_sec;

    return aux;

}
thora carga_hora(){
    thora aux;
    short op;
    do{
        printf("Ingrese la opcion deseada\n");
        printf("1-Registrar hora actual\n");
        printf("2-Registrar manualmente la hora\n");
        printf("0-Salir\n");
        scanf("%hd", &op);
        if( op <= 0 && op >= 2 )
            printf("Valor ingresado erroneo\n");

    }while( op <= 0 && op >= 2 );

    switch ( op ){
        case 1:
            aux = hora_actual();
            break;
        case 2:
             
            printf("Ingrese hora:");
            scanf("%hd", &aux.hor);
            printf("Ingrese minutos:");
            scanf("%hd", &aux.min);
            aux.seg = 0;
            break;
    }
    return aux;
}
void muestra_hora( thora h ){
    if( h.hor != -1 )
        printf(" %.2d:%.2d:%.2d \n", h.hor, h.min, h.seg);
    else
        printf("Aun no sea ha registrado hora de atencion.\n");
}

thora ini_hora(){
    thora aux;
    aux.hor = -1;
    aux.min = -1;
    aux.seg = -1;
    return aux;
}
