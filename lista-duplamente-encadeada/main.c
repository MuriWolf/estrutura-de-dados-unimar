#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int info;
	struct No* prox;
	struct No* ant;
} No;

typedef struct {
	No* inicial;
	No* final;
} Lista;

Lista* criarListaDuplamenteEncadeada() {
	Lista* novaLista = (Lista*)calloc(1, sizeof(Lista));
	novaLista->inicial = NULL;
	novaLista->final = NULL;

	return novaLista;
}

void inserirInicioListaDuplamenteEncadeada(Lista* lista, int valor) {
	No* novoNo = (No*)calloc(1, sizeof(No));
	novoNo->info = valor;
	novoNo->ant = NULL;
	novoNo->prox = lista->inicial;
	if (lista->inicial == NULL) {
		lista->final = novoNo;
	}
	else {
		lista->inicial->ant = novoNo;
	}
	lista->inicial = novoNo;
}

void inserirFimListaDuplamenteEncadeada(Lista* lista, int valor) {
	No* novoNo = (No*)calloc(1, sizeof(No));
	novoNo->info = valor;
	novoNo->prox = NULL;
	novoNo->ant = lista->final;
	if (lista->final == NULL) {
		lista->inicial = novoNo;
	}
	else {
		lista->final->prox = novoNo;
	}
	lista->final = novoNo;
}

int removerInicioListaDuplamenteEncadeada(Lista* lista) {
	No* inicio = lista->inicial;

	if (lista->inicial == NULL) {
		return 0;
	}
	else if (lista->inicial == lista->final) {
		lista->inicial = NULL;
		lista->final = NULL;
	}
	else {
		lista->inicial = lista->inicial->prox;
		lista->inicial->ant = NULL;
	}
	free(inicio);
	return 1;
}

int removerFimListaDuplamenteEncadeada(Lista* lista) {
	No* fim = lista->final;

	if (lista->final == NULL) {
		return 0;
	}
	else if (lista->inicial == lista->final) {
		lista->inicial = NULL;
		lista->final = NULL;
	}
	else {
		lista->final = lista->final->ant;
		lista->final->prox = NULL;
	}

	free(fim);
	return 1;
}

void apresentarLista(Lista* lista) {
	No* aux = lista->inicial;
	while (aux != NULL) {
		printf("%d -> ", aux->info);
		aux = aux->prox;
	}
	printf("NULL\n");
}

void apresentarListaAoContrario(Lista* lista) {
	No* aux = lista->final; 
	while (aux != NULL) {
		printf("%d -> ", aux->info);
		aux = aux->ant;
	}
	printf("NULL\n");
}

int main() {
	Lista* listadupla;
	listadupla = criarListaDuplamenteEncadeada();
	inserirInicioListaDuplamenteEncadeada(listadupla, 20);
	inserirInicioListaDuplamenteEncadeada(listadupla, 10);
	inserirFimListaDuplamenteEncadeada(listadupla, 30);
	inserirFimListaDuplamenteEncadeada(listadupla, 40);
	removerFimListaDuplamenteEncadeada(listadupla);
	removerFimListaDuplamenteEncadeada(listadupla);
	apresentarLista(listadupla);
}