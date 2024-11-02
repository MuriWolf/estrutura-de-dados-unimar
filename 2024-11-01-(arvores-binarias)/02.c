#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No* esq;
	struct No* dir;
} No;

No* inserir_valor_arvore_binaria_busca(No* no, int valor_inserir) {
	if (no == NULL) {
		no = (No*)calloc(1, sizeof(No));

		no->valor = valor_inserir;
		no->esq = NULL;
		no->dir = NULL;

		printf("\n%d foi criado", no->valor);

		return no;
	}
	else if (valor_inserir > no->valor) {
		printf("\n%d e maior que raiz (%d)", valor_inserir, no->valor);
		inserir_valor_arvore_binaria_busca(no->dir, valor_inserir);
	}
	else if (valor_inserir < no->valor) {
		printf("\n%d e menor que raiz (%d)", valor_inserir, no->valor);
		inserir_valor_arvore_binaria_busca(no->esq, valor_inserir);
	}
	else {
		return NULL;
	}
}

// raiz - esq - dir
void pre_order(No* no) {
	if (no != NULL) {
		printf("%d ", no->esq->valor);
		// pre_order(no->esq);
		// pre_order(no->dir);
	}
}

int main() {
	No* raiz;
	raiz = inserir_valor_arvore_binaria_busca(NULL, 5);
	inserir_valor_arvore_binaria_busca(raiz, 6);
	inserir_valor_arvore_binaria_busca(raiz, 3);
	inserir_valor_arvore_binaria_busca(raiz, 7);
	inserir_valor_arvore_binaria_busca(raiz, 2);

	pre_order(raiz);

	return 0;
}