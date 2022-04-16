/*
 ============================================================================
 Name        : TP_1.c
 Author      : Juarez Juan - Div. G
 Version     : Version para entrega - Fecha limite 16/04/2022 23:59
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Agrego funcion getch
#include <ctype.h> // Agrego funcion toupper
#include "bibliotecaMenu.h"
#include "bibliotecaCalculos.h"
#include "bibliotecaValidaciones.h"
#include "bibliotecaOpciones.h"

int main() {
	setbuf(stdout, NULL);
	char salir = 'N';
	int kilometros;
	int flagOpcion1 = 0;
	int flagOpcion2 = 0;
	int flagOpcion3 = 0;
	float precioAerolineas;
	float precioLatam;
	float precioDebA;
	float precioCredA;
	float precioBTCA;
	float precioUnA;
	float precioDebL;
	float precioCredL;
	float precioBTCL;
	float precioUnL;
	float precioDif;

	do {
		switch (menu(kilometros, precioAerolineas, precioLatam, flagOpcion1,flagOpcion2)) {
		case 1:
			flagOpcion1 = ingresoKms(flagOpcion1, &kilometros, &flagOpcion3);
			break;
		case 2:
			flagOpcion2 = ingresoPrecio(flagOpcion2, &flagOpcion3, &precioAerolineas, &precioLatam);
			break;
		case 3:
			if (validacionDoble(flagOpcion1, flagOpcion2) == 1) {
				flagOpcion3 = calcularCostos(kilometros, precioAerolineas, &precioDebA, &precioCredA, &precioBTCA, &precioUnA);
				flagOpcion3 = calcularCostos(kilometros, precioLatam, &precioDebL, &precioCredL, &precioBTCL, &precioUnL);
				precioDif = costoDiferencial(precioAerolineas, precioLatam);
			}
			else {
				if (validacionDoble(flagOpcion1, flagOpcion2) == -2) {
					printf("Para calcular los costos antes debe ingresar la cantidad de kilometros (Opcion 1) y el precio del vuelo (Opcion 2).\n");
				}
				else {
					if (validacionDoble(flagOpcion1, flagOpcion2) == -1) {
						printf("Para calcular los costos antes debe ingresar la cantidad de kilometros (Opcion 1).\n");
					}
					else {
						printf("Para calcular los costos antes debe ingresar el precio del vuelo (Opcion 2).\n");
					}
				}
			}
			break;
		case 4:
			if (validacionSimple(flagOpcion3) == 1) {
				printf("Latam:\n");
				informe(precioDebL, precioCredL, precioBTCL, precioUnL);
				printf("Aerolineas:\n");
				informe(precioDebA, precioCredA, precioBTCA, precioUnA);
				printf("La diferencia de precios es: $ %.2f\n", precioDif);
			}
			else {
				printf("Para mostrar el informe antes debe calcular los costos (Opcion 3).\n");
			}
			break;
		case 5:
			cargaForzada();
			break;
		case 6:
			salida(&salir);
			break;
		case 7:
			printf("Usted no ingreso un numero!\n");
			break;
		default:
			printf("Opcion invalida!\n"); //Se ingresa un numero pero fuera de los case
			break;
		}
		system("pause");
		//printf("Presione una tecla para continuar...\n\n");
		//getch();

	} while (salir != 'S');

	return EXIT_SUCCESS;
}
