/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * 
 * \author João Rego
 * \date   March 2023
 *********************************************************************/

#include "Veiculos.h"
#include "Cliente.h"
#include "Gestor.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	VeiculosListaPtr inicio = LerVeiculos("Dados.bin");

	struct Veiculos Carro = { "Carro", 123, 4760, 900, 22000.00 };

	
}
