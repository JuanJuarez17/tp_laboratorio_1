/*
 * inputs.h
 *
 *  Created on: 9 jun. 2022
 *      Author: PC
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */

int input_validateCharOpt(char cEvaluate, char option1, char option2);
int input_validateIntRange(int sEvaluate, int iEvaluate, int lowLim, int HigLim);
int input_getPassengerType(int* pType);
int input_getPassengerFlyCode(char* pFlyCode);
int input_getPassengerStatusFly(char* flyCode, int* pStatusFly);

/** \brief Solicita el ingreso de un string y valida su tamaño
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo int Tamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int input_getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int input_validateLetter(char letras[]);

/** \brief Solicita el ingreso de un int y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int input_getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/** \brief Solicita el ingreso de un float y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int input_getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int input_validateFloatRange(int sEvaluate, float iEvaluate, float lowLim, float HigLim);

/** \brief Solicita el ingreso de un char y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int input_getResponse(char *message, char *errorMessage, char opt1, char opt2);
