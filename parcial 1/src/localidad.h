#include "inputs.h"
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

struct{
	int idLocalidad;
	char localidad[51];
}typedef eLocalidad;

void MostrarLocalidad(eLocalidad list);
int MostrarLisataLocalidad(eLocalidad list[],int tam);

#endif /* LOCALIDAD_H_ */
