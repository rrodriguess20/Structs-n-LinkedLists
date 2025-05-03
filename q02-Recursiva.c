/*Seja uma lista simplesmente encadeada de estruturas da forma 'typedef struct celula { int x; struct cel
*prox; } celula;'. Apresente a implementação iterativa e recursiva da função 'celula *busca(int x, celula
*lista)', que verifica se x pertence à lista simplesmente encadeada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int x;
	struct celula *prox;

}celula;

celula * cria();
celula * insere(int x, celula * lista);
celula * busca (int x, celula * lista);

int main(){

	celula * teste;
	teste = cria();

	teste = insere(1, teste);
	teste = insere(2, teste);
	teste = insere(3, teste);
	teste = insere(4, teste);
	teste = insere(5, teste);
	teste = insere(6, teste);
	teste = insere(7, teste);

	busca(5, teste);

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

celula * busca (int x, celula * lista){

	if(lista->prox==NULL)
		printf("Lista percorrida, elemento nao encontrado!\n");

	else if(lista->x==x)
		printf("Elemento encontrado! %d esta na lista.\n", x);
	
	else
		return busca(x, lista->prox);
}