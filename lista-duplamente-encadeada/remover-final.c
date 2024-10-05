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