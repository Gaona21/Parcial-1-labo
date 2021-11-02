#include "cliente.h"
int inicializarCliente(eCliente list[], int tam){
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

int BuscarIdCliente(eCliente list[],int tam,int idIngresado){
	int retorno = -1;
	int i;

	if(tam>0 && idIngresado>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idIngresado){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int BorrarCliente(eCliente list[],int tam,int idIngresado){
	int retorno = -1;
	int i;

	if(tam>0 && idIngresado>0){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idIngresado){
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
