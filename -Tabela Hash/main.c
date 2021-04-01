//tabela hash perfeita
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    bool status; //true se existe, false se foi removido
    int chave;
    struct node *next;
}No;

No *createTabelaHask(int size);
No *createNode(int reason);
void insertTableHash(No *prt, int chave);

int main(void){
    int size = 99;
    No *tableHash[size]; // = createTabelaHask(size);
    insertTableHash(ptr, 20181031);
    return 0;
}

void insertTableHash(No *prt, int chave){
    int reason = chave - 20181000 //alunos do primeiro semestre de 2018

    //aqui teremos uma função injetora, mas vamos considerar o caso abaixo
    if(ptr[reason]->prox == NULL){
        ptr[reason]->prox = createNode(chave);
    }
}

No *createNode(int chave){
    No *ptr = NULL;
    if(ptr = (No*)malloc(sizeof(No))){
        ptr->chave = chave;
        ptr->next = NULL;
        ptr->status = true;
        return ptr;
    }
    return NULL;
}


/*No *createTabelaHask(int size){
    No* ptr[size];

    for(int i = 1; i <= size; i++){
        ptr[i] = (No*)malloc(sizeof(No));
        if(!ptr[i]){
           printf("\nError: memoria nao alocada.");
           return NULL;
        }
        ptr[i].
    }
}*/







