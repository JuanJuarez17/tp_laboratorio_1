/*
 * bibliotecaCalculos.h
 *
 *  Created on: 13 abr. 2022
 *      Author: PC
 */

#ifndef BIBLIOTECACALCULOS_H_
#define BIBLIOTECACALCULOS_H_

#endif /* BIBLIOTECACALCULOS_H_ */

/// @brief Calculo de costo neto con debito
///
/// @param Variable costo en bruto
/// @return Variable costo neto con debito
float costoDebito(float); // FUNCION CALCULO COSTO TARJETA DEBITO

/// @brief Calculo de costo neto con credito
///
/// @param Variable costo en bruto
/// @return Variable costo neto con credito
float costoCredito(float); // FUNCION CALCULO COSTO TARJETA CREDITO

/// @brief Calculo de costo neto con BTC
///
/// @param Variable costo en bruto
/// @return Variable costo neto con BTC
float costoBtc(float); // FUNCION CALCULO COSTO BTC

/// @brief Calculo de costo unitario por kilometro
///
/// @param Variable kilometros
/// @param Variable costo en bruto
/// @return Variable costo unitario por kilometro
float costoUnitario(int, float); // FUNCION CALCULO COSTO UNITARIO

/// @brief Calculo de diferencia de costos brutos
///
/// @param Variable costo en bruto 1
/// @param Variable costo en bruto 2
/// @return Variable direfencia de costo
float costoDiferencial(float, float); // FUNCION CALCULO DIFERENCIA DE PRECIO
