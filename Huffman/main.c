//Author: Jeferson Luiz Alves de Souza
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mainH.h"

int main(void){
    //1. o usuario informa o nome do arquivo a ser comprimido
    //2. fun��o que procura na lista um elemento e informa sua frequencia
    //3. fun��o que imprime a arvore
    //4. criar um arquivo de sa�da (nome a escolha do usu�rio) a partido do arquivo do item 1
    //5. fun��o que descomprime um arquivo. o usuario informa o arquivo de entrada e de saida.
    //obs.: a fun��o comprimir arquivo faz
    //pega um arquivo (nome a escolha do usu�rio);
    //imprime a arvore de elementos;
    //imprime a lista (contagem de frequ�ncias de elementos);
    //gera um arquivo comprimido (nome a escolha do usu�rio);
    Tree *treeMain = createTree();
    //1. codificando
    codificaArchive(treeMain);
    decodificaArchive(treeMain);
    return 0;
}
