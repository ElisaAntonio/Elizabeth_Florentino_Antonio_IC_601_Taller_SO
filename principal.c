#include <stdio.h>

int main (int argc, char *argv[])

  char archInicial [CONTENIDO]; //declaramos el nombre del primer archivo
  char archFinal [CONTENIDO];   //declaramos el segundo archivo
  int total=0;   //inicializamos el total de las palabras 
  File *ptrUno;  //primer apuntador al archivo a modificar


  //ciclo for para imprimir los argumentos que fueron ingresados
{
	
	for (int i = 0; i<argc ; i++)
	{
	printf ("Argumento %d--> [%s] \n", i, argv[i]);
	}
	return 0;
}





i