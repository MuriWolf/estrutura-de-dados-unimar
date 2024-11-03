#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	 short int nivel;
} Zumbi;

typedef struct {
	int habilidade;
} Sobrevivente;

typedef struct ZumbisDerrotados {
	int tamanho;
	int topo;
	Zumbi* zumbis;

} ZumbisDerrotados;

typedef struct {
	int primeiro, ultimo, tamanho, capacidade;
	Sobrevivente* sobreviventes;
} Resgatados;

typedef struct {
	char nome[100];
	int xp;
	Resgatados* resgatados;
} Personagem;

ZumbisDerrotados* criarZumbisDerrotados(int tamanho) {
	ZumbisDerrotados* zumbisDerrotados = (ZumbisDerrotados*)calloc(1, sizeof(ZumbisDerrotados));
	zumbisDerrotados->tamanho = tamanho;
	zumbisDerrotados->topo = -1;
	zumbisDerrotados->zumbis = (Zumbi*)calloc(tamanho, sizeof(Zumbi));

	return zumbisDerrotados;
}

int adicionarZumbisDerrotados(ZumbisDerrotados* zumbiDerrotados, Zumbi zumbi) {
	if (zumbiDerrotados->tamanho == zumbiDerrotados->topo - 1) {
		return 1;
	} 
	zumbiDerrotados->topo++;
	*(zumbiDerrotados->zumbis + zumbiDerrotados->topo) = zumbi;
	return 0;
}

int mostrarZumbisDerrotados(ZumbisDerrotados* zumbiDerrotados) {
	if (zumbiDerrotados != NULL) {
		return zumbiDerrotados->topo + 1;
	}
	return 0;
}

Resgatados* criar_resgatados(int capacidade) {
	Resgatados* resgatados = (Resgatados*)calloc(1, sizeof(Resgatados));
	resgatados->capacidade = capacidade;
	resgatados->tamanho = 0;
	resgatados->primeiro = 0;
	resgatados->ultimo = capacidade - 1;
	resgatados->sobreviventes = (Sobrevivente*)calloc(capacidade, sizeof(Sobrevivente));

	return resgatados;
}

int enfileirar_resgatados(Resgatados* resgatados, Sobrevivente novo_resgatado) {
	if (resgatados->tamanho == resgatados->capacidade) { 
		return 1;
	}
	resgatados->ultimo = (resgatados->ultimo + 1) % resgatados->capacidade;
	*(resgatados->sobreviventes + resgatados->ultimo) = novo_resgatado;
	resgatados->tamanho++;

  return 0;
}

// desinfilerar
int usar_habilidade_de_resgatado(Resgatados* resgatados) {
	if (resgatados->tamanho == 0) {
		return 0;
	}
	else {
		Sobrevivente sobrevivente_removido = *(resgatados->sobreviventes + resgatados->primeiro);
		resgatados->primeiro = (resgatados->primeiro + 1) % resgatados->capacidade;
		resgatados->tamanho--;
		return sobrevivente_removido.habilidade;
	}
}

void apresentar_resgatados(Resgatados* resgatados) {
	int primeiro = resgatados->primeiro;
	printf("\nHabilidades dos resgatados: ");
	for (int i = 0; i < resgatados->tamanho; i++) {
    Sobrevivente sobrevivente = *(resgatados->sobreviventes + primeiro);
		printf("%d ", sobrevivente.habilidade);
		primeiro = (primeiro + 1) % resgatados->capacidade;
	}
}

int gerar_numero_aleatorio(int min, int max) {	
	srand((unsigned)time(NULL));
	return min + (rand() % max);
}

int mostrar_opcoes() {
	int escolha;
	printf("\n\nEscolha sua acao\n1. Combater zumbi\n2. Resgatar sobrevivente\n3. Mostrar Status\n4. Sair\n\nEscolher uma opcao: ");
	scanf("%d", &escolha);

	return escolha;
}

Personagem* iniciar_personagem() {
	Personagem* personagem = (Personagem*)calloc(1, sizeof(Personagem));
	personagem->resgatados = criar_resgatados(99);
	printf("\nDigite o nome do personagem: ");
	scanf("%s", personagem->nome);
	personagem->xp = 0;
	
	return personagem;
}

