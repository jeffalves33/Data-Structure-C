#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"

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
        printf("\nnull");
        *root = createNo(x);
        return;
    }
    else{
        //nó já existe
        if(x == (*root)->chave){
            printf("\nja existe");
            *h = 1;
            return;
        }
        //caminho à esquerda (left patch)
        if(x < (*root)->chave){
            printf("\nleft %d", *h);
            insertAVL(&(*root)->left, h, x);

            //considerações de balanceamento
            if(*h == 0){
                switch((*root)->bal){
                    case -1:
                        (*root)->bal = 0;
                        *h = 0;
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
            printf("\nright");
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

No *deleteAVL(No *root, int *i, int x){
/*aqui deveremos tomar cuidado para os 4 possíveis casos:
1 - elemento não tem filhos (nó folha)
2 - elemento possui apenas filhos a esquerda
3 - elemento possui apenas filhos a direita
4 - elemento possui filho a esquerda e a direita*/
    No *aux, *aux2;

    //caso trivial
    if(root == NULL){//valor não existe
        printf("\nthe value not exist.");
        *i = 1;
        return NULL;
    }else{
        //valor encontrado
        if(root->chave == x){

                //caso 1: nó folha
                if(root->left == NULL && root->right == NULL){
                    printf("\nno folha");
                    free(root);
                    return NULL;
                }else if(root->left != NULL && root->right == NULL){ //caso 2: filho apenas à esquerda
                    printf("\nfilhos apenas a esquerda");
                    aux = root->left;
                    free(root);
                    return aux;
                }else if(root->left == NULL && root->right != NULL){//caso 3: filho apenas à direita
                    printf("\nfilhos apenas a direita");
                    aux = root->right;
                    free(root);
                    return aux;
                }else{
                    printf("\nfilhos a esquerda e direita");
                    /*aqui baster pegarmos o maior elemento da esquerda ou,
                    o menor elemento da direita*/

                    //ou seja, esse elemento sempre será folha.
                    int x = auxDeleteAVL(root->right);
                    No *ptr = createNo(x); //criei um novo elemento

                    //agora basta remover o verdadeiro elemento da lista
                    root = deleteAVL(root, i, x);

                    aux  = root->left;
                    aux2 = root->right;
                    free(root);
                    ptr->left = aux;
                    ptr->right = aux2;
                    return ptr;
                }
        }else{ //valor ainda não foi encontrado
            //subárvore esquerda
            if(root->chave > x){
                root->left = deleteAVL(root->left, i, x);
                if(*i == 0){
                    switch(root->bal){
                        case -1:
                            caso2(&root);
                            *i = 1;
                            break;
                        case 0:
                            root->bal = -1;
                            break;
                        case 1:
                            root->bal = 0;
                            break;
                    }
                }
            }
            //subárvore direita
            else{
                root->right = deleteAVL(root->right, i, x);
                if(i){
                    switch(root->bal){
                        case -1:
                            root->bal = 0;
                            *i = 1;
                            break;
                        case 0:
                            root->bal = 1;
                            break;
                        case 1:
                            caso1(&root);
                            *i = 1;
                            break;
                    }
                }
            }
        }
    }
}

int auxDeleteAVL(No *root){
    No *aux = root;
    if(root != NULL){
       while(aux->left != NULL){
            aux = aux->left;
       }
       return aux->chave;
    }
    return -1;
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

No *searchAVL(No *root, int x){

    if(!root) return NULL;

    if(root->chave == x) return root;
    else if(root->chave > x) return searchAVL(root->left, x);
    else return searchAVL(root->right, x);
}

void printAVL(No *root){
	if(!root) return;

    printAVL(root->left);
    printf(" %d", root->chave);
    printAVL(root->right);
}
