/*
 * informes.h
 *
 *  Created on: Oct 22, 2020
 *      Author: juang
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/**
 * \brief Funcion que imprime electrodomesticos cuyo modelo sea 2020
 *
 * \param array puntero a la direccion de memoria del array de la entidad
 * \param longitud tamanio del array
 * \return retorna 0 if OK, -1 if ERROR
 */
int info_electrodomesticosModelo2020(Electrodomestico* array, int longitud);

/**
 * \brief Funcion que imprime electrodomesticos que sean de una marca seleccionada por ID
 *
 * \param array puntero a la direccion de memoria del array de la entidad
 * \param longitud tamanio del array
 * \param idMarca id de marca seleccionada a buscar
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int info_mostrarElectrodomesticosPorMarca(Electrodomestico* array, int longitud, int idMarca);

/**
 * \brief Funcion que imprime reparaciones asignadas a un electrodomestico con numero de serie
 * 		  ingresado por el usuario
 *
 * \param array puntero a la direccion de memoria del array de la entidad
 * \param longitud tamanio del array
 * \param serie numero de serie a ser buscada
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int info_mostrarReparacionesPorElectrodomestico(Reparacion* array, int longitud, int serie);

/**
 * \brief Funcion que imprime electrodomesticos que no tuvieron reparaciones
 *
 * \param array puntero a la direccion de memoria del array de la entidad
 * \param longitud tamanio del array
 * \param arrayReparaciones puntero a la direccion de memoria del array de la entidad
 * \param longitudReparaciones tamanio del array
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int info_mostrarElectrodomesticosSinReparaciones(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones);

/**
 * \brief Funcion que calcula el importe total de las reparaciones a un electrodomestico
 * 		  ingresado por el usuario
 *
 * \param arrayReparaciones puntero a la direccion de memoria del array de la entidad
 * \param longitudReparaciones tamanio del array
 * \param arrayServicios puntero a la direccion de memoria del array de la entidad
 * \param longitudServicios tamanio del array
 * \param serie numero de serie a ser buscada
 *
 * \return retorna > 0 if OK, 0 if ERROR
 */
int info_calcularImporteDeReparaciones(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios, int serie);

/**
 * \brief Funcion que imprime el servicio mas solicitado
 *
 * \param arrayReparaciones puntero a la direccion de memoria del array de la entidad
 * \param longitudReparaciones tamanio del array
 * \param arrayServicios puntero a la direccion de memoria del array de la entidad
 * \param longitudServicios tamanio del array
 * \param serie numero de serie a ser buscada
 *
 * \return retorna > 0 if OK, 0 if ERROR
 */
int info_imprimirServicioMasPedido(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios);

/**
 * \brief Funcion que imprime la cantidad de dinero recaudado en una fecha ingresada por
 * 	      el usuario
 *
 * \param arrayReparaciones puntero a la direccion de memoria del array de la entidad
 * \param longitudReparaciones tamanio del array
 * \param arrayServicios puntero a la direccion de memoria del array de la entidad
 * \param longitudServicios tamanio del array
 * \param serie numero de serie a ser buscada
 *
 * \return retorna > 0 if OK, 0 if ERROR
 */
int info_mostrarRecaudacionPorFecha(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios);

/**
 * \brief Funcion que imprime electrodomesticos que realizan garantia y la fecha en la que se va a realizar
 *
 * \param arrayReparaciones puntero a la direccion de memoria del array de la entidad
 * \param longitudReparaciones tamanio del array
 * \param arrayServicios puntero a la direccion de memoria del array de la entidad
 * \param longitudServicios tamanio del array
 * \param serie numero de serie a ser buscada
 *
 * \return retorna > 0 if OK, 0 if ERROR
 */
int info_mostrarElectrodomesticoGarantiaRealizada(Electrodomestico* arrayElectrodomesticos, int longitudElectrodomesticos,
												  Reparacion* arrayReparaciones, int longitudReparaciones,
												   Servicio* arrayServicios, int longitudServicios);

int info_reparacionesAmodelo2018(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones);

int info_calcularImporteTotal(Reparacion* arrayReparaciones, int longitudReparaciones, Servicio* arrayServicios, int longitudServicios);

#endif /* INFORMES_H_ */
