#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


// pila sin elementos
void prueba_pila_nulo(){
	
	//variable
	pila_t* p= pila_crear();
	
	//prueba con pila vacia
	printf("\nPRUEBA CON PILA VACIA \n");
	print_test("Pila vacia", pila_esta_vacia(p) == true); 
	print_test("Tope Null",pila_ver_tope(p) == NULL);	
	print_test("desapilo", pila_desapilar(p) == NULL);
	
	//Destruyo la pila
	pila_destruir(p);	
	print_test("pila destruida", true);

}

void pruebas_algunos_elementos() {
	pila_t* p = pila_crear();
		
	//apilo algunos elementos
	int a=1,b=2,c=3;
    printf("\nPRUEBA CON ALGUNOS ELEMENTOS \n");
	print_test("apilar 1er valor", pila_apilar(p,&a) != false);
	print_test("apilar 2do valor", pila_apilar(p,&b) != false);
	print_test("apilar 3er valor", pila_apilar(p,&c) != false);

	//control si esta vacia 
	print_test("No esta vacia", pila_esta_vacia(p) == false);
    
    //control tope
	print_test("tope = 3", pila_ver_tope(p) == &c); 
	
	//desapilo y consulto tope
	print_test("Desapilo por 1era vez", pila_desapilar(p) == &c);
	print_test("tope = 2", pila_ver_tope(p) == &b);
	print_test("Desapilo por 2da vez", pila_desapilar(p) == &b);
	print_test("tope = 1", pila_ver_tope(p) == &a);	
	print_test("Desapilo por 3ra vez", pila_desapilar(p) == &a);
	print_test("tope = NULL", pila_ver_tope(p) == NULL);
	
	//control si esta vacia
	print_test("Esta vacia", pila_esta_vacia(p) == true);
		
	//Destruyo la pila
	pila_destruir(p);	
	print_test("pila destruida", true);
	
}

void pruebas_muchos_elementos() {
	
	printf("\nPRUEBA CON MUCHOS ELEMENTOS \n");
	//variables
	pila_t* p = pila_crear();
	int a=1,b=3,i;
	pila_apilar(p, &b);
	
	// cargo muchos elementos. 
	for (i=1; i<990; i++){
		pila_apilar(p, &a);
	}
	printf("Se apilaron %d elementos \n",i);
	
	//apilo uno distinto y controlo el tope
	printf("Apilando elemento distinto\n");
	print_test("apilar valor 3", pila_apilar(p,&b) != false);
	print_test("tope = 3", pila_ver_tope(p) == &b); 
	
	//desapilo todo
	printf("Desapilando elementos\n");
	for (i=991; i>0; i--){
		pila_desapilar(p);
	}
	printf("Prueba de conscutivos\n");
	for ( i=0; i<20; i++){
		pila_apilar(p, &a);
		pila_desapilar(p);
	}
	
	//Destruyo la pila
	pila_destruir(p);	
	print_test("pila destruida", true);
	
}

//Prueba con elementos == NULL
void prueba_todo_nulo() {

	printf("\nPRUEBA ELEMENTOS TODOS NULL\n");
	pila_t* p = pila_crear();
	int *a=NULL;
	print_test("apilar NULL", pila_apilar(p,&a) != false);
	print_test("No esta vacia", pila_esta_vacia(p) == false);
	print_test("apilar NULL", pila_apilar(p,&a) != false);
	print_test("Desapilo una vez", pila_desapilar(p) == &a);
	print_test("No esta vacia", pila_esta_vacia(p) == false);
	print_test("tope = NULL", pila_ver_tope(p) == &a);
	print_test("Desapilo dos veces", pila_desapilar(p) == &a);
	print_test("tope = NULL", pila_ver_tope(p) == NULL);
	print_test("Esta vacia", pila_esta_vacia(p) == true);
	
	//Destruyo la pila
	pila_destruir(p);	
	print_test("pila destruida", true);
	
}

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;
	
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
		
	//inicio de pruebas
	prueba_pila_nulo();
	prueba_todo_nulo();
	pruebas_algunos_elementos();
	pruebas_muchos_elementos();

	
}

