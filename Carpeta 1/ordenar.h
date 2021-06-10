#ifndef __ORDENAR_H
#define __ORDENAR_H

contadorElementos *listarCARACTERES(contadorElementos *CANTIDADELEM)
{
  CANTIDADELEM = NULL;
  return CANTIDADELEM;
};
 
  contadorElementos *nuevoscar(contadorElementos *CANTIDADELEM, char *caracteres)
  {
  contadorElementos *nuevo_Elemento, *aux; 
  nuevo_Elemento = (contadorElementos*)malloc(sizeof(contadorElementos)); //asignamos un bloque de memoria para el nuevo elemento
  strcpy(nuevo_Elemento->cadena,caracteres); //copiamos la cadena cadena2 dentro de cadena1
  nuevo_Elemento->siguiente = NULL;
  //se apunta a nuevos elemntos para al momento de crear el archivo no e pirdan datos y se almacenen en dichas variable 
  if(CANTIDADELEM == NULL) //si no hay memoria disponible se devuelve NULL
  {
    CANTIDADELEM = nuevo_Elemento; //por lo tanto se almacena en nuevo Elemento
  }
  else //en caso contrario
  {
    aux = CANTIDADELEM; //creamos un auxiliar para CANTIDAD DE elementos
    while(aux->siguiente != NULL)
    { 
      aux = aux->siguiente;
    }
    aux->siguiente = nuevo_Elemento; //elemento al que apunta aux de la lista enlazada
  }
  return CANTIDADELEM;
  };

//metodo para ordenar caracteres como parámetros el contador de elementos y la cantidad de elementos
void Ordenar(contadorElementos *CANTIDADELEM){
  ordenarPalabras cadenaPalabras[100];  //creamos un arreglo para almacenar las palabras
  while(CANTIDADELEM->siguiente != NULL) //el ciclo se repetirá hasta que ya no hayan más palabras
  {
    strcpy(cadenaPalabras[c].cadena,CANTIDADELEM->cadena);  
    CANTIDADELEM = CANTIDADELEM->siguiente;  //
    c++;
  }
  strcpy(cadenaPalabras[c].cadena,CANTIDADELEM->cadena);
  char temporal[CAD_TAM]; //Iniciamos el ordenamiento
  //ciclo for para recorrer un arreglo
  for(int i=0; i<c; i++)
  {
    for(int j=0; j<c; j++)
    {
      // Si la cadena es menor que la siguiente (alfabeticamente) entonces intercambiamos
      if(strcmp(cadenaPalabras[j].cadena,cadenaPalabras[j+1].cadena) >= 0) //realiza la comparación de las cadenas 
      {
	        strcpy(temporal,cadenaPalabras[j].cadena); //Guardamos la cadena actual actual en el temporal
	        strcpy(cadenaPalabras[j].cadena,cadenaPalabras[j+1].cadena); //Pasamos la cadena actual al siguiente elemento
	        strcpy(cadenaPalabras[j+1].cadena,temporal);  //En el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
      }
    }
  } 
  for(int i=0; i<=c; i++){ 
      strcpy(cadenaFinal[i].cadena,cadenaPalabras[i].cadena);
      //Realizamos el ordenamiento
  }
};
