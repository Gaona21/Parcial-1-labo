#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

struct{

	int idEditorial;
	char nombre[126];

}typedef eEditorial;

eEditorial* editorial_New();
eEditorial* editorial_NewParametros(char* idEditorial, char* nombre);

int editorial_setId(eEditorial* this,int id);
int editorial_get(eEditorial* this,int* id);

int editorial_setNombre(eEditorial* this,char* nombre);
int editorial_getNombre(eEditorial* this,char* nombre);

void Editorial_MostrarUnaEditorial(eEditorial* this);

#endif /* EDITORIAL_H_ */
