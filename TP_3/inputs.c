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

int input_validateChar(char cEvaluate, char option1, char option2){
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

		/*// INICIO DEBUG
		printf("Debug: %d\n", *pType);
		// FIN DEBUG*/

		while(!(input_validateIntRange(vType, auxType, 1, 3))){
			printf("Error! Ingrese tipo de pasajero: ");
			fflush(stdin);
			vType = scanf("%d", &auxType);
		}
		*pType = auxType;
		/*// INICIO DEBUG
		printf("Debug: %d\n", *pType);
		// FIN DEBUG*/

        rtn = 1;
    }
    return rtn;
}

int input_getPassengerFlyCode(char* pFlyCode){
    int rtn = 0;
    int auxFlyCode;
    int vType;

	/*// INICIO DEBUG
	printf("Debug: %s\n", pFlyCode);
	// FIN DEBUG*/

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

    	/*// INICIO DEBUG
    	printf("Debug: %s\n", pFlyCode);
    	// FIN DEBUG*/
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

int utn_getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos)
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
        if( resultado != NULL && strlen(arrayAuxiliar) >= minimo && strlen(arrayAuxiliar) <= maximo && validarLetra(arrayAuxiliar)==0)
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

int validarLetra (char letras[])
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

int utn_getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = 0;
    int i;
    int buffer;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer, maximo, minimo))
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

int isValidInt(int numero, int maximo, int minimo)
{
    int ret = 0;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 1;
    }
    return ret;
}

int validarNumero (char numeros[])
{
    int ret=0;
    int i=0;
    int CantidadNumeros;
    CantidadNumeros=strlen(numeros);
    while (i<CantidadNumeros && ret==0)
    {
        if (isdigit(numeros[i])!=0)
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

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = 0;
    float buffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer, maximo, minimo))
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

int isValidFloat(float numero, float maximo, float minimo)
{
    int ret = 0;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 1;
    }
    return ret;
}

int utn_getChar( char *resultado,char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno = 0;
    char buffer;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            scanf("%c", &buffer);
            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno=1;
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

int isValidChar(char letra, char maximo, char minimo)
{
    int ret = 0;
    if(letra<=maximo && letra>=minimo)
    {
        ret = 1;
    }
    return ret;
}
