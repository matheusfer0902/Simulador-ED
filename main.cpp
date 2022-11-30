#include <iostream>
#include <string.h>

using namespace std;

void menu(){
    cout << "-- BEM VINDO -- \n"
    "1 - Simular listas \n"
    "2 - Simular arvores \n"
    "3 - Simular grafos \n"
    "4 - Sair" << endl;
}

void listas_menu(){
    int op = 0;

    cout << "-- ESCOLHA O TIPO DE LISTA -- \n"
    "1 - Listas simplesmente encadeadas. (LSE) \n"
    "2 - Listas duplamente encadeadas. (LDE) \n"
    "3 - Listas circulares. \n"
    "4 - Pilhas \n"
    "5 - Filas \n"
    "6 - Voltar" << endl;

    cin >> op;

    switch (op){
    case 1:
        
        break;

    case 2:

        break;

    case 3:

        break;

    case 4:
        
        break;

    case 5:
        
        break;

    case 6:
        
        break;

    default:
        //erro
        break;
    }
}

int main(){
    int op = 0;

    do{
        menu();
        cin >> op;
        switch (op){
            case 1:
                listas_menu();
                break;
            
            default:
                break;
        }
    } while (op != 4);

    return 0;
}