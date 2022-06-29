#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"
#include "parser.h"
#include "Controller.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	FILE* file = NULL;
	if(path != NULL && pArrayListPassenger != NULL){
		file = fopen(path, "r");
		if(file != NULL){
			if(parser_PassengerFromText(file, pArrayListPassenger)){
				printf("Carga de archivo exitosa.\n");
				rtn = 1;
			}
			else{
				printf("Error! No se pudo cargar el archivo.\n");
			}
		}
	}
    return rtn;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	FILE* file = NULL;
	if(path != NULL && pArrayListPassenger != NULL){
		file = fopen(path, "rb");
		if(file != NULL){
			if(parser_PassengerFromBinary(file, pArrayListPassenger)){
				printf("Carga de archivo exitosa.\n");
				rtn = 1;
			}
			else{
				printf("Error! No se pudo cargar el archivo.\n");
			}
		}
	}
    return rtn;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	sPassenger* auxPassenger = Passenger_new();
	int id;
	char name[PASSENGER_NAME_LEN_MAX];
	char lastName[PASSENGER_NAME_LEN_MAX];
	float price;
	char flyCode[PASSENGER_FLYCODE_LEN_MAX];
	int status;
	int type;
	if(pArrayListPassenger != NULL){
		id = Passenger_getNextId(pArrayListPassenger);
		if(id != 0){
			if(input_getString(name, "Ingrese nombre del pasajero: ", "Error! ", 1, 128, 3)
			&& input_getString(lastName, "Ingrese apellido del pasajero: ", "Error! ", 1, 128, 3)
			&& input_getFloat(&price, "Ingrese precio del pasaje: ", "Error! ", 10000, 50000, 3)
			&& input_getPassengerFlyCode(flyCode)
			&& input_getPassengerStatusFly(flyCode, &status)
			&& input_getPassengerType(&type)){
				Passenger_setId(auxPassenger, id);
				Passenger_setName(auxPassenger, name);
				Passenger_setlastName(auxPassenger, lastName);
				Passenger_setPrice(auxPassenger, price);
				Passenger_setFlyCode(auxPassenger, flyCode);
				Passenger_setStatusFly(auxPassenger, status);
				Passenger_setTypePassenger(auxPassenger, type);
				if(auxPassenger != NULL){
			        printf("\n---------------------------------------------------------------------------------------------------------\n");
			        printf(" ID    NOMBRE             APELLIDO            PRECIO    CLASE           CODIGO DE VUELO   ESTADO DE VUELO\n");
			        printf("---------------------------------------------------------------------------------------------------------\n");
					Passenger_print(auxPassenger);
            		if(input_getResponse("\nConfirma alta? (S/N): ", "Error! Confirma alta? (S/N): ", 'S', 'N')){
						ll_add(pArrayListPassenger, auxPassenger);
						printf("Alta de pasajero exitosa.\n");
						rtn = 1;
            		}
					else{
						printf("Alta de pasajero cancelada.\n");
					}
				}
				else{
					printf("Error! No se pudo realizar el alta del pasajero.\n");
				}
			}
		}
	}
    return rtn;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	int id;
	int index;
	char name[PASSENGER_NAME_LEN_MAX];
	char lastName[PASSENGER_NAME_LEN_MAX];
	float price;
	char flyCode[PASSENGER_FLYCODE_LEN_MAX];
	int status;
	int type;
	int lastID;
	sPassenger *auxPassenger = NULL;
	if(pArrayListPassenger != NULL) {
		lastID = Passenger_getNextId(pArrayListPassenger) - 1;
		if(input_getInt(&id, "Ingrese ID del pasajero: ", "Error! ID incorrecto\n", 1, lastID, 3)) {
			if(Passenger_findById(pArrayListPassenger, &index, id)) {
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, index);
				if(auxPassenger != NULL) {
			        printf("\n---------------------------------------------------------------------------------------------------------\n");
			        printf(" ID    NOMBRE             APELLIDO            PRECIO    CLASE           CODIGO DE VUELO   ESTADO DE VUELO\n");
			        printf("---------------------------------------------------------------------------------------------------------\n");
					Passenger_print(auxPassenger);
					switch(menu_edit()){
						case 1:
							input_getString(name, "Ingrese nombre del pasajero: ", "Error!", 1, 128, 3);
							if(input_getResponse("Confirma modificacion? (S/N): ", "Error! Confirma modificacion? (S/N): ", 'S', 'N')){
								Passenger_setName(auxPassenger, name);
								printf("Modificacion exitosa.\n");
								rtn = 1;
							}
							else{
								printf("Modificacion cancelada.\n");
							}
							break;
						case 2:
							input_getString(lastName, "Ingrese apellido del pasajero: ", "Error!", 1, 128, 3);
							if(input_getResponse("Confirma modificacion? (S/N): ", "Error! Confirma modificacion? (S/N): ", 'S', 'N')){
								Passenger_setlastName(auxPassenger, lastName);
								printf("Modificacion exitosa.\n");
								rtn = 1;
							}
							else{
								printf("Modificacion cancelada.\n");
							}
							break;
						case 3:
							input_getFloat(&price, "Ingrese precio del pasaje: ", "Error. Ingrese precio del pasaje: ", 10000, 50000, 3);
							if(input_getResponse("Confirma modificacion? (S/N): ", "Error! Confirma modificacion? (S/N): ", 'S', 'N')){
								Passenger_setPrice(auxPassenger, price);
								printf("Modificacion exitosa.\n");
								rtn = 1;
							}
							else{
								printf("Modificacion cancelada.\n");
							}
							break;
						case 4:
							input_getPassengerType(&type);
							if(input_getResponse("Confirma modificacion? (S/N): ", "Error! Confirma modificacion? (S/N): ", 'S', 'N')){
								Passenger_setTypePassenger(auxPassenger, type);
								printf("Modificacion exitosa.\n");
								rtn = 1;
							}
							else{
								printf("Modificacion cancelada.\n");
							}
							break;
						case 5:
							input_getPassengerFlyCode(flyCode);
							input_getPassengerStatusFly(flyCode, &status);
							if(input_getResponse("Confirma modificacion? (S/N): ", "Error! Confirma modificacion? (S/N): ", 'S', 'N')){
								Passenger_setFlyCode(auxPassenger, flyCode);
								Passenger_setStatusFly(auxPassenger, status);
								printf("Modificacion exitosa.\n");
								rtn = 1;
							}
							else{
								printf("Modificacion cancelada.\n");
							}
							break;
						case 6:
							printf("Error! Ingrese un numero.\n");
							break;
						default:
							printf("Opcion invalida!\n");
							break;
					}
				}
			}
			else {
				printf("Error! No se encontro el ID.\n");
			}
		}
		else {
			printf("Error! No existe esa cantidad de pasajeros.\n");
		}
	}
    return rtn;
}

