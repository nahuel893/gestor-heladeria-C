#include "tproducto.h"
#include <string.h>

tproducto carga_producto(){
	tproducto aux;
	printf("Ingrese el nombre del producto:\n");
	leeCad( aux.nombre, tam_cad );
	printf("Ingrese el precio del producto:\n");
	scanf("%f", &aux.precio);
	return aux;
}
void muestra_producto( tproducto p ){
	printf("Nombre: %s Precio: %.2f\n", p.nombre, p.precio);
}
float retorna_precio( tproducto p ){
	return p.precio;
}
void mod_precio( tproducto *p, float nuevo ){
	p->precio = nuevo;
}
void mod_nombre( tproducto *p, tcad nuevo ){
	strcpy( p->nombre, nuevo);
}






