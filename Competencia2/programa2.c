#include <stdio.h>
int main (){
int ArrayInt[5]; //declaramos el array con 5 
//inicializamos el array con una estructura repetitiva
for (int i=0; i<5; i++)
{
  ArrayInt[i] = i;
}

int *punteroInt= ArrayInt;   // creamos un puntero int  y lo inicializamos el puntero con ArrayInt
int *punteroIntDos= &ArrayInt[0];    //creamos otro puntero y lo  inicializamos el puntero con ArrayInt con el primer elemento del array

printf ("El valor de ArrayInt[0] es: %d\n" ,  ArrayInt[0]);          //imprimimos el contenido del primer elemento
printf("El valor de punteroInt es: %i\n", punteroInt);  //imprimimos el contenido del puntero Int
printf("El valor del punteroIntDos es: %i\n", punteroIntDos);  //imprimimos el contenido del puntero IntDos
printf("El valor de ArrayInt[4] = %d\n",  ArrayInt[4]);          //imprimimos el contenido del primer elemento 5 del array
printf("El valor del punteroIntDos es: %d\n", punteroInt+4); //imprimimos el valor del 5to elemento del puntero Int con aritmètica de punteros
printf("El valor del punteroIntDos es: %d\n", punteroIntDos+4); //imprimimos el valor del 5to elemento del puntero IntDos con aritmètica de punteros

//imprimimos el contenido de todos los elementos del puntero Int
for (int i=0; i<5; i++)
{
  *punteroInt++;
  printf("El contenido de punteroInt [i]: %i\n", i,punteroInt);
}

//imprimimos el contenido de todos los elementos del puntero IntDos
for (int i=0; i<5; i++)
{
  *punteroIntDos++;
  printf("El contenido de punteroIntDos [i]: %i\n",i, punteroIntDos);
}

}
