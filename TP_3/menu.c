/*
 * menu.c
 *
 *  Created on: 9 jun. 2022
 *      Author: PC
 */

#include "Passenger.h"

int menu_main(){
    int option;
    int sOption;
    system("cls");
    printf("1 - CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.csv (MODO TEXTO).\n");
    printf("2 - CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.bin (MODO BINARIO).\n");
    printf("3 - ALTA DE PASAJERO.\n");
    printf("4 - MODIFICAR DATOS DE PASAJERO.\n");
    printf("5 - BAJA DE PASAJERO.\n");
    printf("6 - LISTAR PASAJEROS.\n");
    printf("7 - ORDENAR PASAJEROS.\n");
    printf("8 - GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (MODO TEXTO).\n");
    printf("9 - GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.bin (MODO BINARIO).\n");
    printf("10 - SALIR.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    sOption = scanf("%d", &option);
    if(!sOption){
    	option = 11;
    }
    return option;
}

int menu_sort(){
    int option;
    int sOption;
    system("cls");
    printf("1 - ORDENAR PASAJEROS POR ID.\n");
    printf("2 - ORDENAR PASAJEROS POR NOMBRE.\n");
    printf("3 - ORDENAR PASAJEROS POR APELLIDO.\n");
    printf("4 - ORDENAR PASAJEROS POR TIPO DE PASAJERO.\n");
    printf("5 - ORDENAR PASAJEROS POR CODIGO DE VUELO.\n");
    printf("6 - ORDENAR PASAJEROS POR ESTADO DE VUELO.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    sOption = scanf("%d", &option);
    if(!sOption){
    	option = 7;
    }
    return option;
}

int menu_edit(){
    int option;
    int sOption;
    system("cls");
    printf("1 - EDITAR NOMBRE.\n");
    printf("2 - EDITAR APELLIDO.\n");
    printf("3 - EDITAR PRECIO.\n");
    printf("4 - EDITAR TIPO DE PASAJERO.\n");
    printf("5 - EDITAR CODIGO DE VUELO.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    sOption = scanf("%d", &option);
    if(!sOption){
    	option = 6;
    }
    return option;
}
