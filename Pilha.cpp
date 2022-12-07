#include "Pilha.h"

using namespace std;

Pilha::Pilha() {
	topo = -1;
}

Pilha::~Pilha() {
}

/** Verifica se a Pilha está vazia */
bool Pilha::vazia(){
	if (topo == -1)
		return true;
	else
		return false;
}

/**Verifica se a Pilha está cheia */
bool Pilha::cheia(){
	if (topo == (TAM_MAX -1))
		return true;
	else
		return false;
}

/**Obtém o tamanho da Pilha*/
int Pilha::tamanho(){
	return topo+1;
}

/** Consulta o elemento do topo da Pilha.
	Retorna -1 se a pilha estiver vazia,
	caso contrário retorna o valor que está no topo da pilha. */
string Pilha::top() {
	if (vazia())
		return NULL; // pilha vazia

	return dados[topo];
 }

/** Insere um elemento no topo da pilha.
	Retorna false se a pilha estiver cheia.
	Caso contrário retorna true */
bool Pilha::push(string valor) {
	 if (cheia())
		 return false;  // err: pilha cheia

	 topo++;
	 dados[topo] = valor;
	 return true;
}

/** Retira o elemento do topo da pilha.
 	 Retorna -1 se a pilha estiver vazia. */
string Pilha::pop() {
	if (vazia())
		return NULL; // Pilha vazia

	string valor = dados[topo];
 	topo--;
 	return valor;
 }

string Pilha::sequencia(int ordem)
{
	if(ordem <= topo && ordem >= 0)
		return dados[ordem];
	else
		return NULL;
}