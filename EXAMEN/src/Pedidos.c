#include "Pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>



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
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPedidos(Pedidos *aArray, int cantidad)
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
				printf("Id: %d - Status %d - IDCliente: %d - Tipo: %d - KIlos %.2f\n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].tipo,aArray[i].kilosTotales);
			}

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
				printf("Id: %d - Status %d - IDCliente: %d - Tipo: %d - KIlos %.2f\n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].tipo,aArray[i].kilosTotales);
			}

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
int imprimirArrayPedidosPendientesConClientes(Pedidos *aArray, int cantidad, Clientes *aArrayClientes, int cantidadClientes)
{
	int i;
	int j;
	int retorno = EXIT_ERROR;
	int idCliente;
	int index;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_PENDIENTE)
			{
				idCliente=aArray[i].idCliente;
				index=buscarClientePorId(aArrayClientes,cantidadClientes,idCliente);
				for (j=0;j<cantidadClientes;j++)
				{
					printf("cuit: %s - direccion %s - kilos: %.2f\n",aArrayClientes[index].cuit,aArrayClientes[index].direccion,aArray[i].kilosTotales);
				}

			}

		}
	}
	return retorno;
}

/**\brief Remove an employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer or employee not found] or (EXIT_SUCCESS 0) if OK.
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
				//aArrayPed[posicionClienteEnPedido].status=STATUS_EMPTY;
				retorno=EXIT_SUCCESS;
			}
	return retorno;
}

///**
// * \brief Busca la posicion de un id ingresado por un usuario
// * \param *aArray array que se le pasa a la funcion
// * \param cantidad tamaño del array
// * \param id
// * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la PRIMER posicion en donde se encuentra el id buscado
// *
// */
//int buscarClientePorIdEnPedido(Pedidos *aArray, int cantidad, int idCliente)
//{
//	int retorno =EXIT_ERROR;
//	int i;
//	if(aArray != NULL && cantidad > 0)
//	{
//		for(i=0;i<cantidad;i++)
//	{
//		if(idCliente==aArray[i].idCliente)
//		{
//			retorno = i;
//			break;
//		}
//	}
//	}
//	return retorno;
//}

/**
 * \brief BUsca el primer lugar libre y devuelve el fracaso o la posicion
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
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
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

//int validaKilosResiduos(Pedidos *aArray, int cantidad,)
//{
//	int retorno =EXIT_ERROR;
//
//	return retorno;
//}




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

int cantidadPedidosPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;
//	int contador=0;
//	if(aArray != NULL && cantidad>0 && aArrayClientes!=NULL && cantClientes>0)
//		{
//		contador=0;
//		for(i=0;i<cantClientes;i++)
//
//		{
//			if(aArrayClientes[i].status==STATUS_NOT_EMPTY)
//			for(j=0;i<cantidad;j++)
//			{
//				if(aArrayClientes[i].id==aArray[j].idCliente && aArray[j].status==STATUS_PENDIENTE )
//				{
//					contador++;
//
//
//				}
//				printf("Id: %d - Status %d - Nombre: %s - Direccion: %s - Cuit: %s - Cantidad pedidos Pendiente %d\n",aArrayClientes[i].id,aArrayClientes[i].status,aArrayClientes[i].nombre,aArrayClientes[i].direccion,aArrayClientes[i].cuit,contador);
//			}
//		}
//		}

//	int k;
//	int id;
//	//initAcumulador(aArrayCont,cantCont);
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
//		for(i=0;i<cantCont;i++)
//		{
//			if(aArrayCont[i].status==STATUS_PENDIENTE && aArrayCont[i].idCliente!=aArrayCont[i+1].idCliente)
//			{
//				for(k=0;k<cantClientes;k++)
//
//				{
//					for(j=0;j<cantidad;j++)
//					{
//
//
//					if(aArrayClientes[k].id==aArray[j].idCliente)
//
//					{
//						//id=aArray[j].idCliente;
//						printf("Id: %d - Status %d - Nombre: %s - Direccion: %s - Cuit: %s - Cantidad pedidos Pendiente %d\n",aArrayClientes[j].id,aArrayClientes[j].status,aArrayClientes[j].nombre,aArrayClientes[j].direccion,aArrayClientes[j].cuit,aArrayCont[i].contador);
//					}
//
//				}}
//
////				id=aArrayClientes[i].id;
////				imprimirDatosClientePorId(aArrayClientes,cantClientes,id);
//
//			}
//		}
	}
	return retorno;
}


int imprimirCantidadPedidosPendientesPorCuit(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	if(aArrayCont != NULL && cantCont>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		for(i=0;i<cantCont;i++)
				{
			for(j=0;j<cantClientes;j++)
					if(aArrayCont[i].status==STATUS_NOT_EMPTY && aArrayCont[i].idCliente!=aArrayCont[i+1].idCliente && aArrayCont[i].idCliente==aArrayClientes[j].id)
					{
						printf("Cuit %s - ID Cliente %d - NOmbre %s - Direccion %s - Localidad %s tiene %d pedidos pendientes\n",aArrayClientes[j].cuit,aArrayClientes[j].id,aArrayClientes[j].nombre,aArrayClientes[j].direccion,aArrayClientes[j].localidad,aArrayCont[i].contador);
					}
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


int crearArrayPosicionesPedidosPendientes(Pedidos *aArray, int cantidad, ArrayEnteros *auxArray, int cantEnt)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;
	if(aArray != NULL && cantidad>0)
			{
			for(i=0;i<cantidad;i++)
			{
				if(aArray[i].status==STATUS_PENDIENTE)
				{
					retorno=EXIT_SUCCESS;
					auxArray[j].entero=i;
//					auxArray[j].status=STATUS_NOT_EMPTY;
					j++;
				}
			}
			}


	return retorno;
}








