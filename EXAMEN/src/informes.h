#ifndef INFORMES_H_
#define INFORMES_H_

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000
#define QTY_MAS_X_KILOS_RECICLADOS 1000
#define QTY_MENOS_X_KILOS_RECICLADOS 100
#define QTY_LOCALIDAD 50
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
int minimosPedidos(int cantidadKilos, int *minimoPed, int *id, int *minimoId);
int obtenerCantidadClientesMasMilKilosReciclados(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int cantPedidosMasMilKilos(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, int id);
int obtenerCantidadClientesMenosCienKilosReciclados(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
int cantPedidosMenosCienKilos(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, int id);
int ordenarPorIdPedidos (Pedidos *aArray, int cantidad);
int imprimirPedidosCompletosConClientesYPorcentajePlasticoReciclado(Pedidos *aArrayPed,int cantPed,Clientes *aArrayClientes,int cantClientes);
int sumaTotalesDeReciclajePorIdPedido(Pedidos *aArrayPed, int cantPed, int *id);
//int obtenerCantidadPedidosPendientesPorLocalidadIngresada(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed, int localidad);
int pasarSoloPrimeraLetraMayuscula(char *localidad);
int obtenerCantidadPedidosPendientesPorLocalidadIngresada(Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed, char *localidad);
float obtenerKilosPolipropilenoPromedio(Pedidos *aArrayPed, int cantPed);
int obtenerKilosTotalesTipoResiduoPorCuit(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, char *cuit, int tipoResiduo);
int buscarClientePorCuit(Clientes *aArray, int cantidad, char *cuit);
int imprimirKilosTotalesTipoResiduoPorCuit(int kilos, char *cuit, int tipoResiduo);


int cantPedidosPendientes(Pedidos *aArrayPed, int cantPed, int *id, Clientes *aArrayClientes, int cantClientes);
int imprimirDatosCLientePorId (Clientes *aArray, int cantClientes, int id, Pedidos *aArrayPed, int cantPed);
int buscarPrimerLugarPedidoPendiente(auxContador *aArray, int cantidad);
int cantidadPendientesPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes);
int imprimirClienteConCantidadMaximaPedidos(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPed, int cantPed);
#endif /* INFORMES_H_ */
