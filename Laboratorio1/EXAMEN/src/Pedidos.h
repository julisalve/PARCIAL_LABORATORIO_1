#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define SIN_CANTIDAD_KILOS 0.00

#include "general.h"
#include "Clientes.h"

typedef struct
		{

		float kilos;
		float kilosTotales;
		int tipo;
		int id;
		int status;
		int idCliente;

		}Pedidos;


		struct
		{
					int status;
					int contador;
					int idCliente;
					//char cuit [50];
					//float acmulador;
		}typedef auxContador;


static int generarId();
int initLugarLibrePedidos(Pedidos *aArray, int cantidad);
int imprimirArrayPedidos(Pedidos *aArray, int cantidad);
int bajaClientePorId(Clientes *aArray, int cantidad,Pedidos *aArrayPed, int cantPed, int id);
int buscarLugarPedido(Pedidos *aArray, int cantidad);
int altaPedido(Pedidos *aArrayPed, int cantidad, Pedidos buffer);
int buscarPedidoPorId(Pedidos *aArray, int cantidad, int id);
int cantidadPedidosPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes);
int imprimirArrayPedidosPendientes(Pedidos *aArray, int cantidad);
int modificacionPedidoPorId(Pedidos *aArray, int cantidad, int index, Pedidos buffer);
//
//
int buscarClientePorIdEnPedido(Pedidos *aArray, int cantidad, int idCliente);

int imprimirArrayPedidosPendientesConClientes(Pedidos *aArray, int cantidad, Clientes *aArrayClientes, int cantidadClientes);

int initLugarLibreContador(auxContador *aArray, int cantidad);



#endif /* PEDIDOS_H_ */
