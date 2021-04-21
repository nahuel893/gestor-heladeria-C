#ifndef THORA_H
#define THORA_H

#include <stdlib.h>
#include <stdio.h>
// aqui estuve dudando de si usar el tipo de dato ya creado o usar el mio
// que es mas sencillo 
// entiendo que se puede pensar que es mejor usar lo que ya esta def, pero 
// bueno...
#include <time.h>

typedef struct{
    short hor, min, seg;
}thora;

thora carga_hora();
void muestra_hora( thora h );
thora ini_hora();


#endif
