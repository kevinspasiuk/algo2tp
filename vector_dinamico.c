#include "vector_dinamico.h"


// Funciones del alumno.

/* CONSULTAS:
POS NEGATIVA?, en pruebas no 
puntero en obtener
correcto de en_rango
*/

bool checkeo_rango(vector_t* vector, size_t pos){
	
	size_t tam;
	tam= vector_obtener_tamanio(vector);
	if (pos<tam){
		return true;
	}
	else 
		return false;

}


void vector_destruir(vector_t* vector){
	free(vector->datos);
	free(vector);
	vector=NULL;
	
}

bool vector_obtener(vector_t* vector, size_t pos, int* valor){
	
	bool en_rango;
	en_rango = checkeo_rango(vector,pos);
	if (en_rango==true){
		*valor= vector->datos[pos];
		return true;
	}	
	else{
		return false;
	}
	
	
}

bool vector_guardar(vector_t* vector, size_t pos, int valor){
	
	bool en_rango;
	en_rango= checkeo_rango(vector,pos);
	if (en_rango==true){
		vector->datos[pos]=valor;
		return true;
	}
	else{
		return false;
	}

}


size_t vector_obtener_tamanio(vector_t* vector){
	
	size_t tamanio;
	tamanio= vector->tam;
	return tamanio;	

}

// Funciones implementadas por la catedra.

vector_t* vector_crear(size_t tam) {
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL) {
        return NULL;
    }
    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL) {
        free(vector);
        return NULL;
    }
    vector->tam = tam;
    return vector;
}

bool vector_redimensionar(vector_t* vector, size_t tam_nuevo) {
    int* datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int));

    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }

    vector->datos = datos_nuevo;
    vector->tam = tam_nuevo;
    return true;
}
