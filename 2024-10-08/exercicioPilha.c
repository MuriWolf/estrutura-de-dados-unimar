#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char url[100];
	char nome[50];
} Site;

typedef struct {
	int tamanho;
	int topo;
	Site* sites;
} HistoricoNavegacao;

HistoricoNavegacao* iniciarHistoricoNavegacao(int tamanho) {
	HistoricoNavegacao* novoHistorico = (HistoricoNavegacao*)calloc(1, sizeof(HistoricoNavegacao));

	novoHistorico->tamanho = tamanho;
	novoHistorico->topo = -1;
	novoHistorico->sites = (Site*)calloc(tamanho, sizeof(Site));

	return novoHistorico;
}

void entrarSite(HistoricoNavegacao* historico, Site novoSite) {
	if (historico->tamanho == historico->topo - 1) {
		printf("(Erro) - Lista cheia");
	}
	else {
		*(historico->sites + historico->topo + 1) = novoSite;
		historico->topo++;
	}
}

Site voltarSite(HistoricoNavegacao* historico) {
	if (historico->topo == -1) {
		printf("(Erro) - Lista vazia");
		Site vazio;
		return vazio;
	}
	else {
		Site siteRemovido = *(historico->sites + historico->topo);
		historico->topo--;
		return siteRemovido;
	}
}

void apresentarHistorico(HistoricoNavegacao* historico) {
	for (int i = 0; i <= historico->topo; i++) {
		printf("%s, %s -> ", (*(historico->sites + i)).nome, (*(historico->sites + i)).url);
	}
}

int main() {
	HistoricoNavegacao* historico;
	historico = iniciarHistoricoNavegacao(10);

	while (1) {
		printf("Escolha sua acao\n\n1- entrar site\n2- voltar historico\n3- mostrar historico\n4- sair\n\n");
		int escolha;
		scanf_s("%d", &escolha);
		
		if (escolha == 1) {
			Site novoSite;

			printf("Digite o nome do site:\n");
			scanf_s("%s", novoSite.nome, sizeof(novoSite.nome));

			printf("Digite a URL do site:\n");
			scanf_s("%s", novoSite.url, sizeof(novoSite.url));

			entrarSite(historico, novoSite);
		}
		else if (escolha == 2) {
			voltarSite(historico);
		}
		else if (escolha == 3) {
			apresentarHistorico(historico);
		}
		else if (escolha == 4) {
			break;
		}
		else {
			printf("Input invalido.");
		}
	}

	return 0;
}