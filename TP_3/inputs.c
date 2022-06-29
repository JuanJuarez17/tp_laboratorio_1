/*
 * inputs.c
 *
 *  Created on: 9 jun. 2022
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int input_validateCharOpt(char cEvaluate, char option1, char option2){
	int rtn = 0;
        if(cEvaluate == option1 || cEvaluate == option2){
            rtn = 1;
        }
	return rtn;
}

int input_validateIntRange(int sEvaluate, int iEvaluate, int lowLim, int HigLim){
    int rtn = 0;
        if(sEvaluate == 1 && (iEvaluate >= lowLim && iEvaluate <= HigLim)){
            rtn = 1;
        }
	return rtn;
}

int input_getPassengerType(int* pType){
    int rtn = 0;
    int auxType;
    int vType;
    if(pType){
		printf("Ingrese tipo de pasajero: ");
		printf("(1: EconomyClass - ");
		printf("2: ExecutiveClass - ");
		printf("3: FirstClass): ");
		fflush(stdin);
		vType = scanf("%d", &auxType);
		while(!(input_validateIntRange(vType, auxType, 1, 3))){
			printf("Error! Ingrese tipo de pasajero: ");
			fflush(stdin);
			vType = scanf("%d", &auxType);
		}
		*pType = auxType;
        rtn = 1;
    }
    return rtn;
}

int input_getPassengerFlyCode(char* pFlyCode){
    int rtn = 0;
    int auxFlyCode;
    int vType;
    if(pFlyCode){
		printf("Ingrese codigo de vuelo: ");
		printf("(1: BA24 - ");
		printf("2: BR34 - ");
		printf("3: FR56 - ");
		printf("4: GU23 - ");
		printf("5: HY45 - ");
		printf("6: IB08 - ");
		printf("7: MM09 - ");
		printf("8: TU67): ");
		fflush(stdin);
		vType = scanf("%d", &auxFlyCode);
		while(!(input_validateIntRange(vType, auxFlyCode, 1, 8))){
			printf("Error! Ingrese codigo de vuelo: ");
			fflush(stdin);
			vType = scanf("%d", &auxFlyCode);
		}
		switch(auxFlyCode){
			case 1:
				strcpy(pFlyCode, "BA24");
				break;
			case 2:
				strcpy(pFlyCode, "BR34");
				break;
			case 3:
				strcpy(pFlyCode, "FR56");
				break;
			case 4:
				strcpy(pFlyCode, "GU23");
				break;
			case 5:
				strcpy(pFlyCode, "HY45");
				break;
			case 6:
				strcpy(pFlyCode, "IB08");
				break;
			case 7:
				strcpy(pFlyCode, "MM09");
				break;
			case 8:
				strcpy(pFlyCode, "TU67");
				break;
		}
        rtn = 1;
    }
    return rtn;
}

int input_getPassengerStatusFly(char* flyCode, int* pStatusFly){
    int rtn = 0;
    int auxStatus;
    if(flyCode != NULL && pStatusFly != NULL){
    	if(strcmp("BA24", flyCode) == 0
		|| strcmp("IB08", flyCode) == 0
		|| strcmp("TU67", flyCode) == 0){
    		auxStatus = 1;
    	}
    	if(strcmp("BR34", flyCode) == 0
		|| strcmp("HY45", flyCode) == 0){
    		auxStatus = 2;
    	}
    	if(strcmp("FR56", flyCode) == 0
		|| strcmp("MM09", flyCode) == 0){
    		auxStatus = 3;
    	}
    	if(strcmp("GU23", flyCode) == 0){
    		auxStatus = 4;
    	}
		*pStatusFly = auxStatus;
        rtn = 1;
    }
    return rtn;
}

int input_getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos)
{
    int ret=0;
    char arrayAuxiliar[maximo];
    while(intentos>0)
    {
        printf(mensaje);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
        //__fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( resultado != NULL && strlen(arrayAuxiliar) >= minimo && strlen(arrayAuxiliar) <= maximo && input_validateLetter(arrayAuxiliar)==0)
        {
        	arrayAuxiliar[0] = toupper(arrayAuxiliar[0]);
            strncpy(resultado,arrayAuxiliar,maximo);
            ret=1;
            break;
        }
        else
        {
            printf(mensajeError);
        }
        intentos--;
    }
    return ret;
}

int input_validateLetter (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

int input_getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = 0;
    int i;
    int buffer;
    int sBuffer;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            sBuffer = scanf("%d", &buffer);
            fflush(stdin);
            if(input_validateIntRange(sBuffer, buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
    }
    return retorno;
}

int input_getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = 0;
    float buffer;
    int sBuffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            sBuffer = scanf("%f",&buffer);
            fflush(stdin);
            if(input_validateFloatRange(sBuffer, buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int input_validateFloatRange(int sEvaluate, float iEvaluate, float lowLim, float HigLim){
    int rtn = 0;
        if(sEvaluate == 1 && (iEvaluate >= lowLim && iEvaluate <= HigLim)){
            rtn = 1;
        }
	return rtn;
}

int input_getResponse(char *message, char *errorMessage, char opt1, char opt2){
	int rtn = 0;
	char confirm;
	printf(message); // Pido confirmar
	fflush(stdin); // Siempre que recibamos un char
	scanf("%c", &confirm); // Recibo respuesta
	confirm = toupper(confirm);
	while(!(input_validateCharOpt(confirm, opt1, opt2))){
		printf(errorMessage);
		fflush(stdin);
		scanf("%c", &confirm);
		confirm = toupper(confirm);
	}
	if(confirm == opt1){ // Valido que sea sea afirmativo
		rtn = 1; // Retorno 1 para ser utilziado en otra funcion
	}
	return rtn;
}
