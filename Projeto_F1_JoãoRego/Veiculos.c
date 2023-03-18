/*****************************************************************//**
 * \file   Veiculos.c
 * \brief  Aplica��o das fun��es ligadas a Veiculos.h
 * 
 * \author Jo�o Rego
 * \date   March 2023
 *********************************************************************/

#include "Veiculos.h"
#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>


/**
 *  \brief Aloca mem�ria para armazenar e instanciar novos "Veiculos"
 * 
 * \param tipo
 * \param autonomia
 * \param codigo_postal
 * \param bateria
 * \param custo
 * \param alugado
 * \param Cliente.Nome
 * \return 
 */

Veiculos* CriaVeiculo(char* tipo, int autonomia, int codigo_postal, int bateria, double custo, bool alugado, Cliente Cliente) {
    Veiculos* novo_veiculo = (Veiculos*)malloc(sizeof(Veiculos));

    if (novo_veiculo == NULL) return NULL; //Caso n�o haja mem�ria
       

    strcpy(novo_veiculo->Tipo, tipo);
    novo_veiculo->Autonomia = autonomia;
    novo_veiculo->Codigo_Postal = codigo_postal;
    novo_veiculo->Bateria = bateria;
    novo_veiculo->Custo = custo;    
    novo_veiculo->Alugado = alugado;
	strcpy(novo_veiculo->Cliente.Nome, Cliente.Nome);
    
    return novo_veiculo;
}



/**
 *  \brief Grava todos os "Veiculos" duma lista em ficheiro bin�rio 
 *	\return 1
 */

int GravaVeiculos(VeiculosListaPtr h, char fileName[]) {
	if (h == NULL) return (-1);
	VeiculosListaPtr aux = h;

	FILE* file = fopen(fileName, "wb");

	if (file == NULL) return (-2);

	while (aux != NULL) {
		fwrite(&aux->Veiculo, sizeof(Veiculos), 1, file); 
		aux = aux->next;
	}
	fclose(file);
	return 1;
}
	


/**
 *  \brief L� dados bin�rios de um ficheiro e criar uma Lista baseada nos conteudos
 *	\return h
 */

VeiculosListaPtr LerVeiculos(char fileName[]) {

	VeiculosListaPtr h = NULL; //Pointer do Head da Lista � NULL

	FILE* file = fopen(fileName, "rb"); //Tenta abrir um ficheiro par�metro "fileName" 
	if (file == NULL) return (-2); //Caso n�o consiga returna erro "-2"

	Veiculos* aux; //Cria uma variavel "aux", com um pointer para a struct "Veiculos", que cont�m os dados lidos do ficheiro
	while (fread(&aux, 1, sizeof(Veiculos), file)) {
		h = InsereNodoLista(h, &aux);
	}
	fclose(file);
	return h;
}



/**
* \brief Introduz um novoVeiculo como head da lista caso vazia, caso contr�rio substitui o existente 
* 
* \return head
*/

VeiculosListaPtr InsereVeiculoLista(VeiculosListaPtr head, VeiculosPtr novo) {

    VeiculosListaPtr novoVeiculo = (VeiculosListaPtr)malloc(sizeof(VeiculosLista));

	//Verifica se novoVeiculo � NULL 
	if (novoVeiculo == NULL) return NULL;
	
    // Se a lista estiver vazia, novoVeiculo � a cabe�a da lista
    if (head == NULL) {
        head = novoVeiculo;
        return novoVeiculo;
    }
    else {
        // Se a lista n�o estiver vazia, head passa a apontar para novoVeiculo
        novoVeiculo->next = head;
        head = novoVeiculo;
    }

    // Retorna um ponteiro para a nova cabe�a da lista
    return head;
}



/**
 * \brief Liberta a mem�ria usada por uma lista
 */

bool DestroiLista(VeiculosListaPtr head) {

	//Se o pointer for NULL, indica que nada foi destruido
	if (head == NULL) return false; 

	VeiculosListaPtr aux; //Pointer temporario que cont�m o proximo elemento da lista
	
	//Percorre a lista, come�ando na head at� chegar ao fim
	while (head != NULL) {
		aux = head->next; 
		free(head); //Liberta a mem�ria usada por h
		head = aux; //Move o pointer head para o proximo elemento
	}
	return true;
}





