//Author: Jeferson Luiz Alves de Souza

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "treeRB.h"

int main(){
    Artigo *sent = createSentinel();
	Artigo *mainArtigo = sent;
	Artigo *aux;
	int answer = 1;
	int id;

	while(answer){
        system("cls");
        printf("\n1 - inserir");
        printf("\n2 - remover");
        printf("\n3 - procurar");
        printf("\n4 - printar arvore");
        printf("\n5 - exit");
        printf("\nanswer: ");
        scanf("%d", &answer);

        switch(answer){
            case 1:
                printf("==========INSERCAO==========\n");
                printf("id           : ");
                scanf("%d", &id);
                if(!searchArtigo(mainArtigo, id, sent, 0));
                insertRB(&mainArtigo, id, sent);
                printf("\n");
                system("pause");
                continue;
            case 2:
                printf("==========REMOCAO==========\n");
                printf("id            : ");
                scanf("%d", &id);
                aux = searchArtigo(mainArtigo, id, sent, 0);
                if(aux) removeRB(&mainArtigo, aux, sent);
                printf("\n");
                system("pause");
                continue;
            case 3:
                printf("==========BUSCA==========\n");
                printf("id            : ");
                scanf("%d", &id);
                aux = searchArtigo(mainArtigo, id, sent, 1);
                if(aux){
                    printf("\ninformacoes");
                    printf("\nid           : %d", aux->id);
                    printf("\nano          : %d", aux->ano);
                    printf("\nautor        : %s", aux->autor);
                    printf("titulo       : %s", aux->titulo);
                    printf("revista      : %s", aux->revista);
                    printf("DOI          : %s", aux->DOI);
                    printf("palavra chave: %s", aux->palavraChave);
                    if(aux->dad  != sent) printf("\npai           : %d", aux->dad->id);
                    if(aux->left != sent) printf("\nfilho esquerda: %d", aux->left->id);
                    if(aux->right!= sent) printf("\nfilho direita : %d", aux->right->id);
                }
                printf("\n");
                system("pause");
                continue;
            case 4:
                printf("==========EXIBIR==========\n\n\n");
                printRB(mainArtigo, 0, sent);
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
