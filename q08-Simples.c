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
void verifica(celula *listaA, celula * listaB);

int main(){

	celula * listaA = criaLista();
	celula * listaB = criaLista();

	insere(listaA, 3);
	insere(listaA, 2);
	insere(listaA, 1);

	insere(listaB, 3);
	insere(listaB, 2);
	insere(listaB, 1);

	verifica(listaA, listaB);

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

void verifica(celula *listaA, celula * listaB){

	celula * auxiliarA = listaA->prox;
	celula * auxiliarB = listaB->prox;

	int verificacao = 0;

	while(auxiliarA!=NULL&&auxiliarB!=NULL){

		if(auxiliarA->info==auxiliarB->info){

			auxiliarA = auxiliarA->prox;
			auxiliarB = auxiliarB->prox;

		}

		else{

			verificacao = 1;
			break;
		}

	}

	switch (verificacao){
	
	case 0:
		printf("As listas sao iguais!\n");
		break;

	case 1:
		printf("As listas nao sao iguais!\n");
		break;
	
	default:
		break;
	}

}