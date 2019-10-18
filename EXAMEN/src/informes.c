#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "informes.h"





int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, auxContador *aArrayCont, int cantCont)
{
	int retorno= EXIT_ERROR;
	int opcion;
	int id;
	float acumulador;

	while(getInt(&opcion, "Ingrese una opcion de informes\n  1)Cliente con mas pedidos pendientes.\n  2)Cliente con mas pedidos completos.\n  3)Cliente con mas pedidos.\n  4)Cliente que reciclo mas kilos.\n    5)Cliente que reciclo menos kilos.\n ","NO es una opcion valida.",1,10,3)!=0)
			{
				printf("ERROR.\n ");
			}

	switch (opcion)
	{
//	retorno = EXIT_SUCCESS;
	case 1:
		 obtenerId(aArrayClientes,cantClientes, aArrayPed, cantPed);
		 break;

	case 2:
		obtenerIdCompletos(aArrayClientes,cantClientes, aArrayPed, cantPed);
		break;
	case 3:
obtenerIdMasPedidos(aArrayClientes,cantClientes,aArrayPed, cantPed);
		break;
	case 4: //cliente que reciclo mas kilos
obtenerIdClienteQueRecicloMAsKilos(aArrayClientes, cantClientes, aArrayPed, cantPed);
		break;
	case 5:
obtenerIdClienteQueRecicloMenosKilos(aArrayClientes, cantClientes, aArrayPed, cantPed);
		break;
	}
	return retorno;
}








//cliente con mas pedidos pendientes

int obtenerId(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int cantidadPedidos;
	int maximoPed=0;
	int maximoId=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			cantidadPedidos=cantPedidosPendientes(aArrayPed, cantPed, &id,aArrayClientes, cantClientes);
			maximoPedidos(cantidadPedidos, &maximoPed, &id, &maximoId);
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, maximoId, aArrayPed, cantPed);

	return retorno;
}

int cantPedidosPendientes(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int contador=0;

	if(aArrayPed != NULL && cantPed > 0 )
	{

		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].idCliente ==*id && aArrayPed[i].status==STATUS_PENDIENTE)
			{
				contador++;
			}
		}

		retorno=contador;
	}
	return retorno;
}

int maximoPedidos(int cantidadPedidos, int *maximoPed, int *id, int *maximoId)
{
	int retorno =EXIT_ERROR;

	if(cantidadPedidos>*maximoPed)
	{
		*maximoPed=cantidadPedidos;
		*maximoId=*id;
		retorno=EXIT_SUCCESS;

	}

	return retorno;
}

int buscarClientePorIdInformes(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(id==aArray[i].id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int imprimirDatosCLientePorId (Clientes *aArray, int cantClientes, int id, Pedidos *aArrayPed, int cantPed)
{
	int retorno=EXIT_ERROR;
	int index;
	if(aArray != NULL && cantClientes > 0 )
	{
		index=buscarClientePorIdInformes(aArray,cantClientes,id);

		printf("NOMBRE %s - CUIT %s \n",aArray[index].nombre,aArray[index].cuit);
	}
	return retorno;
}


//cliente con mas pedidos completados

int obtenerIdCompletos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int cantidadPedidos;
	int maximoPed=0;
	int maximoId=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			cantidadPedidos=cantPedidosCompletados(aArrayPed, cantPed, &id,aArrayClientes, cantClientes);
			maximoPedidos(cantidadPedidos, &maximoPed, &id, &maximoId);
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, maximoId, aArrayPed, cantPed);

	return retorno;
}

int cantPedidosCompletados(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int contador=0;

	if(aArrayPed != NULL && cantPed > 0 )
	{

		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].idCliente ==*id && aArrayPed[i].status==STATUS_COMPLETO)
			{
				contador++;
			}
		}

		retorno=contador;
	}
	return retorno;
}


//cliente con mas pedidos

int obtenerIdMasPedidos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int cantidadPedidos;
	int maximoPed=0;
	int maximoId=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			cantidadPedidos=cantPedidosGenerales(aArrayPed, cantPed, &id,aArrayClientes, cantClientes);
			maximoPedidos(cantidadPedidos, &maximoPed, &id, &maximoId);
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, maximoId, aArrayPed, cantPed);

	return retorno;
}

int cantPedidosGenerales(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int contador=0;

	if(aArrayPed != NULL && cantPed > 0 )
	{

		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].idCliente ==*id && aArrayPed[i].status==STATUS_COMPLETO || aArrayPed[i].status==STATUS_PENDIENTE)
			{
				contador++;
			}
		}

		retorno=contador;
	}
	return retorno;
}

