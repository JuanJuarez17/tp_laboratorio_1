/*
 * passenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define TAM_STR 51
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validaciones.h"
#include "menuOpciones.h"
#include "fly.h"

typedef struct{
    int id;
    char name[51];
    char lastname[51];
    float price;
    int typePassenger;
    char flyCode[10];
    int isEmpty;
}ePassenger;

#endif /* PASSENGER_H_ */

// ABM

/// @brief Agregar un elemento al array de estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @param pNextId Recibe variable ID de los elementos del array pasajeros
/// @param name Recibe variable nombre de los elementos del array pasajeros
/// @param lastName Recibe variable apellido de los elementos del array pasajeros
/// @param price Recibe variable precio de los elementos del array pasajeros
/// @param type Recibe variable tipo de los elementos del array pasajeros
/// @param flyCode Recibe variable id vuelo de los elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int addPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly, int* pNextId, char name[], char lastName[], float price, int type, char flyCode[]);

/// @brief Modificar un elemento al array de estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @param name Recibe variable nombre de los elementos del array pasajeros
/// @param lastName Recibe variable apellido de los elementos del array pasajeros
/// @param price Recibe variable precio de los elementos del array pasajeros
/// @param type Recibe variable tipo de los elementos del array pasajeros
/// @param flyCode Recibe variable id vuelo de los elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int editPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly, char name[], char lastName[], float price, int type, char flyCode[]);

/// @brief Baja logica de un elemento del array de estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int removePassenger(ePassenger vec[], int tam, eFly vecFly[], int tamFly);

// PEDIDO DE DATOS

/// @brief Obtener datos de un elemento de estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param name Recibe variable nombre de los elementos del array pasajeros
/// @param lastName Recibe variable apellido de los elementos del array pasajeros
/// @param price Recibe variable precio de los elementos del array pasajeros
/// @param type Recibe variable tipo de los elementos del array pasajeros
/// @param flyCode Recibe variable id vuelo de los elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassenger(eFly vec[], int tam, char name[], char lastName[], float* pPrice, int* pType, char flyCode[]);

/// @brief Obtener el nombre de un elemento de estructura pasajeros
///
/// @param vec Recibe la variable para almacenar el nombre
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassengerName(char vec[]);

/// @brief Obtener el apellido de un elemento de estructura pasajeros
///
/// @param vec Recibe la variable para almacenar el apellido
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassengerLastname(char vec[]);

/// @brief Obtener el precio de un elemento de estructura pasajeros
///
/// @param pPrice Recibe la variable para almacenar el precio
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassengerPrice(float* pPrice);

/// @brief Obtener el tipo de un elemento de estructura pasajeros
///
/// @param pType Recibe la variable para almacenar el tipo
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassengerType(int* pType);

/// @brief Obtener el id de vuelo de un elemento de estructura pasajeros
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @param descr Carga el vector id de vuelo
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int getPassengerFlyCode(eFly vec[], int tam, char descr[]);

/// @brief Cargar descripcion tipo de pasajero
///
/// @param vec Carga el vector descripcion tipo de pasajero
/// @param type Recibe el tipo de pasajero
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int typePassengerDesc(char vec[], int type);

/// @brief Harcodear una determinada cantidad de elementos en el array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param cant Cantidad de elementos del array a hardcodear
/// @param pNextId Recibe variable ID de los elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int hardcodePassenger(ePassenger vec[], int tam, int cant, int* pNextId);

// BUSQUEDA Y VISUALIZACION

/// @brief Encontrar elemento vacio en el array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param pIndex Carga indice (-1) En caso de no encontrarse - (i) En caso encontrarse
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int findEmpty(ePassenger vec[], int tam, int* pIndex);

/// @brief Encontrar elemento lleno en el array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int findFully(ePassenger vec[], int tam);

/// @brief Inicializar elementos en el array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int initPassengers(ePassenger vec[], int tam);

/// @brief Encontrar un elemento en el array de la estructura pasajeros por su id
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param id Recibe el entero id de la estructura pasajeros
/// @param pIndex Carga indice (-1) En caso de no encontrarse - (i) En caso encontrarse
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex);

/// @brief Mostrar elemento de la estructura vuelo
///
/// @param vec Array de estructura pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tam Cantidad de elementos del array de estructura vuelos
void showPassenger(ePassenger vec, eFly vecFly[], int tam);

/// @brief Listar elementos del array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int printPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly);

/// @brief Listar elementos con una condicion particular del array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int printActivePassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly);

// INFORMES

/// @brief Informes de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param vecFly Array de estructura vuelos
/// @param tamFly Cantidad de elementos del array vuelos
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int reportPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly);

/// @brief Ordenar elementos de un array de la estructura pasajeros por su id
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param order Criterio de ordenamiento
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int sortPassengersById(ePassenger vec[], int tam, int order);

/// @brief Ordenar elementos de un array de la estructura pasajeros por apellido y tipo de pasajero
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param order Criterio de ordenamiento
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int sortPassengers(ePassenger vec[], int tam, int order);

/// @brief Obtener el precio promedio de elementos de un array de la estructura pasajeros
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int averagePrice(ePassenger vec[], int tam);

/// @brief Ordenar elementos de un array de la estructura pasajeros por codigo de vuelo
///
/// @param vec Array de estructura pasajeros
/// @param tam Cantidad de elementos del array pasajeros
/// @param order Criterio de ordenamiento
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int sortPassengersByCode(ePassenger vec[], int tam, int order);
