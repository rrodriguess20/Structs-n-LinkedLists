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

	teste = insere(10, teste);
	teste = insere(20, teste);
	teste = insere(30, teste);

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

	return NULL;
}

celula * insere(int x, celula * lista){

	celula * auxiliar = (celula *)malloc(sizeof(celula));

	auxiliar->x = x;
	auxiliar->prox = lista;

	return auxiliar;
}

int tamanhoLista(celula * lista){

	int count = 0;

	while(lista!=NULL){

		count++;
		lista = lista->prox;
	}

	return count;
}

int * exportar(celula * lista, int tamanho){

	int * vetor = (int *)malloc(tamanho * sizeof(int));

	for(int i = 0; i<tamanho; i++){

		vetor[i] = lista->x;
		lista = lista->prox;
	}

	return vetor;
}