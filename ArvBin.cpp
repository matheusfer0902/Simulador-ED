

#include <iostream>
#include <stdlib.h>
using namespace std;

struct NO {
    int item;
    NO *esq;
    NO *dir;
};

class Tree {
  private: NO *root; // raiz

  public: Tree() { root = NULL; } // inicializa arvore

  public: void inserir(int v) {
    NO *novo = new NO(); // cria um novo Nó
    novo->item = v; // atribui o valor recebido ao item de dados do Nó
    novo->dir = NULL;
    novo->esq = NULL;
    if (root == NULL) root = novo;
    else  { // se nao for a raiz
      NO *atual = root;
      NO *anterior;
      while(true) {
        anterior = atual;
        if (v <= atual->item) { // ir para esquerda
          atual = atual->esq;
          if (atual == NULL) {
            anterior->esq = novo;
            return;
          } 
        }  // fim da condição ir a esquerda
        else { // ir para direita
           atual = atual->dir;
           if (atual == NULL) {
             anterior->dir = novo;
             return;
           }
        } // fim da condição ir a direita
      } // fim do laço while
    } // fim do else não raiz

  }

  public: NO *buscar(int chave) {
    if (root == NULL) return NULL; // se arvore vazia
    NO *atual = root;  // começa a procurar desde raiz
    while (atual->item != chave) { // enquanto nao encontrou
      if(chave < atual->item ) atual = atual->esq; // caminha para esquerda
      else atual = atual->dir; // caminha para direita
      if (atual == NULL) return NULL; // encontrou uma folha -> sai
    } // fim laço while
    return atual; // terminou o laço while e chegou aqui é pq encontrou item
  }
  
  public: NO* get_raiz()
  {
    return root;
  }

  public: bool remover(int v) {
    if (root == NULL) return false; // se arvore vazia
    NO *atual = root;
    NO *pai = root;
    bool filho_esq = true;
    // ****** Buscando o valor **********
    while (atual->item != v) { // enquanto nao encontrou
      pai = atual;
      if(v < atual->item ) { // caminha para esquerda
        atual = atual->esq;
        filho_esq = true; // é filho a esquerda? sim
      }
      else { // caminha para direita
        atual = atual->dir; 
        filho_esq = false; // é filho a esquerda? NAO
      }
      if (atual == NULL) return false; // encontrou uma folha -> sai
    } // fim laço while de busca do valor

    // **************************************************************
    // se chegou aqui quer dizer que encontrou o valor (v)
    // "atual": contem a referencia ao No a ser eliminado
    // "pai": contem a referencia para o pai do No a ser eliminado
    // "filho_esq": é verdadeiro se atual é filho a esquerda do pai
    // **************************************************************

    // Se nao possui nenhum filho (é uma folha), elimine-o
    if (atual->esq == NULL && atual->dir == NULL) {
      if (atual == root ) root = NULL; // se raiz
      else if (filho_esq) pai->esq = NULL; // se for filho a esquerda do pai
           else pai->dir = NULL; // se for filho a direita do pai
    }

    // Se é pai e nao possui um filho a direita, substitui pela subarvore a direita
    else if (atual->dir == NULL) {
       if (atual == root) root = atual->esq; // se raiz
       else if (filho_esq) pai->esq = atual->esq; // se for filho a esquerda do pai
            else pai->dir = atual->esq; // se for filho a direita do pai
    }
    
    // Se é pai e nao possui um filho a esquerda, substitui pela subarvore a esquerda
    else if (atual->esq == NULL) {
       if (atual == root) root = atual->dir; // se raiz
       else if (filho_esq) pai->esq = atual->dir; // se for filho a esquerda do pai
            else pai->dir = atual->dir; // se for  filho a direita do pai
    }

    // Se possui mais de um filho, se for um avô ou outro grau maior de parentesco
    else {
      NO *sucessor = no_sucessor(atual);
      // Usando sucessor que seria o Nó mais a esquerda da subarvore a direita do No que deseja-se remover
      if (atual == root) root = sucessor; // se raiz
      else if(filho_esq) pai->esq = sucessor; // se for filho a esquerda do pai
           else pai->dir = sucessor; // se for filho a direita do pai
      sucessor->esq = atual->esq; // acertando o ponteiro a esquerda do sucessor agora que ele assumiu 
                                // a posição correta na arvore   
    }

    return true;
  }
  
