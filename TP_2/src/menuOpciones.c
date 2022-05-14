/*
 * menuOpciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#include "menuOpciones.h"

int editPassengersMenu(){
    int opcion;
    printf("\n1 - NOMBRE.\n");
    printf("2 - APELLIDO.\n");
    printf("3 - PRECIO.\n");
    printf("4 - TIPO DE PASAJERO.\n");
    printf("5 - CODIGO DE VUELO.\n");
    printf("Presione cualquier tecla para salir.\n\n");
    printf("Ingrese campo a modificar: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuOpciones(){
    int opcion;

    system("cls");
    printf("1 - Alta pasajero.\n");
    printf("2 - Modificar pasajero.\n");
    printf("3 - Baja pasajero.\n");
    printf("4 - Carga forzada de pasajeros.\n");
    printf("5 - Informes.\n");
    printf("6 - Salir.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int reportPassengersMenu(){
    int opcion;
    system("cls");
    printf("                - INFORMES DE PASAJEROS -                  \n\n");
    printf("1 - ORDENAR POR ID.\n");
    printf("2 - ORDENAR POR APELLIDO Y TIPO DE PASAJERO.\n");
    printf("3 - ORDENAR POR CODIGO DE VUELO CON ESTADO ACTIVO.\n");
    printf("4 - OBTENER PROMEDIO DE PRECIOS Y PASAJEROS POR ENCIMA DEL MISMO.\n");;
    printf("5 - SALIR.\n\n");
    printf("Ingrese opcion deseado: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void salida(char *pSalir)
{
	if (pSalir != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pSalir);
		*pSalir = toupper(*pSalir);

		while(!(validarChar(*pSalir, 'S', 'N'))){
            printf("Error! Confirma salida? (S/N): ");
            fflush(stdin);
            scanf("%c", pSalir);
            *pSalir = toupper(*pSalir);
		}
	}
}

