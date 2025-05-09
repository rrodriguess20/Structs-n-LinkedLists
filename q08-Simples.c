/*Escreva uma função que verifique se duas listas simplesmente encadeadas são ou não iguais.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int info;
	struct celula * prox;
}celula;

celula *criaLista();
void insere(celula *lista, int x);
void imprime(celula *lista);

int main(){

	return 0;
}