  // O sucessor é o Nó mais a esquerda da subarvore a direita do No que foi passado como parametro do metodo
  private: NO *no_sucessor(NO *apaga) { // O parametro é a referencia para o No que deseja-se apagar
     NO *paidosucessor = apaga;
     NO *sucessor = apaga;
     NO *atual = apaga->dir; // vai para a subarvore a direita

     while (atual != NULL) { // enquanto nao chegar no Nó mais a esquerda
       paidosucessor = sucessor;
       sucessor = atual;
       atual = atual->esq; // caminha para a esquerda
     } 
     // *********************************************************************************
     // quando sair do while "sucessor" será o Nó mais a esquerda da subarvore a direita
     // "paidosucessor" será o o pai de sucessor e "apaga" o Nó que deverá ser eliminado
     // *********************************************************************************
     if (sucessor != apaga->dir) { // se sucessor nao é o filho a direita do Nó que deverá ser eliminado
       paidosucessor->esq = sucessor->dir; // pai herda os filhos do sucessor que sempre serão a direita
       // lembrando que o sucessor nunca poderá ter filhos a esquerda, pois, ele sempre será o
       // Nó mais a esquerda da subarvore a direita do Nó apaga.
       // lembrando também que sucessor sempre será o filho a esquerda do pai

       sucessor->dir = apaga->dir; // guardando a referencia a direita do sucessor para 
                                 // quando ele assumir a posição correta na arvore
     }
     return sucessor;
  }
  
  public: void caminhar() {
    cout << "\n\n Exibindo em ordem: ";
    inOrder(root);
    cout << "\n Exibindo em pos-ordem: ";
    posOrder(root);
    cout << "\n Exibindo em pre-ordem: ";
    preOrder(root);
    cout << "\n Altura da arvore: " << altura(root);
    cout << "\n Quantidade de folhas: " << folhas(root);
    cout << "\n Quantidade de Nos: " << contarNos(root);
    if (root != NULL ) {  // se arvore nao esta vazia
       cout << "\n Valor minimo: " << min();
       cout << "\n Valor maximo: " << max() << endl;
    }
  }

  private: void inOrder(NO *atual) {
    if (atual != NULL) {
      inOrder(atual->esq);
      cout << atual->item << " ";
      inOrder(atual->dir);
    }
  }

  private: int altura(NO *atual) {
     if(atual == NULL || (atual->esq == NULL && atual->dir == NULL))
       return 0;
     else {
   	if (altura(atual->esq) > altura(atual->dir))
   	   return ( 1 + altura(atual->esq) );
   	else
	   return ( 1 + altura(atual->dir) );
     }
  }
  
  private: int folhas(NO *atual) {
    if(atual == NULL) return 0;
    if(atual->esq == NULL && atual->dir == NULL) return 1;
    return folhas(atual->esq) + folhas(atual->dir);
  }
  
  private: int contarNos(NO *atual) {
   if(atual == NULL)  return 0;
   else return ( 1 + contarNos(atual->esq) + contarNos(atual->dir));
  }
  
  private: void posOrder(NO *atual) {
    if (atual != NULL) {
      posOrder(atual->esq);
      posOrder(atual->dir);
      cout << atual->item << " ";
    }
  }
  
  private: void preOrder(NO *atual) {
    if (atual != NULL) {
      cout << atual->item << " ";
      preOrder(atual->esq);
      preOrder(atual->dir);
    }
  }

  public: int min() {
    NO *atual = root;
    NO *anterior = NULL;
    while (atual != NULL) {
      anterior = atual;
      atual = atual->esq;
    }
    return anterior->item;
  }

  public: int max() {
    NO *atual = root;
    NO *anterior = NULL;
    while (atual != NULL) {
      anterior = atual;
      atual = atual->dir;
    }
    return anterior->item;
  }

};

void Exibe_arvore(Tree arv)
{
  int rep = 1, op;
  NO* atual;
  atual = arv.get_raiz();

  if (atual == nullptr){
    cout << "insira algo primeiro!" << endl;
    return;
  }

  cout << "raiz: " << atual->item << "\n";
  while (1)
  {
    for (int j = 0; j < rep; j++)  //identação
      cout << "   ";
    cout << "esquerda: " << atual->esq->item << "\n";

    for (int j = 0; j < rep; j++)  //identação
      cout << "   ";
    cout << "direita: " << atual->dir->item << "\n";
    
    cout << "\n esquerda(1), direita(2), sair(3): ";
    cin >> op;

    if (op == 1)
    {
      atual = atual->esq;
    }else if (op == 2)
    {
      atual = atual ->dir;
    }else
      return;

    if (atual == nullptr){
      cout << "Final!" << endl;
      return;
    }
    rep ++;
  }

}
////////////////////////////////////////////////
void Arvore() {
    Tree arv;
    int opcao, x;
    do {
      cout << "\nEntre com a opcao (int):";
		  cout << "\n 1: Inserir";
		  cout << "\n 2: Excluir";
		  cout << "\n 3: Exibir";
		  cout << "\n 4: Sair";
		  cout << "\n-> ";
		  cin >> opcao;
      
		switch(opcao) {
	 		case 1: {
		    cout << "\n Informe o valor (int) -> ";
		    cin >> x;
		    arv.inserir(x);
		    break;
			}
			case 2: {
		    cout << "\n Informe o valor (int) -> ";
		    cin >> x;
		    if ( !arv.remover(x) )
          cout << "\n Valor nao encontrado!"; 
		    break;
			}
			case 3: {
		    Exibe_arvore(arv);
        break;
			}
      case 4: 
        return;
    } 
    } while(1);
}