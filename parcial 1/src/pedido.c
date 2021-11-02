#include "pedido.h"

int inicializarPedido(ePedido list[],int tam){
	int retorno = -1;
	int i;

	if(tam>0){
		for(i=0; i<tam; i++){
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int CargarListaPedido(ePedido list[],int tam,int* idPedido,int idCliente){
	int retorno = -1;
	int i;

	if(tam>0 && idPedido>0 && idCliente>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == TRUE){
				*idPedido = *idPedido + 1;
				list[i].idPedido = *idPedido;
				list[i].idCliente = idCliente;
				getNumeroFloat(&list[i].kiloTotal,"Ingrese la cantidad de basura en kilos: ");
				list[i].estadoPedido = PENDIENTE;
				list[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int BuscarIdPedido(ePedido list[],int tam,int idIngresado){
	int retorno = -1;
	int i;

	if(tam>0 && idIngresado>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE && list[i].idPedido == idIngresado){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ProcesarResiduos(ePedido list[],int tam,int idIngresado){
	int retorno = -1;
	int i;

	if(tam>0 && idIngresado>0){
		for(i=0;i<tam;i++){
			if(list[i].isEmpty == FALSE && list[i].idPedido == idIngresado && list[i].estadoPedido == PENDIENTE){
				CargarTipoBasura(list,i);
				list[i].estadoPedido = COMPLETADO;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int CargarTipoBasura(ePedido list[],int indice){
	float tipoBasuraTotal;
	int retorno = -1;

	do{
		getNumeroFloat(&list[indice].basuraHDPE,"Ingrese las cantidad de basura HDPE: ");
		while(list[indice].basuraHDPE>list[indice].kiloTotal){
			getNumeroFloat(&list[indice].basuraHDPE,"La cantidad no puede superar a la cantidad total informada\nReingrese las cantidad de basura HDPE: ");
		}

		getNumeroFloat(&list[indice].basuraLDPE,"Ingrese las cantidad de basura LDPE: ");
		while(list[indice].basuraLDPE>list[indice].kiloTotal){
			getNumeroFloat(&list[indice].basuraLDPE,"La cantidad no puede superar a la cantidad total informada\nReingrese las cantidad de basura LDPE: ");
		}

		getNumeroFloat(&list[indice].basuraPP,"Ingrese las cantidad de basura PP: ");
		while(list[indice].basuraPP>list[indice].kiloTotal){
			getNumeroFloat(&list[indice].basuraPP,"La cantidad no puede superar a la cantidad total informada\nReingrese las cantidad de basura PP: ");
		}

		tipoBasuraTotal = list[indice].basuraHDPE + list[indice].basuraLDPE + list[indice].basuraPP;

		if(tipoBasuraTotal > list[indice].kiloTotal){
			printf("\nLa cantidad de basura es mayor a la cantidad informada, reingrese: \n");
		}else{
			retorno = 0;
		}

	}while(tipoBasuraTotal > list[indice].kiloTotal);
	return retorno;
}
