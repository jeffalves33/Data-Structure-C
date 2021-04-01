/*essa estrutura de dados � uma alternativa a arvore AVl. Por�m ambas tem suas prioridades:
  - se opera��o de busca � mais usada, use AVL;
  - se opera��o de inser��o e remo��o � mais usada, ultilize Rubro Negra.
*/

//
//
// mudar estrutura para n� sentinela
//
//

/*o n� externo � uma vari�vel global, que ser� alocado apenas uma vez, na fun��o
principal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    char color; //diz respeito a cor da chave
    struct node *left, *right, *dad;
}No;

void insertRB(No **root, No *ptr);    ///ponteiro para ponteiro?
void insertAuxRB(No *root, No *ptr);  ///ponteiro para ponteiro?
void rotationLeft(No *root, No *w);   ///T deve ser ponteiro para ponteiro?
void rotationRight(No *root, No *w);  ///T deve ser ponteiro para ponteiro?

int main(void){

    return 0;
}


void rotationLeft(No *root, No *w){
    No *v = w->right;
    w->right = v->left;

    if(v->left != NULL){ //caso n seja NULL, deve mudar o apontamento do pai
        v->left->dad = w;
    }

    v->dad = w->dad;

    if(w->dad == NULL){//caso o pai seja NULL, ent�o w ERA a raiz
        root = v;
    }
    else{
        if(w == w->dad->left){//caso w seja filho a esquerda do pai dele
            w->dad->left = v;
        }
        else{
            w->dad->right = v;
        }
    }
    v->left = w;
    w->dad = v;
}

void rotationRight(No *root, No *w){
    No *v = w->left;
    w->left = v->right;

    if(v->right != NULL){ //caso n seja NULL, deve mudar o apontamento do pai
        v->right->dad = w;
    }

    v->dad = w->dad;

    if(w->dad == NULL){//caso o pai seja NULL, ent�o w ERA a raiz
        root = v;
    }
    else{
        if(w == w->dad->right){//caso w seja filho a direita do pai dele
            w->dad->right = v;
        }
        else{
            w->dad->left = v;
        }
    }
    v->right = w;
    w->dad = v;
}

void insertRB(No **root, No *ptr){
    No *v = NULL;
    No *x = *root;///

    while(x != NULL){
        if(x->chave == ptr->chave){
            printf("\nError: chave existe.");
        }
        //ou seja, enquanto x n�o for no externo (NULL)
        v = x;
        if(ptr->chave < x->chave) x = x->left;
        else x = x->right;
    }

    ptr->pai = v;

    //ou seja, se a arvore root passada for NULA
    if(v == NULL) *root = ptr;
    else{
        if(ptr->chave < v->chave) v->left = ptr;
        else v->right = ptr;
    }
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->color = "R"; //Rubro
    insertAuxRB(root, ptr);
}

void insertAuxRB(No *root, No *ptr){
    No *v, *w, *t;

    while(ptr->dad->color == "R"){ //viola��o da propriedade (rubro filho de rubro)
        v = ptr->pai;
        w = v->pai;

        //trocando direita por esquerda
        if(v == w->left){
            t = w->right;

            if(t->color == "R"){ //case 1
                v->color = "N";
                t->color = "N";
                w->color = "R";
                ptr = w; ///atualizando o n� problem�tico
            }
            else{
                if(ptr == v->right){ //case 2
                    ptr = v;  ///atualizando o n� problem�tico
                    rotationLeft(root, ptr); ///
                }
                //como o caso 3 � uma parte do caso 2, ent�o se segue
                //case 3
                ptr->dad->color = "N";
                w->color = "R";
                rotationRight(root, ptr);
            }
        }
        //tratamento sim�trico trocando esquerda por direita;
        else{
            t = w->left;

            if(t->color == "R"){ //case 1
                v->color = "N";
                t->color = "N";
                w->color = "R";
                ptr = w; ///atualizando o n� problem�tico
            }
            else{
                if(ptr == v->left){ //case 2
                    ptr = v;  ///atualizando o n� problem�tico
                    rotationRight(root, ptr); ///
                }
                //como o caso 3 � uma parte do caso 2, ent�o se segue
                //case 3
                ptr->dad->color = "N";
                w->color = "R";
                rotationLeft(root, ptr);
            }
        }
    }
    root->color = "N";
}

//transfere o ponteiro do n� u para o n� v
void transferePaiRB(No *root, No *u, No *v){
    if(u->dad == NULL){
        root = v;
    }
    else{
        if(u == u->dad->left){
            u->dad->left = v;
        }
        else{
            u->dad->right = v;
        }
    }
    v->dad = u->dad;
}

//aqui teremos ponteiro para a raiz da �rvore e temos o ponteiro que iremos inserir.
//ou seja, quando esse algoritmo � chamado, j� entra com a o ponteiro para a chave a ser removida.
void removeRB(No* root, No *z){
    No *x, *y;
    char colorY;

    y = z;
    //deveremos saber se a remo��o desse n� e sua cor, afetar� a �rvore.
    colorY = y->color;

    if(z->left == NULL){
        x = z->right;
        transferePaiRB(root, z, z->right);
    }
    else{
        if(z->right == NULL){
            x = z->left;
            transferePaiRB(root, z, z->left);
        }
        else{ //possui filho � esquerda e � direita.
            y = sucessor(z); ///

            //precisamos antes de qualquer coisa guardar a cor de y. pois, n�o podemos
            //comprometer as outras sub �rvores do outro lado.
            colorY = y->color;
            x = y->right;
            if(y->dad == z){ //significa q y � filho a direita de z
                x->dad = y;
            }
            else{
                transferePaiRB(root, y, y->right);
                y->right = z->right;
                y->right->dad = y;
            }
            transferePaiRB(root, z, y);
            y->left = z->left;
            y->left->dad = y;
            y->color = z->color;
        }
    }
    if(colorY == "N") removeFixUpRB(root, x); //corre��o de viola��o
}


//corrige qualquer viola��o de propriedades
void removeFixUpRB(No *root,No *x);

























