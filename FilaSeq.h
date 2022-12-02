/*
 * FilaSeq.h
 *
 *  Created on: 10 de nov. de 2022
 *      Author: Administrador
 */

#ifndef FILASEQ_H_
#define FILASEQ_H_

#define TAM_MAX 100
#include <iostream>
#include <string.h>
using namespace std;

class FilaSeq {

private:
	string dados[TAM_MAX];
	int inicio;
	int fim;
	int nElementos;

public:
	FilaSeq();
	virtual ~FilaSeq();

	bool vazia();
	bool cheia();
	int tamanho();
	string primeiro();
	bool insere(string nome);
	string remove();
	
	string sequencia(int ordem);
};

#endif /* FILASEQ_H_ */
