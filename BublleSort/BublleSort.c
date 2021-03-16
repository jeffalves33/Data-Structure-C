#include <stdio.h>

#define TAM 18

void bublleSort(char *vet);

int main(void){
    char vet[TAM] = {'e','x','e','m','p','l','o','d','e','o','r','d','e','n','a','c','a','o'};
    int i;

    bublleSort(vet);

    for(i = 0; i < TAM; i++){
        printf("%c", vet[i]);
    }

    return 0;
}


void bublleSort(char *vet){
    int i, j;
    char aux;

    for(i = (TAM - 1); i > 0; i++){
        for(j = 1; j < i; j++){
            if(vet[j] > vet[j + 1]){
                aux      = vet[j];
                vet[j]   = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }


}
