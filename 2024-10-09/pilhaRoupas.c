#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CODIGO FEITO USANDO LINUX

typedef struct {
  char marca[50];
  int tamanho;
  int idade;
} Roupa;

typedef struct {
  int topo;
  int tamanho;
  Roupa* roupas;
} PilhaRoupas;

PilhaRoupas* iniciarPilhaDeRoupa(int tamanho) {
  PilhaRoupas* novaPilhaRoupas = (PilhaRoupas*)calloc(1, sizeof(PilhaRoupas));
  
  novaPilhaRoupas->tamanho = tamanho;
  novaPilhaRoupas->topo = -1;
  novaPilhaRoupas->roupas = (Roupa*)calloc(tamanho, sizeof(Roupa));

  return novaPilhaRoupas;
}

int adicionarRoupa(PilhaRoupas* pilhaRoupas, Roupa novaRoupa) {
  if (pilhaRoupas->topo == pilhaRoupas->tamanho - 1) {
    return 0;
  } else {
    *(pilhaRoupas->roupas + pilhaRoupas->topo + 1) = novaRoupa;
    pilhaRoupas->topo++;
    return 1;
  }
}

Roupa removerRoupa(PilhaRoupas* pilhaRoupas) {
  if (pilhaRoupas->topo == -1) {
    printf("Pilha de roupas vazia");
    Roupa vazio;
    return vazio;

  } else {
    Roupa roupaRemovida = *(pilhaRoupas->roupas + pilhaRoupas->topo);
    pilhaRoupas->topo--;

    return roupaRemovida;
  }
}

void imprimirRoupas(PilhaRoupas* pilhaRoupas) {
  printf("\nRoupas:\n");
  for (int i = 0; i <= pilhaRoupas->topo; i++) {
    Roupa roupaAtual = *(pilhaRoupas->roupas + i);
    printf("marca: %s, tamanho: %d, idade: %d\n", roupaAtual.marca, roupaAtual.tamanho, roupaAtual.idade);
  }
}

int main() {
  PilhaRoupas* pilhaRoupas;
  pilhaRoupas = iniciarPilhaDeRoupa(10);

  Roupa roupaUm;
  roupaUm.tamanho = 10;
  roupaUm.idade = 3;
  strcpy(roupaUm.marca, "Marcax");

  Roupa roupaDois;
  roupaDois.tamanho = 7;
  roupaDois.idade = 8;
  strcpy(roupaDois.marca, "Jubileu");

  adicionarRoupa(pilhaRoupas, roupaUm);
  adicionarRoupa(pilhaRoupas, roupaDois);
  imprimirRoupas(pilhaRoupas);
  removerRoupa(pilhaRoupas);
  imprimirRoupas(pilhaRoupas);

  return 0;
}

