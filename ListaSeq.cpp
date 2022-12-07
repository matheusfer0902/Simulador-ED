#include "ListaSeq.h"

ListaSeq::ListaSeq()
{
    nElementos = 0;
}

ListaSeq::~ListaSeq()
{

}

bool ListaSeq::vazia(){
    return (nElementos == 0) ? true : false;
}

bool ListaSeq::cheia(){
    return (nElementos == MAX) ? true : false;
}

int ListaSeq::tamanho(){
    return nElementos;
}

std::string ListaSeq::elemento(int pos){
    if ((pos > nElementos) || (pos <= 0)){
        return "-1";
    }

    return nomes[pos-1];
}

std::string ListaSeq::posicao (std::string nome){
    for (int i = 0; i < nElementos; i++){
		if (nomes[i].compare(nome) == 0){
			return nomes[i+1];
		}
	}
	return "-1";
}

std::string ListaSeq::posicao (std::string nome, int desloc){
    for (int i = desloc; i < nElementos; i++){
		    if (nomes[i].compare(nome) == 0){
		        return nomes[i+1];
		    }
		}
		return "-1";
}

bool ListaSeq::insere (int pos, std::string nome){
    if (cheia() || (pos > nElementos+1) || (pos <=0)){
		return false;
	}

    for (int i = nElementos; i >= pos; i--){
		nomes[i] = nomes[i-1];
	}

    nomes[pos - 1] = nome;

    nElementos++;
	return true;
}

std::string ListaSeq::remove(int pos){
    if ((pos > nElementos) || (pos < 1 ))
		return "-1";

    std::string aux = nomes[pos-1];

    for (int i = pos - 1; i < nElementos - 1; i++){
		nomes[i] = nomes[i+1];
	}

    nElementos--;
	return aux;
}

std::string ListaSeq::sequencia(int ordem)
{
	if(ordem <= nElementos && ordem >= 0)
		return nomes[ordem];
	else
		return NULL;
}