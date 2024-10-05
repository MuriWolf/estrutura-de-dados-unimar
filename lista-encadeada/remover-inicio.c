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
