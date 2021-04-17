/*essa estrutura de dados é uma alternativa a arvore AVl. Porém ambas tem suas prioridades:
  - se operação de busca é mais usada, use AVL;
  - se operação de inserção e remoção é mais usada, ultilize Rubro Negra.
*/

#include <stdio.h>
#include <stdlib.h>

#define RUBRO 0
#define NEGRO 1
#define SENTINEL -1

//Estrutura de um Artigo
typedef struct artigo{
    int id;
    int color;
    struct artigo *left, *right, *dad;
}Artigo;

Artigo *createSentinel(); ///
Artigo *createArtigo(int id, Artigo *sent); ///
void insertRB(Artigo **mainArtigo, int id, Artigo *sent);///
void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent);///
void removeRB(Artigo* mainArtigo, Artigo *z, Artigo *sent);
void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent);
void transferedadRB(Artigo *mainArtigo, Artigo *z, Artigo *y, Artigo *sent);
void rotationLeft(Artigo *root, Artigo *w, Artigo *sent);
void rotationRight(Artigo *root, Artigo *w, Artigo *sent);
Artigo *sucessor(Artigo *x, Artigo *sent);

int main(){
    Artigo *sent = createSentinel();
	Artigo *mainArtigo = sent;
	insertRB(&mainArtigo, 200, sent);
	insertRB(&mainArtigo, 100, sent);
	insertRB(&mainArtigo, 300, sent);
	insertRB(&mainArtigo,50, sent);
	printf("\ndad,color      : %d, %d", mainArtigo->id, mainArtigo->color);
	printf("\nleft,color     : %d, %d", mainArtigo->left->id, mainArtigo->left->color);
	printf("\nleft-left,color: %d, %d", mainArtigo->left->left->id, mainArtigo->left->left->color);
	printf("\nright,color    : %d, %d", mainArtigo->right->id, mainArtigo->right->color);

	return 0;
}

Artigo *createSentinel(){
    Artigo *sent = (Artigo*)malloc(sizeof(Artigo));
    if(sent){
        sent->color = SENTINEL;
        sent->left  = sent;
        sent->right = sent;
        sent->dad   = sent;
        return sent;
    }
    return NULL;
}

Artigo *createArtigo(int id, Artigo *sent){
	Artigo *ptr = (Artigo*)malloc(sizeof(Artigo));
	if(ptr){
		ptr->color = RUBRO;
		ptr->id    = id;
		ptr->dad   = sent;
		ptr->left  = sent;
		ptr->right = sent;
		return ptr;
	}
	return NULL;
}

void insertRB(Artigo **mainArtigo, int id, Artigo *sent){
    Artigo *ptr = createArtigo(id, sent);
    Artigo *v = sent;
    Artigo *x = *mainArtigo;

    while(x != sent){
        if(x->id == ptr->id){
            printf("\nError: chave existe.");
        }
        //ou seja, enquanto x não for Artigo exterArtigo (NULL)
        v = x;
        if(ptr->id < x->id) x = x->left;
        else x = x->right;
    }

    ptr->dad = v;


    //ou seja, se a arvore mainArtigo passada for NULA
    //casos em que verifica se é na righteita ou à leftuerda que será adicionado
    if(v == sent) *mainArtigo = ptr;
    else{
        if(ptr->id < v->id) v->left = ptr;
        else v->right = ptr;
    }

    insertAuxRB(*mainArtigo, ptr, sent);
}

void insertAuxRB(Artigo *mainArtigo, Artigo *ptr, Artigo *sent){
    Artigo *v, *w, *t;

//# comparar sent COM ALGO  ↓
    while(ptr->dad->color == RUBRO){ //violação da propriedade (rubro filho de rubro)
        v = ptr->dad;
        w = v->dad;

        //trocando righteita por leftuerda
        if(v == w->left){
            t = w->right;

            if(t->color == RUBRO){ //case 1
                v->color = NEGRO;
                t->color = NEGRO;
                w->color = NEGRO;
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->right){ //case 2
                    ptr = v;  ///atualizando o nó problemático
                    rotationLeft(mainArtigo, ptr, sent);
                }
                //como o caso 3 é uma parte do caso 2, então se segue
                //case 3
                ptr->dad->color = NEGRO;
                w->color = RUBRO;
                rotationRight(mainArtigo, ptr, sent);
            }
        }
        //tratamento simétrico trocando leftuerda por righteita;
        else{
            t = w->left;

            if(t->color == RUBRO){ //case 1
                v->color = NEGRO;
                t->color = NEGRO;
                w->color = RUBRO;
                ptr = w; ///atualizando o nó problemático
            }
            else{
                if(ptr == v->left){ //case 2
                    ptr = v;  ///atualizando o nó problemático
                    rotationRight(mainArtigo, ptr, sent);
                }
                //como o caso 3 é uma parte do caso 2, então se segue
                //case 3
                ptr->dad->color = NEGRO;
                w->color = RUBRO;
                rotationLeft(mainArtigo, ptr, sent);
            }
        }
    }
    mainArtigo->color = NEGRO;
}

