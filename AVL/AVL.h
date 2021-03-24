#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct node {
    int chave;
    int bal;
    struct node *left, *right;
}No;

/* funcao: void insertAVL(No **root,int *h, int x)
   *  acao:        insere um elemento de informacao na arvore avl
   *  entrada:     endereco de um ponteiro para a arvore avl, um ponteiro para um elemento de marcacao, e um elemento de informacao
   *  saida:		void
*/
void insertAVL(No **root, int *h, int x);

/* funcao: No *deleteAVL(No *root,int *i, int x)
   *  acao:        eliminar um elemento de informacao da arvore, e mantem a arvore avl
   *  entrada:     ponteiro para a arvore binaria avl, um ponteiro para um elemento de marcação, e um elemento de informacao
   *  saida:       ponteiro para a arvore com o elemento de informcao deletado
*/
No *deleteAVL(No *root, int *i, int x);

/* funcao: int *auxDeleteAVL(No *root,int *i, int x)
   *  acao:        procura o menor elemento da sur árvore direita
   *  entrada:     ponteiro para a arvore binaria avl
   *  saida:       inteiro (chave procurada)
*/
int auxDeleteAVL(No *root);

/* funcao: No *createNo(int x)
   *  acao:        funcao que cria um nó
   *  entrada:     valor da chave
   *  saida:       ponteiro para um nó
*/
No *createNO(int x);

/* funcao: No *caso1(No **root)
   *  acao:        funcao que faz as comparações para saber qual rotação ultilizar
   *  entrada:     ponteiro para a arvore AVL
   *  saida:      void
*/
void caso1(No **root);

/* funcao: No *caso1(No **root)
   *  acao:        funcao que faz as comparações para saber qual rotação ultilizar
   *  entrada:     ponteiro para a arvore AVL
   *  saida:      void
*/
void caso2(No **root);

/* funcao: No searchAVL(No *root, int x)
   *  acao:        busca por um elemento de informacao na arvore avl
   *  entrada:     ponteiro para a arvore avl (avl) e um ponteiro para o elemento de informação
   *  saida:       pontiro para o no da arvore que contem o elemento de informacao buscado
				   NULL, caso contrario
*/
No *searchAVL(No *root, int x);

/* funcao: void printAVL(No *root)
   *  acao:        imprime os elementos de informacao
   *  entrada:     ponteiro para a arvore binaria avl
   *  saida:       void
   *  suposicoes:  arvore avl
*/
void printAVL(No *root);


#endif // AVL_H_INCLUDED