int controller_removePassenger(LinkedList *pArrayListPassenger)
{
	int rtn = 0;
	int id;
	int index;
	int lastID;
	sPassenger *auxPassenger = NULL;
	if(pArrayListPassenger != NULL) {
		lastID = Passenger_getNextId(pArrayListPassenger) - 1;
		if(input_getInt(&id, "Ingrese ID del pasajero: ", "Error! ID incorrecto\n", 1, lastID, 3)) {
			if(Passenger_findById(pArrayListPassenger, &index, id)) {
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, index);
				if(auxPassenger != NULL) {
			        printf("\n---------------------------------------------------------------------------------------------------------\n");
			        printf(" ID    NOMBRE             APELLIDO            PRECIO    CLASE           CODIGO DE VUELO   ESTADO DE VUELO\n");
			        printf("---------------------------------------------------------------------------------------------------------\n");
					Passenger_print(auxPassenger);
            		if(input_getResponse("\nConfirma baja? (S/N): ", "Error! Confirma baja? (S/N): ", 'S', 'N')){
    					if(ll_pop(pArrayListPassenger, index)) {
							printf("Baja exitosa.\n");
							Passenger_delete(auxPassenger);
							rtn = 1;
						}
            		}
					else{
						printf("Baja cancelada.\n");
					}
				}
			}
			else{
				printf("El pasajero ya ha sido eliminado.\n");
			}
		}
	}
	return rtn;
}

