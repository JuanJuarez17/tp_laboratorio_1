/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct{
	int id;
	char name[50];
	char gender;
	float salary;
}sEmployee;

sEmployee* employee_new();
sEmployee* employee_newWithParam(int id, char* name, char gender, float salary);
void employee_print(sEmployee* pEmployee);
int employee_sortByName(void* pEmployee1, void* pEmployee2);

int main(void)
{
//	startTesting(1);  // ll_newLinkedList *
//	startTesting(2);  // ll_len *
//	startTesting(3);  // getNode - test_getNode
//	startTesting(4);  // addNode - test_addNode
//	startTesting(5);  // ll_add *
//	startTesting(6);  // ll_get *
//	startTesting(7);  // ll_set *
//	startTesting(8);  // ll_remove *
//	startTesting(9);  // ll_clear *
//	startTesting(10); // ll_deleteLinkedList *
//	startTesting(11); // ll_indexOf
//	startTesting(12); // ll_isEmpty *
//	startTesting(13); // ll_push *
//	startTesting(14); // ll_pop *
//	startTesting(15); // ll_contains
//	startTesting(16); // ll_containsAll
//	startTesting(17); // ll_subList
//	startTesting(18); // ll_clone
//	startTesting(19); // ll_sort */

	/** Creo una estructura LinkedList y la inicializo. **/
	LinkedList* employeesList = NULL;

	/** Uso ll_newLinkedList. **/
	employeesList = ll_newLinkedList();
	if(employeesList == NULL){
		printf("No se pudo conseguir memoria.\n");
	}

	/** Creo variables estructura sEmployee. **/
	sEmployee* emp1 = employee_newWithParam(1010, "Jose", 'm', 147000);
	sEmployee* emp2 = employee_newWithParam(1020, "Lucia", 'f', 160000);
	sEmployee* emp3 = employee_newWithParam(1030, "Marlene", 'f', 132000);
	sEmployee* emp4 = employee_newWithParam(1040, "Nicolas", 'm', 102000);
	sEmployee* emp5 = employee_newWithParam(1050, "Tamara", 'f', 99000);
	sEmployee* emp6 = employee_newWithParam(1060, "Leopoldo", 'm', 153000);
	sEmployee* emp7 = employee_newWithParam(1070, "Gabriel", 'm', 149000);
	sEmployee* emp8 = employee_newWithParam(1080, "Gaston", 'm', 163000);

	/** ll_add ---> Agrego 8 variables tipo sEmployee al LinkedList **/

	ll_add(employeesList, emp1);
	ll_add(employeesList, emp2);
	ll_add(employeesList, emp3);
	ll_add(employeesList, emp4);
	ll_add(employeesList, emp5);
	ll_add(employeesList, emp6);
	ll_add(employeesList, emp7);
	ll_add(employeesList, emp8);

	/** ll_len ---> Cuento los elementos que componen al LinkedList **/
	printf("El tamaño del ll es: %d\n", ll_len(employeesList));

	/** ll_get ---> Obtengo uno de los elementos (Pos. 2) almacenados en el LinkedList y lo imprimo en pantalla **/
	employee_print((sEmployee*)ll_get(employeesList, 2));

	/** ll_remove ---> Remuevo uno de los elementos (Pos. 1) almacenados en el LinkedList **/
	ll_remove(employeesList, 1);

	/** ll_set ---> Modifico los campos de uno de los elementos (Pos. 1) almacenados en el LinkedList **/
	sEmployee* emp9 = employee_newWithParam(1021, "Julian", 'm', 155000);
	ll_set(employeesList, 1, emp9);

	/** ll_indexOf ---> Obtengo en que indice del LinkedList se encuentra almacenado uno de los elementos e imprimo el retorno de indexOf **/
	printf("%d\n", ll_indexOf(employeesList, emp8));

	/** ll_isEmpty ---> Evaluo si el LindedList esta vacio o no **/
	printf("%d\n", ll_isEmpty(employeesList));

	/** ll_push ---> Agrego un elemento (Pos. 0) en modo "push" al LinkedList **/
	sEmployee* emp10 = employee_newWithParam(1090, "Camila", 'f', 102000);
	ll_push(employeesList, 0, emp10);

	/** ll_pop ---> Obtengo la direccion de memoria y remuevo uno de los elementos (Pos. 0) almacenados en el LinkedList **/
	ll_pop(employeesList, 0);

	/** ll_contains ---> Verifico si un elemento esta almacenado en el LinkedList **/
	printf("%d\n", ll_contains(employeesList, emp10));

	/** ll_sort ---> Ordeno el LinkedList por el campo "nombre" y lo imprimo en pantalla **/
	ll_sort(employeesList, employee_sortByName, 0);
	for(int i = 0; i < ll_len(employeesList); i++){
		employee_print((sEmployee*)ll_get(employeesList, i));
	}
	printf("----------------------------------------\n");

	/** ll_sublist ---> Creo una sublista (Pos. 0 - Pos. 5) del LinkedList original y la imprimo en pantalla **/
	LinkedList* employeesSubList = ll_subList(employeesList, 0, 5);
	for(int i = 0; i < ll_len(employeesSubList); i++){
		employee_print((sEmployee*)ll_get(employeesSubList, i));
	}
	printf("----------------------------------------\n");

	/** ll_clone ---> Clono la sublista creada en el paso anterior en un nuevo LinkedList **/
	LinkedList* employeesListCloned = ll_clone(employeesSubList);

	/** ll_containsAll ---> Verifico si el LinkedList original esta contenido en el LinkedList clonado **/
	printf("%d\n", ll_containsAll(employeesListCloned, employeesList));

	/** ll_clear ---> Elimino los elementos almacenados en la sublista creada e imprimo la cantidad de elementos resultantes **/
	ll_clear(employeesSubList);

	/** ll_deleteLinkedList ---> Elimino la sublista creada **/
	ll_deleteLinkedList(employeesSubList);

    return 0;
}

sEmployee* employee_new(){
	sEmployee* auxEmployee = NULL;
	auxEmployee = (sEmployee*) malloc(sizeof(sEmployee));
	if(auxEmployee != NULL){
		auxEmployee->id = 0;
		strcpy(auxEmployee->name, "");
		auxEmployee->gender = ' ';
		auxEmployee->salary = 0;
	}
	return auxEmployee;
}

sEmployee* employee_newWithParam(int id, char* name, char gender, float salary){
	sEmployee* newEmployee = employee_new();
    if(newEmployee != NULL && name != NULL){
    	newEmployee->id = id;
        strcpy(newEmployee->name, name);
        newEmployee->gender = gender;
        newEmployee->salary = salary;
    }
    return newEmployee;
}

void employee_print(sEmployee* pEmployee){
    printf("%d %s %c %.2f\n",
    		pEmployee->id,
			pEmployee->name,
			pEmployee->gender,
			pEmployee->salary);
}

int employee_sortByName(void* pEmployee1, void* pEmployee2){
    int rtn = 0;
    if(pEmployee1 != NULL && pEmployee2 != NULL){
        sEmployee* emp1 = (sEmployee*) pEmployee1;
        sEmployee* emp2 = (sEmployee*) pEmployee2;
        rtn = strcmp(emp1->name, emp2->name);
    }
    return rtn;
}
