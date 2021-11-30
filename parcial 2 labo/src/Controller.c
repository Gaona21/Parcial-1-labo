#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int respuesta;

	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListLibro != NULL){
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			respuesta = parser_LibroFromText(pArchivo, pArrayListLibro);

			if(respuesta == 0){
				printf("\nSe cargaron los datos correctamente.\n\n");
				retorno = 0;
			}
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int respuesta;

	FILE* pArchivo;

	if(path != NULL && pArrayListLibro != NULL){
		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL){
			respuesta = parser_LibroFromBinary(pArchivo, pArrayListLibro);
			if(respuesta == 0){
				printf("\nSe cargaron los datos correctamente.\n\n");
				retorno = 0;
			}
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}


int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int respuesta;

	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListEditorial != NULL){
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			respuesta = parser_EditorialFromText(pArchivo, pArrayListEditorial);

			if(respuesta == 0){
				printf("\nSe cargaron los datos correctamente.\n\n");
				retorno = 0;
			}
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}


int controller_ListLibro(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int i;
	int len;

	eLibro* pLibro = NULL;

	if(pArrayListLibro != NULL){
		len = ll_len(pArrayListLibro);

		if(len>0){
			for(i=0; i<len; i++){
				pLibro = ll_get(pArrayListLibro, i);
				Libro_MostrarUnLibro(pLibro);
			}
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}


int controller_ListEditorial(LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int i;
	int len;

	eEditorial* pEditorial = NULL;

	if(pArrayListEditorial != NULL){
		len = ll_len(pArrayListEditorial);

		if(len>0){
			for(i=0; i<len; i++){
				pEditorial = ll_get(pArrayListEditorial, i);
				Editorial_MostrarUnaEditorial(pEditorial);
			}
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}


int controller_ListLibroConEditorial(LinkedList* pArrayListLibro,LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int i;
	int len;
	int lenEditorial;

	eLibro* pLibro = NULL;
	eEditorial* pEditorial = NULL;

	if(pArrayListLibro != NULL){
		len = ll_len(pArrayListLibro);
		lenEditorial = ll_len(pArrayListEditorial);
		if(len>0 && lenEditorial>0){
			for(i=0; i<len; i++){
				pLibro = ll_get(pArrayListLibro, i);
				for(int j=0; j<lenEditorial; j++){
					pEditorial = ll_get(pArrayListEditorial, j);
					MostrarLibroConEditorial(pLibro, pEditorial);
				}
			}
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}


int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int retorno= -1;
	int len;

	if(pArrayListLibro!=NULL){
		len = ll_len(pArrayListLibro);
		if(len>0){
			ll_sort(pArrayListLibro, ordenarPorAutor, 1);
			printf("\nSe ordeno la lista por autor de forma ascendente.\n\n");
			retorno = 0;
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}


int controller_FilterEditorialMinotauro(LinkedList* pArrayListLibro, LinkedList* ListaResultado, LinkedList* ListaEditorial)
{
	int retorno= -1;
	int len;

	if(pArrayListLibro!=NULL){
		len = ll_len(pArrayListLibro);
		if(len>0){
			ListaResultado = ll_filter(pArrayListLibro, filtroMinotauro);
			controller_ListLibroConEditorial(ListaResultado, ListaEditorial);
			retorno = 0;
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int len;

	eLibro* pLibro = NULL;
	FILE* pArchivo = NULL;

	if(pArrayListLibro!=NULL){
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL){
			len = ll_len(pArrayListLibro);

			if(len>0){
				for(int i=0; i<len;i++){
					pLibro =(eLibro*) ll_get(pArrayListLibro, i);
					fprintf(pArchivo,"%d,%s,%s,%2.f,%d\n",pLibro->idLibro,pLibro->titulo,pLibro->autor,pLibro->precio,pLibro->idEditorial);
				}
			}else{
				printf("\nNo hay nada para guardar.\n\n");
			}
			retorno = 0;

		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int len;

	eLibro* pLibro = NULL;
	FILE* pArchivo;

	if(pArrayListLibro!=NULL){
		pArchivo = fopen(path,"wb");

		if(pArchivo!=NULL){
			len = ll_len(pArrayListLibro);

			if(len>0){
				for(int i=0; i<len; i++){
					pLibro = (eLibro*) ll_get(pArrayListLibro, i);
					if(pLibro != NULL){
						fwrite(pLibro,sizeof(eLibro),1,pArchivo);
					}else{
						break;
					}
				}
			}else{
				printf("\nNo hay nada para guargar.\n\n");
			}
			retorno = 0;
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

int controller_MapLibro(LinkedList* this, LinkedList* copiaThis){
	int retorno =-1;
	int len = ll_len(this);

	copiaThis = ll_clone(this);

	if(this!=NULL){
		if(len>0){
			ll_map(copiaThis, AplicarDescuento);

			controller_saveAsTextMapeado("mapeado.csv", copiaThis);

			printf("\nSe aplico el descuento correspondiente.\n\n");

			retorno = 0;
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
	return retorno;
}

int controller_saveAsTextMapeado(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int len;

	eLibro* pLibro = NULL;
	FILE* pArchivo = NULL;

	if(pArrayListLibro!=NULL){
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL){
			len = ll_len(pArrayListLibro);

			if(len>0){
				fprintf(pArchivo,"idLibro,titulo,autor,precio,idEditorial\n");
				for(int i=0; i<len;i++){
					pLibro =(eLibro*) ll_get(pArrayListLibro, i);

						fprintf(pArchivo,"%d,%s,%s,%.2f,%d\n",pLibro->idLibro,pLibro->titulo,pLibro->autor,pLibro->precio,pLibro->idEditorial);
				}
			}else{
				printf("\nNo hay nada para guardar.\n\n");
			}
			retorno = 0;

		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

