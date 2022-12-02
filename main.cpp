#include <iostream>
#include <string.h>
#include "FilaSeq.h" 
#include "FilaSeq.cpp"

using namespace std;

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

    } while (control);
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
void Menu(int op){

    switch (op){
    case 1:
        
        break;

    case 2:

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
