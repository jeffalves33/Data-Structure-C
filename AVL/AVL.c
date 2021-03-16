#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int chave;
    int bal;
    struct node *left, *right;
}No;

void insertAVL(No **root, bool h, int x); ///h precisa ser ponteiro?
No *createNO(int x);
void caso1(No **root, bool h);
void caso2(No **root, bool h);

int main(void){
    No *root = NULL;
    insertAVL(&root, true, 50);
    printf("1: %d", root->chave);

    insertAVL(&root, true, 100);
    printf("\n2: %d", root->right->chave);

    insertAVL(&root, true, 25);
    printf("\n3: %d", root->left->chave);

    insertAVL(&root, true, 20);
    printf("\n4: %d", root->left->left->chave);

    insertAVL(&root, true, 10);
    printf("\n5: %d", root->left->chave);
    return 0;
}

No *createNo(int x){
    No *root = NULL;
    if(root = (No*)malloc(sizeof(No))){
        root->bal = 0;
        root->chave = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    return NULL;
}

void insertAVL(No **root, bool h, int x){
    //raiz vazia ou nó folha
    if(*root == NULL){
        *root = createNo(x);
        return;
    }
    else{
        //nó já existe
        if(x == (*root)->chave) return;

        //caminho à esquerda (left patch)
        if(x < (*root)->chave){
            insertAVL(&(*root)->left, h, x);

            //considerações de balanceamento
            if(h){
                switch((*root)->bal){
                    case -1:
                        (*root)->bal = 0;
                        h = false;
                        break;
                    case 0:
                        (*root)->bal = 1;
                        break;
                    case 1:
                        caso1(root, h);
                        break;
                }
            }
        }

        //caminho à direita (right patch)
        else{
            insertAVL(&(*root)->right, h, x);

            //considerações de balanceamento
            if(h){
                switch((*root)->bal){
                    case 1:
                        (*root)->bal = 0;
                        h = false;
                        break;
                    case 0:
                        (*root)->bal = -1;
                        break;
                    case -1:
                        caso2(root, h);
                        break;
                }
            }
        }
    }

}

void caso1(No **root, bool h){
    No *u = (*root)->left;
    No *z;

    //right rotation
    if(u->bal = 1){
        printf("\nright rotation");
        (*root)->left = u->right;
        u->right = (*root);

        /*tenho o trabalho de modificar aqui, já que ao passar o caso1 ou
        caso2 fica a cargo desssa funções modificar o balanceamento deste nó.
        por isso:*/
        (*root)->bal = 0;
        (*root) = u;
    }

    //double right rotation
    else{
        printf("\ndouble right rotation");
        z = u->right;
        u->right = z->left;
        z->left = u;
        (*root)->left = z->right;
        z->right = (*root);
        if(z->bal == 1) (*root)->bal = -1;
        else (*root)->bal = 0;
        if(z->bal == -1) u->bal = 1;
        else u->bal = 0;
        (*root) = z;
    }
    (*root)->bal = 0;
    h = false;
}

void caso2(No **root, bool h){
    No *u, *z;

    u = (*root)->right;

    //left rotation
    if(u->bal = -1){
        printf("\nleft rotation");
        (*root)->right = u->left;
        u->left = (*root);

        /*tenho o trabalho de modificar aqui, já que ao passar o caso1 ou
        caso2 fica a cargo desssa funções modificar o balanceamento deste nó.
        por isso:*/
        (*root)->bal = 0;
        (*root) = u;
    }

    //double left rotation
    else{
        printf("\ndouble left rotation");
        z = u->left;
        u->left = z->right;
        z->right = u;
        (*root)->right = z->left;
        z->left = (*root);
        if(z->bal == 1) u->bal = -1;
        else u->bal = 0;
        if(z->bal == -1) (*root)->bal = 1;
        else (*root)->bal = 0;
        (*root) = z;
    }
    (*root)->bal = 0;
    h = false;
}




























































































