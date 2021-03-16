#include <stdio.h>

#define SIZE 8
int partitions(int *v, int inicio, int fim); //particiona
void quickSort(int *v, int inicio, int fim); //ordenação rápida
void printVector(int *v);

int main(void){
    int vector[SIZE] = {2,8,7,1,3,5,6,4};

    printf("before: ");
    printVector(vector);

    quickSort(vector, 0, SIZE-1);

    printf("\nafter: ");
    printVector(vector);

    return 0;
}

void printVector(int *v){
    for(int i = 0; i < SIZE; i++) printf("%d ", v[i]);
}

void quickSort(int *v, int inicio, int fim){ //ordenação rápida
    int pivo;
    if(fim > inicio){ //acaba no caso base
        pivo = partitions(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

int partitions(int *v, int inicio, int fim){
    int left  = inicio;
    int right = fim;
    int pivo  = v[inicio];
    int aux;

    while(left < right){
        while(v[left] <= pivo) left++;
        while(v[right] > pivo) right--;
        if(left < right){                   //caso tenha quebrado a condição do laço,
            aux      = v[left];             //não haverá uma troca
            v[left]  = v[right];
            v[right] = aux;
        }
    }
    v[inicio] = v[right];
    v[right]  = pivo;
    return right;
}
