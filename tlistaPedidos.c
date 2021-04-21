#include "tlistaPedidos.h"

void ini_listPedidos( tlistaPedidos *lp ){
	lp->tam = 0;
}
void carga_listaPedidosfinal( tlistaPedidos *lp ){
	tpedido aux;
	aux = carga_pedido();
	lp->tam++;	
	lp->vecPedidos[lp->tam] = aux;
}

void carga_listaPedidos( tlistaPedidos *l ){
	int i;
	printf("Ingrese el tamaño de la lista:\n");
	scanf("%d", &l->tam);
	printf("Llegue aqui al modulo de carga, antes del ciclo\n");
	for( i = 1; i <= l->tam; i++ ){
		l->vecPedidos[i] = carga_pedido();
	}
	printf("Termino el modulo de carga\n");
}
void muestra_listaPedidos( tlistaPedidos l ){
	int i;
	for(i = 1; i <= l.tam; i++){
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"); 
		printf("Se muestra el pedido N: %d\n", i);
		printf("<<<<=======================>>>>\n");
		muestra_pedido( l.vecPedidos[i] );
		printf("<<<<=======================>>>>\n");
	}
}
int retorna_tam( tlistaPedidos l ){
	return l.tam;
}
void modifica_pedido( tlistaPedidos *lp ){
	int p; 
	printf("Se procedera a modificar, la lista de helados y costo de envio\n");
	printf("Ingrese el numero de pedido a modificar:\n");
	scanf("%d", &p);
	modifica_lista( &lp->vecPedidos[p] );
	modifica_envio( &lp->vecPedidos[p] );
}
	
