/*Escrever uma função que insere na lista uma nova célula de conteúdo x entre as posições k e k + 1 de
uma lista simplesmente encadeada. Apresente também a implementação para uma lista duplamenta
encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;
	struct celula * prox;
	
}celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);
void insereInBetween(celula * lista, int x, int k);

/*Eu poderia muito bem dizer que esse In Between é só 
por causa do significado literal de ser "Entre alguma coisa e outra.
Mas é muito mais legal homenagear Inbetween Days do The Cure ;) */

int main(){

	celula * minhaLista = criaLista();

	insere(minhaLista, 25);
	insere(minhaLista, 24);
	insere(minhaLista, 22);
	insere(minhaLista, 21);
	insere(minhaLista, 20); //aprender como inserir elementos no fim da lista!

	insereInBetween(minhaLista, 23, 3);

	imprime(minhaLista);

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

void insereInBetween(celula * lista, int x, int k){

	celula * auxiliar = lista;

	int count = 0;

	while(auxiliar!=NULL && count<k){

		auxiliar = auxiliar->prox;
		count++;
	}

	if(auxiliar==NULL)
		printf("Posicao invalida!\n");

	else{

		celula * novo = (celula*)malloc(sizeof(celula));

		novo->info = x;
		novo->prox = auxiliar->prox;
		auxiliar->prox = novo;

	}
}