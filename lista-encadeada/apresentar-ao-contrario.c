void apresentarListaAoContrario(Lista* lista) {
	No* aux = lista->final; 
	while (aux != NULL) {
		printf("%d -> ", aux->info);
		aux = aux->ant;
	}
	printf("NULL\n");
}
