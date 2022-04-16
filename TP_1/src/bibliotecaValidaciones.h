/*
 * bibliotecaValidaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC
 */

#ifndef BIBLIOTECAVALIDACIONES_H_
#define BIBLIOTECAVALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#endif /* BIBLIOTECAVALIDACIONES_H_ */

/// @brief Validar si una variable (char) esta entre dos opciones
///
/// @param Direccion de memoria de la variable a evaluar
/// @param Opcion letra 1
/// @param Opcion letra 2
/// @return Indicacion de si la validacion es correcta o no
int validarCharKm(char*, char, char); // FUNCION VALIDAR CHAR KM

/// @brief Validar si una variable (int) es tal y se encuentra dentro de un rango
///
/// @param Variable limite inferior
/// @param Direccion de memoria de la variable a evaluar
/// @param Direccion de memoria de la validacion de la variable
/// @return Indicacion de si la validacion es correcta o no
int validarInt(int, int*, int*); // FUNCION VALIDAR INT KM

/// @brief Evaluacion del estado de una bandera
///
/// @param Variable bandera a evaluar
/// @return Indicacion de si la validacion es correcta o no
int validacionSimple(int); // FUNCION DE VALIDACION SIMPLE

/// @brief Validar si una variable (char) esta entre dos opciones (Version ingreso precio)
///
/// @param Direccion de memoria de la variable a evaluar
/// @param Opcion letra 1
/// @param Opcion letra 2
/// @return Indicacion de si la validacion es correcta o no
int validarCharV(char*, char, char); // FUNCION VALIDAR CHAR VUELO

/// @brief Validar si una variable (char) esta entre dos opciones (Version ingreso precio 2)
///
/// @param Direccion de memoria de la variable a evaluar
/// @param Opcion letra 1
/// @param Opcion letra 2
/// @return Indicacion de si la validacion es correcta o no
int validarCharVOpc(char*, char, char); // FUNCION VALIDAR CHAR OPCION VUELO

/// @brief Validar si una variable (float) es tal y se encuentra dentro de un rango
///
/// @param Variable limite inferior
/// @param Direccion de memoria de la validacion de la variable
/// @param Direccion de memoria de la variable a evaluar
/// @param Direccion de memoria de la variable opcion vuelo (Version ingreso precio)
/// @return Indicacion de si la validacion es correcta o no
int validarFloat(int, int*, float*, char*); // FUNCION VALIDAR FLOAT VUELO

/// @brief Evaluacion del estado de dos banderas
///
/// @param Variable bandera 1 a evaluar
/// @param Variable bandera 1 a evaluar
/// @return Indicacion de si la validacion es correcta o no
int validacionDoble(int, int); // FUNCION DE VALIDACION DOBLE

/// @brief Validar si una variable (char) esta entre dos opciones (Version salida)
///
/// @param Direccion de memoria de la variable a evaluar
/// @param Opcion letra 1
/// @param Opcion letra 2
/// @return Indicacion de si la validacion es correcta o no
int validarCharS(char*, char, char); // FUNCION VALIDAR CHAR SALIDA
