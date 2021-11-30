#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "editorial.h"

#ifndef LIBRO_H_
#define LIBRO_H_

struct{

	int idLibro;
	char titulo[126];
	char autor[126];
	float precio;
	int idEditorial;

}typedef eLibro;

eLibro* libro_New();
eLibro* libro_NewParametros(char* idLibro, char* titulo, char* autor, char* precio, char* idEditorial);

int libro_SetId(eLibro* this,int id);
int libro_GetId(eLibro* this,int* id);

int libro_SetTitulo(eLibro* this,char* titulo);
int libro_GetTitulo(eLibro* this, char* titulo);

int libro_SetAutor(eLibro* this,char* autor);
int libro_GetAutor(eLibro* this,char* autor);

int libro_SetPrecio(eLibro* this,float precio);
int libro_GetPrecio(eLibro* this,float* precio);

int libro_SetIdEditorial(eLibro* this,int idEditorial);
int libro_GetIdEditorial(eLibro* this,int* idEditorial);

void Libro_MostrarUnLibro(eLibro* this);
void MostrarLibroConEditorial(eLibro* this,eEditorial* thisE);

int ordenarPorAutor(void* a1, void* a2);
int filtroMinotauro(void* this);
int AplicarDescuento(void* this);
#endif /* LIBRO_H_ */
