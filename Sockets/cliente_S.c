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

//función para pedir números
void pedir_Numeros (char numeros[]){
	printf ("Ingresa el número: ");
	scanf ("%d", numeros);
}


int main(int argc, char **argv)
{

	if(argc<2){
		printf("<HOST > <PUERTO>\n");
    	return 1;
  	}

	//DEFINIMOS LAS VARIABLES
	    //escuchar, file descriptor
	int sockfd, connfd;

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

	//crea la esctrucura address format
	memset(&servaddr,0,sizeof(servaddr));

	//asignar IP, Puerto y dirección IPv4
	servaddr.sin_family        = AF_INET;
	servaddr.sin_addr.s_addr   = htonl(INADDR_ANY);;
	servaddr.sin_port          = htons(atoi(argv[1]));  //este valor ordena los bits
	
    //CONECTAMOS LOS SOCKETS-- CLIENTE && SERVIDOR
	if (connect(sockfd, (Socket*)&servaddr, sizeof(servaddr)) != 0) {
		printf("¡¡ERROR!! LA CONEXIÓN FALLÓ\n");
		return -1;
	}
	else
		printf("-->CONEXIÓN CON SERVIDOR EXITOSO\n");

	fD_funcion(sockfd);  //LLAMADA A LA FUNCIÓN DEL FILE DESCRIPTOR
	close(sockfd); //TERMINAMOS EL SOCKET
}

void fD_funcion(int sockfd)
{
 char numero1[DATO_MAXIMO];
 char numero2[DATO_MAXIMO];
 char resultado[DATO_MAXIMO];
 char buff[DATO_MAXIMO]; //definimos buffer para recepción

 //borramos el área de memoria dada con cero byte
    bzero(buff, sizeof(buff));
	bzero(numero1, sizeof(numero1));
	bzero(numero2,sizeof(numero2));
	bzero(resultado,sizeof(resultado));

	//mandamos a llamar a la función para pedir los números
	pedir_Numeros(numero1);
	//función write: el cliente envía datos al servidor
    write(sockfd, numero1, sizeof(numero1));
    pedir_Numeros(numero2);
    write(sockfd, numero2, sizeof(numero2));

    bzero(buff, sizeof(buff));
	bzero(resultado,sizeof(resultado));

    //función read: lee lo que el servidor responde 
    //lee el resultado de la suma
    read(sockfd, resultado, sizeof(resultado)); 
	printf("\n ****RESULTADO= %s  (Longitud %d digitos)\n", resultado,strlen(resultado));
}
