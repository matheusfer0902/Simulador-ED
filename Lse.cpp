#include "LSE.h"

LSE::LSE() {
	cabeca = NULL;
	nElementos = 0;
}

LSE::~LSE() {


}

bool LSE::vazia() {
	return (nElementos == 0);
}

int LSE::tamanho() {

	No *aux = cabeca;
	int cont = 0;
	while(aux != NULL){
		aux = aux->getProx();
		cont++;
	}
	return cont;
}

int LSE::elemento (int pos) {
	if (vazia())
		return -1; 


	if ((pos < 1) || (pos > tamanho()))
		return -1; 

	No *aux = cabeca;

	for (int i =1; i < pos; i++){
	    aux = aux->getProx();
	}

	return aux->getConteudo();
}

int LSE::posicao (int dado) {

	if (vazia())
		return -1;

	No *aux = cabeca;
	int cont = 1;
	while (aux != NULL) {
		if (aux->getConteudo() == dado){
			return cont;
		}

		aux = aux->getProx();
	    cont++;
	}

	return -1;
}

bool LSE::insere(int pos, int valor) {
	if ((vazia()) && (pos != 1))
		return false; 

	if ((pos <= 0) || pos > (nElementos+1))
		return false;

	if (pos == 1)
		return insereInicioLista(valor);
	else
		return insereMeioLista(pos, valor);
}

int LSE::remove(int pos) {
	if (vazia())
		return -1;

	if ((pos <= 0) || (pos > nElementos))
		return -1; 

	if (pos == 1)
		return removeInicioLista();
	else
		return removeNaLista(pos);
}

bool LSE::insereInicioLista(int valor) {

	No *novoNo = new No();

	novoNo->setConteudo(valor);

	novoNo->setProx(cabeca);
	cabeca = novoNo;
	nElementos++;
	return true;
}

bool LSE::insereMeioLista(int pos, int valor){

	No *novoNo = new No();
	novoNo->setConteudo(valor);


	No *aux = cabeca;
	for (int i =1; i < pos-1; i++){

		aux = aux->getProx();
	}

	novoNo->setProx(aux->getProx());
	aux->setProx(novoNo);

	nElementos++;
	return true;
}

int LSE::removeInicioLista(){

	No *p = cabeca;

	int valorRemovido = p->getConteudo();

	cabeca = p->getProx();
	nElementos--;

	delete p;

	return valorRemovido;
}

int LSE::removeNaLista(int pos){

	No *antecessor = cabeca;
	for(int i = 1; i < pos-1; i++) {
		antecessor = antecessor->getProx();
	}

	No *atual = antecessor->getProx();

	int valorRemovido = atual->getConteudo();

	antecessor->setProx(atual->getProx());

	nElementos--;

	delete atual;

	return valorRemovido;
}