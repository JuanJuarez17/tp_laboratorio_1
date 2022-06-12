/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

#define ID_INIT_PASSENGER 0 /**< Valor inicial del ID de un Empleado. >*/
#define PASSENGER_MAX 1500 /**< Cantidad maxima de Empleados en un arreglo. >*/
#define PASSENGER_PRICE_MAX 50000 /**< Precio maximo de un pasajero. >*/
#define PASSENGER_FLYCODE_LEN_MAX 4
#define PASSENGER_NAME_LEN_MAX 128

typedef struct{
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[5];
	int typePassenger;
	int statusFly;
}sPassenger;

/// @brief
///
/// @return
sPassenger* Passenger_new();

/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param tipoPasajeroStr
/// @return
sPassenger* Passenger_newParameters(char* id, char* name, char* lastName, char* price, char* flyCode, char* typePassenger, char* statusFly);

/// @brief
///
void Passenger_delete(sPassenger* this);

/// @brief Establece el ID a una estructura Empleado.
///
/// @param this Direccion de memoria de un pasajero.
/// @param id
/// @return [0] Si no pudo establecer el ID.
/// 		[1] Si pudo establecer el ID.
int Passenger_setId(sPassenger* this, int id);

/// @brief
///
/// @param this
/// @param id
/// @return
int Passenger_getId(sPassenger* this, int* id);

/// @brief
///
/// @param this
/// @param name
/// @return
int Passenger_setName(sPassenger* this, char* name);

/// @brief
///
/// @param this
/// @param name
/// @return
int Passenger_getName(sPassenger* this, char* name);

/// @brief
///
/// @param this
/// @param lastName
/// @return
int Passenger_setlastName(sPassenger* this, char* lastName);

/// @brief
///
/// @param this
/// @param lastName
/// @return
int Passenger_getlastName(sPassenger* this, char* lastName);

/// @brief
///
/// @param this
/// @param price
/// @return
int Passenger_setPrice(sPassenger* this, float price);

/// @brief
///
/// @param this
/// @param price
/// @return
int Passenger_getPrice(sPassenger* this, float* price);

/// @brief
///
/// @param this
/// @param flyCode
/// @return
int Passenger_setFlyCode(sPassenger* this, char* flyCode);

/// @brief
///
/// @param this
/// @param flyCode
/// @return
int Passenger_getFlyCode(sPassenger* this, char* flyCode);

/// @brief
///
/// @param this
/// @param typePassenger
/// @return
int Passenger_setTypePassenger(sPassenger* this, int typePassenger);

/// @brief
///
/// @param this
/// @param typePassenger
/// @return
int Passenger_getTypePassenger(sPassenger* this, int* typePassenger);

/// @brief
///
/// @param this
/// @param statusFly
/// @return
int Passenger_setStatusFly(sPassenger* this, int statusFly);

/// @brief
///
/// @param this
/// @param statusFly
/// @return
int Passenger_getStatusFly(sPassenger* this, int* statusFly);

/// @brief
///
/// @param typePassenger
/// @return
int Passenger_typePassengerToInt(char* typePassenger);

/// @brief
///
/// @param statusFly
/// @return
int Passenger_statusFlightToInt(char* statusFly);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareById(void* this1, void* this2);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareByName(void* this1, void* this2);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareByLastName(void* this1, void* this2);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareByTypePassenger(void* this1, void* this2);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareByFlyCode(void* this1, void* this2);

/// @brief
///
/// @param this1
/// @param this2
/// @return
int Passenger_compareByStatusFly(void* this1, void* this2);

/// @brief
///
/// @param pArrayListPassenger
/// @return
int Passenger_getNextId(LinkedList* pArrayListPassenger);


/// @brief
///
/// @param pArrayListPassenger
/// @param pIndex
/// @param Id
/// @return
int Passenger_findById(LinkedList* pArrayListPassenger, int* pIndex, int Id);

/// @brief
///
/// @param this
/// @return
int Passenger_print(sPassenger* this);

/// @brief
///
/// @param typePassDesc
/// @param typePassenger
/// @return
int Passenger_getTypePassengerDesc(char* typePassDesc, int typePassenger);

/// @brief
///
/// @param statusFlyDesc
/// @param statusFly
/// @return
int Passenger_getStatusFlyDesc(char* statusFlyDesc, int statusFly);

#endif /* PASSENGER_H_ */
