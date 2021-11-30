#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "libro.h"
#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los libros desde el archivo dataLibro.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLibro);

/** \brief Carga los datos de los libros desde el archivo datalibro.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro);

/** \brief Listar libro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro);

/** \brief Ordenar libro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_sortLibro(LinkedList* pArrayListLibro);

/** \brief Guarda los datos de los libros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);

/** \brief Guarda los datos de los libros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro);

/** \brief Carga los datos de los rditoriales desde el archivo dataEditorial.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditorial LinkedList*
 * \return int
 *
 */
int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial);

/** \brief Listar editorial
 *
 * \param path char*
 * \param pArrayListeditorial LinkedList*
 * \return int
 *
 */
int controller_ListEditorial(LinkedList* pArrayListLibro);

/** \brief Listar libro con editorial
 * \param pArrayListLibro LinkedList*
 * \param pArrayListeditorial LinkedList*
 * \return int
 *
 */
int controller_ListLibroConEditorial(LinkedList* pArrayListLibro,LinkedList* pArrayListEditorial);

/** \brief crea lista de libros con editorial minotauro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \param pArrayListResultado LinkedList*
 * \param pArrayListEditorial LinkedList*
 * \return int
 *
 */
int controller_FilterEditorialMinotauro(LinkedList* pArrayListLibro, LinkedList* ListaResultado, LinkedList* ListaEditorial);
int controller_MapLibro(LinkedList* this, LinkedList* copiaThis);

int controller_saveAsTextMapeado(char* path , LinkedList* pArrayListLibro);
#endif /* CONTROLLER_H_ */
