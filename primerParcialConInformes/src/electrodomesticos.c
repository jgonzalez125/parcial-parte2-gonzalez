/*
 * electrodomesticos.c
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "electrodomesticos.h"
#include "marca.h"
#include "reparacion.h"

static const char MARCA[5][20] = {"Wirpool", "Sony", "Liliana", "Gafa", "Philips"};


/*
 * \brief Funcion para validar que la serie sea distinta de todas las demas
 *
 * \param array puntero a la direccion de memoria del array de Electrodomestico
 * \param longitud tamanio del array Electrodomestico
 *
 * \return retorna el indice donde se encuentra la serie if OK, -1 if ERROR
 */
static int elec_validarNumeroDeSerie(Electrodomestico* array, int longitud, int serie);

int elec_initArray(Electrodomestico* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
				array[i].isEmpty = 1;
				retorno = 0;
		}
	}
	return retorno;
}

int elec_getEmptyIndex(Electrodomestico* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].isEmpty == 1){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int elec_imprimir(Electrodomestico* pElectrodomestico){
	int retorno = -1;

	if(pElectrodomestico != NULL && !pElectrodomestico->isEmpty){
		printf("\nNum de serie: %d -- Modelo: %d -- Marca: %s", pElectrodomestico->serie, pElectrodomestico->modelo, MARCA[pElectrodomestico->idMarca - 1000]);
		retorno = 0;
	}

	return retorno;
}

int elec_imprimirArray(Electrodomestico* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].isEmpty != 1){
				printf("\nid: %d serie: %d -- Modelo: %d -- Marca: %s", array[i].id, array[i].serie, array[i].modelo, MARCA[array[i].idMarca - 1000]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int elec_bajaArray(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparacion, int indice){
	int retorno = -1;

	if(array != NULL && longitud > 0 && indice < longitud && array[indice].isEmpty == 0 && indice >= 0){
		if(elec_buscarId(array, longitud, array[indice].id) < 0){
			printf("\nError, ese id no corresponde a ningun Electrodomestico");
		}else{
			printf("\nElectrodomestico a ser eliminado: \n");
			elec_imprimir(&array[indice]);
			if(!rep_bajaArray(arrayReparaciones, longitudReparacion, array[indice].serie)){
				printf("\nEsta(s) reparacion(es) fueron eliminada(s) del sistema");
			}
			array[indice].isEmpty = 1;
			retorno = 0;
		}

	}
	return retorno;
}


int elec_buscarId(Electrodomestico* array, int longitud, int idBuscado){
	int retorno = -1;

	if(array != NULL && longitud > 0 && idBuscado >= 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].id == idBuscado){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int elec_imprimirPorIdMarca(Electrodomestico* array, int longitud, int idBuscado){
	int retorno = -1;

	if(array != NULL && longitud > 0 && idBuscado >= 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].idMarca == idBuscado){
				elec_imprimir(&array[i]);
				retorno = i;
			}
		}
	}
	return retorno;
}

int elec_buscarSerie(Electrodomestico* array, int longitud, int serie){
	int retorno = -1;

	if(array != NULL && longitud > 0 && serie >= 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].serie == serie){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

static int elec_validarNumeroDeSerie(Electrodomestico* array, int longitud, int serie){
	int retorno = 0;
	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].isEmpty) continue;
			if(array[i].serie == serie){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int elec_cargarArray(Electrodomestico* array, int longitud, int indice, int* idElectrodomestico, int idMarca){
	int retorno = -1;
	Electrodomestico variableElectrodomestico;

	if(longitud > 0 && array != NULL && indice < longitud && idElectrodomestico != NULL && idMarca >= 0){
		if(!utn_getNumero(&variableElectrodomestico.modelo, "\nIngrese anio de fabricacion (1980 - 2020)", "\nError, reingrese", 1980, 2020, 3) &&
				!utn_getNumero(&variableElectrodomestico.serie, "\nIngrese numero de serie (1 - 10000)", "\nError, reingrese", 1, 10000, 3)){
			if(elec_validarNumeroDeSerie(array, longitud, variableElectrodomestico.serie) == -1){
				printf("\nNo puede haber numeros de serie iguales");
			}else{
				variableElectrodomestico.idMarca = idMarca;
				variableElectrodomestico.id = *idElectrodomestico;
				variableElectrodomestico.isEmpty = 0;
				array[indice] = variableElectrodomestico;
				(*idElectrodomestico)++;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int elec_buscarSeriePorId(Electrodomestico* array, int limite, int idBuscado){
	int retorno = -1;

	if(array != NULL && limite > 0){
		for(int i = 0; i < limite; i++){
			if(array[i].id == idBuscado){
				retorno = array[i].serie;
				break;
			}
		}
	}
	return retorno;
}

int elec_modificarArray(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones, int indice){
	int retorno = -1;
	int opcion;
	int auxiliarIndice;
	Electrodomestico bufferEntidad;

	if(array != NULL && longitud > 0 && indice < longitud && array[indice].isEmpty == 0 && indice >= 0){
		do{
			printf("\nElectrodomestico a ser modificado: \n");
			elec_imprimir(&array[indice]);
			if(!utn_getNumero(&opcion, "\nQue campo desea modificar? \n1)Modelo\n2)Serie\n3)No modificar","\nError, reingrese", 1, 3, 3)){
				switch(opcion){
				case 1:
					if(!utn_getNumero(&bufferEntidad.modelo, "\nModifique modelo: (1980 - 2020)", "\nError", 1980, 2020, 3)){
						printf("Modelo modificado exitosamente");
						array[indice].modelo = bufferEntidad.modelo;
					}
					break;
				case 2:
					if(!utn_getNumero(&bufferEntidad.serie, "\nModifique serie: (1 - 10000)", "\nError, reingrese:", 1, 10000,3) &&
						elec_validarNumeroDeSerie(array, longitud, bufferEntidad.serie) != -1){
						auxiliarIndice = rep_buscarSerie(arrayReparaciones, longitudReparaciones, array[indice].serie);
						if(bufferEntidad.serie != array[indice].serie && auxiliarIndice >= 0){
							if(!utn_getNumero(&opcion, "\nSu numero de serie cambio, que desea hacer? "
														"\n1-Modificar en la reparacion asignada\n2-Eliminar la reparacion asignada", "\nError, reingrese", 1, 2, 3)){
								switch(opcion){
								case 1:
									arrayReparaciones[auxiliarIndice].serie = bufferEntidad.serie;
									break;
								case 2:
									if(!rep_bajaArray(arrayReparaciones, longitudReparaciones, array[indice].serie)){
										printf("\nEsta(s) reparacion(es) fueron eliminada(s) del sistema");
									}
									break;
								}
								array[indice].serie = bufferEntidad.serie;
							}
						}
						printf("Serie modificada exitosamente");
						array[indice].serie = bufferEntidad.serie;
					}else{
						printf("\nNumero de serie no valido");
					}
					break;
				default:
					printf("\nSaliendo de la modificacion");
				}
				retorno = 0;
			}
		}while(opcion != 3);
	}
	return retorno;
}

int elec_ordenarPorModeloSerie(Electrodomestico* array, int longitud){
	Electrodomestico auxElectrodomestico;
	int retorno = -1;
	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			for(int j = i+i; j < longitud - 1; j++){
				if (array[i].isEmpty == 1 || array[j].isEmpty == 1) {
					continue;
				}
				if(array[i].modelo > array[j].modelo || (array[i].modelo == array[j].modelo && array[i].serie > array[j].serie)){
					auxElectrodomestico = array[i];
					array[i] = array[j];
					array[j] = auxElectrodomestico;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}


