/*essa estrutura de dados é uma alternativa a arvore AVl. Porém ambas tem suas prioridades:
  - se operação de busca é mais usada, use AVL;
  - se operação de inserção e remoção é mais usada, ultilize Rubro Negra.
*/

//
//
// mudar estrutura para nó sentinela
//
//

/*o nó externo é uma variável global, que será alocado apenas uma vez, na função
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

    if(w->dad == NULL){//caso o pai seja NULL, então w ERA a raiz
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

    if(w->dad == NULL){//caso o pai seja NULL, então w ERA a raiz
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
        //ou seja, enquanto x não for no externo (NULL)
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

    while(ptr->dad->color == "R"){ //violação da propriedade (rubro filho de rubro)
        v = ptr->pai;
        w = v->pai;

        //trocando direita por esquerda
        if(v == w->left){
            t = w->right;

            if(t->color == "R"){ //case 1
                v->color = "N";
                t->color = "N";
                w->color = "R";
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->right){ //case 2
                    ptr = v;  ///atualizando o nó problemático
                    rotationLeft(root, ptr); ///
                }
                //como o caso 3 é uma parte do caso 2, então se segue
                //case 3
                ptr->dad->color = "N";
                w->color = "R";
                rotationRight(root, ptr);
            }
        }
        //tratamento simétrico trocando esquerda por direita;
        else{
            t = w->left;

            if(t->color == "R"){ //case 1
                v->color = "N";
                t->color = "N";
                w->color = "R";
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->left){ //case 2
                    ptr = v;  ///atualizando o nó problemático
                    rotationRight(root, ptr); ///
                }
                //como o caso 3 é uma parte do caso 2, então se segue
                //case 3
                ptr->dad->color = "N";
                w->color = "R";
                rotationLeft(root, ptr);
            }
        }
    }
    root->color = "N";
}

//transfere o ponteiro do nó u para o nó v
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

//aqui teremos ponteiro para a raiz da árvore e temos o ponteiro que iremos inserir.
//ou seja, quando esse algoritmo é chamado, já entra com a o ponteiro para a chave a ser removida.
void removeRB(No* root, No *z){
    No *x, *y;
    char colorY;

    y = z;
    //deveremos saber se a remoção desse nó e sua cor, afetará a árvore.
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
        else{ //possui filho à esquerda e à direita.
            y = sucessor(z); ///

            //precisamos antes de qualquer coisa guardar a cor de y. pois, não podemos
            //comprometer as outras sub árvores do outro lado.
            colorY = y->color;
            x = y->right;
            if(y->dad == z){ //significa q y é filho a direita de z
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
    if(colorY == "N") removeFixUpRB(root, x); //correção de violação
}


//corrige qualquer violação de propriedades
void removeFixUpRB(No *root,No *x);

























