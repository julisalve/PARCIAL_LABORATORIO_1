#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "informes.h"
#include "general.h"
#include <ctype.h>




int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, auxContador *aArrayCont, int cantCont)
{
	int retorno= EXIT_ERROR;
	int opcion;
	char localidadIngresadaChar [QTY_LOCALIDAD];
	float promedio;
	int tipoResiduo;
	char cuit[20];
	while(getInt(&opcion, "Ingrese una opcion de informes\n  1)Cliente con mas pedidos pendientes.\n  2)Cliente con mas pedidos completos.\n  3)Cliente con mas pedidos.\n  4)Cliente que reciclo mas kilos.\n  5)Cliente que reciclo menos kilos.\n  6)Cantidad de clientes que reciclaron mas de 1.000 kgs.\n  7)Cantidad de clientes que reciclaron menos de 100 kgs.\n  8)Imprimir pedidos completados.\n  9)Cantidad de pedidos pendientes por localidad ingresada.\n  10)Cantidad de kilos polipropileno reciclado promedio por cliente.\n  11)Cantidad de tipo de residuo por cuit a ingresar.\n","NO es una opcion valida.",1,11,3)!=0)
			{
				printf("ERROR.\n ");
			}
	ordenarPorIdCliente(aArrayPed,cantPed);
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
	case 6:
obtenerCantidadClientesMasMilKilosReciclados(aArrayClientes, cantClientes,aArrayPed,cantPed);
break;
	case 7:
obtenerCantidadClientesMenosCienKilosReciclados(aArrayClientes, cantClientes, aArrayPed, cantPed);
break;
	case 8:
ordenarPorIdPedidos (aArrayPed, cantPed);
imprimirPedidosCompletosConClientesYPorcentajePlasticoReciclado(aArrayPed,cantPed,aArrayClientes,cantClientes);
break;
	case 9:
		if(getDatoSoloLetras(localidadIngresadaChar, "Ingrese el nombre de una localidad para realizar la busqueda de pedidos pendientes \n","NO es una localidad valida \n",2,50,2)!=0)
		{
			printf("ERROR \n");
		}
		else
		{
			pasarSoloPrimeraLetraMayuscula(localidadIngresadaChar);
			opcion=1;
			obtenerCantidadPedidosPendientesPorLocalidadIngresada(aArrayClientes,cantClientes,aArrayPed, cantPed, localidadIngresadaChar);
		}
//		getInt(&localidadIngresada, "Ingrese el nombre de una localidad para realizar la busqueda de pedidos pendientes:\n 1)CABA,\n 2)LANUS,\n 3)QUILMES,\n 4)AVELLANEDA \n","NO es una localidad valida \n",1,4,2);
//obtenerCantidadPedidosPendientesPorLocalidadIngresada(aArrayClientes, cantClientes, aArrayPed, cantPed,localidadIngresada);
		break;
	case 10:
promedio=obtenerKilosPolipropilenoPromedio(aArrayPed,cantPed);
printf("La cantidad de kilos de polipropileno reciclado promedio por cliente es %.2f \n",promedio);
break;
	case 11:
		getInt(&tipoResiduo, "Indique numero de tipo de residuo: 1)HDPE, 2)LDPE , 3)PP:\n","NO es un tipo valido \n",1,3,2);
		getSoloNumeros(cuit, "Ingrese numero de cuit sin guion \n","No es un cuit valido",1,20,2);
obtenerKilosTotalesTipoResiduoPorCuit(aArrayPed, cantPed, aArrayClientes,cantClientes,cuit, tipoResiduo);

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
			if(aArrayPed[i].idCliente ==*id && (aArrayPed[i].status==STATUS_COMPLETO || aArrayPed[i].status==STATUS_PENDIENTE))
			{
				contador++;
			}
		}
		retorno=contador;
	}
	return retorno;
}

//4) cliente que reciclo mas kilos

int obtenerIdClienteQueRecicloMAsKilos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{

	int retorno =EXIT_ERROR;
	int i;
	int id;
	int acumulador;
	int maximoPed=0;
	int maximoId=0;
	int flagClienteConMasDeUnPedido=0;
	int j;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantPed;i++)
		{
			j=i+1;
			if(aArrayPed[i].status==STATUS_COMPLETO)
			{
			if(aArrayPed[j].idCliente==aArrayPed[j-1].idCliente)
			{
				flagClienteConMasDeUnPedido++;
			}
			if(flagClienteConMasDeUnPedido==0)
			{
				acumulador=0;
			}
			id=aArrayPed[i].idCliente;
			acumulador=sumaTotalesDeReciclajePorId(aArrayPed, cantPed, &id);
			maximoPedidos(acumulador, &maximoPed, &id, &maximoId);
			}
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, maximoId, aArrayPed, cantPed);
	return retorno;
}

