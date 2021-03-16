#include <stdlib.h>
#include <stdio.h>

#define TAM 18

void selectionSort(char *vetor);

int main(void){
    char vet[TAM] = {'e','x','e','m','p','l','o','d','e','o','r','d','e','n','a','c','a','o'};
    int vAux;

    printf("before: ");
    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %c", vet[vAux]);
    }

    selectionSort(vet);

    printf("\nafter : ");
    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %c", vet[vAux]);
    }

    return 0;
}

void selectionSort(char *vetor){
    int vMenor, vAux, vTemp, vTroca;

    for(vAux = 0; vAux < (TAM - 1); vAux++){
        //encontra o menor
        vMenor = vAux;
        for(vTemp = vAux + 1; vTemp < TAM; vTemp++){

            if(vetor[vTemp] < vetor[vMenor]){
                vMenor = vTemp;
            }
        }
        //troca o menor elemento com o da posição i
        if (vMenor != vAux){
            vTroca        = vetor[vAux];
            vetor[vAux]   = vetor[vMenor];
            vetor[vMenor] = vTroca;
        }
    }
}
