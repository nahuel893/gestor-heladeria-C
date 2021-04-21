#include "tlista.h"
//#include <stdlib.h>
/* modulos para la carga de lista_precios */

// este deberia ejecutarse en el main
tlista lista_precios;

FILE* abre_archivo(){
	FILE * fp;
	fp = fopen( "precios.txt", "r" );
	if( fp == NULL ){
		printf("Error al abrir el archivo");
		exit(1);
	}else
		printf("Archivo abierto correctamente\n");
	return fp;
}

void elimina_precio( tcad cad ){
	int tam;
	tam = (int)strlen( cad ) - 1;
	printf("Tamaño dado:%d\n", tam);
	while( cad[tam] != ' ' ){
		tam--;
	}
	cad[tam] = '\0';
}

void carga_nombresArchivo( tlista *lista ){
	int tam, j = 0;
	FILE * fp;
	fp = fopen( "precios.txt", "r" );
	if( fp == NULL ){
		printf("Error al abrir el archivo");
		exit(1);
	}else
		printf("Archivo abierto correctamente\n");

	while( feof(fp) == 0 ){
		tcad cadena;
		fgets( cadena, 40, fp ); 
		tam = (int)strlen(cadena) - 1;
		//cadena[tam] = '\0'; 
		// no hace falta agregar \0
		elimina_precio( cadena ); 
		if( tam > 0 ){ 
			j++;
			mod_nombre( &lista->vector_productos[j], cadena );	
		}
		/* cadena[0] = 0; */ 
	}
	lista->tam_lista = j;
	printf("Carga de nombres correcta\n");
	fclose( fp );
}
void carga_preciosArchivo( tlista *lista ){
	int i = 0, j = 0, c;
	char caracter = 0;
	tcad cadena_num;

	FILE * fp;
	fp = fopen( "precios.txt", "r" );
	if( fp == NULL ){
		printf("Error al abrir el archivo");
		exit(1);
	}else
		printf("Archivo abierto correctamente\n");

	while( caracter != EOF && j <= 9 ){
		c = 0;
		i = 0;
		while( (caracter = fgetc(fp)) != '\n' && caracter != EOF){
			c++;
			if( caracter >= 48 && caracter <= 57 && c > 3 ){
				cadena_num[i] = caracter;
				i++;
			}
		}
		cadena_num[i] = '\0';
		if( strlen(cadena_num) > 0 ){ 
			j++;
			mod_precio(&lista->vector_productos[j], atof(cadena_num));
		}
		cadena_num[0] = 0;
	}
	lista->tam_lista = j;
	printf("Carga de precios correcta\n");	
	fclose( fp );
}
void ini_list( tlista *l ){
	l->tam_lista = 0;
}
void agregaFinal( tlista *l ){
	l->vector_productos[l->tam_lista++] = carga_producto(); 
}
void agrega_fin( tlista *l, tproducto p ){
	l->tam_lista++;
	l->vector_productos[l->tam_lista] = p;
}
void carga_lista_entera( tlista *l, int tam ){
	int i;
	for(i = 1; i <= tam; i++){
		l->vector_productos[i] = carga_producto();
	}
	l->tam_lista = tam;
}
void muestra_lista( tlista l ){
	int i;
	for(i = 1; i <= l.tam_lista; i++){
		printf("<====Producto Numero:%d====>\n", i);
		muestra_producto( l.vector_productos[i] );
		printf("\n");
	}
}
void muestra_listaIndices( tlista l ){
	int i;
	for(i = 1; i <= l.tam_lista; i++){
		printf("%d.", i);
		muestra_producto( l.vector_productos[i] );
	}
}
tproducto retorna_producto( tlista l, int p ){
	return l.vector_productos[p];
}
float suma_precios( tlista l ){
	int i;
	float sum = 0;
	for(i = 1; i <= l.tam_lista; i++){
		sum += retorna_precio( l.vector_productos[i] );
	}
	return sum;
}
void inserta_uno( tlista *l, tproducto producto, int p  ){
	int i;
	for(i = l->tam_lista; i <= p ; i--){
		l->vector_productos[i+1] = l->vector_productos[i];
	} l->vector_productos[p] = producto; l->tam_lista++; 
}
void eliminar( tvec vec, int *tam, int p ){
	int i;
	for(i = p; i < *tam; i++){
		vec[i] = vec[i+1]; 
	}
	*tam = *tam - 1;
}
void elimina_lista( tlista *l ){
	int p;
	printf("Se muestra la lista de productos cargados:\n");
	muestra_listaIndices( *l );
	printf("Ingrese el numero del producto que desea eliminar\n");
	scanf("%d", &p); 
	if( p > 0 && p <= l->tam_lista )
		eliminar( l->vector_productos, &l->tam_lista, p );
	else
		printf("Valor ingresado incorrecto\n");
}
short menu_helados(){
	short op;
	printf("====== MENU LISTA DE HELADOS ======\n");
	printf("Ingrese el producto a cargar a lista de helados:(numero)\n");
// aca lo que se hace es mostra la lista de productos de venta
// se mostraran con su precio, modificare el muestra lista para que 
// muestre cada uno con su indice
	muestra_listaIndices( lista_precios );	
	printf("0.Terminar carga de helados.\n");
	scanf("%hd", &op);
	CLS;
	return op;
}
void carga_lista_precios(){
	carga_preciosArchivo( &lista_precios );
	carga_nombresArchivo( &lista_precios ); 
}
void carga_helados_lista( tlista *l ){
	short opcion_helados;
	// se cargan los precios del archivo de texto
	carga_lista_precios();
		do{
			printf("Llegue aqui\n");
			opcion_helados = menu_helados();
			if( opcion_helados != 0 ){
			/* l->vector_productos[l->tam_lista++] = lista_precios.vector_productos[opcion_helados]; */
			agrega_fin( l , retorna_producto(lista_precios, opcion_helados) ); 
			}
		}while( opcion_helados != 0 );
}
int retorna_tam_lista( tlista *l ){
	return l->tam_lista;
}	
