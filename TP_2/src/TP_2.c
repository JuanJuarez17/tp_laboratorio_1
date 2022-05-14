/*
 ============================================================================
 Name        : TP_2.c
 Author      : Juarez Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define TAM_PASSENGER 2000
#define TAM_STR 51
#include "passenger.h"
#include "validaciones.h"
#include "menuOpciones.h"
#include "fly.h"

int main()
{
	setbuf(stdout, NULL);
	char salir = 'N';
    int nextId = 1000;
    char name[TAM_STR];
    char lastName[TAM_STR];
    float price;
    int type;
    char flyCode[10];
    char confirma;

    eFly vuelos[5] = {
    {1, "LA8007", 1, "ACTIVO", "Buenos Aires", "Brasilia", "Latam" },
    {2, "GL3587", 0, "DEMORADO", "San Pablo", "Bahia", "Gol" },
    {3, "AA5795", -1, "CANCELADO", "Cordoba", "Bariloche", "Aerolineas Argentinas" },
    {4, "LA7841", -1, "CANCELADO", "San Pablo", "Buenos Aires", "Latam" },
    {5, "AA9876", 1, "ACTIVO", "Buenos Aires", "Iguazu", "Aerolineas Argentinas" },
    };

    ePassenger lista[TAM_PASSENGER];

    initPassengers(lista, TAM_PASSENGER);

	do{
		switch(menuOpciones()){
			case 1:
			    getPassenger(vuelos, 5, name, lastName, &price, &type, flyCode);
                addPassengers(lista, TAM_PASSENGER, vuelos, 5, &nextId, name, lastName, price, type, flyCode);
                break;
		    case 2:
		        if(findFully(lista, TAM_PASSENGER)){
                   editPassengers(lista, TAM_PASSENGER, vuelos, 5, name, lastName, price, type, flyCode);
		        }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 3:
                if(findFully(lista, TAM_PASSENGER)){
                    removePassenger(lista, TAM_PASSENGER, vuelos, 5);
                }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 4:
		        if(!findFully(lista, TAM_PASSENGER)){
                    hardcodePassenger(lista, TAM_PASSENGER, 10, &nextId);
                    printf("Pasajeros cargados con exito.\n\n");
		        }
		        else{
                    printf("Desea agregar pasajeros a los ya existentes? (S/N): ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    while(!(validarChar(confirma, 'S', 'N'))){
                        printf("Error! Desea agregar pasajeros a los ya existentes? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S'){
                        hardcodePassenger(lista, TAM_PASSENGER, 10, &nextId);
                        printf("Pasajeros cargados con exito.\n\n");
                    }
                    else{
                        printf("Carga cancelada.\n");
                    }
		        }
                break;
		    case 5:
		        if(findFully(lista, TAM_PASSENGER)){
                    reportPassengers(lista, TAM_PASSENGER, vuelos, 5);
		        }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 6:
                salida(&salir);
                break;
            default:
                printf("Opcion invalida!\n");
                break;
		}
        system("pause");
		//printf("\nPresione una tecla para continuar...");
		//getch();
	}while(salir != 'S');
    return EXIT_SUCCESS;
}

