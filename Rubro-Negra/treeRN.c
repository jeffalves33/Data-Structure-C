//Author: Jeferson Luiz Alves de Souza

//Importação de bibliotecas necessárias para o funcionamento do algoritmo
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Importação do cabeçalho
#include "treeRB.h"

/*Função que cria um nó sentinela.*/
Artigo *createSentinel(){
    Artigo *sent = (Artigo*)malloc(sizeof(Artigo));

    if(sent){ //Caso a alocação aconteça.

        //Aqui fazemos com que o os apontamentos sejam apotados para o próprio
        //nó.
        sent->color = SENTINEL;
        sent->left  = sent;
        sent->right = sent;
        sent->dad   = sent;
        return sent;
    }
    return NULL;
}

/*Função que cria um nó interno da árvore.*/
Artigo *createArtigo(int id, Artigo *sent){
	Artigo *ptr = (Artigo*)malloc(sizeof(Artigo));

	if(ptr){//Caso a alocação tenha ocorrido com sucesso

	    //Aqui pegamos as informações do usuário e inserimos no novo nó criado
		ptr->id    = id;

		printf("ano          : ");
		scanf("%d", &ptr->ano);

        //Necessario para que ocorra tudo bem com a função fgets.
		getchar();

		printf("autor        : ");
		fgets(ptr->autor, 200, stdin);

		printf("titulo       : ");
		fgets(ptr->titulo, 200, stdin);

		printf("revista      : ");
		fgets(ptr->revista, 200, stdin);

		printf("DOI          : ");
		fgets(ptr->DOI, 200, stdin);

		printf("palavra chave: ");
		fgets(ptr->palavraChave, 200, stdin);

        //Todo nó inicialmente da arvore começa sendo Rubro.
		ptr->color = RUBRO;

		ptr->dad   = sent;

		ptr->left  = sent;

		ptr->right = sent;

		return ptr;
	}
	return NULL;
}

/*Função que procura um nó interno da arvore.*/
Artigo *searchArtigo(Artigo *mainArtigo, int key, Artigo *sent, int n){
    Artigo *ptr = mainArtigo;

    //Laço vai rodar enquanto o nó não encontrar o nó procurado ou chegar ao
    //nó sentinela (nó folha).
    while(ptr != sent){
        if(ptr->id == key) return ptr;
        else if(ptr->id > key) ptr = ptr->left;
        else ptr = ptr->right;
    }
    if(n != 0) printf("\nchave nao existe");
    return NULL;
}

/*Função que insere um nó na árvore.*/
void insertRB(Artigo **mainArtigo, int id, Artigo *sent){
    Artigo *ptr = createArtigo(id, sent); //Cria o nó a ser inserido.
    Artigo *v = sent;
    Artigo *x = *mainArtigo;

    //Roda enquanto o auxilia x não encontra a posição ao novo nó ser inserido.
    while(x != sent){
        if(x->id == ptr->id){
            printf("\nError: chave existe.");
        }
        //ou seja, enquanto x não for Artigo exterArtigo (NULL)
        v = x;
        if(ptr->id < x->id) x = x->left;
        else x = x->right;
    }

    //Nesse momento, o ponteiro x é a posição aonde o nó deve ser inserido e o
    //ponteito v é seu pai.
    ptr->dad = v;


    //Ou seja, se a arvore mainArtigo passada for NULA.
    //Casos em que verifica se é na direita ou à esquerda que será adicionado.
    if(v == sent) *mainArtigo = ptr;
    else{
        if(ptr->id < v->id) v->left = ptr;
        else v->right = ptr;
    }

    //Essa função auxiliar é chamada porque pode ter ocorrido uma violação na
    //árvore.
    insertAuxRB(*mainArtigo, ptr, sent);
}

/*Função que auxilia nos apontamentos do novo nó inserido e verifica se ouve alguma
violação da árvore Rubro-Negra.*/
void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent){
    Artigo *v, *w, *t;

    //como estamos usando um nó sentinela como externo, então esse nó normalmente é
    //negro por regra. Mas, para associação aqui no código, usamos como se ele n fosse
    //nem uma, nem outra cor para n haver erros de sintaxe, como na comparação a baixo
    //                ↓        ↓
    while(ptr->dad->color == RUBRO){ //Violação da propriedade (rubro filho de rubro)
        v = ptr->dad;
        w = v->dad;

        //Trocando direita por esquerda
        if(v == w->left){
            t = w->right;

            if(t->color == RUBRO){ //Caso 1
                v->color = NEGRO;
                t->color = NEGRO;
                w->color = NEGRO;
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->right){ //case 2
                    ptr = v;  ///atualizando o nó problemático
                    //No caso 2, precisamos chamar a função porque precisa ser
                    //realizado uma rotação a esquerda.
                    rotationLeft(&mainArtigo, ptr, sent);
                }
                //Como o caso 3 é uma parte do caso 2, então se segue.
                //Case 3
                ptr->dad->color = NEGRO;
                w->color = RUBRO;
                //No caso 3, precisamos chamar a função porque precisa ser
                //realizado uma rotação a direita.
                rotationRight(&mainArtigo, w, sent);
            }
        }
        //Tratamento simétrico trocando esquerda por direita;
        else{
            //aqui, precisamos usar as informações do tio do nó inserido.
            t = w->left;

            if(t->color == RUBRO){ //Caso 1
                v->color = NEGRO;
                t->color = NEGRO;
                w->color = RUBRO;
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->left){ //Caso 2
                    ptr = v;  ///atualizando o nó problemático
                    rotationRight(&mainArtigo, ptr, sent);
                }
                //Como o caso 3 é uma parte do caso 2, então se segue
                //case 3
                ptr->dad->color = NEGRO;
                w->color = RUBRO;

                //Precisamos então chamar uma função que rotacione a direita
                //porque uma violação ocorreu em relação ao nó problemático.
                rotationLeft(&mainArtigo, w, sent);
            }
        }
    }
    mainArtigo->color = NEGRO;
}

