#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    float x;
    struct node *next;
}Bucket;

Bucket *createStruct(float x);
void bucketSort(float *vector, Bucket **vet);

int main(void){
    float vector[10] = {0.23,0.54,0.31,0.77,0.41,0.68,0.43,0.15,0.82,0.10};

    //construindo o vetor a ser usado
    Bucket *vet[10];
    for(int i = 0; i < 10; i++){
        vet[i] = createStruct(vector[i]);
        if(!vet[i]) break;
    }

    bucketSort(vector, vet);

    return 0;
}

void bucketSort(float *vector, Bucket **vet){
    float actual;
    //actual = floor(10*vector[i]);

}

Bucket *createStruct(float x){
    Bucket *ptr;
    if(ptr = (Bucket*)malloc(sizeof(Bucket))){
        ptr->next = NULL;
        ptr->x = x;
        return ptr;
    }
    return NULL;
}
