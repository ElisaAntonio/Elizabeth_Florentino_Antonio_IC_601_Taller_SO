/*Para los símbolos estándares*/
#include <unistd.h>  
/* includes para los SOCKETS */
#include <netdb.h> 
#include <netinet/in.h>   
#include <sys/socket.h>
#include <arpa/inet.h>
/*Para errores*/
#include <errn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATO_MAXIMO 10000  //definimos el dato maximo
#define PORT 8080  //Definimos el puerto 8080 que es la alternativa para usar el http
#define Sock struct sockaddr

/*Definimos las variables*/
char numero1[DATO_MAXIMO];
char numero2[DATO_MAXIMO];
char resultado[DATO_MAXIMO];
char buff_rx[DATO_MAXIMO]; //definimos buffer para recepcióm


/*Creamos el método para la SUMA que vamos a ocupar*/
void SUMAR_NUMEROS(char numero1[], char numero2[], char resultado[]){
/*Definimos variables que nos ayudarán*/
	int longitud_MAX, n1, n2, i, j, k;
/*Auxuliares para almacenar lo calculado posteriormente*/
    int aux_N1[n1], aux_N2[n2], aux_LONG[longitud_MAX];

/*CALCULAMOSLA LONGITUD DE AMBAS CADENAS
strlen --> Devuelve la longitud de una cadena*/
n1 = strlen (numero1);
n2 = strlen (numero2);

	//REALIZAMOS LA COMPARACIÓN DE LA LONGITUD DE AMBOS NÚMEROS
    //PARA DETERMINAR LA MÁXIMA LONGITUD
    if(n1>n2)
    	longitud_MAX=n1;
    else
    	longitud_MAX=n2;

/*CONVERTIMOS LOS NÚMEROS DE CARACTER A ENTERO*/
/*Usamos el truco de restar del dígito el número '0'*/
for ( i=0; i<n1; i++){
	aux_N1[i] =n1[i]-'0';
}
for ( j=0; j<n2; j++){
	aux_N2[j] =n2[j]-'0';
}

j = n2 - 1;
k = longitud_MAX-1;

for (i=n1-1; i>0 && j>0; i--)
{
aux_LONG[k] = aux_N1[i]+ aux_N2[j];
j--;
k--;
}
//reducimos los contadores
for (;i>=0; --i, --j){
	aux_LONG = aux_N1[j];
} 
for (;i>=0; --j, --k){
	aux_LONG = aux_N2[k];
} 

for (k = longitud_MAX-1; k>0; k--)
{
	if (aux_LONG[k]>9)
	{
		aux_LONG[k]= aux_LONG[k]%10;
		//aux_LONG[k-1]= aux_LONG[k-1]+1;
		aux_LONG[k]+=1;
	}
}
i=0;
for(k=0; k<longitud_MAX; k++)
{
	if(aux_LONG[k]>9)
	{
     resultado[i]=(aux_LONG[k]-10)+'0';
	}
	else
		resultado[i]=aux_LONG[k]+'0';
	i++;
}

int main(int argc, char const *argv[])
{
	//DEFINIMOS LAS VARIABLES
	    //escuchar, descriptor, longitud 
	int sockfd, connfd, long1;
	//ESTRUCTURA PARA EL SERVIDOR Y EL CLIENTE
	//en esta estructura se define el formato de la dirección
	//familia, puerto y la dirección IPv4
	struct sockaddr_in servaddr, cliente_1;
 
//CREACIÓN DEL SOCKET 
	                //dominio,   tipo, protocolo
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//si hay un error, devuelve -1
	if (sockfd == -1)
	{
		printf(stderr, "¡¡ERROR!! FALLÓ LA CREACIÓN DEL SOCKET\n");
			exit (0)
	}
	else

		printf ("-->SOCKET CREADO EXITOSAMENTE \n");

	//crea la esctrucura saddreess format
	memset(&servaddr,0,sizeof(servaddr));

	//asignar IP, Puerto y dirección IPv4
	servaddr.sin_family        = AF_INET;
	servaddr.sin_addr.s_addr   = htonl(INADDR_ANY);;
	servaddr.sin_port          = htons(atoi(argv[1]));  //este valor ordena los bits
	
	//ASIGNAMOS DIRECCIÓN IP Y PUERTO
	        //file descriptor   puntero a la estrucutra, el tamaño de la esctructura
	        // (SI EL No. ES MAYOR A 0, ASIGNÓ CORRECTAMENTE)
	if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) !=0)
	{
		printf(stderr, "¡¡ERROR!! FALLÓ AL ASIGNAR DIRECCIÓN IP Y PUERTO %s\n");
	    return -1;
	}
	else 
	{
		printf("--> IP Y PUERTO ASIGNADO CORRECTAMENTE\n");
	}

	//llamada al sistema linsten
	             //5 corresponde al backlog No. maximo de conexiones pendientes
	if ((listen(sockfd, 5)) !=0)
	{
		printf("¡¡ERROR!! LA LLAMADA AL SISTEMA FALLÓ.\n");
		exit(0);
	}
	else
		printf("-->LLAMADA AL SISTEMA EXITOSA\n");

	//cargamos en la variable long1 el tamaño de la estructura para el address format del cliente
	long1 = sizeof(cliente_1);

	//Aceptamos a los clientes
	connfd = accept(sockfd, (Sock*)&cliente_1, &long);
	if (connfd < 0) {
		printf("¡¡ERROR!! EL SERVIDOR NO PUDO ACEPTAR AL CLIENTE \n");
		exit(0);
	}
	else
		printf("-->CLIENTE ACEPTADO CORRECTAMENTE\n");

	printf("-------------CONECTADO AL SERVIDOR------------------\n");

	fD_funcion(connfd); //mandamos a llamar a la función del file descriptor
	close(sockfd);  //CERRAR CLIENTE
}
