#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    LinkedList* listaPasajeros = ll_newLinkedList();
	char exit = 'N';
	int passengerQty = 0;
	int flagSaveFile = 0;

    do{
    	passengerQty = ll_len(listaPasajeros);
        switch(menu_main())
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaPasajeros)){
            		passengerQty = ll_len(listaPasajeros);
            	}
                break;
            case 2:
            	if(controller_loadFromBinary("dataBIN.bin", listaPasajeros)){
            		passengerQty = ll_len(listaPasajeros);
            	}
                break;
            case 3:
            	controller_addPassenger(listaPasajeros);
                break;
            case 4:
            	if(passengerQty == 0){
            		printf("Primero debe cargar empleados.\n");
            	}
            	else{
                	controller_editPassenger(listaPasajeros);
            	}
                break;
            case 5:
            	if(passengerQty == 0){
            		printf("Primero debe cargar empleados.\n");
            	}
            	else{
            		controller_removePassenger(listaPasajeros);
            	}
                break;
            case 6:
              	if(passengerQty == 0){
                		printf("Primero debe cargar empleados.\n");
				}
				else{
					controller_listPassenger(listaPasajeros);
				}
                break;
            case 7:
              	if(passengerQty == 0){
                		printf("Primero debe cargar empleados.\n");
				}
				else{
					controller_sortPassenger(listaPasajeros);
				}
                break;
            case 8:
            	if(controller_saveAsText("dataTXT", listaPasajeros)){
            		printf("Archivo de texto guardado con exito.\n");
            		flagSaveFile = 1;
            	}
            	else{
            		printf("No se pudo guardar el archivo de texto.\n");
            	}
                break;
            case 9:
            	if(controller_saveAsBinary("dataBIN.bin", listaPasajeros)){
            		printf("Archivo binario guardado con exito.\n");
            		flagSaveFile = 1;
            	}
            	else{
            		printf("No se pudo guardar el archivo binario.\n");
            	}
                break;
            case 10:
            	if(flagSaveFile == 1){
                	controller_exitProgram(&exit);
                	ll_deleteLinkedList(listaPasajeros);
            	}
            	else{
            		printf("Antes de salir del programa debe guardar el archivo.\n");
            	}
                break;
            default:
            	printf("Opcion invalida!\n");
            	break;
        }
        system("pause");
    }while(exit != 'S');

    return EXIT_SUCCESS;
}

