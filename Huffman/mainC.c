#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mainH.h"

//função que remove o menor elemento (primeiro) da listMaina de prioridades e o retorna
Tree *returnMin(List **listMain){
    List *auxlistMain = NULL;
    Tree *auxTree = NULL;
    //int n = sizelistMain(*listMain);
    //printf("%d ", n);
    if(*listMain){
        auxlistMain = *listMain;
        *listMain = (*listMain)->next;
        auxTree = auxlistMain->ptr;
        free(auxlistMain);
    }
    return auxTree;
}

//essa função retornar um ponteiro para a posição aonde deve ser SOMADO (já existe),
//ou retorna nulo caso n exista.
List *ifExitInlistMain(char *p, List *listMain){
    if(!listMain) return NULL; //listMaina vazia
    List *aux = listMain;

    while(aux){
        //significa q achamos
        if((strcmp(aux->ptr->chave, p) == 0)) return aux;
        aux = aux->next;
    }
    return NULL;
}

//essa função adiciona uma string na listMaina ou soma se a string já existir
void addWord(char *p, List **listMain){
    List *aux = NULL;
    List *ptr = NULL;
    Tree *newTree = newNodeTree(1, p);
    List *position;

    //tratar o caso em q é o primeiro elemento a ser inserido
    if(*listMain == NULL){
        *listMain = newNodelistMain(newTree);
        return;
    }

    //primeiro saber se o elemento já existe na árvore
    if((position = ifExitInlistMain(p, *listMain)) != NULL){ //essa função retorna a posição aonde deve ser somado um elemento
        position->ptr->freq += 1;
    }
    else{//então o elemento não existe
        ptr = newNodelistMain(newTree);
        aux = *listMain;
        while(aux->next != NULL) aux = aux->next; //final da listMaina
        aux->next = ptr;
    }
}

//função destinada a ordenar uma listMaina encadeada e a retornar
List *orderlistMain(List **listMain){
    List *newlistMain = NULL;
    List *aux = *listMain;
    List *smaller = NULL;
    List *auxNewlistMain = NULL;
    List *ptr = NULL;
    int checker = 0; //diz se o smaller é o primeiro elemento ou o segundo
    //laço responsavel por percorrer a listMaina e ir removendo-a até virar nula
    while(*listMain != NULL){
        smaller = *listMain;
        aux = *listMain;
        checker = 0;
        while(aux){
            if(checker > 0){
                if((aux->ptr->freq < smaller->next->ptr->freq)) smaller = ptr;
            }
            //encontramos um elemento menor que o atual menor
            else if((aux->ptr->freq < smaller->ptr->freq)){
                checker += 1;
                smaller = ptr; //guardar a posição anterior
            }
            ptr = aux;
            aux = aux->next;
        }

        //ou seja, se checker for > 0, significa q smaller n é o primeiro elemento

        //se for o primeiro elemento
        if(newlistMain == NULL){
            //isso significa que smaller é ponteiro para o primeiro elemento E
            //ele É EXATAMENTE o elemento a ser removido
            if(smaller == *listMain && checker == 0){//caso o menor elemento esteja no inicio da listMaina
                newlistMain = smaller;
                *listMain = (*listMain)->next;///
            }else{
                newlistMain = smaller->next;
                smaller->next = smaller->next->next;
            }
            auxNewlistMain = newlistMain;
        }
        //se não for o primeiro elemento
        else{
            //isso significa que smaller é ponteiro para o primeiro elemento E
            //ele É EXATAMENTE o elemento a ser removido
            if(smaller == *listMain && checker == 0){//caso o menor elemento esteja no inicio da listMaina
                auxNewlistMain->next = smaller;
                *listMain = (*listMain)->next;
            }else{
                auxNewlistMain->next = smaller->next;
                smaller->next = smaller->next->next;
            }
            auxNewlistMain = auxNewlistMain->next;
        }
    }
    auxNewlistMain->next = NULL; //ultimo elemento apontando para NULL
    return newlistMain;
}

//função destinata a setar a string para '\0'
void cleanString(char *x, int size){
    for(int i = 0; i < size; i++) x[i] = '\0';
}

