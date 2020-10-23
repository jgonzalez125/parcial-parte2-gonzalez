/*
 * reparacion.h
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#ifndef REPARACION_H_
#define REPARACION_H_
#include "servicio.h"

typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	int id;
	int serie;
	int idServicio;
	int isEmpty;
	Fecha fecha;
}Reparacion;


/*
 * \brief Funcion para buscar una serie de electrodomestico asignada a la reparacion
 *
 * \param pProducto puntero a la lugar de memoria del array entidad a ser impreso
 * \param longitud longitud del array a ser impreso
 *
 * return retorna el indice de la posicion donde se encuentra esa serie if OK, -1 if ERROR
 */
int rep_buscarSerie(Reparacion* array, int longitud, int serie);


/*
 * \brief Funcion para imprimir la entidad por numero de serie
 *
 * \param array puntero a la lugar de memoria del array entidad a ser impreso
 * \param longitud longitud del array a ser impreso
 * \param serie numero de serie a ser buscado
 *
 * return retorna el indice de la posicion donde se encuentra esa serie if OK, -1 if ERROR
 */
int rep_imprimirPorSerie(Reparacion* array, int longitud, int serie);

/*
 * \brief Funcion para inicializar un array Reparacion poniendo el campo isEmpty en TRUE (1)
 *
 * \param array puntero a la lugar de memoria del entidad a ser inicializado
 * \param longitud tamanio del array de Reparacion
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int rep_initArray(Reparacion* array, int longitud);

/*
 * \brief Funcion para chequear el primer indice que se encuentre vacio
 *
 * \param array puntero a la lugar de memoria del entidad
 * \param longitud tamanio del array de Reparacion
 *
 * \return retorna el indice vacio, -1 if ERROR
 */
int rep_getEmptyIndex(Reparacion* array, int longitud);


/*
 * \brief Funcion para cargar un array de entidades
 * \param pProducto puntero a la lugar de memoria del entidad a ser cargado
 * \param longitud tamanio del array de Reparacion
 * \param indice indice a ser cargado
 * \param serie serie que corresponde al electrodomestico a ser reparado
 * \param idServicio id del servicio a ser asignado a la reparacion
 * \param id puntero a la lugar de memoria del id a ser autoincrementado
 */
int rep_cargarArray(Reparacion* array, int longitud, int indice, int serie, int idServicio, int* id);

/*
 * \brief Funcion para imprimir un valor
 * \param pProducto puntero a la lugar de memoria del entidad a ser inicializado
 */
int rep_imprimir(Reparacion* array);

/*
 * \brief Funcion para imprimir un array
 * \param pProducto puntero a la lugar de memoria del array entidad a ser impreso
 * \param longitud longitud del array a ser impreso
 */
int rep_imprimirArray(Reparacion* array, int longitud);


/*
 * \brief Funcion para eliminar un indice seteando el campo isEmpty en 1 (TRUE)
 * \param array puntero a la lugar de memoria del indice a ser eliminado
 */
int rep_bajaArray(Reparacion* array, int longitud, int serie);
/*
 * \brief Funcion para encontrar un entidad por id
 * \param array puntero a la lugar de memoria del array
 * \param longitud tamanio del array de Reparacion
 * \param idBuscado id del entidad a ser buscado
 */
int rep_buscarId(Reparacion* array, int limite, int idBuscado);

int rep_buscarFecha(Reparacion* array, int longitud, Fecha fecha);

/*
 * \brief Funcion para modificar un campo del entidad
 * \param pProducto puntero a la lugar de memoria del entidad a ser modificado
 * \param longitud tamanio del array de Reparacion
 * \param indice indice a ser buscado
 */
//int rep_modificarArray(Reparacion* array, Electrodomestico* arrayElectrodomesticos, Servicio* arrayServicio, int longitudServ, int longitudElec, int longitud, int indice);
#endif /* REPARACION_H_ */
