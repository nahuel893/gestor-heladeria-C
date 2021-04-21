#ifndef TPEDIDO_H
#define TPEDIDO_H
#include "tlista.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
    tlista lista_productos;
    thora hora_atencion;
    int id;
	float precio_envio;
    float total;
}tpedido;

tpedido carga_pedido();
void muestra_pedido( tpedido p);
void press_enter();
void modifica_lista( tpedido *pedido );
void modifica_envio( tpedido *p );


#endif
