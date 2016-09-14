#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void prueba_un_elemento(){
	printf("~~~ PRUEBA 1 ELEMENTO ~~~\n");
	//variables
	int a=1;
	cola_t* cola = cola_crear();
	
	if (cola != NULL){
		print_test("Cola esta vacia", cola_esta_vacia(cola) == true );
		
		//encolo algunos elementos
		if (cola_encolar(cola,&a)){
			printf("elemento 1 encolado = True \n");
			print_test("elemento desencolado = 1 ", cola_desencolar(cola)== &a);	
		}
		print_test("elemento desencolado = null ", cola_desencolar(cola)== NULL);
		//destruyo cola
		cola_destruir(cola, NULL);
	}	

}

void prueba_elementos(){
	printf("~~~ PRUEBA VARIOS ELEMENTOS ~~~\n");
	printf("En stack \n");
	//variables
	int a=1,b=2,c=3;
	cola_t* cola = cola_crear();
	
	if (cola != NULL){
		print_test("Cola esta vacia", cola_esta_vacia(cola) == true );
		
		//encolo algunos elementos
		if (cola_encolar(cola,&a)){
			printf("elemento 1 encolado = True \n");
		}	
		if (cola_encolar(cola,&b)){
			printf("elemento 2 encolado = True \n");
		}
		if (cola_encolar(cola,&c)){
			printf("elemento 3 encolado = True \n");
		}

		print_test("ver primero = 1 ", cola_ver_primero(cola)== &a);
		print_test("elemento desencolado = 1 ", cola_desencolar(cola)== &a);
		print_test("ver primero = 2 ", cola_ver_primero(cola)== &b);
		print_test("elemento desencolado = 2 ", cola_desencolar(cola)== &b);
		print_test("ver primero = 3 ", cola_ver_primero(cola)== &c);
		print_test("elemento desencolado = 3 ", cola_desencolar(cola)== &c);
		print_test("ver primero = NULL ", cola_ver_primero(cola)== NULL);		
	
		//destruyo cola
		cola_destruir(cola, NULL);
	}

}

void prueba_destruccion(){
	printf("~~~ PRUEBA DE DESTRUCCION ~~~\n");
	
	//variables
	int a=1;
	cola_t* cola = cola_crear();
	
	if (cola != NULL){
		print_test("Cola esta vacia", cola_esta_vacia(cola) == true );
		
		// encolo algunos elementos
		for(int i=0; i<5; i++){
			cola_encolar(cola,&a);
		}
		//destruyo cola
		cola_destruir(cola, NULL);
	}	
	printf("En heap \n");
	
	//variables
	int* b= malloc(sizeof(int)); 
	int* c= malloc(sizeof(int)); 
	int* d= malloc(sizeof(int)); 		
	cola_t* cola2 = cola_crear();
	*b=3;
	*c=4;
	*d=5;
	if (cola2 != NULL){
		print_test("Cola esta vacia", cola_esta_vacia(cola2) == true );
		
		//encolo algunos punteros
		cola_encolar(cola2, b);
		cola_encolar(cola2, c);
		cola_encolar(cola2, d);
	
		//destruyo cola
		cola_destruir(cola2, free);
	}
}

void prueba_volumen(){
	printf("~~~ PRUEBA DE VOLUMEN ~~~\n");
	
	//variables
	int a=1;
	cola_t* cola = cola_crear();
	
	if (cola != NULL){
		print_test("Cola esta vacia", cola_esta_vacia(cola) == true );
		
		//encolo algunos elementos
		printf("Encolando muchos elementos\n");
		for(int i=0; i<80; i++){
			cola_encolar(cola,&a);
		}
		print_test("Cola NO esta vacia", cola_esta_vacia(cola) == false );
		//destruyo cola
		cola_destruir(cola, NULL);
	}	
}

void pruebas_cola_alumno() {
    cola_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
		
	//inicio de pruebas
	prueba_un_elemento();
	prueba_elementos();
	prueba_destruccion();
	prueba_volumen();
}

