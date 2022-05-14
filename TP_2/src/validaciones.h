/*
 * validaciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#endif /* VALIDACIONES_H_ */

/// @brief Convertir un vector de caracteres a un formato para almacenar
///
/// @param vec Recibe el vector de caracter a convertir
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int guardarStr(char vec[]);

/// @brief Validar un caracter entre dos opciones
///
/// @param cEvaluar Recibe el caracter a evaluar
/// @param opcion1 Criterio 1
/// @param opcion2 Criterio 2
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int validarChar(char cEvaluar, char opcion1, char opcion2);

/// @brief Validar un flotante entre dos opciones
///
/// @param fEvaluar Recibe el flotante a evaluar
/// @param Float Recibe el tipo de dato a evaluar
/// @param limInf Criterio 1
/// @param limSup Criterio 2
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int validarFloatRango(float fEvaluar, float Float, int limInf, int limSup);

/// @brief Validar si un dato es un entero
///
/// @param iEvaluar Recibe el entero a evaluar
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int validarInt(int iEvaluar);

/// @brief
///
/// @param iEvaluar Recibe el entero a evaluar
/// @param Int Recibe el tipo de dato a evaluar
/// @param limInf Criterio 1
/// @param limSup limSup Criterio 2
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int validarIntRango(int iEvaluar, int Int, int limInf, int limSup);

/// @brief Validar si un vector de caracteres esta compuesto solo de letras
///
/// @param vec Recibe el vector de caracter a evaluar
/// @return Retorna (0) En caso de no valido - (1) En caso de valido
int validarStr(char vec[]);
