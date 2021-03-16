#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 6

void mergeSort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);

int main (void){
    int vet[TAM] = {3,5,2,9,1,4};

    printf("before: ");
    for(int i = 0; i < TAM; i++) printf("%d ", vet[i]);

    mergeSort(vet, 0, 5);                            ///////////////

    printf("\n\nafter : ");
    for(int i = 0; i < TAM; i++) printf("%d ", vet[i]);
    printf("\n\n");

    return 0;
}

void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}


void merge(int *v, int inicio, int meio, int fim){
    int i;
    int j        = inicio;
    int k        = meio+1;
    int contV    = 0;
    int contTemp = 0;
    int tamanho  = fim - inicio + 1;
    int *temp    = (int*)malloc(tamanho*sizeof(int));  //temp deve ser um ponteiro!

    //caso a alocação tenha ocorrido com sucesso
    if(temp!= NULL){

        for(i = 0; i < tamanho; i++){

            //caso em que nem um dos dois subvetores tenham chegado ao final
            if(j != (meio+1) && k != fim + 1){
                if(v[j] < v[k]){
                    temp[i] = v[j];
                    j += 1;
                }else{
                    temp[i] = v[k];
                    k += 1;
                }
            }

            //aqui trata quando um ou os dois subvetores terminam
            else{
                if(j == (meio + 1)){
                    temp[i] = v[k];
                    k += 1;
                }
                else{
                    temp[i] = v[j];
                    j += 1;
                }
            }
        }
        //copiamos a informação do vetor temporário para nosso vetor
        for(contV = inicio, contTemp = 0; contTemp < tamanho; contV++, contTemp++){
            v[contV] = temp[contTemp];
        }
        free(temp);
    }
}