//ou seja, o algoritmo de busca deve retornar o elemento z.
//isso significa que a função de remoção não deve se preocupar com a procura do nó.
void removeRB(Artigo* mainArtigo, Artigo *z, Artigo *sent){
    Artigo *x, *y;
    int colorY;

    y = z;
    //deveremos saber se a remoção desse nó e sua color, afetará a árvore.
    colorY = y->color;

    if(z->left == sent){ //se não existir filho a leftuerda, pré supomos que tenha filho a righteita já que estamos trabalhando com nó sentinela
        x = z->right;
        transferedadRB(mainArtigo, z, z->right, sent);
    }
    else{
        if(z->right == sent){//aqui temos a certeza que existe um filho a leftuerda, diferente da condição anteiror
            x = z->left;
            transferedadRB(mainArtigo, z, z->left, sent);
        }
        else{ //possui filho à leftuerda e à righteita.
            y = sucessor(z->right, sent);

            //precisamos antes de qualquer coisa guardar a color de y. pois, não podemos
            //comprometer as outras sub árvores do outro lado.
            colorY = y->color;
            x = y->right;

            if(y->dad == z){ //significa q y é filho a righteita de z
                //tudo bem se x for sentinela e mudar o apontamento para o dad!
                x->dad = y;
            }
            else{
                transferedadRB(mainArtigo, y, y->right, sent);
                y->right = z->right;
                y->right->dad = y;
            }
            transferedadRB(mainArtigo, z, y, sent);
            y->left = z->left;
            y->left->dad = y;
            y->color = z->color;
        }
    }
    if(colorY == NEGRO) removeFixUpRB(mainArtigo, x, sent); //colorreção de violação
}

void removeFixUpRB(Artigo *mainArtigo, Artigo *x, Artigo *sent){
	Artigo *w;
	while((x != mainArtigo) && (x->color == NEGRO)){
		if(x == x->dad->left){
			w = x->dad->right;
			if(w->color == RUBRO){		//CASO 1
				printf("\nConsertaDelete: Entrou no Caso 1.1");
				w->color= NEGRO;
				x->dad->color= RUBRO;
				rotationLeft(mainArtigo, x->dad, sent);
				w= x->dad->right;
			}
			if((w->left->color == NEGRO)&&(w->right->color == NEGRO)){		//CASO 2
				printf("\nConsertaDelete: Entrou no Caso 1.2");
				w->color= RUBRO;
				x= x->dad;
			}
			else{
				if(w->right->color == NEGRO){	//CASO 3
					printf("\nConsertaDelete: Entrou no Caso 1.3");
					w->left->color= NEGRO;
					w->color= RUBRO;
					rotationRight(mainArtigo, w, sent);
					w= x->dad->right;
				}							//CASO 4
				printf("\nConsertaDelete: Entrou no Caso 1.4");
				w->color= x->dad->color;
				x->dad->color= NEGRO;
				w->right->color= NEGRO;
				rotationLeft(mainArtigo, x->dad, sent);
				x= mainArtigo;
			}
		}
		else{
			w= x->dad->left;
			if(w->color == RUBRO){		//CASO 1
				printf("\nConsertaDelete: Entrou no Caso 2.1");
				w->color= NEGRO;
				x->dad->color= RUBRO;
				rotationRight(mainArtigo, x->dad, sent);
				w= x->dad->left;
			}
			if((w->left->color == NEGRO)&&(w->right->color == NEGRO)){		//CASO 2
				printf("\nConsertaDelete: Entrou no Caso 2.2");
				w->color= RUBRO;
				x= x->dad;
			}
			else{
				if(w->right->color == NEGRO){	//CASO 3
					printf("\nConsertaDelete: Entrou no Caso 2.3");
					w->left->color= NEGRO;
					w->color= RUBRO;
					rotationLeft(mainArtigo, w, sent);
					w= x->dad->left;
				}							//CASO 4
				printf("\nConsertaDelete: Entrou no Caso 2.4");
				w->color= x->dad->color;
				x->dad->color= NEGRO;
				w->right->color= NEGRO;
				rotationRight(mainArtigo, x->dad, sent);
				x= mainArtigo;
			}
		}
	}
	x->color= NEGRO;
}

void transferedadRB(Artigo *mainArtigo, Artigo *z, Artigo *y, Artigo *sent){
    if(z->dad == sent){//se z for a raiz
        mainArtigo = y;
    }
    else{//caso z não seja a raiz
        if(z == z->dad->left){//se z for filho a leftuerda
            z->dad->left = y;
        }
        else{//se z for filho a righteita
            z->dad->right = y;
        }
    }
    y->dad = z->dad;
}

void rotationLeft(Artigo *root, Artigo *w, Artigo *sent){
    Artigo *v = w->right;
    w->right = v->left;

    if(v->left != sent){ //caso n seja NULL, deve mudar o apontamento do dad
        v->left->dad = w;
    }

    v->dad = w->dad;

    if(w->dad == sent){//caso o dad seja NULL, então w ERA a raiz
        root = v;
    }
    else{
        if(w == w->dad->left){//caso w seja filho a leftuerda do dad dele
            w->dad->left = v;
        }
        else{
            w->dad->right = v;
        }
    }
    v->left = w;
    w->dad = v;
}

void rotationRight(Artigo *root, Artigo *w, Artigo *sent){
    Artigo *v = w->left;
    w->left = v->right;

    if(v->right != sent){ //caso n seja NULL, deve mudar o apontamento do dad
        v->right->dad = w;
    }

    v->dad = w->dad;

    if(w->dad == sent){//caso o dad seja NULL, então w ERA a raiz
        root = v;
    }
    else{
        if(w == w->dad->right){//caso w seja filho a righteita do dad dele
            w->dad->right = v;
        }
        else{
            w->dad->left = v;
        }
    }
    v->right = w;
    w->dad = v;
}

Artigo *sucessor(Artigo *x, Artigo *sent){
    while(x->left != sent) x = x->left;
    return x;
}
