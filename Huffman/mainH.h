//Author: Jeferson Luiz Alves de Souza
#ifndef MAINH_H_INCLUDED
#define MAINH_H_INCLUDED


typedef struct x{
    bool checker;
    int freq;
    char *chave;
    struct x *left, *right;
}Tree;

typedef struct y{
    Tree *ptr;
    struct y *next;
}List;

/*    funcao     : createTree().
   *  acao       : cria uma árvore.
   *  entrada    : void.
   *  saida      : ponteiro Tree. */
Tree *createTree();

/*    funcao     : createListSort().
   *  acao       : cria uma lista encadeada.
   *  entrada    : void.
   *  saida      : ponteiro para List. */
List *createlistMainSort();

/*    funcao     : sizeList(List *listMain).
   *  acao       : retorna o tamanho de uma lista.
   *  entrada    : ponteiro para a lista.
   *  saida      : tamanho int. */
int sizelistMain(List *listMainMain);

/*    funcao     : newNodeTree(int freq, char *chave).
   *  acao       : cria um novo nó para a árvore.
   *  entrada    : frequencia(inteiro) e a chave(string).
   *  saida      : ponteiro para um nó Tree. */
Tree *newNodeTree(int freq, char *chave);

/*    funcao     : returnMin(List **List).
   *  acao       : retorna o menor elemento de uma lista.
   *  entrada    : ponteiro de ponteiro para a lista.
   *  saida      : um nó da arvore. */
Tree *returnMin(List **listMain);

/*    funcao     : insertList(List **List, Tree *z).
   *  acao       : insere um nó (cabeça de arvore) na lista.
   *  entrada    : ponteiro de ponteiro para a lista, e um nó da arvore.
   *  saida      : void. */
void insertlistMain(List **listMain, Tree *z);

/*    funcao     : newNodeListMain(Tree *z).
   *  acao       : cria um novo nó da lista.
   *  entrada    : um nó da árvore a ser apontado.
   *  saida      : um novo nó da lista apontando para o nó z. */
List *newNodelistMain(Tree *z);

/*    funcao     : printListMain(List *heapMain).
   *  acao       : printa as chaves de uma lista apontando para elementos.
   *  entrada    : uma lista de elementos.
   *  saida      : void. */
void printlistMain(List *heapMain);

/*    funcao     : printTree(Tree *tree, int nivel).
   *  acao       : printa as chaves de uma arvore. função recursiva.
   *  entrada    : ponteiro para a árvore e o nível a se iniciar.
   *  saida      : void. */
void printTree(Tree *tree, int nivel);

/*    funcao     : addWord(char *p, List **list).
   *  acao       : adiciona uma palavra ao arquivo.
   *  entrada    : um ponteiro para string e um ponteiro de ponteiro para a lista.
   *  saida      : void. */
void addWord(char *p, List **listMain);

/*    funcao     : orderListMain(List **list).
   *  acao       : função que ordena a lista.
   *  entrada    : ponteiro de ponteiro para a lista.
   *  saida      : ponteiro para a cabeça da lista. */

List *orderlistMain(List **listMain);

/*    funcao     : ifExitInList(char *p, List *list).
   *  acao       : verifica se existe na lista uma string.
   *  entrada    : um ponteiro para a string e um ponteiro para a cabeça da lista.
   *  saida      : ponteiro para a cabeça da lista. */
List *ifExitInlistMain(char *p, List *listMain);

/*    funcao     : decodificaArchive(FILE *entryArchive, FILE *exitArchive, Tree *tree).
   *  acao       : transforma um arquivo(codificado) em um outro arquivo (decodificado).
   *  entrada    : ponteiro para arquivo de entrada, ponteiro para arquivo de saída e ponteiro para a arvore.
   *  saida      : void. */
void decodificaArchive(Tree *tree);

/*    funcao     : cleanString(char *x, int size).
   *  acao       : função que zera todos os caracteres de uma string.
   *  entrada    : ponteiro para string e um inteiro dizendo o tamanho da string.
   *  saida      : void. */
void cleanString(char *x, int size);

/*    funcao     : codificaArchive(Tree *tree).
   *  acao       : função gera um arquivo codificado.
   *  entrada    : ponteiro para o início da árvore.
   *  saida      : void. */
void codificaArchive(Tree *tree);

/*    funcao     : addExitArchive(char *p, FILE *exiteArchive, Tree *tree).
   *  acao       : função adiciona uma string ao final de um arquivo.
   *  entrada    : ponteiro para string, ponteiro para arquivo e um ponteiro para a árvore.
   *  saida      : void. */
void addExitArchive(char *p, FILE *exiteArchive, Tree *tree);

/*    funcao     : marcaLeaf(char *p, Tree *tree).
   *  acao       : função que marca o caminho até uma string passada por parâmetro.
   *  entrada    : ponteiro para string e um ponteiro para a árvore.
   *  saida      : void. */
void marcaLeaf(char *p, Tree *tree);

/*    funcao     : cleanString(char *p, Tree *tree).
   *  acao       : função que desmarca o caminho até uma string passada por parâmetro.
   *  entrada    : ponteiro para string e um ponteiro para a árvore.
   *  saida      : void. */
void desmarcaLeaf(char *p, Tree *tree);

#endif // MAINH_H_INCLUDED
