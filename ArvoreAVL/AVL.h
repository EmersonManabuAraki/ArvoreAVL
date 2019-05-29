#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "list.h"

typedef struct Treeno{
	int info;
	int altura;
	struct Treeno *Llink;
	struct Treeno *Rlink;
} no;

void newtree(no **T);
int remove_AVL(no **T, int x);
no *create_node(int x);
no *insere_AVL(no *T, int x);
no *balance(no *T);
no *rotacao_Direita(no *T);
no *rotacao_Esquerda(no *T);
int alturaArvore(no *T);
int fatball(no *T);
void emOrdem_AVL(no *T);
void preOrdem_AVL(no *T);
void posOrdem_AVL(no *T);
int largura(no *T);
no *busca(no *T, int x);
void contarNo(no *T,int *cont);
no *maiorNo(no **T);

#endif