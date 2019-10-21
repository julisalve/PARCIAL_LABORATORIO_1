#include "Pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


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
 * \brief Inicializa todas las posiciones del array con el estado "vacio" y los KIlos en cero.
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int initLugarLibrePedidos(Pedidos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			aArray[i].status=STATUS_EMPTY;
			aArray[i].kilosTotales=SIN_CANTIDAD_KILOS;
			aArray[i].kilosHdpe_1=SIN_CANTIDAD_KILOS;
			aArray[i].kilosLdpe_2=SIN_CANTIDAD_KILOS;
			aArray[i].kilosPp_3=SIN_CANTIDAD_KILOS;
			aArray[i].kilosDesecho_4=SIN_CANTIDAD_KILOS;
		}
	}
	return retorno;
}




/**
 * \brief Imprime un array de string en estado Not Empty, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPedidosNotEmpty(Pedidos *aArray, int cantidad)
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
				printf("Id: %d - IDCliente: %d - Kilos %.2f\n",aArray[i].id,aArray[i].idCliente,aArray[i].kilosTotales);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime un array de string con estado distinto a Empty, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPedidosDistintoEmpty(Pedidos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status!=STATUS_EMPTY)
			{
				printf("Id: %d - IDCliente: %d - Kilos %.2f\n",aArray[i].id,aArray[i].idCliente,aArray[i].kilosTotales);
			}
		}
	}
	return retorno;
}



/**
 * \brief Imprime un array de string con estado Pendiente, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPedidosPendientes(Pedidos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_PENDIENTE)
			{
				printf("Id: %d - IDCliente: %d - Kilos %.2f\n",aArray[i].id,aArray[i].idCliente,aArray[i].kilosTotales);
			}
		}
	}
	return retorno;
}



/**\brief Da de baja a un id poniendo su estado como EMPTY en dos estructuras vinculadas
 *
 * \param *aArray array de una esructura
 * \param cantidad tamaño de la estructura anterior
 * \param *aArrayPed array de otra estructura
 * \param cantPed tamaño de la estructura anterior
 * \param id es el id que se pretende dar de baja y poner el estado vacio.
 * \return  devuelve el -1 (EXIT_ERROR) en caso de que alguno de los array sea nulo o que su tamaño sea invalido o que el id ingresado no exista o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */

int bajaClientePorId(Clientes *aArray, int cantidad,Pedidos *aArrayPed, int cantPed, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	int posicionCliente= buscarClientePorId(aArray, cantidad,id);
	if(aArray != NULL && cantidad > 0 && posicionCliente >=0 && aArrayPed !=NULL && cantPed >0)
	{
		aArray[posicionCliente].status= STATUS_EMPTY;
		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].idCliente==id)
			{
				aArrayPed[i].idCliente=STATUS_EMPTY;
			}
		}
		retorno=EXIT_SUCCESS;
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

int buscarLugarPedido(Pedidos *aArray, int cantidad)
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
 * \brief Carga datos en un array, cambiandole el estado a Pendiente y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaPedido(Pedidos *aArrayPed, int cantidad, Pedidos buffer)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarPedido(aArrayPed,cantidad);

	if(aArrayPed != NULL && cantidad > 0 && i!=EXIT_ERROR)
	{
		aArrayPed[i]=buffer;
		aArrayPed[i].id = generarId();
		aArrayPed[i].status = STATUS_PENDIENTE;
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
int buscarPedidoPorId(Pedidos *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status== STATUS_PENDIENTE && id==aArray[i].id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int initLugarLibreContador(auxContador *aArray, int cantidad)
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
 * \brief Calcula cantidad de pedidos pendientes por cliente e imprime esta informacion
 * \param *aArray array de pedidos
 * \param cantidad tamaño del array pedido
 * \param *aArrayCont array de contador
 * \param cantCont tamaño del array contador
 * \param *aArrayClientes array de clientes
 * \param cantClientes tamaño del array clientes
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array de clientes o pedidos sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int cantidadPedidosPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;
	initLugarLibreContador(aArrayCont,cantCont);
	if(aArray != NULL && cantidad>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantCont;i++)
		{
			aArrayCont[i].idCliente=aArray[i].idCliente;
			aArrayCont[i].contador =0;
		}
		for(i=0;i<cantCont;i++)
		{
			for(j=0;j<cantidad;j++)
			{
				if(aArray[j].status == STATUS_PENDIENTE && aArrayCont[i].idCliente==aArray[j].idCliente)
				{
					aArrayCont[i].contador++;
					aArrayCont[i].status=STATUS_PENDIENTE;
					//					aArrayCont[i].acmulador=aArrayCont[i].acmulador+aArray[j].precioFinal;
				}
			}
		}
		imprimirCantidadPedidosPendientesPorCuit(aArrayCont,cantCont,aArrayClientes,cantClientes);
	}
	return retorno;
}

