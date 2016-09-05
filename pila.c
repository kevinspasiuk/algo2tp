#include "pila.h"
#include <stdlib.h>

/**** CONSULTAS ****
  FIJARSE SI ESTA VACIA CON largo? O CON TAM?
*/


/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t capacidad;
    size_t cantidad;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
pila_t* pila_crear(void){
	pila_t* pila= malloc(sizeof(pila_t));

    if (pila == NULL) {
        return NULL;
    }
    pila->datos = malloc(sizeof(*pila->datos));

    if (*pila->datos == NULL) {
        free(pila);
        return NULL;
    }
    pila->datos[0]=NULL;
    pila->capacidad = sizeof(*pila->datos);
    pila->cantidad= 0;
    return pila;
}
	


bool pila_esta_vacia(const pila_t *pila){
	if (pila->cantidad==0){
		return true;
	}
	return  false;
}


void pila_destruir(pila_t *pila){

	if (pila_esta_vacia(pila) == false){
		for (int i=0; i< pila->cantidad; i++){		
			free (pila->datos[i]);
		}
	}
	free(pila->datos);
	pila->datos=NULL;
	free(pila);
}



void* pila_ver_tope(const pila_t *pila){
	
	if (pila_esta_vacia(pila)) {
		return NULL;
	}	
	return &(pila->datos[pila->cantidad-1]);
	
}

bool pila_apilar(pila_t *pila, void* valor){
	
	if ( pila->capacidad/sizeof(pila->datos[0]) < pila->cantidad ){ /* falta espacio*/
			void** datos_nuevo = realloc(pila->datos, 2* pila->capacidad);
			pila->datos= datos_nuevo;
	// realloc== null return true?
	}
	pila->datos[pila->cantidad]= valor;//en datos[largo] asigno &valor 
	pila->cantidad++;
	return false;
}


void* pila_desapilar(pila_t *pila){
	
	if (pila_ver_tope(pila) == NULL){
		return NULL;
	}
	void* ultimo = &(pila->datos[pila->cantidad -1]);
	free(pila->datos[pila->cantidad -1]);
	pila->datos[pila->cantidad -1]=NULL;
	pila->cantidad--; 	
	
	if ( pila->cantidad == (pila->capacidad)/4 ){ /* sobra espacio*/
		void** datos_nuevo = realloc(pila->datos, (pila->capacidad)/2);
		pila->datos= datos_nuevo;
	}
	return ultimo;
	
}


