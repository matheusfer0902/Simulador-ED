#ifndef PILHA_H_
#define PILHA_H_

#include <iostream>
#include <string.h>

#define TAM_MAX 100

using namespace std;

class Pilha {

private:
	string dados[TAM_MAX];
	int topo;

public:
	Pilha();
	virtual ~Pilha();

	bool vazia();
	bool cheia();
	int tamanho();
	string top();
	bool push(string valor);
	string pop();

    string sequencia(int ordem);

};

#endif /* PILHA_H_ */