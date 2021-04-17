#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 3

typedef struct page{
    int level;
    int m; //qtd de chaves
    int keys[ORDER-1];
    struct page *son[ORDER];
}Page;

Page *createLevel(int *vector, int level);
bool searchKey(Page *tree, int key);
int main(void){

    int vet[2] = {10,20};
    Page *tree = createLevel(vet, 1);
    printf("\n%d", tree->keys[0]);
    printf("\n%d", tree->keys[1]);

    vet[0] = 1;
    vet[1] = 5;
    tree->son[0] = createLevel(vet, 2);
    printf("\n%d", tree->son[0]->keys[0]);
    printf("\n%d", tree->son[0]->keys[1]);

    vet[0] = 13;
    vet[1] = 15;
    tree->son[1] = createLevel(vet, 2);
    printf("\n%d", tree->son[1]->keys[0]);
    printf("\n%d", tree->son[1]->keys[1]);

    bool checker = searchKey(tree, 13); //verificador

    return 0;
}

Page *createLevel(int *vector, int level){
    Page *ptr = (Page*)malloc(sizeof(Page));

    if(ptr){

        ptr->level = level;

        ptr->m = 2;

        for(int i = 0; i < ORDER; i++) ptr->son[i] = NULL;

        for(int j = 0; j < ORDER-1; j++){ //melhorar
            ptr->keys[j] = vector[j];
        }
        return ptr;
    }
    printf("\nError: unallocated memory");
    return NULL;

}

bool searchKey(Page *tree, int key){ /// com problema
    Page *ptr = tree;
    int m;
    int i = 0;
    bool checker = true;

    while(ptr || checker){
        m = ptr->m;
        i = 0;
        while(i < m){
            if(key > ptr->keys[i]) i += 1;
            else{
                if(key == ptr->keys[i]){
                    printf("level   : %d", ptr->level);
                    printf("position: %d", i);
                    checker = false; //encontrado
                }
                else{
                    ptr = ptr->son[i];
                }
                i = m+1; //pois se entrar aqui, ou foi encontrado, ou está em outro nível;
            }
        }

        if(i == m+1){//significa que devemos chegar o ultimo ponteiro
            ptr = ptr->son[i];
        }
    }
    if(checker){//se for verdairo, significa q n foi encontrado
        return false;
    }
    return true;
}





















































































































































































