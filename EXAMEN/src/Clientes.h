#ifndef CLIENTES_H_
#define CLIENTES_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1


#include "general.h"

typedef struct
		{
		char cuit[50];
		int id;
		int status;
		char nombre[50];
		char direccion[50];
		char localidad [50];

		}Clientes;



int initLugarLibreClientes(Clientes *aArray, int cantidad);
int imprimirArrayClientes(Clientes *aArray, int cantidad);
int buscarLugarCliente(Clientes *aArray, int cantidad);
int altaClientePorId(Clientes *aArray, int cantidad,Clientes buffer, int *id);
int buscarClientePorId(Clientes *aArray, int cantidad, int id);
int imprimirDatosClientePorId(Clientes *aArray, int cantidad, int id);
int modificacionClientePorIdCamposPuntuales(Clientes *aArray, int cantidad, int index);
int ordenarCuit (Clientes *aArray, int cantidad);;

void altaForzadaClientes(Clientes *aArray,int cantidad);
#endif /* CLIENTES_H_ */
