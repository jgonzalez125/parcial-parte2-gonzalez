/*
 * informes.c
 *
 *  Created on: Oct 22, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "electrodomesticos.h"
#include "marca.h"
#include "reparacion.h"
#include "servicio.h"

int info_electrodomesticosModelo2020(Electrodomestico* array, int longitud){
	int retorno = -1;
	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].modelo == 2020 && !array[i].isEmpty){
				if(!elec_imprimir(&array[i])){
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int info_mostrarElectrodomesticosPorMarca(Electrodomestico* array, int longitud, int idMarca){
	int retorno = -1;
	if(array != NULL && longitud > 0){
		if(elec_imprimirPorIdMarca(array, longitud, idMarca) >= 0){
			retorno = 0;
		}
	}
	return retorno;
}

int info_mostrarReparacionesPorElectrodomestico(Reparacion* array, int longitud, int serie){
	int retorno = -1;
	if(array != NULL && longitud > 0 && serie){
		if(rep_imprimirPorSerie(array, longitud, serie) >= 0){
			retorno = 0;
		}
	}
	return retorno;
}

int info_mostrarElectrodomesticosSinReparaciones(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones){
	int retorno = -1;
	if(array != NULL && longitud > 0 && arrayReparaciones != NULL && longitudReparaciones > 0){
		for(int i = 0; i < longitud; i++){
			if(rep_buscarSerie(arrayReparaciones, longitudReparaciones, array[i].serie) == -1){
				if(!elec_imprimir(&array[i])){
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int info_calcularImporteDeReparaciones(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios, int serie){
	int auxIndiceServicio;
	int acumuladorImportes = 0;
	if(arrayReparaciones != NULL && longitudReparaciones > 0 && arrayServicios != NULL && longitudServicios > 0){
		for(int i = 0; i < longitudReparaciones; i++){
			if(arrayReparaciones[i].isEmpty) continue;
			if(rep_buscarSerie(arrayReparaciones, longitudReparaciones,serie) >= 0){
				auxIndiceServicio = serv_buscarId(arrayServicios, longitudServicios, arrayReparaciones[rep_buscarSerie(arrayReparaciones, longitudReparaciones, serie)].idServicio);
				acumuladorImportes = acumuladorImportes + arrayServicios[auxIndiceServicio].precio;
			}
		}
	}
	return acumuladorImportes;
}

int info_calcularImporteTotal(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios){
	int auxIndiceServicio;
	int acumuladorImportes = 0;
	if(arrayReparaciones != NULL && longitudReparaciones > 0 && arrayServicios != NULL && longitudServicios > 0){
		for(int i = 0; i < longitudReparaciones; i++){
			if(arrayReparaciones[i].isEmpty) continue;
			auxIndiceServicio = serv_buscarId(arrayServicios, longitudServicios, arrayReparaciones[i].idServicio);
			if(auxIndiceServicio >= 0 && !strncmp(arrayServicios[auxIndiceServicio].descripcion, "Mantenimiento", DESCRIPCION_LEN))
			acumuladorImportes = acumuladorImportes + arrayServicios[auxIndiceServicio].precio;
		}
	}
	printf(" %D", acumuladorImportes);
	return acumuladorImportes;
}

int info_calcularCantidadDeServicios(Reparacion* arrayReparaciones, int longitudReparaciones, int idsServicios, int* cantidadServiciosPedidos){
	int retorno = -1;
	int contadorServiciosPedidos = 0;
	int i;
	if(arrayReparaciones != NULL && longitudReparaciones > 0 && cantidadServiciosPedidos != NULL){
		for(i = 0; i < longitudReparaciones; i++){
			if(arrayReparaciones[i].isEmpty) continue;
			if(arrayReparaciones[i].idServicio == idsServicios){
				contadorServiciosPedidos++;
			}
		}
		*cantidadServiciosPedidos = contadorServiciosPedidos;
		retorno = 0;
	}
	return retorno;
}


int info_imprimirServicioMasPedido(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios){
	int retorno = -1;
	int listaServicios[longitudServicios];
	int indiceIdLibre = 0;
	int auxiliarContadorServicios;
	int cantidadMaximaDeServicios;
	int idServicioMasPedido;
	int auxiliarId;
	int i;
	int j;

	if(arrayReparaciones != NULL && longitudReparaciones > 0 && arrayServicios != NULL && longitudServicios > 0){

		for(i = 0; i < longitudServicios; i++){
			if(arrayReparaciones[i].isEmpty) continue;
			auxiliarId = serv_buscarId(arrayServicios, longitudServicios, arrayReparaciones[i].idServicio);
			for(j = 0; j < indiceIdLibre; j++){
				if(listaServicios[j] == auxiliarId){
					break;
				}
			}
			listaServicios[indiceIdLibre] = arrayReparaciones[i].idServicio;
			indiceIdLibre++;
		}
		for(j = 0; j < indiceIdLibre; j++){
			if(!info_calcularCantidadDeServicios(arrayReparaciones, longitudReparaciones, listaServicios[j], &auxiliarContadorServicios)){
				if(j == 0 || auxiliarContadorServicios > cantidadMaximaDeServicios){
					cantidadMaximaDeServicios = auxiliarContadorServicios;
					idServicioMasPedido = listaServicios[j];
				}
			}
		}
		if(serv_buscarId(arrayServicios, longitudServicios, idServicioMasPedido) >= 0){
			retorno = 0;
			serv_imprimir(&arrayServicios[serv_buscarId(arrayServicios, longitudServicios, idServicioMasPedido)]);
		}
	}
	return retorno;
}

int info_mostrarRecaudacionPorFecha(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios){
	int retorno = -1;
	int recaudacion;
	int auxiliarIndice;
	Fecha bufferEntidad;
	if(arrayReparaciones != NULL && longitudReparaciones > 0 && arrayServicios != NULL && longitudServicios > 0){
		if(!utn_getNumero(&bufferEntidad.dia, "\nIngrese dia:", "\nError, reingrese", 1, 31, 3) &&
			!utn_getNumero(&bufferEntidad.mes, "\nIngrese mes:", "\nError, reingrese", 1, 12, 3) &&
			!utn_getNumero(&bufferEntidad.anio, "\nIngrese anio:", "\nError, reingrese", 1900, 2020, 3)){
			auxiliarIndice = rep_buscarFecha(arrayReparaciones, longitudReparaciones, bufferEntidad);
			if(auxiliarIndice >= 0){
				recaudacion = info_calcularImporteDeReparaciones(arrayReparaciones, longitudReparaciones, arrayServicios, longitudServicios, arrayReparaciones[auxiliarIndice].serie);
				printf("\nLa recaudacion de %d/%d/%d fue %d", bufferEntidad.dia, bufferEntidad.mes,bufferEntidad.anio, recaudacion);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int info_mostrarElectrodomesticoGarantiaRealizada(Electrodomestico* arrayElectrodomesticos, int longitudElectrodomesticos,
												  Reparacion* arrayReparaciones, int longitudReparaciones,
												   Servicio* arrayServicios, int longitudServicios){
	int auxiliarIndice;
	int retorno = -1;
	if(arrayElectrodomesticos != NULL && longitudElectrodomesticos > 0 &&
		arrayReparaciones != NULL && longitudReparaciones > 0 &&
		arrayServicios != NULL && longitudServicios > 0){
		for(int i = 0; i < longitudReparaciones; i++){
			if(arrayReparaciones[i].isEmpty) continue;
			auxiliarIndice = elec_buscarSerie(arrayElectrodomesticos, longitudElectrodomesticos, arrayReparaciones[i].serie);
			if(auxiliarIndice >= 0){
				if(serv_buscarTipoPorId(arrayServicios, longitudServicios, arrayReparaciones[i].idServicio) >= 0){
					elec_imprimir(&arrayElectrodomesticos[auxiliarIndice]);
					printf("\nFecha: %d/%d/%d", arrayReparaciones[i].fecha.dia,  arrayReparaciones[i].fecha.mes,  arrayReparaciones[i].fecha.anio);
				}
			}
		}
	}
	return retorno;
}

int info_reparacionesAmodelo2018(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones){
	int retorno = -1;
	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			if(array[i].modelo == 2018 && !array[i].isEmpty){
				if(!info_mostrarReparacionesPorElectrodomestico(arrayReparaciones,longitudReparaciones, array[i].serie)){
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

