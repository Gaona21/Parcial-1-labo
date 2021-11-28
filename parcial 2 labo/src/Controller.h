#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "libro.h"
#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_sortEmployee(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro);

int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial);
int controller_ListEditorial(LinkedList* pArrayListLibro);

int controller_ListLibroConEditorial(LinkedList* pArrayListLibro,LinkedList* pArrayListEditorial);
int controller_FilterEditorialMinotauro(LinkedList* pArrayListLibro, LinkedList* ListaResultado, LinkedList* ListaEditorial);

#endif /* CONTROLLER_H_ */
