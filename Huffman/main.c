//Author: Jeferson Luiz Alves de Souza
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mainH.h"

int main(void){
    //1. o usuario informa o nome do arquivo a ser comprimido
    //2. função que procura na lista um elemento e informa sua frequencia
    //3. função que imprime a arvore
    //4. criar um arquivo de saída (nome a escolha do usuário) a partido do arquivo do item 1
    //5. função que descomprime um arquivo. o usuario informa o arquivo de entrada e de saida.
    //obs.: a função comprimir arquivo faz
    //pega um arquivo (nome a escolha do usuário);
    //imprime a arvore de elementos;
    //imprime a lista (contagem de frequências de elementos);
    //gera um arquivo comprimido (nome a escolha do usuário);
    Tree *treeMain = createTree();
    //1. codificando
    codificaArchive(treeMain);
    decodificaArchive(treeMain);
    return 0;
}
