#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int conteudo;
	struct No* esq;
	struct No* dir;
} No;

typedef struct NoFloat {
	float conteudo;
	struct NoFloat* esq;
	struct NoFloat* dir;
} NoFloat;

No* criarNo(int qtde) {
	No* novo_no;
	if (qtde == 0) {
		novo_no = NULL;
	} else {
		novo_no = (No*)calloc(1, sizeof(No));
		printf("\nDigite o valor do no: ");
		scanf("%d", &novo_no->conteudo);
		novo_no->esq = criarNo(qtde/2);
		novo_no->dir = criarNo(qtde - qtde/2 - 1);
	}
	return novo_no;
}

NoFloat* criarNoFloatAutomatico(int qtde) {
	NoFloat* novo_no;
	if (qtde == 0) {
		novo_no = NULL;
	} else {
		novo_no = (NoFloat*)calloc(1, sizeof(NoFloat));

    // gera número aleatório
		novo_no->conteudo = (float) rand();
		novo_no->esq = criarNoFloatAutomatico(qtde/2);
		novo_no->dir = criarNoFloatAutomatico(qtde - qtde/2 - 1);
	}
	return novo_no;
}

void apresentarArvore(No* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->conteudo);
		apresentarArvore(raiz->esq);
		apresentarArvore(raiz->dir);
	}
}

void apresentarArvoreFloat(NoFloat* raiz) {
	if (raiz != NULL) {
		printf("%.2f ", raiz->conteudo);
		apresentarArvoreFloat(raiz->esq);
		apresentarArvoreFloat(raiz->dir);
	}
}

void apresentarFolhas(No* raiz) {
	if (raiz != NULL) {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			printf("%d ", raiz->conteudo);
		} else {
			apresentarFolhas(raiz->esq);
			apresentarFolhas(raiz->dir);
		}
	}
}

void apresentarGalhos(No* raiz) {
	if (raiz != NULL) {
		if (raiz->esq != NULL || raiz->dir != NULL) {
			printf("%d ", raiz->conteudo);
			apresentarGalhos(raiz->esq);
			apresentarGalhos(raiz->dir);
		}
	}
}

int pegarAltura(No* no) {
  if (no == NULL) {
    return -1;
  }
  int he = pegarAltura(no->esq);
  int hd = pegarAltura(no->dir);
  if (he < hd) return hd + 1;
  else return he + 1;
}

int main()
{
	No* raiz;
	raiz = criarNo(10);
	apresentarArvore(raiz);
	printf("\n");
	printf("\nFolhas: ");
	apresentarFolhas(raiz);
	printf("\n");
	printf("\nGalhos: ");
	apresentarGalhos(raiz);
	printf("\n");
	printf("\nTamanho arvore: ");
  printf("%d", pegarAltura(raiz));


  NoFloat* raizFloat;
  raizFloat = criarNoFloatAutomatico(10);
  printf("\n\n");
  apresentarArvoreFloat(raizFloat);

	return 0;
}


