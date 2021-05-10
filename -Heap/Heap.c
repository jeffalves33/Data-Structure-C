#include <stdio.h>

#define TAM 6

void buildHeap(int *A);
void maxHeapify(int *A, int i);

int main(void){

    int vet[TAM] = {0, 15, 50, 20, 5, 0};

    buildHeap(vet);

    for(int i = 1; i < TAM; i++) printf("%d ", vet[i]);

    return 0;
}

void buildHeap(int *A){
    for(int i = TAM-1; i > 0; i--) maxHeapify(A, i);
}

void maxHeapify(int *A, int i){
    int L = 2*i;
    int R = (2*i) + 1;
    int maior;
    int aux;

    if(L <= (TAM-1) && A[L] > A[i]) maior = L;
    else maior = i;

    if(R <= (TAM-1) && A[R] > A[maior]) maior = R;
    if(maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        maxHeapify(A, maior);
    }
}







