/*
 * marca.h
 *
 *  Created on: Oct 14, 2020
 *      Author: juang
 */

#ifndef MARCA_H_
#define MARCA_H_
#define DESC_LEN 20
#define NOMBRE_LEN 25

typedef struct{
	int id; // comienza en 1000
	char nombre[NOMBRE_LEN];
	char descripcion[DESC_LEN];
	int isEmpty;
}Marca;



/*
 * \brief Funcion para hardcodear un array de MARCAS
 *
 * \param array puntero a la direccion de memoria del entidad a ser cargado
 * \param longitud tamanio del array de Instrumento
 * \param idMarcas puntero a la direccion de memoria del id a ser autoincrementado
 * \param indice indice a ser cargado
 * \param nombre puntero a la direccion de memoria de la cadena de caracteres a ser cargada
 * \param descripcion puntero a la direccion de memoria de la cadena de caracteres a ser cargada
 */
int mar_altaForzada(Marca* array, int longitud, int* idMarcas, int indice, char* nombre, char* descripcion);

/*
 * \brief Funcion para cargar un array de entidades
 * \param pProducto puntero a la direccion de memoria de la entidad a ser cargada
 * \param longitud tamanio del array de Marca
 * \param indice posicion del array a ser cargado
 * \param idMarca puntero a la direccion de memoria del id a ser autoincrementado
 */
int mar_cargarArray(Marca* array, int longitud, int indice, int* idMarca);

/*
 * \brief Funcion para imprimir una marca
 * \param pProducto puntero a la direccion de memoria de la entidad a ser impreso
 */
void mar_imprimir(Marca *array);

/*
 * \brief Funcion para imprimir un array
 * \param pProducto puntero a la direccion de memoria del array marca a ser impreso
 * \param longitud longitud del array a ser impreso
 */
int mar_imprimirArray(Marca* array, int longitud);


/*
 * \brief Funcion para eliminar un indice seteando el campo isEmpty en 1 (TRUE)
 * \param array puntero a la direccion de memoria del indice a ser eliminado
 * \param longitud tamanio del array de Marca
 * \param indice indice a ser buscado
 */
int mar_bajaArray(Marca* array, int longitud, int indice);

/*
 * \brief Funcion para encontrar una marca por id
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Marca
 * \param idBuscado id de la marca a ser buscado
 */
int mar_buscarId(Marca* array, int limite, int idBuscado);

/*
 * \brief Funcion para modificar un campo de marca
 * \param pProducto puntero a la direccion de memoria del cliente a ser modificado
 * \param longitud tamanio del array de Marca
 * \param indice indice a ser buscado
 */
int mar_modificarArray(Marca* array, int longitud, int indice);


/*
 * \brief Funcion para inicializar un array Marca poniendo el campo isEmpty en TRUE (1)
 * \param array puntero a la direccion de memoria del array marca a ser inicializado
 * \param longitud tamanio del array de Marca
 */
int mar_initArray(Marca* array, int longitud);

/*
 * \brief Funcion para chequear el primer indice que se encuentre vacio
 * \param array puntero a la direccion de memoria de entidad
 * \param longitud tamanio del array de Marca
 * \return retorna el indice vacio, -1 if ERROR
 */
int mar_getEmptyIndex(Marca* array, int longitud);


#endif /* MARCA_H_ */
