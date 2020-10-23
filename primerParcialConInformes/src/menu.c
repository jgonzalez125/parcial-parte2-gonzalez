/*
 * menu.c
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "electrodomesticos.h"
#include "marca.h"
#include "reparacion.h"
#include "servicio.h"
#include "informes.h"

#define CANTIDAD_ELECTRODOMESTICOS 100
#define CANTIDAD_MARCAS 5
#define CANTIDAD_SERVICIOS 4
#define CANTIDAD_REPARACIONES 100

#define ID_SERVICIOS_MINIMO 20000
#define ID_SERVICIOS_MAXIMO 20003

#define ID_MARCAS_MINIMO 1000
#define ID_MARCAS_MAXIMO 1004

#define NUMERO_SERIE_MINIMO 1
#define NUMERO_SERIE_MAXIMO 10000




void menu() {
	setbuf(stdout, NULL);

	//Arrays de entidades
	Electrodomestico arrayElectrodomesticos[CANTIDAD_ELECTRODOMESTICOS];
	Reparacion arrayReparaciones[CANTIDAD_REPARACIONES];
	Servicio arrayServicios[CANTIDAD_SERVICIOS];
	Marca arrayMarcas[CANTIDAD_MARCAS];

	char opcion;
	int opcionInformes;

	//Flags para cargar reparacion
	int electrodomesticosCargados = 0;
	int cargoReparacion = 0;

	//Ids autoincrementables
	int idElectrodomesticos = 0;
	int idServicios = 20000;
	int idMarcas = 1000;
	int idReparacion = 0;

	//Variables auxiliares
	int auxiliarImporte;
	int auxiliarSerie;
	int auxiliarIdMarca;
	int auxiliarId;
	int auxiliarIndice;



	if (!elec_initArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS)
				&& !rep_initArray(arrayReparaciones, CANTIDAD_REPARACIONES)) {
			printf("\nArray init ok");

			// Marcas hardcodeadas
			mar_altaForzada(arrayMarcas, CANTIDAD_MARCAS, &idMarcas, 0, "Wirpool", "Lavarropas");
			mar_altaForzada(arrayMarcas, CANTIDAD_MARCAS, &idMarcas, 1, "Sony", "Ultima tecnologia");
			mar_altaForzada(arrayMarcas, CANTIDAD_MARCAS, &idMarcas, 2, "Liliana", "Lo mejor para vos");
			mar_altaForzada(arrayMarcas, CANTIDAD_MARCAS, &idMarcas, 3, "Gafa", "Compra ideal");
			mar_altaForzada(arrayMarcas, CANTIDAD_MARCAS, &idMarcas, 4, "Philips", "Siempre junto a vos");

			// Servicios hardcodeados
			serv_altaForzada(arrayServicios, CANTIDAD_SERVICIOS, &idServicios, 0, "Garantia", 250);
			serv_altaForzada(arrayServicios, CANTIDAD_SERVICIOS, &idServicios, 1, "Mantenimiento", 500);
			serv_altaForzada(arrayServicios, CANTIDAD_SERVICIOS, &idServicios, 2, "Repuestos", 400);
			serv_altaForzada(arrayServicios, CANTIDAD_SERVICIOS, &idServicios, 3, "Refaccion", 600);

		do {
			fpurge(stdin);
			if (!utn_getCaracter(&opcion,"\nA)ALTA ELECTRODOMESTICO"
										"\nB)MODIFICAR ELECTRODOMESTICO: Se ingresará el id, "
										"permitiendo en un submenú modificar: \n  1-Serie\n  2-Modelo"
										"\nC)BAJA ELECTRODOMESTICO"
										"\nD)LISTAR ELECTRODOMESTICOS"
										"\nE)LISTAR MARCAS"
										"\nF)LISTAR SERVICIOS"
										"\nG)ALTA REPARACION"
										"\nH)LISTAR REPARACIONES"
										"\nI)INFORMES (sub menu):"
										"\nJ)SALIR", "\nError", 'A', 'I', 3)) {
				switch (opcion) {
				case 'A':
					auxiliarIndice = elec_getEmptyIndex(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
					mar_imprimirArray(arrayMarcas, CANTIDAD_MARCAS);

					if(auxiliarIndice >= 0 &&
					  !utn_getNumero(&auxiliarIdMarca, "\nIngrese id de marca del electrodomestico:", "\nError, reingrese", ID_MARCAS_MINIMO, ID_MARCAS_MAXIMO, 3) &&
					   mar_buscarId(arrayMarcas, CANTIDAD_MARCAS,auxiliarIdMarca) >= 0) {

						if(!elec_cargarArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarIndice, &idElectrodomesticos, auxiliarIdMarca)){
							printf("\nElectrodomestico cargado exitosamente");
							elec_imprimir(&arrayElectrodomesticos[auxiliarIndice]);
							electrodomesticosCargados++;
						}else{
							printf("\nNo se pudo realizar el alta");
						}

					}else{
						printf("\nEl id de marca no es valido");
					}
					break;
				case 'B':
					if(!electrodomesticosCargados){
						printf("\nDebe cargar un electrodomestico para poder modificar");
					}else{
						elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);

						if(!utn_getNumero(&auxiliarId, "\nIngrese id a modificar: ", "\nError, reingrese", 0, CANTIDAD_ELECTRODOMESTICOS, 3)){
							auxiliarIndice = elec_buscarId(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarId);
							if(auxiliarIndice >= 0 &&
							   !elec_modificarArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, arrayReparaciones, CANTIDAD_REPARACIONES, auxiliarIndice)){
								printf("\n\nModificacion realizada exitosamente");
							}else{
								printf("\nEl id %d no es valido", auxiliarId);
							}
						}
					}
					break;
				case 'C':
					if(!electrodomesticosCargados){
							printf("\nDebe cargar un electrodomestico para poder dar de baja");
						}else{
							elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
							if(!utn_getNumero(&auxiliarId, "\nIngrese id a dar de baja: ", "\nError, reingrese", 0, CANTIDAD_ELECTRODOMESTICOS, 3)){
								auxiliarIndice = elec_buscarId(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarId);
								if(auxiliarIndice >= 0 &&
									!elec_bajaArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, arrayReparaciones, CANTIDAD_REPARACIONES, auxiliarIndice)){
									printf("\n\nBaja realizada exitosamente");
									electrodomesticosCargados--;
								}else{
									printf("\nEl id %d no es valido", auxiliarId);
								}
							}
						}
					break;
				case 'D':
					if(!electrodomesticosCargados){
						printf("\nDebe cargar un electrodomestico para poder imprimir");
					}else{
						printf("\nElectrodomesticos ordenados por modelo y serie: (menor a mayor)");
						elec_ordenarPorModeloSerie(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
						elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
					}
					break;
				case 'E':
					printf("\n=========== MARCAS ===========");
					mar_imprimirArray(arrayMarcas, CANTIDAD_MARCAS);
					break;
				case 'F':
					printf("\n=================== SERVICIOS ====================");
					serv_imprimirArray(arrayServicios, CANTIDAD_SERVICIOS);
					break;
				case 'G':
					if(!electrodomesticosCargados){
						printf("\nNo hay electrodomesticos cargados");
					}else{
						auxiliarIndice = rep_getEmptyIndex(arrayReparaciones, CANTIDAD_REPARACIONES);
						if(auxiliarIndice >= 0){
							elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
							if(!utn_getNumero(&auxiliarSerie, "\nIngrese numero de serie de electrodomestico a ser reparado:", "\nError, reingrese",
								1, 10000, 3) &&
									elec_buscarSerie(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarSerie) >= 0){

								printf("\n=================== SERVICIOS ====================");
								serv_imprimirArray(arrayServicios, CANTIDAD_SERVICIOS);
								if(!utn_getNumero(&auxiliarId, "\nIngrese id de servicio a ser realizado:", "\nError, reingrese", ID_SERVICIOS_MINIMO, ID_SERVICIOS_MAXIMO, 3)){
									if(!rep_cargarArray(arrayReparaciones, CANTIDAD_REPARACIONES, auxiliarIndice, auxiliarSerie, auxiliarId, &idReparacion)){
										printf("\nAlta realizada exitosamente");
										cargoReparacion = 1;
									}else{
										//fallo rep_cargarArray()
										printf("\nNo se puedo realizar el alta");
									}
								}else{
									// fallo el input de id de servicio
									printf("\nId de servicio no es valida");
								}
							}else{
								// elec_buscarSerie() == -1
								printf("\nNumero de serie de electrodomestico no es valido");
							}
						}else{
							// rep_getEmptyIndex() == -1
							printf("\nNo hay mas espacios vacios");
						}
					}
					break;
				case 'H':
					if(!cargoReparacion){
						printf("\nDebe cargar una reparacion previo a imprimir");
					}else{
						rep_imprimirArray(arrayReparaciones, CANTIDAD_REPARACIONES);
					}
					break;
				case 'I':
					if(!electrodomesticosCargados){
						printf("\nDebe ingresar un electrodomestico previo a mostrar informes");
					}else{
						if(!utn_getNumero(&opcionInformes, "\n1-Mostrar Electrodomésticos del año(nodelo) 2020"
														   "\n2-Mostrar Electrodomésticos de una marca seleccionada"
														   "\n3-Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado"
														   "\n4-Listar los Electrodomésticos que no tuvieron reparaciones"
														   "\n5-Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado"
														   "\n6-Mostrar el servicio más pedido"
														   "\n7-Mostrar la recaudación en una fecha en particular"
														   "\n8-Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha"
														   "\n9-Trabajos realizados a Electrodomésticos del año(modelo) 2018"
														   "\n10-Facturación total por los mantenimientos"
														   "\n11-Informar la marca de Electrodomésticos que efectuaron más refacciones"
														   "\n12-Listar los Electrodomésticos que recibieron reparación en un fecha determinada", "\nError, opcion invalida", 1, 12, 3)){
							switch(opcionInformes){
							case 1:
								if(!info_electrodomesticosModelo2020(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS)){
									printf("\nElectrodomesticos modelo 2020");
								}else{
									printf("\nNo hay electrodomesticos cargados de modelo 2020");
								}
								break;
							case 2:
								printf("\n=========== MARCAS ===========");
								mar_imprimirArray(arrayMarcas, CANTIDAD_MARCAS);
								if(!utn_getNumero(&auxiliarId, "\nIngrese id de marca: ", "\nError, reingrese", ID_MARCAS_MINIMO, ID_MARCAS_MAXIMO, 3)){
									auxiliarIndice = mar_buscarId(arrayMarcas, CANTIDAD_MARCAS, auxiliarId);
									if(auxiliarIndice >= 0){
										if(!info_mostrarElectrodomesticosPorMarca(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarId)){
											printf("\nElectrodomesticos de la marca %s", arrayMarcas[auxiliarIndice].nombre);
										}else{
											printf("\nNo hay electrodomesticos cargados de esa marca");
										}
									}else{
										printf("\nNo se pudo encontrar esa marca");
									}
								}
								break;
							case 3:
									printf("\n=========== ELECTRODOMESTICOS ===========");
									elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
									if(!utn_getNumero(&auxiliarSerie, "\nIngrese numero de serie de electrodomestico: ", "\nError, reingrese", NUMERO_SERIE_MINIMO, NUMERO_SERIE_MAXIMO, 3)){
										auxiliarIndice = elec_buscarSerie(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarSerie);
										if(auxiliarIndice >= 0){
											if(!info_mostrarReparacionesPorElectrodomestico(arrayReparaciones, CANTIDAD_REPARACIONES, auxiliarSerie)){
												printf("\nReparaciones efectuadas para el electrodomestico con numero de serie: %d", arrayElectrodomesticos[auxiliarIndice].serie);
											}else{
												printf("\nNo hay reparaciones para el electrodomestico con ese numero de serie");
											}
										}else{
											printf("\nNo se pudo encontrar ese numero de serie");
										}
									}
									break;
							case 4:
								if(!info_mostrarElectrodomesticosSinReparaciones(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, arrayReparaciones, CANTIDAD_REPARACIONES)){
									printf("\nElectrodomesticos sin reparaciones");
								}else{
									printf("\nNo hay electrodomesticos sin reparaciones asignadas");
								}
								break;
							case 5:
								printf("\n=========== ELECTRODOMESTICOS ===========");
								elec_imprimirArray(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS);
								if(!utn_getNumero(&auxiliarSerie, "\nIngrese numero de serie de electrodomestico: ", "\nError, reingrese", NUMERO_SERIE_MINIMO, NUMERO_SERIE_MAXIMO, 3)){
									auxiliarIndice = elec_buscarSerie(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, auxiliarSerie);
									if(auxiliarIndice >= 0){
										auxiliarImporte = info_calcularImporteDeReparaciones(arrayReparaciones, CANTIDAD_REPARACIONES, arrayServicios, CANTIDAD_SERVICIOS, auxiliarSerie);
										if(auxiliarImporte > 0){
											printf("\nEl importe total del electrodomestico con numero de serie: %d es: %d", auxiliarSerie, auxiliarImporte);
										}else{
											printf("\nEse electrodomestico no tiene reparaciones asignadas");
										}
									}else{
										printf("\nNo se pudo encontrar el numero de serie");
									}
								}
								break;
							case 6:
								if(!info_imprimirServicioMasPedido(arrayReparaciones, CANTIDAD_REPARACIONES, arrayServicios, CANTIDAD_SERVICIOS)){
									printf("\nServicio mas pedido");
								}
								break;
							case 7:
								info_mostrarRecaudacionPorFecha(arrayReparaciones, CANTIDAD_REPARACIONES, arrayServicios, CANTIDAD_SERVICIOS);
								break;
							case 8:
								printf("\n ======Electrodomesticos a realizar una garantia======");
								info_mostrarElectrodomesticoGarantiaRealizada(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS,
																				arrayReparaciones, CANTIDAD_REPARACIONES,
																				arrayServicios, CANTIDAD_SERVICIOS);
								break;
							case 9:
								if(!info_reparacionesAmodelo2018(arrayElectrodomesticos, CANTIDAD_ELECTRODOMESTICOS, arrayReparaciones, CANTIDAD_REPARACIONES)){
									printf("\nReparaciones a electrodomesticos modelo 2018");
								}else{
									printf("\nNo hay modelo 2018");
								}
								break;
							case 10:
								if(cargoReparacion){
									printf("\nEl importe total es:");
									info_calcularImporteTotal(arrayReparaciones, CANTIDAD_REPARACIONES, arrayServicios, CANTIDAD_SERVICIOS);
								}else{
									printf("\nNo cargo reparaciones");
								}
							}
						}
					}
					break;
				default:
					printf("\nSaliendo...");
					break;
				}
			} else {
				break;
			}
		} while (opcion != 'J');

	}
}
