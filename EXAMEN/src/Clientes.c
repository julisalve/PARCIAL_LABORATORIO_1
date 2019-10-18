#include "Clientes.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "general.h"

static int generarId();

/**
 * \brief Genera ID irrepetible
 *
 * \return devuelve el numero de ID
 *
 */
static int generarId()
{
	static int contadorId=0;
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
 * \brief Imprime el array de clientes con estado lleno, devolviendo el fracaso o el exito
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
 * \brief Busca el primer lugar libre y devuelve el fracaso o la posicion
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
 * \param id id que se desea buscar
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


/**\brief Imprime datos de un id cliente en particular
 *
 * \param *aArray
 * \param cantidad
 * \param id es el id solicitado
 * \return int DEvuelve(EXIT_ERROR -1) en caso de que el array sea nulo o sea invalido el tamaño o no exista el id solicitado o devuelve la posicion del id en caso de exito
 *
 */
int imprimirDatosClientePorId(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i =buscarClientePorId(aArray,cantidad, id);
	if(aArray != NULL && cantidad > 0 && i>=0)
	{
		retorno = i;
		printf("Id: %d - Nombre: %s - Direccion: %s - Cuit: %s\n",aArray[i].id,aArray[i].nombre,aArray[i].direccion,aArray[i].cuit);
	}
	return retorno;
}


/**\brief Modifica el dato que se desee de los campos de la estructura del array
 *
 * \param *aArray array clientes
 * \param cantidad tamaño del array cleintes
 * \param index posicion en el array
 * \return int Devuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
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

/**\brief Ordena de menor a mayor los cuit del array de clientes
 *
 * \param *aArray array clientes
 * \param cantidad tamaño del array cleintes
 * \return int Devuelve(EXIT_ERROR -1) en caso de que el array sea nulo o su tamaño sea invalido o EXIT SUCCESS (0) en caso de exito
 *
 */
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

/**
 * \brief Carga Forzada de clientes
 * \param *aArray array de clientes
 * \param cantidad tamaño del array clientes
 * \return void
 *
 */
void altaForzadaClientes(Clientes *aArray,int cantidad)
{
	int id[]={1,2,3,4,5,6};
	int status[]={1,1,1,1,1,1};
	char nombre[][50]={" Telefonica","Datasoft","Nestle","Terrabusi","Dia","Quilmes"};
	char direccion[][50]={"Lima 1234","Corientes 2547","Cucha Cucha 555","Rocha 784","Mitre 750","Rocha 741"};
	char cuit[][50]={"30112233445","30445566776","30889955219","30567814235","31545812533","30514857596"};
	char localidad[][50]={"Caba","Caba","Lanus","Quilmes","Avellaneda","Quilmes"};
	int i;
	for(i=0;i<6;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		strncpy(aArray[i].nombre,nombre[i],50);
		strncpy(aArray[i].direccion,direccion[i],50);
		strncpy(aArray[i].cuit,cuit[i],50);
		strncpy(aArray[i].localidad,localidad[i],50);
	}
}
