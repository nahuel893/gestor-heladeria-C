#include "tlistaPedidos.h"
//#include "base_de_datos.h"

void valida_enter();
short menu();
void valida_usuario();
tcad usuario_real = "Romina";
tcad ctrsn_real   = "leon2020";

int main(){
	short op;
	tlistaPedidos pedidos;
	valida_usuario();
	ini_listPedidos( &pedidos );

	do{
		switch( op = menu() ){
			case 1: carga_listaPedidosfinal( &pedidos );
					break;
			case 2:	muestra_listaPedidos( pedidos );
					break;
			case 3: modifica_pedido( &pedidos ); 
					break; 
		}
	}while( op != 0 );
	return 0;
}
short menu(){
	short op;
	printf("<==== MENU LISTA DE PEDIDOS ====>\n");
	printf("1.Carga un pedido al final de la lista\n");
	printf("2.Mostrar pedidos realizados\n");
	printf("3.Modificar un pedido\n");
	printf("0.Salir del programa\n");
	scanf("%hd", &op);
	CLS
	return op;
}
void vacia_cadena( tcad cadena ){
	int i = 0;
	
	while( cadena[i] != '\0' ){
		cadena[i] = '\0';
		i++;
	}
}
void valida_usuario(){
	tcad usuario_ingresado, ctrsn_ing;
	short b = 0;
	while( b == 0){
		FLUSH;
		printf("Ingrese nombre de usuario:\n");
		leeCad(usuario_ingresado, 60);
		printf("Ingrese contraseña:\n");
		leeCad(ctrsn_ing, 60);
		if ( (compara_cad(usuario_ingresado, usuario_real) != 0 || compara_cad(ctrsn_ing, ctrsn_real) != 0)){
			printf("El nombre de usuario o contraseña ingresados son incorrectos\n");
			vacia_cadena( usuario_ingresado );
			vacia_cadena( ctrsn_ing );
		}
		else b = 1;
		
	}
}
