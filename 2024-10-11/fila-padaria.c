#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  char senha[100];
} Cliente;

typedef struct {
  int primeiro, ultimo, capacidade, tamanho;
  Cliente* clientes;
} Fila;

Fila* iniciar_fila(int capacidade) {
  Fila* nova_fila = (Fila*)calloc(1, sizeof(Fila));

  nova_fila->capacidade = capacidade;
  nova_fila->ultimo = capacidade - 1;
  nova_fila->primeiro = 0;
  nova_fila->tamanho = 0;
  nova_fila->clientes = (Cliente*)calloc(capacidade, sizeof(Cliente));

  return nova_fila;
}

int entrar_cliente_fila(Fila* fila, Cliente novo_cliente) {
  if (fila->capacidade == fila->tamanho) {
    return 0;
  } else {
    fila->ultimo = (fila->ultimo + 1) % fila->capacidade;
    *(fila->clientes + fila->ultimo) = novo_cliente;
    fila->tamanho++;
    return 1;
  }
}

int atender_cliente_fila(Fila* fila) {
  if (fila->tamanho == 0) {
    return 0;
  } else {
    Cliente cliente_atendido = *(fila->clientes + fila->primeiro);
    fila->primeiro = (fila->primeiro + 1) % fila->capacidade;
    fila->tamanho--;

    return 1;
  }
}

void apresentar_fila(Fila* fila) {
  int primeiro = fila->primeiro;

  printf("\nClientes: \n");
  for (int i = 0; i < fila->tamanho; i++) {
    Cliente cliente_atual = *(fila->clientes + primeiro);
    printf("%s, %s -> ", cliente_atual.nome, cliente_atual.senha);
    primeiro = (primeiro + 1) % fila->capacidade;
  }
  printf("\n");
}

int main() {
  Fila* fila;
  fila = iniciar_fila(10);

  Cliente cliente_um;
  strcpy(cliente_um.nome, "Josimar");
  strcpy(cliente_um.senha, "1243");

  Cliente cliente_dois;
  strcpy(cliente_dois.nome, "Maria");
  strcpy(cliente_dois.senha, "8338");

  entrar_cliente_fila(fila, cliente_um);
  entrar_cliente_fila(fila, cliente_dois);
  apresentar_fila(fila);

  atender_cliente_fila(fila);
  apresentar_fila(fila);
  
  return 0;
}
