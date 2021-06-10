#include <stdio.h>

#include "metodos.h"
#include "ordenar.h"

int main (int argc, char *argv[])
{

  int ExistenciaArchivo=0;  
  int total = 0;   //inicializamos el total de las palabras 
  FILE *archInicial = NULL;  //primer apuntador al archivo a modificar
  char *NArchInicial [TOTAL_PA]; //declaramos el apuntador char  N= nombre del primer archivo
  char archFinal [TOTAL_PA];   //declaramos el segundo archivo
  FILE *arcchFinal = NULL; //segundo apuntador al archivo a modificar
  char temporal[100];  //definimos una variable temporal y declaramos el tamaño del string en el cual se va a almacenar lo que se leyó en el fichero
  contador *contenido = lista(contenido);   
  *NArchInicial = argv[1]; //declaramos al nombre del archivo como argumento inicial
  existeArchivo = ExistenciaArchivo (*NArchInicial); //

  //ciclo for para imprimir los argumentos que fueron ingresados
{
	
	for (int i = 0; i<argc ; i++)
	{
	printf ("Argumento %d--> [%s] \n", i, argv[i]);
	}
	return 0;
}


//comprobamos que el archivo no exista, para poder crearlo
if (existeArchivo)
   {
	 printf("\n--->El archivo: %s que quieres crear ya existe", *NArchInicial);
   }
else 
   {
	 printf("\nEl archivo: %s aún no existe", *NArchInicial);
   }

	archInicial = soloLectura(*NArchInicial);
	if(archInicial == NULL)
	{
	   printf("\n El archivo %s no pudo abrirse",*NArchInicial);
	}
	else
	{
	  printf("\n Archivo %s abierto correctamente", *NArchInicial);
	     while (!feof(archInicial))  //mientras ya no hayan caracteres por leer 
	   {
	       fscanf(archInicial,"%s",temporal);  //lee el contenido del archivo de entrada en el string temporar
	         if(strcmp(temporal,"")!=0)   //si el contenido de temporal !=0
	           {
	               contenido=palabras_nuevas(contenido,temporal);
	           }
	   memset(temporal,0,50);  //copiamos los caracteres 
	    }
    }

 Ordenar(contenido);
	fclose(archInicial); //Cerramos el archivo ide entrada
	archFinal = fopen(argv[2],"w");  //abrimos el archivo de salida
  	printf("-->>Archivo nuevo : %s\n",argv[2]);
  	for(int i=0; i<=c; i++)
  	 {
        strcpy(temporal,cadenaFinal[i].cadena);
   		  if(strcmp(temporal,"") != 0)
   		  {
      		fprintf(archFinal,"%s\n",temporal); //escribe una salida con formato en el archivo.
          }
  	 }
  	printf("Archivo \"%s\" escrito de manera correcta\n",argv[2]);
  	fclose(archivoS);	
}







