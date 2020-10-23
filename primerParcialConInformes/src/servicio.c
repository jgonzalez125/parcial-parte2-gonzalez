/*
 * servicio.c
 *
 *  Created on: Oct 15, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "electrodomesticos.h"
#include "marca.h"
#include "servicio.h"
#include "reparacion.h"

int serv_imprimir(Servicio *array) {
	int retorno = -1;

	if (array != NULL) {
		printf("\nid servicio: %d) Descripcion: %s -- Precio: %.2f ", array->id,
				array->descripcion, array->precio);
		retorno = 0;
	}

	return retorno;
}



int serv_imprimirArray(Servicio *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			if (array[i].isEmpty != 1) {
				printf("\nid: %d) Descripcion: %s -- Precio: %.2f", array[i].id,
						array[i].descripcion, array[i].precio);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int serv_initArray(Servicio* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
				array[i].isEmpty = 1;
				retorno = 0;
		}
	}
	return retorno;
}

int serv_cargarArray(Servicio* array, int longitud, int indice, int* idServicio){
	int retorno = -1;
	Servicio bufferServicio;

	if(longitud > 0 && array != NULL && indice < longitud && idServicio != NULL){
		if(utn_getDescripcion(bufferServicio.descripcion, DESC_LEN, "\nIngrese descripcion del servicio:", "\nError", 3) == 0 &&
			utn_getNumeroFlotante(&bufferServicio.precio, "\nIngrese precio del servicio:", "\nError, reingrese", 1000, 10000, 3) == 0){
			bufferServicio.id = *idServicio;
			bufferServicio.isEmpty = 0;
			array[indice] = bufferServicio;
			(*idServicio)++;
			retorno = 0;
		}

	}
	return retorno;
}

int serv_altaForzada(Servicio* array, int longitud, int* idServicios, int indice, char* descripcion, int precio){
	int retorno = -1;
	Servicio variableServicio;

	if(longitud > 0 && array != NULL && indice < longitud && idServicios != NULL){
			strncpy(variableServicio.descripcion, descripcion, DESCRIPCION_LEN);
			variableServicio.precio = precio;
			variableServicio.id = *idServicios;
			variableServicio.isEmpty = 0;
			array[indice] = variableServicio;
			(*idServicios)++;
			retorno = 0;
	}
	return retorno;
}


int serv_getEmptyIndex(Servicio *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int serv_buscarId(Servicio* array, int limite, int idBuscado){
	int retorno = -1;

	if(array != NULL && limite > 0){
		for(int i = 0; i < limite; i++){
			if(array[i].id == idBuscado && !array[i].isEmpty){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int serv_buscarTipoPorId(Servicio* array, int limite, int idBuscado){
	int retorno = -1;

	if(array != NULL && limite > 0){
		for(int i = 0; i < limite; i++){
			if(array[i].id == idBuscado && !array[i].isEmpty && !strncmp(array[i].descripcion, "Garantia", DESCRIPCION_LEN)){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
