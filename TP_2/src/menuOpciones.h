/*
 * menuOpciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#ifndef MENUOPCIONES_H_
#define MENUOPCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "validaciones.h"

#endif /* MENUOPCIONES_H_ */

/// @brief Mostrar menu de edicion de pasajeros
///
/// @return Retorna (0) En caso de error - (1) En caso de completo
int editPassengersMenu();

/// @brief Mostrar menu del programa
///
/// @return Retorna (0) En caso de error - (1) En caso de completo
int menuOpciones();

/// @brief Mostrar menu de informes
///
/// @return Retorna (0) En caso de error - (1) En caso de completo
int reportPassengersMenu();

/// @brief Funcion para salir del programa
///
/// @param pSalir Carga el caracter de salida
void salida(char *pSalir);
