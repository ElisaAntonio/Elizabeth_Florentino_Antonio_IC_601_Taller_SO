#include <stdio.h>
#include <stdlib.h> 


int main (){

int ArrayInt [5]; //declaramos el array con 5 
int i;            //inicalizamos a i para el ciclo for

//inicializamos el array con una estructura repetitiva
for (i=0; i<5; i++)
{
  ArrayInt[i] = i;
}

int *punteroInt = &ArrayInt[0];   // creamos un puntero int  y lo inicializamos el puntero con ArrayInt
int *punteroIntDos = &ArrayInt[0];    //creamos otro puntero int y lo inicializamos el puntero con ArrayInt en la posicion 5

printf ("ArrayInt[0] = %i\n" ,  ArrayInt[0]);          //imprimimos el contenido del primer elemento
printf("El valor de punteroInt es: %i\n", *punteroInt);  //imprimimos el contenido del puntero Int
printf("El valor del punteroIntDos es: %i\n", *punteroIntDos);  //imprimimos el contenido del puntero IntDos

printf("ArrayInt[4] = %d ",  ArrayInt[4]);          //imprimimos el contenido del primer elemento 5 del array
printf("El valor del punteroIntDos es: %i\n", *(punteroInt+=4)); //imprimimos el valor del 5to elemento del puntero Int con aritmètica de punteros
printf("El valor del punteroIntDos es: %i\n", *(punteroIntDos+=4)); //imprimimos el valor del 5to elemento del puntero IntDos con aritmètica de punteros

//imprimimos el contenido de todos los elementos del puntero Int
for (i=0; i<5; i++)
{
  punteroInt++;
  printf("El contenido de punteroInt [%i]: %i", i, *punteroInt);
}

//imprimimos el contenido de todos los elementos del puntero IntDos
for (i=0; i<5; i++)
{
  punteroInt++;
  printf("El contenido de punteroIntDos [%i]: %i", i, *punteroIntDos);
}


}
 