/*Função que auxilia nos reapontamentos em relação ao nó passado como parâmetro*/
//Precisa ser ponteiro para ponteiro caso queiramos remover a raiz.
void transferedadRB(Artigo **mainArtigo, Artigo *z, Artigo *y, Artigo *sent){
    if(z->dad == sent){//Se z for a raiz.
        *mainArtigo = y;
    }
    else{//Caso z não seja a raiz.
        if(z == z->dad->left){//Se z for filho a esquerda.
            z->dad->left = y;
        }
        else{//Se z for filho a direita.
            z->dad->right = y;
        }
    }
    y->dad = z->dad;
}

/*Função que procura o nó sucessor ao nó passado como parâmetro.*/
Artigo *sucessor(Artigo *x, Artigo *sent){
    //Ou seja, ela vai procurar o menor nó, da subarvore a direita.
    while(x->left != sent) x = x->left;
    return x;
}

/*Função que remove um elemento da árvore passado como parâmetro*/
//ou seja, o algoritmo de busca deve retornar o elemento z.
//isso significa que a função de remoção não deve se preocupar com a procura do nó.
void removeRB(Artigo **mainArtigo, Artigo *z, Artigo *sent){
    Artigo *x, *y;
    int colorY;

    y = z;
    //Deveremos saber se a remoção desse nó e sua color, afetará a árvore.
    colorY = y->color;

    //Se não existir filho a esqueda, pré supomos que tenha filho a direita
    //já que estamos trabalhando com nó sentinela.
    if(z->left == sent){
        x = z->right;

        //Função auxiliar para os reapontamentos de z, para seu filho a direita
        transferedadRB(&(*mainArtigo), z, z->right, sent);
    }
    else{
        //aqui temos a certeza que existe um filho a leftuerda, diferente da
        //condição anteiror.
        if(z->right == sent){
            x = z->left;
            //Função auxiliar para os reapontamentos de z, para seu filho a esquerda.
            transferedadRB(&(*mainArtigo), z, z->left, sent);
        }
        //Possui filho à esquerda e à direita.
        else{
            y = sucessor(z->right, sent);

            //Precisamos antes de qualquer coisa guardar a color de y. pois, não podemos
            //comprometer as outras sub árvores do outro lado.
            colorY = y->color;
            x = y->right;
            //Significa q y é filho a direita de z.
            if(y->dad == z){

                //Tudo bem se x for sentinela e mudar o apontamento para o dad!
                x->dad = y;
            }
            //y é filho a esquerda de z.
            else{
                //Função auxiliar para os reapontamentos de y, para seu filho a direita
                transferedadRB(&(*mainArtigo), y, y->right, sent);
                y->right = z->right;
                y->right->dad = y;
            }
            //Função auxiliar para os reapontamentos de z, para y
            transferedadRB(&(*mainArtigo), z, y, sent);
            y->left = z->left;
            y->left->dad = y;
            y->color = z->color;
        }
    }
    free(z); //Devolve z à memória.

    //Caso a cor do nó y, que no caso, ficou no lugar do nó removido seja negro,
    //significa que alguma regra da árvore Rubro-Negra está comprometida.
    if(colorY == NEGRO) removeFixUpRB(*mainArtigo, x, sent); //correção de violação
}

