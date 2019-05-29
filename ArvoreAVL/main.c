#include<stdio.h>
#include<stdlib.h>
#include "AVL.h"


void main(){
	no *T = NULL;
	int x,y;
	//newtree(&T);
	printf("Digite o numero que deseja inserir na Arvore \nPara sair digite -1\n");

	while(1){
		scanf("\n%d",&x);
		if(x == -1){
			break;
		}
		T = insere_AVL(T, x);
	}
	largura(T);

	printf("\nDigite o numero que deseja remover na Arvore\n");
	scanf("%d",&y);
	remove_AVL(&T,y);
	printf("\n");
	largura(T);
	/*
	printf("Digite 1 para apresentar a arvore em Em Ordem\nDigite 2 para apresentar a arvore em Pre Ordem \nDigite 3 para apresentar a arvore em Pos Ordem\n");
	scanf("\n%d",&y);
	if(y == 1){
		emOrdem_AVL(&T);
		printf("\n");
	}
	if(y == 2){
		preOrdem_AVL(&T);
		printf("\n");
	}
	if(y == 3){
		posOrdem_AVL(&T);
		printf("\n");
	}
*/
}