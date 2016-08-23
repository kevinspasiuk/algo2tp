#include "tp0.h"
#include <stdio.h>

/* ******************************************************************
 *                     FUNCIONES A COMPLETAR
 * *****************************************************************/

/* swap() intercambia dos valores enteros.
 */
void swap (int* x, int* y) {
	int z;
    z = *x;
	*x = *y;
	*y = z;
}

/* maximo() busca el mayor elemento del arreglo y devuelve su posicion.
 * Si el vector es de largo 0, devuelve -1.
 */
int maximo(int vector[], int n) {
	if (n==0) {
		return -1;
	}
	
	int pos,max;		
	for (pos=max=0; pos<n; pos++){
		if  (vector[pos]>vector[max]) {
			max= pos;
		}
	}	
	return max;	
}

/* La función comparar recibe dos vectores y sus respectivas longitudes
 * y devuelve -1 si el primer vector es menor que el segundo; 0 si son
 * iguales; y 1 si el segundo es menor.
 *
 * Un vector es menor a otro cuando al compararlos elemento a elemento,
 * el primer elemento en el que difieren no existe o es menor.
 */
int comparar(int vector1[], int n1, int vector2[], int n2) {
	int i=0;
	while (i < n1 && i < n2){
		if (vector1[i] < vector2[i]){
			return -1;
		}
		else if (vector2[i] < vector1[i]){
			return 1;
		}
		i++;
	}
	if (i == n1 && i ==n2){
		return 0;
	}
	else if (i==n1){
		return -1;
	}
	else{
		return 1;
	}
}

/* selection_sort() ordena el arreglo recibido mediante el algoritmo de
 * selección.
 */

 
/*void seleccion(int vector[], int n) {
	int i,j;
	
	for (i=0; i < n-1; i++) {
		for (j=i+1; j < n; j++){
			if (vector[i] > vector[j]){
				swap(&vector[i],&vector[j]);
			}
		}
	}
}
*/
void seleccion(int vector[], int n) {
	int i,posMax,posUltimo;
	
	for (i=0; i < n; i++) {
		posMax= maximo(vector, n-i );		
		posUltimo= n-1;
		/* n-1 para que no acceda a espacio de memoria
		 * que no pertenezca al vector
		 */
		swap(&vector[posMax],&vector[posUltimo-i]);
			
		
	}
}
