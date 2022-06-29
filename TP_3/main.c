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
	int flagSaveFile = 0;
    do{
        switch(menu_main()){
            case 1:
            	if(ll_len(listaPasajeros)){
            		if(input_getResponse("Desea sobre escribir? (S/N): ", "Error! Desea sobre escribir? (S/N): ", 'S', 'N')){
						ll_clear(listaPasajeros);
		            	if(controller_loadFromText("data.csv",listaPasajeros)){
		            		printf("Se cargaron %d pasajeros.\n", ll_len(listaPasajeros));
		            	}
            		}
					else{
						printf("Sobre escritura cancelada.\n");
					}
            	}
            	else{
            		if(controller_loadFromText("data.csv",listaPasajeros)){
            			printf("Se cargaron %d pasajeros.\n", ll_len(listaPasajeros));
					}
            	}
                break;
            case 2:
            	if(ll_len(listaPasajeros)){
            		if(input_getResponse("Desea sobre escribir? (S/N): ", "Error! Desea sobre escribir? (S/N): ", 'S', 'N')){
						ll_clear(listaPasajeros);
		            	if(controller_loadFromBinary("dataBIN.bin", listaPasajeros)){
		            		printf("Se cargaron %d pasajeros.\n", ll_len(listaPasajeros));
		            	}
            		}
					else{
						printf("Sobre escritura cancelada.\n");
					}
            	}
            	else{
                	if(controller_loadFromBinary("dataBIN.bin", listaPasajeros)){
                		printf("Se cargaron %d pasajeros.\n", ll_len(listaPasajeros));
                	}
            	}
                break;
            case 3:
            	controller_addPassenger(listaPasajeros);
                break;
            case 4:
            	if(!ll_len(listaPasajeros)){
            		printf("Primero debe cargar empleados.\n");
            	}
            	else{
                	controller_editPassenger(listaPasajeros);
            	}
                break;
            case 5:
            	if(!ll_len(listaPasajeros)){
            		printf("Primero debe cargar empleados.\n");
            	}
            	else{
            		controller_removePassenger(listaPasajeros);
            	}
                break;
            case 6:
              	if(!ll_len(listaPasajeros)){
					printf("Primero debe cargar empleados.\n");
				}
				else{
					controller_listPassenger(listaPasajeros);
				}
                break;
            case 7:
              	if(!ll_len(listaPasajeros)){
					printf("Primero debe cargar empleados.\n");
				}
				else{
					controller_sortPassenger(listaPasajeros);
				}
                break;
            case 8:
              	if(!ll_len(listaPasajeros)){
					printf("Primero debe cargar empleados.\n");
				}
				else{
	            	if(controller_saveAsText("dataTXT.csv", listaPasajeros)){
	            		printf("Archivo de texto guardado con exito.\n");
	            		flagSaveFile = 1;
	            	}
	            	else{
	            		printf("No se pudo guardar el archivo de texto.\n");
	            	}
				}
                break;
            case 9:
              	if(!ll_len(listaPasajeros)){
					printf("Primero debe cargar empleados.\n");
				}
				else{
	            	if(controller_saveAsBinary("dataBIN.bin", listaPasajeros)){
	            		printf("Archivo binario guardado con exito.\n");
	            		flagSaveFile = 1;
	            	}
	            	else{
	            		printf("No se pudo guardar el archivo binario.\n");
	            	}
				}
                break;
            case 10:
            	if(flagSaveFile){
                	controller_exitProgram(&exit);
                	ll_deleteLinkedList(listaPasajeros);
            	}
            	else{
            		printf("Antes de salir del programa debe guardar el archivo.\n");
            	}
                break;
            case 11:
            	printf("Error! Ingrese un numero.\n");
            	break;
            default:
            	printf("Opcion invalida!\n");
            	break;
        }
        system("pause");
    }while(exit != 'S');

    return EXIT_SUCCESS;
}

