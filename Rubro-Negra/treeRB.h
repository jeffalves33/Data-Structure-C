//Author: Jeferson Luiz Alves de Souza
#ifndef TREERB_H_INCLUDED
#define TREERB_H_INCLUDED

//Definições das cores possíveis da árvore e seu sentinela.
#define RUBRO 0
#define NEGRO 1
#define SENTINEL -1

//Estrutura de um Artigo
typedef struct artigo{
    int id;
    int ano;
    char autor[200];
    char titulo[200];
    char revista[200];
    char DOI[200];
    char palavraChave[200];
    int color;
    struct artigo *left, *right, *dad;
}Artigo;

/*    funcao     : Artigo *createSentinel()
   *  acao       : cria o nó sentinela da árvore
   *  entrada    : void
   *  saida      : ponteiro para um Artigo.
*/
Artigo *createSentinel();

/*    funcao     : Artigo *createArtigo(int id, Artigo *sent)
   *  acao       : cria o nó da árvore
   *  entrada    : identificador para criar o nó e o nó sentinela
   *  saida      : ponteiro para um Artigo.
*/
Artigo *createArtigo(int id, Artigo *sent);

/*    funcao     : Artigo *searchArtigo(Artigo *mainArtigo, int key, Artigo *sent, int n)
   *  acao       : procura um nó da árvore
   *  entrada    : a árvore, chave a ser procurada, nó sentinela e um identificador
   *  saida      : ponteiro para um Artigo
*/
Artigo *searchArtigo(Artigo *mainArtigo, int key, Artigo *sent, int n);

/*    funcao     : void insertRB(Artigo **mainArtigo, int id, Artigo *sent)
   *  acao       : insere um nó na árvore
   *  entrada    : a árvore, identificador e o sentinela
   *  saida      : void
*/
void insertRB(Artigo **mainArtigo, int id, Artigo *sent);

/*    funcao     : void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent)
   *  acao       : auxilia a função de inserção com reorganização dos apontamentos
   *  entrada    : a árvore, nó problemático e o sentinela
   *  saida      : void
*/
void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent);

/*    funcao     : void removeRB(Artigo **mainArtigo, Artigo *z, Artigo *sent)
   *  acao       : remove um nó da árvore
   *  entrada    : a árvore, o nó a ser removido e o sentinela
   *  saida      : void
*/
void removeRB(Artigo **mainArtigo, Artigo *z, Artigo *sent);

/*    funcao     : void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent)
   *  acao       : auxilia a função de remoção com reorganização dos apontamentos
   *  entrada    : a árvore, nó problemático e o sentinela
   *  saida      : void
*/
void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent);

/*    funcao     : void transferedadRB(Artigo **mainArtigo, Artigo *z, Artigo *y, Artigo *sent)
   *  acao       : refaz alguns apontamentos
   *  entrada    : a árvore, 2 artigos problemáticos e o sentinela
   *  saida      : void
*/
void transferedadRB(Artigo **mainArtigo, Artigo *z, Artigo *y, Artigo *sent);

/*    funcao     : void rotationLeft(Artigo **mainArtigo, Artigo *w, Artigo *sent)
   *  acao       : realiza a rotação a esquerda do nó problemático
   *  entrada    : a árvore, nó problemático e o sentinela
   *  saida      : void
*/
void rotationLeft(Artigo **mainArtigo, Artigo *w, Artigo *sent);

/*    funcao     : void rotationRight(Artigo **mainArtigo, Artigo *w, Artigo *sent)
   *  acao       : realiza a rotação a direita do nó problemático
   *  entrada    : a árvore, nó problemático e o sentinela
   *  saida      : void
*/
void rotationRight(Artigo **mainArtigo, Artigo *w, Artigo *sent);

/*    funcao     : Artigo *sucessor(Artigo *x, Artigo *sent)
   *  acao       : retorna o sucessor do nó passado como parâmetro
   *  entrada    : o nó a ser trabalhado e o sentinela
   *  saida      : um ponteiro para o sucessor do nó passado
*/
Artigo *sucessor(Artigo *x, Artigo *sent);

/*    funcao     : void printRB(Artigo *mainArtigo, int nivel, Artigo *sent)
   *  acao       : pronta a árvore com tabulação necessária
   *  entrada    : a árvore, o nível a começar a exibição e o sentinela
   *  saida      : void
*/
void printRB(Artigo *mainArtigo, int nivel, Artigo *sent);

#endif // TREERB_H_INCLUDED
