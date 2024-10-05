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