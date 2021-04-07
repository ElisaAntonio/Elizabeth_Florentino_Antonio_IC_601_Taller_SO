#include<stdio.h>
 int main()
{
   int i, j, nProc, pos, tem, tEjec[20], pro[20], tEsp[20], tLleg[20], total=0;
   float tPromEs, tPromRes;
   
   printf ("\nImplementacion de Scheduler en C --El Trabajo mas corto--\n");
     
   //Solicitamos la cantidad de procesos a trabajar, y almacenamos los datos en nProc
   printf("\nIngresa el numero de procesos: ");
   scanf("%d", &nProc);
   //Pedimos al usuario ingresar el tiempo de ráfaga, para que se puedan ordenar 
   //y así ejecutar primero el más corto
   printf("\n >>>Ingresa el tiempo de ejecucion del proceso: ");
   for (i=0; i<nProc; i++) //De acuerdo al la cantidad de procesos ingresados, se irán pidiendo el tiempo de ejecución
   {
     printf ("\n proceso %d: ", i+1); //Aquí se irán ingresando los tiempos de ejecución de cada proceso
     scanf("%d", &tEjec[i]); //Guarda los datos ingresados del tiempo de ejecución del proceso en el vector  tEjec
     pro[i]= i + 1; //A cada proceso se le irá asignando su tieempo de ejecución
   }

//prioridad de los tiempos de ejecución de cada proceso
  for(i=0; i<nProc;i++) //para i
   {
    pos=i;
    for (j=i+1; j<nProc;j++)
     {
      if (tEjec[j] < tEjec[pos]) //
            pos=j; //
     }

    tem= tEjec[i];
    tEjec[i]= tEjec[pos];
    tEjec[pos]= tem;


    tem= pro[i];
    pro[i] = pro[pos];
    pro[pos]=tem;

   }
 
    tEsp[0]=0; //al tiempo de Espera, le asignamos el valor de 0, en la posición 0
               //Esto quiere decir que el tiempo de espera para el primer elemento es 0

    //Calculamos el tiempo de espera restante con 2 ciclos for, uno exterior y otro interior. Dentro del segundo bucle 
    //el tiempo espera se calcula sumando tiempo de ejecución, con el tiempo de espera

    for (i=1;i<nProc; i++) //iniciamos el ciclo, para i, hasta que llegue al número de procesos
    {
    tEsp[i]=0;  //asignamos un valor de cero a cada ubicación del arreglo e iniciamos otro ciclo
    for (j=0; j<i;j++) //hasta que j, sea igual al valor del tiempo de Espera ingresado
          tEsp[i]+=tEjec[j]; //El tiempo de espera es igual al Tiempo de espera más el tiempo de ejecución  
         //(La opración quiere decir lo siguiente tEsp[i]=tEsp[i]+tEjec[j])
            total+=tEsp[j];  //Calculamos el total de todo el tiempo de espera juntos
    }
       

     tPromEs= (float)total/nProc;  
     total= 0;

     
     printf("\n No.Proceso\t\tTiempo Ejecucion\t\t Tiempo Espera \t\t\tTiempo Respuesta");
     //El tiempo de respuesta se calcula sumando el tiempo de ráfaga y el tiempo de espera
     //Creamos un ciclo for, donde la variable total, contiene al tiempo de respuesta o llegada total.
     //Aquí calculamos el tiempo medio de respuesta
     for(i=0; i<nProc; i++)
      {
       tLleg[i]= tEjec[i] + tEsp[i]; 
       total+=tLleg[i];
       printf("\n proceso %d \t\t  \t  %d \t  \t\t   %d  \t  \t\t   %d", pro[i], tEjec[i], tEsp[i], tLleg[i]);

      }
   
    tPromRes=(float)total/nProc;
    printf("\n >>>El tiempo Medio de Espera es =%f",tPromEs);
    printf("\n >>>El tiempo de Respuesta es: =%f",tPromRes);
    printf("\n");

}
