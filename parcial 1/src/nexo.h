#include "pedido.h"
#include "localidad.h"
#ifndef NEXO_H_
#define NEXO_H_

/// @fn void MostrarMenuPrincipal()
/// @brief muestra las opociones del menu
///
void MostrarMenuPrincipal();

/// @fn void MostrarCliente(eCliente)
/// @brief muestra un cliente y todos sus datos
///
/// @param list
void MostrarCliente(eCliente list,eLocalidad listL[], int tamL);

/// @fn int MostrarListaCliente(eCliente[], int)
/// @brief muestra una lista de todos los clientes y sus datos
///
/// @param list
/// @param tam
/// @return -1 si no puede mostrar o 0 si puedo mostrar;
int MostrarListaCliente(eCliente list[],int tam,eLocalidad listL[],int tamL);


/// @fn void MostrarPedidoPendiente(ePedido, eCliente)
/// @brief muestra un pedido con estado PENDIENTE
///
/// @param listP
/// @param listC
void MostrarPedidoPendiente(ePedido listP, eCliente listC);

/// @fn void MostrarPedidoCompletado(ePedido, eCliente)
/// @brief muestra un pedido en estado completado
///
/// @param listP
/// @param listC
void MostrarPedidoCompletado(ePedido listP, eCliente listC);

/// @fn int MostrarListaPedido(ePedido[], int, int, eCliente[], int)
/// @brief muestra una lista con todos los pedidos en estado pendiente o completado
///
/// @param list
/// @param tam
/// @param estadoPendiente
/// @param listC
/// @param tamC
/// @return -1 si puede mostrar o 0 si ya mostro.
int MostrarListaPedido(ePedido list[], int tam,int estadoPendiente,eCliente listC[],int tamC);

/// @fn int BuscarPorLocalidad(eCliente[], int, ePedido[], int, char[], int*)
/// @brief se ingresa una localidad y se buscae informa cuantos pedidos hay en esa localidad.
///
/// @param listC
/// @param tamC
/// @param listP
/// @param tamP
/// @param localidadIngresada
/// @param contPedidosPendienteLocalidad
/// @return -1 si no econtro o 0 si encontro localidad.
int BuscarPorLocalidad(eCliente listC[], int tamC,ePedido listP[],int tamP,int localidadIngresada,int* contPedidosPendienteLocalidad);

/// @fn int CalcularCantPolipropileno(eCliente[], int, ePedido[], int, float*)
/// @brief calcula la cantidad de polipropileno reciclado en total y se divide por la cantida declientes que reciclaron polipropileno
///
/// @param listC
/// @param tamC
/// @param listP
/// @param tamP
/// @param promedioPolipropileno
/// @return -1 si no hay polipropileno para reciclar o 0 si calculo el promedio total.
int CalcularCantPolipropileno(eCliente listC[],int tamC,ePedido listP[],int tamP, float* promedioPolipropileno);

/// @fn void InformarPromedioPolipropileno(float)
/// @brief muestra en pantalla el promedio de polipropileno en total.
///
/// @param promedioPolipropileno
void InformarPromedioPolipropileno(float promedioPolipropileno);

/// @fn int CargarListaEmpleado(eCliente[], int, int*)
/// @brief pedimos los datos al usuario y lo cargamos al array.
///
/// @param list
/// @param tam
/// @param idCliente
/// @return -1 si no cargo los datos y 0 se cargo los datos
int CargarListaCliente(eCliente list[],int tam,int* idCliente, eLocalidad listL[],int tamL);

int CargarLocalidad(int* idLocalidad, eLocalidad list[],int tam);

/// @fn int ModificarCliente(eCliente[], int, int)
/// @brief permite modificar dirrecion o localidad por id
///
/// @param list
/// @param tam
/// @param idIngresado
/// @return -1 si no se pudo modificar o 0 si se modifico
int ModificarCliente(eCliente list[], int tam, int idIngresado,eLocalidad listL[],int tamL);

void MostrarBusaquedaPorLocalidad(eLocalidad list[],int tam,int idlocalidad,int canPedidos);

void MenuModificar(eCliente list,eLocalidad listL[],int tamL);

int InformarCantidadPedidos(ePedido listP[], int tamP,eCliente listC[],int tamC ,int* canPedidos,int estadoPedido);

void MostrarCantidadPedidosMayor(eCliente list,int cantPedidos);

#endif /* NEXO_H_ */
