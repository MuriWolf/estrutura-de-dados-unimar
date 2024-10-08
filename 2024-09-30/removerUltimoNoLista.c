#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	char info[100];
	No* prox;
} No;

typedef struct {
	No* inicial;
} Lista;

int removeerUltimoNo(Lista* lista) {
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