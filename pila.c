#include "pila.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM_INICIAL 10
#define TAM_MINIMO 5
#define TAM_DOBLE 2*(pila->capacidad)
#define TAM_MITAD (pila->capacidad/2)
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

bool pila_redimensionar(pila_t* pila, size_t tam_nuevo) {

    void** datos_nuevo = realloc(pila->datos, tam_nuevo * sizeof(void*));
    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }
    pila->datos = datos_nuevo;
    pila->capacidad = tam_nuevo;
    return true;
}

pila_t* pila_crear(void){

	pila_t* pila= malloc(sizeof(pila_t));
    if (pila == NULL) {
        return NULL;
    }
    pila->datos = malloc(TAM_INICIAL * sizeof(void*));   
    pila->capacidad = TAM_INICIAL;
    pila->cantidad= 0;
    return pila;
    
}

bool pila_esta_vacia(const pila_t *pila){
	
	if (pila->cantidad == 0){
		return true;
	}
	return  false;
}

void pila_destruir(pila_t *pila){
	
	free(pila->datos);
	free(pila);
}

void* pila_ver_tope(const pila_t *pila){
	
	if (pila_esta_vacia(pila)) {
		return NULL;
	}	
	return pila->datos[pila->cantidad-1]; 
	
	
}

bool pila_apilar(pila_t *pila, void* valor){
	/* si falta espacio*/
	if ( pila->capacidad == pila->cantidad ){ 
			if( pila_redimensionar(pila, TAM_DOBLE) == false){
					return false;
			}
	}
	pila->datos[pila->cantidad]= valor;//en datos[largo] asigno &valor 
	pila->cantidad++;
	return true;

}

void* pila_desapilar(pila_t *pila){
	
	if (pila_esta_vacia(pila)){
		return NULL;
	}
	void* ultimo = pila->datos[(pila->cantidad)-1];
	pila->cantidad--; 	
	/* si sobra espacio*/
	if ( pila->cantidad == (pila->capacidad)/4 && pila->capacidad>TAM_MINIMO ){ 
		pila_redimensionar(pila, TAM_MITAD);
	}
	return ultimo;
	
}
