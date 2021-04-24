//Author: Jeferson Luiz Alves de Souza
#ifndef TREERB_H_INCLUDED
#define TREERB_H_INCLUDED

//Defini��es das cores poss�veis da �rvore e seu sentinela.
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
   *  acao       : cria o n� sentinela da �rvore
   *  entrada    : void
   *  saida      : ponteiro para um Artigo.
*/
Artigo *createSentinel();

/*    funcao     : Artigo *createArtigo(int id, Artigo *sent)
   *  acao       : cria o n� da �rvore
   *  entrada    : identificador para criar o n� e o n� sentinela
   *  saida      : ponteiro para um Artigo.
*/
Artigo *createArtigo(int id, Artigo *sent);

/*    funcao     : Artigo *searchArtigo(Artigo *mainArtigo, int key, Artigo *sent, int n)
   *  acao       : procura um n� da �rvore
   *  entrada    : a �rvore, chave a ser procurada, n� sentinela e um identificador
   *  saida      : ponteiro para um Artigo
*/
Artigo *searchArtigo(Artigo *mainArtigo, int key, Artigo *sent, int n);

/*    funcao     : void insertRB(Artigo **mainArtigo, int id, Artigo *sent)
   *  acao       : insere um n� na �rvore
   *  entrada    : a �rvore, identificador e o sentinela
   *  saida      : void
*/
void insertRB(Artigo **mainArtigo, int id, Artigo *sent);

/*    funcao     : void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent)
   *  acao       : auxilia a fun��o de inser��o com reorganiza��o dos apontamentos
   *  entrada    : a �rvore, n� problem�tico e o sentinela
   *  saida      : void
*/
void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent);

/*    funcao     : void removeRB(Artigo **mainArtigo, Artigo *z, Artigo *sent)
   *  acao       : remove um n� da �rvore
   *  entrada    : a �rvore, o n� a ser removido e o sentinela
   *  saida      : void
*/
void removeRB(Artigo **mainArtigo, Artigo *z, Artigo *sent);

/*    funcao     : void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent)
   *  acao       : auxilia a fun��o de remo��o com reorganiza��o dos apontamentos
   *  entrada    : a �rvore, n� problem�tico e o sentinela
   *  saida      : void
*/
void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent);

/*    funcao     : void transferedadRB(Artigo **mainArtigo, Artigo *z, Artigo *y, Artigo *sent)
   *  acao       : refaz alguns apontamentos
   *  entrada    : a �rvore, 2 artigos problem�ticos e o sentinela
   *  saida      : void
*/
void transferedadRB(Artigo **mainArtigo, Artigo *z, Artigo *y, Artigo *sent);

/*    funcao     : void rotationLeft(Artigo **mainArtigo, Artigo *w, Artigo *sent)
   *  acao       : realiza a rota��o a esquerda do n� problem�tico
   *  entrada    : a �rvore, n� problem�tico e o sentinela
   *  saida      : void
*/
void rotationLeft(Artigo **mainArtigo, Artigo *w, Artigo *sent);

/*    funcao     : void rotationRight(Artigo **mainArtigo, Artigo *w, Artigo *sent)
   *  acao       : realiza a rota��o a direita do n� problem�tico
   *  entrada    : a �rvore, n� problem�tico e o sentinela
   *  saida      : void
*/
void rotationRight(Artigo **mainArtigo, Artigo *w, Artigo *sent);

/*    funcao     : Artigo *sucessor(Artigo *x, Artigo *sent)
   *  acao       : retorna o sucessor do n� passado como par�metro
   *  entrada    : o n� a ser trabalhado e o sentinela
   *  saida      : um ponteiro para o sucessor do n� passado
*/
Artigo *sucessor(Artigo *x, Artigo *sent);

/*    funcao     : void printRB(Artigo *mainArtigo, int nivel, Artigo *sent)
   *  acao       : pronta a �rvore com tabula��o necess�ria
   *  entrada    : a �rvore, o n�vel a come�ar a exibi��o e o sentinela
   *  saida      : void
*/
void printRB(Artigo *mainArtigo, int nivel, Artigo *sent);

#endif // TREERB_H_INCLUDED
