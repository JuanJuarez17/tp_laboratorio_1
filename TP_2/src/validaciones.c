/*
 * validaciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juarez Juan
 */

#include "validaciones.h"

int guardarStr(char vec[]){
    int todoOk = 0;
    if(vec != NULL){
        for(int i = 0; vec[i] != '\0'; i++){
            if(i == 0){
                vec[i] = toupper(vec[i]);
            }
            else{
                if(vec[i - 1] == ' '){
                    vec[i] = toupper(vec[i]);
                }
                else{
                    vec[i] = tolower(vec[i]);
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarChar(char cEvaluar, char opcion1, char opcion2){
	int rtn = 0;
        if(cEvaluar == opcion1 || cEvaluar == opcion2){
            rtn = 1;
        }
	return rtn;
}

int validarFloatRango(float fEvaluar, float Float, int limInf, int limSup){
    int rtn = 0;
        if(fEvaluar == 1 && (Float > limInf && Float <= limSup)){
            rtn = 1;
        }
	return rtn;
}

int validarInt(int iEvaluar){
	int rtn = 0;
        if(iEvaluar == 1){
            rtn = 1;
        }
	return rtn;
}

int validarIntRango(int iEvaluar, int Int, int limInf, int limSup){
    int rtn = 0;
        if(iEvaluar == 1 && (Int >= limInf && Int <= limSup)){
            rtn = 1;
        }
	return rtn;
}

int validarStr(char vec[]){
    int rtn = 0;
    if(vec != NULL){
        for(int i = 0; vec[i] != '\0'; i++){
            if(!(vec[i] >= 'a' && vec[i] <= 'z') && !(vec[i] >= 'A' && vec[i] <= 'Z') && vec[i] != ' '){
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}