int sumaTotalesDeReciclajePorId(Pedidos *aArrayPed, int cantPed, int *id)
{
	int retorno =EXIT_ERROR;
	int i;
	int acumulador;
	acumulador=0;
	if(aArrayPed != NULL && cantPed > 0)
	{
		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].status==STATUS_COMPLETO && aArrayPed[i].idCliente==*id)
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
	int acumulador;
	int minimoPed=100000000;
	int minimoId=100;
	int flagClienteConMasDeUnPedido=0;
	int j;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantPed;i++)
		{
			j=i+1;
			if(aArrayPed[i].status==STATUS_COMPLETO)
			{
			if(aArrayPed[j].idCliente==aArrayPed[j-1].idCliente)
			{
				flagClienteConMasDeUnPedido++;
			}
			if(flagClienteConMasDeUnPedido==0)
			{
				acumulador=0;
			}
			id=aArrayPed[i].idCliente;
			acumulador=sumaTotalesDeReciclajePorId(aArrayPed, cantPed, &id);
			minimosPedidos(acumulador, &minimoPed, &id, &minimoId);
			}
		}
		}
	imprimirDatosCLientePorId (aArrayClientes,cantClientes, minimoId, aArrayPed, cantPed);
	return retorno;
}

int minimosPedidos(int cantidadKilos, int *minimoPed, int *id, int *minimoId)
{
	int retorno =EXIT_ERROR;
	if(cantidadKilos<*minimoPed)
	{
		*minimoPed=cantidadKilos;
		*minimoId=*id;
		retorno=EXIT_SUCCESS;
	}
	return retorno;
}


//6) cantidad clientes que reciclaron mas de 1.000 kg - SUPONGO SOLO KILOS RECICLAJE.

int obtenerCantidadClientesMasMilKilosReciclados(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{
	int retorno =EXIT_ERROR;
	int i;
	int id;
	int pedidosMasMilKilos=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			pedidosMasMilKilos=pedidosMasMilKilos +cantPedidosMasMilKilos(aArrayPed, cantPed,aArrayClientes, cantClientes, id);
		}
	if(pedidosMasMilKilos==0)
	{
		printf("No hay clientes que hayan reciclado mas de 1.000 kgs \n");
	}
	else
	{
		printf("La cantidad de clientes que reciclaron mas de 1.000 kg es %d\n",pedidosMasMilKilos);
	}
		}
	return retorno;
}

int cantPedidosMasMilKilos(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	int contador=0;
	int kilosReciclados;
	if(aArrayPed != NULL && cantPed > 0 )
	{
		for(i=0;i<cantPed;i++)
		{
			j=i+1;
			if(aArrayPed[i].idCliente==id)
			{
			kilosReciclados=sumaTotalesDeReciclajePorId(aArrayPed,cantPed, &id);
			if(aArrayPed[i].status==STATUS_COMPLETO && kilosReciclados>QTY_MAS_X_KILOS_RECICLADOS &&aArrayPed[j].idCliente!=aArrayPed[j-1].idCliente )
			{
					contador++;
			}
		}
	}
		retorno=contador;
	}
	return retorno;
}


// 7) Cant clientes que reciclaron menos de 100 kg

int obtenerCantidadClientesMenosCienKilosReciclados(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed)
{
	int retorno =EXIT_ERROR;
	int i;
	int id;
	int pedidosMenosCienKilos=0;
	if(aArrayClientes != NULL && cantClientes > 0 )
		{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			id=aArrayClientes[i].id;
			pedidosMenosCienKilos=pedidosMenosCienKilos +cantPedidosMenosCienKilos(aArrayPed, cantPed,aArrayClientes, cantClientes, id);
		}
	if(pedidosMenosCienKilos==0)
	{
		printf("No hay clientes que hayan reciclado menos de 100 kgs \n");
	}
	else
	{
		printf("La cantidad de clientes que reciclaron menos de 100 kg es %d\n",pedidosMenosCienKilos);
	}
		}
	return retorno;
}

int cantPedidosMenosCienKilos(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	int contador=0;
	int kilosReciclados;
	if(aArrayPed != NULL && cantPed > 0 )
	{
		for(i=0;i<cantPed;i++)
		{
			j=i+1;
			if(aArrayPed[i].idCliente==id)
			{
			kilosReciclados=sumaTotalesDeReciclajePorId(aArrayPed,cantPed, &id);
			if(aArrayPed[i].status==STATUS_COMPLETO && kilosReciclados<QTY_MENOS_X_KILOS_RECICLADOS &&aArrayPed[j].idCliente!=aArrayPed[j-1].idCliente )
			{
					contador++;
				}
			}
		}
		retorno=contador;

	}
	return retorno;
}


