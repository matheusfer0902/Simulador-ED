#ifndef LISTASEQ_H
#define LISTASEQ_H
#include <string>

#pragma once

#define MAX 100

class ListaSeq
{
public:
    ListaSeq();
    ~ListaSeq();

    bool vazia();
    bool cheia();
    int tamanho();
    std::string elemento(int pos);
    std::string posicao(std::string nome);
    std::string posicao(std::string nome, int desloc);
    bool insere (int pos, std::string nome);
    std::string remove(int pos);
    std::string sequencia(int ordem);

private:
    std::string nomes[MAX];
    int nElementos;

};

#endif