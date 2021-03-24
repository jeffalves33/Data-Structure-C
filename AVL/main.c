#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"

int main(void){
    int *h = (int*)malloc(sizeof(int));
    *h = 0; //true
    int *i = (int*)malloc(sizeof(int));
    *i = 0; //true
    No *root = NULL;
    No *aux = NULL;
    int answer = 1;
    int x;

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
                scanf("%d", &x);
                insertAVL(&root, h, x);
                printf("\n");
                system("pause");
                *h = 0;
                continue;
            case 2:
                printf("\nelemento a remover: ");
                scanf("%d", &x);
                root = deleteAVL(root, i, x);
                printf("\n");
                system("pause");
                *i = 0;
                continue;
            case 3:
                printf("\nelemento a buscar: ");
                scanf("%d", &x);
                aux = searchAVL(root, x);
                printf("chave           : %d", aux->chave);
                printf("\nbalanceamento   : %d", aux->bal);
                if(aux->left)printf("\nfilho a esquerda: %d", aux->left->chave);
                if(aux->right)printf("\nfilho a direita : %d", aux->right->chave);
                printf("\n");
                system("pause");
                continue;
            case 4:
                printAVL(root);
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
