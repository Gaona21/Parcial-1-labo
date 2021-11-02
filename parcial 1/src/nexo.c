#include "nexo.h"

void MostrarMenuPrincipal(){
	printf("\nMenu principal: \n");
	printf("1.Alta de cliente\n");
	printf("2.Modifica datos del cliente\n");
	printf("3.Baja de cliente\n");
	printf("4.Crear predido de recoleccion\n");
	printf("5.Procesar reciduos\n");
	printf("6.Imprimir cliente\n");
	printf("7.Imprimir pedidos pendientes\n");
	printf("8.Imprimir pedidos procesados\n");
	printf("9.Buscar por localidad\n");
	printf("10.Cantidad de kilos de polipropileno reciclado por cliente\n");
	printf("11.Cliente con más pedidos pendientes\n");
	printf("12.Cliente con más pedidos completados\n");
	printf("13.Salir\n");
}

void MostrarCliente(eCliente list,eLocalidad listL[], int tamL){
	int i;

	list.nombreEmpresa[0] = toupper(list.nombreEmpresa[0]);
	list.direccion[0] = toupper(list.direccion[0]);

	for(i=0; i<tamL; i++){
		if(listL[i].idLocalidad == list.idLocalidad){
			printf(" %2d %-12s %-12s %-15s %-12s\n",list.idCliente,list.nombreEmpresa,list.cuit,list.direccion,listL[i].localidad);
			break;
		}
	}
}

int MostrarListaCliente(eCliente list[],int tam,eLocalidad listL[],int tamL){
	int retorno = -1;
	int i;

	if(tam>0){
		printf("\n ID EMPRESA 	 CUIT 	      DIRECCION       LOCALIDAD\n");
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE){
				MostrarCliente(list[i], listL, tamL);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int CargarListaCliente(eCliente list[],int tam,int* idCliente, eLocalidad listL[],int tamL){
	int retorno = -1;
	int i;

	if(tam>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == TRUE){

				*idCliente = *idCliente + 1;
				list[i].idCliente = *idCliente;

				GetString("Ingrese el nombre de la empresa: ",list[i].nombreEmpresa,sizeof(list[i].nombreEmpresa));

				GetCuit("Ingrese su cuit: ",list[i].cuit,sizeof(list[i].cuit));

				GetString("Ingrese dirreccion: ",list[i].direccion,sizeof(list[i].direccion));

				CargarLocalidad(&list[i].idLocalidad, listL, tamL);
				list[i].isEmpty = FALSE;
				retorno = 0;
				break;

			}
		}
	}
	return retorno;
}

void MostrarPedidoPendiente(ePedido listP, eCliente listC){

	listC.direccion[0] = toupper(listC.direccion[0]);

	printf(" %d %-12s %-16s %-7.3fkg\n",listP.idPedido,listC.cuit,listC.direccion,listP.kiloTotal);
}

void MostrarPedidoCompletado(ePedido listP, eCliente listC){

	listC.direccion[0] = toupper(listC.direccion[0]);

	printf(" %d %-15s %-12s %-7.2f %-7.2f %-7.2f\n",listP.idPedido,listC.cuit,listC.direccion,listP.basuraHDPE,listP.basuraLDPE,listP.basuraPP);
}

