#ifndef __METODOS_H
#define __METODOS_H
#define TOTAL_PA 150

int existeArchivo (char *archivoNom);

typedef struct listarElementos
{
  	char cadena[TOTAL_PA];
  	struct listarElementos *siguiente;
}contadorElementos;
//FILE ES UNA ESTRUCTURA
FILE *abrir_Archivo_solo_Lectura(char *nombre_arch);
FILE *abrir_Archivo_lectura_escritura(char *nombre_arch);
contadorElementos *listarCARACTERES(contadorElementos *ELEM);
contadorElementos *caracteresN(contadorElementos *ELEM, char *caracteres);
void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);
void Ordenar(contadorElementos *CANTIDADELEMENTOS);
int t =0;

//definimos una estructura llamada ordenarPalabras
typedef struct ordenarPalabras
 {
  char cadena[TOTAL_PA];  //creamos un arreglo llamado cadena tipo caracter de 150 palaras
 }ordenarPalabras;

ordenarPalabras cadenaFinal[100];  //declaramos usando el sinónimo de la estructura creada

//existe archivo
int existeArchivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 0;
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}

//Se abre el archivo en modo lectura
FILE *abrir_Archivo_solo_Lectura(char *nombre_arch){
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "r");  //fopen abre un archivo.
	if( ptrArchivo == NULL ){
		printf("\n********El archivo no pudo abrirse");
	}	
	else{
		printf("\n~~~~~~Archivo abierto");
	}
	return ptrArchivo;
}
//Se abre el archivo en modo lectura y escritura
FILE *abrir_Archivo_lectura_escritura(char *nombre_arch){
	FILE *ptrArchivo;
	// con r+ Abre un archivo para actualización (lectura y escritura).
	ptrArchivo = fopen(nombre_arch, "r+");
	if( ptrArchivo == NULL ){
		printf("******El archivo no pudo abrirse");
	}	
	else{
		printf("~~~~~Archivo abierto");
	}
	return ptrArchivo;
}


void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);   //fclose cierra un archivo.
	printf("~~~~~~~Archivo Cerrado");
}

#endif