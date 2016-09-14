#include "cola.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo_cola {
		void* dato;
		struct nodo_cola* siguiente;
}nodo_cola_t;

struct cola {
	nodo_cola_t* primero;
	nodo_cola_t* ultimo;
};



/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void){
	
	cola_t* cola= malloc(sizeof(cola_t));
    if (cola == NULL) {
        return NULL;
    }
	cola->primero=NULL;
	cola->ultimo=NULL;
    return cola;		
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	
	if (cola == NULL) return;
	while ( !cola_esta_vacia(cola)){
		void* p = cola_desencolar(cola);
		if (destruir_dato != NULL && p!=NULL){
			destruir_dato(p);
		}	
	}
	free(cola);
	
}

bool cola_esta_vacia(const cola_t *cola){
	//COLA !=NULL
	if (cola->primero == NULL && cola->ultimo== NULL){
		 return true;
	}  
	return false;
}

bool cola_encolar(cola_t *cola, void* valor){
	
	nodo_cola_t* nodo = malloc(sizeof(nodo_cola_t));
	if (nodo == NULL ) {
		return false;
	}
	nodo->dato= valor;
	nodo->siguiente= NULL;
	if (cola_esta_vacia(cola)){
		cola->primero= nodo;
		cola->ultimo= nodo;
		return true;
	}
	cola->ultimo->siguiente=nodo;
	cola->ultimo= nodo;
	return true;
}

void* cola_ver_primero(const cola_t *cola){
	
	if (cola_esta_vacia(cola)){
		return NULL;
	}
	return cola->primero->dato;
	
}

void* cola_desencolar(cola_t *cola){
	if (cola_esta_vacia(cola)){
			return NULL;
	}
	nodo_cola_t* aux= cola->primero;
	cola->primero= aux->siguiente;
	void* dato= aux->dato;
	if (aux->siguiente == NULL){// solo un elemento
		cola->ultimo= NULL;
	}
	
	free(aux);
	return dato;
}
