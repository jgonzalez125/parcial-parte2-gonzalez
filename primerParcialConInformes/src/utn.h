/*
 * utn.h
 *
 *  Created on: Jul 5, 2020
 *      Author: juang
 */

#ifndef UTN_H_
#define UTN_H_

/*
===========================================================================================================================
                                          ACLARACION DE DOCUMENTACION:
TODAS las funciones que comienzan con "utn_" Y obtienen un tipo de dato nativo (char, int, float),
contienen los siguientes parametros obligatoriamente:

 * \param (int || char || float)* pResultado, puntero a direccion de memoria del numero || caracter
 * \param char* mensaje, puntero a direccion de memoria a ser alojado el mensaje de ingreso
 * \param char* mensajeError, puntero a direccion de memoria a ser alojado el mensaje de error en caso de haberse
 * \param (int || char) minimo, numero || caracter minimo que podria ingresarse
 * \param (int || char) maximo, numero || caracter maximo que podria ingresarse
 * \param int reintentos, cantidad de oportunidades
 *
 * retorna 0 if OK, -1 if ERROR

Por el otro lado, TODAS las funciones que comienzan con "utn_" y obtienen un tipo de dato no nativo (STRING, CUIL, EMAIL, DNI),
contienen los siguientes parametros obligatoriamente:

 * \param char* pResultado, puntero a direccion de memoria del string
 * \param int longitud, integer del tamanio del string
 * \param char* mensaje, puntero a direccion de memoria a ser alojado el mensaje de ingreso
 * \param char* mensajeError, puntero a direccion de memoria a ser alojado el mensaje de error en caso de haberse
 * \param int reintentos, cantidad de oportunidades
 *
 * retorna 0 if OK, -1 if ERROR
============================================================================================================================
 */

/**
 * \brief Funcion para conseguir un numero int
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Funcion para conseguir un caracter
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/**
 * \brief Funcion para conseguir un numero float
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief Funcion para conseguir un nombre
 */
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief Funcion para conseguir un string de caracteres con espacios/puntuacion
 */
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
/**
 * \brief Funcion para conseguir un DNI
 */
int utn_getDni(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief Funcion para conseguir un email
 */
int utn_getEmail(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief Funcion para conseguir un cuil
 */
int utn_getCuil(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);


/* ======================= FUNCIONES DE ARRAYS =======================  */

/**
 * \brief Funcion para imprimir un array de int
 * \param int* array puntero a la direccion de memoria de un array de int
 * \param len tamaño del array
 *
 * retorna 0 if OK -1 if ERROR
 */
int imprimirArrayInt(int* array, int longitud);



/**
 * \brief Funcion para inicializar un array de int
 * \param int* array puntero a la direccion de memoria de un array de int
 * \param longitud tamaño del array
 *	\param valorInicial el valor con el cual se van a cargar todos los valores del array
 * retorna 0 if OK -1 if ERROR
 */
int initArrayInt(int* array, int longitud, int valorInicial);


/**
 * \brief Funcion para cargar un array de int
 * \param int* array puntero a la direccion de memoria de un array de int
 * \param longitud tamaño del array
 *	\param minimo el valor con el cual se pueda cargar el array
 *	\param maximo el valor maximo con el cual se pueda cargar el array
 * retorna 0 if OK -1 if ERROR
 */
int cargarArrayInt(int* array, int longitud, int minimo, int maximo);


/**
 * \brief Funcion para imprimir un array de int de menor a mayor (bubble sort)
 * \param int* array puntero a la direccion de memoria de un array de int
 * \param len tamaño del array
 *
 * retorna 0 if OK -1 if ERROR
 */
int ordenarArrayIntMenorAmayor(int* array, int longitud);

/**
 * \brief Funcion para imprimir un array de int de mayor a menor (bubble sort)
 * \param int* array puntero a la direccion de memoria de un array de int
 * \param len tamaño del array
 *
 * retorna 0 if OK -1 if ERROR
 */
int ordenarArrayIntMayorAmenor(int* array, int longitud);
/**
 * \brief Funcion para inicializar un array de float
 * \param int* array puntero a la direccion de memoria de un array de float
 * \param len tamaño del array
 *	\param valorInicial el valor con el cual se van a cargar todos los valores del array
 * retorna 0 if OK -1 if ERROR
 */
int initArrayFloat(float* array, int longitud, float valorInicial);

/**
 * \brief Funcion para imprimir un array de float
 * \param int* array puntero a la direccion de memoria de un array de float
 * \param len tamaño del array
 *
 * retorna 0 if OK -1 if ERROR
 */
int imprimirArrayFloat(float* array, int longitud);

#endif /* UTN_H_ */
