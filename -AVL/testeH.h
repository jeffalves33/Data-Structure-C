#ifndef TESTEH_H_INCLUDED
#define TESTEH_H_INCLUDED

typedef struct node {
    void *chave;
    int bal;
    struct node *left, *right;
}No;

/* funcao: int comparaChave(void *chave1, void *chave2);
   *  acao:        compara se uma chave é maior, igual ou menor que outra
   *  entrada:     endereço de dois ponteiros. um da árvore e outro do elemento generico passado pelo usuário
   *  saida:	   1 se chave1 for maior
                   0 se forem iguais
                   -1 se chave2 for maior
*/
int comparaChaves(void *chave1, void *chave2);

/* funcao: void printChave(No *root);
   *  acao:        printa uma chave passada como parametro
   *  entrada:     endereco de um ponteiro para a arvore avl
   *  saida:		void
*/
void printaChave(No *root);

/* funcao: void insertAVL(No **root,int *h, int x)
   *  acao:        insere um elemento de informacao na arvore avl
   *  entrada:     endereco de um ponteiro para a arvore avl, um ponteiro para um elemento de marcacao, e um elemento de informacao
   *  saida:		void
*/
void insertAVL(No **root, int *h, void *x);

/* funcao: No *deleteAVL(No *root,int *i, int x)
   *  acao:        eliminar um elemento de informacao da arvore, e mantem a arvore avl
   *  entrada:     ponteiro para a arvore binaria avl, um ponteiro para um elemento de marcação, e um elemento de informacao
   *  saida:       ponteiro para a arvore com o elemento de informcao deletado
*/
No *deleteAVL(No *root, int *i, void *x);

/* funcao: int *auxDeleteAVL(No *root,int *i, int x)
   *  acao:        procura o menor elemento da sur árvore direita
   *  entrada:     ponteiro para a arvore binaria avl
   *  saida:       inteiro (chave procurada)
*/
void *auxDeleteAVL(No *root);

/* funcao: No *createNo(int x)
   *  acao:        funcao que cria um nó
   *  entrada:     valor da chave
   *  saida:       ponteiro para um nó
*/
No *createNO(void *x);

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
No *searchAVL(No *root, void *x);

/* funcao: void printAVL(No *root)
   *  acao:        imprime os elementos de informacao
   *  entrada:     ponteiro para a arvore binaria avl
   *  saida:       void
   *  suposicoes:  arvore avl
*/
void printAVL(No *root, int nivel);


#endif // TESTEH_H_INCLUDED
