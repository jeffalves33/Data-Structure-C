#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

void radixSort(int *A, int *B, int digitos);
void countingSort(int *B, int *A, int K, int cont);
void printVector(int *v);

int main(void){
    int vet[TAM]            = {950, 291, 546, 235, 765, 255, 111, 564, 702, 459};
    int vetResultante[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    radixSort(vet, vetResultante, 3);

    return 0;
}

void radixSort(int *A, int *B, int digitos){
    int a = 1;
    printf("before: ");
    printVector(A);

    for(int i = 1; i <= digitos; i++){
        a *= 10;
        if(!(i == 1)) countingSort(A, B, 9, a);
        else countingSort(B, A, 9, a);
    }

    printf("\nafter : ");
    printVector(B);
}

void countingSort(int *B, int *A, int k, int cont){
    int C[k+1];
    int i,j, aux;
    //int B[lenghtA];

    //menor ou igual porque o lenght de C = k+1
    for(i = 0; i <= k; i++) C[i] = 0;

    //contagem do aparecimento de cada elemento em seus devidos indices
    for(j = 0; j < TAM; j++){
        aux = floor((A[j]%cont)/(cont/10));
        C[aux] += 1;
    }
    //torna o C um vetor com relaчуo direta com o vetor B e A.
    for(i = 1; i <= k; i++) C[i] += C[i-1];

    for(j = TAM-1; j >= 0; j--){
        B[(C[A[j]])-1] = A[j];
        C[A[j]] -= 1;
    }
}

void printVector(int *v){
    for(int i = 0; i < TAM; i++) printf("%d ", v[i]);
}