//função mais complexa do programa
List *createlistMainSort(){
    List *listMain = NULL;
    //pega uma palavra no arquivo
    FILE *myArchive = fopen("inicial.txt", "r");
    FILE *ptr = fopen("inicial.txt", "r");
    char x[10];
    char y[1];
    char aux[10];
    int i = 0;
    int j = 0;
    bool cont = false;

    //percorrendo o  arquivo
    while((aux[j] = fgetc(ptr)) != EOF){
        if(aux[j] == 32){//caso o aux for espaço em branco
            if(!cont){ //palavra n foi adicionada ainda
                addWord(x, &listMain);
                //sempre que eu adicionar uma palavra, preciso setar minha string
                //para que não haja restos
                cleanString(x,10); //string e o tamanho.
                i = 0;
                cont = true;
                y[0] = aux[j];
                addWord(y, &listMain);
                cleanString(y,1);
                cleanString(aux,10);
                fgetc(myArchive);
                j = -1;
            }
            else{ //caso já tenha sido adicionada
                y[0] = aux[j];
                addWord(y, &listMain);
                cleanString(y,1); //string e o tamanho.
                cleanString(aux,10); //string e o tamanho.
                fgetc(myArchive); //assim eu igualo aux à myArchive por enquanto
                j = -1;
            }
        }
        else{
            //↓ caso aux seja pontuações e afins
            if((aux[j] >= 33 && aux[j] <= 47) || (aux[j] >= 58 && aux[j] <= 64) || (aux[j] >= 91 && aux[j] <= 96) || (aux[j] >= 123 && aux[j] <= 126)){
                if(!cont){ //palavra n foi adicionada ainda
                    addWord(x, &listMain);
                    //sempre que eu adicionar uma palavra, preciso setar minha string
                    //para que não haja restos
                    cleanString(x,10); //string e o tamanho.
                    i = 0;
                    cont = true;
                    y[0] = aux[j];
                    addWord(y, &listMain);
                    cleanString(y,1); //string e o tamanho.
                    cleanString(aux,10); //string e o tamanho.
                    fgetc(myArchive);
                    j = -1;
                }
                else{ //caso já tenha sido adicionada
                    y[0] = aux[j];
                    addWord(y, &listMain);
                    cleanString(y,1);
                    cleanString(aux, 10);
                    fgetc(myArchive); //assim eu igualo aux à myArchive por enquanto
                    j = -1;
                }
            }
            else{ //ou seja, ele é alguma letra
                cont = false; //sempre que entrar aqui, significa q uma letra foi add, ou seja, n foi add a palavra atual.
                x[i] = fgetc(myArchive);
                i += 1;
            }
        }
        j += 1;
    }
    fclose(myArchive);
    fclose(ptr);
    //a função deve retornar uma listMaina ORDENADA
    List *listMainReturn = orderlistMain(&listMain);
    return listMainReturn;
}

//função que insere em uma listMaina de prioridades um novo nó de uma árvore
void insertlistMain(List **listMain, Tree *z){
    //caso a listMaina for vazia
    if(!*listMain){
        *listMain = newNodelistMain(z);
        return;
    }
    bool checker = true;
    List *aux    = *listMain;
    List *ptr    = NULL;
    List *x      = NULL;
    List *w      = NULL;
    //laço vai rodar enquanto o novo nó da árvore não foi adicionado na listMaina
    while(checker){
        //pelo "teste de mesa" precisamos fazer o caso em que deve ser inserido
        //no último elemento
        //contamos q a listMaina nunca será checada quando n ouver nenhum elemento
        if(aux == NULL){
            w = newNodelistMain(z);
            ptr->next = w;
            w->next = NULL;//referencia do novo nó
            checker = false;
        }
        //caso o elemento atual seja maior que o elemento a ser inserido
        else if(aux->ptr->freq > z->freq){
            //caso o elemento deva ser inserido no inicio da listMaina
            if(ptr == NULL){
                x = newNodelistMain(z);
                x->next = *listMain;
                *listMain = x;
            }
            else{ //caso não seja o primeiro elemento, então ptr existe
                w = newNodelistMain(z);
                ptr->next = w;
                w->next = aux;//referencia do novo nó
            }
            //ou seja, independente da condição que entrar, o novo nó será adicionado. por isso:
            checker = false;
        }
        //caso a variável que chega já for falsa, significa q n precisa mais mexer
        //no reapontamento das variáveis locais
        if(checker){
            ptr = aux;
            aux = aux->next;
        }
    }
}

