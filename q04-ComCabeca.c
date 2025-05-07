/*Escrever uma função que exporte uma lista simplesmente encadeada para um vetor: int *Exportar(celula
*lista). Apresente esta implementação para uma lista simplesmente encadeada sem cabeça e com cabeça.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int x;
	struct celula *prox;

}celula;

celula * cria();
celula * insere(int x, celula * lista);
int tamanhoLista(celula * lista);
int * exportar(celula * lista, int tamanho);

int main(){

	celula * teste;
	teste = cria();

	insere(10, teste);
	insere(20, teste);
	insere(30, teste);

	int tamanho = tamanhoLista(teste);
	int * vetor = exportar(teste, tamanho);

	printf("Elementos do vetor: \n");

	for(int i = 0; i<tamanho; i++){

		printf("%d	", vetor[i]);
	}

	printf("\n");

	free(vetor);

	return 0;
}

celula * cria(){

	celula * cabeca = (celula *)malloc(sizeof(celula));
	cabeca->prox = NULL;
	
	return cabeca;
}

celula * insere(int x, celula * lista){

	celula * auxiliar = (celula *)malloc(sizeof(celula));

	auxiliar->x = x;
	auxiliar->prox = lista->prox;
	lista->prox = auxiliar;

	return auxiliar;
}

int tamanhoLista(celula * lista){

	int count = 0;
	celula * auxiliar = lista->prox;

	while(auxiliar!=NULL){

		count++;
		auxiliar = auxiliar->prox;
	}

	return count;
}

int * exportar(celula * lista, int tamanho){

	int * vetor = (int *)malloc(tamanho * sizeof(int));
	celula * auxiliar = lista->prox;

	for(int i = 0; i<tamanho; i++){

		vetor[i] = auxiliar->x;
		auxiliar = auxiliar->prox;
	}

	return vetor;
}