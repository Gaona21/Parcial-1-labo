#include "libro.h"

eLibro* libro_New(){
	eLibro* pLibro = NULL;

	pLibro =(eLibro*) malloc(sizeof(eLibro));

	if(pLibro!=NULL){
		libro_SetId(pLibro, 0);
		libro_SetTitulo(pLibro, " ");
		libro_SetAutor(pLibro, " ");
		libro_SetPrecio(pLibro, 0);
		libro_SetIdEditorial(pLibro, 0);
	}
	return pLibro;
}

eLibro* libro_NewParametros(char* idLibro, char* titulo, char* autor, char* precio, char* idEditorial){
	eLibro* pLibro = NULL;

	pLibro = libro_New();

	if(pLibro!=NULL){
		libro_SetId(pLibro, atoi(idLibro));
		libro_SetTitulo(pLibro, titulo);
		libro_SetAutor(pLibro, autor);
		libro_SetPrecio(pLibro, atof(precio));
		libro_SetIdEditorial(pLibro, atoi(idEditorial));

	}
	return pLibro;
}

int libro_SetId(eLibro* this,int id){
	int retorno=-1;

	if(id>0){
		this->idLibro = id;
		retorno = 0;
	}
	return retorno;
}
int libro_GetId(eLibro* this,int* id){
	int retorno=-1;
	if(id>0){
		 *id = this->idLibro;
		retorno = 0;
	}
	return retorno;
}

int libro_SetTitulo(eLibro* this,char* titulo){
	int retorno=-1;

	if(this!=NULL){
		strncpy(this->titulo,titulo,sizeof(this->titulo));
		retorno = 0;
	}
	return retorno;
}
int libro_GetTitulo(eLibro* this, char* titulo){
	int retorno=-1;

	if(this!=NULL){
		strncpy(titulo,this->titulo,sizeof(this->titulo));
		retorno = 0;
	}
	return retorno;
}


int libro_SetAutor(eLibro* this,char* autor){
	int retorno=-1;

	if(this!=NULL){
		strncpy(this->autor,autor,sizeof(this->autor));
		retorno = 0;
	}
	return retorno;
}
int libro_GetAutor(eLibro* this,char* autor){
	int retorno=-1;

	if(this!=NULL){
		strncpy(autor,this->autor,sizeof(this->autor));
		retorno = 0;
	}
	return retorno;
}


int libro_SetPrecio(eLibro* this,float precio){
	int retorno=-1;

	if(this!=NULL){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int libro_GetPrecio(eLibro* this,float* precio){
	int retorno=-1;

	if(this!=NULL){
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int libro_SetIdEditorial(eLibro* this,int idEditorial){
	int retorno=-1;

	if(this!=NULL && idEditorial>0){
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
int libro_GetIdEditorial(eLibro* this,int* idEditorial){
	int retorno=-1;

	if(this!=NULL && idEditorial>0){
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

void Libro_MostrarUnLibro(eLibro* this){
	printf("%d---%s---%s---%2.f--%d\n",this->idLibro,this->titulo,this->autor,this->precio,this->idEditorial);
}

void MostrarLibroConEditorial(eLibro* this,eEditorial* thisE){
	if(this->idEditorial == thisE->idEditorial){
		printf("%-5d %-30s %-20s %-20.2f %-20s\n",this->idLibro,this->titulo,this->autor,this->precio,thisE->nombre);
	}
}

int ordenarPorAutor(void* a1, void* a2){
	int retorno = 0;

	eLibro* pA1 = NULL;
	eLibro* pA2 = NULL;

	pA1 = (eLibro*) a1;
	pA2 = (eLibro*) a2;

	retorno = strcmp(pA1->autor,pA2->autor);

	if(retorno>0){
		retorno = 1;
	}else{
		if(retorno<0){
			retorno = -1;
		}
	}
	return retorno;
}

int filtroMinotauro(void* this){
	int retorno = -1;
	int idaux;
	eLibro* pLibro = NULL;

	if(this!=NULL){
		pLibro = (eLibro*) this;
		libro_GetIdEditorial(pLibro, &idaux);

		if(idaux == 4){
			retorno = 1;
		}else{
			retorno = 0;
		}
	}
	return retorno;
}

int AplicarDescuento(void* this){
	int retorno = -1;
	int descuento = 0;
	int auxIdEditorial;
	float auxPrecio;

	eLibro* pLibro = NULL;

	if(this!=NULL){
		pLibro = (eLibro*) this;
		libro_GetIdEditorial(pLibro, &auxIdEditorial);
		libro_GetPrecio(pLibro, &auxPrecio);


		if(auxIdEditorial == 1 && auxPrecio >= 300) {

			descuento = 20;
		}

		if(auxIdEditorial == 2 && auxPrecio <=200){


			descuento = 10;

		}

		auxPrecio = auxPrecio-((auxPrecio*descuento)/100);
		libro_SetPrecio(pLibro, auxPrecio);

		retorno = descuento;
	}
	return retorno;
}










