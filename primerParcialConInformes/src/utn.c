#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un
 * 		  maximo de 'n - 1' caracteres (n siendo la longitud del string).
 * \param cadena: Puntero al espaciode memoria donde se copia el string obtenido
 * \param longitud: Define el tamanio de la cadena
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int myGets(char* cadena, int longitud);

/**
 * \brief Obtiene el string de caracteres
 * \param cadena puntero a la direccion de memoria a ser almacenado el string obtenido
 * \param longitud tamanio de la cadena de caracteres a ser obtenida
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getString(char* cadena, int longitud);

/**
 * \brief Lee la cadena para chequear que los caracteres sean alfabeticos
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica
 * \param longitud tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esNombre(char* cadena, int longitud);

/**
 * \brief Lee la cadena para chequear que el caracter no sea mayor a '9' y menor a '0'
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esNumerica(char cadena[]);

/**
 * \brief Obtiene el numero int
 * \param pResultado puntero a la direccion de memoria a ser almacenado el numero obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getInt(int* pResultado);

/**
 * \brief Lee la cadena para chequear que el caracter no sea mayor a '9' y menor a '0' y que contenga un solo '.'
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica decimal
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esNumericaFloat(char cadena[]);

/**
 * \brief Obtiene el numero flotante
 * \param pResultado puntero a la direccion de memoria a ser almacenado el numero flotante obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getFloat(float* pResultado);

/**
 * \brief Obtiene el email
 * \param pResultado puntero a la direccion de memoria a ser almacenado el email obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getEmail(char* pResultado, int longitud);

/**
 * \brief Lee la cadena para chequear que el string sea valido como email
 * \param cadena: cadena de caracteres a confirmar si es una cadena alfanumerica
 * \param longiud: tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esEmail(char* cadena, int longitud);


/**
 * \brief Obtiene el DNI
 * \param pResultado puntero a la direccion de memoria a ser almacenado el DNI obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getDni(char* pResultado, int longitud);

/**
 * \brief Lee la cadena para chequear que el string sea valido como DNI
 * \param cadena: cadena de caracteres a confirmar si es una cadena numerica con 2 puntos
 * \param longiud: tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esDni(char* cadena, int longitud);

/**
 * \brief Lee la cadena para chequear que el string sea valido como CUIL
 * \param cadena: cadena de caracteres a confirmar si es una cadena numerica con 2 guiones
 * \param longiud: tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esCuil(char* cadena, int longitud);

/**
 * \brief Obtiene el CUIL
 * \param pResultado puntero a la direccion de memoria a ser almacenado el CUIL obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getCuil(char* pResultado, int longitud);

/**
 * \brief Lee la cadena para chequear que el string sea valido como Descripcion
 * \param cadena: cadena de caracteres a confirmar si es una cadena numerica con 2 guiones
 * \param longiud: tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esDescripcion(char* cadena, int longitud);

/**
 * \brief Obtiene la descripcion
 * \param pResultado puntero a la direccion de memoria a ser almacenado la descripcion
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getDescripcion(char* pResultado, int longitud);

static int myGets(char* cadena, int longitud){
	int retorno = -1;
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena){
		fpurge(stdin);
		if(cadena[strlen(cadena) - 1] == '\n'){
			cadena[strlen(cadena) -1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

static int getString(char* cadena, int longitud){
	int retorno = -1;
	char bufferString[4096];
	if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
		if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
			bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
		}
		if(strnlen(bufferString, sizeof(bufferString)) <= longitud){
			strncpy(cadena, bufferString, longitud);
			retorno=0;
		}
	}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getNumero() =============== */

static int getInt(int* pResultado){
	char buffer[64];
	int retorno = -1;
	myGets(buffer, sizeof(buffer));

	if(esNumerica(buffer)){
		*pResultado = atoi(buffer);
		retorno = 1;
	}
	return retorno;
}

static int esNumerica(char cadena[]){
	int i;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		for(i = 0;cadena[i] != '\0'; i++){
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos > 0){
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 1){
				if(bufferInt <= maximo && bufferInt >= minimo){
					break;
				}
				fflush(stdin);
				printf("%s", mensajeError);
			}
			reintentos--;
		}
		if(reintentos == 0){
			retorno = -1;
		}else{
			retorno = 0;
			*pResultado = bufferInt;
		}
	}
	return retorno;
}


/* =============== FUNCIONES NECESARIAS PARA utn_getNumeroFlotante() =============== */

static int getFloat(float* pResultado){
	char buffer[128];
	int retorno = -1;
	myGets(buffer, sizeof(buffer));

	if(esNumericaFloat(buffer) == 0){
		*pResultado = atof(buffer);
		retorno = 1;
	}
	return retorno;
}

