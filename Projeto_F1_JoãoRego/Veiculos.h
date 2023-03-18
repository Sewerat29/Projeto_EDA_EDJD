/*****************************************************************//**
 * \file   Veiculos.h
 * \brief  Listas Ligadas de veiculos eletricos 
 * 
 * \author João Rego
 * \date   March 2023
 *********************************************************************/

#ifndef Veiculo_
#define Veiculo_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

#pragma warning( disable : 4996 ) 
#pragma once
#define N 20

#pragma region Veiculos_Struct

typedef struct Veiculos
{
	char Tipo[N];
	int Autonomia;
	int Codigo_Postal;
	int Bateria;
	double Custo;
	bool Alugado;
	Cliente Cliente;

}Veiculos, *VeiculosPtr;


typedef struct VeiculosLista {

	Veiculos Veiculo;
	struct Veiculos* next; //aponta para o próximo veiculo 

}VeiculosLista, * VeiculosListaPtr;


//Aloca memória para armazenar Veiculos
Veiculos* CriaVeiculo(char* tipo, int autonomia, int codigo_postal, int bateria, double custo, bool alugado, Cliente cliente); 


#pragma region Ler e Escrever Ficheiros

//Grava os dados dos Veiculos 
int GravaVeiculos(VeiculosListaPtr h, char fileName[]);
//Lê informação de um ficheiro 
VeiculosListaPtr LerVeiculos(char fileName[]);

#pragma endregion


#pragma region Manipulação de Listas

//Introduz um "Veiculo" como head da lista
VeiculosListaPtr InsereVeiculoLista(VeiculosListaPtr head, VeiculosPtr novo);

//Liberta a memória usada por uma lista
bool DestroiLista(VeiculosListaPtr head);

#pragma endregion


#pragma endregion

#endif 





