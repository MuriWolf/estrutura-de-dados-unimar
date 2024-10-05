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