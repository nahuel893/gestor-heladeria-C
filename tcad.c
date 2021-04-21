#include "tcad.h"
void leeCad(tcad cadena, int tam){
	int j=0, m;
	while(j < tam-1 && (m = getchar()) != EOF && m != '\n'){
		cadena[j] = m;
		j++;
	}
	cadena[j] = '\0';
	if(m != EOF && m != '\n')
		while( (m = getchar()) != EOF && m != '\n' );
}
int compara_cad(tcad cad1, tcad cad2){
	return strcmp(cad1,cad2);
}
void muestra_cad(tcad cadena){
	printf("%s",cadena);
}
 
