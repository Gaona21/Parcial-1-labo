#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro);


int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);


#endif /* PARSER_H_ */
