#ifndef TCAD_H
#define TCAD_H
#define tam_cad 60
// macro para limpiar pantalla 
#include "thora.h"
#ifdef _WIN32 
#define FLUSH fflush(stdin);
#define CLS system("cls");
#else
#include <stdio_ext.h>
#define FLUSH __fpurge(stdin); 
#define CLS system("clear");
#endif 
// ====  
// limpiar consola
#include <string.h>
typedef char tcad[tam_cad];



void leeCad(tcad cadena, int tam);
int compara_cad(tcad cad1, tcad cad2);
void muestra_cad(tcad cadena);
void flush_buffer();

#endif