static int esNumericaFloat(char cadena[]){
	int retorno = -1;
	int i;
	int contadorPuntos = 0;

	for(i = 0; cadena[i] != '\0'; i++){
		if(cadena[i] < '0' || cadena[i] > '9'){
			if(cadena[i] == '.'){
				contadorPuntos++;
				// si es mas de un punto, devuelvo error
				if(contadorPuntos > 1){
					retorno = 0;
					break;
				}
			}
		}else{
			// no se ingreso nada que sea un numero
			if(i == 0){
				if(cadena[i] != '+' && cadena[i] != '-'){
					retorno = 0;
					break;
				}
			}else{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos > 0){
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 1){
				if(bufferFloat <= maximo && bufferFloat >= minimo){
					break;
				}
				fflush(stdin);
				printf("%s", mensajeError);
			}
			reintentos--;
		}
		if(reintentos == 0){
			retorno = -1;
		}else{
			retorno = 0;
			*pResultado = bufferFloat;
		}
	}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getCaracter() =============== */

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		printf("\n%s", mensaje);
		for(int i = 0; i < reintentos; i++){
			scanf("%c", &bufferChar);
			fflush(stdin);

			if(i == reintentos - 1 && (bufferChar > maximo || bufferChar < minimo)){
				printf("\nSe quedo sin intentos");

			}else if(bufferChar > maximo || bufferChar < minimo){
				printf("\n%s", mensajeError);
				printf("\n%s", mensaje);
			}else{
				*pResultado = bufferChar;
				retorno = 0;
				break;

			}
		}
	}
	return retorno;
}


/* =============== FUNCIONES NECESARIAS PARA utn_getNombre() =============== */

