/*
 * fly.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#ifndef FLY_H_
#define FLY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int opc;
    char flyCode[6];
    int statusFly;
    char statusFlyDesc[15];
    char origen[15];
    char destino[15];
    char empresa[25];

}eFly;

#endif /* FLY_H_ */
/// @brief Muestra listado de vuelos
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @return Retorna (0) En caso de error - (1) En caso de completo
int printFly(eFly vec[], int tam);

/// @brief Carga la descripcion del estado de vuelo en la estructura ePassenger
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @param flyCode Recibe el vector codigo de vuelo de la estructura eFly
/// @param desc Carga el vector descripcion
/// @return Retorna (0) En caso de error - (1) En caso de completo
int loadStatusFly(eFly vec[], int tam, char flyCode[], char desc[]);

/// @brief Carga el estado de vuelo en la estructura ePassenger
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @param flyCode Recibe el vector codigo de vuelo de la estructura eFly
/// @param status Carga el entero estado de vuelo
/// @return Retorna (0) En caso de error - (1) En caso de completo
int loadStatus(eFly vec[], int tam, char flyCode[], int* status);

/// @brief Encontrar un valor de opcion dentro de la estructura eFly
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @param opc Recibe el entero opcion de la estructura eFly
/// @param pIndex Carga indice (-1) En caso de no encontrarse - (opc) En caso encontrarse
/// @return Retorna (0) En caso de error - (1) En caso de completo
int findFly(eFly vec[], int tam, int opc, int* pIndex);

/// @brief Validar si un valor de opcion existe dentro de una estructura
///
/// @param vec Array de estructura vuelos
/// @param tam Cantidad de elementos del array
/// @param opc Recibe el entero opcion de la estructura eFly
/// @return Retorna (0) En caso de error - (1) En caso de completo
int validateFly(eFly vec[], int tam, int opc);
