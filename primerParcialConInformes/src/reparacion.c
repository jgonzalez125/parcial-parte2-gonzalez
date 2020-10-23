/*
 * reparacion.c
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
#include "servicio.h"
#include "reparacion.h"

int rep_initArray(Reparacion* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
				array[i].isEmpty = 1;
				retorno = 0;
		}
	}
	return retorno;
}

int rep_getEmptyIndex(Reparacion* array, int longitud){
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

int rep_cargarArray(Reparacion* array, int longitud, int indice, int serie, int idServicio, int* id){
	int retorno = -1;
	Fecha bufferEntidad;

	if(longitud > 0 && array != NULL && indice < longitud && id != NULL){
		if(!utn_getNumero(&bufferEntidad.dia, "\nIngrese dia:", "\nError, reingrese", 1, 31, 3) &&
			!utn_getNumero(&bufferEntidad.mes, "\nIngrese mes:", "\nError, reingrese", 1, 12, 3) &&
			!utn_getNumero(&bufferEntidad.anio, "\nIngrese anio:", "\nError, reingrese", 1900, 2020, 3)){

			array[indice].isEmpty = 0;
			array[indice].fecha = bufferEntidad;
			array[indice].id = *(id);
			array[indice].idServicio = idServicio;
			array[indice].serie = serie;
			(*id)++;
			retorno = 0;
		}

	}
	return retorno;
}

int rep_bajaArray(Reparacion* array, int longitud, int serie){
	int retorno = -1;

	if(array != NULL && longitud > 0 && serie >= 1){
		for(int i = 0; i < longitud; i++){
			if(array[i].isEmpty) continue;

			if(array[i].serie == serie){
				printf("\nReparacion a ser eliminada:");
				rep_imprimir(&array[i]);
				array[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int rep_buscarId(Reparacion* array, int limite, int idBuscado){
	int retorno = -1;

	if(array != NULL && limite > 0 && idBuscado >= 0){
		for(int i = 0; i < limite; i++){
			if(array[i].id == idBuscado && array[i].isEmpty != 1){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int rep_imprimirArray(Reparacion* array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud){
		for(int i = 0; i < longitud; i++){
			if(!array[i].isEmpty){
			printf("\nSerie de electrodomestico: %d -- id de Servicio: %d -- fecha: %d/%d/%d",
					array[i].serie,
					array[i].idServicio,
					array[i].fecha.dia,
					array[i].fecha.mes,
					array[i].fecha.anio);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int rep_buscarSerie(Reparacion* array, int longitud, int serie){
	int retorno = -1;
	if(array != NULL && longitud && serie >= 1){
		for(int i = 0; i < longitud; i++){
			if(array[i].serie == serie){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int rep_buscarFecha(Reparacion* array, int longitud, Fecha fecha){
	int retorno = -1;
	if(array != NULL && longitud && fecha.anio > 0 && fecha.mes > 0 && fecha.dia > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].fecha.dia == fecha.dia &&
				array[i].fecha.mes == fecha.mes &&
				array[i].fecha.anio == fecha.anio){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int rep_buscarServicio(Reparacion* array, int longitud, int idServicio){
	int retorno = -1;
	if(array != NULL && longitud && idServicio >= 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].idServicio == idServicio){
				retorno = i;
			}
		}
	}
	return retorno;
}


int rep_imprimirPorSerie(Reparacion* array, int longitud, int serie){
	int retorno = -1;
	if(array != NULL && longitud && serie >= 1){
		for(int i = 0; i < longitud; i++){
			if(array[i].serie == serie){
				rep_imprimir(&array[i]);
				retorno = i;
			}
		}
	}
	return retorno;
}


int rep_imprimir(Reparacion* array){
	int retorno = -1;

	if(array != NULL && array->isEmpty != 1){
		printf("\nid: %d) serie: %d -- idServicio: %d -- fecha: %d/%d/%d",
				array->id,
				array->serie,
				array->idServicio,
				array->fecha.dia,
				array->fecha.mes,
				array->fecha.anio);
		retorno = 0;
	}
	return retorno;
}

//int rep_modificarArray(Reparacion* array, Electrodomestico* arrayElectrodomesticos, Servicio* arrayServicio, int longitudServ, int longitudElec, int longitud, int indice){
//	int retorno = -1;
//	int opcion;
//	Reparacion bufferEntidad;
//
//	if(array != NULL && longitud > 0 && indice < longitud && array[indice].isEmpty == 0 && indice >= 0){
//		do{
//			printf("\nPantalla a ser modificada: ");
//			rep_imprimir(&array[indice]);
//			if(!utn_getNumero(&opcion, "\nQue campo desea modificar? \n1)Serie\n2)id Servicio\n3)fecha\n4)No modificar","\nError, reingrese", 1, 4, 3)){
//				switch(opcion){
//				case 1:
//					if(!utn_getNumero(&bufferEntidad.serie, "\nModifique serie:", "\nError", 1, 10, 3) &&
//						elec_buscarSerie(arrayElectrodomesticos, longitudElec, bufferEntidad.serie) >= 0){
//						printf("Serie modificado exitosamente");
//						array[indice].serie = bufferEntidad.serie;
//					}else{
//						printf("\nEsa serie no es valida");
//					}
//					break;
//				case 2:
//					if(!utn_getNumero(&bufferEntidad.idServicio, "\nModifique id servicio:", "\nError", 1, 10, 3) &&
//					   serv_buscarId(arrayServicio, longitudServ, bufferEntidad.idServicio) >= 0){
//						array[indice].idServicio = bufferEntidad.idServicio;
//						printf("Lugar modificada exitosamente");
//					}else{
//						printf("\nEse id no es valido");
//					}
//					break;
//				case 3:
//					if(!utn_getNumero(&opcion, "\nQue campo desea modificar? \n1)Dia\n2)Mes\n3)Anio\n4)No modificar", "\nError. reingrese", 1, 3, 3)){
//						do{
//							switch(opcion){
//							case 1:
//								if(!utn_getNumero(&bufferEntidad.fecha.dia, "\nIngrese dia:", "\nError", 1, 31, 3)){
//									printf("\nDia modificado exitosamente");
//								}
//								break;
//							case 2:
//								if(!utn_getNumero(&bufferEntidad.fecha.mes, "\nIngrese mes:", "\nError", 1, 12, 3)){
//									printf("\nMes modificado exitosamente");
//								}
//								break;
//							case 3:
//								if(!utn_getNumero(&bufferEntidad.fecha.anio, "\nIngrese anio:", "\nError", 1900, 2020, 3)){
//									printf("\nAnio modificado exitosamente");
//								}
//								break;
//							default:
//								printf("\nSaliendo de modificacion de fecha...");
//								break;
//							}
//						}while(opcion != 4);
//					}
//					break;
//				default:
//					printf("\nSaliendo de la modificacion");
//				}
//				retorno = 0;
//			}
//		}while(opcion != 5);
//	}
//	return retorno;
//}

