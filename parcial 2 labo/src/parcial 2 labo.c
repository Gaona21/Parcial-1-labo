#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	char nombreArchivo[51];

	LinkedList* listaLibro = ll_newLinkedList();
	LinkedList* listaEditorial = ll_newLinkedList();
	LinkedList* listaResultado = ll_newLinkedList();
	LinkedList* listaMapeado = ll_newLinkedList();



	do{
		opcion = Menu();
		switch(opcion){
			case 1:
				GetString("Ingrese el nombre del archivo con su extencion: ", nombreArchivo, 51);
				controller_loadFromText(nombreArchivo, listaLibro);
				break;

			case 2:
				GetString("Ingrese el nombre del archivo con su extencion: ", nombreArchivo, 51);
				controller_loadFromTextEditorial(nombreArchivo, listaEditorial);
				break;

			case 3:
				controller_sortLibro(listaLibro);
				break;

			case 4:
				controller_ListLibroConEditorial(listaLibro, listaEditorial);
				break;

			case 5:
				controller_FilterEditorialMinotauro(listaLibro,listaResultado,listaEditorial);
				break;

			case 6:
				controller_MapLibro(listaLibro,listaMapeado);
				controller_loadFromText("mapeado.csv", listaMapeado);
				controller_ListLibroConEditorial(listaMapeado, listaEditorial);
				break;

			case 7:
				printf("\nSe cerro el programa...\n");
				break;

			default:
				printf("\nOpcion incorrecta\n");
		}
		if(opcion!=7){
			system("pause");
		}

	}while(opcion != 7);

	return EXIT_SUCCESS;
}
