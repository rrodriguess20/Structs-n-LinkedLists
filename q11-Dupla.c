/*Escreva uma função que remova o i-ésimo item de uma lista simplesmente encadeada. Apresente
também a implementação para uma lista duplamenta encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;
	struct celula * prox;
	struct celula * ant;
}celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);
celula * removeItem(celula * lista, int i);

int main(){

	celula *minhaLista = criaLista();

	insere(minhaLista, 1);
	insere(minhaLista, 2);
	insere(minhaLista, 3);
	insere(minhaLista, 4);
	insere(minhaLista, 5);

	minhaLista = removeItem(minhaLista, 3);

	imprime(minhaLista);

	return 0;
}

celula *criaLista(){

	celula * cabeca = (celula*)malloc(sizeof(celula));

	cabeca->prox = NULL;
	
	return cabeca;

}

void insere(celula *lista, int x){

	celula * auxiliar = (celula*)malloc(sizeof(celula));

	auxiliar->info = x;
	auxiliar->prox = lista->prox;
	auxiliar->ant = lista;

	if(lista->prox!=NULL)
		lista->prox->ant = auxiliar;
	
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

celula * removeItem(celula * lista, int i){

	celula * auxiliar = lista;
	int posicao = 0;

	while(auxiliar!=NULL && posicao<i){

		auxiliar = auxiliar->prox;
		posicao++;
	}

	if(auxiliar==NULL)
		printf("Posicao invalida!\n");
	
	else{

		auxiliar->ant->prox = auxiliar->prox;

		if(auxiliar->prox!=NULL)
			auxiliar->prox->ant = auxiliar->ant;
	}

	free(auxiliar);

	return lista;
}