//função que cria uma árvore a partir de uma listMaina
Tree *createTree(){
    Tree *z = NULL;
    Tree *x = NULL;
    Tree *y = NULL;
    //é a listMaina de pripridades de frequencia das ocorrências no arquivo
    List *listMain = createlistMainSort();
    printlistMain(listMain);
    //retorna o tamanho da listMaina de prioridades
    int n = sizelistMain(listMain);
    //laço destinado a criar a nossa árvore de frequências
    for(int i = 1; i < n; i++){
        z = newNodeTree(0, "");
        x = returnMin(&listMain); //essa função também deve remover o nó da listMaina
        z->right = x;
        y = returnMin(&listMain);
        z->left = y;
        z->freq = x->freq + y->freq;
        z->chave = ""; //to dizendo que esse, é um nó interno da árvore.
        //essa função deve adicionar z na fila de prioridades ordenadamente.
        insertlistMain(&listMain, z);
        z = NULL;
    }
    //aqui já temos nossa arvore
    return returnMin(&listMain);
}

//essa função retorna o tamanho da listMaina de prioridades
int sizelistMain(List *listMainMain){
    List *aux = listMainMain;
    int cont = 0;
    //enquanto o aux não chegar ao fim da listMaina.
    while(aux){
        cont += 1;
        aux = aux->next;
    }
    return cont;
}

//função que cria um novo nó da arvore
Tree *newNodeTree(int freq, char *chave){ //cuidado com ponteiro de char
    char *aux = (char*)malloc(sizeof(char));
    for(int i = 0; i < 10; i++) aux[i] = chave[i];
    Tree *ptr = (Tree*)malloc(sizeof(Tree));
    if(ptr){
        ptr->checker = false;
        ptr->freq  = freq;
        ptr->chave = aux;
        ptr->left  = NULL;
        ptr->right = NULL;
    }
    return ptr;
}

//função que cria um novo nó da listMaina de prioridades
List *newNodelistMain(Tree *z){
    List *ptr = (List *)malloc(sizeof(List));
    if(ptr){
        ptr->ptr  = z;
        ptr->next = NULL;
    }
    return ptr;
}

/*Função que imprime a árvore com tabulação.
void printTree(Tree *tree, int nivel){
    int i;
	if(tree != NULL){
        printTree(tree->right, nivel+1);

        //tabbed printer
        for(i = 0; i < nivel; i++) printf("\t");

        if(tree->chave == "") printf("(%d)\n", tree->freq);///
        else printf("[%s]\n", tree->chave);
        printTree(tree->left, nivel+1);
	}
}*/

void printlistMain(List *heapMain){
    List *aux = heapMain;
    printf("\n-----print listMain-----");
    while(aux){
        printf("\n[%s][%d]", aux->ptr->chave, aux->ptr->freq);
        aux = aux->next;
    }
    printf("\n--------------------");
}

void marcaLeaf(char *p, Tree *tree){
    if(tree == NULL) return;
    marcaLeaf(p, tree->left);
    marcaLeaf(p,tree->right);
    //quando ela retornar da direita, significa que encontramos um nó folha
    if(strcmp(p, tree->chave) == 0){//significa que encontramos a chave desejada
        tree->checker = true;
    }
    //quando retorna preciso verificar se o esquerda ou direita já foi modificado
    //pode ocorrer em alguma situação que um nó interno não tenhoa um filho a direita ou a esquerda
    //então deve-se tomar cuidado
    if(tree->left) if(tree->left->checker == true) tree->checker = true;
    if(tree->right) if(tree->right->checker == true) tree->checker = true;

}

void desmarcaLeaf(char *p, Tree *tree){
    Tree *aux = tree;
    while(strcmp(p, aux->chave) != 0){
        aux->checker = false;
        if(aux->left->checker == true) aux = aux->left;
        else aux = aux->right;
    }
    aux->checker = false;
}

void addExitArchive(char *p, FILE *exiteArchive, Tree *tree){

    marcaLeaf(p, tree); //vai marcar o caminho em que a folha se encontra
    //agora com o caminho, iremos adicionar a sequencia no arquivo de saida.
    Tree *aux = tree;

    while(strcmp(p, aux->chave) != 0){
        if(aux->left->checker == true){
            aux = aux->left;
            fputc(48,exiteArchive);
        }
        else{
            aux = aux->right;
            fputc(49,exiteArchive);
        }
    }
    desmarcaLeaf(p, tree);
}

