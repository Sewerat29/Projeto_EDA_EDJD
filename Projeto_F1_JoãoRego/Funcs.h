#pragma once
#define N 20

typedef struct Veiculos
{
	char Tipo[N];
	int Autonomia;
	int Codigo_Postal;
	int Bateria;
	double Custo;
	int* next;

}Veiculos, * Veiculos;



