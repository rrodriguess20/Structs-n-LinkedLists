/* Escrever uma função que crie e retorne uma cópia de uma lista simplesmente encadeada passada como
parâmetro. Apresente também a implementação para uma lista duplamenta encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
	int info;
	struct celula *prox;
	struct celula *ant;

} celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);
celula *copiaLista(celula *lista);

int main()
{
	celula *minhaLista = criaLista();

	insere(minhaLista, 1);
	insere(minhaLista, 2);
	insere(minhaLista, 3);
	insere(minhaLista, 4);
	insere(minhaLista, 5);

	celula *minhaListaCopia = copiaLista(minhaLista);

	imprime(minhaListaCopia);

	return 0;
}

celula *criaLista()
{
	celula *cabeca = (celula *)malloc(sizeof(celula));

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

void imprime(celula *lista)
{
	celula *auxiliar = lista->prox;

	while (auxiliar != NULL)
	{
		printf("%d	", auxiliar->info);
		auxiliar = auxiliar->prox;
	}

	printf("\n");
}

//mudar a funcao
celula *copiaLista(celula *lista){

	celula *copia = criaLista();
	celula *fim = copia;
	celula *atual = lista->prox;

	while (atual != NULL){

		celula *novo = (celula *)malloc(sizeof(celula));

		novo->info = atual->info;
		novo->prox = NULL;
		novo->ant = fim;

		fim->prox = novo;
		fim = novo;
		atual = atual->prox;
	}

	return copia;
}