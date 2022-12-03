#include <iostream>
#include <string.h>
#include "FilaSeq.h" 
#include "FilaSeq.cpp"
#include "Pilha.h"
#include "Pilha.cpp"

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
    int valor;
    int topo;

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


void Exibe_menu(){
    cout << "-- BEM VINDO -- \n"
    "1 - Simular listas simplesmente encadeadas (LSE) \n"
    "2 - Simular pilhas (LIFO)\n"
    "3 - Simular filas (FIFO)\n"
    "4 - Simular arvores binarias \n"
    "5 - Sair" << endl;
}

void Menu(int op){

    switch (op){
    case 1:
        
        break;

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
