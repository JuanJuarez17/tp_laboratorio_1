#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	char buffer[7][PASSENGER_NAME_LEN_MAX];
	sPassenger* auxPassenger;

	if(pFile != NULL && pArrayListPassenger != NULL){
		fscanf(pFile, "[^\n]\n");
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]) == 7){
				auxPassenger = Passenger_newParameters(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
			}
			if(auxPassenger != NULL){
				if(!ll_add(pArrayListPassenger, (sPassenger*) auxPassenger) && ll_len(pArrayListPassenger) < PASSENGER_MAX){
					rtn = 1;
				}
			}
		}
	}
	fclose(pFile);
    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = 1;
	sPassenger auxPassengerSt;
	sPassenger* auxPassengerDn = NULL;
	if(pFile != NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){
			fread(&auxPassengerSt, sizeof(sPassenger), 1, pFile);
			auxPassengerDn = Passenger_new();
			if(auxPassengerDn != NULL
			&& Passenger_setId(auxPassengerDn, auxPassengerSt.id)
			&& Passenger_setName(auxPassengerDn, auxPassengerSt.name)
			&& Passenger_setlastName(auxPassengerDn, auxPassengerSt.lastName)
			&& Passenger_setPrice(auxPassengerDn, auxPassengerSt.price)
			&& Passenger_setTypePassenger(auxPassengerDn, auxPassengerSt.typePassenger)
			&& Passenger_setFlyCode(auxPassengerDn, auxPassengerSt.flyCode)
			&& Passenger_setStatusFly(auxPassengerDn, auxPassengerSt.statusFly)){
				ll_add(pArrayListPassenger, auxPassengerDn);
				rtn = 1;
			}
		}
		fclose(pFile);
		Passenger_delete(auxPassengerDn);
	}

    return rtn;
}
