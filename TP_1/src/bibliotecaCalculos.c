/*
 * bibliotecaCalculos.c
 *
 *  Created on: 13 abr. 2022
 *      Author: PC
 */

#include "bibliotecaCalculos.h"

float costoDebito(float precio) // FUNCION CALCULO COSTO TARJETA DEBITO
{
	return precio - (precio * 10 / 100);
}

float costoCredito(float precio) // FUNCION CALCULO COSTO TARJETA CREDITO
{
	return precio + (precio * 25 / 100);
}

float costoBtc(float precio) // FUNCION CALCULO COSTO BTC
{
	return precio / 4520954.43;
}

float costoUnitario(int kilometros, float precio) // FUNCION CALCULO COSTO UNITARIO
{
	return precio / kilometros;
}

float costoDiferencial(float precio, float precio2) // FUNCION CALCULO DIFERENCIA DE PRECIO
{
	return precio - precio2;
}
