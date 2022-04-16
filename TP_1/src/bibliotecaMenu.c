/*
 * bibliotecaMenu.c
 *
 *  Created on: 13 abr. 2022
 *      Author: PC
 */

#include "bibliotecaMenu.h"

int menu(int kilometros, float precioAerolineas, float precioLatam, int flagOpcion1, int flagOpcion2) // FUNCION MENU DE OPCIONES
{
	int opcion;
	int vOpcion;

	system("cls"); // Le pido a windows que limpie la pantalla

	printf("*** Menu de opciones***\n\n");
	if (flagOpcion1 == 1) {
		printf("1 - Ingresar kilometros: (km = %d)\n", kilometros);
	} else {
		printf("1 - Ingresar kilometros: (km = x)\n");
	}
	if (flagOpcion2 == 1) {
		printf(
				"2 - Ingresar precio de vuelos: (Aerolineas = %.2f, Latam = %.2f)\n",
				precioAerolineas, precioLatam);
	} else {
		printf("2 - Ingresar precio de vuelos: (Aerolineas = y, Latam = z)\n");
	}
	printf("3 - Calcular todos los costos.\n");
	printf("4 - Informar resultados.\n");
	printf("5 - Carga forzada de datos.\n");
	printf("6 - Salir\n\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	vOpcion = scanf("%d", &opcion); //Validar si se ingreso un numero

	if (vOpcion == 0) {
		opcion = 7;
	}
	return opcion;
}