int controller_listPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	sPassenger* auxPassenger;
	if(pArrayListPassenger != NULL){
        printf("\n                                         - LISTA DE PASAJEROS -                                        \n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf(" ID    NOMBRE             APELLIDO            PRECIO    CLASE           CODIGO DE VUELO   ESTADO DE VUELO\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < ll_len(pArrayListPassenger); i++){
        	auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
        	if(auxPassenger != NULL){
        		Passenger_print(auxPassenger);
        	    rtn = 1;
        	}
		}
	}
	return rtn;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	int crit;
	if(pArrayListPassenger != NULL){
            switch(menu_sort()){
                case 1:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareById, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 2:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareByName, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 3:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareByLastName, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 4:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareByTypePassenger, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 5:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareByFlyCode, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 6:
                	if(input_getInt(&crit, "Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ", "Error!\n", 0, 1, 3)) {
                		ll_sort(pArrayListPassenger, Passenger_compareByStatusFly, crit);
						printf("Elija la opcion 6 para listar los pasajeros.\n");
                	}
                    break;
                case 7:
                	printf("Error! Ingrese un numero.\n");
                    break;
                default:
                    printf("Opcion invalida!.\n");
                    break;
            }
            rtn = 1;
            system("pause");
	}
    return rtn;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	FILE* auxFile = NULL;
	sPassenger* auxPassenger = NULL;
	char typePassDesc[15];
	char statusFlyDesc[15];
	if(path != NULL && pArrayListPassenger != NULL){
		auxFile = fopen(path, "w");
		if(auxFile != NULL){
			fprintf(auxFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					Passenger_getStatusFlyDesc(statusFlyDesc, auxPassenger->statusFly);
					Passenger_getTypePassengerDesc(typePassDesc, auxPassenger->typePassenger);
					fprintf(auxFile, "%d,%s,%s,%f,%s,%s,%s\n",
							auxPassenger->id,
							auxPassenger->name,
							auxPassenger->lastName,
							auxPassenger->price,
							auxPassenger->flyCode,
							//auxPassenger->typePassenger,
							//auxPassenger->statusFly,
							typePassDesc,
							statusFlyDesc);
					rtn = 1;
				}
				else{
					Passenger_delete(auxPassenger);
				}
			}
		}
		fclose(auxFile);
	}
    return rtn;
}

/*int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) // Sin encabezado
{
	int rtn = 0;
	FILE* fileAux = NULL;
	sPassenger* auxPassenger = NULL;
	if(path != NULL && pArrayListPassenger != NULL){
		fileAux = fopen(path, "wb");
		if(fileAux != NULL){
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					fwrite(auxPassenger, sizeof(sPassenger), 1, fileAux);
				}
			}
			fclose(fileAux);
			rtn = 1;
		}
	}
    return rtn;
}*/

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) // Con encabezado
{
	int rtn = 0;
	FILE* fileAux = NULL;
	sPassenger* auxPassenger = NULL;
	char fileHeader[65] = "id,name,lastname,price,flycode,typePassenger,statusFlight\n";
	if(path != NULL && pArrayListPassenger != NULL){
		fileAux = fopen(path, "wb");
		if(fileAux != NULL){
			fwrite(fileHeader, sizeof(fileHeader), 1, fileAux);
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					fwrite(auxPassenger, sizeof(sPassenger), 1, fileAux);
				}
			}
			fclose(fileAux);
			rtn = 1;
		}
	}
    return rtn;
}

void controller_exitProgram(char *pExit)
{
	if (pExit != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pExit);
		*pExit = toupper(*pExit);

		while(!(input_validateCharOpt(*pExit, 'S', 'N'))){
            printf("Error! Confirma salida? (S/N): ");
            fflush(stdin);
            scanf("%c", pExit);
            *pExit = toupper(*pExit);
		}
	}
}