static int esNombre(char* cadena, int longitud){
	int retorno = -1;
	int i = 0;

	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getNombre(char* pResultado, int longitud){
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL){
		if(getString(buffer, sizeof(buffer)) == 0 && esNombre(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud && buffer[0] != '\0'){
			for(int i = 0; i < longitud; i++){
				strncpy(pResultado, buffer, longitud);
				retorno = 0;
			}

		}
	}
	return retorno;
}

int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;

		while(reintentos > 0){
			printf("%s", mensaje);

			if(getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud){
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}else{
				printf("\n%s", mensajeError);
				fflush(stdin);
				reintentos--;
			}
		}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getCuil() =============== */

static int esCuil(char* cadena, int longitud){
	int retorno = 1;
	int i = 0;
	int contadorGuiones = 0;

	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++){
			if(cadena[i] == 45){
				contadorGuiones++;
			}
			/**
			 * Condiciones para que sea falso:
			 * Si la cadena no arranca con un 2
			 * No es un caracter numerico
			 * Tiene mas de 2 guiones
			 * Si los primeros dos caracteres no forman un 20, 23, 24 o 27
			 * Si en el tercer y anteultimo caracter no hay un guion
			 */
			if((cadena[i] < 45 || cadena[i] > 57 || contadorGuiones > 2) || cadena[2] != 45 || cadena[i] == 46 ||
				(i == 1 && (cadena[i] == 53 || cadena[i] == 54 || cadena[i] == 50 || cadena[i] == 49)) ||
				cadena[i] == 47 || cadena[0] != 50 || cadena[11] != 45){
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}


static int getCuil(char* pResultado, int longitud){
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL){
		if(getString(buffer, sizeof(buffer)) == 0 && esCuil(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}


int utn_getCuil(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;

		while(reintentos > 0){
			printf("%s", mensaje);

			if(getCuil(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud && strnlen(bufferString, sizeof(bufferString)) == 13){
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("\n%s", mensajeError);
				fflush(stdin);
			}
		}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getEmail() =============== */

static int esEmail(char* cadena, int longitud){
	int retorno = 1;
	int i = 0;
	int contadorArrobas = 0;
	int contadorPuntos = 0;

	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++){
			if(cadena[i] == 64) contadorArrobas++;
			if(cadena[i] == 46) contadorPuntos++;

			if(((cadena[i] < 64 || cadena[i] > 90) && (cadena[i] < 97 || cadena[i] > 122) && (cadena[i] < 46 || cadena[i] > 57)) ||
				cadena[i] == 47 || contadorArrobas > 1 ||
				contadorPuntos > 1){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getEmail(char* pResultado, int longitud){
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && longitud > 0){
		if(getString(buffer, sizeof(buffer)) == 0 && esEmail(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getEmail(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;

	if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && reintentos >0){
		while(reintentos > 0){
			printf("%s", mensaje);

			if(getEmail(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud && strnlen(bufferString, sizeof(bufferString)) > 10){
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("\n%s", mensajeError);
				fflush(stdin);
			}
		}
	}
	return retorno;
}


/* =============== FUNCIONES NECESARIAS PARA utn_getDni() =============== */

static int esDni(char* cadena, int longitud){
	int retorno = 1;
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++){
			if(cadena[i] == 46){
				contadorPuntos++;
			}
			/**
			 * Condiciones para que sea falso:
			 * Si la cadena arranca en un punto
			 * No es un caracter numerico
			 * Tiene mas de 2 puntos
			 * Una vez ingresado el punto, 4 caracteres mas adelante tiene que ser un punto otra vez
			 */
			if((cadena[i] < 46 || cadena[i] > 57 || cadena[i] == 47 || contadorPuntos > 2) ||
			   (cadena[i] == 46 && cadena[i+4] > 46) || cadena[0] == 46 ||
			   (cadena[i] == 46 && cadena[i+3] == '\0')){
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

static int getDni(char* pResultado, int longitud){
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL){
		if(getString(buffer, sizeof(buffer)) == 0 && esDni(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getDni(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;

		while(reintentos > 0){
			printf("%s", mensaje);

			if(getDni(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud &&
			  ((strnlen(bufferString, sizeof(bufferString)) == 10 && bufferString[0] < 53) || strnlen(bufferString, sizeof(bufferString)) == 9)){
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("\n%s", mensajeError);
				fflush(stdin);
			}
		}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getDescripcion() =============== */

static int esDescripcion(char* cadena, int longitud){
	int retorno = -1;
	int i = 0;

	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++){
			if(cadena[i] != ' ' && cadena[i] == '\n' && cadena[i] != '.' && cadena[i] != ',' && (cadena[i] < 'A' || cadena[i] > 'Z') &&
		      (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getDescripcion(char* pResultado, int longitud){
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL){
		if(getString(buffer, sizeof(buffer)) == 0 && esDescripcion(buffer, sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud && buffer[0] != '\0'){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;

		while(reintentos > 0){
			printf("%s", mensaje);
			fflush(stdin);

			if((getDescripcion(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)){
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}else{
				printf("\n%s", mensajeError);
				reintentos--;
			}
		}
	return retorno;
}


/* =============== FUNCIONES DE ARRAYS =============== */


int initArrayInt(int* array, int longitud, int valorInicial){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		retorno = 0;
		for(int i = 0; i < longitud; i++){
			array[i] = valorInicial;
		}
	}
	return retorno;
}

int imprimirArrayInt(int* array, int longitud){
	int retorno = -1;
	if(longitud > 0 && array != NULL){
		for(int i = 0; i < longitud; i++){
			setbuf(stdout, NULL);
			retorno = 0;
			printf("\n%d) %d", i+1, array[i]);
		}
	}
	return retorno;
}

int initArrayFloat(float* array, int longitud, float valorInicial){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		retorno = 0;
		for(int i = 0; i < longitud; i++){
			array[i] = valorInicial;
		}
	}
	return retorno;
}

int imprimirArrayFloat(float* array, int longitud){
	int retorno = -1;

	if(longitud > 0 && array != NULL){
		for(int i = 0; i < longitud; i++){
			setbuf(stdout, NULL);
			retorno = 0;
			printf("\n%d) %.2f", i+1, array[i]);
		}
	}
	return retorno;
}

int cargarArrayInt(int* array, int longitud, int minimo, int maximo){
	int retorno = -1;
	int bufferIndice;
	int bufferValor;

	if(longitud > 0 && array != NULL && minimo <= maximo){
		retorno = 0;
		if(!utn_getNumero(&bufferIndice, "\nIngrese indice a modificar:", "\nError, indice invalido", 1, longitud, 3) &&
			!utn_getNumero(&bufferValor, "\nIngrese valor", "\nError, reingrese", minimo, maximo, 3)){
			array[bufferIndice - 1] = bufferValor;
		}
	}
	return retorno;
}

int ordenarArrayIntMenorAmayor(int* array, int len){
	int retorno = -1;
	int aux;
	if(array != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i < len-1; i++){
			for(int j = i+1; j < len; j++){
				if(array[i] > array[j]){
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;
				}
			}
		}
	}
	return retorno;

}

int ordenarArrayIntMayorAmenor(int* array, int len){
	int retorno = -1;
	int aux;
	if(array != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i < len-1; i++){
			for(int j = i+1; j < len; j++){
				if(array[i] < array[j]){
					aux = array[j];
					array[j] = array[i];
					array[i] = aux;
				}
			}
		}
	}
	return retorno;
}
