#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "general.h"

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0


/**
 * \brief Solicita un entero al usuario y devuelve el exito o el facaso.
 * \param *resultado es el entero obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el entero
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el entero.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */
int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,
		  int minimo,
		  int maximo,
		  int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(resultado !=NULL &&
	    mensaje !=NULL &&
		mensajeError != NULL &&
		minimo<maximo &&
		reintentos >= 0)
	{
		do
		{
		printf("%s",mensaje);
		__fpurge(stdin);//fflush(stdin); //en windows funciona __fflush para limpiar
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
			{
				retorno =EXIT_SUCCESS;
				*resultado=buffer; //caso de exito
				break; //de aca salgo del while y evito poner el else
			}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	}return retorno;
}


/**
 * \brief Solicita una cadena de caracteres al usuario y devuelve el exito o el facaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el string
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de carateres que puede tener el string
 * \param maximo es la cantidad maxima de carateres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el string.
 * \return devuelve el -1 en caso de no haber podido obtener el string, o el 0 en caso de exito.
 *
 */

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];
	if(resultado!=NULL &&
		mensaje !=NULL &&
		mensajeError !=NULL &&
		maximo>minimo &&
		reintentos>0)
	{
	do
	{
		printf("%s", mensaje);
		__fpurge(stdin); //fflush(stdin) EN WINDOWS . limpia el teclado
		fgets(buffer,sizeof(buffer),stdin); //toma lo del teclado de manera segura
		buffer[strlen(buffer)-1]='\0'; //en buffer se toma hasta lo anterior en \0
		if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
		{
			strncpy(resultado,buffer,maximo+1);
			retorno =EXIT_SUCCESS;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);
	}
	return retorno;
}


/**
 * \brief Solicita un dato char al usuario y devuelve el exito o el facaso.
 * \param *resultadoChar es el char obtenido
 * \param *mensajeChar es el mensaje a ser mostrado para solicitar el char
 * \param *mensajeErrorChar es el mensaje  de error
 * \param minimo es el char minimo que puede ingresar el usuario
 * \param maximo es el char maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el char.
 * \return devuelve el -1 en caso de no haber podido obtener el dato, o el 0 en caso de exito.
 *
 */
char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char bufferChar;
	if(resultadoChar != NULL &&
		mensajeChar != NULL &&
		mensajeErrorChar != NULL &&
		minimo<maximo &&
		reintentos >=0)
	{
		do
		{
			printf("%s",mensajeChar);
			__fpurge(stdin);//fflush(stdin);
			if(scanf("%c",&bufferChar)==1)
			{
				if(bufferChar >= minimo && bufferChar <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultadoChar = bufferChar;
					break;
				}
			}
			printf("%s", mensajeErrorChar);
			reintentos--;
		}while (reintentos >=0 );
	}
	return retorno;
}

/**
 * \brief Valida que una cadena de caracteres sea de letras, devolviendo el exito o fracaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el string
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de carateres que puede tener el string
 * \param maximo es la cantidad maxima de carateres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el string.
 * \return devuelve el -1 /EXIT_EROR) en caso de que no sean letras , o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int esLetra(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno =EXIT_ERROR;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);
	int cantidad;
	int contador=0;
	cantidad=strlen(buffer);
	while((buffer[i] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z'))
	{
		contador++;
		i++;
	}
	if(cantidad==contador && reintentos>=0)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = EXIT_SUCCESS;
	}
	else
	{
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita un string que sea solo letras al usuario y devuelve el exito o el facaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de caracteres que puede tener el string
 * \param maximo es la cantidad minima de caracteres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar la carga.
 * \return devuelve el -1 (EXIT_ERROR) en caso de error, o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int getDatoSoloLetras(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];
	reintentos++;
	do
		{
		getString(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		reintentos--;
		}while(esLetra(buffer,
				mensaje,
				mensajeError,
				minimo,
				maximo,
				reintentos)!=0 && reintentos>=0);

		 if(esLetra(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			 {
			 	 strncpy(resultado,buffer,maximo+1);
		       	  retorno = 0;}
	return retorno;
	}

/**
 * \brief Valida si el dato es alfanumerico y devuelve el exito o el facaso.
 * \param *resultado son las letras y/o numeros obtenidas
 * \param *mensaje es el mensaje a ser mostrado.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de letras y/o numeros minimos que puede ingresar el usuario
 * \param maximo es la cantidad de letras y/o numeros maximos que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser letras y/o numeros, o el 0 en caso de exito.
 *
 */
