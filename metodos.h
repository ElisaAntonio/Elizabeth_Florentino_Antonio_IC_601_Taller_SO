



int Exisarchivo(char *archivoNom){
	FILE *ptrArchivo;
	int existe = 0;
	ptrArchivo = fopen(archivoNom, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, archivoNom);
	}	
	return existe;
}
//abrimos el archivo en modo de lectura 
FILE *soloLectura(char *archivoNom){
	FILE *ptrArchivo;
	ptrArchivo = fopen(archivoNom, "r");
	if( ptrArchivo == NULL ){
		printf("\n El archivo no pudo abrirse");
	}	
	else{
		printf("\n Archivo abierto");
	}
	return ptrArchivo;
}

FILE *archivoLE(char *archivoNom){
	FILE *ptrArchivo;
	ptrArchivo = fopen(archivoNom, "r+");
	if( ptrArchivo == NULL ){
		printf("El archivo no pudo abrirse");
	}	
	else{
		printf("Archivo abierto");
	}
	return ptrArchivo;
}
//abrir archibo para modo de escritura y lectura 

void cerrar_archivo(FILE *ptrArchivo, char *archivoNom){
	fclose(ptrArchivo);
	printf("Archivo Cerrado");
}