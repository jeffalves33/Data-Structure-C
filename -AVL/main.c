//autor: Jeferson Luiz Alves de Souza
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "testeH.h"

int comparaChaves(void* chave1, void* chave2){
    if (*(int*)chave1 > *(int*)chave2)
        return 1;
    else if (*(int*)chave1 < *(int*)chave2)
        return -1;
    else
        return 0;
}
void printaChave(No *root){
    printf("%d\n", *(int*)root->chave);
}
int *alocaInt(){
    int* a = NULL;
    a = (int*) malloc(sizeof(int));
    scanf("%d", a);
    return a;
}
int main(void){
    int *h = (int*)malloc(sizeof(int));
    *h = 0; //true
    int *i = (int*)malloc(sizeof(int));
    *i = 0; //true
    No *root = NULL;
    No *aux = NULL;
    int answer = 1;
    int *x;

    while(answer){
        system("cls");
        printf("\n1 - inserir elemento");
        printf("\n2 - remover elemento");
        printf("\n3 - procurar elemento");
        printf("\n4 - printar arvore");
        printf("\n5 - exit");
        printf("\nanswer: ");
        scanf("%d", &answer);

        switch(answer){
            case 1:
                printf("\nelemento a inserir: ");
                x = alocaInt();
                insertAVL(&root, h, x);
                printf("\n");
                system("pause");
                *h = 0;
                continue;
            case 2:
                printf("\nelemento a remover: ");
                x = alocaInt();
                root = deleteAVL(root, i, x);
                printf("\n");
                system("pause");
                *i = 0;
                continue;
            case 3:
                printf("\nelemento a buscar: ");
                x = alocaInt();
                aux = searchAVL(root, x);
                if(aux){
                    printf("\nchave           : ");
                    printaChave(aux);
                    printf("\nbalanceamento   : %d\n", aux->bal);
                    if(aux->left){
                        printf("\nfilho a esquerda: ");
                        printaChave(aux->left);
                    }
                    if(aux->right){
                        printf("\nfilho a direita : ");
                        printaChave(aux->right);
                    }
                }else printf("elemento nao existe");

                printf("\n\n");
                system("pause");
                continue;
            case 4:
                printAVL(root, 0);
                printf("\n");
                system("pause");
                continue;
            case 5:
                printf("\n:) bye");
                exit(1);
            default:
                printf("\nerror\n");
                system("pause");
                continue;
        }
    }
    return 0;
}