int combater_zumbi(Personagem* personagem, ZumbisDerrotados* zumbisDerrotados) { 
	int escolha_atacar = 0;
  int usar_habilidade = 0;

	int nivel_aleatorio = gerar_numero_aleatorio(1, 5);
	Zumbi zumbi;
	zumbi.nivel = nivel_aleatorio;

	while (escolha_atacar != 1 && escolha_atacar != 2) {
		printf("\nUm zumbi de nivel %d surgiu!!\n1. Atacar\n2. Fugir\n\nEscolha rapido: ", zumbi.nivel);
		scanf("%d", &escolha_atacar);
	}
    if (escolha_atacar == 1) {
      int valor_ataque = gerar_numero_aleatorio(1, 10);

      if (personagem->resgatados->tamanho > 0) {
        do {
          printf("\nDeseja usar uma habilidade? (1. sim 2. nao): ");
          scanf("%d", &usar_habilidade);
        } while (usar_habilidade != 1 && usar_habilidade != 2);

        if (usar_habilidade == 1) {
          zumbi.nivel -= usar_habilidade_de_resgatado(personagem->resgatados);
        }
      }

      if (zumbi.nivel < 1) {
        zumbi.nivel = 1;
      }

      if (valor_ataque > zumbi.nivel) {
        adicionarZumbisDerrotados(zumbisDerrotados, zumbi);
        personagem->xp += zumbi.nivel;
        printf("\n\nVoce matou o zumbi. Mais %d de xp!", zumbi.nivel);

        return 0;
      }
      else {
        if (zumbi.nivel > personagem->xp) {
          personagem->xp = 0;
          printf("\n\nVoce perdeu a batalha. xp zerado!");

        }
        else {
          printf("\n\nVoce perdeu a batalha. Menos %d de xp!", zumbi.nivel);
          personagem->xp -= zumbi.nivel;
        }

        return 1;
      }
    }
    else {
      printf("\n\nVoce fugiu com sucesso do zumbi...");
      return 1;
    }
}

int resgatar_sobrevivente(Personagem* personagem, ZumbisDerrotados* zumbisDerrotados) {
	int usar_habilidade = 0;

	Zumbi zumbi;
	int nivel_aleatorio = gerar_numero_aleatorio(1, 5);
	zumbi.nivel = nivel_aleatorio;

	Sobrevivente sobrevivente;
	int habilidade_aleatoria = gerar_numero_aleatorio(1, 2);
	sobrevivente.habilidade = habilidade_aleatoria;

	zumbi.nivel -= sobrevivente.habilidade;

	if (personagem->resgatados->tamanho > 0) {
		do {
      printf("\nDeseja usar uma habilidade? (1. sim 2. nao): ");
			scanf("%d", &usar_habilidade);
		} while (usar_habilidade != 1 && usar_habilidade != 2);

		if (usar_habilidade == 1) {
			zumbi.nivel -= usar_habilidade_de_resgatado(personagem->resgatados);
		}
	}

	if (zumbi.nivel < 1) {
		zumbi.nivel = 1;
	}

	int valor_ataque = gerar_numero_aleatorio(1, 10);

	if (valor_ataque > zumbi.nivel) {
		adicionarZumbisDerrotados(zumbisDerrotados, zumbi);
		personagem->xp += zumbi.nivel;
    enfileirar_resgatados(personagem->resgatados, sobrevivente);

    printf("\n\nSobrevivente salvo. Habilidade adicionada.");

    return 0;
	}
	else {
		if (zumbi.nivel > personagem->xp) {
			personagem->xp = 0;
		}
		else {
			personagem->xp -= zumbi.nivel;
		}

    printf("\n\nSobrevivente nao foi salvo...");

    return 1;
	}

}

void mostrar_status(Personagem* personagem, ZumbisDerrotados* zumbisDerrotados) {
	printf("\n\nSTATUS DO JOGO\n");
	printf("\nXp do %s: %d", personagem->nome, personagem->xp);
	printf("\nQuantidade de zumbis derrotados: %d", zumbisDerrotados->topo + 1);
	apresentar_resgatados(personagem->resgatados);
}

int main() {
	ZumbisDerrotados* zumbisDerrotados;
	zumbisDerrotados = criarZumbisDerrotados(99);

  printf("\n\nBem vindo ao apocalipse.\n\n");

  Personagem* protagonista;
  protagonista = iniciar_personagem();
	
	while (1) {
		int escolha = mostrar_opcoes();

		switch (escolha)
		{
		case 1:
      combater_zumbi(protagonista, zumbisDerrotados);
			break;
		case 2:
      resgatar_sobrevivente(protagonista, zumbisDerrotados);
			break;
		case 3:
        mostrar_status(protagonista, zumbisDerrotados);
			break;
		case 4:
        printf("\n\n%s nao aguentou o terror e deu fim a propria vida... x|\n", protagonista->nome);
      return 0;
			break;
		default:
			printf("\nEscolha invalida!!");
			break;
		}
	}

	return 0;
}

