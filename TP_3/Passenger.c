/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

sPassenger* Passenger_new(){
	sPassenger* auxPassenger = NULL;
	auxPassenger = (sPassenger*) malloc(sizeof(sPassenger));
	if(auxPassenger != NULL){
		auxPassenger->id = 0;
		strcpy(auxPassenger->name, "");
		strcpy(auxPassenger->lastName, "");
		auxPassenger->price = 0;
		strcpy(auxPassenger->flyCode, "");
		auxPassenger->typePassenger = 0;
		auxPassenger->statusFly = 0;
	}
	return auxPassenger;
}

sPassenger* Passenger_newParameters(char* id, char* name, char* lastName, char* price, char* flyCode, char* typePassenger, char* statusFly){
	sPassenger* rtnPassenger = Passenger_new();
	sPassenger* auxPassenger = Passenger_new();
	if(auxPassenger != NULL && rtnPassenger != NULL && id != NULL && name != NULL && lastName != NULL && price != NULL && flyCode != NULL && typePassenger != NULL && statusFly != NULL){
		if(Passenger_setId(auxPassenger, atoi(id))
	    && Passenger_setName(auxPassenger, name)
	    && Passenger_setlastName(auxPassenger, lastName)
	    && Passenger_setPrice(auxPassenger, atof(price))
	    && Passenger_setFlyCode(auxPassenger, flyCode)
	    && Passenger_setTypePassenger(auxPassenger, Passenger_setTypePassengerToInt(typePassenger))
	    && Passenger_setStatusFly(auxPassenger, Passenger_setStatusFlightToInt(statusFly))){
			rtnPassenger = auxPassenger;
		}
		else{
			Passenger_delete(auxPassenger);
		}
	}
	return rtnPassenger;
}

void Passenger_delete(sPassenger* this){
	free(this);
}

