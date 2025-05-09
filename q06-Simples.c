/*Escrever uma função que concatene duas listas simplesmente encadeadas em uma única lista
simplesmente encadeada. Apresente também a implementação para uma lista duplamenta encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;
	struct celula * prox;

}celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);
celula * concatena(celula * listaA, celula * listaB);

int main(){

	celula * listaA = criaLista();
	celula * listaB = criaLista();

	insere(listaA, 3);
	insere(listaA, 2);
	insere(listaA, 1);

	insere(listaB, 6);
	insere(listaB, 5);
	insere(listaB, 4);

	celula * listaC = concatena(listaA, listaB);

	imprime(listaC);

	return 0;
}

celula *criaLista(){

	celula *cabeca = (celula *)malloc(sizeof(celula));

	cabeca->prox = NULL;

	return cabeca;
}

void insere(celula *lista, int x){

	celula *auxiliar = (celula *)malloc(sizeof(celula));

	auxiliar->info = x;
	auxiliar->prox = lista->prox;
	lista->prox = auxiliar;
}

void imprime(celula *lista){

	celula *auxiliar = lista->prox;

	while (auxiliar != NULL){
		printf("%d	", auxiliar->info);
		auxiliar = auxiliar->prox;
	}

	printf("\n");
}

celula * concatena(celula * listaA, celula * listaB){

	celula * listaConcat = listaA;

	while(listaConcat->prox!=NULL)
		listaConcat = listaConcat->prox;

	//ligação entre as listas

	listaConcat->prox = listaB->prox;

	return listaA;
}