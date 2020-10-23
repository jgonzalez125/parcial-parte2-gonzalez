/*
 * electrodomesticos.h
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#ifndef ELECTRODOMESTICOS_H_
#define ELECTRODOMESTICOS_H_
#include "marca.h"
#include "reparacion.h"

typedef struct{
	int id;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;
}Electrodomestico;


/*
 * \brief Funcion para ordenar por doble criterio (modelo - serie)
 *
 * \param array puntero a la direccion de memoria de la entidad
 * \param longitud tamanio del array de Electrodomestico
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int elec_ordenarPorModeloSerie(Electrodomestico* array, int longitud);

/*
 * \brief Funcion para validar que la serie sea la correcta al momento de dar de baja
 *
 * \param array puntero a la direccion de memoria del array de Electrodomestico
 * \param longitud tamanio del array Electrodomestico
 * \param serie serie a ser buscada
 *
 * \return retorna el indice donde se encuentra la serie if OK, -1 if ERROR
 */
int elec_buscarSerie(Electrodomestico* array, int longitud, int serie);

/*
 * \brief Funcion para chequear el primer indice que se encuentre vacio
 *
 * \param array puntero a la direccion de memoria de la entidad
 * \param longitud tamanio del array de Electrodomestico
 *
 * \return retorna el indice vacio, -1 if ERROR
 */
int elec_getEmptyIndex(Electrodomestico* array, int longitud);

/*
 * \brief Funcion para inicializar un array Electrodomestico poniendo el campo isEmpty en TRUE (1)
 *
 * \param array puntero a la direccion de memoria del array Electrodomestico a ser inicializado
 * \param longitud tamanio del array de Electrodomestico
 *
 * \return retorna 0 if INIT OK, -1 if ERROR
 */
int elec_initArray(Electrodomestico* array, int longitud);


/*
 * \brief Funcion para encontrar una serie de electrodomestico por id
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Electrodomestico
 * \param idBuscado id del Electrodomestico a ser buscado
 *
 * \return retorna el indice donde se encuentra la serie, -1 if ERROR
 */
int elec_buscarSeriePorId(Electrodomestico* array, int limite, int idBuscado);

/*
 * \brief Funcion para encontrar un electrodomestico por id
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Electrodomestico
 * \param idBuscado id del Electrodomestico a ser buscado
 *
 * \return retorna el indice donde se encuentra el id, -1 if ERROR
 */
int elec_buscarId(Electrodomestico* array, int limite, int idBuscado);

/*
 * \brief Funcion para encontrar un electrodomestico por idMarca e imprimirlo
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Electrodomestico
 * \param idBuscado id del Electrodomestico a ser buscado
 *
 * \return retorna el indice donde se encuentra el idMarca, -1 if ERROR
 */
int elec_imprimirPorIdMarca(Electrodomestico* array, int longitud, int idBuscado);

/*
 * \brief Funcion para imprimir un array
 *
 * \param pProducto puntero a la direccion de memoria del array cliente a ser impreso
 * \param longitud longitud del array a ser impreso
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int elec_imprimirArray(Electrodomestico* array, int longitud);

/*
 * \brief Funcion para imprimir un electrodomestico
 *
 * \param pProducto puntero a la direccion de memoria del entidad a ser impreso
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int elec_imprimir(Electrodomestico* pElectrodomestico);

/*
 * \brief Funcion para cargar un array de entidades
 *
 * \param array puntero a la direccion de memoria del entidad a ser cargada
 * \param longitud tamanio del array de Electrodomestico
 * \param indice indice a ser cargado
 * \param idElectrodomestico puntero a la direccion de memoria del id a ser autoincrementado
 * \param idMarca numero del id de marca que se le asignara al electrodomestico
 *
 * \return retorna 0 if CARGA OK, -1 if ERROR
 */
int elec_cargarArray(Electrodomestico* array, int longitud, int indice, int* idElectrodomestico, int idMarca);


/*
 * \brief Funcion para dar de baja electrodomesticos y, si tiene asignadas, las reparaciones tambien
 *
 * \param array puntero a la direccion de memoria del entidad a ser cargada
 * \param longitud tamanio del array de Electrodomestico
 * \param arrayReparaciones puntero a la direccion de memoria del entidad a ser cargada
 * \param longitudReparaciones tamanio del array de Reparacion
 * \param indice indice a ser dado de baja
 *
 * \return retorna 0 if BAJA OK, -1 if ERROR
 */
int elec_bajaArray(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparacion, int indice);

/*
 * \brief Funcion para dar de baja electrodomesticos de una reparacion
 *
 * \param array puntero a la direccion de memoria del electrodomestico a ser dado de baja
 * \param longitud tamanio del array de Electrodomestico
 * \param auxiliarSerie numero de serie a ser validado
 *
 * \return retorna 0 if BAJA OK, -1 if ERROR
 */
int elec_bajaElectrodomesticosDeReparacion(Electrodomestico* array, int longitud, int auxiliarSerie);

/*
 * \brief Funcion para modificar electrodomesticos y, si tiene asignadas, las reparaciones tambien
 *
 * \param array puntero a la direccion de memoria del entidad a ser cargada
 * \param longitud tamanio del array de Electrodomestico
 * \param arrayReparaciones puntero a la direccion de memoria del entidad a ser cargada
 * \param longitudReparaciones tamanio del array de Reparacion
 * \param indice indice a ser dado de baja
 *
 * \return retorna 0 if BAJA OK, -1 if ERROR
 */
int elec_modificarArray(Electrodomestico* array, int longitud, Reparacion* arrayReparaciones, int longitudReparaciones, int indice);
#endif /* ELECTRODOMESTICOS_H_ */
