#include "inputs.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_

#define TRUE 1
#define FALSE 0

struct{
	int idCliente;
	int idLocalidad;
	char nombreEmpresa[51];
	char cuit[12];
	char direccion[71];
	int isEmpty;
}typedef eCliente;

/// @fn int inicializarCliente(eCliente[], int)
/// @brief inicializa isEmpty en verdadero en cada posicion del array.
///
/// @param list
/// @param tam
/// @return retorna -1 si no se ejecuta y 0 si se ejecuto.
int inicializarCliente(eCliente list[],int tam);

/// @fn int BuscarIdCliente(eCliente[], int, int)
/// @brief pide un id al usuario y la busca.
///
/// @param list
/// @param tam
/// @param idIngresado
/// @return -1 si no encontro el id o el indice del id encontrado
int BuscarIdCliente(eCliente list[],int tam,int idIngresado);


/// @fn int BorrarCliente(eCliente[], int, int)
/// @brief mediante un id se pone isEmpty en TRUE
///
/// @param list
/// @param tam
/// @param idIngresado
/// @return -1 si no se puede eliminar o 0 si se elimino.
int BorrarCliente(eCliente list[],int tam,int idIngresado);
#endif /* CLIENTE_H_ */