/*Função auxiliar à função de remoção. Auxilia quando uma regra é quebrada.*/
void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent){
	Artigo *w;

	//Se x não for a raiz e sua cor for negra.
	while((x != mainArtigo) && (x->color == NEGRO)){

        //Se x for filho a esquerda de seu pai.
		if(x == x->dad->left){
			w = x->dad->right; //Tio de x.

			//Se a cor do tio for rubro.
			if(w->color == RUBRO){		//Caso 1.
				printf("\nCaso 1.1");
				w->color= NEGRO;
				x->dad->color= RUBRO;

				//Função chamada para realizar rotação a esquerda.
				rotationLeft(&mainArtigo, x->dad, sent);
				w= x->dad->right;
			}

            ///ou seja, o caso 1, ele não se encerra. Ele é usado para modificar
            ///o estado da árvore para que caia no caso 2.
            //Se o tio tiver filhos negros, ele será modificado para Rubro.
			if((w->left->color == NEGRO)&&(w->right->color == NEGRO)){		//CASO 2
				printf("Caso 1.2");
				w->color= RUBRO;
				x= x->dad;
			}

			//Se não, vai chegar mais dois casos.
			else{

                //Se o filho a direita do tio for negro.
				if(w->right->color == NEGRO){	//CASO 3
					printf("\nCaso 1.3");
					w->left->color= NEGRO;
					w->color= RUBRO;
					rotationRight(&mainArtigo, w, sent);
					w= x->dad->right;
				}							//CASO 4

				//Então o problema se resume ao caso em que a mudança já ocorreu, e,
				//então, deve-se modificar a cor de w e do pai de x.
				printf("\nCaso 1.4");
				w->color= x->dad->color;
				x->dad->color= NEGRO;
				w->right->color= NEGRO;

                //Faz uma rotação a esquerda.
				rotationLeft(&mainArtigo, x->dad, sent);
				x= mainArtigo;
			}
		}

		//Aqui vai ocorrer a mesma coisa do bloco a cima, porém, pela esquerda.
        //Se x for filho a direita de seu pai.
		else{
			w = x->dad->left; //Tio de x.

			//Se a cor do tio for rubro.
			if(w->color == RUBRO){		//CASO 1
				printf("\nCaso 2.1");
				w->color= NEGRO;
				x->dad->color= RUBRO;

				//Função que rotaciona a direita.
				rotationRight(&mainArtigo, x->dad, sent);
				w= x->dad->left;
			}

			//Se os filhos do tio forem negros.
			if((w->left->color == NEGRO)&&(w->right->color == NEGRO)){		//CASO 2
				printf("\nCaso 2.2");
				w->color= RUBRO;
				x= x->dad;
			}

			//Se os filhos do tio não forem negros.
			else{

                //Se apenas o filho a direita do tio for negro.
				if(w->right->color == NEGRO){	//CASO 3
					printf("\nCaso 2.3");
					w->left->color= NEGRO;
					w->color= RUBRO;

                    //Rotação a esquerda.
					rotationLeft(&mainArtigo, w, sent);
					w= x->dad->left;
				}							//CASO 4

				//E então se resume ao último caso.
				printf("\nCaso 2.4");
				w->color = x->dad->color;
				x->dad->color= NEGRO;
				w->right->color= NEGRO;

                //Rotação a direita.
				rotationRight(&mainArtigo, x->dad, sent);
				x= mainArtigo;
			}
		}
	}

	//Ao final, x deve ter a cor modificada para negra.
	if(x != sent) x->color= NEGRO;
}

/*Função que rotaciona à esquerda a árvore em relação a w*/
void rotationLeft(Artigo **mainArtigo, Artigo *w, Artigo *sent){
    Artigo *v = w->right;
    w->right = v->left;

    //Caso o filho a esquerda do filho a direita de w seja um sentinela
    if(v->left != sent) v->left->dad = w;

    v->dad = w->dad;

    //Caso w seja raiz da arvore.
    if(w->dad == sent) *mainArtigo = v;

    //Aqui trata os casos em que w tem pai.
    else{

        //Caso w seja filho a esquerda de seu pai.
        if(w == w->dad->left) w->dad->left = v;

        //Caso w seja filho a direita de seu pai
        else w->dad->right = v;
    }
    v->left = w;
    w->dad = v;
}

/*Função que rotaciona à direita a árvore em relação a w*/
void rotationRight(Artigo **mainArtigo, Artigo *w, Artigo *sent){
    Artigo *v = w->left;
    w->left = v->right;

    //Se o filho a direita do filho a esquerda de w for sentinela
    if(v->right != sent) v->right->dad = w;

    v->dad = w->dad;

    //Se w for raiz da árvore.
    if(w->dad == sent) *mainArtigo = v;

    //Trata os casos em que w não seja a raiz da árvore.
    else{

        //Caso seja filho a direita de seu pai.
        if(w == w->dad->right) w->dad->right = v;

        //Se w for fiho a esquerda de seu pai
        else w->dad->left = v;
    }
    v->right = w;
    w->dad = v;
}

/*Função que imprime a árvore com tabulação.*/
void printRB(Artigo *mainArtigo, int nivel, Artigo *sent){
    int i;
	if(mainArtigo != sent){
        printRB(mainArtigo->right, nivel+1, sent);

        //tabbed printer
        for(i = 0; i < nivel; i++) printf("\t");

        if(mainArtigo->color == 0) printf("[%d:R]\n", mainArtigo->id);
        else printf("[%d:N]\n", mainArtigo->id);
        printRB(mainArtigo->left, nivel+1, sent);
	}
}
