#include "inputs.h"
#include "cliente.h"
#ifndef PEDIDO_H_
#define PEDIDO_H_

#define TRUE 1
#define FALSE 0
#define COMPLETADO 1
#define PENDIENTE 0

struct{
	int idPedido;
	int idCliente;
	float kiloTotal;
	float basuraHDPE;
	float basuraLDPE;
	float basuraPP;
	int estadoPedido;
	int isEmpty;
}typedef ePedido;

/// @fn int inicializarPedido(ePedido[], int)
/// @brief inicializa isEmpty en TRUE en cada posicion del array.
///
/// @param list
/// @param tam
/// @return -1 si no ejecuto o 0 si se ejecuto.
int inicializarPedido(ePedido list[],int tam);

/// @fn int CargarListaPedido(ePedido[], int, int*, int)
/// @brief pedimos los datos al usuario y lo cargamos al array.
///
/// @param list
/// @param tam
/// @param idPedido
/// @param idCliente
/// @return -1 si no cargo los datos y 0 se cargo los datos
int CargarListaPedido(ePedido list[],int tam,int* idPedido,int idCliente);

/// @fn int ProcesarResiduos(ePedido[], int, int)
/// @brief ingresa la catidad de basura de cada tipo.
///
/// @param list
/// @param tam
/// @param idIngresado
/// @return -1 si no cargo los datos o 0 si cargo los datos.
int ProcesarResiduos(ePedido list[],int tam,int idIngresado);

/// @fn int BuscarIdPedido(ePedido[], int, int)
/// @brief pide un id al usuario y la busca.
///
/// @param list
/// @param tam
/// @param idIngresado
/// @return -1 si no encontro el id o el indice del id encontrado.
int BuscarIdPedido(ePedido list[],int tam,int idIngresado);

void MenuProcesarResiduos(ePedido list,int tam,int* contador,float* basuraHDPE, float* basuraLDPE,float* basuraPP);

int CargarTipoBasura(ePedido list[],int indice);
#endif /* PEDIDO_H_ */
