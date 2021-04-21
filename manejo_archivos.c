#include <stdio.h>
#include <stdlib.h>
/*practica de archivos para guardar precios*/
#include <string.h>
typedef char tcad[100];
typedef struct{
	tcad cadena;
	int tam;
}tregistro;
typedef tregistro vector_cadenas[30];
void muestra_vector( vector_cadenas vec );
void extrae_precios( vector_cadenas vec, FILE *fp );
void extrae_nombres( vector_cadenas vec, FILE *fp );
int main(int argc, char *argv[]) {
	
	FILE * fp;
	
	vector_cadenas vecCad;
	
	fp = fopen("precios.txt", "r");
	if( fp == NULL ){ 
		printf("Error al abrir el archivo: \n") ; exit(1);
	}
	extrae_nombres( vecCad, fp );	
	extrae_precios( vecCad, fp );

	fclose(fp);

		return 0;
}
//sabiendo que strlen da el tamaño incluyendo el '\0'
void elimina_precio( tcad cad ){
	int tam = strlen( cad );
	
	while( cad[tam] != ' ' ){
		tam--;
	}
	cad[tam] = '\0';
} 
void extrae_nombres( vector_cadenas vec, FILE *fp ){
	tcad cadena;
	int tam, j = 0;
	while( feof(fp) == 0 ){
		fgets( cadena, 40, fp ); 
		tam = (int)strlen(cadena) - 1;
		cadena[tam] = '\0'; 
		elimina_precio( cadena ); 
		printf("Cadena:%s Longitud: %d\n", cadena, (int)strlen(cadena));
		if( tam > 0 ){ 
			j++;
			strcpy( vec[j].cadena, cadena );	
		}
		cadena[0] = 0; 
	}
	vec->tam = j;
}

void muestra_vector( vector_cadenas vec ){
	int i;
	for( i = 1; i <= vec->tam; i++ ){
		printf("cadena:%s\n", vec[i].cadena);
	}
}
void extrae_precios( vector_cadenas vecCad, FILE *fp ){
	int i = 0, j = 0, c;
	char caracter = 0;
	tcad cadena_num;
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
			strcpy( vecCad[j].cadena, cadena_num );
		}
		cadena_num[0] = 0;
	}
	vecCad->tam = j;
}


