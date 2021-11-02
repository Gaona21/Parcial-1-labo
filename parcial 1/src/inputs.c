#include "inputs.h"

int GetString(char mensaje[], char cadena[], int tam){
	char auxiliarString[500];
	int retorno = 0;

	if(cadena != NULL && mensaje != NULL){
		puts(mensaje);
		fflush(stdin);
		gets(auxiliarString);

		retorno = 1;

		while(strlen(auxiliarString)>tam){
			printf("Error reingrese: ");
			fflush(stdin);
			gets(auxiliarString);
		}
		strncpy(cadena, auxiliarString,tam);
	}
	return retorno;
}

int GetCuit(char mensaje[], char cadena[], int tam){
	char auxiliarString[100];
	int retorno = 0;
	int respuesta;

	if(cadena != NULL && mensaje != NULL){

		tam = tam-1;

		puts(mensaje);
		fflush(stdin);
		gets(auxiliarString);

		respuesta = esNumerica(auxiliarString);

			while(respuesta == 0 || (strlen(auxiliarString)>tam || strlen(auxiliarString)<tam)){
				printf("Formato erroneo, reingrese: ");
				fflush(stdin);
				gets(auxiliarString);
				respuesta = esNumerica(auxiliarString);
			}

		strncpy(cadena,auxiliarString,tam);
		retorno = 1;
	}
	return retorno;
}

int getNumero(int* pResultado, char mensaje[]){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		do{
			printf("%s",mensaje);

			respuesta = getInt(&auxiliarInt);
			if(respuesta==0){
				*pResultado = auxiliarInt;
				retorno = 0;
			}
		}while(respuesta!=0);
	}

	return retorno;
}

int getInt(int* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(esNumerica(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atoi(auxiliarIngresado);
	}
	return retorno;
}

int esNumerica(char* cadena){
	int retorno = 1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

float getNumeroFloat(float* pResultado, char mensaje[]){
	int retorno = -1;
	float auxiliarFloat;
	int respuesta;

	if(pResultado != NULL && mensaje != NULL){
		do{
			printf("%s",mensaje);

			respuesta = getFloat(&auxiliarFloat);
			if(respuesta==0){
				*pResultado = auxiliarFloat;
				retorno = 0;
			}
		}while(respuesta!=0);
	}
	return retorno;
}

int getFloat(float* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(esNumericaFloat(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atof(auxiliarIngresado);
	}
	return retorno;
}

int esNumericaFloat(char* cadena){
	int retorno = 1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			if(cadena[i]!='.'){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
