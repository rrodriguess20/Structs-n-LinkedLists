/*Escreva uma função que conta o nó de células de uma lista simplesmente encadeada. Apresente a
implementação para uma lista encadeada sem cabeça. Apresente esta implementação para uma lista
encadeada com cabeça.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;

	struct celula * prox;

}Celula;

typedef Celula * CCelula;

CCelula criaCelula();
CCelula insereElemento(CCelula lista, int i);
void contaCelulas(CCelula lista);

int main(){

	CCelula teste;
	teste = criaCelula();

	teste = insereElemento(teste, 1);
	teste = insereElemento(teste, 2);
	teste = insereElemento(teste, 3);
	teste = insereElemento(teste, 4);
	teste = insereElemento(teste, 5);

	contaCelulas(teste);

	return 0;
}

CCelula criaCelula(){

	CCelula cabeca = (CCelula)malloc(sizeof(Celula));
	cabeca->prox = NULL; // nó inicial, valor nulo
	return cabeca;
}

CCelula insereElemento(CCelula lista, int i){

	CCelula novo =  (CCelula)malloc(sizeof(Celula));

	novo->info = i;
	novo->prox = lista->prox;
	lista->prox = novo;

	return novo;
}

void contaCelulas(CCelula lista){

	int count = 0;
	CCelula listaAuxiliar = lista->prox;

	while(listaAuxiliar!=NULL){

		count++;
		listaAuxiliar = listaAuxiliar->prox;
	}

	printf("O numero de elementos na lista e: %d\n", count);
}