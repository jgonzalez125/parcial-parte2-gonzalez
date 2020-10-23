/*
 * marca.c
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "marca.h"
#include "utn.h"
#define DESC_LEN 20

void mar_imprimir(Marca *array) {
	if (array != NULL) {
		printf("\nid marca: %d) --  Descripcion: %s", array->id,
				array->descripcion);
	}
}

int mar_altaForzada(Marca* array, int longitud, int* idMarcas, int indice, char* nombre, char* descripcion){
	int retorno = -1;
	Marca variableMarca;

	if(longitud > 0 && array != NULL && indice < longitud && idMarcas != NULL){
			strncpy(variableMarca.descripcion, descripcion, DESC_LEN);
			strncpy(variableMarca.nombre, nombre, DESC_LEN);
			variableMarca.id = *idMarcas;
			variableMarca.isEmpty = 0;
			array[indice] = variableMarca;
			(*idMarcas)++;
			retorno = 0;
	}
	return retorno;
}

int mar_imprimirArray(Marca *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			if (array[i].isEmpty != 1) {
				printf("\nid: %d) -- Nombre: %s -- Descripcion: %s", array[i].id, array[i].nombre, array[i].descripcion);
				retorno++;
			}
		}
	}
	return retorno;
}

int mar_getEmptyIndex(Marca *array, int longitud) {
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

int mar_initArray(Marca* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
				array[i].isEmpty = 1;
				retorno = 0;
		}
	}
	return retorno;
}

int mar_cargarArray(Marca* array, int longitud, int indice, int* idMarcas){
	int retorno = -1;
	Marca auxMarca;

	if(longitud > 0 && array != NULL && indice < longitud && idMarcas != NULL){
		if(!utn_getDescripcion(auxMarca.descripcion, DESC_LEN, "\nIngrese descripcion:", "\nError", 3)){
			auxMarca.id = *idMarcas;
			auxMarca.isEmpty = 0;
			array[indice] = auxMarca;
			(*idMarcas)++;
			retorno = 0;
		}

	}
	return retorno;
}

int mar_buscarId(Marca* array, int limite, int idBuscado){
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

int mar_bajaArray(Marca* array, int longitud, int indice){
	int retorno = -1;

	if(array != NULL && longitud > 0 && indice < longitud && array[indice].isEmpty == 0 && indice >= 0){
			printf("\nMarca a ser eliminada:");
			mar_imprimir(&array[indice]);
			array[indice].isEmpty = 1;
			retorno = 0;
	}
	return retorno;
}

int mar_modificarArray(Marca* array, int longitud, int indice){
	int retorno = -1;
	char auxDescripcion[DESC_LEN];

	if(array != NULL && longitud > 0 && indice < longitud && array[indice].isEmpty == 0 && indice >= 0){
			printf("\nMarca a ser modificada: ");
			mar_imprimir(&array[indice]);
			if(!utn_getDescripcion(auxDescripcion, DESC_LEN, "\nIngrese nueva descripcion: ", "\nError", 3)){
				strncpy(array[indice].descripcion, auxDescripcion, DESC_LEN);
				retorno = 0;
			}
	}
	return retorno;
}