// 8) IMprimir pedidos completados indicando ID pedido - CUIT - % de plastico reciclado (kg reciclados/kg totales)



/**\brief Ordena de mayor a menor el id de los clientes
 *
 * \param *aArray array de pedidos
 * \param cantidad tamaño del aray de pedidos
 * \return int DEvuelve(EXIT_ERROR -1) en caso de de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int ordenarPorIdPedidos (Pedidos *aArray, int cantidad)
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
			while (aArray[j].id<aArray[j-1].id && j>0) //ordena de menor a mayor
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
 * \brief Imprime pedidos completos con siguientes datos: ID Pedidos - CUIT - % de plastico reciclado
 * \param *aArrayPed array de pedidos
 * \param cantPed tamaño del array pedidos
 * \param *aArrayClientes array de clientes
 * \param cantClientes tamaño del array clientes
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array de clientes o pedidos sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int imprimirPedidosCompletosConClientesYPorcentajePlasticoReciclado(Pedidos *aArrayPed,int cantPed,Clientes *aArrayClientes,int cantClientes)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	int id;
	int suma;
	float porcentajePlasticoReciclado;
	if(aArrayPed != NULL && cantPed>0 && aArrayClientes!=NULL && cantClientes>0)
	{
		retorno =EXIT_SUCCESS;
		for(i=0;i<cantPed;i++)
		{
			for(j=0;j<cantClientes;j++)
			{
		if(aArrayPed[i].status==STATUS_COMPLETO && aArrayPed[i].idCliente==aArrayClientes[j].id)
			{
			id=aArrayPed[i].id;
			suma=sumaTotalesDeReciclajePorIdPedido(aArrayPed,cantPed,&id);
			porcentajePlasticoReciclado=suma/aArrayPed[i].kilosTotales*100;
			printf("Id pedido: %d - Cuit: %s - Porcentaje Plastico Reciclado : %.2f\n",aArrayPed[i].id,aArrayClientes[j].cuit,porcentajePlasticoReciclado);
				}
			}
		}
	}
	return retorno;
}

int sumaTotalesDeReciclajePorIdPedido(Pedidos *aArrayPed, int cantPed, int *id)
{
	int retorno =EXIT_ERROR;
	int i;
	int acumulador;
	acumulador=0;
	if(aArrayPed != NULL && cantPed > 0)
	{
		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].status==STATUS_COMPLETO && aArrayPed[i].id==*id)
			{
					acumulador=acumulador+aArrayPed[i].kilosHdpe_1+aArrayPed[i].kilosLdpe_2+aArrayPed[i].kilosPp_3;
			}
		}
		retorno=acumulador;
	}
	return retorno;
}


// 9)Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.

//int obtenerCantidadPedidosPendientesPorLocalidadIngresada(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed, int localidad)
//{
//	int retorno =EXIT_ERROR;
//	int i;
//	char localidadEnLetras[50];
//	int contador=0;
//	if(aArrayPed != NULL && cantPed > 0 && aArrayClientes != NULL && cantClientes > 0)
//	{
//		retorno=EXIT_SUCCESS;
//		switch(localidad)
//		{
//		case 1:
//			strncpy(localidadEnLetras,"Caba",50);
//			break;
//		case 2:
//			strncpy(localidadEnLetras,"Lanus",50);
//			break;
//		case 3:
//			strncpy(localidadEnLetras,"Quilmes",50);
//			break;
//		case 4:
//			strncpy(localidadEnLetras,"Avellaneda",50);
//			break;
//		default:
//			printf("NO existe lcoalidad con ese nombre \n");
//			break;
//		}
//		for(i=0;i<cantClientes;i++)
//		{
//			if(strncmp(localidadEnLetras,aArrayClientes[i].localidad,50)==0)
//			{
//				contador++;
//			}
//		}
//		if(contador==0)
//		{
//			printf("No existe esa localidad\n");
//		}
//		else
//		{
//			printf("La cantidad de pedidos pendientes para la localidad %s es: %d\n",localidadEnLetras,contador);
//		}
//	}
//	return retorno;
//}

int pasarSoloPrimeraLetraMayuscula(char *localidad)
{
	int retorno =EXIT_ERROR;
	int i=0;
	if(localidad !=NULL)
	{
	retorno=EXIT_SUCCESS;
	localidad[0]=toupper(localidad[0]);

	for(i=1;i<QTY_LOCALIDAD;i++)
	{
		localidad[i]=tolower(localidad[i]);
	}
	}
	return retorno;
}


int obtenerCantidadPedidosPendientesPorLocalidadIngresada(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed, char *localidad)
{
	int retorno =EXIT_ERROR;
	int i;
	int contador=0;
	if(aArrayPed != NULL && cantPed > 0 && aArrayClientes != NULL && cantClientes > 0 && localidad !=NULL)
	{
		retorno=EXIT_SUCCESS;
		for(i=0;i<cantClientes;i++)
		{
			if(strncmp(localidad,aArrayClientes[i].localidad,QTY_LOCALIDAD)==0)
			{
				contador++;
			}
		}
		if(contador==0)
		{
			printf("No existe esa localidad\n");
		}
		else
		{
			printf("La cantidad de pedidos pendientes para la localidad %s es %d\n",localidad,contador);
		}
	}

	return retorno;
}

// cantidad kilos propileno reciclado promedio por cliente (kg totales polipropileno / cant clientes) Tomo pedidos solo completos. Sumo polipropileno y divido por clientes con pedidos completos.  230+30+270+70+3 y se divide por 4 (id 1 solo una vez se cuenta)

float obtenerKilosPolipropilenoPromedio(Pedidos *aArrayPed, int cantPed)
{
	float retorno =EXIT_ERROR;
	int contadorClientes=1;
	int flag=0;
	float kilosPolipropileno=0;
	float promedio;
	int i;
	int j;
	if(aArrayPed != NULL && cantPed > 0 )
		{

			retorno =EXIT_SUCCESS;
			for(i=0;i<cantPed; i++)
			{j=i+1;
				if(aArrayPed[i].status==STATUS_COMPLETO)
				{
					flag=1;
					if(aArrayPed[j].idCliente!=aArrayPed[j-1].idCliente)
					{
						contadorClientes++;
					}
					kilosPolipropileno=kilosPolipropileno +aArrayPed[i].kilosPp_3;
				}

			}
			if(flag==0)
							{
								contadorClientes=0;
								printf("NO se puede calcular el promedio ya que no hay pedidos completos \n");
							}
			promedio=kilosPolipropileno/contadorClientes;
			retorno=promedio;
		}
	return retorno;
}


//11) ingresar cuit de cliente y uno de los tres tipo de plastico e informar kilos totales reciclados de dicho tipo.

int obtenerKilosTotalesTipoResiduoPorCuit(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, char *cuit, int tipoResiduo)
{
	int retorno =EXIT_ERROR;
	int index;
	int idCliente;
	int kilos=0;
	int i;
	if(aArrayPed != NULL && cantPed > 0 && aArrayClientes !=NULL && cantClientes >0)
	{
		index=buscarClientePorCuit(aArrayClientes,cantClientes,cuit);
		if(index<0)
		{
			printf("NO existe el cuit ingresado \n");
		}
		idCliente=aArrayClientes[index].id;
		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].idCliente==idCliente && aArrayPed[i].status==STATUS_COMPLETO)
			{
				switch(tipoResiduo)
				{
				case 1:
					kilos=kilos+aArrayPed[i].kilosHdpe_1;
					break;
				case 2:
					kilos=kilos+aArrayPed[i].kilosLdpe_2;
					break;
				case 3:
					kilos=kilos+aArrayPed[i].kilosPp_3;
					break;
				}

			}
		}imprimirKilosTotalesTipoResiduoPorCuit(kilos,cuit,tipoResiduo);
		retorno=kilos;
	}
	return retorno;
}

/**
 * \brief Busca la posicion de un cuit ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param cuit que se desea buscar
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el cuit buscado
 *
 */
int buscarClientePorCuit(Clientes *aArray, int cantidad, char *cuit)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status== STATUS_NOT_EMPTY && strncmp(cuit,aArray[i].cuit,20)==0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int imprimirKilosTotalesTipoResiduoPorCuit(int kilos, char *cuit, int tipoResiduo)
{
	int retorno=EXIT_ERROR;
	char residuoEnLetras[50];
if(cuit!=NULL)
{
	switch(tipoResiduo)
	{
	case 1:
		strncpy(residuoEnLetras,"HDPE",50);
		break;
	case 2:
		strncpy(residuoEnLetras,"LDPE",50);
		break;
	case 3:
		strncpy(residuoEnLetras,"PP",50);
		break;
	}
	printf("La cantidad de kilos de plastico %s para el cuit %s es %d \n",residuoEnLetras,cuit,kilos);
}

	return retorno;
}
