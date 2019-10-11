#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Clientes.h"
#include "general.h"
#include "Pedidos.h"

#define QTY_PEDIDOS 1000
#define QTY_CLIENTES 100

int altaForzadaPublicidad(Pedidos *aArray,int cantidad);
int altaForzadaPantalla(Clientes *aArray,int cantidad);

int altaForzadaPantalla(Clientes *aArray,int cantidad)
{
	int retorno;
	int id[]={1,2,3,4,5};
	int status[]={1,1,1,1,1};
	char nombre[][50]={" juan sh","pedro srl","maria sa","luis sca","eva scc"};
	char direccion[][50]={" Lavalle 209","Ayolas 3429","383 2696","pellegrini y calchaqui","12 de oct 2431"};
	char cuit[][50]={"11111111111","22222222222","33333333333","44444444444","55555555555"};
	char localidad[][50]={" Quilmes","Avellaneda","caba","Wilde","Burzaco"};

	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];

		strncpy(aArray[i].nombre,nombre[i],50);
		strncpy(aArray[i].direccion,direccion[i],50);
		strncpy(aArray[i].cuit,cuit[i],50);
		strncpy(aArray[i].localidad,localidad[i],50);

		retorno=0;
	}
	return retorno;
}



int altaForzadaPublicidad(Pedidos *aArray,int cantidad)
{
	int retorno;
	float kilos[]={12.5,1.2,8.9,9.8,10.0};
	int tipo[]={1,2,3,1,1};
	int id[]={10,3,4,2,9};
	int status[]={1,2,0,2,1};
	int idCliente[]={1,2,3,4,5};

	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].kilos=kilos[i];
		aArray[i].tipo=tipo[i];
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		aArray[i].idCliente=idCliente[i];

		retorno=0;
	}
	return retorno;
}







int main(void)
{
	Pedidos aPedidos[QTY_PEDIDOS];
	Pedidos bPedidos;
	//Pedidos auxPedidos[QTY_PEDIDOS];
	Clientes aClientes[QTY_CLIENTES];
	Clientes bCliente;
	auxContador aContador[QTY_PEDIDOS];
	int opcion;
	int flagOpcionUno=0;
	int flagDos=0;
	//int tipoResiduo;
	//ArrayEnteros aArrayEnterosId[QTY_PANTALLAS];
	int id;
	int index;
	char respuesta[4];
	char confirmacion [3];
	//char cuit[50];
	initLugarLibrePedidos(aPedidos,QTY_PEDIDOS);
	initLugarLibreClientes(aClientes,QTY_CLIENTES);
	do
	{
		//altaForzadaPantalla(aPantalla,QTY_PANTALLAS);
		imprimirArrayClientes(aClientes,QTY_CLIENTES);
		//altaForzadaPublicidad(aPublicidad,QTY_PUBLICIDADES);
		imprimirArrayPedidos(aPedidos,QTY_PEDIDOS);




		system("clear");
		printf("1)ALTA CLIENTE.\n2)MODIFICACION CLIENTE\n3)BAJA CLIENTE.\n4)CREAR PEDIDO DE RECOLECCION.\n5) PROCESAR RESIDUOS.\n6) IMPIMIR CLIENTES.\n7) IMPRIMIR PEDIDOS PENDIENTES.\n8) IMPRIMIR PEDIDOS PROCESADOS.\n ");
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






			altaClientePorId(aClientes,QTY_CLIENTES,bCliente);
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
				}
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
					imprimirArrayPedidos(aPedidos, QTY_PEDIDOS);
					flagDos=1;
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
				index=buscarPedidoPorId(aPedidos, QTY_PEDIDOS,id);
				while(index==-1)
				{
					getInt(&id,"NO es un id valido para realizar el procesamiento de residuos, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				bPedidos.kilosTotales=aPedidos[index].kilosTotales;
				do
				{

					while(getInt(&bPedidos.tipo,"Ingrese el tipo de residuo . 1)HDPE, 2)LDPE, 3)PP, 4)DESECHO \n","NO es un tipo valido \n",1,4,2)!=0)

					{
						printf("ERROR.\n");

					}

					printf("Usted selecciono el tipo de residuo %d \n",bPedidos.tipo);

					if(getFloat(&bPedidos.kilos,"Ingrese los kilos del tipo de residuo seleccionado \n","NO es un dato valido \n",0.01,1000000.0,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}


					if(esSiONo(respuesta,"¿Desea seguir cargando kilos de otro tipo de residuo? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
					{							printf("ERROR. \n");
					break;
					}


				}while(strncmp(respuesta,"si",3)==0);
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
				ordenarCuit (aClientes,QTY_CLIENTES);
						imprimirArrayClientes(aClientes,QTY_CLIENTES);
				cantidadPedidosPendientesPorCuit(aPedidos,QTY_PEDIDOS, aContador,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
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




		}
		if(esSiONo(respuesta,"¿Desea seguir haciendo otra operacion? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
							{
								printf("ERROR. \n");
								break;
							}
	}

		while(strncmp(respuesta,"si",4)==0);
	}
