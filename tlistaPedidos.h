#ifndef TLISTAPEDIDOS_H
#define TLISTAPEDIDOS_H
#include "tpedido.h"
// se define la lista de pedidos y sus operaciones
typedef tpedido vector_pedidos[100];
typedef struct{
    vector_pedidos vecPedidos;
    int tam;
}tlistaPedidos;

void ini_listPedidos( tlistaPedidos *lp );
void carga_listaPedidosfinal( tlistaPedidos *lp );
void carga_listaPedidos( tlistaPedidos *l );
void muestra_listaPedidos( tlistaPedidos l );
int retorna_tam( tlistaPedidos l );
void modifica_pedido( tlistaPedidos *lp );


#endif


