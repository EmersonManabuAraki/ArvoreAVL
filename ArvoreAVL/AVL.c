#include<stdio.h>
#include<stdlib.h>
#include "AVL.h"
#include "list.h"
#include "fila.h"

void newtree(no **T){
	*T = NULL;
}


no *create_node(int x){
	no *T = malloc (sizeof(no));

	T->info = x;
	T->Llink = NULL;
	T->Rlink = NULL;
		
	return T;

}

no *insere_AVL(no *T,int x){
	if(T == NULL){
		return create_node(x);
	}
	else{
		if(x < T->info){
			T->Llink = insere_AVL(T->Llink, x);
		}
		else{
			if(x > T->info){
				T->Rlink = insere_AVL(T->Rlink, x);
			}
		}
	}
	return balance(T);
}


no *rotacao_Direita(no *T){
	no *q;
	q = T->Llink;
	T->Llink = q->Rlink;
	q->Rlink = T;
	//alturaArvore(&(*T));
	//alturaArvore(&q);
	return q;
}

no *rotacao_Esquerda(no *T){
	no *q;
	q = T->Rlink;
	T->Rlink = q->Llink;
	q->Llink = T;
	//alturaArvore(&(*T));
	//alturaArvore(&q);
	return q;
}

no *balance(no *T){
	//alturaArvore(T);
	if(fatball(T) == 2){
		if(fatball(T->Rlink) < 0){
			T->Rlink = rotacao_Direita(T->Rlink);
		}
		return rotacao_Esquerda(T);

	}
	if(fatball(T) == -2 ){
		if(fatball(T->Llink) > 0){
			T->Llink = rotacao_Esquerda(T->Llink);
		}
		return rotacao_Direita(T);

	}
	return T;
}

int fatball(no *T){
	return (alturaArvore(T->Rlink) - alturaArvore(T->Llink));
}


int alturaArvore(no *T){
	if(T == NULL){
		return -1;		}
	else{
		int esquerda = alturaArvore(T->Llink);
		int direita = alturaArvore(T->Rlink);
		if(direita > esquerda){
			return direita + 1;
		}	
		else{
			return esquerda + 1;
		}
	}
}

void preOrdem_AVL(no *T) {
	if(T != NULL) {
		printf("\n %d", T->info);
		preOrdem_AVL(T->Llink);
		preOrdem_AVL(T->Rlink);
	}
}

void emOrdem_AVL(no *T) {
	if(T != NULL) {
		emOrdem_AVL(T->Llink);
		printf("\n %d", T->info);
		emOrdem_AVL(T->Rlink);
	}
}

void posOrdem_AVL(no *T) {
	if(T != NULL) {
		posOrdem_AVL(T->Llink);
		posOrdem_AVL(T->Rlink);
		printf("\n %d", T->info);
	}

}

no *busca(no *T, int x){
	if(T != NULL){
		if(T->info == x){
			return T;
		}
		if(T->info > x){
			if(T->Llink != NULL){
				busca(T->Llink,x);
			}
		}
		else if(T->info < x){
			if(T->Rlink != NULL){
				busca(T->Rlink,x);
			}
		}
		
	}
}

int largura(no *T){
	if(T == NULL){
		return -1;
	}	
	int cont = 0;
	contarNo(T,&cont);
	list *larg = new_queue(cont);
	enqueue(T->info,larg);
	int x;
	no *aux;
	while(is_empty(larg) == 0){
		aux = busca(T,peek(larg));
		x = dequeue(larg);
		printf("\n %d",x);
		if(aux->Llink != NULL){
			enqueue(aux->Llink->info,larg);
		}
		if(aux->Rlink != NULL){
			enqueue(aux->Rlink->info,larg);
		}
	}
}

void contarNo(no *T,int *cont){
	if(T != NULL){
		contarNo(T->Llink,cont);
		contarNo(T->Rlink,cont);
		(*cont)++;
	}

}

no *maiorNo(no **T){
	if((*T)->Llink == NULL){
		return *T;
	}
	else{
		maiorNo(&((*T)->Llink));
	}
}

int remove_AVL(no **T, int x){
	no *p;
	int aux;
	if(*T == NULL){
		return 0;
	}
	else{
		if(x < (*T)->info){
			remove_AVL(&(*T)->Llink,x);
			*T = balance(*T);
		}
		else{
			if(x > (*T)->info){
				remove_AVL(&(*T)->Rlink,x);
				
				*T = balance(*T);
				
			}
			else{
				if(((*T)->Llink == NULL) && ((*T)->Rlink == NULL)){
					p = (*T);
					free(p);
					(*T) = NULL;
					return 1;
				}
				else{
					if((*T)->Llink == NULL){
						p = (*T);
						(*T) = (*T)->Rlink;
						free(p);
						return 1;
					}
					else{
						if((*T)->Rlink == NULL){
							p = (*T);
							(*T) = (*T)->Llink;
							free(p);
							return 1;
						}
						else{
							p = maiorNo(&(*T)->Llink);
							(*T)->info = p->info;
							remove_AVL(&((*T)->Llink),p->info);
						}
					}
				}
			}
		}

	}
}
