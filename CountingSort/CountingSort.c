#include <stdio.h>

#define lenghtA 8

void countingSort(int *B, int *A, int K);
void printVector(int *v);

int main(void){
    int k        = 5; //diz respeito ao MAIOR elemento do vetor.
    int vector[lenghtA]       = {2,5,3,0,2,3,0,3};
    int vectorResult[lenghtA] = {0,0,0,0,0,0,0,0};

    printf("before: ");
    printVector(vector);

    countingSort(vectorResult, vector, k);

    printf("\nafter : ");
    printVector(vectorResult);

    return 0;
}

void countingSort(int *B, int *A, int k){
    int C[k+1];
    int i,j;
    //int B[lenghtA];

    //menor ou igual porque o lenght de C é k+1
    for(i = 0; i <= k; i++) C[i] = 0;

    //contagem do aparecimento de cada elemento em seus devidos indices
    for(j = 0; j < lenghtA; j++) C[A[j]] += 1;

    //torna o C um vetor com relação direta com o vetor B e A.
    for(i = 1; i <= k; i++) C[i] += C[i-1];

    for(j = lenghtA-1; j >= 0; j--){
        B[(C[A[j]])-1] = A[j];
        C[A[j]] -= 1;
    }
}

void printVector(int *v){
    for(int i = 0; i < lenghtA; i++) printf("%d ", v[i]);
}














