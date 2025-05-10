/*Escreva uma função que remova o i-ésimo item de uma lista simplesmente encadeada. Apresente
também a implementação para uma lista duplamenta encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;
	struct celula * prox;
}celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);
celula * removeItem(celula * lista, int i); //int i = i-ésimo item

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

celula * removeItem(celula * lista, int i){

	celula * auxiliar = lista;

	for(int j = 1; j<i; j++){ // j = 1 para que o n-ésimo item não seja contado de 0 até o número...

		if(auxiliar->prox==NULL)
			return lista;
		
		auxiliar = auxiliar->prox;
	}

	if(auxiliar->prox==NULL)
		return lista;

	celula * removida = auxiliar->prox;
	auxiliar->prox = removida->prox;
	
	free(removida);

	return lista;
}