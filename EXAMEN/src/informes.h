#ifndef INFORMES_H_
#define INFORMES_H_

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000
#include "general.h"
#include "Clientes.h"
#include "Pedidos.h"

int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, auxContador *aArrayCont, int cantCont);
int obtenerId(Clientes *aArray, int cantidad,  Pedidos *aArrayPed, int cantPed);
int cantPedidosPendientes(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes);
int maximoPedidos(int cantidadPedidos, int *maximoPed, int *id, int *maximoId);
int buscarClientePorIdInformes(Clientes *aArray, int cantidad, int id);
int cantPedidosCompletados(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes);
int obtenerIdCompletos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int obtenerIdMasPedidos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int cantPedidosGenerales(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes);
int obtenerIdClienteQueRecicloMAsKilos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int sumaTotalesDeReciclajePorId(Pedidos *aArrayPed, int cantPed, int *id);
int obtenerIdClienteQueRecicloMenosKilos(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int minimosPedidos(int cantidadPedidos, int *minimoPed, int *id, int *minimoId);


int cantPedidosPendientes(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes);
int imprimirDatosCLientePorId (Clientes *aArray, int cantClientes, int id, Pedidos *aArrayPed, int cantPed);
int buscarPrimerLugarPedidoPendiente(auxContador *aArray, int cantidad);
int cantidadPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes);
int imprimirClienteConCantidadMaximaPedidos(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
#endif /* INFORMES_H_ */
