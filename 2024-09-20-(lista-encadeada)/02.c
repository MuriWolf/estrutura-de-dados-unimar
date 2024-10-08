#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int infoIint;
	float infoFloat;
	struct No* prox;
} No;

typedef struct Lista {
	No* inicial;
} Lista;

Lista* criarLista() {
	Lista* l = (Lista*)calloc(1, sizeof(Lista));
	l->inicial = NULL;
	return l;
}

void inserirInicio(Lista* lista, int valorInt, float valorFloat) {
	No* novoNo = (No*)calloc(1, sizeof(No));
	novoNo->infoIint = valorInt;
	novoNo->infoFloat = valorFloat;
	novoNo->prox = lista->inicial;
	lista->inicial = novoNo;
}

void apresentarLista(Lista* lista) {
	No* aux = lista->inicial;
	while (aux != NULL) {
		printf("\nvalor inteiro %d", aux->infoIint);
		printf("\nvalor flutuante %f", aux->infoFloat);
		aux = aux->prox;
	}
	printf("\nNULL");
}

