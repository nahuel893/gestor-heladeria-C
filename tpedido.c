#include "tpedido.h"

void press_enter(){
	printf("Presione enter para continuar...\n");
	while( getchar() != '\n');
}
void actualiza_total( tpedido *p ){
	p->total = suma_precios( p->lista_productos ) + p->precio_envio;
}
void modifica_lista( tpedido *pedido ){
	short op;
	short b = 0;
	do{
	printf("<==== MODIFICACION DE LISTA DE HELADOS ====>\n");
	printf("Ingrese la opcion deseada:\n");
	printf("1.Eliminar un producto de la lista\n");
	printf("2.Agregar productos a la lista\n");
	printf("0.Salir de este menu\n");
	scanf("%hd", &op);
		switch( op ){
			case 1: 
				elimina_lista( &pedido->lista_productos );				
				b = 1;
				break;
			case 2: 
				carga_helados_lista( &pedido->lista_productos );
				b = 1;
				break;
		}
	}while( op != 0 );
	if( b == 1 )
		actualiza_total( pedido );
		
}
void modifica_envio( tpedido *p ){
	float nvo;
	printf("Indique nuevo precio de envio:(0 si no se cobra envio)\n");
	scanf("%f", &nvo); 
	p->precio_envio = nvo;
}
//============================================================================
void muestra_pedido( tpedido p ){
	muestra_lista( p.lista_productos );
	printf("Hora de carga del pedido: \n");
	muestra_hora( p.hora_atencion );
	/*
	muestra_fecha( p.fecha_atencion);
	*/
	printf(ANSI_COLOR_MAGENTA "Precio total:%f (envio incluido)\n" ANSI_COLOR_RESET "\n", p.total);
}
tpedido carga_pedido(){
	tpedido aux;
	ini_list( &aux.lista_productos );
	carga_helados_lista( &aux.lista_productos );		
	/*
	 tiene que haber un carga_hora_automatico y uno manual
	 */
	aux.hora_atencion = carga_hora();
	printf("Ingrese costo de envio( 0 => si no se cobra envio )\n");
	scanf("%f", &aux.precio_envio);
	aux.total = suma_precios( aux.lista_productos ) + aux.precio_envio;
	CLS
	muestra_pedido( aux ); 
	printf("Este es el pedido que acaba de cargar\n");
	FLUSH	
	press_enter();
	CLS	
	return aux;
}
float retorna_envio( tpedido p ){
	return p.precio_envio;
}
float retorna_total ( tpedido p ){
	return p.total;
}
// helados == productos 
