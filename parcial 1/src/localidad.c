#include "localidad.h"

void MostrarLocalidad(eLocalidad list){
	printf("%d.%s\n",list.idLocalidad,list.localidad);
}

int MostrarLisataLocalidad(eLocalidad list[],int tam){
	int retorno = -1;
	int i;

	for(i=0; i<tam; i++){
		MostrarLocalidad(list[i]);
		retorno = 0;
	}
	return retorno;
}
