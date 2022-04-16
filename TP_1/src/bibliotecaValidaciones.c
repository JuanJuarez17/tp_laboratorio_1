/*
 * bibliotecaValidaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC
 */

#include "bibliotecaValidaciones.h"

int validarCharKm(char *pEvaluar, char opcion1, char opcion2) // FUNCION VALIDAR CHAR
{
	int ret = 0;

	while (!(*pEvaluar == opcion1 || *pEvaluar == opcion2)) {
		printf(
				"Error! Quiere sobreescribir la cantidad de kilometros? (S/N): ");
		fflush(stdin);
		scanf("%c", pEvaluar);
		*pEvaluar = toupper(*pEvaluar);
	}
	ret = 1;
	return ret;
}

int validarInt(int limiteInf, int *pValid, int *evaluar) // FUNCION VALIDAR INT KM
{
	int ret = 0;

	while (*pValid == 0 || *evaluar <= limiteInf) {
		printf(
				"Error! Ingrese la distancia de su vuelo en kilometros (sin decimales): ");
		fflush(stdin);
		*pValid = scanf("%d", evaluar);
	}
	return ret;
}

int validacionSimple(int flag1) // FUNCION DE VALIDACION SIMPLE
{
	int ret = 0;

	if (flag1 == 1) {
		ret = 1;
	}
	return ret;
}

int validarCharV(char *pEvaluar, char opcion1, char opcion2) // FUNCION VALIDAR CHAR
{
	int ret = 0;

	while (!(*pEvaluar == opcion1 || *pEvaluar == opcion2)) {
		printf("Error! Quiere sobreescribir el precio de los vuelos? (S/N): ");
		fflush(stdin);
		scanf("%c", pEvaluar);
		*pEvaluar = toupper(*pEvaluar);
	}
	ret = 1;
	return ret;
}

int validarCharVOpc(char *pEvaluar, char opcion1, char opcion2) // FUNCION VALIDAR CHAR
{
	int ret = 0;

	while (!(*pEvaluar == opcion1 || *pEvaluar == opcion2)) {
		printf("Error! Ingrese la aerolinea (A: Aerolineas/L: Latam): ");
		fflush(stdin);
		scanf("%c", pEvaluar);
		*pEvaluar = toupper(*pEvaluar);
	}
	ret = 1;
	return ret;
}

int validarFloat(int limInferior, int *pValid, float *evaluar, char *pOpcionVuelo) // FUNCION VALIDAR FLOAT VUELO
{
	int ret = 0;
	while (*pValid == 0 || *evaluar < limInferior) {
		printf("Error! Ingrese el costo del viaje en pesos ($) de %c: ",
				*pOpcionVuelo);
		fflush(stdin);
		*pValid = scanf("%f", evaluar);
	}
	ret = 1;
	return ret;
}

int validacionDoble(int flag1, int flag2) // FUNCION DE VALIDACION DOBLE
{
	int ret = 0;

	if (flag1 == 0) {
		if (flag2 == 0) {
			ret = -2;
		} else {
			ret = -1;
		}
	} else if (flag2 == 0) {
		ret = 0;
	} else {
		ret = 1;
	}
	return ret;
}

int validarCharS(char *pEvaluar, char opcion1, char opcion2) // FUNCION VALIDAR CHAR SALIDA
{
	int ret = 0;

	while (!(*pEvaluar == opcion1 || *pEvaluar == opcion2)) {
		printf("Error! Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pEvaluar);
		*pEvaluar = toupper(*pEvaluar);
	}
	ret = 1;
	return ret;
}