int MostrarListaPedido(ePedido list[],int tamP, int estadoPedido, eCliente listC[], int tamC){
	int retorno = -1;
	int i;
	int j;

	if(tamP>0 && tamC>0){
		if(estadoPedido == 0){
			printf("\n ID CUIT 	DIRECCION    	 BASURA\n");
		}else{
			printf("\n ID CUIT 	   DIRECCION   	HDPE 	LDPE	PP\n");
		}
		for(i=0;i<tamP;i++){
			if(list[i].isEmpty == FALSE && list[i].estadoPedido == estadoPedido){
				for(j=0;j<tamC;j++){
					if(list[i].idCliente == listC[j].idCliente){
						if(estadoPedido == PENDIENTE){
							MostrarPedidoPendiente(list[i],listC[j]);
						}else{
							MostrarPedidoCompletado(list[i], listC[j]);
						}
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

int BuscarPorLocalidad(eCliente listC[], int tamC,ePedido listP[],int tamP,int localidadIngresada,int* contPedidosPendienteLocalidad){
	int retorno = -1;
	int i;
	int j;
	int auxContador = 0;

	if(tamC>0 && tamP>0){
		for(i=0; i<tamC; i++){
			if(listC[i].isEmpty == FALSE && listC[i].idLocalidad == localidadIngresada){
				for(j=0; j<tamP;j++){
					if(listC[i].idCliente == listP[j].idCliente && listP[j].estadoPedido == PENDIENTE){
						auxContador++;
						*contPedidosPendienteLocalidad = auxContador;
						retorno = 0;
					}
				}
			}
		}

	}
	return retorno;
}

void MostrarBusaquedaPorLocalidad(eLocalidad list[],int tam,int idlocalidad,int canPedidos){
	int i;
	printf("\nLocalidad  	Pedidos\n");
	for(i=0; i<tam; i++){
		if(list[i].idLocalidad == idlocalidad){
			printf("%-15s %-5d\n",list[i].localidad,canPedidos);
		}
	}
}

int CalcularCantPolipropileno(eCliente listC[],int tamC,ePedido listP[],int tamP, float* promedioPolipropileno){
	int retorno = -1;
	int i;
	int j;
	float acumuladorPP = 0;
	int contador = 0;
	float promedio;

	if(tamP>0 && tamC>0){
		for(i=0; i<tamC; i++){
			if(listC[i].isEmpty == FALSE){
				for(j=0; j<tamP; j++){
					if(listP[j].estadoPedido == COMPLETADO && listP[j].basuraPP>0){
						acumuladorPP +=listP[j].basuraPP;
						contador++;
					}
				}
			}
		}

		if(contador>0 && acumuladorPP>0){
			promedio = acumuladorPP/contador;
			*promedioPolipropileno = promedio;
			retorno = 0;
		}
	}
	return retorno;
}

void InformarPromedioPolipropileno(float promedioPolipropileno){
	printf("\nPromedio total de basura polipropileno: %.2f\n",promedioPolipropileno);
}

int CargarLocalidad(int* idLocalidad, eLocalidad list[],int tam){
	int retorno = -1;
	int auxId;

		MostrarLisataLocalidad(list, tam);
		do{
			getNumero(&auxId,"Seleccione una localidad: ");
		}while(auxId<1 || auxId>8);

		*idLocalidad = auxId;

	return retorno;
}

int ModificarCliente(eCliente list[], int tam, int idIngresado, eLocalidad listL[],int tamL){
	int retorno = -1;
	int i;
	int opcion;

	printf("\nMenu Modifica:\n1.Direccion\n2.Localidad\n\n");
	getNumero(&opcion,"OPCION: ");

	if(tam>0 && idIngresado>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idIngresado){
				switch(opcion){
				case 1:
					GetString("Ingrese direccion nueva: ",list[i].direccion,sizeof(list[i].direccion));
					break;

				case 2:
					CargarLocalidad(&list[i].idLocalidad, listL, tamL);
					break;

				default:
					printf("\nOpcion incorrecta.\n");
				}
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int InformarCantidadPedidos(ePedido listP[], int tamP,eCliente listC[],int tamC ,int* canPedidos,int estadoPedido){
	int retorno = -1;
	int contador = 0;
	int banderaCantPedidosMayor = 1;
	int CantidadPedidosMayor;

	if(tamP>0 && tamC>0 && canPedidos!=NULL){
		for(int i=0; i<tamC; i++){
			if(listC[i].isEmpty == FALSE ){
				for(int j=0; j<tamP; j++){
					if(listP[j].isEmpty == FALSE && listP[j].idCliente == listC[i].idCliente && listP[j].estadoPedido == estadoPedido){
						contador++;
						if(banderaCantPedidosMayor == 1 || contador>=CantidadPedidosMayor){

							banderaCantPedidosMayor = 0;
							CantidadPedidosMayor = contador;

							retorno = i;
						}
					}
				}
				contador = 0;
			}
		}
		*canPedidos = CantidadPedidosMayor;
	}
	return retorno;
}

void MostrarCantidadPedidosMayor(eCliente list,int cantPedidos){
	list.nombreEmpresa[0] = toupper(list.nombreEmpresa[0]);
	printf("\n Nombre		Cuit	 Pedidos\n");
	printf(" %-10s %-10s %5d\n",list.nombreEmpresa, list.cuit, cantPedidos);
}





