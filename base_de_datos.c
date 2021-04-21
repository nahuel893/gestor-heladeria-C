#include "base_de_datos.h"
#include <sqlite3.h>

/*
char* INSERT = "INSERT INTO  %s ( fecha_hora, total_pedido) VALUES ( (datetime( 'now', 'localtime' ) ), %.2f );"; 

void insert_productos(){
	sqlite3 *db;
	int res;

	res = sqlite3_open("heladeria.db", &db );
	if( res ){
		fprintf( stderr, "No se pudo abrir la base de datos:%s \n", sqlite3_errmsg(db));
		exit(0);
	}
	else printf("Se abrio correctamente la base de datos\n");
	
}

short menuBasedeDatos(){
	short op;
	printf("Ingrese la opcion que desea realizar:\n");
	printf("1. Guardar pedidos en la base de datos.\n");
	printf("2. Mostrar los pedidos guardados.\n");
	printf("0. Salir del menu. \n");
	scanf("%hd", &op);
	return op;
}
void BaseDeDatos( tpedido pedidos[], int *tam ){
	float total;
	int i;
	char *error = 0;

	// primero abrir mi base de datos
	// hasta aqui se abrio la base de datos y se comprobaron errores
	short op;
		
	do{
		char sql[300];
		op = menuBasedeDatos();
		switch( op ){
			case 1:
				printf("Llegue aqui 1\n");
				// recorremos nuestra lista de pedidos
				for( i = 1; i <= *tam; i++ ){
					// recibo el total de un pedido
					total = retorna_total( pedidos[i] );
					//creo la orden sql, insertandole el total
					sprintf(sql, "INSERT INTO totales ( fecha_hora, total_pedido) VALUES ( (datetime( 'now', 'localtime' ) ), %.2f );", total ); 
					printf("%s", sql);		
					// ejecutamos la orden sql, pasandole db, sql y 
					// error por si algo sale mal
					res = sqlite3_exec( db, sql, NULL, 0, &error );
					// hacemos manejo de errores
					if ( res != SQLITE_OK ){
						fprintf(stderr, "Error: %s\n", error);
						sqlite3_free(error);
					}
					else
						fprintf(stdout, "INSERT correcto!\n");
				}
				// con eso deberia ser suficiente para hacer el INSERT
				break;
		}

	}while( op != 0 );

	sqlite3_close( db );
}

*/
