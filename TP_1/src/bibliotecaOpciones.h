/*
 * bibliotecaOpciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC
 */

#ifndef BIBLIOTECAOPCIONES_H_
#define BIBLIOTECAOPCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibliotecaCalculos.h"
#include "bibliotecaValidaciones.h"

#endif /* BIBLIOTECAOPCIONES_H_ */

/// @brief Opcion 1 - Ingreso de kilometros del vuelo
///
/// @param Evaluacion de bandera opcion 1 para sobrescritura
/// @param Direccion de memoria variable kilometros
/// @param Modificacion de bandera opcion 3 cuando se hace sobrescritura
/// @return Bandera de opcion 1
int ingresoKms(int, int*, int*); // FUNCION INGRESO KILOMETROS

/// @brief Opcion 2 - Ingreso de precios de vuelo
///
/// @param Evaluacion de bandera opcion 2 para sobrescritura
/// @param Modificacion de bandera opcion 3 cuando se hace sobrescritura
/// @param Direccion de memoria variable precio
/// @param Direccion de memoria variable precio
/// @return Bandera de opcion 2
int ingresoPrecio(int, int*, float*, float*); // FUNCION PRECIO VUELO

/// @brief Opcion 3 - Calculo de costos
///
/// @param Variable kilometros
/// @param Variable precio (una aerolinea)
/// @param Direccion de memoria variable precio debito
/// @param Direccion de memoria variable precio credito
/// @param Direccion de memoria variable precio BTC
/// @param Direccion de memoria variable precio unitario
/// @return Bandera de opcion 3
int calcularCostos(int, float, float*, float*, float*, float*); // FUNCION CALCULAR COSTO

/// @brief Opcion 4 - Informe
///
/// @param Variable precio debito
/// @param Variable precio credito
/// @param Variable precio BTC
/// @param Variable precio unitario
/// @return Bandera de opcion 4
int informe(float, float, float, float); // FUNCION INFORMES

/// @brief Opcion 5 - Carga forzada de datos
///
void cargaForzada(); // FUNCION CARGA FORZADA

/// @brief Opcion 6 - Salida
///
/// @param Direccion de memoria variable salir
void salida(char*); // FUNCION SALIDA DEL PROGRAMA
