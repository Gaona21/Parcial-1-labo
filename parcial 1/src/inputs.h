#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/// @fn int getNumero(int*, char[])
/// @brief permite ingresar numeros enteros y valida que no se letras.
///
/// @param pResultado
/// @param mensaje
/// @return -1 si no pudo validar y 0 si valido el valor ingresado.
int getNumero(int* pResultado, char mensaje[]);
/// @fn int getInt(int*)
/// @brief toma lo ingresado en getnumero y lo guarda en un char.
///
/// @param pResultado
/// @return -1 si no es numerica y 0 si es numerica.
int getInt(int* pResultado);
/// @fn int esNumerica(char*)
/// @brief toma una cadena de caracteres y verifica si es numerica posicion a posicion.
///
/// @param cadena
/// @return 0 si no es numerica y 1 si es numerica.
int esNumerica(char* cadena);

/// @fn float getNumeroFloat(float*, char[])
/// @brief permite ingresar numeros con coma  y valida que no se letras.
///
/// @param pResultado
/// @param mensaje
/// @return -1 si no pudo validar y 0 si valido el valor ingresado.
float getNumeroFloat(float* pResultado, char mensaje[]);
/// @fn int getFloat(float*)
/// @brief toma lo ingresado en getnumero y lo guarda en un char.
///
/// @param pResultado
/// @return -1 si no es numerica y 0 si es numerica.
int getFloat(float* pResultado);
/// @fn int esNumericaFloat(char*)
/// @brief toma una cadena de caracteres y verifica si es numerica posicion a posicion.
///
/// @param cadena
/// @return 0 si no es numerica y 1 si es numerica.
int esNumericaFloat(char* cadena);

/// @fn int GetString(char[], char[], int)
/// @brief permite el ingreso de un string y valida que no se pase del tama�o.
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @return 0 si no pudo validar y 1 si pudo guardar el string.
int GetString(char mensaje[], char cadena[], int tam);

int GetCuit(char mensaje[], char cadena[], int tam);

#endif /* INPUTS_H_ */
