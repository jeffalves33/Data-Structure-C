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
   *  acao       : cria uma �rvore.
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
   *  acao       : cria um novo n� para a �rvore.
   *  entrada    : frequencia(inteiro) e a chave(string).
   *  saida      : ponteiro para um n� Tree. */
Tree *newNodeTree(int freq, char *chave);

/*    funcao     : returnMin(List **List).
   *  acao       : retorna o menor elemento de uma lista.
   *  entrada    : ponteiro de ponteiro para a lista.
   *  saida      : um n� da arvore. */
Tree *returnMin(List **listMain);

/*    funcao     : insertList(List **List, Tree *z).
   *  acao       : insere um n� (cabe�a de arvore) na lista.
   *  entrada    : ponteiro de ponteiro para a lista, e um n� da arvore.
   *  saida      : void. */
void insertlistMain(List **listMain, Tree *z);

/*    funcao     : newNodeListMain(Tree *z).
   *  acao       : cria um novo n� da lista.
   *  entrada    : um n� da �rvore a ser apontado.
   *  saida      : um novo n� da lista apontando para o n� z. */
List *newNodelistMain(Tree *z);

/*    funcao     : printListMain(List *heapMain).
   *  acao       : printa as chaves de uma lista apontando para elementos.
   *  entrada    : uma lista de elementos.
   *  saida      : void. */
void printlistMain(List *heapMain);

/*    funcao     : printTree(Tree *tree, int nivel).
   *  acao       : printa as chaves de uma arvore. fun��o recursiva.
   *  entrada    : ponteiro para a �rvore e o n�vel a se iniciar.
   *  saida      : void. */
void printTree(Tree *tree, int nivel);

/*    funcao     : addWord(char *p, List **list).
   *  acao       : adiciona uma palavra ao arquivo.
   *  entrada    : um ponteiro para string e um ponteiro de ponteiro para a lista.
   *  saida      : void. */
void addWord(char *p, List **listMain);

/*    funcao     : orderListMain(List **list).
   *  acao       : fun��o que ordena a lista.
   *  entrada    : ponteiro de ponteiro para a lista.
   *  saida      : ponteiro para a cabe�a da lista. */

List *orderlistMain(List **listMain);

/*    funcao     : ifExitInList(char *p, List *list).
   *  acao       : verifica se existe na lista uma string.
   *  entrada    : um ponteiro para a string e um ponteiro para a cabe�a da lista.
   *  saida      : ponteiro para a cabe�a da lista. */
List *ifExitInlistMain(char *p, List *listMain);

/*    funcao     : decodificaArchive(FILE *entryArchive, FILE *exitArchive, Tree *tree).
   *  acao       : transforma um arquivo(codificado) em um outro arquivo (decodificado).
   *  entrada    : ponteiro para arquivo de entrada, ponteiro para arquivo de sa�da e ponteiro para a arvore.
   *  saida      : void. */
void decodificaArchive(Tree *tree);

/*    funcao     : cleanString(char *x, int size).
   *  acao       : fun��o que zera todos os caracteres de uma string.
   *  entrada    : ponteiro para string e um inteiro dizendo o tamanho da string.
   *  saida      : void. */
void cleanString(char *x, int size);

/*    funcao     : codificaArchive(Tree *tree).
   *  acao       : fun��o gera um arquivo codificado.
   *  entrada    : ponteiro para o in�cio da �rvore.
   *  saida      : void. */
void codificaArchive(Tree *tree);

/*    funcao     : addExitArchive(char *p, FILE *exiteArchive, Tree *tree).
   *  acao       : fun��o adiciona uma string ao final de um arquivo.
   *  entrada    : ponteiro para string, ponteiro para arquivo e um ponteiro para a �rvore.
   *  saida      : void. */
void addExitArchive(char *p, FILE *exiteArchive, Tree *tree);

/*    funcao     : marcaLeaf(char *p, Tree *tree).
   *  acao       : fun��o que marca o caminho at� uma string passada por par�metro.
   *  entrada    : ponteiro para string e um ponteiro para a �rvore.
   *  saida      : void. */
void marcaLeaf(char *p, Tree *tree);

/*    funcao     : cleanString(char *p, Tree *tree).
   *  acao       : fun��o que desmarca o caminho at� uma string passada por par�metro.
   *  entrada    : ponteiro para string e um ponteiro para a �rvore.
   *  saida      : void. */
void desmarcaLeaf(char *p, Tree *tree);

#endif // MAINH_H_INCLUDED
