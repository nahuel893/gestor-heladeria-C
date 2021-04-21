#ifndef T_LISTA_H
#define T_LISTA_H
#include "tproducto.h"
typedef tproducto tvec[100];
typedef struct{
    tvec vector_productos;
    int tam_lista;
}tlista;

tlista lista_precios;
void ini_list( tlista *l );
void agregaFinal( tlista *l ); 
void agrega_fin( tlista *l, tproducto p );
void carga_helados_lista( tlista *l );
void elimina_lista( tlista *l );
void muestra_lista( tlista l );
void muestra_listaIndices( tlista l );
int retorna_tam_lista( tlista *l );
tproducto retorna_producto( tlista l, int p );
float suma_precios( tlista l );
void carga_preciosArchivo( tlista *lista );
void carga_nombresArchivo( tlista *lista );
FILE * abre_archivo();


#endif