//cliente que recibio mas kilos

int obtenerIdClienteQueRecicloMAsKilos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int acumulador=0;
	int maximoPed=0;
	int maximoId=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			acumulador=sumaTotalesDeReciclajePorId(aArrayPed, cantPed, &id);
			maximoPedidos(acumulador, &maximoPed, &id, &maximoId);
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, maximoId, aArrayPed, cantPed);

	return retorno;
}

int sumaTotalesDeReciclajePorId(Pedidos *aArrayPed, int cantPed, int *id)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	int acumulador;

	acumulador=0;
	if(aArrayPed != NULL && cantPed > 0)
	{

		for(i=0;i<cantPed;i++)
		{
			if((aArrayPed[i].status==STATUS_COMPLETO || aArrayPed[i].status==STATUS_PENDIENTE) &&aArrayPed[i].idCliente==*id)
			{

					acumulador=acumulador+aArrayPed[i].kilosHdpe_1+aArrayPed[i].kilosLdpe_2+aArrayPed[i].kilosPp_3;


			}

		}

		retorno=acumulador;
	}

	return retorno;
}




// cliente que reciclo menos kilos

int obtenerIdClienteQueRecicloMenosKilos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int acumulador=0;
	int minimoPed=0;
	int minimoId=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			acumulador=sumaTotalesDeReciclajePorId(aArrayPed, cantPed, &id);
			minimosPedidos(acumulador, &minimoPed, &id, &minimoId);
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, minimoId, aArrayPed, cantPed);

	return retorno;
}

int minimosPedidos(int cantidadPedidos, int *minimoPed, int *id, int *minimoId)
{
	int retorno =EXIT_ERROR;

	if(cantidadPedidos<*minimoPed)
	{
		*minimoPed=cantidadPedidos;
		*minimoId=*id;
		retorno=EXIT_SUCCESS;

	}

	return retorno;
}






























/**
 * \brief BUsca el primer lugar de pedido completo/procesado y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la primer posicion del array procesado/completo, para ser utilizado
 *
 */

int buscarPrimerLugarPedidoPendiente(auxContador *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int cantidadPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;
	initLugarLibreContador(aArrayCont,cantCont);
	if(aArray != NULL && cantidad>0 && aArrayClientes!=NULL && cantClientes>0 && aArrayCont!=NULL && cantCont>0)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantCont;i++)
		{
			aArrayCont[i].idCliente=aArrayClientes[i].id;
			aArrayCont[i].contador=0;
		}
		for(i=0;i<cantCont;i++)
		{
			for(j=0;j<cantidad;j++)
			{
				if(aArray[j].status == STATUS_PENDIENTE && aArrayCont[i].idCliente==aArray[j].idCliente)
				{

					aArrayCont[i].contador++;
					aArrayCont[i].statusPedido=aArray[j].status;
				}
			}
		}
		imprimirClienteConCantidadMaximaPedidos(aArrayCont,cantCont,aArrayClientes,cantClientes, aArray, cantidad);
	}
	return retorno;
}

int imprimirClienteConCantidadMaximaPedidos(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{
	int retorno =EXIT_ERROR;
	int i;
	int index;
	int maximaCanPedidosPendientes;
	int maximoIdCliente;
	int primerPosicionOcupada= buscarPrimerLugarPedidoPendiente(aArrayCont,cantCont);
	printf("%d",primerPosicionOcupada);

	if(aArrayCont != NULL && cantCont > 0 && aArrayClientes != NULL && cantClientes > 0)
	{
		retorno=EXIT_SUCCESS;
		maximaCanPedidosPendientes=aArrayCont[primerPosicionOcupada].contador;
		maximoIdCliente=aArrayClientes[primerPosicionOcupada].id;
		for(i=0;i<cantCont;i++)
		{
			if(aArrayCont[i].contador>maximaCanPedidosPendientes && aArrayCont[i].status==STATUS_PENDIENTE)
			{
				maximaCanPedidosPendientes=aArrayCont[i].contador;
				maximoIdCliente=aArrayCont[i].idCliente;
			}
		}

		index=buscarClientePorId(aArrayClientes,cantClientes,maximoIdCliente);
		printf("El cliente con mas pendidos pendientes es: NOMBRE %s - CUIT %s - DIRECCION %s - LOCALIDAD %s y tiene %d pedidos pendientes\n ",aArrayClientes[index].nombre,aArrayClientes[index].cuit,aArrayClientes[index].direccion,aArrayClientes[index].localidad,maximaCanPedidosPendientes);
		retorno=maximoIdCliente;
	}
	return retorno;
}


