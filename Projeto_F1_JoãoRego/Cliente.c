/*****************************************************************//**
 * \file   Cliente.c
 * \brief  
 * 
 * \author João Rego
 * \date   March 2023
 *********************************************************************/

#include "Cliente.h"
#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>


 /**
  *  \brief Aloca memória para armazenar e instanciar novos "Clientes"
  *
  * \param nome
  * \param morada
  * \param saldo
  * \param nif
  * \return
  */
    
ClientePtr CriaCliente(char* nome, char* morada, double saldo, int nif) {

    ClientePtr novo_cliente = (ClientePtr)malloc(sizeof(Cliente));
    if (novo_cliente == NULL) return NULL; 

    // copia os valores passados como argumentos para o novo cliente
    strcpy(novo_cliente->Nome, nome);
    strcpy(novo_cliente->Morada, morada);
    novo_cliente->Saldo = saldo;
    novo_cliente->NIF = nif;

    return novo_cliente;    
}