void codificaArchive(Tree *tree){
    FILE *entryArchive = fopen("inicial.txt", "r"); // para leitura (arquivo deve existir)
    FILE *exitArchive  = fopen("codificado.txt", "wb");  // para gravação (arquivo n precisa existir)
    FILE *myArchive    = fopen("inicial.txt", "r");
    char x[10];
    char y[1];
    char aux[10];
    int i = 0;
    int j = 0;
    bool cont = false;

    //percorrendo o  arquivo
    while((aux[j] = fgetc(entryArchive)) != EOF){
        if(aux[j] == 32){//caso o aux for espaço em branco
            if(!cont){ //palavra n foi adicionada ainda
                addExitArchive(x, exitArchive, tree);
                //sempre que eu adicionar uma palavra, preciso setar minha string
                //para que não haja restos
                cleanString(x,10); //string e o tamanho.
                i = 0;
                cont = true;
                y[0] = aux[j];
                addExitArchive(y, exitArchive, tree);
                cleanString(y,1);
                cleanString(aux,10);
                fgetc(myArchive);
                j = -1;
            }
            else{ //caso já tenha sido adicionada
                y[0] = aux[j];
                addExitArchive(y, exitArchive, tree);
                cleanString(y,1); //string e o tamanho.
                cleanString(aux,10); //string e o tamanho.
                fgetc(myArchive); //assim eu igualo aux à myArchive por enquanto
                j = -1;
            }
        }
        else{
            //↓ caso aux seja pontuações e afins
            if((aux[j] >= 33 && aux[j] <= 47) || (aux[j] >= 58 && aux[j] <= 64) || (aux[j] >= 91 && aux[j] <= 96) || (aux[j] >= 123 && aux[j] <= 126)){
                if(!cont){ //palavra n foi adicionada ainda
                    addExitArchive(x, exitArchive, tree);
                    //sempre que eu adicionar uma palavra, preciso setar minha string
                    //para que não haja restos
                    cleanString(x,10); //string e o tamanho.
                    i = 0;
                    cont = true;
                    y[0] = aux[j];
                    addExitArchive(y, exitArchive, tree);
                    cleanString(y,1); //string e o tamanho.
                    cleanString(aux,10); //string e o tamanho.
                    fgetc(myArchive);
                    j = -1;
                }
                else{ //caso já tenha sido adicionada
                    y[0] = aux[j];
                    addExitArchive(y, exitArchive, tree);
                    cleanString(y,1);
                    cleanString(aux, 10);
                    fgetc(myArchive); //assim eu igualo aux à myArchive por enquanto
                    j = -1;
                }
            }
            else{ //ou seja, ele é alguma letra
                cont = false; //sempre que entrar aqui, significa q uma letra foi add, ou seja, n foi add a palavra atual.
                x[i] = fgetc(myArchive);
                i += 1;
            }
        }
        j += 1;
    }
    fclose(myArchive);
    fclose(entryArchive);
    fclose(exitArchive);
}

void decodificaArchive(Tree *tree){
    /*essa função irá percorrer a árvore mediante cada inteiro (0 ou 1) que ler
    no arquivo. quando o auxiliar chegar a um nó folha, ele para, e adiciona aquele
    caracter na arvore.
    após isso, ele volta a ser a raiz e continua percorrendo o arquivo enquanto ele
    não termina.*/
    FILE *archive = fopen("codificado.txt", "r"); //para leitura, o arquivo deve existir
    FILE *exitArchive = fopen("decodificado.txt", "a"); //deve ser em branco, já que o caracter "a" sempre adicionará ao final
    char x[1];
    Tree *aux = tree;

    while((x[0] = fgetc(archive)) != EOF){
        if(x[0] == 49) aux = aux->right;
        else aux = aux->left;

        //ver se chegou a um folha
        if(!aux->left & !aux->right){ //chegou a um nó folha
            //então precisamos adicionar no arquivo de saída e
            //fazer aux ser a raiz novamente
            fputs(aux->chave, exitArchive);
            aux = tree;
        }
    }
    fclose(archive);
    fclose(exitArchive);
}