int Passenger_setId(sPassenger* this, int id){
	int rtn = 0;
	if(this != NULL && id > ID_INIT_PASSENGER && id < PASSENGER_MAX){
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getId(sPassenger* this, int* id){
	int rtn = 0;
	if(this != NULL && id != NULL){
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setName(sPassenger* this, char* name){
	int rtn = 0;
	if(this != NULL && name != NULL){
		strcpy(this->name, name);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getName(sPassenger* this, char* name){
	int rtn = 0;
	if(this != NULL && name != NULL){
		strcpy(name, this->name);
		rtn = 1;
	}
	return rtn;

}

int Passenger_setlastName(sPassenger* this, char* lastName){
	int rtn = 0;
	if(this != NULL && lastName != NULL){
		strcpy(this->lastName, lastName);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getlastName(sPassenger* this, char* lastName){
	int rtn = 0;
	if(this != NULL && lastName != NULL){
		strcpy(lastName, this->lastName);
		rtn = 1;
	}
	return rtn;
}

int Passenger_setPrice(sPassenger* this, float price){
	int rtn = 0;
	if(this != NULL && price >= 0 && price <= PASSENGER_PRICE_MAX){
		this->price = price;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getPrice(sPassenger* this, float* price){
	int rtn = 0;
	if(this != NULL && price != NULL){
		*price = this->price;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setFlyCode(sPassenger* this, char* flyCode){
	int rtn = 0;
	/*// INICIO DEBUG
	printf("Ingreso set: %s\n", flyCode);
	// FIN DEBUG*/
	if(this != NULL && flyCode != NULL && strlen(flyCode) == PASSENGER_FLYCODE_LEN_MAX){
		strcpy(this->flyCode, flyCode);
		rtn = 1;
	}
	/*// INICIO DEBUG
	printf("Salida set: %s\n", this->flyCode);
	// FIN DEBUG*/
	return rtn;
}

int Passenger_getFlyCode(sPassenger* this, char* flyCode){
	int rtn = 0;
	if(this != NULL && flyCode != NULL){
		strcpy(flyCode, this->flyCode);
		rtn = 1;
	}
	return rtn;
}

int Passenger_setTypePassenger(sPassenger* this, int typePassenger){
	int rtn = 0;
	if(this != NULL && typePassenger >= 1 && typePassenger <= 3){
		this->typePassenger = typePassenger;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getTypePassenger(sPassenger* this, int* typePassenger){
	int rtn = 0;
	if(this != NULL && typePassenger != NULL){
		*typePassenger = this->typePassenger;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setStatusFly(sPassenger* this, int statusFly){
	int rtn = 0;
	if(this != NULL && statusFly >= 1 && statusFly <= 4){
		this->statusFly = statusFly;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getStatusFly(sPassenger* this, int* statusFly){
	int rtn = 0;
	if(this != NULL && statusFly != NULL){
		*statusFly = this->statusFly;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setTypePassengerToInt(char* typePassenger){
	int rtn = 0;
	if(typePassenger != NULL){
		if(strcmp(typePassenger, "EconomyClass") == 0){
			rtn = 1;
		}
		if(strcmp(typePassenger, "ExecutiveClass") == 0){
			rtn = 2;
		}
		if(strcmp(typePassenger, "FirstClass") == 0){
			rtn = 3;
		}
	}
	return rtn;
}

int Passenger_setStatusFlightToInt(char* statusFly){
	int rtn = 0;
	if(statusFly != NULL){
		if(strcmp(statusFly, "Aterrizado") == 0){
			rtn = 1;
		}
		if(strcmp(statusFly, "Demorado") == 0){
			rtn = 2;
		}
		if(strcmp(statusFly, "En Horario") == 0){
			rtn = 3;
		}
		if(strcmp(statusFly, "En Vuelo") == 0){
			rtn = 4;
		}
	}
	return rtn;
}

int Passenger_compareById(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;
	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		if(auxPassenger1->id > auxPassenger2->id){
			rtn = 1;
		}
		else if(auxPassenger1->id < auxPassenger2->id){
			rtn = -1;
		}
	}
	return rtn;
}

int Passenger_compareByName(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;

	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		rtn = strcmp(auxPassenger1->name, auxPassenger2->name);
	}
	return rtn;
}


int Passenger_compareByLastName(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;

	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		rtn = strcmp(auxPassenger1->lastName, auxPassenger2->lastName);
	}
	return rtn;
}

int Passenger_compareByTypePassenger(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;
	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		if(auxPassenger1->typePassenger > auxPassenger2->typePassenger){
			rtn = 1;
		}
		else if(auxPassenger1->typePassenger < auxPassenger2->typePassenger){
			rtn = -1;
		}
	}
	return rtn;
}

int Passenger_compareByFlyCode(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;

	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		rtn = strcmp(auxPassenger1->flyCode, auxPassenger2->flyCode);
	}
	return rtn;
}

int Passenger_compareByStatusFly(void* this1, void* this2){
	int rtn = 0;
	sPassenger* auxPassenger1 = (sPassenger*) this1;
	sPassenger* auxPassenger2 = (sPassenger*) this2;
	if(auxPassenger1 != NULL && auxPassenger2 != NULL){
		if(auxPassenger1->statusFly > auxPassenger2->statusFly){
			rtn = 1;
		}
		else if(auxPassenger1->statusFly < auxPassenger2->statusFly){
			rtn = -1;
		}
	}
	return rtn;
}

int Passenger_getNextId(LinkedList* pArrayListPassenger){
	int nextID = 0;
	int arrayLength = 0;
	int counter = 0;
	sPassenger* auxPassenger = Passenger_new();
	if(auxPassenger != NULL){
		arrayLength = ll_len(pArrayListPassenger);
		if(arrayLength > 0){ // Si hay pasajeros en el ll
			for(int i = 0; i < arrayLength; i++){ // Recorro el ll
				auxPassenger = (sPassenger*) ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					if(counter == 0 || (auxPassenger->id > nextID && auxPassenger->id < PASSENGER_MAX)){
						nextID = auxPassenger->id;
						counter++;
					}
				}
			}
		}
		if(counter > 0){ // Si se conto algun pasajero dentro de ll
			nextID++; // Uno mas que el ultimo que se encontro
		}
		else{ // counter == 0
			nextID = 1;
		}
	}
	return nextID;
}

int Passenger_findById(LinkedList* pArrayListPassenger, int* pIndex, int id){
	int rtn = 0;
	int auxId;
	sPassenger* auxPassenger = NULL;
	if(pArrayListPassenger != NULL && pIndex != NULL && id > 0 && id <= PASSENGER_MAX){
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL){
				Passenger_getId(auxPassenger, &auxId);
				if(id == auxId){
					*pIndex = i;
					rtn = 1;
				}
			}
		}
	}
	return rtn;
}

int Passenger_print(sPassenger* this){
	int rtn = 0;
	int id;
	char name[PASSENGER_NAME_LEN_MAX];
	char lastName[PASSENGER_NAME_LEN_MAX];
	float price;
	char flyCode[PASSENGER_FLYCODE_LEN_MAX];
	int statusFly;
	int typePassenger;
	char typePassDesc[20];
	char statusFlyDesc[20];
	if(this != NULL){
        if(Passenger_getId(this, &id)
	   && Passenger_getName(this, name)
	   && Passenger_getlastName(this, lastName)
	   && Passenger_getPrice(this, &price)
	   && Passenger_getTypePassenger(this, &typePassenger)
	   && Passenger_getFlyCode(this, flyCode)
	   && Passenger_getStatusFly(this, &statusFly)){
			Passenger_getStatusFlyDesc(statusFlyDesc, this->statusFly);
			Passenger_getTypePassengerDesc(typePassDesc, this->typePassenger);
			printf("%4d   %-18s %-18s %8.2f   %-15s     %6s             %10s\n",
				   id,
				   name,
				   lastName,
				   price,
				   typePassDesc,
				   flyCode,
				   statusFlyDesc);
	        rtn = 1;
        }
	}
	return rtn;
}

int Passenger_getTypePassengerDesc(char* typePassDesc, int typePassenger){
    int rtn = 0;
    if(typePassDesc != NULL && typePassenger >= 1 && typePassenger <= 3){
        switch(typePassenger){
            case 1:
                strcpy(typePassDesc, "EconomyClass");
                break;
            case 2:
                strcpy(typePassDesc, "ExecutiveClass");
                break;
            case 3:
                strcpy(typePassDesc, "FirstClass");
                break;
        }
        rtn = 1;
    }
    return rtn;
}

int Passenger_getStatusFlyDesc(char* statusFlyDesc, int statusFly){
    int rtn = 0;
    if(statusFlyDesc != NULL && statusFly >= 1 && statusFly <= 4){
        switch(statusFly){
            case 1:
                strcpy(statusFlyDesc, "Aterrizado");
                break;
            case 2:
                strcpy(statusFlyDesc, "Demorado");
                break;
            case 3:
                strcpy(statusFlyDesc, "En Horario");
                break;
            case 4:
                strcpy(statusFlyDesc, "En Vuelo");
                break;
        }
        rtn = 1;
    }
    return rtn;
}
