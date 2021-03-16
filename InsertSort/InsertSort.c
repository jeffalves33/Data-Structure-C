#include <stdio.h>
//#include <stdlib.h>

void insertSort(char *vector, int size);

int main(void){
    int size, i;
    printf("how big is the vector: ");
    scanf("%d", &size);
    system("cls");
    char vetor[size];

    insertSort(vetor, size);

    for(i = 0; i < size; i++){
        printf("%c", vetor[i]);
    }
    return 0;
}

void insertSort(char *vector, int size){
    int i, j;
    char aux = 0;

    for(i = 0; i < size; i++){
        printf("digite: ");
        if(i==0){
            scanf("%s", &vector[i]);
            continue;
        }
        scanf("%s", &aux);
        j = i - 1;

        while(j >= 0 && vector[j] > aux){
            vector[j + 1] = vector[j];
            j -= 1;
        }
        vector[j + 1] = aux;
    }
}
