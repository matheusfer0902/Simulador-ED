#include <iostream>
#include <string.h>
#include <ios>
#include <limits>
#include <cctype>
#include <cstring>
#include <algorithm>

#include "Lse.cpp"
#include "Lse.h"
#include "No.cpp"
#include "No.h"
#include "FilaSeq.h" 
#include "FilaSeq.cpp"
#include "Pilha.h"
#include "Pilha.cpp"
#include "ListaSeq.h"
#include "ListaSeq.cpp"

using namespace std;

void Clear()    // limpa a tela do prompt de comando de acordo com o sistema operacional
{
#if defined _WIN32
    system("cls");
    //clrscr(); // conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //ANSI
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Exibe_fila(FilaSeq *fila)
{
    cout << "_____________________________________________________________________________________\n";
    if(!fila->vazia()){
        cout << fila->sequencia(0);
        for (size_t i = 1; i < fila->tamanho(); i++)
        {
            cout << " | " << fila->sequencia(i);
        }
    }
    cout << "\n_____________________________________________________________________________________\n\n";
}

void Fila()
{
    FilaSeq fila;
    unsigned short control;
    string nom;

    do
    {  
        Exibe_fila(&fila);

        cout << "Insere(1), remove(2), sair(0): ";
        cin >> control;

        switch (control)
        {
        case 1:
            cout << "Nome: ";
            cin >> nom;     //!bug com nomes compostos

            fila.insere(nom);
            break;

        case 2:
            fila.remove();
            break;

        case 0:
            //sair
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        Clear();

    } while (control);
}

void Exibe_Pilha(Pilha *pilha)
{
    cout << "\n_____________________________________________________________________________________\n";
    if(!pilha->vazia()){
        cout << pilha->sequencia(0);
        for (size_t i = 1; i < pilha->tamanho(); i++)
        {
            cout << "\n\n" << pilha->sequencia(i);
        }
    }
    cout << "\n_____________________________________________________________________________________\n\n";
}

void Func_Pilha(){
    Pilha pilha;
    unsigned short op;
    string valor;
    string topo;

    do
    {  
        Exibe_Pilha(&pilha);

        cout << "Push(1), Pop(2), Topo(3), sair(0): ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Que valor deseja inserir? ";
            cin >> valor;     

            pilha.push(valor);
            topo = pilha.top();
            break;

        case 2:
            pilha.pop();
            topo = pilha.top();
            break;

        case 3:
            cout << "O topo da pilha é: " << topo;
            break;

        case 0:
            //sair
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        Clear();

    } while (op);
}

void exibe_listaSeq(ListaSeq listaSeq) // Arrumar  a axibição
{
    cout << "_____________________________________________________________________________________\n";
    if(!listaSeq.vazia()){
        for (size_t i = 1; i < 11; i++)
        {
            if(listaSeq.elemento(i).compare("-1") != 0){
                cout << i << "- " << listaSeq.elemento(i) << endl;
            } else {
                cout << i << "- " << endl;
            }
        }
    }
    cout << "_____________________________________________________________________________________\n\n";
}

int func_listaSeq(){
    ListaSeq listaSeq;
    int control;
    string nome;

    do
    {  
        exibe_listaSeq(listaSeq);

        cout << "Digite os valores correspondentes das operacoes: " << endl;
        cout << "Insere(1), remove(2), consutar(3), sair(0): ";
        cin >> control;

        if(control != 1 && control != 2 && control != 3 && control != 0){
            return -1;
        }

        switch (control)
        {
        case 1:
            {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(listaSeq.cheia()){
                    cout << "Impossivel inserir novo nome, A lista esta cheia." << endl;
                    break;
                }
                int pos;
                cout << "Digite um nome para inserir na lista: ";
                getline(cin, nome);

                transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

                cout << "Digite uma posicao para inserir: ";
                cin >> pos;

                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                // arrumar o feedback, sendo apagado pelo clear

                if(listaSeq.insere(pos, nome)){
                    cout << "Nome inserido com sucesso!" << endl;
                } else {
                    cout << "Erro ao inserir nome" << endl;
                }

                break;
            }
        case 2:
            {
                if(listaSeq.vazia()){
                    cout << "Impossivel remover nomes, A lista esta vazia." << endl;
                    break;
                }

                int pos;

                cout << "Digite uma posicao para remover: ";
                cin >> pos;

                listaSeq.remove(pos);

                break;
            }
        
        case 3:
            {
                int c = 0;
                if(listaSeq.vazia()){
                    cout << "Impossivel buscar nomes, A lista esta vazia." << endl;
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                cout << "Digite um nome para buscar na lista: ";
                getline(cin, nome);

                transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

                if(listaSeq.posicao(nome).compare("-1") != 0){
                    cout << "Nome (" << listaSeq.posicao(nome) << ") encontrado na posicao " << listaSeq.indice(nome) << endl; 
                } else {
                    cout << "Nome nao encontrado." << endl;
                }
            }

        case 0:
            //sair
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        // Clear();

    } while (control);
}
void Exibe_LSE(LSE *lse)
{   

    cout << "\n_____________________________________________________________________________________\n";
    if(!lse->vazia()){
        for (int i = 1; i <= lse->tamanho(); i++){
    	cout << "\n\n" <<  lse->elemento(i);
        }
    }

    cout << "\n_____________________________________________________________________________________\n\n";
}

void Lse()
{
    LSE lse;
    unsigned short op;
    int valor;
    int pos;

    do
    {  
        Exibe_LSE(&lse);

        cout << "Insere(1), remove(2), sair(0): ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Valor: ";
            cin >> valor;
            cout << "Posicao: ";
            cin >> pos;

            lse.insere(pos, valor);
            break;
            
        case 2:
            cout << "Qual posicao voce deseja remover: ";
            cin >> pos;

            lse.remove(pos);
            break;

        case 0:
            break;

        default:
            cout << "Opcao invalida!\n";
            break;
        }
        Clear();

    } while (op);
}

void Exibe_menu(){
    cout << "-- BEM VINDO -- \n"
    "0 - Simular listas simplesmente encadeadas (LSE) \n"
    "1 - Simular lista sequencial (LSeq) \n"
    "2 - Simular pilhas (LIFO) \n"
    "3 - Simular filas (FIFO) \n"
    "4 - Simular arvores binarias \n"
    "5 - Sair" << endl;
}

void Menu(int op){

    switch (op){
    case 0:
        Lse();
        break;
    
    case 1:
        {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            int op2 = 0;
            cin >> op2;
            op2 = op2 - 1;
            if(op2){
                func_listaSeq(); 
            } else {

            }
            break;
        }
    case 2:
        Func_Pilha();
        break;

    case 3:
        Fila();
        break;

    case 4:
        
        break;
    
    case 5:
        //sair
        break;

    default:
        //erro
        break;
    }
}

int main(){
    int op = 0;

    do{
        Exibe_menu();
        cin >> op;
        Menu(op);
    } while (op != 5);

    return 0;
}