int esAlfaNumerico(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =-1;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
   	int cantidad;
   	int contador=0;
   	cantidad=strlen(buffer);
   	while((buffer[0] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z')||(buffer[i] >= '0' && buffer[i] <= '9'))
		  {
			contador++;
			i++;
		   }
if(cantidad==contador)
	{
	strncpy(resultado,buffer,maximo+1);
	retorno = 0;
	}
else
{
	printf("%s",mensajeError);
}
	return retorno;
}

/**
 * \brief Solicita un string que sea solo letras y/o numeros al usuario y devuelve el exito o el facaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de caracteres que puede tener el string
 * \param maximo es la cantidad minima de caracteres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar la carga.
 * \return devuelve el -1 (EXIT_ERROR) en caso de error, o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int getDatoAlfaNumerico(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];

	do{
		getString(buffer,

					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while (esAlfaNumerico(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0);


			if(esAlfaNumerico(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			{
		       	  strncpy(resultado,buffer,maximo+1);
		       	  retorno = 0;

			}
	return retorno;
	}


/**
 * \brief Valida si el dato es numerico y devuelve el exito o el facaso.
 * \param *resultado es el numero obtenido
 * \param *mensaje es el mensaje a ser mostrado
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de numeros minimos que puede ingresar el usuario
 * \param maximo es la cantidad de numeros maximos que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser un numero, o el 0 en caso de exito.
 *
 */

int isNumber(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =EXIT_ERROR;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
   	int cantidad;
   	int contador=0;
   	cantidad=strlen(buffer);
   	while(buffer[0] != '\0' && (buffer[i] >= '0' && buffer[i] <= '9'))
		  {
			contador++;
			i++;
		   }
  if(cantidad==contador)
	{
	strncpy(resultado,buffer,maximo+1);
	retorno = EXIT_SUCCESS;
	}
else
{
	printf("%s",mensajeError);
}
	return retorno;
}

int getSoloNumeros(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];

	do{
		getString(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while (isNumber(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0);


			if(isNumber(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			{
		       	  strncpy(resultado,buffer,maximo+1);
		       	  retorno = EXIT_SUCCESS;

			}
	return retorno;
	}


/**
 * \brief Solicita un flotante al usuario y devuelve el exito o el facaso.
 * \param *resultado es el flotante obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el flotante.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el flotante.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */

float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos)
{
	int retorno= EXIT_ERROR;
	float buffer;
	if(resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		maximo>minimo &&
		reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno =0; //EXIT_SUCCESS;
					*resultado=buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

///**
// * \brief Solicita un tipo al usuario y devuelve el exito o el facaso.
// * \param *resultado es el dato obtenido
// * \param *mensaje es el mensaje a ser mostrado
// * \param *mensajeError es el mensaje  de error
// * \param minimo es el valor minimo que puede ingresar el usuario
// * \param maximo es el valor maximo que puede ingresar el usuario
// * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el dato.
// * \return devuelve el -1 (EXIT_ERROR) en caso de fracaso o el 0 (EXIT_SUCCESS) en caso de exito.
// *
// */
//int getTipo(char *resultado,
//			char *mensaje,
//			char *mensajeError,
//			int minimo,
//			int maximo,
//			int reintentos)
//{
//	int retorno =EXIT_ERROR;
//	char buffer;
//	do
//	{	getChar(buffer,
//				mensaje,
//				mensajeError,
//				minimo,
//				maximo,
//				reintentos);
//
//		if(buffer=='a' || buffer=='b')
//		{
//   		*resultado=buffer;
//   		retorno = EXIT_SUCCESS;
//   		break;
//   		}
//		else
//		{
//			printf("%s",mensajeError);
//			reintentos--;
//		}
//	}while(reintentos>=0);
//   	return retorno;
//}



/**
 * \brief Solicita una confirmacion al usuario la cual puede ser si o no
 * \param *resultado es el dato obtenido
 * \param *mensaje es el mensaje a ser mostrado
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de caracteres que puede contener el string
 * \param maximo es la cantidad maxima de caracteres que puede contener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el dato.
 * \return devuelve el -1 (EXIT_ERROR) en caso de fracaso o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
	int esSiONo(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
	{
		int retorno =EXIT_ERROR;
		char buffer[4096];
		do
		{	getString(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);

			if(strncmp(buffer,"si",maximo+1)==0 || strncmp(buffer,"no",maximo+1)==0)
			{
	   		strncpy(resultado,buffer,maximo+1);
	   		retorno = EXIT_SUCCESS;
	   		break;
	   		}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	   	return retorno;
	}


	int imprimeArrayInt(ArrayEnteros *array,int limite )
	{
		int i;
		int retorno = EXIT_ERROR;
		if(array != NULL && limite > 0 )
		{
			retorno = EXIT_SUCCESS;
			for(i=0;i<limite;i++)
			{
				if(array[i].status==STATUS_NOT_EMPTY)
				{
					printf("%d\n",array[i].entero);
				}

			}
		}
		return retorno;
	}








//	int imprimirArrayEmpleadosCompleto(Employee*list, int len){
//		int i;
//		int retorno = EXIT_ERROR;
//		if(list != NULL && len>0)
//		{
//			retorno = 0;
//			for(i=0;i<len;i++)
//			{
//					printf("Estado : %d - Id: %d - Nombre: %s - Apellido: %s - SalarioDNI: %.2f - Sector: %d \n",list[i].isEmpty,list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
//
//			}
//		}
//		return retorno;
//	}
