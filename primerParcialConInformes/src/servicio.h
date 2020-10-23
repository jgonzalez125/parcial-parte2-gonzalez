/*
 * servicio.h
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#define DESCRIPCION_LEN 25


typedef struct{
	int id; // comienza en 20000
	char descripcion[DESCRIPCION_LEN];
	float precio;
	int isEmpty;
}Servicio;


/*
 * \brief Funcion para hardcodear un array de SERVICIOS
 *
 * \param array puntero a la direccion de memoria del entidad a ser cargado
 * \param longitud tamanio del array de Instrumento
 * \param idServicios puntero a la direccion de memoria del id a ser autoincrementado
 * \param indice indice a ser cargado
 * \param descripcion puntero a la direccion de memoria de la cadena de caracteres a ser cargada
 * \param precio numero correspondiente al precio a ser cargado
 */
int serv_altaForzada(Servicio* array, int longitud, int* idServicios, int indice, char* descripcion, int precio);

/*
 * \brief Funcion para imprimir un array
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Servicio
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int serv_imprimirArray(Servicio *array, int longitud);

int serv_getEmptyIndex(Servicio *array, int longitud);
/*
 * \brief Funcion para encontrar un Servicio por id
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Servicio
 * \param idBuscado id del Servicio a ser buscado
 *
 * \return retorna el indice if ID encontrado, -1 if ERROR
 */
int serv_buscarId(Servicio* array, int limite, int idBuscado);

/*
 * \brief Funcion para inicializar un array Servicio poniendo el campo isEmpty en TRUE (1)
 *
 * \param array puntero a la direccion de memoria del array marca a ser inicializado
 * \param longitud tamanio del array de Servicio
 *
 * \return retorna 0 if INIT OK, -1 if ERROR
 */
int serv_initArray(Servicio* array, int longitud);

// Funciones no usadas
int serv_cargarArray(Servicio* array, int longitud, int indice, int* idServicio);
int serv_imprimir(Servicio *array);
int serv_buscarTipoPorId(Servicio* array, int limite, int idBuscado);


#endif /* SERVICIO_H_ */
