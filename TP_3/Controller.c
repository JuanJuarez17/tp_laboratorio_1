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
	FILE* fileAux = NULL;
	if(path != NULL && pArrayListPassenger != NULL){
		fileAux = fopen(path, "rb");
		if(fileAux != NULL){
			if(parser_PassengerFromBinary(fileAux, pArrayListPassenger)){
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
	char confirm;

	// INICIO DEBUG
	//printf("Debug: %d\n", type);
	// FIN DEBUG

	if(pArrayListPassenger != NULL){
		id = Passenger_getNextId(pArrayListPassenger);
		if(id != 0){
			if(utn_getString(name, "Ingrese nombre del pasajero: ", "Error! ", 1, 128, 3)
			&& utn_getString(lastName, "Ingrese apellido del pasajero: ", "Error! ", 1, 128, 3)
			&& utn_getFloat(&price, "Ingrese precio del pasaje: ", "Error! ", 10000, 50000, 3)
			&& input_getPassengerFlyCode(flyCode)
			&& input_getPassengerStatusFly(flyCode, &status)
			&& input_getPassengerType(&type)){
				/*// INICIO DEBUG
				printf("Debug: %s\n", name);
				printf("Debug: %s\n", lastName);
				printf("Debug: %.2f\n", price);
				printf("Debug: %d\n", type);
				printf("Debug: %s\n", flyCode);
				printf("Debug: %d\n", status);
				system("pause");
				// FIN DEBUG*/
				Passenger_setId(auxPassenger, id);
				Passenger_setName(auxPassenger, name);
				Passenger_setlastName(auxPassenger, lastName);
				Passenger_setPrice(auxPassenger, price);
				Passenger_setFlyCode(auxPassenger, flyCode);
				Passenger_setStatusFly(auxPassenger, status);
				Passenger_setTypePassenger(auxPassenger, type);
				/*// INICIO DEBUG
				printf("Debug: %s\n", auxPassenger->name);
				printf("Debug: %s\n", auxPassenger->lastName);
				printf("Debug: %.2f\n", auxPassenger->price);
				printf("Debug: %d\n", auxPassenger->typePassenger);
				printf("Debug: %s\n", auxPassenger->flyCode);
				printf("Debug: %d\n", auxPassenger->statusFly);
				// FIN DEBUG*/
				if(auxPassenger != NULL){
					Passenger_print(auxPassenger);
					printf("\nConfirma alta? (S/N): "); // Pido confirmar
					fflush(stdin); // Siempre que recibamos un char
					scanf("%c", &confirm); // Recibo respuesta
					confirm = toupper(confirm);
					while(!(input_validateChar(confirm, 'S', 'N'))){
						printf("Error! Confirma alta? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
					}
					if(confirm == 'S'){ // Valido que sea sea afirmativo
						ll_add(pArrayListPassenger, auxPassenger);
						printf("Alta de pasajero exitosa.\n"); // Aviso del cambio
						rtn = 1;
					}
					else{ // Si no es afirmativo
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
	char confirm;
	char name[PASSENGER_NAME_LEN_MAX];
	char lastName[PASSENGER_NAME_LEN_MAX];
	float price;
	char flyCode[PASSENGER_FLYCODE_LEN_MAX];
	int status;
	int type;
	sPassenger *auxPassenger = NULL;
	if(pArrayListPassenger != NULL) {
		if(utn_getInt(&id, "Ingrese ID del pasajero: ", "Error! ID incorrecto\n", 1, ll_len(pArrayListPassenger), 3)) {
			if(Passenger_findById(pArrayListPassenger, &index, id)) {
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, index);
				if(auxPassenger != NULL) {
					Passenger_print(auxPassenger);
					switch(menu_edit()){
					case 1:
						utn_getString(name, "Ingrese nombre del pasajero: ", "Error!", 1, 128, 3);
						printf("Confirma modificacion? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
						while(!(input_validateChar(confirm, 'S', 'N'))){
							printf("Error! Confirma modificacion? (S/N): ");
							fflush(stdin);
							scanf("%c", &confirm);
							confirm = toupper(confirm);
						}
						if(confirm == 'S'){
							Passenger_setName(auxPassenger, name);
							printf("Modificacion exitosa.\n");
							rtn = 1;

						}
						else{
							printf("Baja cancelada.\n");
						}
						break;
					case 2:
						utn_getString(lastName, "Ingrese apellido del pasajero: ", "Error!", 1, 128, 3);
						printf("Confirma modificacion? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
						while(!(input_validateChar(confirm, 'S', 'N'))){
							printf("Error! Confirma modificacion? (S/N): ");
							fflush(stdin);
							scanf("%c", &confirm);
							confirm = toupper(confirm);
						}
						if(confirm == 'S'){
							Passenger_setlastName(auxPassenger, lastName);
							printf("Modificacion exitosa.\n");
							rtn = 1;
						}
						else{
							printf("Baja cancelada.\n");
						}
						break;
					case 3:
						utn_getFloat(&price, "Ingrese precio del pasaje: ", "Error. Ingrese precio del pasaje: ", 10000, 50000, 3);
						printf("Confirma modificacion? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
						while(!(input_validateChar(confirm, 'S', 'N'))){
							printf("Error! Confirma modificacion? (S/N): ");
							fflush(stdin);
							scanf("%c", &confirm);
							confirm = toupper(confirm);
						}
						if(confirm == 'S'){
							Passenger_setPrice(auxPassenger, price);
							printf("Modificacion exitosa.\n");
							rtn = 1;
						}
						else{
							printf("Baja cancelada.\n");
						}
						break;
					case 4:
						input_getPassengerType(&type);
						printf("Confirma modificacion? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
						while(!(input_validateChar(confirm, 'S', 'N'))){
							printf("Error! Confirma modificacion? (S/N): ");
							fflush(stdin);
							scanf("%c", &confirm);
							confirm = toupper(confirm);
						}
						if(confirm == 'S'){
							Passenger_setTypePassenger(auxPassenger, type);
							printf("Modificacion exitosa.\n");
							rtn = 1;
						}
						else{
							printf("Baja cancelada.\n");
						}
						break;
					case 5:
						input_getPassengerFlyCode(flyCode);
						input_getPassengerStatusFly(flyCode, &status);
						printf("Confirma modificacion? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
						while(!(input_validateChar(confirm, 'S', 'N'))){
							printf("Error! Confirma modificacion? (S/N): ");
							fflush(stdin);
							scanf("%c", &confirm);
							confirm = toupper(confirm);
						}
						if(confirm == 'S'){
							Passenger_setFlyCode(auxPassenger, flyCode);
							Passenger_setStatusFly(auxPassenger, status);
							printf("Modificacion exitosa.\n");
							rtn = 1;
						}
						else{
							printf("Baja cancelada.\n");
						}
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
	char confirm;
	sPassenger *auxPassenger = NULL;
	if(pArrayListPassenger != NULL) {
		if(utn_getInt(&id, "Ingrese ID del pasajero: ", "Error! ID incorrecto\n", 1, ll_len(pArrayListPassenger), 3)) {
			if(Passenger_findById(pArrayListPassenger, &index, id)) {
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, index);
				if(auxPassenger != NULL) {
					Passenger_print(auxPassenger);
					printf("\nConfirma baja? (S/N): "); // Pido confirmar
					fflush(stdin); // Siempre que recibamos un char
					scanf("%c", &confirm); // Recibo respuesta
					confirm = toupper(confirm);
					while(!(input_validateChar(confirm, 'S', 'N'))) {
						printf("Error! Confirma baja? (S/N): ");
						fflush(stdin);
						scanf("%c", &confirm);
						confirm = toupper(confirm);
					}
					if(confirm == 'S') { // Valido que sea sea afirmativo
						if(ll_pop(pArrayListPassenger, index)) {
							printf("Baja exitosa.\n"); // Aviso del cambio
							Passenger_delete(auxPassenger);
							rtn = 1;
						}
					}
					else
					{ // Si no es afirmativo
						printf("Baja cancelada.\n");
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

int controller_listPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	int id;
	char name[PASSENGER_NAME_LEN_MAX];
	char lastName[PASSENGER_NAME_LEN_MAX];
	float price;
	int statusFly;
	char flyCode[5];
	int typePassenger;
	sPassenger* auxPassenger;
	if(pArrayListPassenger != NULL){
        printf("\n                                       - LISTA DE PASAJEROS -                                      \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < ll_len(pArrayListPassenger); i++){
        	auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
        	if(auxPassenger != NULL){
          		if(Passenger_getId(auxPassenger, &id)
            	       && Passenger_getName(auxPassenger, name)
    				   && Passenger_getlastName(auxPassenger, lastName)
    				   && Passenger_getPrice(auxPassenger, &price)
    				   && Passenger_getTypePassenger(auxPassenger, &typePassenger)
    				   && Passenger_getFlyCode(auxPassenger, flyCode)
    				   && Passenger_getStatusFly(auxPassenger, &statusFly)){
                	    printf("%4d   %-18s %-18s %8.2f   %10d        %6s            %10d\n",
                	           id,
        					   name,
        					   lastName,
        					   price,
        					   typePassenger,
        					   flyCode,
        					   statusFly);
        		}
        	    rtn = 1;
        	}
		}
	}
	return rtn;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	char exit = 'N';
	int crit;
	int sCrit;
	if(pArrayListPassenger != NULL){
            switch(menu_sort()){
                case 1:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareById, crit);
                    break;
                case 2:
                    printf("Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareByName, crit);
                    break;
                case 3:
                    printf("Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareByLastName, crit);
                    break;
                case 4:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareByTypePassenger, crit);
                    break;
                case 5:
                    printf("Ingrese criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: A-Z - 0: Z-A): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareByFlyCode, crit);
                    break;
                case 6:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    sCrit = scanf("%d", &crit);
                    while(!(input_validateIntRange(sCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        sCrit = scanf("%d", &crit);
                    }
                    ll_sort(pArrayListPassenger, Passenger_compareByStatusFly, crit);
                    break;
                case 7:
                	controller_exitProgram(&exit);
                    break;
                default:
                    printf("Opcion invalida!.\n");
                    break;
            }
            rtn = 1;
            printf("Elija la opcion 6 para listar los pasajeros.\n");
            system("pause");
	}
    return rtn;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	FILE* auxFile = NULL;
	sPassenger* auxPassenger = NULL;
	if(path != NULL && pArrayListPassenger != NULL){
		auxFile = fopen(path, "w");
		if(auxFile != NULL){
			fprintf(auxFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					fprintf(auxFile, "%d,%s,%s,%f,%s,%d,%d\n",
							auxPassenger->id,
							auxPassenger->name,
							auxPassenger->lastName,
							auxPassenger->price,
							auxPassenger->flyCode,
							auxPassenger->typePassenger,
							auxPassenger->statusFly);
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

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
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
}

void controller_exitProgram(char *pExit)
{
	if (pExit != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pExit);
		*pExit = toupper(*pExit);

		while(!(input_validateChar(*pExit, 'S', 'N'))){
            printf("Error! Confirma salida? (S/N): ");
            fflush(stdin);
            scanf("%c", pExit);
            *pExit = toupper(*pExit);
		}
	}
}
