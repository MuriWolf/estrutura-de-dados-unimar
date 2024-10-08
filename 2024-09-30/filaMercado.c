#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int info;
	struct No* prox;
} No;

typedef struct {
	No* inicial;
} Lista;


Lista* criarLista() {
	Lista* l = (Lista*)calloc(1, sizeof(Lista));
	l->inicial = NULL;
	return l;
}


int removerUltimoNo(Lista* lista) {
	if (lista->inicial == NULL) {
		return 0;
	}
	else {
		No* temp ;
		temp = lista->inicial;
		if (temp->prox == NULL) {
			free(temp);
			return 1;
		}
		else {
			while (temp->prox->prox != NULL) {
				temp = temp->prox;
			}
			free(temp->prox);
			temp->prox = NULL;
			return 1;
		}
	}
}

int removerPrimeiroNo(Lista* lista) {
	No* inicial = (No*)calloc(1, sizeof(No));
	inicial = lista->inicial;
	if (inicial == NULL) {
		return 0;
	}
	else {
		lista->inicial = lista->inicial->prox;
		free(inicial);
		return 1;
	}
}


void inserirInicio(Lista* lista, int valor) {
	No* novoNo = (No*)calloc(1, sizeof(No));

	novoNo->info = valor;
	novoNo->prox = lista->inicial;
	lista->inicial = novoNo;
}


int main() {
	Lista* filaSupermercado;
	filaSupermercado = criarLista();

	int escolha = 0;

	do {
		printf("\nFaca sua escolha\n\nAdicionar ID: 1\nRemover ID: 2\nSair: 0\n\n");
		scanf_s("%d", &escolha);
		if (escolha == 1) {
			int userID;
			scanf_s("%d", &userID);
			inserirInicio(filaSupermercado, userID);
		}
		else if (escolha == 2) {
			int escolhaRemocao;
			printf("\nFaca sua escolha\n\nAdicionar ID do inicio: 1\nRemover ID do fim: 2\nNao remover: any other key\n\n");
			scanf_s("%d", &escolhaRemocao);
			if (escolhaRemocao == 1) {
				removerPrimeiroNo(filaSupermercado);
			}
			else if (escolhaRemocao == 2) {
				removerUltimoNo(filaSupermercado);
			}
		} 
	} while (escolha != 0);

	return 0;
}