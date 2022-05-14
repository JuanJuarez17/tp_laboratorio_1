/*
 * fly.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#include "fly.h"

int printFly(eFly vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        printf("\n                                - LISTA DE VUELOS -                                 \n");
        printf("--------------------------------------------------------------------------------------\n");
        printf(" OPCION     ID     DESCRIPCION                 EMPRESA          ORIGEN         DESTINO\n");
        printf("--------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            printf("  %2d      %6s    %10s  %22s %15s %15s\n",
                   vec[i].opc,
                   vec[i].flyCode,
                   vec[i].statusFlyDesc,
                   vec[i].empresa,
                   vec[i].origen,
                   vec[i].destino);
            rtn = 1;
        }
    }
    return rtn;
}

int loadStatusFly(eFly vec[], int tam, char flyCode[], char desc[]){
    int rtn = 0;
    if(vec != NULL && tam > 0 && desc != NULL){
        for(int i = 0; i < tam; i++){
            if(strcmp(vec[i].flyCode, flyCode) == 0){ // El id del array sector coincide con el buscado
                strcpy(desc, vec[i].statusFlyDesc);
                rtn = 1;
            }
        }
    }
    return rtn;
}

int loadStatus(eFly vec[], int tam, char flyCode[], int* status){
    int rtn = 0;
    if(vec != NULL && tam > 0 && flyCode != NULL){
        for(int i = 0; i < tam; i++){
            if(strcmp(vec[i].flyCode, flyCode) == 0){ // El id del array sector coincide con el buscado
                *status = vec[i].statusFly;
                rtn = 1;
            }
        }
    }
    return rtn;
}

int findFly(eFly vec[], int tam, int opc, int* pIndex){
    int rtn = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){ // (vec && pIndex && tam > 0)
        *pIndex = -1;
        for(int i = 0; i < tam; i++){
            if(vec[i].opc == opc){
                *pIndex = opc;
                break;
            }
        }
        rtn = 1;
    }
    return rtn;
}

int validateFly(eFly vec[], int tam, int opc){
    int rtn = 0; // No valido vec y tam porque vienen validadas de la funcion buscarSector. El retorno solo se encarga de validar el indice.
    int indice;
    if(findFly(vec, tam, opc, &indice)){
        if(indice != -1){
            rtn = 1;
        }
    }
    return rtn;
}


