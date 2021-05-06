#include "scheduler.h"
#include <pthread.h> //cabecera para el hilo 

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);



 //Creamos una funciòn o una rutina que es invocada cada que un hilo comience su ejecuciòn
 //Si el Hilo se crea correctamente retorna 0
 //Lo ùnico que esta funciòn realiza es imprimir la acciòn de acuerdo a lo que se està realizando.
    void *rMusica(*void args){
        printf("Reproduciendo Música\n");
        return 0;
    }
    void *aYoutube(*void args){
        printf("Abriendo Youtube\n");
        return 0;
    }
    void *eTextoWord(*void args){
        printf("Escribiendo Texto en Word\n");
        return 0;
    }
    void *dArchivo(*void args){
        printf("Descargando archivo\n");
        return 0;
    }
    void *sArchivo(*void args){
        printf("Subiendo archivo\n");
        return 0;
    }
    void *cPrograma(*void args){
        printf("Compilando Programa\n");
        return 0;
    }
    void *ePrograma(*void args){
        printf("EjecutandoPrograma\n");
        return 0;
    }
    void *uTerminal(*void args){
        printf("Usando Terminal\n");
        return 0;
    }
    
 //Despuès de la funciòn main se crean los hilos y las variables de cada uno  
int main(int argc, char const *argv[]){
      
     //con pthread_t le asignamos un identificador o nombre a cada hilo
      pthread_t reproducir_Musica;
      pthread_t abrir_Youtube;
      pthread_t escribir_Texto_Word;
      pthread_t descargar_Archivo;
      pthread_t subiendo_Archivo;
      pthread_t compilando_Programa;
      pthread_t ejecutando_Programa;
      prhread_t usando_Terminal;
      
      //con la funciòn pthread_create creamos los hilo
      //como paràmetros tendrà el ID, atributos del hilo (por defecto), funcion o rutina invocada y los parametros de la funcion
       pthread_create (&reproducir_Musica, NULL, rMusica, NULL);
       pthread_create (&abrir_Youtube, NULL, aYoutube, NULL);
       pthread_create (&escribir_Texto_Word, NULL, eTextoWord, NULL);
       pthread_create (&descargar_Archivo, NULL, dArchivo, NULL);
       pthread_create (&subiendo_Archivo, NULL, sArchivo, NULL);
       pthread_create (&compilando_Programa, NULL, cPrograma, NULL);
       pthread_create (&ejecutando_Programa, NULL, ePrograma, NULL);
       pthread_create (&usando_Terminal, NULL, uTerminal, NULL);
       pthread_create (&usando_Terminal, NULL, uTerminal, NULL);
       
        process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}


//con Pthread_join esperamos a que un hilo termine de ejecutarse 
//Sus paràmetros son: identificador del hilo, y el valor que regresa una vez que el hilo se haya ejecutado.
void reproducir_musica(void){
   phtread_join (reproducir_Musica, Null)
}
void abrir_youtube(void){
   phtread_join (abrir_Youtube, Null)
}
void escribir_texto_word(void){
   phtread_join (escribir_Texto_Word, Null)
}
void descargar_archivo(void){
   phtread_join (descargar_Archivo, Null)
}
void subiendo_archivo(void){
   phtread_join (subiendo_Archivo, Null)
}
void compilando_programa(void){
   phtread_join (compilando_Programa, Null)
}
void ejecutando_programa(void){
   phtread_join (ejecutando_Programa, Null)
}
void usando_Terminal(void){
   phtread_join (usando_Terminal, Null)
}
