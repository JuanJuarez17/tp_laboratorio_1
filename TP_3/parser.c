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
	char fileHeader[65];
	sPassenger* auxPassenger;
	if(pFile != NULL && pArrayListPassenger != NULL){
		fscanf(pFile, "%[^\n]\n", fileHeader);
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
/*int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger) // Sin encabezado
{
	int rtn = 0;
	sPassenger auxPassengerSt; // Estructura estatica para guardar los datos leidos del archivo
	sPassenger* auxPassengerDn = NULL; // Estructura dinamica para agregar al ll
	if(pFile != NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){ // Hasta que el cursor haya llegado al final del archivo
			if(fread(&auxPassengerSt, sizeof(sPassenger), 1, pFile) == 1){ // Si la cantidad de elementos que se leyeron es igual a 1

				 Leo de pFile
				 Leo un elemento
				 El tamaño del elemento es el tamaño de la estructura sPassenger
				 Guardo lo leido en la variable estatica

				auxPassengerDn = Passenger_new(); // Inicializo la estructura dinamica
				if(auxPassengerDn != NULL // Valido si se consiguio espacio de memoria
				&& Passenger_setId(auxPassengerDn, auxPassengerSt.id)
				&& Passenger_setName(auxPassengerDn, auxPassengerSt.name)
				&& Passenger_setlastName(auxPassengerDn, auxPassengerSt.lastName)
				&& Passenger_setPrice(auxPassengerDn, auxPassengerSt.price)
				&& Passenger_setTypePassenger(auxPassengerDn, auxPassengerSt.typePassenger)
				&& Passenger_setFlyCode(auxPassengerDn, auxPassengerSt.flyCode)
				&& Passenger_setStatusFly(auxPassengerDn, auxPassengerSt.statusFly)){
					ll_add(pArrayListPassenger, auxPassengerDn); // Agrego la estructura dinamica al array
					rtn = 1;
				}
				else{
					Passenger_delete(auxPassengerDn); // Libero la direccion de memoria pedida
				}
			}
		}
		fclose(pFile); // Llegado al final del archivo, lo cierro
	}
    return rtn;
}*/

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger) // Con encabezado
{
	int rtn = 0;
	sPassenger auxPassengerSt; // Estructura estatica para guardar los datos leidos del archivo
	sPassenger* auxPassengerDn = NULL; // Estructura dinamica para agregar al ll
	char fileHeader[65];
	if(pFile != NULL && pArrayListPassenger != NULL){
		fread(fileHeader, sizeof(fileHeader), 1, pFile);
		while(!feof(pFile)){ // Hasta que el cursor haya llegado al final del archivo
			if(fread(&auxPassengerSt, sizeof(sPassenger), 1, pFile) == 1){ // Si la cantidad de elementos que se leyeron es igual a 1
				/* Leo de pFile
				 * Leo un elemento
				 * El tamaño del elemento es el tamaño de la estructura sPassenger
				 * Guardo lo leido en la variable estatica
				 */
				auxPassengerDn = Passenger_new(); // Inicializo la estructura dinamica
				if(auxPassengerDn != NULL // Valido si se consiguio espacio de memoria
				&& Passenger_setId(auxPassengerDn, auxPassengerSt.id)
				&& Passenger_setName(auxPassengerDn, auxPassengerSt.name)
				&& Passenger_setlastName(auxPassengerDn, auxPassengerSt.lastName)
				&& Passenger_setPrice(auxPassengerDn, auxPassengerSt.price)
				&& Passenger_setTypePassenger(auxPassengerDn, auxPassengerSt.typePassenger)
				&& Passenger_setFlyCode(auxPassengerDn, auxPassengerSt.flyCode)
				&& Passenger_setStatusFly(auxPassengerDn, auxPassengerSt.statusFly)){
					ll_add(pArrayListPassenger, auxPassengerDn); // Agrego la estructura dinamica al array
					rtn = 1;
				}
				else{
					Passenger_delete(auxPassengerDn); // Libero la direccion de memoria pedida
				}
			}
		}
		fclose(pFile); // Llegado al final del archivo, lo cierro
	}
    return rtn;
}
