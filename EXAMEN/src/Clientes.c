#include "Clientes.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "general.h"


/**
 * \brief Genera ID irrepetiblre
 *
 * \return devuelve el numero de ID
 *
 */
static int generarId()
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}

/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int initLugarLibreClientes(Clientes *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].status=STATUS_EMPTY;
	}
		}
		return retorno;
}



/**
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayClientes(Clientes *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY)
			{
				printf("Id: %d - Status %d - Nombre: %s - Direccion: %s - Cuit: %s\n",aArray[i].id,aArray[i].status,aArray[i].nombre,aArray[i].direccion,aArray[i].cuit);
			}

		}
	}
	return retorno;
}


/**
 * \brief BUsca el primer lugar libre y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la posicion del array con espacio libre, para ser utilizado
 *
 */
int buscarLugarCliente(Clientes *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaClientePorId(Clientes *aArray, int cantidad,Clientes buffer, int *id)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarCliente(aArray,cantidad);

		if(aArray != NULL && cantidad > 0 && i!=EXIT_ERROR)
		{
			aArray[i]=buffer;
			aArray[i].id = generarId();
			*id=aArray[i].id;
			aArray[i].status = STATUS_NOT_EMPTY;
			retorno = EXIT_SUCCESS;
		}
	return retorno;

}


/**
 * \brief Busca la posicion de un id ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param id
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
 *
 */
int buscarClientePorId(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].id)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}


/**\brief Imprime datos de un id en particular
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param id es el id solicitado
 * \return int DEvuelve(EXIT_ERROR -1) en caso de que el array sea nulo o sea invalido el tamaño o devuelve la posicion del id en caso de exito
 *
 */
int imprimirDatosClientePorId(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i =buscarClientePorId(aArray,cantidad, id);
	if(aArray != NULL && cantidad > 0)
	{
		if(i>=0)
		{
			retorno = i;
			printf("Id: %d - Status %d - Nombre: %s - Direccion: %s - Cuit: %s\n",aArray[i].id,aArray[i].status,aArray[i].nombre,aArray[i].direccion,aArray[i].cuit);
		}
	}
	return retorno;
}


/**\brief Modifica el dato que se desee de los campos de la estructura del srray
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param index posicion del array
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
 *
 */
int modificacionClientePorIdCamposPuntuales(Clientes *aArray, int cantidad, int index)
{
	int retorno =EXIT_ERROR;
	char datoAModificar;
	Clientes bCliente;
		if(getChar(&datoAModificar,"Seleccione dato a modificar: a)direccion, b)localidad\n","NO es un dato valido\n",'a','z',2)!=0)
		{
			printf("ERROR");
		}
		else
		{
			switch(datoAModificar)
			{
			case 'a':

							if(getDatoAlfaNumerico(bCliente.direccion,"Ingrese direccion \n","NO es una direccion valida \n",2,16,2)!=0)
							{
								printf ("Error\n");
								break;
							}
							else
							{
								strncpy(aArray[index].direccion,bCliente.direccion,50);
								retorno =EXIT_SUCCESS;
							}

							break;
			case 'b':

				if(getDatoSoloLetras(bCliente.localidad,"Ingrese la localidad\n","NO es una localidad valida \n",2,16,2)!=0)
				{
					printf("ERROR \n");
					break;
				}
				else
				{
					strncpy(aArray[index].localidad,bCliente.localidad,50);
					retorno =EXIT_SUCCESS;
				}
				break;

			default:
				printf("Error, opcion invalida \n");
				break;
			}
		}
			return retorno;
		}

int ordenarCuit (Clientes *aArray, int cantidad)
{
	int retorno =EXIT_ERROR;
	int i;
	Clientes bCliente;
	int j;
	 if(aArray != NULL && cantidad > 0)
	 {
		 retorno=EXIT_SUCCESS;

	for(i=0;i<cantidad;i++)
	{
		j=i;
		while (strncmp(aArray[j].cuit,aArray[j-1].cuit,50)<0 && j>0) //ordena de menor a mayor
		{
							bCliente=aArray[j-1];
							aArray[j-1]=aArray[j];
							aArray[j]=bCliente;
							j--;
		}
	}

	 }

	return retorno;
}















