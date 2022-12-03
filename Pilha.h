/*
 * PilhaSeq.h
 *
 *  Created on: 20 de out. de 2022
 *      Author: tiagomaritan
 */

#ifndef PILHA_H_
#define PILHA_H_

#define TAM_MAX 100

using namespace std;

class Pilha {

private:
	int dados[TAM_MAX];
	int topo;

public:
	Pilha();
	virtual ~Pilha();

	bool vazia();
	bool cheia();
	int tamanho();
	int top();
	bool push(int valor);
	int pop();

    int sequencia(int ordem);

};

#endif /* PILHA_H_ */