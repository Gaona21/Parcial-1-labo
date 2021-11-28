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
				controller_sortEmployee(listaLibro);
				break;

			case 4:
				controller_ListLibroConEditorial(listaLibro, listaEditorial);
				break;

			case 5:
				controller_FilterEditorialMinotauro(listaLibro,listaResultado,listaEditorial);
				controller_ListLibroConEditorial(listaResultado, listaEditorial);
				break;

			case 6:
				printf("\nSe cerro el programa...\n");
				break;

			default:
				printf("\nOpcion incorrecta\n");
		}
		if(opcion!=6){
			system("pause");
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
