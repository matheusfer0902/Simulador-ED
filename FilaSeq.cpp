/*
 * FilaSeq.cpp
 *
 *  Created on: 10 de nov. de 2022
 *      Author: Administrador
 */

#include "FilaSeq.h"

FilaSeq::FilaSeq() {
	nElementos = 0;
}

FilaSeq::~FilaSeq() {
}



/** Verifica se a Fila está vazia */
bool FilaSeq::vazia() {
	return (nElementos == 0);
}

	/**Verifica se a Fila está cheia */
bool FilaSeq::cheia() {
	return (nElementos == TAM_MAX);
}

/** Obtém o tamanho da Fila */
int FilaSeq::tamanho() {
	return nElementos;
}

/** Consulta o elemento do início da fila.
 *  Retorna -1 se a fila estiver vazia. */
string FilaSeq::primeiro() {
	if (vazia())
		return NULL; // Erro: Fila vazia

	return dados[0];
}

/**Insere um elemento no fim de uma fila
	Retorna false se a fila estiver cheia, true caso contrário. */
bool FilaSeq::insere(string nome) {
	if (cheia())
		return false;
	
	dados[nElementos] = nome;
	nElementos++;
	return true;
}

/**Remove o elemento do início da fila e retorna o valor removido.
 * Retorna -1 se a fila estiver vazia.*/
string FilaSeq::remove() {
	if (vazia())
		return NULL;

	// Guarda o valor a ser removido
	//int valor = primeiro();
	string nome = dados[0];
	
	nElementos--;

	for (size_t i = 0; i < nElementos; i++)
	{
		dados[i] = dados[i+1];
	}
	return nome;
}

string FilaSeq::sequencia(int ordem)
{
	if(ordem <= nElementos && ordem >= 0)
		return dados[ordem];
	else
		return NULL;
}
