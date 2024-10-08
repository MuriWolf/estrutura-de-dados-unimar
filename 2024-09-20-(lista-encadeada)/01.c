#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int info;
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

void inserirInicio(Lista* lista, int valor) {
	No* novoNo = (No*)calloc(1, sizeof(No));
	novoNo->info = valor;
	novoNo->prox = lista->inicial;
	lista->inicial = novoNo;
}

void apresentarLista(Lista* lista) {
	No* aux = lista->inicial;
	while (aux != NULL) {
		printf("\n%d", aux->info);
		aux = aux->prox;
	}
	printf("\nNULL");
}

int main() {
	Lista* list;
	list = criarLista();
	for (int i = 0; i < 5; i++) {
		int valor = 0;
		printf("Digite um valor: ");
		scanf_s("%d", &valor, sizeof(valor));
		inserirInicio(list, valor);
	}
	apresentarLista(list);
	
	return 0;
}
