//autor: Jeferson Luiz Alves de Souza

//importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "testeH.h"

//memory allocation function with generic parameter
No *createNo(void *x){
    No *root = NULL;
    //if the allocation is successful, the assignments will be carried out
    if(root = (No*)malloc(sizeof(No))){
        root->bal = 0;
        root->chave = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    return NULL;
}

//key insertion function
void insertAVL(No **root, int *h, void *x){

    //empty root or leaf
    if(*root == NULL){
        printf("\nnull");
        *root = createNo(x);
        return;
    }

    else{
        //node already exists
        if(comparaChaves(x, (*root)->chave) == 0){
            printf("\nalready exists");
            *h = 1;
            return;
        }
        //left patch
        if(comparaChaves(x, (*root)->chave) < 0){
            printf("\nleft ");
            insertAVL(&(*root)->left, h, x);

            //balancing considerations
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

        //right patch
        else{
            printf("\nright");
            insertAVL(&(*root)->right, h, x);

            //balancing considerations
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

No *deleteAVL(No *root, int *i, void* x){
/*here we must take care of the 4 possible cases:
1 - element has no children (leaf node)
2 - element has only children on the left
3 - element has only children on the right
4 - element has children on the left and right*/
    No *aux, *aux2;

    //trivial case
    if(root == NULL){//value not exists
        printf("\nthe value not exist.");
        *i = 1;
        return NULL;
    }else{
        //value found
        if(comparaChaves(root->chave, x) == 0){

                //case 1: leaf knot
                if(root->left == NULL && root->right == NULL){
                    printf("\nknot sheet");
                    free(root);
                    return NULL;
                }else if(root->left != NULL && root->right == NULL){ //case 2: child just on the left
                    printf("\nchildren just left");
                    aux = root->left;
                    free(root);
                    return aux;
                }else if(root->left == NULL && root->right != NULL){//case 3: child just on the right
                    printf("\nchildren just right");
                    aux = root->right;
                    free(root);
                    return aux;

                }else{//case 4: children just left and right
                    printf("\nchildren just left and right");

                    /*here baster we take the biggest element from the left or,
                    the smallest element on the right*/

                    //that is, this element will always be a leaf.
                    void *x = auxDeleteAVL(root->right);

                    No *ptr = createNo(x); //criei um novo elemento

                    //now just remove the real element from the list
                    root = deleteAVL(root, i, x);

                    aux  = root->left;
                    aux2 = root->right;
                    free(root);
                    ptr->left = aux;
                    ptr->right = aux2;
                    return ptr;
                }
        }else{ //value not yet found

            //left subtree
            if(comparaChaves(x, root->chave) < 0){

                root->left = deleteAVL(root->left, i, x);

                //balancing considerations
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

            //right subtree
            else{

                root->right = deleteAVL(root->right, i, x);

                //balancing considerations
                if(*i == 0){
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

//function that returns the leftmost element of the right subtree
void *auxDeleteAVL(No *root){
    No *aux = root;
    if(root != NULL){
       while(aux->left != NULL){
            aux = aux->left;
       }
       return aux->chave;
    }
    return NULL;
}

//function that assists in the right turns
void caso1(No **root){
    No *u = (*root)->left;
    No *z;

    //right rotation
    if(u->bal = 1){
        printf("\nright rotation");
        (*root)->left = u->right;
        u->right = (*root);

        /*I have the job of modifying here, since when passing the case1 or
        case2 is in charge of these functions to modify the balance of this node.
        that's why:*/
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

        //rebalanceando
        if(z->bal == 1) (*root)->bal = -1;
        else (*root)->bal = 0;
        if(z->bal == -1) u->bal = 1;
        else u->bal = 0;
        (*root) = z;
    }
    (*root)->bal = 0;
}

//function that assists in the left rotations
void caso2(No **root){
    No *u, *z;

    u = (*root)->right;

    //left rotation
    if(u->bal = -1){
        printf("\nleft rotation");
        (*root)->right = u->left;
        u->left = (*root);

        /*I have the job of modifying here, since when passing the case1 or
        case2 is in charge of these functions to modify the balance of this node.
        that's why:*/
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

        //rebalancing
        if(z->bal == 1) u->bal = -1;
        else u->bal = 0;
        if(z->bal == -1) (*root)->bal = 1;
        else (*root)->bal = 0;
        (*root) = z;
    }
    (*root)->bal = 0;
}

//function that cycles through the tree to find an existing element
No *searchAVL(No *root, void *x){

    //if not, returns null
    if(!root) return NULL;

    if(comparaChaves(root->chave, x) == 0) return root;

    else if(comparaChaves(root->chave, x) < 0) return searchAVL(root->left, x);

    else return searchAVL(root->right, x);
}

//function that prints the tree
void printAVL(No *root, int nivel){
    int i;
	if(root){
        printAVL(root->right, nivel+1);

        //tabbed printer
        for(i = 0; i < nivel; i++) printf("\t");

        printaChave(root);

        printAVL(root->left, nivel+1);
	}
}
