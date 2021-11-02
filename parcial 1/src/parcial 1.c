#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define TC 100
#define TP 1000
#define TL 8

int main(void) {
	setbuf(stdout,NULL);
	eCliente listaCliente[TC]={ {1,2,"carrefour","20439193639","roca"},
								{2,8,"coto","20439193639","españa"},
								{3,5,"dia","20439193639","mitre"},
								{4,7,"josimar","20439193639","belgrano"},
								{5,1,"jumbo","20439193639","chaca"}};

	ePedido ListaPedido[TP];

	eLocalidad listaLocalidad[TL]={ {1,"Almirante Brown"},
									{2,"Avellaneda"},
									{3,"Quilmes"},
									{4,"Lanus"},
									{5,"Florencio Varela"},
									{6,"Berazategui"},
									{7,"Lomas de Zamora"},
									{8,"Esteban Echeverria"}};

	int opcion;
	int respuesta;
	int idIngresado;
	int idCliente = 0;
	int idPedido = 0;
	int idLocalidad;
	int pedidosPLocalidad = 0;
	float promedioPolipropileno;
	int cantidadMayorPedidos = 0;
	int indice = 0;

	//inicializarCliente(listaCliente,TC);
	inicializarPedido(ListaPedido,TP);

	do{
		MostrarMenuPrincipal();
		respuesta = getNumero(&opcion,"Opcion: ");

		if(respuesta == 0){
			switch(opcion){
			case 1:
				respuesta = CargarListaCliente(listaCliente,TC,&idCliente,listaLocalidad,TL);
				if(respuesta == 0){
					printf("\nSe cargo el cliente correctamente.\n");
				}else{
					printf("\nNo se pudo cargar el cliente.\n");
				}
				break;

			case 2:
				do{
					getNumero(&idIngresado,"Ingrese ID del cliente a modificar: ");

					respuesta = BuscarIdCliente(listaCliente,TC,idIngresado);
					if(respuesta != -1){
						MostrarCliente(listaCliente[respuesta],listaLocalidad,TL);
						ModificarCliente(listaCliente,TC,idIngresado,listaLocalidad,TL);
						respuesta = 2;
					}else{
						getNumero(&respuesta,"\nId no existente:Intentar de nuevo\n1.Si\t2.No ");
					}
				}while(respuesta != 2);
				break;

			case 3:
				do{
					getNumero(&idIngresado,"Ingrese ID del cliente a eliminar: ");

					respuesta = BuscarIdCliente(listaCliente,TC,idIngresado);
					if(respuesta != -1){
						getNumero(&respuesta,"Esta seguro/a?\n1.Si\t2.No");
						if(respuesta == 1){
							respuesta = BorrarCliente(listaCliente,TC,idIngresado);
							if(respuesta == 0){
								printf("\nSe elimino el cliente.\n");
								respuesta = 2;
							}else{
								printf("\nNo se puso eliminar el cliente.\n");
							}
						}
					}else{
						getNumero(&respuesta,"\nId no existente:Intentar de nuevo\n1.Si\t2.No ");
					}
				}while(respuesta != 2);
				break;

			case 4:
				do{
					MostrarListaCliente(listaCliente,TC,listaLocalidad,TL);

					getNumero(&idIngresado,"Ingrese ID del cliente: ");

					respuesta = BuscarIdCliente(listaCliente,TC,idIngresado);
					if(respuesta != -1){
						MostrarCliente(listaCliente[respuesta],listaLocalidad,TL);
						CargarListaPedido(ListaPedido,TC,&idPedido,idIngresado);
						respuesta = 2;
					}else{
						getNumero(&respuesta,"\nId no existente:Intentar de nuevo\n1.Si\t2.No ");
					}
					}while(respuesta != 2);
				break;

			case 5:
				do{
					MostrarListaPedido(ListaPedido,TP,PENDIENTE,listaCliente,TC);
					getNumero(&idIngresado,"Ingrese ID del pedido a procesar: ");

					respuesta = BuscarIdPedido(ListaPedido,TP,idIngresado);
					if(respuesta != -1){
						ProcesarResiduos(ListaPedido,TP,idIngresado);
						respuesta = 2;
					}else{
						getNumero(&respuesta,"\nId no existente:Intentar de nuevo\n1.Si\t2.No ");
					}
				}while(respuesta != 2);

				break;

			case 6:
				respuesta = MostrarListaCliente(listaCliente,TC,listaLocalidad,TL);
				if(respuesta!=0){
				printf("\nNo se puede mostrar.\n");
				}
				break;

			case 7:
				MostrarListaPedido(ListaPedido,TP,PENDIENTE,listaCliente,TC);
				break;

			case 8:
				MostrarListaPedido(ListaPedido,TP,COMPLETADO,listaCliente,TC);
				break;

			case 9:
				do{
					CargarLocalidad(&idLocalidad, listaLocalidad,TL);

					respuesta = BuscarPorLocalidad(listaCliente,TC,ListaPedido,TP,idLocalidad,&pedidosPLocalidad);
					if(respuesta == 0){
						MostrarBusaquedaPorLocalidad(listaLocalidad, TL, idLocalidad, pedidosPLocalidad);
						respuesta = 2;
					}else{
						getNumero(&respuesta,"\nId no existente:Intentar de nuevo\n1.Si\t2.No ");
					}
				}while(respuesta != 2);
				break;

			case 10:
				respuesta = CalcularCantPolipropileno(listaCliente,TC,ListaPedido,TP,&promedioPolipropileno);

				if(respuesta == 0){
					InformarPromedioPolipropileno(promedioPolipropileno);
				}else{
					printf("\nNo hay basura polipropileno reciclado\n");
				}
				break;

			case 11:
				indice = InformarCantidadPedidos(ListaPedido,TP,listaCliente,TC,&cantidadMayorPedidos,PENDIENTE);
				MostrarCantidadPedidosMayor(listaCliente[indice],cantidadMayorPedidos);
				break;

			case 12:
				indice = InformarCantidadPedidos(ListaPedido,TP,listaCliente,TC,&cantidadMayorPedidos,COMPLETADO);
				MostrarCantidadPedidosMayor(listaCliente[indice],cantidadMayorPedidos);
				break;

			case 13:
				break;

			default:
				printf("\nOpcion incorrecta\n");
			}
		}
	}while(opcion!=13);

	return EXIT_SUCCESS;
}
