#include "parser.h"
#include "editorial.h"

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno = -1;

	char idLibro[150];
	char titulo[150];
	char autor[150];
	char precio[150];
	char idEditorial[150];
	int respuesta;

	eLibro* pLibro = NULL;

	if(pFile != NULL && pArrayListLibro != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLibro,titulo,autor,precio,idEditorial); //tiene enxabezado
		//printf("%s--%s--%s--%s--%s\n",idLibro,titulo,autor,precio,idEditorial);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLibro,titulo,autor,precio,idEditorial);
			//printf("%s--%s--%s--%s--%s\n",idLibro,titulo,autor,precio,idEditorial);

			pLibro = libro_NewParametros(idLibro, titulo, autor, precio, idEditorial);

			if(pLibro != NULL){
				respuesta = ll_add(pArrayListLibro, pLibro);

				if(respuesta == 0){
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno = -1;

	eLibro* pLibro = NULL;


	if(pFile != NULL && pArrayListLibro != NULL){

		while(!feof(pFile)){
			pLibro = libro_New();
			fread(pLibro,sizeof(eLibro),1,pFile);

			if(!feof(pFile)){
				ll_add(pArrayListLibro, pLibro);
			}
		}
		retorno = 0;
	}
    return retorno;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int retorno = -1;

	char idEditorial[150];
	char nombre[150];
	int respuesta;

	eEditorial* pEditorial = NULL;

	if(pFile != NULL && pArrayListEditorial != NULL){
		fscanf(pFile, "%[^,],%[^\n]\n",idEditorial,nombre); //tiene enxabezado
		//printf("%s--%s\n",idEditorial,nombre);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^\n]\n",idEditorial,nombre);
			//printf("%s--%s\n",idEditorial,nombre);

			pEditorial = editorial_NewParametros(idEditorial,nombre);

			if(pEditorial != NULL){
				respuesta = ll_add(pArrayListEditorial, pEditorial);

				if(respuesta == 0){
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

