/*
 * passenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#include "passenger.h"

// ABM

int addPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly, int* pNextId, char name[], char lastName[], float price, int type, char flyCode[]){
    int rtn = 0;
    int indice;
    ePassenger newPassenger;
    char confirma;

    if(vec && pNextId && tam > 0){ //(vec != NULL && pNextId != NULL && tam > 0)
        findEmpty(vec, tam, &indice);
        if(indice == -1){
            printf("\n------------------------------------------------------------------------------------------------------\n");
            printf("                                    - NO HAY LUGAR EN EL SISTEMA -                                    \n");
            printf("------------------------------------------------------------------------------------------------------\n");
        }
        else{
            newPassenger.id = *pNextId;
            strcpy(newPassenger.name, name);
            strcpy(newPassenger.lastname, lastName);
            newPassenger.price = price;
            newPassenger.typePassenger = type;
            strcpy(newPassenger.flyCode, flyCode);

            printf("\n------------------------------------------------------------------------------------------------------\n");
            printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
            printf("------------------------------------------------------------------------------------------------------\n");
            showPassenger(newPassenger, vecFly, tamFly);

            printf("\nConfirma carga? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = toupper(confirma);

            while(!(validarChar(confirma, 'S', 'N'))){
                printf("Error! Confirma carga? (S/N): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = toupper(confirma);
            }

            if(confirma == 'S'){ // Valido que sea sea afirmativo
                newPassenger.isEmpty = 0;
                vec[indice] = newPassenger;
                (*pNextId)++;
                printf("Carga exitosa.\n"); // Aviso del cambio
                rtn = 1;
            }
            else{ // Si no es afirmativo
                printf("Carga cancelada.\n");
            }
        }
    }
    return rtn;
}

int removePassenger(ePassenger vec[], int tam, eFly vecFly[], int tamFly){
    int rtn = 0;
    int indice;
    int vIndice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0){
        system("cls");
        printf("                        - BAJA PASAJERO -                         \n");
        printPassengers(vec, tam, vecFly, tamFly); // Muestro todos los usuarios
        printf("\nIngrese ID: "); // Pido que ingrese el ID
        fflush(stdin); // Siempre que recibamos un char
        vIndice = scanf("%d", &id); // Tomo el ID

        while(!(validarInt(vIndice))){
            printf("Error! Ingrese ID: ");
            fflush(stdin);
            vIndice = scanf("%d", &id);
        }

        if(findPassengerById(vec, tam, id, &indice)){ // Busco empleado
            if(indice == -1){ //Si no existe lo hago saber
                printf("\nNo existe un pasajero con ID: %d en el sistema.\nVolviendo al menu principal\n", id);
            }
            else{ // Si existe
                printf("\n------------------------------------------------------------------------------------------------------\n");
                printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                showPassenger(vec[indice], vecFly, tamFly); // Muestro el empleado
                printf("\nConfirma baja? (S/N): "); // Pido confirmar
                fflush(stdin); // Siempre que recibamos un char
                scanf("%c", &confirma); // Recibo respuesta
                confirma = toupper(confirma);

                while(!(validarChar(confirma, 'S', 'N'))){
                    printf("Error! Confirma baja? (S/N): ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                }

                if(confirma == 'S'){ // Valido que sea sea afirmativo
                    vec[indice].isEmpty = 1; // Cambio el valor isEmpty del indice de la estruc eEmpleado cuyo ID fue ingresado por el usuario (No lo borro, solo no se muestra en la lista)
                    printf("Baja exitosa.\n"); // Aviso del cambio
                }
                else{ // Si no es afirmativo
                    printf("Baja cancelada.\n");
                }
            }
            rtn = 1;
        }
    }
    return rtn;
}

int editPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly, char name[], char lastName[], float price, int type, char flyCode[]){
    int rtn = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0){
        system("cls");
        printf("                       - EDITAR PASAJERO -                        \n");
        printPassengers(vec, tam, vecFly, tamFly); // Muestro todos los usuarios
        printf("\nIngrese ID: "); // Pido que ingrese el ID
        scanf("%d", &id); // Tomo el ID

        if(findPassengerById(vec, tam, id, &indice)){ // Busco empleado
            if(indice == -1){ //Si no existe lo hago saber
            printf("\nNo existe un pasajero con ID: %d en el sistema.\nVolviendo al menu principal\n", id);
            }
            else{ // Si existe
                printf("------------------------------------------------------------------------------------------------------\n");
                printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                showPassenger(vec[indice], vecFly, tamFly); // Muestro el empleado
                switch(editPassengersMenu()){
                    case 1:
                        getPassengerName(name);
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            strcpy(vec[indice].name, name);
                            guardarStr(vec[indice].name);
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 2:
                        getPassengerLastname(lastName);
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            strcpy(vec[indice].lastname, lastName);
                            guardarStr(vec[indice].lastname);
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 3:
                        getPassengerPrice(&price);
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].price = price;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 4:
                        getPassengerType(&type);
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].typePassenger = type;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 5:
                        getPassengerFlyCode(vecFly, tamFly, flyCode);
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            strcpy(vec[indice].flyCode, flyCode);
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                }
            }
        }
    }
    return rtn;
}

// PEDIDO DE DATOS

int getPassenger(eFly vec[], int tam, char name[], char lastName[], float* pPrice, int* pType, char flyCode[]){
    int rtn = 0;
    if(name && lastName && pPrice && pType){
        system("cls");
        printf("                          - ALTA PASAJERO -                       \n\n");
        getPassengerName(name);
        getPassengerLastname(lastName);
        getPassengerPrice(pPrice);
        getPassengerType(pType);
        getPassengerFlyCode(vec, tam, flyCode);
        rtn = 1;
    }
    return rtn;
}

int getPassengerName(char vec[]){
    int rtn = 0;
    char auxCad[100];
    if(vec){
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad) >= TAM_STR){
            printf("Nombre demasiado largo! Reingrese: ");
            fflush(stdin);
            gets(auxCad);
        }
        while(validarStr(auxCad)){
            printf("Error! Reingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(vec, auxCad);
        guardarStr(vec);
        rtn = 1;
    }
    return rtn;
}

int getPassengerLastname(char vec[]){
    int rtn = 0;
    char auxCad[100];
    if(vec){
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad) >= TAM_STR){
            printf("Apellido demasiado largo! Reingrese: ");
            fflush(stdin);
            gets(auxCad);
        }
        while(validarStr(auxCad)){
            printf("Error! Reingrese apellido: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(vec, auxCad);
        guardarStr(vec);
        rtn = 1;
    }
    return rtn;
}

int getPassengerPrice(float* pPrice){
    int rtn = 0;
    float auxFloat;
    int vPrice;
    if(pPrice){
            printf("Ingrese precio del vuelo: ");
            fflush(stdin);
            vPrice = scanf("%f", &auxFloat);
            while(!(validarFloatRango(vPrice, auxFloat, 0, 50000))){
                printf("Error! Ingrese precio del vuelo: ");
                fflush(stdin);
                vPrice = scanf("%f", &auxFloat);
            }
            *pPrice = auxFloat;
        rtn = 1;
    }
    return rtn;
}

int getPassengerType(int* pType){
    int rtn = 0;
    int auxInt;
    int vType;
    if(pType){
            printf("Ingrese tipo de pasajero: ");
            printf("(1: Clase economica - ");
            printf("2: Clase ejecutiva - ");
            printf("3: Clase premium - ");
            printf("4: Primera clase): ");
            fflush(stdin);
            vType = scanf("%d", &auxInt);
            while(!(validarIntRango(vType, auxInt, 1, 4))){
                printf("Error! Ingrese tipo de pasajero: ");
                fflush(stdin);
                vType = scanf("%d", &auxInt);
            }
            *pType = auxInt;
        rtn = 1;
    }
    return rtn;
}

int getPassengerFlyCode(eFly vec[], int tam, char descr[]){
    int rtn = 0;
    int opcion;
    if(vec){
        printFly(vec, tam);
        printf("\nIngrese Opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        while(!validateFly(vec, tam, opcion)){
            printf("Error! Ingrese Opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        for(int i = 0; i < tam; i++){
            if(vec[i].opc == opcion){
                strcpy(descr, vec[i].flyCode);
                break;
            }
        }
        rtn = 1;
    }
    return rtn;
}

int typePassengerDesc(char vec[], int type){
    int rtn = 0;
    if(vec != NULL && type >= 1 && type <= 4){
        switch(type){
            case 1:
                strcpy(vec, "Economica");
                break;
            case 2:
                strcpy(vec, "Ejecutiva");
                break;
            case 3:
                strcpy(vec, "Premium");
                break;
            case 4:
                strcpy(vec, "Primera");
                break;
        }
        rtn = 1;
    }
    return rtn;
}

int hardcodePassenger(ePassenger vec[], int tam, int cant, int* pNextId){ // cant: Cantidad de pasajeros que quiero cargar a pesar de que el array sea de 10
    int rtn = 0;
    ePassenger pasajero[10] = {
        {0, "Roman Norberto", "Perez", 26930.5, 4, "AA9876", 0},
        {0, "Jacqueline", "Beltran", 19260.5, 2, "AA5795", 0},
        {0, "Dario", "Viegener", 10530.5, 4, "AA5795", 0},
        {0, "Roberto", "Gonzalez", 16260, 3, "LA8007", 0},
        {0, "Maria Florencia", "Alvarez", 11215.5, 1, "LA7841", 0},
        {0, "Vanesa", "Gomez", 10580, 1, "GL3587", 0},
        {0, "Juan Carlos", "Gallardo", 25880, 4, "LA7841", 0},
        {0, "Alfredo", "Fernandez", 19130.5, 3, "LA8007", 0},
        {0, "Juan Pedro", "Herrera", 22690, 2, "AA9876", 0},
        {0, "Nicolas Ezequiel", "Rodriguez", 11580.5, 1, "GL3587", 0},
    };
    if(vec != NULL && pNextId != NULL && tam > 0 && tam <= 2000 && cant <= tam){
        for(int i = 0; i < cant; i++){
            vec[i] = pasajero[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        rtn = 1;
    }
    return rtn;
}

// BUSQUEDA Y VISUALIZACION

int findEmpty(ePassenger vec[], int tam, int* pIndex){ // Devuelve el indice del primer vector de la estructura libre.
    int rtn = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){ // (vec && pIndex && tam > 0)
        *pIndex = -1;
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty){ // (vec[i].isEmpty == 1)
                *pIndex = i;
                break; // Para devovler el indice de la primer estructura libre y no el de la ultima.
            }
        }
        rtn = 1;
    }
    return rtn;
}

int findFully(ePassenger vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!vec[i].isEmpty){
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}

int initPassengers(ePassenger vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            vec[i].isEmpty = 1;
        }
        rtn = 1;
    }
    return rtn;
}

int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex){
    int rtn = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){ // (vec && pIndex && tam > 0) Valido
        *pIndex = -1; // Precargo sobre la variable id -1
        for(int i = 0; i < tam; i++){ // Recorro el array
            if(!vec[i].isEmpty && vec[i].id == id){ // Si la estructura esta vacia y el id coincide con el buscado
                *pIndex = i; // Cargo sobre la variable id el indice encontrado
                break;
            }
        }
        rtn = 1;
    }
    return rtn;
}

void showPassenger(ePassenger vec, eFly vecFly[], int tam){
    char typeDesc[15];
    typePassengerDesc(typeDesc, vec.typePassenger);
    char statusDesc[15];
    loadStatusFly(vecFly, tam, vec.flyCode, statusDesc);
    printf("%4d   %-18s %-18s %8.2f   %10s        %6s            %10s\n",
           vec.id,
           vec.name,
           vec.lastname,
           vec.price,
           typeDesc,
           vec.flyCode,
           statusDesc);
}

int printPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        //system("cls");
        printf("\n                                       - LISTA DE PASAJEROS -                                      \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                showPassenger(vec[i], vecFly, tamFly);
            }
        }
        rtn = 1;
    }
    return rtn;
}

int printActivePassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly){
    int rtn = 0;
    int status;
    if(vec != NULL && tam > 0){
        //system("cls");
        printf("\n                                       - LISTA DE PASAJEROS -                                      \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf(" ID    NOMBRE             APELLIDO            PRECIO         CLASE   CODIGO DE VUELO   ESTADO DE VUELO\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                loadStatus(vecFly, tamFly, vec[i].flyCode, &status);
                if(status == 1){
                    showPassenger(vec[i], vecFly, tamFly);
                }
            }
        }
        rtn = 1;
    }
    return rtn;
}

// INFORMES

int reportPassengers(ePassenger vec[], int tam, eFly vecFly[], int tamFly){
    int rtn = 0;
    char salir = 'N';
    int crit;
    int vCrit;
    if(vec != NULL && tam > 0){
        do{
            switch(reportPassengersMenu()){
                case 1:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    vCrit = scanf("%d", &crit);
                    while(!(validarIntRango(vCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        vCrit = scanf("%d", &crit);
                    }
                    sortPassengersById(vec, tam, crit);
                    printPassengers(vec, tam, vecFly, tamFly);
                    break;
                case 2:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    vCrit = scanf("%d", &crit);
                    while(!(validarIntRango(vCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        vCrit = scanf("%d", &crit);
                    }
                    sortPassengers(vec, tam, crit);
                    printPassengers(vec, tam, vecFly, tamFly);
                    break;
                case 3:
                    printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    vCrit = scanf("%d", &crit);
                    while(!(validarIntRango(vCrit, crit, 0, 1))){
                        printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                        fflush(stdin);
                        vCrit = scanf("%d", &crit);
                    }
                    sortPassengersByCode(vec, tam, crit);
                    printActivePassengers(vec, tam, vecFly, tamFly);
                    break;
                case 4:
                    averagePrice(vec, tam);
                    break;
                case 5:
                    salida(&salir);
                    break;
                default:
                    printf("Opcion invalida!.\n");
                    break;
            }
            rtn = 1;
            system("pause");
            //printf("\nPresione una tecla para continuar...");
            //getch();
        }while(salir != 'S');
    }
    return rtn;
}

int sortPassengersById(ePassenger vec[], int tam, int order){
    int rtn = 0;
    ePassenger aux;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if(order){
                    if(vec[i].id > vec[j].id){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
                else{
                    if(vec[i].id < vec[j].id){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
            }
        }
        rtn = 1;
    }
    return rtn;
}

int sortPassengers(ePassenger vec[], int tam, int order){
    int rtn = 0;
    ePassenger aux;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if(order){
                    if((vec[i].typePassenger == vec[j].typePassenger && strcmp(vec[i].lastname, vec[j].lastname) > 0)
                    || (vec[i].typePassenger != vec[j].typePassenger && vec[i].typePassenger > vec[j].typePassenger)){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
                else{
                    if((vec[i].typePassenger == vec[j].typePassenger && strcmp(vec[i].lastname, vec[j].lastname) < 0)
                    || (vec[i].typePassenger != vec[j].typePassenger && vec[i].typePassenger < vec[j].typePassenger)){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
            }
        }
        rtn = 1;
    }
    return rtn;
}

int averagePrice(ePassenger vec[], int tam){
    int rtn = 0;
    float accuPrice = 0;
    int countPassenger = 0;
    float avgPrice = 0;
    int pasAvobeAvg = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!vec[i].isEmpty){
                accuPrice = accuPrice + vec[i].price;
                countPassenger++;
            }
        }
        avgPrice = accuPrice / countPassenger;
        for(int i = 0; i < tam; i++){
            if(vec[i].price > avgPrice){
                pasAvobeAvg++;
            }
        }
        printf("\nCosto de pasajes promedio: $%.2f\n", avgPrice);
        printf("Cantidad de pasajeros con un costo de pasaje por encima del promedio: %d\n", pasAvobeAvg);
        rtn = 1;
    }
    return rtn;
}

int sortPassengersByCode(ePassenger vec[], int tam, int order){ // Ordenamiento por dos criterios. El primer criterio tiene que ser de agrupamiento
    int rtn = 0;
    ePassenger aux;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if(order){
                    if(strcmp(vec[i].flyCode, vec[j].flyCode) > 0){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
                else{
                    if(strcmp(vec[i].flyCode, vec[j].flyCode) < 0){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }

            }
        }
        rtn = 1;
    }
    return rtn;
}