/**
 * \brief Imprime cantidad de pedidos pendientes por cliente
 * \param *aArrayCont array de contador
 * \param cantCont tamaño del array contador
 * \param *aArrayClientes array de clientes
 * \param cantClientes tamaño del array clientes
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array de clientes o contador sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int imprimirCantidadPedidosPendientesPorCuit(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	if(aArrayCont != NULL && cantCont>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantCont;i++)
		{
			for(j=0;j<cantClientes;j++)
				if(aArrayCont[i].status==STATUS_PENDIENTE && aArrayCont[i].idCliente!=aArrayCont[i+1].idCliente && aArrayCont[i].idCliente==aArrayClientes[j].id)
				{
					printf("Cuit %s - ID Cliente %d - NOmbre %s - Direccion %s - Localidad %s tiene %d pedidos pendientes\n",aArrayClientes[j].cuit,aArrayClientes[j].id,aArrayClientes[j].nombre,aArrayClientes[j].direccion,aArrayClientes[j].localidad,aArrayCont[i].contador);
				}
		}
	}
	return retorno;
}

/**
 * \brief Imprime pedidos pendientes con datos de clientes
 * \param *aArrayPed array de pedidos
 * \param cantPed tamaño del array pedidos
 * \param *aArrayClientes array de clientes
 * \param cantClientes tamaño del array clientes
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array de clientes o pedidos sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int imprimirArrayPedidosPendientesConClientes(Pedidos *aArrayPed,int cantPed,Clientes *aArrayClientes,int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	if(aArrayPed != NULL && cantPed>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantPed;i++)
		{
			for(j=0;j<cantClientes;j++)
				if(aArrayPed[i].status==STATUS_PENDIENTE && aArrayPed[i].idCliente==aArrayClientes[j].id)
				{
					printf("Cuit %s - Direccion %s - CAntidad Kilos a recolectar %.2f \n",aArrayClientes[j].cuit,aArrayClientes[j].direccion,aArrayPed[i].kilosTotales);
				}
		}
	}
	return retorno;
}




/**\brief Modifica el estado de un pedido en particular a "Completo" y permite la carga de los kilos de cada tipo de residuo dentro de ese mismo pedido
 *
 * \param *aArray array de pedidos
 * \param cantidad tamaño del aray de pedidos
 * \param index posicion del array
 * \return int DEvuelve(EXIT_ERROR -1) en caso de de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int modificacionPedidoPorId(Pedidos *aArray, int cantidad, int index, Pedidos buffer)
{
	int retorno =EXIT_ERROR;
	if(aArray != NULL && cantidad>0 )
	{
		retorno=EXIT_SUCCESS;
		aArray[index].kilosTotales=buffer.kilosTotales;
		aArray[index].kilosHdpe_1=buffer.kilosHdpe_1;
		aArray[index].kilosLdpe_2=buffer.kilosLdpe_2;
		aArray[index].kilosPp_3=buffer.kilosPp_3;
		aArray[index].kilosDesecho_4=buffer.kilosDesecho_4;
		aArray[index].status=STATUS_COMPLETO;
	}
	return retorno;
}

/**\brief Ordena de mayor a menor el id de los clientes
 *
 * \param *aArray array de pedidos
 * \param cantidad tamaño del aray de pedidos
 * \return int DEvuelve(EXIT_ERROR -1) en caso de de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int ordenarPorIdCliente (Pedidos *aArray, int cantidad)
{
	int retorno =EXIT_ERROR;
	int i;
	Pedidos bPedidos;
	int j;
	if(aArray != NULL && cantidad > 0)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			j=i;
			while (aArray[j].idCliente>aArray[j-1].idCliente && j>0) //ordena de mayor a menor
			{
				bPedidos=aArray[j-1];
				aArray[j-1]=aArray[j];
				aArray[j]=bPedidos;
				j--;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime pedidos completos con datos de clientes
 * \param *aArrayPed array de pedidos
 * \param cantPed tamaño del array pedidos
 * \param *aArrayClientes array de clientes
 * \param cantClientes tamaño del array clientes
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array de clientes o pedidos sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int imprimirArrayPedidosCompletosConClientes(Pedidos *aArrayPed,int cantPed,Clientes *aArrayClientes,int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	if(aArrayPed != NULL && cantPed>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantPed;i++)
		{
			for(j=0;j<cantClientes;j++)
				if(aArrayPed[i].status==STATUS_COMPLETO && aArrayPed[i].idCliente==aArrayClientes[j].id)
				{
					printf("Cuit %s - Direccion %s - Cantidad Kilos HDPE a recolectar %.2f - Cantidad Kilos LDPE a recolectar %.2f - Cantidad Kilos PP a recolectar %.2f\n",aArrayClientes[j].cuit,aArrayClientes[j].direccion,aArrayPed[i].kilosHdpe_1,aArrayPed[i].kilosLdpe_2,aArrayPed[i].kilosPp_3);
				}
		}
	}
	return retorno;
}

/**
 * \brief Carga Forzada de pedidos
 * \param *aArray array de pedidos
 * \param cantidad tamaño del array pedidos
 * \return void
 *
 */
void altaForzadaPedidos(Pedidos *aArray,int cantidad)
{
	float kilosHdpe_1[]={200,210,0,0,500,100,0,10,0};
	float kilosLdpe_2[]={145,45,0,0,150,50,0,5,0};
	float kilosPp_3[]={230,30,0,0,270,70,0,3,0};
	float kilosDesecho_4[]={425,515,0,0,580,530,0,12,0};
	float kilosTotales[]={1000,800,100,300,1500,750,200,30,456};
	int id[]={1,2,3,4,5,6,7,8,9};
	int status[]={1,1,2,2,1,1,2,1,2};
	int idCliente[]={1,1,2,2,3,4,1,5,6};
	int i;
	for(i=0;i<9;i++)
	{
		aArray[i].kilosTotales=kilosTotales[i];
		aArray[i].kilosHdpe_1=kilosHdpe_1[i];
		aArray[i].kilosLdpe_2=kilosLdpe_2[i];
		aArray[i].kilosPp_3=kilosPp_3[i];
		aArray[i].kilosDesecho_4=kilosDesecho_4[i];
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		aArray[i].idCliente=idCliente[i];
	}
}


