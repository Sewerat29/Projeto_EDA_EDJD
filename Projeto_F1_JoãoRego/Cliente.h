/*****************************************************************//**
 * \file   Cliente.h
 * \brief  
 * 
 * \author João Rego
 * \date   March 2023
 *********************************************************************/

#ifndef Clientes
#define Clientes

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>	

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#define N 20
#pragma once

#pragma region 

typedef struct Cliente {

	char Nome[N];
	char Morada[N];
	double Saldo;
	int NIF;

}Cliente, *ClientePtr;


//Aloca memória para armazenar Clientes
ClientePtr CriaCliente(char* nome, char* morada, double saldo, int nif);

#pragma endregion

#endif