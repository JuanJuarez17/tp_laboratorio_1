/*
 * bibliotecaOpciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC
 */

#include "bibliotecaOpciones.h"

int ingresoKms(int flagOpcion1, int *pKilometros, int *pFlagOpcion3) // FUNCION INGRESO KILOMETROS V2
{
	int ret;
	int vIngreso;
	char rta;

	if (pKilometros != NULL && pFlagOpcion3 != NULL) {
		if (flagOpcion1 == 1) {
			printf("Quiere sobreescribir la cantidad de kilometros? (S/N): ");
			fflush(stdin);
			scanf("%c", &rta);
			rta = toupper(rta);

			if ((validarCharKm(&rta, 'S', 'N')) == 1) {
				if (rta == 'S') {
					printf(
							"Ingrese la distancia de su vuelo en kilometros (sin decimales): ");
					fflush(stdin);
					vIngreso = scanf("%d", pKilometros);
					validarInt(0, &vIngreso, pKilometros);
					printf("Valor guardado como distancia en kilometros.\n");
					*pFlagOpcion3 = 0;
				}
			}
		} else {
			printf(
					"Ingrese la distancia de su vuelo en kilometros (sin decimales): ");
			fflush(stdin);
			vIngreso = scanf("%d", pKilometros);
			validarInt(0, &vIngreso, pKilometros);
			printf("Valor guardado como distancia en kilometros.\n");
		}
		ret = 1;
	}
	return ret;
}

int ingresoPrecio(int flagOpcion2, int *pFlagOpcion3, float *pPrecioAerolineas,
		float *pPrecioLatam) // FUNCION PRECIO VUELO V2
{
	int ret = 0;
	char opcionVuelo;
	float costoVuelo;
	int vCostoVuelo;
	char rta;
	int flagCostoA = 0;
	int flagCostoL = 0;

	if (pFlagOpcion3 != NULL && pPrecioAerolineas != NULL
			&& pPrecioLatam != NULL) {
		if (flagOpcion2 == 1) {
			printf("Quiere sobreescribir el precio de los vuelos? (S/N): ");
			fflush(stdin);
			scanf("%c", &rta);
			rta = toupper(rta);

			if ((validarCharV(&rta, 'S', 'N')) == 1) {
				if (rta == 'S') {
					while (!(flagCostoA == 1 && flagCostoL == 1)) {
						printf(
								"Ingrese la aerolinea (A: Aerolineas/L: Latam): ");
						fflush(stdin);
						scanf("%c", &opcionVuelo);
						opcionVuelo = toupper(opcionVuelo);

						if ((validarCharVOpc(&opcionVuelo, 'A', 'L')) == 1) {
							printf(
									"Ingrese el costo del viaje en pesos ($) de %c: ",
									opcionVuelo);
							fflush(stdin);
							vCostoVuelo = scanf("%f", &costoVuelo);

							if (validarFloat(0, &vCostoVuelo, &costoVuelo,
									&opcionVuelo) == 1) {
								if (opcionVuelo == 'A') {
									printf(
											"Valor guardado como costo de Aerolineas.\n");
									*pPrecioAerolineas = costoVuelo;
									flagCostoA = 1;
								} else {
									printf(
											"Valor guardado como costo de Latam.\n");
									*pPrecioLatam = costoVuelo;
									flagCostoL = 1;
								}
							}
						}
					}
					*pFlagOpcion3 = 0;
				}
			}
		} else {
			while (!(flagCostoA == 1 && flagCostoL == 1)) {
				printf("Ingrese la aerolinea (A: Aerolineas/L: Latam): ");
				fflush(stdin);
				scanf("%c", &opcionVuelo);
				opcionVuelo = toupper(opcionVuelo);

				if ((validarCharVOpc(&opcionVuelo, 'A', 'L')) == 1) {
					printf("Ingrese el costo del viaje en pesos ($) de %c: ",
							opcionVuelo);
					fflush(stdin);
					vCostoVuelo = scanf("%f", &costoVuelo);
					if (validarFloat(0, &vCostoVuelo, &costoVuelo, &opcionVuelo)
							== 1) {
						if (opcionVuelo == 'A') {
							printf(
									"Valor guardado como costo de Aerolineas.\n");
							*pPrecioAerolineas = costoVuelo;
							flagCostoA = 1;
						} else {
							printf("Valor guardado como costo de Latam.\n");
							*pPrecioLatam = costoVuelo;
							flagCostoL = 1;
						}
					}
				}
			}
		}
		ret = 1;
	}
	return ret;
}

int calcularCostos(int kilometros, float precio, float *pPrecioDeb,
		float *pPrecioCred, float *pPrecioBTC, float *pPrecioUn) // FUNCION COSTOS
{
	int ret = 0;

	if (pPrecioDeb != NULL && pPrecioCred != NULL && pPrecioBTC != NULL
			&& pPrecioUn != NULL) {
		*pPrecioDeb = costoDebito(precio);
		*pPrecioCred = costoCredito(precio);
		*pPrecioBTC = costoBtc(precio);
		*pPrecioUn = costoUnitario(kilometros, precio);

		ret = 1;
	}
	return ret;
}

int informe(float precioDeb, float precioCred, float precioBTC, float precioUn) // FUNCION INFORMES
{
	int ret = 1;

	printf("a) Precio con tarjeta de debito: $%.2f\n", precioDeb);
	printf("b) Precio con tarjeta de credito: $%.2f\n", precioCred);
	printf("c) Precio pagando con bitcoin: %.4f BTC\n", precioBTC);
	printf("d) Precio unitario: $%.2f\n\n", precioUn);

	return ret;
}

void cargaForzada() // FUNCION CARGA FORZADA
{
	int ingresofKm = 7090;
	float preciofAerolineas = 162965;
	float preciofLatam = 159339;
	float preciofDebA;
	float preciofCredA;
	float preciofBTCA;
	float preciofUnA;
	float preciofDebL;
	float preciofCredL;
	float preciofBTCL;
	float preciofUnL;
	float preciofDif;

	calcularCostos(ingresofKm, preciofAerolineas, &preciofDebA, &preciofCredA,
			&preciofBTCA, &preciofUnA);
	calcularCostos(ingresofKm, preciofLatam, &preciofDebL, &preciofCredL,
			&preciofBTCL, &preciofUnL);
	preciofDif = costoDiferencial(preciofAerolineas, preciofLatam);

	printf("KMs ingresados: %d km\n\n", ingresofKm);
	printf("Precio Aerolineas: $%.2f\n", preciofAerolineas);
	informe(preciofDebA, preciofCredA, preciofBTCA, preciofUnA);
	printf("Precio Latam: $%.2f\n", preciofLatam);
	informe(preciofDebL, preciofCredL, preciofBTCL, preciofUnL);
	printf("La diferencia de precio es: $%.2f\n", preciofDif);
}

void salida(char *pSalir) // FUNCION SALIDA DEL PROGRAMA
{
	if (pSalir != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pSalir);
		*pSalir = toupper(*pSalir);

		validarCharS(pSalir, 'S', 'N');
	}
}
