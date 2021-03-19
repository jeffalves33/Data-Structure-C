#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int chave;
    int bal;
    struct node *left, *right;
}No;

void insertAVL(No **root, int *h, int x);
No *createNO(int x);
void caso1(No **root);
void caso2(No **root);

int main(void){
    int *h = (int*)malloc(sizeof(int));
    *h = 0; //true
    No *root = NULL;
    insertAVL(&root, h, 50);
    printf("\nadd: %d", root->chave);

    insertAVL(&root, h, 60);
    printf("\nadd: %d", root->right->chave);

    insertAVL(&root, h, 40);
    printf("\nadd: %d", root->left->chave);

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

void insertAVL(No **root, int *h, int x){
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
            if(*h == 0){
                switch((*root)->bal){
                    case -1:
                        (*root)->bal = 0;
                        break;
                    case 0:
                        (*root)->bal = 1;
                        break;
                    case 1:
                        caso1(root);
                        *h = 1;
                        break;
                }
            }
        }

        //caminho à direita (right patch)
        else{
            insertAVL(&(*root)->right, h, x);

            //considerações de balanceamento
            if(*h == 0){
                switch((*root)->bal){
                    case 1:
                        (*root)->bal = 0;
                        *h = 1;
                        break;
                    case 0:
                        (*root)->bal = -1;
                        break;
                    case -1:
                        caso2(root);
                        *h = 1;
                        break;
                }
            }
        }
    }

}

void caso1(No **root){
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

    //zerando o bal de u
    (*root)->bal = 0;
}

void caso2(No **root){
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
}




























































































