#include "editorial.h"

eEditorial* editorial_New(){
	eEditorial* pEditorial = NULL;

	pEditorial =(eEditorial*) malloc(sizeof(eEditorial));
	if(pEditorial!=NULL){
		editorial_setId(pEditorial, 0);
		editorial_setNombre(pEditorial, " ");
	}
	return pEditorial;
}

eEditorial* editorial_NewParametros(char* idEditorial, char* nombre){
	eEditorial* pEditorial = NULL;

	pEditorial = editorial_New();

	if(pEditorial != NULL){
		editorial_setId(pEditorial, atoi(idEditorial));
		editorial_setNombre(pEditorial, nombre);
	}
	return pEditorial;
}

int editorial_setId(eEditorial* this,int id){
	int retorno = -1;

	if(this!=NULL && id>0){
		this->idEditorial = id;
		retorno  = 0;
	}
	return retorno;
}

int editorial_get(eEditorial* this,int* id){
	int retorno = -1;

	if(this!=NULL && id>0){
		*id = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

int editorial_setNombre(eEditorial* this,char* nombre){
	int retorno = -1;

	if(this!=NULL){
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int editorial_getNombre(eEditorial* this,char* nombre){
	int retorno = -1;

	if(this!=NULL){
		strncpy(nombre,this->nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

void Editorial_MostrarUnaEditorial(eEditorial* this){
	if(this!=NULL){
		printf("%d---%s\n",this->idEditorial,this->nombre);
	}
}
