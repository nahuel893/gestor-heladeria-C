#ifndef T_PRODUCTO_H
#define T_PRODUCTO_H
#include "tcad.h"
typedef struct{
    tcad nombre;
    float precio;
}tproducto;

tproducto carga_producto();
void muestra_producto( tproducto p );
float retorna_precio( tproducto p );
void mod_precio( tproducto *p, float nuevo );
void mod_nombre( tproducto *p, tcad nuevo );
#endif
