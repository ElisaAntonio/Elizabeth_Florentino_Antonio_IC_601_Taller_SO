elementos *listcar(elementos *ELEM){
  ELEM = NULL;
  return ELEM;
};

  elementos *nuevoscar(elementos *ELEM, char *caracteres){
  elementos *nuevo_Elemento, *aux; 
  nuevo_Elemento = (elementos*)malloc(sizeof(elementos));
  strcpy(nuevo_Elemento->cadena,caracteres);
  nuevo_Elemento->sig = NULL;
  //se apunta a nuevos elemntos para al momento de crear el archivo no e pirdan datos y se almacenen en dichas variable 
  if(ELEM == NULL){
    ELEM = nuevo_Elemento;
  }else{
    aux = ELEM;
    while(aux->sig != NULL){ 
      aux = aux->sig;
    }
    aux->sig = nuevo_Elemento; // nos movemos al ultimo elemento al que apunta aux de la lista enlazada  que anteriormente lo relizamos 
  }
  return ELEM;
};


void Burbu(elementos *ELEM){
  ordenT cadA[100];
  while(ELEM->sig != NULL){
    strcpy(cadA[c].cadena,ELEM->cadena); 
    ELEM = ELEM->sig;
    c++;
  }
  strcpy(cadA[c].cadena,ELEM->cadena);
  char temp[CAD_TAM]; //se inicia el ordenamiento por metodo de burbuja 
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      if(strcmp(cadA[j].cadena,cadA[j+1].cadena) >= 0){
	strcpy(temp,cadA[j].cadena);
	strcpy(cadA[j].cadena,cadA[j+1].cadena);
	strcpy(cadA[j+1].cadena,temp);
      }
    }
  } 
  for(int i=0; i<=c; i++){ 
      strcpy(cadORD[i].cadena,cadA[i].cadena);
      //Ordenamos los elemnentos del arreglo mediante el metodo de la burbuja 
  }
};