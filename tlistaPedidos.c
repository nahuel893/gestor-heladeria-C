#include "tlistaPedidos.h"
#include "tpedido.h"

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
		printf(ANSI_COLOR_GREEN "Se muestra el pedido N: %d\n" ANSI_COLOR_RESET "\n", i);
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
	short op;
	printf("Se procedera a modificar, la lista de helados y costo de envio\n");
	printf("A continuacion se mostrara la lista de pedidos recuerde ");	
	printf(ANSI_COLOR_GREEN "el numero de pedido" ANSI_COLOR_RESET);
	printf("que desea modificar\n");
	press_enter();
	CLS
	muestra_listaPedidos( *lp );
	printf("Ingrese el numero de pedido a modificar:\n");
	scanf("%d", &p);
	CLS
	printf("Como desea modificar el pedido? Ingrese una opcion:\n");
	printf("1) Modificar lista de helados\n");
	printf("2) Modificar el costo del envio\n");
	printf("3) Ambas opciones\n");
	scanf("%hd", &op);
	if( op == 1 )
		modifica_lista( &lp->vecPedidos[p] );
	else if ( op == 2 )
		modifica_envio( &lp->vecPedidos[p] );
	else if ( op == 3 ){
		modifica_lista( &lp->vecPedidos[p] );
		modifica_envio( &lp->vecPedidos[p] );
	}
	else 
		printf("Valor ingresado incorrecto\n");
}
	
