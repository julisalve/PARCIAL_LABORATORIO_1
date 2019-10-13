#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Clientes.h"
#include "general.h"
#include "Pedidos.h"

#define QTY_PEDIDOS 1000
#define QTY_CLIENTES 100

int main(void)
{
	Pedidos aPedidos[QTY_PEDIDOS];
	Pedidos bPedidos;
	Clientes aClientes[QTY_CLIENTES];
	Clientes bCliente;
	auxContador aContador[QTY_PEDIDOS];
	int opcion;
	int flagOpcionUno=0;
	int flagDos=0;
	int contadorClientes=0;
	int id;
	int index;
	char respuesta[4];
	char confirmacion [3];
	initLugarLibrePedidos(aPedidos,QTY_PEDIDOS);
	initLugarLibreClientes(aClientes,QTY_CLIENTES);
	do
	{
		//		altaForzadaClientes(aClientes,QTY_CLIENTES);
		//		imprimirArrayClientes(aClientes,QTY_CLIENTES);
		//		altaForzadaPedidos(aPedidos,QTY_PEDIDOS);
		//		imprimirArrayPedidosDistintoEmpty(aPedidos,QTY_PEDIDOS);

		system("clear");
		printf("1)ALTA CLIENTE.\n2)MODIFICACION CLIENTE\n3)BAJA CLIENTE.\n4)CREAR PEDIDO DE RECOLECCION.\n5)PROCESAR RESIDUOS.\n6)IMPIMIR CLIENTES CON PEDIDOS PENDIENTES.\n7)IMPRIMIR PEDIDOS PENDIENTES.\n8)IMPRIMIR PEDIDOS PROCESADOS.\n ");
		if(getInt(&opcion, "Ingrese una opcion del menu \n", "NO es una opcion valida \n",1,8,3)!=0)
		{
			printf("ERROR.\n ");
			break;
		}
		switch(opcion)
		{
		case 1:
			if(buscarLugarCliente(aClientes,QTY_CLIENTES)==-1)
			{
				printf("NO hay lugar libre.\n");
				break;
			}
			if(getDatoSoloLetras(bCliente.nombre,"Ingrese el nombre de la empresa\n","NO es un nombre valido\n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getSoloNumeros(bCliente.cuit,"Ingrese numero de cuit \n","NO es un cuit valido \n",10,17,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getDatoAlfaNumerico(bCliente.direccion,"Indique la direccion\n","NO es una direccion valida \n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getDatoSoloLetras(bCliente.localidad,"Ingrese la localidad\n","NO es una localidad valido\n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			altaClientePorId(aClientes,QTY_CLIENTES,bCliente,&id);
			printf("ALTA REALIZADA CON EXITO.\nID generado para el cliente: %d\n",id);
			contadorClientes++;
			flagOpcionUno=1;
			break;

		case 2:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else
			{
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				if(getInt(&id,"Indique el id que desea modificar\n", "NO es un id valido\n", 1,100,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				printf("Ha seleccionado el siguiente ID para modificar. \n");
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				index=buscarClientePorId(aClientes, QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"¿Desea modificar este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					do
					{
						modificacionClientePorIdCamposPuntuales(aClientes,QTY_CLIENTES,index);
						if(esSiONo(respuesta,"¿Desea seguir modificando este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
						{							printf("ERROR. \n");
						break;
						}

					}while(strncmp(respuesta,"si",3)==0);
					printf("MODIFICACION EXITOSA. \n");
				}
			}
			break;

		case 3:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else
			{
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				if(getInt(&id,"Indique el id que desea dar de baja\n", "NO es un id valido\n", 1,100,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				printf("Ha seleccionado el siguiente ID para dar de baja. \n");
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"¿Desea dar de baja este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					bajaClientePorId(aClientes,QTY_CLIENTES,aPedidos,QTY_PEDIDOS,id); // DOY DE BAJA LOS PEDIDOS DE ESTE CLIENTE. NO LO DICE EL ENUNCIADO PERO ME PARECE ADECUADO HACERLO
					printf("BAJA EXITOSA. \n");
					contadorClientes--;
				}
			}
			if(contadorClientes==0)
			{
				printf("NO hay clientes en la lista. \n");
			}
			else
			{
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
			}
			break;

		case 4:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else
			{
				if(buscarLugarPedido(aPedidos,QTY_PEDIDOS)==-1)
				{
					printf("NO hay lugar libre.\n");
					break;
				}
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				getInt(&id,"Indique el ID del cliente en la cual quiere cargar un pedido.\n","NO es un id valido\n", 1,100,2);
				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);
				}
				printf("Ha seleccionado el siguiente ID para cargar pedidos. \n");
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"Ha seleccionado este cliente para cargar un pedido ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					bPedidos.idCliente=id;

					if(getFloat(&bPedidos.kilosTotales,"Ingrese kilos totales a recolectar\n","NO es un dato valido \n",0.01,1000000.0,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}
					//				index=buscarPantallaPorId(aPantalla,QTY_PANTALLAS,id);
					altaPedido(aPedidos, QTY_PEDIDOS, bPedidos);
					imprimirArrayPedidosNotEmpty(aPedidos, QTY_PEDIDOS);
					flagDos=1;
					printf("CARGA DE PEDIDO REALIZADA CON EXITO. LA MISMO SE ENCUENTRA EN ESTADO PENDIENTE.\n");
				}
			}
			break;

		case 5:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe cargar un pedido\n");
			}
			else
			{
				imprimirArrayPedidosPendientes(aPedidos, QTY_PEDIDOS);
				getInt(&id,"Indique el ID del pedido que quiere procesar.\n","NO es un id valido\n", 1,100,2);
				do
					{
					index=buscarPedidoPorId(aPedidos, QTY_PEDIDOS,id);
					if(index==-1)
					{
						getInt(&id,"NO es un id valido para realizar el procesamiento de residuos, reingrese\n", "NO es un id valido\n", 1,100,2);
					}
					}while(index==-1);
				bPedidos.kilosTotales=aPedidos[index].kilosTotales;
				printf("La cantidad total de Kilos a procesar en este pedido es: %.2f \n",bPedidos.kilosTotales);
				do
				{
					do
					{

						while(getInt(&opcion,"Ingrese el tipo de residuo . 1)HDPE, 2)LDPE, 3)PP \n","NO es un tipo valido \n",1,3,2)!=0)
						{
							printf("ERROR.\n");
						}
						switch(opcion)
						{
						case 1:
							if(getFloat(&bPedidos.kilosHdpe_1,"Ingrese los kilos de residuo tipo HDPE \n","NO es un dato valido \n",0,1000000.0,2)!=0)
							{
								printf("ERROR.\n");
								break;
							}
							break;
						case 2:
							if(getFloat(&bPedidos.kilosLdpe_2,"Ingrese los kilos de residuo tipo LDPE \n","NO es un dato valido \n",0.01,1000000.0,2)!=0)
							{
								printf("ERROR.\n");
								break;
							}
							break;
						case 3:
							if(getFloat(&bPedidos.kilosPp_3,"Ingrese los kilos de residuo tipo PP \n","NO es un dato valido \n",0.01,1000000.0,2)!=0)
							{
								printf("ERROR.\n");
								break;
							}
							break;
						}
						if(esSiONo(respuesta,"¿Desea seguir cargando kilos de otro tipo de residuo? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
						{							printf("ERROR. \n");
						break;
						}
					}while(strncmp(respuesta,"si",3)==0);
					bPedidos.kilosDesecho_4=bPedidos.kilosTotales-bPedidos.kilosHdpe_1-bPedidos.kilosLdpe_2-bPedidos.kilosPp_3;
					printf("kilos desecho %.2f \n",bPedidos.kilosDesecho_4);
					if(bPedidos.kilosDesecho_4<0)
						{
						printf("La suma de los kilos por tipo de residuo superan los kilos totales. Debe cargar nuevamente los datos \n");
						bPedidos.kilosHdpe_1=0;
						bPedidos.kilosLdpe_2=0;
						bPedidos.kilosPp_3=0;
						}
				}while(bPedidos.kilosDesecho_4<=0);
				modificacionPedidoPorId(aPedidos,QTY_CLIENTES,index, bPedidos);
			}
			break;

		case 6:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe cargar un pedido\n");
			}
			else
			{
				ordenarPorIdCliente (aPedidos,QTY_PEDIDOS);
				//		imprimirArrayPedidos(aPedidos,QTY_PEDIDOS);
				cantidadPedidosPendientesPorCuit(aPedidos,QTY_PEDIDOS, aContador,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
				//imprimirCantidadPedidosPendientesPorCuit(aContador,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
			}
			break;

		case 7:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe cargar un pedido\n");
			}
			else
			{
				imprimirArrayPedidosPendientesConClientes(aPedidos,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
			}
			break;

		case 8:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar un cliente\n");
			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe cargar un pedido\n");
			}
			else
			{
				imprimirArrayPedidosCompletosConClientes(aPedidos,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
			}
			break;

		}
		if(esSiONo(respuesta,"¿Desea seguir haciendo otra operacion? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
		{
			printf("ERROR. \n");
			break;
		}
	}while(strncmp(respuesta,"si",4)==0);
}
